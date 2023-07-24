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
 * @file:      iic_Hardware.c
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

#include "IIC_Hardware.h"
#include "hal_iic.h"
#include "string.h"
#include "dr7f701651.dvf.h"
#include "Cdd_Common.h"

/******************************************************************************
Typedef definitions
******************************************************************************/

/* iic interrupt define */
#define SET_IIC_INT_DISABLE()           do{ \
                                        /* Set the interrupt flags */   \
                                            INTC2MKRIIC0TI = 1U;\
                                            INTC2RFRIIC0TI = 0U;\
                                            INTC2TBRIIC0TI = 1U;\
                                            INTC2P3RIIC0TI = 0U;\
                                                           \
                                            INTC2MKRIIC0TEI = 1U;\
                                            INTC2RFRIIC0TEI = 0U;\
                                            INTC2TBRIIC0TEI = 1U;\
                                            INTC2P3RIIC0TEI = 0U;\
                                                           \
                                            INTC2MKRIIC0RI = 1U;\
                                            INTC2RFRIIC0RI = 0U;\
                                            INTC2TBRIIC0RI = 1U;\
                                            INTC2P3RIIC0RI = 0U;\
                                                           \
                                            INTC2MKRIIC0EE = 1U;\
                                            INTC2RFRIIC0EE = 0U;\
                                            INTC2TBRIIC0EE = 1U;\
                                            INTC2P3RIIC0EE = 0U;\
                                        }while(0)
#define SET_IIC_INT_ENABLE()            do{ \
                                            /* interrupt mask release */ \
                                            INTC2MKRIIC0TI  = 0U;    \
                                            INTC2MKRIIC0TEI = 0U;    \
                                            INTC2MKRIIC0RI  = 0U;    \
                                            INTC2MKRIIC0EE  = 0U;    \
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

#define SET_PORT_AS_IIC()               do{     \
                                            SET_ALTERNATIVE_FUN(PORT.PMC0,BIT11|BIT12);\
                                            /* open drain */                      \
                                            SET_PODC0_REG(PORT.PODC0|(BIT11|BIT12));   \
                                            SET_PORT_BOTH_DIRECT(PORT.PBDC0,BIT11|BIT12);\
                                            SET_OUTPUT(PORT.PM0,BIT11|BIT12);         \
                                            PORT.PFCAE0 &= ~(BIT11|BIT12);             \
                                            PORT.PFCE0  &= ~(BIT11|BIT12);             \
                                            PORT.PFC0   &= ~(BIT11|BIT12);             \
                                        }while(0)

/* iic operate define */
#define IIC_SEND_START()                do{RIIC0.CR2.UINT32 |= BIT1;}while(0)
#define IIC_SEND_STOP()                 do{RIIC0.CR2.UINT32 |= BIT3;}while(0)
#define IIC_SEND_BYTE(byte)             do{RIIC0.DRT.UINT32 = byte; }while(0)
#define IIC_SEND_ACK()                  do{RIIC0.MR3.UINT32&= ~BIT3;}while(0)
#define IIC_SEND_NACK()                 do{RIIC0.MR3.UINT32 |= BIT3;}while(0)

#define IIC_GET_BYTE(byte)              do{byte = RIIC0.DRR.UINT32; }while(0)
#define IIC_GET_TDRE()                  ((0u != (RIIC0.SR2.UINT32&BIT7)) ? 1:0)/*1: data empty*/
#define IIC_GET_NACKF()                 ((0u != (RIIC0.SR2.UINT32&BIT4)) ? 1:0)/*1: NACK is detected.*/
#define IIC_GET_TEND()                  ((0u != (RIIC0.SR2.UINT32&BIT6)) ? 1:0)/*1: Data has been transmitted.*/
#define IIC_GET_RDRF()                  ((0u != (RIIC0.SR2.UINT32&BIT5)) ? 1:0)/*1: RIICnDRR contains receive data.*/
#define IIC_GET_BUS_STATE()             ((0u != (RIIC0.CR2.UINT32&BIT7)) ? 1:0)/*1: The I2C bus is occupied */
#define IIC_GET_STOP_FLAG()             ((0u != (RIIC0.SR2.UINT32&BIT3)) ? 1:0)/*1: Stop condition is detected.*/
#define IIC_GET_START_FLAG()            ((0u != (RIIC0.SR2.UINT32&BIT2)) ? 1:0)/*1: Start condition is detected.*/

