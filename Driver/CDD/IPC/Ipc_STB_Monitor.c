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
 * @file:      Ipc_STB_Monitor.c
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
#include "Rte_IPC.h"
#include "IPC_STB_Monitor.h"
#include "IPC_STB_Com.h"
#include "IPC_STB_If.h"
#include "Crc.h"
#include "logger.h"
#include "Std_Types.h"
#include "string.h"
#include "IPC_STB_LoadTest.h"

#include "IPC_Common.h"
//static uint16 IPC_STB_RegisterFrameLen;
static uint16 IPC_STB_TxFrameLen;


uint8 IPC_STB_TxFrameBuffer[IPC_STB_DATA_FRAME_LENGTH]; /*IPC_STB DMA send data buffer.*/
uint8 IPC_STB_RxFrameBuffer[IPC_STB_DATA_FRAME_LENGTH];   /*DMA receive data buffer.*/
uint8 IPC_STB_TxAckBuffer[IPC_STB_ACK_FRAME_LENGTH];   /*Ack data buffer.*/

static uint8 IPC_STB_TxRollCnt;
uint8 IPC_STB_RxRollCnt;




extern e_IPC_STB_State_t IPC_STB_State;
extern uint16 IPC_STB_TxDataHighPriLen;
extern uint16 IPC_STB_TxDataLowPriLen;
extern uint8 IPC_STB_TxDataHighPri[IPC_STB_DATA_HIGH_PRI_LENGTH]; /*IPC_STB DMA High priority send data buffer.*/  
extern uint8 IPC_STB_TxDataLowPri[IPC_STB_DATA_LOW_PRI_LENGTH]; /*IPC_STB DMA High priority send data buffer.*/  


static void IPC_STB_IdleState(void);
static void IPC_STB_PrepareSendData(void);
static void IPC_STB_PrepareDummyData(void);



/*******************************************************************************
* Function: IPC_STB_Monitor_Init
* Description: Handle IPC_STB Monitor initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_Monitor_Init(void)
{
    memset(IPC_STB_TxFrameBuffer,0x00,IPC_STB_DATA_FRAME_LENGTH);
    memset(IPC_STB_RxFrameBuffer,0x00,IPC_STB_DATA_FRAME_LENGTH);
    memset(IPC_STB_TxAckBuffer,0x00,IPC_STB_ACK_FRAME_LENGTH);

//    IPC_STB_RegisterFrameLen = 0;
    IPC_STB_TxFrameLen = 0;
    IPC_STB_TxRollCnt = 0;
    IPC_STB_RxRollCnt = 0;
}

/*******************************************************************************
* Function: IPC_STB_Monitor_DeInit
* Description: Handle IPC_STB Monitor deinitial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_Monitor_DeInit(void)
{


}

/*******************************************************************************
* Function: IPC_STB_MainFunction
* Description: IPC_STB mainfunction, handle IPC_STB state schedule
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_Monitor_MainFunction(void)
{
#if 0
    IPC_STB_M2S_ServiceHMITime_t hmitime;
    hmitime.Year = 1;
    hmitime.Month=2;
    hmitime.Day = 3;
    hmitime.Hour=4;
    hmitime.Minute = 5;
    hmitime.Second=6;
    hmitime.TimeMode=7;
    (void)IPC_STB_M2S_ServiceHMITime_Transmit(&hmitime);
    
#endif

#if (STD_ON == IPC_STB_BUFFER_FULL_PRITF_EN)
		IPC_STB_BufferFullPritf_Mainfunction();
#endif

#ifdef IPC_STB_DEBUG_OPEN
		IPC_STB_BusMonitor_Mainfunction();
#endif

    switch(IPC_STB_State)
    {
        case IPC_STB_STATE_IDLE:
            IPC_STB_IdleState();
            break;
        case IPC_STB_STATE_DATASEND:
            IPC_STB_SendData();
            break;
        case IPC_STB_STATE_ACK:
            IPC_STB_AckData();
            break;
        default:
			/* nothing to do */
            break;
    }
}


