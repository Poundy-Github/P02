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
 * @file:      Ipc_STB_Com.c
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
#include "Os.h"
#include "Dio.h"
#include "hal_spi.h"
#include "Dma.h"
#include "logger.h"
#include "IPC_STB_com.h"
#include "IPC_STB_Monitor.h"
#include "IPC_STB_If.h"
#include "csih_spi.h"
#include "Icu.h"
#include "Std_Types.h"
#include "Crc.h"
#include "Ipc_Cfg.h"
#include "Rtm.h"
#include "IPC_STB_LoadTest.h" 


e_IPC_STB_State_t IPC_STB_State;
static IPC_STB_Com_State_e IPC_STB_Com_State = IPC_STB_COM_SPITRANSPORT;
static uint16 IPC_STB_timer;
static uint16 IPC_STB_timeout_print_cnt=0;

static uint16 IPC_STB_RxFrameLen;

static boolean IPC_STB_ComComplete; /* IPC_STB Spi communication complete state */

extern uint8 IPC_STB_TxFrameBuffer[IPC_STB_DATA_FRAME_LENGTH]; /*IPC_STB DMA send data buffer.*/
extern uint8 IPC_STB_RxFrameBuffer[IPC_STB_DATA_FRAME_LENGTH];   /*DMA receive data buffer.*/
extern uint8 IPC_STB_TxAckBuffer[IPC_STB_ACK_FRAME_LENGTH];   /*Ack data buffer.*/
extern uint8 IPC_STB_RxRollCnt;


static void IPC_STB_Com_HardwareInit(void);
static void IPC_STB_SpiTransmit(uint8 * pTxBuf, uint16 tx_len,  uint8*pRxBuf, uint16 rx_len);
static void IPC_STB_SetMcuReq(void);
static void IPC_STB_ClearMcuReq(void); 

static void IPC_STB_ReceiveData(void);
static void IPC_STB_ReceiveAckData(void);
static e_IPC_STB_FrameType_t IPC_STB_CheckFrameType(uint8 * p_frame);
static void IPC_STB_RecevieDataDecode(uint8 *p_frame, uint16 frame_len);

#if IPC_STB_COM_RETRY_LIMIT == STD_ON

static uint8 Ipc_STB_ComContinuousNackCnt = 0;;

#endif


/*******************************************************************************
* Function: IPC_STB_Com_Init
* Description: Handle IPC_STB Monitor initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_Com_Init(void)
{
    IPC_STB_State = IPC_STB_STATE_IDLE;
    IPC_STB_RxFrameLen = 0;
    IPC_STB_Com_State = IPC_STB_COM_SPITRANSPORT;
    IPC_STB_timer = 0;
#if IPC_STB_COM_RETRY_LIMIT == STD_ON
    Ipc_STB_ComContinuousNackCnt = 0;
#endif

    IPC_STB_Com_HardwareInit();
}

/*******************************************************************************
* Function: IPC_STB_Com_DeInit
* Description: Handle IPC_STB Monitor initial
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_Com_DeInit(void)
{


}

/*******************************************************************************
* Function: IPC_STB_Com_HardwareInit
* Description: Handle IPC_STB hardware initial
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_STB_Com_HardwareInit(void)
{
    /* DMA, ICU, SPI */

}

/*******************************************************************************
* Function: IPC_STB_SpiTransmit
* Description: handle spi data transmit
* Parameter: 
* Return: void
*******************************************************************************/
static void IPC_STB_SpiTransmit(uint8 * pTxBuf, uint16 tx_len,  uint8*pRxBuf, uint16 rx_len)
{
    (void)Hal_Spi_Close(HAL_SPI_IPC_STB);
    (void)Hal_Spi_Open(HAL_SPI_IPC_STB);

    Dma_ChannelConfiguration(DMA_IPC_STB_TX
    ,&pTxBuf[1]
    ,(void *)IPC_STB_USER_TX_ADDR
    ,tx_len);

    Dma_ChannelConfiguration(DMA_IPC_STB_RX
    ,(void *)IPC_STB_USER_RX_ADDR
    ,&pRxBuf[0]
    ,rx_len);

    (void)Hal_Spi_Transmit(HAL_SPI_IPC_STB, &pTxBuf[0],1);
}

