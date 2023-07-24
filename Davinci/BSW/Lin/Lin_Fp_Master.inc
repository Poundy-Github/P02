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
/*!        \file  Lin_Fp_Master.inc
 *        \brief  AUTOSAR LIN Driver Frame Processor
 *
 *      \details  Interface implementation of Master specific functions for RLIN2/RLIN3 hardware frame processor (RH850)
 *
 *********************************************************************************************************************/

#if !defined (LIN_FP_MASTER_INC)
#define LIN_FP_MASTER_INC

/***********************************************************************************************************************
 *  Lin_CommonFrameSetup
 **********************************************************************************************************************/
/*!
 * \internal
 * - make sure HW is in communication state and no communication is ongoing
 * - clear status flags
 * - configure PID to be sent
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_CommonFrameSetup( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx,
                                                  CONSTP2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_VAR) PduInfoPtr )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */

  /* make sure HW is in communication state and no communication is ongoing */
  Lin_TransitionTo( LIN_LCUC_REQUEST_RESET, ChannelConfigIdx );
  Lin_TransitionTo( LIN_LCUC_MODE_NORMAL, ChannelConfigIdx );

  /* clear status flags */
  ChannelRegisterBase->LST  = LIN_LST_CLEAR_DEFAULT; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LEST = LIN_LEST_CLEAR_DEFAULT; /* SBSW_LIN_PTR_HW */

  /* configure PID to be sent */
  ChannelRegisterBase->LIDB = PduInfoPtr->Pid; /* SBSW_LIN_PTR_HW */
}

/***********************************************************************************************************************
 *  Lin_Fp_DequeueStatus
 **********************************************************************************************************************/
/*!
 * \internal
 *   - Dequeue hardware status: read an clear hardware status flags
 *      - mapping hardware status flags to frame processor status
 *        - check if an error flag set
 *            - check if a header error flag is set
 *                - return frame processor status LIN_FP_HEADERERROR
 *            - check time out and received data bytes flags
 *                - return frame processor status LIN_FP_NO_RESPONSE
 *            - error in response or all other errors
 *                - return frame processor status LIN_FP_ERROR
 *        - check if transmission or reception was successful
 *            - return frame processor status LIN_FP_SUCCESSFUL
 *        - no hardware flags set, hardware queue was empty
 *            - return frame processor status LIN_FP_EMPTY
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(uint8, LIN_CODE) Lin_Fp_DequeueStatus( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx ) /* PRQA S 3206 */ /* MD_LIN_3206 */
{
  uint8 ret;
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */

  /* Dequeue hardware status: read an clear hardware status flags */
  VAR(uint8, AUTOMATIC) Flags    = ChannelRegisterBase->LST;
  VAR(uint8, AUTOMATIC) ErrFlags = ChannelRegisterBase->LEST;

  ChannelRegisterBase->LST  = LIN_LST_CLEAR_DEFAULT; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LEST = LIN_LEST_CLEAR_DEFAULT; /* SBSW_LIN_PTR_HW */

  /* mapping hardware status flags to frame processor status */
  /* check if the overall error flags is set */
  if( (Flags & LIN_LST_ERR) != 0U )
  { /* check if a header error flag is set */
    if( (Flags & LIN_LST_HTRC) == 0U )
    {
      /* return frame processor status LIN_FP_HEADERERROR */
      ret = LIN_FP_STATUS_HEADERERROR;
    }

    /* check time out and received data bytes flags */
    else if( ((ChannelRegisterBase->LDFC & LIN_LDFC_RESP_DIR_TX) == 0U) && /* RX Frame */
             ((ErrFlags & LIN_LEST_FER) == 0U) && /* not a framing error */
             ((Flags    & LIN_LST_D1RC) == 0U) ) /* no bytes received */
    {
      /* return frame processor status LIN_FP_NO_RESPONSE */
      ret = LIN_FP_STATUS_NO_RESPONSE;
    }

    /* error in response or all other errors */
    else
    {
      /* return frame processor status LIN_FP_ERROR */
      ret = LIN_FP_STATUS_ERROR;
    }
  }

  /* check if transmission or reception was successful */
  else if( (Flags & (LIN_LST_FTC | LIN_LST_FRC)) != 0U )
  {
    /* return frame processor status LIN_FP_SUCCESSFUL */
    ret = LIN_FP_STATUS_SUCCESSFUL;
  }

  /* no hardware flags set, hardware queue was empty */
  else
  {
    /* return frame processor status LIN_FP_EMPTY */
    ret = LIN_FP_STATUS_EMPTY;
  }

  return ret;
}

/***********************************************************************************************************************
 *  Lin_Fp_StartTxFrame
 **********************************************************************************************************************/
