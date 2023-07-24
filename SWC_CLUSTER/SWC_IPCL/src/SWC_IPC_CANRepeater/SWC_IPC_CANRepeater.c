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
**  Name         : SWC_IPC_CANRepeater.c
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
#include "IPC_CAN.h"
#include "Ipc_if.h"
#include "logger.h"

#include "VConfig_Cfg.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_IPC_Interface.h"
#include "SWC_IPC_CANRepeater.h"
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
* IPC CAN Message Attribute Table                                                                         *
**********************************************************************************************************/
const SWC_IPC_CanMsgAttribute SWC_IPC__CanMsgAttributeTable[(uint32)SWC_IPC_CAN_MSG_TOTAL_NUMBER] = SWC_IPC_CAN_MSG_ATTRIBUTE_TABLE;

const uint8 SWC_IPC__CanMsgConstTable[(uint32)SWC_IPC_CAN_MSG_DATA_BUFFER_LENGTH] =  SWC_IPC_CAN_MSG_CONST_TABLE;

const SWC_IPC_CanSignalAttribute SWC_IPC__TxCanSignalAttributeTable[(uint32)SWC_IPC_TX_CAN_SIGNAL_TOTAL_NUMBER] = SWC_IPC_TX_CAN_SIGNAL_ATTRIBUTE_TABLE;

const SWC_IPC_CanSignalAttribute SWC_IPC__RxCanSignalAttributeTable[(uint32)SWC_IPC_RX_CAN_SIGNAL_TOTAL_NUMBER] = SWC_IPC_RX_CAN_SIGNAL_ATTRIBUTE_TABLE;

const uint16 SWC_IPC__EventTxCanSignalMappingTable[(uint32)SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] = SWC_IPC_EVENT_TX_CAN_SIGNAL_MAPPING_TABLE;

static const char *SWC_IPC__EventTxCanSignalNameTable[(uint32)SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER] = SWC_IPC_EVENT_TXSIGNAL_NAME_TABLE;

#define SWC_IPC_NW_STOP_SEC_CONST_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                    					  *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* IPC CAN Message Repeater Object                                                                         *
**********************************************************************************************************/

static SWC_IPC_CanRepeaterObject SWC_IPC__CANRepeaterObject = {0};

#define SWC_IPC_NW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                   					  *
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

