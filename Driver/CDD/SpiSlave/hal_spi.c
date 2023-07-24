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
 * @file:      hal_spi.c
 * @author:    Nobo
 * @date:      2020-3-16
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-3-16
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "VariantCfg.h"

#include "Std_Types.h"
#include "Cdd_Common.h"
#include "csih_spi.h"
#include "hal_spi.h"


#include "Dma.h"
#include "Icu.h"
#include <string.h>


static Hal_Spi_Cfg Hal_Spi_CfgTable[HAL_SPI_DEVICE_MAX] =
{
	{ HAL_SPI_IPC,      SPI_BUS_CSIH1 },
#ifdef PLATFORM_OF_STB_IPC_USED
	{ HAL_SPI_IPC_STB,  SPI_BUS_CSIH2 }
#endif
	
};


/**************************************************************************************
 *
 * Function Name: Hal_Spi_Init
 *
 * Argumetns: void
 *
 * Return:  void
 *
 * Note: This function used to intialize the SPI HAL. Acctually it will not initialize the
 * 	     SPI device. It will intialize the SPI HAL.
 *
 **************************************************************************************/
void Hal_Spi_Init(void)
{


}

/**************************************************************************************
 *
 * Function Name: Hal_Spi_DeInit
 *
 * Argumetns: void
 *
 * Return:  void
 *
 * Note: This function used to intialize the SPI HAL. Acctually it will not initialize the
 * 	     SPI device. It will intialize the SPI HAL.
 *
 **************************************************************************************/
void Hal_Spi_DeInit(void)
{

	
}


/**************************************************************************************
 *
 * Function Name: Hal_Spi_Open
 *
 * Argumetns: device_id
 *
 * Return:  E_NOT_OK
 			E_OK
 *
 * Note: This function used to used to open the SPI device for further communication.
 *
 *
 **************************************************************************************/
uint8 Hal_Spi_Open(HAL_SPI_USED_NUM device_id)
{
	uint8 i;
	uint8 ret = E_NOT_OK;
	
	if(device_id < HAL_SPI_DEVICE_MAX)
	{
		for(i = 0; i < HAL_SPI_DEVICE_MAX; i++)
		{
			if(Hal_Spi_CfgTable[i].SWChannel == device_id)
			{
				csih_init_to_slave(Hal_Spi_CfgTable[i].HWChannel);
				ret = E_OK;
			}
		}
	}
    return ret;

}

/**************************************************************************************
 *
 * Function Name: Hal_Spi_Close
 *
 * Argumetns: device_id
 *
 * Return:	E_NOT_OK
			 E_OK
 *
 * Note: This function used to close the SPI handler.
 *
 **************************************************************************************/
uint8 Hal_Spi_Close(HAL_SPI_USED_NUM device_id)
{
	uint8 i;
	uint8 ret = E_NOT_OK;
	
	if(device_id < HAL_SPI_DEVICE_MAX)
	{
		for(i = 0; i < HAL_SPI_DEVICE_MAX; i++)
		{
			if(Hal_Spi_CfgTable[i].SWChannel == device_id)
			{
				csih_close(Hal_Spi_CfgTable[i].HWChannel);
				ret = E_OK;
			}
		}
	}
    return ret;


}

/**************************************************************************************
 *
 * Function Name: Hal_Spi_Transmit
 *
 * Argumetns: device_id，write_buffer，write_buffer_size
 *
 * Return:	E_NOT_OK
			E_OK
 *
 * Note: This function used to close the SPI handler.
 *
 **************************************************************************************/
uint8 Hal_Spi_Transmit(HAL_SPI_USED_NUM device_id,uint8 *write_buffer, uint16 write_buffer_size)
{
	uint8 i;
	uint8 ret = E_NOT_OK;
	
	if(device_id < HAL_SPI_DEVICE_MAX)
	{
		for(i = 0; i < HAL_SPI_DEVICE_MAX; i++)
		{
			if(Hal_Spi_CfgTable[i].SWChannel == device_id)
			{
				csih_slave_send_data(Hal_Spi_CfgTable[i].HWChannel,write_buffer[0]);
				ret = E_OK;
			}
		}
	}
    return ret;

}

#ifdef SPI_TEST

uint8 Txbuffer[20] ={ 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
uint8 Rxbuffer[20] = {0};
uint8 spi_com_done = 1;


void Hal_Spi_Test(void)
{

	if(spi_com_done == 1)
	{
		spi_com_done = 0;
	
		Hal_Spi_Close(HAL_SPI_IPC);
		Hal_Spi_Open(HAL_SPI_IPC);

		Dma_ChannelConfiguration(DMA_IPC_TX
                ,&Txbuffer[1]
                ,(void *)CSIH3_TX_ADDR
                ,20);

		Dma_ChannelConfiguration(DMA_IPC_RX
            ,(void *)CSIH3_RX_ADDR
            ,&Rxbuffer[0]
            ,20);

		Hal_Spi_Transmit(HAL_SPI_IPC, &Txbuffer[0],1);
	}
}

void Hal_Spi_Isr(void)
{
	
	if(ICU_HIGH == Icu_GetInputLevel(IcuConf_IcuChannel_SOC_VIP_CSIH3_CS))
	{
		spi_com_done = 1;
		memset(Rxbuffer, 0, 20);
	}
}

#endif
