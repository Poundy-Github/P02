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
**  Name         : SWC_IPC_CANRepeater.h
**
**  Description  :
**
**  Organization :
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_IPC_CANR_H
#define SWC_IPC_CANR_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Std_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_IPC_Config.h"
#include "SWC_IPC_CANMatrix.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* IPC Rte Interface Type Definenation                                                                     *
**********************************************************************************************************/

#ifdef SWC_IPC_PROJECT_TYPE_B03
typedef Std_ReturnType (*SWC_IPC_RteIf)(uint8 *Data);
#endif

/**********************************************************************************************************
* IPC Can Msessage Attribute Structure Definenation                                                       *
**********************************************************************************************************/

typedef struct
{
    uint16 FrameId;
    uint16 Offset;
    uint8 Length;
    uint8 Priority;
    uint16 Cycle;
    boolean Event;
	uint8 Direction;
	boolean E2E;
	/* Any project that uses the COMEX architecture interface */
	/* B02 P03 P05 */
#ifndef SWC_IPC_PROJECT_TYPE_B03
	boolean SecOc;
    uint16 SignalId;
#else
    SWC_IPC_RteIf RteIf;
#endif
}SWC_IPC_CanMsgAttribute;

/**********************************************************************************************************
* IPC Can Msessage Status Structure Definenation                                                          *
**********************************************************************************************************/

typedef struct
{
	/*CAN message cycle time tick . */
    uint16 u16Tick;
	/*When this Flag is triggered , Repeater need send can data message again . */
    boolean DataRepeat;
	/*When this Flag is triggered , Repeater need send can status message again . */
    boolean StatusRepeat;
	/*When this Flag is triggered , print status to uart . */
    boolean StatusChanged;
}SWC_IPC_CanMsgStatus;

/**********************************************************************************************************
* IPC Can Signal Attribute Structure Definenation                                                         *
**********************************************************************************************************/

typedef struct
{
	uint16 MsgId;
	uint16 EventId;
	uint32 SignalId; /*Define in protobuf file*/
    uint16 StartBit;
    uint16 BitLength;
	uint16 NvmOffset;
}SWC_IPC_CanSignalAttribute;

/**********************************************************************************************************
* IPC Can Msessage Status Structure Definenation                                                          *
**********************************************************************************************************/

typedef struct
{
	/*When this Flag is triggered , Repeater need send can data message again . */
    boolean DataRepeat;
	/* Set buffer */
    boolean SetBuffer;
	/*When this Flag is triggered , Repeater need upload callback . */
    boolean TxCallback;
}SWC_IPC_CanSignalStatus;

/**********************************************************************************************************
* IPC Can Nvm Block Structure Definenation                                                                *
**********************************************************************************************************/
/*Total: 120 bytes*/
typedef struct
{
	uint8 NvmVersion;
#ifdef SWC_IPC_OBJECT_CHECK
	uint8 Data[SWC_IPC_CAN_REPEATER_NVM_SIZE - 5];
	uint32 NvmChecksum;
#else
	uint8 Data[SWC_IPC_CAN_REPEATER_NVM_SIZE - 1];
#endif
}SWC_IPC_CanDataNvmBlock;

/**********************************************************************************************************
* IPC Can Repeater Object Structure Definenation                                                          *
**********************************************************************************************************/

typedef struct
{
	/*Nvm*/
	SWC_IPC_CanDataNvmBlock CanNvm;
	uint8 NvmBlockSize;
	boolean NvmUpdateSwitch;
	/*Message*/
    uint32 CanMsgTotalNumber;
    SWC_IPC_CanMsgAttribute* CanMsgAttribute;
    SWC_IPC_CanMsgStatus CanMsgStatus[(uint32)SWC_IPC_CAN_MSG_TOTAL_NUMBER] ;
	uint8 MsgBuffer[SWC_IPC_CAN_MSG_DATA_BUFFER_LENGTH + 1u];
	uint8* ConstMsgBuffer;
	/*Tx Signal*/
	uint32 SignalTxUpdateTick;
	uint32 TxCanSignalTotalNumber;
	SWC_IPC_CanSignalAttribute* TxCanSignalAttribute;
	SWC_IPC_CanSignalStatus TxCanSignalStatus[(uint32)SWC_IPC_TX_CAN_SIGNAL_TOTAL_NUMBER];
	uint32 EventTxCanSignalTotalNumber;
	uint16* EventTxCanSignalMappingTable;
	/*Rx Signal*/
	uint32 RxCanSignalTotalNumber;
	SWC_IPC_CanSignalAttribute* RxCanSignalAttribute;
	/*Com State*/
	boolean IpcBusState;
	boolean CanBusState;
	/* Tx signal fill flag */
	boolean TxCanSignalFilledNotSentFlag[(uint32)SWC_IPC_TX_CAN_SIGNAL_TOTAL_NUMBER];
#ifdef SWC_IPC_DEBUG
	uint32 Error;
#endif
}SWC_IPC_CanRepeaterObject;

/* MsgBuffer
    |<-       Data       ->|<-      Status       ->|<  Pile->|
  Data                  Status                   Status    Buffer
  Start                 Start                     End       End
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
*                                                                                    					  *
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
