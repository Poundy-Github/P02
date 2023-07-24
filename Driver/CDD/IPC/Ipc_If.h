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
 * @file:      Ipc_If.h
 * @author:    Nobo
 * @date:      2020-5-22
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-5-22
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %header file in this project/library%
 */
#ifndef __IPC_IF_H__
#define __IPC_IF_H__
#include "Cdd_Common.h"


#include "IPC_Common.h"
#include "SOCManager.h"
#include "Misc.h"
#include "Gyro.h"
#include "Upgrade.h"
#include "IPC_EOL.h"
#include "EOL_Diag.h"
#include "AMP.h"
#include "DcmEx_Diag.h"
#include "IPC_Com.h"
#include "IPC_Audio.h"
#include "IPC_CAN.h"
#include "IPC_ClusterApp.h"
#include "IPC_Diagnose.h"
#include "IPC_EOL.h"
#include "IPC_Log.h"
#include "IPC_Misc.h"
#include "IPC_POWER.h"
#include "IPC_SWUM.h"
#include "IPC_Sensor.h"
#include "IPC_SystemState.h"
#include "IPC_IVIApp.h"
#include "IPC_Engineer.h"
#include "IPC_Infra.h"
#include "IPC_HUD.h"
#include "IPC_SAFETY.h"



#define IPC_GROUP_TEST_ID   (0u)

#define IPC_BUFFER_FULL_PRITF_EN		(STD_ON)

typedef enum e_IPC_ErrorType_t
{
    IPC_ERR_NONE,
    IPC_ERR_BUFFER_FULL,
    IPC_ERR_NO_MSG,
    IPC_ERR_PLOAD_SIZE,
    IPC_ERR_NINIT,
    IPC_ERR_NREADY,
    IPC_ERR_PRIORITY,
}e_IPC_ErrorType_t;

typedef enum e_IPC_StateType_t
{
    IPC_NONE_INIT,
    IPC_INIT_DONE,
    IPC_CONN_READY,
}e_IPC_StateType_t;


 typedef struct s_IPC_CallbackRegister_t
 {
     uint8 group_id;
     void (*p_fun)(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len);
 
 }s_IPC_CallbackRegister_t;


#define IPC_ENTER_CRITICAL()           Rte_Enter_ExclusiveArea_IPC()
#define IPC_EXIT_CRITICAL()            Rte_Exit_ExclusiveArea_IPC()

extern uint16 ipc_TxDataHighPriLen;
extern uint16 ipc_TxDataLowPriLen;
extern uint8 ipc_TxDataHighPri[IPC_DATA_HIGH_PRI_LENGTH]; /*IPC DMA High priority send data buffer.*/  
extern uint8 ipc_TxDataLowPri[IPC_DATA_LOW_PRI_LENGTH]; /*IPC DMA High priority send data buffer.*/  

#if (STD_ON == IPC_BUFFER_FULL_PRITF_EN)
#define IPC_BUFFER_FULL_PRINTF_TIME		(1000/10)//1s = 1000/10 * 10ms

extern void IPC_BufferFullPritf_Mainfunction(void);
#endif


extern void IPC_If_Init(void);
extern void IPC_DeInit(void);
extern e_IPC_ErrorType_t IPC_DataSend(uint8 *p_msg, uint16 len, uint8 priority);
extern e_IPC_ErrorType_t IPC_DataSendFormHandshake(uint8 *p_msg, uint16 len, uint8 priority);

extern boolean IPC_CheckDataSend(void);
extern void IPC_SetIPCStateType(e_IPC_StateType_t state_type);
extern e_IPC_StateType_t IPC_GetIPCStateType(void);
extern void IPC_RecevieMessageDecode(uint8 *p_frame, uint16 frame_len);

extern void IPC_TestCallback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len);

#if 0
extern void ipc_ServiceReceiveCallback(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len);
#endif
extern void AMP_ReceiveIPCData(uint8 Major_msg_id,uint8 Sub_msg_id,uint8 *param,uint16_t param_len);
extern void IPC_Call_Diagnose_ReceiveData(uint8 msgMajorId, uint8 msgSubId, uint8 *param, uint16 paramLen);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Common_GateWay_IPC_DataSend_If_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) p_msg, uint16 len, uint8 priority); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

// Sort by Group Id
// reserved ID filled with {IPC_GROUP_TEST_ID,IPC_TestCallback},
#define IPC_APP_REGISTER_LIST \
{\
/* 00 */{IPC_GROUP_TEST_ID,IPC_TestCallback},\
/* 01 */{IPC_GROUP_CAN_ID,IPC_API_CanMsgReceiveCallback},\
/* 02 */{IPC_GROUP_POWER_ID,SOC_PowerGroupParsing},\
/* 03 */{IPC_GROUP_EOL_ID,EOL_DiagTransferReceiveResponseData},\
/* 04 */{IPC_GROUP_SWUM_ID,Upgrade_Ipc_UpgrdMsgRcvCall},\
/* 05 */{IPC_GROUP_DIAGNOSE_ID,IPC_Call_Diagnose_ReceiveData},\
/* 06 */{IPC_GROUP_LOG_ID,IPC_Log_Callback},\
/* 07 */{IPC_GROUP_TEST_ID,IPC_TestCallback},\
/* 08 */{IPC_GROUP_TEST_ID,IPC_TestCallback},\
/* 09 */{IPC_GROUP_SENSOR_ID,Gyro_IPCCallbackM},\
/* 10 */{IPC_GROUP_MISC_ID,IPC_MISC_Callback},\
/* 11 */{IPC_GROUP_ENGINEER_ID,IPC_API_EngineerAppReceiveCallback},\
/* 12 */{IPC_GROUP_AUDIO_ID,AMP_ReceiveIPCData},\
/* 13 */{IPC_GROUP_CLUSTERAPP_ID,IPC_API_ClusterAppReceiveCallback},\
/* 14 */{IPC_GROUP_HUD_ID,IPC_API_WhudReceiveCallback},\
/* 15 */{IPC_GROUP_TEST_ID,IPC_TestCallback},\
/* 16 */{IPC_GROUP_IVIAPP_ID,IPC_API_IviAppReceiveCallback},\
/* 17 */{IPC_GROUP_INFRA_ID,IPC_API_InfraReceiveCallback},\
/* 18 */{IPC_GROUP_SAFETY_ID,IPC_API_SaftyReceiveCallback},\
}
#endif
