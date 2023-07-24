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
/*!        \file  Lin_Fp_Common.inc
 *        \brief  AUTOSAR LIN Driver Frame Processor
 *
 *      \details  Interface implementation for RLIN2/RLIN3 hardware frame processor (RH850)
 *
 *********************************************************************************************************************/

#if !defined (LIN_FP_COMMON_INC) /* COV_LIN_COMPATIBILITY */
#define LIN_FP_COMMON_INC

#include "Lin_Fp_Internal_Common.h"

/***********************************************************************************************************************
 *  Include Frame Processor Interface and Implementation (inc)
 **********************************************************************************************************************/

#if ( LIN_EXISTS_MASTER_NODETYPEOFCHANNELCONFIG == STD_ON ) /* COV_LIN_SLAVE_MA_ALWAYS_ON */
# include "Lin_Fp_Master.h"
# include "Lin_Fp_Master.inc"
#endif

#if ( LIN_EXISTS_SLAVE_NODETYPEOFCHANNELCONFIG == STD_ON ) /* COV_LIN_SLAVE_SL_ALWAYS_OFF */
# include "Lin_Fp_Slave.h"
# include "Lin_Fp_Slave.inc"
#endif


#define LIN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  Internal Functions Implementation
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Lin_TransitionTo
 **********************************************************************************************************************/
/*!
 * \internal
 * - if mode transition to LCUC_REQUEST_RESET requested
 *   - request transition to LCUC_REQUEST_RESET
 *   - wait until the mode bit is set or the counter is 0
 * - if mode transition to LCUC_MODE_WAKEUP or LCUC_MODE_NORMAL requested
 *   - request transition to request mode
 *   - wait until the mode bit is set or the counter is 0
 * - if transition to request mode not executed (counter is 0)
 *   - call DET if configured (production error to development error)
 *   - call DEM if configured
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_TransitionTo( uint8 Mode, Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx ) /* PRQA S 3206 */ /* MD_LIN_3206 */
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */

  VAR(uint8, AUTOMATIC) TimeoutCounter = LIN_TIMEOUT_DURATION;

  /* if mode transition to LCUC_REQUEST_RESET requested */
  if( Mode == LIN_LCUC_REQUEST_RESET )
  {
    /* request transition to LCUC_REQUEST_RESET */
    ChannelRegisterBase->LCUC = (ChannelRegisterBase->LCUC & 0x02U); /* SBSW_LIN_PTR_HW */

    /* wait until the mode bit is set or the counter is 0 */
    for ( ; ( (((ChannelRegisterBase->LMST) & 0x01U) != 0U ) && (TimeoutCounter != 0U) ); TimeoutCounter--) /* COV_LIN_HW_FAILURE */
    {
      ;
    }
  }
  /* if mode transition to LCUC_MODE_WAKEUP or LCUC_MODE_NORMAL requested */
  else
  {
    /* request transition to request mode */
    ChannelRegisterBase->LCUC = Mode; /* SBSW_LIN_PTR_HW */

    /* wait until the mode bit is set or the counter is 0 */
    for ( ; ( (((ChannelRegisterBase->LMST) & 0x03U) != Mode ) && (TimeoutCounter != 0U) ); TimeoutCounter--) /* COV_LIN_HW_FAILURE */
    {
      ;
    }
  }

  /* if transition to request mode not executed (counter is 0) */
#if ( ( LIN_E_TIMEOUT_TYPE_DET == STD_ON) && ( LIN_DEV_ERROR_REPORT == STD_ON ) )
  if( TimeoutCounter == 0U ) /* COV_LIN_HW_FAILURE */
  {
    /* call DET if configured (production error to development error) */
    Lin_Det_ReportError( LIN_SID_TIMEOUT_DURATION_ID, LIN_E_TIMEOUT );
  }
#elif ( ( LIN_E_TIMEOUT_TYPE_DET == STD_ON) && ( LIN_DEV_ERROR_REPORT == STD_OFF ) )
#else
  if( TimeoutCounter == 0U ) /* COV_LIN_HW_FAILURE */
  {
    /* call DEM */
    Dem_SetEventStatus( LIN_E_TIMEOUT, DEM_EVENT_STATUS_FAILED );
  }
#endif
}



/**********************************************************************************************************************
 *  Frame Processor Implementation
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Lin_Fp_GlobalInit
 **********************************************************************************************************************/
/*!
 * \internal
 * - nothing to do
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_GlobalInit( void )
{
  /* no global init demand for this driver */
}

/***********************************************************************************************************************
 *  Lin_Fp_ChannelInit
 **********************************************************************************************************************/
