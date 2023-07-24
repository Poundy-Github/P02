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
/*!        \file  Lin_Fp_Master.h
 *        \brief  AUTOSAR LIN Driver Frame Processor
 *
 *      \details  Header for Master specific functions for RLIN2/RLIN3 hardware frame processor (RH850)
 *
 *********************************************************************************************************************/

#if !defined (LIN_FP_MASTER_H)
#define LIN_FP_MASTER_H

/***********************************************************************************************************************
 *  Lin_CommonFrameSetup
 **********************************************************************************************************************/
/*! \brief       Set up common part of all frames
 *  \details     Set up header data, checksum and data length
 *  \param[in]   ChannelConfigIdx: Access to all Channel data (register, data, ...)
 *  \param[in]   PduInfoPtr: Pointer to PDU containing the PID, Checksum model, Response type, Dl and SDU data pointer.
 *  \pre         Internal function. Do not call.
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LIN channels
 *  \synchronous FALSE
 **********************************************************************************************************************/
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_CommonFrameSetup( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx,
                                                   CONSTP2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_VAR) PduInfoPtr );

#endif /* LIN_FP_MASTER_H */
