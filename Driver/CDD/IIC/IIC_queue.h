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
 * @file:      iic_queue.h
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

#ifndef _IIC_QUEUE_H_
#define _IIC_QUEUE_H_



#include "IIC.h"
#include "IIC_cfg.h"




#define EVENT_I2C_TX_RX             ((uint16) BIT(1u,0))
#define EVENT_I2C_SCAN              ((uint16) BIT(1u,1))
#define EVENT_I2C_SUCCESS           ((uint16) BIT(1u,2))
#define EVENT_I2C_ERROR             ((uint16) BIT(1u,3))
#define EVENT_I2C_TIMOUT            ((uint16) BIT(1u,4))
#define EVENT_I2C_ALL               (EVENT_I2C_TX_RX | \
                                     EVENT_I2C_SCAN  | \
                                     EVENT_I2C_SUCCESS|\
                                     EVENT_I2C_ERROR|  \
                                     EVENT_I2C_TIMOUT)

#define IIC_ENTER_CRITICAL_SECTION()          Rte_Enter_ExclusiveArea_IIC()
#define IIC_EXIT_CRITICAL_SECTION()           Rte_Enter_ExclusiveArea_IIC()


extern IIC_Return_t IIC_QueueInit(void);
extern void IIC_StateManage(IIC_QueueID_t tQueueID,uint16 event);

#endif /* ifndef _IIC_QUEUE_H_.2020-3-16 16:26:08 GW00188879 */