static void IPC_CanRepeaterObjectInit(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_CanDataBufferInit(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_CanNvmBlockInit(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_ComBusStateUpdate(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_CanAttributeCheck(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_CanNvmBlockPeriodicUpdate(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_CanMsgPeriodicUpdate(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_CanSignalPeriodicUpdate(SWC_IPC_CanRepeaterObject * const Object);

static void IPC_SingleRxCanMsgUpload(const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object);

static void IPC_SingleRxCanMsgRefresh(uint32 MsgIndex, SWC_IPC_CanRepeaterObject * const Object);

#if 0
static void IPC_TxCanMsgDownloadRequest(const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object);

static void IPC_TxCanMsgDownload(uint8 * const Data, const uint16 Length,SWC_IPC_CanRepeaterObject * const Object);
#endif
static void IPC_RxCanMsgUploadRequest(uint8 * const Data, const uint16 Length,SWC_IPC_CanRepeaterObject * const Object);

static void IPC_SingleTxCanMsgDownload(const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object);

static void IPC_TxCanSignalDownload(uint8 * const Data, const uint16 Length, SWC_IPC_CanRepeaterObject * const Object);

static void IPC_TxCanSignalCallbackRequest(uint8 * const Data, const uint16 Length, SWC_IPC_CanRepeaterObject * const Object);

static void IPC_E2eTxCanMsgDownLoad(const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object);

static void IPC_EventTxCanSignalDownload(const uint32 SignalIndex, const uint8 * const Data ,SWC_IPC_CanRepeaterObject * const Object);

static void IPC_MsgValidMaskOperation(const uint32 MsgIndex, uint8 * const Data, SWC_IPC_CanRepeaterObject * const Object);

static void IPC_PackCanSignalToMsg(uint8 * const MsgData, const uint8 * const SignalData, const SWC_IPC_CanSignalAttribute * const SignalAttribute);

static void IPC_ParseCanSignalFromMsg(const uint8 * const MsgData, uint8 * const SignalData, const SWC_IPC_CanSignalAttribute * const SignalAttribute);

static void IPC_ConvertEndian(const uint8 * const RawData ,uint8 * const Data, const uint8 ByteLength);

static void IPC_RepeatTxCanSignal( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object);

static void IPC_TriggerTxCanSignalCallback( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object );

static void IPC_UploadTxSignalCallback( const uint32 SignalIndex ,SWC_IPC_CanRepeaterObject * const Object );

static void IPC_SetEventTxCanSignalBuffer(const uint32 SignalIndex, const uint8 * const Data ,SWC_IPC_CanRepeaterObject * const Object);

static void IPC_SetTxCanSignalCallbackLock( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object );

static void IPC_ClrTxCanSignalCallbackLock( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object );

static boolean IPC_GetTxCanSignalCallbackLock( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object );

/**********************************************************************************************************
*Function   : IPC_CanRepeaterInit                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
void IPC_CanRepeaterInit(void)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;

	IPC_CanRepeaterObjectInit(Object);

	IPC_CanNvmBlockInit(Object);

	IPC_CanDataBufferInit(Object);
#ifdef SWC_IPC_DEBUG

  IPC_CanAttributeCheck(Object);

#endif

	IPC_API_RepeatCanMsg(SWC_IPC_MCU2SOC, SWC_IPC_NONE);
}

/**********************************************************************************************************
*Function   : IPC_CanRepeaterTask                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
void IPC_CanRepeaterTask(void)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;

	IPC_ComBusStateUpdate(Object);

	IPC_CanMsgPeriodicUpdate(Object);

	IPC_CanSignalPeriodicUpdate(Object);

	IPC_CanNvmBlockPeriodicUpdate(Object);

    #ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)IPC_API_TxCanMsgCallback_HUT_IP2_E2E();
	(void)IPC_API_TxCanMsgCallback_HUT32_E2E();
    #endif

	#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)  || \
		(defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
	IPC_API_TxCanMsgCallback_DMS_FD1_E2E();
    #endif

}
/**********************************************************************************************************
*Function   : IPC_CanRepeaterObjectInit                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * const Object                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-31                                                                                  *
**********************************************************************************************************/
static void IPC_CanRepeaterObjectInit(SWC_IPC_CanRepeaterObject * const Object)
{
	/*Clear object ram data.*/
	(void)memset(Object,0,sizeof(SWC_IPC_CanRepeaterObject));

	/*Nvm size*/
	Object->NvmBlockSize = (uint8)SWC_IPC_MIN(sizeof(SWC_IPC_CanDataNvmBlock),SWC_IPC_CAN_REPEATER_NVM_SIZE);

	/*Message*/
	Object->CanMsgTotalNumber = (uint32)SWC_IPC_CAN_MSG_TOTAL_NUMBER;
	Object->CanMsgAttribute = (SWC_IPC_CanMsgAttribute*)SWC_IPC__CanMsgAttributeTable;

	Object->ConstMsgBuffer = (uint8*)SWC_IPC__CanMsgConstTable;
	/*Signal*/
	Object->TxCanSignalTotalNumber =(uint32)SWC_IPC_TX_CAN_SIGNAL_TOTAL_NUMBER;
	Object->TxCanSignalAttribute = (SWC_IPC_CanSignalAttribute*)SWC_IPC__TxCanSignalAttributeTable;

	Object->EventTxCanSignalTotalNumber = (uint32)SWC_IPC_EVENT_TX_CAN_SIGNAL_TOTAL_NUMBER;
	Object->EventTxCanSignalMappingTable = (uint16*)&SWC_IPC__EventTxCanSignalMappingTable;

	Object->RxCanSignalTotalNumber =(uint32)SWC_IPC_RX_CAN_SIGNAL_TOTAL_NUMBER;
	Object->RxCanSignalAttribute =(SWC_IPC_CanSignalAttribute*)SWC_IPC__RxCanSignalAttributeTable;

	/*Tx Signal Tick*/
	Object->SignalTxUpdateTick = 0;
}

/**********************************************************************************************************
*Function   : IPC_CanNvmBlockInit                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * const Object                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-16                                                                                  *
**********************************************************************************************************/
static void IPC_CanNvmBlockInit(SWC_IPC_CanRepeaterObject * const Object)
{
	Object->NvmUpdateSwitch = FALSE;

	(void)memcpy((void *)(&(Object->CanNvm)),
	       (void *)Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock(),
	       sizeof(SWC_IPC_CanDataNvmBlock));

	if (Object->CanNvm.NvmVersion != SWC_IPC_CAN_DATA_NVM_VERSION)
	{
		SWC_IPC_PRINT_WARNING("Can nvm block last version: %d , current version: %d. Version updated! Restore can nvm block!",
			                  Object->CanNvm.NvmVersion,SWC_IPC_CAN_DATA_NVM_VERSION );

		/*Clear nvm data pool*/
		(void)memset(&Object->CanNvm,0,sizeof(SWC_IPC_CanDataNvmBlock));

		Object->CanNvm.NvmVersion = SWC_IPC_CAN_DATA_NVM_VERSION;

        IPC_API_RestoreNvmTxCanSignal();

		(void)memcpy((void *)Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock(),
			   (void *)(&(Object->CanNvm)),
			   sizeof(SWC_IPC_CanDataNvmBlock));

		if(E_OK != Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(NULL_PTR))
		{
			/*Clear mirror buffer*/
			(void)memset(Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock(),0,sizeof(SWC_IPC_CanDataNvmBlock));

			SWC_IPC_PRINT_ERROR("Can nvm mirror block update failed!");
		}
		else
		{
			SWC_IPC_PRINT_WARNING("Can nvm mirror block update success!");
		}
	}
	else
	{
		SWC_IPC_PRINT_WARNING("Can nvm block init success , version:%d",Object->CanNvm.NvmVersion);
	}

	Object->NvmUpdateSwitch = TRUE;
}
/**********************************************************************************************************
*Function   : IPC_CanDataBufferInit                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * const Object                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
static void IPC_CanDataBufferInit(SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 Index = 0;

	/*Buffer pool init*/
	(void)memset(Object->MsgBuffer,0,sizeof(Object->MsgBuffer));

	/*Set default value , Only copy transmit message buffer*/
	for(Index = 0 ; Index < Object->CanMsgTotalNumber ; ++Index)
	{
		/* Rx status */
		if(SWC_IPC_MCU2SOC & Object->CanMsgAttribute[Index].Direction)
		{
			Object->MsgBuffer[SWC_IPC_CAN_MSG_STATUS_BUFFER_START + Index] = RTE_E_NEVER_RECEIVED;
		}

		/* Tx buffer */
		if(SWC_IPC_SOC2MCU & Object->CanMsgAttribute[Index].Direction)
		{
			(void)memcpy(&Object->MsgBuffer[Object->CanMsgAttribute[Index].Offset],
				   &Object->ConstMsgBuffer[Object->CanMsgAttribute[Index].Offset],
				   Object->CanMsgAttribute[Index].Length);
		}
	}

	/*Set tick init value*/
	for(Index = 0 ; Index < Object->CanMsgTotalNumber ; ++Index)
	{
		Object->CanMsgStatus[Index].u16Tick = \
				(uint16)Object->CanMsgAttribute[Index].Priority + Object->CanMsgAttribute[Index].Cycle;
	}

	/*Set Tx signal default value from Nvm shardow area*/
	for(Index = 0 ; Index < Object->TxCanSignalTotalNumber ; ++Index)
	{
		if(Object->TxCanSignalAttribute[Index].NvmOffset < ((uint16)SWC_IPC_NVM_CAN_SIGNAL_DATA_BUFFER_LENGTH))
		{
			IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[Object->TxCanSignalAttribute[Index].MsgId].Offset],
		                           &Object->CanNvm.Data[Object->TxCanSignalAttribute[Index].NvmOffset],
		                           &Object->TxCanSignalAttribute[Index]);

			/* Cyclic signal need call com interface to modify default buffer . */
			if(SWC_IPC_EVENT_TX_CAN_SIGNAL_NULL_INDEX == Object->TxCanSignalAttribute[Index].EventId)
			{
				IPC_RepeatTxCanSignal(Index,Object);
			}
			else
			{
				/* Event signal need to fill com buffer but do not trigger. */
				/* Avoid bringing out the event signals that need to be sent in the comwakephase2 during the comwakephase1 when wake-up */
				IPC_SetEventTxCanSignalBuffer(Index, &Object->CanNvm.Data[Object->TxCanSignalAttribute[Index].NvmOffset], Object);
			}
		}
	}

#ifdef SWC_IPC_DEBUG
	Object->MsgBuffer[(uint8)SWC_IPC_CAN_MSG_DATA_BUFFER_LENGTH] = (uint8)SWC_IPC_DEBUG_PILE;
#endif
}

/**********************************************************************************************************
*Function   : IPC_CanAttributeCheck                                                                       *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * const Object                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2021-01-27                                                                                  *
**********************************************************************************************************/
#ifdef SWC_IPC_DEBUG
static void IPC_CanAttributeCheck(SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 Index ;

	if(Object->CanMsgTotalNumber > 0)
	{
		if( SWC_IPC_NULL != Object->CanMsgAttribute )
		{
			for(Index = 0; Index < Object->CanMsgTotalNumber; Index ++)
		    {
				if( 0 == Object->CanMsgAttribute[Index].FrameId)
				{
					SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute[%d].FrameId = 0 !!!",Index);
				}
				/*��׼֡Ѱַ����Ϊ11bit*/
				else if(0x7FF < Object->CanMsgAttribute[Index].FrameId)
				{
					SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute[%d].FrameId is invalid !!!",Index);
				}
				else
				{

				}

				if( 0 == Object->CanMsgAttribute[Index].Length)
				{
					SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute[%d].Length = 0 !!!",Index);
				}
				else if( 64 < Object->CanMsgAttribute[Index].Length)
				{
					SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute[%d].Length is over size !!!",Index);
				}
				else
				{

				}

				if( 0 == Object->CanMsgAttribute[Index].Cycle)
				{
					SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute[%d].Cycle = 0 !!!",Index);
				}

				if(( SWC_IPC_MCU2SOC != Object->CanMsgAttribute[Index].Direction)
				 &&( SWC_IPC_SOC2MCU != Object->CanMsgAttribute[Index].Direction))
				{
					SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute[%d].Direction is invalid !!!",Index);
				}

				#ifdef SWC_IPC_PROJECT_TYPE_B03
				if( SWC_IPC_NULL == Object->CanMsgAttribute[Index].RteIf)
				{
					SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute[%d].RteIf = NULL !!!",Index);
				}
				#endif
		    }
		}
		else
		{
			SWC_IPC_PRINT_ERROR("Object->CanMsgAttribute = NULL !!!");
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Object->CanMsgTotalNumber = 0 !!!");
	}

	if(Object->TxCanSignalTotalNumber > 0 )
	{
		if( SWC_IPC_NULL != Object->TxCanSignalAttribute )
		{
			for(Index = 0; Index < Object->TxCanSignalTotalNumber; Index ++)
			{
				if( Object->CanMsgTotalNumber <= Object->TxCanSignalAttribute[Index].MsgId)
				{
					SWC_IPC_PRINT_ERROR("Object->TxCanSignalAttribute[%d].MsgId is invalid !!!",Index);
				}
			}
		}
		else
		{
			SWC_IPC_PRINT_ERROR("Object->TxCanSignalAttribute = NULL !!!");
		}
	}

	if(Object->EventTxCanSignalTotalNumber > 0 )
	{
		if( SWC_IPC_NULL != Object->TxCanSignalAttribute )
		{
			for(Index = 0; Index < Object->TxCanSignalTotalNumber; Index ++)
		    {
				if(( Object->EventTxCanSignalTotalNumber <= Object->TxCanSignalAttribute[Index].EventId)
				 &&(Object->TxCanSignalAttribute[Index].EventId != SWC_IPC_EVENT_TX_CAN_SIGNAL_NULL_INDEX))
				{
					SWC_IPC_PRINT_ERROR("Object->TxCanSignalAttribute[%d].EventId is invalid !!!",Index);
				}
		    }
		}
		else
		{
			SWC_IPC_PRINT_ERROR("Object->TxCanSignalAttribute = NULL !!!");
		}
	}

	if( SWC_IPC_NULL == Object->EventTxCanSignalMappingTable  )
	{
		SWC_IPC_PRINT_ERROR("Object->EventTxCanSignalMappingTable = NULL !!!");
	}
}
#endif
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
static void IPC_ComBusStateUpdate(SWC_IPC_CanRepeaterObject * const Object)
{
	uint8 CanComMode ;

	/*Ipc bus*/
	if(IPC_CONN_READY == IPC_GetIPCStateType())
	{
		if(FALSE == Object->IpcBusState)
		{
			/*Ipc bus from abnormal switch to normal , upload all msg!*/
			IPC_API_RepeatCanMsg(SWC_IPC_MCU2SOC, SWC_IPC_NONE);;

			SWC_IPC_PRINT_WARNING("Ipc driver state is connected!");
		}
		Object->IpcBusState = TRUE ;
	}
	else
	{
#ifdef SWC_IPC_DEBUG
		if(FALSE != Object->IpcBusState)
		{
			SWC_IPC_PRINT_ERROR("Ipc driver state is disconnected!");
		}
#endif
		Object->IpcBusState = FALSE ;
	}

	/*Can bus*/
	if(E_OK == Rte_Call_ComM_UserRequest_GetCurrentComMode(&CanComMode))
	{
		if(COMM_FULL_COMMUNICATION == CanComMode)
		{
	#ifdef SWC_IPC_DEBUG
			if(FALSE == Object->CanBusState)
			{
				SWC_IPC_PRINT_WARNING("Com manager state in full commnucation mode!");
			}
	#endif
			Object->CanBusState = TRUE ;
		}
		else
		{
		#ifdef SWC_IPC_DEBUG
			if(FALSE != Object->CanBusState)
			{
				if(COMM_SILENT_COMMUNICATION == CanComMode)
				{
					SWC_IPC_PRINT_WARNING("Com manager state in silent commnucation mode!");
				}
				else if(COMM_NO_COMMUNICATION == CanComMode)
				{
					SWC_IPC_PRINT_WARNING("Com manager state in no commnucation mode!");
				}
				else
				{
					SWC_IPC_PRINT_ERROR("Com manager state in error mode!");
				}
			}
		#endif
			Object->CanBusState = FALSE ;
		}
	}
}

/**********************************************************************************************************
*Function   : IPC_CanNvmBlockPeriodicUpdate                                                               *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * const Object                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-16                                                                                  *
**********************************************************************************************************/
static void IPC_CanNvmBlockPeriodicUpdate(SWC_IPC_CanRepeaterObject * const Object)
{
	NvM_RequestResultType NvmErrorStatus = NVM_REQ_OK;

	if(FALSE != Object->NvmUpdateSwitch )
	{
		if (E_OK == Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_GetErrorStatus(&NvmErrorStatus))
		{
			if (NvmErrorStatus != NVM_REQ_PENDING)
			{
				/*Avoid ipc driver cdd interrupt.*/
				Rte_Enter_ExclusiveArea();

				if (FALSE != memcmp(Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock(),
					                &(Object->CanNvm),
					                sizeof(SWC_IPC_CanDataNvmBlock)))
				{
					(void)memcpy((void*)Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock(),
						   (void*)(&(Object->CanNvm)),
						   sizeof(SWC_IPC_CanDataNvmBlock));

					Rte_Exit_ExclusiveArea();

					if(E_OK != Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(NULL_PTR))
					{
						/*Clear mirror buffer*/
						(void)memset(Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock(),0,sizeof(SWC_IPC_CanDataNvmBlock));

						SWC_IPC_PRINT_ERROR("Can nvm mirror block update failed!");
					}
					else
					{
						SWC_IPC_PRINT_WARNING("Can nvm mirror block update success!");
					}
				}
				else
				{
					Rte_Exit_ExclusiveArea();
				}
			}
		}
	}
}
/**********************************************************************************************************
*Function   : IPC_API_ControlCanNvmSwitch                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const boolean Switch                                                                          *
*                                                                                                         *
*Return     : boolean                                                                                       *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-03                                                                                  *
**********************************************************************************************************/
boolean IPC_API_ControlCanNvmSwitch( const boolean Switch )
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	NvM_RequestResultType NvmErrorStatus = NVM_REQ_OK;
	boolean ReturnSwitch = Switch;

	if(Object->NvmUpdateSwitch != Switch)
	{
		/*On -> Off */
		if( FALSE == Switch )
		{
			if (RTE_E_OK == Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_GetErrorStatus(&NvmErrorStatus))
			{
				if (NvmErrorStatus != NVM_REQ_PENDING)
				{
					ReturnSwitch = FALSE;
					Object->NvmUpdateSwitch = FALSE;
					SWC_IPC_PRINT_WARNING("Can nvm block update switch off!");
				}
				else
				{
					ReturnSwitch = TRUE;
				}
			}
			else
			{
				ReturnSwitch = TRUE;
			}
		}
		/*Off -> On */
		else
		{
			ReturnSwitch = TRUE;
			Object->NvmUpdateSwitch = TRUE;
			SWC_IPC_PRINT_WARNING("Can nvm block update switch on!");
		}
	}
	else
	{
		ReturnSwitch = Object->NvmUpdateSwitch;
	}
	return ReturnSwitch;
}

/**********************************************************************************************************
*Function   : IPC_CanMsgPeriodicUpdate                                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * const Object                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
static void IPC_CanMsgPeriodicUpdate(SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 Index = 0;

	for(Index = 0 ; Index < Object->CanMsgTotalNumber ; ++Index)
	{
		if(Object->CanMsgStatus[Index].u16Tick <= Object->CanMsgAttribute[Index].Priority)
		{
			if(SWC_IPC_MCU2SOC & Object->CanMsgAttribute[Index].Direction)
			{
				if( FALSE != Object->IpcBusState )
				{
					IPC_SingleRxCanMsgUpload(Index,Object);
				}
				else
				{
					IPC_SingleRxCanMsgRefresh(Index,Object);
				}
			}

			#if 0
			if(SWC_IPC_SOC2MCU & Object->CanMsgAttribute[Index].Direction)
			{
				/*E2E Msg call in tx hook*/
				//IPC_E2eTxCanMsgDownLoad(Index,Object);

				if( IPC_CONN_READY == BusState )
				{
					//IPC_TxCanMsgDownloadRequest(Index,Object);
				}
			}
			#endif

			Object->CanMsgStatus[Index].u16Tick  = \
				(uint16)Object->CanMsgAttribute[Index].Priority + Object->CanMsgAttribute[Index].Cycle;
		}
		else
		{
			Object->CanMsgStatus[Index].u16Tick -= 1;
		}
	}
}
/**********************************************************************************************************
*Function   : IPC_CanMsgPeriodicUpdate                                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : SWC_IPC_CanRepeaterObject * const Object                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
static void IPC_CanSignalPeriodicUpdate(SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 SignalIndex = 0 , MsgIndex = 0 ;
	uint8 SignalData[64]= {0};

#define IPC_TX_SIGNAL_UPDATE_CYCLE (10u/SWC_IPC_CAN_REPEATER_TASK_CYCLE)

	if (Object->SignalTxUpdateTick == 0)
	{
		/*Set Tx Signal Buffer*/
		for(SignalIndex = 0 ; SignalIndex < Object->TxCanSignalTotalNumber ; ++SignalIndex)
		{
			/*Set buffer*/
			if(FALSE != Object->TxCanSignalStatus[SignalIndex].SetBuffer)
			{
				MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;
				/*Call output interface */
				if(Object->TxCanSignalAttribute[SignalIndex].EventId < Object->EventTxCanSignalTotalNumber)
				{
					/*Parse signal from local message buffer */
					IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset] ,
											SignalData,
											&Object->TxCanSignalAttribute[SignalIndex]);
					IPC_SetEventTxCanSignalBuffer(SignalIndex,SignalData,Object);
				}
				else
				{
					if(FALSE == Object->CanMsgAttribute[MsgIndex].E2E)
					{
						IPC_SingleTxCanMsgDownload(MsgIndex,Object);
					}

				}
				/*Clear repeat flag*/
				Object->TxCanSignalStatus[SignalIndex].SetBuffer = FALSE;
			}
		}

		/*Tx Signal*/
		for(SignalIndex = 0 ; SignalIndex < Object->TxCanSignalTotalNumber ; ++SignalIndex)
		{
			/*Tx repeat*/
			if(FALSE != Object->TxCanSignalStatus[SignalIndex].DataRepeat)
			{
				MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;

				/*Call output interface */
				if(Object->TxCanSignalAttribute[SignalIndex].EventId < Object->EventTxCanSignalTotalNumber)
				{
					/*Parse signal from local message buffer */
					IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset] ,
											SignalData,
											&Object->TxCanSignalAttribute[SignalIndex]);

					IPC_EventTxCanSignalDownload(SignalIndex,SignalData,Object);
				}
				else
				{
					SWC_IPC_PRINT_INFO("[CTX][CONVERT][%X->%X]",
									Object->TxCanSignalAttribute[SignalIndex].SignalId,
									Object->CanMsgAttribute[MsgIndex].FrameId);

					if(FALSE == Object->CanMsgAttribute[MsgIndex].E2E)
					{
						IPC_SingleTxCanMsgDownload(MsgIndex,Object);
					}

					/*Clear repeat flag*/
					Object->TxCanSignalStatus[SignalIndex].DataRepeat = FALSE;

					if(Object->IpcBusState != FALSE)
					{
						IPC_TriggerTxCanSignalCallback(SignalIndex,Object);
					}
				}
			}

			/*Tx callback*/
			/*Check bus state*/
			if((FALSE != Object->CanBusState)&&(FALSE != Object->IpcBusState))
			{
				if(FALSE != Object->TxCanSignalStatus[SignalIndex].TxCallback)
				{
					IPC_UploadTxSignalCallback(SignalIndex,Object);
				}
			}
		}
		Object->SignalTxUpdateTick = IPC_TX_SIGNAL_UPDATE_CYCLE;
	}
	else
	{
		Object->SignalTxUpdateTick --;
	}
}