#define IIC_CLEAR_TRANSMIT_END()        do{ RIIC0.SR2.UINT32 &= ~BIT6;}while(0)/* Clear Transmit End Flag.*/
#define IIC_CLEAR_TRANSMIT_EMPTY()      do{ RIIC0.SR2.UINT32 &= ~BIT7;}while(0)/* */
#define IIC_CLEAR_NACKF()               do{ RIIC0.SR2.UINT32 &= ~BIT4;}while(0)/* */
#define IIC_CLEAR_RDRF()                do{ RIIC0.SR2.UINT32 &= ~BIT5;}while(0)/* */
#define IIC_CLEAR_STOP_FLAG()           do{ RIIC0.SR2.UINT32 &= ~BIT3;}while(0)
#define IIC_CLEAR_ALL_FLAG()            do{ RIIC0.SR2.UINT32 &= ~0x7Fu;}while(0)


#define IIC_BUS_DISABLE()               do{ RIIC0.CR1.UINT32 &= ~BIT7;}while(0)
#define IIC_BUS_ENABLE()                do{ RIIC0.CR1.UINT32 |= BIT7; }while(0)

#define IIC_BUS_RESET()                 do{ RIIC0.CR1.UINT32 |= BIT6; }while(0)
#define IIC_BUS_NO_RESET()              do{ RIIC0.CR1.UINT32 &= ~BIT6;}while(0)

#define IIC_SET_ACKWP_EN()              do{ RIIC0.MR3.UINT32 |= BIT4; }while(0)
#define IIC_SET_WAIT_EN()               do{ RIIC0.MR3.UINT32 |= BIT6; }while(0)
#define IIC_SET_WAIT_DISABLE()          do{ RIIC0.MR3.UINT32 &= ~BIT6;}while(0)


/******************************************************************************
iic command define
******************************************************************************/

#define IIC_CMD_WRITE                   ( 0x00U )
#define IIC_CMD_READ                    ( 0x01U )

/******************************************************************************
iic public variant definitions
******************************************************************************/

static IIC_OperateMgr_t tIIC_Used;
static IIC_BUS_STATE_t  tIIC_Sate;

typedef void (*p_iic_callback)(IIC_QueueState_t state);
extern void IIC_QueueResultUpdate(IIC_QueueState_t rcv);
p_iic_callback callback_func = &IIC_QueueResultUpdate;

/******************************************************************************
* Function Name : uint8 IIC_InspectBusState( void )
* Description   : return the IIC bus status
* Argument      : none
* Return Value  : uint8
******************************************************************************/
uint8 IIC_InspectBusState(void)
{
    return (uint8)tIIC_Used.busState;
}

/******************************************************************************
* Function Name : uint8 IIC_InspectRunningState( void )
* Description   : return the IIC read/write result status
* Argument      : none
* Return Value  : uint8
******************************************************************************/
IIC_BUS_STATE_t IIC_InspectRunningState(void)
{
    return tIIC_Sate;
}