/*******************************************************************************
* Function: IPC_STB_IdleState
* Description: Handle IPC_STB idle state
* Parameter: void
* Return:  void
*******************************************************************************/
static void IPC_STB_IdleState(void)
{
    if(IPC_STB_CheckDataSend() == TRUE)
    {
        IPC_STB_PrepareSendData();
        IPC_STB_SetState(IPC_STB_STATE_DATASEND);
        IPC_STB_SendData();
    }
    else
    {
        if(IPC_STB_GetSocReq() == TRUE)
        {
            IPC_STB_PrepareDummyData();
            IPC_STB_SetState(IPC_STB_STATE_DATASEND);
            IPC_STB_SendData();
        }
    }

}

/*******************************************************************************
* Function: IPC_STB_PrepareSendData
* Description: prepare IPC_STB send data
* Parameter: void
* Return:  void
*******************************************************************************/
static void IPC_STB_PrepareSendData(void)
{
    uint16 data_len;
    uint16 checksum;

    IPC_STB_TxFrameLen = 0;

    IPC_STB_ENTER_CRITICAL();

    if(IPC_STB_TxDataHighPriLen > IPC_STB_MSG_HEAD_LEN)
    {
        memcpy(&IPC_STB_TxFrameBuffer[IPC_STB_FRAME_HEAD_LEN], IPC_STB_TxDataHighPri, IPC_STB_TxDataHighPriLen);
        IPC_STB_TxFrameLen = IPC_STB_TxDataHighPriLen;
        /* Set tx data length to 0 to Clear tx data buffer */
        IPC_STB_TxDataHighPriLen = 0;
    }

    data_len = IPC_STB_TxDataLowPriLen;

    if(IPC_STB_TxDataLowPriLen > IPC_STB_MSG_HEAD_LEN)
    {
        memcpy(&IPC_STB_TxFrameBuffer[IPC_STB_FRAME_HEAD_LEN + IPC_STB_TxFrameLen], IPC_STB_TxDataLowPri, IPC_STB_TxDataLowPriLen);
        IPC_STB_TxFrameLen = IPC_STB_TxFrameLen + IPC_STB_TxDataLowPriLen;
        /* Set tx data length to 0 to Clear tx data buffer */
        IPC_STB_TxDataLowPriLen = 0;
    }

    IPC_STB_EXIT_CRITICAL();

    data_len = IPC_STB_TxFrameLen + IPC_STB_FRAME_HEAD_LEN; /* Frame length not include checksum */
    IPC_STB_TxFrameLen = IPC_STB_TxFrameLen + IPC_STB_FRAME_HEAD_AND_CHECKSUM ; /* Frame length total */
    IPC_STB_TxRollCnt++;

    IPC_STB_TxFrameBuffer[0] = (uint8)(IPC_STB_TxFrameLen >> 8);
    IPC_STB_TxFrameBuffer[1] = (uint8)(IPC_STB_TxFrameLen & 0xFF);
    IPC_STB_TxFrameBuffer[2] = IPC_STB_TxRollCnt;

    checksum = Crc_CalculateCRC16(IPC_STB_TxFrameBuffer,data_len, 0,TRUE);

    IPC_STB_TxFrameBuffer[data_len] = (uint8)(checksum >> 8);
    IPC_STB_TxFrameBuffer[data_len + 1] = (uint8)(checksum & 0xFF);
    TST_IPC_STB_CheckTransport(IPC_STB_TxFrameLen);
}

/*******************************************************************************
* Function: IPC_STB_RePrepareSendData
* Description: reprepare IPC_STB send data, clear roll counter to 0
* Parameter: void
* Return:  void
*******************************************************************************/
void IPC_STB_RePrepareSendData(void)
{
    uint16 data_len;
    uint16 checksum;
 
    if (IPC_STB_TxFrameLen > IPC_STB_DUMMY_FRAME_LENGTH)
    {
        IPC_STB_TxFrameBuffer[2] = 0; /* Clear roll counter to 0 */
        
        data_len = IPC_STB_TxFrameLen - IPC_STB_FRAME_CHECKSUM_LEN;
        checksum = Crc_CalculateCRC16(IPC_STB_TxFrameBuffer,data_len, 0,TRUE);
        
        IPC_STB_TxFrameBuffer[data_len] = (uint8)(checksum >> 8);
        IPC_STB_TxFrameBuffer[data_len + 1] = (uint8)(checksum & 0xFF);
    }
}

