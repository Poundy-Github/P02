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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Cfg.h
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined(CANIF_CFG_H)
#define CANIF_CFG_H


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/
#include "Can.h"




/**********************************************************************************************************************
  \def  Version defines
**********************************************************************************************************************/

#define CANIF_CFG5_VERSION                                 0x0415u
#define CANIF_CFG5_RELEASE_VERSION                         0x00u
#define IF_ASRIFCAN_GENTOOL_CFG5_MAJOR_VERSION             0x04u
#define IF_ASRIFCAN_GENTOOL_CFG5_MINOR_VERSION             0x15u
#define IF_ASRIFCAN_GENTOOL_CFG5_PATCH_VERSION             0x00u

#define CANIF_CFG5_GENERATOR_COMPATIBILITY_VERSION         0x0212u

/**********************************************************************************************************************
  \def  Switches
**********************************************************************************************************************/

#define CANIF_TRANSMIT_BUFFER                              STD_ON /* Signals if Tx-buffer is enabled at all in CanIf. The value is determined from parameter "CanIfPublicTxBuffering". */
#define CANIF_TRANSMIT_BUFFER_PRIO_BY_CANID                STD_ON
#define CANIF_TRANSMIT_BUFFER_FIFO                         STD_OFF
#define CANIF_BITQUEUE                                     STD_OFF
#define CANIF_STATIC_FD_TXQUEUE                            STD_ON
#define CANIF_WAKEUP_SUPPORT                               STD_ON
#define CANIF_WAKEUP_VALIDATION                            STD_ON
#define CANIF_WAKEUP_VALID_ALL_RX_MSGS                     STD_OFF
#define CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS                 STD_ON
#define CANIF_CHECK_WAKEUP_CAN_RET_TYPE                    STD_OFF
#define CANIF_DEV_ERROR_DETECT                             STD_ON
#define CANIF_DEV_ERROR_REPORT                             STD_ON
#define CANIF_TRANSMIT_CANCELLATION                        STD_ON
#define CANIF_CANCEL_SUPPORT_API                           STD_OFF
#define CANIF_VERSION_INFO_API                             STD_OFF
#define CANIF_DLC_CHECK                                    STD_ON
#define CANIF_SUPPORT_NMOSEK_INDICATION                    STD_OFF
#define CANIF_TRCV_HANDLING                                STD_ON
#define CANIF_TRCV_MAPPING                                 STD_OFF
#define CANIF_PN_TRCV_HANDLING                             STD_OFF
#define CANIF_EXTENDEDID_SUPPORT                           STD_OFF
#define CANIF_ONE_CONTROLLER_OPTIMIZATION                  STD_OFF
#define CANIF_SETDYNAMICTXID_API                           STD_OFF
#define CANIF_PN_WU_TX_PDU_FILTER                          STD_OFF
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_OFF
#define CANIF_RX_INDICATION_TYPE_I_IS_USED                 STD_OFF
#define CANIF_RX_INDICATION_TYPE_IV_IS_USED                STD_OFF
#define CANIF_CHANGE_BAUDRATE_SUPPORT                      STD_OFF
#define CANIF_SET_BAUDRATE_API                             STD_OFF
#define CANIF_META_DATA_RX_SUPPORT                         STD_OFF
#define CANIF_META_DATA_TX_SUPPORT                         STD_OFF
#define CANIF_J1939_DYN_ADDR_SUPPORT                       CANIF_J1939_DYN_ADDR_DISABLED
#define CANIF_MULTIPLE_CANDRV_SUPPORT                      STD_OFF
#define CANIF_RX_SEARCH_CONSIDER_MSG_TYPE                  STD_ON
#define CANIF_ECUC_SAFE_BSW_CHECKS                         STD_OFF
#define CANIF_EXTENDED_RAM_CHECK_SUPPORT                   STD_OFF
#define CANIF_DATA_CHECKSUM_RX_SUPPORT                     STD_ON
#define CANIF_DATA_CHECKSUM_TX_SUPPORT                     STD_OFF
#define CANIF_SET_PDU_RECEPTION_MODE_SUPPORT               STD_OFF 
#define CANIF_BUS_MIRRORING_SUPPORT                        STD_OFF 

#define CANIF_SUPPRESS_EXTENDED_VERSION_CHECK

#ifndef CANIF_USE_DUMMY_STATEMENT
#define CANIF_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT_CONST
#define CANIF_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANIF_ATOMIC_VARIABLE_ACCESS
#define CANIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANIF_PROCESSOR_RH850_1651
#define CANIF_PROCESSOR_RH850_1651
#endif
#ifndef CANIF_COMP_GREENHILLS
#define CANIF_COMP_GREENHILLS
#endif
#ifndef CANIF_GEN_GENERATOR_MSR
#define CANIF_GEN_GENERATOR_MSR
#endif
#ifndef CANIF_CPUTYPE_BITORDER_LSB2MSB
#define CANIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CANIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_LINKTIME
#define CANIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANIF_CONFIGURATION_VARIANT
#define CANIF_CONFIGURATION_VARIANT CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANIF_POSTBUILD_VARIANT_SUPPORT
#define CANIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CANIF_CPU_TYPE_SET_IN_ECUC_MODULE                  CPU_TYPE_32

/**********************************************************************************************************************
  \def  Search algorithm
**********************************************************************************************************************/
#define CANIF_SEARCH_ALGORITHM                             CANIF_DOUBLE_HASH


/**********************************************************************************************************************
  \def  Configuration variant
**********************************************************************************************************************/
#define CANIF_CONFIG_VARIANT                               CANIF_CFGVAR_PRECOMPILETIME


/**********************************************************************************************************************
  Type definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
  \def  Tx-buffer - queue size type
**********************************************************************************************************************/
typedef uint8 CanIf_TxBufferSizeType;


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
#include "CanIf_Types.h"

/**********************************************************************************************************************
  \def  Memory mapping keywords
**********************************************************************************************************************/
#define CANIF_XCFG                                         CANIF_CONST
#define CANIF_VAR_XCFG_NOINIT                              CANIF_VAR_NOINIT


/**********************************************************************************************************************
  \def  Invalid PDU handle
**********************************************************************************************************************/
#define CanIf_TxPduHnd_INVALID                             0xFFFFu
#define CanIf_RxPduHnd_INVALID                             0xFFFFu


/**********************************************************************************************************************
  \def  Tx-buffer - handling types
**********************************************************************************************************************/
#define CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID                                                             1u
#define CANIF_TXBUFFER_HANDLINGTYPE_FIFO                                                                    2u
#define CANIF_TXBUFFER_HANDLINGTYPE_NONE                                                                    3u



/**********************************************************************************************************************
  \def  CAN controller channels - symbolic handles
**********************************************************************************************************************/

#define CanIfConf_CanIfCtrlCfg_CT_B30_for_SC_CAN_V3_2_4a04dc9c                                      0u
#define CanIfConf_CanIfCtrlCfg_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001                                  1u
#define CanIfConf_CanIfCtrlCfg_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002                                  2u


/**********************************************************************************************************************
  \def  CAN transceiver channels - symbolic handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTrcvCfg_CanIfTrcvCfg_CAN0                                                    0u
#define CanIfConf_CanIfTrcvCfg_CanIfTrcvCfg_CAN1                                                    1u
#define CanIfConf_CanIfTrcvCfg_CanIfTrcvCfg_CAN3                                                    2u





/**********************************************************************************************************************
  \def  Transceiver handling APIs
**********************************************************************************************************************/
 
#define CanTrcv_SetOpMode                                  CanTrcv_30_Tja1040_SetOpMode
#define CanTrcv_GetOpMode                                  CanTrcv_30_Tja1040_GetOpMode
#define CanTrcv_GetBusWuReason                             CanTrcv_30_Tja1040_GetBusWuReason
#define CanTrcv_SetWakeupMode                              CanTrcv_30_Tja1040_SetWakeupMode
#define CanTrcv_CheckWakeup                                CanTrcv_30_Tja1040_CheckWakeup


/**********************************************************************************************************************
  \def  Tx PDU handles
**********************************************************************************************************************/

#define CanIfTxPduHnd_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx                           0u
#define CanIfTxPduHnd_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx                              1u
#define CanIfTxPduHnd_ZCluster_Debug_Msg_0x7AF_Tx                                                   2u
#define CanIfTxPduHnd_ZCluster_Debug_Msg_0x7AE_Tx                                                   3u
#define CanIfTxPduHnd_ZCluster_Debug_Msg_0x7AD_Tx                                                   4u
#define CanIfTxPduHnd_ZCluster_Debug_Msg_0x7AC_Tx                                                   5u
#define CanIfTxPduHnd_ZCluster_Debug_Msg_0x7AB_Tx                                                   6u
#define CanIfTxPduHnd_HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx                                       7u
#define CanIfTxPduHnd_HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx                                 8u
#define CanIfTxPduHnd_HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx                                         9u
#define CanIfTxPduHnd_HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx                                         10u
#define CanIfTxPduHnd_HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx                                         11u
#define CanIfTxPduHnd_HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx                                         12u
#define CanIfTxPduHnd_HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx                                        13u
#define CanIfTxPduHnd_HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx                                        14u
#define CanIfTxPduHnd_HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx                                        15u
#define CanIfTxPduHnd_HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx                                        16u
#define CanIfTxPduHnd_HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx                                        17u
#define CanIfTxPduHnd_HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx                                        18u
#define CanIfTxPduHnd_HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx                                        19u
#define CanIfTxPduHnd_HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx                                        20u
#define CanIfTxPduHnd_HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx                                        21u
#define CanIfTxPduHnd_HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx                                        22u
#define CanIfTxPduHnd_HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx                                     23u
#define CanIfTxPduHnd_HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx                                        24u
#define CanIfTxPduHnd_HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx                                        25u
#define CanIfTxPduHnd_HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx                                        26u
#define CanIfTxPduHnd_HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx                                        27u
#define CanIfTxPduHnd_HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx                                        28u
#define CanIfTxPduHnd_HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx                                        29u
#define CanIfTxPduHnd_HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx                                        30u
#define CanIfTxPduHnd_HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx                                        31u
#define CanIfTxPduHnd_HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx                                        32u
#define CanIfTxPduHnd_HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx                                      33u
#define CanIfTxPduHnd_HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx                                      34u
#define CanIfTxPduHnd_HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx                                        35u
#define CanIfTxPduHnd_HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx                                         36u
#define CanIfTxPduHnd_HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx                                         37u
#define CanIfTxPduHnd_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx                                        38u
#define CanIfTxPduHnd_HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx                                        39u
#define CanIfTxPduHnd_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx                                        40u
#define CanIfTxPduHnd_IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx                                          41u
#define CanIfTxPduHnd_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx                                        42u
#define CanIfTxPduHnd_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx                                        43u
#define CanIfTxPduHnd_HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx                                        44u
#define CanIfTxPduHnd_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx                                      45u
#define CanIfTxPduHnd_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx                                   46u
#define CanIfTxPduHnd_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx                                        47u
#define CanIfTxPduHnd_HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx                                        48u
#define CanIfTxPduHnd_IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx                                          49u
#define CanIfTxPduHnd_IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx                                       50u
#define CanIfTxPduHnd_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx                                        51u
#define CanIfTxPduHnd_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx                                      52u
#define CanIfTxPduHnd_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx                                      53u
#define CanIfTxPduHnd_HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx                                        54u
#define CanIfTxPduHnd_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx                                      55u


/**********************************************************************************************************************
  \def  Rx PDU handles (Rx indication function specific ones)
**********************************************************************************************************************/

