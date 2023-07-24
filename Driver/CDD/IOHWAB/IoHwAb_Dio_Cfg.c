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
 * @file:      IoHwAb_Dio_Cfg.c
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

#include "IoHwAb.h"
#include "IoHwAb_Dio.h"
#include "IoHwAb_Dio_Cfg.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <Dio.h>

#define IoHwAb_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Macro defines RAM data of digital input&output channel*/

static CIoHwAb_SignalRAM Signal_GPIO_I_SXM_VIP_STBY_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_SXM_VIP_CTI_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_PMIC_VIP_PSHOLD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_SI4624_VIP_INT_3V3_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_SI479XX_VIP_INT_3V3_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_SOC_VIP_CSIH1_REQ2_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_SOC_VIP_CSIH2_REQ2_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_A2B_VIP_INT_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_20098_PG_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_AMP8531_DIAG1_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_AMP8531_DIAG2_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_8532_DIAG3_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_AMP8532_DIAG1_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_AMP8532_DIAG2_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_AMP8532_DIAG3_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_BSF_IDL_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_Gyro_INT1_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_LVI_IDL_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_OPL_IDL_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_RLIN31_INH_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_RLIN32_INH_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_RTC_INT_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_SI_IDH_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_SXM_VIP_FACT_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_VIP_ON_IDH_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_I_Tuner_VIP_debug2_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                 
};
static CIoHwAb_SignalRAM Signal_GPIO_O_PMIC_VIP_FAULT_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_USB1_CTRL2_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VBATT_VIP_DET_EN_3V3_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_A2BPWR_EN_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_ADC_M_REST_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_CD_EN_ODH_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_DSP_SELE_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_MIC_res_key_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_PD_EN_ODH_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_PMIC_CBL_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_PMIC_KPD_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_PMIC_RST_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_REVERSE_IRQ_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_RTC_FEN_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_SOC_SHUTDOWN_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_SOC_UPDATA_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_SWITCH_SPI_EN_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_TM_IDL_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_TUNER_ANT_EN_3V3_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_SOC_EDL_3V3_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
static CIoHwAb_SignalRAM Signal_GPIO_O_VIP_ChargeEN_ODH_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */                                                    
};                                                                     
#define IoHwAb_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Macro defines ROM data of Digital input&output channel
 * @arg Name - Channel name
 * @arg Id - Id defined in enum EIOVoltageInId
 * @arg pFilters - Filters to be applied to HW value
 * @arg ResolutionDivisor -  Divisor for conversion from HW to Application value
 * @arg ResolutionMultiplier -  Multiplier for conversion from HW to Application value. ApplValue = (HWValue + Offset) * Multiplier / Divisor
 * @arg HwId - Analog group id (see in Adc configuration)
 * @arg HwIdEx - Channel index in group
 * @arg Type - Set it to cIoHwAb_Signal_AnaInput*/
/******************************************************digital input*****************************************************************/