/******************************************************************************
* Function Name : void hal_iic_init( void )
* Description   : This function initialize IIC.
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC_RegInit(void)
{
    SET_IIC_INT_DISABLE();
    SET_PORT_AS_IIC();
    /* Disabled I2C Bus Interface
    b 7          ICE    - I2C Bus Interface Enable    - Disabled (the RIICnSCL and RIICnSDA pins are not driven). set to 0
    */
    IIC_BUS_DISABLE();
    /* I2C Bus Interface Internal Reset
    b 6          IICRST - I2C Bus Interface Internal Reset - Initiates the RIIC reset or internal reset. set to 1
    */
    IIC_BUS_RESET();
    /* Enabled I2C Bus Interface
    b 7          ICE    - I2C Bus Interface Enable                    - Enabled (the RIICnSCL and RIICnSDA pins driven). set to 1
    */
    IIC_BUS_ENABLE();
    
    RIIC0.SAR0.UINT32   = 0;
    /* Slave address in RIICnSAR0 is enabled.
    RIICnSER            - I2C Bus Status Enable Register
    b31:b 6             - Reserved set to 0
    b 5          DIDE   - Extra SCL Clock Cycle Output                - Device-ID address detection is disabled. set to 0
    b 4                 - Reserved set to 0
    b 3          GCE    - SCL Output Control/Monitor                  - General call address detection is disabled. set to 0
    b 2          SAR2   - SDA Output Control/Monitor                  - Slave address in RIICnSAR2 is disabled. set to 0
    b 1          SAR1   - SCL Line Monitor                            - Slave address in RIICnSAR1 is disabled. set to 0
    b 0          SAR0   - SDA Line Monitor                            - Slave address in RIICnSAR0 is enabled. set to 1 */
    RIIC0.SER.UINT32    = 0;
    /* Internal Reference Clock Selection.
    RIICnMR1            - I2C Bus Mode Register 1
    b31:b 8             - Reserved set to 0
    b 7          MTWP   - MST/TRS Write Protect                       - not change.
    b 6:b 4      CKS    - Internal Reference Clock Selection          - PCLK2/16 clock. set to 100'b
    b 3          BCWP   - BC Write Protect                            - not change.
    b 2:b 0      BC     - Bit Counter                                 - not change. */
    /*config the rate as 400Kbps*/
   // RIIC0.MR1.UINT32 |= BIT4; 
   // RIIC0.BRH.UINT32  = 0xF9;
  //  RIIC0.BRL.UINT32  = 0xF9;
    
    /*config rate as 100Kbps*/
    RIIC0.MR1.UINT32 |= BIT4; /* IIC_CLK = 40MHz / 8  */
//    RIIC0.MR2.UINT32 |= BIT7|BIT6|BIT5|BIT4;
//    RIIC0.MR3.UINT32 |= BIT0|BIT1|BIT2;
    RIIC0.BRH.UINT32    = 0xF7;
    RIIC0.BRL.UINT32    = 0xF9;
    

    
    /* Set the I2C Bus Mode.
    RIICnMR2            - I2C Bus Mode Register 2
        BIT2 :  Count is enabled while the SCL line is at a high level.
        BIT1 :  Count is enabled while the SCL line is at a low level

    */
    RIIC0.MR2.UINT32    = BIT1;
    
    /* Set the I2C Bus functions.
    RIICnFER            - I2C Bus Function Enable Register
    b 4          NACKE  - NACK Reception Transfer Suspension Enable   - Transfer operation is suspended during NACK reception. set to 1
    */
    RIIC0.FER.UINT32    = BIT4|BIT1|BIT5;//
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
    RIIC0.IER.UINT32 = BIT7|BIT6|BIT5|BIT3|BIT1;//|BIT0;
    /* I2C Bus Interface Internal Reset
    b 6   IICRST - I2C Bus Interface Internal Reset  - Clears the RIIC reset or internal reset. set to 0
    */
    IIC_BUS_NO_RESET(); /* release from reset state */

    IIC_CLEAR_ALL_FLAG();
	
	SET_IIC_INT_ENABLE();
	
    (void)memset(&tIIC_Used,0,sizeof(IIC_OperateMgr_t));
    tIIC_Sate = IIC_STATE_IDLE;
}


/******************************************************************************
* Function Name : uint8 iic_transmit_data(uint8 addr, void *tx_buf, uint8 len)
* Description   : This function transmits the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
HAL_STATUS IIC_TransmitData(uint8 addr, void *txBuf, uint8 len)
{
    HAL_STATUS ret = HAL_STATUS_OK;
    tIIC_Sate = IIC_STATE_IDLE;
    
    if(NULL_PTR == txBuf)
    {
        return HAL_STATUS_I2C_INVALID_HANDLE;
    }
    
    //ATTENTION: BUSY is not cleared immediately after sending.
    if(IIC_GET_BUS_STATE())
    {
        IIC_CLEAR_STOP_FLAG();      /* Clear Stop Condition Detection Flag */
        IIC_SEND_STOP();            /* Requests to issue a stop condition*/
        return HAL_STATUS_I2C_BUS_BUSY;/* iic_bus busy */
    }
    
    tIIC_Used.busState           = IIC_STATE_SEND_ADDR_W;
    tIIC_Used.operate.outBuf     = (uint8 *)txBuf;
    tIIC_Used.operate.sendLength = len;
    tIIC_Used.operate.sendCount  = 0;
    tIIC_Used.operate.slaveAddr  = addr;
    
    IIC_CLEAR_ALL_FLAG();
    IIC_SEND_START();/* Requests to issue a start condition */

    return ret;
}

