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
 * @file:      Ipc_Com.h
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

#ifndef IPC_COM_H
#define IPC_COM_H

#include "Platform_Types.h"


#define IPC_COM_RETRY_LIMIT             STD_ON

#if IPC_COM_RETRY_LIMIT == STD_ON
#define IPC_COM_MAX_RETRY_TIMES         (0x05u)
#endif

#define IPC_COM_NACK_CHECK_EN	STD_ON

#define IPC_COM_TICK    (10)
#define IPC_COM_TIMEOUT (200/IPC_COM_TICK)  /* 200ms*/
#define IPC_COM_TIMEOUT_PRINTF_CNT (10)  /* 200*10ms printf ipc timeout*/

#define IPC_NONE_DATA   (0)
#define IPC_ACK_DATA    (1)
#define IPC_NACK_DATA   (2)
#define IPC_NACK_ERR_ROLL   (3)

#define IPC_DATA_FRAME_LENGTH (IPC_FRAME_HEAD_AND_CHECKSUM + IPC_DATA_HIGH_PRI_LENGTH + IPC_DATA_LOW_PRI_LENGTH)  /* IPC head + Checksum + Hgih Priority + Low Priority */
#define IPC_DATA_HIGH_PRI_LENGTH  (1024)
#define IPC_DATA_LOW_PRI_LENGTH   (5120)

#define IPC_MAX_TX_MSG_PLOAD_LENGTH       (1024 - 2)
#define IPC_MAX_RX_MSG_PLOAD_LENGTH       (1024 - 2)

#define IPC_ACK_FRAME_LENGTH      (5) /*2 bytes FrameLen + 1 byte ACK/NACK + 2 bytes FrameChecksum*/
#define IPC_DUMMY_FRAME_LENGTH    (6) /*2 bytes FrameLen + 2 bytes Fix Data + 2 bytes FrameChecksum*/
#define IPC_MASTER_MIN_MSG_SIZE   (5) /*2 bytws msg len + 1 group id + 2bytes Msg id */
#define IPC_MASTER_MAX_MSG_SIZE    (IPC_MASTER_MIN_MSG_SIZE + IPC_MAX_RX_MSG_PLOAD_LENGTH)  /*Master MAX message size */

 
#define IPC_MSG_HEAD_LEN    (5) /*2 bytes msglen + 1 byte Group id + 1 byte Major msg id + 1 byte Sub msg id */
#define IPC_MSG_LENGTH_LEN  (2) /* Message length's leng*/
#define IPC_FRAME_HEAD_LEN  (3) /* 2 bytes Data Frame Length + 1 byte rolling counter*/
#define IPC_FRAME_CHECKSUM_LEN  (2) /*Data Frame Checksum*/
#define IPC_FRAME_HEAD_AND_CHECKSUM (IPC_FRAME_HEAD_LEN + IPC_FRAME_CHECKSUM_LEN)	/*FrameHead and FrameLen, 5 bytes.*/
#define IPC_FRAME_LENGTH_LEN    (2) /* Frame length's leng*/
#define IPC_FRAME_MIN_LEN   (IPC_FRAME_HEAD_AND_CHECKSUM + IPC_MSG_HEAD_LEN)


#define IPC_DUMMY_FARME_DATA1   (0x11)
#define IPC_DUMMY_FARME_DATA2   (0x22)


typedef enum IPC_Com_State_e
{
    IPC_COM_SPITRANSPORT,
    IPC_COM_DATARECEIVE,
}IPC_Com_State_e;

typedef enum e_IPC_FrameType_t
{
    IPC_FRAME_TYPE_DUMMY,
    IPC_FRAME_TYPE_DATA,
    IPC_FRAME_TYPE_ACK,
    IPC_FRAME_TYPE_NACK,
    IPC_FRAME_TYPE_DATA_ERR_ROLL,
    IPC_FRAME_TYPE_ACK_ERR_ROLL,
    IPC_FRAME_TYPE_ERR,
    IPC_FRAME_TYPE_MAX,
}e_IPC_FrameType_t;

typedef enum e_IPC_State_t
{
    IPC_STATE_IDLE,
    IPC_STATE_DATASEND,
    IPC_STATE_ACK
}e_IPC_State_t;

extern e_IPC_State_t ipc_State;
extern void IPC_Com_Init(void);
extern void IPC_Com_DeInit(void);
extern boolean IPC_GetSocReq(void);
//extern void IPC_IsrCsDetect(void);
//extern void IPC_IsrSocReqDetect(void);
extern e_IPC_State_t IPC_GetIpcState(void);
extern void IPC_SetState(e_IPC_State_t state);
extern void IPC_SendData(void);
extern void IPC_AckData(void);


extern void IPC_TriggerMainfunction(boolean fromISR);

#endif
