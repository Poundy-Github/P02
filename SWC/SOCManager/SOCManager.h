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
 * @file:      SOCManager.h
 * @author:    Nobo
 * @date:      2020-7-2
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-7-2
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _SOC_MANAGE_H_
#define _SOC_MANAGE_H_


extern uint8 RTE_SocManagerSystemState;

void SOC_Manage_Mainfunction(void);
void SOC_PowerGroupParsing(uint8 major_msg_id, uint8 sub_msg_id, uint8 * param, uint16 param_len);

#endif /* ifndef _SOC_MANAGEMENT_H_.2020-6-24 15:30:32 GW00188879 */
