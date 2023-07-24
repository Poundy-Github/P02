/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Cbk.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CBK_H
# define RTE_CBK_H

# include "Com.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * COM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AMP2_0x3E3_oAMP2_oB30_for_SC_CAN_V3_2_fcde4f66_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_AMP3_0x3E5_oAMP3_oB30_for_SC_CAN_V3_2_cac874de_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx(void);

/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ABS1_0x231_oABS1_oB30_for_SC_CAN_V3_2_12e0e9e4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ABS2_0x246_oABS2_oB30_for_SC_CAN_V3_2_b0714d10_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AC1_0x29D_oAC1_oB30_for_SC_CAN_V3_2_22980340_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AC2_0x385_oAC2_oB30_for_SC_CAN_V3_2_0cf77687_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ACC_FD2_0x2AB_oACC_FD2_oB30_for_SC_CAN_V3_2_33ba28b9_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ACC_FD3_0x2B4_oACC_FD3_oB30_for_SC_CAN_V3_2_adc7888c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_AEB_FD2_0x227_oAEB_FD2_oB30_for_SC_CAN_V3_2_b89db7a8_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM12_0x238_oBCM12_oB30_for_SC_CAN_V3_2_ced434a5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM1_0x319_oBCM1_oB30_for_SC_CAN_V3_2_3b9040e0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM3_0x345_oBCM3_oB30_for_SC_CAN_V3_2_63d58c65_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BCM8_0x29F_oBCM8_oB30_for_SC_CAN_V3_2_959fd4c6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BMS4_0xF1_oBMS4_oB30_for_SC_CAN_V3_2_ad291777_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CSA1_0x165_oCSA1_oB30_for_SC_CAN_V3_2_432419b3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CSA2_0xA1_oCSA2_oB30_for_SC_CAN_V3_2_7f0f027f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_CSA3_0x244_oCSA3_oB30_for_SC_CAN_V3_2_a76b1812_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DCT3_0xA6_oDCT3_oB30_for_SC_CAN_V3_2_f1cd20ee_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DCT5_0x221_oDCT5_oB30_for_SC_CAN_V3_2_6e7f38ea_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DDCM1_0x2CA_oDDCM1_oB30_for_SC_CAN_V3_2_0a1045c1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_DSM1_0x2C1_oDSM1_oB30_for_SC_CAN_V3_2_abfa59d6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM11_0x2D3_oECM11_oB30_for_SC_CAN_V3_2_a1715d7d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM1_0x111_oECM1_oB30_for_SC_CAN_V3_2_b49cfb6f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM2_0x271_oECM2_oB30_for_SC_CAN_V3_2_35a250f4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ECM3_0x371_oECM3_oB30_for_SC_CAN_V3_2_3a68860a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EEM1_0x2A8_oEEM1_oB30_for_SC_CAN_V3_2_a343c1b7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EPB1_0x16B_oEPB1_oB30_for_SC_CAN_V3_2_19631844_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EPS_FD1_0x147_oEPS_FD1_oB30_for_SC_CAN_V3_2_fd5fd087_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ESP11_0xC8_oESP11_oB30_for_SC_CAN_V3_2_b2794d17_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ESP8_0x170_oESP8_oB30_for_SC_CAN_V3_2_97b77884_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_ESP_FD2_0x137_oESP_FD2_oB30_for_SC_CAN_V3_2_bc62acd8_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_GW_FD1_0x2BB_oGW_FD1_oB30_for_SC_CAN_V3_2_004ea45d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HAP_FD1_0x15B_oHAP_FD1_oB30_for_SC_CAN_V3_2_93124709_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HAP_FD2_0x274_oHAP_FD2_oB30_for_SC_CAN_V3_2_5363b27c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HAP_FD3_0x298_oHAP_FD3_oB30_for_SC_CAN_V3_2_22400704_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HCU_HC7_0x3C2_oHCU_HC7_oB30_for_SC_CAN_V3_2_d59a401d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HCU_PT4_0x2FA_oHCU_PT4_oB30_for_SC_CAN_V3_2_a6c96633_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HCU_PT7_0x248_oHCU_PT7_oB30_for_SC_CAN_V3_2_30a9f673_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_HUD1_0x325_oHUD1_oB30_for_SC_CAN_V3_2_567ca009_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_IFC_FD2_0x23D_oIFC_FD2_oB30_for_SC_CAN_V3_2_6083e7b7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_IFC_FD3_0x2CF_oIFC_FD3_oB30_for_SC_CAN_V3_2_b81a4d55_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PDCM1_0x2CD_oPDCM1_oB30_for_SC_CAN_V3_2_6c5cb461_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PEPS2_0x295_oPEPS2_oB30_for_SC_CAN_V3_2_d1207061_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PEPS4_0x302_oPEPS4_oB30_for_SC_CAN_V3_2_97914cf7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_RSDS_FD1_0x16F_oRSDS_FD1_oB30_for_SC_CAN_V3_2_0c3e88fc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_RSDS_FD2_0x30A_oRSDS_FD2_oB30_for_SC_CAN_V3_2_3f10f708_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_TPMS1_0x341_oTPMS1_oB30_for_SC_CAN_V3_2_7481a0ed_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_TPMS2_0x395_oTPMS2_oB30_for_SC_CAN_V3_2_64d1204c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_WPC1_0x2BA_oWPC1_oB30_for_SC_CAN_V3_2_0ada7fde_Rx(void);

/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_CBK_H */
