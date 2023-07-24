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
 * @file:      iic1_Hardware.h
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

#ifndef _IIC1_HARDWARE_H_
#define _IIC1_HARDWARE_H_


#include "IIC.h"



typedef enum
{
    IIC1_STATE_IDLE              = 0x00,
    IIC1_STATE_SEND_ADDR_W       = 0x10,
    IIC1_STATE_SEND_ADDR_R       = 0x11,
    IIC1_STATE_SENDING           = 0x20,
    IIC1_STATE_SEND_END          = 0x22,
    IIC1_STATE_RECEIVE_1         = 0x30,
    IIC1_STATE_RECEIVE_2         = 0x31,
    IIC1_STATE_RECEIVE_3         = 0x32,
    IIC1_STATE_RECEIVE_4         = 0x33,
    IIC1_STATE_RECEIVE_END_1     = 0x40,
    IIC1_STATE_RECEIVE_END_2     = 0x41,

    IIC1_STATE_SEND_ERROR        = 0x50,
    IIC1_STATE_RECV_ERROR        = 0x51,
}IIC1_BUS_STATE_t;

typedef struct
{
    uint8 slaveAddr;       /* salve device address */
    uint8 receiveCount;
    uint8 receiveLength;
    uint8 sendCount;
    uint8 sendLength;
    uint8 *recBuf;
    uint8 *outBuf;
}IIC1_Handle_t;

typedef struct
{
    IIC1_BUS_STATE_t busState;
    uint8 combineRead;
    IIC1_Handle_t operate;
}IIC1_OperateMgr_t;

extern  void IIC1_RegInit(void);
extern  HAL_STATUS IIC1_TransmitData(uint8 addr, void *tx_buf, uint8 len);
extern  HAL_STATUS IIC1_ReceptionData(uint8 addr, void *rx_buf, uint8 len);

extern  void IIC1_TransmitEmptyInterrupt(void);
extern  void IIC1_TransmitEndInterrupt(void);
extern  void IIC1_EventInterrupt(void);
extern  void IIC1_ReceptionInterrupt(void);
extern  uint8 IIC1_InspectBusState(void);
extern IIC1_BUS_STATE_t IIC1_InspectRunningState(void);

#endif