/******************************************************************************
* Function Name : uint8 iic_reception_data(uint8 addr, void *rx_buf, uint8 len)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
HAL_STATUS IIC_ReceptionData(uint8 addr, void *rxBuf, uint8 len)
{
    HAL_STATUS ret = HAL_STATUS_OK;
    
    tIIC_Sate = IIC_STATE_IDLE;
    
    if(NULL_PTR == rxBuf)
    {
        return HAL_STATUS_I2C_INVALID_HANDLE;
    }
    if(IIC_GET_BUS_STATE())
    {
        IIC_CLEAR_STOP_FLAG();      /* Clear Stop Condition Detection Flag */
        IIC_SEND_STOP();            /* Requests to issue a stop condition*/
        return HAL_STATUS_I2C_BUS_BUSY;/* iic_bus busy */
    }

    tIIC_Used.busState              = IIC_STATE_SEND_ADDR_R;
    tIIC_Used.operate.recBuf        = (uint8 *)rxBuf;
    tIIC_Used.operate.receiveLength = len;
    tIIC_Used.operate.receiveCount  = 0;
    tIIC_Used.operate.slaveAddr     = addr;

    IIC_CLEAR_ALL_FLAG();
    IIC_SEND_START();/* Requests to issue a start condition */

    return ret;
}

/******************************************************************************
* Function Name : void iic_transmit_empty_interrupt()
* Description   : iic send the hardware address and write/read command
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC_TransmitEmptyInterrupt(void)
{
    /* first byte */
    if (tIIC_Used.busState == IIC_STATE_SEND_ADDR_W )
    {
        RIIC0.DRT.UINT32 = tIIC_Used.operate.slaveAddr + IIC_CMD_WRITE;
        tIIC_Used.busState = IIC_STATE_SENDING;
    }
    else if ( tIIC_Used.busState == IIC_STATE_SEND_ADDR_R )
    {
        RIIC0.DRT.UINT32 = tIIC_Used.operate.slaveAddr + IIC_CMD_READ;
        tIIC_Used.busState   = IIC_STATE_RECEIVE_1;
    }

}

/******************************************************************************
* Function Name : void iic_transmit_end_interrupt(void)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC_TransmitEndInterrupt(void)
{
    uint8 delay = 20U;
    
    if (tIIC_Used.busState == IIC_STATE_SENDING )
    {
        /* NACK ? or Transmission end ?*/
        if ( IIC_GET_NACKF() || (tIIC_Used.operate.sendCount >= tIIC_Used.operate.sendLength))
        {
            IIC_CLEAR_TRANSMIT_END();   /* Clear Transmit End Flag*/
            IIC_CLEAR_STOP_FLAG();      /* Clear Stop Condition Detection Flag */
            IIC_SEND_STOP();            /* Requests to issue a stop condition*/
            if(tIIC_Used.operate.sendCount >= tIIC_Used.operate.sendLength)
            {
                tIIC_Used.busState = IIC_STATE_SEND_END;
            }
            else
            {
                tIIC_Used.busState = IIC_STATE_SEND_ERROR;
            }
        }
        else
        {
            RIIC0.DRT.UINT32 = tIIC_Used.operate.outBuf[tIIC_Used.operate.sendCount++];/* Write data*/

            /*Confirm TEND flag is cleared */
            while((delay > 0U) && (IIC_GET_TEND()))
            {
                delay--;
            }
        }
    }
    else
    {
        //IIC_CLEAR_ALL_FLAG();
    }
}

