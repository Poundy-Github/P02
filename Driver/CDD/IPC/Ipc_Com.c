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
 * @file:      Ipc_Com.c
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
#include "Os.h"
#include "Dio.h"
#include "hal_spi.h"
#include "Dma.h"
#include "logger.h"
#include "Ipc_Com.h"
#include "Ipc_Monitor.h"
#include "Ipc_If.h"
#include "csih_spi.h"
#include "Icu.h"
#include "Std_Types.h"
#include "Crc.h"
#include "Ipc_Cfg.h"
#include "Rtm.h"
#include "Ipc_LoadTest.h" 


e_IPC_State_t ipc_State;
static IPC_Com_State_e IPC_Com_State = IPC_COM_SPITRANSPORT;
static uint16 ipc_timer;
static uint16 ipc_timeout_print_cnt=0;

static uint16 ipc_RxFrameLen;

static boolean IPC_ComComplete; /* IPC Spi communication complete state */

#if IPC_COM_RETRY_LIMIT == STD_ON

static uint8 Ipc_ComContinuousNackCnt = 0;;


#endif


static void IPC_Com_HardwareInit(void);
static void IPC_SpiTransmit(uint8 * pTxBuf, uint16 tx_len,  uint8*pRxBuf, uint16 rx_len);
static void IPC_SetMcuReq(void);
static void IPC_ClearMcuReq(void); 

static void IPC_ReceiveData(void);
static void IPC_ReceiveAckData(void);
static e_IPC_FrameType_t IPC_CheckFrameType(uint8 * p_frame);
static void IPC_RecevieDataDecode(uint8 *p_frame, uint16 frame_len);




/*******************************************************************************
* Function: IPC_Com_Init
* Description: Handle IPC Monitor initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_Com_Init(void)
{
    ipc_State = IPC_STATE_IDLE;
    ipc_RxFrameLen = 0;
    IPC_Com_State = IPC_COM_SPITRANSPORT;
    ipc_timer = 0;

#if IPC_COM_RETRY_LIMIT == STD_ON
    Ipc_ComContinuousNackCnt = 0;
#endif


    IPC_Com_HardwareInit();
}

/*******************************************************************************
* Function: IPC_Com_DeInit
* Description: Handle IPC Monitor initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_Com_DeInit(void)
{
/* doing nothing*/
}

/*******************************************************************************
* Function: IPC_Com_HardwareInit
* Description: Handle IPC hardware initial
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_Com_HardwareInit(void)
{
    /* DMA, ICU, SPI */

}

/*******************************************************************************
* Function: IPC_SpiTransmit
* Description: handle spi data transmit
* Parameter: 
* Return: void
*******************************************************************************/
static void IPC_SpiTransmit(uint8 * pTxBuf, uint16 tx_len,  uint8*pRxBuf, uint16 rx_len)
{
    (void)Hal_Spi_Close(HAL_SPI_IPC);
    (void)Hal_Spi_Open(HAL_SPI_IPC);

    Dma_ChannelConfiguration(DMA_IPC_TX
    ,&pTxBuf[1]
    ,(void *)IPC_USER_TX_ADDR
    ,tx_len);

    Dma_ChannelConfiguration(DMA_IPC_RX
    ,(void *)IPC_USER_RX_ADDR
    ,&pRxBuf[0]
    ,rx_len);

    (void)Hal_Spi_Transmit(HAL_SPI_IPC, &pTxBuf[0],1);
}

/*******************************************************************************
* Function: IPC_SetMcuReq
* Description: Set Mcu transmit request
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_SetMcuReq(void)
{
    TST_IPC_CheckRequestTransport();
    Dio_WriteChannel(IPC_VIP_SOC_REQ,STD_HIGH);
}
/*******************************************************************************
* Function: IPC_SetMcuReq
* Description: clear Mcu transmit request
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_ClearMcuReq(void)
{
    Dio_WriteChannel(IPC_VIP_SOC_REQ,STD_LOW);
}

/*******************************************************************************
* Function: IPC_SetMcuReq
* Description: Get Soc transmit request status
* Parameter: void
* Return: void
*******************************************************************************/
boolean IPC_GetSocReq(void)
{
    boolean ret = FALSE;
   // if(STD_HIGH == Dio_ReadChannel(DioConf_DioChannel_VIP_SOC_REQ))
    if(ICU_HIGH == IPC_GET_SOC_VIP_REQ())
    {
        ret = TRUE;
    }
    return ret;
}

