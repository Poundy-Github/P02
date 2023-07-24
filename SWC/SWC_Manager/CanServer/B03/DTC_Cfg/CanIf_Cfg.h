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
 *   Generation Time: 2021-02-27 10:45:59
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

#define CANIF_TRANSMIT_BUFFER                              STD_OFF /* Signals if Tx-buffer is enabled at all in CanIf. The value is determined from parameter "CanIfPublicTxBuffering". */
#define CANIF_TRANSMIT_BUFFER_PRIO_BY_CANID                STD_OFF
#define CANIF_TRANSMIT_BUFFER_FIFO                         STD_OFF
#define CANIF_BITQUEUE                                     STD_OFF
#define CANIF_STATIC_FD_TXQUEUE                            STD_OFF
#define CANIF_WAKEUP_SUPPORT                               STD_ON
#define CANIF_WAKEUP_VALIDATION                            STD_ON
#define CANIF_WAKEUP_VALID_ALL_RX_MSGS                     STD_OFF
#define CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS                 STD_ON
#define CANIF_CHECK_WAKEUP_CAN_RET_TYPE                    STD_OFF
#define CANIF_DEV_ERROR_DETECT                             STD_ON
#define CANIF_DEV_ERROR_REPORT                             STD_ON
#define CANIF_TRANSMIT_CANCELLATION                        STD_OFF
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
#define CANIF_DATA_CHECKSUM_TX_SUPPORT                     STD_ON
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

