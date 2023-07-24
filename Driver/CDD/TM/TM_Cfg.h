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
 * @file:      TM_Cfg.h
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

 #ifndef __TM_CFG_H
 #define __TM_CFG_H

 
 #include "std_types.h"
 
 /*status*/
 #define TM_STOP		0xFF 
 #define TM_RUNNING     0xAA
 #define TM_EXPIRED	    0xBB
 /*type*/
 #define TM_TYPE_0P1US	0X01
 #define TM_TYPE_1MS	0X02
 /*operation*/
 #define TM_OP_START	0X01
 #define TM_OP_CLEAR    0X02
 #define TM_OP_CHECK	0X03

 
 typedef struct
 {
	 uint32 TM_Start;
	 uint32 TM_Elapsed;
	 uint32 TM_CompareValue;
	 uint8 TM_Status;
 }TM_Info_Str;


typedef enum
{
    TM_MISC_TEST_us = 0,
    TM_MISC_TEST_ms,
    MAX_TM_ID
} TMID;

typedef struct
{
    TMID TM_Id;
    uint8 TM_Type;
    TM_Info_Str* TM_Info;
}TM_Str;

extern const TM_Str TM_Str_cfg[MAX_TM_ID];


 #endif
