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
 * @file:      DcmEx_Switch.h
 * @author:    Nobo
 * @date:      2020-8-13
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-13
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#ifndef _DCMEX_SWITCH_H_
#define _DCMEX_SWITCH_H_

#include "Platform_Types.h"

#if !( (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_B03) || (defined GWM_V35_PROJECT_TYPE_P05) )
    #define DIAG_USE_DCMEX TRUE
#else
    #define DIAG_USE_DCMEX FALSE
#endif

#endif
