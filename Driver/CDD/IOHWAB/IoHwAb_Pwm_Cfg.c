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
 * @file:      IoHwAb_Pwm_Cfg.c
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
#include "IoHwAb_Pwm.h"
#include "IoHwAb_Pwm_Cfg.h"
#include "IoHwAb_Filter.h"
#include "IoHwAb_Filter_Cfg.h"
#include <Pwm.h>

#define IoHwAb_START_SEC_VAR_INIT_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Macro defines RAM data of digital input&output channel*/

static CIoHwAb_SignalRAM Signal_PWM_PWM0_Period_RAM = {
    0, /* AppValue =*/0, /* HwValue =*/E_NOT_OK /* Status */
};
static CIoHwAb_SignalRAM Signal_PWM_PWM0_Duty_RAM = {
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
/******************************************************pwm period*****************************************************************/

const IOHWAB_CFG_STR CIoHwAb_Pwm_PeriodOutCfg[IoHwAb_Pwm_PeriodOutCfg_Count] = {
    {
        0, /* Id =*/                                                                   
        &Signal_PWM_PWM0_Period_RAM, /* pRAM =*/                
        67, /* FilterId*/ 
        TRUE, /* IsPeriod*/
        0, /* Offset =*/                               
        1, /* ResolutionDivisor =*/        
        1, /* ResolutionMultiplier =*/
        0, /* HwId =*/                                
        0, /* HwIdEx =*/                               
        cIoHwAb_Signal_PwmOutputPeriod /* Type =*/                                 
    },
};                                                                            

/******************************************************pwm duty*****************************************************************/

const IOHWAB_CFG_STR CIoHwAb_Pwm_DutyOutCfg[IoHwAb_Pwm_DutyOutCfg_Count] = {
    {     
        0, /* Id =*/
        &Signal_PWM_PWM0_Duty_RAM, /* pRAM =*/
        67, /* FilterId*/
        TRUE, /* IsPeriod*/
        0, /* Offset =*/
        1,  /* ResolutionDivisor =*/
        1, /* ResolutionMultiplier =*/
        0, /* HwId =*/
        0, /* HwIdEx =*/
        cIoHwAb_Signal_PwmOutputDuty /* Type =*/
    },
};                                                                            

#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED
#include "IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

