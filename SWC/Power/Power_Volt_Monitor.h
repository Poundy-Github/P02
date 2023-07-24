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
 * @file:      Power_Volt_Monitor.h
 * @author:    Nobo
 * @date:      2020-8-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef __POWER_VOLT_MONITOR_H_
#define __POWER_VOLT_MONITOR_H_

#include "Rte_Power.h"

#define POWER_VOLTAGE_NORMAL                (0u)
#define POWER_VOLTAGE_ABNORMAL              (1u)

#define POWER_VOLTAGE_NORMAL_MAX            (1750u)
#define POWER_VOLTAGE_NORMAL_MIN            (650u)
#define POWER_VOLTAGE_LOW_RECOVER           (700u)
#define POWER_VOLTAGE_LOW_SLEEP             (500u)
#define POWER_VOLTAGE_HIGH_SLEEP            (2400u)
#define POWER_VOLTAGE_HIGH_ALARM            (1900u)

#define POWER_VOLTAGEEVENT_LOWENTER 		(600u)
#define POWER_VOLTAGEEVENT_LOWEXIT			(620u)

#define EVENT_OCCUR 						(1u)
#define NO_EVENT 						    (0u)


#define POWER_START_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern s_PowerOut_t Power_OutDataCurrent;
extern uint8  Power_EolSleepflag;

extern void Power_Volt_Init(void);
extern void Power_Volt_Mgr(void);
extern s_PowerOut_t Power_VoltageOutMgr(void);
extern uint8 Power_VoltageStateFlg(void);
extern uint8 Power_VoltageRecoverFlg(void);

extern uint8 PM_VoltageShutdownEventCheck(void);
extern uint8 PM_VoltageEnableEventCheck(void);
extern void PM_EOL_FastSleep(void);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif

