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
**  Name         : SWC_IPC_Manager.c
**
**  Description  :
**
**  Organization :
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Ipc_if.h"
#include "Rte_Common_GateWay.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_IPC_Interface.h"
#include "SWC_IPC_Manager.h"
#include "SWC_IPC_Config.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CONST_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* IPC Application Node Attribute Table                                                                    *
**********************************************************************************************************/

const SWC_IPC_AppNodeAttribute SWC_IPC__AppNodeAttributeTable[SWC_IPC_APP_MSG_TOTAL_NUMBER] = SWC_IPC_APP_MSG_ATTRIBUTE_TABLE;

#define SWC_IPC_NW_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                     					  *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* IPC Cluster Manager Object                                                                              *
**********************************************************************************************************/

static SWC_IPC_ManagerObject SWC_IPC__ManagerObject = {0};

#define SWC_IPC_NW_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* Static Function Defination                                                                              *
**********************************************************************************************************/

static void IPC_ManagerObjectInit(SWC_IPC_ManagerObject * const Object);

static void IPC_ComBusStateUpdate(SWC_IPC_ManagerObject * const Object);

static void IPC_MsgPeriodicUpdate(SWC_IPC_ManagerObject * const Object);

static void IPC_AppMsgTransmit(const uint8 Index, SWC_IPC_ManagerObject * const Object);

static void IPC_AppMsgReceive(const uint8 Index, uint8 *Data, uint16 Length, SWC_IPC_ManagerObject * const Object);

#ifdef SWC_IPC_DEBUG

static void IPC_TransmitPrintLog(const uint8 Index, SWC_IPC_ManagerObject * const Object);

#endif
/**********************************************************************************************************
*Function   : IPC_ManagerInit                                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
void IPC_ManagerInit(void)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject;

	IPC_ManagerObjectInit(Object);

	IPC_API_RepeatAppMsg(SWC_IPC_APP_MSG_TYPE_PERIODIC , SWC_IPC_NONE);
}
/**********************************************************************************************************
*Function   : IPC_ManagerTask                                                                             *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
void IPC_ManagerTask(void)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject;

	IPC_ComBusStateUpdate(Object);

	IPC_API_ClusterPowerOperation();

	IPC_MsgPeriodicUpdate(Object);
}
/**********************************************************************************************************
*Function   : IPC_ManagerObjectInit                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_ManagerObject * const Object                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-31                                                                                  *
**********************************************************************************************************/
static void IPC_ManagerObjectInit(SWC_IPC_ManagerObject * const Object)
{
	/*Clear object ram data.*/
	(void)memset(Object,0,sizeof(SWC_IPC_ManagerObject));

	Object->AppNodeTotalNumber = (uint32)SWC_IPC_APP_MSG_TOTAL_NUMBER;
	Object->AppNodeAttribute = (SWC_IPC_AppNodeAttribute*)SWC_IPC__AppNodeAttributeTable;

#ifdef SWC_IPC_DEBUG
	Object->MsgBuffer[SWC_IPC_APP_MSG_DATA_BUFFER_LENGTH] = SWC_IPC_DEBUG_PILE;
#endif
}
/**********************************************************************************************************
*Function   : IPC_ComBusStateUpdate                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * Object                                                          *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-27                                                                                  *
**********************************************************************************************************/
static void IPC_ComBusStateUpdate(SWC_IPC_ManagerObject * const Object)
{
	/*Ipc bus*/
	if(IPC_CONN_READY == IPC_GetIPCStateType())
	{
		if(FALSE == Object->IpcBusState)
		{
			IPC_API_RepeatAppMsg(SWC_IPC_APP_MSG_TYPE_PERIODIC , SWC_IPC_NONE);
		}
		Object->IpcBusState = TRUE ;
	}
	else
	{
		Object->IpcBusState = FALSE ;
	}
}

/**********************************************************************************************************
*Function   : IPC_MsgPeriodicUpdate                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_ManagerObject * const Object                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
static void IPC_MsgPeriodicUpdate(SWC_IPC_ManagerObject * const Object)
{
	uint8 Index = 0;

	/*Check ipc communication state*/
	if(FALSE != Object->IpcBusState )
	{
		for(Index = 0 ; Index < Object->AppNodeTotalNumber ; ++Index)
		{
			if(Object->Status[Index].u16Tick <= Object->AppNodeAttribute[Index].Priority)
			{
				Object->Status[Index].u16Tick  = \
					(uint16)Object->AppNodeAttribute[Index].Priority + Object->AppNodeAttribute[Index].Cycle;

				if(SWC_IPC_MCU2SOC == Object->AppNodeAttribute[Index].Direction)
				{
					if( FALSE != Object->Status[Index].Repeat)
					{
						IPC_AppMsgTransmit(Index, Object);
					}
				}
			}
			else
			{
				Object->Status[Index].u16Tick -= 1;
			}
		}
	}
}

/**********************************************************************************************************
*Function   : IPC_API_AppMsgTransmit                                                                      *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 Index, const uint8 * const Data, const uint16 Length, const boolean SyncFlag   *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
void IPC_API_AppMsgTransmit(const uint8 Index, const uint8 * const Data, const uint16 Length, const boolean SyncFlag)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;

	if((Length <= Object->AppNodeAttribute[Index].Length)\
	 &&(Index < Object->AppNodeTotalNumber))
	{
		if( SWC_IPC_NULL != Data )
		{
			if((FALSE != memcmp(&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset],
							    Data,
							    Length))
			|| (FALSE != SyncFlag))
			{
				if (FALSE != memcmp(&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset], Data, Length))
				{
					(void)memcpy(&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset], Data, Length);
					Object->Status[Index].usBufferChanged = TRUE;
				}
				else
				{
					/* do nothing */
				}

				if((FALSE != SyncFlag)&&(FALSE != Object->IpcBusState))
				{
					IPC_AppMsgTransmit(Index, Object);
				}
				else
				{
					IPC_API_RepeatAppMsg(SWC_IPC_NONE, Index);
				}
			}
		}
		else
		{
			if(FALSE != SyncFlag)
			{
				if(FALSE != Object->IpcBusState)
				{
					IPC_AppMsgTransmit(Index, Object);
				}
				else
				{
					IPC_API_RepeatAppMsg(SWC_IPC_NONE, Index);
				}
			}
		}
	}
}

/**********************************************************************************************************
*Function   : IPC_API_SetAppMsgBuffer                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 Index, const uint8 * const Data, const uint16 Length                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : DylanZhao                                                                                   *
*                                                                                                         *
*Date       : 2021-03-5                                                                                  *
**********************************************************************************************************/
void IPC_API_SetAppMsgBuffer(const uint8 Index, const uint8 * const Data, const uint16 Length)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;

	if((Length <= Object->AppNodeAttribute[Index].Length)\
	 &&(Index < Object->AppNodeTotalNumber))
	{
		if( SWC_IPC_NULL != Data )
		{
			if((FALSE != memcmp(&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset], Data, Length)))
			{
				(void)memcpy(&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset], Data, Length);
				Object->Status[Index].usBufferChanged = TRUE;
			}
		}
		else
		{
			SWC_IPC_PRINT_ERROR("SetAppMsgBuffer:Data is NULL pointer!!!");
		}
	}
}

