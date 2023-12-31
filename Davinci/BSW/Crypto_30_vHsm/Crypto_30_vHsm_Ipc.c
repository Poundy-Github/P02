/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Crypto_30_vHsm_Ipc.c
 *        \brief  MICROSAR vHsm Crypto Driver (Crypto)
 *
 *      \details  Inter-processor communication between Host and Vector Hardware Security Module Firmware.
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_IPC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm.h"
#include "Crypto_30_vHsm_Ipc.h"
#include "Crypto_30_vHsm_Jobs.h"
#include "CryIf_Cbk.h"
#include "SchM_Crypto_30_vHsm.h"

#if ( CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_VHSM_LOCAL) /* COV_CRYPTO_30_VHSM_LOCAL_DEFINE */
# define CRYPTO_30_VHSM_LOCAL                                         static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL_INLINE) /* COV_CRYPTO_30_VHSM_LOCAL_DEFINE */
# define CRYPTO_30_VHSM_LOCAL_INLINE                                  LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Allocate non-cached, shared memory for inter-processor communication between Host and vHSM. */
VAR( uint32, CRYPTO_30_VHSM_VAR_NOINIT ) Crypto_30_vHsm_Ipc_Memory[CRYPTO_30_VHSM_IPC_MEMORY_SIZE / 4u];

#define CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Pointer to the IPC memory */
P2VAR( uint32, CRYPTO_30_VHSM_VAR_NOINIT, CRYPTO_30_VHSM_VAR_NOINIT ) Crypto_30_vHsm_Ipc_MemoryPtr;

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SendRequestToIpc()
 *********************************************************************************************************************/
/*!
 * \brief       Serialize the jobrequest
 * \details     -
 * \param[in]   jobRequestId         Valid Id of the jobrequest
 * \param[in]   jobRequestBuffer     Valid buffer pointer where the job shall be serialized.
 *                                   Must at least be of size jobRequestBufferSize.
 * \param[in]   jobRequestBufferSize Valid size of the buffer
 * \param[in]   cancel               Indicates if this is a cancel request
 * \return      TRUE if the job request was correctly serialized, otherwise E_NOT_OK
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SendRequestToIpc(
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  Crypto_30_vHsm_JobRequestBufferPtrType jobRequestBuffer,
  Crypto_30_vHsm_JobRequestBufferSizeType jobRequestBufferSize,
  boolean cancel);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_GetResponseFromIpc()
 *********************************************************************************************************************/
/*!
 * \brief       Deserialize the job response
 * \details     -
 * \param[in]   rxChannelId           Valid Channel where the response is allocated
 * \param[in]   jobResponseBuffer     Valid buffer pointer which shall be used to deserialized the job.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_GetResponseFromIpc(
  Crypto_30_vHsm_ChannelIdType rxChannelId,
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer);

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SendRequestToIpc()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SendRequestToIpc(
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  Crypto_30_vHsm_JobRequestBufferPtrType jobRequestBuffer,
  Crypto_30_vHsm_JobRequestBufferSizeType jobRequestBufferSize,
  boolean cancel)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Crypto_30_vHsm_JobKindType jobRequestKind;
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  Crypto_JobRedirectionInfoType Crypto_JobRedirectionInfoDummy;
  P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) Crypto_JobRedirectionInfoPtr;
  boolean isCryptoJob = FALSE;
#endif
  uint32 jobInformation;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the kind of the job request */
  jobRequestKind = Crypto_30_vHsm_GetKindOfJobRequest(jobRequestId);

  if ((jobRequestKind == CRYPTO_30_VHSM_CRYPTO_JOBKIND)
#if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
    || (jobRequestKind == CRYPTO_30_VHSM_CRYPTO_MACGEN_JOBKIND)
    || (jobRequestKind == CRYPTO_30_VHSM_CRYPTO_MACVER_JOBKIND)
#endif
    )
  {
#if(CRYPTO_30_VHSM_REDIRECTION == STD_ON)
    isCryptoJob = TRUE;
#endif
  }
  /* #21 Add job request header. */
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 1)
  jobInformation = jobRequestId;
#endif
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 2)
  jobInformation = ((1uL << 31) | (((uint32)(Crypto_30_vHsm_GetIdOfDriverObject(Crypto_30_vHsm_GetInternalObjectIdOfJobRequest(jobRequestId))) << 8)) | (jobRequestId & 0x000000FFu));