/*******************************************************************************
* Function: IPC_STB_PrepareDummyData
* Description: prepare IPC_STB dummy data
* Parameter: void
* Return:  void
*******************************************************************************/
static void IPC_STB_PrepareDummyData(void)
{
    uint16 checksum;

    /* calculate IPC_STB frame length */
    IPC_STB_TxFrameBuffer[0] = 0;
    IPC_STB_TxFrameBuffer[1] = IPC_STB_DUMMY_FRAME_LENGTH;

    IPC_STB_TxFrameBuffer[2] = IPC_STB_DUMMY_FARME_DATA1;
    IPC_STB_TxFrameBuffer[3] = IPC_STB_DUMMY_FARME_DATA2;

    checksum = Crc_CalculateCRC16(IPC_STB_TxFrameBuffer,IPC_STB_DUMMY_FRAME_LENGTH - 2, 0,TRUE);
    IPC_STB_TxFrameLen = IPC_STB_DUMMY_FRAME_LENGTH;

    IPC_STB_TxFrameBuffer[4] = (uint8)(checksum >> 8);
    IPC_STB_TxFrameBuffer[5] = (uint8)(checksum & 0xFF);
}

/*******************************************************************************
* Function: IPC_STB_PrepareAckData
* Description: prepare IPC_STB ack data
* Parameter: void
* Return:  void
*******************************************************************************/
void IPC_STB_PrepareAckData(uint8 ack)
{
    uint16 checksum;
    
    /* calcute IPC_STB frame length */
    IPC_STB_TxAckBuffer[0] = 0;
    IPC_STB_TxAckBuffer[1] = (IPC_STB_ACK_FRAME_LENGTH);
    IPC_STB_TxAckBuffer[2] = ack;
     
    checksum = Crc_CalculateCRC16(IPC_STB_TxAckBuffer,IPC_STB_ACK_FRAME_LENGTH-2, 0,TRUE);

    IPC_STB_TxAckBuffer[3] = (uint8)(checksum >> 8);
    IPC_STB_TxAckBuffer[4] = (uint8)(checksum & 0xff);
}

/*******************************************************************************
* Function: IPC_STB_ClearRollCounter
* Description: void
* Parameter: void
* Return:  void
*******************************************************************************/
void IPC_STB_ClearRollCounter(void)
{
    IPC_STB_TxRollCnt = 0;
    IPC_STB_RxRollCnt = 0;
}

/*******************************************************************************
* Function: IPC_STB_NACKDeal
* Description: NACK was defined by SOC recv ipc_frame err CRC 
* Parameter: void
* Return: void
*******************************************************************************/


#if(STD_ON == IPC_STB_COM_NACK_CHECK_EN)
boolean IPC_STB_NackCheck(void)
{
	boolean ret = TRUE;
    uint16 data_len;
    uint16 checksum,checksumPre;

	if((IPC_STB_TxFrameLen >= IPC_STB_FRAME_MIN_LEN) && (IPC_STB_TxFrameLen <= IPC_STB_DATA_FRAME_LENGTH))
	{
		data_len = IPC_STB_TxFrameLen - IPC_STB_FRAME_CHECKSUM_LEN;
		checksumPre = ((uint16)IPC_STB_TxFrameBuffer[IPC_STB_TxFrameLen-2] * 0x100u) + (uint16)IPC_STB_TxFrameBuffer[IPC_STB_TxFrameLen-1];
		checksum = Crc_CalculateCRC16(IPC_STB_TxFrameLen,data_len, 0,TRUE);
		if(checksumPre != checksum)
		{
			ret = FALSE;
			ipc_warn("[IPC-STB_E]:data tampered ,len = %d , PreCrc = %d\r\n",data_len,checksumPre);
		}
	}else if(IPC_STB_TxFrameLen == IPC_STB_DUMMY_FRAME_LENGTH)
	{
		ret = FALSE;
		ipc_warn("[IPC-STB_E]:frame was dummy,drop it!\r\n");
	}
	else
	{
		ret = FALSE;
		ipc_warn("[IPC-STB_E]:data tampered ,len = %d\r\n",IPC_STB_TxFrameLen);
	}
	return ret;
}
#endif


#endif