/**********************************************************************************************************
*Function   : IPC_SingleRxCanMsgUpload                                                                    *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
static void IPC_SingleRxCanMsgUpload(const uint32 MsgIndex, SWC_IPC_CanRepeaterObject * const Object)
{
	IPC_M2S_CANMessageReceive_t MsgBuffer;
	IPC_M2S_CANMessageStatus_t MsgStatus;
	boolean SendMsgBuffer ;
	boolean SendMsgStatus ;
	#ifndef SWC_IPC_PROJECT_TYPE_B03
	uint8 PayloadLength = 0;
	#endif

	#ifdef SWC_IPC_PROJECT_TYPE_B03
	if(SWC_IPC_NULL != Object->CanMsgAttribute[MsgIndex].RteIf)
	{
	#endif
		/*Init temporary variable value .*/
		MsgBuffer.FrameId = Object->CanMsgAttribute[MsgIndex].FrameId;
		MsgBuffer.DataLength = Object->CanMsgAttribute[MsgIndex].Length;
		MsgStatus.FrameId = Object->CanMsgAttribute[MsgIndex].FrameId;
		MsgStatus.Status = 0;
		(void)memset(MsgBuffer.Data,0,sizeof(MsgBuffer.Data));

		/*Get CAN message data from RTE interface .*/
		#ifndef SWC_IPC_PROJECT_TYPE_B03
		/* The length of the SecOc signal needs to be subtracted 8 bytes */
		if (FALSE != Object->CanMsgAttribute[MsgIndex].SecOc)
		{
			PayloadLength = (uint8)MsgBuffer.DataLength - (uint8)8;
		}
		else
		{
			PayloadLength = (uint8)MsgBuffer.DataLength;
		}
		MsgStatus.Status = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(Object->CanMsgAttribute[MsgIndex].SignalId,
																	   (uint8 *)&MsgBuffer.Data[0], PayloadLength);
        if ((RTE_E_ComEx_COMEX_UPDATE_RECEIVED == MsgStatus.Status) || (RTE_E_ComEx_E_OK == MsgStatus.Status))
        {
            MsgStatus.Status = RTE_E_OK;
        }
        else if (RTE_E_ComEx_COMEX_NEVER_RECEIVED == MsgStatus.Status)
        {
            MsgStatus.Status = RTE_E_NEVER_RECEIVED;
        }
        else if (RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED == MsgStatus.Status)
        {
            MsgStatus.Status = RTE_E_MAX_AGE_EXCEEDED;
        }
        else
        {
            MsgStatus.Status = RTE_E_NEVER_RECEIVED;
        }

		#else
		MsgStatus.Status = Object->CanMsgAttribute[MsgIndex].RteIf(MsgBuffer.Data);
		#endif
		IPC_MsgValidMaskOperation(MsgIndex,MsgBuffer.Data,Object);

		/*Compare message buffer , when data buffer is changed or last is send faild , then send new message to SOC .*/
		if((FALSE != memcmp(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
							MsgBuffer.Data,
							Object->CanMsgAttribute[MsgIndex].Length))
		 || (FALSE != Object->CanMsgStatus[MsgIndex].DataRepeat))
		{
			/*Copy message update data to static buffer*/
			(void)memcpy(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				   MsgBuffer.Data,
				   Object->CanMsgAttribute[MsgIndex].Length);

			SendMsgBuffer = TRUE;
		}
		else
		{
			/*Copy message update data from static buffer*/
			(void)memcpy(MsgBuffer.Data,
				   &Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				   Object->CanMsgAttribute[MsgIndex].Length);

			SendMsgBuffer = FALSE;
		}

		/*Compare status , when status is changed or last send is faild , then send new message to SOC .*/
		if((MsgStatus.Status != Object->MsgBuffer[SWC_IPC_CAN_MSG_STATUS_BUFFER_START + MsgIndex])
		 ||(FALSE != Object->CanMsgStatus[MsgIndex].StatusRepeat))
		{
			if (MsgStatus.Status != Object->MsgBuffer[SWC_IPC_CAN_MSG_STATUS_BUFFER_START + MsgIndex])
			{
				Object->CanMsgStatus[MsgIndex].StatusChanged = TRUE;
			}
			else
			{
				/* Do nothing */
			}

			Object->MsgBuffer[SWC_IPC_CAN_MSG_STATUS_BUFFER_START + MsgIndex] = MsgStatus.Status;

			SendMsgStatus = TRUE;
		}
		else
		{
			SendMsgStatus = FALSE;
		}

		/*This part deal with priority between data and status . */
		if(FALSE != SendMsgStatus)
		{
			/*Current status is not OK , send status first .*/
			if( RTE_E_OK != MsgStatus.Status )
			{
				if(IPC_ERR_NONE != IPC_M2S_CANMessageStatus_Transmit(&MsgStatus))
				{
					Object->CanMsgStatus[MsgIndex].StatusRepeat = TRUE;

					//SWC_IPC_PRINT_ERROR("[CRX][MSG-STAT-UP][FAILD][%X=%d]",MsgStatus.FrameId,MsgStatus.Status);
				}
				else
				{
					Object->CanMsgStatus[MsgIndex].StatusRepeat = FALSE;

					SWC_IPC_PRINT_WARNING("[CRX][MSG-STAT-UP][OK][%X=%d]",MsgStatus.FrameId,MsgStatus.Status);

					if (FALSE != Object->CanMsgStatus[MsgIndex].StatusChanged)
					{
						(void)SWC_IPC_PRINT_DEBUG("[MSG][OK][CANID:0x%X=%d]",MsgStatus.FrameId,MsgStatus.Status);
						Object->CanMsgStatus[MsgIndex].StatusChanged = FALSE;
					}
				}
				/*Send status only once in one time . */
				SendMsgStatus = FALSE;
				/*When status is not OK , do not send msg buffer even data is changed*/
				SendMsgBuffer = FALSE;
				Object->CanMsgStatus[MsgIndex].DataRepeat = FALSE;
			}
			else
			{
				/*Send msg buffer because status is change to OK. */
				SendMsgBuffer = TRUE;
			}
		}

		if(FALSE != SendMsgBuffer)
		{
			if(IPC_ERR_NONE != IPC_M2S_CANMessageReceive_Transmit(&MsgBuffer))
			{
				Object->CanMsgStatus[MsgIndex].DataRepeat = TRUE;

				//SWC_IPC_PRINT_ERROR("[CRX][MSG-BUF-UP][FAILD][%X]",MsgBuffer.FrameId);
			}
			else
			{
				Object->CanMsgStatus[MsgIndex].DataRepeat = FALSE;

                          	#ifdef SWC_IPC_CAN_BUFFER_VERBOSE_PRINT_SWITCH

				(void)SWC_IPC_PRINT_VERBOSE("[CRX][MSG-BUF-UP][OK][%X]", MsgBuffer.FrameId);
				IPC_API_PrintDataArrayLog(MsgBuffer.Data , MsgBuffer.DataLength);

				#endif
			}

		}

		if(FALSE != SendMsgStatus)
		{
			if(IPC_ERR_NONE != IPC_M2S_CANMessageStatus_Transmit(&MsgStatus))
			{
				Object->CanMsgStatus[MsgIndex].StatusRepeat = TRUE;

				//SWC_IPC_PRINT_ERROR("[CRX][MSG-STAT-UP][FAILD][%X=%d]",MsgStatus.FrameId,MsgStatus.Status);
			}
			else
			{
				Object->CanMsgStatus[MsgIndex].StatusRepeat = FALSE;

				SWC_IPC_PRINT_INFO("[CRX][MSG-STAT-UP][OK][%X=%d]",MsgStatus.FrameId,MsgStatus.Status);

				if (FALSE != Object->CanMsgStatus[MsgIndex].StatusChanged)
				{
					(void)SWC_IPC_PRINT_DEBUG("[MSG][OK][CANID:0x%X=%d]",MsgStatus.FrameId,MsgStatus.Status);
					Object->CanMsgStatus[MsgIndex].StatusChanged = FALSE;
				}
			}
		}
	#ifdef SWC_IPC_PROJECT_TYPE_B03
	}
	#endif
}
/**********************************************************************************************************
*Function   : IPC_SingleRxCanMsgRefresh                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
static void IPC_SingleRxCanMsgRefresh(uint32 MsgIndex, SWC_IPC_CanRepeaterObject * const Object)
{
	uint8 MsgStatus = RTE_E_INVALID;
	uint8 MsgBuffer[64] = {0};
	#ifndef SWC_IPC_PROJECT_TYPE_B03
	uint8 PayloadLength = 0;
	#endif

	#ifdef SWC_IPC_PROJECT_TYPE_B03
	if(SWC_IPC_NULL != Object->CanMsgAttribute[MsgIndex].RteIf)
	{
	#endif
		/*Get CAN message data from RTE interface .*/
		#ifndef SWC_IPC_PROJECT_TYPE_B03
		/* The length of the SecOc signal needs to be subtracted 8 bytes */
		if (FALSE != Object->CanMsgAttribute[MsgIndex].SecOc)
		{
			PayloadLength = Object->CanMsgAttribute[MsgIndex].Length - (uint8)8;
		}
		else
		{
			PayloadLength = Object->CanMsgAttribute[MsgIndex].Length;
		}
		MsgStatus = Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(Object->CanMsgAttribute[MsgIndex].SignalId,
																	   (uint8 *)&MsgBuffer[0], PayloadLength);
        if ((RTE_E_ComEx_COMEX_UPDATE_RECEIVED == MsgStatus) || (RTE_E_ComEx_E_OK == MsgStatus))
        {
            MsgStatus = RTE_E_OK;
        }
        else if (RTE_E_ComEx_COMEX_NEVER_RECEIVED == MsgStatus)
        {
            MsgStatus = RTE_E_NEVER_RECEIVED;
        }
        else if (RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED == MsgStatus)
        {
            MsgStatus = RTE_E_MAX_AGE_EXCEEDED;
        }
        else
        {
            MsgStatus = RTE_E_NEVER_RECEIVED;
        }
		#else
		MsgStatus = Object->CanMsgAttribute[MsgIndex].RteIf(MsgBuffer);
		#endif
		IPC_MsgValidMaskOperation(MsgIndex,MsgBuffer,Object);

	#ifdef SWC_IPC_PROJECT_TYPE_B03
	}
	#endif

	/*Compare message buffer , when data buffer is changed , refresh buffer and set repeat flag .*/
	if(FALSE != memcmp(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
						MsgBuffer,
						Object->CanMsgAttribute[MsgIndex].Length))
	{
		/*Copy message update data to static buffer*/
		(void)memcpy(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
			   MsgBuffer,
			   Object->CanMsgAttribute[MsgIndex].Length);

		Object->CanMsgStatus[MsgIndex].DataRepeat = TRUE;
	}

	/*Compare status , when status is changed , refresh buffer and set repeat flag .*/
	if(MsgStatus != Object->MsgBuffer[SWC_IPC_CAN_MSG_STATUS_BUFFER_START + MsgIndex])
	{
		Object->MsgBuffer[SWC_IPC_CAN_MSG_STATUS_BUFFER_START + MsgIndex] = MsgStatus;

		Object->CanMsgStatus[MsgIndex].StatusRepeat = TRUE;
		Object->CanMsgStatus[MsgIndex].StatusChanged = TRUE;
	}
}