/*!
 * \internal
 * - get global unit register address
 * - set LIN module in reset state for configuration
 * - configure wakeup reception mode
 * - set baudrate prescaler 0 and 1
 * - set LIN master mode, select clock source, configure interrupt source, set 3-bit majority voting logic
 * - configure break field with selected sync break length and 2 bits break delimiter
 * - configure wakeup tx length to 8bits to handle LIN2.x wakuep frames as well as 1.3 slaves
 * - configure header-response space to 1TBit and inter-byte space to 1 TBit
 * - enable error detection
 * - no interrupts (polling)
 * - enable normal communication mode, leave reset mode
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_ChannelInit( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx )
{
  /* get global unit register address */
  P2VAR(Lin_GlobalRegisterStruct, AUTOMATIC, LIN_VAR_REGS) GlobalRegisterBase  = Lin_GetGlobalBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */

  /* set LIN module in reset state for configuration */
  Lin_TransitionTo( LIN_LCUC_REQUEST_RESET, ChannelConfigIdx );

  /* configure wakeup reception mode */
  GlobalRegisterBase->LWBR = Lin_GetLWBROfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */

  /* set baudrate prescaler 0 and 1 */
  GlobalRegisterBase->LBRP0 = Lin_GetLBRP0OfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */
  GlobalRegisterBase->LBRP1 = Lin_GetLBRP1OfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */

  /* set LIN master mode, select clock source, configure interrupt source, set 3-bit majority voting logic */
  ChannelRegisterBase->LMD = Lin_GetLMDOfChannelConfig( ChannelConfigIdx );  /* SBSW_LIN_PTR_HW */

  /* configure break field with selected sync break length and 2 bits break delimiter */
  ChannelRegisterBase->LBFC = Lin_GetLBFCOfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */

  /* configure wakeup tx length to 8bits to handle LIN2.x wakuep frames as well as 1.3 slaves */
  ChannelRegisterBase->LWUP = LIN_LWUP_8BITS; /* SBSW_LIN_PTR_HW */

  /* configure header-response space to 1TBit and inter-byte space to 1 TBit */
  ChannelRegisterBase->LSC = LIN_LSC_DEFAULT; /* SBSW_LIN_PTR_HW */

  /* enable error detection */
  ChannelRegisterBase->LEDE = Lin_GetLEDEOfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */

  /* no interrupts (polling) */
  ChannelRegisterBase->LIE = Lin_GetLIEOfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */

  /* enable normal communication mode, leave reset mode */
  Lin_TransitionTo( LIN_LCUC_MODE_NORMAL, ChannelConfigIdx );

#if ( LIN_EXISTS_SLAVE_NODETYPEOFCHANNELCONFIG == STD_ON ) /* COV_LIN_SLAVE_SL_ALWAYS_OFF */
# if ( LIN_EXISTS_MASTER_NODETYPEOFCHANNELCONFIG == STD_ON )
  if (Lin_GetNodeTypeOfChannelConfig(ChannelConfigIdx) == LIN_SLAVE_NODETYPEOFCHANNELCONFIG)
# endif
  {
    ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ; /* SBSW_LIN_PTR_HW */
  }
#endif
}

/***********************************************************************************************************************
 *  Lin_Fp_Interrupt
 **********************************************************************************************************************/
/*!
 * \internal
 * - Master: nothing to do
 * - Slave: redirect to implementation
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE_ISR) Lin_Fp_Interrupt( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx ) /* PRQA S 3206 */ /* MD_LIN_3206 */
{
#if ( LIN_EXISTS_SLAVE_NODETYPEOFCHANNELCONFIG == STD_ON ) /* COV_LIN_SLAVE_SL_ALWAYS_OFF */
# if ( LIN_EXISTS_MASTER_NODETYPEOFCHANNELCONFIG == STD_ON )
  if (Lin_GetNodeTypeOfChannelConfig(ChannelConfigIdx) == LIN_SLAVE_NODETYPEOFCHANNELCONFIG)
# endif
  {
    Lin_Fp_Slave_Interrupt(ChannelConfigIdx);
  }
#endif
}

/***********************************************************************************************************************
 *  Lin_Fp_StartWakeupPulse
 **********************************************************************************************************************/
/*!
 * \internal
 * - set wakeup mode
 * - set interrupts
 * - set direction to tx
 * - trigger wakeup transmission
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_StartWakeupPulse( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  /* set wakeup mode */
  Lin_TransitionTo( LIN_LCUC_REQUEST_RESET, ChannelConfigIdx );

  /* disable interrupts for Master and enable for Slave */
  ChannelRegisterBase->LIE = Lin_GetLIEOfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */
  Lin_TransitionTo( LIN_LCUC_MODE_WAKEUP, ChannelConfigIdx );

  /* set direction to tx */
  ChannelRegisterBase->LDFC = LIN_LDFC_RESP_DIR_TX; /* SBSW_LIN_PTR_HW */

  /* trigger wakeup transmission */
  ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ; /* SBSW_LIN_PTR_HW */
}

