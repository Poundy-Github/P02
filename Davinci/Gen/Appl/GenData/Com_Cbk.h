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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cbk.h
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx         0u
#define ComConf_ComIPdu_ABM2_oB30_for_SC_CAN_V3_2_e97c616e_Rx         1u
#define ComConf_ComIPdu_ABS1_oB30_for_SC_CAN_V3_2_3c057b3e_Rx         2u
#define ComConf_ComIPdu_ABS2_oB30_for_SC_CAN_V3_2_057dd67e_Rx         3u
#define ComConf_ComIPdu_AC1_oB30_for_SC_CAN_V3_2_b80b56cf_Rx          4u
#define ComConf_ComIPdu_AC2_oB30_for_SC_CAN_V3_2_8173fb8f_Rx          5u
#define ComConf_ComIPdu_AC3_oB30_for_SC_CAN_V3_2_965b9f4f_Rx          6u
#define ComConf_ComIPdu_AC4_oB30_for_SC_CAN_V3_2_f382a10f_Rx          7u
#define ComConf_ComIPdu_AC6_oB30_for_SC_CAN_V3_2_ddd2688f_Rx          8u
#define ComConf_ComIPdu_AC7_oB30_for_SC_CAN_V3_2_cafa0c4f_Rx          9u
#define ComConf_ComIPdu_AC8_oB30_for_SC_CAN_V3_2_1660140f_Rx          10u
#define ComConf_ComIPdu_AC14_oB30_for_SC_CAN_V3_2_1c102f98_Rx         11u
#define ComConf_ComIPdu_ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx      12u
#define ComConf_ComIPdu_ACC_FD3_oB30_for_SC_CAN_V3_2_d3df4879_Rx      13u
#define ComConf_ComIPdu_ACC_FD4_oB30_for_SC_CAN_V3_2_b6067639_Rx      14u
#define ComConf_ComIPdu_AEB_FD1_oB30_for_SC_CAN_V3_2_a6cb7aa9_Rx      15u
#define ComConf_ComIPdu_AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx      16u
#define ComConf_ComIPdu_ALS1_oB30_for_SC_CAN_V3_2_5e3515d0_Rx         17u
#define ComConf_ComIPdu_AMP1_oB30_for_SC_CAN_V3_2_a9f549ca_Rx         18u
#define ComConf_ComIPdu_AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx         19u
#define ComConf_ComIPdu_AMP3_oB30_for_SC_CAN_V3_2_87a5804a_Rx         20u
#define ComConf_ComIPdu_AMP4_ANC1_oB30_for_SC_CAN_V3_2_0839201d_Rx    21u
#define ComConf_ComIPdu_BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx         22u
#define ComConf_ComIPdu_BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx         23u
#define ComConf_ComIPdu_BCM7_oB30_for_SC_CAN_V3_2_163d45da_Rx         24u
#define ComConf_ComIPdu_BCM8_oB30_for_SC_CAN_V3_2_caa75d9a_Rx         25u
#define ComConf_ComIPdu_BCM11_oB30_for_SC_CAN_V3_2_d72078da_Rx        26u
#define ComConf_ComIPdu_BCM12_oB30_for_SC_CAN_V3_2_ee58d59a_Rx        27u
#define ComConf_ComIPdu_BCM14_oB30_for_SC_CAN_V3_2_9ca98f1a_Rx        28u
#define ComConf_ComIPdu_BCM18_oB30_for_SC_CAN_V3_2_794b3a1a_Rx        29u
#define ComConf_ComIPdu_BCM19_oB30_for_SC_CAN_V3_2_6e635eda_Rx        30u
#define ComConf_ComIPdu_BLE1_oB30_for_SC_CAN_V3_2_876057b5_Rx         31u
#define ComConf_ComIPdu_BLE5_oB30_for_SC_CAN_V3_2_dbc1c4b5_Rx         32u
#define ComConf_ComIPdu_BMS4_oB30_for_SC_CAN_V3_2_a1743164_Rx         33u
#define ComConf_ComIPdu_BMS8_oB30_for_SC_CAN_V3_2_44968464_Rx         34u
#define ComConf_ComIPdu_BMS19_oB30_for_SC_CAN_V3_2_34e8b018_Rx        35u
#define ComConf_ComIPdu_BMS22_oB30_for_SC_CAN_V3_2_c2360265_Rx        36u
#define ComConf_ComIPdu_BMS30_oB30_for_SC_CAN_V3_2_77152131_Rx        37u
#define ComConf_ComIPdu_BMS35_oB30_for_SC_CAN_V3_2_3c9cd6f1_Rx        38u
#define ComConf_ComIPdu_BMS65_oB30_for_SC_CAN_V3_2_a7b39db6_Rx        39u
#define ComConf_ComIPdu_BMS66_oB30_for_SC_CAN_V3_2_9ecb30f6_Rx        40u
#define ComConf_ComIPdu_BMS_FD14_oB30_for_SC_CAN_V3_2_20801849_Rx     41u
#define ComConf_ComIPdu_CP1_oB30_for_SC_CAN_V3_2_16a725b1_Rx          42u
#define ComConf_ComIPdu_CR_FD1_oB30_for_SC_CAN_V3_2_da926426_Rx       43u
#define ComConf_ComIPdu_CSA1_oB30_for_SC_CAN_V3_2_bec912dc_Rx         44u
#define ComConf_ComIPdu_CSA2_oB30_for_SC_CAN_V3_2_87b1bf9c_Rx         45u
#define ComConf_ComIPdu_CSA3_oB30_for_SC_CAN_V3_2_9099db5c_Rx         46u
#define ComConf_ComIPdu_DCT3_oB30_for_SC_CAN_V3_2_bbff95c2_Rx         47u
#define ComConf_ComIPdu_DCT5_oB30_for_SC_CAN_V3_2_c90ecf42_Rx         48u
#define ComConf_ComIPdu_DCT_FD4_oB30_for_SC_CAN_V3_2_c3f55f0e_Rx      49u
#define ComConf_ComIPdu_DDCM1_oB30_for_SC_CAN_V3_2_4226467c_Rx        50u
#define ComConf_ComIPdu_DDCM3_oB30_for_SC_CAN_V3_2_6c768ffc_Rx        51u
#define ComConf_ComIPdu_DOCK1_oB30_for_SC_CAN_V3_2_b60a11e2_Rx        52u
#define ComConf_ComIPdu_DOCK2_oB30_for_SC_CAN_V3_2_8f72bca2_Rx        53u
#define ComConf_ComIPdu_DSC4_oB30_for_SC_CAN_V3_2_d686ca5d_Rx         54u
#define ComConf_ComIPdu_DSM1_oB30_for_SC_CAN_V3_2_707c0cc1_Rx         55u
#define ComConf_ComIPdu_DWD1_oB30_for_SC_CAN_V3_2_82b03b6c_Rx         56u
#define ComConf_ComIPdu_EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_683305cd_Rx 57u
#define ComConf_ComIPdu_ECM1_oB30_for_SC_CAN_V3_2_aa9ce3f2_Rx         58u
#define ComConf_ComIPdu_ECM2_oB30_for_SC_CAN_V3_2_93e44eb2_Rx         59u
#define ComConf_ComIPdu_ECM3_oB30_for_SC_CAN_V3_2_84cc2a72_Rx         60u
#define ComConf_ComIPdu_ECM4_oB30_for_SC_CAN_V3_2_e1151432_Rx         61u
#define ComConf_ComIPdu_ECM7_oB30_for_SC_CAN_V3_2_d86db972_Rx         62u
#define ComConf_ComIPdu_ECM9_oB30_for_SC_CAN_V3_2_13dfc5f2_Rx         63u
#define ComConf_ComIPdu_ECM11_oB30_for_SC_CAN_V3_2_0fe303fc_Rx        64u
#define ComConf_ComIPdu_ECM16_oB30_for_SC_CAN_V3_2_6a3a3dbc_Rx        65u
#define ComConf_ComIPdu_ECM19_oB30_for_SC_CAN_V3_2_b6a025fc_Rx        66u
#define ComConf_ComIPdu_ECM20_oB30_for_SC_CAN_V3_2_6e2e5e01_Rx        67u
#define ComConf_ComIPdu_ECM24_oB30_for_SC_CAN_V3_2_328fcd01_Rx        68u
#define ComConf_ComIPdu_ECM_PT5_oB30_for_SC_CAN_V3_2_032abda1_Rx      69u
#define ComConf_ComIPdu_ECM_PT6_oB30_for_SC_CAN_V3_2_3a5210e1_Rx      70u
#define ComConf_ComIPdu_ECM_PT7_oB30_for_SC_CAN_V3_2_2d7a7421_Rx      71u
#define ComConf_ComIPdu_EEM1_oB30_for_SC_CAN_V3_2_1aa1b1a2_Rx         72u
#define ComConf_ComIPdu_ELD1_oB30_for_SC_CAN_V3_2_d24341c9_Rx         73u
#define ComConf_ComIPdu_EPB1_oB30_for_SC_CAN_V3_2_fbe9ee6f_Rx         74u
#define ComConf_ComIPdu_EPS_FD1_oB30_for_SC_CAN_V3_2_bceaa863_Rx      75u
#define ComConf_ComIPdu_ESCL2_oB30_for_SC_CAN_V3_2_91777cb9_Rx        76u
#define ComConf_ComIPdu_ESP8_oB30_for_SC_CAN_V3_2_e1785022_Rx         77u
#define ComConf_ComIPdu_ESP11_oB30_for_SC_CAN_V3_2_12b19c69_Rx        78u
#define ComConf_ComIPdu_ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx      79u
#define ComConf_ComIPdu_ETC2_oB30_for_SC_CAN_V3_2_30e437a4_Rx         80u
#define ComConf_ComIPdu_ETC3_oB30_for_SC_CAN_V3_2_27cc5364_Rx         81u
#define ComConf_ComIPdu_ETC4_oB30_for_SC_CAN_V3_2_42156d24_Rx         82u
#define ComConf_ComIPdu_F_PBOX1_oB30_for_SC_CAN_V3_2_24a181fc_Rx      83u
#define ComConf_ComIPdu_GLO_NASS1_oB30_for_SC_CAN_V3_2_96a1bccc_Rx    84u
#define ComConf_ComIPdu_GW_FD1_oB30_for_SC_CAN_V3_2_765a3f2a_Rx       85u
#define ComConf_ComIPdu_GW_OTA_oB30_for_SC_CAN_V3_2_cf261bba_Rx       86u
#define ComConf_ComIPdu_GW_Sync_Req_oB30_for_SC_CAN_V3_2_6800966b_Rx  87u
#define ComConf_ComIPdu_HAP_FD1_oB30_for_SC_CAN_V3_2_7488140e_Rx      88u
#define ComConf_ComIPdu_HAP_FD2_oB30_for_SC_CAN_V3_2_4df0b94e_Rx      89u
#define ComConf_ComIPdu_HAP_FD3_oB30_for_SC_CAN_V3_2_5ad8dd8e_Rx      90u
#define ComConf_ComIPdu_HAP_FD6_oB30_for_SC_CAN_V3_2_11512a4e_Rx      91u
#define ComConf_ComIPdu_HAP_FD7_oB30_for_SC_CAN_V3_2_06794e8e_Rx      92u
#define ComConf_ComIPdu_HCM_L1_oB30_for_SC_CAN_V3_2_02400631_Rx       93u
#define ComConf_ComIPdu_HCM_L2_oB30_for_SC_CAN_V3_2_3b38ab71_Rx       94u
#define ComConf_ComIPdu_HCM_R1_oB30_for_SC_CAN_V3_2_ee41b121_Rx       95u
#define ComConf_ComIPdu_HCM_R2_oB30_for_SC_CAN_V3_2_d7391c61_Rx       96u
#define ComConf_ComIPdu_HCU_FD1_oB30_for_SC_CAN_V3_2_641912c5_Rx      97u
#define ComConf_ComIPdu_HCU_HC3_oB30_for_SC_CAN_V3_2_5ec02d05_Rx      98u
#define ComConf_ComIPdu_HCU_HC6_oB30_for_SC_CAN_V3_2_1549dac5_Rx      99u
#define ComConf_ComIPdu_HCU_HC7_oB30_for_SC_CAN_V3_2_0261be05_Rx      100u
#define ComConf_ComIPdu_HCU_HC8_oB30_for_SC_CAN_V3_2_defba645_Rx      101u
#define ComConf_ComIPdu_HCU_HC16_oB30_for_SC_CAN_V3_2_a481d524_Rx     102u
#define ComConf_ComIPdu_HCU_HP5_oB30_for_SC_CAN_V3_2_5ba6c8f4_Rx      103u
#define ComConf_ComIPdu_HCU_HP6_oB30_for_SC_CAN_V3_2_62de65b4_Rx      104u
#define ComConf_ComIPdu_HCU_HP8_oB30_for_SC_CAN_V3_2_a96c1934_Rx      105u
#define ComConf_ComIPdu_HCU_PT4_oB30_for_SC_CAN_V3_2_e1b44e24_Rx      106u
#define ComConf_ComIPdu_HCU_PT5_oB30_for_SC_CAN_V3_2_f69c2ae4_Rx      107u
#define ComConf_ComIPdu_HCU_PT7_oB30_for_SC_CAN_V3_2_d8cce364_Rx      108u
#define ComConf_ComIPdu_HCU_PT8_oB30_for_SC_CAN_V3_2_0456fb24_Rx      109u
#define ComConf_ComIPdu_HUD1_oB30_for_SC_CAN_V3_2_8c3d2e2f_Rx         110u
#define ComConf_ComIPdu_IFC1_oB30_for_SC_CAN_V3_2_787af09a_Rx         111u
#define ComConf_ComIPdu_IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx      112u
#define ComConf_ComIPdu_IFC_FD3_oB30_for_SC_CAN_V3_2_d1bdd095_Rx      113u
#define ComConf_ComIPdu_IFC_FD5_oB30_for_SC_CAN_V3_2_a34c8a15_Rx      114u
#define ComConf_ComIPdu_IFC_FD6_oB30_for_SC_CAN_V3_2_9a342755_Rx      115u
#define ComConf_ComIPdu_Ibooster_FD2_oB30_for_SC_CAN_V3_2_e9e18adf_Rx 116u
#define ComConf_ComIPdu_OBC1_oB30_for_SC_CAN_V3_2_7aa70263_Rx         117u
#define ComConf_ComIPdu_OBC2_oB30_for_SC_CAN_V3_2_43dfaf23_Rx         118u
#define ComConf_ComIPdu_P2M1_oB30_for_SC_CAN_V3_2_8af900bc_Rx         119u
#define ComConf_ComIPdu_P2M3_oB30_for_SC_CAN_V3_2_a4a9c93c_Rx         120u
#define ComConf_ComIPdu_PDCM1_oB30_for_SC_CAN_V3_2_c2e08bda_Rx        121u
#define ComConf_ComIPdu_PEPS2_oB30_for_SC_CAN_V3_2_9567d791_Rx        122u
#define ComConf_ComIPdu_PEPS4_oB30_for_SC_CAN_V3_2_e7968d11_Rx        123u
#define ComConf_ComIPdu_RFCM_L1_oB30_for_SC_CAN_V3_2_0f4843bb_Rx      124u
#define ComConf_ComIPdu_RFCM_R1_oB30_for_SC_CAN_V3_2_e349f4ab_Rx      125u
#define ComConf_ComIPdu_RSDS_FD1_oB30_for_SC_CAN_V3_2_984f3330_Rx     126u
#define ComConf_ComIPdu_RSDS_FD2_oB30_for_SC_CAN_V3_2_a1379e70_Rx     127u
#define ComConf_ComIPdu_R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx      128u
#define ComConf_ComIPdu_SCM1_oB30_for_SC_CAN_V3_2_9950a83a_Rx         129u
#define ComConf_ComIPdu_TOD1_oB30_for_SC_CAN_V3_2_77c15f81_Rx         130u
#define ComConf_ComIPdu_TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx        131u
#define ComConf_ComIPdu_TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx        132u
#define ComConf_ComIPdu_T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx    133u
#define ComConf_ComIPdu_T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx    134u
#define ComConf_ComIPdu_T_BOX_FD4_oB30_for_SC_CAN_V3_2_f4d43aba_Rx    135u
#define ComConf_ComIPdu_T_BOX_FD9_oB30_for_SC_CAN_V3_2_061eeb7a_Rx    136u
#define ComConf_ComIPdu_T_BOX_FD10_oB30_for_SC_CAN_V3_2_fbbdad00_Rx   137u
#define ComConf_ComIPdu_Trailer1_oB30_for_SC_CAN_V3_2_7da566bd_Rx     138u
#define ComConf_ComIPdu_VMDR1_oB30_for_SC_CAN_V3_2_32d43f61_Rx        139u
#define ComConf_ComIPdu_WPC1_oB30_for_SC_CAN_V3_2_a8eb0588_Rx         140u
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ComIPdu_userData_tx                           0u
#define ComConf_ComIPdu_DMS_FD1_oB30_for_SC_CAN_V3_2_2e6458a5_Tx      1u
#define ComConf_ComIPdu_DVR_FD1_oB30_for_SC_CAN_V3_2_e61bae2e_Tx      2u
#define ComConf_ComIPdu_HUT1_oB30_for_SC_CAN_V3_2_8d4fa863_Tx         3u
#define ComConf_ComIPdu_HUT2_oB30_for_SC_CAN_V3_2_b4370523_Tx         4u
#define ComConf_ComIPdu_HUT3_oB30_for_SC_CAN_V3_2_a31f61e3_Tx         5u
#define ComConf_ComIPdu_HUT4_oB30_for_SC_CAN_V3_2_c6c65fa3_Tx         6u
#define ComConf_ComIPdu_HUT6_oB30_for_SC_CAN_V3_2_e8969623_Tx         7u
#define ComConf_ComIPdu_HUT7_oB30_for_SC_CAN_V3_2_ffbef2e3_Tx         8u
#define ComConf_ComIPdu_HUT10_oB30_for_SC_CAN_V3_2_9fe417a5_Tx        9u
#define ComConf_ComIPdu_HUT12_oB30_for_SC_CAN_V3_2_b1b4de25_Tx        10u
#define ComConf_ComIPdu_HUT13_oB30_for_SC_CAN_V3_2_a69cbae5_Tx        11u
#define ComConf_ComIPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx        12u
#define ComConf_ComIPdu_HUT16_oB30_for_SC_CAN_V3_2_ed154d25_Tx        13u
#define ComConf_ComIPdu_HUT17_oB30_for_SC_CAN_V3_2_fa3d29e5_Tx        14u
#define ComConf_ComIPdu_HUT19_oB30_for_SC_CAN_V3_2_318f5565_Tx        15u
#define ComConf_ComIPdu_HUT20_oB30_for_SC_CAN_V3_2_e9012e98_Tx        16u
#define ComConf_ComIPdu_HUT21_oB30_for_SC_CAN_V3_2_fe294a58_Tx        17u
#define ComConf_ComIPdu_HUT22_oB30_for_SC_CAN_V3_2_c751e718_Tx        18u
#define ComConf_ComIPdu_HUT23_oB30_for_SC_CAN_V3_2_d07983d8_Tx        19u
#define ComConf_ComIPdu_HUT25_oB30_for_SC_CAN_V3_2_a288d958_Tx        20u
#define ComConf_ComIPdu_HUT26_oB30_for_SC_CAN_V3_2_9bf07418_Tx        21u
#define ComConf_ComIPdu_HUT27_oB30_for_SC_CAN_V3_2_8cd810d8_Tx        22u
#define ComConf_ComIPdu_HUT30_oB30_for_SC_CAN_V3_2_7272c44c_Tx        23u
#define ComConf_ComIPdu_HUT31_oB30_for_SC_CAN_V3_2_655aa08c_Tx        24u
#define ComConf_ComIPdu_HUT32_oB30_for_SC_CAN_V3_2_5c220dcc_Tx        25u
#define ComConf_ComIPdu_HUT33_oB30_for_SC_CAN_V3_2_4b0a690c_Tx        26u
#define ComConf_ComIPdu_HUT34_oB30_for_SC_CAN_V3_2_2ed3574c_Tx        27u
#define ComConf_ComIPdu_HUT35_oB30_for_SC_CAN_V3_2_39fb338c_Tx        28u
#define ComConf_ComIPdu_HUT36_oB30_for_SC_CAN_V3_2_00839ecc_Tx        29u
#define ComConf_ComIPdu_HUT37_oB30_for_SC_CAN_V3_2_17abfa0c_Tx        30u
#define ComConf_ComIPdu_HUT38_oB30_for_SC_CAN_V3_2_cb31e24c_Tx        31u
#define ComConf_ComIPdu_HUT39_oB30_for_SC_CAN_V3_2_dc19868c_Tx        32u
#define ComConf_ComIPdu_HUT40_oB30_for_SC_CAN_V3_2_04cb5ce2_Tx        33u
#define ComConf_ComIPdu_HUT41_oB30_for_SC_CAN_V3_2_13e33822_Tx        34u
#define ComConf_ComIPdu_HUT42_oB30_for_SC_CAN_V3_2_2a9b9562_Tx        35u
#define ComConf_ComIPdu_HUT43_oB30_for_SC_CAN_V3_2_3db3f1a2_Tx        36u
#define ComConf_ComIPdu_HUT45_oB30_for_SC_CAN_V3_2_4f42ab22_Tx        37u
#define ComConf_ComIPdu_HUT46_oB30_for_SC_CAN_V3_2_763a0662_Tx        38u
#define ComConf_ComIPdu_HUT49_oB30_for_SC_CAN_V3_2_aaa01e22_Tx        39u
#define ComConf_ComIPdu_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx      40u
#define ComConf_ComIPdu_HUT_FD2_oB30_for_SC_CAN_V3_2_5851ef80_Tx      41u
#define ComConf_ComIPdu_HUT_FD3_oB30_for_SC_CAN_V3_2_4f798b40_Tx      42u
#define ComConf_ComIPdu_HUT_FD4_oB30_for_SC_CAN_V3_2_2aa0b500_Tx      43u
#define ComConf_ComIPdu_HUT_FD5_oB30_for_SC_CAN_V3_2_3d88d1c0_Tx      44u
#define ComConf_ComIPdu_HUT_Sync_Req_oB30_for_SC_CAN_V3_2_c00563cb_Tx 45u
#define ComConf_ComIPdu_IP1_oB30_for_SC_CAN_V3_2_1d91d500_Tx          46u
#define ComConf_ComIPdu_IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx          47u
#define ComConf_ComIPdu_IP3_oB30_for_SC_CAN_V3_2_33c11c80_Tx          48u
#define ComConf_ComIPdu_ZCluster_Debug_Msg_0x7AB_Tx                   49u
#define ComConf_ComIPdu_ZCluster_Debug_Msg_0x7AC_Tx                   50u
#define ComConf_ComIPdu_ZCluster_Debug_Msg_0x7AD_Tx                   51u
#define ComConf_ComIPdu_ZCluster_Debug_Msg_0x7AE_Tx                   52u
#define ComConf_ComIPdu_ZCluster_Debug_Msg_0x7AF_Tx                   53u
/**\} */

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
#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /*MD_MSR_MemMap */
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after an I-PDU has been received.
    \param[in]    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                               Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param[in]    PduInfoPtr   Payload information of the received I-PDU (pointer to data and data length).
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737026
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after the PDU has been transmitted on the network.
                  A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param[in]    TxPduId   ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737028
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
  Com_TriggerTransmit
