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
 * @file:      iic1_Hardware.c
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

#include "string.h"
#include "hal_iic.h"
#include "IIC1_Hardware.h"
#include "dr7f701651.dvf.h"
#include "Cdd_Common.h"




/******************************************************************************
Typedef definitions
******************************************************************************/

/* iic interrupt define */
#define SET_IIC1_INT_DISABLE()           do{ \
                                        /* Set the interrupt flags */   \
                                            INTC2MKRIIC1TI = 1U;\
                                            INTC2RFRIIC1TI = 0U;\
                                            INTC2TBRIIC1TI = 1U;\
                                            INTC2P3RIIC1TI = 0U;\
                                                           \
                                            INTC2MKRIIC1TEI = 1U;\
                                            INTC2RFRIIC1TEI = 0U;\
                                            INTC2TBRIIC1TEI = 1U;\
                                            INTC2P3RIIC1TEI = 0U;\
                                                           \
                                            INTC2MKRIIC1RI = 1U;\
                                            INTC2RFRIIC1RI = 0U;\
                                            INTC2TBRIIC1RI = 1U;\
                                            INTC2P3RIIC1RI = 0U;\
                                                           \
                                            INTC2MKRIIC1EE = 1U;\
                                            INTC2RFRIIC1EE = 0U;\
                                            INTC2TBRIIC1EE = 1U;\
                                            INTC2P3RIIC1EE = 0U;\
                                        }while(0)
#define SET_IIC1_INT_ENABLE()            do{ \
                                            /* interrupt mask release */ \
                                            INTC2MKRIIC1TI  = 0U;    \
                                            INTC2MKRIIC1TEI = 0U;    \
                                            INTC2MKRIIC1RI  = 0U;    \
                                            INTC2MKRIIC1EE  = 0U;    \
                                        }while(0)
#define SET_ALTERNATIVE_FUN(PMCn,PIN_BIT)       (PMCn |= (PIN_BIT))
                                            /*special register*/
#define SET_PODC0_REG(reg32)                    do{  \
                                                     PORT.PPCMD0 = 0xA5u; \
                                                     PORT.PODC0 = (reg32);   \
                                                     PORT.PODC0 = ~(reg32);  \
                                                     PORT.PODC0 = (reg32);   \
                                                }while ( PORT.PPROTS0 != 0u );
#define SET_PORT_BOTH_DIRECT(PBDCn,PIN_BIT)     (PBDCn |= (PIN_BIT))
#define SET_OUTPUT(PMn,PIN_BIT)                 (PMn &= ~(PIN_BIT))


/* iic operate define */
#define IIC1_SEND_START()                do{RIIC1.CR2.UINT32 |= BIT1;}while(0)
#define IIC1_SEND_STOP()                 do{RIIC1.CR2.UINT32 |= BIT3;}while(0)
#define IIC1_SEND_BYTE(byte)             do{RIIC1.DRT.UINT32 = byte; }while(0)
#define IIC1_SEND_ACK()                  do{RIIC1.MR3.UINT32&= ~BIT3;}while(0)
#define IIC1_SEND_NACK()                 do{RIIC1.MR3.UINT32 |= BIT3;}while(0)

#define IIC1_GET_BYTE(byte)              do{byte = RIIC1.DRR.UINT32; }while(0)
#define IIC1_GET_TDRE()                  ((0u != (RIIC1.SR2.UINT32&BIT7)) ? 1:0)/*1: data empty*/
#define IIC1_GET_NACKF()                 ((0u != (RIIC1.SR2.UINT32&BIT4)) ? 1:0)/*1: NACK is detected.*/
#define IIC1_GET_TEND()                  ((0u != (RIIC1.SR2.UINT32&BIT6)) ? 1:0)/*1: Data has been transmitted.*/
#define IIC1_GET_RDRF()                  ((0u != (RIIC1.SR2.UINT32&BIT5)) ? 1:0)/*1: RIICnDRR contains receive data.*/
#define IIC1_GET_BUS_STATE()             ((0u != (RIIC1.CR2.UINT32&BIT7)) ? 1:0)/*1: The I2C bus is occupied */
#define IIC1_GET_STOP_FLAG()             ((0u != (RIIC1.SR2.UINT32&BIT3)) ? 1:0)/*1: Stop condition is detected.*/
#define IIC1_GET_START_FLAG()            ((0u != (RIIC1.SR2.UINT32&BIT2)) ? 1:0)/*1: Start condition is detected.*/

