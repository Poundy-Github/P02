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
 * @file:      IoHwAb_Adc_Cfg.h
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

#ifndef _IOHWAB_ADC_CFG_H_
#define _IOHWAB_ADC_CFG_H_



#define IoHwAb_Adc_MaxGroups               2
#define IoHwAb_Adc_MaxChannelsInGroup      16

/* For every Analog input channel add one raw using macro IOHWAB_AIN_VOLTAGE_ROM.
 * For every Alalog group add one SIOVoltageInCfg * array with channels it contains.
 * Add Analog groups in array CIoHwAb_AIn_VoltageInCfg.
 * In CIoHwAb_AIn_VoltageInCfg_Count put counts of channels in every group.*/
#define CHANNEL_VIP_NTC_MON1_IAN_AD 15
#define CHANNEL_MICpwr_VIP_Adsense_AD 14
#define CHANNEL_VIP_NTC_MON3_IAN_AD 13
#define CHANNEL_VIP_NTC_MON2_IAN_AD 12
#define CHANNEL_VIP_TPS7B7701_IAN_AD 11
#define CHANNEL_GPSANTpwer_VIP_ADsense_AD 10
#define CHANNEL_VIP_ANT2_P_Diag_AD 9
#define CHANNEL_VIP_ANT1_P_Diag_AD 8
#define CHANNEL_VIP_BC_IAN_AD 7
#define CHANNEL_VIP_Version_MON2_IAN_AD 6
#define CHANNEL_VIP_Version_MON1_IAN_AD 5
#define CHANNEL_VIP_Fuellevel2_IAN_AD 4
#define CHANNEL_VIP_Fuellevel1_IAN_AD 3
#define CHANNEL_VIP_VREF_Fuel_IAN_AD 2
#define CHANNEL_VIP_A1VREF_IAN_AD 1
#define CHANNEL_VBATT_VIP_DET_ADC_AD 0
#define CHANNEL_MIC_VIP_SENS2_AD 1
#define CHANNEL_MIC_VIP_SENS1_N_AD 2
#define CHANNEL_MIC_VIP_SENS2_N_AD 3
#define CHANNEL_MIC_VIP_SENS1_AD 0
#define IoHwAb_AIn_Cfg_Count 20

#endif /* ifndef _IOHWAB_ADC_CFG_H_ */