const IOHWAB_CFG_STR CIoHwAb_DIn_PinInCfg[IoHwAb_DIn_PinInCfg_Count] = {
    {
        0, /* Id =*/
        &Signal_GPIO_I_SXM_VIP_STBY_RAM, /* pRAM =*/
        20, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_SXM_VIP_STBY, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        1, /* Id =*/
        &Signal_GPIO_I_SXM_VIP_CTI_RAM, /* pRAM =*/
        21, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_SXM_VIP_CTI, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        2, /* Id =*/
        &Signal_GPIO_I_PMIC_VIP_PSHOLD_RAM, /* pRAM =*/
        22, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_PMIC_VIP_PSHOLD, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        3, /* Id =*/
        &Signal_GPIO_I_SI4624_VIP_INT_3V3_RAM, /* pRAM =*/
        23, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_SI4624_VIP_INT_3V3, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        4, /* Id =*/
        &Signal_GPIO_I_SI479XX_VIP_INT_3V3_RAM, /* pRAM =*/
        24, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_SI479XX_VIP_INT_3V3, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        5, /* Id =*/
        &Signal_GPIO_I_SOC_VIP_CSIH1_REQ2_RAM, /* pRAM =*/
        25, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_SOC_VIP_CSIH1_REQ2, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        6, /* Id =*/
        &Signal_GPIO_I_SOC_VIP_CSIH2_REQ2_RAM, /* pRAM =*/
        26, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_SOC_VIP_CSIH2_REQ2, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        7, /* Id =*/
        &Signal_GPIO_I_A2B_VIP_INT_RAM, /* pRAM =*/
        27, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_A2B_VIP_INT, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        8, /* Id =*/
        &Signal_GPIO_I_VIP_20098_PG_RAM, /* pRAM =*/
        28, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_20098_PG, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        9, /* Id =*/
        &Signal_GPIO_I_VIP_AMP8531_DIAG1_RAM, /* pRAM =*/
        29, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_AMP8531_DIAG1, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        10, /* Id =*/
        &Signal_GPIO_I_VIP_AMP8531_DIAG2_RAM, /* pRAM =*/
        30, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_AMP8531_DIAG2, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        11, /* Id =*/
        &Signal_GPIO_I_VIP_8532_DIAG3_RAM, /* pRAM =*/
        31, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_8532_DIAG3, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        12, /* Id =*/
        &Signal_GPIO_I_VIP_AMP8532_DIAG1_RAM, /* pRAM =*/
        32, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_AMP8532_DIAG1, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        13, /* Id =*/
        &Signal_GPIO_I_VIP_AMP8532_DIAG2_RAM, /* pRAM =*/
        33, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_AMP8532_DIAG2, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        14, /* Id =*/
        &Signal_GPIO_I_VIP_AMP8532_DIAG3_RAM, /* pRAM =*/
        34, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_AMP8532_DIAG3, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        15, /* Id =*/
        &Signal_GPIO_I_VIP_BSF_IDL_RAM, /* pRAM =*/
        35, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_BSF_IDL, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        16, /* Id =*/
        &Signal_GPIO_I_VIP_Gyro_INT1_RAM, /* pRAM =*/
        36, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_Gyro_INT1, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        17, /* Id =*/
        &Signal_GPIO_I_VIP_LVI_IDL_RAM, /* pRAM =*/
        37, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_LVI_IDL, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        18, /* Id =*/
        &Signal_GPIO_I_VIP_OPL_IDL_RAM, /* pRAM =*/
        38, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_OPL_IDL, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        19, /* Id =*/
        &Signal_GPIO_I_VIP_RLIN31_INH_RAM, /* pRAM =*/
        39, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_RLIN31_INH, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        20, /* Id =*/
        &Signal_GPIO_I_VIP_RLIN32_INH_RAM, /* pRAM =*/
        40, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_RLIN32_INH, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        21, /* Id =*/
        &Signal_GPIO_I_VIP_RTC_INT_RAM, /* pRAM =*/
        41, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_RTC_INT, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        22, /* Id =*/
        &Signal_GPIO_I_VIP_SI_IDH_RAM, /* pRAM =*/
        42, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_SI_IDH, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        23, /* Id =*/
        &Signal_GPIO_I_SXM_VIP_FACT_RAM, /* pRAM =*/
        43, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_SXM_VIP_FACT, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        24, /* Id =*/
        &Signal_GPIO_I_VIP_ON_IDH_RAM, /* pRAM =*/
        44, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_ON_IDH, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
    {
        25, /* Id =*/
        &Signal_GPIO_I_Tuner_VIP_debug2_RAM, /* pRAM =*/
        45, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_Tuner_VIP_debug2, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalInput /* Type =*/
    },
};                                                                            

/******************************************************digital output*****************************************************************/


const IOHWAB_CFG_STR CIoHwAb_DOut_PinOutCfg[IoHwAb_DOut_PinOutCfg_Count] =
{
    {
        0, /* Id =*/
        &Signal_GPIO_O_PMIC_VIP_FAULT_RAM, /* pRAM =*/
        46, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_PMIC_VIP_FAULT, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        1, /* Id =*/
        &Signal_GPIO_O_VIP_USB1_CTRL2_RAM, /* pRAM =*/
        47, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_USB1_CTRL2, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        2, /* Id =*/
        &Signal_GPIO_O_VBATT_VIP_DET_EN_3V3_RAM, /* pRAM =*/
        48, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VBATT_VIP_DET_EN_3V3, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        3, /* Id =*/
        &Signal_GPIO_O_VIP_A2BPWR_EN_RAM, /* pRAM =*/
        49, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_A2BPWR_EN, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        4, /* Id =*/
        &Signal_GPIO_O_VIP_ADC_M_REST_RAM, /* pRAM =*/
        50, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_ADC_M_REST, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        5, /* Id =*/
        &Signal_GPIO_O_VIP_CD_EN_ODH_RAM, /* pRAM =*/
        51, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_CD_EN_ODH, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        6, /* Id =*/
        &Signal_GPIO_O_VIP_DSP_SELE_RAM, /* pRAM =*/
        52, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_DSP_SELE, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        7, /* Id =*/
        &Signal_GPIO_O_VIP_MIC_res_key_RAM, /* pRAM =*/
        53, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_MIC_res_key, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        8, /* Id =*/
        &Signal_GPIO_O_VIP_PD_EN_ODH_RAM, /* pRAM =*/
        54, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_PD_EN_ODH, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        9, /* Id =*/
        &Signal_GPIO_O_VIP_PMIC_CBL_RAM, /* pRAM =*/
        55, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_PMIC_CBL, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        10, /* Id =*/
        &Signal_GPIO_O_VIP_PMIC_KPD_RAM, /* pRAM =*/
        56, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_PMIC_KPD, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        11, /* Id =*/
        &Signal_GPIO_O_VIP_PMIC_RST_RAM, /* pRAM =*/
        57, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_PMIC_RST, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        12, /* Id =*/
        &Signal_GPIO_O_VIP_REVERSE_IRQ_RAM, /* pRAM =*/
        58, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_REVERSE_IRQ, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        13, /* Id =*/
        &Signal_GPIO_O_VIP_RTC_FEN_RAM, /* pRAM =*/
        59, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_RTC_FEN, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        14, /* Id =*/
        &Signal_GPIO_O_VIP_SOC_SHUTDOWN_RAM, /* pRAM =*/
        60, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_SOC_SHUTDOWN, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        15, /* Id =*/
        &Signal_GPIO_O_VIP_SOC_UPDATA_RAM, /* pRAM =*/
        61, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_SOC_UPDATA, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        16, /* Id =*/
        &Signal_GPIO_O_VIP_SWITCH_SPI_EN_RAM, /* pRAM =*/
        62, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_SWITCH_SPI_EN, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        17, /* Id =*/
        &Signal_GPIO_O_VIP_TM_IDL_RAM, /* pRAM =*/
        63, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_TM_IDL, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        18, /* Id =*/
        &Signal_GPIO_O_VIP_TUNER_ANT_EN_3V3_RAM, /* pRAM =*/
        64, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_TUNER_ANT_EN_3V3, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        19, /* Id =*/
        &Signal_GPIO_O_VIP_SOC_EDL_3V3_RAM, /* pRAM =*/
        65, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_SOC_EDL_3V3, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
    {
        20, /* Id =*/
        &Signal_GPIO_O_VIP_ChargeEN_ODH_RAM, /* pRAM =*/
        66, /* FilterId*/
        FALSE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        DioConf_DioChannel_VIP_ChargeEN_ODH, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_DigitalOutput /* Type =*/
    },
};                                                                 


#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