/**********************************************************************************************************
*Function   : IPC_MsgValidMaskOperation                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 MsgIndex, uint8 * const Data, SWC_IPC_CanRepeaterObject * const Object         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-21                                                                                  *
**********************************************************************************************************/
static void IPC_MsgValidMaskOperation(const uint32 MsgIndex, uint8 * const Data, SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 Index = 0;

	for(Index = 0 ; Index < Object->CanMsgAttribute[MsgIndex].Length ; ++Index)
	{
		Data[Index] &= Object->ConstMsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset + Index];
	}
}
/**********************************************************************************************************
*Function   : IPC_TxCanMsgDownloadRequest                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object                              *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
#if 0
static void IPC_TxCanMsgDownloadRequest(const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object)
{
	IPC_M2S_CANMessageRequest_t MsgBuffer;

	if(Object->CanMsgStatus[MsgIndex].DataRepeat)
	{
		/*Init temporary variable value .*/
		MsgBuffer.FrameId = Object->CanMsgAttribute[MsgIndex].FrameId;

		if(IPC_ERR_NONE == IPC_M2S_CANMessageRequest_Transmit(&MsgBuffer))
		{
			Object->CanMsgStatus[MsgIndex].DataRepeat = FALSE;
		}
	}
}
#endif
/**********************************************************************************************************
*Function   : IPC_CanMsgReceiveCallBack                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
void IPC_API_CanMsgReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject ;

	switch(MajorId)
	{
		case IPC_S2M_CAN_MSGMAJOR_MESSAGE_ID:
		{
			switch(SubId)
			{
				#if 0
				case IPC_S2M_CAN_MESSAGE_MSGSUB_TRANSMIT_ID:
				{
					IPC_TxCanMsgDownload(Data,Length,Object);
					break;
				}
				#endif
				case IPC_S2M_CAN_MESSAGE_MSGSUB_REQUEST_ID:
				{
					IPC_RxCanMsgUploadRequest(Data,Length,Object);
					break;
				}
				default:
				{
					/* do nothing */
					break;
				}
			}
			break;
		}
		case IPC_S2M_CAN_MSGMAJOR_SIGNAL_ID:
		{
			switch(SubId)
			{
				case IPC_S2M_CAN_SIGNAL_MSGSUB_TRANSMIT_ID:
				{
					IPC_TxCanSignalDownload(Data,Length,Object);
					break;
				}
				case IPC_S2M_CAN_SIGNAL_MSGSUB_REQUEST_ID:
				{
					IPC_TxCanSignalCallbackRequest(Data,Length,Object);
					break;
				}
				default:
				{
					/* do nothing */
					break;
				}
			}
			break;
		}
		default:
		{
			/* do nothing */
			break;
		}
	}
}
/**********************************************************************************************************
*Function   : IPC_TxCanMsgDownload                                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 * const Data, const uint16 Length,SWC_IPC_CanRepeaterObject * const Object            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
#if 0
static void IPC_TxCanMsgDownload(uint8 * const Data, const uint16 Length,SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 Index = 0;
	IPC_S2M_CANMessageTransmit_t MsgBuffer;

	/*Parse by ipc interface*/
	IPC_S2M_CANMessageTransmit_Receive(Data,&MsgBuffer,Length);

	for(Index = 0 ; Index < Object->CanMsgTotalNumber ; ++Index)
	{
		if((SWC_IPC_SOC2MCU & Object->CanMsgAttribute[Index].Direction) \
		&& ((Object->CanMsgAttribute[Index].FrameId == MsgBuffer.FrameId)))
		{
			/*Check message length , abandon when message length error.*/
			if(MsgBuffer.DataLength <= Object->CanMsgAttribute[Index].Length)
			{
				/*Compare message buffer , when data buffer is changed or message is event ,
				  then send new message use rte interface .*/
				if((FALSE != memcmp(&Object->MsgBuffer[Object->CanMsgAttribute[Index].Offset],
									MsgBuffer.Data,
									MsgBuffer.DataLength))
				 || (FALSE != Object->CanMsgAttribute[Index].Event)
				 || (FALSE != Object->CanMsgStatus[Index].DataRepeat))
				{
					/*Copy message update data to static buffer*/
					(void)memcpy(&Object->MsgBuffer[Object->CanMsgAttribute[Index].Offset],
						   MsgBuffer.Data,
						   MsgBuffer.DataLength);

					if(FALSE == Object->CanMsgAttribute[Index].E2E)
					{
						IPC_SingleTxCanMsgDownload(Index,Object);
					}
				}
			}
			break;
		}
	}
}
#endif
/**********************************************************************************************************
*Function   : IPC_TxCanSignalDownload                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 * const Data, const uint16 Length, SWC_IPC_CanRepeaterObject * const Object           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-25                                                                                  *
**********************************************************************************************************/
static void IPC_TxCanSignalDownload(uint8 * const Data, const uint16 Length, SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 ReferSignalIndex, SignalIndex, MsgIndex , PoolIndex;
	uint8 SignalByteLength ;
	uint32 SignalId;
	uint8 SignalTempBuffer[64] = {0};
	IPC_S2M_CANSignalTransmit_t SignalBuffer ;
	// IPC_M2S_CANSignalTransmitCallback_t CallbackBuffer = {0,0,{0}};

	/*Parse by ipc interface*/
	IPC_S2M_CANSignalTransmit_Receive(Data,&SignalBuffer,Length);

	PoolIndex = 0;

	for(SignalIndex = 0 ; SignalIndex < SignalBuffer.Number ; ++SignalIndex)
	{
		/*Check pool length*/
		if((PoolIndex + 4) > SignalBuffer.DataPoolLength )
		{
			break;
		}

		/*Format moto 4 Bytes -> uint32 */
		SignalId  = ((uint32)SignalBuffer.DataPool[PoolIndex]<<24);
		SignalId |= ((uint32)SignalBuffer.DataPool[PoolIndex+1]<<16);
		SignalId |= ((uint32)SignalBuffer.DataPool[PoolIndex+2]<<8);
		SignalId |= ((uint32)SignalBuffer.DataPool[PoolIndex+3]);

		PoolIndex += sizeof(uint32) ;

		for(ReferSignalIndex = 0 ; ReferSignalIndex < Object->TxCanSignalTotalNumber ; ++ReferSignalIndex)
		{
			MsgIndex = Object->TxCanSignalAttribute[ReferSignalIndex].MsgId;

			if(((uint8)SWC_IPC_SOC2MCU == Object->CanMsgAttribute[MsgIndex].Direction)
			  &&(Object->TxCanSignalAttribute[ReferSignalIndex].SignalId == SignalId))
			{
				SignalByteLength = (uint8)((Object->TxCanSignalAttribute[ReferSignalIndex].BitLength + (uint16)7) >> (uint16)3);

				/*Check pool length*/
				if((PoolIndex + SignalByteLength) > SignalBuffer.DataPoolLength )
				{
					PoolIndex += SignalByteLength;
					break;
				}

				/*Parse signal from local message buffer */
				IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset] ,
				                          SignalTempBuffer,
				                          &Object->TxCanSignalAttribute[ReferSignalIndex]);

				/*Compare signal buffer , when data buffer is changed or message is event ,
			  	then send new signal use output interface .*/
				if((FALSE != memcmp(&SignalTempBuffer, &SignalBuffer.DataPool[PoolIndex], SignalByteLength))
				|| (FALSE != Object->CanMsgAttribute[MsgIndex].Event)
				|| (Object->TxCanSignalAttribute[ReferSignalIndex].EventId < Object->EventTxCanSignalTotalNumber))
				{
					IPC_SetTxCanSignalCallbackLock(ReferSignalIndex, Object);
					IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
					                       &SignalBuffer.DataPool[PoolIndex],
					                       &Object->TxCanSignalAttribute[ReferSignalIndex]);

					/*Nvm signal*/
					if(Object->TxCanSignalAttribute[ReferSignalIndex].NvmOffset < ((uint16)SWC_IPC_NVM_CAN_SIGNAL_DATA_BUFFER_LENGTH))
					{
						/*Copy message update data to nvm static buffer*/
						(void)memcpy(&Object->CanNvm.Data[Object->TxCanSignalAttribute[ReferSignalIndex].NvmOffset],
							   &SignalBuffer.DataPool[PoolIndex],
							   SignalByteLength);

						SWC_IPC_PRINT_INFO("[CTX][SOC-SET-NVM-SIG][%X->%d]",
							               SignalId,Object->TxCanSignalAttribute[ReferSignalIndex].NvmOffset);
					}
					else
					{
						SWC_IPC_PRINT_INFO("[CTX][SOC-SET-SIG][%X]",SignalId);
					}

					#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH
						IPC_API_PrintDataArrayLog(&SignalBuffer.DataPool[PoolIndex] , SignalByteLength);
					#endif

					IPC_RepeatTxCanSignal(ReferSignalIndex,Object);
				}
				PoolIndex += SignalByteLength;
				break;
			}
		}
