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
 * @file:      DSP_Test.c
 * @author:    Nobo
 * @date:      2020-6-22
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-22
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include <stdio.h>
#include <string.h>

#include "CDD_Test.h"
#include "DSP_Test.h"
#include "Dio.h"

#ifdef DSP_TEST





#define SPI_HW_CN               (SpiConf_SpiChannel_CSIH3)

#define DSP_BUFFER_SIZE     (20)


static uint8 DSP_Buffer_TX[DSP_BUFFER_SIZE];
static uint8 DSP_Buffer_RX[DSP_BUFFER_SIZE];
static uint8 uPCommand[] = {0xDE,0xAD,0xDA,0x7A};
static uint8 u8ReadDeviceIdentification[] = {0x40,0x01,0x30,0x00};



void DSP_Init(void)
{

    memset(DSP_Buffer_RX,0,DSP_BUFFER_SIZE);
    memset(DSP_Buffer_TX,0,DSP_BUFFER_SIZE);
}




void DSP_Transmit(void * buffer, uint16 len)
{

    CDD_TEST_ACCERT(len < DSP_BUFFER_SIZE);
    CDD_TEST_ACCERT(buffer !=  NULL_PTR);
    
    memcpy(DSP_Buffer_TX,buffer,len);
    Spi_SetupEB(SPI_HW_CN,DSP_Buffer_TX,DSP_Buffer_RX,len);
    Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence);

    
}

void DSP_uP_Interface(uint8 cmd)
{
     DSP_Transmit(uPCommand,sizeof(uPCommand));
}

uint8 DSP_DeviceIdentification = 0;

void DSP_MainFunction(void)
{
    static uint8 step = 0;

    switch(step)
    {
        case 0:
            Dio_WriteChannel(DioConf_DioChannel_VIP_SWITCH_SPI_CTRL,DIO_LOW_LEVEL_OUTPUT);
            step = 1;
            break;
        case 1:
            DSP_Transmit(uPCommand,sizeof(uPCommand));
            step = 2;
            break;
        case 2:
            DSP_Transmit(u8ReadDeviceIdentification,sizeof(u8ReadDeviceIdentification));
            step = 3;
            break;
        case 3:
            DSP_DeviceIdentification = DSP_Buffer_RX[3];
            step = 4;
            break;
        default:
            break;
}
}
uint8 DSP_GetDeviceIdentification(void)
{
    return DSP_DeviceIdentification;
}

#endif
