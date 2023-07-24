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
 * @file:      Dma.c
 * @author:    Nobo
 * @date:      2020-4-3
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-4-3
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "dr7f701651.dvf.h"
#include "Std_Types.h"
#include "Dma.h"

typedef struct DMA_RegDef_t
{
    uint32 DSA;
    uint32 DDA;
    uint32 DTC;
    uint32 DTCT;
    uint32 DRSA;
    uint32 DRDA;
    uint32 DRTC;
    uint8 dummy1[4];
    uint32 DCEN;
    uint32 DCST;
    uint32 DCSTS;
    uint32 DCSTC;    
    uint32 DTFR;
    const uint32 DTFRRQ;
    uint32 DTFRRQC;
}DMA_RegDef_t;

static DMA_RegDef_t* const dma_reg_table[]=
{
    (DMA_RegDef_t *)0xFFFF8400, /* DMAC0_0 */
    (DMA_RegDef_t *)0xFFFF8440, /* DMAC0_1 */
    (DMA_RegDef_t *)0xFFFF8480, /* DMAC0_2 */
    (DMA_RegDef_t *)0xFFFF84C0, /* DMAC0_3 */
    (DMA_RegDef_t *)0xFFFF8500, /* DMAC0_4 */
    (DMA_RegDef_t *)0xFFFF8540, /* DMAC0_5 */
    (DMA_RegDef_t *)0xFFFF8580, /* DMAC0_6 */
    (DMA_RegDef_t *)0xFFFF85C0, /* DMAC0_7 */
    (DMA_RegDef_t *)0xFFFF8600, /* DMAC1_0 */
    (DMA_RegDef_t *)0xFFFF8640, /* DMAC1_1 */
    (DMA_RegDef_t *)0xFFFF8680, /* DMAC1_2 */
    (DMA_RegDef_t *)0xFFFF86C0, /* DMAC1_3 */
    (DMA_RegDef_t *)0xFFFF8700, /* DMAC1_4 */
    (DMA_RegDef_t *)0xFFFF8740, /* DMAC1_5 */
    (DMA_RegDef_t *)0xFFFF8780, /* DMAC1_6 */
    (DMA_RegDef_t *)0xFFFF87C0, /* DMAC1_7 */
};

static uint32* const dma_master_set_reg_table[]=
{
    (uint32 *)0xFFFF8100, /* DMA0_0CM */
    (uint32 *)0xFFFF8104, /* DMA0_1CM */
    (uint32 *)0xFFFF8108, /* DMA0_2CM */
    (uint32 *)0xFFFF810C, /* DMA0_3CM */
    (uint32 *)0xFFFF8110, /* DMA0_4CM */
    (uint32 *)0xFFFF8114, /* DMA0_5CM */
    (uint32 *)0xFFFF8118, /* DMA0_6CM */
    (uint32 *)0xFFFF811C, /* DMA0_7CM */
    (uint32 *)0xFFFF8120, /* DMA1_0CM */
    (uint32 *)0xFFFF8124, /* DMA1_1CM */
    (uint32 *)0xFFFF8128, /* DMA1_2CM */
    (uint32 *)0xFFFF812C, /* DMA1_3CM */
    (uint32 *)0xFFFF8130, /* DMA1_4CM */
    (uint32 *)0xFFFF8134, /* DMA1_5CM */
    (uint32 *)0xFFFF8138, /* DMA1_6CM */
    (uint32 *)0xFFFF813C, /* DMA1_7CM */
};



/*******************************************************************************
 * Function:	Dma_Init
 * Description: set dma permissible option 
 * Invocation:	where this function is invoked
 * Parameter:	void
 * Return:	void
 *******************************************************************************/
void Dma_Init(void)
{
    /* Permit access  to external master with specified SPID.*/
    PEGSP = BIT0;
    PEGG1MK = 0xFFFFF000;
    /* Read/write access enable, GnSP1 peimit */
    PEGG1BA = BIT0 | BIT1 | BIT2 | BIT4 | BIT5;
}