#define CanIfTxPduHnd_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx                              0u
#define CanIfTxPduHnd_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx                           1u
#define CanIfTxPduHnd_HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx                                       2u
#define CanIfTxPduHnd_HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx                                 3u
#define CanIfTxPduHnd_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx                                        4u
#define CanIfTxPduHnd_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx                                        5u
#define CanIfTxPduHnd_HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx                                         6u
#define CanIfTxPduHnd_HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx                                         7u
#define CanIfTxPduHnd_HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx                                         8u
#define CanIfTxPduHnd_HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx                                         9u
#define CanIfTxPduHnd_HUT_IP3_oB30_for_SC_CAN_V3_2_34a8d95f_Tx                                      10u
#define CanIfTxPduHnd_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx                                        11u
#define CanIfTxPduHnd_T_Box_FD6_oB30_for_SC_CAN_V3_2_6be33b24_Tx                                    12u
#define CanIfTxPduHnd_HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx                                        13u
#define CanIfTxPduHnd_HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx                                        14u
#define CanIfTxPduHnd_HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx                                        15u
#define CanIfTxPduHnd_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx                                        16u
#define CanIfTxPduHnd_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx                                      17u
#define CanIfTxPduHnd_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx                                      18u
#define CanIfTxPduHnd_HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx                                        19u
#define CanIfTxPduHnd_HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx                                        20u
#define CanIfTxPduHnd_HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx                                        21u
#define CanIfTxPduHnd_HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx                                        22u
#define CanIfTxPduHnd_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx                                   23u
#define CanIfTxPduHnd_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx                                        24u
#define CanIfTxPduHnd_HUT_IP1_oB30_for_SC_CAN_V3_2_1b547682_Tx                                      25u
#define CanIfTxPduHnd_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx                                      26u
#define CanIfTxPduHnd_HUT_IP2_Sc_oB30_for_SC_CAN_V3_2_663377cd_Tx                                   27u
#define CanIfTxPduHnd_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx                                        28u
#define CanIfTxPduHnd_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx                                      29u
#define CanIfTxPduHnd_HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx                                     30u
#define CanIfTxPduHnd_HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx                                        31u
#define CanIfTxPduHnd_HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx                                        32u
#define CanIfTxPduHnd_HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx                                        33u
#define CanIfTxPduHnd_HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx                                         34u


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
#define CanIfRxPduHnd_T_Box_FD3_Sc_oB30_for_SC_CAN_V3_2_be0a3640_Rx                                 2u
#define CanIfRxPduHnd_AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx                                         3u
#define CanIfRxPduHnd_AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx                                      4u
#define CanIfRxPduHnd_AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx                                         5u
#define CanIfRxPduHnd_TMCU_FD3_oB30_for_SC_CAN_V3_2_481b1f14_Rx                                     6u
#define CanIfRxPduHnd_HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx                                      7u
#define CanIfRxPduHnd_BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx                                        8u
#define CanIfRxPduHnd_ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx                                        9u
#define CanIfRxPduHnd_ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx                                        10u
#define CanIfRxPduHnd_AMP5_IESS1_oB30_for_SC_CAN_V3_2_6a7e89d2_Rx                                   11u
#define CanIfRxPduHnd_TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx                                     12u
#define CanIfRxPduHnd_AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx                                          13u
#define CanIfRxPduHnd_ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx                                         14u
#define CanIfRxPduHnd_CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx                                          15u
#define CanIfRxPduHnd_BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx                                        16u
#define CanIfRxPduHnd_ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx                                      17u
#define CanIfRxPduHnd_BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx                                      18u
#define CanIfRxPduHnd_TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx                                     19u
#define CanIfRxPduHnd_HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx                                         20u
#define CanIfRxPduHnd_BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx                                      21u
#define CanIfRxPduHnd_OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx                                         22u
#define CanIfRxPduHnd_OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx                                         23u
#define CanIfRxPduHnd_HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx                                      24u
#define CanIfRxPduHnd_RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx                                     25u
#define CanIfRxPduHnd_ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx                                        26u
#define CanIfRxPduHnd_PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx                                        27u
#define CanIfRxPduHnd_PLG_1_oB30_for_SC_CAN_V3_2_9256d283_Rx                                        28u
#define CanIfRxPduHnd_VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx                                        29u
#define CanIfRxPduHnd_HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx                                      30u
#define CanIfRxPduHnd_RPAS2_oB30_for_SC_CAN_V3_2_9ad6b778_Rx                                        31u
#define CanIfRxPduHnd_VSG1_oB30_for_SC_CAN_V3_2_ef738777_Rx                                         32u
#define CanIfRxPduHnd_ALCM1_oB30_for_SC_CAN_V3_2_d6e83463_Rx                                        33u
#define CanIfRxPduHnd_ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx                                        34u
#define CanIfRxPduHnd_AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx                                    35u
#define CanIfRxPduHnd_SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx                                         36u
#define CanIfRxPduHnd_IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx                                      37u
#define CanIfRxPduHnd_PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx                                        38u
#define CanIfRxPduHnd_DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx                                        39u
#define CanIfRxPduHnd_BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx                                        40u
#define CanIfRxPduHnd_DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx                                         41u
#define CanIfRxPduHnd_GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx                                       42u
#define CanIfRxPduHnd_WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx                                         43u
#define CanIfRxPduHnd_ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx                                      44u
#define CanIfRxPduHnd_ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx                                      45u
#define CanIfRxPduHnd_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx                                   46u
#define CanIfRxPduHnd_EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx                                         47u
#define CanIfRxPduHnd_BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx                                         48u
#define CanIfRxPduHnd_AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx                                          49u
#define CanIfRxPduHnd_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx                                      50u
#define CanIfRxPduHnd_PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx                                        51u
#define CanIfRxPduHnd_ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx                                      52u
#define CanIfRxPduHnd_BCM6_oB30_for_SC_CAN_V3_2_f11643ac_Rx                                         53u
#define CanIfRxPduHnd_HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx                                      54u
#define CanIfRxPduHnd_HC1_oB30_for_SC_CAN_V3_2_f63a95a4_Rx                                          55u
#define CanIfRxPduHnd_BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx                                         56u
#define CanIfRxPduHnd_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx                                      57u
#define CanIfRxPduHnd_Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx                                     58u
#define CanIfRxPduHnd_ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx                                         59u
#define CanIfRxPduHnd_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx                                        60u
#define CanIfRxPduHnd_FPAS1_oB30_for_SC_CAN_V3_2_133a22d3_Rx                                        61u
#define CanIfRxPduHnd_HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx                                      62u
#define CanIfRxPduHnd_ABS3_oB30_for_SC_CAN_V3_2_961138dc_Rx                                         63u
#define CanIfRxPduHnd_Haldex1_oB30_for_SC_CAN_V3_2_bbae6b8e_Rx                                      64u
#define CanIfRxPduHnd_HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx                                      65u
#define CanIfRxPduHnd_ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx                                         66u
#define CanIfRxPduHnd_ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx                                         67u
#define CanIfRxPduHnd_CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx                                         68u
#define CanIfRxPduHnd_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx                                   69u
#define CanIfRxPduHnd_BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx                                        70u
#define CanIfRxPduHnd_DCT7_Sc_oB30_for_SC_CAN_V3_2_5c786cc5_Rx                                      71u
#define CanIfRxPduHnd_ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx                                         72u
#define CanIfRxPduHnd_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx                                   73u
#define CanIfRxPduHnd_IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx                                      74u
#define CanIfRxPduHnd_DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx                                         75u
#define CanIfRxPduHnd_STBS1_oB30_for_SC_CAN_V3_2_3fe5270b_Rx                                        76u
#define CanIfRxPduHnd_HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx                                      77u
#define CanIfRxPduHnd_HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx                                      78u
#define CanIfRxPduHnd_T_Box_FD4_oB30_for_SC_CAN_V3_2_f496a4b1_Rx                                    79u
#define CanIfRxPduHnd_HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx                                      80u
#define CanIfRxPduHnd_IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx                                      81u
#define CanIfRxPduHnd_R_PBox1_Sc_oB30_for_SC_CAN_V3_2_79c76dd7_Rx                                   82u
#define CanIfRxPduHnd_F_PBox1_oB30_for_SC_CAN_V3_2_cb257250_Rx                                      83u
#define CanIfRxPduHnd_AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx                                      84u
#define CanIfRxPduHnd_ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx                                         85u
#define CanIfRxPduHnd_RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx                                     86u
#define CanIfRxPduHnd_EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx                                         87u
#define CanIfRxPduHnd_EPS1_oB30_for_SC_CAN_V3_2_a33fe139_Rx                                         88u
#define CanIfRxPduHnd_CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx                                         89u
#define CanIfRxPduHnd_EPS2_oB30_for_SC_CAN_V3_2_7018c07d_Rx                                         90u
#define CanIfRxPduHnd_CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx                                       91u
#define CanIfRxPduHnd_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx                                      92u
#define CanIfRxPduHnd_ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx                                         93u
#define CanIfRxPduHnd_HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx                                      94u
#define CanIfRxPduHnd_ESP1_Sc_oB30_for_SC_CAN_V3_2_c7573a5b_Rx                                      95u
#define CanIfRxPduHnd_EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx                                      96u
#define CanIfRxPduHnd_ESP2_Sc_oB30_for_SC_CAN_V3_2_12ed4148_Rx                                      97u
#define CanIfRxPduHnd_ECM10_oB30_for_SC_CAN_V3_2_6dcbec2b_Rx                                        98u
#define CanIfRxPduHnd_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx                                   99u
#define CanIfRxPduHnd_Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx                                 100u
#define CanIfRxPduHnd_HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx                                      101u
#define CanIfRxPduHnd_ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx                                      102u
#define CanIfRxPduHnd_ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx                                         103u
#define CanIfRxPduHnd_IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx                                         104u
#define CanIfRxPduHnd_ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx                                         105u
#define CanIfRxPduHnd_BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx                                         106u
#define CanIfRxPduHnd_ESP10_oB30_for_SC_CAN_V3_2_119f3682_Rx                                        107u
#define CanIfRxPduHnd_ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx                                        108u
#define CanIfRxPduHnd_DHT_FD1_oB30_for_SC_CAN_V3_2_e564e605_Rx                                      109u
#define CanIfRxPduHnd_DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx                                         110u
#define CanIfRxPduHnd_CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx                                         111u
#define CanIfRxPduHnd_TMCU6_oB30_for_SC_CAN_V3_2_e6ceb015_Rx                                        112u
#define CanIfRxPduHnd_ECM8_oB30_for_SC_CAN_V3_2_a98d7fca_Rx                                         113u
#define CanIfRxPduHnd_ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx                                         114u
#define CanIfRxPduHnd_ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx                                         115u
#define CanIfRxPduHnd_HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx                                      116u
#define CanIfRxPduHnd_GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx                                    117u
#define CanIfRxPduHnd_T_Box_FD1_Sc_oB30_for_SC_CAN_V3_2_d763f605_Rx                                 118u