/*******************************************************************************
* Function: IPC_IsrCsDetect
* Description: SPI Cs High detect, interrupt
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_IsrCsDetect(void)
{
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
	
    if(ICU_HIGH == IPC_GET_SOC_VIP_CS())
    {
        TST_IPC_CheckSPITransportEnd();
        /* CS Disable, Communication done, Trigger IPC_Mainfunction */
        IPC_ComComplete = TRUE;
        IPC_TriggerMainfunction(TRUE);
        
    }
    else
    {
        /* CS Enable, Clear MCU request: Todo, send message clear request in task */
        IPC_ClearMcuReq();
        
    }
	
	Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
}

/*******************************************************************************
* Function: IPC_IsrSocReqDetect
* Description: SOC Request High detect, interrupt
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_IsrSocReqDetect(void)
{
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
    /* SOC Request communication, Trigger IPC_Mainfunction */
    IPC_TriggerMainfunction(TRUE);
    
	Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
}

/*******************************************************************************
* Function: IPC_DmaStop
* Description: Stop DMA transmit
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_DmaStop(void)
{
    Dma_ChannelStop(DMA_IPC_TX);
    Dma_ChannelStop(DMA_IPC_RX);
}

/*******************************************************************************
* Function: IPC_GetIpcState
* Description: Get ipc state
* Parameter: void
* Return: e_IPC_State_t
*******************************************************************************/
e_IPC_State_t IPC_GetIpcState(void)
{
    return ipc_State;
}

/*******************************************************************************
* Function: IPC_SetState
* Description: set ipc state
* Parameter: e_IPC_State_t
* Return: void
*******************************************************************************/
void IPC_SetState(e_IPC_State_t state)
{
    ipc_State = state;
    ipc_timer = 0; 
    IPC_Com_State = IPC_COM_SPITRANSPORT;
}
extern void TM_Timer1msStartStamp(uint32 * StartStamp);

/*******************************************************************************
* Function: IPC_SendData
* Description: Handle IPC Senddata state
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_SendData(void)
{
	uint32 curOsTimer=0;

    if(IPC_Com_State == IPC_COM_SPITRANSPORT)
    {
        IPC_ComComplete = FALSE;
        IPC_SpiTransmit(ipc_TxFrameBuffer, IPC_DATA_FRAME_LENGTH, ipc_RxFrameBuffer, IPC_DATA_FRAME_LENGTH);
		ipc_timer = 0 ;
        IPC_Com_State = IPC_COM_DATARECEIVE;

        IPC_SetMcuReq();
    }
    else if(IPC_Com_State == IPC_COM_DATARECEIVE)
    {
        if(IPC_ComComplete == TRUE)
        {
            IPC_ComComplete = FALSE;
			ipc_timeout_print_cnt = 0 ;
            IPC_DmaStop();
            IPC_ClearMcuReq();
            IPC_ReceiveData();
        }
        else
        {
            ipc_timer ++;

            if(ipc_timer >= IPC_COM_TIMEOUT)
            {
                /* Timeout, Set IPC State Datasend to resend */
                IPC_DmaStop();
                IPC_ClearMcuReq();
                IPC_SetState(IPC_STATE_DATASEND);
                /* Error log every IPC_COM_TIMEOUT_PRINTF_CNT*IPC_COM_TIMEOUT ms*/
				if((ipc_timeout_print_cnt%IPC_COM_TIMEOUT_PRINTF_CNT) == 0)
				{
					TM_Timer1msStartStamp(&curOsTimer);
	                ipc_warn("[IPC-W]:%d ms,DataSwapTimeout\r\n",curOsTimer);
				}
				ipc_timeout_print_cnt++;
            }
			
        }
    }
    else
    {
        /* Do nothing */
    }

}

/*******************************************************************************
* Function: IPC_AckData
* Description: Handle IPC Ackdata state
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_AckData(void)
{
	uint32 curOsTimer=0;
    if(IPC_Com_State == IPC_COM_SPITRANSPORT)
    {
        IPC_ComComplete = FALSE;
        IPC_SpiTransmit(ipc_TxAckBuffer, IPC_DATA_FRAME_LENGTH, ipc_RxFrameBuffer, IPC_DATA_FRAME_LENGTH);
        ipc_timer = 0;
        IPC_Com_State = IPC_COM_DATARECEIVE;

        IPC_SetMcuReq();
    }
    else if(IPC_Com_State == IPC_COM_DATARECEIVE)
    {
        if(IPC_ComComplete == TRUE)
        {
            IPC_ComComplete = FALSE;
			ipc_timeout_print_cnt = 0 ;
            IPC_DmaStop();
            IPC_ClearMcuReq();
            IPC_ReceiveAckData();
        }
        else
        {
            ipc_timer ++;

            if(ipc_timer >= IPC_COM_TIMEOUT)
            {
                /* Timeout, Set IPC State Datasend to resend */
                IPC_DmaStop();
                IPC_ClearMcuReq();
                IPC_SetState(IPC_STATE_DATASEND);
                /* Error log every IPC_COM_TIMEOUT_PRINTF_CNT*IPC_COM_TIMEOUT ms*/
				if((ipc_timeout_print_cnt%IPC_COM_TIMEOUT_PRINTF_CNT) == 0)
				{
					TM_Timer1msStartStamp(&curOsTimer);
					ipc_warn("[IPC-W]:%d ms,AckSwapTimeout\r\n",curOsTimer);
				}
				ipc_timeout_print_cnt++;
            }
        }
    }
    else
    {
        /* Do nothing */
    }

}

