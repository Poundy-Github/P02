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
 * @file:      CDD_Test.h
 * @author:    Nobo
 * @date:      2020-5-26
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-26
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _CDD_TEST_H_
#define _CDD_TEST_H_
#include "uart.h"



void CDD_Test_Init(void);
void CDD_Test_MainFunction(void);
void CDD_Test_UartRxCallback(Uart_Id_t id, uint8 ch);

void WachDogEnable(void);
void WachDogDisable(void);
void WachDogFeedDis(void);



#define CDD_TEST_ENTER_CRITICAL()
#define CDD_TEST_EXIT_CRITICAL()

#include <stdio.h>
#include "logger.h"
//#define CDD_TEST_DEBUG(...)     sys_info(__VA_ARGS__)
//#define CDD_TEST_ACCERT(expr)   do{(expr)?(void)0 : (void)rtc_err("\nFILE:%s;\nLINE:%d;\n",(uint8_t*)__FILE__,__LINE__);}while(0)
#define CDD_TEST_DEBUG(...)     sys_info(__VA_ARGS__)
#define CDD_TEST_ACCERT(expr)   do{(expr)?(void)0 : (void)sys_info("\nLINE:%d;\n",__LINE__);}while(0)


void CDD_Test_DisplayLog(void);
void WachDogFeed(void);

#endif /* ifndef _CDD_TEST_H_.2020-5-26 11:52:40 GW00188879 */