#ifdef SWC_IPC_DEBUG
		if(ReferSignalIndex == Object->TxCanSignalTotalNumber)
		{
			SWC_IPC_PRINT_ERROR("Unknown Tx can signal set request! SignalId = 0x%X" , SignalId);
		}
#endif
	}
#ifdef SWC_IPC_DEBUG
	if((SignalIndex != SignalBuffer.Number)
	 ||(0 == SignalBuffer.Number)
	 ||(PoolIndex != SignalBuffer.DataPoolLength))
	{
		SWC_IPC_PRINT_ERROR("Tx can signal set request format error! Signal number = %d , Data pool length = %d , Data = ..." ,
			                SignalBuffer.Number, SignalBuffer.DataPoolLength);

	#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH

		IPC_API_PrintDataArrayLog(SignalBuffer.DataPool , SignalBuffer.DataPoolLength);

	#endif
	}
#endif
}
/**********************************************************************************************************
*Function   : IPC_TxCanSignalRequest                                                                      *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 * const Data, const uint16 Length, SWC_IPC_CanRepeaterObject * const Object           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-12                                                                                  *
**********************************************************************************************************/
static void IPC_TxCanSignalCallbackRequest(uint8 * const Data, const uint16 Length, SWC_IPC_CanRepeaterObject * const Object)
{
	IPC_S2M_CANSignalRequest_t RequestMsg;
	uint16 SignalIndex = 0;

	/*Parse by ipc interface*/
	IPC_S2M_CANSignalRequest_Receive(Data, &RequestMsg, Length);

	for(SignalIndex = 0 ; SignalIndex < Object->TxCanSignalTotalNumber ; ++SignalIndex)
	{
		if(RequestMsg.SignalId == Object->TxCanSignalAttribute[SignalIndex].SignalId)
		{
			SWC_IPC_PRINT_INFO("[CTX][SOC-REQ-CB][%X]",RequestMsg.SignalId);

			IPC_TriggerTxCanSignalCallback(SignalIndex, Object);

			break;
		}
	}

#ifdef SWC_IPC_DEBUG
	if(SignalIndex == Object->TxCanSignalTotalNumber)
	{
		SWC_IPC_PRINT_ERROR("Unknown Tx can signal callback request! SignalId = 0x%X" ,RequestMsg.SignalId);
	}
#endif
}

/**********************************************************************************************************
*Function   : IPC_E2eTxCanMsgDownLoad                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object                              *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-29                                                                                  *
**********************************************************************************************************/
static void IPC_E2eTxCanMsgDownLoad(const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object)
{
	if(FALSE != Object->CanMsgAttribute[MsgIndex].E2E)
	{
		IPC_SingleTxCanMsgDownload(MsgIndex,Object);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_E2eTxCanMsgDownLoadCallback                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 MsgIndex                                                                      *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-12                                                                                  *
**********************************************************************************************************/
void IPC_API_E2eTxCanMsgDownLoadCallback( const uint32 MsgIndex)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;

	IPC_E2eTxCanMsgDownLoad(MsgIndex,Object);
}

/**********************************************************************************************************
*Function   : IPC_RxCanMsgUploadRequest                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 * const Data, const uint16 Length,SWC_IPC_CanRepeaterObject * const Object            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
static void IPC_RxCanMsgUploadRequest(uint8 * const Data, const uint16 Length,SWC_IPC_CanRepeaterObject * const Object)
{
	uint32 Index = 0;
	IPC_S2M_CANMessageRequest_t MsgBuffer;

	/*Parse by ipc interface*/
	IPC_S2M_CANMessageRequest_Receive(Data,&MsgBuffer,Length);

	if(MsgBuffer.FrameId != 0)
	{
		for(Index = 0 ; Index < Object->CanMsgTotalNumber ; ++Index)
		{
			if(((uint8)SWC_IPC_MCU2SOC == Object->CanMsgAttribute[Index].Direction) \
			&& ((Object->CanMsgAttribute[Index].FrameId == MsgBuffer.FrameId)))
			{
				IPC_API_RepeatCanMsg(SWC_IPC_NONE, Index);
				SWC_IPC_PRINT_INFO("[CRX][SOC-REQ-STAT&BUF][%X]",MsgBuffer.FrameId);
				break;
			}
		}

#ifdef SWC_IPC_DEBUG
		if(Index == Object->CanMsgTotalNumber)
		{
			SWC_IPC_PRINT_ERROR("Unknown Rx can message upload request! MsgId = 0x%X" , MsgBuffer.FrameId);
		}
#endif
	}
	else
	{
		IPC_API_RepeatCanMsg(SWC_IPC_MCU2SOC, SWC_IPC_NONE);
		(void)SWC_IPC_PRINT_DEBUG("[CRX][SOC-REQ-STAT&BUF][ALL]");
	}
}
/**********************************************************************************************************
*Function   : IPC_SingleTxCanMsgDownload                                                                  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object                              *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-08-06                                                                                  *
**********************************************************************************************************/
static void IPC_SingleTxCanMsgDownload(const uint32 MsgIndex,SWC_IPC_CanRepeaterObject * const Object)
{
	/*Send Can message data by rte interface .*/
	#ifndef SWC_IPC_PROJECT_TYPE_B03
	(void)Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(Object->CanMsgAttribute[MsgIndex].SignalId,
													&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
													Object->CanMsgAttribute[MsgIndex].Length);
	#else
	if(SWC_IPC_NULL != Object->CanMsgAttribute[MsgIndex].RteIf)
	{
		(void)Object->CanMsgAttribute[MsgIndex].RteIf(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset]);
	}
	#endif

	Object->CanMsgStatus[MsgIndex].DataRepeat = FALSE;

#ifdef SWC_IPC_DEBUG
	/*Only print none-e2e msg log*/
	if(FALSE == Object->CanMsgAttribute[MsgIndex].E2E)
	{
		SWC_IPC_PRINT_INFO("[CTX][TX-CYC-MSG][OK][%X]",Object->CanMsgAttribute[MsgIndex].FrameId);

	#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH
		IPC_API_PrintDataArrayLog(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset] ,Object->CanMsgAttribute[MsgIndex].Length);
	#endif
	}
