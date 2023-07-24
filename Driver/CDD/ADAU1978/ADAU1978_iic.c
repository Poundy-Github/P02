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
 * @file:      ADAU1978_iic.c
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

#include "ADAU1978.h"
#include "ADAU1978_reg.h"
#include "ADAU1978_iic.h"

typedef enum
{
    I2C_Req_Idle = 0u,
    I2C_Req_Success,
    I2C_Req_Err,
    I2C_Req_PushSucess,
    I2C_Req_Trigger,
    I2C_Req_Wait,
    I2C_Req_RXResponseTrigger,
    I2C_Req_RXResponseWait,
    I2C_Req_RXDataTrigger,
    I2C_Req_RXDataWait,
}ADAU_I2C_Req_Sts_t;

typedef struct
{
    ADAU_I2C_Req_Sts_t Sts;
    uint8 Flg;
    uint8 Counter;
    uint8 Data[10];
    uint8 Rx_Request[5];
    uint8 Rx_Response[5];
}ADAU_I2C_Req_t;

typedef struct AUDU1978_reg
{
    uint8 reg_addr;
    uint8 reg_value;
}AUDU1978_reg_t;

static const AUDU1978_reg_t adau1977_reg_defaults[] = {
    {ADAU1978_REG_SAI_CTRL0, ADAU1978_SAI_CTRL0_FMT_LJ | ADAU1978_SAI_CTRL0_SAI_TDM_8 | ADAU1978_SAI_CTRL0_FS_32000_48000},
    {ADAU1978_REG_SAI_CTRL1, ADAU1978_SAI_CTRL1_SLOT_WIDTH_32 | ADAU1978_SAI_CTRL1_DATA_WIDTH_24BIT | ADAU1978_SAI_CTRL1_LRCLK_PULSE | ADAU1978_SAI_CTRL1_BCLKRATE_32},
    {ADAU1978_REG_CMAP12, 0x10},
    {ADAU1978_REG_CMAP34, 0x32},
    {ADAU1978_REG_POST_ADC_GAIN(0), 0x8A},
    {ADAU1978_REG_POST_ADC_GAIN(1), 0x8A},
    {ADAU1978_REG_POST_ADC_GAIN(2), 0x90},
    {ADAU1978_REG_POST_ADC_GAIN(3), 0x90},
};

static ADAU_I2C_Req_t ADAU_I2C_Req_Data;

extern void ADC_I2CTx_Callback(IIC_ResultStatus_t state)
{
    adau1978_info("ADC Tx state:%d\n", state);
    ADAU1978_set_next_status(state, NULL);
}

extern void ADC_I2CRx_Callback(IIC_ResultStatus_t state, const uint8 * p_data, uint16_t size)
{
    if (size > 0)
    {
        adau1978_info("ADC Rx size:%d data:%d\n", size, p_data[0]);
    }
    ADAU1978_set_next_status(state, p_data);
}

extern boolean audu1978_pwup(void)
{
    adau1978_info("audu1978_pwup\n");
    ADAU_I2C_Req_Data.Data[0] = ADAU1978_REG_POWER;
    ADAU_I2C_Req_Data.Data[1] = ADAU1978_POWER_PWUP;
    if (eIIC_Return_Success == IIC_QueueTxReq(eIIC_DeviceID_ADC, ADAU_I2C_Req_Data.Data, 2))
    {
        return TRUE;
    }
    else
    {
        adau1978_info("audu1978_pwup FAILED\n", ADAU_I2C_Req_Data.Data[0], ADAU_I2C_Req_Data.Data[1]);
        return FALSE;
    }
}

extern boolean audu1978_read_pll(void)
{
    adau1978_info("audu1978_read_pll\n");
    ADAU_I2C_Req_Data.Data[0] = ADAU1978_REG_PLL;
    if (eIIC_Return_Success == IIC_QueueRxReq(eIIC_DeviceID_ADC, ADAU_I2C_Req_Data.Data, 1, 1))
    {
        return TRUE;
    }
    else
    {
        adau1978_info("audu1978_read_pll\n");
        return FALSE;
    }
}

extern boolean audu1978_get_default_reg(uint8 index, uint8 *p_reg_addr, uint8 *p_reg_value)
{
    if ((NULL != p_reg_addr) && (NULL != p_reg_value) && (index < (sizeof(adau1977_reg_defaults)/sizeof(AUDU1978_reg_t))))
    {
        *p_reg_addr = adau1977_reg_defaults[index].reg_addr;
        *p_reg_value = adau1977_reg_defaults[index].reg_value;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

extern boolean audu1978_set_reg(uint8 reg_addr, uint8 reg_value)
{
    adau1978_info("set_reg addr:%d value:0x%02x\n", reg_addr, reg_value);
    ADAU_I2C_Req_Data.Data[0] = reg_addr;
    ADAU_I2C_Req_Data.Data[1] = reg_value;

    if (eIIC_Return_Success == IIC_QueueTxReq(eIIC_DeviceID_ADC, ADAU_I2C_Req_Data.Data, 2))
    {
        return TRUE;
    }
    else
    {
        adau1978_info("audu1978_set_reg FAILED\n");
        return FALSE;
    }
}