/* These definitions can change at Link-time and Post-build configuration time. Use them wisely. */
/* Assigned to: NULL_PTR*/
/* Assigned to: CanNm_RxIndication*/
#define CanIfRxPduHnd_NMRange_oB30_for_SC_CAN_V3_2_bdc4688d_Rx                                      0u
/* Assigned to: CanTp_RxIndication*/
#define CanIfRxPduHnd_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_030a1f56_Rx                               0u
#define CanIfRxPduHnd_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_20_5d31e3ec_Rx                            1u
#define CanIfRxPduHnd_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_9e7c1619_Rx                               2u
#define CanIfRxPduHnd_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_20_05fdfda7_Rx                            3u
/* Assigned to: PduR_CanIfRxIndication*/
#define CanIfRxPduHnd_GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_9379f94a_Rx                               0u
#define CanIfRxPduHnd_BMS30_oB30_for_SC_CAN_V3_2_457e1fbf_Rx                                        1u
#define CanIfRxPduHnd_T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_3b96f3fe_Rx                                 2u
#define CanIfRxPduHnd_AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx                                         3u
#define CanIfRxPduHnd_AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx                                      4u
#define CanIfRxPduHnd_AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx                                         5u
#define CanIfRxPduHnd_HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx                                      6u
#define CanIfRxPduHnd_BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx                                        7u
#define CanIfRxPduHnd_ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx                                        8u
#define CanIfRxPduHnd_ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx                                        9u
#define CanIfRxPduHnd_BMS66_oB30_for_SC_CAN_V3_2_d0cbb33b_Rx                                        10u
#define CanIfRxPduHnd_TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx                                     11u
#define CanIfRxPduHnd_AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx                                          12u
#define CanIfRxPduHnd_ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx                                         13u
#define CanIfRxPduHnd_CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx                                          14u
#define CanIfRxPduHnd_BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx                                        15u
#define CanIfRxPduHnd_ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx                                      16u
#define CanIfRxPduHnd_ECM24_oB30_for_SC_CAN_V3_2_f58bcd8b_Rx                                        17u
#define CanIfRxPduHnd_BCM18_oB30_for_SC_CAN_V3_2_4bcd4508_Rx                                        18u
#define CanIfRxPduHnd_BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx                                      19u
#define CanIfRxPduHnd_ETC3_oB30_for_SC_CAN_V3_2_5aaed6e3_Rx                                         20u
#define CanIfRxPduHnd_TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx                                     21u
#define CanIfRxPduHnd_RFCM_R1_oB30_for_SC_CAN_V3_2_e80a1e77_Rx                                      22u
#define CanIfRxPduHnd_RFCM_L1_oB30_for_SC_CAN_V3_2_c3d527d2_Rx                                      23u
#define CanIfRxPduHnd_HCM_R2_oB30_for_SC_CAN_V3_2_8594005d_Rx                                       24u
#define CanIfRxPduHnd_HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx                                         25u
#define CanIfRxPduHnd_BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx                                      26u
#define CanIfRxPduHnd_OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx                                         27u
#define CanIfRxPduHnd_OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx                                         28u
#define CanIfRxPduHnd_HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx                                      29u
#define CanIfRxPduHnd_DOCK1_oB30_for_SC_CAN_V3_2_ad577210_Rx                                        30u
#define CanIfRxPduHnd_BCM19_oB30_for_SC_CAN_V3_2_bc202778_Rx                                        31u
#define CanIfRxPduHnd_HCM_R1_oB30_for_SC_CAN_V3_2_c6a7a6c6_Rx                                       32u
#define CanIfRxPduHnd_RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx                                     33u
#define CanIfRxPduHnd_HCM_L1_oB30_for_SC_CAN_V3_2_838a93c0_Rx                                       34u
#define CanIfRxPduHnd_BCM11_oB30_for_SC_CAN_V3_2_6e8f2dfc_Rx                                        35u
#define CanIfRxPduHnd_HCM_L2_oB30_for_SC_CAN_V3_2_c0b9355b_Rx                                       36u
#define CanIfRxPduHnd_ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx                                        37u
#define CanIfRxPduHnd_PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx                                        38u
#define CanIfRxPduHnd_AC3_oB30_for_SC_CAN_V3_2_ea1dcaef_Rx                                          39u
#define CanIfRxPduHnd_VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx                                        40u
#define CanIfRxPduHnd_HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx                                      41u
#define CanIfRxPduHnd_AC6_oB30_for_SC_CAN_V3_2_5378f98d_Rx                                          42u
#define CanIfRxPduHnd_DDCM3_oB30_for_SC_CAN_V3_2_47eb1dc1_Rx                                        43u
#define CanIfRxPduHnd_T_BOX_FD10_oB30_for_SC_CAN_V3_2_1bbcf88b_Rx                                   44u
#define CanIfRxPduHnd_ECM16_oB30_for_SC_CAN_V3_2_3037abc8_Rx                                        45u
#define CanIfRxPduHnd_ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx                                        46u
#define CanIfRxPduHnd_AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx                                    47u
#define CanIfRxPduHnd_SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx                                         48u
#define CanIfRxPduHnd_AC7_oB30_for_SC_CAN_V3_2_74cca3c7_Rx                                          49u
#define CanIfRxPduHnd_IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx                                      50u
#define CanIfRxPduHnd_DSC4_oB30_for_SC_CAN_V3_2_c9fc5f8d_Rx                                         51u
#define CanIfRxPduHnd_PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx                                        52u
#define CanIfRxPduHnd_AC4_oB30_for_SC_CAN_V3_2_1c104d19_Rx                                          53u
#define CanIfRxPduHnd_DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx                                        54u
#define CanIfRxPduHnd_BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx                                        55u
#define CanIfRxPduHnd_DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx                                         56u
#define CanIfRxPduHnd_GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx                                       57u
#define CanIfRxPduHnd_WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx                                         58u
#define CanIfRxPduHnd_DWD1_oB30_for_SC_CAN_V3_2_e70e0616_Rx                                         59u
#define CanIfRxPduHnd_ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx                                      60u
#define CanIfRxPduHnd_ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx                                      61u
#define CanIfRxPduHnd_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx                                   62u
#define CanIfRxPduHnd_EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx                                         63u
#define CanIfRxPduHnd_BCM14_oB30_for_SC_CAN_V3_2_f035cace_Rx                                        64u
#define CanIfRxPduHnd_BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx                                         65u
#define CanIfRxPduHnd_AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx                                          66u
#define CanIfRxPduHnd_HAP_FD7_oB30_for_SC_CAN_V3_2_3a38a501_Rx                                      67u
#define CanIfRxPduHnd_AC14_oB30_for_SC_CAN_V3_2_44780039_Rx                                         68u
#define CanIfRxPduHnd_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx                                      69u
#define CanIfRxPduHnd_PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx                                        70u
#define CanIfRxPduHnd_ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx                                      71u
#define CanIfRxPduHnd_BCM7_oB30_for_SC_CAN_V3_2_09245eaf_Rx                                         72u
#define CanIfRxPduHnd_HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx                                      73u
#define CanIfRxPduHnd_ALS1_oB30_for_SC_CAN_V3_2_fa40a3a9_Rx                                         74u
#define CanIfRxPduHnd_BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx                                         75u
#define CanIfRxPduHnd_AC8_oB30_for_SC_CAN_V3_2_6412f020_Rx                                          76u
#define CanIfRxPduHnd_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx                                      77u
#define CanIfRxPduHnd_Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx                                     78u
#define CanIfRxPduHnd_ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx                                         79u
#define CanIfRxPduHnd_HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx                                      80u
#define CanIfRxPduHnd_BLE1_oB30_for_SC_CAN_V3_2_6fd972c2_Rx                                         81u
#define CanIfRxPduHnd_TOD1_oB30_for_SC_CAN_V3_2_7b636dc1_Rx                                         82u
#define CanIfRxPduHnd_HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx                                      83u
#define CanIfRxPduHnd_ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx                                         84u
#define CanIfRxPduHnd_ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx                                         85u
#define CanIfRxPduHnd_CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx                                         86u
#define CanIfRxPduHnd_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx                                   87u
#define CanIfRxPduHnd_BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx                                        88u
#define CanIfRxPduHnd_DCT_FD4_oB30_for_SC_CAN_V3_2_737de028_Rx                                      89u
#define CanIfRxPduHnd_ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx                                         90u
#define CanIfRxPduHnd_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx                                   91u
#define CanIfRxPduHnd_IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx                                      92u
#define CanIfRxPduHnd_DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx                                         93u
#define CanIfRxPduHnd_HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx                                      94u
#define CanIfRxPduHnd_T_BOX_FD9_oB30_for_SC_CAN_V3_2_18c22ff6_Rx                                    95u
#define CanIfRxPduHnd_BLE5_oB30_for_SC_CAN_V3_2_39f30a4c_Rx                                         96u
#define CanIfRxPduHnd_ETC4_oB30_for_SC_CAN_V3_2_dfa38f29_Rx                                         97u
#define CanIfRxPduHnd_ETC2_oB30_for_SC_CAN_V3_2_a29ccbe0_Rx                                         98u
#define CanIfRxPduHnd_BMS_FD14_oB30_for_SC_CAN_V3_2_d6fdd23c_Rx                                     99u
#define CanIfRxPduHnd_HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx                                      100u
#define CanIfRxPduHnd_T_BOX_FD4_oB30_for_SC_CAN_V3_2_4f1f2ee0_Rx                                    101u
#define CanIfRxPduHnd_DOCK2_oB30_for_SC_CAN_V3_2_6e11d2c1_Rx                                        102u
#define CanIfRxPduHnd_GW_OTA_oB30_for_SC_CAN_V3_2_556bd38c_Rx                                       103u
#define CanIfRxPduHnd_HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx                                      104u
#define CanIfRxPduHnd_IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx                                      105u
#define CanIfRxPduHnd_R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_89d7921d_Rx                                   106u
#define CanIfRxPduHnd_F_PBOX1_oB30_for_SC_CAN_V3_2_0d3fde0d_Rx                                      107u
#define CanIfRxPduHnd_AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx                                      108u
#define CanIfRxPduHnd_ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx                                         109u
#define CanIfRxPduHnd_RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx                                     110u
#define CanIfRxPduHnd_EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx                                         111u
#define CanIfRxPduHnd_CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx                                         112u
#define CanIfRxPduHnd_CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx                                       113u
#define CanIfRxPduHnd_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx                                      114u
#define CanIfRxPduHnd_ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx                                         115u
#define CanIfRxPduHnd_BMS65_oB30_for_SC_CAN_V3_2_138d13ea_Rx                                        116u
#define CanIfRxPduHnd_HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx                                      117u
#define CanIfRxPduHnd_EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx                                      118u
#define CanIfRxPduHnd_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx                                   119u
#define CanIfRxPduHnd_EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_3b0df78d_Rx                                 120u
#define CanIfRxPduHnd_Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx                                 121u
#define CanIfRxPduHnd_HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx                                      122u
#define CanIfRxPduHnd_ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx                                      123u
#define CanIfRxPduHnd_ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx                                         124u
#define CanIfRxPduHnd_IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx                                         125u
#define CanIfRxPduHnd_ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx                                         126u
#define CanIfRxPduHnd_HCU_HP8_oB30_for_SC_CAN_V3_2_0a33e699_Rx                                      127u
#define CanIfRxPduHnd_BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx                                         128u
#define CanIfRxPduHnd_ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx                                        129u
#define CanIfRxPduHnd_P2M3_oB30_for_SC_CAN_V3_2_c252eb72_Rx                                         130u
#define CanIfRxPduHnd_P2M1_oB30_for_SC_CAN_V3_2_e947d735_Rx                                         131u
#define CanIfRxPduHnd_DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx                                         132u
#define CanIfRxPduHnd_CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx                                         133u
#define CanIfRxPduHnd_HCU_HC16_oB30_for_SC_CAN_V3_2_1bcddd39_Rx                                     134u
#define CanIfRxPduHnd_ECM_PT5_oB30_for_SC_CAN_V3_2_df71da3f_Rx                                      135u
#define CanIfRxPduHnd_ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx                                         136u
#define CanIfRxPduHnd_ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx                                         137u
#define CanIfRxPduHnd_HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx                                      138u
#define CanIfRxPduHnd_GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx                                    139u
#define CanIfRxPduHnd_T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_52ff33bb_Rx                                 140u



