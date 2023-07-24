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
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  LinIf_Slave.c
 *    Component:  AUTOSAR LIN INTERFACE
 *       Module:  If_Asr4IfLin
 *    Generator:  If_Asr4IfLin
 *
 *  Description:  LIN Slave specific implementation of the AUTOSAR LIN Interface
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define LINIF_SLAVE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LinIf.h"

#if ( LINIF_NODETYPE_SLAVE_SUPPORTED == STD_ON )

# include "LinIf_Cbk.h"
# include "LinIf_Int.h"
# include "LinIf_Slave.h"
# include "Com.h"

# if ( LINIF_BUSMIRRORING == STD_ON )
#  include "Mirror_Cbk.h"
# endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
# if ( LINIF_SLAVE_MAJOR_VERSION != (8u) )
#  error "Source and Header file LinIf_Slave.h are inconsistent (LINIF_SLAVE_MAJOR_VERSION)!"
# endif
# if ( LINIF_SLAVE_MINOR_VERSION != (1u) )
#  error "Source and Header file LinIf_Slave.h are inconsistent (LINIF_SLAVE_MINOR_VERSION)!"
# endif
# if ( LINIF_SLAVE_PATCH_VERSION != (0u) )
#  error "Source and Header file LinIf_Slave.h are inconsistent (LINIF_SLAVE_PATCH_VERSION)!"
# endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
# if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
/*!
 * \defgroup LinIfNcServiceIdentifier Node configuration service identifier codes
 * \{
 */
#  define LinIf_Nc_SID_AssignNAD                   ((uint8)0xB0u) /*!< AssignNAD service identifier */
#  define LinIf_Nc_SID_AssignFrameId               ((uint8)0xB1u) /*!< AssignFrameId service identifier */
#  define LinIf_Nc_SID_ReadByIdentifier            ((uint8)0xB2u) /*!< ReadByIdentifier service identifier */
#  define LinIf_Nc_SID_SaveConfiguration           ((uint8)0xB6u) /*!< SaveConfiguration service identifier */
#  define LinIf_Nc_SID_AssignFrameIdentifierRange  ((uint8)0xB7u) /*!< AssignFrameIdentifierRange service identifier */
/*! \} */

#  define LinIf_Nc_Wildcard_SupplierID             ((uint16)0x7FFFu) /*!< Wildcard value for Supplier ID */
#  define LinIf_Nc_Wildcard_FunctionID             ((uint16)0xFFFFu) /*!< Wildcard value for Function ID */

#  define LinIf_Nc_NRC_SubFunctionNotSupported     ((uint8)0x12u) /*!< Negative response code for SubFunctionNotSupported */

#  define LinIf_Nc_PID_Invalid                     ((uint8)0x40u) /*!< Invalid PID value */
#  define LinIf_Nc_PID_Unassign                    ((uint8)0x00u) /*!< Unassign PID value */
#  define LinIf_Nc_PID_DoNotCare                   ((uint8)0xFFu) /*!< Do-not-care PID value */
# endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
# if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
/*! Node configuration service indication handler return type */
typedef uint8                                     LinIf_NcIndicationHandlerRetType;

/*!
 * \defgroup LinIfNcIndicationHandlerReturnCodes Node configuration service indication handler return codes
 * \{
 */
#  define LinIf_NcIndicationRet_Accepted           ((LinIf_NcIndicationHandlerRetType)0x00u)
#  define LinIf_NcIndicationRet_Ignored            ((LinIf_NcIndicationHandlerRetType)0x01u)
#  define LinIf_NcIndicationRet_IgnoreNoForward    ((LinIf_NcIndicationHandlerRetType)0x02u)
/*! \} */
# endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define LINIF_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LinIf_HeaderIndication_Unconditional()
 *********************************************************************************************************************/
/*! \brief       Processes the reception of a LIN header.
 *  \details     Searches if the received PID is known. If the PID belongs to an unconditional Tx frame, the
 *               transmission data is requested from upper layer and the driver is configured for transmission. In case
 *               of a Rx frame, the driver is configured for reception. If the received PID does not belong to an known
 *               unconditional Rx or Tx frame, no handling is performed.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \param[in]   PduPtr               Pointer to PDU providing the received PID and pointer to the SDU data buffer
 *  \param[in]   SlaveChannelDataPtr  Pointer to slave-specific channel data
 *  \return      E_OK                 Request was accepted and header was processed.
 *  \return      E_NOT_OK             Request was not accepted and header not processed.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication_Unconditional
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR)                     PduPtr,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr
);

# if ( LINIF_TP_SUPPORTED == STD_ON ) || ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_HeaderIndication_DiagTx()
 *********************************************************************************************************************/
/*! \brief       Processes the reception of a diagnostic LIN Tx header of a slave response frame.
 *  \details     Requests the users of slave response frames if a response is pending for transmission, in order of
 *               priority. First the node configuration service handler is requested - if no response shall be
 *               transmitted, the transport protocol handler is requested. Configures the driver to transmit a response
 *               if any user requests a slave response transmission.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \param[in]   PduPtr               Pointer to PDU providing the received PID and pointer to the SDU data buffer
 *  \param[in]   SlaveChannelDataPtr  Pointer to slave-specific channel data
 *  \return      E_OK                 Request was accepted and header was processed.
 *  \return      E_NOT_OK             Request was not accepted and header not processed.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED AND ( LINIF_TP_SUPPORTED OR LINIF_NC_GENERAL_SUPPORTED )
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication_DiagTx
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR)                     PduPtr,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr
);
# endif

/**********************************************************************************************************************
 *  LinIf_RxIndication_DiagRequest()
 *********************************************************************************************************************/
/*! \brief       Processes the reception of a diagnostic LIN Rx response of a master request frame.
 *  \details     Evaluates the type of the received MRF: A sleep mode frame is directly processed. Otherwise the
 *               received request is forwarded to the users in order of priority: If the node configuration service
 *               handler does not accepted the request, it is forwarded to the ransport protocol handler.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \param[in]   LinSduPtr            Pointer to receive buffer of master request frame
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_RxIndication_DiagRequest
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);

# if ( LINIF_BUSMIRRORING == STD_ON )
/**********************************************************************************************************************
 *  LinIf_ErrorIndication_Mirror()
 *********************************************************************************************************************/
/*! \brief       Informs the mirror module about an occurred LIN error event.
 *  \details     Converts the slave error event to a LIN status event and inform the mirror module about the error
 *               occurrence for the current frame.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \param[in]   ErrorStatus          Type of detected LIN communication error
 *  \param[in]   ChannelDataPtr       Pointer to channel data structure
 *  \param[in]   SlaveChannelDataPtr  Pointer to slave-specific channel data structure
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_BUSMIRRORING
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_ErrorIndication_Mirror
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  VAR(Lin_SlaveErrorType, AUTOMATIC)                                ErrorStatus,
  P2CONST(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)       ChannelDataPtr,
  P2CONST(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  SlaveChannelDataPtr
);
# endif

# if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_NcRxIndication_Main()
 *********************************************************************************************************************/
/*! \brief       Handles the reception of a MRF.
 *  \details     Evaluates a received MRF to analyze if it contains a valid node configuration / identification service
 *               addressing this node. In this case, the service request is processed and the response is prepared.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \param[in]   LinSduPtr            Pointer to receive buffer of master request frame
 *  \return      LinIf_NcIndicationRet_Accepted   Node configuration request accepted and processed
 *  \return      LinIf_NcIndicationRet_Ignored    Frame not handled by node configuration service handler
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_NC_GENERAL_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(LinIf_NcIndicationHandlerRetType, LINIF_CODE) LinIf_NcRxIndication_Main
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);

/**********************************************************************************************************************
 *  LinIf_NcGetExpectedLengthAndAddress()
 *********************************************************************************************************************/
/*! \brief       Retrieves the expected NAD and request length for the requested node configuration service identifier.
 *  \details     -
 *  \param[in]   LinIfSlaveChannel    LinIf Slave channel handle
 *  \param[in]   Sid                  Service ID of request
 *  \param[out]  Address              Expected NAD value for the provided node configuration service identifier
 *  \param[out]  Length               Expected length value for the provided node configuration service identifier
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf Slave channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_NC_GENERAL_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcGetExpectedLengthAndAddress
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  VAR(uint8, AUTOMATIC)                                             Sid,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)                           Address,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)                           Length
);

/**********************************************************************************************************************
 *  LinIf_NcCheckSupplierIDAndFunctionID()
 *********************************************************************************************************************/
/*! \brief       Check if Supplier ID and Function ID match in received node configuration service request.
 *  \details     Assembles the Supplier ID and Function ID from the received node configuration service request and
 *               evaluates them for validity.
 *  \param[in]   LinIfSlaveChannel    LinIf Slave channel handle
 *  \param[in]   LinSduPtr            Pointer to the LSB of the supplier ID in reception buffer. The following bytes
 *                                    must be the MSB of supplier ID, LSB and MSB of function id.
 *  \return      TRUE                 Supplier ID and Function ID match
 *  \return      FALSE                Supplier ID and Function ID do not match
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf Slave channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_NC_GENERAL_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinIf_NcCheckSupplierIDAndFunctionID
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);

#  if ( LINIF_NC_LIN20_ASSIGN_FRAME_ID_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_NcRxIndication_AssignFrameIdLin20()
 *********************************************************************************************************************/
/*! \brief       Handles the LIN 2.0 AssignFrameId (SID 0xB1) node configuration request.
 *  \details     This function is called after an AssignFrameId request with correct NAD and PCI was
 *               received. It processes the request by searching the frame with the given message ID and assign the new
 *               PID to it.
 *  \param[in]   LinIfSlaveChannel    LinIf Slave channel handle
 *  \param[in]   SlaveChannelDataPtr  Pointer to slave-specific channel data structure
 *  \param[in]   LinSduPtr            Pointer to receive buffer of master request frame
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf Slave channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_NC_GENERAL_SUPPORTED and
 *               LINIF_NC_LIN20_ASSIGN_FRAME_ID_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcRxIndication_AssignFrameIdLin20
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);
#  endif

/**********************************************************************************************************************
 *  LinIf_NcRxIndication_ReadByIdentifier()
 *********************************************************************************************************************/
/*! \brief       Handles the ReadByIdentifier (SID 0xB2) node configuration request.
 *  \details     This function is called after an ReadByIdentifier request with correct NAD and PCI was received.
 *               It checks for correct supplier and function ID and for support of the requested identifier.
 *               If valid, it processes the request and prepares the response data.
 *  \param[in]   LinIfSlaveChannel    LinIf Slave channel handle
 *  \param[in]   SlaveChannelDataPtr  Pointer to slave-specific channel data structure
 *  \param[in]   LinSduPtr            Pointer to receive buffer of master request frame. Must point to a buffer with
 *                                    size >= 8.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf Slave channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_NC_GENERAL_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcRxIndication_ReadByIdentifier
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);

#  if ( LINIF_NC_ASSIGN_FRAME_ID_RANGE_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_NcRxIndication_AssignFrameIdentifierRange()
 *********************************************************************************************************************/
/*! \brief       Handles the AssignFrameIdentifierRange (SID 0xB7) node configuration request.
 *  \details     This function is called after an AssignFrameIdentifierRange request with correct NAD and PCI was
 *               received. It processes the request by assigning the given PIDs to the frames.
 *  \param[in]   LinIfSlaveChannel    LinIf Slave channel handle
 *  \param[in]   SlaveChannelDataPtr  Pointer to slave-specific channel data structure
 *  \param[in]   LinSduPtr            Pointer to receive buffer of master request frame
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf Slave channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_NC_GENERAL_SUPPORTED and
 *               LINIF_NC_ASSIGN_FRAME_ID_RANGE_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcRxIndication_AssignFrameIdentifierRange
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);
#  endif

# endif

# if ( LINIF_TP_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinTp_SlaveRxIndication_Main()
 *********************************************************************************************************************/
/*! \brief       Handles the reception of a MRF.
 *  \details     Evaluates a received MRF to analyze if it contains transport protocol data. If the frame is valid
 *               and expected, the frame is further processed and received data is passed to PduR.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \param[in]   LinSduPtr            Pointer to receive buffer of master request frame
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_TP_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinTp_SlaveRxIndication_Main
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);

/**********************************************************************************************************************
 *  LinTp_SlaveRxIndication_SF()
 *********************************************************************************************************************/
/*! \brief       Handles the reception of a single frame N-PDU.
 *  \details     This function processes a received MRF containing a single frame. Terminates a possible ongoing
 *               reception on the same channel and initiates a new receive connection.
 *  \param[in]   CtrlPtr              Pointer to Tp channel control structure
 *  \param[in]   LinSduPtr            Pointer to receive buffer of SF slave response frame
 *  \return      TRUE                 Request accepted, new connection initiated
 *  \return      FALSE                Request not accepted
 *  \pre         The received NAD must address the slave node, NAD is not further validated.
 *  \context     TASK|ISR
 *  \reentrant   TRUE for Tp channel control structures of different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_TP_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_SF
(
  CONSTP2VAR(LinTp_ControlType,  AUTOMATIC, LINIF_VAR_NOINIT)       CtrlPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);

/**********************************************************************************************************************
 *  LinTp_SlaveRxIndication_FF()
 *********************************************************************************************************************/