/**********************************************************************************************************************
  \def  AUTOSAR Tx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTxPduCfg_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx                    0u
#define CanIfConf_CanIfTxPduCfg_HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx                 1u
#define CanIfConf_CanIfTxPduCfg_HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx                             2u
#define CanIfConf_CanIfTxPduCfg_HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx                       3u
#define CanIfConf_CanIfTxPduCfg_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx                              4u
#define CanIfConf_CanIfTxPduCfg_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx                              5u
#define CanIfConf_CanIfTxPduCfg_HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx                               6u
#define CanIfConf_CanIfTxPduCfg_HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx                               7u
#define CanIfConf_CanIfTxPduCfg_HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx                               8u
#define CanIfConf_CanIfTxPduCfg_HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx                               9u
#define CanIfConf_CanIfTxPduCfg_HUT_IP3_oB30_for_SC_CAN_V3_2_34a8d95f_Tx                            10u
#define CanIfConf_CanIfTxPduCfg_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx                              11u
#define CanIfConf_CanIfTxPduCfg_T_Box_FD6_oB30_for_SC_CAN_V3_2_6be33b24_Tx                          12u
#define CanIfConf_CanIfTxPduCfg_HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx                              13u
#define CanIfConf_CanIfTxPduCfg_HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx                              14u
#define CanIfConf_CanIfTxPduCfg_HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx                              15u
#define CanIfConf_CanIfTxPduCfg_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx                              16u
#define CanIfConf_CanIfTxPduCfg_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx                            17u
#define CanIfConf_CanIfTxPduCfg_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx                            18u
#define CanIfConf_CanIfTxPduCfg_HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx                              19u
#define CanIfConf_CanIfTxPduCfg_HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx                              20u
#define CanIfConf_CanIfTxPduCfg_HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx                              21u
#define CanIfConf_CanIfTxPduCfg_HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx                              22u
#define CanIfConf_CanIfTxPduCfg_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx                         23u
#define CanIfConf_CanIfTxPduCfg_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx                              24u
#define CanIfConf_CanIfTxPduCfg_HUT_IP1_oB30_for_SC_CAN_V3_2_1b547682_Tx                            25u
#define CanIfConf_CanIfTxPduCfg_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx                            26u
#define CanIfConf_CanIfTxPduCfg_HUT_IP2_Sc_oB30_for_SC_CAN_V3_2_663377cd_Tx                         27u
#define CanIfConf_CanIfTxPduCfg_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx                              28u
#define CanIfConf_CanIfTxPduCfg_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx                            29u
#define CanIfConf_CanIfTxPduCfg_HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx                           30u
#define CanIfConf_CanIfTxPduCfg_HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx                              31u
#define CanIfConf_CanIfTxPduCfg_HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx                              32u
#define CanIfConf_CanIfTxPduCfg_HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx                              33u
#define CanIfConf_CanIfTxPduCfg_HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx                               34u


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
#define CanIfConf_CanIfRxPduCfg_T_Box_FD3_Sc_oB30_for_SC_CAN_V3_2_be0a3640_Rx                       7u
#define CanIfConf_CanIfRxPduCfg_AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx                               8u
#define CanIfConf_CanIfRxPduCfg_AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx                            9u
#define CanIfConf_CanIfRxPduCfg_AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx                               10u
#define CanIfConf_CanIfRxPduCfg_TMCU_FD3_oB30_for_SC_CAN_V3_2_481b1f14_Rx                           11u
#define CanIfConf_CanIfRxPduCfg_HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx                            12u
#define CanIfConf_CanIfRxPduCfg_BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx                              13u
#define CanIfConf_CanIfRxPduCfg_ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx                              14u
#define CanIfConf_CanIfRxPduCfg_ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx                              15u
#define CanIfConf_CanIfRxPduCfg_AMP5_IESS1_oB30_for_SC_CAN_V3_2_6a7e89d2_Rx                         16u
#define CanIfConf_CanIfRxPduCfg_TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx                           17u
#define CanIfConf_CanIfRxPduCfg_AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx                                18u
#define CanIfConf_CanIfRxPduCfg_ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx                               19u
#define CanIfConf_CanIfRxPduCfg_CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx                                20u
#define CanIfConf_CanIfRxPduCfg_BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx                              21u
#define CanIfConf_CanIfRxPduCfg_ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx                            22u
#define CanIfConf_CanIfRxPduCfg_BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx                            23u
#define CanIfConf_CanIfRxPduCfg_TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx                           24u
#define CanIfConf_CanIfRxPduCfg_HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx                               25u
#define CanIfConf_CanIfRxPduCfg_BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx                            26u
#define CanIfConf_CanIfRxPduCfg_OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx                               27u
#define CanIfConf_CanIfRxPduCfg_OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx                               28u
#define CanIfConf_CanIfRxPduCfg_HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx                            29u
#define CanIfConf_CanIfRxPduCfg_RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx                           30u
#define CanIfConf_CanIfRxPduCfg_ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx                              31u
#define CanIfConf_CanIfRxPduCfg_PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx                              32u
#define CanIfConf_CanIfRxPduCfg_PLG_1_oB30_for_SC_CAN_V3_2_9256d283_Rx                              33u
#define CanIfConf_CanIfRxPduCfg_VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx                              34u
#define CanIfConf_CanIfRxPduCfg_HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx                            35u
#define CanIfConf_CanIfRxPduCfg_RPAS2_oB30_for_SC_CAN_V3_2_9ad6b778_Rx                              36u
#define CanIfConf_CanIfRxPduCfg_VSG1_oB30_for_SC_CAN_V3_2_ef738777_Rx                               37u
#define CanIfConf_CanIfRxPduCfg_ALCM1_oB30_for_SC_CAN_V3_2_d6e83463_Rx                              38u
#define CanIfConf_CanIfRxPduCfg_ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx                              39u
#define CanIfConf_CanIfRxPduCfg_AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx                          40u
#define CanIfConf_CanIfRxPduCfg_SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx                               41u
#define CanIfConf_CanIfRxPduCfg_IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx                            42u
#define CanIfConf_CanIfRxPduCfg_PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx                              43u
#define CanIfConf_CanIfRxPduCfg_DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx                              44u
#define CanIfConf_CanIfRxPduCfg_BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx                              45u
#define CanIfConf_CanIfRxPduCfg_DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx                               46u
#define CanIfConf_CanIfRxPduCfg_GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx                             47u
#define CanIfConf_CanIfRxPduCfg_WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx                               48u
#define CanIfConf_CanIfRxPduCfg_ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx                            49u
#define CanIfConf_CanIfRxPduCfg_ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx                            50u
#define CanIfConf_CanIfRxPduCfg_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx                         51u
#define CanIfConf_CanIfRxPduCfg_EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx                               52u
#define CanIfConf_CanIfRxPduCfg_BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx                               53u
#define CanIfConf_CanIfRxPduCfg_AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx                                54u
#define CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx                            55u
#define CanIfConf_CanIfRxPduCfg_PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx                              56u
#define CanIfConf_CanIfRxPduCfg_ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx                            57u
#define CanIfConf_CanIfRxPduCfg_BCM6_oB30_for_SC_CAN_V3_2_f11643ac_Rx                               58u
#define CanIfConf_CanIfRxPduCfg_HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx                            59u
#define CanIfConf_CanIfRxPduCfg_HC1_oB30_for_SC_CAN_V3_2_f63a95a4_Rx                                60u
#define CanIfConf_CanIfRxPduCfg_BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx                               61u
#define CanIfConf_CanIfRxPduCfg_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx                            62u
#define CanIfConf_CanIfRxPduCfg_Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx                           63u
#define CanIfConf_CanIfRxPduCfg_ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx                               64u
#define CanIfConf_CanIfRxPduCfg_RPAS1_oB30_for_SC_CAN_V3_2_599017a9_Rx                              65u
#define CanIfConf_CanIfRxPduCfg_FPAS1_oB30_for_SC_CAN_V3_2_133a22d3_Rx                              66u
#define CanIfConf_CanIfRxPduCfg_HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx                            67u
#define CanIfConf_CanIfRxPduCfg_ABS3_oB30_for_SC_CAN_V3_2_961138dc_Rx                               68u
#define CanIfConf_CanIfRxPduCfg_Haldex1_oB30_for_SC_CAN_V3_2_bbae6b8e_Rx                            69u
#define CanIfConf_CanIfRxPduCfg_HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx                            70u
#define CanIfConf_CanIfRxPduCfg_ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx                               71u
#define CanIfConf_CanIfRxPduCfg_ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx                               72u
#define CanIfConf_CanIfRxPduCfg_CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx                               73u
#define CanIfConf_CanIfRxPduCfg_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx                         74u
#define CanIfConf_CanIfRxPduCfg_BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx                              75u
#define CanIfConf_CanIfRxPduCfg_DCT7_Sc_oB30_for_SC_CAN_V3_2_5c786cc5_Rx                            76u
#define CanIfConf_CanIfRxPduCfg_ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx                               77u
#define CanIfConf_CanIfRxPduCfg_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx                         78u
#define CanIfConf_CanIfRxPduCfg_IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx                            79u
#define CanIfConf_CanIfRxPduCfg_DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx                               80u
#define CanIfConf_CanIfRxPduCfg_STBS1_oB30_for_SC_CAN_V3_2_3fe5270b_Rx                              81u
#define CanIfConf_CanIfRxPduCfg_HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx                            82u
#define CanIfConf_CanIfRxPduCfg_HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx                            83u
#define CanIfConf_CanIfRxPduCfg_T_Box_FD4_oB30_for_SC_CAN_V3_2_f496a4b1_Rx                          84u
#define CanIfConf_CanIfRxPduCfg_HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx                            85u
#define CanIfConf_CanIfRxPduCfg_IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx                            86u
#define CanIfConf_CanIfRxPduCfg_R_PBox1_Sc_oB30_for_SC_CAN_V3_2_79c76dd7_Rx                         87u
#define CanIfConf_CanIfRxPduCfg_F_PBox1_oB30_for_SC_CAN_V3_2_cb257250_Rx                            88u
#define CanIfConf_CanIfRxPduCfg_AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx                            89u
#define CanIfConf_CanIfRxPduCfg_ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx                               90u
#define CanIfConf_CanIfRxPduCfg_RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx                           91u
#define CanIfConf_CanIfRxPduCfg_EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx                               92u
#define CanIfConf_CanIfRxPduCfg_EPS1_oB30_for_SC_CAN_V3_2_a33fe139_Rx                               93u
#define CanIfConf_CanIfRxPduCfg_CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx                               94u
#define CanIfConf_CanIfRxPduCfg_EPS2_oB30_for_SC_CAN_V3_2_7018c07d_Rx                               95u
#define CanIfConf_CanIfRxPduCfg_CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx                             96u
#define CanIfConf_CanIfRxPduCfg_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx                            97u
#define CanIfConf_CanIfRxPduCfg_ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx                               98u
#define CanIfConf_CanIfRxPduCfg_HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx                            99u
#define CanIfConf_CanIfRxPduCfg_ESP1_Sc_oB30_for_SC_CAN_V3_2_c7573a5b_Rx                            100u
#define CanIfConf_CanIfRxPduCfg_EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx                            101u
#define CanIfConf_CanIfRxPduCfg_ESP2_Sc_oB30_for_SC_CAN_V3_2_12ed4148_Rx                            102u
#define CanIfConf_CanIfRxPduCfg_ECM10_oB30_for_SC_CAN_V3_2_6dcbec2b_Rx                              103u
#define CanIfConf_CanIfRxPduCfg_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx                         104u
#define CanIfConf_CanIfRxPduCfg_Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx                       105u
#define CanIfConf_CanIfRxPduCfg_HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx                            106u
#define CanIfConf_CanIfRxPduCfg_ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx                            107u
#define CanIfConf_CanIfRxPduCfg_ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx                               108u
#define CanIfConf_CanIfRxPduCfg_IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx                               109u
#define CanIfConf_CanIfRxPduCfg_ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx                               110u
#define CanIfConf_CanIfRxPduCfg_BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx                               111u
#define CanIfConf_CanIfRxPduCfg_ESP10_oB30_for_SC_CAN_V3_2_119f3682_Rx                              112u
#define CanIfConf_CanIfRxPduCfg_ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx                              113u
#define CanIfConf_CanIfRxPduCfg_DHT_FD1_oB30_for_SC_CAN_V3_2_e564e605_Rx                            114u
#define CanIfConf_CanIfRxPduCfg_DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx                               115u
#define CanIfConf_CanIfRxPduCfg_CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx                               116u
#define CanIfConf_CanIfRxPduCfg_TMCU6_oB30_for_SC_CAN_V3_2_e6ceb015_Rx                              117u
#define CanIfConf_CanIfRxPduCfg_ECM8_oB30_for_SC_CAN_V3_2_a98d7fca_Rx                               118u
#define CanIfConf_CanIfRxPduCfg_ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx                               119u
#define CanIfConf_CanIfRxPduCfg_ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx                               120u
#define CanIfConf_CanIfRxPduCfg_HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx                            121u
#define CanIfConf_CanIfRxPduCfg_GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx                          122u
#define CanIfConf_CanIfRxPduCfg_T_Box_FD1_Sc_oB30_for_SC_CAN_V3_2_d763f605_Rx                       123u



/**********************************************************************************************************************
  \def  Tx buffer type
**********************************************************************************************************************/

