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
 * @file:      GNSS_Com.c
 * @author:    Nobo
 * @date:      2021-3-6
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2021-3-6
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "VariantCfg.h"
#ifdef PLATFOEM_OF_GNSS_USED

#include "GNSS_RI.h"
#include "GNSS_Com.h"

#include "uart.h"
#include "dma.h"

#include "GNSS_Alg.h"

// Module parameters
#define cGNSS_ALG_FIFO_DEEPTH                   (512u)          // 115200bps = 11 Byte/ms
#define cRLIN34_LDBR_ADDR                       (0xFFCE2100+0x26)

// GNSS Com mode state define
typedef enum 
{
    eGNSS_Com_Uninit = 0,
    eGNSS_Com_Ready,
    eGNSS_Com_Err,
}GNSS_Com_State_t;


// Private 
// GNSS COM state 
static GNSS_Com_State_t tGNSS_Com_State = eGNSS_Com_Uninit;

// Fifo parameters
static uint8 GNSS_Alg_FIFO[cGNSS_ALG_FIFO_DEEPTH];
static sint32 sFIFOReadPrt = 0;



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void GNSS_Com_Init(void)
{
    sFIFOReadPrt = 0;
    tGNSS_Com_State = eGNSS_Com_Ready;
	
    RB_Init(GNSS_TX_RING_BUFFER_ID);
    RB_Init(GNSS_RX_RING_BUFFER_ID);
    
    Uart_Init(UART_ID_GPS);
    Dma_ChannelConfiguration(DMA_GPS_RX,(void *)cRLIN34_LDBR_ADDR
    ,&GNSS_Alg_FIFO[0]
    ,cGNSS_ALG_FIFO_DEEPTH);
    Uart_Open(UART_ID_GPS);
    
}

void GNSS_Com_DeInit(void)
{
    Uart_Close(UART_ID_GPS);
    Uart_Deinit(UART_ID_GPS);
	Dma_ChannelStop(DMA_GPS_RX);
}

void GNSS_DmaErrDeal(void)
{
	static uint32 osTick;
	switch(tGNSS_Com_State)
	{
		case eGNSS_Com_Uninit:
			GNSS_GET_OSTick(&osTick);
			gnss_err("[GNSS-E]:at %d ms , Cause Not Init , Start Init \r\n",osTick);
			GNSS_Com_Init();
			//
			tGNSS_Com_State = eGNSS_Com_Ready;
			break;
		case eGNSS_Com_Ready:
			break;
		case eGNSS_Com_Err:
			GNSS_GET_OSTick(&osTick);
			gnss_err("[GNSS-E]:at %d ms , Gnss Com Err , Start DeInit . \r\n",osTick);
			GNSS_Com_DeInit();
			GNSS_Alg_Init();
			//
			tGNSS_Com_State = eGNSS_Com_Uninit;
			break;
		default:
			tGNSS_Com_State = eGNSS_Com_Uninit;
			break;
	}
}

/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint16 GNSS_Com_GetWritePrt(void)
{
    sint32 WritePrt = 0;
    
    WritePrt = Dma_ChannelTransferCnt((DMA_DEVICE_ID)DMA_GPS_RX);
    
    if ((WritePrt < 0)||(WritePrt > cGNSS_ALG_FIFO_DEEPTH))
    {
        gnss_warn("Lenth error WritePrt = %d.",WritePrt);
        tGNSS_Com_State = eGNSS_Com_Err;
        WritePrt = 0;
    }
	else if((0 == WritePrt) || (cGNSS_ALG_FIFO_DEEPTH == WritePrt))
	{
		if(TRUE == Dma_ChannelTransferComplete((DMA_DEVICE_ID)DMA_GPS_RX))
		{
			Dma_ChannelTransferCompleteClear((DMA_DEVICE_ID)DMA_GPS_RX);
			WritePrt = (sint32)cGNSS_ALG_FIFO_DEEPTH;
			gnss_verbose("Dma Complete Flag Appear , %d\r\n",WritePrt);
		}
		else
		{
			WritePrt = 0 ;
		}
	}
	else
    {
        WritePrt = (sint32)cGNSS_ALG_FIFO_DEEPTH - WritePrt;
    }
    return (uint16) WritePrt;
}


/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
static uint16 GNSS_Com_GetFifoLength(void)
{
    uint16 lenth = 0;
    uint16 WritePrt = 0;

    WritePrt = GNSS_Com_GetWritePrt();
    
    if (tGNSS_Com_State == eGNSS_Com_Ready)
    {
        if (WritePrt >= sFIFOReadPrt)
        {
            lenth = WritePrt - (uint16)sFIFOReadPrt;
        }
        else
        {
            lenth = WritePrt + cGNSS_ALG_FIFO_DEEPTH - (uint16)sFIFOReadPrt;
        }
    }
    else
    {
        lenth = 0;
    }

    return lenth;
}



/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
uint16 GNSS_Com_ReadData(uint8 * buffer,uint16 size)
{
    uint16 lenth = 0;
    uint32 i;
    
    lenth = GNSS_Com_GetFifoLength();

    if (size < lenth)
    {
        lenth = size;
    }
    
    for (i=0; i< lenth; i++)
    {
        buffer[i] = GNSS_Alg_FIFO[sFIFOReadPrt];
        sFIFOReadPrt++;
        if (sFIFOReadPrt >= cGNSS_ALG_FIFO_DEEPTH)
        {
            sFIFOReadPrt = 0;
        }
    }

    return lenth;
}

