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
 * @file:      CLI_Commands.h
 * @author:    Nobo
 * @date:      2020-6-8
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-8
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _CLI_COMMANDS_H_
#define _CLI_COMMANDS_H_



void CLI_Init(void);
void CLI_CmdMainFunction(void);
boolean IsDigitStr(char const  * src, sint32 len);

#endif /* ifndef _CLI_COMMANDS_H_.2020-6-8 14:42:51 GW00188879 */