#ifdef SWC_IPC_CYCLIC_MSG_PRINT_SWITCH
	else
	{
		SWC_IPC_PRINT_INFO("[CTX][TX-E2E-MSG][OK][%X]",Object->CanMsgAttribute[MsgIndex].FrameId);
	#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH
		IPC_API_PrintDataArrayLog(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset] ,Object->CanMsgAttribute[MsgIndex].Length);
	#endif
	}
#endif
#endif
}
/**********************************************************************************************************
*Function   : IPC_EventTxCanSignalDownload                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex, const uint8 * const Data ,SWC_IPC_CanRepeaterObject * const Object*
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-02                                                                                  *
**********************************************************************************************************/
static void IPC_EventTxCanSignalDownload(const uint32 SignalIndex, const uint8 * const Data ,SWC_IPC_CanRepeaterObject * const Object)
{
	uint8 TempData[64] = {0};
	uint8 ByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7) / (uint16)8);

	/*Convert data type .*/
	if((ByteLength > 1)&&(ByteLength <= 64))
	{
		IPC_ConvertEndian(Data,TempData,ByteLength);
	}
	else
	{
		(void)memcpy(TempData,Data,ByteLength);
	}

	#if(defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_P02)
	if(ByteLength > 4)
	{
		/*Send Can signal data by can service rte interface .*/
		if( E_OK == Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(Object->TxCanSignalAttribute[SignalIndex].EventId , TempData ))
		{
			Object->TxCanSignalStatus[SignalIndex].DataRepeat = FALSE;
			IPC_ClrTxCanSignalCallbackLock(SignalIndex, Object);
			IPC_API_PrintDataArrayLog(TempData , ByteLength);
		}
		else
		{
			Object->TxCanSignalStatus[SignalIndex].DataRepeat = TRUE;
			SWC_IPC_PRINT_ERROR("[CTX][TX-EV-SIG][FAILD][%X->%d]",
								Object->TxCanSignalAttribute[SignalIndex].SignalId,
								Object->TxCanSignalAttribute[SignalIndex].EventId);
		}
	}
	else
	#endif
	{
		/*Send Can signal data by can service rte interface .*/
		if( E_OK == Rte_Call_CNA_SignalSet_Operation(Object->TxCanSignalAttribute[SignalIndex].EventId , TempData ))
		{

			Object->TxCanSignalStatus[SignalIndex].DataRepeat = FALSE;
			IPC_ClrTxCanSignalCallbackLock(SignalIndex, Object);
			(void)SWC_IPC_PRINT_DEBUG("[EV:%s:%d]", SWC_IPC__EventTxCanSignalNameTable[Object->TxCanSignalAttribute[SignalIndex].EventId], TempData[0]);

		}
		else
		{
			Object->TxCanSignalStatus[SignalIndex].DataRepeat = TRUE;
			SWC_IPC_PRINT_ERROR("[CTX][TX-EV-SIG][FAILD][%X->%d]",
								Object->TxCanSignalAttribute[SignalIndex].SignalId,
								Object->TxCanSignalAttribute[SignalIndex].EventId);
		}
	}

#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH

	IPC_API_PrintDataArrayLog(Data , ((Object->TxCanSignalAttribute[SignalIndex].BitLength + 7) >> 3));

#endif

}


/**********************************************************************************************************
*Function   : IPC_SetEventTxCanSignalBuffer                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex, const uint8 * const Data ,SWC_IPC_CanRepeaterObject * const Object*
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2021-05-28                                                                                  *
**********************************************************************************************************/
static void IPC_SetEventTxCanSignalBuffer(const uint32 SignalIndex, const uint8 * const Data ,SWC_IPC_CanRepeaterObject * const Object)
{
	uint8 TempData[8] = {0};
	uint8 ByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7) / (uint16)8);

	/*Convert data type .*/
	if((ByteLength > 1)&&(ByteLength <= 8))
	{
		IPC_ConvertEndian(Data,TempData,ByteLength);
	}
	else
	{
		(void)memcpy(TempData,Data,ByteLength);
	}

	/*Send Can signal data by can service rte interface .*/
	if (E_OK == Rte_Call_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation(Object->TxCanSignalAttribute[SignalIndex].EventId , TempData ))
	{
		Object->TxCanSignalStatus[SignalIndex].SetBuffer = FALSE;

		SWC_IPC_PRINT_INFO("[CTX][TX-EV-SIG][OK][%X->%d]",
				           Object->TxCanSignalAttribute[SignalIndex].SignalId,
						   Object->TxCanSignalAttribute[SignalIndex].EventId);
	}
	else
	{
		Object->TxCanSignalStatus[SignalIndex].SetBuffer = TRUE;

		SWC_IPC_PRINT_ERROR("[CTX][TX-EV-SIG][FAILD][%X->%d]",
						    Object->TxCanSignalAttribute[SignalIndex].SignalId,
						    Object->TxCanSignalAttribute[SignalIndex].EventId);
	}

#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH
	IPC_API_PrintDataArrayLog(Data , ((Object->TxCanSignalAttribute[SignalIndex].BitLength + 7) >> 3));
#endif
}

/**********************************************************************************************************
*Function   : IPC_API_RepeatCanMsg                                                                        *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 Direction , const uint32 MsgIndex                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-30                                                                                  *
**********************************************************************************************************/
void IPC_API_RepeatCanMsg( const uint8 Direction , const uint32 MsgIndex)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint32 Index = 0;

	if( SWC_IPC_NONE != Direction )
	{
		for(Index = 0 ; Index < Object->CanMsgTotalNumber ; ++Index)
		{
			if( Direction & Object->CanMsgAttribute[Index].Direction )
			{
				Object->CanMsgStatus[Index].DataRepeat = TRUE;
				Object->CanMsgStatus[Index].StatusRepeat = TRUE;
			}
		}
	}
	else
	{
		if(MsgIndex < Object->CanMsgTotalNumber)
		{
			Object->CanMsgStatus[MsgIndex].DataRepeat = TRUE;
			Object->CanMsgStatus[MsgIndex].StatusRepeat = TRUE;
		}
		else if (MsgIndex == Object->CanMsgTotalNumber)
		{
			for(Index = 0 ; Index < Object->CanMsgTotalNumber ; ++Index)
			{
				Object->CanMsgStatus[Index].DataRepeat = TRUE;
				Object->CanMsgStatus[Index].StatusRepeat = TRUE;
			}
		}
		else
		{

		}
	}
}
/**********************************************************************************************************
*Function   : IPC_API_RepeatTxCanSignal                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex                                                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2021-01-07                                                                                  *
**********************************************************************************************************/
void IPC_API_RepeatTxCanSignal(const uint32 SignalIndex )
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;

	if(SignalIndex  < Object->TxCanSignalTotalNumber)
	{
		IPC_RepeatTxCanSignal(SignalIndex,Object);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_SetTxCanMsg                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 MsgIndex , const uint8 * const Data                                            *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-26                                                                                  *
**********************************************************************************************************/
uint8 IPC_API_SetTxCanMsg( const uint32 MsgIndex , const uint8 * const Data )
{
	uint8 RteReturn = RTE_E_INVALID ;
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;

	#ifndef SWC_IPC_PROJECT_TYPE_B03
	if (MsgIndex < Object->CanMsgTotalNumber)
	{
		/* Special TX can Message handle */
		if (SWC_IPC_CAN_MSG_IP1 == MsgIndex)
		{
			(void)IPC_API_TxCanMsgCallback_HUT_IP1();
		}
		else if (SWC_IPC_CAN_MSG_IP3 == MsgIndex)
		{
			(void)IPC_API_TxCanMsgCallback_HUT_IP3();
		}
		else if(SWC_IPC_CAN_MSG_HUT34 == MsgIndex)
		{
			(void)IPC_API_TxCanMsgCallback_HUT34();
		}
		#ifdef SWC_IPC_PROJECT_TYPE_P05
		else if(SWC_IPC_CAN_MSG_IP7 == MsgIndex)
		{
			(void)IPC_API_TxCanMsgCallback_HUT_IP7();
		}
		#endif
		#ifdef SWC_IPC_PROJECT_TYPE_P05
		else if(SWC_IPC_CAN_MSG_IP4 == MsgIndex)
		{
			(void)IPC_API_TxCanMsgCallback_HUT_IP4();
		}
		#endif
		else
		{
			//do nothing
		}

		if (SWC_IPC_NULL != Data)
		{
			(void)memcpy(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset], Data, Object->CanMsgAttribute[MsgIndex].Length);
		}

		RteReturn = Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(Object->CanMsgAttribute[MsgIndex].SignalId,
															  &Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
															  Object->CanMsgAttribute[MsgIndex].Length);
	}
	#else
	if ((MsgIndex < Object->CanMsgTotalNumber) && (SWC_IPC_NULL != Object->CanMsgAttribute[MsgIndex].RteIf))
	{
		if( SWC_IPC_NULL != Data )
		{
			(void)memcpy(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],Data,Object->CanMsgAttribute[MsgIndex].Length);
		}

		RteReturn = Object->CanMsgAttribute[MsgIndex].RteIf(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset]);
	}
	#endif

	return RteReturn;
}

/**********************************************************************************************************
*Function   : IPC_API_GetRxCanMsg                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 MsgIndex , uint8 * const Data                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-23                                                                                  *
**********************************************************************************************************/
uint8 IPC_API_GetRxCanMsg( const uint32 MsgIndex , uint8 * const Data )
{
	uint8 MsgStatus = RTE_E_OK;
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;

	if(MsgIndex < Object->CanMsgTotalNumber)
	{
		MsgStatus = Object->MsgBuffer[SWC_IPC_CAN_MSG_STATUS_BUFFER_START + MsgIndex];

		if(SWC_IPC_NULL != Data)
		{
			(void)memcpy(Data,&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],Object->CanMsgAttribute[MsgIndex].Length);
		}
	}
	return MsgStatus;
}

/**********************************************************************************************************
*Function   : IPC_TriggerTxCanSignalCallback                                                              *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-01                                                                                  *
**********************************************************************************************************/
static void IPC_TriggerTxCanSignalCallback( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object )
{
	Object->TxCanSignalStatus[SignalIndex].TxCallback = TRUE;
}

/**********************************************************************************************************
*Function   : IPC_RepeatTxCanSignal                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-01                                                                                  *
**********************************************************************************************************/
static void IPC_RepeatTxCanSignal( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object )
{
	Object->TxCanSignalStatus[SignalIndex].DataRepeat = TRUE;
}

