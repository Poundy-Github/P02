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
 * @file:      Power_OutMgr.h
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

#ifndef __POWER_OUTMGR_H
#define __POWER_OUTMGR_H

#include "IPC_POWER.h"
#include "Rte_Power.h"
#include "Power_Volt_Monitor.h"

#define POWER_START_SEC_CODE
#include "Power_MemMap.h"

#define PM_FIRSTMSG_NOTSEND  	 					(0u)//event occer,first msg sending
#define PM_FIRSTMSG_SENDSUCCESS						(1u)//event occer,first msg send success
#define PM_VIRTUAL_ACTIVE							(1u)//event occur,(send success&&gotcbkmsg),means active
#define PM_VIRTUAL_NOACTIVE							(0u)//event occur,!(send success&&gotcbkmsg)
#define PM_NOSEND                       			(0u)//send success
#define PM_SENDING                       		    (1u)//send fail,retry immediately
#define PM_CALLBCAKMSG_RECIVE						(2u)//before recive,send cycle: 1s
#define PM_CALLBCAKMSG_WAITING  					(1u)//before recive,send cycle: 1s
#define PM_CALLBCAKMSG_NOWAIT    					(0u)//no event

/*APP Type*/
#define APP_INFOSM_LOCAL_STS                        (1u)
#define APP_INFOSM_NM                               (2u)
#define APP_INFOSM_DIAG2MINI                        (3u)
#define APP_INFOMSTYPE_AVRACK                  	    (4u)
#define APP_INFOSM_VIRTUALEVENT						(5u)
#define APP_INFOSM_AWAKEHOLDOUTFLG                  (6u)

/*APP Value*/
#define NM_OUT_Prebussleep                          (1u)
#define NM_OUT_Bussleep                             (2u)
#define NM_OUT_Normal                               (3u)



typedef enum 
{
	usbshutdown,		//batvoltage <6.0
	usbenable,		    //batvoltage >6.2
	camerashutdown,		//batvoltage <6.0
	cameraenable,		//batvoltage >6.2
    VirtualEvent_NUM,
}PM_VirtualEvent_t;

typedef uint8 (*VirtualCondition)(void);

typedef struct
{
  VirtualCondition PMVirtualEventResult;
  uint8 Virtual_EventMsg[2];
}PM_VirtualEventTable_t;

typedef struct
{
	uint8 immediatesend;
	uint8 isactive;
	uint8 sendsts;
	uint8 callbackmsg;
}PM_VirtualSendFlag;
#define PM_VirtualEventcbk_INIT_TALBE \
{ \
	{(uint8)0xff,(uint8)0xff},\
	{(uint8)0xff,(uint8)0xff},\
	{(uint8)0xff,(uint8)0xff},\
	{(uint8)0xff,(uint8)0xff},\
}

#define VirtualSendFlag_INIT_TABLE \
{\
{PM_FIRSTMSG_NOTSEND,PM_VIRTUAL_NOACTIVE,PM_NOSEND,PM_CALLBCAKMSG_NOWAIT},\
{PM_FIRSTMSG_NOTSEND,PM_VIRTUAL_NOACTIVE,PM_NOSEND,PM_CALLBCAKMSG_NOWAIT},\
{PM_FIRSTMSG_NOTSEND,PM_VIRTUAL_NOACTIVE,PM_NOSEND,PM_CALLBCAKMSG_NOWAIT},\
{PM_FIRSTMSG_NOTSEND,PM_VIRTUAL_NOACTIVE,PM_NOSEND,PM_CALLBCAKMSG_NOWAIT},\
}
static const PM_VirtualEventTable_t PM_VirtualEventTable[VirtualEvent_NUM]=
{
    {PM_VoltageShutdownEventCheck,		{APP_INFOSM_VIRTUALEVENT,(uint8)usbshutdown }},
    {PM_VoltageEnableEventCheck,		{APP_INFOSM_VIRTUALEVENT,(uint8)usbenable }},
    {PM_VoltageShutdownEventCheck,		{APP_INFOSM_VIRTUALEVENT,(uint8)camerashutdown }},
    {PM_VoltageEnableEventCheck,		{APP_INFOSM_VIRTUALEVENT,(uint8)cameraenable }},
};


extern IPC_S2M_POWERSystemStateAPP_INFOSM_t* Power_VirtualEventcbk_Get(void);
extern void SystemState_IVINOForceResponseFunc(uint8 * param, uint16 param_len);
extern void SystemState_QnxCloseResponseFunc(uint8 * param, uint16 param_len);
extern void SystemState_OutInit(void);
extern void SystemState_OutMain(void);
extern uint8 Power_IVIResponse(void);
extern uint8 Power_QnxCloseResponse(void);


#define POWER_STOP_SEC_CODE
#include "Power_MemMap.h"


#endif