/*! \brief       Handles the reception of a first frame N-PDU.
 *  \details     This function processes a received MRF containing a first frame. Terminates a possible ongoing
 *               reception on the same channel and initiates a new receive connection.
 *  \param[in]   CtrlPtr              Pointer to Tp channel control structure
 *  \param[in]   LinSduPtr            Pointer to receive buffer of FF slave response frame
 *  \return      TRUE                 Request accepted, new connection initiated
 *  \return      FALSE                Request not accepted
 *  \pre         The received NAD must address the slave node, NAD is not further validated.
 *  \context     TASK|ISR
 *  \reentrant   TRUE for Tp channel control structures of different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_TP_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_FF
(
  CONSTP2VAR(LinTp_ControlType,  AUTOMATIC, LINIF_VAR_NOINIT)       CtrlPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
);

/**********************************************************************************************************************
 *  LinTp_SlaveTxHeaderIndication()
 *********************************************************************************************************************/
/*! \brief       Processes the reception of a SRF header.
 *  \details     Determines if a Tp transmission is pending and returns the transmission data, if available.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \param[out]  LinSduPtr            Pointer to transmission data buffer. If transmission data is available, the
 *                                    transmission data is copied to the buffer before returning TRUE.
 *                                    If no transmission data is available, the function returns FALSE. In this case,
 *                                    the pointer is not allowed to be dereferenced.
 *  \return      TRUE                 Transmission data is available and provided
 *  \return      FALSE                No transmission data is provided
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_TP_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinTp_SlaveTxHeaderIndication
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)                           LinSduPtr
);

/**********************************************************************************************************************
 *  LinTp_SlaveTxConfirmation()
 *********************************************************************************************************************/
/*! \brief       Handles the confirmation of a successfully transmitted SRF containing transport protocol data.
 *  \details     Closes connection after transmission of last frame of connection, otherwise prepares next consecutive
 *               frame for transmission.
 *  \param[in]   LinIfChannel         LinIf channel handle
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different LinIf channels
 *  \synchronous TRUE
 *  \config      LINIF_NODETYPE_SLAVE_SUPPORTED and LINIF_TP_SUPPORTED
 *********************************************************************************************************************/
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinTp_SlaveTxConfirmation
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel
);

# endif


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 *  LinIf Slave Frame Handling - Local Functions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LinIf_HeaderIndication_Unconditional()
 *********************************************************************************************************************/
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
 */
LINIF_LOCAL_INLINE FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication_Unconditional
(
  VAR(NetworkHandleType, AUTOMATIC)                               LinIfChannel,
  P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR)                   PduPtr,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  SlaveChannelDataPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)       channelDataPtr;
  LinIf_FrameListStartIdxOfChannelConfigType                      frameLoopIdx;
  uint16                                                          frameHandle;
  PduInfoType                                                     pduInfo;
  uint8                                                           errorId;
  Std_ReturnType                                                  retVal;
# if ( LINIF_BUSMIRRORING == STD_ON )
  uint8                                                           byteIdx;
# endif

  retVal  = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */
  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Search the configured PID list for received PID to retrieve the frame handle and information */
  frameHandle                           = LinIf_FrameHandle_Invalid;

  for ( frameLoopIdx = LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel));
        frameLoopIdx < LinIf_GetConfiguredPIDTableEndIdxOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel));
        frameLoopIdx++)
  {
    if ( LinIf_GetConfiguredPIDTable(frameLoopIdx) == PduPtr->Pid )
    {
      frameHandle = frameLoopIdx;
      break;
    }
  }

  /* #20 If the PID is unknown, ignore response */
  if ( frameHandle == LinIf_FrameHandle_Invalid )
  {
    /* unknown PID, frame not relevant, ignore response */
    retVal          = (Std_ReturnType)E_OK;
  }
  /* #30 Otherwise */
  else
  {
    /* convert index into configured PID table to index into frame list */
    frameHandle     = (LinIf_FrameListStartIdxOfChannelConfigType)(frameHandle - LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel))
                                                                   + LinIf_GetFrameListStartIdxOfChannelConfig(LinIfChannel));
    channelDataPtr  = LinIf_GetAddrChannelData(LinIfChannel);

    /* #40 If the frame is a known Tx frame */
    if ( LinIf_GetDirectionOfFrameList(frameHandle) == LIN_FRAMERESPONSE_TX )
    {
      /* #50 Report error if frame is a Tx frame and data buffer is invalid */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
      if ( PduPtr->SduPtr == NULL_PTR )
      {
        errorId = LINIF_E_PARAMETER_POINTER;
      }
      else
# endif
      /* #60 Otherwise: Request data from by upper layer and configure response transmission */
      {
        /* get data for unconditional Tx frame */
        pduInfo.SduDataPtr  = PduPtr->SduPtr;
        pduInfo.SduLength   = LinIf_GetLengthOfFrameList(frameHandle);
# if ( LINIF_IGNORE_TRIGGERTRANSMIT_RETVAL == STD_OFF )
#  if ( LINIF_PDUR_ONLY_UL_OPTIMIZATION == STD_OFF )
        if (LinIf_GetTxTriggerFctList(LinIf_GetTxTriggerFctListTxTriggerFctIdxOfFrameList(frameHandle)) /* SBSW_LINIF_FCT_POINTER_CALL_PDUINFO */
                                     (LinIf_GetPduIdOfFrameList(frameHandle), &pduInfo) == E_OK)
#  else
        if (PduR_LinIfTriggerTransmit(LinIf_GetPduIdOfFrameList(frameHandle), &pduInfo) == E_OK) /* SBSW_LINIF_FCT_CALL_EXTERNAL_WITH_PTR_STACK_VAR_PDUINFO */
#  endif
# else
#  if ( LINIF_PDUR_ONLY_UL_OPTIMIZATION == STD_OFF )
        (void)LinIf_GetTxTriggerFctList(LinIf_GetTxTriggerFctListTxTriggerFctIdxOfFrameList(frameHandle)) /* SBSW_LINIF_FCT_POINTER_CALL_PDUINFO */
                                       (LinIf_GetPduIdOfFrameList(frameHandle), &pduInfo);
#  else
        (void)PduR_LinIfTriggerTransmit(LinIf_GetPduIdOfFrameList(frameHandle), &pduInfo); /* SBSW_LINIF_FCT_CALL_EXTERNAL_WITH_PTR_STACK_VAR_PDUINFO */
#  endif
# endif
        {
          /* data provided by upper layer */
          SlaveChannelDataPtr->LinIf_FrameState                       = LinIf_SlaveFrameState_Tx; /* SBSW_LINIF_PASSED_PTR_ACCESS */
          channelDataPtr->LinIf_FrameHandle                           = frameHandle; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
          channelDataPtr->LinIf_CurrentFrameType                      = LinIf_FrameType_UnconditionalFrame; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
          PduPtr->Drc                                                 = (Lin_FrameResponseType)LIN_FRAMERESPONSE_TX; /* SBSW_LINIF_PASSED_PTR_ACCESS */
          PduPtr->Dl                                                  = (Lin_FrameDlType)LinIf_GetLengthOfFrameList(frameHandle); /* SBSW_LINIF_PASSED_PTR_ACCESS */
          PduPtr->Cs                                                  = (Lin_FrameCsModelType)LinIf_GetChecksumTypeOfFrameList(frameHandle); /* SBSW_LINIF_PASSED_PTR_ACCESS */
# if ( LINIF_BUSMIRRORING == STD_ON )
          /* If mirroring is enabled, copy transmission data to local buffer to provide it to mirror module after successful transmission */
          for (byteIdx = 0; byteIdx < LinIf_GetLengthOfFrameList(frameHandle); byteIdx++)
          {
            SlaveChannelDataPtr->LinIf_MirrorTxData[byteIdx & LINIF_LINPDU_SIZE_MASK] = PduPtr->SduPtr[byteIdx & LINIF_LINPDU_SIZE_MASK]; /* SBSW_LINIF_PASSED_PTR_ACCESS */
          }
# endif
          retVal                                                      = (Std_ReturnType)E_OK;
        }
# if ( LINIF_IGNORE_TRIGGERTRANSMIT_RETVAL == STD_OFF )
        else
        {
          /* data cannot be provided, report error and inform driver to ignore response */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
          errorId = LINIF_E_TRIGGERTRANSMIT_NO_DATA;
#  endif
        }
# endif
      }
    }
    /* #70 If the frame is a known Rx frame, configure response reception */
    else if ( LinIf_GetDirectionOfFrameList(frameHandle) == LIN_FRAMERESPONSE_RX ) /* COV_LINIF_MISRA_ELSEBRANCH */
    {
      /* Rx frame, configure frame data to be passed to LIN driver */
      SlaveChannelDataPtr->LinIf_FrameState   = LinIf_SlaveFrameState_Rx;/* SBSW_LINIF_PASSED_PTR_ACCESS */
      channelDataPtr->LinIf_FrameHandle       = frameHandle; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
      channelDataPtr->LinIf_CurrentFrameType  = LinIf_FrameType_UnconditionalFrame; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
      PduPtr->Drc                             = (Lin_FrameResponseType)LIN_FRAMERESPONSE_RX; /* SBSW_LINIF_PASSED_PTR_ACCESS */
      PduPtr->Dl                              = (Lin_FrameDlType)LinIf_GetLengthOfFrameList(frameHandle); /* SBSW_LINIF_PASSED_PTR_ACCESS */
      PduPtr->Cs                              = (Lin_FrameCsModelType)LinIf_GetChecksumTypeOfFrameList(frameHandle); /* SBSW_LINIF_PASSED_PTR_ACCESS */
      retVal                                  = (Std_ReturnType)E_OK;
    }
    else
    {
      /* MISRA only - can never happen, unknown frame check already executed above */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_HEADERINDICATION, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

# if ( LINIF_TP_SUPPORTED == STD_ON ) || ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_HeaderIndication_DiagTx()
 *********************************************************************************************************************/
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
 */
LINIF_LOCAL_INLINE FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication_DiagTx
(
  VAR(NetworkHandleType, AUTOMATIC)                               LinIfChannel,
  P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR)                   PduPtr,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  SlaveChannelDataPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean                                                         sendResponseFlag;
  uint8                                                           errorId;
  Std_ReturnType                                                  retVal;
#  if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
  uint8_least                                                     bufIdx;
#  endif

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */

  /* ----- Development Error Checks ------------------------------------- */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  retVal  = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */
  /* #10 Check data buffer for validity */
  if ( PduPtr->SduPtr == NULL_PTR )
  {
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    sendResponseFlag = FALSE;

#  if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
    /* #20 If node configuration service is enabled: If a node configuration response is pending,
           copy Tx data and notify response transmission */
    if ( SlaveChannelDataPtr->LinIf_NcRespBuffer[0] != 0x00u )
    {
      sendResponseFlag  = TRUE;
      for (bufIdx = 0; bufIdx < LINIF_NC_BUF_SIZE; bufIdx++)
      {
        PduPtr->SduPtr[bufIdx] = SlaveChannelDataPtr->LinIf_NcRespBuffer[bufIdx]; /* SBSW_LINIF_PASSED_PTR_ACCESS */
      }
    }
    /* #30 Otherwise */
    else
#  endif
    {
      /* #40 If transport protocol is enabled: If a transport protocol response is pending,
          update pointer to Tx data and notify response transmission */
#  if ( LINIF_TP_SUPPORTED == STD_ON )
      if ( LinTp_SlaveTxHeaderIndication(LinIfChannel, PduPtr->SduPtr) == TRUE ) /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
      {
        sendResponseFlag = TRUE;
      }
#  endif
    }

    /* #50 If an SRF user has indicated a pending response transmission, configure LIN driver to transmit a response */
    if ( sendResponseFlag == TRUE )
    {
      SlaveChannelDataPtr->LinIf_FrameState                           = LinIf_SlaveFrameState_Tx; /* SBSW_LINIF_PASSED_PTR_ACCESS */
      LinIf_GetAddrChannelData(LinIfChannel)->LinIf_CurrentFrameType  = LinIf_FrameType_SRF; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
      PduPtr->Drc                                                     = (Lin_FrameResponseType)LIN_FRAMERESPONSE_TX; /* SBSW_LINIF_PASSED_PTR_ACCESS */
      PduPtr->Dl                                                      = (Lin_FrameDlType)0x08u; /* SBSW_LINIF_PASSED_PTR_ACCESS */
      PduPtr->Cs                                                      = (Lin_FrameCsModelType)LIN_CLASSIC_CS; /* SBSW_LINIF_PASSED_PTR_ACCESS */
    }

    retVal = (Std_ReturnType)E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#  if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_HEADERINDICATION, errorId);
  }
#  else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif

/**********************************************************************************************************************
 *  LinIf_RxIndication_DiagRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_RxIndication_DiagRequest
(
  VAR(NetworkHandleType, AUTOMATIC)                               LinIfChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                       LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
# if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON ) && ( LINIF_TP_SUPPORTED == STD_ON )
  uint8                                                           retValNc;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If master request frame is sleep mode frame, indicate sleep mode to upper layer */
  if ( LinSduPtr[0] == 0x00u )
  {
# if ( LINIF_LINSM_ONLY_UL_OPTIMIZATION == STD_OFF )
    LinIf_GetGotoSleepIndFctList(LinIf_GetGotoSleepIndFctListIdxOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)))( /* SBSW_LINIF_FCT_POINTER_CALL */
      LinIf_GetSystemChannelIndexOfChannelIndTable(LinIfChannel));
# else
    LinSM_GotoSleepIndication(LinIf_GetSystemChannelIndexOfChannelIndTable(LinIfChannel));
