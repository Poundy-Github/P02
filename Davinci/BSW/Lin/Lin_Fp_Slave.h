/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Lin_Fp_Slave.h
 *        \brief  AUTOSAR LIN Driver Frame Processor
 *
 *      \details  Header for Slave specific functions for RLIN3 hardware frame processor (RH850)
 *
 *********************************************************************************************************************/

#if !defined (LIN_FP_SLAVE_H)
#define LIN_FP_SLAVE_H

/***********************************************************************************************************************
 *  Lin_Fp_Slave_Interrupt_Error_Occurred
 **********************************************************************************************************************/
/*! \brief       The Slave specific interrupt functions error handling function
 *  \details     The Slave specific interrupt functions error handling function
 *  \param[in]   ChannelConfigIdx: The valid index of the 1:1 relation pointing to Lin_ChannelConfig or Lin_ChannelData
 *  \param[in]   LSTFlags: The read LST Flags
 *  \param[in]   LESTFlags: The read LEST Flags
 *  \pre         -
 *  \context     ISR
 *  \reentrant   TRUE for different handles (LIN channels)
 *  \synchronous FALSE
 **********************************************************************************************************************/
LIN_LOCAL_INLINE FUNC(void, LIN_CODE_ISR) Lin_Fp_Slave_Interrupt_Error_Occurred( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx, uint8 LSTFlags, uint8 LESTFlags );

/***********************************************************************************************************************
 *  Lin_Fp_Slave_Interrupt
 **********************************************************************************************************************/
/*! \brief       The Slave specific interrupt function
 *  \details     The Slave specific interrupt function
 *  \param[in]   ChannelConfigIdx: The valid index of the 1:1 relation pointing to Lin_ChannelConfig or Lin_ChannelData
 *  \pre         -
 *  \context     ISR
 *  \reentrant   TRUE for different handles (LIN channels)
 *  \synchronous FALSE
 **********************************************************************************************************************/
LIN_LOCAL_INLINE FUNC(void, LIN_CODE_ISR) Lin_Fp_Slave_Interrupt( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx );


#endif /* LIN_FP_SLAVE_H */