/*******************************************************************************
* Function: IPC_ReceiveData
* Description: Handle IPC receive data
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_ReceiveData(void)
{
    e_IPC_FrameType_t eFrameType;
    eFrameType = IPC_CheckFrameType(ipc_RxFrameBuffer);

    switch(eFrameType)
    {
    	//N-1:Swap Data , Recv Data
        case IPC_FRAME_TYPE_DATA:            
            IPC_RecevieDataDecode(ipc_RxFrameBuffer,ipc_RxFrameLen);
            
            IPC_PrepareAckData(IPC_ACK_DATA);
            IPC_SetState(IPC_STATE_ACK);
            /* Receive data decode complete, trigger mainfunction to start ack data */
            IPC_TriggerMainfunction(FALSE);
            break;
			
    	//N-2:Swap Data , Recv Data , But Was Dummy
        case IPC_FRAME_TYPE_DUMMY:
            IPC_PrepareAckData(IPC_ACK_DATA);
            IPC_SetState(IPC_STATE_ACK);
            IPC_TriggerMainfunction(FALSE);
            break;
            
		//N-3:Swap Data , Recv Data , But Data Roll Error
        case IPC_FRAME_TYPE_DATA_ERR_ROLL:
            ipc_warn("[IPC-W-D]:D-Swaped,R-D,RollCntWasErr\r\n");
            IPC_ClearRollCounter();   /* Clear roll counter */
            /* Receive data error, send ack error roll, not reprepare data and re send data */
            IPC_PrepareAckData(IPC_NACK_ERR_ROLL);  
            IPC_SetState(IPC_STATE_ACK);
            IPC_TriggerMainfunction(FALSE);            
            break;
            
		//abN-1:Swap Data , Recv ACK , BUT ACK_ERR_ROLL
        case IPC_FRAME_TYPE_ACK_ERR_ROLL:
            ipc_warn("[IPC-W-D]:D-Swaped,R-A,RollCntWasErr\r\n");
            IPC_ClearRollCounter();   /* Clear roll counter */
            IPC_RePrepareSendData(); /* Roll counter error, reprepare send data */
            IPC_SetState(IPC_STATE_DATASEND);
            IPC_TriggerMainfunction(FALSE);            
            break;  
            
		//N-4:Swap Data ,Type Error
        case IPC_FRAME_TYPE_ERR:
            ipc_warn("[IPC-W-D]:D-Swaped,FrameTypeErr,CKup\r\n");
            IPC_PrepareAckData(IPC_NACK_DATA);
            IPC_SetState(IPC_STATE_ACK);
            IPC_TriggerMainfunction(FALSE);
            break;
            
    	//abN-2:Swap Data And Recv Ack
        case IPC_FRAME_TYPE_ACK:
            ipc_warn("[IPC-W-D]:D-Swaped,R-A,CKup\r\n");
            /* Host Ack or error state, keep in data send state to sync with host */
            IPC_SetState(IPC_STATE_DATASEND);
            IPC_TriggerMainfunction(FALSE); 
            break;

		//abN-2:Swap Data And Recv Data , But Data Roll Error
		case IPC_FRAME_TYPE_NACK:
			ipc_warn("[IPC-W-D]:D-Swaped,R-NA,CKup\r\n");
			/* Host Ack or error state, keep in data send state to sync with host */
			IPC_SetState(IPC_STATE_DATASEND);
			#if(STD_ON == IPC_COM_NACK_CHECK_EN)	
				if(FALSE == IPC_NackCheck())
				{
					IPC_ClearRollCounter();
					IPC_SetState(IPC_STATE_IDLE);
					ipc_warn("[IPC-E]:data tampered ,discard it!\r\n");
				}
			#endif
			IPC_TriggerMainfunction(FALSE); 
			break;


        default:
			/* nothing to do */
            break;
    }
}

