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
 * @file:      SystemState_InitCfg.h
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

#ifndef __SYSTEMSTATE_INIT_CFG
#define __SYSTEMSTATE_INIT_CFG

#include "AMP.h"
#include "Rte_Power.h"
#include "AMP_ShutDown.h"


/* list of cluster module Init name */
typedef enum 
{
    e_GWInit = 0u, 
    e_NormalInit,
    e_SFInit,
    e_ClusterInitNum, 
} e_Systemstate_ClusterInitName_t;

/* list of cluster module name */
typedef enum 
{
    e_COMMOM_Gateway = 0u, 
    e_COMMOM_Normal,
    e_COMMOM_Safety,
    e_COMMOM_Num, 
} e_Systemstate_ClusterModuleName_t;



/* list of cluster module Init name */
typedef enum 
{
    e_GWDeInit = 0u, 
    e_NormalDeInit,
    e_SFDeInit,
    e_ClusterDeInitNum, 
} e_Systemstate_ClusterDeInitName_t;


/* list of CDD module Init name*/
typedef enum 
{
    e_RTCInit = 0u,
    e_GyroInit, 
    e_AMPInit,
    e_ADAUInit,
    e_CDDInitNum, 
} e_Systemstate_CDDInitName_t;


/* list of CDD module Deinit name*/
typedef enum 
{
    e_AMPDeInit = 0u, 
    e_ADAUDeInit,
    e_CDDDeInitNum, 
} e_Systemstate_CDDDeInitName_t;

typedef struct 
{
    e_Systemstate_ClusterInitName_t ClusterInitName;
    Std_ReturnType(*p_fun) (void);
} s_Systemstate_ClusterInit_t;


typedef struct 
{
    e_Systemstate_CDDInitName_t CDDInitName;
    Std_ReturnType(*p_fun) (void);
} s_Systemstate_CDDInit_t;


typedef struct 
{
    e_Systemstate_CDDDeInitName_t CDDDeInitName;
    Std_ReturnType(*p_fun) (void);
} s_Systemstate_CDDDeInit_t;

typedef struct 
{
    e_Systemstate_ClusterModuleName_t ClusterInitName;
    Std_ReturnType(*p_fun) (void);
} s_Systemstate_ClusterState_t;


typedef struct 
{
    e_Systemstate_ClusterDeInitName_t ClusterDeInitName;
    Std_ReturnType(*p_fun) (void);
} s_Systemstate_ClusterDeInit_t;


#define SYSTEMSTATE_ClUSTERINIT_LIST    {\
    {e_GWInit,Rte_Call_Common_GW_List_Int},\
    {e_NormalInit,Rte_Call_Common_Normal_List_Int},\
    {e_SFInit,Rte_Call_Common_SF_List_Int},\
}

#define SYSTEMSTATE_ClUSTERDEINIT_LIST      {\
    {e_GWDeInit,Rte_Call_Common_GW_List_Deinit},\
    {e_NormalDeInit,Rte_Call_Common_Normal_List_Deinit},\
    {e_SFDeInit,Rte_Call_Common_SF_List_Deinit},\
}

#define SYSTEMSTATE_CDDINIT_LIST    {\
    {e_RTCInit,Rte_Call_Rtc_Init_server_Operation},\
    {e_GyroInit,Rte_Call_Gyro_Init_server_Operation},\
    {e_AMPInit,AMP_CDDInit},\
    {e_ADAUInit,Rte_Call_Power_ADAU_server_StateToInit},\
}



#define SYSTEMSTATE_CDDDEINIT_LIST      {\
    {e_AMPDeInit,PowerCtrl_AMPShutDown},\
    {e_ADAUDeInit,Rte_Call_Power_ADAU_server_StateToDeInit},\
}


#define SYSTEMSTATE_ClUSTERINIT_STANDBY2NORMAL_LIST     {\
    {e_COMMOM_Gateway,Rte_Call_rcCS_Common_GateWay_PowerTransfer_Standby2NomalCallback},\
    {e_COMMOM_Normal, Rte_Call_rcCS_Common_Nomal_PowerTransfer_Standby2NomalCallback  },\
    {e_COMMOM_Safety, Rte_Call_rcCS_Common_Safety_PowerTransfer_Standby2NomalCallback  },\
}

#define SYSTEMSTATE_ClUSTERINIT_NORMAL2STANDBY_LIST     {\
    {e_COMMOM_Gateway,Rte_Call_rcCS_Common_GateWay_PowerTransfer_Nomal2StandbyCallback},\
    {e_COMMOM_Normal, Rte_Call_rcCS_Common_Nomal_PowerTransfer_Nomal2StandbyCallback  },\
    {e_COMMOM_Safety, Rte_Call_rcCS_Common_Safety_PowerTransfer_Nomal2StandbyCallback  },\
}

#define Power_START_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


extern void SystemState_ClusterInitFunc(void);
extern void SystemState_ClusterDeInitFunc(void);
extern void SystemState_CDDInitFunc(void);
extern void SystemState_CDDDeInitFunc(void);
extern void SysTemState_ClusterNormal2Standby(void);
extern void SysTemState_ClusterStandby2Normal(void);
#define Power_STOP_SEC_CODE
#include "Power_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif
