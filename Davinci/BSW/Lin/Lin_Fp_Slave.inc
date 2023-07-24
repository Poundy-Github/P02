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
/*!        \file  Lin_Fp_Slave.inc
 *        \brief  AUTOSAR LIN Driver Frame Processor
 *
 *      \details  Interface implementation of Slave specific functions for RLIN3 hardware frame processor (RH850)
 *
 *********************************************************************************************************************/

#if !defined (LIN_FP_SLAVE_INC)
#define LIN_FP_SLAVE_INC

/***********************************************************************************************************************
 *  Lin_Fp_Slave_Interrupt_Error_Occurred
 **********************************************************************************************************************/
/*!
 * \internal
 * - evaluate the hardware flags and report the corresponding error
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE_ISR) Lin_Fp_Slave_Interrupt_Error_Occurred( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx, uint8 LSTFlags, uint8 LESTFlags ) /* PRQA S 3206 */ /* MD_LIN_3206 */
{
  if ((LESTFlags & LIN_LEDE_FTERE) == LIN_LEDE_FTERE)
  {
    if((LSTFlags & LIN_LST_D1RC) == LIN_LST_D1RC)
    {
      Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_INC_RESP );
    }
    else
    {
      Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_NO_RESP );
    }
  }
  else if ((LESTFlags & LIN_LEDE_FERE) == LIN_LEDE_FERE)
  {
    if((LSTFlags & LIN_LST_D1RC) == LIN_LST_D1RC)  /* first data byte rx (FERE in data 1 will be acounted as header) */
    {
      Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_RESP_STOPBIT );
    }
    else
    {
      Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_HEADER );
    }
  }
  else if ((LESTFlags & LIN_LEDE_BERE) == LIN_LEDE_BERE)
  {
    Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_RESP_DATABIT );
  }
  else if ((LESTFlags & LIN_LEDE_SFER) == LIN_LEDE_SFER)
  {
    Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_HEADER );
  }
  else if ((LESTFlags & LIN_LEDE_CSER) == LIN_LEDE_CSER)
  {
    Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_RESP_CHKSUM );
  }
  else if ((LESTFlags & LIN_LEDE_IPER) == LIN_LEDE_IPER)
  {
    Lin_LinIf_LinErrorIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), LIN_ERR_HEADER );
  }
  else
  {
    /* nothing to do */
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Lin_Fp_Slave_Interrupt
 **********************************************************************************************************************/
/*!
 * \internal
 * - get and clear hardware state
 * - if normal mode is not set, set to normal mode
 * - search for transition
 * -- error
 * -- header reception
 * -- response reception
 * -- response transmission
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE_ISR) Lin_Fp_Slave_Interrupt( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  Lin_PduType TmpPduPtr;

  VAR(uint8, AUTOMATIC) Flags    = ChannelRegisterBase->LST;
  VAR(uint8, AUTOMATIC) ErrFlags = ChannelRegisterBase->LEST;

  ChannelRegisterBase->LST  = (uint8)~Flags;  /* clear Flags that have been saved */ /* SBSW_LIN_PTR_HW */
  ChannelRegisterBase->LEST = (uint8)~ErrFlags;  /* clear Flags that have been saved */ /* SBSW_LIN_PTR_HW */

  if((ChannelRegisterBase->LMST & 0x03U) != LIN_LCUC_MODE_NORMAL)
  {
    Lin_TransitionTo( LIN_LCUC_MODE_NORMAL, ChannelConfigIdx );
    ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ; /* SBSW_LIN_PTR_HW */
  }

  if( (Lin_GetState( ChannelConfigIdx ) != LIN_STATE_SLEEP) && (Lin_GetState( ChannelConfigIdx ) != LIN_STATE_WAKEUP_PENDING)) /* Not in sleep */
  {
    if ((Flags & LIN_LST_ERR) == LIN_LST_ERR)
    {
      Lin_Fp_Slave_Interrupt_Error_Occurred(ChannelConfigIdx, Flags, ErrFlags);
    }
    else if ((Flags & LIN_LST_HTRC) == LIN_LST_HTRC)
    {
      TmpPduPtr.Pid = ChannelRegisterBase->LIDB;
      TmpPduPtr.SduPtr = (uint8*)(ChannelRegisterBase->LDB); /* PRQA S 0312 */ /* MD_LIN_0312 */

      if(Lin_LinIf_HeaderIndication( (NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), &TmpPduPtr ) == E_OK) /* SBSW_LIN_SLAVE_FUNCTION */
      {
        ChannelRegisterBase->LDFC = ((TmpPduPtr.Cs == (Lin_FrameCsModelType)LIN_ENHANCED_CS)? 0x20u : 0x00u) | TmpPduPtr.Dl; /* SBSW_LIN_PTR_HW */
      }
      else
      {  /* if something goes wrong in the LinIf, ignore the frame */
        TmpPduPtr.Drc = LIN_FRAMERESPONSE_IGNORE;
      }

      switch (TmpPduPtr.Drc)
      {
        case LIN_FRAMERESPONSE_TX:
          ChannelRegisterBase->LDFC |= LIN_LDFC_RESP_DIR_TX; /* tx */ /* SBSW_LIN_PTR_HW */
          ChannelRegisterBase->LTRC = LIN_LTRC_COMM_RESPONSE_REQ;  /* response start */ /* SBSW_LIN_PTR_HW */
          Lin_SetState( ChannelConfigIdx, LIN_STATE_TX_BUSY ); /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
          break;
        case LIN_FRAMERESPONSE_RX:
          ChannelRegisterBase->LDFC |= LIN_LDFC_RESP_DIR_RX; /* rx */ /* SBSW_LIN_PTR_HW */
          ChannelRegisterBase->LTRC = LIN_LTRC_COMM_RESPONSE_REQ;  /* response start */ /* SBSW_LIN_PTR_HW */
          Lin_SetState( ChannelConfigIdx, LIN_STATE_RX_BUSY ); /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
          break;
        case LIN_FRAMERESPONSE_IGNORE:
          ChannelRegisterBase->LTRC = LIN_LTRC_COMM_NO_RESPONS;  /* ignore */ /* SBSW_LIN_PTR_HW */
          Lin_SetState( ChannelConfigIdx, LIN_STATE_S2S_BUSY ); /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
          break;
        default:
          /* nothing to do */
          break;
      }
    }
    else if ((Flags & LIN_LST_FRC) == LIN_LST_FRC)
    {
      if (Lin_GetState( ChannelConfigIdx ) == LIN_STATE_RX_BUSY)
      {
        Lin_LinIf_RxIndication((NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx), (uint8*)(ChannelRegisterBase->LDB)); /* PRQA S 0312 */ /* MD_LIN_0312 */ /* SBSW_LIN_SLAVE_FUNCTION */
      }
      else
      {
        /* nothing to do */
      }
      Lin_SetState( ChannelConfigIdx, LIN_STATE_WAKE ); /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
    }
    else if ((Flags & LIN_LST_FTC) == LIN_LST_FTC)
    {

      if (Lin_GetState( ChannelConfigIdx ) == LIN_STATE_TX_BUSY)
      {
        Lin_LinIf_TxConfirmation((NetworkHandleType) Lin_GetChannelIdOfChannelConfig(ChannelConfigIdx));
      }
      else
      {
        /* nothing to do */
      }
      Lin_SetState( ChannelConfigIdx, LIN_STATE_WAKE ); /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
    }
    else
    {
      /* nothing to do */
    }
  }
  else if (Lin_GetState( ChannelConfigIdx ) == LIN_STATE_WAKEUP_PENDING)
  {
    Lin_SetState( ChannelConfigIdx, LIN_STATE_WAKE ); /* SBSW_LIN_CSL03_INTERNALSTATE_CHANNELID */
  }
  else
  {
    /* Intentionally Empty */
  }
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_LIN_SLAVE_FUNCTION
  \DESCRIPTION The function uses ether a Pdu pointer to receive data or a Sdu Pointer to transfer data.
  \COUNTERMEASURE \T The code inspection and tests ensure that the Pdu is a local variable which always exists and that
                     the Sdu pointer has always a valid size.

SBSW_JUSTIFICATION_END */

#endif /* LIN_FP_SLAVE_INC */
