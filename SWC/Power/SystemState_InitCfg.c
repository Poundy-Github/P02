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
 * @file:      SystemState_InitCfg.c
 * @author:    Nobo
 * @date:      2020-8-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-8-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "SystemState_InitCfg.h"
#include "Logger_Cfg.h"
#include "logger.h"



#define POWER_START_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"

static  s_Systemstate_ClusterInit_t SystemState_ClusterInitList[] = SYSTEMSTATE_ClUSTERINIT_LIST;
//static const s_Systemstate_ClusterDeInit_t SystemState_ClusterDeInitList[] = SYSTEMSTATE_ClUSTERDEINIT_LIST;
static const s_Systemstate_ClusterState_t SystemState_ClusterStandby2NormalList[] = SYSTEMSTATE_ClUSTERINIT_STANDBY2NORMAL_LIST;
static const s_Systemstate_ClusterState_t SystemState_ClusterNormal2StandbyList[] = SYSTEMSTATE_ClUSTERINIT_NORMAL2STANDBY_LIST;


static  s_Systemstate_CDDInit_t SystemState_CDDInitList[] = SYSTEMSTATE_CDDINIT_LIST;
static  s_Systemstate_CDDDeInit_t SystemState_CDDDeInitList[] = SYSTEMSTATE_CDDDEINIT_LIST;

#define POWER_STOP_SEC_CONST_UNSPECIFIED
#include "Power_MemMap.h"




#define POWER_START_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


void SystemState_ClusterInitFunc(void)
{
    uint16          AppIndex;
    s_Systemstate_ClusterInit_t * p_AppInit = NULL_PTR;

    p_AppInit           = (s_Systemstate_ClusterInit_t *) &SystemState_ClusterInitList[0];

    for (AppIndex = 0u; AppIndex < e_ClusterInitNum; AppIndex++)
    {
        (*p_AppInit[AppIndex].p_fun) ();
    }
}


void SystemState_CDDInitFunc(void)
{
    uint16          CDDIndex;
    s_Systemstate_CDDInit_t * p_CDDInit = NULL_PTR;
    p_CDDInit           = (s_Systemstate_CDDInit_t *) &SystemState_CDDInitList[0];
    for (CDDIndex = 0u; CDDIndex < e_CDDInitNum; CDDIndex++)
    {
        (*p_CDDInit[CDDIndex].p_fun) ();
    }
    power_info("SystemState_CDDInitFunc called");
}


void SystemState_ClusterDeInitFunc(void)
{
    uint16          AppDeIndex;
    s_Systemstate_ClusterDeInit_t * p_AppDeInit = NULL_PTR;
    p_AppDeInit         = (s_Systemstate_ClusterDeInit_t *) &SystemState_ClusterInitList[0];
    for (AppDeIndex = 0u; AppDeIndex < e_ClusterInitNum; AppDeIndex++)
    {
        (*p_AppDeInit[AppDeIndex].p_fun) ();
    }
}


void SystemState_CDDDeInitFunc(void)
{
    uint16          CDDDeIndex;
    s_Systemstate_CDDDeInit_t * p_CDDDeInit = NULL_PTR;
    p_CDDDeInit         = (s_Systemstate_CDDDeInit_t *) &SystemState_CDDDeInitList[0];
    for (CDDDeIndex = 0u; CDDDeIndex < e_CDDDeInitNum; CDDDeIndex++)
    {
        (*p_CDDDeInit[CDDDeIndex].p_fun) ();
    }
    power_info("SystemState_CDDDeInitFunc called !!\r\n");
}

static void SysTemState_ClusterTransferCallback(const s_Systemstate_ClusterState_t * list,uint8 len)
{
    uint8 i = 0;

    for (i=0; i<len; i++)
    {
        if (list[i].p_fun != NULL_PTR)
        {
            (void)list[i].p_fun ();
        }
    }
}


void SysTemState_ClusterNormal2Standby(void)
{
    SysTemState_ClusterTransferCallback(
            SystemState_ClusterNormal2StandbyList,
            (uint8)e_COMMOM_Num);
}

void SysTemState_ClusterStandby2Normal(void)
{
    SysTemState_ClusterTransferCallback(
            SystemState_ClusterStandby2NormalList,
            (uint8)e_COMMOM_Num);
}


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
