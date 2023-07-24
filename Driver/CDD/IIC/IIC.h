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
 * @file:      IIC.h
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

#ifndef _IIC_H_
#define _IIC_H_


#include "IIC_Type.h"
#include "Compiler.h"
#include "Cdd_Common.h"
#include "IIC_cfg.h"




void IIC_Init(void);
IIC_Return_t IIC_QueueRxReq(IIC_DeviceID_t dev_id, uint8 *pu8buf, uint16 tx_size, uint16 rx_size);
IIC_Return_t IIC_QueueTxReq(IIC_DeviceID_t dev_id, uint8 *pu8buf, uint16 tx_size);
void IIC0_MainFunction(void);
void IIC1_MainFunction(void);



#endif /* ifndef _IIC_H_.2020-3-16 16:31:14 GW00188879 */
