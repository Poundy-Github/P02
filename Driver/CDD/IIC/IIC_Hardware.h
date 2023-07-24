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
 * @file:      iic_Hardware.h
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

#ifndef _IIC_HARDWARE_H_
#define _IIC_HARDWARE_H_




#include "IIC.h"


typedef enum
{
    IIC_STATE_IDLE              = 0x00,
    IIC_STATE_SEND_ADDR_W       = 0x10,
    IIC_STATE_SEND_ADDR_R       = 0x11,
    IIC_STATE_SENDING           = 0x20,
    IIC_STATE_SEND_END          = 0x22,
    IIC_STATE_RECEIVE_1         = 0x30,
    IIC_STATE_RECEIVE_2         = 0x31,
    IIC_STATE_RECEIVE_3         = 0x32,
    IIC_STATE_RECEIVE_4         = 0x33,
    IIC_STATE_RECEIVE_END_1     = 0x40,
    IIC_STATE_RECEIVE_END_2     = 0x41,

    IIC_STATE_SEND_ERROR        = 0x50,
    IIC_STATE_RECV_ERROR        = 0x51,
}IIC_BUS_STATE_t;

typedef struct
{
    uint8 slaveAddr;       /* salve device address */
    uint8 receiveCount;
    uint8 receiveLength;
    uint8 sendCount;
    uint8 sendLength;
    uint8 *recBuf;
    uint8 *outBuf;
}IIC_Handle_t;



typedef struct
{
    IIC_BUS_STATE_t busState;
    uint8 combineRead;
    IIC_Handle_t operate;
}IIC_OperateMgr_t;



extern void Hal_IIC_ClockInit(void);

extern  void IIC_RegInit(void);
extern  HAL_STATUS IIC_TransmitData(uint8 addr, void *txBuf, uint8 len);
extern  HAL_STATUS IIC_ReceptionData(uint8 addr, void *rxBuf, uint8 len);

extern  void IIC_TransmitEmptyInterrupt(void);
extern  void IIC_TransmitEndInterrupt(void);
extern  void IIC_EventInterrupt(void);
extern  void IIC_ReceptionInterrupt(void);
extern  uint8 IIC_InspectBusState(void);
extern  IIC_BUS_STATE_t IIC_InspectRunningState(void);

#endif