#define IIC1_CLEAR_TRANSMIT_END()        do{ RIIC1.SR2.UINT32 &= ~BIT6;}while(0)/* Clear Transmit End Flag.*/
#define IIC1_CLEAR_TRANSMIT_EMPTY()      do{ RIIC1.SR2.UINT32 &= ~BIT7;}while(0)/* */
#define IIC1_CLEAR_NACKF()               do{ RIIC1.SR2.UINT32 &= ~BIT4;}while(0)/* */
#define IIC1_CLEAR_RDRF()                do{ RIIC1.SR2.UINT32 &= ~BIT5;}while(0)/* */
#define IIC1_CLEAR_STOP_FLAG()           do{ RIIC1.SR2.UINT32 &= ~BIT3;}while(0)
#define IIC1_CLEAR_ALL_FLAG()            do{ RIIC1.SR2.UINT32 &= ~0x7Fu;}while(0)


#define IIC1_BUS_DISABLE()               do{ RIIC1.CR1.UINT32 &= ~BIT7;}while(0)
#define IIC1_BUS_ENABLE()                do{ RIIC1.CR1.UINT32 |= BIT7; }while(0)

#define IIC1_BUS_RESET()                 do{ RIIC1.CR1.UINT32 |= BIT6; }while(0)
#define IIC1_BUS_NO_RESET()              do{ RIIC1.CR1.UINT32 &= ~BIT6;}while(0)

#define IIC1_SET_ACKWP_EN()              do{ RIIC1.MR3.UINT32 |= BIT4; }while(0)
#define IIC1_SET_WAIT_EN()               do{ RIIC1.MR3.UINT32 |= BIT6; }while(0)
#define IIC1_SET_WAIT_DISABLE()          do{ RIIC1.MR3.UINT32 &= ~BIT6;}while(0)


/******************************************************************************
iic command define
******************************************************************************/

#define IIC1_CMD_WRITE                   ( 0x00U )
#define IIC1_CMD_READ                    ( 0x01U )

/******************************************************************************
iic public variant definitions
******************************************************************************/

static IIC1_OperateMgr_t IIC1Used;
static IIC1_BUS_STATE_t IIC1State;

typedef void (*p_iic1_callback)(IIC_QueueState_t state);
extern void IIC1_QueueResultUpdate(IIC_QueueState_t rcv);
static p_iic1_callback callback_func1 = &IIC1_QueueResultUpdate;

/******************************************************************************
* Function Name : uint8 IIC1_InspectBusState( void )
* Description   : return the IIC bus status
* Argument      : none
* Return Value  : uint8
******************************************************************************/
uint8 IIC1_InspectBusState(void)
{
    return (uint8)IIC1Used.busState;
}

/******************************************************************************
* Function Name : uint8 IIC1_InspectRunningState( void )
* Description   : return the IIC read/write result status
* Argument      : none
* Return Value  : uint8
******************************************************************************/
IIC1_BUS_STATE_t IIC1_InspectRunningState(void)
{
    return IIC1State;
}