void Dma_DeInit(void)
{
	uint8 id;
	for(id=0; id < DMA_USED_NUMB; id++)
	{
		Dma_TrasferStop(DMA_CONFIG_TABLE[id].hw_channel);
	}
}


static void Dma_WriteReg(Dma_typef *dma_user)
{
    volatile DMA_RegDef_t *dma_reg;
    volatile uint32 *dma_master_set_reg;
    
 	if(NULL_PTR != dma_user)
    {  
	    /* supervisor mode, SPID1,PE1*/
	    dma_master_set_reg = dma_master_set_reg_table[dma_user->channel];
	    *dma_master_set_reg = BIT2 | BIT4;

	    /* Channel protection violation clear */
	    PDMA0CMVC = BIT0 | BIT1;
	    
	    dma_reg = (DMA_RegDef_t *)dma_reg_table[dma_user->channel];

	    /*Channel operation is disabled*/
	    dma_reg->DCEN &= ~BIT0;
	    
	    /* DMA Source Address Register */
	    dma_reg->DSA=(uint32)dma_user->source_addr;
	    /*DMA Destination Address*/
	    dma_reg->DDA=(uint32)dma_user->dest_addr;
	    /*transfer count register  */
	    dma_reg->DTC = dma_user->transfer_times;   /*times*/
        /* DMA Reload Set */
	    if (dma_user->option & DMA_RELOAD_SOURCE)
	    {
	        dma_reg->DRSA=(uint32)dma_user->source_addr;
	        dma_reg->DRTC = dma_user->transfer_times;
	    }

        if (dma_user->option & DMA_RELOAD_DEST)
	    {
	        dma_reg->DRDA=(uint32)dma_user->dest_addr;
	        dma_reg->DRTC = dma_user->transfer_times;
	    }

	    /*DMA Transfer Control

		8, 7 DACM[1:0] Destination address count direction
			Specifies the count direction of the destination address.
			DACM1 DACM0 Direction of Count
			0		 0 		Increment
			0 		1 		Decrement
			1 		0 		Fixed
			1 		1 		Setting prohibited (The operation is not guaranteed.)
		6, 5 SACM[1:0] Source address count direction
			Specifies the count direction of the source address.
			SACM1 SACM0 Direction of Count
			0 		0 		Increment
			0 		1 		Decrement
			1 		0 		Fixed
			1 		1 		Setting prohibited (The operation is not guaranteed.)

		bit 1, 0 TRM[1:0] Transfer mode
			Specifies the DMA transfer mode.
			00: Single transfer
			01: Block transfer 1 (The number of transfers is specified by the transfer
			count.)
			10: Block transfer 2 (The number of transfers is specified by the address
			reload count.)
			11: Setting prohibited (The operation is not guaranteed.)
	    */
	    dma_reg->DTCT = dma_user->option | BIT26 | BIT27; /* single  transfer */

	    
	    /* DMA trigger factors : select the transfer source.*/
	    if(DMA_TRIGGER_SOFTWARE == dma_user->trigger_source)
	    {
	         dma_reg->DTFR = 0;
	    }
	    else// if(DMA_TRIGGER_INTCSIH3IR == dma_user->trigger_source)
	    {
	       /* set DMA trigger source */
	        dma_reg->DTFR= (dma_user->trigger_source <<1) | BIT0;
	    }
	    /* clear transfer status*/
	    dma_reg->DCSTC = BIT0 | BIT4 | BIT7;
	    dma_reg->DTFRRQC |= BIT0;

	    /*Channel operation is enabled*/
	    dma_reg->DCEN |= BIT0;
	}
}

void Dma_software_start(DMA_CHANNEL channel)
{
    volatile DMA_RegDef_t *dma_reg;
    
    dma_reg = (DMA_RegDef_t *)dma_reg_table[channel];
    /* clear dma transfer compeleted flag */
    /* trigger dma transfer */
    dma_reg->DCEN |= BIT0;
    dma_reg->DCSTS |= BIT0;
}

void Dma_TrasferStop(DMA_CHANNEL channel)
{
    volatile DMA_RegDef_t *dma_reg;
    
    dma_reg = (DMA_RegDef_t *)dma_reg_table[channel];
    /* disable dma transfer */
    dma_reg->DCEN &= ~BIT0;
}