/**********************************************************************************************************
*Function   : IPC_AppMsgTransmit                                                                          *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const SWC_IPC_AppMsgList AppNodeId , SWC_IPC_ManagerObject * const Object                   *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
static void IPC_AppMsgTransmit(const uint8 Index , SWC_IPC_ManagerObject * const Object)
{
	uint8 * Data = &Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset];

	if(NULL != Object->AppNodeAttribute[Index].Callback)
	{
		Object->AppNodeAttribute[Index].Callback(Data);
	}

	if(NULL != Object->AppNodeAttribute[Index].Upload)
	{
		if(IPC_ERR_NONE != Object->AppNodeAttribute[Index].Upload((void *)Data))
		{
			Object->Status[Index].Repeat = TRUE;
		}
		else
		{
			Object->Status[Index].Repeat = FALSE;
		}
	#ifdef SWC_IPC_DEBUG
		if (TRUE == Object->Status[Index].usBufferChanged)
		{
			IPC_TransmitPrintLog(Index, Object);
			Object->Status[Index].usBufferChanged = FALSE;
		}
		else
		{
			/* do nothing */
		}
	#endif
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid ipc application transmit index! Index = %d",Index);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_ClusterAppReceiveCallback                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-14                                                                                  *
**********************************************************************************************************/
void IPC_API_ClusterAppReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	SWC_IPC_AppMsgList Index = SWC_IPC_APP_MSG_START_INDEX;

	switch(MajorId)
	{
		case IPC_S2M_CLUSTERAPP_MSGMAJOR_CLUSTERSOC_ID:
		{
			switch(SubId)
			{
				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_WRNID_ID:
				{
					Index = S2M_WARNING;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTSTATUS_ID:
				{
					Index = S2M_TELLTALE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_BACKCHIME_ID:
				{
					Index = S2M_CHIME;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TCCLEAR_ID:
				{
					Index = S2M_TC_CLEAR_REQ;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_COMMONAPPALIVE_ID:
				{
					Index = S2M_COMMON_APP_ALIVE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUSETTING_ID:
				{
					Index = S2M_SET_MENU_REQ;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGES_ID:
				{
					Index = S2M_GAUGES_VALUE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_INTERFACEAPPALIVE_ID:
				{
					Index = S2M_INTERFACE_ALIVE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_ADASSTATUS_ID:
				{
					Index = S2M_ADAS_STATUS;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMIPOWERMODE_ID:
				{
					Index = S2M_HMI_POWER_MODE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_GAUGESALIVE_ID:
				{
					Index = S2M_GAUGES_ALIVE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_CHIMECLIENTALIVE_ID:
				{
					Index = S2M_CHIME_CLIENT_ALIVE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_MENUTHEME_ID:
				{
					Index = S2M_MENU_THEME_REQ;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_HMISAFETY_ID:
				{
					Index = S2M_HMI_SAFETY_ALIVE;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_TTTOCHIME_ID:
				{
					Index = S2M_TtToChime_REQ;
					break;
				}

				case IPC_S2M_CLUSTERAPP_CLUSTERSOC_MSGSUB_OFFROADINFO_ID:
				{
					Index = S2M_SET_OffroadInfo_REQ;
					break;
				}

				default:
				{
					SWC_IPC_PRINT_ERROR("Invalid sub id from cluster callback! MajorId = %d ,SubId = %d",MajorId,SubId);
					break;
				}
			}
			break;
		}
		default:
		{
			SWC_IPC_PRINT_ERROR("Invalid major id from cluster callback! MajorId = %d ,SubId = %d",MajorId,SubId);
			break;
		}
	}

	if(Index > SWC_IPC_APP_MSG_START_INDEX)
	{
		IPC_AppMsgReceive((uint8)Index , Data , Length , Object);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_WhudReceiveCallback                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-01                                                                                  *
**********************************************************************************************************/
void IPC_API_WhudReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	SWC_IPC_AppMsgList Index = SWC_IPC_APP_MSG_START_INDEX;

	switch(MajorId)
	{
		case IPC_S2M_HUD_MSGMAJOR_COMMON_ID:
		{
			switch(SubId)
			{
				case IPC_S2M_HUD_COMMON_MSGSUB_NVMCONFIGREQUSET_ID:
				{
					Index = S2M_WHUD_NVM_CONFIG_REQ;
					break;
				}
				case IPC_S2M_HUD_COMMON_MSGSUB_SETNVMCONFIG_ID:
				{
					Index = S2M_WHUD_SET_NVM_CONFIG;
					break;
				}
				case IPC_S2M_HUD_COMMON_MSGSUB_ALIVEMSG_ID:
				{
					Index = S2M_WHUD_APP_ALIVE;
					break;
				}
				case IPC_S2M_HUD_COMMON_MSGSUB_WHUDNVMSET_ID:
				{
					Index = S2M_WHUD_NVM_SET;
					break;
				}
				default:
				{
					SWC_IPC_PRINT_ERROR("Invalid sub id from whud callback! MajorId = %d ,SubId = %d",MajorId,SubId);
					break;
				}
			}
			break;
		}
		default:
		{
			SWC_IPC_PRINT_ERROR("Invalid major id from whud callback! MajorId = %d ,SubId = %d",MajorId,SubId);
			break;
		}
	}

	if(Index > SWC_IPC_APP_MSG_START_INDEX)
	{
		IPC_AppMsgReceive((uint8)Index , Data , Length , Object);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_IviAppReceiveCallback                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-01                                                                                  *
**********************************************************************************************************/
void IPC_API_IviAppReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	SWC_IPC_AppMsgList Index = SWC_IPC_APP_MSG_START_INDEX;

	switch(MajorId)
	{
		case IPC_S2M_IVIAPP_MSGMAJOR_INFO_ID:
		{
			switch(SubId)
			{
				case IPC_S2M_IVIAPP_INFO_MSGSUB_READSETTINGSIGNALREQ_ID:
				{
					Index = S2M_READ_SETTING_REQ;
					break;
				}

				case IPC_S2M_IVIAPP_INFO_MSGSUB_SETSETTINGSIGNALREQ_ID:
				{
					Index = S2M_SET_SETTING_REQ;
					break;
				}

				default:
				{
					SWC_IPC_PRINT_ERROR("Invalid sub id from ivi callback! MajorId = %d ,SubId = %d",MajorId,SubId);
					break;
				}
			}
			break;
		}
		default:
		{
			SWC_IPC_PRINT_ERROR("Invalid major id from ivi callback! MajorId = %d ,SubId = %d",MajorId,SubId);
			break;
		}
	}

	if(Index > SWC_IPC_APP_MSG_START_INDEX)
	{
		IPC_AppMsgReceive((uint8)Index , Data , Length , Object);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_IviAppReceiveCallback                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-01                                                                                  *
**********************************************************************************************************/
void IPC_API_EngineerAppReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	SWC_IPC_AppMsgList Index = SWC_IPC_APP_MSG_START_INDEX;

	switch(MajorId)
	{
		case IPC_S2M_ENGINEER_MSGMAJOR_IVI_ID:
		{
			switch(SubId)
			{
				case IPC_S2M_ENGINEER_IVI_MSGSUB_READINFOREQUEST_ID:
				{
					Index = S2M_READ_ENGINEER_INFO_REQ;
					break;
				}
				case IPC_S2M_ENGINEER_IVI_MSGSUB_SETPARAREQUEST_ID:
				{
					Index = S2M_SET_ENGINEER_PARA_REQ;
					break;
				}
				default:
				{
					SWC_IPC_PRINT_ERROR("Invalid sub id from engineer callback! MajorId = %d ,SubId = %d",MajorId,SubId);
					break;
				}
			}
			break;
		}
		default:
		{
			SWC_IPC_PRINT_ERROR("Invalid major id from engineer callback! MajorId = %d ,SubId = %d",MajorId,SubId);
			break;
		}
	}

	if(Index > SWC_IPC_APP_MSG_START_INDEX)
	{
		IPC_AppMsgReceive((uint8)Index , Data , Length , Object);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_InfraReceiveCallback                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-12                                                                                  *
**********************************************************************************************************/
void IPC_API_InfraReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	SWC_IPC_AppMsgList Index = SWC_IPC_APP_MSG_START_INDEX;

	switch(MajorId)
	{
		case IPC_S2M_INFRA_MSGMAJOR_MISC_ID:
		{
			switch(SubId)
			{
				case IPC_S2M_INFRA_MISC_MSGSUB_RESTOREFACTORYSETTINGREQUSET_ID:
				{
					Index = S2M_RESTORE_FACTORY_REQ;
					break;
				}

                case IPC_S2M_INFRA_MISC_MSGSUB_READSERIALNUMBERREQUEST_ID:
				{
					Index = S2M_READ_SERIAL_NUMBER_REQ;
					break;
				}
				case IPC_S2M_INFRA_MISC_MSGSUB_READVINNUMBERREQUEST_ID:
				{
					Index = S2M_READ_VIN_NUMBER_REQ;
					break;
				}
				case IPC_S2M_INFRA_MISC_MSGSUB_READBEANIDREQUEST_ID:
				{
					Index = S2M_ReadBeanID_REQ;
					break;
				}
				case IPC_S2M_INFRA_MISC_MSGSUB_SETAVASSWITCHSTATUS_ID:
				{
					Index = S2M_SETAVASSWTST_REQ;
					break;
				}
				default:
				{
					SWC_IPC_PRINT_ERROR("Invalid sub id from infrastructure callback! MajorId = %d ,SubId = %d",MajorId,SubId);
					break;
				}
			}
			break;
		}
		default:
		{
			SWC_IPC_PRINT_ERROR("Invalid major id from infrastructure callback! MajorId = %d ,SubId = %d",MajorId,SubId);
			break;
		}
	}

	if(Index > SWC_IPC_APP_MSG_START_INDEX)
	{
		IPC_AppMsgReceive((uint8)Index , Data , Length , Object);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_SaftyReceiveCallback                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-05                                                                                  *
**********************************************************************************************************/
void IPC_API_SaftyReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	SWC_IPC_AppMsgList Index = SWC_IPC_APP_MSG_START_INDEX;

	switch(MajorId)
	{
		case IPC_S2M_SAFETY_MSGMAJOR_APP_ID:
		{
			switch(SubId)
			{
				case IPC_S2M_SAFETY_APP_MSGSUB_SAFETYAPPALIVE_ID:
				{
					Index = S2M_SAFETY_APP_ALIVE;
					break;
				}
				case IPC_S2M_SAFETY_APP_MSGSUB_SAFETYTTCRC_ID:
				{
					Index = S2M_SAFETY_TT_CRC;
					break;
				}
				case IPC_S2M_SAFETY_APP_MSGSUB_SAFETYGEARCRC_ID:
				{
					Index = S2M_SAFETY_GEAR_CRC;
					break;
				}
				case IPC_S2M_SAFETY_APP_MSGSUB_TTSELFCHECK_ID:
				{
					Index = S2M_SELF_CHECK;
					break;
				}
				default:
				{
					SWC_IPC_PRINT_ERROR("Invalid sub id from safty callback! MajorId = %d ,SubId = %d",MajorId,SubId);
					break;
				}
			}
			break;
		}
		default:
		{
			SWC_IPC_PRINT_ERROR("Invalid major id from safty callback! MajorId = %d ,SubId = %d",MajorId,SubId);
					break;
		}
	}

	if(Index > SWC_IPC_APP_MSG_START_INDEX)
	{
		IPC_AppMsgReceive((uint8)Index , Data , Length , Object);
	}
}
/**********************************************************************************************************
*Function   : IPC_AppMsgReceive                                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const SWC_IPC_AppMsgList Index , SWC_IPC_ManagerObject * const Object                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2021-01-12                                                                                  *
**********************************************************************************************************/
static void IPC_AppMsgReceive(const uint8 Index , uint8 *Data , uint16 Length , SWC_IPC_ManagerObject * const Object)
{
	if(NULL != Object->AppNodeAttribute[Index].Download)
	{
		Object->AppNodeAttribute[Index].Download(Data,(void*)&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset],Length);
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Invalid ipc application receive index! Index = %d",Index);
	}

	if(NULL != Object->AppNodeAttribute[Index].Callback)
	{
		Object->AppNodeAttribute[Index].Callback(&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset]);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_RepeatAppMsg                                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 Type , const uint8 AppIndex                                                     *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-19                                                                                  *
**********************************************************************************************************/
void IPC_API_RepeatAppMsg( const uint8 Type , const uint8 AppIndex)
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	uint32 Index = 0;

	if( SWC_IPC_NONE != Type )
	{
		for(Index = 0 ; Index < Object->AppNodeTotalNumber ; ++Index)
		{
			if(Type & Object->AppNodeAttribute[Index].Type)
			{
				Object->Status[Index].Repeat = TRUE;
			}
		}
	}
	else
	{
		if(AppIndex < Object->AppNodeTotalNumber)
		{
			Object->Status[AppIndex].Repeat = TRUE;
		}
		else if (AppIndex == Object->AppNodeTotalNumber)
		{
			for(Index = 0 ; Index < Object->AppNodeTotalNumber ; ++Index)
			{
				Object->Status[Index].Repeat = TRUE;
			}
		}
		else
		{

		}
	}
}
/**********************************************************************************************************
*Function   : IPC_API_RepeatAppMsg                                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 Index                                                                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
boolean IPC_API_CheckRepeatStatus( const uint8 AppIndex )
{
	SWC_IPC_ManagerObject * Object = &SWC_IPC__ManagerObject ;
	boolean Return = FALSE ;
	if(AppIndex < Object->AppNodeTotalNumber)
	{
		Return = Object->Status[AppIndex].Repeat;
	}
	return Return;
}
/**********************************************************************************************************
*Function   : IPC_TransmitPrintLog                                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const SWC_IPC_AppMsgList Index , const boolean Return                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2021-01-12                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_DEBUG

#define CASE_COMMON_INDEX(index,log) \
	case index: \
		(void)strcat(StringBuffer,log); \
		break;

#ifdef SWC_IPC_CYCLIC_MSG_PRINT_SWITCH

#define CASE_CYCLIC_INDEX(index,log) \
	case index: \
		(void)strcat(StringBuffer,log); \
		break;

#else

#define CASE_CYCLIC_INDEX(index,log) \
	case index: \
		{ \
			return; \
		}

#endif

static void IPC_TransmitPrintLog(const uint8 Index , SWC_IPC_ManagerObject * const Object)
{
	char StringBuffer[50] = {0};
	// char NumberBuffer[11] = {0};

	(void)strcat(StringBuffer,"[M2S]");

	switch(Index)
	{
		CASE_COMMON_INDEX((uint8)M2S_CLUSTER_POWER,"[CLUSTER-POWER]");
		CASE_COMMON_INDEX((uint8)M2S_SAFETY_APP_MSG_UPLOADED,"[CLUSTER-SAFTY-ALIVE-RESP]");
		CASE_COMMON_INDEX((uint8)M2S_COMMON_APP_MSG_UPLOADED,"[CLUSTER-COM-ALIVE-RESP]");
		CASE_COMMON_INDEX((uint8)M2S_RESTORE_FACTORY_RESP,"[INFRA-RESTORE-RESP]");

		default:
		{
			//strcat(StringBuffer,"[UNKNOW]");
			//sprintf(NumberBuffer, "[%d]", Index);
			//strcat(StringBuffer,NumberBuffer);
			break;
		}
	}

	if ((M2S_CLUSTER_POWER == Index) ||
		(M2S_SAFETY_APP_MSG_UPLOADED == Index) ||
		(M2S_COMMON_APP_MSG_UPLOADED == Index) ||
		(M2S_RESTORE_FACTORY_RESP == Index))
	{
		if(FALSE == Object->Status[Index].Repeat) /*Repeat flag = FALSE : Transmit success*/
		{
			strcat(StringBuffer,"[OK]");

			SWC_IPC_PRINT_DEBUG(StringBuffer);
			IPC_API_PrintDataArrayLog(&Object->MsgBuffer[Object->AppNodeAttribute[Index].Offset],
									   Object->AppNodeAttribute[Index].Length);
		}
		else
		{
			// strcat(StringBuffer,"[FAILD]");

			// SWC_IPC_PRINT_ERROR(StringBuffer);
		}
	}
}
#endif

#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                                         *
**********************************************************************************************************/

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