# if(CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  if ((isCryptoJob == TRUE)
    && (Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId)->jobRedirectionInfoRef != NULL_PTR))
  {
    jobInformation |= (((uint32)Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId)->jobRedirectionInfoRef->redirectionConfig) << 16);
    Crypto_JobRedirectionInfoPtr = Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId)->jobRedirectionInfoRef;
  }
  else
  {
    Crypto_JobRedirectionInfoDummy.redirectionConfig = 0u;
    Crypto_JobRedirectionInfoPtr = &Crypto_JobRedirectionInfoDummy;
  }
# endif
#endif
    /* Buffer size */
  Crypto_30_vHsm_Serialize_Uint32(jobRequestBufferSize, jobRequestBuffer); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  /* Header */
  Crypto_30_vHsm_Serialize_Uint32(jobInformation, &jobRequestBuffer[4]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(jobRequestKind, &jobRequestBuffer[8]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32((uint32)cancel, &jobRequestBuffer[12]); /* PRQA S 0310, 3305, 4304 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  /* Set init values inside jobRequest */
  Crypto_30_vHsm_SetUsedBufferOfJobRequest(jobRequestId, 0u); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  Crypto_30_vHsm_SetTrimmedOutputBufferOfJobRequest(jobRequestId, FALSE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
#endif

  /* #22 Call job request transmission function. */
  switch (jobRequestKind)
  {
#if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
  case CRYPTO_30_VHSM_CRYPTO_MACVER_JOBKIND:
    retVal = Crypto_30_vHsm_SerializeRequest_CryptoJob_MacVer( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
      jobRequestId,
      Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId),
      &jobRequestBuffer[16u],
      jobRequestBufferSize - 16u
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
      , Crypto_JobRedirectionInfoPtr
# endif
    );
    break;
  case CRYPTO_30_VHSM_CRYPTO_MACGEN_JOBKIND:
    retVal = Crypto_30_vHsm_SerializeRequest_CryptoJob_MacGen( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
      jobRequestId,
      Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId),
      &jobRequestBuffer[16u],
      jobRequestBufferSize - 16u
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
      , Crypto_JobRedirectionInfoPtr
# endif
    );
    break;
#endif
  case CRYPTO_30_VHSM_CRYPTO_JOBKIND:
    retVal = Crypto_30_vHsm_SerializeRequest_CryptoJob( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
      jobRequestId,
      Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId),
      &jobRequestBuffer[16u],
      jobRequestBufferSize - 16u
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
      , Crypto_JobRedirectionInfoPtr
#endif
    );
    break;
  case CRYPTO_30_VHSM_KEYMANAGEMENT_JOBKIND:
    retVal = Crypto_30_vHsm_SerializeRequest_KeyMJob( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
      jobRequestId,
      Crypto_30_vHsm_GetKeyMJobOfJobRequest(jobRequestId),
      &jobRequestBuffer[16u],
      jobRequestBufferSize - 16u);
    break;
  case CRYPTO_30_VHSM_KEYMANAGEMENT_COPY_PARTIAL_JOBKIND:
    retVal = Crypto_30_vHsm_SerializeRequest_KeyMJob_CopyPartial( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
      jobRequestId,
      Crypto_30_vHsm_GetKeyMJobOfJobRequest(jobRequestId),
      &jobRequestBuffer[16u],
      jobRequestBufferSize - 16u);
    break;
# if (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON)
  case CRYPTO_30_VHSM_KEYMANAGEMENT_KEYDERIVEJOB_JOBKIND:
    retVal = Crypto_30_vHsm_SerializeRequest_CryptoJob_KeyDerive( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
      jobRequestId,
      Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId),
      &jobRequestBuffer[16u],
      jobRequestBufferSize - 16u);
    break;
