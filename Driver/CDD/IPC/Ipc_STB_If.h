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
 * @file:      Ipc_STB_If.h
 * @author:    Nobo
 * @date:      2020-9-18
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-9-18
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "VariantCfg.h"
#ifdef PLATFORM_OF_STB_IPC_USED

/*
 *  %header file in this project/library%
 */
#ifndef IPC_STB_IF_H
#define IPC_STB_IF_H

#include "Cdd_Common.h"
#include "IPC_Common.h"
#include "SOCManager.h"
#include "Misc.h"
#include "Gyro.h"
#include "Upgrade.h"
#include "IPC_EOL.h"
#include "EOL_Diag.h"
#include "AMP.h"
#include "IPC_Dedicated.h"

#ifdef PLATFOEM_OF_GNSS_USED
#include "IPC_GNSS.h"
#endif


#define IPC_STB_GROUP_TEST_ID   (0u)
#define IPC_STB_BUFFER_FULL_PRITF_EN		(STD_ON)


typedef enum
{
    IPC_STB_ERR_NONE,
    IPC_STB_ERR_BUFFER_FULL,
    IPC_STB_ERR_NO_MSG,
    IPC_STB_ERR_PLOAD_SIZE,
    IPC_STB_ERR_NINIT,
    IPC_STB_ERR_NREADY,
    IPC_STB_ERR_PRIORITY,
}e_IPC_STB_ErrorType_t;

typedef enum
{
    IPC_STB_NONE_INIT,
    IPC_STB_INIT_DONE,
    IPC_STB_CONN_READY,
}e_IPC_STB_StateType_t;


 typedef struct
 {
     uint8 group_id;
     void (*p_fun)(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len);
 
 }s_IPC_STB_CallbackRegister_t;


#define IPC_STB_ENTER_CRITICAL()           Rte_Enter_ExclusiveArea_IPC_STB()
#define IPC_STB_EXIT_CRITICAL()            Rte_Exit_ExclusiveArea_IPC_STB()

#if (STD_ON == IPC_STB_BUFFER_FULL_PRITF_EN)
#define IPC_STB_BUFFER_FULL_PRINTF_TIME		(1000/10)//1s = 1000/10 * 10ms
void IPC_STB_BufferFullPritf_Mainfunction(void);
#endif


extern void IPC_STB_If_Init(void);
extern void IPC_STB_DeInit(void);
e_IPC_STB_StateType_t IPC_STB_DataSendFormHandshake(uint8 *p_msg, uint16 len, uint8 priority);
extern e_IPC_STB_ErrorType_t IPC_STB_DataSend(uint8 *p_msg, uint16 len, uint8 priority);


extern boolean IPC_STB_CheckDataSend(void);
extern void IPC_STB_SetIPC_STBStateType(e_IPC_STB_StateType_t state_type);
extern e_IPC_STB_StateType_t IPC_STB_GetIPC_STBStateType(void);
extern void IPC_STB_RecevieMessageDecode(uint8 *p_frame, uint16 frame_len);
void IPC_STB_TestCallback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len);
void SOC_Dedicated_GroupParsing(uint8 major_msg_id, uint8 sub_msg_id, uint8 * param, uint16 param_len);
#ifdef PLATFOEM_OF_GNSS_USED
void GNSS_GroupParsing(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len);
#endif

#ifdef PLATFOEM_OF_GNSS_USED
// Sort by Group Id
// reserved ID filled with {IPC_STB_GROUP_TEST_ID,IPC_STB_TestCallback},
#define IPC_STB_APP_REGISTER_LIST \
{\
/* 00 */{IPC_STB_GROUP_TEST_ID,IPC_STB_TestCallback},\
/* 01 */{IPC_STB_GROUP_TEST_ID,IPC_STB_TestCallback},\
/* 02 */{IPC_GROUP_DEDICATED_ID,SOC_Dedicated_GroupParsing},\
/* 03 */{IPC_GROUP_GNSS_ID,GNSS_GroupParsing},\
}
#else
#define IPC_STB_APP_REGISTER_LIST \
{\
/* 00 */{IPC_STB_GROUP_TEST_ID,IPC_STB_TestCallback},\
/* 01 */{IPC_STB_GROUP_TEST_ID,IPC_STB_TestCallback},\
/* 02 */{IPC_GROUP_DEDICATED_ID,SOC_Dedicated_GroupParsing},\
}
#endif

#endif

#endif
