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
 * @file:      NetStatus.h
 * @author:    Nobo
 * @date:      2020-9-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _NETSTATUS_H_
#define _NETSTATUS_H_

#include "Std_Types.h"

#define NS_SIGNAL_OK(flag)                          ((E_OK == flag) || (COMEX_UPDATE_RECEIVED == flag))
#define NS_SIGNAL_NOT_OK(flag)                      ((E_OK != flag) && (COMEX_UPDATE_RECEIVED != flag))

#define NS_STATUS_VOLTAGE_NORMAL                    (0u)
#define NS_STATUS_VOLTAGE_ABNORMAL                  (1u)

typedef struct
{
    uint8 statusVoltage;
} NS_Voltage;

#define NS_STATUS_ACTIVE_SLEEP                      (0u)
#define NS_STATUS_ACTIVE_WAKE_RECOVERY              (1u)
#define NS_STATUS_ACTIVE_WAKE                       (2u)

#define NS_STATUS_ACTIVE_IGN_OFF                    (0u)
#define NS_STATUS_ACTIVE_IGN_ON_RECOVERY            (1u)
#define NS_STATUS_ACTIVE_IGN_ON                     (2u)

#define NS_STATUS_ACTIVE_VOLTAGE_NORMAL             (0u)
#define NS_STATUS_ACTIVE_VOLTAGE_NORMAL_RECOVERY    (1u)
#define NS_STATUS_ACTIVE_VOLTAGE_ABNORMAL           (2u)

#define NS_STATUS_ACTIVE_INACTIVE                   (0u)
#define NS_STATUS_ACTIVE_ACTIVE                     (1u)

typedef struct
{
    uint16 countWake;
    uint16 countVoltage;
    uint16 countIgn;
} NS_ActiveCfg;

typedef struct
{
    uint8 statusWake;
    uint8 statusIgn;
    uint8 statusVoltage;
    uint8 statusActive;
    uint16 countWake;
    uint16 countVoltage;
    uint16 countIgn;
} NS_Active;

#define NS_STATUS_NOACK_DISAPPEAR                   (0u)
#define NS_STATUS_NOACK_WAITING                     (1u)
#define NS_STATUS_NOACK_RECOVERY                    (2u)

typedef struct
{
    uint16 countNoAck;
} NS_NoAckCfg;

typedef struct
{
    uint8 statusNoAck;
    uint16 countNoAck;
} NS_NoAck;

#define NS_STATUS_BUSOFF_NOT_DETERMINED             (0u)
#define NS_STATUS_BUSOFF_PREPASSED                  (1u)
#define NS_STATUS_BUSOFF_PASSED                     (2u)
#define NS_STATUS_BUSOFF_PREFAILED                  (3u)
#define NS_STATUS_BUSOFF_FAILED                     (4u)

typedef struct
{
    uint8 countFail;
    uint16 countPass;
} NS_BusOffCfg;

typedef struct
{
    uint8 statusBusOff;
    uint8 countFail;
    uint16 countPass;
    uint8 PrestatusActive;
    uint16 reportcounter;
    uint8 prestatusBusOff;
} NS_BusOff;


#define NS_STATUS_CONTROLLER_OK                     (0u)
#define NS_STATUS_CONTROLLER_VOLTAGE_ABNORMAL       (1u)
#define NS_STATUS_CONTROLLER_NO_ACK_WAITING         (2u)
#define NS_STATUS_CONTROLLER_BUSOFF                 (4u)

typedef struct
{
    uint8 statusController;
} NS_Controller;


typedef struct
{
    NS_Voltage voltageData;
    NS_Controller controllerData;    
    NS_Active activeData;
    NS_NoAck noAckData;
    NS_BusOff busOffData;
} NS_Data;

typedef struct
{
    NS_ActiveCfg activeCfg;
    NS_NoAckCfg noAckCfg;
    NS_BusOffCfg busOffCfg;
} NS_Cfg;

#endif