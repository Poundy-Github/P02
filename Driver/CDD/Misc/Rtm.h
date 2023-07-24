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
 * @file:      Rtm.h
 * @author:    Nobo
 * @date:      2020-8-19
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-19
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#define RtmConf_RtmMeasurementPoint_Can_Init 0
#define RtmConf_RtmMeasurementPoint_Can_SetControllerMode 1
#define RtmConf_RtmMeasurementPoint_Can_Write 2

#define RtmConf_RtmMeasurementPoint_CanInterruptRxFifo 3
#define RtmConf_RtmMeasurementPoint_CanInterruptWakeup 4
#define RtmConf_RtmMeasurementPoint_CanInterruptStatus 5
#define RtmConf_RtmMeasurementPoint_CanInterruptGlobalStatus 6
#define RtmConf_RtmMeasurementPoint_Interrupt_Callout 7


void Rtm_Start(uint8 measurement_point);
void Rtm_Stop(uint8 measurement_point);