/******************************************************************************
* Function Name : void IIC1_RegInit( void )
* Description   : This function initialize IIC.
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC1_RegInit(void)
{
    SET_IIC1_INT_DISABLE();
    //SET_PORT_AS_IIC1();
    /* Disabled I2C Bus Interface
    b 7          ICE    - I2C Bus Interface Enable    - Disabled (the RIICnSCL and RIICnSDA pins are not driven). set to 0
    */
    IIC1_BUS_DISABLE();
    /* I2C Bus Interface Internal Reset
    b 6          IICRST - I2C Bus Interface Internal Reset - Initiates the RIIC reset or internal reset. set to 1
    */
    IIC1_BUS_RESET();
    /* Enabled I2C Bus Interface
    b 7          ICE    - I2C Bus Interface Enable                    - Enabled (the RIICnSCL and RIICnSDA pins driven). set to 1
    */
    IIC1_BUS_ENABLE();
    
    RIIC1.SAR0.UINT32   = 0;
    /* Slave address in RIICnSAR0 is enabled.
    RIICnSER            - I2C Bus Status Enable Register
    b31:b 6             - Reserved set to 0
    b 5          DIDE   - Extra SCL Clock Cycle Output                - Device-ID address detection is disabled. set to 0
    b 4                 - Reserved set to 0
    b 3          GCE    - SCL Output Control/Monitor                  - General call address detection is disabled. set to 0
    b 2          SAR2   - SDA Output Control/Monitor                  - Slave address in RIICnSAR2 is disabled. set to 0
    b 1          SAR1   - SCL Line Monitor                            - Slave address in RIICnSAR1 is disabled. set to 0
    b 0          SAR0   - SDA Line Monitor                            - Slave address in RIICnSAR0 is enabled. set to 1 */
    RIIC1.SER.UINT32    = 0;
    /* Internal Reference Clock Selection.
    RIICnMR1            - I2C Bus Mode Register 1
    b31:b 8             - Reserved set to 0
    b 7          MTWP   - MST/TRS Write Protect                       - not change.
    b 6:b 4      CKS    - Internal Reference Clock Selection          - PCLK2/16 clock. set to 100'b
    b 3          BCWP   - BC Write Protect                            - not change.
    b 2:b 0      BC     - Bit Counter                                 - not change. */
    /*config the rate as 400Kbps*/
   // RIIC1.MR1.UINT32 |= BIT4;
   // RIIC1.BRH.UINT32  = 0xF9;
  //  RIIC1.BRL.UINT32  = 0xF9;
    
    /*config rate as 200Kbps*/
    RIIC1.MR1.UINT32 |= BIT4; /* IIC1_CLK = 40MHz / 2  */
    RIIC1.BRH.UINT32    = 0xF7;
    RIIC1.BRL.UINT32    = 0xF9;
    
    
    /* Set the I2C Bus Mode.
    RIICnMR2            - I2C Bus Mode Register 2
        BIT2 :  Count is enabled while the SCL line is at a high level.
        BIT1 :  Count is enabled while the SCL line is at a low level

    */
    RIIC1.MR2.UINT32    = BIT1;
    
    /* Set the I2C Bus functions.
    RIICnFER            - I2C Bus Function Enable Register
    b 4          NACKE  - NACK Reception Transfer Suspension Enable   - Transfer operation is suspended during NACK reception. set to 1
    */
    RIIC1.FER.UINT32    = BIT4|BIT0;//
    /* Set the Interrupts.
    RIICnIER            - I2C Bus Interrupt Enable Register
    b 7          TIE    - Transmit Data Empty Interrupt Enable        - Transmit data empty interrupt request (INTIICnTI) is enabled. set to 1
    b 6          TEIE   - Transmit End Interrupt Enable               - Transmit end interrupt request (INTIICnTEI) is enabled. set to 1
    b 5          RIE    - Receive Complete Interrupt Enable           - Receive complete interrupt request (INTIICnRI) is enabled. set to 1
    b 4          NAKIE  - NACK Reception Interrupt Enable             - NACK reception interrupt request (NAKI) is disabled. set to 0
    b 3          SPIE   - Stop Condition Detection Interrupt Enable   - Stop condition detection interrupt request (SPI) is enabled. set to 1
    b 2          STIE   - Start Condition Detection Interrupt Enable  - Start condition detection interrupt request (STI) is disabled. set to 0
    b 1          ALIE   - Arbitration-Lost Interrupt Enabl       e    - Arbitration-lost interrupt request (ALI) is disabled. set to 0
    b 0          TMOIE  - Timeout Interrupt Enable                    - Timeout interrupt request (TMOI) is disabled. set to 0 */
    RIIC1.IER.UINT32 = BIT7|BIT6|BIT5|BIT3;//|BIT0;
    /* I2C Bus Interface Internal Reset
    b 6   IICRST - I2C Bus Interface Internal Reset  - Clears the RIIC reset or internal reset. set to 0
    */
    IIC1_BUS_NO_RESET(); /* release from reset state */

    IIC1_CLEAR_ALL_FLAG();
	
	SET_IIC1_INT_ENABLE();
	
    (void)memset(&IIC1Used,0,sizeof(IIC1_OperateMgr_t));
    IIC1State = IIC1_STATE_IDLE;
}