#define CanIfTxBufferType                    NONE

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

#define CANIF_CFG_MAXTXDLC_PLUS_DATACHECKSUM      8u


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
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIG                       STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfig' Reason: 'Tx-buffer support is deactivated.' */
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG           STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfig.InvalidHnd' Reason: 'Tx-buffer support is deactivated.' */
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
#define CANIF_MAPPEDTXBUFFERSCONFIG                                   STD_OFF  /**< Deactivateable: 'CanIf_MappedTxBuffersConfig' Reason: 'Tx-buffer support is deactivated.' */
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
#define CANIF_SIZEOFCTRLCONFIG                                        STD_ON
#define CANIF_SIZEOFCTRLSTATES                                        STD_ON
#define CANIF_SIZEOFMAILBOXCONFIG                                     STD_ON
#define CANIF_SIZEOFRXDHADJUST                                        STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLIST                               STD_ON
#define CANIF_SIZEOFRXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFTRCVTOCTRLMAP                                     STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLIST                             STD_ON
#define CANIF_SIZEOFTXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFWAKEUPCONFIG                                      STD_ON
#define CANIF_TRANSCEIVERUPTOLOWMAP                                   STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_CANTRCVFCTTBLIDXOFTRANSCEIVERUPTOLOWMAP                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_CHANNELINDEXOFTRANSCEIVERUPTOLOWMAP                     STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.ChannelIndex' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_TRANSCEIVERUPTOUPPERMAP                                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_TRCVMODEINDICATIONFCTPTR                                STD_ON
#define CANIF_TRCVTOCTRLMAP                                           STD_ON
#define CANIF_TXBUFFERFIFOCONFIG                                      STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                  STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig.SizeOfOnePayloadEl' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG                       STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig.BitPos2TxPduIdOffset' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                      STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdByteQueueConfig' Reason: 'Tx-buffer PRIO_BY_CANID support as BYTE_QUEUE is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus' Reason: 'Tx-buffer PRIO_BY_CANID support as BYTE_QUEUE is deactivated.' */
#define CANIF_TXCONFIRMATIONFCTLIST                                   STD_ON
#define CANIF_TXPDUCONFIG                                             STD_ON
#define CANIF_CANIDOFTXPDUCONFIG                                      STD_ON
#define CANIF_CANIDTXMASKOFTXPDUCONFIG                                STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.CanIdTxMask' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_CTRLSTATESIDXOFTXPDUCONFIG                              STD_ON
#define CANIF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                        STD_ON
#define CANIF_ISPNWUTXPDUOFTXPDUCONFIG                                STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' */
#define CANIF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                          STD_ON
#define CANIF_MAILBOXCONFIGIDXOFTXPDUCONFIG                           STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                   STD_ON
#define CANIF_TXMETADATALENGTHOFTXPDUCONFIG                           STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.TxMetaDataLength' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_TXPDULENGTHOFTXPDUCONFIG                                STD_ON
#define CANIF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                          STD_ON
#define CANIF_TXPDUQUEUEINDEX                                         STD_OFF  /**< Deactivateable: 'CanIf_TxPduQueueIndex' Reason: 'Tx buffer support is deactivated.' */
#define CANIF_TXPDUSTATIC2DYNAMICINDIRECTION                          STD_OFF  /**< Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' */
#define CANIF_TXQUEUEINDEX2DATASTARTSTOP                              STD_OFF  /**< Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx-buffer is deactivated.' */
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
#define CANIF_CTRLCONFIGOFPCCONFIG                                    STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_CTRLSTATESOFPCCONFIG                                    STD_ON
#define CANIF_DATACHECKSUMRXERRFCTPTROFPCCONFIG                       STD_ON
#define CANIF_FINALMAGICNUMBEROFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                 STD_ON
#define CANIF_GENERATORVERSIONOFPCCONFIG                              STD_ON
#define CANIF_INITDATAHASHCODEOFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIGOFPCCONFIG                                 STD_ON
#define CANIF_MAXTRCVHANDLEIDPLUSONEOFPCCONFIG                        STD_ON
#define CANIF_MAXWAKEUPSOURCESOFPCCONFIG                              STD_ON
#define CANIF_RXDHADJUSTOFPCCONFIG                                    STD_ON
#define CANIF_RXINDICATIONFCTLISTOFPCCONFIG                           STD_ON
#define CANIF_RXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_SIZEOFCTRLCONFIGOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFCTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFMAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_SIZEOFRXDHADJUSTOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_SIZEOFRXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTRCVTOCTRLMAPOFPCCONFIG                           STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_SIZEOFTXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFWAKEUPCONFIGOFPCCONFIG                            STD_ON
#define CANIF_TRCVMODEINDICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_TRCVTOCTRLMAPOFPCCONFIG                                 STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTOFPCCONFIG                         STD_ON
#define CANIF_TXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_WAKEUPCONFIGOFPCCONFIG                                  STD_ON
#define CANIF_WAKEUPVALIDATIONFCTPTROFPCCONFIG                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIsReducedToDefineDefines  CanIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANIF_ISDEF_RXDHRANDOMNUMBER1OFCTRLCONFIG                     STD_OFF
#define CANIF_ISDEF_RXDHRANDOMNUMBER2OFCTRLCONFIG                     STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFMAILBOXCONFIG                      STD_OFF
#define CANIF_ISDEF_MAILBOXTYPEOFMAILBOXCONFIG                        STD_OFF
#define CANIF_ISDEF_PDUIDFIRSTOFMAILBOXCONFIG                         STD_OFF
#define CANIF_ISDEF_PDUIDLASTOFMAILBOXCONFIG                          STD_OFF
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
#define CANIF_ISDEF_TXCONFIRMATIONFCTLIST                             STD_OFF
#define CANIF_ISDEF_CANIDOFTXPDUCONFIG                                STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFTXPDUCONFIG                        STD_OFF
#define CANIF_ISDEF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                  STD_OFF
#define CANIF_ISDEF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                    STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFTXPDUCONFIG                     STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG             STD_OFF
#define CANIF_ISDEF_TXPDULENGTHOFTXPDUCONFIG                          STD_OFF
#define CANIF_ISDEF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                    STD_OFF
#define CANIF_ISDEF_CONTROLLEROFWAKEUPCONFIG                          STD_OFF
#define CANIF_ISDEF_WAKEUPSOURCEOFWAKEUPCONFIG                        STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                 STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                  STD_OFF
#define CANIF_ISDEF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CTRLCONFIGOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_DATACHECKSUMRXERRFCTPTROFPCCONFIG                 STD_ON
#define CANIF_ISDEF_MAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_ISDEF_RXDHADJUSTOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_RXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_ISDEF_RXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TRCVMODEINDICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_TRCVTOCTRLMAPOFPCCONFIG                           STD_ON
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_ISDEF_TXPDUCONFIGOFPCCONFIG                             STD_ON
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
#define CANIF_EQ2_RXDHRANDOMNUMBER1OFCTRLCONFIG                       
#define CANIF_EQ2_RXDHRANDOMNUMBER2OFCTRLCONFIG                       
#define CANIF_EQ2_CTRLSTATESIDXOFMAILBOXCONFIG                        
#define CANIF_EQ2_MAILBOXTYPEOFMAILBOXCONFIG                          
#define CANIF_EQ2_PDUIDFIRSTOFMAILBOXCONFIG                           
#define CANIF_EQ2_PDUIDLASTOFMAILBOXCONFIG                            
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
#define CANIF_EQ2_TXCONFIRMATIONFCTLIST                               
#define CANIF_EQ2_CANIDOFTXPDUCONFIG                                  
#define CANIF_EQ2_CTRLSTATESIDXOFTXPDUCONFIG                          
#define CANIF_EQ2_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                    
#define CANIF_EQ2_ISTXPDUTRUNCATIONOFTXPDUCONFIG                      
#define CANIF_EQ2_MAILBOXCONFIGIDXOFTXPDUCONFIG                       
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG               
#define CANIF_EQ2_TXPDULENGTHOFTXPDUCONFIG                            
#define CANIF_EQ2_UPPERLAYERTXPDUIDOFTXPDUCONFIG                      
#define CANIF_EQ2_CONTROLLEROFWAKEUPCONFIG                            
#define CANIF_EQ2_WAKEUPSOURCEOFWAKEUPCONFIG                          
#define CANIF_EQ2_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                   
#define CANIF_EQ2_WAKEUPTARGETMODULEOFWAKEUPCONFIG                    
#define CANIF_EQ2_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                  CanIf_BusOffNotificationFctPtr
#define CANIF_EQ2_CTRLCONFIGOFPCCONFIG                                CanIf_CtrlConfig
#define CANIF_EQ2_CTRLMODEINDICATIONFCTPTROFPCCONFIG                  CanIf_CtrlModeIndicationFctPtr
#define CANIF_EQ2_CTRLSTATESOFPCCONFIG                                CanIf_CtrlStates.raw
#define CANIF_EQ2_DATACHECKSUMRXERRFCTPTROFPCCONFIG                   CanIf_DataChecksumRxErrFctPtr
#define CANIF_EQ2_MAILBOXCONFIGOFPCCONFIG                             CanIf_MailBoxConfig
#define CANIF_EQ2_RXDHADJUSTOFPCCONFIG                                CanIf_RxDHAdjust
#define CANIF_EQ2_RXINDICATIONFCTLISTOFPCCONFIG                       CanIf_RxIndicationFctList
#define CANIF_EQ2_RXPDUCONFIGOFPCCONFIG                               CanIf_RxPduConfig
#define CANIF_EQ2_TRCVMODEINDICATIONFCTPTROFPCCONFIG                  CanIf_TrcvModeIndicationFctPtr
#define CANIF_EQ2_TRCVTOCTRLMAPOFPCCONFIG                             CanIf_TrcvToCtrlMap
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTOFPCCONFIG                     CanIf_TxConfirmationFctList
#define CANIF_EQ2_TXPDUCONFIGOFPCCONFIG                               CanIf_TxPduConfig
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
#define CanIf_GetCtrlConfigOfPCConfig()                               CanIf_CtrlConfig  /**< the pointer to CanIf_CtrlConfig */
#define CanIf_GetCtrlModeIndicationFctPtrOfPCConfig()                 CanIf_CtrlModeIndicationFctPtr  /**< the pointer to CanIf_CtrlModeIndicationFctPtr */
#define CanIf_GetCtrlStatesOfPCConfig()                               CanIf_CtrlStates.raw  /**< the pointer to CanIf_CtrlStates */
#define CanIf_GetDataChecksumRxErrFctPtrOfPCConfig()                  CanIf_DataChecksumRxErrFctPtr  /**< the pointer to CanIf_DataChecksumRxErrFctPtr */
#define CanIf_GetGeneratorCompatibilityVersionOfPCConfig()            0x0212u
#define CanIf_GetGeneratorVersionOfPCConfig()                         0x00041500u
#define CanIf_GetMailBoxConfigOfPCConfig()                            CanIf_MailBoxConfig  /**< the pointer to CanIf_MailBoxConfig */
#define CanIf_GetMaxTrcvHandleIdPlusOneOfPCConfig()                   3u
#define CanIf_GetMaxWakeUpSourcesOfPCConfig()                         2u
#define CanIf_GetRxDHAdjustOfPCConfig()                               CanIf_RxDHAdjust  /**< the pointer to CanIf_RxDHAdjust */
#define CanIf_GetRxIndicationFctListOfPCConfig()                      CanIf_RxIndicationFctList  /**< the pointer to CanIf_RxIndicationFctList */
#define CanIf_GetRxPduConfigOfPCConfig()                              CanIf_RxPduConfig  /**< the pointer to CanIf_RxPduConfig */
#define CanIf_GetSizeOfCtrlConfigOfPCConfig()                         3u  /**< the number of accomplishable value elements in CanIf_CtrlConfig */
#define CanIf_GetSizeOfCtrlStatesOfPCConfig()                         3u  /**< the number of accomplishable value elements in CanIf_CtrlStates */
#define CanIf_GetSizeOfMailBoxConfigOfPCConfig()                      6u  /**< the number of accomplishable value elements in CanIf_MailBoxConfig */
#define CanIf_GetSizeOfRxDHAdjustOfPCConfig()                         178u  /**< the number of accomplishable value elements in CanIf_RxDHAdjust */
#define CanIf_GetSizeOfRxIndicationFctListOfPCConfig()                4u  /**< the number of accomplishable value elements in CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfRxPduConfigOfPCConfig()                        124u  /**< the number of accomplishable value elements in CanIf_RxPduConfig */
#define CanIf_GetSizeOfTrcvToCtrlMapOfPCConfig()                      3u  /**< the number of accomplishable value elements in CanIf_TrcvToCtrlMap */
#define CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()              4u  /**< the number of accomplishable value elements in CanIf_TxConfirmationFctList */
#define CanIf_GetSizeOfTxPduConfigOfPCConfig()                        35u  /**< the number of accomplishable value elements in CanIf_TxPduConfig */
#define CanIf_GetSizeOfWakeUpConfigOfPCConfig()                       2u  /**< the number of accomplishable value elements in CanIf_WakeUpConfig */
#define CanIf_GetTrcvModeIndicationFctPtrOfPCConfig()                 CanIf_TrcvModeIndicationFctPtr  /**< the pointer to CanIf_TrcvModeIndicationFctPtr */
#define CanIf_GetTrcvToCtrlMapOfPCConfig()                            CanIf_TrcvToCtrlMap  /**< the pointer to CanIf_TrcvToCtrlMap */
#define CanIf_GetTxConfirmationFctListOfPCConfig()                    CanIf_TxConfirmationFctList  /**< the pointer to CanIf_TxConfirmationFctList */
#define CanIf_GetTxPduConfigOfPCConfig()                              CanIf_TxPduConfig  /**< the pointer to CanIf_TxPduConfig */
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
#define CanIf_GetTxConfirmationFctList(Index)                         (CanIf_GetTxConfirmationFctListOfPCConfig()[(Index)])
#define CanIf_GetCanIdOfTxPduConfig(Index)                            (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdOfTxPduConfig)
#define CanIf_GetCtrlStatesIdxOfTxPduConfig(Index)                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CtrlStatesIdxOfTxPduConfig)
#define CanIf_IsIsDataChecksumTxPduOfTxPduConfig(Index)               ((CanIf_GetTxPduConfigOfPCConfig()[(Index)].IsDataChecksumTxPduOfTxPduConfig) != FALSE)
#define CanIf_IsIsTxPduTruncationOfTxPduConfig(Index)                 ((CanIf_GetTxPduConfigOfPCConfig()[(Index)].IsTxPduTruncationOfTxPduConfig) != FALSE)
#define CanIf_GetMailBoxConfigIdxOfTxPduConfig(Index)                 (CanIf_GetTxPduConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfTxPduConfig)
#define CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(Index)         (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxConfirmationFctListIdxOfTxPduConfig)
#define CanIf_GetTxPduLengthOfTxPduConfig(Index)                      (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxPduLengthOfTxPduConfig)
#define CanIf_GetUpperLayerTxPduIdOfTxPduConfig(Index)                (CanIf_GetTxPduConfigOfPCConfig()[(Index)].UpperLayerTxPduIdOfTxPduConfig)
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
#define CanIf_GetMaxTrcvHandleIdPlusOne()                             CanIf_GetMaxTrcvHandleIdPlusOneOfPCConfig()
#define CanIf_GetMaxWakeUpSources()                                   CanIf_GetMaxWakeUpSourcesOfPCConfig()
#define CanIf_GetSizeOfCtrlConfig()                                   CanIf_GetSizeOfCtrlConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlStates()                                   CanIf_GetSizeOfCtrlStatesOfPCConfig()
#define CanIf_GetSizeOfMailBoxConfig()                                CanIf_GetSizeOfMailBoxConfigOfPCConfig()
#define CanIf_GetSizeOfRxDHAdjust()                                   CanIf_GetSizeOfRxDHAdjustOfPCConfig()
#define CanIf_GetSizeOfRxIndicationFctList()                          CanIf_GetSizeOfRxIndicationFctListOfPCConfig()
#define CanIf_GetSizeOfRxPduConfig()                                  CanIf_GetSizeOfRxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTrcvToCtrlMap()                                CanIf_GetSizeOfTrcvToCtrlMapOfPCConfig()
#define CanIf_GetSizeOfTxConfirmationFctList()                        CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()
#define CanIf_GetSizeOfTxPduConfig()                                  CanIf_GetSizeOfTxPduConfigOfPCConfig()
#define CanIf_GetSizeOfWakeUpConfig()                                 CanIf_GetSizeOfWakeUpConfigOfPCConfig()
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
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCHasMacros  CanIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanIf_HasBusOffNotificationFctPtr()                           (TRUE != FALSE)
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
#define CanIf_HasSizeOfCtrlConfig()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStates()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfRxDHAdjust()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctList()                          (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTrcvToCtrlMap()                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctList()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfig()                                 (TRUE != FALSE)
#define CanIf_HasTrcvModeIndicationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasTrcvToCtrlMap()                                      (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctList()                              (TRUE != FALSE)
#define CanIf_HasTxPduConfig()                                        (TRUE != FALSE)
#define CanIf_HasCanIdOfTxPduConfig()                                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfTxPduConfig()                         (TRUE != FALSE)
#define CanIf_HasIsDataChecksumTxPduOfTxPduConfig()                   (TRUE != FALSE)
#define CanIf_HasIsTxPduTruncationOfTxPduConfig()                     (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfTxPduConfig()                      (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListIdxOfTxPduConfig()              (TRUE != FALSE)
#define CanIf_HasTxPduLengthOfTxPduConfig()                           (TRUE != FALSE)
#define CanIf_HasUpperLayerTxPduIdOfTxPduConfig()                     (TRUE != FALSE)
#define CanIf_HasWakeUpConfig()                                       (TRUE != FALSE)
#define CanIf_HasControllerOfWakeUpConfig()                           (TRUE != FALSE)
#define CanIf_HasWakeUpSourceOfWakeUpConfig()                         (TRUE != FALSE)
#define CanIf_HasWakeUpTargetAddressOfWakeUpConfig()                  (TRUE != FALSE)
#define CanIf_HasWakeUpTargetModuleOfWakeUpConfig()                   (TRUE != FALSE)
#define CanIf_HasWakeUpValidationFctPtr()                             (TRUE != FALSE)
#define CanIf_HasPCConfig()                                           (TRUE != FALSE)
#define CanIf_HasBusOffNotificationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCtrlConfigOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasDataChecksumRxErrFctPtrOfPCConfig()                  (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersionOfPCConfig()            (TRUE != FALSE)
#define CanIf_HasGeneratorVersionOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasMailBoxConfigOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasMaxTrcvHandleIdPlusOneOfPCConfig()                   (TRUE != FALSE)
#define CanIf_HasMaxWakeUpSourcesOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasRxDHAdjustOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasRxPduConfigOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlConfigOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStatesOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfigOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasSizeOfRxDHAdjustOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctListOfPCConfig()                (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTrcvToCtrlMapOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctListOfPCConfig()              (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfigOfPCConfig()                       (TRUE != FALSE)
#define CanIf_HasTrcvModeIndicationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasTrcvToCtrlMapOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasTxPduConfigOfPCConfig()                              (TRUE != FALSE)
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
/**   \brief  type used to iterate CanIf_CtrlConfig */
typedef uint8_least CanIf_CtrlConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlStates */
typedef uint8_least CanIf_CtrlStatesIterType;

