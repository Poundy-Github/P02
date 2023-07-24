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
 * @file:      LinTest.h
 * @author:    Nobo
 * @date:      2020-5-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _LIN_TEST_H_
#define _LIN_TEST_H_

#include "Platform_Types.h"

#define LIN_TEST_SETUP     (1u)
#define LIN_TEST_TXRX      (2u)
#define LIN_TEST_SLEEP     (3u)
#define LIN_TEST_IDLE      (4u)

extern void LinTest_MainFunction(void);
extern void LinTest_SetUp(void);
extern void LinTest_TxAndRx(uint8 LinNetwork);
extern void LinTest_Sleep(void);

#endif