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
 * @file:      DSP_Test.h
 * @author:    Nobo
 * @date:      2020-6-22
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-22
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _DSP_TEST_H_
#define _DSP_TEST_H_


//#define DSP_TEST

#ifdef DSP_TEST

#include "Spi.h"

void DSP_Init(void);
void DSP_MainFunction(void);
uint8 DSP_GetDeviceIdentification(void);

#else
#define DSP_Init()
#define DSP_MainFunction()
#define DSP_GetDeviceIdentification()       (0u)
#endif


#endif /* ifndef _DSP_TEST_H_.2020-6-22 11:11:35 GW00188879 */