# endif
  }
  /* #20 Otherwise: */
  else
  {
# if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
    /* #30 Forward master request frame to node configuration handler if node configuration is enabled */
#  if ( LINIF_TP_SUPPORTED == STD_ON )
    retValNc = LinIf_NcRxIndication_Main(LinIfChannel, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
    /* #40 If node configuration service received and accepted, close possibly ongoing Tp connection if transport protocol is enabled */
    if ( retValNc == LinIf_NcIndicationRet_Accepted )
    {
      LinTp_CloseActiveConnection(LinTp_GetAddrCtrl(LinIfChannel)); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
    }
    /* #50 Else if configuration service received and ignored, do not forward if transport protocol is enabled */
    else if ( retValNc == LinIf_NcIndicationRet_IgnoreNoForward )
    {
      /* ignore frame, do not forward to LinTp */
    }
    /* #60 Else forward master request frame to transport protocol handler if transport protocol is enabled */
    else
    {
      LinTp_SlaveRxIndication_Main(LinIfChannel, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
    }
#  else
    (void)LinIf_NcRxIndication_Main(LinIfChannel, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
#  endif
# elif ( LINIF_TP_SUPPORTED == STD_ON )
    LinTp_SlaveRxIndication_Main(LinIfChannel, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
# endif
  }
}

# if ( LINIF_BUSMIRRORING == STD_ON )
/**********************************************************************************************************************
 *  LinIf_ErrorIndication_Mirror()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_ErrorIndication_Mirror
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  VAR(Lin_SlaveErrorType, AUTOMATIC)                                ErrorStatus,
  P2CONST(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)       ChannelDataPtr,
  P2CONST(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  SlaveChannelDataPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  PduInfoType                                                     pduInfo;
  Lin_StatusType                                                  linStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If bus mirroring is active on current channel and current frame type is supported */
  if ( (ChannelDataPtr->LinIf_MirroringActivationState == TRUE) && (ChannelDataPtr->LinIf_CurrentFrameType == LinIf_FrameType_UnconditionalFrame) )
  {
    pduInfo.SduLength = 0x00u;
    pduInfo.SduDataPtr = NULL_PTR;

    /* #20 Convert slave error event to LIN status type */
    switch ( ErrorStatus )
    {
      case LIN_ERR_RESP_CHKSUM:
      case LIN_ERR_INC_RESP:
        linStatus = LIN_RX_ERROR;
        break;

      case LIN_ERR_NO_RESP:
        linStatus = LIN_RX_NO_RESPONSE;
        break;

      case LIN_ERR_RESP_DATABIT:
        linStatus = LIN_TX_ERROR;
        break;

      case LIN_ERR_RESP_STOPBIT:
      default: /* COV_LINIF_MISRA_DEFAULTBRANCH */
        if ( SlaveChannelDataPtr->LinIf_FrameState == LinIf_SlaveFrameState_Rx )
        {
          linStatus = LIN_RX_ERROR;
        }
        else /* TX */
        {
          linStatus = LIN_TX_ERROR;
        }
        break;
    }

    /* #30 Inform mirror module about error event */
    Mirror_ReportLinFrame(LinIf_GetSystemChannelIndexOfChannelIndTable(LinIfChannel), /* SBSW_LINIF_FCT_CALL_EXTERNAL_WITH_PTR_STACK_VAR */
                          LinIf_GetPidOfFrameList(ChannelDataPtr->LinIf_FrameHandle), &pduInfo, linStatus);
  }
}
# endif

/**********************************************************************************************************************
 *
 *  LinIf Slave Frame Handling - Local Functions
 *
 *********************************************************************************************************************/


# if ( LINIF_TP_SUPPORTED == STD_ON )

/**********************************************************************************************************************
 *
 *  LinIf Slave Transport Protocol - Local Functions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LinTp_SlaveRxIndication_SF()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_SF
(
  CONSTP2VAR(LinTp_ControlType,  AUTOMATIC, LINIF_VAR_NOINIT)       CtrlPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean                                                           retVal;

  /* ----- Implementation ----------------------------------------------- */
  retVal = FALSE;

  /* #10 If length information in SF is valid */
  if ( (LinSduPtr[1] > 0x00u) && (LinSduPtr[1] <= 0x06u) )
  {
    /* #20 In case a Tp connection is already active on channel, abort it and inform PduR */
    LinTp_CloseActiveConnection(CtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */

    /* #30 Initialize new single frame RX connection */
    CtrlPtr->LinTp_Timer                       = LinTp_GetNcrOfRxNSdu(CtrlPtr->LinTp_Curr_Rx_Id); /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_RemainingLength             = (PduLengthType)(LinSduPtr[1]); /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_Tx_Rx_Buffer_Length         = (uint8)(CtrlPtr->LinTp_RemainingLength); /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_Tx_Rx_Buffer_Idx            = 2; /* index of the buffer copied from - SF:2 */ /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_Curr_UL_NSdu_Id             = LinTp_GetUpperLayerPduIdOfRxNSdu(CtrlPtr->LinTp_Curr_Rx_Id); /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */

    CtrlPtr->LinTp_Ch_State                    = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START; /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */

    /* #40 Start receive buffer handling */
    LinTp_RxDataBufferHandling_Main(CtrlPtr, LinSduPtr); /* SBSW_LINIF_TP_RXDATABUFHANDLING_CALL */
    retVal = TRUE;
  }
  else
  {
    /* ingnore SF with invalid PCI */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LinTp_SlaveRxIndication_FF()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinTp_SlaveRxIndication_FF
(
  CONSTP2VAR(LinTp_ControlType,  AUTOMATIC, LINIF_VAR_NOINIT)       CtrlPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16                                                            reqLength;
  boolean                                                           retVal;

  /* ----- Implementation ----------------------------------------------- */
  retVal = FALSE;

  reqLength = (uint16)( (uint16)(((uint16)LinSduPtr[1] & 0x0Fu) << 8u) | (LinSduPtr[2]) );

  /* #10 If length information in FF is valid */
  if ( reqLength > 6u )
  {
    /* #20 In case a Tp connection is already active on channel, abort it and inform PduR */
    LinTp_CloseActiveConnection(CtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */

    /* #30 Initialize new multi frame RX connection */
    CtrlPtr->LinTp_Timer                      = LinTp_GetNcrOfRxNSdu(CtrlPtr->LinTp_Curr_Rx_Id); /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_RemainingLength            = (PduLengthType)reqLength; /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_Tx_Rx_Buffer_Length        = 5; /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_Tx_Rx_Buffer_Idx           = 3; /* index of the buffer copied from - FF:3 */ /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_SN                         = 1; /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_Curr_UL_NSdu_Id            = LinTp_GetUpperLayerPduIdOfRxNSdu(CtrlPtr->LinTp_Curr_Rx_Id); /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */
    CtrlPtr->LinTp_Ch_State                   = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START; /* SBSW_LINIF_TP_PASSED_PTR_ACCESS */

    /* #40 Start receive buffer handling */
    LinTp_RxDataBufferHandling_Main(CtrlPtr, LinSduPtr); /* SBSW_LINIF_TP_RXDATABUFHANDLING_CALL */
    retVal = TRUE;
  }
  return retVal;
}


/**********************************************************************************************************************
 *  LinTp_SlaveRxIndication_Main()
 *********************************************************************************************************************/
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
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinTp_SlaveRxIndication_Main
(
  VAR(NetworkHandleType, AUTOMATIC)                         LinIfChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                 LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  LinTp_ChannelType                                         linTpChannelIdx;
  P2VAR(LinTp_ControlType,  AUTOMATIC, LINIF_VAR_NOINIT)    tpCtrlPtr;
  uint16_least                                              rxNSduIndLoopIdx;
  LinTp_RxNSduIndType                                       rxNSduRefIndex;
  uint16                                                    rxNSduId;
  boolean                                                   bMatchesConfiguredNAD;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If Tp is active on current channel */
  linTpChannelIdx = LinTp_GetChannelOfLinIfToLinTpChannel(LinIfChannel);
  if ( linTpChannelIdx < LinTp_GetSizeOfChannelConfig())
  {
    tpCtrlPtr = LinTp_GetAddrCtrl(LinIfChannel);

    /* If the received NAD matches the current configured NAD, also search for a configured RxNSDU with NAD zero */
    bMatchesConfiguredNAD = FALSE;
    if ( LinSduPtr[0] == LinIf_GetSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)).LinIf_ConfiguredNAD )
    {
      bMatchesConfiguredNAD = TRUE;
    }

    /* #20 Retrieve RxNSduId from NAD by searching all RxNSdus configured on current channel */
    rxNSduId = LinTp_InvalidNsduIdx;
    for (rxNSduIndLoopIdx = LinTp_GetRxNSduIndStartIdxOfChannelConfig(linTpChannelIdx);
         rxNSduIndLoopIdx < LinTp_GetRxNSduIndEndIdxOfChannelConfig(linTpChannelIdx);
         rxNSduIndLoopIdx++)
    {
      rxNSduRefIndex = LinTp_GetRxNSduInd(rxNSduIndLoopIdx);
      /* note: the indirection to the relevant RxNSdus does not contain references to invalid handles, no need to check for them */
      if ( (LinTp_GetNADOfRxNSdu(rxNSduRefIndex) == LinSduPtr[0]) || ( (bMatchesConfiguredNAD == TRUE) && (LinTp_GetNADOfRxNSdu(rxNSduRefIndex) == 0x00u) ) )
      {
        rxNSduId = rxNSduRefIndex;
        break;
      }
    }

    /* #30 If matching RxNSdu found (request addresses this slave node) */
    if ( rxNSduId != LinTp_InvalidNsduIdx )
    {
      /* Matching RxNSdu found */
      tpCtrlPtr->LinTp_Curr_Rx_Id           = rxNSduId; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */

#  if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
      /* #40 Check if received frame is a functional request (if functional request support is enabled) */
      if ( LinTp_GetNADOfRxNSdu(rxNSduId) == LinIf_NAD_Functional )
      {
        /* #50 Process valid functional request and indicate it to PduR in Tp idle state, otherwise ignore frame (if functional request support is enabled) */
        if ( (tpCtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_IDLE) && ((LinSduPtr[1] > 0u) && (LinSduPtr[1] <= 6u)) )
        {
          tpCtrlPtr->LinTp_Curr_UL_NSdu_Id      = LinTp_GetUpperLayerPduIdOfRxNSdu(rxNSduId); /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
          tpCtrlPtr->LinTp_RemainingLength      = LinSduPtr[1]; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
          tpCtrlPtr->LinTp_Tx_Rx_Buffer_Length  = LinSduPtr[1]; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
          LinTp_RxDataBufferHandling_StartOfReception(tpCtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */

          if ( tpCtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_RX )
          {
            /* valid state, provide receive data to upper layer */
            tpCtrlPtr->LinTp_PduInfoPtr.SduDataPtr = (uint8*)&LinSduPtr[2]; /* PRQA S 0311 */ /* MD_LINIF_Rule11.8_0311 */ /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
            tpCtrlPtr->LinTp_PduInfoPtr.SduLength  = (uint8)LinSduPtr[1]; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
            LinTp_RxDataBufferHandling_CopyRxData(tpCtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
          }
        }
      }
      /* #60 Otherwise */
      else
#  endif
      {
        /* #70 Evaluate frame type of received frame */
        switch (LinSduPtr[1] & 0xF0u)
        {
          /***********************************************************************************************************
           *  LinTp_FrameType_SF
           **********************************************************************************************************/
          case LinTp_FrameType_SF:
            /* #80 If single frame is received, process it */
#  if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
            if ( LinTp_SlaveRxIndication_SF(tpCtrlPtr, LinSduPtr) == TRUE ) /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            {
              /* #81 If request is accepted and node configuration request pending, clear node configuration response */
              if ( LinIf_GetSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)).LinIf_NcRespBuffer[0] != 0x00u )
              {
                /* clear pending node configuration response */
                LinIf_GetSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)).LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                /* disable Nas timer */
                LinIf_GetSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)).LinIf_NasTimer = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              }
            }
#  else
            (void)LinTp_SlaveRxIndication_SF(tpCtrlPtr, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
#  endif
            break;

          /***********************************************************************************************************
           *  LinTp_FrameType_FF
           **********************************************************************************************************/
          case LinTp_FrameType_FF:
            /* #90 If first frame is received, process it */
#  if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
            if ( LinTp_SlaveRxIndication_FF(tpCtrlPtr, LinSduPtr) == TRUE ) /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            {
              /* #91 If request is accepted and node configuration request pending, clear node configuration response */
              if ( LinIf_GetSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)).LinIf_NcRespBuffer[0] != 0x00u )
              {
                /* clear pending node configuration response */
                LinIf_GetSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)).LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                /* disable Nas timer */
                LinIf_GetSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)).LinIf_NasTimer = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              }
            }
