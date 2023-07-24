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
 * @file:      SRV_Wdg.c
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

#include "SRV_Wdg.h"
#include "Wdg_59_DriverA.h"
#include "Wdg_59_DriverA_Private.h"
#include "Wdg_59_DriverA_PBTypes.h"




Std_ReturnType SRV_Wdg_SetMode(WdgIf_ModeType Mode)
{
    return Wdg_59_DriverA_SetMode(Mode);
}
void SRV_Wdg_SetTriggerCondition(uint16 timeout)
{
    if (timeout != 0)
    {
        Wdg_59_DriverA_TriggerFunc(WDG_59_DRIVERA_INCLUDE_CRITICAL_SECTION);
    }
}