/******************************************************************************
* Function Name : uint8 IIC1_TransmitData(uint8 addr, void *tx_buf, uint8 len)
* Description   : This function transmits the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
HAL_STATUS IIC1_TransmitData(uint8 addr, void *txBuf, uint8 len)
{
	HAL_STATUS ret = HAL_STATUS_OK;
    
    IIC1State = IIC1_STATE_IDLE;
    
    if(NULL_PTR == txBuf)
    {
        return HAL_STATUS_I2C_INVALID_HANDLE;
    }
    if(IIC1_GET_BUS_STATE())
    {
        IIC1_CLEAR_STOP_FLAG();      /* Clear Stop Condition Detection Flag */
        IIC1_SEND_STOP();            /* Requests to issue a stop condition*/
        return HAL_STATUS_I2C_BUS_BUSY;/* IIC1_bus busy */
    }
    
    IIC1Used.busState           = IIC1_STATE_SEND_ADDR_W;
    IIC1Used.operate.outBuf     = (uint8 *)txBuf;
    IIC1Used.operate.sendLength = len;
    IIC1Used.operate.sendCount  = 0;
    IIC1Used.operate.slaveAddr  = addr;
    
    IIC1_CLEAR_ALL_FLAG();
    IIC1_SEND_START();/* Requests to issue a start condition */

    return ret;
}

/******************************************************************************
* Function Name : uint8 IIC1_reception_data(uint8 addr, void *rx_buf, uint8 len)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
HAL_STATUS IIC1_ReceptionData(uint8 addr, void *rxBuf, uint8 len)
{
    HAL_STATUS ret = HAL_STATUS_OK;
    
    IIC1State = IIC1_STATE_IDLE;
    
    if(NULL_PTR == rxBuf)
    {
        return HAL_STATUS_I2C_INVALID_HANDLE;
    }
    if(IIC1_GET_BUS_STATE())
    {
        IIC1_CLEAR_STOP_FLAG();      /* Clear Stop Condition Detection Flag */
        IIC1_SEND_STOP();            /* Requests to issue a stop condition*/
        return HAL_STATUS_I2C_BUS_BUSY;/* IIC1_bus busy */
    }

    IIC1Used.busState              = IIC1_STATE_SEND_ADDR_R;
    IIC1Used.operate.recBuf        = (uint8 *)rxBuf;
    IIC1Used.operate.receiveLength = len;
    IIC1Used.operate.receiveCount  = 0;
    IIC1Used.operate.slaveAddr     = addr;

    IIC1_CLEAR_ALL_FLAG();
    IIC1_SEND_START();/* Requests to issue a start condition */

    return ret;
}

/******************************************************************************
* Function Name : void IIC1_transmit_empty_interrupt()
* Description   : iic send the hardware address and write/read command
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC1_TransmitEmptyInterrupt(void)
{
    /* first byte */
    if (IIC1Used.busState == IIC1_STATE_SEND_ADDR_W )
    {
        RIIC1.DRT.UINT32 = IIC1Used.operate.slaveAddr + IIC1_CMD_WRITE;
        IIC1Used.busState = IIC1_STATE_SENDING;
    }
    else if ( IIC1Used.busState == IIC1_STATE_SEND_ADDR_R )
    {
        RIIC1.DRT.UINT32 = IIC1Used.operate.slaveAddr + IIC1_CMD_READ;
        IIC1Used.busState   = IIC1_STATE_RECEIVE_1;
    }
}

/******************************************************************************
* Function Name : void IIC1_transmit_end_interrupt(void)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC1_TransmitEndInterrupt(void)
{
    uint8 delay = 20U;

    if (IIC1Used.busState == IIC1_STATE_SENDING )
    {
        /* NACK ? or Transmission end ?*/
        if ( IIC1_GET_NACKF() || (IIC1Used.operate.sendCount >= IIC1Used.operate.sendLength))
        {
            if(IIC1_GET_TEND())
            {
                IIC1_CLEAR_TRANSMIT_END();   /* Clear Transmit End Flag*/
                IIC1_CLEAR_STOP_FLAG();      /* Clear Stop Condition Detection Flag */
                IIC1_SEND_STOP();            /* Requests to issue a stop condition*/
                if(IIC1Used.operate.sendCount >= IIC1Used.operate.sendLength)
                {
                    IIC1Used.busState = IIC1_STATE_SEND_END;
                }
                else
                {
                    IIC1Used.busState = IIC1_STATE_SEND_ERROR;
                }
            }
        }
        else
        {
            RIIC1.DRT.UINT32 = IIC1Used.operate.outBuf[IIC1Used.operate.sendCount++];/* Write data*/

            /*Confirm TEND flag is cleared */
            while((delay > 0U) && (IIC1_GET_TEND()))
            {
                delay--;
            }
        }
    }
}