/**********************************************************************************************************************
  \def  AUTOSAR Tx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTxPduCfg_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx                 0u
#define CanIfConf_CanIfTxPduCfg_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx                    1u
#define CanIfConf_CanIfTxPduCfg_ZCluster_Debug_Msg_0x7AF_Tx                                         2u
#define CanIfConf_CanIfTxPduCfg_ZCluster_Debug_Msg_0x7AE_Tx                                         3u
#define CanIfConf_CanIfTxPduCfg_ZCluster_Debug_Msg_0x7AD_Tx                                         4u
#define CanIfConf_CanIfTxPduCfg_ZCluster_Debug_Msg_0x7AC_Tx                                         5u
#define CanIfConf_CanIfTxPduCfg_ZCluster_Debug_Msg_0x7AB_Tx                                         6u
#define CanIfConf_CanIfTxPduCfg_HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx                             7u
#define CanIfConf_CanIfTxPduCfg_HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx                       8u
#define CanIfConf_CanIfTxPduCfg_HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx                               9u
#define CanIfConf_CanIfTxPduCfg_HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx                               10u
#define CanIfConf_CanIfTxPduCfg_HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx                               11u
#define CanIfConf_CanIfTxPduCfg_HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx                               12u
#define CanIfConf_CanIfTxPduCfg_HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx                              13u
#define CanIfConf_CanIfTxPduCfg_HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx                              14u
#define CanIfConf_CanIfTxPduCfg_HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx                              15u
#define CanIfConf_CanIfTxPduCfg_HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx                              16u
#define CanIfConf_CanIfTxPduCfg_HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx                              17u
#define CanIfConf_CanIfTxPduCfg_HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx                              18u
#define CanIfConf_CanIfTxPduCfg_HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx                              19u
#define CanIfConf_CanIfTxPduCfg_HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx                              20u
#define CanIfConf_CanIfTxPduCfg_HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx                              21u
#define CanIfConf_CanIfTxPduCfg_HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx                              22u
#define CanIfConf_CanIfTxPduCfg_HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx                           23u
#define CanIfConf_CanIfTxPduCfg_HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx                              24u
#define CanIfConf_CanIfTxPduCfg_HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx                              25u
#define CanIfConf_CanIfTxPduCfg_HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx                              26u
#define CanIfConf_CanIfTxPduCfg_HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx                              27u
#define CanIfConf_CanIfTxPduCfg_HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx                              28u
#define CanIfConf_CanIfTxPduCfg_HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx                              29u
#define CanIfConf_CanIfTxPduCfg_HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx                              30u
#define CanIfConf_CanIfTxPduCfg_HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx                              31u
#define CanIfConf_CanIfTxPduCfg_HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx                              32u
#define CanIfConf_CanIfTxPduCfg_HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx                            33u
#define CanIfConf_CanIfTxPduCfg_HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx                            34u
#define CanIfConf_CanIfTxPduCfg_HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx                              35u
#define CanIfConf_CanIfTxPduCfg_HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx                               36u
#define CanIfConf_CanIfTxPduCfg_HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx                               37u
#define CanIfConf_CanIfTxPduCfg_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx                              38u
#define CanIfConf_CanIfTxPduCfg_HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx                              39u
#define CanIfConf_CanIfTxPduCfg_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx                              40u
#define CanIfConf_CanIfTxPduCfg_IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx                                41u
#define CanIfConf_CanIfTxPduCfg_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx                              42u
#define CanIfConf_CanIfTxPduCfg_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx                              43u
#define CanIfConf_CanIfTxPduCfg_HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx                              44u
#define CanIfConf_CanIfTxPduCfg_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx                            45u
#define CanIfConf_CanIfTxPduCfg_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx                         46u
#define CanIfConf_CanIfTxPduCfg_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx                              47u
#define CanIfConf_CanIfTxPduCfg_HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx                              48u
#define CanIfConf_CanIfTxPduCfg_IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx                                49u
#define CanIfConf_CanIfTxPduCfg_IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx                             50u
#define CanIfConf_CanIfTxPduCfg_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx                              51u
#define CanIfConf_CanIfTxPduCfg_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx                            52u
#define CanIfConf_CanIfTxPduCfg_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx                            53u
#define CanIfConf_CanIfTxPduCfg_HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx                              54u
#define CanIfConf_CanIfTxPduCfg_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx                            55u


/**********************************************************************************************************************
  \def  AUTOSAR Rx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfRxPduCfg_NMRange_oB30_for_SC_CAN_V3_2_bdc4688d_Rx                            0u
#define CanIfConf_CanIfRxPduCfg_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_030a1f56_Rx                     1u
#define CanIfConf_CanIfRxPduCfg_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_20_5d31e3ec_Rx                  2u
#define CanIfConf_CanIfRxPduCfg_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_9e7c1619_Rx                     3u
#define CanIfConf_CanIfRxPduCfg_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_20_05fdfda7_Rx                  4u
#define CanIfConf_CanIfRxPduCfg_GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_9379f94a_Rx                     5u
#define CanIfConf_CanIfRxPduCfg_BMS30_oB30_for_SC_CAN_V3_2_457e1fbf_Rx                              6u
#define CanIfConf_CanIfRxPduCfg_T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_3b96f3fe_Rx                       7u
#define CanIfConf_CanIfRxPduCfg_AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx                               8u
#define CanIfConf_CanIfRxPduCfg_AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx                            9u
#define CanIfConf_CanIfRxPduCfg_AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx                               10u
#define CanIfConf_CanIfRxPduCfg_HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx                            11u
#define CanIfConf_CanIfRxPduCfg_BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx                              12u
#define CanIfConf_CanIfRxPduCfg_ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx                              13u
#define CanIfConf_CanIfRxPduCfg_ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx                              14u
#define CanIfConf_CanIfRxPduCfg_BMS66_oB30_for_SC_CAN_V3_2_d0cbb33b_Rx                              15u
#define CanIfConf_CanIfRxPduCfg_TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx                           16u
#define CanIfConf_CanIfRxPduCfg_AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx                                17u
#define CanIfConf_CanIfRxPduCfg_ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx                               18u
#define CanIfConf_CanIfRxPduCfg_CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx                                19u
#define CanIfConf_CanIfRxPduCfg_BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx                              20u
#define CanIfConf_CanIfRxPduCfg_ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx                            21u
#define CanIfConf_CanIfRxPduCfg_ECM24_oB30_for_SC_CAN_V3_2_f58bcd8b_Rx                              22u
#define CanIfConf_CanIfRxPduCfg_BCM18_oB30_for_SC_CAN_V3_2_4bcd4508_Rx                              23u
#define CanIfConf_CanIfRxPduCfg_BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx                            24u
#define CanIfConf_CanIfRxPduCfg_ETC3_oB30_for_SC_CAN_V3_2_5aaed6e3_Rx                               25u
#define CanIfConf_CanIfRxPduCfg_TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx                           26u
#define CanIfConf_CanIfRxPduCfg_RFCM_R1_oB30_for_SC_CAN_V3_2_e80a1e77_Rx                            27u
#define CanIfConf_CanIfRxPduCfg_RFCM_L1_oB30_for_SC_CAN_V3_2_c3d527d2_Rx                            28u
#define CanIfConf_CanIfRxPduCfg_HCM_R2_oB30_for_SC_CAN_V3_2_8594005d_Rx                             29u
#define CanIfConf_CanIfRxPduCfg_HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx                               30u
#define CanIfConf_CanIfRxPduCfg_BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx                            31u
#define CanIfConf_CanIfRxPduCfg_OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx                               32u
#define CanIfConf_CanIfRxPduCfg_OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx                               33u
#define CanIfConf_CanIfRxPduCfg_HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx                            34u
#define CanIfConf_CanIfRxPduCfg_DOCK1_oB30_for_SC_CAN_V3_2_ad577210_Rx                              35u
#define CanIfConf_CanIfRxPduCfg_BCM19_oB30_for_SC_CAN_V3_2_bc202778_Rx                              36u
#define CanIfConf_CanIfRxPduCfg_HCM_R1_oB30_for_SC_CAN_V3_2_c6a7a6c6_Rx                             37u
#define CanIfConf_CanIfRxPduCfg_RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx                           38u
#define CanIfConf_CanIfRxPduCfg_HCM_L1_oB30_for_SC_CAN_V3_2_838a93c0_Rx                             39u
#define CanIfConf_CanIfRxPduCfg_BCM11_oB30_for_SC_CAN_V3_2_6e8f2dfc_Rx                              40u
#define CanIfConf_CanIfRxPduCfg_HCM_L2_oB30_for_SC_CAN_V3_2_c0b9355b_Rx                             41u
#define CanIfConf_CanIfRxPduCfg_ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx                              42u
#define CanIfConf_CanIfRxPduCfg_PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx                              43u
#define CanIfConf_CanIfRxPduCfg_AC3_oB30_for_SC_CAN_V3_2_ea1dcaef_Rx                                44u
#define CanIfConf_CanIfRxPduCfg_VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx                              45u
#define CanIfConf_CanIfRxPduCfg_HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx                            46u
#define CanIfConf_CanIfRxPduCfg_AC6_oB30_for_SC_CAN_V3_2_5378f98d_Rx                                47u
#define CanIfConf_CanIfRxPduCfg_DDCM3_oB30_for_SC_CAN_V3_2_47eb1dc1_Rx                              48u
#define CanIfConf_CanIfRxPduCfg_T_BOX_FD10_oB30_for_SC_CAN_V3_2_1bbcf88b_Rx                         49u
#define CanIfConf_CanIfRxPduCfg_ECM16_oB30_for_SC_CAN_V3_2_3037abc8_Rx                              50u
#define CanIfConf_CanIfRxPduCfg_ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx                              51u
#define CanIfConf_CanIfRxPduCfg_AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx                          52u
#define CanIfConf_CanIfRxPduCfg_SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx                               53u
#define CanIfConf_CanIfRxPduCfg_AC7_oB30_for_SC_CAN_V3_2_74cca3c7_Rx                                54u
#define CanIfConf_CanIfRxPduCfg_IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx                            55u
#define CanIfConf_CanIfRxPduCfg_DSC4_oB30_for_SC_CAN_V3_2_c9fc5f8d_Rx                               56u
#define CanIfConf_CanIfRxPduCfg_PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx                              57u
#define CanIfConf_CanIfRxPduCfg_AC4_oB30_for_SC_CAN_V3_2_1c104d19_Rx                                58u
#define CanIfConf_CanIfRxPduCfg_DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx                              59u
#define CanIfConf_CanIfRxPduCfg_BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx                              60u
#define CanIfConf_CanIfRxPduCfg_DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx                               61u
#define CanIfConf_CanIfRxPduCfg_GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx                             62u
#define CanIfConf_CanIfRxPduCfg_WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx                               63u
#define CanIfConf_CanIfRxPduCfg_DWD1_oB30_for_SC_CAN_V3_2_e70e0616_Rx                               64u
#define CanIfConf_CanIfRxPduCfg_ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx                            65u
#define CanIfConf_CanIfRxPduCfg_ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx                            66u
#define CanIfConf_CanIfRxPduCfg_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx                         67u
#define CanIfConf_CanIfRxPduCfg_EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx                               68u
#define CanIfConf_CanIfRxPduCfg_BCM14_oB30_for_SC_CAN_V3_2_f035cace_Rx                              69u
#define CanIfConf_CanIfRxPduCfg_BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx                               70u
#define CanIfConf_CanIfRxPduCfg_AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx                                71u
#define CanIfConf_CanIfRxPduCfg_HAP_FD7_oB30_for_SC_CAN_V3_2_3a38a501_Rx                            72u
#define CanIfConf_CanIfRxPduCfg_AC14_oB30_for_SC_CAN_V3_2_44780039_Rx                               73u
#define CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx                            74u
#define CanIfConf_CanIfRxPduCfg_PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx                              75u
#define CanIfConf_CanIfRxPduCfg_ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx                            76u
#define CanIfConf_CanIfRxPduCfg_BCM7_oB30_for_SC_CAN_V3_2_09245eaf_Rx                               77u
#define CanIfConf_CanIfRxPduCfg_HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx                            78u
#define CanIfConf_CanIfRxPduCfg_ALS1_oB30_for_SC_CAN_V3_2_fa40a3a9_Rx                               79u
#define CanIfConf_CanIfRxPduCfg_BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx                               80u
#define CanIfConf_CanIfRxPduCfg_AC8_oB30_for_SC_CAN_V3_2_6412f020_Rx                                81u
#define CanIfConf_CanIfRxPduCfg_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx                            82u
#define CanIfConf_CanIfRxPduCfg_Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx                           83u
#define CanIfConf_CanIfRxPduCfg_ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx                               84u
#define CanIfConf_CanIfRxPduCfg_HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx                            85u
#define CanIfConf_CanIfRxPduCfg_BLE1_oB30_for_SC_CAN_V3_2_6fd972c2_Rx                               86u
#define CanIfConf_CanIfRxPduCfg_TOD1_oB30_for_SC_CAN_V3_2_7b636dc1_Rx                               87u
#define CanIfConf_CanIfRxPduCfg_HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx                            88u
#define CanIfConf_CanIfRxPduCfg_ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx                               89u
#define CanIfConf_CanIfRxPduCfg_ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx                               90u
#define CanIfConf_CanIfRxPduCfg_CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx                               91u
#define CanIfConf_CanIfRxPduCfg_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx                         92u
#define CanIfConf_CanIfRxPduCfg_BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx                              93u
#define CanIfConf_CanIfRxPduCfg_DCT_FD4_oB30_for_SC_CAN_V3_2_737de028_Rx                            94u
#define CanIfConf_CanIfRxPduCfg_ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx                               95u
#define CanIfConf_CanIfRxPduCfg_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx                         96u
#define CanIfConf_CanIfRxPduCfg_IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx                            97u
#define CanIfConf_CanIfRxPduCfg_DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx                               98u
#define CanIfConf_CanIfRxPduCfg_HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx                            99u
#define CanIfConf_CanIfRxPduCfg_T_BOX_FD9_oB30_for_SC_CAN_V3_2_18c22ff6_Rx                          100u
#define CanIfConf_CanIfRxPduCfg_BLE5_oB30_for_SC_CAN_V3_2_39f30a4c_Rx                               101u
#define CanIfConf_CanIfRxPduCfg_ETC4_oB30_for_SC_CAN_V3_2_dfa38f29_Rx                               102u
#define CanIfConf_CanIfRxPduCfg_ETC2_oB30_for_SC_CAN_V3_2_a29ccbe0_Rx                               103u
#define CanIfConf_CanIfRxPduCfg_BMS_FD14_oB30_for_SC_CAN_V3_2_d6fdd23c_Rx                           104u
#define CanIfConf_CanIfRxPduCfg_HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx                            105u
#define CanIfConf_CanIfRxPduCfg_T_BOX_FD4_oB30_for_SC_CAN_V3_2_4f1f2ee0_Rx                          106u
#define CanIfConf_CanIfRxPduCfg_DOCK2_oB30_for_SC_CAN_V3_2_6e11d2c1_Rx                              107u
#define CanIfConf_CanIfRxPduCfg_GW_OTA_oB30_for_SC_CAN_V3_2_556bd38c_Rx                             108u
#define CanIfConf_CanIfRxPduCfg_HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx                            109u
#define CanIfConf_CanIfRxPduCfg_IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx                            110u
#define CanIfConf_CanIfRxPduCfg_R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_89d7921d_Rx                         111u
#define CanIfConf_CanIfRxPduCfg_F_PBOX1_oB30_for_SC_CAN_V3_2_0d3fde0d_Rx                            112u
#define CanIfConf_CanIfRxPduCfg_AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx                            113u
#define CanIfConf_CanIfRxPduCfg_ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx                               114u
#define CanIfConf_CanIfRxPduCfg_RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx                           115u
#define CanIfConf_CanIfRxPduCfg_EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx                               116u
#define CanIfConf_CanIfRxPduCfg_CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx                               117u
#define CanIfConf_CanIfRxPduCfg_CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx                             118u
#define CanIfConf_CanIfRxPduCfg_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx                            119u
#define CanIfConf_CanIfRxPduCfg_ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx                               120u
#define CanIfConf_CanIfRxPduCfg_BMS65_oB30_for_SC_CAN_V3_2_138d13ea_Rx                              121u
#define CanIfConf_CanIfRxPduCfg_HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx                            122u
#define CanIfConf_CanIfRxPduCfg_EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx                            123u
#define CanIfConf_CanIfRxPduCfg_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx                         124u
#define CanIfConf_CanIfRxPduCfg_EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_3b0df78d_Rx                       125u
#define CanIfConf_CanIfRxPduCfg_Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx                       126u
#define CanIfConf_CanIfRxPduCfg_HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx                            127u
#define CanIfConf_CanIfRxPduCfg_ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx                            128u
#define CanIfConf_CanIfRxPduCfg_ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx                               129u
#define CanIfConf_CanIfRxPduCfg_IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx                               130u
#define CanIfConf_CanIfRxPduCfg_ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx                               131u
#define CanIfConf_CanIfRxPduCfg_HCU_HP8_oB30_for_SC_CAN_V3_2_0a33e699_Rx                            132u
#define CanIfConf_CanIfRxPduCfg_BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx                               133u
#define CanIfConf_CanIfRxPduCfg_ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx                              134u
#define CanIfConf_CanIfRxPduCfg_P2M3_oB30_for_SC_CAN_V3_2_c252eb72_Rx                               135u
#define CanIfConf_CanIfRxPduCfg_P2M1_oB30_for_SC_CAN_V3_2_e947d735_Rx                               136u
#define CanIfConf_CanIfRxPduCfg_DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx                               137u
#define CanIfConf_CanIfRxPduCfg_CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx                               138u
#define CanIfConf_CanIfRxPduCfg_HCU_HC16_oB30_for_SC_CAN_V3_2_1bcddd39_Rx                           139u
#define CanIfConf_CanIfRxPduCfg_ECM_PT5_oB30_for_SC_CAN_V3_2_df71da3f_Rx                            140u
#define CanIfConf_CanIfRxPduCfg_ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx                               141u
#define CanIfConf_CanIfRxPduCfg_ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx                               142u
#define CanIfConf_CanIfRxPduCfg_HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx                            143u
#define CanIfConf_CanIfRxPduCfg_GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx                          144u
#define CanIfConf_CanIfRxPduCfg_T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_52ff33bb_Rx                       145u



/**********************************************************************************************************************
  \def  Tx buffer type
**********************************************************************************************************************/

#define CanIfTxBufferType                    BYTE_QUEUE

/**********************************************************************************************************************
  \def  For ASR4.0.3/ASR4.2.2 compatibility - indirection macros
**********************************************************************************************************************/
#define  CanIf_RxIndication(Hrh, CanId, CanDlc, CanSduPtr) CanIf_RxIndicationAsr403((Hrh), (CanId), (CanDlc), (CanSduPtr)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/**********************************************************************************************************************
  \def  Transceiver handling indirection macros
**********************************************************************************************************************/

