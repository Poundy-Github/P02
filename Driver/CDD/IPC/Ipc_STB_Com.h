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
 * @file:      Ipc_STB_Com.h
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

#ifndef IPC_STB_COM_H
#define IPC_STB_COM_H

#include "Platform_Types.h"

#define IPC_STB_COM_RETRY_LIMIT             STD_ON

#if IPC_STB_COM_RETRY_LIMIT == STD_ON
#define IPC_STB_COM_MAX_RETRY_TIMES         (0x05u)
#endif

#define IPC_STB_COM_NACK_CHECK_EN	STD_ON


#define IPC_STB_COM_TICK    (10)
#define IPC_STB_COM_TIMEOUT (200/IPC_STB_COM_TICK)  /* 200ms*/ 
#define IPC_STB_COM_TIMEOUT_CNT	(10)/* 200*10ms printf ipc timeout*/

#define IPC_STB_NONE_DATA   (0)
#define IPC_STB_ACK_DATA    (1)
#define IPC_STB_NACK_DATA   (2)
#define IPC_STB_NACK_ERR_ROLL   (3)

#define IPC_STB_DATA_FRAME_LENGTH (IPC_STB_FRAME_HEAD_AND_CHECKSUM + IPC_STB_DATA_HIGH_PRI_LENGTH + IPC_STB_DATA_LOW_PRI_LENGTH)  /* IPC_STB head + Checksum + Hgih Priority + Low Priority */
#define IPC_STB_DATA_HIGH_PRI_LENGTH  (1024)
#define IPC_STB_DATA_LOW_PRI_LENGTH   (2048)//reduce the RAM Costs from 5120->2048 ,total reduce:3k+3k+3k

#define IPC_STB_MAX_TX_MSG_PLOAD_LENGTH       (1024 - 2)
#define IPC_STB_MAX_RX_MSG_PLOAD_LENGTH       (1024 - 2)

#define IPC_STB_ACK_FRAME_LENGTH      (5) /*2 bytes FrameLen + 1 byte ACK/NACK + 2 bytes FrameChecksum*/
#define IPC_STB_DUMMY_FRAME_LENGTH    (6) /*2 bytes FrameLen + 2 bytes Fix Data + 2 bytes FrameChecksum*/
#define IPC_STB_MASTER_MIN_MSG_SIZE   (5) /*2 bytws msg len + 1 group id + 2bytes Msg id */
#define IPC_STB_MASTER_MAX_MSG_SIZE    (IPC_STB_MASTER_MIN_MSG_SIZE + IPC_STB_MAX_RX_MSG_PLOAD_LENGTH)  /*Master MAX message size */

 
#define IPC_STB_MSG_HEAD_LEN    (5) /*2 bytes msglen + 1 byte Group id + 1 byte Major msg id + 1 byte Sub msg id */
#define IPC_STB_MSG_LENGTH_LEN  (2) /* Message length's leng*/
#define IPC_STB_FRAME_HEAD_LEN  (3) /* 2 bytes Data Frame Length + 1 byte rolling counter*/
#define IPC_STB_FRAME_CHECKSUM_LEN  (2) /*Data Frame Checksum*/
#define IPC_STB_FRAME_HEAD_AND_CHECKSUM (IPC_STB_FRAME_HEAD_LEN + IPC_STB_FRAME_CHECKSUM_LEN)	/*FrameHead and FrameLen, 5 bytes.*/
#define IPC_STB_FRAME_LENGTH_LEN    (2) /* Frame length's leng*/
#define IPC_STB_FRAME_MIN_LEN   (IPC_STB_FRAME_HEAD_AND_CHECKSUM + IPC_STB_MSG_HEAD_LEN)


#define IPC_STB_DUMMY_FARME_DATA1   (0x11)
#define IPC_STB_DUMMY_FARME_DATA2   (0x22)


typedef enum
{
    IPC_STB_COM_SPITRANSPORT,
    IPC_STB_COM_DATARECEIVE,
}IPC_STB_Com_State_e;

typedef enum
{
    IPC_STB_FRAME_TYPE_DUMMY,
    IPC_STB_FRAME_TYPE_DATA,
    IPC_STB_FRAME_TYPE_ACK,
    IPC_STB_FRAME_TYPE_NACK,
    IPC_STB_FRAME_TYPE_DATA_ERR_ROLL,
    IPC_STB_FRAME_TYPE_ACK_ERR_ROLL,
    IPC_STB_FRAME_TYPE_ERR,
    IPC_STB_FRAME_TYPE_MAX,
}e_IPC_STB_FrameType_t;

typedef enum
{
    IPC_STB_STATE_IDLE,
    IPC_STB_STATE_DATASEND,
    IPC_STB_STATE_ACK
}e_IPC_STB_State_t;


extern void IPC_STB_Com_Init(void);
extern void IPC_STB_Com_DeInit(void);
extern boolean IPC_STB_GetSocReq(void);
extern void IPC_STB_IsrCsDetect(void);
extern void IPC_STB_IsrSocReqDetect(void);
extern e_IPC_STB_State_t IPC_STB_GetIPC_STBState(void);
extern void IPC_STB_SetState(e_IPC_STB_State_t state);
extern void IPC_STB_SendData(void);
extern void IPC_STB_AckData(void);


extern void IPC_STB_TriggerMainfunction(boolean fromISR);

#endif

#endif
