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
 * @file:      TM_Cfg.c
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

#include "TM_Cfg.h"


#pragma ghs section bss = ".MISC_SHARE_NOINIT_DATA" 
#pragma ghs section data = ".MISC_SHARE_INIT_DATA" 

static TM_Info_Str TM_MISC_TEST_us_Info = { 0,0,0,TM_STOP};
static TM_Info_Str TM_MISC_TEST_ms_Info = { 0,0,0,TM_STOP};

#pragma ghs section bss = default 
#pragma ghs section data = default 

#define TM_START_SEC_CONST_UNSPECIFIED
#include "TM_MemMap.h"

const TM_Str TM_Str_cfg[MAX_TM_ID] = 
{
    { 
    	TM_MISC_TEST_us,
		TM_TYPE_0P1US,
		&TM_MISC_TEST_us_Info
    },   
    { 
    	TM_MISC_TEST_ms,
		TM_TYPE_1MS,
		&TM_MISC_TEST_ms_Info
    },
};

#define TM_STOP_SEC_CONST_UNSPECIFIED
#include "TM_MemMap.h"