#  else
            (void)LinTp_SlaveRxIndication_FF(tpCtrlPtr, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
#  endif
            break;

          /***********************************************************************************************************
           *  LinTp_FrameType_CF
           **********************************************************************************************************/
          case LinTp_FrameType_CF:
            /* #100 If consecutive frame is received, process it */
            LinTp_RxIndication_CF(tpCtrlPtr, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            break;

          default:
            /* #110 Ignore frames with unknown PCI types */
            break;
        }
      }
    }
    else
    {
      /* #120 Unknown NAD received, terminate ongoing Tp connection if frame is SF or FF, otherwise ignore it */
      if ( ((LinSduPtr[1] & 0xF0u) == LinTp_FrameType_SF) || ((LinSduPtr[1] & 0xF0u) == LinTp_FrameType_FF) )
      {
        LinTp_CloseActiveConnection(tpCtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
      }
      else
      {
        /* frame with invalid PCI not addressing this node is ignored */
      }
    }
  }
  else
  {
    /* Tp not not active on current channel, ignore request */
  }
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  LinTp_SlaveTxHeaderIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinTp_SlaveTxHeaderIndication
(
  VAR(NetworkHandleType, AUTOMATIC)                           LinIfChannel,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)                     LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinTp_ControlType,  AUTOMATIC, LINIF_VAR_NOINIT)      tpCtrlPtr;
  boolean                                                     sendRespRetVal;
  uint8_least                                                 bufIdx;

  /* ----- Implementation ----------------------------------------------- */
  sendRespRetVal = FALSE;

  /* #10 If Tp is active on current channel */
  if ( LinTp_GetChannelOfLinIfToLinTpChannel(LinIfChannel) < LinTp_GetSizeOfChannelConfig() )
  {
    tpCtrlPtr = LinTp_GetAddrCtrl(LinIfChannel);

    /* #20 If transmission data is currently not available, request it from PduR */
    if ( tpCtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_TX_INVALID )
    {
      /* Request transmission data from PduR and adapt the channel state if necessary */
      if ( LinTp_TxDataRequest(tpCtrlPtr) == E_NOT_OK ) /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
      {
        /* unable to obtain data from PduR - permanent failure */
        LinTp_TxCloseConnection(tpCtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
      }
    }

    /* #30 If transmission data is available */
    if ( tpCtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_TX_VALID )
    {
      /* #40 Copy transmission data to buffer and update Tp timer */
      for (bufIdx = 0; bufIdx < LINTP_LOCAL_BUFFER_SIZE; bufIdx++)
      {
        LinSduPtr[bufIdx] = tpCtrlPtr->LinTp_Tx_Rx_Buffer[bufIdx]; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
      }

      /* update timer with N_As */
      tpCtrlPtr->LinTp_Timer                  = LinTp_GetNasOfTxNSdu(tpCtrlPtr->LinTp_Curr_Tx_Id); /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */

      sendRespRetVal = TRUE;
    }

  }
  else
  {
    /* Tp not active on current channel, ignore request */
  }

  return sendRespRetVal;
}

/**********************************************************************************************************************
 *  LinTpSlaveTxConfirmation()
 *********************************************************************************************************************/
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
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinTp_SlaveTxConfirmation
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinTp_ControlType,  AUTOMATIC, LINIF_VAR_NOINIT)      tpCtrlPtr;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 If Tp is active on current channel */
  if ( LinTp_GetChannelOfLinIfToLinTpChannel(LinIfChannel) < LinTp_GetSizeOfChannelConfig())
  {
    tpCtrlPtr = LinTp_GetAddrCtrl(LinIfChannel);

    /* #20 If complete Tp message is finished */
    if ( tpCtrlPtr->LinTp_RemainingLength == 0u )
    {
      /* #30 Tp request transmitted successfully, close connection and inform PduR */
      tpCtrlPtr->LinTp_Timer                  = 0; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      tpCtrlPtr->LinTp_Ch_State               = LINTP_CHANNEL_IDLE; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      PduR_LinTpTxConfirmation(tpCtrlPtr->LinTp_Curr_UL_NSdu_Id, E_OK);
    }
    /* #40 Otherwise more frames to be transmitted for current request */
    else
    {
      /* #50 Prepare next CF for transmission */
      tpCtrlPtr->LinTp_SN                     = (uint8)((tpCtrlPtr->LinTp_SN + 1u) & 0x0Fu); /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      /* set PCI */
      tpCtrlPtr->LinTp_Tx_Rx_Buffer[1]        = (uint8)(LinTp_FrameType_CF | tpCtrlPtr->LinTp_SN); /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      tpCtrlPtr->LinTp_Tx_Rx_Buffer_Idx       = 2; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      /* prepare pdu structure for buffer request */
      tpCtrlPtr->LinTp_PduInfoPtr.SduDataPtr  = &tpCtrlPtr->LinTp_Tx_Rx_Buffer[2]; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      if ( tpCtrlPtr->LinTp_RemainingLength <= 6u)
      {
        tpCtrlPtr->LinTp_PduInfoPtr.SduLength = tpCtrlPtr->LinTp_RemainingLength; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      }
      else
      {
        tpCtrlPtr->LinTp_PduInfoPtr.SduLength = 6; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      }

      /* #60 If request for new transmission data is accepted */
      if ( LinTp_TxDataRequest(tpCtrlPtr) == E_OK ) /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
      {
        /* #70 Update Tp timer with N_Cs timeout and continue transmission */
        tpCtrlPtr->LinTp_Timer                = LinTp_GetNcsOfTxNSdu(tpCtrlPtr->LinTp_Curr_Tx_Id); /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
      }
      /* #80 Otherwise close connection and inform PduR */
      else
      {
        LinTp_TxCloseConnection(tpCtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
      }
    }
  }
  else
  {
    /* Tp not not active on current channel, ignore request */
  }
}

/**********************************************************************************************************************
 *
 *  END - LinIf Slave Transport Protocol - Local Functions
 *
 *********************************************************************************************************************/
# endif


# if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )

/**********************************************************************************************************************
 *
 *  LinIf Node Configuration Service - Local Functions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LinIf_NcGetExpectedLengthAndAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcGetExpectedLengthAndAddress
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  VAR(uint8, AUTOMATIC)                                             Sid,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)                           Address,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)                           Length
)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the expected node address (encoded in NAD field) of the request */
  if ( Sid == LinIf_Nc_SID_AssignNAD )
  {
    *Address = LinIf_GetInitialNADOfSlaveChannelConfig(LinIfSlaveChannel); /* SBSW_LINIF_PASSED_PTR_ACCESS */
  }
  else
  {
    *Address = LinIf_GetAddrSlaveChannelData(LinIfSlaveChannel)->LinIf_ConfiguredNAD; /* SBSW_LINIF_PASSED_PTR_ACCESS */
  }

  /* #20 Calculate the expected length (encoded in PCI field) of the request */
  if ( Sid == LinIf_Nc_SID_SaveConfiguration )
  {
    *Length = 1; /* SBSW_LINIF_PASSED_PTR_ACCESS */
  }
  else
  {
    *Length = 6; /* SBSW_LINIF_PASSED_PTR_ACCESS */
  }
}

/**********************************************************************************************************************
 *  LinIf_NcCheckSupplierIDAndFunctionID()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(boolean, LINIF_CODE) LinIf_NcCheckSupplierIDAndFunctionID
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean                                                           retVal;
  uint16                                                            supplierId;
  uint16                                                            functionId;

  /* ----- Implementation ----------------------------------------------- */
  retVal            = FALSE;

  /* #10 Assemble supplier ID and function ID from received data */
  supplierId = (uint16)(((uint16)LinSduPtr[1] << 8) | LinSduPtr[0]);
  functionId = (uint16)(((uint16)LinSduPtr[3] << 8) | LinSduPtr[2]);

  /* #20 Check if supplier ID and function ID are valid */
  if ( ((supplierId == LinIf_GetSupplierId(LinIfSlaveChannel)) || (supplierId == LinIf_Nc_Wildcard_SupplierID)) &&
       ((functionId == LinIf_GetFunctionId(LinIfSlaveChannel)) || (functionId == LinIf_Nc_Wildcard_FunctionID)) )
  {
    retVal = TRUE;
  }

  return retVal;
}

#  if ( LINIF_NC_LIN20_ASSIGN_FRAME_ID_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_NcRxIndication_AssignFrameIdLin20()
 *********************************************************************************************************************/
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
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcRxIndication_AssignFrameIdLin20
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least                                                      pidLoopIdx;
  uint16                                                            supplierId;
  uint16                                                            messageId;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Assemble supplier ID from received data */
  supplierId = (uint16)(((uint16)LinSduPtr[4] << 8) | LinSduPtr[3]);

  /* #15 Preset to send no response */
  SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_PASSED_PTR_ACCESS */

  /* #20 Check if supplier ID is valid */
  if ( (supplierId == LinIf_GetSupplierId(LinIfSlaveChannel)) || (supplierId == LinIf_Nc_Wildcard_SupplierID) )
  {
    /* #30 Assemble message ID from received data */
    messageId = (uint16)(((uint16)LinSduPtr[6] << 8) | LinSduPtr[5]);

    /* #40 iterate over all configured frames and search for frame with given message ID */
    /* Note: ConfiguredPIDTable and MessageIdList have always the same size and order */
    for ( pidLoopIdx = LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(LinIfSlaveChannel);
          pidLoopIdx < LinIf_GetConfiguredPIDTableEndIdxOfSlaveChannelConfig(LinIfSlaveChannel);
          pidLoopIdx++)
    {
      /* If message ID is found, quit loop */
      if ( LinIf_GetMessageIdOfMessageIdList(pidLoopIdx) == messageId )
      {
        break;
      }
    }

    /* #50 If frame with message ID is found (request is valid) */
    if ( pidLoopIdx < LinIf_GetConfiguredPIDTableEndIdxOfSlaveChannelConfig(LinIfSlaveChannel) )
    {
      /* #60 Update PID of frame with provided new PID */
      LinIf_SetConfiguredPIDTable( pidLoopIdx, LinSduPtr[7] ); /* SBSW_LINIF_SET_CONFIGURED_PID */

      /* #70 Prepare positive response */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = SlaveChannelDataPtr->LinIf_ConfiguredNAD;  /* Configured NAD */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x01u;                                     /* response length */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0xF1u;                                     /* RSID, positive response code */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[3] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[4] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[5] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[6] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    }
  }
}
#  endif

/**********************************************************************************************************************
 *  LinIf_NcRxIndication_ReadByIdentifier()
 *********************************************************************************************************************/
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
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcRxIndication_ReadByIdentifier
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if supplier ID and function ID are valid */
  if ( LinIf_NcCheckSupplierIDAndFunctionID(LinIfSlaveChannel, &LinSduPtr[4]) == TRUE ) /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
  {
    /* #20 If identifier 0 is requested (LIN product identification) */
    if ( LinSduPtr[3] == 0u )
    {
      /* #30 Prepare response data for identifier 0 */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = SlaveChannelDataPtr->LinIf_ConfiguredNAD;    /* Configured NAD */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x06u;                                       /* response length */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0xF2u;                                       /* RSID, positive response code */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[3] =                                              /* SBSW_LINIF_PASSED_PTR_ACCESS */
        (uint8)(LinIf_GetSupplierId(LinIfSlaveChannel) & 0x00FFu);                              /* LSB of supplier ID */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[4] =                                              /* SBSW_LINIF_PASSED_PTR_ACCESS */
        (uint8)((LinIf_GetSupplierId(LinIfSlaveChannel) & 0xFF00u) >> 8u );                     /* MSB of supplier ID */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[5] =                                              /* SBSW_LINIF_PASSED_PTR_ACCESS */
        (uint8)(LinIf_GetFunctionId(LinIfSlaveChannel) & 0x00FFu);                              /* LSB of function ID */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[6] =                                              /* SBSW_LINIF_PASSED_PTR_ACCESS */
        (uint8)((LinIf_GetFunctionId(LinIfSlaveChannel) & 0xFF00u) >> 8u );                     /* MSB of function ID */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[7] =                                              /* SBSW_LINIF_PASSED_PTR_ACCESS */
        LinIf_GetVariantId(LinIfSlaveChannel);                                                  /* Variant ID */
    }

    /* #40 If identifier 3 is requested (LIN database source and version) */
#  if ( LINIF_NC_READ_BY_IDENTIFIER_3_SUPPORTED == STD_ON )
    else if ( LinSduPtr[3] == 3u )
    {
      /* #50 If identifier 3 is supported on requested channel */
      if ( LinIf_GetDatabaseSourceOfSlaveChannelConfig(LinIfSlaveChannel) != LinIf_DatabaseSource_UNUSED )
      {
        /* #60 Prepare response data for identifier 3 */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = SlaveChannelDataPtr->LinIf_ConfiguredNAD;  /* Configured NAD */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x06u;                                     /* response length */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0xF2u;                                     /* RSID, positive response code */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[3] =                                            /* SBSW_LINIF_PASSED_PTR_ACCESS */
                (uint8)LinIf_GetDatabaseMajorVerOfSlaveChannelConfig(LinIfSlaveChannel);        /* Major version */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[4] =                                            /* SBSW_LINIF_PASSED_PTR_ACCESS */
                (uint8)LinIf_GetDatabaseMinorVerOfSlaveChannelConfig(LinIfSlaveChannel);        /* Minor version */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[5] =                                            /* SBSW_LINIF_PASSED_PTR_ACCESS */
                (uint8)LinIf_GetDatabaseSubVerOfSlaveChannelConfig(LinIfSlaveChannel);          /* Sub version */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[6] =                                            /* SBSW_LINIF_PASSED_PTR_ACCESS */
                (uint8)LinIf_GetDatabaseSourceOfSlaveChannelConfig(LinIfSlaveChannel);          /* Source of database */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0x00u;                                     /* reserved */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      }
    }
#  endif

    /* #70 If identifier 16 - 31 is requested (LIN 2.0 message ID) */
#  if ( LINIF_NC_LIN20_ASSIGN_FRAME_ID_SUPPORTED == STD_ON )
    else if ( (LinSduPtr[3] > 15u) && (LinSduPtr[3] < 32u) )
    {
      if ( (LinSduPtr[3] < (uint8)(LinIf_GetMessageIdListLengthOfSlaveChannelConfig(LinIfSlaveChannel) + 16u) )
#   if ( LINIF_NC_LIN20_ASSIGN_FRAME_ID_ON_ALL_CHANNELS_SUPPORTED == STD_OFF )
         && ( LinIf_GetProtocolVersionOfSlaveChannelConfig(LinIfSlaveChannel) == LinIf_LinProtocolVersion_20 )
#   endif
         )
      {
        uint16 frameIdx = (uint16)(LinIf_GetMessageIdListStartIdxOfSlaveChannelConfig(LinIfSlaveChannel) + (uint16)LinSduPtr[3] - 16u);
        /* #80 Prepare response data for identifier 16 - 31 */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = SlaveChannelDataPtr->LinIf_ConfiguredNAD;  /* Configured NAD */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x04u;                                     /* response length */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0xF2u;                                     /* RSID, positive response code */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[3] =                                            /* SBSW_LINIF_PASSED_PTR_ACCESS */
                (uint8)(LinIf_GetMessageIdOfMessageIdList(frameIdx) & 0x00FFu);                 /* LSB of message ID */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[4] =                                            /* SBSW_LINIF_PASSED_PTR_ACCESS */
                (uint8)((LinIf_GetMessageIdOfMessageIdList(frameIdx) & 0xFF00u) >> 8);          /* MSB of message ID */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[5] =                                            /* SBSW_LINIF_PASSED_PTR_ACCESS */
                (uint8)(LinIf_GetConfiguredPIDTable(frameIdx));                                 /* PID */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[6] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      }
      else
      {
        /* prepare negative response data */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = SlaveChannelDataPtr->LinIf_ConfiguredNAD;  /* Configured NAD */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x03u;                                     /* response length */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0x7Fu;                                     /* RSID, negative response code */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[3] = LinIf_Nc_SID_ReadByIdentifier;             /* SID of request */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[4] = LinIf_Nc_NRC_SubFunctionNotSupported;      /* NRC */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[5] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[6] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
        SlaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      }
    }
#  endif

    /* #90 Otherwise, send negative response for all other idenitiers (includes identifier 2 and unsupported identifier) */
    else
    {
      /* prepare negative response data */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = SlaveChannelDataPtr->LinIf_ConfiguredNAD;    /* Configured NAD */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x03u;                                       /* response length */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0x7Fu;                                       /* RSID, negative response code */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[3] = LinIf_Nc_SID_ReadByIdentifier;               /* SID of request */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[4] = LinIf_Nc_NRC_SubFunctionNotSupported;        /* NRC */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[5] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[6] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
      SlaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    }
  }
}