/******************************************************************************
* Function Name : void IIC1_event_interrupt(void)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC1_EventInterrupt(void)
{
    /* INTRIIC0EE (STOP) */
    if ( (IIC1Used.busState == IIC1_STATE_SEND_END)
        || (IIC1Used.busState == IIC1_STATE_RECEIVE_END_1) 
        || (IIC1Used.busState == IIC1_STATE_RECEIVE_END_2) 
        || (IIC1Used.busState == IIC1_STATE_SEND_ERROR)
        || (IIC1Used.busState == IIC1_STATE_RECV_ERROR))
    {
        if ( IIC1_GET_STOP_FLAG() )
        {
            if ( IIC1Used.busState == IIC1_STATE_RECEIVE_END_2 )
            {
                /* ACK write enable*/
                IIC1_SET_ACKWP_EN();
                /* set I2C Bus Mode
                RIICnMR3            - I2C Bus Mode Register 3
                b 5          RDRFS  - RDRF Flag Set Timing Selection
                                    - The RDRF flag is set at the rising edge of the ninth SCL clock cycle. set to 0
                b 3          ACKBT  - Transmit Acknowledge
                                    - A 0 is sent as the acknowledge bit (ACK transmission). set to 0
                */
                RIIC1.MR3.UINT32 &= ~(BIT5|BIT3);
            }
            /* Clear NACK Detection Flag  */
            IIC1_CLEAR_NACKF();
            /* Clear Stop Condition Detection Flag. */
            IIC1_CLEAR_STOP_FLAG();
            if(callback_func1 != NULL_PTR)
            {
                switch(IIC1Used.busState)
                {
                    case IIC1_STATE_SEND_END:
                    case IIC1_STATE_RECEIVE_END_1:
                    case IIC1_STATE_RECEIVE_END_2:    
                            callback_func1(I2C_QUEUE_SUCCESS);
                            break;
                    case IIC1_STATE_SEND_ERROR:
                    case IIC1_STATE_RECV_ERROR:
                            callback_func1(I2C_QUEUE_FAIL);
                            break;
                    default:
                    /* Do Nothing*/
                        break;
                }
            }
            IIC1Used.busState = IIC1_STATE_IDLE;
            
        }
    }
    IIC1_CLEAR_ALL_FLAG();
}