#define CanIf_30_Tja1040_TrcvModeIndication(Transceiver, TransceiverMode)                           (CanIf_TrcvModeIndication((Transceiver), TransceiverMode)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCDataSwitches  CanIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_BUSOFFNOTIFICATIONFCTPTR                                STD_ON
#define CANIF_CANCHANNELIDUPTOLOWMAP                                  STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLIDXOFCANCHANNELIDUPTOLOWMAP                 STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLUSEDOFCANCHANNELIDUPTOLOWMAP                STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHANNELINDEXOFCANCHANNELIDUPTOLOWMAP                    STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap.ChannelIndex' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBL                                            STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANCELTXFCTOFCANDRVFCTTBL                               STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CancelTxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHANGEBAUDRATEFCTOFCANDRVFCTTBL                         STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKBAUDRATEFCTOFCANDRVFCTTBL                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANDRVFCTTBL                            STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERERRORSTATEFCTOFCANDRVFCTTBL                STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERRXERRORCOUNTEROFCANDRVFCTTBL               STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERTXERRORCOUNTEROFCANDRVFCTTBL               STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLECONTROLLERFCTOFCANDRVFCTTBL               STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLEMAILBOXFCTOFCANDRVFCTTBL                  STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKEXECUTEFCTOFCANDRVFCTTBL                        STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETBAUDRATEFCTOFCANDRVFCTTBL                            STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETCONTROLLERMODEFCTOFCANDRVFCTTBL                      STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_WRITEFCTOFCANDRVFCTTBL                                  STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIG                       STD_ON
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG           STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfig.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' */
#define CANIF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_ON
#define CANIF_CANTRCVFCTTBL                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEFLAGFCTOFCANTRCVFCTTBL                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANTRCVFCTTBL                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CLEARTRCVWUFFLAGFCTOFCANTRCVFCTTBL                      STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETBUSWUREASONFCTOFCANTRCVFCTTBL                        STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETOPMODEFCTOFCANTRCVFCTTBL                             STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETOPMODEFCTOFCANTRCVFCTTBL                             STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETWAKEUPMODEFCTOFCANTRCVFCTTBL                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CTRLCONFIG                                              STD_ON
#define CANIF_FEATUREPNWUTXPDUFILTERENABLEDOFCTRLCONFIG               STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'PN wake-up Tx-PDU filter is deactivated.' */
#define CANIF_J1939DYNADDROFFSETOFCTRLCONFIG                          STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'J1939 dynamic address support is deactivated.' */
#define CANIF_J1939DYNADDRSUPPORTOFCTRLCONFIG                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'J1939 dynamic address support is deactivated.' */
#define CANIF_RXDHRANDOMNUMBER1OFCTRLCONFIG                           STD_ON
#define CANIF_RXDHRANDOMNUMBER2OFCTRLCONFIG                           STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTR                                STD_ON
#define CANIF_CTRLSTATES                                              STD_ON
#define CANIF_CTRLMODEOFCTRLSTATES                                    STD_ON
#define CANIF_PDUMODEOFCTRLSTATES                                     STD_ON
#define CANIF_WAKEUPVALIDATIONSTATEOFCTRLSTATES                       STD_ON
#define CANIF_DATACHECKSUMRXERRFCTPTR                                 STD_ON
#define CANIF_FINALMAGICNUMBER                                        STD_OFF  /**< Deactivateable: 'CanIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSION                           STD_ON
#define CANIF_GENERATORVERSION                                        STD_ON
#define CANIF_HXHOFFSET                                               STD_OFF  /**< Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_INITDATAHASHCODE                                        STD_OFF  /**< Deactivateable: 'CanIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIG                                           STD_ON
#define CANIF_CTRLSTATESIDXOFMAILBOXCONFIG                            STD_ON
#define CANIF_MAILBOXTYPEOFMAILBOXCONFIG                              STD_ON
#define CANIF_PDUIDFIRSTOFMAILBOXCONFIG                               STD_ON
#define CANIF_PDUIDLASTOFMAILBOXCONFIG                                STD_ON
#define CANIF_TXBUFFERCFGIDXOFMAILBOXCONFIG                           STD_ON
#define CANIF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                          STD_ON
#define CANIF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                     STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIG                                   STD_ON
#define CANIF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                 STD_ON
#define CANIF_MAXTRCVHANDLEIDPLUSONE                                  STD_ON
#define CANIF_MAXWAKEUPSOURCES                                        STD_ON
#define CANIF_PDURXMODE                                               STD_OFF  /**< Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANIF_RXDHADJUST                                              STD_ON
#define CANIF_RXINDICATIONFCTLIST                                     STD_ON
#define CANIF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                    STD_ON
#define CANIF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                 STD_ON
#define CANIF_RXPDUCONFIG                                             STD_ON
#define CANIF_CANIFRXPDUIDOFRXPDUCONFIG                               STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_ISCANNMRXPDUOFRXPDUCONFIG                               STD_ON
#define CANIF_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                        STD_ON
#define CANIF_MSGTYPEOFRXPDUCONFIG                                    STD_ON
#define CANIF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                     STD_ON
#define CANIF_RXMETADATALENGTHOFRXPDUCONFIG                           STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.RxMetaDataLength' Reason: 'Rx meta data support is deactivated.' */
#define CANIF_RXPDUCANIDOFRXPDUCONFIG                                 STD_ON
#define CANIF_RXPDUDLCOFRXPDUCONFIG                                   STD_ON
#define CANIF_RXPDUMASKOFRXPDUCONFIG                                  STD_ON
#define CANIF_UPPERPDUIDOFRXPDUCONFIG                                 STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                 STD_ON
#define CANIF_SIZEOFCTRLCONFIG                                        STD_ON
#define CANIF_SIZEOFCTRLSTATES                                        STD_ON
#define CANIF_SIZEOFMAILBOXCONFIG                                     STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIG                             STD_ON
#define CANIF_SIZEOFRXDHADJUST                                        STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLIST                               STD_ON
#define CANIF_SIZEOFRXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFTRCVTOCTRLMAP                                     STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASE                           STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS          STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLIST                             STD_ON
#define CANIF_SIZEOFTXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEX                                   STD_ON
#define CANIF_SIZEOFTXQUEUE                                           STD_ON
#define CANIF_SIZEOFTXQUEUEDATA                                       STD_ON
#define CANIF_SIZEOFTXQUEUEINDEX2DATASTARTSTOP                        STD_ON
#define CANIF_SIZEOFWAKEUPCONFIG                                      STD_ON
#define CANIF_TRANSCEIVERUPTOLOWMAP                                   STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_CANTRCVFCTTBLIDXOFTRANSCEIVERUPTOLOWMAP                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_CHANNELINDEXOFTRANSCEIVERUPTOLOWMAP                     STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.ChannelIndex' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_TRANSCEIVERUPTOUPPERMAP                                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_TRCVMODEINDICATIONFCTPTR                                STD_ON
#define CANIF_TRCVTOCTRLMAP                                           STD_ON
#define CANIF_TXBUFFERFIFOCONFIG                                      STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                  STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig.SizeOfOnePayloadEl' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBASE                                 STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG                       STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig.BitPos2TxPduIdOffset' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                      STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                STD_ON
#define CANIF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS STD_ON
#define CANIF_TXCONFIRMATIONFCTLIST                                   STD_ON
#define CANIF_TXPDUCONFIG                                             STD_ON
#define CANIF_CANIDOFTXPDUCONFIG                                      STD_ON
#define CANIF_CANIDTXMASKOFTXPDUCONFIG                                STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.CanIdTxMask' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_CTRLSTATESIDXOFTXPDUCONFIG                              STD_ON
#define CANIF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                        STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' */
#define CANIF_ISPNWUTXPDUOFTXPDUCONFIG                                STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' */
#define CANIF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                          STD_ON
#define CANIF_MAILBOXCONFIGIDXOFTXPDUCONFIG                           STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                   STD_ON
#define CANIF_TXMETADATALENGTHOFTXPDUCONFIG                           STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.TxMetaDataLength' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_TXPDULENGTHOFTXPDUCONFIG                                STD_ON
#define CANIF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                          STD_ON
#define CANIF_TXPDUQUEUEINDEX                                         STD_ON
#define CANIF_TXQUEUEIDXOFTXPDUQUEUEINDEX                             STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX          STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOPUSEDOFTXPDUQUEUEINDEX         STD_ON
#define CANIF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                            STD_ON
#define CANIF_TXPDUSTATIC2DYNAMICINDIRECTION                          STD_OFF  /**< Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' */
#define CANIF_TXQUEUE                                                 STD_ON
#define CANIF_TXQUEUEDATA                                             STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOP                              STD_ON
#define CANIF_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP           STD_ON
#define CANIF_TXQUEUEDATALENGTHOFTXQUEUEINDEX2DATASTARTSTOP           STD_ON
#define CANIF_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP         STD_ON
#define CANIF_TXQUEUEDATAUSEDOFTXQUEUEINDEX2DATASTARTSTOP             STD_ON
#define CANIF_ULRXPDUID2INTERNALRXPDUID                               STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGIDXOFULRXPDUID2INTERNALRXPDUID               STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGUSEDOFULRXPDUID2INTERNALRXPDUID              STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_ULTXPDUID2INTERNALTXPDUID                               STD_OFF  /**< Deactivateable: 'CanIf_UlTxPduId2InternalTxPduId' Reason: 'Configuration variant is Pre-compile!' */
#define CANIF_WAKEUPCONFIG                                            STD_ON
#define CANIF_CONTROLLEROFWAKEUPCONFIG                                STD_ON
#define CANIF_WAKEUPSOURCEOFWAKEUPCONFIG                              STD_ON
#define CANIF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                       STD_ON
#define CANIF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                        STD_ON
#define CANIF_WAKEUPVALIDATIONFCTPTR                                  STD_ON
#define CANIF_PCCONFIG                                                STD_ON
#define CANIF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG             STD_ON
#define CANIF_CTRLCONFIGOFPCCONFIG                                    STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_CTRLSTATESOFPCCONFIG                                    STD_ON
#define CANIF_DATACHECKSUMRXERRFCTPTROFPCCONFIG                       STD_ON
#define CANIF_FINALMAGICNUMBEROFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                 STD_ON
#define CANIF_GENERATORVERSIONOFPCCONFIG                              STD_ON
#define CANIF_INITDATAHASHCODEOFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIGOFPCCONFIG                                 STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                         STD_ON
#define CANIF_MAXTRCVHANDLEIDPLUSONEOFPCCONFIG                        STD_ON
#define CANIF_MAXWAKEUPSOURCESOFPCCONFIG                              STD_ON
#define CANIF_RXDHADJUSTOFPCCONFIG                                    STD_ON
#define CANIF_RXINDICATIONFCTLISTOFPCCONFIG                           STD_ON
#define CANIF_RXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG       STD_ON
#define CANIF_SIZEOFCTRLCONFIGOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFCTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFMAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIGOFPCCONFIG                   STD_ON
#define CANIF_SIZEOFRXDHADJUSTOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_SIZEOFRXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTRCVTOCTRLMAPOFPCCONFIG                           STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASEOFPCCONFIG                 STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG      STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_SIZEOFTXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                         STD_ON
#define CANIF_SIZEOFTXQUEUEDATAOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG              STD_ON
#define CANIF_SIZEOFTXQUEUEOFPCCONFIG                                 STD_ON
#define CANIF_SIZEOFWAKEUPCONFIGOFPCCONFIG                            STD_ON
#define CANIF_TRCVMODEINDICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_TRCVTOCTRLMAPOFPCCONFIG                                 STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                       STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG            STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG      STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTOFPCCONFIG                         STD_ON
#define CANIF_TXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_TXPDUQUEUEINDEXOFPCCONFIG                               STD_ON
#define CANIF_TXQUEUEDATAOFPCCONFIG                                   STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG                    STD_ON
#define CANIF_TXQUEUEOFPCCONFIG                                       STD_ON
#define CANIF_WAKEUPCONFIGOFPCCONFIG                                  STD_ON
#define CANIF_WAKEUPVALIDATIONFCTPTROFPCCONFIG                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMinNumericValueDefines  CanIf Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANIF_MIN_TXQUEUEDATA                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMaxNumericValueDefines  CanIf Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANIF_MAX_TXQUEUEDATA                                         255u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCNoReferenceDefines  CanIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG                        255u
#define CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX                          255u
#define CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX       255u
#define CANIF_NO_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP        65535u
#define CANIF_NO_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP      65535u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIsReducedToDefineDefines  CanIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_OFF
#define CANIF_ISDEF_RXDHRANDOMNUMBER1OFCTRLCONFIG                     STD_OFF
#define CANIF_ISDEF_RXDHRANDOMNUMBER2OFCTRLCONFIG                     STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFMAILBOXCONFIG                      STD_OFF
#define CANIF_ISDEF_MAILBOXTYPEOFMAILBOXCONFIG                        STD_OFF
#define CANIF_ISDEF_PDUIDFIRSTOFMAILBOXCONFIG                         STD_OFF
#define CANIF_ISDEF_PDUIDLASTOFMAILBOXCONFIG                          STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGIDXOFMAILBOXCONFIG                     STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                    STD_OFF
#define CANIF_ISDEF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG               STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG           STD_OFF
#define CANIF_ISDEF_RXDHADJUST                                        STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTOFRXINDICATIONFCTLIST              STD_OFF
#define CANIF_ISDEF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST           STD_OFF
#define CANIF_ISDEF_ISCANNMRXPDUOFRXPDUCONFIG                         STD_OFF
#define CANIF_ISDEF_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                  STD_OFF
#define CANIF_ISDEF_MSGTYPEOFRXPDUCONFIG                              STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG               STD_OFF
#define CANIF_ISDEF_RXPDUCANIDOFRXPDUCONFIG                           STD_OFF
#define CANIF_ISDEF_RXPDUDLCOFRXPDUCONFIG                             STD_OFF
#define CANIF_ISDEF_RXPDUMASKOFRXPDUCONFIG                            STD_OFF
#define CANIF_ISDEF_UPPERPDUIDOFRXPDUCONFIG                           STD_OFF
#define CANIF_ISDEF_TRCVTOCTRLMAP                                     STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLIST                             STD_OFF
#define CANIF_ISDEF_CANIDOFTXPDUCONFIG                                STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFTXPDUCONFIG                        STD_OFF
#define CANIF_ISDEF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                    STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFTXPDUCONFIG                     STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG             STD_OFF
#define CANIF_ISDEF_TXPDULENGTHOFTXPDUCONFIG                          STD_OFF
#define CANIF_ISDEF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                    STD_OFF
#define CANIF_ISDEF_TXQUEUEIDXOFTXPDUQUEUEINDEX                       STD_OFF
#define CANIF_ISDEF_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX    STD_OFF
#define CANIF_ISDEF_TXQUEUEINDEX2DATASTARTSTOPUSEDOFTXPDUQUEUEINDEX   STD_OFF
#define CANIF_ISDEF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                      STD_OFF
#define CANIF_ISDEF_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP     STD_OFF
#define CANIF_ISDEF_TXQUEUEDATALENGTHOFTXQUEUEINDEX2DATASTARTSTOP     STD_OFF
#define CANIF_ISDEF_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP   STD_OFF
#define CANIF_ISDEF_TXQUEUEDATAUSEDOFTXQUEUEINDEX2DATASTARTSTOP       STD_OFF
#define CANIF_ISDEF_CONTROLLEROFWAKEUPCONFIG                          STD_OFF
#define CANIF_ISDEF_WAKEUPSOURCEOFWAKEUPCONFIG                        STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                 STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                  STD_OFF
#define CANIF_ISDEF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG       STD_ON
#define CANIF_ISDEF_CTRLCONFIGOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_DATACHECKSUMRXERRFCTPTROFPCCONFIG                 STD_ON
#define CANIF_ISDEF_MAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                   STD_ON
#define CANIF_ISDEF_RXDHADJUSTOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_RXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_ISDEF_RXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TRCVMODEINDICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_TRCVTOCTRLMAPOFPCCONFIG                           STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                 STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG      STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG STD_ON
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_ISDEF_TXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TXPDUQUEUEINDEXOFPCCONFIG                         STD_ON
#define CANIF_ISDEF_TXQUEUEDATAOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG              STD_ON
#define CANIF_ISDEF_TXQUEUEOFPCCONFIG                                 STD_ON
#define CANIF_ISDEF_WAKEUPCONFIGOFPCCONFIG                            STD_ON
#define CANIF_ISDEF_WAKEUPVALIDATIONFCTPTROFPCCONFIG                  STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEqualsAlwaysToDefines  CanIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG 
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG 
#define CANIF_EQ2_RXDHRANDOMNUMBER1OFCTRLCONFIG                       
#define CANIF_EQ2_RXDHRANDOMNUMBER2OFCTRLCONFIG                       
#define CANIF_EQ2_CTRLSTATESIDXOFMAILBOXCONFIG                        
#define CANIF_EQ2_MAILBOXTYPEOFMAILBOXCONFIG                          
#define CANIF_EQ2_PDUIDFIRSTOFMAILBOXCONFIG                           
#define CANIF_EQ2_PDUIDLASTOFMAILBOXCONFIG                            
#define CANIF_EQ2_TXBUFFERCFGIDXOFMAILBOXCONFIG                       
#define CANIF_EQ2_TXBUFFERCFGUSEDOFMAILBOXCONFIG                      
#define CANIF_EQ2_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                 
#define CANIF_EQ2_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG             
#define CANIF_EQ2_RXDHADJUST                                          
#define CANIF_EQ2_RXINDICATIONFCTOFRXINDICATIONFCTLIST                
#define CANIF_EQ2_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST             
#define CANIF_EQ2_ISCANNMRXPDUOFRXPDUCONFIG                           
#define CANIF_EQ2_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                    
#define CANIF_EQ2_MSGTYPEOFRXPDUCONFIG                                
#define CANIF_EQ2_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                 
#define CANIF_EQ2_RXPDUCANIDOFRXPDUCONFIG                             
#define CANIF_EQ2_RXPDUDLCOFRXPDUCONFIG                               
#define CANIF_EQ2_RXPDUMASKOFRXPDUCONFIG                              
#define CANIF_EQ2_UPPERPDUIDOFRXPDUCONFIG                             
#define CANIF_EQ2_TRCVTOCTRLMAP                                       
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS 
#define CANIF_EQ2_TXCONFIRMATIONFCTLIST                               
#define CANIF_EQ2_CANIDOFTXPDUCONFIG                                  
#define CANIF_EQ2_CTRLSTATESIDXOFTXPDUCONFIG                          
#define CANIF_EQ2_ISTXPDUTRUNCATIONOFTXPDUCONFIG                      
#define CANIF_EQ2_MAILBOXCONFIGIDXOFTXPDUCONFIG                       
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG               
#define CANIF_EQ2_TXPDULENGTHOFTXPDUCONFIG                            
#define CANIF_EQ2_UPPERLAYERTXPDUIDOFTXPDUCONFIG                      
#define CANIF_EQ2_TXQUEUEIDXOFTXPDUQUEUEINDEX                         
#define CANIF_EQ2_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX      
#define CANIF_EQ2_TXQUEUEINDEX2DATASTARTSTOPUSEDOFTXPDUQUEUEINDEX     
#define CANIF_EQ2_TXQUEUEUSEDOFTXPDUQUEUEINDEX                        
#define CANIF_EQ2_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP       
#define CANIF_EQ2_TXQUEUEDATALENGTHOFTXQUEUEINDEX2DATASTARTSTOP       
#define CANIF_EQ2_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP     
#define CANIF_EQ2_TXQUEUEDATAUSEDOFTXQUEUEINDEX2DATASTARTSTOP         
#define CANIF_EQ2_CONTROLLEROFWAKEUPCONFIG                            
#define CANIF_EQ2_WAKEUPSOURCEOFWAKEUPCONFIG                          
#define CANIF_EQ2_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                   
#define CANIF_EQ2_WAKEUPTARGETMODULEOFWAKEUPCONFIG                    
#define CANIF_EQ2_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                  CanIf_BusOffNotificationFctPtr
#define CANIF_EQ2_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG         CanIf_CanIfCtrlId2MappedTxBuffersConfig
#define CANIF_EQ2_CTRLCONFIGOFPCCONFIG                                CanIf_CtrlConfig
#define CANIF_EQ2_CTRLMODEINDICATIONFCTPTROFPCCONFIG                  CanIf_CtrlModeIndicationFctPtr
#define CANIF_EQ2_CTRLSTATESOFPCCONFIG                                CanIf_CtrlStates.raw
#define CANIF_EQ2_DATACHECKSUMRXERRFCTPTROFPCCONFIG                   CanIf_DataChecksumRxErrFctPtr
#define CANIF_EQ2_MAILBOXCONFIGOFPCCONFIG                             CanIf_MailBoxConfig
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                     CanIf_MappedTxBuffersConfig
#define CANIF_EQ2_RXDHADJUSTOFPCCONFIG                                CanIf_RxDHAdjust
#define CANIF_EQ2_RXINDICATIONFCTLISTOFPCCONFIG                       CanIf_RxIndicationFctList
#define CANIF_EQ2_RXPDUCONFIGOFPCCONFIG                               CanIf_RxPduConfig
#define CANIF_EQ2_TRCVMODEINDICATIONFCTPTROFPCCONFIG                  CanIf_TrcvModeIndicationFctPtr
#define CANIF_EQ2_TRCVTOCTRLMAPOFPCCONFIG                             CanIf_TrcvToCtrlMap
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                   CanIf_TxBufferPrioByCanIdBase.raw
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG        CanIf_TxBufferPrioByCanIdByteQueueConfig
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTOFPCCONFIG                     CanIf_TxConfirmationFctList
#define CANIF_EQ2_TXPDUCONFIGOFPCCONFIG                               CanIf_TxPduConfig
#define CANIF_EQ2_TXPDUQUEUEINDEXOFPCCONFIG                           CanIf_TxPduQueueIndex
#define CANIF_EQ2_TXQUEUEDATAOFPCCONFIG                               CanIf_TxQueueData.raw
#define CANIF_EQ2_TXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG                CanIf_TxQueueIndex2DataStartStop
#define CANIF_EQ2_TXQUEUEOFPCCONFIG                                   CanIf_TxQueue.raw
#define CANIF_EQ2_WAKEUPCONFIGOFPCCONFIG                              CanIf_WakeUpConfig
#define CANIF_EQ2_WAKEUPVALIDATIONFCTPTROFPCCONFIG                    CanIf_WakeUpValidationFctPtr
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicInitializationPointers  CanIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanIf_Config_Ptr                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanIf' */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCInitializationSymbols  CanIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanIf_Config                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanIf */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGeneral  CanIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANIF_CHECK_INIT_POINTER                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANIF_FINAL_MAGIC_NUMBER                                      0x3C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanIf */
#define CANIF_INDIVIDUAL_POSTBUILD                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanIf' is not configured to be postbuild capable. */
#define CANIF_INIT_DATA                                               CANIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANIF_INIT_DATA_HASH_CODE                                     -713533440  /**< the precompile constant to validate the initialization structure at initialization time of CanIf with a hashcode. The seed value is '0x3C1Eu' */
#define CANIF_USE_ECUM_BSW_ERROR_HOOK                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANIF_USE_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer CanIf shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfLTDataSwitches  CanIf Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_LTCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPBDataSwitches  CanIf Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_PBCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_LTCONFIGIDXOFPBCONFIG                                   STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_PCCONFIGIDXOFPBCONFIG                                   STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCGetConstantDuplicatedRootDataMacros  CanIf Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtrOfPCConfig()                 CanIf_BusOffNotificationFctPtr  /**< the pointer to CanIf_BusOffNotificationFctPtr */
#define CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()        CanIf_CanIfCtrlId2MappedTxBuffersConfig  /**< the pointer to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetCtrlConfigOfPCConfig()                               CanIf_CtrlConfig  /**< the pointer to CanIf_CtrlConfig */
#define CanIf_GetCtrlModeIndicationFctPtrOfPCConfig()                 CanIf_CtrlModeIndicationFctPtr  /**< the pointer to CanIf_CtrlModeIndicationFctPtr */
#define CanIf_GetCtrlStatesOfPCConfig()                               CanIf_CtrlStates.raw  /**< the pointer to CanIf_CtrlStates */
#define CanIf_GetDataChecksumRxErrFctPtrOfPCConfig()                  CanIf_DataChecksumRxErrFctPtr  /**< the pointer to CanIf_DataChecksumRxErrFctPtr */
#define CanIf_GetGeneratorCompatibilityVersionOfPCConfig()            0x0212u
#define CanIf_GetGeneratorVersionOfPCConfig()                         0x00041500u
#define CanIf_GetMailBoxConfigOfPCConfig()                            CanIf_MailBoxConfig  /**< the pointer to CanIf_MailBoxConfig */
#define CanIf_GetMappedTxBuffersConfigOfPCConfig()                    CanIf_MappedTxBuffersConfig  /**< the pointer to CanIf_MappedTxBuffersConfig */
#define CanIf_GetMaxTrcvHandleIdPlusOneOfPCConfig()                   3u
#define CanIf_GetMaxWakeUpSourcesOfPCConfig()                         2u
#define CanIf_GetRxDHAdjustOfPCConfig()                               CanIf_RxDHAdjust  /**< the pointer to CanIf_RxDHAdjust */
#define CanIf_GetRxIndicationFctListOfPCConfig()                      CanIf_RxIndicationFctList  /**< the pointer to CanIf_RxIndicationFctList */
#define CanIf_GetRxPduConfigOfPCConfig()                              CanIf_RxPduConfig  /**< the pointer to CanIf_RxPduConfig */
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()  3u  /**< the number of accomplishable value elements in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetSizeOfCtrlConfigOfPCConfig()                         3u  /**< the number of accomplishable value elements in CanIf_CtrlConfig */
#define CanIf_GetSizeOfCtrlStatesOfPCConfig()                         3u  /**< the number of accomplishable value elements in CanIf_CtrlStates */
#define CanIf_GetSizeOfMailBoxConfigOfPCConfig()                      24u  /**< the number of accomplishable value elements in CanIf_MailBoxConfig */
#define CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()              1u  /**< the number of accomplishable value elements in CanIf_MappedTxBuffersConfig */
#define CanIf_GetSizeOfRxDHAdjustOfPCConfig()                         197u  /**< the number of accomplishable value elements in CanIf_RxDHAdjust */
#define CanIf_GetSizeOfRxIndicationFctListOfPCConfig()                4u  /**< the number of accomplishable value elements in CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfRxPduConfigOfPCConfig()                        146u  /**< the number of accomplishable value elements in CanIf_RxPduConfig */
#define CanIf_GetSizeOfTrcvToCtrlMapOfPCConfig()                      3u  /**< the number of accomplishable value elements in CanIf_TrcvToCtrlMap */
#define CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()            1u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig() 1u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() 38u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
#define CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()              4u  /**< the number of accomplishable value elements in CanIf_TxConfirmationFctList */
#define CanIf_GetSizeOfTxPduConfigOfPCConfig()                        56u  /**< the number of accomplishable value elements in CanIf_TxPduConfig */
#define CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()                    56u  /**< the number of accomplishable value elements in CanIf_TxPduQueueIndex */
#define CanIf_GetSizeOfTxQueueDataOfPCConfig()                        712u  /**< the number of accomplishable value elements in CanIf_TxQueueData */
#define CanIf_GetSizeOfTxQueueIndex2DataStartStopOfPCConfig()         38u  /**< the number of accomplishable value elements in CanIf_TxQueueIndex2DataStartStop */
#define CanIf_GetSizeOfTxQueueOfPCConfig()                            38u  /**< the number of accomplishable value elements in CanIf_TxQueue */
#define CanIf_GetSizeOfWakeUpConfigOfPCConfig()                       2u  /**< the number of accomplishable value elements in CanIf_WakeUpConfig */
#define CanIf_GetTrcvModeIndicationFctPtrOfPCConfig()                 CanIf_TrcvModeIndicationFctPtr  /**< the pointer to CanIf_TrcvModeIndicationFctPtr */
#define CanIf_GetTrcvToCtrlMapOfPCConfig()                            CanIf_TrcvToCtrlMap  /**< the pointer to CanIf_TrcvToCtrlMap */
#define CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()                  CanIf_TxBufferPrioByCanIdBase.raw  /**< the pointer to CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()       CanIf_TxBufferPrioByCanIdByteQueueConfig  /**< the pointer to CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus  /**< the pointer to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
#define CanIf_GetTxConfirmationFctListOfPCConfig()                    CanIf_TxConfirmationFctList  /**< the pointer to CanIf_TxConfirmationFctList */
#define CanIf_GetTxPduConfigOfPCConfig()                              CanIf_TxPduConfig  /**< the pointer to CanIf_TxPduConfig */
#define CanIf_GetTxPduQueueIndexOfPCConfig()                          CanIf_TxPduQueueIndex  /**< the pointer to CanIf_TxPduQueueIndex */
#define CanIf_GetTxQueueDataOfPCConfig()                              CanIf_TxQueueData.raw  /**< the pointer to CanIf_TxQueueData */
#define CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()               CanIf_TxQueueIndex2DataStartStop  /**< the pointer to CanIf_TxQueueIndex2DataStartStop */
#define CanIf_GetTxQueueOfPCConfig()                                  CanIf_TxQueue.raw  /**< the pointer to CanIf_TxQueue */
#define CanIf_GetWakeUpConfigOfPCConfig()                             CanIf_WakeUpConfig  /**< the pointer to CanIf_WakeUpConfig */
#define CanIf_GetWakeUpValidationFctPtrOfPCConfig()                   CanIf_WakeUpValidationFctPtr  /**< the pointer to CanIf_WakeUpValidationFctPtr */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDataMacros  CanIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtr()                           (CanIf_GetBusOffNotificationFctPtrOfPCConfig())
#define CanIf_GetMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index) (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index) (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetRxDHRandomNumber1OfCtrlConfig(Index)                 (CanIf_GetCtrlConfigOfPCConfig()[(Index)].RxDHRandomNumber1OfCtrlConfig)
#define CanIf_GetRxDHRandomNumber2OfCtrlConfig(Index)                 (CanIf_GetCtrlConfigOfPCConfig()[(Index)].RxDHRandomNumber2OfCtrlConfig)
#define CanIf_GetCtrlModeIndicationFctPtr()                           (CanIf_GetCtrlModeIndicationFctPtrOfPCConfig())
#define CanIf_GetCtrlModeOfCtrlStates(Index)                          (CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates)
#define CanIf_GetPduModeOfCtrlStates(Index)                           (CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates)
#define CanIf_GetWakeUpValidationStateOfCtrlStates(Index)             (CanIf_GetCtrlStatesOfPCConfig()[(Index)].WakeUpValidationStateOfCtrlStates)
#define CanIf_GetDataChecksumRxErrFctPtr()                            (CanIf_GetDataChecksumRxErrFctPtrOfPCConfig())
#define CanIf_GetCtrlStatesIdxOfMailBoxConfig(Index)                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].CtrlStatesIdxOfMailBoxConfig)
#define CanIf_GetMailBoxTypeOfMailBoxConfig(Index)                    (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].MailBoxTypeOfMailBoxConfig)
#define CanIf_GetPduIdFirstOfMailBoxConfig(Index)                     (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdFirstOfMailBoxConfig)
#define CanIf_GetPduIdLastOfMailBoxConfig(Index)                      (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdLastOfMailBoxConfig)
#define CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index)                 (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgIdxOfMailBoxConfig)
#define CanIf_GetTxBufferHandlingTypeOfMailBoxConfig(Index)           (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferHandlingTypeOfMailBoxConfig)
#define CanIf_GetMailBoxConfigIdxOfMappedTxBuffersConfig(Index)       (CanIf_GetMappedTxBuffersConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfMappedTxBuffersConfig)
#define CanIf_GetRxDHAdjust(Index)                                    (CanIf_GetRxDHAdjustOfPCConfig()[(Index)])
#define CanIf_GetRxIndicationFctOfRxIndicationFctList(Index)          (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationFctOfRxIndicationFctList)
#define CanIf_GetRxIndicationLayoutOfRxIndicationFctList(Index)       (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationLayoutOfRxIndicationFctList)
#define CanIf_IsIsCanNmRxPduOfRxPduConfig(Index)                      ((CanIf_GetRxPduConfigOfPCConfig()[(Index)].IsCanNmRxPduOfRxPduConfig) != FALSE)
#define CanIf_IsIsDataChecksumRxPduOfRxPduConfig(Index)               ((CanIf_GetRxPduConfigOfPCConfig()[(Index)].IsDataChecksumRxPduOfRxPduConfig) != FALSE)
#define CanIf_GetMsgTypeOfRxPduConfig(Index)                          (CanIf_GetRxPduConfigOfPCConfig()[(Index)].MsgTypeOfRxPduConfig)
#define CanIf_GetRxIndicationFctListIdxOfRxPduConfig(Index)           (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxIndicationFctListIdxOfRxPduConfig)
#define CanIf_GetRxPduCanIdOfRxPduConfig(Index)                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduCanIdOfRxPduConfig)
#define CanIf_GetRxPduDlcOfRxPduConfig(Index)                         (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduDlcOfRxPduConfig)
#define CanIf_GetRxPduMaskOfRxPduConfig(Index)                        (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduMaskOfRxPduConfig)
#define CanIf_GetUpperPduIdOfRxPduConfig(Index)                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].UpperPduIdOfRxPduConfig)
#define CanIf_GetTrcvModeIndicationFctPtr()                           (CanIf_GetTrcvModeIndicationFctPtrOfPCConfig())
#define CanIf_GetTrcvToCtrlMap(Index)                                 (CanIf_GetTrcvToCtrlMapOfPCConfig()[(Index)])
#define CanIf_GetTxBufferPrioByCanIdBase(Index)                       (CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)])
#define CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()[(Index)].TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus)
#define CanIf_GetTxConfirmationFctList(Index)                         (CanIf_GetTxConfirmationFctListOfPCConfig()[(Index)])
#define CanIf_GetCanIdOfTxPduConfig(Index)                            (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdOfTxPduConfig)
#define CanIf_GetCtrlStatesIdxOfTxPduConfig(Index)                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CtrlStatesIdxOfTxPduConfig)
#define CanIf_IsIsTxPduTruncationOfTxPduConfig(Index)                 ((CanIf_GetTxPduConfigOfPCConfig()[(Index)].IsTxPduTruncationOfTxPduConfig) != FALSE)
#define CanIf_GetMailBoxConfigIdxOfTxPduConfig(Index)                 (CanIf_GetTxPduConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfTxPduConfig)
#define CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(Index)         (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxConfirmationFctListIdxOfTxPduConfig)
#define CanIf_GetTxPduLengthOfTxPduConfig(Index)                      (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxPduLengthOfTxPduConfig)
#define CanIf_GetUpperLayerTxPduIdOfTxPduConfig(Index)                (CanIf_GetTxPduConfigOfPCConfig()[(Index)].UpperLayerTxPduIdOfTxPduConfig)
#define CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index)                   (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueueIndex2DataStartStopIdxOfTxPduQueueIndex(Index) (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueue(Index)                                       (CanIf_GetTxQueueOfPCConfig()[(Index)])
#define CanIf_GetTxQueueData(Index)                                   (CanIf_GetTxQueueDataOfPCConfig()[(Index)])
#define CanIf_GetTxQueueDataEndIdxOfTxQueueIndex2DataStartStop(Index) (CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()[(Index)].TxQueueDataEndIdxOfTxQueueIndex2DataStartStop)
#define CanIf_GetTxQueueDataLengthOfTxQueueIndex2DataStartStop(Index) (CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()[(Index)].TxQueueDataLengthOfTxQueueIndex2DataStartStop)
#define CanIf_GetTxQueueDataStartIdxOfTxQueueIndex2DataStartStop(Index) (CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()[(Index)].TxQueueDataStartIdxOfTxQueueIndex2DataStartStop)
#define CanIf_GetControllerOfWakeUpConfig(Index)                      (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].ControllerOfWakeUpConfig)
#define CanIf_GetWakeUpSourceOfWakeUpConfig(Index)                    ((EcuM_WakeupSourceType)CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpSourceOfWakeUpConfig)
#define CanIf_GetWakeUpTargetAddressOfWakeUpConfig(Index)             (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpTargetAddressOfWakeUpConfig)
#define CanIf_GetWakeUpTargetModuleOfWakeUpConfig(Index)              (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpTargetModuleOfWakeUpConfig)
#define CanIf_GetWakeUpValidationFctPtr()                             (CanIf_GetWakeUpValidationFctPtrOfPCConfig())
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDeduplicatedDataMacros  CanIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanIf_GetGeneratorCompatibilityVersion()                      CanIf_GetGeneratorCompatibilityVersionOfPCConfig()
#define CanIf_GetGeneratorVersion()                                   CanIf_GetGeneratorVersionOfPCConfig()
#define CanIf_IsTxBufferCfgUsedOfMailBoxConfig(Index)                 (((boolean)(CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index) != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetMaxTrcvHandleIdPlusOne()                             CanIf_GetMaxTrcvHandleIdPlusOneOfPCConfig()
#define CanIf_GetMaxWakeUpSources()                                   CanIf_GetMaxWakeUpSourcesOfPCConfig()
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfig()            CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlConfig()                                   CanIf_GetSizeOfCtrlConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlStates()                                   CanIf_GetSizeOfCtrlStatesOfPCConfig()
#define CanIf_GetSizeOfMailBoxConfig()                                CanIf_GetSizeOfMailBoxConfigOfPCConfig()
#define CanIf_GetSizeOfMappedTxBuffersConfig()                        CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfRxDHAdjust()                                   CanIf_GetSizeOfRxDHAdjustOfPCConfig()
#define CanIf_GetSizeOfRxIndicationFctList()                          CanIf_GetSizeOfRxIndicationFctListOfPCConfig()
#define CanIf_GetSizeOfRxPduConfig()                                  CanIf_GetSizeOfRxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTrcvToCtrlMap()                                CanIf_GetSizeOfTrcvToCtrlMapOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdBase()                      CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfig()           CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()     CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()
#define CanIf_GetSizeOfTxConfirmationFctList()                        CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()
#define CanIf_GetSizeOfTxPduConfig()                                  CanIf_GetSizeOfTxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxPduQueueIndex()                              CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()
#define CanIf_GetSizeOfTxQueue()                                      CanIf_GetSizeOfTxQueueOfPCConfig()
#define CanIf_GetSizeOfTxQueueData()                                  CanIf_GetSizeOfTxQueueDataOfPCConfig()
#define CanIf_GetSizeOfTxQueueIndex2DataStartStop()                   CanIf_GetSizeOfTxQueueIndex2DataStartStopOfPCConfig()
#define CanIf_GetSizeOfWakeUpConfig()                                 CanIf_GetSizeOfWakeUpConfigOfPCConfig()
#define CanIf_IsTxQueueIndex2DataStartStopUsedOfTxPduQueueIndex(Index) (((boolean)(CanIf_GetTxQueueIndex2DataStartStopIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxQueueIndex2DataStartStop */
#define CanIf_IsTxQueueUsedOfTxPduQueueIndex(Index)                   (((boolean)(CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxQueue */
#define CanIf_IsTxQueueDataUsedOfTxQueueIndex2DataStartStop(Index)    (((boolean)(CanIf_GetTxQueueDataLengthOfTxQueueIndex2DataStartStop(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanIf_TxQueueData */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSetDataMacros  CanIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanIf_SetCtrlModeOfCtrlStates(Index, Value)                   CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates = (Value)
#define CanIf_SetPduModeOfCtrlStates(Index, Value)                    CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates = (Value)
#define CanIf_SetWakeUpValidationStateOfCtrlStates(Index, Value)      CanIf_GetCtrlStatesOfPCConfig()[(Index)].WakeUpValidationStateOfCtrlStates = (Value)
#define CanIf_SetTxBufferPrioByCanIdBase(Index, Value)                CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueue(Index, Value)                                CanIf_GetTxQueueOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueueData(Index, Value)                            CanIf_GetTxQueueDataOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetAddressOfDataMacros  CanIf Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanIf_GetAddrTxQueueData(Index)                               (&CanIf_GetTxQueueData(Index))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCHasMacros  CanIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanIf_HasBusOffNotificationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfig()                  (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig() (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig() (TRUE != FALSE)
#define CanIf_HasCtrlConfig()                                         (TRUE != FALSE)
#define CanIf_HasRxDHRandomNumber1OfCtrlConfig()                      (TRUE != FALSE)
#define CanIf_HasRxDHRandomNumber2OfCtrlConfig()                      (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasCtrlStates()                                         (TRUE != FALSE)
#define CanIf_HasCtrlModeOfCtrlStates()                               (TRUE != FALSE)
#define CanIf_HasPduModeOfCtrlStates()                                (TRUE != FALSE)
#define CanIf_HasWakeUpValidationStateOfCtrlStates()                  (TRUE != FALSE)
#define CanIf_HasDataChecksumRxErrFctPtr()                            (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersion()                      (TRUE != FALSE)
#define CanIf_HasGeneratorVersion()                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfig()                                      (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfMailBoxConfig()                       (TRUE != FALSE)
#define CanIf_HasMailBoxTypeOfMailBoxConfig()                         (TRUE != FALSE)
#define CanIf_HasPduIdFirstOfMailBoxConfig()                          (TRUE != FALSE)
#define CanIf_HasPduIdLastOfMailBoxConfig()                           (TRUE != FALSE)
#define CanIf_HasTxBufferCfgIdxOfMailBoxConfig()                      (TRUE != FALSE)
#define CanIf_HasTxBufferCfgUsedOfMailBoxConfig()                     (TRUE != FALSE)
#define CanIf_HasTxBufferHandlingTypeOfMailBoxConfig()                (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfig()                              (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfMappedTxBuffersConfig()            (TRUE != FALSE)
#define CanIf_HasMaxTrcvHandleIdPlusOne()                             (TRUE != FALSE)
#define CanIf_HasMaxWakeUpSources()                                   (TRUE != FALSE)
#define CanIf_HasRxDHAdjust()                                         (TRUE != FALSE)
#define CanIf_HasRxIndicationFctList()                                (TRUE != FALSE)
#define CanIf_HasRxIndicationFctOfRxIndicationFctList()               (TRUE != FALSE)
#define CanIf_HasRxIndicationLayoutOfRxIndicationFctList()            (TRUE != FALSE)
#define CanIf_HasRxPduConfig()                                        (TRUE != FALSE)
#define CanIf_HasIsCanNmRxPduOfRxPduConfig()                          (TRUE != FALSE)
#define CanIf_HasIsDataChecksumRxPduOfRxPduConfig()                   (TRUE != FALSE)
#define CanIf_HasMsgTypeOfRxPduConfig()                               (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListIdxOfRxPduConfig()                (TRUE != FALSE)
#define CanIf_HasRxPduCanIdOfRxPduConfig()                            (TRUE != FALSE)
#define CanIf_HasRxPduDlcOfRxPduConfig()                              (TRUE != FALSE)
#define CanIf_HasRxPduMaskOfRxPduConfig()                             (TRUE != FALSE)
#define CanIf_HasUpperPduIdOfRxPduConfig()                            (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfig()            (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlConfig()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStates()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfRxDHAdjust()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctList()                          (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTrcvToCtrlMap()                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBase()                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfig()           (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()     (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctList()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndex()                              (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueue()                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueData()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueIndex2DataStartStop()                   (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfig()                                 (TRUE != FALSE)
#define CanIf_HasTrcvModeIndicationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasTrcvToCtrlMap()                                      (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBase()                            (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfig()                 (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdus()           (TRUE != FALSE)
#define CanIf_HasTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus() (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctList()                              (TRUE != FALSE)
#define CanIf_HasTxPduConfig()                                        (TRUE != FALSE)
#define CanIf_HasCanIdOfTxPduConfig()                                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfTxPduConfig()                         (TRUE != FALSE)
#define CanIf_HasIsTxPduTruncationOfTxPduConfig()                     (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfTxPduConfig()                      (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListIdxOfTxPduConfig()              (TRUE != FALSE)
#define CanIf_HasTxPduLengthOfTxPduConfig()                           (TRUE != FALSE)
#define CanIf_HasUpperLayerTxPduIdOfTxPduConfig()                     (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndex()                                    (TRUE != FALSE)
#define CanIf_HasTxQueueIdxOfTxPduQueueIndex()                        (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStopIdxOfTxPduQueueIndex()     (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStopUsedOfTxPduQueueIndex()    (TRUE != FALSE)
#define CanIf_HasTxQueueUsedOfTxPduQueueIndex()                       (TRUE != FALSE)
#define CanIf_HasTxQueue()                                            (TRUE != FALSE)
#define CanIf_HasTxQueueData()                                        (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStop()                         (TRUE != FALSE)
#define CanIf_HasTxQueueDataEndIdxOfTxQueueIndex2DataStartStop()      (TRUE != FALSE)
#define CanIf_HasTxQueueDataLengthOfTxQueueIndex2DataStartStop()      (TRUE != FALSE)
#define CanIf_HasTxQueueDataStartIdxOfTxQueueIndex2DataStartStop()    (TRUE != FALSE)
#define CanIf_HasTxQueueDataUsedOfTxQueueIndex2DataStartStop()        (TRUE != FALSE)
#define CanIf_HasWakeUpConfig()                                       (TRUE != FALSE)
#define CanIf_HasControllerOfWakeUpConfig()                           (TRUE != FALSE)
#define CanIf_HasWakeUpSourceOfWakeUpConfig()                         (TRUE != FALSE)
#define CanIf_HasWakeUpTargetAddressOfWakeUpConfig()                  (TRUE != FALSE)
#define CanIf_HasWakeUpTargetModuleOfWakeUpConfig()                   (TRUE != FALSE)
#define CanIf_HasWakeUpValidationFctPtr()                             (TRUE != FALSE)
#define CanIf_HasPCConfig()                                           (TRUE != FALSE)
#define CanIf_HasBusOffNotificationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()        (TRUE != FALSE)
#define CanIf_HasCtrlConfigOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasDataChecksumRxErrFctPtrOfPCConfig()                  (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersionOfPCConfig()            (TRUE != FALSE)
#define CanIf_HasGeneratorVersionOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasMailBoxConfigOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasMaxTrcvHandleIdPlusOneOfPCConfig()                   (TRUE != FALSE)
#define CanIf_HasMaxWakeUpSourcesOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasRxDHAdjustOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasRxPduConfigOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()  (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlConfigOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStatesOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfigOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfigOfPCConfig()              (TRUE != FALSE)
#define CanIf_HasSizeOfRxDHAdjustOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctListOfPCConfig()                (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTrcvToCtrlMapOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBaseOfPCConfig()            (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig() (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctListOfPCConfig()              (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndexOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueDataOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueIndex2DataStartStopOfPCConfig()         (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfigOfPCConfig()                       (TRUE != FALSE)
#define CanIf_HasTrcvModeIndicationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasTrcvToCtrlMapOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseOfPCConfig()                  (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfigOfPCConfig()       (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasTxPduConfigOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndexOfPCConfig()                          (TRUE != FALSE)
#define CanIf_HasTxQueueDataOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStopOfPCConfig()               (TRUE != FALSE)
#define CanIf_HasTxQueueOfPCConfig()                                  (TRUE != FALSE)
#define CanIf_HasWakeUpConfigOfPCConfig()                             (TRUE != FALSE)
#define CanIf_HasWakeUpValidationFctPtrOfPCConfig()                   (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIncrementDataMacros  CanIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanIf_IncCtrlModeOfCtrlStates(Index)                          CanIf_GetCtrlModeOfCtrlStates(Index)++
#define CanIf_IncPduModeOfCtrlStates(Index)                           CanIf_GetPduModeOfCtrlStates(Index)++
#define CanIf_IncWakeUpValidationStateOfCtrlStates(Index)             CanIf_GetWakeUpValidationStateOfCtrlStates(Index)++
#define CanIf_IncTxBufferPrioByCanIdBase(Index)                       CanIf_GetTxBufferPrioByCanIdBase(Index)++
#define CanIf_IncTxQueue(Index)                                       CanIf_GetTxQueue(Index)++
#define CanIf_IncTxQueueData(Index)                                   CanIf_GetTxQueueData(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCDecrementDataMacros  CanIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanIf_DecCtrlModeOfCtrlStates(Index)                          CanIf_GetCtrlModeOfCtrlStates(Index)--
#define CanIf_DecPduModeOfCtrlStates(Index)                           CanIf_GetPduModeOfCtrlStates(Index)--
#define CanIf_DecWakeUpValidationStateOfCtrlStates(Index)             CanIf_GetWakeUpValidationStateOfCtrlStates(Index)--
#define CanIf_DecTxBufferPrioByCanIdBase(Index)                       CanIf_GetTxBufferPrioByCanIdBase(Index)--
#define CanIf_DecTxQueue(Index)                                       CanIf_GetTxQueue(Index)--
#define CanIf_DecTxQueueData(Index)                                   CanIf_GetTxQueueData(Index)--
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCIterableTypes  CanIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef uint8_least CanIf_CanIfCtrlId2MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlConfig */
typedef uint8_least CanIf_CtrlConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlStates */
typedef uint8_least CanIf_CtrlStatesIterType;