#  if ( LINIF_NC_ASSIGN_FRAME_ID_RANGE_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_NcRxIndication_AssignFrameIdentifierRange()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LINIF_LOCAL_INLINE FUNC(void, LINIF_CODE) LinIf_NcRxIndication_AssignFrameIdentifierRange
(
  VAR(uint8, AUTOMATIC)                                             LinIfSlaveChannel,
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    SlaveChannelDataPtr,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8                                                             pidLoopIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over the four provided PIDs and update the configured PID table if index is valid */
  for ( pidLoopIdx = 0u; pidLoopIdx < 4u; pidLoopIdx++ )
  {
    if ( LinSduPtr[(uint8)(7u - pidLoopIdx)] != LinIf_Nc_PID_DoNotCare )
    {
      /* PID is not of type do-not-care, but assign or unassign PID */
      if ( (uint8)((LinSduPtr[3] + 3u) - pidLoopIdx) < LinIf_GetConfiguredPIDTableLengthOfSlaveChannelConfig(LinIfSlaveChannel) )
      {
        /* PID index is valid */
        /* If requested PID is unassign PID, set current PID to unassigned value, else assign new PID value */
        if ( LinSduPtr[(uint8)(7u - pidLoopIdx)] == LinIf_Nc_PID_Unassign )
        {
          LinIf_SetConfiguredPIDTable( LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(LinIfSlaveChannel) + (uint8)(LinSduPtr[3] + 3u - pidLoopIdx), LinIf_Nc_PID_Invalid); /* SBSW_LINIF_SET_CONFIGURED_PID */
        }
        else
        {
          LinIf_SetConfiguredPIDTable( LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(LinIfSlaveChannel) + (uint8)(LinSduPtr[3] + 3u - pidLoopIdx), /* SBSW_LINIF_SET_CONFIGURED_PID */
                                       LinSduPtr[(uint8)(7u - pidLoopIdx)]);
        }
      }
      else
      {
        /* PID index is invalid, quit loop */
        break;
      }
    }
  }

  /* #20 If request is valid, prepare negative response, otherwise send no response */
  if ( pidLoopIdx == 4u )
  {
    /* request is valid, prepare positive response */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = SlaveChannelDataPtr->LinIf_ConfiguredNAD;  /* Configured NAD */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x01u;                                     /* response length */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0xF7u;                                     /* RSID, positive response code */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[3] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[4] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[5] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[6] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0xFFu;                                     /* unused stuffing byte */ /* SBSW_LINIF_PASSED_PTR_ACCESS */
  }
  else
  {
    /* request is invalid, requested PID index out of range, no response */
    SlaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_PASSED_PTR_ACCESS */
  }
}
#  endif

/**********************************************************************************************************************
 *  LinIf_NcRxIndication_Main()
 *********************************************************************************************************************/
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
 */
LINIF_LOCAL_INLINE FUNC(LinIf_NcIndicationHandlerRetType, LINIF_CODE) LinIf_NcRxIndication_Main
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel,
  P2CONST(uint8, AUTOMATIC, LINIF_APPL_VAR)                         LinSduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    slaveChannelDataPtr;
  LinIf_NcIndicationHandlerRetType                                  retVal;
  uint8                                                             expectedNAD;
  uint8                                                             expectedPCI;
  uint8                                                             linIfSlaveChannel;
#  if ( LINIF_NC_SAVE_CONFIGURATION_SUPPORTED == STD_ON )
  boolean                                                           saveConfigCalloutRetVal;