/*******************************************************************************
* Function: IPC_ReceiveData
* Description: Handle IPC receive Ack data
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_ReceiveAckData(void)
{
    e_IPC_FrameType_t eFrameType;

    eFrameType = IPC_CheckFrameType(ipc_RxFrameBuffer);
    
#if IPC_COM_RETRY_LIMIT == STD_ON
    if (eFrameType == IPC_FRAME_TYPE_NACK)
    {
        Ipc_ComContinuousNackCnt ++;
    }
    else
    {
        Ipc_ComContinuousNackCnt = 0;
    }
#endif


    switch(eFrameType)
    {
		//N-1:Swap Ack , Recv Ack
        case IPC_FRAME_TYPE_ACK:
            IPC_SetState(IPC_STATE_IDLE);
            /* Set IPC status Ready */
//            IPC_SetIPCStateType(IPC_CONN_READY);
            IPC_TriggerMainfunction(FALSE);
            break;

		//abN-1:Swap Ack , Recv Data
        case IPC_FRAME_TYPE_DATA:
            IPC_RecevieDataDecode(ipc_RxFrameBuffer,ipc_RxFrameLen);
            /* Sync with master state */
            IPC_PrepareAckData(IPC_ACK_DATA);
            IPC_SetState(IPC_STATE_ACK);   
            IPC_TriggerMainfunction(FALSE);
            break;

		//abN-2:Swap Ack , Recv Dummy
        case IPC_FRAME_TYPE_DUMMY:
            /* Sync with master state */
            IPC_PrepareAckData(IPC_ACK_DATA);
            IPC_SetState(IPC_STATE_ACK);            
            IPC_TriggerMainfunction(FALSE);
            break;
            
		//abN-3:Swap Ack , Recv DATA
        case IPC_FRAME_TYPE_DATA_ERR_ROLL:
            ipc_warn("[IPC-W-A]:A-Swaped,R-D,RollCntWasErr\r\n");
            IPC_ClearRollCounter();  /* Clear roll counter */
            /* Receive data error, send ack error roll, not reprepare data and re send data */
            IPC_PrepareAckData(IPC_NACK_ERR_ROLL);
            IPC_SetState(IPC_STATE_ACK);
            IPC_TriggerMainfunction(FALSE);   
			break;
          
		//N-2:Swap Ack , Recv Ack  
        case IPC_FRAME_TYPE_ACK_ERR_ROLL:
            ipc_warn("[IPC-W-A]:A-Swaped,R-A,RollCntWasErr\r\n");
            IPC_ClearRollCounter();   /* Clear roll counter */
            IPC_RePrepareSendData(); /* Roll counter error, reprepare send data */            
            IPC_SetState(IPC_STATE_DATASEND);
            IPC_TriggerMainfunction(FALSE);

            break;
            
    	case IPC_FRAME_TYPE_NACK:
            (void)ipc_warn("[IPC-W-A]:A-Swaped,R-NA,CKup\r\n");
		
            /* Host Ack or error state, keep in data send state to sync with host */
            IPC_SetState(IPC_STATE_DATASEND);
			
			#if(STD_ON == IPC_COM_NACK_CHECK_EN)	
				if(FALSE == IPC_NackCheck())
				{
					IPC_ClearRollCounter();
					IPC_SetState(IPC_STATE_IDLE);
					ipc_warn("[IPC-E]:data tampered ,discard it!\r\n");
				}
				else
			#endif
				{
			#if IPC_COM_RETRY_LIMIT == STD_ON
				if (Ipc_ComContinuousNackCnt >= IPC_COM_MAX_RETRY_TIMES)
				{
					Ipc_ComContinuousNackCnt = 0;
					ipc_warn("[IPC-W-A]:A-Swaped,R-NA,Retry Timeout\r\n");
					IPC_ClearRollCounter();
					IPC_SetState(IPC_STATE_IDLE);
				}
			#endif
				}
            IPC_TriggerMainfunction(FALSE);
            break;
			
        case IPC_FRAME_TYPE_ERR:
            ipc_warn("[IPC-W-A]:A-Swaped,FrameTypeErr,CKup\r\n");
            /* Host Ack or error state, keep in data send state to sync with host */
            IPC_SetState(IPC_STATE_DATASEND);
            IPC_TriggerMainfunction(FALSE);
            break;

        default:
			/* nothing to do */
            break;
     
	}
}

