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
 * @file:      IoHwAb_Adc_Cfg.c
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
#include "IoHwAb_Adc.h"
#include "IoHwAb_Adc_Cfg.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <Adc.h>
#include "Compiler.h"

#define IoHwAb_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* For every Analog channel add one IOHWAB_AIN_VOLTAGE_RAM to define RAM data of channel*/
static CIoHwAb_SignalRAM Signal_VIP_NTC_MON1_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_MICpwr_VIP_Adsense_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_NTC_MON3_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_NTC_MON2_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_TPS7B7701_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_GPSANTpwer_VIP_ADsense_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_ANT2_P_Diag_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_ANT1_P_Diag_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_BC_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_Version_MON2_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_Version_MON1_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_Fuellevel2_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_Fuellevel1_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_VREF_Fuel_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VIP_A1VREF_IAN_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_VBATT_VIP_DET_ADC_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_MIC_VIP_SENS2_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_MIC_VIP_SENS1_N_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_MIC_VIP_SENS2_N_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_MIC_VIP_SENS1_AD_RAM = { 
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
#define IoHwAb_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define IoHwAb_START_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Macro defines ROM data of Analog input channel
 * @arg Name - Channel name
 * @arg Id - Id defined in enum EIOVoltageInId
 * @arg pFilters - Filters to be applied to HW value
 * @arg ResolutionDivisor -  Divisor for conversion from HW to Application value
 * @arg ResolutionMultiplier -  Multiplier for conversion from HW to Application value. ApplValue = (HWValue + Offset) * Multiplier / Divisor
 * @arg HwId - Analog group id (see in Adc configuration)
 * @arg HwIdEx - Channel index in group
 * @arg Type - Set it to cIoHwAb_Signal_AnaInput*/


const IOHWAB_CFG_STR CIoHwAb_AIn_VoltageInCfg[IoHwAb_AIn_Cfg_Count] = 
{
    { 
        0, /* Id =*/
        &Signal_VIP_NTC_MON1_IAN_AD_RAM, /* pRAM =*/
        0, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_NTC_MON1_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        1, /* Id =*/
        &Signal_MICpwr_VIP_Adsense_AD_RAM, /* pRAM =*/
        1, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_MICpwr_VIP_Adsense_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        2, /* Id =*/
        &Signal_VIP_NTC_MON3_IAN_AD_RAM, /* pRAM =*/
        2, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_NTC_MON3_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        3, /* Id =*/
        &Signal_VIP_NTC_MON2_IAN_AD_RAM, /* pRAM =*/
        3, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_NTC_MON2_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        4, /* Id =*/
        &Signal_VIP_TPS7B7701_IAN_AD_RAM, /* pRAM =*/
        4, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_TPS7B7701_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        5, /* Id =*/
        &Signal_GPSANTpwer_VIP_ADsense_AD_RAM, /* pRAM =*/
        5, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_GPSANTpwer_VIP_ADsense_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        6, /* Id =*/
        &Signal_VIP_ANT2_P_Diag_AD_RAM, /* pRAM =*/
        6, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_ANT2_P_Diag_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        7, /* Id =*/
        &Signal_VIP_ANT1_P_Diag_AD_RAM, /* pRAM =*/
        7, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_ANT1_P_Diag_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        8, /* Id =*/
        &Signal_VIP_BC_IAN_AD_RAM, /* pRAM =*/
        8, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_BC_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        9, /* Id =*/
        &Signal_VIP_Version_MON2_IAN_AD_RAM, /* pRAM =*/
        9, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_Version_MON2_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        10, /* Id =*/
        &Signal_VIP_Version_MON1_IAN_AD_RAM, /* pRAM =*/
        10, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_Version_MON1_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        11, /* Id =*/
        &Signal_VIP_Fuellevel2_IAN_AD_RAM, /* pRAM =*/
        11, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_Fuellevel2_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        12, /* Id =*/
        &Signal_VIP_Fuellevel1_IAN_AD_RAM, /* pRAM =*/
        12, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_Fuellevel1_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        13, /* Id =*/
        &Signal_VIP_VREF_Fuel_IAN_AD_RAM, /* pRAM =*/
        13, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_VREF_Fuel_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        14, /* Id =*/
        &Signal_VIP_A1VREF_IAN_AD_RAM, /* pRAM =*/
        14, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VIP_A1VREF_IAN_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        15, /* Id =*/
        &Signal_VBATT_VIP_DET_ADC_AD_RAM, /* pRAM =*/
        15, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup0, /* HwId =*/
        CHANNEL_VBATT_VIP_DET_ADC_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        16, /* Id =*/
        &Signal_MIC_VIP_SENS2_AD_RAM, /* pRAM =*/
        16, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup1, /* HwId =*/
        CHANNEL_MIC_VIP_SENS2_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        17, /* Id =*/
        &Signal_MIC_VIP_SENS1_N_AD_RAM, /* pRAM =*/
        17, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup1, /* HwId =*/
        CHANNEL_MIC_VIP_SENS1_N_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        18, /* Id =*/
        &Signal_MIC_VIP_SENS2_N_AD_RAM, /* pRAM =*/
        18, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup1, /* HwId =*/
        CHANNEL_MIC_VIP_SENS2_N_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
    { 
        19, /* Id =*/
        &Signal_MIC_VIP_SENS1_AD_RAM, /* pRAM =*/
        19, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1, /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        AdcConf_AdcGroup_AdcGroup1, /* HwId =*/
        CHANNEL_MIC_VIP_SENS1_AD, /* HwIdEx =*/
        cIoHwAb_Signal_AnaInput /* Type =*/
    },
}; 


#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