/******************************************************************************
* Function Name : void iic_event_interrupt(void)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
void IIC_EventInterrupt(void)
{
    /* INTRIIC0EE (STOP) */
    if ( (tIIC_Used.busState == IIC_STATE_SEND_END)
        || (tIIC_Used.busState == IIC_STATE_RECEIVE_END_1) 
        || (tIIC_Used.busState == IIC_STATE_RECEIVE_END_2) 
        || (tIIC_Used.busState == IIC_STATE_SEND_ERROR)
        || (tIIC_Used.busState == IIC_STATE_RECV_ERROR))
    {
        if ( IIC_GET_STOP_FLAG() )
        {
            if ( tIIC_Used.busState == IIC_STATE_RECEIVE_END_2 )
            {
                /* ACK write enable*/
                IIC_SET_ACKWP_EN();
                /* set I2C Bus Mode
                RIICnMR3            - I2C Bus Mode Register 3
                b 5          RDRFS  - RDRF Flag Set Timing Selection
                                    - The RDRF flag is set at the rising edge of the ninth SCL clock cycle. set to 0
                b 3          ACKBT  - Transmit Acknowledge
                                    - A 0 is sent as the acknowledge bit (ACK transmission). set to 0
                */
                RIIC0.MR3.UINT32 &= ~(BIT5|BIT3);
            }
            /* Clear NACK Detection Flag  */
            IIC_CLEAR_NACKF();
            /* Clear Stop Condition Detection Flag. */
            IIC_CLEAR_STOP_FLAG();
            if(callback_func != NULL_PTR)
            {
                switch(tIIC_Used.busState)
                {
                    case IIC_STATE_SEND_END:
                    case IIC_STATE_RECEIVE_END_1:
                    case IIC_STATE_RECEIVE_END_2:    
                            callback_func(I2C_QUEUE_SUCCESS);
                            break;
                    case IIC_STATE_SEND_ERROR:
                    case IIC_STATE_RECV_ERROR:
                            callback_func(I2C_QUEUE_FAIL);
                            break;
                    default:
                    /* Do Nothing*/
                        break;
                }
            }
            tIIC_Used.busState = IIC_STATE_IDLE;
            
        }
    }
    IIC_CLEAR_ALL_FLAG();
}