/*******************************************************************************
* Function: IPC_CheckFrameType
* Description: 
* Parameter: void
* Return: void
*******************************************************************************/
static e_IPC_FrameType_t IPC_CheckFrameType(uint8 * p_frame)
{
    uint8 *p_uframe;
    uint16 frame_len;
    uint16 checksum;
    e_IPC_FrameType_t t_stType;

    t_stType = IPC_FRAME_TYPE_DUMMY;

    if(p_frame == NULL_PTR)
    {
        t_stType = IPC_FRAME_TYPE_ERR;
        ipc_warn("[IPC-W-C]:p_frame Was Null");
    }

    if(t_stType != IPC_FRAME_TYPE_ERR)
    {
        p_uframe = &p_frame[0];
        frame_len = (((uint16)p_uframe[0]) << 8) + (uint16)p_uframe[1];
        if ((frame_len<IPC_ACK_FRAME_LENGTH) || (frame_len>IPC_DATA_FRAME_LENGTH))
        {
            
            ipc_warn("[IPC-W-C]:FrameLenErr,len=%u\n",frame_len);
            t_stType = IPC_FRAME_TYPE_ERR;
        }
    }

    if (t_stType != IPC_FRAME_TYPE_ERR)
    {
        checksum = ((uint16)p_uframe[frame_len-2] * 0x100u) + (uint16)p_uframe[frame_len-1];

        if (checksum == Crc_CalculateCRC16(p_uframe,frame_len-2, 0,TRUE))
        {
            if(frame_len == IPC_DUMMY_FRAME_LENGTH)
            {
                t_stType = IPC_FRAME_TYPE_DUMMY;
            }
            else if(frame_len == IPC_ACK_FRAME_LENGTH)
            {
                /*receive ack message*/
                if(p_uframe[2] == IPC_ACK_DATA)
                {
                    t_stType = IPC_FRAME_TYPE_ACK;
                }
                else if (p_uframe[2] == IPC_NACK_DATA)
                {
                    t_stType = IPC_FRAME_TYPE_NACK;
                }
                else if (p_uframe[2] == IPC_NACK_ERR_ROLL)
                {
                    t_stType = IPC_FRAME_TYPE_ACK_ERR_ROLL;
                    ipc_warn("[IPC-W-C]:A-WasErrRollCnt,T=%d\n",p_uframe[2]);
                }
                else
                {
                    ipc_warn("[IPC-W-C]:AckTypeErr,T=%u\n",p_uframe[2]);
                    t_stType = IPC_FRAME_TYPE_ERR;
                }
            }
            else if((frame_len >= IPC_FRAME_MIN_LEN) && (frame_len <= IPC_DATA_FRAME_LENGTH))
            {
                /*receive message handling*/
                ipc_RxFrameLen = frame_len;

                if(++ipc_RxRollCnt == p_uframe[2])
                {
                    t_stType = IPC_FRAME_TYPE_DATA;
                }
                else
                {
                    t_stType = IPC_FRAME_TYPE_DATA_ERR_ROLL;
                    ipc_warn("[IPC-W-C]:D-RolCntErr,e=%u,r=%u\n",ipc_RxRollCnt,p_uframe[2]);
                }
            }
            else
            {
                ipc_warn("[IPC-W-C]:FrameLenNotMatch,len=%u\n",frame_len);
                t_stType = IPC_FRAME_TYPE_ERR;
        
            }
        }/* endif checksum == crc16_checksum(frame_len-2, p_uframe) */
        else
        {
            ipc_warn("[IPC-W-C]:CRCErr,ck=%u,len=%d\n",checksum,frame_len);
            t_stType = IPC_FRAME_TYPE_ERR;
        }
    }
    return (t_stType);
}

/*******************************************************************************
* Function: IPC_RecevieDataDecode
* Description: 
* Parameter: void
* Return: void
*******************************************************************************/    
static void IPC_RecevieDataDecode(uint8 *p_frame, uint16 frame_len)
{
	if((frame_len >= IPC_FRAME_HEAD_AND_CHECKSUM) && (NULL_PTR != p_frame))
	{
	    IPC_RecevieMessageDecode((p_frame + IPC_FRAME_HEAD_LEN), (frame_len - IPC_FRAME_HEAD_AND_CHECKSUM));
	    TST_IPC_CheckReceiver(frame_len);
	}
}


/*******************************************************************************
* Function: IPC_TriggerMainfunction
* Description: 
* Parameter: fromISR: TRUE, call from ISR
                      FALSE, not call from ISR
* Return: void
*******************************************************************************/  
void IPC_TriggerMainfunction(boolean fromISR)
{
	(void)fromISR;
    SetEvent(IPC,Rte_Ev_Run_IPC_IPC_MainFunction);
}