#define GNSS_GET_CURRENT_CFGNMEA	"$CFGNMEA\r\n"
/***********************************************************************
 * @brief       : 
 * @param       : 
 * @retval      : 
 ***********************************************************************/
void GNSS_Com_Monitoring(void)
{

	//(void)RI_GNSSNMEAData_Receive();
	//RI_GNSSNAVData_Receive
	//RI_GNSSFrameLossData_Receive

	
	GNSS_InputDeal_Mainfunction();
	GNSS_DmaErrDeal();
}


void GNSS_GroupParsing(uint8 major_msg_id, uint8 sub_msg_id,uint8* param, uint16 param_len)
{
    switch(major_msg_id)
    {
        case IPC_S2M_GNSS_MSGMAJOR_RESERVED_ID:
            break;
        case IPC_S2M_GNSS_MSGMAJOR_NMEA_ID:
			if(IPC_S2M_GNSS_NMEA_MSGSUB_READ_ID == sub_msg_id)
			{
				if(IPC_S2M_GNSS_NMEA_MSGSUB_READ_LENGTH == param_len)
				{
					app_GNSS_CMD_CFGNMEA_GetTriger();
				}
			}
			else if(IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_ID == sub_msg_id)
			{
				if(IPC_S2M_GNSS_NMEA_MSGSUB_WRITE_LENGTH == param_len)
				{
					app_GNSS_CMD_CFGNMEA_Set((eGNSSNMEA_t)(*param));
				}
			}
            break;
        case IPC_S2M_GNSS_MSGMAJOR_NAV_ID:
			if(IPC_S2M_GNSS_NAV_MSGSUB_READ_ID == sub_msg_id)
			{
				if(IPC_S2M_GNSS_NAV_MSGSUB_READ_LENGTH == param_len)
				{
					app_GNSS_CMD_CFGNAV_GetTriger();
				}
			}
			else if(IPC_S2M_GNSS_NAV_MSGSUB_WRITE_ID == sub_msg_id)
			{
				if(IPC_S2M_GNSS_NAV_MSGSUB_WRITE_LENGTH == param_len)
				{
					app_GNSS_CMD_CFGNAV_Set((eGNSSNAV_t)(*param));
				}
			}
            break;
        case IPC_S2M_GNSS_MSGMAJOR_FRAMELOSS_ID:
			if(IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_ID == sub_msg_id)
			{
				if(IPC_S2M_GNSS_FRAMELOSS_MSGSUB_READ_LENGTH == param_len)
				{
					app_GNSS_CMD_ERR_FRAME_GetTriger();
				}
			}
            break;
        case IPC_S2M_GNSS_MSGMAJOR_CONFIG_ID:
			switch(sub_msg_id)
			{
				case IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_ID:
					if(IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_READ_LENGTH == param_len)
					{
						app_GNSS_CMD_CFGNMEA_GetTriger();
						gnss_info("[GNSS-I]:CFGNMEA_GetTriger\r\n");
					}
					break;
				case IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_ID:
					if(IPC_S2M_GNSS_CONFIG_MSGSUB_NMEA_WRITE_LENGTH == param_len)
					{
						app_GNSS_CMD_CFGNMEA_Set((eGNSSNMEA_t)(*param));
						gnss_info("[GNSS-I]:CFGNMEA_Set = %d\r\n",(*param));
					}
					break;
				case IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_ID:
					if(IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_READ_LENGTH == param_len)
					{
						app_GNSS_CMD_CFGNAV_GetTriger();
						gnss_info("[GNSS-I]:CFGNAV_GetTriger\r\n");
					}
					break;
				case IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_ID:
					if(IPC_S2M_GNSS_CONFIG_MSGSUB_NAV_WRITE_LENGTH == param_len)
					{
						app_GNSS_CMD_CFGNAV_Set((eGNSSNAV_t)(*param));
						gnss_info("[GNSS-I]:CFGNAV_Set = %d\r\n",(*param));
					}
					break;
				case IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_ID:
					if(IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_READ_LENGTH == param_len)
					{
						app_GNSS_CMD_ERR_FRAME_GetTriger();
						gnss_info("[GNSS-I]:FRAME_GetTriger\r\n");
					}
					break;
				case IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_ID:
					if(IPC_S2M_GNSS_CONFIG_MSGSUB_FRAMELOSS_WRITE_LENGTH == param_len)
					{
						app_GNSS_CMD_ERR_FRAME_SetTriger(((uint16)param[0]<<8)&0xff00 + param[1]);
						gnss_info("[GNSS-I]:FRAME_Set = %d\r\n",(((uint16)param[0]<<8)&0xff00 + param[1]));
					}
					break;
				case IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_ID:
					if(IPC_S2M_GNSS_CONFIG_MSGSUB_PDTINFO_READ_LENGTH == param_len)
					{
						app_GNSS_CMD_PDTINFO_GetTriger();
						gnss_info("[GNSS-I]:PDTINFO_GetTriger\r\n");
					}
					break;
				default:
					/* nothing to do */
					break;
			}
			break;
		default:
			/* nothing to do */
			break;
    }
}

#endif