void Dma_ChannelStop(DMA_DEVICE_ID user_id)
{
    uint8 id;

	for(id=0; id < DMA_USED_NUMB; id++)
	{
		if(user_id == DMA_CONFIG_TABLE[id].user_id)
		{
			Dma_TrasferStop(DMA_CONFIG_TABLE[id].hw_channel);
			break;
		}
	}
}

static uint16 Dma_TransferCnt(DMA_CHANNEL channel)
{
    volatile DMA_RegDef_t *dma_reg;
	sint32 max_wait_CY_cnt = 10000;//CPU_FREQ = 240Mhz , DMA_FREQ = 24Mhz , UART BYTE=0.0115200Mhz
    
    dma_reg = (DMA_RegDef_t *)dma_reg_table[channel];

	while(((dma_reg->DCST & BIT8) != 0 ) && (max_wait_CY_cnt > 0))//1: DMA cycle is ongoing.
	{
		max_wait_CY_cnt--;
	}
	
    /* disable dma transfer */
    return( (uint16)(dma_reg->DTC & 0xFFFFu) );
}


sint32 Dma_ChannelTransferCnt(uint8 user_id)
{
    uint8 id;
    sint32 ret=-1;
    
	for(id=0; id < DMA_USED_NUMB; id++)
	{
		if(user_id == DMA_CONFIG_TABLE[id].user_id)
		{
			ret = (sint32)Dma_TransferCnt(DMA_CONFIG_TABLE[id].hw_channel);
			break;
		}
	}
	return ret;
}

static boolean Dma_TransferComplete(DMA_CHANNEL channel)
{
    volatile DMA_RegDef_t *dma_reg;
	
    dma_reg = (DMA_RegDef_t *)dma_reg_table[channel];
    return ((((dma_reg->DCST & BIT4 ) == BIT4 )?TRUE:FALSE));
}
boolean Dma_ChannelTransferComplete(uint8 user_id)
{
    uint8 id;
    boolean ret=FALSE;
    
	for(id=0; id < DMA_USED_NUMB; id++)
	{
		if(user_id == DMA_CONFIG_TABLE[id].user_id)
		{
			ret = (boolean)Dma_TransferComplete(DMA_CONFIG_TABLE[id].hw_channel);
			break;
		}
	}
	return ret;
}
static void Dma_TransferCompleteClear(DMA_CHANNEL channel)
{
    volatile DMA_RegDef_t *dma_reg;
	
    dma_reg = (DMA_RegDef_t *)dma_reg_table[channel];
	dma_reg->DCSTC |= BIT4;//write 1 clear
}
void Dma_ChannelTransferCompleteClear(uint8 user_id)
{
    uint8 id;
    
	for(id=0; id < DMA_USED_NUMB; id++)
	{
		if(user_id == DMA_CONFIG_TABLE[id].user_id)
		{
			Dma_TransferCompleteClear(DMA_CONFIG_TABLE[id].hw_channel);
			break;
		}
	}
}




void Dma_ChannelConfiguration( DMA_DEVICE_ID user_id ,void *soure_address ,void *dest_address, uint16 times )
{
    Dma_typef dma_user;
    uint8 id;

  	if((NULL_PTR != soure_address) || (NULL_PTR != dest_address))
    {
		for(id=0; id < DMA_USED_NUMB; id++)
		{
			if(user_id == DMA_CONFIG_TABLE[id].user_id)
			{
				dma_user.channel = (DMA_CHANNEL)DMA_CONFIG_TABLE[id].hw_channel;
				dma_user.option = (DMA_OPTION)DMA_CONFIG_TABLE[id].option;
				dma_user.trigger_source = DMA_CONFIG_TABLE[id].trigger;
				
				dma_user.source_addr = (uint32 *)soure_address;
				dma_user.dest_addr = (uint32 *)dest_address;
				dma_user.transfer_times = times;
				
				Dma_WriteReg(&dma_user);
				/* clear all channel request */
				DMA_CLEARL_ALL_REQ();
				
				break;
			}
		}
    }
}
