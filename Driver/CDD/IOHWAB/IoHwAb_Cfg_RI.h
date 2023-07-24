/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      IoHwAb_Cfg_RI.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _IOHWAB_CFG_RI_H_
#define _IOHWAB_CFG_RI_H_


/******************************************************digital input*****************************************************************/
#define RI_IoHwAb_DIn_PinInCfg_SXM_VIP_STBY (0)
#define RI_IoHwAb_DIn_PinInCfg_SXM_VIP_CTI (1)
#define RI_IoHwAb_DIn_PinInCfg_PMIC_VIP_PSHOLD (2)
#define RI_IoHwAb_DIn_PinInCfg_SI4624_VIP_INT_3V3 (3)
#define RI_IoHwAb_DIn_PinInCfg_SI479XX_VIP_INT_3V3 (4)
#define RI_IoHwAb_DIn_PinInCfg_SOC_VIP_CSIH1_REQ2 (5)
#define RI_IoHwAb_DIn_PinInCfg_SOC_VIP_CSIH2_REQ2 (6)
#define RI_IoHwAb_DIn_PinInCfg_A2B_VIP_INT (7)
#define RI_IoHwAb_DIn_PinInCfg_VIP_20098_PG (8)
#define RI_IoHwAb_DIn_PinInCfg_VIP_AMP8531_DIAG1 (9)
#define RI_IoHwAb_DIn_PinInCfg_VIP_AMP8531_DIAG2 (10)
#define RI_IoHwAb_DIn_PinInCfg_VIP_8532_DIAG3 (11)
#define RI_IoHwAb_DIn_PinInCfg_VIP_AMP8532_DIAG1 (12)
#define RI_IoHwAb_DIn_PinInCfg_VIP_AMP8532_DIAG2 (13)
#define RI_IoHwAb_DIn_PinInCfg_VIP_AMP8532_DIAG3 (14)
#define RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL (15)
#define RI_IoHwAb_DIn_PinInCfg_VIP_Gyro_INT1 (16)
#define RI_IoHwAb_DIn_PinInCfg_VIP_LVI_IDL (17)
#define RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL (18)
#define RI_IoHwAb_DIn_PinInCfg_VIP_RLIN31_INH (19)
#define RI_IoHwAb_DIn_PinInCfg_VIP_RLIN32_INH (20)
#define RI_IoHwAb_DIn_PinInCfg_VIP_RTC_INT (21)
#define RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH (22)
#define RI_IoHwAb_DIn_PinInCfg_SXM_VIP_FACT (23)
#define RI_IoHwAb_DIn_PinInCfg_VIP_ON_IDH (24)
#define RI_IoHwAb_DIn_PinInCfg_Tuner_VIP_debug2 (25)

/******************************************************digital output*****************************************************************/
#define RI_IoHwAb_DOut_PinOutCfg_PMIC_VIP_FAULT (0)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_USB1_CTRL2 (1)
#define RI_IoHwAb_DOut_PinOutCfg_VBATT_VIP_DET_EN_3V3 (2)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_A2BPWR_EN (3)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_ADC_M_REST (4)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_CD_EN_ODH (5)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_DSP_SELE (6)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_MIC_res_key (7)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_PD_EN_ODH (8)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_PMIC_CBL (9)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_PMIC_KPD (10)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_PMIC_RST (11)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_REVERSE_IRQ (12)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_RTC_FEN (13)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_SOC_SHUTDOWN (14)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_SOC_UPDATA (15)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_SWITCH_SPI_EN (16)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_TM_IDL (17)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_TUNER_ANT_EN_3V3 (18)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_SOC_EDL_3V3 (19)
#define RI_IoHwAb_DOut_PinOutCfg_VIP_ChargeEN_ODH (20)

/******************************************************AD*****************************************************************/
#define RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON1_IAN (0)
#define RI_IoHwAb_AIn_PinInCfg_MICpwr_VIP_Adsense (1)
#define RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON3_IAN (2)
#define RI_IoHwAb_AIn_PinInCfg_VIP_NTC_MON2_IAN (3)
#define RI_IoHwAb_AIn_PinInCfg_VIP_TPS7B7701_IAN (4)
#define RI_IoHwAb_AIn_PinInCfg_GPSANTpwer_VIP_ADsense (5)
#define RI_IoHwAb_AIn_PinInCfg_VIP_ANT2_P_Diag (6)
#define RI_IoHwAb_AIn_PinInCfg_VIP_ANT1_P_Diag (7)
#define RI_IoHwAb_AIn_PinInCfg_VIP_BC_IAN (8)
#define RI_IoHwAb_AIn_PinInCfg_VIP_Version_MON2_IAN (9)
#define RI_IoHwAb_AIn_PinInCfg_VIP_Version_MON1_IAN (10)
#define RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel2_IAN (11)
#define RI_IoHwAb_AIn_PinInCfg_VIP_Fuellevel1_IAN (12)
#define RI_IoHwAb_AIn_PinInCfg_VIP_VREF_Fuel_IAN (13)
#define RI_IoHwAb_AIn_PinInCfg_VIP_A1VREF_IAN (14)
#define RI_IoHwAb_AIn_PinInCfg_VBATT_VIP_DET_ADC (15)
#define RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS2 (16)
#define RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS1_N (17)
#define RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS2_N (18)
#define RI_IoHwAb_AIn_PinInCfg_MIC_VIP_SENS1 (19)

/******************************************************PWM*****************************************************************/
#define RI_IoHwAb_PWM_PinOutCfg_PWM0 (0)

/******************************************************HSLS*****************************************************************/
#define RI_IoHwAb_HSLS_PinOutCfg_HSLS0 (0)

#endif /*IoHwAb_DIO_Cfg_RI_H*/