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
 * @file:      iic_cfg.h
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

#ifndef _IIC_CFG_H_
#define _IIC_CFG_H_

#include "RingBuffer.h"


#include "IIC.h"
#include "hal_iic.h"

typedef void (*p_rx_callback_t)(IIC_ResultStatus_t state, const uint8 * pu8buf, uint16 size);
typedef void (*p_tx_callback_t)(IIC_ResultStatus_t state);


typedef struct  
{
    
    IIC_QueueID_t       tQueueID;             /*!>  */
    uint8               flag;
    uint16              u16adder;
    p_tx_callback_t     tx_callback_func;
    p_rx_callback_t     rx_callback_func;
}
IIC_DrvCfg_t;

/* define Queue Cfg configuration */
typedef struct
{
    RB_Id_t id; 
    IIC_Unitx_t eUnit;
}
IIC_QueueCfg_t;


#define eIIC_DeviceID_RTC                      (0u)
#define eIIC_DeviceID_GYRO                     (1u)
#define eIIC_DeviceID_AMP1                     (2u)
#define eIIC_DeviceID_AMP2                     (3u)
#define eIIC_DeviceID_ADC                      (4u)
#define eIIC_DeviceID_MPQ2022_MIC_GNSS         (5u)
#define eIIC_DeviceID_MPQ2022_ANT1_2           (6u)
#define eIIC_DeviceID_MPQ2022_RVC              (7u)
#define eIIC_DeviceID_NUMBER                   (8u)



#define eIIC_QueueID_Unit0                     (0u)
#define eIIC_QueueID_Unit1                     (1u)
#define eIIC_QueueID_NUMBER                    (2u)

#define cIIC_TimeOutMs                          (1000)

extern const IIC_DrvCfg_t tIIC_DeviceCfgTable[eIIC_DeviceID_NUMBER];
#endif /* ifndef _IIC_CFG_H_.2020-3-17 9:07:30 GW00188879 */
