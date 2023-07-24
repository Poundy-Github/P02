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
 * @file:      hal_iic.h
 * @author:    Nobo
 * @date:      2020-3-16
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-3-16
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _HAL_IIC_H_
#define _HAL_IIC_H_

#include "IIC.h"
/* Common hal status values */
typedef enum
{
    HAL_STATUS_OK,
	/* IIC */
    HAL_STATUS_I2C_INVALID_SHARED,
    HAL_STATUS_I2C_INVALID_HANDLE,
    HAL_STATUS_I2C_BUS_BUSY,
} HAL_STATUS;

typedef enum
{
    I2C_QUEUE_NONE = 0x00,
	I2C_QUEUE_SUCCESS,
	I2C_QUEUE_FAIL,
}IIC_QueueState_t;




extern void HAL_IIC_Init(void);
extern IIC_Return_t HAL_IIC_Open(IIC_Unitx_t tUnitx);

extern IIC_Return_t HAL_IIC_Write(IIC_Unitx_t tUnitx, uint16 IIC_addr, uint8 *value, uint16 length);
extern IIC_Return_t HAL_IIC_Read(IIC_Unitx_t tUnitx, uint16 IIC_addr, uint8 *value, uint16 length);
extern void HAL_IIC_Reset(IIC_Unitx_t tUnitx);
#endif /* ifndef _HAL_IIC_H_.2020-3-16 15:05:39 GW00188879 */