/**********************************************************************************************************
*Function   : IPC_SetTxCanSignalCallbackLock                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chentuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-09-26                                                                                  *
**********************************************************************************************************/
static void IPC_SetTxCanSignalCallbackLock( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object )
{
	Object->TxCanSignalFilledNotSentFlag[SignalIndex] = TRUE;
}

/**********************************************************************************************************
*Function   : IPC_ClrTxCanSignalCallbackLock                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chentuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-09-26                                                                                  *
**********************************************************************************************************/
static void IPC_ClrTxCanSignalCallbackLock( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object )
{
	Object->TxCanSignalFilledNotSentFlag[SignalIndex] = FALSE;
}

/**********************************************************************************************************
*Function   : IPC_GetTxCanSignalCallbackLock                                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Chentuhe                                                                                   *
*                                                                                                         *
*Date       : 2021-09-26                                                                                  *
**********************************************************************************************************/
static boolean IPC_GetTxCanSignalCallbackLock( const uint32 SignalIndex , SWC_IPC_CanRepeaterObject * const Object )
{
	return (Object->TxCanSignalFilledNotSentFlag[SignalIndex]);
}

/**********************************************************************************************************
*Function   : IPC_E2eTxCanMsgDownLoad                                                                     *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex , const uint8 * const Data                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-29                                                                                  *
**********************************************************************************************************/
void IPC_API_SetTxCanSignal( const uint32 SignalIndex, const uint8 * const Data)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint8 SignalBuffer[64] ;
	uint8 SignalByteLength ;
	uint32 MsgIndex ;

	if(SignalIndex < Object->TxCanSignalTotalNumber)
	{
		if(SWC_IPC_NULL != Data)
		{
			MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;
			SignalByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7 )>>(uint16)3);

			/*Signal is event , trigger it always time.*/
			if(Object->TxCanSignalAttribute[SignalIndex].EventId < Object->EventTxCanSignalTotalNumber)
			{
				IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				                       Data,
				                       &Object->TxCanSignalAttribute[SignalIndex]);

				if(Object->TxCanSignalAttribute[SignalIndex].NvmOffset < ((uint16)SWC_IPC_NVM_CAN_SIGNAL_DATA_BUFFER_LENGTH))
				{
					/*Copy message update data to nvm static buffer*/
					(void)memcpy(&Object->CanNvm.Data[Object->TxCanSignalAttribute[SignalIndex].NvmOffset],
						   Data,
						   SignalByteLength);

					SWC_IPC_PRINT_INFO("[CTX][MCU-TRIG-NVM-EV-SIG][%X->%d]",
						               Object->TxCanSignalAttribute[SignalIndex].SignalId,
						               Object->TxCanSignalAttribute[SignalIndex].NvmOffset);
				}
				else
				{
					SWC_IPC_PRINT_INFO("[CTX][MCU-TRIG-EV-SIG][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
				}

				IPC_RepeatTxCanSignal(SignalIndex,Object);
			}
			else
			{
				IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				                      	  SignalBuffer,
				                      	  &Object->TxCanSignalAttribute[SignalIndex]);

				if(FALSE != memcmp(SignalBuffer,Data,SignalByteLength))
				{
					IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				                               Data,
				                               &Object->TxCanSignalAttribute[SignalIndex]);

					if(Object->TxCanSignalAttribute[SignalIndex].NvmOffset < ((uint16)SWC_IPC_NVM_CAN_SIGNAL_DATA_BUFFER_LENGTH))
					{
						/*Copy message update data to nvm static buffer*/
						(void)memcpy(&Object->CanNvm.Data[Object->TxCanSignalAttribute[SignalIndex].NvmOffset],
							   Data,
							   SignalByteLength);

						SWC_IPC_PRINT_INFO("[CTX][MCU-SET-NVM-CYC-SIG][%X->%d]",
							               Object->TxCanSignalAttribute[SignalIndex].SignalId,
							               Object->TxCanSignalAttribute[SignalIndex].NvmOffset);
					}
					else
					{
						SWC_IPC_PRINT_INFO("[CTX][MCU-SET-CYC-SIG][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
					}

					IPC_RepeatTxCanSignal(SignalIndex,Object);
				}
			}
		}
		else /*Input data buffer is null, use local data buffer . Set repeat flag.*/
		{
			if(Object->TxCanSignalAttribute[SignalIndex].EventId < Object->EventTxCanSignalTotalNumber)
			{
				IPC_RepeatTxCanSignal(SignalIndex,Object);

				SWC_IPC_PRINT_INFO("[CTX][MCU-TRIG-EV-SIG][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
			}
			else
			{
				/*This condition is abnormal because cyclic msg do not need trigger by application.*/
				SWC_IPC_PRINT_WARNING("[CTX][MCU-TRIG-CYC-SIGNAL][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
			}
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Unknown Tx can signal set request from mcu: Signal index = %d ", SignalIndex);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_SetTxCanSignalNotStore                                                              *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex , const uint8 * const Data                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-29                                                                                  *
**********************************************************************************************************/
void IPC_API_SetTxCanSignalNotStore( const uint32 SignalIndex, const uint8 * const Data)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint8 SignalBuffer[64] ;
	uint8 SignalByteLength ;
	uint32 MsgIndex ;

	if(SignalIndex < Object->TxCanSignalTotalNumber)
	{
		if(SWC_IPC_NULL != Data)
		{
			MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;
			SignalByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7 )>>(uint16)3);

			/*Signal is event , trigger it always time.*/
			if(Object->TxCanSignalAttribute[SignalIndex].EventId < Object->EventTxCanSignalTotalNumber)
			{
				IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				                       Data,
				                       &Object->TxCanSignalAttribute[SignalIndex]);

				IPC_RepeatTxCanSignal(SignalIndex,Object);
			}
			else
			{
				IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				                      	  SignalBuffer,
				                      	  &Object->TxCanSignalAttribute[SignalIndex]);

				if(FALSE != memcmp(SignalBuffer,Data,SignalByteLength))
				{
					IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
				                               Data,
				                               &Object->TxCanSignalAttribute[SignalIndex]);

					IPC_RepeatTxCanSignal(SignalIndex,Object);
				}
			}
		}
		else /*Input data buffer is null, use local data buffer . Set repeat flag.*/
		{
			if(Object->TxCanSignalAttribute[SignalIndex].EventId < Object->EventTxCanSignalTotalNumber)
			{
				IPC_RepeatTxCanSignal(SignalIndex,Object);

				SWC_IPC_PRINT_INFO("[CTX][MCU-TRIG-EV-SIG][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
			}
			else
			{
				/*This condition is abnormal because cyclic msg do not need trigger by application.*/
				SWC_IPC_PRINT_WARNING("[CTX][MCU-TRIG-CYC-SIGNAL][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
			}
		}
	}
	else
	{
		SWC_IPC_PRINT_ERROR("Unknown Tx can signal set request from mcu: Signal index = %d ", SignalIndex);
	}
}
/**********************************************************************************************************
*Function   : IPC_API_SetTxCanSignalBuffer                                                                *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  :  const uint32 SignalIndex, const uint8 * const Data                                         *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-12-01                                                                                  *
**********************************************************************************************************/
void IPC_API_SetTxCanSignalBuffer( const uint32 SignalIndex, const uint8 * const Data)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint8 SignalByteLength ;
	uint32 MsgIndex ;

	if(SignalIndex < Object->TxCanSignalTotalNumber)
	{
		if(SWC_IPC_NULL != Data)
		{
			MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;
			SignalByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7 )>>(uint16)3);

			IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
		                           Data,
		                           &Object->TxCanSignalAttribute[SignalIndex]);

			Object->TxCanSignalStatus[SignalIndex].SetBuffer = TRUE;

			if(Object->TxCanSignalAttribute[SignalIndex].NvmOffset < ((uint16)SWC_IPC_NVM_CAN_SIGNAL_DATA_BUFFER_LENGTH))
			{
				/*Copy message update data to nvm static buffer*/
				(void)memcpy(&Object->CanNvm.Data[Object->TxCanSignalAttribute[SignalIndex].NvmOffset],
					   Data,
					   SignalByteLength);

				SWC_IPC_PRINT_INFO("[CTX][MCU-SET-NVM-SIG-BUF][%X->%d]",
					               Object->TxCanSignalAttribute[SignalIndex].SignalId,
					               Object->TxCanSignalAttribute[SignalIndex].NvmOffset);
			}
			else
			{
				SWC_IPC_PRINT_INFO("[CTX][MCU-SET-SIG-BUF][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
			}
		}
		else
		{
			SWC_IPC_PRINT_ERROR("Invalid Tx can signal set buffer request from mcu: Signal index = %d ",Object->TxCanSignalAttribute[SignalIndex].SignalId);
		}
	}

}

/**********************************************************************************************************
*Function   : IPC_API_GetTxCanSignal                                                                      *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex,uint8 * const Data                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-09                                                                                  *
**********************************************************************************************************/
void IPC_API_GetTxCanSignal(const uint32 SignalIndex, uint8 * const Data)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint32 MsgIndex ;

	if(SignalIndex < Object->TxCanSignalTotalNumber)
	{
		MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;

		IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
			                      Data,
			                      &Object->TxCanSignalAttribute[SignalIndex]);
	}
}

/**********************************************************************************************************
*Function   : IPC_API_GetTxCanSignal                                                                      *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex , uint8 * const Data                                               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-10-23                                                                                  *
**********************************************************************************************************/
void IPC_API_GetRxCanSignal(const uint32 SignalIndex , uint8 * const Data)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint32 MsgIndex ;

	if(SignalIndex < Object->RxCanSignalTotalNumber)
	{
		MsgIndex = Object->RxCanSignalAttribute[SignalIndex].MsgId;

		IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
			                      Data,
			                      &Object->RxCanSignalAttribute[SignalIndex]);
	}
}
/**********************************************************************************************************
*Function   : IPC_PackCanSignalToMsg                                                                      *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : uint8 * const MsgData, const uint8 * const SignalData,                                      *
*             const SWC_IPC_CanSignalAttribute * const SignalAttribute                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-24                                                                                  *
**********************************************************************************************************/
static void IPC_PackCanSignalToMsg(uint8 * const MsgData, const uint8 * const SignalData,
                                             const SWC_IPC_CanSignalAttribute * const SignalAttribute)
{
	uint8 Index = 0 ;
	uint8 Shift = (uint8)((SignalAttribute->StartBit - (SignalAttribute->BitLength % 8) + 9) % 8);
	uint8 ByteLength = (uint8)((SignalAttribute->BitLength + 7 ) >> 3);
	uint16 Mask = (SignalAttribute->BitLength % 8)?((uint16)((2 << ((SignalAttribute->BitLength % 8) - 1)) - 1)):0xFF;
	uint8 Target = (uint8)((SignalAttribute->StartBit >> 3) + (((Mask << Shift) > 0xFF)?1:0));
	uint16 Short = 0 ;

	for(Index = 0 ; Index < ByteLength ; ++Index)
	{
		Mask = (((0 == Index)?Mask:0xFF) << Shift) ;
		Short = (((uint16)SignalData[Index] << Shift) & Mask);

		if( Mask > 0xFF )
		{
			MsgData[Target + Index - 1] &= ~((Mask >> 8) & 0xFF);
            MsgData[Target + Index - 1] |= ((Short >> 8) & 0xFF);
		}
		MsgData[Target + Index] &= ~(Mask & 0xFF);
        MsgData[Target + Index] |= (Short & 0xFF);
	}
}