/**   \brief  type used to iterate CanIf_MailBoxConfig */
typedef uint8_least CanIf_MailBoxConfigIterType;

/**   \brief  type used to iterate CanIf_MappedTxBuffersConfig */
typedef uint8_least CanIf_MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_RxDHAdjust */
typedef uint8_least CanIf_RxDHAdjustIterType;

/**   \brief  type used to iterate CanIf_RxIndicationFctList */
typedef uint8_least CanIf_RxIndicationFctListIterType;

/**   \brief  type used to iterate CanIf_RxPduConfig */
typedef uint8_least CanIf_RxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TrcvToCtrlMap */
typedef uint8_least CanIf_TrcvToCtrlMapIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdBase */
typedef uint8_least CanIf_TxBufferPrioByCanIdBaseIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdByteQueueConfig */
typedef uint8_least CanIf_TxBufferPrioByCanIdByteQueueConfigIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8_least CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusIterType;

/**   \brief  type used to iterate CanIf_TxConfirmationFctList */
typedef uint8_least CanIf_TxConfirmationFctListIterType;

/**   \brief  type used to iterate CanIf_TxPduConfig */
typedef uint8_least CanIf_TxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxPduQueueIndex */
typedef uint8_least CanIf_TxPduQueueIndexIterType;

