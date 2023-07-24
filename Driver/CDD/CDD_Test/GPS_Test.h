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
 * @file:      GPS_Test.h
 * @author:    Nobo
 * @date:      2020-6-15
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-15
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _GPS_TEST_H_
#define _GPS_TEST_H_
#include "Uart.h"

void GPS_Init(void);
void GPS_MainFunction(void);
void GPS_UartTransmitCallback(Uart_Id_t id, uint8_t *data, uint8_t *length);
void GPS_UartTransmitFinishCallback(Uart_Id_t id, uint8_t *data, uint8_t *length);
void GPS_UartRxCallback(Uart_Id_t id, uint8 ch);
void GPS_TriggerTransmit(uint8 * buffer);
//void GPS_SetDumpState(boolean state);
void GPS_GetGPSSatelliteCount(uint16 *cnt);
void GPS_ReadPDTINFO(void);

#endif /* ifndef _GPS_TEST_H_.2020-6-15 13:24:40 GW00188879 */
