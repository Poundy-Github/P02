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
 * @file:      iic_irq.c
 * @author:    Nobo
 * @date:      2020-3-17
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-3-17
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

#include "Os.h"
#include "IIC_Hardware.h"
#include "IIC1_Hardware.h"


ISR(INTRIIC0TI_interrupt)
{
    IIC_TransmitEmptyInterrupt();
}
ISR(INTRIIC0TEI_interrupt)
{
    IIC_TransmitEndInterrupt();
}
ISR(INTRIIC0RI_interrupt)
{
    IIC_ReceptionInterrupt();
}

ISR(INTRIIC0EE_interrupt)
{
    IIC_EventInterrupt();
}


ISR(INTRIIC1TI_interrupt)
{
    IIC1_TransmitEmptyInterrupt();
}
ISR(INTRIIC1TEI_interrupt)
{
    IIC1_TransmitEndInterrupt();
}
ISR(INTRIIC1RI_interrupt)
{
    IIC1_ReceptionInterrupt();
}
ISR(INTRIIC1EE_interrupt)
{
    IIC1_EventInterrupt();
}