**********************************************************************************************************************/
/** \brief          This function is called by the lower layer when an AUTOSAR COM I-PDU shall be transmitted.
                    Within this function, AUTOSAR COM shall copy the contents of its I-PDU transmit buffer
                    to the L-PDU buffer given by SduPtr.
                    Use case:
                    This function is used e.g. by the LIN Master for sending out a LIN frame. In this case, the trigger transmit
                    can be initiated by the Master schedule table itself or a received LIN header.
                    This function is also used by the FlexRay Interface for requesting PDUs to be sent in static part
                    (synchronous to the FlexRay global time). Once the I-PDU has been successfully sent by the lower layer
                    (PDU-Router), the lower layer must call Com_TxConfirmation().
    \param[in]      TxPduId       ID of AUTOSAR COM I-PDU that is requested to be transmitted by AUTOSAR COM.
    \param[in,out]  PduInfoPtr    Contains a pointer to a buffer (SduDataPtr) where the SDU
                                  data shall be copied to, and the available buffer size in SduLengh.
                                  On return, the service will indicate the length of the copied SDU
                                  data in SduLength.
    \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
    \return         E_NOT_OK      No data has been copied, because
                                  Com is not initialized
                                  or TxPduId is not valid
                                  or PduInfoPtr is NULL_PTR
                                  or SduDataPtr is NULL_PTR
                                  or SduLength is too small.
    \context        TASK|ISR2
    \synchronous    TRUE
    \reentrant      TRUE, for different Handles
    \trace          SPEC-2737022, SPEC-2737023, SPEC-2737024
    \note           The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_VAR) PduInfoPtr);


#define COM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