/*!
 * \internal
 * - setup common frame data of pdu
 * - set RLIN unit to tx
 * - copy transmission data
 * - start transmission
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_StartTxFrame( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx,
                                                   CONSTP2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_VAR) PduInfoPtr )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  /* setup common frame data of pdu */
  Lin_CommonFrameSetup( ChannelConfigIdx, PduInfoPtr ); /* SBSW_LIN_CONST_PTR_CONST */

  /* set RLIN unit to tx */
  ChannelRegisterBase->LDFC = /* SBSW_LIN_PTR_HW */
    (uint8)(LIN_LDFC_FRM_MODE_COMBINED |
    (uint8)((PduInfoPtr->Cs == (Lin_FrameCsModelType)LIN_ENHANCED_CS) ? LIN_LDFC_CHKSUM_ENH : LIN_LDFC_CHKSUM_CLASSIC) |
    LIN_LDFC_RESP_DIR_TX       |
    (LIN_LDFC_RESP_LENGTH_MASK  & (PduInfoPtr->Dl)));

  /* copy transmission data */
  ChannelRegisterBase->LDB[0] = PduInfoPtr->SduPtr[0]; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LDB[1] = PduInfoPtr->SduPtr[1]; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LDB[2] = PduInfoPtr->SduPtr[2]; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LDB[3] = PduInfoPtr->SduPtr[3]; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LDB[4] = PduInfoPtr->SduPtr[4]; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LDB[5] = PduInfoPtr->SduPtr[5]; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LDB[6] = PduInfoPtr->SduPtr[6]; /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LDB[7] = PduInfoPtr->SduPtr[7]; /* SBSW_LIN_PTR_HW */

  /* start transmission */
  ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ; /* SBSW_LIN_PTR_HW */
}

/***********************************************************************************************************************
 *  Lin_Fp_StartRxFrame
 **********************************************************************************************************************/
/*!
 * \internal
 * - setup common frame data of pdu
 * - set RLIN unit to rx
 * - start header transmission
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_StartRxFrame( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx,
                                                  CONSTP2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_VAR) PduInfoPtr )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  /* setup common frame data of pdu */
  Lin_CommonFrameSetup( ChannelConfigIdx, PduInfoPtr ); /* SBSW_LIN_CONST_PTR_CONST */

  /* set RLIN unit to rx */
  ChannelRegisterBase->LDFC = /* SBSW_LIN_PTR_HW */
    (uint8)(LIN_LDFC_FRM_MODE_COMBINED |
    (uint8)((PduInfoPtr->Cs == (Lin_FrameCsModelType)LIN_ENHANCED_CS) ? LIN_LDFC_CHKSUM_ENH : LIN_LDFC_CHKSUM_CLASSIC) |
    LIN_LDFC_RESP_DIR_RX |
    (LIN_LDFC_RESP_LENGTH_MASK  & (PduInfoPtr->Dl)));

  /* start header transmission */
  ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ; /* SBSW_LIN_PTR_HW */
}

/***********************************************************************************************************************
 *  Lin_Fp_StartS2sFrame
 **********************************************************************************************************************/
/*!
 * \internal
 * - setup common frame data of pdu
 * - use Rx frame with zero expected databytes. Occuring timeout or error interrupt will be ignored
 * - start header transmission
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_StartS2sFrame( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx,
                                                   CONSTP2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_VAR) PduInfoPtr )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  /* setup common frame data of pdu */
  Lin_CommonFrameSetup( ChannelConfigIdx, PduInfoPtr ); /* SBSW_LIN_CONST_PTR_CONST */

  /* use Rx frame with zero expected databytes. Occuring timeout or error interrupt will be ignored */;
  ChannelRegisterBase->LDFC = (uint8)(LIN_LDFC_FRM_MODE_COMBINED | LIN_LDFC_RESP_DIR_RX ); /* SBSW_LIN_PTR_HW */

  /* start header transmission */
  ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ; /* SBSW_LIN_PTR_HW */
}

/***********************************************************************************************************************
 *  Lin_Fp_SaveRxData
 **********************************************************************************************************************/
/*!
 * \internal
 * - nothing to do
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_SaveRxData( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx ) /* PRQA S 3206 */ /* MD_LIN_3206 */
{
  /* not used for this hardware as received data are directly accessibe from registers */
}

/***********************************************************************************************************************
 *  Lin_Fp_HasNoResponseBytes
 **********************************************************************************************************************/
/*!
 * \internal
 * - return FALSE if responsebytes have been received or if this is not detectable
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(boolean, LIN_CODE) Lin_Fp_HasNoResponseBytes( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx ) /* PRQA S 3206 */ /* MD_LIN_3206 */
{
  return FALSE;
}

/***********************************************************************************************************************
 *  Lin_IfRxByteNotStarted
 **********************************************************************************************************************/
/*!
 * \internal
 * - return FALSE if the reception of the rx byte has started or if this is not detectable
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(boolean, LIN_CODE) Lin_Fp_IfRxByteNotStarted( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx ) /* PRQA S 3206 */ /* MD_LIN_3206 */ /* COV_LIN_HW_TIMEOUT */
{
  return FALSE;
}

/***********************************************************************************************************************
 *  Lin_Fp_GetReceiveBufferPointer
 **********************************************************************************************************************/
/*!
 * \internal
 * - return the receiver buffer pointer
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(uint8*, LIN_CODE) Lin_Fp_GetReceiveBufferPointer( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx ) /* PRQA S 3206 */ /* MD_LIN_3206 */
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  /* use memory mapped LIN Hardware receive buffer instead shadow buffer */
  return (uint8*)(ChannelRegisterBase->LDB); /* PRQA S 0312 */ /* MD_LIN_0312 */
}

#endif /* LIN_FP_MASTER_INC */