/**   \brief  type used to iterate CanIf_TxQueue */
typedef uint8_least CanIf_TxQueueIterType;

/**   \brief  type used to iterate CanIf_TxQueueData */
typedef uint16_least CanIf_TxQueueDataIterType;

/**   \brief  type used to iterate CanIf_TxQueueIndex2DataStartStop */
typedef uint8_least CanIf_TxQueueIndex2DataStartStopIterType;

/**   \brief  type used to iterate CanIf_WakeUpConfig */
typedef uint8_least CanIf_WakeUpConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCValueTypes  CanIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_RxDHRandomNumber1OfCtrlConfig */
typedef uint16 CanIf_RxDHRandomNumber1OfCtrlConfigType;

/**   \brief  value based type definition for CanIf_RxDHRandomNumber2OfCtrlConfig */
typedef uint16 CanIf_RxDHRandomNumber2OfCtrlConfigType;

/**   \brief  value based type definition for CanIf_GeneratorCompatibilityVersion */
typedef uint16 CanIf_GeneratorCompatibilityVersionType;

/**   \brief  value based type definition for CanIf_GeneratorVersion */
typedef uint32 CanIf_GeneratorVersionType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfMailBoxConfig */
typedef uint8 CanIf_CtrlStatesIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdFirstOfMailBoxConfig */
typedef uint8 CanIf_PduIdFirstOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdLastOfMailBoxConfig */
typedef uint8 CanIf_PduIdLastOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgIdxOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgUsedOfMailBoxConfig */
typedef boolean CanIf_TxBufferCfgUsedOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferHandlingTypeOfMailBoxConfig */
typedef uint8 CanIf_TxBufferHandlingTypeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfMappedTxBuffersConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MaxTrcvHandleIdPlusOne */
typedef uint8 CanIf_MaxTrcvHandleIdPlusOneType;

