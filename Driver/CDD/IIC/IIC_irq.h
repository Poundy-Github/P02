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
 * @file:      iic_irq.h
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

#ifndef _IIC_IRQ_H_
#define _IIC_IRQ_H_





extern __interrupt void INTRIIC0TI_interrupt(void);
extern __interrupt void INTRIIC0TEI_interrupt(void);
extern __interrupt void INTRIIC0RI_interrupt(void);
extern __interrupt void INTRIIC0EE_interrupt(void);

extern __interrupt void INTRIIC1TI_interrupt(void);
extern __interrupt void INTRIIC1TEI_interrupt(void);
extern __interrupt void INTRIIC1RI_interrupt(void);
extern __interrupt void INTRIIC1EE_interrupt(void);




#endif /* ifndef _IIC_IRQ_H_.2020-3-17 13:20:12 GW00188879 */