/**   \brief  type used to iterate CanIf_MailBoxConfig */
typedef uint8_least CanIf_MailBoxConfigIterType;

/**   \brief  type used to iterate CanIf_RxDHAdjust */
typedef uint8_least CanIf_RxDHAdjustIterType;

/**   \brief  type used to iterate CanIf_RxIndicationFctList */
typedef uint8_least CanIf_RxIndicationFctListIterType;

/**   \brief  type used to iterate CanIf_RxPduConfig */
typedef uint8_least CanIf_RxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TrcvToCtrlMap */
typedef uint8_least CanIf_TrcvToCtrlMapIterType;

/**   \brief  type used to iterate CanIf_TxConfirmationFctList */
typedef uint8_least CanIf_TxConfirmationFctListIterType;

/**   \brief  type used to iterate CanIf_TxPduConfig */
typedef uint8_least CanIf_TxPduConfigIterType;

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

/**   \brief  value based type definition for CanIf_SizeOfCtrlConfig */
typedef uint8 CanIf_SizeOfCtrlConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlStates */
typedef uint8 CanIf_SizeOfCtrlStatesType;

/**   \brief  value based type definition for CanIf_SizeOfMailBoxConfig */
typedef uint8 CanIf_SizeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_SizeOfRxDHAdjust */
typedef uint8 CanIf_SizeOfRxDHAdjustType;