/******************************************************************************
* Function Name : void IIC1_reception_interrupt(void)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
/* INTRIIC0RI */
void IIC1_ReceptionInterrupt(void)
{
    uint32 dummy_read = 0u;
    dummy_read += 0u;	/*fix QAC & compile warning*/
    if ( IIC1Used.busState == IIC1_STATE_RECEIVE_1 )
    {
        if ( IIC1_GET_NACKF())
        {
            /* Clear Stop Condition Detection Flag*/
            IIC1_CLEAR_STOP_FLAG();
            /* Requests to issue a stop condition*/
            IIC1_SEND_STOP();
            /*dummy read*/
            IIC1_GET_BYTE(dummy_read);
            
            if ( IIC1Used.operate.receiveLength <= 2u )
            {
                IIC1Used.busState = IIC1_STATE_RECEIVE_END_2;
            }
            else
            {
                IIC1Used.busState = IIC1_STATE_RECEIVE_END_1;
            }

            if(IIC1Used.operate.receiveCount < IIC1Used.operate.receiveLength)
            {
                IIC1Used.busState = IIC1_STATE_RECV_ERROR;
            }
        }
        else
        {
            if ( IIC1Used.operate.receiveLength <= 2u )
            {
                /* WAIT      RIICnMR3   - I2C Bus Mode Register 3
                b 6          WAIT   - WAIT. set to 1  */
                IIC1_SET_WAIT_EN();
                if ( IIC1Used.operate.receiveLength == 2U )
                {
                    IIC1_GET_BYTE(dummy_read);
                    IIC1Used.busState   = IIC1_STATE_RECEIVE_2;
                }
                else
                {
                    IIC1_SET_ACKWP_EN(); /* NACK write enable*/
                    /* NACK
                    RIICnMR3            - I2C Bus Mode Register 3
                    b 5          RDRFS  - The RDRF flag is set at the rising edge of the eighth SCL clock cycle. set to 1
                    b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
                    */
                    RIIC1.MR3.UINT32 |= BIT5|BIT3;
                    IIC1_GET_BYTE(dummy_read);
                    IIC1Used.busState   = IIC1_STATE_RECEIVE_3;
                }
            }
            else
            {
                IIC1_GET_BYTE(dummy_read);
                IIC1Used.busState = IIC1_STATE_RECEIVE_4;
            }
        }
    }
    else if ( IIC1Used.busState == IIC1_STATE_RECEIVE_2 )
    {
        IIC1_SET_ACKWP_EN();/* NACK write enable*/
        /* NACK
        RIICnMR3            - I2C Bus Mode Register 3
        b 5          RDRFS  - The RDRF flag is set at the rising edge of the eighth SCL clock cycle. set to 1
        b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
        */
        RIIC1.MR3.UINT32 |= BIT5|BIT3;
        IIC1Used.operate.recBuf[IIC1Used.operate.receiveCount++] =(uint8) RIIC1.DRR.UINT32;
        IIC1Used.busState    = IIC1_STATE_RECEIVE_3;
    }
    else if ( IIC1Used.busState == IIC1_STATE_RECEIVE_3 )
    {
        IIC1_CLEAR_STOP_FLAG();/* Clear Stop Condition Detection Flag.*/
        IIC1_SEND_STOP();/* Requests to issue a stop condition*/
        /* read data */
        IIC1Used.operate.recBuf[IIC1Used.operate.receiveCount++] =(uint8) RIIC1.DRR.UINT32;
        IIC1_SET_ACKWP_EN();/* NACK write enable*/
        /* NACK      RIICnMR3            - I2C Bus Mode Register 3
        b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission)
        */
        IIC1_SEND_NACK();
        /* WAIT relese  RIICnMR3            - I2C Bus Mode Register 3
        b 6          WAIT    - no WAIT. set to 0
        */
        IIC1_SET_WAIT_DISABLE();
        IIC1Used.busState   = IIC1_STATE_RECEIVE_END_2;
    }
    else if ( IIC1Used.busState == IIC1_STATE_RECEIVE_4 )
    {
        if ( IIC1Used.operate.receiveLength == (IIC1Used.operate.receiveCount + 1u) )
        {
            /* Clear Stop Condition Detection Flag*/
            IIC1_CLEAR_STOP_FLAG();
            /* Requests to issue a stop condition*/
            IIC1_SEND_STOP();
            /*read data*/
            IIC1Used.operate.recBuf[IIC1Used.operate.receiveCount++] =(uint8) RIIC1.DRR.UINT32;
            /* WAIT relese  RIICnMR3            - I2C Bus Mode Register 3
            b 6          WAIT    - no WAIT. set to 0
            */
            IIC1_SET_WAIT_DISABLE();
            IIC1Used.busState   = IIC1_STATE_RECEIVE_END_1;
        }
        else if ( IIC1Used.operate.receiveLength == (IIC1Used.operate.receiveCount + 2u) )
        {
            /* NACK write enable*/
            IIC1_SET_ACKWP_EN();
            /* NACK      RIICnMR3 - I2C Bus Mode Register 3
            b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission)
            */
            IIC1_SEND_NACK();
            /*read data*/
            IIC1Used.operate.recBuf[IIC1Used.operate.receiveCount++] =(uint8) RIIC1.DRR.UINT32;
        }
        else if ( IIC1Used.operate.receiveLength == (IIC1Used.operate.receiveCount + 3u) )
        {
            IIC1_SET_WAIT_EN();
            IIC1Used.operate.recBuf[IIC1Used.operate.receiveCount++] =(uint8) RIIC1.DRR.UINT32;
        }
        else
        {
            IIC1Used.operate.recBuf[IIC1Used.operate.receiveCount++] =(uint8) RIIC1.DRR.UINT32;
        }
    }
}