/***********************************************************************************************************************
 *  Lin_Fp_DisableWakupDetection
 **********************************************************************************************************************/
/*!
 * \internal
 * - set wakeup mode
 * - disable interrupts
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_DisableWakupDetection ( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  /* set wakeup mode */
  Lin_TransitionTo( LIN_LCUC_REQUEST_RESET, ChannelConfigIdx );

  /* disable interrupts */
  ChannelRegisterBase->LIE = Lin_GetLIEOfChannelConfig( ChannelConfigIdx ); /* SBSW_LIN_PTR_HW */

#if ( LIN_EXISTS_MASTER_NODETYPEOFCHANNELCONFIG == STD_ON ) /* COV_LIN_SLAVE_MA_ALWAYS_ON */
# if ( LIN_EXISTS_SLAVE_NODETYPEOFCHANNELCONFIG == STD_ON ) /* COV_LIN_SLAVE_SL_ALWAYS_OFF */
  if (Lin_GetNodeTypeOfChannelConfig(ChannelConfigIdx) == LIN_MASTER_NODETYPEOFCHANNELCONFIG)
# endif
  {
    Lin_TransitionTo( LIN_LCUC_MODE_WAKEUP, ChannelConfigIdx );
  }
#endif
#if ( LIN_EXISTS_SLAVE_NODETYPEOFCHANNELCONFIG == STD_ON ) /* COV_LIN_SLAVE_SL_ALWAYS_OFF */
# if ( LIN_EXISTS_MASTER_NODETYPEOFCHANNELCONFIG == STD_ON )
  if (Lin_GetNodeTypeOfChannelConfig(ChannelConfigIdx) == LIN_SLAVE_NODETYPEOFCHANNELCONFIG)
# endif
  {
    Lin_TransitionTo( LIN_LCUC_MODE_NORMAL, ChannelConfigIdx );
    ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ; /* SBSW_LIN_PTR_HW */
  }
#endif
}

/***********************************************************************************************************************
 *  Lin_Fp_EnableWakupDetection
 **********************************************************************************************************************/
/*!
 * \internal
 * - set wakeup mode and enable interrupts
 * - set direction to RX
 * - set communication bit to enable wakeup frame reception
 * \endinternal
 */
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_Fp_EnableWakupDetection ( Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx )
{
  P2VAR(Lin_RegisterStruct,       AUTOMATIC, LIN_VAR_REGS) ChannelRegisterBase = Lin_GetChannelBaseAddressOfChannelConfig( ChannelConfigIdx ); /* PRQA S 0303 */ /* MD_LIN_0303 */
  /* set wakeup mode and enable interrupts */
  Lin_TransitionTo( LIN_LCUC_REQUEST_RESET, ChannelConfigIdx );
  ChannelRegisterBase->LIE = LIN_LIE_DEFAULT; /* SBSW_LIN_PTR_HW */
  Lin_TransitionTo( LIN_LCUC_MODE_WAKEUP, ChannelConfigIdx );

  /* set direction to RX */
  ChannelRegisterBase->LDFC = LIN_LDFC_RESP_DIR_RX; /* SBSW_LIN_PTR_HW */

  /* set communication bit to enable wakeup frame reception */
  ChannelRegisterBase->LTRC = LIN_LTRC_COMM_START_REQ;  /* SBSW_LIN_PTR_HW */
}


#define LIN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:

  MD_LIN_0312:
    Reason: API specification given by AUTOSAR and must be kept (See SWS_Lin_00168). Give the HW Byte Receive Buffer to the If.
    Risk: Possible access to invalid data.
    Prevention: Execute testsuite to confirm correct data reception.

*/

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_LIN_PTR_HW
  \DESCRIPTION The function accesses a hardware register using a pointer access.
  \COUNTERMEASURE \T The code inspection and tests on hardware ensure that the memory location
                     referenced contains the registers with the same structure as specified.
                  \S Verify that the values generated match the address of register of the used hardware. [SMI-108172]

SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

  \ID COV_LIN_HW_FAILURE
  \ACCEPT XF xf xx
  \ACCEPT XF
  \REASON [COV_MSR_HW_FAILURE]

END_COVERAGE_JUSTIFICATION */

#endif /* LIN_FP_INC */

/**********************************************************************************************************************
 *  END OF FILE: Lin_Fp.inc
 *********************************************************************************************************************/
