/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  Crypto_30_vHsm.c
 *      \brief  MICROSAR vHsm Crypto Driver (Crypto)
 *
 *      \details  Core of the Vector Hardware Security Module Firmware driver.
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

#define CRYPTO_30_VHSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm.h"
#include "Crypto_30_vHsm_Ipc.h"
#include "Crypto_30_vHsm_Jobs.h"
#include "SchM_Crypto_30_vHsm.h"
#include "vstdlib.h"

#if ( CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

 /* Check the version of CRYPTO header file */
#if (  (CRYPTO_30_VHSM_MAJOR_VERSION != (2u)) \
    || (CRYPTO_30_VHSM_MINOR_VERSION != (6u)) \
    || (CRYPTO_30_VHSM_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of Crypto_30_vHsm.c and Crypto_30_vHsm.h are inconsistent"
#endif

#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 1)
# if ( (Crypto_30_vHsm_GetSizeOfDriverObject() != 4) \
     || (Crypto_30_vHsm_GetIpcChannelsOfvHsm() != Crypto_30_vHsm_GetSizeOfDriverObject()) \
     || (Crypto_30_vHsm_GetIpcChannelsOfvHsm() != Crypto_30_vHsm_GetSizeOfDriverObject()) )
#  error Configuring additional driver objects is not supported at the moment!
# endif
#endif

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
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Data Buffer containing all pointers to the buffers used by the driver */
VAR(Crypto_30_vHsm_GlobalDataBufferType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DataBufferBuffer;

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Pointer to the data Buffer */
P2VAR(Crypto_30_vHsm_GlobalDataBufferType, CRYPTO_30_VHSM_VAR_INIT, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DataBufferPtr = &Crypto_30_vHsm_DataBufferBuffer;

#define CRYPTO_30_VHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
VAR(uint8, CRYPTO_30_VHSM_VAR_ZERO_INIT) Crypto_30_vHsm_ModuleInitialized;
#endif

#define CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

 /**********************************************************************************************************************
 *  Crypto_30_vHsm_HandleDet()
 *********************************************************************************************************************/
 /*!
 * \brief       Checks if vHSM invokes a DET error and forwards it to Det module
 * \details     Gets parameters from IPC, acknowledges the handling and calls Det_ReportError
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
CRYPTO_30_VHSM_LOCAL FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_HandleDet(void);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_AllocateJobRequest()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Try to allocate a job request on the IPC
 * \details     -
 * \param[in]   internalObjectId       Driver object which shall be used
 * \param[in]   jobRequestId           Valid pinter for ID of the job request
 * \return      E_OK if the request was successfully allocated, otherwise E_NOT_OK.
 * \pre         Needs to be called with a lock on CRYPTO_30_VHSM_EXCLUSIVE_AREA_0
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_AllocateJobRequest(
  uint32 internalObjectId,
  P2VAR(Crypto_30_vHsm_JobRequestIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRequestId);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_IsCryptoJobAccepted()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Check if the job can be accepted
 * \details     When a job is not finished, only the same jobId will be forwarded. All other jobs will be blocked.
 * \param[in]   internalObjectId        Valid driver object ID which shall be checked
 * \param[in]   job                     Valid pointer to a job structure which shall be checked for acceptance
 * \param[in]   jobRequestIdPtr         Valid pointer to the jobRequestId which will be filled during allocation of the job inside the IPC.
 * \return      E_OK if the job is accepted, otherwise E_NOT_OK
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_IsCryptoJobAccepted(
  uint32 internalObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) job,
  P2VAR(Crypto_30_vHsm_JobRequestIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRequestIdPtr);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ProcessCryptoJob()
 *********************************************************************************************************************/
/*!
 *
 * \brief      Process a crypto job
 * \details    Putting the job request into the IPC and send the request to the vHsm
 * \param[in]  internalObjectId   Valid driver object ID which shall execute the job
 * \param[in]  job                Valid pointer to the job structure
 * \param[in]  cancel             Indicates if this is a cancel request
 * \return     Return of the job
 * \pre        -
 * \context    ANY
 * \reentrant  TRUE
 * \synchronous TRUE or FALSE depending on the job
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ProcessCryptoJob(
  uint32 internalObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) job,
  boolean cancel);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_TransmitRequest()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Use the Ipc to transmitt a job request
 * \details     -
 * \param[in]   jobRequestId   Valid Id of the job request
 * \param[in]   cancel         Indicates if this is a cancel request
 * \param[out]  channel        Valid pointer to the memory location which will contain the channel
 * \return      Return of the job request
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_TransmitRequest(
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  boolean cancel,
  P2VAR(Crypto_30_vHsm_ChannelIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) channel);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  Crypto_30_vHsm_HandleDet()
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
 */
CRYPTO_30_VHSM_LOCAL FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_HandleDet(void)
{
  if (Crypto_30_vHsm_Ipc_GetDetReportFlag() == TRUE) /* PRQA S 0310, 3305, 4340 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */
  {
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
    /* #10 Check if a Det error has been reported */
    SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_1();
    if (Crypto_30_vHsm_Ipc_GetDetReportFlag() == TRUE) /* PRQA S 0310, 3305, 4340 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* COV_CRYPTO_30_VHSM_DOUBLE_CHECK */
    {
      uint16 moduleId;
      uint8 instanceId, apiId, errorId;

      /* #20 Get the Det parameters */
      Crypto_30_vHsm_Ipc_GetDet(&moduleId, &instanceId, &apiId, &errorId); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */

      /* #30 Acknowledge the forwarding of the Det Error */
      Crypto_30_vHsm_Ipc_SetDetReportFlag(FALSE); /* PRQA S 0310, 3305, 4404 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* SBSW_CRYPTO_30_VHSM_SET_VALUE_IN_IPC */
      SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_1();

#if (CRYPTO_30_VHSM_DET_INSTANCE_MASK != 0)
      /* #35 Modify the InstanceId of the Det to distinguish between DET from vHsm and DET from application core */
      instanceId |= Crypto_30_vHsm_GetDetInstanceMaskOfvHsm();
#endif

      /* #40 Call the Det */
      (void)Det_ReportError(moduleId, instanceId, apiId, errorId);
    }
    else
    {
      SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_1();
    }
#else
    /* #50 Acknowledge the forwarding of the Det Error */
    Crypto_30_vHsm_Ipc_SetDetReportFlag(FALSE); /* PRQA S 0310, 3305, 4404 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* SBSW_CRYPTO_30_VHSM_SET_VALUE_IN_IPC */
#endif
  }
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_AllocateJobRequest()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC( Std_ReturnType, CRYPTO_30_VHSM_CODE ) Crypto_30_vHsm_AllocateJobRequest(
  uint32 internalObjectId,
  P2VAR( Crypto_30_vHsm_JobRequestIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR ) jobRequestId )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Ensure that internalObjectId can be used as index for the jobRequest Table */
  if (internalObjectId < Crypto_30_vHsm_GetSizeOfJobRequest())
  {
    /* #20 Find a free slot in the IPC to store the job request */
    if (Crypto_30_vHsm_IsLockOfJobRequest(internalObjectId) == FALSE)
    {
      *jobRequestId = internalObjectId; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
      Crypto_30_vHsm_SetLockOfJobRequest(*jobRequestId, TRUE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_IsCryptoJobAccepted()
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
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_IsCryptoJobAccepted(
  uint32 internalObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) job, /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
  P2VAR(Crypto_30_vHsm_JobRequestIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRequestIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  uint32 acceptedCryptoJobId;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0();

  acceptedCryptoJobId = Crypto_30_vHsm_GetDriverObjectLock(internalObjectId);

  /* #10 Check if the driver object accepts all jobs */
  if (acceptedCryptoJobId == CRYPTO_30_VHSM_ACCEPT_ANY_JOBID)
  {
    /* #11 If the job is not a SINGLE_CALL: */
    if ((job->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode & CRYPTO_OPERATIONMODE_FINISH) != CRYPTO_OPERATIONMODE_FINISH)
    {
      /* #12 Prevent the access of the driver object from other other jobs */
      /* Rational: Prevent interleaved processing of single call and streaming operations. */
      Crypto_30_vHsm_SetDriverObjectLock(internalObjectId, job->jobInfo->jobId); /* SBSW_CRYPTO_30_VHSM_CSL01_DRIVEROBJECTLOCK */
    }
  }
  /* #20 Check if the given JobId can be accepted for this driver object */
  else if (acceptedCryptoJobId != job->jobInfo->jobId)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_OK;
  }

  if (retVal == E_OK)
  {
    /* #30 Allocate job request */
    if (Crypto_30_vHsm_AllocateJobRequest(internalObjectId, jobRequestIdPtr) == E_OK) /* SBSW_CRYPTO_30_VHSM_FORWARDING_STACK_VARIABLE_PTR */
    {
      retVal = E_OK;
    }
    /* #40 If allocation failed */
    else
    {
      /* #50 Set driver object to accept any job */
      /* Rational: Unlock driver object */
      Crypto_30_vHsm_SetDriverObjectLock(internalObjectId, CRYPTO_30_VHSM_ACCEPT_ANY_JOBID); /* SBSW_CRYPTO_30_VHSM_CSL01_DRIVEROBJECTLOCK */
      retVal = E_NOT_OK;
    }
  }

  SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0();

  return retVal;
}

/**********************************************************************************************************************
  Crypto_30_vHsm_ProcessCryptoJob()
 **********************************************************************************************************************/
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
 *
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ProcessCryptoJob(
  uint32 internalObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) job,
  boolean cancel)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  Crypto_30_vHsm_JobRequestIdType jobRequestId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the request is accepted by the crypto driver object and can be allocated inside the IPC */
  if (Crypto_30_vHsm_IsCryptoJobAccepted(internalObjectId, job, &jobRequestId) == E_OK) /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  {
#if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
    /* #20 Set the parameters of the job request */
    if( (job->jobPrimitiveInfo->primitiveInfo->service) == CRYPTO_MACVERIFY)
    {
      Crypto_30_vHsm_SetKindOfJobRequest(jobRequestId, CRYPTO_30_VHSM_CRYPTO_MACVER_JOBKIND); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }
    else if ((job->jobPrimitiveInfo->primitiveInfo->service) == CRYPTO_MACGENERATE)
    {
      Crypto_30_vHsm_SetKindOfJobRequest(jobRequestId, CRYPTO_30_VHSM_CRYPTO_MACGEN_JOBKIND); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }
    else
#endif
#if (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON)
    if ((job->jobPrimitiveInfo->primitiveInfo->service) == CRYPTO_KEYDERIVE)
    {
      Crypto_30_vHsm_SetKindOfJobRequest(jobRequestId, CRYPTO_30_VHSM_KEYMANAGEMENT_KEYDERIVEJOB_JOBKIND); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }
    else
#endif
    {
      Crypto_30_vHsm_SetKindOfJobRequest(jobRequestId, CRYPTO_30_VHSM_CRYPTO_JOBKIND); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }

    Crypto_30_vHsm_SetCryptoJobOfJobRequest(jobRequestId, job); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    Crypto_30_vHsm_SetProcessingTypeOfJobRequest(jobRequestId, job->jobPrimitiveInfo->processingType); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    Crypto_30_vHsm_SetInternalObjectIdOfJobRequest(jobRequestId, internalObjectId); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    Crypto_30_vHsm_SetCancelOfJobRequest(jobRequestId, cancel); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

    /* 21 Save job state and set it to processing */
    Crypto_30_vHsm_SetJobStateOfJobRequest(jobRequestId, job->CRYPTO_30_VHSM_JOB_STATE_MEMBER); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    job->CRYPTO_30_VHSM_JOB_STATE_MEMBER = CRYPTO_JOBSTATE_PROGRESSING; /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */

    /* #30 Process crypto job request. */
    retVal = Crypto_30_vHsm_ProcessJobRequest(jobRequestId, job->jobPrimitiveInfo->processingType, cancel);

    /* #40 Check if the job request has been correctly issued */
    if (retVal == E_OK)
    {
      /* #50 If the job is synchronous: */
      if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_SYNC)
      {
        /* #51 Obtain state and return value of synchronous crypto job. */
        job->CRYPTO_30_VHSM_JOB_STATE_MEMBER = Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
        retVal = (Std_ReturnType)Crypto_30_vHsm_GetResultOfJobRequest(jobRequestId);

        /* #52 Check if the mode was finish */
        if (((job->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH)
          || (Crypto_30_vHsm_IsCancelOfJobRequest(jobRequestId)))
        {
          SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_2();
          /* #53 Remove the lock from the driver object to accept new jobs */
          Crypto_30_vHsm_SetDriverObjectLock(internalObjectId, CRYPTO_30_VHSM_ACCEPT_ANY_JOBID); /* SBSW_CRYPTO_30_VHSM_CSL01_DRIVEROBJECTLOCK */
          SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_2();
        }

        /* #54 Free the job request lock */
        Crypto_30_vHsm_SetLockOfJobRequest(jobRequestId, FALSE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
      }
      /* #60 ELSE: If the job is asynchronous return E_OK */
    }
    /* #70 If job could not be issued correctly: */
    else
    {
      SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_2();
      /* #71 Remove the lock from the driver object to accept new jobs */
      Crypto_30_vHsm_SetDriverObjectLock(internalObjectId, CRYPTO_30_VHSM_ACCEPT_ANY_JOBID); /* SBSW_CRYPTO_30_VHSM_CSL01_DRIVEROBJECTLOCK */
      SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_2();

      /* #72 Restore job state and free the job request lock */
      job->CRYPTO_30_VHSM_JOB_STATE_MEMBER = Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
      Crypto_30_vHsm_SetLockOfJobRequest(jobRequestId, FALSE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }
  }
  else
  {
    /* #80 If the job request could not be allocated because the IPC was full return BUSY */
    retVal = CRYPTO_E_BUSY;
  }

  return retVal;
}
#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_ProcessJobRequest()
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
 *
 */
FUNC( Std_ReturnType, CRYPTO_30_VHSM_CODE ) Crypto_30_vHsm_ProcessJobRequest(
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  Crypto_ProcessingType processingType,
  boolean cancel )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Crypto_30_vHsm_ChannelIdType channel = Crypto_30_vHsm_GetIpcChannelsOfvHsm();

  /* ----- Implementation ----------------------------------------------- */

  if (Crypto_30_vHsm_Ipc_IsRamExec() == TRUE) /* PRQA S 0310, 3305, 4340 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* COV_CRYPTO_30_VHSM_NO_FLASH_SYNC_SUPPORT_IN_VHSM */
  {
    retVal = CRYPTO_E_BUSY;
  }
  else
  {
    /* #10 Set the state of the request to processing */
    Crypto_30_vHsm_SetStateOfJobRequest(jobRequestId, CRYPTO_30_VHSM_JOBREQUEST_STATE_PROCESSING); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

    /* #20 Transmit the job request to the IPC */
    retVal = Crypto_30_vHsm_TransmitRequest( jobRequestId, cancel, &channel); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */

    /* #21 Check if the job request was transmitted correctly */
    if (retVal == E_OK)
    {
      /* #22 Mark transmitted job as ready so that vHSM can start execution */
      /* Note: This will make the new job request immediately visible from vHsm. */
      Crypto_30_vHsm_Ipc_GetTxChannelWriteIdx(channel) += 1u; /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* SBSW_CRYPTO_30_VHSM_SET_VALUE_IN_IPC */

      Crypto_30_vHsm_TriggerInterrupt(); /* PRQA S 0303 */ /* MD_CRYPTO_30_VHSM_TRIGGER_INTERRUPT */ /* SBSW_CRYPTO_30_VHSM_TRIGGER_INTERRUPT */

      /* #30 Check if it is a synchronous job */
      if (processingType == CRYPTO_PROCESSING_SYNC)
      {
        /* #31 Wait until job response is available */
        /* The Flag will be set in the interrupt triggered by the vHsm */
        while (Crypto_30_vHsm_GetStateOfJobRequest(jobRequestId) == CRYPTO_30_VHSM_JOBREQUEST_STATE_PROCESSING)
        {
          /* #32 Process the job response available in the IPC if interrupt mode is disabled */
          Crypto_30_vHsm_Ipc_ReceiveResponse(channel);

#if (CRYPTO_30_VHSM_WAITLOOPCALLOUTOFVHSM == STD_ON)
          Crypto_30_vHsm_GetWaitLoopCalloutOfvHsm()();
#endif
        }
        Crypto_30_vHsm_SetStateOfJobRequest(jobRequestId, CRYPTO_30_VHSM_JOBREQUEST_STATE_IDLE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

        Crypto_30_vHsm_HandleDet(); /* PRQA S 2987 */ /* MD_CRYPTO_30_VHSM_2987_HANDLEDET */
      }
      /* #40 ELSE: If it is an asynchronous job: */
      /* #41 Do not wait until job response has been received, because this will be handled in the interrupt */
    }
    else
    {
      /* #50 Clear state if job could not be transmitted */
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 2)
      if (channel < Crypto_30_vHsm_GetSizeOfChannelState())
      {
        Crypto_30_vHsm_SetChannelState(channel, CRYPTO_30_VHSM_IPC_CHANNELSTATE_FREE); /* SBSW_CRYPTO_30_VHSM_CSL01_CHANNELSTATE */
      }
#endif
      Crypto_30_vHsm_SetStateOfJobRequest( jobRequestId, CRYPTO_30_VHSM_JOBREQUEST_STATE_IDLE ); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#define CRYPTO_30_VHSM_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_TransmitRequest()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_TransmitRequest(
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  boolean cancel,
  P2VAR(Crypto_30_vHsm_ChannelIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 2)
  Crypto_30_vHsm_ChannelIdType txChannelIdTmp;
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the TxChannel */
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 1)
  /* #20 Ensure that jobRequestId (which is the same as internalObjectId) can be used as index for the ChannelState Table */
  if (jobRequestId < Crypto_30_vHsm_GetSizeOfChannelState())
  {
    *channel = (Crypto_30_vHsm_ChannelIdType)jobRequestId; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
    Crypto_30_vHsm_SetChannelState(*channel, Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId) + 1u); /* SBSW_CRYPTO_30_VHSM_CSL01_CHANNELSTATE */

    /* #30 Transmit the job request */
    retVal = Crypto_30_vHsm_Ipc_TransmitRequest(*channel, jobRequestId, cancel);
  }
  else
  {
    retVal = E_NOT_OK;
  }
#endif
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 2)
  SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0();
  for (txChannelIdTmp = 0u; txChannelIdTmp < Crypto_30_vHsm_GetSizeOfChannelState(); txChannelIdTmp++)
  {
    if (Crypto_30_vHsm_GetChannelState(txChannelIdTmp) == CRYPTO_30_VHSM_IPC_CHANNELSTATE_FREE)
    {
      *channel = txChannelIdTmp; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
      Crypto_30_vHsm_SetChannelState(txChannelIdTmp, Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId) + 1u); /* SBSW_CRYPTO_30_VHSM_CSL01_CHANNELSTATE */
      break;
    }
  }
  SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0();

  if (txChannelIdTmp >= Crypto_30_vHsm_GetSizeOfChannelState())
  {
    retVal = CRYPTO_E_BUSY;
  }
  else
  {
    /* #30 Transmit the job request */
    retVal = Crypto_30_vHsm_Ipc_TransmitRequest(*channel, jobRequestId, cancel);
  }
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Crypto_30_vHsm_InitMemory()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the mode to uninitialized */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  Crypto_30_vHsm_ModuleInitialized = (uint8)CRYPTO_30_VHSM_UNINIT;
#endif

} /* Crypto_30_vHsm_InitMemory() */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_Init()
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
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  Crypto_30_vHsm_JobRequestIterType jobRequestIter;
  Crypto_30_vHsm_DriverObjectIterType driverObjectIdx;
  Crypto_30_vHsm_ChannelStateIterType txChannel;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Crypto_30_vHsm_ModuleInitialized == (uint8)CRYPTO_30_VHSM_INITIALIZED)
  {
    errorId = CRYPTO_E_INIT_FAILED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Initialize the IPC */
    Crypto_30_vHsm_Ipc_MemoryPtr = &Crypto_30_vHsm_Ipc_Memory[0U];

#if (CRYPTO_30_VHSM_IPC_INITIALIZATION == STD_ON)
    /* Check if Ipc has already been initialized before */
    if (Crypto_30_vHsm_IsIpcNotInitialized()) /* PRQA S 0303 */ /* MD_CRYPTO_30_VHSM_REGISTER_ACCESS */
    {
      /* Initialize IPC */
      VStdLib_MemClr(Crypto_30_vHsm_Ipc_Memory, CRYPTO_30_VHSM_IPC_MEMORY_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_VHSM_INIT_IPC_MEMORY */
    }
#endif

    for (txChannel = 0u; txChannel < Crypto_30_vHsm_GetSizeOfChannelState(); txChannel++)
    {
      Crypto_30_vHsm_SetChannelState(txChannel, CRYPTO_30_VHSM_IPC_CHANNELSTATE_FREE); /* SBSW_CRYPTO_30_VHSM_CSL01_CHANNELSTATE */
    }

#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 2)
    Crypto_30_vHsm_Ipc_DriverProtocolVersion() = CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION; /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* SBSW_CRYPTO_30_VHSM_SET_VALUE_IN_IPC */
#endif

    for (driverObjectIdx = 0u; driverObjectIdx < Crypto_30_vHsm_GetSizeOfDriverObject(); driverObjectIdx++)
    {
      Crypto_30_vHsm_SetDriverObjectLock(driverObjectIdx, CRYPTO_30_VHSM_ACCEPT_ANY_JOBID); /* SBSW_CRYPTO_30_VHSM_CSL01_DRIVEROBJECTLOCK */
    }

    /* #30 Reset job request states */
    for (jobRequestIter = 0u; jobRequestIter < Crypto_30_vHsm_GetSizeOfJobRequest(); jobRequestIter++)
    {
      Crypto_30_vHsm_SetLockOfJobRequest(jobRequestIter, FALSE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
      Crypto_30_vHsm_SetStateOfJobRequest(jobRequestIter, CRYPTO_30_VHSM_JOBREQUEST_STATE_IDLE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }

#if (CRYPTO_30_VHSM_IPC_INITIALIZATION == STD_ON)
    /* Indicate that IPC has been initialized. HSM will now be able to use the IPC. */
    Crypto_30_vHsm_IndicateInitializedIpc(); /* PRQA S 0303 */ /* MD_CRYPTO_30_VHSM_REGISTER_ACCESS */ /* SBSW_CRYPTO_30_VHSM_REGISTER_ACCESS */
#endif

    /* #40 Set module state to initialized */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
    Crypto_30_vHsm_ModuleInitialized = CRYPTO_30_VHSM_INITIALIZED;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* #100 Call Det if error occurred */
    (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID, CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_SID_INIT, errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

#if ( CRYPTO_30_VHSM_VERSION_INFO_API == STD_ON )
/**********************************************************************************************************************
 *  Crypto_30_vHsm_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) versioninfo
)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if provided pointer is valid */
  if (versioninfo == NULL_PTR)
  {
    /* [SWS_Crypto_00042] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Copy the version info to the provided buffer */
    versioninfo->vendorID = (uint16)CRYPTO_30_VHSM_VENDOR_ID; /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
    versioninfo->moduleID = (uint8)CRYPTO_30_VHSM_MODULE_ID; /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
    versioninfo->sw_major_version = (uint8)CRYPTO_30_VHSM_MAJOR_VERSION; /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
    versioninfo->sw_minor_version = (uint8)CRYPTO_30_VHSM_MINOR_VERSION; /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
    versioninfo->sw_patch_version = (uint8)CRYPTO_30_VHSM_PATCH_VERSION; /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* #30 Call Det if pointer was invalid */
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      (uint8)CRYPTO_30_VHSM_SID_GET_VERSION_INFO,
      errorId);
  }
# else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_MainFunction()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_MainFunction(void)
{
#if (CRYPTO_30_VHSM_INTERRUPT_MODE == STD_OFF)
  /* #10 Process the job response available in the IPC */
  Crypto_30_vHsm_Ipc_ProcessChannels();

  /* #20 Process the callbacks of async jobs */
  Crypto_30_vHsm_Ipc_ProcessCallbacks();
#endif

  /* #30 Check Det if error occurred */
  Crypto_30_vHsm_HandleDet(); /* PRQA S 2987 */ /* MD_CRYPTO_30_VHSM_2987_HANDLEDET */
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ProcessJob()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ProcessJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  /* Check if module is initialized */
  /* [SWS_Crypto_00057] Check initialization state of the component */
  if (Crypto_30_vHsm_ModuleInitialized == (uint8)CRYPTO_30_VHSM_UNINIT)
  {
    errorId = CRYPTO_E_UNINIT;
  }
  /* Check plausibility of input parameters */
  /* [SWS_Crypto_00058] Check if driver object is valid */
  else if (objectId >= Crypto_30_vHsm_GetSizeOfInternalObjectIds())
  {
    errorId = CRYPTO_E_PARAM_HANDLE;
  }
  /* [SWS_Crypto_00059] Check if job is a null pointer */
  else if ( job == NULL_PTR )
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Get internal handle and process the job */
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 1)
    errorId = CRYPTO_E_NO_ERROR;
    retVal = Crypto_30_vHsm_ProcessCryptoJob(Crypto_30_vHsm_GetInternalObjectIds(objectId), job, FALSE); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
#else
    uint32 internalObjectId;

    /* [SWS_Crypto_00058] Check if object id is out of range */
    errorId = CRYPTO_E_PARAM_HANDLE;

    if(Crypto_30_vHsm_GetInternalObjectId(objectId, &internalObjectId) == E_OK) /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
    {
      errorId = CRYPTO_E_NO_ERROR;
      retVal = Crypto_30_vHsm_ProcessCryptoJob(internalObjectId, job, FALSE); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
    }
#endif
  }
   /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* #100 Call Det if error occurred */
    (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID, CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_SID_PROCESS_JOB, errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_CancelJob()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_CancelJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  /* Check if module is initialized */
  /* [SWS_Crypto_00123] Check initialization state of the component */
  if (Crypto_30_vHsm_ModuleInitialized == (uint8)CRYPTO_30_VHSM_UNINIT)
  {
    errorId = CRYPTO_E_UNINIT;
  }
  /* Check plausibility of input parameters */
  /* [SWS_Crypto_00124] Check if driver object is valid */
  else if (objectId >= Crypto_30_vHsm_GetSizeOfInternalObjectIds())
  {
    errorId = CRYPTO_E_PARAM_HANDLE;
  }
  /* [SWS_Crypto_00125] Check if job is a null pointer */
  else if (job == NULL_PTR)
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #10 Get internal handle and process the job */
#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 1)
    errorId = CRYPTO_E_NO_ERROR;
    retVal = Crypto_30_vHsm_ProcessCryptoJob(Crypto_30_vHsm_GetInternalObjectIds(objectId), job, TRUE); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
#else
    uint32 internalObjectId;

    /* [SWS_Crypto_00124] Check if object id is out of range */
    errorId = CRYPTO_E_PARAM_HANDLE;

    if(Crypto_30_vHsm_GetInternalObjectId(objectId, &internalObjectId) == E_OK) /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
    {
      errorId = CRYPTO_E_NO_ERROR;
      retVal = Crypto_30_vHsm_ProcessCryptoJob(internalObjectId, job, TRUE); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
    }
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* #100 Call Det if error occurred */
    (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID, CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_SID_CANCEL_JOB, errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  if (retVal != E_OK)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

#if (Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm() == 2)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_GetInternalObjectId()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_GetInternalObjectId(
  uint32 objectId,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) internalObjectId)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Find the internal driver object id if available */

  if (Crypto_30_vHsm_GetInternalObjectIds(objectId) != CRYPTO_30_VHSM_NO_INTERNALOBJECTIDS)
  {
    *internalObjectId = Crypto_30_vHsm_GetInternalObjectIds(objectId); /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
    retVal = E_OK;
  }

  /* #20 Return result */
  return retVal;
}
#endif

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_WaitForHsmRam()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_WaitForHsmRam(void) /* COV_CRYPTO_30_VHSM_WAIT_FOR_HSM */
{
  /* #10 Get the offset of the ready flag */
  volatile uint32 readyFlagOffsetTmp = Crypto_30_vHsm_Ipc_MemoryLayout.readyFlagOffset;

  Crypto_30_vHsm_Ipc_MemoryPtr = &Crypto_30_vHsm_Ipc_Memory[0U];

  /* #20 Wait until the ready flag has been set by the vHsm */
  while (Crypto_30_vHsm_CheckForHsmReady()) /* PRQA S 0303, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_REGISTER_ACCESS */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* COV_CRYPTO_30_VHSM_WAIT_FOR_HSM */
  {
    ;
  }

#if (CRYPTO_30_VHSM_IPC_INITIALIZATION == STD_ON)
  /* Check if Ipc has already been initialized before */
  if (Crypto_30_vHsm_IsIpcNotInitialized()) /* PRQA S 0303 */ /* MD_CRYPTO_30_VHSM_REGISTER_ACCESS */
  {
    /* Initialize IPC */
    VStdLib_MemClr(Crypto_30_vHsm_Ipc_Memory, CRYPTO_30_VHSM_IPC_MEMORY_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_VHSM_INIT_IPC_MEMORY */

    /* Indicate that IPC has been initialized. HSM will now be able to use the IPC. */
    Crypto_30_vHsm_IndicateInitializedIpc(); /* PRQA S 0303 */ /* MD_CRYPTO_30_VHSM_REGISTER_ACCESS */ /* SBSW_CRYPTO_30_VHSM_REGISTER_ACCESS */
  }
#endif
  while ((Crypto_30_vHsm_Ipc_GetMemoryValue32(readyFlagOffsetTmp)) != 0xDEADBEEFu) /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* COV_CRYPTO_30_VHSM_WAIT_FOR_HSM */
  {
    ;
  }
}

#define CRYPTO_30_VHSM_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* Module specific MISRA deviations:

MD_CRYPTO_30_VHSM_0306_CHECK_MEMORY_LAYOUT:
Reason:       Cast needed to evaluate if the pointer address is located in a specific memory region.
Risk:         Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention:   vHsm for specific hardware(32 - Bit platforms) (pointer size type can not differ). Valid memory access ensured by code review and test

MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO:
Reason:       Cast needed in order to have a platform independent IPC on shared memory for different architectures
Risk:         Writing or reading of invalid memory
Prevention:   Covered by code review and tests.

MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO:
Reason:       Cast needed in order to have a platform independent IPC on shared memory. Ptr needs to be transferred by their address.
Risk:         Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention:   vHsm for specific hardware(32 - Bit platforms) (pointer size type can not differ). Valid memory access ensured by code review and test

MD_CRYPTO_30_VHSM_0310_KEYELEMENT_CONTENT:
Reason:       The content of a key element which is an uint8 array has to be copied to e.g. a uint32 value.
Risk:         Wrong interpretation of the data.
Prevention:   Covered by code review and tests on hardware.

MD_CRYPTO_30_VHSM_IPC_MACRO
Reason:       Cast needed in order to have a platform independent IPC on shared memory for different architectures
Risk:         Writing or reading of invalid memory
Prevention:   Covered by code review and tests.

MD_CRYPTO_30_VHSM_3453_IPC_MACRO
Reason:       Macro used because macros are faster than functions and IPC is performance critical
Risk:         Macros don't evaluate types. Can cause invalid memory access
Prevention:   Covered by code review and tests.

MD_CRYPTO_30_VHSM_3453_JOB_MACRO
Reason:       Macro used because macros are faster than functions and job handling is performance critical
Risk:         Macros don't evaluate types. Can cause invalid memory access
Prevention:   Covered by code review and tests.

MD_CRYPTO_30_VHSM_3673_API_SPECIFIC
Reason:       Parameter cannot be set to const since it is passed as var parameter to lower layer library.
Risk:         -
Prevention:   -

MD_CRYPTO_30_VHSM_2822_DEREFERENCING_NULLPTR
Reason:       Parameter my be NULL_PTR which will then be dereferenced.
Risk:         Undefined or unspecified behaviour
Prevention:   On hardware platforms, NULL_PTR may be a valid address. Covered by code review and tests.

MD_CRYPTO_30_VHSM_2987_HANDLEDET
Reason:       Function is detected without side effects even if it clears a variable in the IPC
Risk:         -
Prevention:   -

MD_CRYPTO_30_VHSM_UNUSED_PARAMETER
Reason:       The API is designed to be the same for multiple sub components. Some implementations don't use a parameter.
Risk:         Unused parameter may be less efficient
Prevention:   Code review, tests

MD_CRYPTO_30_VHSM_1533_OBJECT_ONLY_ACCESSED_ONCE
Reason:       The static object is only accessed in one function.
Risk:         -
Prevention:   Code review

MD_CRYPTO_30_VHSM_REGISTER_ACCESS
Reason:       Register access
Risk:         Access to invalid memory
Prevention:   The user has to make sure that only the correct register address is configured to access the hardware register. The register is hardware dependant.

MD_CRYPTO_30_VHSM_TRIGGER_INTERRUPT
Reason:       Register access
Risk:         Access to invalid memory
Prevention:   The user has to make sure that only the correct register address is configured to trigger the interrupt. The register is hardware dependant.

MD_CRYPTO_30_VHSM_2985_REDUNDANT_OP_WHEN_NO_REDIRECTION
Reason:       This operation is redundant. The value of the result is always that of the left-hand operand when redirection is disabled
Risk:         Not needed operation
Prevention:   Code review, tests

MD_CRYPTO_30_VHSM_3679_JOB_POINTER_AS_VAR
Reason:       The object referenced by the pointer is not modified through it, so the object could be declared with type 'objectType const*'. However the referenced data inside the struct is modified, therefore P2VAR.
Risk:         -
Prevention:   Code review, tests

 */

/*
\CM CM_CRYPTO_30_VHSM_IPC_SERIALIZE The total size of the serialized data per job is fixed. Before serialization, a runtime check is performed if the section in the ipc is big enough to hold the serialized job.
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_CRYPTO_30_VHSM_FORWARDING_PTR
\DESCRIPTION    The caller forwards as parameter one or more pointer.
\COUNTERMEASURE \N The pointer is forwarded and assumed to be valid.

\ID SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR
\DESCRIPTION A variable located on the stack is given as parameter pointer to a function.
\COUNTERMEASURE \N The pointer is forwarded and assumed to be valid.

\ID SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR_WITH_BUFFER
\DESCRIPTION A variable located on the stack is given as parameter pointer to a function. Also a pointer to a buffer is passed which is used to read a value from the IPC.
\COUNTERMEASURE \N The pointer is forwarded and assumed to be valid. The buffer always points to the valid IPC memory area which is always available.

\ID SBSW_CRYPTO_30_VHSM_SET_VALUE_IN_IPC
\DESCRIPTION A variable located in the ipc memory is written.
\COUNTERMEASURE \N The memory area in the IPC is assumed to be valied. The offset is static and depending on the IPC protocol version

\ID SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32
\DESCRIPTION A variable is serialized to the IPC. An offset is used to determine the destination in the IPC memory
\COUNTERMEASURE \R [CM_CRYPTO_30_VHSM_IPC_SERIALIZE]

\ID SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR
\DESCRIPTION A pointer is serialized to the IPC. An offset is used to determine the destination in the IPC memory
\COUNTERMEASURE \R [CM_CRYPTO_30_VHSM_IPC_SERIALIZE]

\ID SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST
\DESCRIPTION Access of LockOfJobRequest, JobStateOfJobRequest, StateOfJobRequest, ResultOfJobRequest, CryptoJobOfJobRequest, ProcessingTypeOfJobRequest KeyMJobOfJobRequest, ObjectIdOfJobRequest, CancelOfJobRequest, using ComStackLib. The GetSizeOf-check is performed in Crypto_30_vHsm_AllocateJobRequest().
\COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib.

\ID SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST_JOB_PTR
\DESCRIPTION Access of CryptoJobOfJobRequest using ComStackLib. The GetSizeOf-check is performed in Crypto_30_vHsm_AllocateJobRequest().
\COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib. Additionally the pointers inside the job are assumed to be valid. The caller of Crypto_30_vHsm_CancelJob or Crypto_30_vHsm_ProcessJob must ensure the validity of the pointers inside the job structure.

\ID SBSW_CRYPTO_30_VHSM_CSL01_DRIVEROBJECTLOCK
\DESCRIPTION Access of DriverObjectLock using ComStackLib. The GetSizeOf-check is performed in one of the global APIs Crypto_30_vHsm_CancelJob or Crypto_30_vHsm_ProcessJob.
\COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib.

\ID SBSW_CRYPTO_30_VHSM_CSL01_CHANNELSTATE
\DESCRIPTION Access of ChannelState using ComStackLib. The GetSizeOf-check is performed in Crypto_30_vHsm_TransmitRequest().
\COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib.

\ID SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK
\DESCRIPTION Write access to a pointer.
\COUNTERMEASURE \R The pointer is checked for validity before.

\ID SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK
\DESCRIPTION The value of a pointer to a variable located on the stack is written.
\COUNTERMEASURE \N The function call is synchronous and there is no array access.

\ID SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL
\DESCRIPTION The value of a pointer to a global variable of the CSL is written.
\COUNTERMEASURE \N The function call is synchronous and there is no array access.

\ID SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_GLOBAL_BUFFER
\DESCRIPTION The value of a pointer to a variable located on the global buffer
\COUNTERMEASURE \N The function call is synchronous and there is no array access. The global buffer is always available.

\ID SBSW_CRYPTO_30_VHSM_FORWARDING_STACK_VARIABLE_PTR
\DESCRIPTION The function is called with pointers pointing to stack variables.
\COUNTERMEASURE \N The pointer is forwarded and assumed to be valid

\ID SBSW_CRYPTO_30_VHSM_FORWARDING_OF_IPC_BUFFER_AS_PTR
\DESCRIPTION A pointer to an array located in the global ipc memory is given as parameter to a function with an offset. The function known to only write a specific number of bytes to the pointer.
\COUNTERMEASURE \N The function call is synchronous and the size of the array has been previously checked and the function only serializes a known number of bytes which is specified in Crypto_30_vHsm_JobBufferSize, therefore the array in the is valid for the function call.

\ID SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_REDIRECTION_WITH_GLOBAL_BUFFERS
\DESCRIPTION The function is called with pointers to the global buffer and parameters containing the key and element id.
\COUNTERMEASURE \N The pointer to the global buffer is assumed to be valid.

\ID SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_PTR_WITH_GLOBAL_BUFFERS
\DESCRIPTION The function is called with pointers to the global buffer and the original ptr which shall be serialized.
\COUNTERMEASURE \N The pointer to the global buffer is assumed to be valid.

\ID SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE
\DESCRIPTION The function is called with a pointer to a job which has been checked, the pointer to the memory area in the IPC where the job shall be serialized and a pointer to a local variable on the stack (offset).
\COUNTERMEASURE \N The pointer to the job has been checked in Crypto_30_vHsm_ProcessJob or Crypto_30_vHsm_CancelJob or is a local variable on the stack in a synchronous call in case of a KeyM job. The buffer has a static size in the IPC memory and is always available and the offset is a local variable on the stack.

\ID SBSW_CRYPTO_30_VHSM_MEMORY_VALID_CHECK
\DESCRIPTION    The caller forwards as parameter one pointers. The data can be NULL_PTR.
\COUNTERMEASURE \N The pointer is forwarded and is allowed to be NULL_PTR. Depending on the length, the function will return an error.

\ID SBSW_CRYPTO_30_VHSM_COPY_TO_DESTINATION_FROM_GLOBAL_BUFFER
\DESCRIPTION    The original pointers in the job are used as destination for the data in the global buffer which is always available because the caller always passes a valid job.
\COUNTERMEASURE \N The pointers in the job are assumed to be valid. The pointer to the global buffer is assumed to be valid or have a size of 0. The destination pointer and length have been checked against NULL_PTR.
                   The length is checked, that it is not bigger than the original provided buffer.
                   The vHsm Firmware can therefore not trigger any memory corruption via the driver when providing a bigger output buffer size than the size of the buffer in the job pointer.

\ID SBSW_CRYPTO_30_VHSM_COPY_TO_GLOBAL_BUFFER_FROM_SOURCE
\DESCRIPTION    The original pointers in the job are used as source for the data in the global buffer which is always available because the caller always passes a valid job.
\COUNTERMEASURE \N The pointers in the job are assumed to be valid. The pointer to the global buffer is assumed to be valid or have a size of 0. The source pointer has been checked against NULL_PTR.
                   The length is checked, that it is not bigger than the original provided buffer.

\ID SBSW_CRYPTO_30_VHSM_BUFFER_REPLACMENET_FLAG_ARRAY
\DESCRIPTION An array iss accessed with the internalObjectId as index.
\COUNTERMEASURE \N Crypto_30_vHsm_ProcessJob or in case of KeyM functions the generator ensures that the internalObjectId is a valid index to access the array.

\ID SBSW_CRYPTO_30_VHSM_REGISTER_ACCESS
\DESCRIPTION An address is accessed as uint32 to access a hardware register
\COUNTERMEASURE \S The address, mask and value is configured by the user and is platform dependant. The user must make sure to only provide a valid address. [SMI-427853]

\ID SBSW_CRYPTO_30_VHSM_TRIGGER_INTERRUPT
\DESCRIPTION An address is accessed as uint32 to trigger the interrupt
\COUNTERMEASURE \S The address, mask and value is configured by the user and is platform dependant. The user must make sure to only provide a valid address. [SMI-427853]

\ID SBSW_CRYPTO_30_VHSM_INIT_IPC_MEMORY
\DESCRIPTION The function is called with the ipc memory which is always available and a known size.
\COUNTERMEASURE \N The array is always available and the size is known.

SBSW_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN

\ID COV_CRYPTO_30_VHSM_LOCAL_DEFINE
\ACCEPT TX
\ACCEPT XF
\REASON CRYPTO_30_VHSM_LOCAL is always defined externally.

\ID COV_CRYPTO_30_VHSM_CSM_DEFINES
\ACCEPT XF
\ACCEPT TX
\REASON This defines could be defined in other crypto drivers as well. In order to increase flexibility, defines are defined in crypto driver if not provided yet.

\ID COV_CRYPTO_30_VHSM_MISRA_ADDITIONAL_STATEMENT
\ACCEPT X
\REASON This else/default statements are required by misra but cannot be reached in code. The statement is captured by upper Api.

\ID COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS
\ACCEPT TX
\REASON The Crypto needs custom key elements, which could be defined in other modules as well.

\ID COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE
\ACCEPT TX
\REASON The Crypto needs custom key elements, which could be defined in other modules as well.

\ID COV_CRYPTO_30_VHSM_KEY_ELEMENTS_RIGHTS
\ACCEPT TX
\REASON The Crypto provides key elements rights which can be defined in upper layer.

\ID COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM
\ACCEPT TX
\REASON The Crypto needs custom algorithm and algorithm mode defines, which could be defined in other modules as well.

\ID COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM
\ACCEPT TX
\REASON The Crypto needs custom key algorithm, which could be defined in other modules as well.

\ID COV_CRYPTO_30_VHSM_CUSTOM_KDF
\ACCEPT TX
\REASON The Crypto needs custom key algorithm, which could be defined in other modules as well.

\ID COV_CRYPTO_30_VHSM_DOUBLE_CHECK
\ACCEPT TX
\REASON To avoid unnecessary entering of exclusive areas, rare occuring events are checked twice: Outside of an exclusive area before entering it
        and again inside the area to make sure that it is not already handled meanwhile.

\ID COV_CRYPTO_30_VHSM_COMMENT
\ACCEPT TX
\ACCEPT XF
\REASON -

\ID COV_CRYPTO_30_VHSM_DATABUFFER
\ACCEPT TX
\REASON A Configuration without a configured data buffer for inputPtr, secondaryInputPtr or outputPtr is not really usabale.

\ID COV_CRYPTO_30_VHSM_NO_FLASH_SYNC_SUPPORT_IN_VHSM
\ACCEPT XX
\ACCEPT XF tf tf tf xf
\ACCEPT XF
\REASON Not all platforms where the vHsm Firmware is executed need flash synchronisation. Therefore the HAL does not provide the functionality.

\ID COV_CRYPTO_30_VHSM_WAIT_FOR_HSM
\ACCEPT XF
\ACCEPT X
\ACCEPT XX
\REASON The application core does not need to wait on all platforms until the vHsm Firmware is initialized.

\ID COV_CRYPTO_30_VHSM_IPC_BUFFER_SIZE_CHECK
\REASON The buffer size is defined in a lookup table and can not be altered from outside. Due to defensive coding the check is done nevertheless.

\ID COV_CRYPTO_30_VHSM_ROBUST_POINTER_CHECK
\ACCEPT TF tf tx
\ACCEPT XF xf xx
\REASON There are more checks for the pointers as needed to improve the robustness on different platforms.

\ID COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE
\ACCEPT TX xf tx tx tx
\ACCEPT TX xf tx
\ACCEPT TX
\REASON Examples for different compilers are given in the MemMap file. Project is only compiled with one compiler in all configs.

\ID COV_CRYPTO_30_VHSM_ASR_COMPATIBILITY
\ACCEPT XF
\ACCEPT TX
\REASON The Crypto_JobType differs between the different ASR version to support ASR 4.3.0 the defines ca be overwritten. Standard is ASR 4.3.1.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm.c
 *********************************************************************************************************************/