#  endif

  /* ----- Implementation ----------------------------------------------- */
  retVal = LinIf_NcIndicationRet_Ignored;
  linIfSlaveChannel = LinIf_GetNodeChannelDataIdxOfLinIfChannel(LinIfChannel);
  slaveChannelDataPtr = LinIf_GetAddrSlaveChannelData(linIfSlaveChannel);

  /* #10 Check if SID is in general slave node configuration / identification range */
  /* Note: For simplicity, the received SID is checked for the maximum range of known service identifier (ISO17987).
      A pedantic SID validation would check the SID against for service identifier range based on used LIN protocol
      on current channel, but this is not worth the effort */
  if ( (LinSduPtr[2] >= 0xB0u) && (LinSduPtr[2] <= 0xB8u) && (LinSduPtr[1] >= 0x01u) && ( LinSduPtr[1] <= 0x06u) )
  {
    /* #20 Retrieve expected NAD and PCI for requested node configuration service */
    LinIf_NcGetExpectedLengthAndAddress(linIfSlaveChannel, LinSduPtr[2], &expectedNAD, &expectedPCI); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */

    /* #30 Check if NAD is valid for requested node configuration service */
    if ( (LinSduPtr[0] == expectedNAD) || (LinSduPtr[0] == LinIf_NAD_Broadcast) )
    {
      /* #40 Check if PCI is valid for requested node configuration service */
      if ( LinSduPtr[1] == expectedPCI )
      {
        /* preset common case that request is handled */
        retVal = LinIf_NcIndicationRet_Accepted;

        /* #50 Evaluate received SID */
        switch ( LinSduPtr[2] )
        {

#  if ( LINIF_NC_ASSIGN_NAD_SUPPORTED == STD_ON )
          /***********************************************************************************************************
           *  AssignNAD
           **********************************************************************************************************/
          /* #60 If SID is 0xB0, perform handling for AssignNAD */
          case LinIf_Nc_SID_AssignNAD:
            /* check if supplier ID and function ID are valid */
            if ( LinIf_NcCheckSupplierIDAndFunctionID(linIfSlaveChannel, &LinSduPtr[3]) == TRUE ) /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            {
              /* update configured NAD with received new NAD */
              slaveChannelDataPtr->LinIf_ConfiguredNAD = LinSduPtr[7];                    /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

              /* prepare positive response data */
              slaveChannelDataPtr->LinIf_NcRespBuffer[0] =
                      LinIf_GetInitialNADOfSlaveChannelConfig(linIfSlaveChannel);         /* initial NAD from request */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              slaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x01u;                         /* response length */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              slaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0xF0u;                         /* RSID, positive response code */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              slaveChannelDataPtr->LinIf_NcRespBuffer[3] = 0xFFu;                         /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              slaveChannelDataPtr->LinIf_NcRespBuffer[4] = 0xFFu;                         /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              slaveChannelDataPtr->LinIf_NcRespBuffer[5] = 0xFFu;                         /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              slaveChannelDataPtr->LinIf_NcRespBuffer[6] = 0xFFu;                         /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              slaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0xFFu;                         /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
            }
            else
            {
              /* invalid supplier ID or function ID, ignore frame */
            }
            break;
#  endif

#  if ( LINIF_NC_LIN20_ASSIGN_FRAME_ID_SUPPORTED == STD_ON )
          /***********************************************************************************************************
           *  AssignFrameId
           **********************************************************************************************************/
          /* #70 If SID is 0xB1, perform handling for LIN 2.0 AssignFrameId */
          case LinIf_Nc_SID_AssignFrameId:
#   if ( LINIF_NC_LIN20_ASSIGN_FRAME_ID_ON_ALL_CHANNELS_SUPPORTED == STD_OFF )
            if ( LinIf_GetProtocolVersionOfSlaveChannelConfig(linIfSlaveChannel) == LinIf_LinProtocolVersion_20 )
#   endif
            {
              /* process AssignFrameId request */
              LinIf_NcRxIndication_AssignFrameIdLin20(linIfSlaveChannel, slaveChannelDataPtr, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            }
#   if ( LINIF_NC_LIN20_ASSIGN_FRAME_ID_ON_ALL_CHANNELS_SUPPORTED == STD_OFF )
            else
            {
              /* AssignFrameId service not supported on current channel */
              slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u;  /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              retVal = LinIf_NcIndicationRet_Ignored;
            }
#   endif
            break;
#  endif

          /***********************************************************************************************************
           *  ReadByIdentifier
           **********************************************************************************************************/
          /* #80 If SID is 0xB2, perform handling for ReadByIdentifier */
          case LinIf_Nc_SID_ReadByIdentifier:
            /* process ReadByIdentifier request */
            LinIf_NcRxIndication_ReadByIdentifier(linIfSlaveChannel, slaveChannelDataPtr, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            break;

#  if ( LINIF_NC_SAVE_CONFIGURATION_SUPPORTED == STD_ON )
          /***********************************************************************************************************
           *  SaveConfiguration
           **********************************************************************************************************/
          /* #90 If SID is 0xB6, perform handling for SaveConfiguration */
          case LinIf_Nc_SID_SaveConfiguration:
#   if ( LINIF_NC_SAVE_CONFIGURATION_ON_ALL_CHANNELS_SUPPORTED == STD_OFF )
            if ( LinIf_GetProtocolVersionOfSlaveChannelConfig(linIfSlaveChannel) >= LinIf_LinProtocolVersion_21 )
#   endif
            {
              /* call save configuration callout */
              saveConfigCalloutRetVal = LinIf_SaveConfigurationCalloutFctPtr( LinIf_GetSystemChannelIndexOfChannelIndTable(LinIfChannel) ); /* SBSW_LINIF_FCT_POINTER_CALL */

              /* prepare positive or negative response depending on return value of callout function */
              if ( saveConfigCalloutRetVal == TRUE )
              {
                /* prepare positive response */
                slaveChannelDataPtr->LinIf_NcRespBuffer[0] = slaveChannelDataPtr->LinIf_ConfiguredNAD;    /* Configured NAD */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                slaveChannelDataPtr->LinIf_NcRespBuffer[1] = 0x01u;                                       /* response length */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                slaveChannelDataPtr->LinIf_NcRespBuffer[2] = 0xF6u;                                       /* RSID, positive response code */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                slaveChannelDataPtr->LinIf_NcRespBuffer[3] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                slaveChannelDataPtr->LinIf_NcRespBuffer[4] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                slaveChannelDataPtr->LinIf_NcRespBuffer[5] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                slaveChannelDataPtr->LinIf_NcRespBuffer[6] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
                slaveChannelDataPtr->LinIf_NcRespBuffer[7] = 0xFFu;                                       /* unused stuffing byte */ /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              }
              else
              {
                /* send no response */
                slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              }
            }
#   if ( LINIF_NC_SAVE_CONFIGURATION_ON_ALL_CHANNELS_SUPPORTED == STD_OFF )
            else
            {
              /* SaveConfiguration service not supported on current channel */
              slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              retVal = LinIf_NcIndicationRet_Ignored;
            }
#   endif
            break;
#  endif

#  if ( LINIF_NC_ASSIGN_FRAME_ID_RANGE_SUPPORTED == STD_ON )
          /***********************************************************************************************************
           *  AssignFrameIdentifierRange
           **********************************************************************************************************/
          /* #100 If SID is 0xB7, perform handling for AssignFrameIdentifierRange */
          case LinIf_Nc_SID_AssignFrameIdentifierRange:
#   if ( LINIF_NC_ASSIGN_FRAME_ID_RANGE_ON_ALL_CHANNELS_SUPPORTED == STD_OFF )
            if ( LinIf_GetProtocolVersionOfSlaveChannelConfig(linIfSlaveChannel) >= LinIf_LinProtocolVersion_21 )
#   endif
            {
              /* process AssignFrameIdentifierRange request */
              LinIf_NcRxIndication_AssignFrameIdentifierRange(linIfSlaveChannel, slaveChannelDataPtr, LinSduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            }
#   if ( LINIF_NC_ASSIGN_FRAME_ID_RANGE_ON_ALL_CHANNELS_SUPPORTED == STD_OFF )
            else
            {
              /* AssignFrameIdentifierRange service not supported on current channel */
              slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
              retVal = LinIf_NcIndicationRet_Ignored;
            }
#   endif
            break;
#  endif

          default:
            /* unsupported service identifier */
            slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
            retVal = LinIf_NcIndicationRet_Ignored;
            break;
        }
      }
      else
      {
        /* ignore frame with invalid PCI */
        retVal = LinIf_NcIndicationRet_IgnoreNoForward;
      }
    }
    else
    {
      if ( (LinSduPtr[0] == LinIf_NAD_Functional) &&
           (    (slaveChannelDataPtr->LinIf_NcRespBuffer[0] != 0x00u)
#  if ( LINIF_TP_SUPPORTED == STD_ON )
             || ( LinTp_GetAddrCtrl(LinIfChannel)->LinTp_Ch_State != LINTP_CHANNEL_IDLE)
#  endif
             ) )
      {
        /* ignore functional request if node configuration request is pending or Tp connection is active */
        retVal = LinIf_NcIndicationRet_IgnoreNoForward;
      }
      else
      {
        /* node configuration service addressing another node, abort reponse */
        slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
        /* clear possibly running timer (if valid request has been received before and response was pending) */
        slaveChannelDataPtr->LinIf_NasTimer = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
      }
    }
  }
  else
  {
    /* ignore frame unknown node configuration SID */
  }

  /* #110 Start N_As timeout timer if request is accepted */
  if ( slaveChannelDataPtr->LinIf_NcRespBuffer[0] != 0x00u )
  {
    slaveChannelDataPtr->LinIf_NasTimer = LinIf_GetNasTimeoutOfSlaveChannelConfig(linIfSlaveChannel); /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
  }

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *
 *  END - LinIf Node Configuration Service - Local Functions
 *
 *********************************************************************************************************************/

# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * LinIf Slave callback functions from driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LinIf_HeaderIndication()
 *********************************************************************************************************************/
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
 */
FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication
(
  VAR(NetworkHandleType, AUTOMATIC)                               Channel,
  P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR)                   PduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                                  retVal;
  uint8                                                           errorId;
  uint8                                                           linIfChannelIdx;
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  slaveChannelDataPtr;
  P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)       channelDataPtr;

# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  retVal  = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */
# endif
  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
#  if ( LINIF_TP_SUPPORTED == STD_ON )
  if ( (LinIf_Dev_InitDetect != LINIF_INIT) || (LinTp_Dev_InitDetect != LINTP_INIT) )
#  else
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
#  endif
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter PduPtr */
  else if ( PduPtr == (P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_VAR))NULL_PTR )
  {
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  /* #30 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfLinDrvToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert Lin driver channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfLinDrvToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      channelDataPtr        = LinIf_GetAddrChannelData(linIfChannelIdx);
      slaveChannelDataPtr   = LinIf_GetAddrSlaveChannelData(LinIf_GetNodeChannelDataIdxOfLinIfChannel(linIfChannelIdx));

      SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_2();

      /* #40 Report error if LIN response is expected instead of a header */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
      if ( (slaveChannelDataPtr->LinIf_FrameState == LinIf_SlaveFrameState_Rx) || (slaveChannelDataPtr->LinIf_FrameState == LinIf_SlaveFrameState_Tx) )
      {
        errorId = LINIF_E_RESPONSE;
      }
# endif

      /* #50 If this header indication implies an expected wakeup confirmation */
      if ( slaveChannelDataPtr->LinIf_NmWakeupState == LinIf_SlaveNmState_WaitForWakeupConf )
      {
        /* #60 Confirm wakeup to upper layer and enter operational state */
# if ( LINIF_LINSM_ONLY_UL_OPTIMIZATION == STD_OFF )
        LinIf_GetWakeupConfFctList(LinIf_GetWakeupConfFctListIdxOfChannelConfig(linIfChannelIdx))( /* SBSW_LINIF_FCT_POINTER_CALL */
               LinIf_GetSystemChannelIndexOfChannelIndTable(linIfChannelIdx), TRUE);
# else
        LinSM_WakeupConfirmation(LinIf_GetSystemChannelIndexOfChannelIndTable(linIfChannelIdx), TRUE);
# endif
        channelDataPtr->LinIf_ChannelState        = LINIF_CHANNEL_OPERATIONAL; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
        slaveChannelDataPtr->LinIf_NmWakeupState  = LinIf_SlaveNmState_Idle; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
      }

      /* #70 Restart bus idle timer */
      slaveChannelDataPtr->LinIf_BusIdleTimer   = LinIf_GetBusIdleTimeoutOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx)); /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      /* configure PDU data to be an irrelevant frame - in valid cases, the configuration is overwritten below */
      PduPtr->Drc                               = (Lin_FrameResponseType)LIN_FRAMERESPONSE_IGNORE; /* SBSW_LINIF_PASSED_PTR_ACCESS */
      slaveChannelDataPtr->LinIf_FrameState     = LinIf_SlaveFrameState_Irrelevant; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      /* #80 If received header is a MRF header, configure response reception */
      if ( PduPtr->Pid == 0x3Cu )
      {
        /* Configure reception of master request frame */
        slaveChannelDataPtr->LinIf_FrameState   = LinIf_SlaveFrameState_Rx; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
        channelDataPtr->LinIf_CurrentFrameType  = LinIf_FrameType_MRF;  /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
        PduPtr->Drc                             = (Lin_FrameResponseType)LIN_FRAMERESPONSE_RX; /* SBSW_LINIF_PASSED_PTR_ACCESS */
        PduPtr->Dl                              = (Lin_FrameDlType)0x08u; /* SBSW_LINIF_PASSED_PTR_ACCESS */
        PduPtr->Cs                              = (Lin_FrameCsModelType)LIN_CLASSIC_CS; /* SBSW_LINIF_PASSED_PTR_ACCESS */
        retVal                                  = (Std_ReturnType)E_OK;
      }
      /* #90 If received header is a SRF header, forward header indication to diagnostic dispatcher */
      else if ( PduPtr->Pid == 0x7Du )
      {
# if ( LINIF_TP_SUPPORTED == STD_ON ) || ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
        retVal = LinIf_HeaderIndication_DiagTx(linIfChannelIdx, PduPtr, slaveChannelDataPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
# else
        retVal = (Std_ReturnType)E_OK;
# endif
      }
      /* #100 Otherwise handle received header as an unconditional frame header */
      else
      {
        /* Retrieve frame handle from PID */
        retVal = LinIf_HeaderIndication_Unconditional(linIfChannelIdx, PduPtr, slaveChannelDataPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
      }

      SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_2();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_HEADERINDICATION, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  LinIf_RxIndication()
 *********************************************************************************************************************/
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
 */
FUNC(void, LINIF_CODE) LinIf_RxIndication
(
  VAR(NetworkHandleType, AUTOMATIC)                               Channel,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)                         Lin_SduPtr
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  slaveChannelDataPtr;
  P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)       channelDataPtr;
  uint8                                                           errorId;
  PduInfoType                                                     pduInfo;
  uint8                                                           linIfChannelIdx;

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
#  if ( LINIF_TP_SUPPORTED == STD_ON )
  if ( (LinIf_Dev_InitDetect != LINIF_INIT) || (LinTp_Dev_InitDetect != LINTP_INIT) )
#  else
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
#  endif
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter Lin_SduPtr */
  else if ( Lin_SduPtr == (P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR))NULL_PTR )
  {
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  /* #30 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfLinDrvToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert Lin driver channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfLinDrvToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      channelDataPtr        = LinIf_GetAddrChannelData(linIfChannelIdx);
      slaveChannelDataPtr   = LinIf_GetAddrSlaveChannelData(LinIf_GetNodeChannelDataIdxOfLinIfChannel(linIfChannelIdx));

      SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_2();

      /* #40 Restart bus idle timer */
      slaveChannelDataPtr->LinIf_BusIdleTimer = LinIf_GetBusIdleTimeoutOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx)); /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      /* #50 If response is expected to be received */
      if ( slaveChannelDataPtr->LinIf_FrameState == LinIf_SlaveFrameState_Rx )
      {
        /* #60 If received response belongs to a MRF, forward to response diagnostic dispatcher */
        if ( channelDataPtr->LinIf_CurrentFrameType == LinIf_FrameType_MRF )
        {
          LinIf_RxIndication_DiagRequest(linIfChannelIdx, Lin_SduPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
        }
        /* #70 Otherwise received frame is an unconditional frame */
        else
        {
          /* #80 Report response data to upper layer */
          pduInfo.SduLength   = LinIf_GetLengthOfFrameList(channelDataPtr->LinIf_FrameHandle);
          pduInfo.SduDataPtr  = Lin_SduPtr;
# if ( LINIF_PDUR_ONLY_UL_OPTIMIZATION == STD_OFF )
          LinIf_GetRxIndFctList((uint8)LinIf_GetIndConfFctIdxOfFrameList(channelDataPtr->LinIf_FrameHandle))( /* SBSW_LINIF_FCT_POINTER_CALL */
                                        LinIf_GetPduIdOfFrameList(channelDataPtr->LinIf_FrameHandle), &pduInfo);
# else
          PduR_LinIfRxIndication(LinIf_GetPduIdOfFrameList(channelDataPtr->LinIf_FrameHandle), &pduInfo); /* SBSW_LINIF_FCT_CALL_EXTERNAL_WITH_PTR_STACK_VAR */
# endif

# if ( LINIF_BUSMIRRORING == STD_ON )
          /* #90 If bus mirroring is enabled, inform mirror module about response reception */
          if ( channelDataPtr->LinIf_MirroringActivationState == TRUE )
          {
            Mirror_ReportLinFrame(LinIf_GetSystemChannelIndexOfChannelIndTable(linIfChannelIdx), /* SBSW_LINIF_FCT_CALL_EXTERNAL_WITH_PTR_STACK_VAR */
                                  LinIf_GetPidOfFrameList(channelDataPtr->LinIf_FrameHandle), &pduInfo, LIN_RX_OK);
          }
# endif
        }

      }
      else
      {
        /* do nothing, ignore unexpected response indication */
      }

      /* reset state to wait for next header */
      slaveChannelDataPtr->LinIf_FrameState = LinIf_SlaveFrameState_Idle; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_2();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_RXINDICATION, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 *  LinIf_TxConfirmation()
 *********************************************************************************************************************/
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
 */
FUNC(void, LINIF_CODE) LinIf_TxConfirmation
(
  VAR(NetworkHandleType, AUTOMATIC)                               Channel
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  slaveChannelDataPtr;
  P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)       channelDataPtr;
  uint8                                                           linIfChannelIdx;
  uint8                                                           errorId;
  LinIf_NodeChannelConfigIdxOfChannelConfigType                   linIfSlaveChannel;
  uint8                                                           linRespErrSigVal = 0u;
# if ( LINIF_BUSMIRRORING == STD_ON )
  PduInfoType                                                     pduInfo;
# endif

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
#  if ( LINIF_TP_SUPPORTED == STD_ON )
  if ( (LinIf_Dev_InitDetect != LINIF_INIT) || (LinTp_Dev_InitDetect != LINTP_INIT) )
#  else
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
#  endif
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfLinDrvToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert Lin driver channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfLinDrvToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      linIfSlaveChannel   = LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx);
      channelDataPtr      = LinIf_GetAddrChannelData(linIfChannelIdx);
      slaveChannelDataPtr = LinIf_GetAddrSlaveChannelData(linIfSlaveChannel);

      SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_2();

      /* #30 Restart bus idle timer */
      slaveChannelDataPtr->LinIf_BusIdleTimer = LinIf_GetBusIdleTimeoutOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx)); /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      /* #40 If response transmission is expected to be confirmed */
      if ( slaveChannelDataPtr->LinIf_FrameState == LinIf_SlaveFrameState_Tx )
      {
# if ( LINIF_TP_SUPPORTED == STD_ON ) || ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
        /* #50 If transmitted response belongs to a SRF, forward confirmation to diagnostic dispatcher */
        if ( channelDataPtr->LinIf_CurrentFrameType == LinIf_FrameType_SRF )
        {
#  if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
#   if ( LINIF_TP_SUPPORTED == STD_ON )
          if ( slaveChannelDataPtr->LinIf_NcRespBuffer[0] != 0x00u )
#   endif
          {
            /* clear response pending flag */
            slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
            /* disable Nas timer */
            slaveChannelDataPtr->LinIf_NasTimer = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
          }
#  endif
#  if ( LINIF_TP_SUPPORTED == STD_ON )
#   if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
          else
#   endif
          {
            LinTp_SlaveTxConfirmation(linIfChannelIdx);
          }
#  endif
        }
        /* #60 Otherwise response to an unconditional Tx frame */
        else
# endif
        {
          /* #70 If frame contains the response error signal and response error signal is currently set */
          if ( (LinIf_IsRespErrSignalExistsOfSlaveChannelConfig(linIfSlaveChannel)) &&
               (channelDataPtr->LinIf_FrameHandle == LinIf_GetFrameListRespErrTxFrameIdxOfSlaveChannelConfig(linIfSlaveChannel)) &&
               (slaveChannelDataPtr->LinIf_RespErrValue == 0x01u) ) /* COV_SLAVE_RESP_ERR_SIG */
          {
            /* #80 Request Com to clear the response error signal after successful transmission */
            (void)Com_SendSignal(LinIf_GetRespErrSignalHandleOfSlaveChannelConfig(linIfSlaveChannel), &linRespErrSigVal); /* PRQA S 0315 */ /* MD_LINIF_Dir1.1_0315 */ /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            /* #90 Inform upper layer if response signal changed callout is enabled */
# if ( LINIF_RESPERRSIG_CHANGED_CALLOUT == STD_ON )
            LinIf_RespErrSigChangedCalloutFctPtr(LinIf_GetSystemChannelIndexOfChannelIndTable(linIfChannelIdx), FALSE); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
# endif
            /* #100 Clear internal response error signal */
            slaveChannelDataPtr->LinIf_RespErrValue = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
          }

          /* #110 Confirm response transmission to upper layer */
# if ( LINIF_PDUR_ONLY_UL_OPTIMIZATION == STD_OFF )
          LinIf_GetTxConfFctList((uint8)LinIf_GetIndConfFctIdxOfFrameList(channelDataPtr->LinIf_FrameHandle))(LinIf_GetPduIdOfFrameList(channelDataPtr->LinIf_FrameHandle)); /* SBSW_LINIF_FCT_POINTER_CALL */
# else
          PduR_LinIfTxConfirmation(LinIf_GetPduIdOfFrameList(channelDataPtr->LinIf_FrameHandle));
# endif

# if ( LINIF_BUSMIRRORING == STD_ON )
          /* #120 If bus mirroring is enabled, inform mirror module about response transmission */
          if ( channelDataPtr->LinIf_MirroringActivationState == TRUE )
          {
            pduInfo.SduLength  = LinIf_GetLengthOfFrameList(channelDataPtr->LinIf_FrameHandle);
            pduInfo.SduDataPtr = slaveChannelDataPtr->LinIf_MirrorTxData;
            Mirror_ReportLinFrame(LinIf_GetSystemChannelIndexOfChannelIndTable(linIfChannelIdx), /* SBSW_LINIF_FCT_CALL_EXTERNAL_WITH_PTR_STACK_VAR */
                                  LinIf_GetPidOfFrameList(channelDataPtr->LinIf_FrameHandle), &pduInfo, LIN_TX_OK);
          }
# endif
        }

      }
      else
      {
        /* do nothing, ignore unexpected response indication */
      }

      /* reset state to wait for next header */
      slaveChannelDataPtr->LinIf_FrameState = LinIf_SlaveFrameState_Idle; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_2();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_TXCONFIRMATION, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  LinIf_LinErrorIndication()
 *********************************************************************************************************************/
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
 */
