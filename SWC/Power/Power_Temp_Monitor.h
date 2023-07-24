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
 * @file:      Power_Temp_Monitor.h
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

#ifndef POWER_TEMP_MONITOR_H
#define POWER_TEMP_MONITOR_H

#include "Rte_Power.h"


#define POWER_TEMP_NORMAL               (0u)
#define POWER_TEMP_ABNORMAL             (1u)

//#define APM_TEMP_TEST


typedef struct
{
    uint8  State;
    sint16 Value;
    boolean bTempFault;
}s_TempOut_t;
#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

extern void Power_TempInit(void);
extern void Power_TempMonitor(void);
extern Std_ReturnType Power_TempOut(s_TempOut_t *ptr);
extern uint8 Power_TempStateRTUFlg(void);
extern uint8 Power_TempStateTempFlg(void);
extern void Power_TempEOL_Get_MCUAMP_Temperature(EOL_Struct_3Element * arg);

#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"




#endif