/**   \brief  value based type definition for CanIf_MaxWakeUpSources */
typedef uint8 CanIf_MaxWakeUpSourcesType;

/**   \brief  value based type definition for CanIf_RxDHAdjust */
typedef uint8 CanIf_RxDHAdjustType;

/**   \brief  value based type definition for CanIf_IsCanNmRxPduOfRxPduConfig */
typedef boolean CanIf_IsCanNmRxPduOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_IsDataChecksumRxPduOfRxPduConfig */
typedef boolean CanIf_IsDataChecksumRxPduOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxIndicationFctListIdxOfRxPduConfig */
typedef uint8 CanIf_RxIndicationFctListIdxOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduCanIdOfRxPduConfig */
typedef uint16 CanIf_RxPduCanIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduDlcOfRxPduConfig */
typedef uint8 CanIf_RxPduDlcOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduMaskOfRxPduConfig */
typedef uint16 CanIf_RxPduMaskOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperPduIdOfRxPduConfig */
typedef PduIdType CanIf_UpperPduIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlConfig */
typedef uint8 CanIf_SizeOfCtrlConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlStates */
typedef uint8 CanIf_SizeOfCtrlStatesType;

/**   \brief  value based type definition for CanIf_SizeOfMailBoxConfig */
typedef uint8 CanIf_SizeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_SizeOfMappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfRxDHAdjust */
typedef uint8 CanIf_SizeOfRxDHAdjustType;

/**   \brief  value based type definition for CanIf_SizeOfRxIndicationFctList */
typedef uint8 CanIf_SizeOfRxIndicationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfRxPduConfig */
typedef uint8 CanIf_SizeOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTrcvToCtrlMap */
typedef uint8 CanIf_SizeOfTrcvToCtrlMapType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdBase */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdBaseType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  value based type definition for CanIf_SizeOfTxConfirmationFctList */
typedef uint8 CanIf_SizeOfTxConfirmationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduConfig */
typedef uint8 CanIf_SizeOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduQueueIndex */
typedef uint8 CanIf_SizeOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueue */
typedef uint8 CanIf_SizeOfTxQueueType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueueData */
typedef uint16 CanIf_SizeOfTxQueueDataType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueueIndex2DataStartStop */
typedef uint8 CanIf_SizeOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_SizeOfWakeUpConfig */
typedef uint8 CanIf_SizeOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_TrcvToCtrlMap */
typedef uint8 CanIf_TrcvToCtrlMapType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8 CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  value based type definition for CanIf_CanIdOfTxPduConfig */
typedef uint16 CanIf_CanIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfTxPduConfig */
typedef uint8 CanIf_CtrlStatesIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_IsTxPduTruncationOfTxPduConfig */
typedef boolean CanIf_IsTxPduTruncationOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfTxPduConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxConfirmationFctListIdxOfTxPduConfig */
typedef uint8 CanIf_TxConfirmationFctListIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxPduLengthOfTxPduConfig */
typedef uint8 CanIf_TxPduLengthOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperLayerTxPduIdOfTxPduConfig */
typedef PduIdType CanIf_UpperLayerTxPduIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxQueueIdxOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueIdxOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueIndex2DataStartStopIdxOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueIndex2DataStartStopUsedOfTxPduQueueIndex */
typedef boolean CanIf_TxQueueIndex2DataStartStopUsedOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueUsedOfTxPduQueueIndex */
typedef boolean CanIf_TxQueueUsedOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueData */
typedef uint8 CanIf_TxQueueDataType;

/**   \brief  value based type definition for CanIf_TxQueueDataEndIdxOfTxQueueIndex2DataStartStop */
typedef uint16 CanIf_TxQueueDataEndIdxOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_TxQueueDataLengthOfTxQueueIndex2DataStartStop */
typedef uint8 CanIf_TxQueueDataLengthOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_TxQueueDataStartIdxOfTxQueueIndex2DataStartStop */
typedef uint16 CanIf_TxQueueDataStartIdxOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_TxQueueDataUsedOfTxQueueIndex2DataStartStop */
typedef boolean CanIf_TxQueueDataUsedOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_ControllerOfWakeUpConfig */
typedef uint8 CanIf_ControllerOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_WakeUpSourceOfWakeUpConfig */
typedef uint8 CanIf_WakeUpSourceOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_WakeUpTargetAddressOfWakeUpConfig */
typedef uint8 CanIf_WakeUpTargetAddressOfWakeUpConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCStructTypes  CanIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef struct sCanIf_CanIfCtrlId2MappedTxBuffersConfigType
{
  CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
  CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
} CanIf_CanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_CtrlConfig */
typedef struct sCanIf_CtrlConfigType
{
  CanIf_RxDHRandomNumber1OfCtrlConfigType RxDHRandomNumber1OfCtrlConfig;  /**< Rx - DoubleHash - 1st random number. */
  CanIf_RxDHRandomNumber2OfCtrlConfigType RxDHRandomNumber2OfCtrlConfig;  /**< Rx - DoubleHash - 2nd random number. */
} CanIf_CtrlConfigType;

/**   \brief  type used in CanIf_CtrlStates */
typedef struct sCanIf_CtrlStatesType
{
  CanIf_ControllerModeType CtrlModeOfCtrlStates;  /**< Controller mode. */
  CanIf_PduGetModeType PduModeOfCtrlStates;  /**< PDU mode state. */
  CanIf_WakeUpValidationStateType WakeUpValidationStateOfCtrlStates;  /**< Wake-up validation state. */
} CanIf_CtrlStatesType;

/**   \brief  type used in CanIf_MailBoxConfig */
typedef struct sCanIf_MailBoxConfigType
{
  CanIf_CtrlStatesIdxOfMailBoxConfigType CtrlStatesIdxOfMailBoxConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_PduIdFirstOfMailBoxConfigType PduIdFirstOfMailBoxConfig;  /**< "First" PDU mapped to mailbox. */
  CanIf_PduIdLastOfMailBoxConfigType PduIdLastOfMailBoxConfig;  /**< "Last" PDU mapped to mailbox. */
  CanIf_TxBufferCfgIdxOfMailBoxConfigType TxBufferCfgIdxOfMailBoxConfig;  /**< the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig */
  CanIf_TxBufferHandlingTypeOfMailBoxConfigType TxBufferHandlingTypeOfMailBoxConfig;
  CanIf_MailBoxTypeType MailBoxTypeOfMailBoxConfig;  /**< Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused. */
} CanIf_MailBoxConfigType;

/**   \brief  type used in CanIf_MappedTxBuffersConfig */
typedef struct sCanIf_MappedTxBuffersConfigType
{
  CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType MailBoxConfigIdxOfMappedTxBuffersConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
} CanIf_MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_RxIndicationFctList */
typedef struct sCanIf_RxIndicationFctListType
{
  CanIf_RxIndicationFctType RxIndicationFctOfRxIndicationFctList;  /**< Rx indication function. */
  CanIf_RxIndicationLayoutType RxIndicationLayoutOfRxIndicationFctList;  /**< Layout of Rx indication function. */
} CanIf_RxIndicationFctListType;

