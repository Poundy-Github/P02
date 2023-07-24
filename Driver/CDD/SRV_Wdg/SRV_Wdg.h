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
 * @file:      SRV_Wdg.h
 * @author:    Nobo
 * @date:      2020-9-23
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-23
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _SRV_WDG_H_
#define _SRV_WDG_H_

#include "WdgIf_Types.h"

Std_ReturnType SRV_Wdg_SetMode(WdgIf_ModeType Mode);
void SRV_Wdg_SetTriggerCondition(uint16 timeout);


#endif /* ifndef _SRV_WDG_H_.2020-9-23 13:44:19 GW00188879 */
