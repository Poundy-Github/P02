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
**  Name         : SWC_IPC_Interface.h
**
**  Description  :
**
**  Organization :
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_IPC_IF_H
#define SWC_IPC_IF_H

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


/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_IPC_NW_START_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"

/**********************************************************************************************************
* IPC Can Repeater Module Interface                                                                       *
**********************************************************************************************************/

void IPC_CanRepeaterInit(void);

void IPC_CanRepeaterTask(void);

boolean IPC_API_ControlCanNvmSwitch( const boolean Switch );

void IPC_API_RepeatCanMsg( const uint8 Direction , const uint32 MsgIndex );

void IPC_API_RepeatTxCanSignal(const uint32 SignalIndex );

uint8 IPC_API_SetTxCanMsg( const uint32 MsgIndex , const uint8 * const Data );

uint8 IPC_API_GetRxCanMsg( const uint32 MsgIndex , uint8 * const Data );

void IPC_API_SetTxCanSignal( const uint32 SignalIndex , const uint8 * const Data );

void IPC_API_SetTxCanSignalNotStore( const uint32 SignalIndex, const uint8 * const Data);

void IPC_API_SetTxCanSignalBuffer(const uint32 SignalIndex, const uint8 * const Data);

void IPC_API_GetTxCanSignal(const uint32 SignalIndex , uint8 * const Data);

void IPC_API_GetRxCanSignal(const uint32 SignalIndex , uint8 * const Data);

void IPC_API_UploadEventTxSignalCallback( const uint32 EventIndex , void * const Data );

void IPC_API_SetEventTxSignalBuffer ( const uint32 EventIndex , void * const Data );

void IPC_API_FormatSignalToArray(const uint32 SignalIndex , const uint64 SignalValue, uint8 * const SignalData);

void IPC_API_E2eTxCanMsgDownLoadCallback(const uint32 MsgIndex);

/**********************************************************************************************************
* IPC Manager Module Interface                                                                            *
**********************************************************************************************************/

void IPC_ManagerInit(void);

void IPC_ManagerTask(void);

void IPC_API_AppMsgTransmit(const uint8 Index, const uint8 * const Data, const uint16 Length, const boolean SyncFlag);

void IPC_API_SetAppMsgBuffer(const uint8 Index, const uint8 * const Data, const uint16 Length);

void IPC_API_RepeatAppMsg( const uint8 Type , const uint8 AppIndex );

boolean IPC_API_CheckRepeatStatus( const uint8 AppIndex );

/**********************************************************************************************************
* IPC Application Module Interface                                                                        *
**********************************************************************************************************/
void IPC_ApplicationInit(void);

void IPC_ApplicationTask(void);

boolean IPC_API_ControlAppNvmSwitch( const boolean Switch );

void IPC_API_RestoreNvmTxCanSignal(void);

/**********************************************************************************************************
* IPC Application Callback                                                                                *
**********************************************************************************************************/

void IPC_API_ReadEngineerInfoCallback( uint8 *Data );

void IPC_API_WriteEngineerInfoCallback( uint8 *Data );

void IPC_API_ReadCommonInfoCallback( uint8 *Data );

void IPC_API_WriteCommonInfoCallback( uint8 *Data );

void IPC_API_GetSafetyAppAliveCallback( uint8 *Data );

void IPC_API_GetCommonAppAliveCallback( uint8 *Data );

void IPC_API_GetWhudAliveCallback( uint8 *Data );

void IPC_API_GetWhudNvmConfigCallback(uint8 *Data);

void IPC_API_SetWhudNvmConfigCallback(uint8 *Data);

void IPC_API_SetRestoreSettingCallback(uint8 *Data);

void IPC_API_ReadSerialNumberCallback(uint8 *Data);

void IPC_API_WriteGaugesValueCallback(uint8 *Data);

void IPC_API_GetInterfaceAppAliveCallback(uint8 *Data);

void IPC_API_GaugesAliveCallback(uint8 *Data);

void IPC_API_ReadVINNumberCallback(uint8 *Data);

void IPC_API_ChimeClientAliveCallback(uint8 *Data);

void IPC_API_SetBeanIDReqCallback(uint8 *Data);

void IPC_API_WhudNvmSetWithIdCallback(uint8 *Data);

void IPC_API_GetSocHMISafetyAliveCallback(uint8 *Data);

void IPC_API_SetAVASSwitchStatusCallback(uint8 *Data);

/**********************************************************************************************************
* IPC Driver Module Callback                                                                              *
**********************************************************************************************************/

void IPC_API_CanMsgReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length);

void IPC_API_ClusterAppReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length);

void IPC_API_WhudReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length);

void IPC_API_IviAppReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length);

void IPC_API_EngineerAppReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length);

void IPC_API_InfraReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length);

void IPC_API_SaftyReceiveCallback(uint8 MajorId, uint8 SubId,uint8 *Data, uint16 Length);

void IPC_API_ClusterPowerOperation(void);

/**********************************************************************************************************
* IPC Special Can Msg Callback                                                                            *
**********************************************************************************************************/

#ifndef SWC_IPC_PROJECT_TYPE_B03

Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP1(void);
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP2_E2E(void);
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP3(void);
Std_ReturnType IPC_API_TxCanMsgCallback_HUT32_E2E(void);
Std_ReturnType IPC_API_TxCanMsgCallback_HUT34(void);
#if (defined SWC_IPC_PROJECT_TYPE_P03) || (defined SWC_IPC_PROJECT_TYPE_D01) || (defined SWC_IPC_PROJECT_TYPE_D02)  || \
    (defined SWC_IPC_PROJECT_TYPE_D03) || (defined SWC_IPC_PROJECT_TYPE_P02) || (defined SWC_IPC_PROJECT_TYPE_P01)
void IPC_API_TxCanMsgCallback_DMS_FD1_E2E(void);
#endif
#else
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP1( const uint8 *Data );
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP2_E2E( const uint8 *Data );
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP3( const uint8 *Data );
Std_ReturnType IPC_API_TxCanMsgCallback_HUT32_E2E( const uint8 *Data );
Std_ReturnType IPC_API_TxCanMsgCallback_HUT34( const uint8 *Data );
#ifdef SWC_IPC_PROJECT_TYPE_B03
Std_ReturnType IPC_API_TxCanMsgCallback_DMS_FD1_E2E( const uint8 *Data );
#endif

#endif

#ifdef SWC_IPC_PROJECT_TYPE_P05
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP7(void);
#endif

#ifdef SWC_IPC_PROJECT_TYPE_P05
Std_ReturnType IPC_API_TxCanMsgCallback_HUT_IP4(void);
#endif

/**********************************************************************************************************
* IPC Debug Interfacer                                                                                    *
**********************************************************************************************************/
#ifdef SWC_IPC_DEBUG

void IPC_API_PrintDataArrayLog(const uint8 * const Data ,const uint32 Length );

#endif
/**********************************************************************************************************
*                                                                                                         *
**********************************************************************************************************/
#define SWC_IPC_NW_STOP_SEC_CODE
#include "SWC_IPC_NW_MemMap.h"
/**********************************************************************************************************
*#endif ||Section End                                                                                     *
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