/*******************************************************************************
* Function: IPC_STB_SetMcuReq
* Description: Set Mcu transmit request
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_STB_SetMcuReq(void)
{
    TST_IPC_STB_CheckRequestTransport();
    Dio_WriteChannel(IPC_STB_VIP_SOC_REQ,STD_HIGH);
}
/*******************************************************************************
* Function: IPC_STB_SetMcuReq
* Description: clear Mcu transmit request
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_STB_ClearMcuReq(void)
{
    Dio_WriteChannel(IPC_STB_VIP_SOC_REQ,STD_LOW);
}

/*******************************************************************************
* Function: IPC_STB_SetMcuReq
* Description: Get Soc transmit request status
* Parameter: void
* Return: void
*******************************************************************************/
boolean IPC_STB_GetSocReq(void)
{
    boolean ret = FALSE;
   // if(STD_HIGH == Dio_ReadChannel(DioConf_DioChannel_VIP_SOC_REQ))
    if(ICU_HIGH == IPC_STB_GET_SOC_VIP_REQ())
    {
        ret = TRUE;
    }
    return ret;
}

/*******************************************************************************
* Function: IPC_STB_IsrCsDetect
* Description: SPI Cs High detect, interrupt
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_IsrCsDetect_Standby(void)
{
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
	
    if(ICU_HIGH == IPC_STB_GET_SOC_VIP_CS())
    {
        TST_IPC_STB_CheckSPITransportEnd();
        /* CS Disable, Communication done, Trigger IPC_STB_Mainfunction */
        IPC_STB_ComComplete = TRUE;
        IPC_STB_TriggerMainfunction(TRUE);
        
    }
    else
    {
        /* CS Enable, Clear MCU request: Todo, send message clear request in task */
        IPC_STB_ClearMcuReq();
        
    }
	
	Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
}

/*******************************************************************************
* Function: IPC_STB_IsrSocReqDetect
* Description: SOC Request High detect, interrupt
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_IsrSocReqDetect2(void)
{
	Rtm_Start(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
    /* SOC Request communication, Trigger IPC_STB_Mainfunction */
    IPC_STB_TriggerMainfunction(TRUE);
    
	Rtm_Stop(RtmConf_RtmMeasurementPoint_Interrupt_Callout);
}

/*******************************************************************************
* Function: IPC_STB_DmaStop
* Description: Stop DMA transmit
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_STB_DmaStop(void)
{
    Dma_ChannelStop(DMA_IPC_STB_TX);
    Dma_ChannelStop(DMA_IPC_STB_RX);
}

/*******************************************************************************
* Function: IPC_STB_GetIPC_STBState
* Description: Get IPC_STB state
* Parameter: void
* Return: e_IPC_STB_State_t
*******************************************************************************/
e_IPC_STB_State_t IPC_STB_GetIPC_STBState(void)
{
    return IPC_STB_State;
}

/*******************************************************************************
* Function: IPC_STB_SetState
* Description: set IPC_STB state
* Parameter: e_IPC_STB_State_t
* Return: void
*******************************************************************************/
void IPC_STB_SetState(e_IPC_STB_State_t state)
{
    IPC_STB_State = state;
    IPC_STB_timer = 0; 
    IPC_STB_Com_State = IPC_STB_COM_SPITRANSPORT;
}
extern void TM_Timer1msStartStamp(uint32 * StartStamp);