/**   \brief  type used in CanIf_RxPduConfig */
typedef struct sCanIf_RxPduConfigType
{
  CanIf_UpperPduIdOfRxPduConfigType UpperPduIdOfRxPduConfig;  /**< PDU ID defined by upper layer. */
  CanIf_RxPduCanIdOfRxPduConfigType RxPduCanIdOfRxPduConfig;  /**< Rx-PDU: CAN identifier. */
  CanIf_RxPduMaskOfRxPduConfigType RxPduMaskOfRxPduConfig;  /**< Rx-PDU: CAN identifier mask. */
  CanIf_IsCanNmRxPduOfRxPduConfigType IsCanNmRxPduOfRxPduConfig;  /**< TRUE: CAN-Nm Rx-PDU (for Wakeup validation), FALSE: No CAN-Nm Rx-PDU */
  CanIf_IsDataChecksumRxPduOfRxPduConfigType IsDataChecksumRxPduOfRxPduConfig;  /**< TRUE: Data checksum Rx-PDU, FALSE: None Data checksum Rx-PDU */
  CanIf_RxIndicationFctListIdxOfRxPduConfigType RxIndicationFctListIdxOfRxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_RxIndicationFctList */
  CanIf_RxPduDlcOfRxPduConfigType RxPduDlcOfRxPduConfig;  /**< Rx-PDU length (DLC). */
  CanIf_MsgType MsgTypeOfRxPduConfig;  /**< Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0). */
} CanIf_RxPduConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdByteQueueConfig */
typedef struct sCanIf_TxBufferPrioByCanIdByteQueueConfigType
{
  CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig;  /**< the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
} CanIf_TxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef struct sCanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType
{
  CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus;  /**< the index of the 1:1 relation pointing to CanIf_TxPduConfig */
} CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  type used in CanIf_TxPduConfig */
typedef struct sCanIf_TxPduConfigType
{
  CanIf_UpperLayerTxPduIdOfTxPduConfigType UpperLayerTxPduIdOfTxPduConfig;  /**< Upper layer handle ID (8bit / 16bit). */
  CanIf_CanIdOfTxPduConfigType CanIdOfTxPduConfig;  /**< CAN identifier (16bit / 32bit). */
  CanIf_IsTxPduTruncationOfTxPduConfigType IsTxPduTruncationOfTxPduConfig;  /**< TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled */
  CanIf_CtrlStatesIdxOfTxPduConfigType CtrlStatesIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_MailBoxConfigIdxOfTxPduConfigType MailBoxConfigIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
  CanIf_TxConfirmationFctListIdxOfTxPduConfigType TxConfirmationFctListIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList */
  CanIf_TxPduLengthOfTxPduConfigType TxPduLengthOfTxPduConfig;  /**< Tx-PDU length. */
} CanIf_TxPduConfigType;

/**   \brief  type used in CanIf_TxPduQueueIndex */
typedef struct sCanIf_TxPduQueueIndexType
{
  CanIf_TxQueueIdxOfTxPduQueueIndexType TxQueueIdxOfTxPduQueueIndex;  /**< the index of the 0:1 relation pointing to CanIf_TxQueue */
  CanIf_TxQueueIndex2DataStartStopIdxOfTxPduQueueIndexType TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex;  /**< the index of the 0:1 relation pointing to CanIf_TxQueueIndex2DataStartStop */
} CanIf_TxPduQueueIndexType;

/**   \brief  type used in CanIf_TxQueueIndex2DataStartStop */
typedef struct sCanIf_TxQueueIndex2DataStartStopType
{
  CanIf_TxQueueDataEndIdxOfTxQueueIndex2DataStartStopType TxQueueDataEndIdxOfTxQueueIndex2DataStartStop;  /**< the end index of the 0:n relation pointing to CanIf_TxQueueData */
  CanIf_TxQueueDataStartIdxOfTxQueueIndex2DataStartStopType TxQueueDataStartIdxOfTxQueueIndex2DataStartStop;  /**< the start index of the 0:n relation pointing to CanIf_TxQueueData */
  CanIf_TxQueueDataLengthOfTxQueueIndex2DataStartStopType TxQueueDataLengthOfTxQueueIndex2DataStartStop;  /**< the number of relations pointing to CanIf_TxQueueData */
} CanIf_TxQueueIndex2DataStartStopType;

/**   \brief  type used in CanIf_WakeUpConfig */
typedef struct sCanIf_WakeUpConfigType
{
  CanIf_ControllerOfWakeUpConfigType ControllerOfWakeUpConfig;  /**< CAN controller handle ID */
  CanIf_WakeUpSourceOfWakeUpConfigType WakeUpSourceOfWakeUpConfig;  /**< Wake-up source identifier */
  CanIf_WakeUpTargetAddressOfWakeUpConfigType WakeUpTargetAddressOfWakeUpConfig;  /**< Logical handle ID of target (CAN controller / transceiver) */
  CanIf_WakeUpTargetType WakeUpTargetModuleOfWakeUpConfig;  /**< Target for wake-up source: CAN controller / transceiver */
} CanIf_WakeUpConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicStructTypes  CanIf Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates */
typedef struct CanIf_CtrlStatesStructSTag
{
  CanIf_CtrlStatesType CT_B30_for_SC_CAN_V3_2_4a04dc9c;
  CanIf_CtrlStatesType CT_B30_for_SC_CAN_V3_2_4a04dc9c_001;
  CanIf_CtrlStatesType CT_B30_for_SC_CAN_V3_2_4a04dc9c_002;
} CanIf_CtrlStatesStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase */
typedef struct CanIf_TxBufferPrioByCanIdBaseStructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_b4130143;
} CanIf_TxBufferPrioByCanIdBaseStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue */
typedef struct CanIf_TxQueueStructSTag
{
  CanIf_TxPrioByCanIdByteQueueType HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx;
  CanIf_TxPrioByCanIdByteQueueType ZCluster_Debug_Msg_0x7AF_Tx;
  CanIf_TxPrioByCanIdByteQueueType ZCluster_Debug_Msg_0x7AE_Tx;
  CanIf_TxPrioByCanIdByteQueueType ZCluster_Debug_Msg_0x7AD_Tx;
  CanIf_TxPrioByCanIdByteQueueType ZCluster_Debug_Msg_0x7AC_Tx;
  CanIf_TxPrioByCanIdByteQueueType ZCluster_Debug_Msg_0x7AB_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx;
  CanIf_TxPrioByCanIdByteQueueType HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx;
} CanIf_TxQueueStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueData */
typedef struct CanIf_TxQueueDataStructSTag
{
  CanIf_TxQueueDataType HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx[8];
  CanIf_TxQueueDataType HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx[8];
  CanIf_TxQueueDataType ZCluster_Debug_Msg_0x7AF_Tx[64];
  CanIf_TxQueueDataType ZCluster_Debug_Msg_0x7AE_Tx[64];
  CanIf_TxQueueDataType ZCluster_Debug_Msg_0x7AD_Tx[64];
  CanIf_TxQueueDataType ZCluster_Debug_Msg_0x7AC_Tx[64];
  CanIf_TxQueueDataType ZCluster_Debug_Msg_0x7AB_Tx[64];
  CanIf_TxQueueDataType HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx[8];
  CanIf_TxQueueDataType HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx[16];
  CanIf_TxQueueDataType HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx[8];
  CanIf_TxQueueDataType HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx[8];
  CanIf_TxQueueDataType HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx[8];
  CanIf_TxQueueDataType HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx[8];
  CanIf_TxQueueDataType HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx[8];
  CanIf_TxQueueDataType HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx[8];
  CanIf_TxQueueDataType HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx[8];
  CanIf_TxQueueDataType HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx[8];
  CanIf_TxQueueDataType HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx[8];
  CanIf_TxQueueDataType HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx[8];
  CanIf_TxQueueDataType HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx[8];
  CanIf_TxQueueDataType HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx[8];
  CanIf_TxQueueDataType HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx[8];
  CanIf_TxQueueDataType HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx[8];
  CanIf_TxQueueDataType HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx[16];
  CanIf_TxQueueDataType HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx[8];
  CanIf_TxQueueDataType HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx[8];
  CanIf_TxQueueDataType HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx[8];
  CanIf_TxQueueDataType HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx[8];
  CanIf_TxQueueDataType HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx[8];
  CanIf_TxQueueDataType HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx[8];
  CanIf_TxQueueDataType HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx[8];
  CanIf_TxQueueDataType HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx[8];
  CanIf_TxQueueDataType HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx[8];
  CanIf_TxQueueDataType HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx[64];
  CanIf_TxQueueDataType HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx[64];
  CanIf_TxQueueDataType HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx[8];
  CanIf_TxQueueDataType HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx[8];
  CanIf_TxQueueDataType HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx[8];
} CanIf_TxQueueDataStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCUnionIndexAndSymbolTypes  CanIf Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access CanIf_CtrlStates in an index and symbol based style. */
typedef union CanIf_CtrlStatesUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_CtrlStatesType raw[3];
  CanIf_CtrlStatesStructSType str;
} CanIf_CtrlStatesUType;

/**   \brief  type to access CanIf_TxBufferPrioByCanIdBase in an index and symbol based style. */
typedef union CanIf_TxBufferPrioByCanIdBaseUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxBufferPrioByCanIdBaseType raw[1];
  CanIf_TxBufferPrioByCanIdBaseStructSType str;
} CanIf_TxBufferPrioByCanIdBaseUType;

/**   \brief  type to access CanIf_TxQueue in an index and symbol based style. */
typedef union CanIf_TxQueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxPrioByCanIdByteQueueType raw[38];
  CanIf_TxQueueStructSType str;
} CanIf_TxQueueUType;

/**   \brief  type to access CanIf_TxQueueData in an index and symbol based style. */
typedef union CanIf_TxQueueDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxQueueDataType raw[712];
  CanIf_TxQueueDataStructSType str;
} CanIf_TxQueueDataUType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootPointerTypes  CanIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef P2CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_CtrlConfig */
typedef P2CONST(CanIf_CtrlConfigType, TYPEDEF, CANIF_CONST) CanIf_CtrlConfigPtrType;

/**   \brief  type used to point to CanIf_CtrlStates */
typedef P2VAR(CanIf_CtrlStatesType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_CtrlStatesPtrType;

/**   \brief  type used to point to CanIf_MailBoxConfig */
typedef P2CONST(CanIf_MailBoxConfigType, TYPEDEF, CANIF_CONST) CanIf_MailBoxConfigPtrType;

/**   \brief  type used to point to CanIf_MappedTxBuffersConfig */
typedef P2CONST(CanIf_MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_RxDHAdjust */
typedef P2CONST(CanIf_RxDHAdjustType, TYPEDEF, CANIF_CONST) CanIf_RxDHAdjustPtrType;

/**   \brief  type used to point to CanIf_RxIndicationFctList */
typedef P2CONST(CanIf_RxIndicationFctListType, TYPEDEF, CANIF_CONST) CanIf_RxIndicationFctListPtrType;

/**   \brief  type used to point to CanIf_RxPduConfig */
typedef P2CONST(CanIf_RxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_RxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TrcvToCtrlMap */
typedef P2CONST(CanIf_TrcvToCtrlMapType, TYPEDEF, CANIF_CONST) CanIf_TrcvToCtrlMapPtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdBase */
typedef P2VAR(CanIf_TxBufferPrioByCanIdBaseType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBasePtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdByteQueueConfig */
typedef P2CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, TYPEDEF, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfigPtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef P2CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, TYPEDEF, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusPtrType;

/**   \brief  type used to point to CanIf_TxConfirmationFctList */
typedef P2CONST(CanIf_TxConfirmationFctType, TYPEDEF, CANIF_CONST) CanIf_TxConfirmationFctListPtrType;

/**   \brief  type used to point to CanIf_TxPduConfig */
typedef P2CONST(CanIf_TxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_TxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TxPduQueueIndex */
typedef P2CONST(CanIf_TxPduQueueIndexType, TYPEDEF, CANIF_CONST) CanIf_TxPduQueueIndexPtrType;

/**   \brief  type used to point to CanIf_TxQueue */
typedef P2VAR(CanIf_TxPrioByCanIdByteQueueType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxQueuePtrType;

/**   \brief  type used to point to CanIf_TxQueueData */
typedef P2VAR(CanIf_TxQueueDataType, TYPEDEF, CANIF_VAR_NOINIT_FAST) CanIf_TxQueueDataPtrType;

/**   \brief  type used to point to CanIf_TxQueueIndex2DataStartStop */
typedef P2CONST(CanIf_TxQueueIndex2DataStartStopType, TYPEDEF, CANIF_CONST) CanIf_TxQueueIndex2DataStartStopPtrType;

/**   \brief  type used to point to CanIf_WakeUpConfig */
typedef P2CONST(CanIf_WakeUpConfigType, TYPEDEF, CANIF_CONST) CanIf_WakeUpConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootValueTypes  CanIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanIf_PCConfig */
typedef struct sCanIf_PCConfigType
{
  uint8 CanIf_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanIf_PCConfigType;

typedef CanIf_PCConfigType CanIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlConfig
  \details
  Element              Description
  RxDHRandomNumber1    Rx - DoubleHash - 1st random number.
  RxDHRandomNumber2    Rx - DoubleHash - 2nd random number.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CtrlConfigType, CANIF_CONST) CanIf_CtrlConfig[3];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_DataChecksumRxErrFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_DataChecksumRxErrFctType, CANIF_CONST) CanIf_DataChecksumRxErrFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[24];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxDHAdjust
**********************************************************************************************************************/
/** 
  \var    CanIf_RxDHAdjust
  \brief  Rx - DoubleHash - adjust values.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxDHAdjustType, CANIF_CONST) CanIf_RxDHAdjust[197];
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  UpperPduId                PDU ID defined by upper layer.
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  IsCanNmRxPdu              TRUE: CAN-Nm Rx-PDU (for Wakeup validation), FALSE: No CAN-Nm Rx-PDU
  IsDataChecksumRxPdu       TRUE: Data checksum Rx-PDU, FALSE: None Data checksum Rx-PDU
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[146];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TrcvModeIndicationFctType, CANIF_CONST) CanIf_TrcvModeIndicationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvToCtrlMap
**********************************************************************************************************************/
/** 
  \var    CanIf_TrcvToCtrlMap
  \brief  Indirection table: logical transceiver index to CAN controller index.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TrcvToCtrlMapType, CANIF_CONST) CanIf_TrcvToCtrlMap[3];
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[38];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CanId                       CAN identifier (16bit / 32bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[56];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element                          Description
  TxQueueIdx                       the index of the 0:1 relation pointing to CanIf_TxQueue
  TxQueueIndex2DataStartStopIdx    the index of the 0:1 relation pointing to CanIf_TxQueueIndex2DataStartStop
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[56];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueIndex2DataStartStop
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueIndex2DataStartStop
  \details
  Element                Description
  TxQueueDataEndIdx      the end index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataStartIdx    the start index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataLength      the number of relations pointing to CanIf_TxQueueData
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxQueueIndex2DataStartStopType, CANIF_CONST) CanIf_TxQueueIndex2DataStartStop[38];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  Controller             CAN controller handle ID
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Logical handle ID of target (CAN controller / transceiver)
  WakeUpTargetModule     Target for wake-up source: CAN controller / transceiver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpValidationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_WakeUpValidationFctType, CANIF_CONST) CanIf_WakeUpValidationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element                  Description
  CtrlMode                 Controller mode.
  PduMode                  PDU mode state.
  WakeUpValidationState    Wake-up validation state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueData
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueData
  \brief  Variable declaration - Tx queue data.
*/ 
#define CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueDataUType, CANIF_VAR_NOINIT_FAST) CanIf_TxQueueData;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




#endif  /* CANIF_CFG_H */
/**********************************************************************************************************************
  END OF FILE: CanIf_Cfg.h
**********************************************************************************************************************/