#endif
  default: /* COV_CRYPTO_30_VHSM_MISRA_ADDITIONAL_STATEMENT */ /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_GetResponseFromIpc()
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
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_GetResponseFromIpc(
  Crypto_30_vHsm_ChannelIdType rxChannelId,
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CRYPTO_E_PARAM_VALUE;

  Crypto_30_vHsm_JobRequestIdType jobRequestId;
  Crypto_30_vHsm_JobKindType jobResponseKind;
  Crypto_30_vHsm_JobResponseBufferSizeType jobResponseBufferSize;

  /* #05 Parse and remove channel entry header. */
  jobResponseBufferSize = Crypto_30_vHsm_Deserialize_Uint32(jobResponseBuffer); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR_WITH_BUFFER */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the buffer is big enough to contain the job response */
  if (jobResponseBufferSize > CRYPTO_30_VHSM_JOBRESPONSE_HEADER_SIZE)
  {
    /* #20 Parse and remove job response header. */
    jobRequestId = Crypto_30_vHsm_Deserialize_Uint32(&jobResponseBuffer[4]);  /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR_WITH_BUFFER */
    jobRequestId &= 0x000000FFu;
    jobResponseKind = (Crypto_30_vHsm_JobKindType)Crypto_30_vHsm_Deserialize_Uint32(&jobResponseBuffer[8]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR_WITH_BUFFER */

    /* #30 Check if jobRequestKind is valid. */
    if ((jobRequestId < Crypto_30_vHsm_GetSizeOfJobRequest()))
    {
      /* Check if the jobRequestKind inside the request is the same as in the jobRequestList */
      if (Crypto_30_vHsm_GetKindOfJobRequest(jobRequestId) == jobResponseKind)
      {
        /* #40 Check that remaining job response buffer size matches the job kind. */
        if (Crypto_30_vHsm_JobBufferSize[jobResponseKind] == (jobResponseBufferSize - CRYPTO_30_VHSM_JOBRESPONSE_HEADER_SIZE))
        {

          /* #50 Call job response receive function for processing. */
          if ( (jobResponseKind == CRYPTO_30_VHSM_KEYMANAGEMENT_JOBKIND)
            || (jobResponseKind == CRYPTO_30_VHSM_KEYMANAGEMENT_COPY_PARTIAL_JOBKIND) )
          {
            Crypto_30_vHsm_ReceiveResponse_KeyMJob( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
              jobRequestId,
              &jobResponseBuffer[12]);
          }
          else
          {
            Crypto_30_vHsm_ReceiveResponse_CryptoJob( /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
              jobRequestId,
              &jobResponseBuffer[12]);
          }

          Crypto_30_vHsm_SetChannelState(rxChannelId, CRYPTO_30_VHSM_IPC_CHANNELSTATE_FREE); /* SBSW_CRYPTO_30_VHSM_CSL01_CHANNELSTATE */
          /* #60 State processing of job request is done and job results are available. */
          Crypto_30_vHsm_SetStateOfJobRequest(jobRequestId, CRYPTO_30_VHSM_JOBREQUEST_STATE_RESULT_AVAILABLE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
          errorId = CRYPTO_E_NO_ERROR;
#endif
        }
      }
    }
  }

#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 1)
  CRYPTO_30_VHSM_DUMMY_STATEMENT(rxChannelId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* #100 Call Det if error occurred */
    (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID, CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_SID_COPYJOBRESPONSERXDATA, errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_TransmitRequest()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_TransmitRequest(
  Crypto_30_vHsm_ChannelIdType txChannelId,
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  boolean cancel)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = CRYPTO_30_VHSM_IPC_E_NO_ERROR;
  uint32 readIdx;
  uint32 writeIdx;

  /* Use local copy of read index to prevent concurrency issues. */
  readIdx = Crypto_30_vHsm_Ipc_GetTxChannelReadIdx(txChannelId); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */
  writeIdx = Crypto_30_vHsm_Ipc_GetTxChannelWriteIdx(txChannelId); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Return BUSY when channel is full. */
  if ((writeIdx - readIdx) > 0u)
  {
    /* Error: Tx Channel is full. */
    retVal = CRYPTO_E_BUSY;
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
    /* Error: Cannot allocate enough space for job request in Tx channel. */
    errorId = CRYPTO_30_VHSM_IPC_E_CANNOT_ALLOCATE_JOBREQUEST_BUFFER;
#endif
  }
  else  /* (writeIdx - readIdx) < CRYPTO_30_VHSM_IPC_CHANNEL_SIZE */
  {
    /* #30 Copy job request data from driver into Tx channel for transmission to vHsm. */
    retVal = Crypto_30_vHsm_SendRequestToIpc(jobRequestId, (Crypto_30_vHsm_JobRequestBufferPtrType)Crypto_30_vHsm_Ipc_GetTxChannelBuffer(txChannelId), CRYPTO_30_VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE, cancel); /* PRQA S 0310 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
    if (E_OK != retVal)
    {
      /* Error: Copying job request data for transmission failed. */
      errorId = CRYPTO_30_VHSM_IPC_E_CANNOT_COPY_JOBREQUEST_DATA;
    }
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_30_VHSM_IPC_E_NO_ERROR)
  {
    /* #100 Report Det if error occurred */
    (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_IPC_SID_TRANSMITJOBREQUEST, errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  return retVal;
}

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_ReceiveResponse()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_ReceiveResponse(
  Crypto_30_vHsm_ChannelIdType rxChannelId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 readIdx;
  uint32 writeIdx;
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer;

  /* ----- Implementation ----------------------------------------------- */
  readIdx = Crypto_30_vHsm_Ipc_GetRxChannelReadIdx(rxChannelId); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */
  /* Use local copy of write index to prevent concurrency issues. */
  writeIdx = Crypto_30_vHsm_Ipc_GetRxChannelWriteIdx(rxChannelId); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */

  /* #10 Receive job responses from Rx channel if present. */
  if (readIdx != writeIdx)
  {
    jobResponseBuffer = (Crypto_30_vHsm_JobResponseBufferPtrType)Crypto_30_vHsm_Ipc_GetRxChannelBuffer(rxChannelId); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */

    /* #40 Copy job response data to driver for processing. */
    /* When a job response was invalid it is marked as read and will be discared! */
    Crypto_30_vHsm_GetResponseFromIpc(rxChannelId, jobResponseBuffer); /* SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR */

    /* #50 Commit the reception of the job response. */
    Crypto_30_vHsm_Ipc_GetRxChannelReadIdx(rxChannelId) = writeIdx; /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* SBSW_CRYPTO_30_VHSM_SET_VALUE_IN_IPC */
  }
}

#define CRYPTO_30_VHSM_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_GetDet()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_GetDet(
  P2VAR(uint16, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) moduleId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) instanceId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) apiId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) errorId)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the values of the Det stored inside the Ipc */
  /* PRQA S 0310, 3305 4 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */
  *moduleId = Crypto_30_vHsm_Ipc_GetDetModuleId(); /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
  *instanceId = Crypto_30_vHsm_Ipc_GetDetInstanceId(); /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
  *apiId = Crypto_30_vHsm_Ipc_GetDetApiId(); /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
  *errorId = Crypto_30_vHsm_Ipc_GetDetErrorId(); /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
}
#endif