/*******************************************************************************
* Function: IPC_STB_SendData
* Description: Handle IPC_STB Senddata state
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_SendData(void)
{
	uint32 curOsTimer=0;
    if(IPC_STB_Com_State == IPC_STB_COM_SPITRANSPORT)
    {
        IPC_STB_ComComplete = FALSE;
        IPC_STB_SpiTransmit(IPC_STB_TxFrameBuffer, IPC_STB_DATA_FRAME_LENGTH, IPC_STB_RxFrameBuffer, IPC_STB_DATA_FRAME_LENGTH);
        IPC_STB_Com_State = IPC_STB_COM_DATARECEIVE;
		IPC_STB_timer = 0 ;

        IPC_STB_SetMcuReq();
    }
    else if(IPC_STB_Com_State == IPC_STB_COM_DATARECEIVE)
    {
        if(IPC_STB_ComComplete == TRUE)
        {
            IPC_STB_ComComplete = FALSE;
			IPC_STB_timeout_print_cnt = 0 ;
            IPC_STB_DmaStop();
            IPC_STB_ClearMcuReq();
            IPC_STB_ReceiveData();
        }
        else
        {
            IPC_STB_timer ++;

            if(IPC_STB_timer >= IPC_STB_COM_TIMEOUT)
            {
                /* Timeout, Set IPC_STB State Datasend to resend */
                IPC_STB_DmaStop();
                IPC_STB_ClearMcuReq();
                IPC_STB_SetState(IPC_STB_STATE_DATASEND);
                /* Error log every IPC_STB_COM_TIMEOUT*IPC_STB_COM_TIMEOUT_CNT ms*/
				if((IPC_STB_timeout_print_cnt%IPC_STB_COM_TIMEOUT_CNT) == 0)
				{
					TM_Timer1msStartStamp(&curOsTimer);
	                ipc_warn("[IPC-STB-W]:%d ms,DataSwapTimeout\r\n",curOsTimer);
				}
				IPC_STB_timeout_print_cnt++;
            }
        }
    }
    else
    {
        /* Do nothing */
    }

}

/*******************************************************************************
* Function: IPC_STB_AckData
* Description: Handle IPC_STB Ackdata state
* Parameter: void
* Return: void
*******************************************************************************/
void IPC_STB_AckData(void)
{
	uint32 curOsTimer=0;
    if(IPC_STB_Com_State == IPC_STB_COM_SPITRANSPORT)
    {
        IPC_STB_ComComplete = FALSE;
        IPC_STB_SpiTransmit(IPC_STB_TxAckBuffer, IPC_STB_DATA_FRAME_LENGTH, IPC_STB_RxFrameBuffer, IPC_STB_DATA_FRAME_LENGTH);
        IPC_STB_timer = 0;
        IPC_STB_Com_State = IPC_STB_COM_DATARECEIVE;

        IPC_STB_SetMcuReq();
    }
    else if(IPC_STB_Com_State == IPC_STB_COM_DATARECEIVE)
    {
        if(IPC_STB_ComComplete == TRUE)
        {
            IPC_STB_ComComplete = FALSE;
			IPC_STB_timeout_print_cnt = 0 ;
            IPC_STB_DmaStop();
            IPC_STB_ClearMcuReq();
            IPC_STB_ReceiveAckData();
        }
        else
        {
            IPC_STB_timer ++;

            if(IPC_STB_timer >= IPC_STB_COM_TIMEOUT)
            {
                /* Timeout, Set IPC_STB State Datasend to resend */
                IPC_STB_DmaStop();
                IPC_STB_ClearMcuReq();
                IPC_STB_SetState(IPC_STB_STATE_DATASEND);
                /* Error log every IPC_STB_COM_TIMEOUT*IPC_STB_COM_TIMEOUT_CNT ms*/
				if((IPC_STB_timeout_print_cnt%IPC_STB_COM_TIMEOUT_CNT) == 0)
				{
					TM_Timer1msStartStamp(&curOsTimer);
	                ipc_warn("[IPC-STB-W]:%d ms,AckSwapTimeout\r\n",curOsTimer);
				}
				IPC_STB_timeout_print_cnt++;
            }
        }
    }
    else
    {
        /* Do nothing */
    }

}