/**   \brief  value based type definition for CanIf_SizeOfRxIndicationFctList */
typedef uint8 CanIf_SizeOfRxIndicationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfRxPduConfig */
typedef uint8 CanIf_SizeOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTrcvToCtrlMap */
typedef uint8 CanIf_SizeOfTrcvToCtrlMapType;

/**   \brief  value based type definition for CanIf_SizeOfTxConfirmationFctList */
typedef uint8 CanIf_SizeOfTxConfirmationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduConfig */
typedef uint8 CanIf_SizeOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfWakeUpConfig */
typedef uint8 CanIf_SizeOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_TrcvToCtrlMap */
typedef uint8 CanIf_TrcvToCtrlMapType;

/**   \brief  value based type definition for CanIf_CanIdOfTxPduConfig */
typedef uint16 CanIf_CanIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfTxPduConfig */
typedef uint8 CanIf_CtrlStatesIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_IsDataChecksumTxPduOfTxPduConfig */
typedef boolean CanIf_IsDataChecksumTxPduOfTxPduConfigType;

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
  CanIf_MailBoxTypeType MailBoxTypeOfMailBoxConfig;  /**< Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused. */
} CanIf_MailBoxConfigType;

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

/**   \brief  type used in CanIf_TxPduConfig */
typedef struct sCanIf_TxPduConfigType
{
  CanIf_UpperLayerTxPduIdOfTxPduConfigType UpperLayerTxPduIdOfTxPduConfig;  /**< Upper layer handle ID (8bit / 16bit). */
  CanIf_CanIdOfTxPduConfigType CanIdOfTxPduConfig;  /**< CAN identifier (16bit / 32bit). */
  CanIf_IsDataChecksumTxPduOfTxPduConfigType IsDataChecksumTxPduOfTxPduConfig;  /**< TRUE: Data checksum Tx-PDU, FALSE: None Data checksum Tx-PDU */
  CanIf_IsTxPduTruncationOfTxPduConfigType IsTxPduTruncationOfTxPduConfig;  /**< TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled */
  CanIf_CtrlStatesIdxOfTxPduConfigType CtrlStatesIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_MailBoxConfigIdxOfTxPduConfigType MailBoxConfigIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
  CanIf_TxConfirmationFctListIdxOfTxPduConfigType TxConfirmationFctListIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList */
  CanIf_TxPduLengthOfTxPduConfigType TxPduLengthOfTxPduConfig;  /**< Tx-PDU length. */
} CanIf_TxPduConfigType;

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

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootPointerTypes  CanIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanIf_CtrlConfig */
typedef P2CONST(CanIf_CtrlConfigType, TYPEDEF, CANIF_CONST) CanIf_CtrlConfigPtrType;

