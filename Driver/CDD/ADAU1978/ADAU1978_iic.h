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
 * @file:      ADAU1978_iic.h
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

#ifndef ADAU1978_IIC_H
#define ADAU1978_IIC_H

#include "IIC_cfg.h"
#include "IIC.h"

extern void ADC_I2CTx_Callback(IIC_ResultStatus_t state);
extern void ADC_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16_t size);

extern boolean audu1978_pwup(void);
extern boolean audu1978_read_pll(void);
extern boolean audu1978_get_default_reg(uint8 index, uint8 *p_reg_addr, uint8 *p_reg_value);
extern boolean audu1978_set_reg(uint8 reg_addr, uint8 reg_value);

#endif