/*******************************************************************************
* Function: IPC_STB_ReceiveData
* Description: Handle IPC_STB receive data
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_STB_ReceiveData(void)
{
    e_IPC_STB_FrameType_t eFrameType;
    eFrameType = IPC_STB_CheckFrameType(IPC_STB_RxFrameBuffer);

    switch(eFrameType)
    {
    	//N-1:Swap Data , Recv Data
        case IPC_STB_FRAME_TYPE_DATA:            
            IPC_STB_RecevieDataDecode(IPC_STB_RxFrameBuffer,IPC_STB_RxFrameLen);
            
            IPC_STB_PrepareAckData(IPC_STB_ACK_DATA);
            IPC_STB_SetState(IPC_STB_STATE_ACK);
            /* Receive data decode complete, trigger mainfunction to start ack data */
            IPC_STB_TriggerMainfunction(FALSE);
            break;
		//N-2:Swap Data , Recv Data , But Was Dummy
        case IPC_STB_FRAME_TYPE_DUMMY:
            IPC_STB_PrepareAckData(IPC_STB_ACK_DATA);
            IPC_STB_SetState(IPC_STB_STATE_ACK);
            IPC_STB_TriggerMainfunction(FALSE);
            break;
        //N-3:Swap Data , Recv Data , But Data Roll Error    
        case IPC_STB_FRAME_TYPE_DATA_ERR_ROLL:
            ipc_warn("[IPC-STB-W-D]:D-Swaped,R-D,RollCntWasErr\r\n");
            IPC_STB_ClearRollCounter();   /* Clear roll counter */
            /* Receive data error, send ack error roll, not reprepare data and re send data */
            IPC_STB_PrepareAckData(IPC_STB_NACK_ERR_ROLL);  
            IPC_STB_SetState(IPC_STB_STATE_ACK);
            IPC_STB_TriggerMainfunction(FALSE);            
            break;
        //abN-1:Swap Data , Recv ACK , Type Was ACK_ERR_ROLL    
        case IPC_STB_FRAME_TYPE_ACK_ERR_ROLL:
            ipc_warn("[IPC-STB-W-D]:D-Swaped,R-A,RollCntWasErr\r\n");
            IPC_STB_ClearRollCounter();   /* Clear roll counter */
            IPC_STB_RePrepareSendData(); /* Roll counter error, reprepare send data */
            IPC_STB_SetState(IPC_STB_STATE_DATASEND);
            IPC_STB_TriggerMainfunction(FALSE);            
            break;  
        //N-4:Swap Data ,Type Error    
        case IPC_STB_FRAME_TYPE_ERR:
            ipc_warn("[IPC-STB-W-D]:D-Swaped,FrameTypeErr,CKup\r\n");
            IPC_STB_PrepareAckData(IPC_STB_NACK_DATA);
            IPC_STB_SetState(IPC_STB_STATE_ACK);
            IPC_STB_TriggerMainfunction(FALSE);
            break;
            
        case IPC_STB_FRAME_TYPE_ACK:
            ipc_warn("[IPC-STB-W-D]:D-Swaped,R-A,CKup\r\n");
			/* Host Ack or error state, keep in data send state to sync with host */
            IPC_STB_SetState(IPC_STB_STATE_DATASEND);
            IPC_STB_TriggerMainfunction(FALSE); 
            break;
        case IPC_STB_FRAME_TYPE_NACK:
			ipc_warn("[IPC-STB-W-D]:D-Swaped,R-NA,CKup\r\n");
			/* Host Ack or error state, keep in data send state to sync with host */
            IPC_STB_SetState(IPC_STB_STATE_DATASEND);
			#if(STD_ON == IPC_STB_COM_NACK_CHECK_EN)	
				if(FALSE == IPC_STB_NackCheck())
				{
					IPC_STB_ClearRollCounter();
					IPC_STB_SetState(IPC_STB_STATE_IDLE);
					ipc_warn("[IPC-STB-E]:data tampered ,discard it!\r\n");
				}
			#endif
            IPC_STB_TriggerMainfunction(FALSE); 
            break;

        default:
			/* nothing to do */
            break;
    }
}

