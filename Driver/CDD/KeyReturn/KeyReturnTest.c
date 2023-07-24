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
 * @file:      KeyReturnTest.c
 * @author:    Nobo
 * @date:      2021-4-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-4-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Rte_KeyReturn.h"
#include "KeyReturnTest.h"
#include "KeyReturn_Server.h"
#include "stdio.h"

#define KEY_TEST_0  0xF0
#define KEY_TEST_1  0xF1
#define KEY_TEST_2  0xF2
#define KEY_TEST_3  0xF3
#define KEY_TEST_4  0xF4
uint8 test0_data = 0;
static Std_ReturnType kr_test0_sig(uint8* data){
    *data = test0_data ;
    return E_OK;
}
uint8 test1_data = 0;
static Std_ReturnType kr_test1_sig(uint8* data){
    uint8 d = 0;
    *data = test1_data ;
    return E_OK;
}
uint8 test2_data = 0;
static Std_ReturnType kr_test2_sig(uint8* data){
    uint8 d = 0;
    *data = test2_data ;
    return E_OK;
}
uint8 test3_data = 0;
static Std_ReturnType kr_test3_sig(uint8* data){
    uint8 d = 0;
    *data = test3_data ;
    return E_OK;
}
uint8 test4_data = 0;
static Std_ReturnType kr_test4_sig(uint8* data){
    uint8 d = 0;
    *data = test4_data ;
    return E_OK;
}

void kr_event_test1_and_test2_TESE1(void){
    printf("kr_event_test1_and_test2_TESE1\r\n");
}
void kr_free_test1_and_test2_TESE1(void){
    printf("kr_free_test1_and_test2_TESE1\r\n");
}
void kr_event_test1_and_test2_TESE2(void){
    printf("kr_event_test1_and_test2_TESE2\r\n");
}
void kr_free_test1_and_test2_TESE2(void){
    printf("kr_free_test1_and_test2_TESE2\r\n");
}

static void kr_test_mainfunction(void) {
    uint8 reg = 0;
    KeyAttribute_st attribute = {0};
    uint8 TEST1 = FALSE, TEST2 = FALSE;
    uint8 keyId = 0;
    if (TEST1){ // 长按 5 s
            // KeyReturn_CODE KR_register(const KeyAttribute_st* attribute, uint8* KeyId)
            attribute.KeyList[0]=KEY_TEST_0;
            attribute.KeyList[1]=KEY_TEST_1;
            attribute.EventCallout = (uint32)kr_event_test1_and_test2_TESE1;
            attribute.FreeCallout = (uint32)kr_free_test1_and_test2_TESE1;
            attribute.PressCnt = 1;     // 等于 1 时 在按下PressTime时间之后触发事件
            attribute.PressTime = 5000;  // 5s
            attribute.OnlyKey = TRUE;
            attribute.KeyCnt = 2;
            KR_register(&attribute, &keyId);
    }
    if (TEST2){ // 10 s内 按 3 次
            // KeyReturn_CODE KR_register(const KeyAttribute_st* attribute, uint8* KeyId)
            attribute.KeyList[0]=KEY_TEST_0;
            attribute.KeyList[1]=KEY_TEST_1;
            attribute.EventCallout = (uint32)kr_event_test1_and_test2_TESE2;
            attribute.FreeCallout = (uint32)kr_free_test1_and_test2_TESE2;
            attribute.PressCnt = 3;     // 等于 1 时 在按下PressTime时间之后触发事件
            attribute.PressTime = 10000;  // 5s
            attribute.OnlyKey = TRUE;
            attribute.KeyCnt = 2;
            KR_register(&attribute, &keyId);
    }
}
