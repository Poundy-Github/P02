/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Lin_Fp_Internal_Common.h
 *        \brief  AUTOSAR LIN Driver Frame Processor
 *
 *      \details  Interface implementation for RLIN2/RLIN3 hardware frame processor (RH850)
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Lutz Pflueger                 vislpr        Vector Informatik GmbH
 *  Andreas Pick                  visap         Vector Informatik GmbH
 *  Jan Gaukel                    visjgl        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  14.00.00  2018-01-25  vislpr  -             Implement new AUTOSAR 4 LIN driver for RH850
 *            2018-03-12  visap   -             Review finding rework
 *  14.01.00  2018-08-31  visjgl  TASK-88956    MISRA-2012
 *  15.00.00  2020-03-31  visjgl  STORY-11998   implementation of LIN Slave
 *                                ESCAN00101991 Compiler error: unresolved symbol Lin_Det_ReportError (Det_ReportError)
 **********************************************************************************************************************/

#if !defined (LIN_FP_INTERNAL_COMMON)
#define LIN_FP_INTERNAL_COMMON

/*!
  \name Component version information (decimal version of ALM implementation package)
  \{
*/
#define LIN_PLATFORM_MAJOR_VERSION 15
#define LIN_PLATFORM_MINOR_VERSION 0
#define LIN_PLATFORM_PATCH_VERSION 0
/*! \} */

/***********************************************************************************************************************
 *  Hardware Software Interface
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/*!
  \name Hardware register layout
  \{
*/
/*! Channel Hardware register layout */
struct Lin_RegisterStructTag
{
  VAR(uint8, TYPEDEF) LMD;       /*!< 0x0000: LIN / UART mode register */
  VAR(uint8, TYPEDEF) LBFC;      /*!< 0x0001: LIN break field configuration register */
  VAR(uint8, TYPEDEF) LSC;       /*!< 0x0002: LIN / UART space configuration register */
  VAR(uint8, TYPEDEF) LWUP;      /*!< 0x0003: LIN Wake-up configuration register */
  VAR(uint8, TYPEDEF) LIE;       /*!< 0x0004: LIN interrupt enable register */
  VAR(uint8, TYPEDEF) LEDE;      /*!< 0x0005: LIN / UART error detection enable register */
  VAR(uint8, TYPEDEF) LCUC;      /*!< 0x0006: LIN / UART control register */
  VAR(uint8, TYPEDEF) Reserved;  /*!< 0x0007: Reserved */
  VAR(uint8, TYPEDEF) LTRC;      /*!< 0x0008: LIN / UART transmission control register */
  VAR(uint8, TYPEDEF) LMST;      /*!< 0x0009: LIN / UART mode status register */
  VAR(uint8, TYPEDEF) LST;       /*!< 0x000A: LIN / UART Status register */
  VAR(uint8, TYPEDEF) LEST;      /*!< 0x000B: LIN / UART error status register */
  VAR(uint8, TYPEDEF) LDFC;      /*!< 0x000C: LIN / UART data field configuration register */
  VAR(uint8, TYPEDEF) LIDB;      /*!< 0x000D: LIN / UART identifier buffer register */
  VAR(uint8, TYPEDEF) LCBR;      /*!< 0x000E: LIN checksum buffer register */
  VAR(uint8, TYPEDEF) LUDB0;     /*!< 0x000F: UART data buffer 0 register */
  VAR(uint8, TYPEDEF) LDB[8];    /*!< 0x0010 - 0x0017: LIN / UART data buffer 1 - 8 register */
};

/*! Channel Global Hardware register layout */
struct Lin_GlobalRegisterStructTag
{
  VAR(uint8, TYPEDEF) Reserved;  /*! 0x0000: Reserved */
  VAR(uint8, TYPEDEF) LWBR;      /*! 0x0001: LIN Wake-up baud rate selector register */
  VAR(uint8, TYPEDEF) LBRP0;     /*! 0x0002: LIN / UART baud rate prescaler 0 register */
  VAR(uint8, TYPEDEF) LBRP1;     /*! 0x0003: LIN / UART baud rate prescaler 1 register */
  VAR(uint8, TYPEDEF) LSTC;      /*! 0x0004: LIN self test control register */
};
/*! \} */

/***********************************************************************************************************************
 *  Used registers and bits (bit mask)
 **********************************************************************************************************************/
/*!
\name Bitmasks for LIN_LSCC (LIN space configuration register)
\{
*/
#if !defined (LIN_LSC_RESP_SPACE)       /* make response space configurable by user config */ /* COV_LIN_COMPATIBILITY */
# define LIN_LSC_RESP_SPACE         ((uint8)0x01U)              /*!< Response space = 1 TBit */
#endif
#if !defined (LIN_LSC_INTERBYTE_SPACE) /* make interbyte space configurable by user config */ /* COV_LIN_COMPATIBILITY */
# define LIN_LSC_INTERBYTE_SPACE    ((uint8)0x10U)              /*!< Inter-byte space = 1 TBit */
#endif
#define LIN_LSC_DEFAULT            ( LIN_LSC_INTERBYTE_SPACE | LIN_LSC_RESP_SPACE )
/*! \} */

/*!
  \name Bitmask for LIN interrupt enable register (LIE)
  \{
*/
#define LIN_LIE_FTCIE              ((uint8)0x01U)              /*!< Transmission interrupt enable bit */
#define LIN_LIE_FRCIE              ((uint8)0x02U)              /*!< Reception interrupt enable bit */
#define LIN_LIE_ERRIE              ((uint8)0x04U)              /*!< Error detection enable bit */
#define LIN_LIE_DEFAULT            ( LIN_LIE_FTCIE | LIN_LIE_FRCIE | LIN_LIE_ERRIE )
/*! \} */