/**********************************************************************************************************
*Function   : IPC_ParseCanSignalFromMsg                                                                   *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 * const MsgData, uint8 * const SignalData,                                      *
*             const SWC_IPC_CanSignalAttribute * const SignalAttribute                                    *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-24                                                                                  *
**********************************************************************************************************/
static void IPC_ParseCanSignalFromMsg(const uint8 * const MsgData, uint8 * const SignalData,
                                                 const SWC_IPC_CanSignalAttribute * const SignalAttribute)
{
	uint8 Index = 0 ;
	uint8 Shift = (uint8)((SignalAttribute->StartBit - (SignalAttribute->BitLength % 8) + 9) % 8);
	uint8 ByteLength = (uint8)((SignalAttribute->BitLength + 7 ) >> 3);
	uint16 Mask = (SignalAttribute->BitLength % 8)?((uint16)((2 << ((SignalAttribute->BitLength % 8) - 1)) - 1)):0xFF;
	uint8 Target = (uint8)(SignalAttribute->StartBit >> 3 ) + (((Mask << Shift) > 0xFF)?1:0);
	uint16 Short = 0 ;

	for(Index = 0 ; Index < ByteLength ; ++Index)
	{
		Mask = (((0 == Index)?Mask:0xFF) << Shift);
		Short = 0;
		if( Mask > 0xFF )
		{
			 Short |= (( MsgData[Target + Index - 1] & ((Mask >> 8) & 0xFF)) << 8 ) & 0xFF00 ;
		}
		Short |= MsgData[Target + Index] & (Mask & 0xFF);
        SignalData[Index] = (Short >> Shift);
	}
}
/**********************************************************************************************************
*Function   : IPC_ConvertEndian                                                                           *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint8 * const RawData ,uint8 * const Data, uint8 ByteLength                           *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-06                                                                                  *
**********************************************************************************************************/
static void IPC_ConvertEndian(const uint8 * const RawData ,uint8 * const Data, const uint8 ByteLength)
{
	uint8 index ;
	for (index = 0; index < ByteLength; ++index)
	{
		Data[index] = RawData[ByteLength - 1 - index];
	}
}

/**********************************************************************************************************
*Function   : IPC_API_FormatSignalToArray                                                                 *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex , const uint64 SignalValue, uint8 * const SignalData               *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-09-24                                                                                  *
**********************************************************************************************************/
void IPC_API_FormatSignalToArray(const uint32 SignalIndex , const uint64 SignalValue, uint8 * const SignalData)
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint8 Index , Shift;
	uint8 SignalByteLength = 0;

	if(SignalIndex < Object->TxCanSignalTotalNumber)
	{
		SignalByteLength = (uint8)(( Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7 ) >> (uint16)3);

		/*Moto Type , MST->LST*/
		Shift = 0;
		for(Index = 0 ; Index < SignalByteLength ; ++Index)
		{
			SignalData[SignalByteLength - Index - 1] = (uint8)(SignalValue >> Shift) ;
			Shift += 8;
		}
	}
}

/**********************************************************************************************************
*Function   : IPC_UploadTxSignalCallback                                                                  *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 SignalIndex ,SWC_IPC_CanRepeaterObject * const Object                          *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
static void IPC_UploadTxSignalCallback(const uint32 SignalIndex ,SWC_IPC_CanRepeaterObject * const Object )
{
	IPC_M2S_CANSignalTransmitCallback_t CallbackBuffer = {0,0,{0}};
	uint8 SignalByteLength ;
	uint8 SignalTempBuffer[64] = {0};
	uint32 MsgIndex;

	SignalByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7) >> (uint16)3);

	CallbackBuffer.Number = 1;

	CallbackBuffer.DataPool[CallbackBuffer.DataPoolLength] = (uint8)(Object->TxCanSignalAttribute[SignalIndex].SignalId >> 24);
	CallbackBuffer.DataPool[CallbackBuffer.DataPoolLength + 1] = (uint8)(Object->TxCanSignalAttribute[SignalIndex].SignalId >> 16);
	CallbackBuffer.DataPool[CallbackBuffer.DataPoolLength + 2] = (uint8)(Object->TxCanSignalAttribute[SignalIndex].SignalId >> 8);
	CallbackBuffer.DataPool[CallbackBuffer.DataPoolLength + 3] = (uint8)(Object->TxCanSignalAttribute[SignalIndex].SignalId );

	MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;

	/*Parse signal from local message buffer */
	IPC_ParseCanSignalFromMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset] ,
	                          SignalTempBuffer,
	                          &Object->TxCanSignalAttribute[SignalIndex]);

	(void)memcpy(&CallbackBuffer.DataPool[sizeof(uint32)],SignalTempBuffer,SignalByteLength);

	CallbackBuffer.DataPoolLength += ((uint16)SignalByteLength + (uint16)sizeof(uint32));

	if(IPC_ERR_NONE != IPC_M2S_CANSignalTransmitCallback_Transmit(&CallbackBuffer))
	{
		Object->TxCanSignalStatus[SignalIndex].TxCallback = TRUE;

		SWC_IPC_PRINT_INFO("[CTX][SIG-CB-UP][FAILD][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
	}
	else
	{
		Object->TxCanSignalStatus[SignalIndex].TxCallback = FALSE;

		SWC_IPC_PRINT_INFO("[CTX][SIG-CB-UP][OK][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
	}

#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH

	IPC_API_PrintDataArrayLog(SignalTempBuffer , SignalByteLength);

#endif
}
/**********************************************************************************************************
*Function   : IPC_API_UploadEventTxSignalCallback                                                         *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 EventIndex , void * const Data                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-10                                                                                  *
**********************************************************************************************************/
void IPC_API_UploadEventTxSignalCallback( const uint32 EventIndex , void * const Data )
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint32 SignalIndex , MsgIndex;
	uint8 SignalByteLength = 0 ;
	uint8 SignalTempBuffer[64] = {0};

	if(EventIndex < Object->EventTxCanSignalTotalNumber)
	{
		SignalIndex = Object->EventTxCanSignalMappingTable[EventIndex];

		if(SignalIndex < Object->TxCanSignalTotalNumber)
		{
			MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;
			SignalByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7) >> (uint16)3);

			/*Max data type is 8 bytes(uint64) . Bytes array do not need convert endian.*/
			if(SignalByteLength <= 8)
			{
				IPC_ConvertEndian(Data,SignalTempBuffer,SignalByteLength);
			}
			else
			{
				(void)memcpy(SignalTempBuffer,Data,SignalByteLength);
			}

			if(TRUE == IPC_GetTxCanSignalCallbackLock(SignalIndex, Object))
			{
				// The new data has been populated, and the old data callback is no longer returned
			}
			else
			{
				/*Save new value from input data buffer */
				IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
									SignalTempBuffer,
									&Object->TxCanSignalAttribute[SignalIndex]);

				IPC_TriggerTxCanSignalCallback(SignalIndex,Object);
			}

			SWC_IPC_PRINT_INFO("[CTX][COM-TRIG-EV-SIG][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);

		#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH

			IPC_API_PrintDataArrayLog(SignalTempBuffer , SignalByteLength);

		#endif
		}
	}
}
/**********************************************************************************************************
*Function   : IPC_API_SetEventTxSignalBuffer                                                              *
*                                                                                                         *
*Description:                                                                                             *
*                                                                                                         *
*Parameter  : const uint32 EventIndex , void * const Data                                                 *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : HenryChan                                                                                   *
*                                                                                                         *
*Date       : 2020-11-17                                                                                  *
**********************************************************************************************************/
void IPC_API_SetEventTxSignalBuffer( const uint32 EventIndex , void * const Data )
{
	SWC_IPC_CanRepeaterObject * Object = &SWC_IPC__CANRepeaterObject;
	uint32 SignalIndex , MsgIndex;
	uint8 SignalByteLength = 0 ;
	uint8 SignalTempBuffer[64] = {0};

	if(EventIndex < Object->EventTxCanSignalTotalNumber)
	{
		SignalIndex = Object->EventTxCanSignalMappingTable[EventIndex];
		MsgIndex = Object->TxCanSignalAttribute[SignalIndex].MsgId;
		SignalByteLength = (uint8)((Object->TxCanSignalAttribute[SignalIndex].BitLength + (uint16)7) >> (uint16)3);

		/*Max data type is 8 bytes(uint64) . Bytes array do not need convert endian.*/
		if(SignalByteLength <= 8)
		{
			IPC_ConvertEndian(Data,SignalTempBuffer,SignalByteLength);
		}
		else
		{
			(void)memcpy(SignalTempBuffer,Data,SignalByteLength);
		}

		if(TRUE == IPC_GetTxCanSignalCallbackLock(SignalIndex, Object))
		{
			// The new data has been populated, and the old data callback is no longer returned
		}
		else
		{
			/*Save new value from input data buffer */
			IPC_PackCanSignalToMsg(&Object->MsgBuffer[Object->CanMsgAttribute[MsgIndex].Offset],
								SignalTempBuffer,
								&Object->TxCanSignalAttribute[SignalIndex]);

			SWC_IPC_PRINT_INFO("[CTX][COM-SET-EV-SIG-BUF][%X]",Object->TxCanSignalAttribute[SignalIndex].SignalId);
		}
	#ifdef SWC_IPC_CAN_BUFFER_PRINT_SWITCH

		IPC_API_PrintDataArrayLog(SignalTempBuffer , SignalByteLength);

	#endif
	}
}

#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*                                                                                   					  *
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