/*******************************************************************************
* Function: IPC_STB_ReceiveData
* Description: Handle IPC_STB receive Ack data
* Parameter: void
* Return: void
*******************************************************************************/
static void IPC_STB_ReceiveAckData(void)
{
    e_IPC_STB_FrameType_t eFrameType;

    eFrameType = IPC_STB_CheckFrameType(IPC_STB_RxFrameBuffer);
    
#if IPC_STB_COM_RETRY_LIMIT == STD_ON
    if (eFrameType == IPC_STB_FRAME_TYPE_NACK)
    {
        Ipc_STB_ComContinuousNackCnt ++;
    }
    else
    {
        Ipc_STB_ComContinuousNackCnt = 0;
    }
#endif
    switch(eFrameType)
    {
    	//N-1:Swap Ack , Recv Ack
        case IPC_STB_FRAME_TYPE_ACK:
            IPC_STB_SetState(IPC_STB_STATE_IDLE);
            /* Set IPC_STB status Ready */
//            IPC_STB_SetIPC_STBStateType(IPC_STB_CONN_READY);
            IPC_STB_TriggerMainfunction(FALSE);
            break;
			
		//abN-1:Swap Ack , Recv Data
        case IPC_STB_FRAME_TYPE_DATA:
            IPC_STB_RecevieDataDecode(IPC_STB_RxFrameBuffer,IPC_STB_RxFrameLen);
            /* Sync with master state */
            IPC_STB_PrepareAckData(IPC_STB_ACK_DATA);
            IPC_STB_SetState(IPC_STB_STATE_ACK);   
            IPC_STB_TriggerMainfunction(FALSE);
            break;
			
		//abN-2:Swap Ack , Recv Dummy
        case IPC_STB_FRAME_TYPE_DUMMY:
            /* Sync with master state */
            IPC_STB_PrepareAckData(IPC_STB_ACK_DATA);
            IPC_STB_SetState(IPC_STB_STATE_ACK);            
            IPC_STB_TriggerMainfunction(FALSE);
            break;
			
        //abN-3:Swap Ack , Recv DATA    
        case IPC_STB_FRAME_TYPE_DATA_ERR_ROLL:
            ipc_warn("[IPC-STB-W-A]:A-Swaped,R-D,RollCntWasErr\r\n");
            IPC_STB_ClearRollCounter();  /* Clear roll counter */
            /* Receive data error, send ack error roll, not reprepare data and re send data */
            IPC_STB_PrepareAckData(IPC_STB_NACK_ERR_ROLL);
            IPC_STB_SetState(IPC_STB_STATE_ACK);
            IPC_STB_TriggerMainfunction(FALSE);
			break;
			
        //N-2:Swap Ack , Recv Ack     
        case IPC_STB_FRAME_TYPE_ACK_ERR_ROLL:
            ipc_warn("[IPC-STB-W-A]:A-Swaped,R-A,RollCntWasErr\r\n");
            IPC_STB_ClearRollCounter();   /* Clear roll counter */
            IPC_STB_RePrepareSendData(); /* Roll counter error, reprepare send data */            
            IPC_STB_SetState(IPC_STB_STATE_DATASEND);
            IPC_STB_TriggerMainfunction(FALSE);

            break;
            
        case IPC_STB_FRAME_TYPE_NACK: 
            ipc_warn("[IPC-STB-W-A]:A-Swaped,R-NA,CKup\r\n");
		    /* Host Ack or error state, keep in data send state to sync with host */
            IPC_STB_SetState(IPC_STB_STATE_DATASEND);
			
			#if(STD_ON == IPC_STB_COM_NACK_CHECK_EN)	
				if(FALSE == IPC_STB_NackCheck())
				{
					IPC_STB_ClearRollCounter();
					IPC_STB_SetState(IPC_STB_STATE_IDLE);
					ipc_warn("[IPC-STB-E]:data tampered ,discard it!\r\n");
				}
				else
			#endif
				{
			#if IPC_STB_COM_RETRY_LIMIT == STD_ON
				if (Ipc_STB_ComContinuousNackCnt >= IPC_STB_COM_MAX_RETRY_TIMES)
				{
					Ipc_STB_ComContinuousNackCnt = 0;
					ipc_warn("[IPC-STB-W-A]:A-Swaped,R-NA,Retry Timeout\r\n");
					IPC_STB_ClearRollCounter();
					IPC_STB_SetState(IPC_STB_STATE_IDLE);
				}
			#endif
				}
            IPC_STB_TriggerMainfunction(FALSE);
            break;
			

			
        case IPC_STB_FRAME_TYPE_ERR:
            ipc_warn("[IPC-STB-W-A]:A-Swaped,FrameTypeErr,CKup\r\n");
            /* Host Ack or error state, keep in data send state to sync with host */
            IPC_STB_SetState(IPC_STB_STATE_DATASEND);
            IPC_STB_TriggerMainfunction(FALSE);
            break;

        default:
			/* nothing to do */
            break;
     }
}

