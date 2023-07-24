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
 * @file:      Ipc_Monitor.c
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

/*
 *  %header file in this project/library%
 */
#include "Rte_IPC.h"
#include "Ipc_Monitor.h"
#include "Ipc_Com.h"
#include "Ipc_If.h"
#include "Crc.h"
#include "logger.h"
#include "Std_Types.h"
#include "string.h"
#include "Ipc_LoadTest.h"

#include "IPC_Common.h"
//static uint16 ipc_RegisterFrameLen;
static uint16 ipc_TxFrameLen;


uint8 ipc_TxFrameBuffer[IPC_DATA_FRAME_LENGTH]; /*IPC DMA send data buffer.*/
uint8 ipc_RxFrameBuffer[IPC_DATA_FRAME_LENGTH];   /*DMA receive data buffer.*/
uint8 ipc_TxAckBuffer[IPC_ACK_FRAME_LENGTH];   /*Ack data buffer.*/

static uint8 ipc_TxRollCnt;
uint8 ipc_RxRollCnt;






static void IPC_IdleState(void);
static void IPC_PrepareSendData(void);
static void IPC_PrepareDummyData(void);



/*******************************************************************************
* Function: IPC_Monitor_Init
* Description: Handle IPC Monitor initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_Monitor_Init(void)
{
    memset(ipc_TxFrameBuffer,0x00,IPC_DATA_FRAME_LENGTH);
    memset(ipc_RxFrameBuffer,0x00,IPC_DATA_FRAME_LENGTH);
    memset(ipc_TxAckBuffer,0x00,IPC_ACK_FRAME_LENGTH);

//    ipc_RegisterFrameLen = 0;
    ipc_TxFrameLen = 0;
    ipc_TxRollCnt = 0;
    ipc_RxRollCnt = 0;
}

/*******************************************************************************
* Function: IPC_Monitor_DeInit
* Description: Handle IPC Monitor deinitial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_Monitor_DeInit(void)
{
/* doing nothing*/
}

/*******************************************************************************
* Function: IPC_MainFunction
* Description: Ipc mainfunction, handle ipc state schedule
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_Monitor_MainFunction(void)
{
#if 0
    IPC_M2S_ServiceHMITime_t hmitime;
    hmitime.Year = 1;
    hmitime.Month=2;
    hmitime.Day = 3;
    hmitime.Hour=4;
    hmitime.Minute = 5;
    hmitime.Second=6;
    hmitime.TimeMode=7;
    (void)IPC_M2S_ServiceHMITime_Transmit(&hmitime);
    
#endif
	#if (STD_ON == IPC_BUFFER_FULL_PRITF_EN)
		IPC_BufferFullPritf_Mainfunction();
	#endif

	#ifdef IPC_DEBUG_OPEN
		IPC_BusMonitor_Mainfunction();
	#endif
	
    switch(ipc_State)
    {
        case IPC_STATE_IDLE:
            IPC_IdleState();
            break;
        case IPC_STATE_DATASEND:
            IPC_SendData();
            break;
        case IPC_STATE_ACK:
            IPC_AckData();
            break;
        default:
			/* nothing to do */
            break;
    }
}


/*******************************************************************************
* Function: IPC_IdleState
* Description: Handle IPC idle state
* Parameter: void
* Return:  void
*******************************************************************************/
static void IPC_IdleState(void)
{
    if(IPC_CheckDataSend() == TRUE)
    {
        IPC_PrepareSendData();
        IPC_SetState(IPC_STATE_DATASEND);
        IPC_SendData();
    }
    else
    {
        if(IPC_GetSocReq() == TRUE)
        {
            IPC_PrepareDummyData();
            IPC_SetState(IPC_STATE_DATASEND);
            IPC_SendData();
        }
    }

}

/*******************************************************************************
* Function: IPC_PrepareSendData
* Description: prepare ipc send data
* Parameter: void
* Return:  void
*******************************************************************************/
static void IPC_PrepareSendData(void)
{
    uint16 data_len;
    uint16 checksum;

    ipc_TxFrameLen = 0;

    IPC_ENTER_CRITICAL();

    if(ipc_TxDataHighPriLen > IPC_MSG_HEAD_LEN)
    {
        memcpy(&ipc_TxFrameBuffer[IPC_FRAME_HEAD_LEN], ipc_TxDataHighPri, ipc_TxDataHighPriLen);
        ipc_TxFrameLen = ipc_TxDataHighPriLen;
        /* Set tx data length to 0 to Clear tx data buffer */
        ipc_TxDataHighPriLen = 0;
    }

    data_len = ipc_TxDataLowPriLen;

    if(ipc_TxDataLowPriLen > IPC_MSG_HEAD_LEN)
    {
        memcpy(&ipc_TxFrameBuffer[IPC_FRAME_HEAD_LEN + ipc_TxFrameLen], ipc_TxDataLowPri, ipc_TxDataLowPriLen);
        ipc_TxFrameLen = ipc_TxFrameLen + ipc_TxDataLowPriLen;
        /* Set tx data length to 0 to Clear tx data buffer */
        ipc_TxDataLowPriLen = 0;
    }

    IPC_EXIT_CRITICAL();

    data_len = ipc_TxFrameLen + IPC_FRAME_HEAD_LEN; /* Frame length not include checksum */
    ipc_TxFrameLen = ipc_TxFrameLen + IPC_FRAME_HEAD_AND_CHECKSUM ; /* Frame length total */
    ipc_TxRollCnt++;

    ipc_TxFrameBuffer[0] = (uint8)(ipc_TxFrameLen >> 8);
    ipc_TxFrameBuffer[1] = (uint8)(ipc_TxFrameLen & 0xFF);
    ipc_TxFrameBuffer[2] = ipc_TxRollCnt;

    checksum = Crc_CalculateCRC16(ipc_TxFrameBuffer,data_len, 0,TRUE);

    ipc_TxFrameBuffer[data_len] = (uint8)(checksum >> 8);
    ipc_TxFrameBuffer[data_len + 1] = (uint8)(checksum & 0xFF);
    TST_IPC_CheckTransport(ipc_TxFrameLen);
}

