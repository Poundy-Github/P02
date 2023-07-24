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
 * @file:      AMPVCfg.h
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

#ifndef AMPVCFG_H
#define AMPVCFG_H

#include "Std_Types.h"


#define CHANNEL_NUM                                     (4U)
#define CHANNEL_NONE                                    (0u)
#define CHANNEL_DC                                      (1u)
#define CHANNEL_DC_AC                                   (2u)




typedef union{
    uint8 AMPCfgSts;
    struct{
        uint8 CH4    :2;
        uint8 CH3    :2;
        uint8 CH2    :2;
        uint8 CH1    :2;
    }AMPCHCfgSts;
}u_AMPCfg_t;


typedef struct
{
    u_AMPCfg_t  AMP1Cfg;
    u_AMPCfg_t  AMP2Cfg;
}s_AMPVCfg_t;


#define AMP_START_SEC_CODE
#include "AMP_MemMap.h"

extern void AMP_VConfig(s_AMPVCfg_t *VCfg);
extern uint16 AMP_ChCfgSts(void);

#define AMP_STOP_SEC_CODE
#include "AMP_MemMap.h"

#endif

