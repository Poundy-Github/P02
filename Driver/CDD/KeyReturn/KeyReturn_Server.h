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
 * @file:      KeyReturn_Server.h
 * @author:    Nobo
 * @date:      2021-4-13
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-4-13
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef KEYRETURN_SERVER_H
#define KEYRETURN_SERVER_H

void KR_Init(void);
void KR_MainFunction(void);
KeyReturn_CODE KR_State(uint8 KeyId, boolean* isPress);
KeyReturn_CODE KR_disable(void);
KeyReturn_CODE KR_enable(void);
KeyReturn_CODE KR_register(const KeyAttribute_st* attribute, uint8* KeyId);
KeyReturn_CODE KR_remove(uint8 KeyId);

#endif //KEYRETURN_SERVER_H
