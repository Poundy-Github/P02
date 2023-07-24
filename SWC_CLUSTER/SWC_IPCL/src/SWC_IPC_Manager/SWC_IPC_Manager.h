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

/***********************************************************************************************************
**
**  Name:               SWC_IPC_Manager.h
**
**  Description:        
**
**  Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_IPC_MANAGER_H
#define SWC_IPC_MANAGER_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Std_Types.h"
#include "SWC_Chime_Adapt.h"
#include "IPC_Infra.h"
#include "IPC_ClusterApp.h"
#include "IPC_IVIApp.h"
#include "IPC_Engineer.h"
#include "IPC_HUD.h"
#include "IPC_SAFETY.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_IPC_Config.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* IPC Interface Type Definenation                                                                         *
**********************************************************************************************************/

typedef int32_t (*SWC_IPC_Upload)(void *Data);
typedef void (*SWC_IPC_Download)(uint8 *ReceiveData, void *Data, uint32 Length);
typedef void (*SWC_IPC_Callback)(uint8 *Data);

/**********************************************************************************************************
* IPC Can Msessage Attribute Structure Definenation                                                       *
**********************************************************************************************************/

typedef struct
{
    uint16 Offset;
    uint16 Length;
	uint16 Cycle;
    uint8 Priority;
    uint8 Direction : 4;
	uint8 Type : 4;
	SWC_IPC_Upload Upload;
	SWC_IPC_Download Download;
	SWC_IPC_Callback Callback;
}SWC_IPC_AppNodeAttribute;

/**********************************************************************************************************
* IPC Can Msessage Status Structure Definenation                                                          *
**********************************************************************************************************/

typedef struct
{
	/*Application node cycle time tick . */
    uint16 u16Tick;
	/*When this Flag is triggered , Repeater need send application message again . */
    boolean Repeat;
	/* Data buffer changed flag */
	boolean usBufferChanged;
}SWC_IPC_AppNodeStatus;

/**********************************************************************************************************
* IPC Can Repeater Object Structure Definenation                                                          *
**********************************************************************************************************/
typedef struct
{
    uint32 AppNodeTotalNumber;
    SWC_IPC_AppNodeAttribute* AppNodeAttribute;
    SWC_IPC_AppNodeStatus Status[(uint32)SWC_IPC_APP_MSG_TOTAL_NUMBER] ;
	uint8 MsgBuffer[SWC_IPC_APP_MSG_DATA_BUFFER_LENGTH + 1u];
	/*Com State*/
	boolean IpcBusState;
#ifdef SWC_IPC_DEBUG
	uint16 LoadCount[(uint32)SWC_IPC_APP_MSG_TOTAL_NUMBER];
	uint8 ErrorCount[(uint32)SWC_IPC_APP_MSG_TOTAL_NUMBER];

	uint32 Error;
#endif
}SWC_IPC_ManagerObject;

/* MsgBuffer
    |<-       Data       ->|<  Pile->|
  Data                              Buffer
  Start                              End
*/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h" 


#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                   					  *
**********************************************************************************************************/
#endif

/**********************************************************************************************************
**
**  Revision : 2.0  
**
**  Author   : HenryChan , Cao Wenping
**
**  Date     : 2020/07/10  1.0    Original Version.    Cao Wenping
**             2020/08/06  2.0    Firmwork Update.     HenryChan
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