/*********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_ProcessChannels()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_ProcessChannels(void)
{
  /* ----- Implementation ----------------------------------------------- */
  Crypto_30_vHsm_ChannelStateIterType rxChannel;

  /* #10 Process the job response available in the IPC */
  for (rxChannel = 0u; rxChannel  < Crypto_30_vHsm_GetSizeOfChannelState(); rxChannel ++)
  {
    if (Crypto_30_vHsm_GetChannelState(rxChannel) == CRYPTO_30_VHSM_IPC_CHANNELSTATE_ASYNC)
    {
      Crypto_30_vHsm_Ipc_ReceiveResponse((Crypto_30_vHsm_ChannelIdType)rxChannel);
    }
  }
}

/*********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_ProcessCallbacks()
 *********************************************************************************************************************/
/*!
 *
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
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_ProcessCallbacks(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Crypto_30_vHsm_JobRequestIterType jobRequestId;
  Std_ReturnType jobRetVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all job request slots */
  for (jobRequestId = 0u; jobRequestId < Crypto_30_vHsm_GetSizeOfJobRequest(); jobRequestId++)
  {
    /* #21 Check if the job is an async job */
    if (Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId) == CRYPTO_PROCESSING_ASYNC)
    {
      /* #22 Check if the job request lock is still set */
      if (Crypto_30_vHsm_IsLockOfJobRequest(jobRequestId))
      {
        /* #23 Check if the job request is finished */
        if (Crypto_30_vHsm_GetStateOfJobRequest(jobRequestId) == CRYPTO_30_VHSM_JOBREQUEST_STATE_RESULT_AVAILABLE)
        {
          /* #30 Get the corresponding job */
          P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) tmpJob = Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId);

          /* #40 Set the state of the job */
          tmpJob->CRYPTO_30_VHSM_JOB_STATE_MEMBER = Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST_JOB_PTR */

          /* #50 Check if the mode was finish */
          if (((tmpJob->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH)
            || (Crypto_30_vHsm_IsCancelOfJobRequest(jobRequestId)))
          {
            /* #60 Remove the lock from the driver object to accept new jobs */
            SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_3();
            Crypto_30_vHsm_SetDriverObjectLock(Crypto_30_vHsm_GetInternalObjectIdOfJobRequest(jobRequestId), CRYPTO_30_VHSM_ACCEPT_ANY_JOBID); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
            SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_3();
          }

          jobRetVal = (Std_ReturnType)Crypto_30_vHsm_GetResultOfJobRequest(jobRequestId);
          /* #70 Free the job request lock */
          Crypto_30_vHsm_SetStateOfJobRequest(jobRequestId, CRYPTO_30_VHSM_JOBREQUEST_STATE_IDLE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

          Crypto_30_vHsm_SetLockOfJobRequest(jobRequestId, FALSE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

          /* #80 Call the CryIf callback */
          CryIf_CallbackNotification(
            tmpJob, /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
            jobRetVal);
        }
      }
    }
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Ipc.c
 *********************************************************************************************************************/