/*******************************************************************************
* Function: IPC_STB_CheckFrameType
* Description: 
* Parameter: void
* Return: void
*******************************************************************************/
static e_IPC_STB_FrameType_t IPC_STB_CheckFrameType(uint8 * p_frame)
{
    uint8 *p_uframe;
    uint16 frame_len;
    uint16 checksum;
    e_IPC_STB_FrameType_t t_stType;

    t_stType = IPC_STB_FRAME_TYPE_DUMMY;

    if(p_frame == NULL_PTR)
    {
        t_stType = IPC_STB_FRAME_TYPE_ERR;
        ipc_warn("[IPC-STB-W-C]:p_frame Was Null");
    }

    if(t_stType != IPC_STB_FRAME_TYPE_ERR)
    {
        p_uframe = &p_frame[0];
        frame_len = (((uint16)p_uframe[0]) << 8) + (uint16)p_uframe[1];
        if ((frame_len<IPC_STB_ACK_FRAME_LENGTH) || (frame_len>IPC_STB_DATA_FRAME_LENGTH))
        {
            ipc_warn("[IPC-STB-W-C]:FrameLenErr,len=%u\n",frame_len);
            t_stType = IPC_STB_FRAME_TYPE_ERR;
        }
    }

    if (t_stType != IPC_STB_FRAME_TYPE_ERR)
    {
        checksum = ((uint16)p_uframe[frame_len-2] * 0x100u) + (uint16)p_uframe[frame_len-1];

        if (checksum == Crc_CalculateCRC16(p_uframe,frame_len-2, 0,TRUE))
        {
            if(frame_len == IPC_STB_DUMMY_FRAME_LENGTH)
            {
                t_stType = IPC_STB_FRAME_TYPE_DUMMY;
            }
            else if(frame_len == IPC_STB_ACK_FRAME_LENGTH)
            {
                /*receive ack message*/
                if(p_uframe[2] == IPC_STB_ACK_DATA)
                {
                    t_stType = IPC_STB_FRAME_TYPE_ACK;
                }
                else if (p_uframe[2] == IPC_STB_NACK_DATA)
                {
                    t_stType = IPC_STB_FRAME_TYPE_NACK;
                }
                else if (p_uframe[2] == IPC_STB_NACK_ERR_ROLL)
                {
                    t_stType = IPC_STB_FRAME_TYPE_ACK_ERR_ROLL;
                    ipc_warn("[IPC-STB-W-C]:A-WasErrRollCnt,T=%d\n",p_uframe[2]);
                }
                else
                {
                    ipc_warn("[IPC-STB-W-C]:AckTypeErr,T=%u\n",p_uframe[2]);
                    t_stType = IPC_STB_FRAME_TYPE_ERR;
                }
            }
            else if((frame_len >= IPC_STB_FRAME_MIN_LEN) && (frame_len <= IPC_STB_DATA_FRAME_LENGTH))
            {
                /*receive message handling*/
                IPC_STB_RxFrameLen = frame_len;

                if(++IPC_STB_RxRollCnt == p_uframe[2])
                {
                    t_stType = IPC_STB_FRAME_TYPE_DATA;
                }
                else
                {
                    t_stType = IPC_STB_FRAME_TYPE_DATA_ERR_ROLL;
                    ipc_warn("[IPC-STB-W-C]:D-RolCntErr,e=%u,r=%u\n",IPC_STB_RxRollCnt,p_uframe[2]);
                }
            }
            else
            {
                ipc_warn("[IPC-STB-W-C]:FrameLenNotMatch,len=%u\n",frame_len);
                t_stType = IPC_STB_FRAME_TYPE_ERR;
        
            }
        }/* endif checksum == crc16_checksum(frame_len-2, p_uframe) */
        else
        {
            ipc_warn("[IPC-STB-W-C]:CRCErr,ck=%u,len=%d\n",checksum,frame_len);
            t_stType = IPC_STB_FRAME_TYPE_ERR;
        }
    }
    return (t_stType);
}

/*******************************************************************************
* Function: IPC_STB_RecevieDataDecode
* Description: 
* Parameter: void
* Return: void
*******************************************************************************/    
static void IPC_STB_RecevieDataDecode(uint8 *p_frame, uint16 frame_len)
{

    IPC_STB_RecevieMessageDecode(p_frame + IPC_STB_FRAME_HEAD_LEN, frame_len - IPC_STB_FRAME_HEAD_AND_CHECKSUM);
    TST_IPC_STB_CheckReceiver(frame_len);
}


/*******************************************************************************
* Function: IPC_STB_TriggerMainfunction
* Description: 
* Parameter: fromISR: TRUE, call from ISR
                      FALSE, not call from ISR
* Return: void
*******************************************************************************/  
void IPC_STB_TriggerMainfunction(boolean fromISR)
{
	(void)fromISR;
    (void)SetEvent(IPC,Rte_Ev_Run_IPC_IPC_STB_MainFunction);
}

#endif