FUNC(void, LINIF_CODE) LinIf_LinErrorIndication
(
  VAR(NetworkHandleType, AUTOMATIC)                               Channel,
  VAR(Lin_SlaveErrorType, AUTOMATIC)                              ErrorStatus
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)  slaveChannelDataPtr;
# if ( LINIF_TP_SUPPORTED == STD_ON ) || ( LINIF_NC_GENERAL_SUPPORTED == STD_ON ) || ( LINIF_BUSMIRRORING == STD_ON )
  P2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)       channelDataPtr;
# endif
  uint8                                                           errorId;
  uint8                                                           linIfChannelIdx;
  LinIf_NodeChannelConfigIdxOfChannelConfigType                   linIfSlaveChannel;
  uint8                                                           linRespErrSigVal = 1u;

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
#  if ( LINIF_TP_SUPPORTED == STD_ON )
  if ( (LinIf_Dev_InitDetect != LINIF_INIT) || (LinTp_Dev_InitDetect != LINTP_INIT) )
#  else
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
#  endif
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfLinDrvToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert Lin driver channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfLinDrvToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      linIfSlaveChannel     = LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx);
# if ( LINIF_TP_SUPPORTED == STD_ON ) || ( LINIF_NC_GENERAL_SUPPORTED == STD_ON ) || ( LINIF_BUSMIRRORING == STD_ON )
      channelDataPtr        = LinIf_GetAddrChannelData(linIfChannelIdx);
# endif
      slaveChannelDataPtr   = LinIf_GetAddrSlaveChannelData(linIfSlaveChannel);

      SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_2();

      /* #30 Restart bus idle timer */
      slaveChannelDataPtr->LinIf_BusIdleTimer = LinIf_GetBusIdleTimeoutOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx)); /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      /* #40 If response is expected and an error during response processing has occurred */
      if ( (slaveChannelDataPtr->LinIf_FrameState == LinIf_SlaveFrameState_Tx) || (slaveChannelDataPtr->LinIf_FrameState == LinIf_SlaveFrameState_Rx) )
      {
        /* #50 Check if setting of response error bit is necessary */
        if ( (ErrorStatus == LIN_ERR_RESP_STOPBIT) || (ErrorStatus == LIN_ERR_RESP_CHKSUM) || (ErrorStatus == LIN_ERR_RESP_DATABIT) || (ErrorStatus == LIN_ERR_INC_RESP) )
        {
          /* #60 If response error signal exists on current LIN channel and is not yet set */
          if ( (LinIf_IsRespErrSignalExistsOfSlaveChannelConfig(linIfSlaveChannel)) && (slaveChannelDataPtr->LinIf_RespErrValue == 0x00u) ) /* COV_SLAVE_RESP_ERR_SIG */
          {
            /* #70 Request Com to set the response error signal */
            (void)Com_SendSignal(LinIf_GetRespErrSignalHandleOfSlaveChannelConfig(linIfSlaveChannel), &linRespErrSigVal); /* PRQA S 0315 */ /* MD_LINIF_Dir1.1_0315 */ /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
            /* #80 Inform upper layer if response signal changed callout is enabled */
# if ( LINIF_RESPERRSIG_CHANGED_CALLOUT == STD_ON )
            LinIf_RespErrSigChangedCalloutFctPtr(LinIf_GetSystemChannelIndexOfChannelIndTable(linIfChannelIdx), TRUE); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
# endif
            /* #90 Set internal response error signal */
            slaveChannelDataPtr->LinIf_RespErrValue = 0x01u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
          }
        }

# if ( LINIF_TP_SUPPORTED == STD_ON ) || ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
        /* #100 If current response belongs to a SRF, notify error to node configuration service and transport protocol handler */
        if ( channelDataPtr->LinIf_CurrentFrameType == LinIf_FrameType_SRF )
        {
#  if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
#   if ( LINIF_TP_SUPPORTED == STD_ON )
          if ( slaveChannelDataPtr->LinIf_NcRespBuffer[0] != 0x00u )
#   endif
          {
            /* clear response pending flag */
            slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
            /* disable Nas timer */
            slaveChannelDataPtr->LinIf_NasTimer = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
          }
#  endif
#  if ( LINIF_TP_SUPPORTED == STD_ON )
#   if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
          else
#   endif
          {
            /* close Tx connection on error */
            LinTp_TxCloseConnection(LinTp_GetAddrCtrl(linIfChannelIdx)); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
          }
#  endif
        }
# endif

        /* #110 If the error is not a header error */
        if ( ErrorStatus != LIN_ERR_HEADER )
        {
          /* #120 Report error to upper layer */
          errorId = LINIF_E_RESPONSE;

# if ( LINIF_BUSMIRRORING == STD_ON )
          /* #130 If bus mirroring is enabled, inform mirror module with matching error code */
          LinIf_ErrorIndication_Mirror(linIfChannelIdx, ErrorStatus, channelDataPtr, slaveChannelDataPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
# endif
        }

        /* reset state to wait for next header */
        slaveChannelDataPtr->LinIf_FrameState = LinIf_SlaveFrameState_Idle; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
      }
      else
      {
        /* do nothing, no further error handling for irrelevant frames or in idle state required */
      }

      SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_2();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_LINERRORINDICATION, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */


/**********************************************************************************************************************
 *
 * END - LinIf Slave callback functions from driver
 *
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *
 * LinIf Initialization, Task and General Functions for slave nodes
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LinIf_SlaveChannelMainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, LINIF_CODE) LinIf_SlaveChannelMainFunction
(
  VAR(NetworkHandleType, AUTOMATIC)                                 LinIfChannel
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)    slaveChannelDataPtr;
# if ( LINIF_TP_SUPPORTED == STD_ON )
  P2VAR(LinTp_ControlType,     AUTOMATIC, LINIF_VAR_NOINIT)         tpCtrlPtr;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* get pointer to general channel data */
  slaveChannelDataPtr = LinIf_GetAddrSlaveChannelData(LinIf_GetNodeChannelDataIdxOfLinIfChannel(LinIfChannel));
# if ( LINIF_TP_SUPPORTED == STD_ON )
  tpCtrlPtr           = LinTp_GetAddrCtrl(LinIfChannel);
# endif

  /* #10 Update bus idle timer if active */
  if ( slaveChannelDataPtr->LinIf_BusIdleTimer > 0u )
  {
    slaveChannelDataPtr->LinIf_BusIdleTimer--; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
    /* #20 If bus idle timeout has elapsed, start sleep mode transition */
    if ( slaveChannelDataPtr->LinIf_BusIdleTimer == 0u )
    {
      /* indicate sleep mode, caused by bus idle, to upper layer */
# if ( LINIF_LINSM_ONLY_UL_OPTIMIZATION == STD_OFF )
      LinIf_GetGotoSleepIndFctList(LinIf_GetGotoSleepIndFctListIdxOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)))( /* SBSW_LINIF_FCT_POINTER_CALL */
                    LinIf_GetSystemChannelIndexOfChannelIndTable(LinIfChannel));
# else
      LinSM_GotoSleepIndication(LinIf_GetSystemChannelIndexOfChannelIndTable(LinIfChannel));
# endif
    }
  }

# if ( LINIF_TP_SUPPORTED == STD_ON )
  /* #30 Update Tp timer and abort Tp connection on timeout (if transport protocol is enabled) */
  if (tpCtrlPtr->LinTp_Timer > 0u)
  {
    tpCtrlPtr->LinTp_Timer--; /* SBSW_LINIF_TP_CTRL_PTR_LOCAL */
    if (tpCtrlPtr->LinTp_Timer == 0u)
    {
      LinTp_CloseActiveConnection(tpCtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
    }
  }

  /* #40 Poll PduR for transmission data or reception buffer if necessary (if transport protocol is enabled) */
  LinTp_BufferPolling(tpCtrlPtr); /* SBSW_LINIF_FCT_CALL_PTR_HANDOVER_OR_LOCAL_OR_CSL */
# endif

# if ( LINIF_NC_GENERAL_SUPPORTED == STD_ON )
  /* #50 Update N_As node configuration service timer (if node configuration services are enabled) */
  if ( slaveChannelDataPtr->LinIf_NasTimer > 0u )
  {
    slaveChannelDataPtr->LinIf_NasTimer--; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
    /* #60 If N_As node configuration service timeout has elapsed, clear pending response */
    if ( slaveChannelDataPtr->LinIf_NasTimer == 0u )
    {
      slaveChannelDataPtr->LinIf_NcRespBuffer[0] = 0x00u; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
    }
  }
# endif
}

/**********************************************************************************************************************
 *
 * END - LinIf Initialization, Task and General Functions for slave nodes
 *
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *
 * LinIf Node Management for slave nodes
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LinIf_SlaveWakeup()
 *********************************************************************************************************************/
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
 */
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SlaveWakeup
(
  VAR(NetworkHandleType, AUTOMATIC)                                     Channel,
  VAR(NetworkHandleType, AUTOMATIC)                                     LinIfChannel,
  CONSTP2VAR(LinIf_ChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)        ChannelDataPtr /* PRQA S 3673 */ /* MD_LINIF_Rule8.13_3673 */
)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(LinIf_SlaveChannelDataType, AUTOMATIC, LINIF_VAR_NOINIT)        slaveChannelDataPtr;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_1();

  /* #10 If channel state is OPERATIONAL */
  if ( ChannelDataPtr->LinIf_ChannelState == LINIF_CHANNEL_OPERATIONAL )
  {
    /* #20 Confirm the wakeup to upper layer because the state is already operational */
    /* Call function directly called, so no wakeup is send, to inform upper layer */
# if ( LINIF_WAKEUPCONF_AR403_COMPATIBILITY == STD_ON )
    /* FALSE returned because no wakeup frame is sent */
#  if ( LINIF_LINSM_ONLY_UL_OPTIMIZATION == STD_OFF )
    LinIf_GetWakeupConfFctList(LinIf_GetWakeupConfFctListIdxOfChannelConfig(LinIfChannel))(Channel, FALSE); /* SBSW_LINIF_FCT_POINTER_CALL */
#  else
    LinSM_WakeupConfirmation(Channel, FALSE);
#  endif
# else
    /* TRUE returned because wakeup is accepted according to AR4-612 (AR4.1.x) */
#  if ( LINIF_LINSM_ONLY_UL_OPTIMIZATION == STD_OFF )
    LinIf_GetWakeupConfFctList(LinIf_GetWakeupConfFctListIdxOfChannelConfig(LinIfChannel))(Channel, TRUE); /* SBSW_LINIF_FCT_POINTER_CALL */
#  else
    LinSM_WakeupConfirmation(Channel, TRUE);
#  endif
# endif
  }
  /* #30 Otherwise if channel is SLEEP */
  else if ( ChannelDataPtr->LinIf_ChannelState == LINIF_CHANNEL_SLEEP ) /* COV_LINIF_MISRA_ELSEBRANCH */
  {
    slaveChannelDataPtr   = LinIf_GetAddrSlaveChannelData(LinIf_GetNodeChannelDataIdxOfLinIfChannel(LinIfChannel));

    /* #40 If the external wakeup flag is not set, start transmission of a wakeup frame */
# if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
    if (ChannelDataPtr->LinIf_WakeupFlag == (uint8)0x00u)
# endif
    { /* no external wakeup was indicated previously */

      /* set LIN driver to sleep mode to be able to transmit a wakeup frame in case of wakeup repetition */
      if ( slaveChannelDataPtr->LinIf_NmWakeupState == LinIf_SlaveNmState_WaitForWakeupConf )
      {
# if ( LINIF_MULTIPLE_DRIVER_SUPPORT == STD_ON )
        (void) LinIf_GetLin_GoToSleepInternalFctOfLinInstFctTable(LinIf_GetLinInstFctTableIdxOfChannelConfig(LinIfChannel)) (LinIf_GetLinChannelIndexOfChannelIndTable(LinIfChannel)); /* SBSW_LINIF_FCT_POINTER_CALL */
# else
        (void) LinIf_Lin_GoToSleepInternal_FctCall(LinIf_GetLinChannelIndexOfChannelIndTable(LinIfChannel));
# endif
      }

# if ( LINIF_MULTIPLE_DRIVER_SUPPORT == STD_ON )
      (void) LinIf_GetLin_WakeupFctOfLinInstFctTable(LinIf_GetLinInstFctTableIdxOfChannelConfig(LinIfChannel)) (LinIf_GetLinChannelIndexOfChannelIndTable(LinIfChannel)); /* SBSW_LINIF_FCT_POINTER_CALL */
# else
      (void) LinIf_Lin_Wakeup_FctCall(LinIf_GetLinChannelIndexOfChannelIndTable(LinIfChannel));
# endif

      /* #50 Update state to wait for the reception of the first header as completion of wakeup transition */
      slaveChannelDataPtr->LinIf_NmWakeupState = LinIf_SlaveNmState_WaitForWakeupConf; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
    }
# if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
    /* #60 Else If the external wakeup flag is set */
    else
    {
      /* #70 Set LIN driver to OPERATIONAL state without wakeup frame transmission */
      /* external wakeup already reported by driver or transceiver, suppress active wakeup frame transmission */
#  if ( LINIF_MULTIPLE_DRIVER_SUPPORT == STD_ON )
      (void) LinIf_GetLin_WakeupInternalFctOfLinInstFctTable(LinIf_GetLinInstFctTableIdxOfChannelConfig(LinIfChannel)) (LinIf_GetLinChannelIndexOfChannelIndTable(LinIfChannel)); /* SBSW_LINIF_FCT_POINTER_CALL */
#  else
      (void) LinIf_Lin_WakeupInternal_FctCall(LinIf_GetLinChannelIndexOfChannelIndTable(LinIfChannel));
#  endif

      /* #80 Transit to OPERATIONAL state and confirm the wakeup to upper layer */
      ChannelDataPtr->LinIf_ChannelState        = LINIF_CHANNEL_OPERATIONAL; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
      slaveChannelDataPtr->LinIf_BusIdleTimer   = LinIf_GetBusIdleTimeoutOfSlaveChannelConfig(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(LinIfChannel)); /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
      slaveChannelDataPtr->LinIf_NmWakeupState  = LinIf_SlaveNmState_Idle; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      /* Call function directly called, so no wakeup is send, to inform upper layer */
#  if ( LINIF_LINSM_ONLY_UL_OPTIMIZATION == STD_OFF )
      LinIf_GetWakeupConfFctList(LinIf_GetWakeupConfFctListIdxOfChannelConfig(LinIfChannel))(Channel, TRUE); /* SBSW_LINIF_FCT_POINTER_CALL */
#  else
      LinSM_WakeupConfirmation(Channel, TRUE);
#  endif
    }
# endif
  }
  else
  {
    /* MISRA only */
  }

  /* #90 Clear wakeup flag in any case */
