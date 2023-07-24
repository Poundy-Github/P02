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
 * @file:      csih_spi.c
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
#include "csih_spi.h"
#include "hal_spi.h"

typedef struct CSIH_RegDef_t
{                                                          /* Module           */
    uint8  CTL0;                                           /* CTL0             */
    uint8  dummy927[3];                                    /* Reserved         */
    const uint32 STR0;                                     /* STR0             */
    uint16 STCR0;                                          /* STCR0            */
    uint8  dummy928[6];                                    /* Reserved         */
    uint32 CTL1;                                           /* CTL1             */
    uint16 CTL2;                                           /* CTL2             */
    uint8  dummy929[2];                                    /* Reserved         */
    uint8  EMU;                                        	   /* EMU              */
    uint8  dummy930[4071];                                 /* Reserved         */
    uint32 MCTL1;                                          /* MCTL1            */
    uint32 MCTL2;                                          /* MCTL2            */
    uint32 TX0W;                                           /* TX0W             */
    uint16 TX0H;                                           /* TX0H             */
    uint8  dummy931[2];                                    /* Reserved         */
    const uint32 RX0W;                                     /* RX0W             */
    const uint16 RX0H;                                     /* RX0H             */
    uint8  dummy932[2];                                    /* Reserved         */
    uint32 MRWP0;                                          /* MRWP0            */
    uint8  dummy933[36];                                   /* Reserved         */
    uint16 MCTL0;                                          /* MCTL0            */
    uint8  dummy934[2];                                    /* Reserved         */
    uint32 CFG0;                                           /* CFG0             */
    uint32 CFG1;                                           /* CFG1             */
    uint32 CFG2;                                           /* CFG2             */
    uint32 CFG3;                                           /* CFG3             */
    uint32 CFG4;                                           /* CFG4             */
    uint32 CFG5;                                           /* CFG5             */
    uint32 CFG6;                                           /* CFG6             */
    uint32 CFG7;                                           /* CFG7             */
    uint8  dummy935[4];                                    /* Reserved         */
    uint16 BRS0;                                           /* BRS0             */
    uint8  dummy936[2];                                    /* Reserved         */
    uint16 BRS1;                                           /* BRS1             */
    uint8  dummy937[2];                                    /* Reserved         */
    uint16 BRS2;                                           /* BRS2             */
    uint8  dummy938[2];                                    /* Reserved         */
    uint16 BRS3;                                           /* BRS3             */
} CSIH_RegDef_t;


typedef CSIH_RegDef_t csih_RegDef;


//volatile csih_RegDef *Testcsih;

static csih_RegDef* const csih_spi_reg_table[SPI_BUS_MAX]=
{
    (csih_RegDef*)0xFFD80000, /* CSIH0 */
    (csih_RegDef*)0xFFD82000, /* CSIH1 */
    (csih_RegDef*)0xFFD84000, /* CSIH2 */
    (csih_RegDef*)0xFFD86000, /* CSIH3 */
};


/******************************************************************************
* Function Name : void csih_init_to_slave(uint8 csih_numb)
* Description   : set the csih to working slave mode
* Argument      : csih_numb
* Return Value  : none
******************************************************************************/
void csih_init_to_slave(uint8 csih_numb)
{
    volatile csih_RegDef* csih_reg;

//	Testcsih = (csih_RegDef *)csih_spi_reg_table[csih_numb];
    if(csih_numb > SPI_BUS_MAX)
	{
		return;
	}
    /*get the csih hardware register address*/
    csih_reg = (csih_RegDef *)csih_spi_reg_table[csih_numb];
	
    csih_reg->CTL0 =BIT0; /*stop CSIH*/
	
    csih_reg->CTL1 = BIT16;;  /*CSIHnCTL1.CSIHnCKR = 0, CS Default level High; */
	
    /*  (slave mode)   */
    csih_reg->CTL2 = BIT15|BIT14|BIT13;
    /*When using slave mode, disable the baud rate generator (BRG)*/
    csih_reg->BRS0 = 0;
    csih_reg->BRS1 = 0; 
    csih_reg->BRS2 = 0; 
    csih_reg->BRS3 = 0; 
    /*data config:
    bit31~bit30: - set as 0
    bit29~bit28: - No parity is transmitted
    bit27~bit24: - data length = 8
    bit19:       - CSIHnRCBx Selects the recessive configuration for broadcasting for chip select x.
                0: Dominant (higher priority)
                1: Recessive (lower priority)
    bit18:       - CSIHnDIRx Selects the serial data direction of chip select signal x.
                0: Data is transmitted/received with MSB first.
                1: Data is transmitted/received with LSB first
    bit17:       - CSIHnCKPx CSIHnCKPx: Clock phase selection bit
    bit16:       - CSIHnDAPx CSIHnDAPx: Data phase selection bit
    */
    /* CPOL 1；CPHA 1； */
    csih_reg->CFG0 = (8<<24);	/* CSIHnCTL1.CSIHnCKR = 0, CS Default level High,  CSIHnCKPx = 0;CSIHnDAPx = 0;  */
	/*  CSIHn Configuration Register
		bit27 to 24 CSIHnDLSx[3:0] :  8 data length 8bits
		bit17 CSIHnCKPx： Clock phase selection bit
		bit16 CSIHnDAPx:  Data phase selection bit

	*/	
	csih_reg->MCTL0 = 0x00;
	
    csih_reg->CTL0 |= BIT5; /* Permits reception */
    csih_reg->CTL0 |= BIT6; /* Permits transmission */
    csih_reg->CTL0 |= BIT7; /*Provides operation clock*/
}


/******************************************************************************
* Function Name : void hal_csih_close(uint8 csih_numb)
* Description   : close the cish function 
* Argument      : csih_numb
* Return Value  : none
******************************************************************************/
void csih_close(uint8 csih_numb)
{
    volatile csih_RegDef* csih_reg;

    if(csih_numb <= SPI_BUS_MAX)
    {
	    csih_reg = (csih_RegDef *)csih_spi_reg_table[csih_numb];
	    
	    csih_reg->CTL0 &=~BIT5;
	    csih_reg->CTL0 &=~BIT6;
	    csih_reg->CTL0 &=~BIT7;
    }
    
}

/******************************************************************************
* Function Name : void hal_csih_send_data(uint8 csih_numb,uint8 tx_buf)
* Description   : send one byte (tx_buf) data through csih_numb
* Argument      : csih_numb
* Return Value  : none
******************************************************************************/
void csih_slave_send_data(uint8 csih_numb,uint8 tx_buf)
{
    volatile csih_RegDef* csih_reg;

    if(csih_numb <= SPI_BUS_MAX)
    {
	    csih_reg = (csih_RegDef *)csih_spi_reg_table[csih_numb];
		csih_reg->STCR0 = 0xFFFF;   /*clear all flag*/
	    csih_reg->TX0H = tx_buf;
    }
}