/**   \brief  type used to point to CanIf_CtrlStates */
typedef P2VAR(CanIf_CtrlStatesType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_CtrlStatesPtrType;

/**   \brief  type used to point to CanIf_MailBoxConfig */
typedef P2CONST(CanIf_MailBoxConfigType, TYPEDEF, CANIF_CONST) CanIf_MailBoxConfigPtrType;

/**   \brief  type used to point to CanIf_RxDHAdjust */
typedef P2CONST(CanIf_RxDHAdjustType, TYPEDEF, CANIF_CONST) CanIf_RxDHAdjustPtrType;

/**   \brief  type used to point to CanIf_RxIndicationFctList */
typedef P2CONST(CanIf_RxIndicationFctListType, TYPEDEF, CANIF_CONST) CanIf_RxIndicationFctListPtrType;

/**   \brief  type used to point to CanIf_RxPduConfig */
typedef P2CONST(CanIf_RxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_RxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TrcvToCtrlMap */
typedef P2CONST(CanIf_TrcvToCtrlMapType, TYPEDEF, CANIF_CONST) CanIf_TrcvToCtrlMapPtrType;

/**   \brief  type used to point to CanIf_TxConfirmationFctList */
typedef P2CONST(CanIf_TxConfirmationFctType, TYPEDEF, CANIF_CONST) CanIf_TxConfirmationFctListPtrType;

/**   \brief  type used to point to CanIf_TxPduConfig */
typedef P2CONST(CanIf_TxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_TxPduConfigPtrType;

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
  Element          Description
  CtrlStatesIdx    the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst       "First" PDU mapped to mailbox.
  PduIdLast        "Last" PDU mapped to mailbox.
  MailBoxType      Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[6];
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
extern CONST(CanIf_RxDHAdjustType, CANIF_CONST) CanIf_RxDHAdjust[178];
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
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[124];
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
  IsDataChecksumTxPdu         TRUE: Data checksum Tx-PDU, FALSE: None Data checksum Tx-PDU
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
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[35];
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