# if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
  ChannelDataPtr->LinIf_WakeupFlag                   = (uint8)0x00u; /* SBSW_LINIF_CHANNEL_DATA_PTR_LOCAL */
# endif

  SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_1();

  return E_OK;
}


/**********************************************************************************************************************
 *
 * END - LinIf Node Management for slave nodes
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 *  LinIf Slave Configuration Services - Global Functions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LinIf_GetConfiguredNAD()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetConfiguredNAD
(
  VAR(NetworkHandleType, AUTOMATIC)             Channel,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)       Nad
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                retVal;
  uint8                                         errorId;
  uint8                                         linIfChannelIdx;

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  retVal = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter Nad */
  else if ( Nad == (P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR))NULL_PTR )
  {
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  /* #30 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfSystemToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert system channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfSystemToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_1();

      /* #40 Return configured NAD */
      *Nad = LinIf_GetAddrSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx))->LinIf_ConfiguredNAD; /* SBSW_LINIF_PASSED_PTR_ACCESS */

      SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_1();
      retVal = (Std_ReturnType)E_OK;
    }

  }
  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_GETCONFIGUREDNAD, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  LinIf_SetConfiguredNAD()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetConfiguredNAD
(
  VAR(NetworkHandleType, AUTOMATIC)             Channel,
  VAR(uint8, AUTOMATIC)                         Nad
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                retVal;
  uint8                                         errorId;
  uint8                                         linIfChannelIdx;

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  retVal = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter Nad */
  else if ( Nad == 0u )
  {
    errorId = LINIF_E_PARAMETER;
  }
  /* #30 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfSystemToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert system channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfSystemToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_1();

      /* #40 Update configured NAD */
      LinIf_GetAddrSlaveChannelData(LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx))->LinIf_ConfiguredNAD = Nad; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */

      SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_1();
      retVal = (Std_ReturnType)E_OK;
    }

  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_SETCONFIGUREDNAD, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  LinIf_GetPIDTable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetPIDTable
(
  VAR(NetworkHandleType, AUTOMATIC)                   Channel,
  P2VAR(Lin_FramePidType, AUTOMATIC, LINIF_APPL_VAR)  PidBuffer,
  P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR)             PidBufferLength
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                      retVal;
  uint8                                               errorId;
  uint8                                               linIfChannelIdx;
  uint8                                               linIfSlaveChannel;
  uint16_least                                        configuredPidTblIdx;

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  retVal = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter PidBuffer */
  else if ( PidBuffer == (P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR))NULL_PTR )
  {
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  /* #30 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfSystemToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert system channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfSystemToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      linIfSlaveChannel   = LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx);

# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
      /* #40 Check validity of parameter PidBufferLength */
      if ( PidBufferLength == (P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR))NULL_PTR )
      {
        errorId = LINIF_E_PARAMETER_POINTER;
      }
      else if ( ((*PidBufferLength) != 0u) && ((*PidBufferLength) < (uint8)LinIf_GetConfiguredPIDTableLengthOfSlaveChannelConfig(linIfSlaveChannel)) )
      {
        errorId = LINIF_E_PARAMETER;
      }
      else
# endif
      {
        /* ----- Implementation ----------------------------------------------- */
        /* #50 Copy configured PIDs to provided buffer if necessary */
        if ( (*PidBufferLength) != 0u )
        {
          for (configuredPidTblIdx = LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(linIfSlaveChannel);
               configuredPidTblIdx < LinIf_GetConfiguredPIDTableEndIdxOfSlaveChannelConfig(linIfSlaveChannel);
               configuredPidTblIdx++)
          {
            PidBuffer[configuredPidTblIdx - LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(linIfSlaveChannel)] = LinIf_GetConfiguredPIDTable(configuredPidTblIdx); /* SBSW_LINIF_PIDBUFFER_ARRAY */
          }
        }

        /* #60 Update length parameter with number of configured PID values */
        *PidBufferLength = (uint8)(LinIf_GetConfiguredPIDTableLengthOfSlaveChannelConfig(linIfSlaveChannel)); /* SBSW_LINIF_PASSED_PTR_ACCESS */

        retVal = (Std_ReturnType)E_OK;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_GETPIDTABLE, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  LinIf_SetPIDTable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetPIDTable
(
  VAR(NetworkHandleType, AUTOMATIC)                     Channel,
  P2CONST(Lin_FramePidType, AUTOMATIC, LINIF_APPL_VAR)  PidBuffer,
  VAR(uint8, AUTOMATIC)                                 PidBufferLength /* PRQA S 3206 */ /* MD_LINIF_Rule2.7_3206 */
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                      retVal;
  uint8                                               errorId;
  uint8                                               linIfChannelIdx;
  uint8                                               linIfSlaveChannel;
  uint16_least                                        configuredPidTblIdx;

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  retVal = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter PidBuffer */
  else if ( PidBuffer == (P2VAR(uint8, AUTOMATIC, LINIF_APPL_VAR))NULL_PTR )
  {
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  /* #30 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfSystemToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
# endif
  {
    /* convert system channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfSystemToLinIfChannel(Channel);
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#  endif
    else
# endif
    {
      linIfSlaveChannel   = LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx);

# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
      /* #40 Check validity of parameter PidBufferLength */
      if ( PidBufferLength < LinIf_GetConfiguredPIDTableLengthOfSlaveChannelConfig(linIfSlaveChannel))
      {
        errorId = LINIF_E_PARAMETER;
      }
      else
# endif
      {
        /* ----- Implementation ----------------------------------------------- */
        SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_1();

        /* #50 Update the configured PIDs with the values of provided buffer */
        for (configuredPidTblIdx = LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(linIfSlaveChannel);
             configuredPidTblIdx < LinIf_GetConfiguredPIDTableEndIdxOfSlaveChannelConfig(linIfSlaveChannel);
             configuredPidTblIdx++)
        {
          LinIf_SetConfiguredPIDTable(configuredPidTblIdx, PidBuffer[configuredPidTblIdx - LinIf_GetConfiguredPIDTableStartIdxOfSlaveChannelConfig(linIfSlaveChannel)]); /* SBSW_LINIF_SET_CONFIGURED_PID */
        }

        SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_1();
        retVal = (Std_ReturnType)E_OK;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_SETPIDTABLE, errorId);
  }
# else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

# if ( LINIF_NC_PRODUCT_ID_CONFIGURABLE_SUPPORTED == STD_ON )
/**********************************************************************************************************************
 *  LinIf_SetLinProductIdentification()
 *********************************************************************************************************************/
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
 */
FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetLinProductIdentification
(
  VAR(NetworkHandleType, AUTOMATIC)                   Channel,
  VAR(LinIf_ProductIdentType, AUTOMATIC)              ProductIdentKey,
  VAR(uint16, AUTOMATIC)                              Value
)
{
    /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                      retVal;
  uint8                                               errorId;
  uint8                                               linIfChannelIdx;
  uint8                                               linIfSlaveChannel;

  errorId = LINIF_E_NO_ERROR; /* PRQA S 2983 */ /* MD_LINIF_Rule2.2_2983 */
  retVal = (Std_ReturnType)E_NOT_OK; /* PRQA S 2983 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* #10 Check if component is initialized */
  if ( LinIf_Dev_InitDetect != LINIF_INIT )
  {
    errorId = LINIF_E_UNINIT;
  }
  /* #20 Check validity of parameter ProductIdentKey */
  else if ( (ProductIdentKey != LINIF_LINPRODIDENT_SUPPLIER_ID) &&
            (ProductIdentKey != LINIF_LINPRODIDENT_FUNCTION_ID) &&
            (ProductIdentKey != LINIF_LINPRODIDENT_VARIANT_ID) )
  {
    errorId = LINIF_E_PARAMETER;
  }
  /* #30 Check validity of parameter Channel */
  else if ( Channel >= LinIf_GetSizeOfSystemToLinIfChannel() )
  {
    errorId = LINIF_E_NONEXISTENT_CHANNEL;
  }
  else
#  endif
  {
    /* convert system channel to LinIf channel */
    linIfChannelIdx   = LinIf_GetLinIfChannelIndexOfSystemToLinIfChannel(Channel);
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* check that LinIf channel handle exists and is in valid range */
    if ( linIfChannelIdx >= LinIf_GetSizeOfChannelData() )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#   if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
    /* check that LinIf channel handle addresses a LinIf slave channel */
    else if ( LinIf_GetNodeTypeOfChannelConfig(linIfChannelIdx) != LinIf_ChannelNodeType_Slave )
    {
      errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
#   endif
    else
#  endif
    {
      linIfSlaveChannel   = LinIf_GetNodeChannelConfigIdxOfLinIfChannel(linIfChannelIdx);

      SchM_Enter_LinIf_LINIF_EXCLUSIVE_AREA_1();

      /* #40 Update the selected LIN product identification property with the given value */
      switch ( ProductIdentKey )
      {
        /************************************************************************************
         *  Supplier ID
         ************************************************************************************/
        /* #50 If Supplier ID is selected, check given value and update supplier ID if value is in valid range */
        case LINIF_LINPRODIDENT_SUPPLIER_ID:
          if ( Value <= LinIf_Nc_Wildcard_SupplierID )
          {
            LinIf_GetSlaveChannelData(linIfSlaveChannel).LinIf_SupplierId = Value; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
            retVal = (Std_ReturnType)E_OK;
          }
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
          else
          {
            errorId = LINIF_E_PARAMETER;
          }
#  endif
          break;

        /************************************************************************************
         *  Function ID
         ************************************************************************************/
        /* #60 If Function ID is selected, update Function ID */
        case LINIF_LINPRODIDENT_FUNCTION_ID:
          LinIf_GetSlaveChannelData(linIfSlaveChannel).LinIf_FunctionId = Value; /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
          retVal = (Std_ReturnType)E_OK;
          break;

        /************************************************************************************
         *  Variant ID
         ************************************************************************************/
        /* #70 If Variant ID is selected, update Variant ID with LSB of given value */
        case LINIF_LINPRODIDENT_VARIANT_ID:
          LinIf_GetSlaveChannelData(linIfSlaveChannel).LinIf_VariantId = (uint8)(Value & 0x00FFu); /* SBSW_LINIF_MASTER_SLAVE_CHANNEL_DATA_PTR */
          retVal = (Std_ReturnType)E_OK;
          break;

        /************************************************************************************
         *  Unknown / invalid property
         ************************************************************************************/
        default: /* COV_LINIF_MISRA_DEFAULTBRANCH */
          break;
      }

      SchM_Exit_LinIf_LINIF_EXCLUSIVE_AREA_1();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if ( LINIF_DEV_ERROR_REPORT == STD_ON )
  if ( errorId != LINIF_E_NO_ERROR )
  {
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_SETLINPRODUCTIDENTIFICATION, errorId);
  }
#  else
  LINIF_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
# endif

/**********************************************************************************************************************
 *
 *  END - LinIf Slave Configuration Services - Global Functions
 *
 *********************************************************************************************************************/

# define LINIF_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* LINIF_NODETYPE_SLAVE_SUPPORTED */