/******************************************************************************
* Function Name : void iic_reception_interrupt(void)
* Description   : This function reception the master mode.
* Argument      : none
* Return Value  : none
******************************************************************************/
/* INTRIIC0RI */
void IIC_ReceptionInterrupt(void)
{
    uint32 dummy_read = 0;
    dummy_read += 0;	/*fix QAC & compile warning*/
    if ( tIIC_Used.busState == IIC_STATE_RECEIVE_1 )
    {
        if ( IIC_GET_NACKF())
        {
            /* Clear Stop Condition Detection Flag*/
            IIC_CLEAR_STOP_FLAG();
            /* Requests to issue a stop condition*/
            IIC_SEND_STOP();
            /*dummy read*/
            IIC_GET_BYTE(dummy_read);
            
            if ( tIIC_Used.operate.receiveLength <= 2u )
            {
                tIIC_Used.busState = IIC_STATE_RECEIVE_END_2;
            }
            else
            {
                tIIC_Used.busState = IIC_STATE_RECEIVE_END_1;
            }

            if(tIIC_Used.operate.receiveCount < tIIC_Used.operate.receiveLength)
            {
                tIIC_Used.busState = IIC_STATE_RECV_ERROR;
            }
        }
        else
        {
            if ( tIIC_Used.operate.receiveLength <= 2u )
            {
                /* WAIT      RIICnMR3   - I2C Bus Mode Register 3
                b 6          WAIT   - WAIT. set to 1  */
                IIC_SET_WAIT_EN();
                if ( tIIC_Used.operate.receiveLength == 2U )
                {
                    IIC_GET_BYTE(dummy_read);
                    tIIC_Used.busState   = IIC_STATE_RECEIVE_2;
                }
                else
                {
                    IIC_SET_ACKWP_EN(); /* NACK write enable*/
                    /* NACK
                    RIICnMR3            - I2C Bus Mode Register 3
                    b 5          RDRFS  - The RDRF flag is set at the rising edge of the eighth SCL clock cycle. set to 1
                    b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
                    */
                    RIIC0.MR3.UINT32 |= BIT5|BIT3;
                    IIC_GET_BYTE(dummy_read);
                    tIIC_Used.busState   = IIC_STATE_RECEIVE_3;
                }
            }
            else
            {
                IIC_GET_BYTE(dummy_read);
                tIIC_Used.busState = IIC_STATE_RECEIVE_4;
            }
        }
    }
    else if ( tIIC_Used.busState == IIC_STATE_RECEIVE_2 )
    {
        IIC_SET_ACKWP_EN();/* NACK write enable*/
        /* NACK
        RIICnMR3            - I2C Bus Mode Register 3
        b 5          RDRFS  - The RDRF flag is set at the rising edge of the eighth SCL clock cycle. set to 1
        b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission). set to 1
        */
        RIIC0.MR3.UINT32 |= BIT5|BIT3;
        tIIC_Used.operate.recBuf[tIIC_Used.operate.receiveCount++] =(uint8) RIIC0.DRR.UINT32;
        tIIC_Used.busState    = IIC_STATE_RECEIVE_3;
    }
    else if ( tIIC_Used.busState == IIC_STATE_RECEIVE_3 )
    {
        IIC_CLEAR_STOP_FLAG();/* Clear Stop Condition Detection Flag.*/
        IIC_SEND_STOP();/* Requests to issue a stop condition*/
        /* read data */
        tIIC_Used.operate.recBuf[tIIC_Used.operate.receiveCount++] =(uint8) RIIC0.DRR.UINT32;
        IIC_SET_ACKWP_EN();/* NACK write enable*/
        /* NACK      RIICnMR3            - I2C Bus Mode Register 3
        b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission)
        */
        IIC_SEND_NACK();
        /* WAIT relese  RIICnMR3            - I2C Bus Mode Register 3
        b 6          WAIT    - no WAIT. set to 0
        */
        IIC_SET_WAIT_DISABLE();
        tIIC_Used.busState   = IIC_STATE_RECEIVE_END_2;
    }
    else if ( tIIC_Used.busState == IIC_STATE_RECEIVE_4 )
    {
        if ( tIIC_Used.operate.receiveLength == (tIIC_Used.operate.receiveCount + 1u) )
        {
            /* Clear Stop Condition Detection Flag*/
            IIC_CLEAR_STOP_FLAG();
            /* Requests to issue a stop condition*/
            IIC_SEND_STOP();
            /*read data*/
            tIIC_Used.operate.recBuf[tIIC_Used.operate.receiveCount++] =(uint8) RIIC0.DRR.UINT32;
            /* WAIT relese  RIICnMR3            - I2C Bus Mode Register 3
            b 6          WAIT    - no WAIT. set to 0
            */
            IIC_SET_WAIT_DISABLE();
            tIIC_Used.busState   = IIC_STATE_RECEIVE_END_1;
        }
        else if ( tIIC_Used.operate.receiveLength == (tIIC_Used.operate.receiveCount + 2u) )
        {
            /* NACK write enable*/
            IIC_SET_ACKWP_EN();
            /* NACK      RIICnMR3 - I2C Bus Mode Register 3
            b 3          ACKBT  - A 1 is sent as the acknowledge bit (NACK transmission)
            */
            IIC_SEND_NACK();
            /*read data*/
            tIIC_Used.operate.recBuf[tIIC_Used.operate.receiveCount++] =(uint8) RIIC0.DRR.UINT32;
        }
        else if ( tIIC_Used.operate.receiveLength == (tIIC_Used.operate.receiveCount + 3u) )
        {
            IIC_SET_WAIT_EN();
            tIIC_Used.operate.recBuf[tIIC_Used.operate.receiveCount++] =(uint8) RIIC0.DRR.UINT32;
        }
        else
        {
            tIIC_Used.operate.recBuf[tIIC_Used.operate.receiveCount++] =(uint8) RIIC0.DRR.UINT32;
        }
    }
}


#define REGISTER_PROTECT_VALUE          (0xA5u)


void Hal_IIC_ClockInit(void)
{
	uint32 reg32_value;
    /* Source Clock Setting for IIC
         C_ISO_IIC - PPLLCLK2 :40MHz*/
    do
    {
        reg32_value      = BIT1;
        WPROTR.PROTCMD1         = REGISTER_PROTECT_VALUE;/* Protection release the CKSC_IIICS_CTL register */
        CLKCTL.CKSC_IIICS_CTL  = reg32_value;
        CLKCTL.CKSC_IIICS_CTL  = ~reg32_value;
        CLKCTL.CKSC_IIICS_CTL  = reg32_value;
    } while ( WPROTR.PROTS1 != 0u );
    while ( CLKCTL.CKSC_IIICS_ACT != reg32_value )
    {
        /* Waiting for CKSC_IIICS_CTL to set. */
    }    
}