/*!
  \name Bitmasks for LIN_LEDE (LIN error detection enable register)
  \{
*/
#define LIN_LEDE_BERE              ((uint8)0x01U)              /*!< Bit error detection enable bit */
#define LIN_LEDE_PBERE             ((uint8)0x02U)              /*!< Physical bus error detection enable bit */
#define LIN_LEDE_FTERE             ((uint8)0x04U)              /*!< Frame / Response timeout detection enable bit */
#define LIN_LEDE_FERE              ((uint8)0x08U)              /*!< Framing error detection enable bit */
#define LIN_LEDE_DEFAULT           ( LIN_LEDE_BERE | LIN_LEDE_PBERE | LIN_LEDE_FTERE | LIN_LEDE_FERE )
/* Slave specific defines */
#define LIN_LEDE_SFER              ((uint8)0x10U)              /*!< Sync Field Error detection enable bit */
#define LIN_LEDE_CSER              ((uint8)0x20U)              /*!< Checksum Error detection enable bit */
#define LIN_LEDE_IPER              ((uint8)0x40U)              /*!< ID Parity Error detection enable bit */
/*! \} */

/*!
  \name Bitmasks for LIN_LCUC (LIN control register)
  \{
*/
#define LIN_LCUC_REQUEST_RESET     ((uint8)0x00U)              /*!< 0 = request reset, 1 = reset request inactive */
#define LIN_LCUC_MODE_WAKEUP       ((uint8)0x01U)              /*!< Wakeup mode */
#define LIN_LCUC_MODE_NORMAL       ((uint8)0x03U)              /*!< Normal communication mode */
/*! \} */

/*!
  \name Bitmasks for LIN_LDFC (LIN data field configuration register
  \{
*/
#define LIN_LDFC_RESP_LENGTH_MASK  ((uint8)0x0FU)              /*!< Response field length mask */
#define LIN_LDFC_RESP_DIR_RX       ((uint8)0x00U)              /*!< Response direction RX */
#define LIN_LDFC_RESP_DIR_TX       ((uint8)0x10U)              /*!< Response direction TX */
#define LIN_LDFC_CHKSUM_CLASSIC    ((uint8)0x00U)              /*!< Classic checksum mode */
#define LIN_LDFC_CHKSUM_ENH        ((uint8)0x20U)              /*!< Enhanced checksum mode */
#define LIN_LDFC_FRM_MODE_COMBINED ((uint8)0x00U)              /*!< Combined frame mode */
/*! \} */

/*!
  \name Bitmasks for LIN_LTRC (LIN transmission control register)
  \{
*/
#define LIN_LTRC_COMM_START_REQ    ((uint8)0x01U)              /*!< Frame Communication start */
/* Slave specific defines */
#define LIN_LTRC_COMM_RESPONSE_REQ ((uint8)0x02U)              /*!< Response transmission/reception start */
#define LIN_LTRC_COMM_NO_RESPONS   ((uint8)0x04U)              /*!< No Response request */
/*! \} */

/*!
  \name Bitmasks for LIN_LST (LIN status register)
  \{
*/
#define LIN_LST_FTC                ((uint8)0x01U)              /*!< Frame transmission completion flag */
#define LIN_LST_FRC                ((uint8)0x02U)              /*!< Frame reception completion flag */
#define LIN_LST_ERR                ((uint8)0x08U)              /*!< Overall LIN error flag */
#define LIN_LST_D1RC               ((uint8)0x40U)              /*!< One byte reception flag */
#define LIN_LST_HTRC               ((uint8)0x80U)              /*!< LIN header completion flag */
#define LIN_LST_CLEAR_DEFAULT      ((uint8)0x00U)              /*!< Mask to clear all status flags */
/*! \} */

/*!
  \name Bitmasks for LIN_LEST (LIN error status register)
  \{
*/
#define LIN_LEST_FER               ((uint8)0x08U)              /*!< LIN Framing error flag */
#define LIN_LEST_CLEAR_DEFAULT     ((uint8)0x00U)              /*!< Mask to clear all error status flags */
/*! \} */

/*!
  \name Bitmasks for LIN_LWUP (LIN wake-up configuration register)
  \{
*/
#define LIN_LWUP_8BITS             ((uint8)0x70U)              /*!< Wakeup tx length 8 Bits */
/*! \} */

/***********************************************************************************************************************
 *  Lin_TransitionTo
 **********************************************************************************************************************/
/*! \brief       Transition to hardware mode.
 *  \details     In case of hardware failure DEM or DET are called if configured
 *  \param[in]   Mode: The mode (LCUC_REQUEST_RESET, LCUC_MODE_WAKEUP or LCUC_MODE_NORMAL)
 *  \param[in]   ChannelConfigIdx: The valid index of the 1:1 relation pointing to Lin_ChannelConfig or Lin_ChannelData
 *  \pre         Lin interrupts must be locked.
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different handles (LIN channels)
 *  \synchronous FALSE
 **********************************************************************************************************************/
LIN_LOCAL_INLINE FUNC(void, LIN_CODE) Lin_TransitionTo( uint8 Mode, Lin_ChannelConfigIdxOfChannelIdType ChannelConfigIdx );


#endif /* LIN_FP_INTERNAL_COMMON */