/*******************************************************************************
* Function: IPC_RePrepareSendData
* Description: reprepare ipc send data, clear roll counter to 0
* Parameter: void
* Return:  void
*******************************************************************************/
void IPC_RePrepareSendData(void)
{
    uint16 data_len;
    uint16 checksum;
 
    if (ipc_TxFrameLen > IPC_DUMMY_FRAME_LENGTH)
    {
        ipc_TxFrameBuffer[2] = 0; /* Clear roll counter to 0 */
        
        data_len = ipc_TxFrameLen - IPC_FRAME_CHECKSUM_LEN;
        checksum = Crc_CalculateCRC16(ipc_TxFrameBuffer,data_len, 0,TRUE);
        
        ipc_TxFrameBuffer[data_len] = (uint8)(checksum >> 8);
        ipc_TxFrameBuffer[data_len + 1] = (uint8)(checksum & 0xFF);
    }
}

/*******************************************************************************
* Function: IPC_PrepareDummyData
* Description: prepare ipc dummy data
* Parameter: void
* Return:  void
*******************************************************************************/
static void IPC_PrepareDummyData(void)
{
    uint16 checksum;

    /* calculate ipc frame length */
    ipc_TxFrameBuffer[0] = 0;
    ipc_TxFrameBuffer[1] = IPC_DUMMY_FRAME_LENGTH;

    ipc_TxFrameBuffer[2] = IPC_DUMMY_FARME_DATA1;
    ipc_TxFrameBuffer[3] = IPC_DUMMY_FARME_DATA2;

    checksum = Crc_CalculateCRC16(ipc_TxFrameBuffer,IPC_DUMMY_FRAME_LENGTH - 2, 0,TRUE);
    ipc_TxFrameLen = IPC_DUMMY_FRAME_LENGTH;

    ipc_TxFrameBuffer[4] = (uint8)(checksum >> 8);
    ipc_TxFrameBuffer[5] = (uint8)(checksum & 0xFF);
}

/*******************************************************************************
* Function: IPC_PrepareAckData
* Description: prepare ipc ack data
* Parameter: void
* Return:  void
*******************************************************************************/
void IPC_PrepareAckData(uint8 ack)
{
    uint16 checksum;
    
    /* calcute ipc frame length */
    ipc_TxAckBuffer[0] = 0;
    ipc_TxAckBuffer[1] = (IPC_ACK_FRAME_LENGTH);
    ipc_TxAckBuffer[2] = ack;
     
    checksum = Crc_CalculateCRC16(ipc_TxAckBuffer,IPC_ACK_FRAME_LENGTH-2, 0,TRUE);

    ipc_TxAckBuffer[3] = (uint8)(checksum >> 8);
    ipc_TxAckBuffer[4] = (uint8)(checksum & 0xff);
}

/*******************************************************************************
* Function: IPC_ClearRollCounter
* Description: void
* Parameter: void
* Return:  void
*******************************************************************************/
void IPC_ClearRollCounter(void)
{
    ipc_TxRollCnt = 0;
    ipc_RxRollCnt = 0;
}

/*******************************************************************************
* Function: IPC_NACKDeal
* Description: NACK was defined by SOC recv ipc_frame err CRC 
* Parameter: void
* Return: void
*******************************************************************************/
#if(STD_ON == IPC_COM_NACK_CHECK_EN)
boolean IPC_NackCheck(void)
{
	boolean ret = TRUE;
    uint16 data_len;
    uint16 checksum,checksumPre;

	if((ipc_TxFrameLen >= IPC_FRAME_MIN_LEN) && (ipc_TxFrameLen <= IPC_DATA_FRAME_LENGTH))
	{
		data_len = ipc_TxFrameLen - IPC_FRAME_CHECKSUM_LEN;
		checksumPre = ((uint16)ipc_TxFrameBuffer[ipc_TxFrameLen-2] * 0x100u) + (uint16)ipc_TxFrameBuffer[ipc_TxFrameLen-1];
		checksum = Crc_CalculateCRC16(ipc_TxFrameBuffer,data_len, 0,TRUE);
		if(checksumPre != checksum)
		{
			ret = FALSE;
			ipc_warn("[IPC-E]:data tampered ,len = %d , PreCrc = %d\r\n",data_len,checksumPre);
		}
	}
	else if(ipc_TxFrameLen == IPC_DUMMY_FRAME_LENGTH)
	{
		ret = FALSE;
		ipc_warn("[IPC-E]:frame was dummy,drop it!\r\n");
	}
	else
	{
		ret = FALSE;
		ipc_warn("[IPC-E]:data tampered ,len = %d\r\n",ipc_TxFrameLen);
	}
	return ret;
}

#endif

