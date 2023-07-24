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
 * @file:      iic_cfg.c
 * @author:    Nobo
 * @date:      2020-3-17
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-3-17
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "IIC_cfg.h"
#include "RTC_Driver.h"
#include "AMP_Common.h"
#include "Gyro_Asm330.h"
#include "adau1978_iic.h"
#include "MPQ2022.h"


#define IIC_DeviceID_RTC_INFO      {\
    eIIC_QueueID_Unit1,\
    0,\
    0x64,\
    RTC_Tx_Callback,\
    RTC_Rx_Callback,\
    }

#define IIC_DeviceID_GYRO_INFO         {\
    eIIC_QueueID_Unit1,\
    0,\
    0xD6,\
    Asm330_WriteCallback,\
    Asm330_ReadCallback,\
    }

#define eIIC_DeviceID_AMP1_INFO		{\
    eIIC_QueueID_Unit0,\
    0,\
    0xD4,\
    AMP1_I2CTx_Callback,\
    AMP1_I2CRx_Callback,\
}

#define eIIC_DeviceID_AMP2_INFO		{\
    eIIC_QueueID_Unit0,\
    0,\
    0xDC,\
    AMP2_I2CTx_Callback,\
    AMP2_I2CRx_Callback,\
}

#define eIIC_DeviceID_ADC_INFO      {\
    eIIC_QueueID_Unit0,\
    0,\
    0x22,\
    ADC_I2CTx_Callback,\
    ADC_I2CRx_Callback,\
}

#define eIIC_DeviceID_MPQ2022_MIC_GNSS_INFO      {\
    eIIC_QueueID_Unit1,\
    0,\
    0x21*2,\
    MPQ2022_MIC_GNSS_I2CTx_Callback,\
    MPQ2022_MIC_GNSS_I2CRx_Callback,\
}
#define eIIC_DeviceID_MPQ2022_ANT1_2_INFO      {\
    eIIC_QueueID_Unit1,\
    0,\
    0x22*2,\
    MPQ2022_ANT1_2_I2CTx_Callback,\
    MPQ2022_ANT1_2_I2CRx_Callback,\
}
#define eIIC_DeviceID_MPQ2022_RVC_INFO      {\
    eIIC_QueueID_Unit1,\
    0,\
    0x27*2,\
    MPQ2022_RVC_I2CTx_Callback,\
    MPQ2022_RVC_I2CRx_Callback,\
}

const IIC_DrvCfg_t tIIC_DeviceCfgTable[eIIC_DeviceID_NUMBER] = 
{
    IIC_DeviceID_RTC_INFO,
    IIC_DeviceID_GYRO_INFO,
    eIIC_DeviceID_AMP1_INFO,
    eIIC_DeviceID_AMP2_INFO,
    eIIC_DeviceID_ADC_INFO,
    eIIC_DeviceID_MPQ2022_MIC_GNSS_INFO,
    eIIC_DeviceID_MPQ2022_ANT1_2_INFO,
    eIIC_DeviceID_MPQ2022_RVC_INFO,
};

const IIC_QueueCfg_t tIIC_QueueCfgTable[eIIC_QueueID_NUMBER] =
{
    {RB_ID_I2C_QUEUE0,eIIC_Unit0},
    {RB_ID_I2C_QUEUE1,eIIC_Unit1},
};
