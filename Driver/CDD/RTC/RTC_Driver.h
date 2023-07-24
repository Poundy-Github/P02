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
 * @file:      RTC_Driver.h
 * @author:    Nobo
 * @date:      2020-4-24
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-24
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _RTC_DRIVER_H_
#define _RTC_DRIVER_H_

#include <time.h>
#include "IIC.h"
#include "RTC.h"

typedef uint8 Rtc_Status_t;
#define eRTC_STATUS_OK               (0x00)
#define eRTC_STATUS_ERROR            (0x01)
#define eRTC_STATUS_BUSY             (0x02)


#define RTC_RETRY_CNT               (0x3)




RTC_Return_t RTC_Impl_SynchronizationTime(void);
RTC_Return_t RTC_Impl_SetTime(const    time_t  time);
Rtc_Status_t RTC_Impl_ReadResult(time_t * time);

void RTC_Driver_Impl_Init(void);

void RTC_Rx_Callback(IIC_ResultStatus_t state, const uint8 * pu8buf, uint16 size);
void RTC_Tx_Callback(IIC_ResultStatus_t state);
void RTC_Driver_Impl_MainFunction(void);
boolean RTC_Driver_Impl_IsInit(void);



#endif /* ifndef _RTC_DRIVER_H_.2020-4-24 17:27:20 GW00188879 */

