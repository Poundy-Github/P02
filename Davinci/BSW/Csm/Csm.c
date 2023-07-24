/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Csm.c
 *        \brief  MICROSAR Crypto Service Manager (CSM)
 *
 *      \details  Implementation of the MICROSAR Crypto Service Manager (CSM)
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

#define CSM_SOURCE
/* PRQA S 6060 EOF */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm.h"
#include "Csm_Cbk.h"
#include "CryIf.h"
#include "SchM_Csm.h"

#if (CSM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

 /* Check the version of CSM header file */
#if ((CSM_SW_MAJOR_VERSION != (5u)) \
    || (CSM_SW_MINOR_VERSION != (0u)) \
    || (CSM_SW_PATCH_VERSION != (1u)))
# error "Vendor specific version numbers of Csm.c and Csm.h are inconsistent"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((CSM_AR_RELEASE_MAJOR_VERSION != (4u)) \
    || (CSM_AR_RELEASE_MINOR_VERSION != (4u)) \
    || (CSM_AR_RELEASE_REVISION_VERSION != (0u)))
# error "AUTOSAR Specification Version numbers of Csm.c and Csm.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Service idle state */
#define CSM_SERVICE_IDLE                                              (0u)
/*! Service active state */
#define CSM_SERVICE_ACTIVE                                            (1u)

/*! Callback is idle and must not be notified to RTE. */
#define CSM_CALLBACK_IDLE                                             (0xFEu)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define Csm_GetApiIdByService(service)                                Csm_ServiceToApiIdTable[(service)] /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (CSM_LOCAL) /* COV_CSM_LOCAL_DEFINE */
# define CSM_LOCAL                                                    static
#endif

#if !defined (CSM_LOCAL_INLINE) /* COV_CSM_LOCAL_DEFINE */
# define CSM_LOCAL_INLINE                                             LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define CSM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CSM_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
CSM_LOCAL VAR(uint8, CSM_VAR_ZERO_INIT) Csm_IsInitialized = CSM_UNINIT;
#endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */

#define CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CSM_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CSM_JOB == STD_ON)
# if (CSM_DEV_ERROR_REPORT == STD_ON)
/*! Service to API lookup table */
CSM_LOCAL CONST(uint8, CSM_CONST) Csm_ServiceToApiIdTable[] = /* PRQA S 3218 */ /* MD_CSM_ACCESSED_ONLY_ONCE */
{
  /** CRYPTO_HASH                         **/  CSM_HASH_ID,
  /** CRYPTO_MACGENERATE                  **/  CSM_MACGENERATE_ID,
  /** CRYPTO_MACVERIFY                    **/  CSM_MACVERIFY_ID,
  /** CRYPTO_ENCRYPT                      **/  CSM_ENCRYPT_ID,
  /** CRYPTO_DECRYPT                      **/  CSM_DECRYPT_ID,
  /** CRYPTO_AEADENCRYPT                  **/  CSM_AEADENCRYPT_ID,
  /** CRYPTO_AEADDECRYPT                  **/  CSM_AEADDECRYPT_ID,
  /** CRYPTO_SIGNATUREGENERATE            **/  CSM_SIGNATUREGENERATE_ID,
  /** CRYPTO_SIGNATUREVERIFY              **/  CSM_SIGNATUREVERIFY_ID,
  /** CRYPTO_SECCOUNTERINCREMENT          **/  CSM_SECURECOUNTERINCREMENT_ID,
  /** CRYPTO_SECCOUNTERREAD               **/  CSM_SECURECOUNTERREAD_ID,
  /** CRYPTO_RANDOMGENERATE               **/  CSM_RANDOMGENERATE_ID,
  /** CRYPTO_RANDOMSEED                   **/  CSM_JOBRANDOMSEED_ID,
  /** CRYPTO_KEYGENERATE                  **/  CSM_JOBKEYGENERATE_ID,
  /** CRYPTO_KEYDERIVE                    **/  CSM_JOBKEYDERIVE_ID,
  /** CRYPTO_KEYEXCHANGECALCPUBVAL        **/  CSM_JOBKEYEXCHANGECALCPUBVAL_ID,
  /** CRYPTO_KEYEXCHANGECALCSECRET        **/  CSM_JOBKEYEXCHANGECALCSECRET_ID,
  /** CRYPTO_CERTIFICATEPARSE             **/  CSM_CERTIFICATEPARSE_ID,
  /** CRYPTO_CERTIFICATEVERIFY            **/  CSM_CERTIFICATEVERIFY_ID,
  /** CRYPTO_KEYSETVALID                  **/  CSM_JOBKEYSETVALID_ID
};
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */
#endif /* (CSM_JOB == STD_ON) */

#define CSM_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CSM_JOB == STD_ON)
/**********************************************************************************************************************
 *  Csm_ProcessJob()
 *********************************************************************************************************************/
/*! \brief         Process the received job
 *  \details       This function unifies all external calls to call CryIf_ProcessJob.
 *  \param[in]     queueIdx                Holds the identifier of the queue.
 *  \param[in,out] job                     Pointer to the configuration of the job. Contains structures with user and
 *                                         primitive relevant information.
 *  \param[in]     primitiveService        Holds the primitive which shall be processed.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \return        CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
 *  \return        CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
 *  \return        CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           Param queueIdx needs to be a valid index.
 *                 Job must point to a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CSM_LOCAL FUNC(Std_ReturnType, CSM_CODE) Csm_ProcessJob(Csm_QueueInfoIterType queueIdx,
                                                        P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job,
                                                        Crypto_ServiceInfoType primitiveService);

# if (CSM_ASYNC_PROCESSING == STD_ON)
/**********************************************************************************************************************
 *  Csm_JobSort()
 *********************************************************************************************************************/
/*! \brief         Sort job
 *  \details       This function is sorting given jobs regarding jobPriority.
 *  \param[in]     queueIdx                Holds the identifier of the queue.
 *  \pre           Param queueIdx needs to be a valid index.
 *  \note          Should only be called with locked interrupts
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CSM_LOCAL FUNC(void, CSM_CODE) Csm_JobSort(Csm_QueueInfoIterType queueIdx);

/**********************************************************************************************************************
 *  Csm_TriggerAsynchJobProcessing()
 *********************************************************************************************************************/
/*! \brief        Triggers the Processing of asynchronous jobs
 *  \details      This function checks for the given queue if an asynchronous job is available. If so, it triggers the
 *                CryIf to process this asynchronous job.
 *  \param[in]    queueIdx                Holds the identifier of the queue.
 *  \pre          Param queueIdx needs to be a valid index.
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CSM_LOCAL FUNC(void, CSM_CODE) Csm_TriggerAsynchJobProcessing(Csm_QueueInfoIterType queueIdx);
# endif /* (CSM_ASYNC_PROCESSING == STD_ON) */

/**********************************************************************************************************************
 *  Csm_HandleJobProcessing()
 *********************************************************************************************************************/
/*! \brief         Triggers the CryIf to process the given job.
 *  \details       This function triggers the CryIf to process the corresponding job. Furthermore, pre- and postjob callouts are called from this function if enabled.
 *  \param[in]     channelId           Holds the identifier of the queue.
 *  \param[in,out] job                 Pointer to the corresponding job
 *  \pre           Param channelId needs to be a valid CryIf channel.
 *                 Param Job needs to be a valid pointer to a job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CSM_LOCAL FUNC(Std_ReturnType, CSM_CODE) Csm_HandleJobProcessing(Csm_ChannelIdOfQueueInfoType channelId, P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  Csm_AppendRedirectionToJob()
 *********************************************************************************************************************/
/*! \brief         Appends redirection info to job object.
 *  \details       If the job is configured to use an in-out redirection, it is appended to the job object in this function.
 *  \param[in,out] job     Pointer to the corresponding job.
 *  \pre           Param job needs to point to a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CSM_LOCAL_INLINE FUNC(void, CSM_CODE) Csm_AppendRedirectionToJob(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job);
#endif /* (CSM_JOB == STD_ON) */

#if (CSM_CALLOUT == STD_ON)
/**********************************************************************************************************************
 *  Csm_CallPreJobCallout()
 *********************************************************************************************************************/
/*! \brief         Triggers the calling of the configured prejob callout.
 *  \details       This function checks for the given job if an prejob callout has to be called. If so, it triggers the
 *                 call.
 *  \param[in,out] job     Pointer to the corresponding job.
 *  \pre           Param job needs to point to a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CSM_LOCAL FUNC(Std_ReturnType, CSM_CODE) Csm_CallPreJobCallout(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  Csm_CallPostJobCallout()
 *********************************************************************************************************************/
/*! \brief         Triggers the calling of the configured postjob callout.
 *  \details       This function checks for the given job if an postjob callout has to be called. If so, it triggers the
 *                 call.
 *  \param[in,out] job                       Pointer to the job.
 *  \param[in,out] retValFromProcessing      Pointer to the processing result of the corresponding job. It can be overwritten by the postjob callout.
 *  \pre           Param job needs to point to a valid job object.
 *  \pre           Param retValFromProcessing needs to point to a valid location.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CSM_LOCAL FUNC(void, CSM_CODE) Csm_CallPostJobCallout(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) retValFromProcessing);
#endif /* (CSM_CALLOUT == STD_ON) */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (CSM_CALLOUT == STD_ON)
/**********************************************************************************************************************
 *  Csm_CallPostJobCallout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CSM_LOCAL FUNC(void, CSM_CODE) Csm_CallPostJobCallout(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) retValFromProcessing)
{
  Csm_CalloutInfoIdxOfJobTableType calloutInfoId;

  calloutInfoId = Csm_GetCalloutInfoIdxOfJobTable(job->jobInfo->jobId);

  /* #10 Check if postjob callout is configured for the given job. */
  if (calloutInfoId < Csm_GetSizeOfCalloutInfo())
  {
    /* #20 Call postjob callout and reset the callout state to IDLE. */
    (void)Csm_GetPostJobCalloutFuncOfCallout(Csm_GetCalloutIdxOfCalloutInfo(calloutInfoId))( /* SBSW_CSM_FUNCTION_POINTER */
      job,
      CSM_CALLOUT_STATE_POST_INITIAL,
      retValFromProcessing);

    Csm_SetCalloutStateOfCalloutState(calloutInfoId, CSM_CALLOUT_STATE_IDLE); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
  }
}

/**********************************************************************************************************************
 *  Csm_CallPreJobCallout()
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
CSM_LOCAL FUNC(Std_ReturnType, CSM_CODE) Csm_CallPreJobCallout(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job)
{
  Csm_CalloutInfoIdxOfJobTableType calloutInfoId;
  Std_ReturnType retVal = E_OK;

  /* Retrieve reference to callout for given job */
  calloutInfoId = Csm_GetCalloutInfoIdxOfJobTable(job->jobInfo->jobId);

  /* Check if prejob callout is configured for the given job. */
  if (calloutInfoId < Csm_GetSizeOfCalloutInfo())
  {
# if (CSM_ASYNC_PROCESSING == STD_ON)
    uint8 calloutState = Csm_GetCalloutStateOfCalloutState(calloutInfoId);

    if( job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_ASYNC)
    {
      /* If no callout has been called before or callout did not finish yet, call prejob. */
      if ((calloutState == CSM_CALLOUT_STATE_IDLE) || (calloutState == CSM_CALLOUT_STATE_PRE_PENDING))
      {
        /* Call prejob callout */
        retVal = Csm_GetPreJobCalloutFuncOfCallout(Csm_GetCalloutIdxOfCalloutInfo(calloutInfoId))( /* SBSW_CSM_FUNCTION_POINTER */
          job,
          (calloutState == CSM_CALLOUT_STATE_IDLE) ? (CSM_CALLOUT_STATE_PRE_INITIAL) : (CSM_CALLOUT_STATE_PRE_PENDING));

        /* Set state according to return value of callout. */
        switch (retVal)
        {
          case E_OK:
          {
            /* prejob callout has finished, Processing can start */
            Csm_SetCalloutStateOfCalloutState(calloutInfoId, CSM_CALLOUT_STATE_PROCESSING); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
            break;
          }

          case CSM_E_PENDING:
          {
            /* prejob callout has not yet finished, this is only possible in asynchronous job configurations */
            Csm_SetCalloutStateOfCalloutState(calloutInfoId, CSM_CALLOUT_STATE_PRE_PENDING); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
            break;
          }

          default:
          {
            Csm_SetCalloutStateOfCalloutState(calloutInfoId, CSM_CALLOUT_STATE_PROCESSING_ABORTED_BY_CALLOUT); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
            /* Change retVal to E_OK to remove job from queue since processing shall never be started */
            retVal = E_OK;
            break;
          }
        }
      }
    }
    else
# endif /* (CSM_ASYNC_PROCESSING == STD_ON) */
    {
      /* Call prejob.  */
      retVal = Csm_GetPreJobCalloutFuncOfCallout(Csm_GetCalloutIdxOfCalloutInfo(calloutInfoId))(job, CSM_CALLOUT_STATE_PRE_INITIAL); /* SBSW_CSM_FUNCTION_POINTER */

      /* Set state according to return value of callout. */
      if(retVal == E_OK)
      {
        /*  If return value is equal to E_OK, the job shall be executed as without callout. */
        Csm_SetCalloutStateOfCalloutState(calloutInfoId, CSM_CALLOUT_STATE_PROCESSING); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
      }
      else
      {
        /* If return value is different to E_OK, processing of the job shall be supressed. */
        Csm_SetCalloutStateOfCalloutState(calloutInfoId, CSM_CALLOUT_STATE_POST_INITIAL); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
      }
    }
  }
  return retVal;
}
#endif /* (CSM_CALLOUT == STD_ON) */

#if (CSM_JOB == STD_ON)
/**********************************************************************************************************************
 *  Csm_AppendRedirectionToJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CSM_LOCAL_INLINE FUNC(void, CSM_CODE) Csm_AppendRedirectionToJob(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job)
{

# if (CSM_INOUTREDIRECTION == STD_ON)
  uint32 jobId = job->jobId;

  /* #10 If job in- or output shall be redirected, copy corresponding redirection sources and destinations to the job object. */
  if(Csm_IsInOutRedirectionUsedOfJobTable(jobId))
  {
    uint8 indexOfInOutRedirectionTable = Csm_GetInOutRedirectionConfigIdxOfJobTable(jobId);
    Csm_RedirectionConfigValueOfInOutJobRedirectionTableType redirectionConfigValue =  Csm_GetRedirectionConfigValueOfInOutJobRedirectionTable(indexOfInOutRedirectionTable);

    job->jobRedirectionInfoRef = &(Csm_GetInOutRedirection(Csm_GetInOutRedirectionIdxOfJobTable(jobId))); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobRedirectionInfoRef->redirectionConfig = redirectionConfigValue; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT)
    {
      job->jobRedirectionInfoRef->inputKeyElementId = Csm_GetInputKeyElementIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobRedirectionInfoRef->inputKeyId = Csm_GetCryIfKeyIdOfKey(Csm_GetInputKeyIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable)); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT)
    {
      job->jobRedirectionInfoRef->secondaryInputKeyElementId = Csm_GetSecondaryInputKeyElementIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobRedirectionInfoRef->secondaryInputKeyId = Csm_GetCryIfKeyIdOfKey(Csm_GetSecondaryInputKeyIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable)); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT)
    {
      job->jobRedirectionInfoRef->tertiaryInputKeyElementId = Csm_GetTertiaryInputKeyElementIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobRedirectionInfoRef->tertiaryInputKeyId = Csm_GetCryIfKeyIdOfKey(Csm_GetTertiaryInputKeyIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable)); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT)
    {
      job->jobRedirectionInfoRef->outputKeyElementId = Csm_GetOutputKeyElementIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobRedirectionInfoRef->outputKeyId = Csm_GetCryIfKeyIdOfKey(Csm_GetOutputKeyIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable)); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    }

    if((redirectionConfigValue & ((uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT)) == (uint8)CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT)
    {
      job->jobRedirectionInfoRef->secondaryOutputKeyElementId = Csm_GetSecondaryOutputKeyElementIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobRedirectionInfoRef->secondaryOutputKeyId = Csm_GetCryIfKeyIdOfKey(Csm_GetSecondaryOutputKeyIdOfInOutJobRedirectionTable(indexOfInOutRedirectionTable)); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    }
  }
  else
# endif /* (CSM_INOUTREDIRECTION == STD_ON) */
  /* #20 Else set redirection to dummy value. */
  {
    job->jobRedirectionInfoRef = (P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CSM_VAR_NOINIT)) (NULL_PTR); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
  }
}

/**********************************************************************************************************************
 *  Csm_HandleJobProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CSM_LOCAL FUNC(Std_ReturnType, CSM_CODE) Csm_HandleJobProcessing(Csm_ChannelIdOfQueueInfoType channelId, P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job)
{
  Std_ReturnType retVal;

# if (CSM_CALLOUT == STD_ON)
  Csm_CalloutInfoIdxOfJobTableType calloutInfoId;

  /* Retrieve reference to callout for given job */
  calloutInfoId = Csm_GetCalloutInfoIdxOfJobTable(job->jobInfo->jobId);

  /* #10 Call preJobCallout */
  retVal = Csm_CallPreJobCallout(job); /* SBSW_CSM_PASS_JOB_POINTER_API_REQUIREMENT */

  if ((calloutInfoId >= Csm_GetSizeOfCalloutInfo()) || (Csm_GetCalloutStateOfCalloutState(calloutInfoId) == CSM_CALLOUT_STATE_PROCESSING))
# endif /* (CSM_CALLOUT == STD_ON) */
  {
    /* #20 Call CryIf to process given job */
    retVal = CryIf_ProcessJob(channelId, job); /* SBSW_CSM_PASS_JOB_POINTER_API_REQUIREMENT */
# if (CSM_CALLOUT == STD_ON)
    if (calloutInfoId < Csm_GetSizeOfCalloutInfo())
    {
      /* Job has finished, either successful (E_OK) or not */
#  if (CSM_ASYNC_PROCESSING == STD_ON)
      if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_SYNC)
#  endif /* (CSM_ASYNC_PROCESSING == STD_ON) */
      {
        /* We need to call the post callout routine */
        Csm_SetCalloutStateOfCalloutState(calloutInfoId, CSM_CALLOUT_STATE_POST_INITIAL); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
        Csm_CallPostJobCallout(job, &retVal); /* SBSW_CSM_PASS_JOB_POINTER_API_REQUIREMENT */
      }
    }
# endif /* # (CSM_CALLOUT == STD_ON) */
  }
  return retVal;
}
/**********************************************************************************************************************
 *  Csm_ProcessJob()
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
 *
 */
CSM_LOCAL FUNC(Std_ReturnType, CSM_CODE) Csm_ProcessJob(Csm_QueueInfoIterType queueIdx,
                                                        P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job,
                                                        Crypto_ServiceInfoType primitiveService)
{
  Std_ReturnType retVal = E_NOT_OK;
  boolean enqueuingNecessary = FALSE;
  Csm_ChannelIdOfQueueInfoType channelId = Csm_GetChannelIdOfQueueInfo(queueIdx);

  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #02 Check if the correct API was called for the corresponding service */
  if (job->jobPrimitiveInfo->primitiveInfo->service != primitiveService)
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  } else
# else
  CSM_DUMMY_STATEMENT(primitiveService); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    Crypto_JobStateType combinedJobState = job->jobState;

# if (CSM_ENFORCE_430_COMPATIBILITY == STD_ON)
    combinedJobState |= job->state;
# endif /* (CSM_ENFORCE_430_COMPATIBILITY == STD_ON) */

    /* #05 Append job redirection to job object */
    Csm_AppendRedirectionToJob(job); /* SBSW_CSM_PASS_JOB_POINTER_API_REQUIREMENT */

# if (CSM_ASYNC_PROCESSING == STD_OFF)
    CSM_DUMMY_STATEMENT(enqueuingNecessary); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    CSM_DUMMY_STATEMENT(combinedJobState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

    retVal = Csm_HandleJobProcessing(channelId, job); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
# else
    /* #10 When the job is active the Csm_HandleJobProcessing is called */
    if ((combinedJobState & CRYPTO_JOBSTATE_ACTIVE) == CRYPTO_JOBSTATE_ACTIVE)
    {
      /* Call CryIf_ProcessJob() */
      retVal = Csm_HandleJobProcessing(channelId, job); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
    }
    else
    {
      SchM_Enter_Csm_CSM_EXCLUSIVE_AREA_0();
      /* #20 Determine if queue is empty and call Csm_HandleJobProcessing if so */
      if (Csm_GetQueueIdxOfQueueState(queueIdx) == Csm_GetQueueStartIdxOfQueueInfo(queueIdx))
      {
        SchM_Exit_Csm_CSM_EXCLUSIVE_AREA_0();
        retVal = Csm_HandleJobProcessing(channelId, job); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
        SchM_Enter_Csm_CSM_EXCLUSIVE_AREA_0();

        /* #25 When return value is either BUSY or QUEUE_FULL enqueuing is mandatory */
        if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_ASYNC)
        {
          /* If crypto is busy or crypto queue full, further processing is required. */
          enqueuingNecessary = (retVal == CRYPTO_E_BUSY) || (retVal == CRYPTO_E_QUEUE_FULL);
        }
      }
      /* Queue is not empty */
      /* #30 Synchronous job: the job priority is compared with the highest priority in the queue */
      else if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_SYNC)
      {
        /* #31 Sort queue if jobs where enqueued since last Csm_MainFunction call */
        if (Csm_IsSortNeededOfQueueState(queueIdx))
        {
          /* Sort jobs by priority */
          Csm_JobSort(queueIdx);
          Csm_SetSortNeededOfQueueState(queueIdx, FALSE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_JOBID */
        }
        /* #32 Call Csm_HandleJobProcessing function if job priority is higher than the highest priority in the queue,
               otherwise return busy */

        if ((job->jobInfo->jobPriority > (Csm_GetQueue((Csm_QueueIdxOfQueueStateType)(Csm_GetQueueIdxOfQueueState(queueIdx) - 1u))->jobInfo->jobPriority)))
        {
          Csm_SetPauseProcessingOfQueueState(queueIdx, TRUE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_JOBID */
          SchM_Exit_Csm_CSM_EXCLUSIVE_AREA_0();
          retVal = Csm_HandleJobProcessing(channelId, job); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
          SchM_Enter_Csm_CSM_EXCLUSIVE_AREA_0();
          Csm_SetPauseProcessingOfQueueState(queueIdx, FALSE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_JOBID */
        }
        else
        {
          retVal = CRYPTO_E_BUSY;
        }
      }
      /* #40 Asynchronous job must be queued */
      else
      {
        enqueuingNecessary = TRUE;
      }

      /* #50 Enqueuing necessary: Enqueue job if queue is not full, otherwise return that queue is full */
      if (enqueuingNecessary == TRUE)
      {
        if (Csm_GetQueueIdxOfQueueState(queueIdx) < (Csm_GetQueueEndIdxOfQueueInfo(queueIdx) - Csm_GetReservedIndexesOfQueueState(queueIdx)))
        {
          /* Job needs to be enqueued */
          Csm_SetQueue(Csm_GetQueueIdxOfQueueState(queueIdx), job); /* SBSW_CSM_WRITE_TO_QUEUE_BY_LOCALIDX */
          Csm_SetSortNeededOfQueueState(queueIdx, TRUE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_JOBID */
          Csm_GetQueueIdxOfQueueState(queueIdx)++; /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_JOBID */
          retVal = E_OK;
        }
        else
        {
          retVal = CRYPTO_E_QUEUE_FULL;
        }
      }
      SchM_Exit_Csm_CSM_EXCLUSIVE_AREA_0();
    }
# endif /* (CSM_ASYNC_PROCESSING == STD_OFF) */
  }

# if (CSM_DEV_ERROR_REPORT == STD_ON)
    if (errorId != CSM_E_NO_ERROR)
    {
      (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(Csm_GetApiIdByService(primitiveService)), errorId);
    }
# else
    CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */
  return retVal;
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */

# if (CSM_ASYNC_PROCESSING == STD_ON)
/**********************************************************************************************************************
 *  Csm_JobSort()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CSM_LOCAL FUNC(void, CSM_CODE) Csm_JobSort(Csm_QueueInfoIterType queueIdx)
{
  P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) tempJob;
  Csm_QueueIterType startIdx = Csm_GetQueueStartIdxOfQueueInfo(queueIdx);
  Csm_QueueIterType i, j;

  for (i = (Csm_QueueIterType)(startIdx + 1u); i < Csm_GetQueueIdxOfQueueState(queueIdx); i++)
  {
    tempJob = Csm_GetQueue(i); /* PRQA S 2841 */ /* MD_CSM_QUEUE_BY_QUEUEIDX */
    for (j = i; j > startIdx; j--)
    {
      if (Csm_GetQueue(j - 1u)->jobInfo->jobPriority > (tempJob->jobInfo->jobPriority))
      {
        Csm_SetQueue(j, Csm_GetQueue(j - 1u));  /* PRQA S 2841 */ /* MD_CSM_QUEUE_BY_QUEUEIDX */ /* SBSW_CSM_WRITE_TO_QUEUE_BY_LOCALIDX */
      }
      else
      {
        break;
      }
    }
    Csm_SetQueue(j, tempJob); /* SBSW_CSM_WRITE_TO_QUEUE_BY_LOCALIDX */
  }

}

/**********************************************************************************************************************
 *  Csm_TriggerAsynchJobProcessing()
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
CSM_LOCAL FUNC(void, CSM_CODE) Csm_TriggerAsynchJobProcessing(Csm_QueueInfoIterType queueIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = NULL_PTR;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_Csm_CSM_EXCLUSIVE_AREA_0();
  /* #10 Check if queue has entries */
  /* Csm_QueueState and Csm_QueueInfo are of the same size. */
  if (Csm_GetQueueIdxOfQueueState(queueIdx) != Csm_GetQueueStartIdxOfQueueInfo(queueIdx))
  {
    /* #20 Sort jobs if needed */
    if (Csm_IsSortNeededOfQueueState(queueIdx))
    {
      /* Sort jobs by priority */
      Csm_JobSort(queueIdx);
      Csm_SetSortNeededOfQueueState(queueIdx, FALSE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
    }
    /* #30 Process job if possible (not paused because of active synchronous request): */
    if (!Csm_IsPauseProcessingOfQueueState(queueIdx))
    {
      /* #31 Remove job from queue temporarily (reserve a slot) and pass it to underlying crypto. */
      Csm_GetQueueIdxOfQueueState(queueIdx)--; /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
      Csm_GetReservedIndexesOfQueueState(queueIdx)++; /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
      job = Csm_GetQueue(Csm_GetQueueIdxOfQueueState(queueIdx));

      SchM_Exit_Csm_CSM_EXCLUSIVE_AREA_0();
      retVal = Csm_HandleJobProcessing(Csm_GetChannelIdOfQueueInfo(queueIdx), job); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
      SchM_Enter_Csm_CSM_EXCLUSIVE_AREA_0();

      /* #32 If job cannot be processed because of busy driver of full queue, job needs to be enqueued again. */
      if ((retVal == CRYPTO_E_BUSY) || (retVal == CRYPTO_E_QUEUE_FULL)) {
        Csm_SetQueue(Csm_GetQueueIdxOfQueueState(queueIdx), job); /* SBSW_CSM_WRITE_TO_QUEUE_BY_LOCALIDX */
        Csm_SetSortNeededOfQueueState(queueIdx, TRUE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
        Csm_GetQueueIdxOfQueueState(queueIdx)++; /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
        job = NULL_PTR;
      }
      Csm_GetReservedIndexesOfQueueState(queueIdx)--; /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
    }
  }
  SchM_Exit_Csm_CSM_EXCLUSIVE_AREA_0();
    /* #40 Call CallbackNotification if CryIf returns an error */
  if ((retVal != E_OK) && (job != NULL_PTR))
  {
    Csm_CallbackNotification(job, retVal); /* SBSW_CSM_PASS_JOB_POINTER_LOCAL */
  }
}

# endif /* (CSM_ASYNC_PROCESSING == STD_ON) */
#endif /* (CSM_JOB == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CSM_CODE) Csm_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if (CSM_DEV_ERROR_DETECT == STD_ON)
  Csm_IsInitialized = CSM_UNINIT;
#endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
} /* Csm_InitMemory() */

/**********************************************************************************************************************
 *  Csm_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, CSM_CODE) Csm_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state */
  if (Csm_IsInitialized == (uint8)CSM_INITIALIZED)
  {
    errorId = CSM_E_ALREADY_INITIALIZED;
  }
  else
#endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
#if (CSM_JOB == STD_ON)
    uint32_least index;
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Initialize job input/output buffer */
    for (index = 0u; index < Csm_GetSizeOfJob(); index++)
    {
      Csm_GetJob(index).jobState = CRYPTO_JOBSTATE_IDLE; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.inputPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.inputLength = 0u; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.secondaryInputPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.secondaryInputLength = 0u; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.tertiaryInputPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.tertiaryInputLength = 0u; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.outputPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.outputLengthPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.secondaryOutputPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.secondaryOutputLengthPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.verifyPtr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.output64Ptr = NULL_PTR; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInputOutput.mode = 0u; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobPrimitiveInfo = Csm_GetAddrJobPrimitiveInfo(Csm_GetJobPrimitiveInfoIdxOfJobTable(index)); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobInfo = Csm_GetAddrJobInfo(Csm_GetJobInfoIdxOfJobTable(index)); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).cryptoKeyId = 0u; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).jobId = Csm_GetJob(index).jobInfo->jobId; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

# if (CSM_ENFORCE_430_COMPATIBILITY == STD_ON)
      Csm_GetJob(index).PrimitiveInputOutput = Csm_GetJob(index).jobPrimitiveInputOutput; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      Csm_GetJob(index).state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
# endif
    }

    /* #30 Init queues */
    for (index = 0u; index < Csm_GetSizeOfQueueInfo(); index++)
    {
      Csm_SetQueueIdxOfQueueState(index, Csm_GetQueueStartIdxOfQueueInfo(index)); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
      Csm_SetReservedIndexesOfQueueState(index, 0u); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
      Csm_SetSortNeededOfQueueState(index, FALSE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
      Csm_SetPauseProcessingOfQueueState(index, FALSE); /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE */
    }

# if (CSM_CALLOUT == STD_ON)
    /* Initialize Callout State */
    for (index = 0u; index < Csm_GetSizeOfCalloutState(); index++)
    {
      Csm_SetCalloutStateOfCalloutState(index, CSM_CALLOUT_STATE_IDLE); /* SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE */
    }
# endif /* (CSM_CALLOUT == STD_ON) */

# if (CSM_RTECALLBACK == STD_ON)
    Csm_SetRteCallbackOccured(FALSE); /* SBSW_CSM_CSL_VAR_ACCESS */
    for (index = 0u; index < Csm_GetSizeOfRteCallback(); index++)
    {
      Csm_SetRteResult(index, CSM_CALLBACK_IDLE); /* SBSW_CSM_WRITE_TO_RTERESULT_BY_SIZE */
    }
# endif /* (CSM_RTECALLBACK == STD_ON) */

#endif /* (CSM_JOB == STD_ON) */

#if (CSM_DEV_ERROR_DETECT == STD_ON)
    /* #40 Set CSM initialization state to initialized */
    Csm_IsInitialized = CSM_INITIALIZED;
#endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */

  }
  /* ----- Development Error Report --------------------------------------- */
#if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError(CSM_MODULE_ID, CSM_INSTANCE_ID, CSM_INIT_ID, errorId);
  }
#else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */
} /* Csm_Init() */

#if (CSM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Csm_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CSM_CODE) Csm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CSM_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  if (versioninfo == NULL_PTR)
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  else
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (uint16)CSM_VENDOR_ID; /* SBSW_CSM_GETVERSIONINFO */
    versioninfo->moduleID = (uint8)CSM_MODULE_ID; /* SBSW_CSM_GETVERSIONINFO */
    versioninfo->sw_major_version = (uint8)CSM_SW_MAJOR_VERSION; /* SBSW_CSM_GETVERSIONINFO */
    versioninfo->sw_minor_version = (uint8)CSM_SW_MINOR_VERSION; /* SBSW_CSM_GETVERSIONINFO */
    versioninfo->sw_patch_version = (uint8)CSM_SW_PATCH_VERSION; /* SBSW_CSM_GETVERSIONINFO */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)CSM_GETVERSIONINFO_ID, errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */
}
#endif /* (CSM_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
 *  Csm_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CSM_CODE) Csm_MainFunction(void)
{
#if (CSM_JOB == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
# if (CSM_ASYNC_PROCESSING == STD_ON)

    Csm_QueueInfoIterType queueIdx;

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Loop over configured queues and trigger asynchronous job processing */
    for (queueIdx = 0u; queueIdx < Csm_GetSizeOfQueueInfo(); queueIdx++)
    {
      Csm_TriggerAsynchJobProcessing(queueIdx);
    }

#  if (CSM_CALLOUT == STD_ON)
    {
      Csm_CalloutInfoIterType calloutInfoIdx;
      for (calloutInfoIdx = 0u; calloutInfoIdx < Csm_GetSizeOfCalloutInfo(); calloutInfoIdx++)
      {
        if (Csm_GetCalloutStateOfCalloutState(calloutInfoIdx) == CSM_CALLOUT_STATE_PROCESSING_ABORTED_BY_CALLOUT)
        {
          Csm_CallbackNotification(&Csm_GetJob(Csm_GetJobTableIdxOfCalloutInfo(calloutInfoIdx)), E_NOT_OK); /* SBSW_CSM_PASS_JOB_POINTER_CSL03 */
        }
      }
    }
#  endif /* (CSM_CALLOUT == STD_ON) */

#  if (CSM_RTECALLBACK == STD_ON)
    /* Rte Notifications */
    if (Csm_IsRteCallbackOccured())
    {
      Csm_JobIterType callbackIdx;
      Std_ReturnType retVal;

      Csm_SetRteCallbackOccured(FALSE); /* SBSW_CSM_CSL_VAR_ACCESS */
      for (callbackIdx = 0u; callbackIdx < Csm_GetSizeOfRteCallback(); callbackIdx++)
      {
        retVal = Csm_GetRteResult(callbackIdx);
        if (retVal != CSM_CALLBACK_IDLE)
        {
          Csm_SetRteResult(callbackIdx, CSM_CALLBACK_IDLE); /* SBSW_CSM_WRITE_TO_RTERESULT_BY_SIZE */
          (void)Csm_GetRteCallback(callbackIdx)(retVal);  /* SBSW_CSM_FUNCTION_POINTER */
        }
      }
    }
#  endif /* (CSM_RTECALLBACK == STD_ON) */
# endif /* (CSM_ASYNC_PROCESSING == STD_ON) */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_MAINFUNCTION_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */
#endif /* (CSM_JOB == STD_ON) */
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */ /* Csm_MainFunction() */

/**********************************************************************************************************************
 *  Csm_CallbackNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, CSM_CODE) Csm_CallbackNotification(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job,
                                              Std_ReturnType result)
{
#if (CSM_JOB == STD_ON) && (CSM_ASYNC_PROCESSING == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CSM_E_NO_ERROR;
  Std_ReturnType resultCopy = result;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check for null pointers */
  else if (job == NULL_PTR)
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  else if (job->jobInfo->jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {

# if (CSM_CALLOUT == STD_ON)
    Csm_CallPostJobCallout(job, &resultCopy); /* SBSW_CSM_PASS_JOB_POINTER_LOCALLY_CHECKED */
# endif /* (CSM_CALLOUT == STD_ON) */
    /* #30 Call user callback function */
# if (CSM_CALLBACK_START_NOTIFICATION == STD_OFF)
    if ((((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_UPDATE) == CRYPTO_OPERATIONMODE_UPDATE)
            && (job->jobPrimitiveInfo->callbackUpdateNotification == TRUE))
        || ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH)
        || (resultCopy == CRYPTO_E_JOB_CANCELED))
# endif /* (CSM_CALLBACK_START_NOTIFICATION == STD_OFF) */
    {
# if (CSM_CALLBACKFUNC43OFBSWCALLBACKS == STD_ON) 
      if (Csm_IsBswCallbacksUsedOfJobTable(job->jobInfo->jobId) && (Csm_GetCallbackFunc43OfBswCallbacks(Csm_GetBswCallbacksIdxOfJobTable(job->jobInfo->jobId)) != NULL_PTR))
      {
        Csm_GetCallbackFunc43OfBswCallbacks(Csm_GetBswCallbacksIdxOfJobTable(job->jobInfo->jobId))(job, resultCopy); /* SBSW_CSM_API_CALL_FORWARDING_PTR */
      }
      else
# endif /* (CSM_CALLBACKFUNC43OFBSWCALLBACKS == STD_ON) */

# if(CSM_CALLBACKFUNC44OFBSWCALLBACKS == STD_ON) 
      if (Csm_IsBswCallbacksUsedOfJobTable(job->jobInfo->jobId) && (Csm_GetCallbackFunc44OfBswCallbacks(Csm_GetBswCallbacksIdxOfJobTable(job->jobInfo->jobId)) != NULL_PTR))
      {
        Csm_GetCallbackFunc44OfBswCallbacks(Csm_GetBswCallbacksIdxOfJobTable(job->jobInfo->jobId))(job->jobInfo->jobId, resultCopy); /* SBSW_CSM_API_CALL_FORWARDING_ID_ONLY */
      }
      else
# endif  /* (CSM_CALLBACKFUNC44OFBSWCALLBACKS == STD_ON) */

# if(CSM_CALLBACKFUNC45OFBSWCALLBACKS == STD_ON) 
      /* Coming to this line Csm_GetCallbackFunc45OfBswCallbacks is always != NULL_PTR */
      if (Csm_IsBswCallbacksUsedOfJobTable(job->jobInfo->jobId))
      {
        Csm_GetCallbackFunc45OfBswCallbacks(Csm_GetBswCallbacksIdxOfJobTable(job->jobInfo->jobId))(job, resultCopy); /* SBSW_CSM_API_CALL_FORWARDING_PTR */
      }
      else
#  endif /* (CSM_CALLBACKFUNC45OFBSWCALLBACKS == STD_ON) */

# if (CSM_RTECALLBACK == STD_ON)
      if (Csm_IsRteCallbackUsedOfJobTable(job->jobInfo->jobId)) /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
      {
        Csm_SetRteResult(Csm_GetRteCallbackIdxOfJobTable(job->jobInfo->jobId), resultCopy);  /* SBSW_CSM_WRITE_TO_RTERESULT_BY_JOBID */
        Csm_SetRteCallbackOccured(TRUE); /* SBSW_CSM_CSL_VAR_ACCESS */
      }
      else
# endif /* (CSM_RTECALLBACK == STD_ON) */

      {
        errorId = CSM_E_PARAM_METHOD_INVALID;
        /* Notification was called with an invalid job */
        CSM_DUMMY_STATEMENT(resultCopy); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
      }
    }
# if (CSM_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO == STD_ON)
    {
      /* #40 Trigger new asynchronous job */
      Csm_QueueInfoIterType queueIdx;
      queueIdx = Csm_GetQueueRefIdxOfJobTable(job->jobInfo->jobId);
      if (Csm_IsTriggerAsynchJobsInCallbackOfQueueInfo(queueIdx)) /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
      {
        Csm_TriggerAsynchJobProcessing(queueIdx);
      }
    }
# endif /* (CSM_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO == STD_ON) */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_CALLBACKNOTIFICATION_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */
#else
  CSM_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* (CSM_JOB == STD_ON) && (CSM_ASYNC_PROCESSING == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/* Csm Key Management Functions */
/**********************************************************************************************************************
 *  Csm_KeyElementSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyElementSet(uint32 keyId,
                                                 uint32 keyElementId,
                                                 P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) keyPtr,
                                                 uint32 keyLength)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check for null pointers */
  else if (keyPtr == NULL_PTR)
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  /* #30 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Call of CryIf_KeyElementSet function */
    retVal = CryIf_KeyElementSet(Csm_GetCryIfKeyIdOfKey(keyId), keyElementId, keyPtr, keyLength); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYELEMENTSET_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT_CONST(keyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyElementSet() */

/**********************************************************************************************************************
 *  Csm_KeySetValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeySetValid(uint32 keyId)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Call of CryIf_KeySetValid function */
    retVal = CryIf_KeySetValid(Csm_GetCryIfKeyIdOfKey(keyId));
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYSETVALID_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeySetValid() */

/**********************************************************************************************************************
 *  Csm_KeyElementGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyElementGet(uint32 keyId,
                                                 uint32 keyElementId,
                                                 P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) keyPtr,
                                                 P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) keyLengthPtr)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check for null pointers */
  else if ((keyPtr == NULL_PTR)
         || (keyLengthPtr == NULL_PTR))
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  /* #30 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Call of CryIf_KeyElementGet function */
    retVal = CryIf_KeyElementGet(Csm_GetCryIfKeyIdOfKey(keyId), keyElementId, keyPtr, keyLengthPtr); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYELEMENTGET_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyElementGet() */

/**********************************************************************************************************************
 *  Csm_KeyElementCopy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyElementCopy(uint32 keyId,
                                                  uint32 keyElementId,
                                                  uint32 targetKeyId,
                                                  uint32 targetKeyElementId)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (targetKeyId >= Csm_GetSizeOfKey()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Call of CryIf_KeyElementCopy function */
    retVal = CryIf_KeyElementCopy(Csm_GetCryIfKeyIdOfKey(keyId), keyElementId, Csm_GetCryIfKeyIdOfKey(targetKeyId), targetKeyElementId);
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYELEMENTCOPY_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(targetKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(targetKeyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyElementCopy() */

/**********************************************************************************************************************
 *  Csm_KeyElementCopyPartial()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyElementCopyPartial( uint32 keyId,
                                                          uint32 keyElementId,
                                                          uint32 keyElementSourceOffset,
                                                          uint32 keyElementTargetOffset,
                                                          uint32 keyElementCopyLength,
                                                          uint32 targetKeyId,
                                                          uint32 targetKeyElementId)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (targetKeyId >= Csm_GetSizeOfKey()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Call of CryIf_KeyElementCopyPartial function */
    retVal = CryIf_KeyElementCopyPartial(Csm_GetCryIfKeyIdOfKey(keyId), keyElementId, keyElementSourceOffset, keyElementTargetOffset, keyElementCopyLength, Csm_GetCryIfKeyIdOfKey(targetKeyId), targetKeyElementId);
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYELEMENTCOPYPARTIAL_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyElementSourceOffset); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyElementTargetOffset); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(keyElementCopyLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(targetKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(targetKeyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
}

/**********************************************************************************************************************
 *  Csm_KeyCopy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyCopy(uint32 keyId,
                                           uint32 targetKeyId)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (targetKeyId >= Csm_GetSizeOfKey()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Call of CryIf_KeyCopy function */
    retVal = CryIf_KeyCopy(Csm_GetCryIfKeyIdOfKey(keyId), Csm_GetCryIfKeyIdOfKey(targetKeyId));
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYCOPY_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(targetKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyCopy() */

/**********************************************************************************************************************
 *  Csm_RandomSeed()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_RandomSeed(uint32 keyId,
                                              P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) seedPtr,
                                              uint32 seedLength)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check for null pointers */
  else if (seedPtr == NULL_PTR)
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  /* #30 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Call of CryIf_RandomSeed function */
    retVal = CryIf_RandomSeed(Csm_GetCryIfKeyIdOfKey(keyId), seedPtr, seedLength); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_RANDOMSEED_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT_CONST(seedPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(seedLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_RandomSeed() */

/**********************************************************************************************************************
 *  Csm_KeyGenerate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyGenerate(uint32 keyId)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Call of CryIf_KeyGenerate function */
    retVal = CryIf_KeyGenerate(Csm_GetCryIfKeyIdOfKey(keyId));
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYGENERATE_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyGenerate() */

/**********************************************************************************************************************
 *  Csm_KeyDerive()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyDerive(uint32 keyId,
                                             uint32 targetKeyId)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (targetKeyId >= Csm_GetSizeOfKey()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Call of CryIf_KeyDerive function */
    retVal = CryIf_KeyDerive(Csm_GetCryIfKeyIdOfKey(keyId), Csm_GetCryIfKeyIdOfKey(targetKeyId));
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYDERIVE_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(targetKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyDerive() */

/**********************************************************************************************************************
 *  Csm_KeyExchangeCalcPubVal()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyExchangeCalcPubVal(uint32 keyId,
                                                         P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) publicValuePtr,
                                                         P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) publicValueLengthPtr)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check for null pointers */
  else if ((publicValuePtr == NULL_PTR)
         || (publicValueLengthPtr == NULL_PTR))
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  /* #30 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Call of CryIf_KeyExchangeCalcPubVal function */
    retVal = CryIf_KeyExchangeCalcPubVal(Csm_GetCryIfKeyIdOfKey(keyId), publicValuePtr, publicValueLengthPtr); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYEXCHANGECALCPUBVAL_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(publicValuePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(publicValueLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyExchangeCalcPubVal() */

/**********************************************************************************************************************
 *  Csm_KeyExchangeCalcSecret()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_KeyExchangeCalcSecret(uint32 keyId,
                                                         P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) partnerPublicValuePtr,
                                                         uint32 partnerPublicValueLength)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check for null pointers */
  else if (partnerPublicValuePtr == NULL_PTR)
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  /* #30 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Call of CryIf_KeyExchangeCalcSecret function */
    retVal = CryIf_KeyExchangeCalcSecret(Csm_GetCryIfKeyIdOfKey(keyId), partnerPublicValuePtr, partnerPublicValueLength); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_KEYEXCHANGECALCSECRET_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(partnerPublicValuePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(partnerPublicValueLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_KeyExchangeCalcSecret() */

/**********************************************************************************************************************
 *  Csm_CertificateParse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_CertificateParse(uint32 keyId)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key range */
  else if (keyId >= Csm_GetSizeOfKey())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Call of CryIf_CertificateParse function */
    retVal = CryIf_CertificateParse(Csm_GetCryIfKeyIdOfKey(keyId));
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_CERTIFICATEPARSE_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_CertificateParse() */

/**********************************************************************************************************************
 *  Csm_CertificateVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_CertificateVerify(uint32 keyId,
                                                     uint32 verifyKeyId,
                                                     P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr)
{
#if (CSM_KEY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check for null pointers */
  else if (verifyPtr == NULL_PTR)
  {
    errorId = CSM_E_PARAM_POINTER;
  }
  /* #30 Check key range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (verifyKeyId >= Csm_GetSizeOfKey()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Call of CryIf_CertificateVerify function */
    retVal = CryIf_CertificateVerify(Csm_GetCryIfKeyIdOfKey(keyId), Csm_GetCryIfKeyIdOfKey(verifyKeyId), verifyPtr); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_CERTIFICATEVERIFY_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(keyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(verifyKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(verifyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_KEY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_CertificateVerify() */

/**********************************************************************************************************************
 *  Csm_CancelJob()
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
FUNC(Std_ReturnType, CSM_CODE) Csm_CancelJob(uint32 jobId,
                                             Crypto_OperationModeType mode)
{
#if (CSM_JOB == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);

# if (CSM_ASYNC_PROCESSING == STD_ON)

    boolean isJobQueued = FALSE;
    /* #30 Remove asynchronous job from job queue */
    if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_ASYNC)
    {
      Csm_QueueIterType idx = Csm_GetQueueStartIdxOfQueueInfo(queueInfoIdx);
      Csm_QueueIdxOfQueueStateType queueSize;

      SchM_Enter_Csm_CSM_EXCLUSIVE_AREA_0();
      queueSize = Csm_GetQueueIdxOfQueueState(queueInfoIdx);

      for (; idx < queueSize; idx++)
      {
        if (Csm_GetQueue(idx)->jobInfo->jobId == jobId)
        {
          /* Job is queued */
          isJobQueued = TRUE;
          /* Decrease queue index */
          Csm_GetQueueIdxOfQueueState(queueInfoIdx)--; /* SBSW_CSM_WRITE_TO_QUEUESTATE_BY_JOBID */
        }

        /* Shift remaining jobs to the left */
        if ((isJobQueued == TRUE) && (idx < (Csm_QueueIdxOfQueueStateType)(queueSize - 1u)))
        {
          Csm_SetQueue(idx, Csm_GetQueue(idx + 1u)); /* SBSW_CSM_WRITE_TO_QUEUE_BY_LOCALIDX */
        }
      }
      SchM_Exit_Csm_CSM_EXCLUSIVE_AREA_0();

      /* #40 If job was queued, call configured callback notification function */
      if (isJobQueued == TRUE)
      {
        Csm_CallbackNotification(job, CRYPTO_E_JOB_CANCELED); /* SBSW_CSM_API_CALL_FORWARDING_PTR */
        retVal = E_OK;
      }
      else
      {
        retVal = CryIf_CancelJob(Csm_GetChannelIdOfQueueInfo(queueInfoIdx), job); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
      }
    }
    else
# endif /* (CSM_ASYNC_PROCESSING == STD_ON) */
    {
      /* #50 else cancel job in lower layer */
      retVal = CryIf_CancelJob(Csm_GetChannelIdOfQueueInfo(queueInfoIdx), job); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */

# if (CSM_CALLOUT == STD_ON)
      if(retVal == E_OK)
      {
        Csm_CallPostJobCallout(job, &retVal); /* SBSW_CSM_PASS_JOB_POINTER_LOCALLY_CHECKED */
      }
# endif /* (CSM_CALLOUT == STD_ON) */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_CANCELJOB_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retVal;
#else

  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_JOB == STD_ON) */
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */ /* Csm_CancelJob() */

/* Csm Service Functions */

/**********************************************************************************************************************
 *  Csm_Hash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_Hash(uint32 jobId,
                                        Crypto_OperationModeType mode,
                                        P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
                                        uint32 dataLength,
                                        P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
                                        P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr)
{
#if (CSM_EXIST_HASH == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = dataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = dataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = resultPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_HASH); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_HASH_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_Hash() */

/**********************************************************************************************************************
 *  Csm_MacGenerate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_MacGenerate(uint32 jobId,
                                               Crypto_OperationModeType mode,
                                               P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
                                               uint32 dataLength,
                                               P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) macPtr,
                                               P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) macLengthPtr)
{
#if (CSM_EXIST_MACGENERATE == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = dataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = dataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = macPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = macLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_MACGENERATE); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_MACGENERATE_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(macPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(macLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_MACGENERATE == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_MacGenerate() */

/**********************************************************************************************************************
 *  Csm_MacVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_MacVerify(uint32 jobId,
                                             Crypto_OperationModeType mode,
                                             P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
                                             uint32 dataLength,
                                             P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) macPtr,
                                             uint32 macLength,
                                             P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr)
{
#if (CSM_EXIST_MACVERIFY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = dataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = dataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputPtr = macPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputLength = macLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.verifyPtr = verifyPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_MACVERIFY); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_MACVERIFY_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(macPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(macLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(verifyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_MACVERIFY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_MacVerify() */

/**********************************************************************************************************************
 *  Csm_Encrypt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_Encrypt(uint32 jobId,
                                           Crypto_OperationModeType mode,
                                           P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
                                           uint32 dataLength,
                                           P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
                                           P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr)
{
#if (CSM_EXIST_ENCRYPT == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = dataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = dataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = resultPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_ENCRYPT); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_ENCRYPT_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_ENCRYPT == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_Encrypt() */

/**********************************************************************************************************************
 *  Csm_Decrypt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_Decrypt(uint32 jobId,
                                           Crypto_OperationModeType mode,
                                           P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
                                           uint32 dataLength,
                                           P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
                                           P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr)
{
#if (CSM_EXIST_DECRYPT == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = dataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = dataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = resultPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_DECRYPT); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_DECRYPT_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_DECRYPT == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_Decrypt() */

/**********************************************************************************************************************
 *  Csm_AEADEncrypt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_AEADEncrypt(uint32 jobId,
                                               Crypto_OperationModeType mode,
                                               P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) plaintextPtr,
                                               uint32 plaintextLength,
                                               P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) associatedDataPtr,
                                               uint32 associatedDataLength,
                                               P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) ciphertextPtr,
                                               P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) ciphertextLengthPtr,
                                               P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) tagPtr,
                                               P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) tagLengthPtr)
{
#if (CSM_EXIST_AEADENCRYPT == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = plaintextPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = plaintextLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = ciphertextPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = ciphertextLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryOutputPtr = tagPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryOutputLengthPtr = tagLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_AEADENCRYPT); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_AEADENCRYPT_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(plaintextPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(plaintextLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(associatedDataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(associatedDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(ciphertextPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(ciphertextLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(tagPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(tagLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_AEADENCRYPT == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_AEADEncrypt() */

/**********************************************************************************************************************
 *  Csm_AEADDecrypt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_AEADDecrypt(uint32 jobId,
                                               Crypto_OperationModeType mode,
                                               P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) ciphertextPtr,
                                               uint32 ciphertextLength,
                                               P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) associatedDataPtr,
                                               uint32 associatedDataLength,
                                               P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) tagPtr,
                                               uint32 tagLength,
                                               P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) plaintextPtr,
                                               P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) plaintextLengthPtr,
                                               P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr)
{
#if (CSM_EXIST_AEADDECRYPT == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = ciphertextPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = ciphertextLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputPtr = associatedDataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputLength = associatedDataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.tertiaryInputPtr = tagPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.tertiaryInputLength = tagLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = plaintextPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = plaintextLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.verifyPtr = verifyPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_AEADDECRYPT); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_AEADDECRYPT_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(ciphertextPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(ciphertextLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(associatedDataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(associatedDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(tagPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(tagLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(plaintextPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(plaintextLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(verifyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_AEADDECRYPT == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_AEADDecrypt() */

/**********************************************************************************************************************
 *  Csm_SignatureGenerate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_SignatureGenerate(uint32 jobId,
                                                     Crypto_OperationModeType mode,
                                                     P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
                                                     uint32 dataLength,
                                                     P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
                                                     P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr)
{
#if (CSM_EXIST_SIGNATUREGENERATE == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = dataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = dataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = resultPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_SIGNATUREGENERATE); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_SIGNATUREGENERATE_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_SIGNATUREGENERATE == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_SignatureGenerate() */

/**********************************************************************************************************************
 *  Csm_SignatureVerify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_SignatureVerify(uint32 jobId,
                                                   Crypto_OperationModeType mode,
                                                   P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
                                                   uint32 dataLength,
                                                   P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) signaturePtr,
                                                   uint32 signatureLength,
                                                   P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr)
{
#if (CSM_EXIST_SIGNATUREVERIFY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = mode; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = dataPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = dataLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputPtr = signaturePtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.secondaryInputLength = signatureLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.verifyPtr = verifyPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_SIGNATUREVERIFY); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_SIGNATUREVERIFY_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(dataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(signaturePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(signatureLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(verifyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_SIGNATUREVERIFY == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_SignatureVerify() */

/**********************************************************************************************************************
 *  Csm_RandomGenerate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CSM_CODE) Csm_RandomGenerate(uint32 jobId,
                                                  P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
                                                  P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr)
{
#if (CSM_EXIST_RANDOMGENERATE == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check job range */
  else if (jobId >= Csm_GetSizeOfJob())
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable(jobId);
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job = Csm_GetAddrJob(jobId);

    job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = resultPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = resultLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob(queueInfoIdx, job, CRYPTO_RANDOMGENERATE); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_RANDOMGENERATE_ID), errorId);
  }
# else
  CSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT(jobId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT(resultLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_RANDOMGENERATE == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_RandomGenerate() */

/**********************************************************************************************************************
 *  Csm_JobKeySetValid()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, CSM_CODE ) Csm_JobKeySetValid( uint32 jobId, uint32 keyId )
{
#if (CSM_EXIST_JOBKEYSETVALID == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */ 
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key and job range */
  else if ( ( keyId >= Csm_GetSizeOfKey() ) || ( jobId >= Csm_GetSizeOfJob() ) )
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable( jobId );
    P2VAR( Crypto_JobType, AUTOMATIC, CSM_APPL_VAR ) job = Csm_GetAddrJob( jobId );

    job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.cryIfKeyId = Csm_GetCryIfKeyIdOfKey( keyId ); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
            
    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob( queueInfoIdx, job, CRYPTO_KEYSETVALID ); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError( (uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_JOBKEYSETVALID_ID), errorId );
  }
# else
  CSM_DUMMY_STATEMENT( errorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT( jobId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( keyId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_JOBKEYSETVALID == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_JobKeySetValid() */ 

/**********************************************************************************************************************
 *  Csm_JobRandomSeed()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, CSM_CODE ) Csm_JobRandomSeed( uint32 jobId, uint32 keyId, P2CONST( uint8, AUTOMATIC, CSM_APPL_VAR ) seedPtr, uint32 seedLength )
{
  {
#if (CSM_EXIST_JOBRANDOMSEED == STD_ON)
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
    uint8 errorId = CSM_E_NO_ERROR;

    /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
    /* #10 Check initialization state of the component */
    if (Csm_IsInitialized != CSM_INITIALIZED)
    {
      errorId = CSM_E_UNINIT;
    }
    /* #20 Check key and job range */
    else if ( ( keyId >= Csm_GetSizeOfKey() ) || ( jobId >= Csm_GetSizeOfJob() ) )
    {
      errorId = CSM_E_PARAM_METHOD_INVALID;
    }
    else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
    {
      /* ----- Implementation ----------------------------------------------- */
      Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable( jobId );
      P2VAR( Crypto_JobType, AUTOMATIC, CSM_APPL_VAR ) job = Csm_GetAddrJob( jobId );

      job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobPrimitiveInputOutput.cryIfKeyId = Csm_GetCryIfKeyIdOfKey( keyId ); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobPrimitiveInputOutput.inputPtr = seedPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
      job->jobPrimitiveInputOutput.inputLength = seedLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */

      /* #30 Dispatch job if possible */
      retVal = Csm_ProcessJob( queueInfoIdx, job, CRYPTO_RANDOMSEED ); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
    }
    /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
    if (errorId != CSM_E_NO_ERROR)
    {
      (void)Det_ReportError( (uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_JOBRANDOMSEED_ID), errorId );
    }
# else
    CSM_DUMMY_STATEMENT( errorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

    return retVal;
#else
    CSM_DUMMY_STATEMENT_CONST( jobId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    CSM_DUMMY_STATEMENT( keyId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    CSM_DUMMY_STATEMENT_CONST( seedPtr ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    CSM_DUMMY_STATEMENT( seedLength ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    return E_NOT_OK;
#endif /* (CSM_EXIST_JOBRANDOMSEED == STD_ON) */
  } /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_JobRandomSeed() */
}

/**********************************************************************************************************************
 *  Csm_JobKeyGenerate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, CSM_CODE ) Csm_JobKeyGenerate( uint32 jobId, uint32 keyId )
{
#if (CSM_EXIST_JOBKEYGENERATE == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key and job range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (jobId >= Csm_GetSizeOfJob()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable( jobId );
    P2VAR( Crypto_JobType, AUTOMATIC, CSM_APPL_VAR ) job = Csm_GetAddrJob( jobId );

    job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.cryIfKeyId = Csm_GetCryIfKeyIdOfKey( keyId ); /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob( queueInfoIdx, job, CRYPTO_KEYGENERATE ); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError( (uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_JOBKEYGENERATE_ID), errorId );
  }
# else
  CSM_DUMMY_STATEMENT( errorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT( jobId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( keyId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_JOBKEYGENERATE == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_JobKeyGenerate() */


/**********************************************************************************************************************
 *  Csm_JobKeyDerive()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, CSM_CODE ) Csm_JobKeyDerive( uint32 jobId, uint32 keyId, uint32 targetKeyId )
{
#if (CSM_EXIST_JOBKEYDERIVE == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key, targetKey and job range */
  else if ( (keyId >= Csm_GetSizeOfKey()) || (targetKeyId >= Csm_GetSizeOfKey()) || (jobId >= Csm_GetSizeOfJob()) )
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable( jobId );
    P2VAR( Crypto_JobType, AUTOMATIC, CSM_APPL_VAR ) job = Csm_GetAddrJob( jobId );

    job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.cryIfKeyId = Csm_GetCryIfKeyIdOfKey( keyId ); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.targetCryIfKeyId = Csm_GetCryIfKeyIdOfKey( targetKeyId ); /* SBSW_CSM_WRITE_TO_JOB_POINTER */

    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob( queueInfoIdx, job, CRYPTO_KEYDERIVE ); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError( (uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_JOBKEYDERIVE_ID), errorId );
  }
# else
  CSM_DUMMY_STATEMENT( errorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT( jobId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( keyId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( targetKeyId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_JOBKEYDERIVE == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_JobKeyDerive() */

/**********************************************************************************************************************
 *  Csm_JobKeyExchangeCalcPubVal()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, CSM_CODE ) Csm_JobKeyExchangeCalcPubVal( uint32 jobId,
                                                               uint32 keyId, 
                                                               P2VAR( uint8, AUTOMATIC, CSM_APPL_VAR ) publicValuePtr, 
                                                               P2VAR( uint32, AUTOMATIC, CSM_APPL_VAR ) publicValueLengthPtr )
{
#if (CSM_EXIST_JOBKEYEXCHANGECALCPUBVAL == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key and job range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (jobId >= Csm_GetSizeOfJob()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable( jobId );
    P2VAR( Crypto_JobType, AUTOMATIC, CSM_APPL_VAR ) job = Csm_GetAddrJob( jobId );

    job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.cryIfKeyId = Csm_GetCryIfKeyIdOfKey( keyId ); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputPtr = publicValuePtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.outputLengthPtr = publicValueLengthPtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob( queueInfoIdx, job, CRYPTO_KEYEXCHANGECALCPUBVAL ); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError( (uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_JOBKEYEXCHANGECALCPUBVAL_ID), errorId );
  }
# else
  CSM_DUMMY_STATEMENT( errorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT( jobId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( keyId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( publicValuePtr ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( publicValueLengthPtr ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_JOBKEYEXCHANGECALCPUBVAL == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_JobKeyExchangeCalcPubVal() */

/**********************************************************************************************************************
 *  Csm_JobKeyExchangeCalcSecret()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC( Std_ReturnType, CSM_CODE ) Csm_JobKeyExchangeCalcSecret(  uint32 jobId,
                                                                uint32 keyId, 
                                                                P2CONST( uint8, AUTOMATIC, CSM_APPL_VAR ) partnerPublicValuePtr, 
                                                                uint32 partnerPublicValueLength ) 
{
#if (CSM_EXIST_JOBKEYEXCHANGECALCSECRET == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CSM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Csm_IsInitialized != CSM_INITIALIZED)
  {
    errorId = CSM_E_UNINIT;
  }
  /* #20 Check key and job range */
  else if ((keyId >= Csm_GetSizeOfKey()) || (jobId >= Csm_GetSizeOfJob()))
  {
    errorId = CSM_E_PARAM_METHOD_INVALID;
  }
  else
# endif /* (CSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* ----- Implementation ----------------------------------------------- */
    Csm_QueueInfoIterType queueInfoIdx = Csm_GetQueueRefIdxOfJobTable( jobId );
    P2VAR( Crypto_JobType, AUTOMATIC, CSM_APPL_VAR ) job = Csm_GetAddrJob( jobId );

    job->jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.cryIfKeyId = Csm_GetCryIfKeyIdOfKey( keyId ); /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputPtr = partnerPublicValuePtr; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    job->jobPrimitiveInputOutput.inputLength = partnerPublicValueLength; /* SBSW_CSM_WRITE_TO_JOB_POINTER */
    /* #30 Dispatch job if possible */
    retVal = Csm_ProcessJob( queueInfoIdx, job, CRYPTO_KEYEXCHANGECALCSECRET ); /* SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CSM_E_NO_ERROR)
  {
    (void)Det_ReportError( (uint16)CSM_MODULE_ID, CSM_INSTANCE_ID, (uint8)(CSM_JOBKEYEXCHANGECALCSECRET_ID), errorId );
  }
# else
  CSM_DUMMY_STATEMENT( errorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CSM_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
#else
  CSM_DUMMY_STATEMENT( jobId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( keyId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( partnerPublicValuePtr ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CSM_DUMMY_STATEMENT( partnerPublicValueLength ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
#endif /* (CSM_EXIST_JOBKEYEXCHANGECALCSECRET == STD_ON) */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */ /* Csm_JobKeyExchangeCalcSecret() */


#define CSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Module specific MISRA deviations
 *********************************************************************************************************************/
/* Module specific MISRA deviations:
  MD_CSM_DECLARED_BY_RTE:
    Reason:     The function is declared by RTE which is not part of the MISRA check.
    Risk:       None
    Prevention: Covered by review and compile/link test.
  MD_CSM_QUEUE_BY_QUEUEIDX:
    Reason:     If Queue variable has only a size of 1, accessing with any index + 1 causes this message.
    Risk:       Access could be executed causing an invalid memory access.
    Prevention: During runtime, loop is only entered if Queue is at least two since index is checked agains localQueueIndex. Covered by code review.
  MD_CSM_ACCESSED_ONLY_ONCE:
    Reason:     The table Csm_ServiceToApiIdTable lies in static ROM, but is only accessed in one function.
    Risk:       Additional Rom usage.
    Prevention: None.
 */

/* SBSW_JUSTIFICATION_BEGIN
  \ID SBSW_CSM_GETVERSIONINFO
    \DESCRIPTION The function Csm_GetVersionInfo writes to the object referenced by parameter VersionInfoPtr
    \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter VersionInfoPtr is valid.

  \ID SBSW_CSM_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    The API is called with a pointer and an id.
    \COUNTERMEASURE \N The function pointer is read using the passed Id and ComStackLib macros (CSL03).
                       The Id is a SNV provided by the Csm and is converted to the corresponding ID of lower layer using ComStackLib (CSL01).
                       It is checked when it was first passed to the Csm module.
                       The pointer is either forwarded and assumed to be valid or it is a local stack variable.

  \ID SBSW_CSM_FUNCTION_POINTER
    \DESCRIPTION    The API call is made using a function pointer which is read using ComStackLib macros.
    \COUNTERMEASURE \N The function pointer is read using the passed Id and ComStackLib macros (CSL03).
                       The pointer is forwarded and assumed to be valid.

  \ID SBSW_CSM_API_CALL_FORWARDING_PTR
    \DESCRIPTION    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    The API is called with a pointer.
    \COUNTERMEASURE \N The function pointer is read using the passed Id and ComStackLib macros (CSL03).
                       The pointer is forwarded and assumed to be valid.

  \ID SBSW_CSM_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    The API is called with an Id.
    \COUNTERMEASURE \N The function pointer is read using the passed Id and ComStackLib macros (CSL03).
                       The Id is a SNV provided by the Csm and is converted to the corresponding ID of lower layer using ComStackLib (CSL01).
                       It is checked when it was first passed to the Csm module.

  \ID SBSW_CSM_PASS_JOB_POINTER_LOCALLY_CHECKED
    \DESCRIPTION    The function passes a pointer referencing a job. The passed pointer has been passed by the caller and is locally checked.
    \COUNTERMEASURE \N The function is only called if the pointer to the job is valid.

  \ID SBSW_CSM_PASS_JOB_POINTER_LOCAL
    \DESCRIPTION    The function passes a pointer referencing a job. The passed pointer has been initialized and points to a valid job object.
    \COUNTERMEASURE \N The pointer is initialized from a local queue. The queue is only filled with valid job objects and therefore always contains valid jobs except when it is empty. In this case, the function is not called.

  \ID SBSW_CSM_PASS_JOB_POINTER_API_REQUIREMENT
    \DESCRIPTION    The function passes a pointer referencing a job. The passed pointer has been passed by the caller. The API requires that the referenced job is valid.
    \COUNTERMEASURE \N The caller ensures that the pointer passed as parameter is valid and references a valid object.

  \ID SBSW_CSM_PASS_JOB_POINTER_CSL03
    \DESCRIPTION    The function passes a pointer referencing a job. The passed pointer is valid since it is an indirection to Job via CalloutInfo.
    \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_CSM_WRITE_TO_JOB_POINTER
    \DESCRIPTION    The function does a write access on the job pointer.
    \COUNTERMEASURE \R The pointer is checked when it was first to the service.

  \ID SBSW_CSM_WRITE_TO_CALLOUT_STATE_BY_SIZE
  \DESCRIPTION Access of CalloutState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_CSM_WRITE_TO_QUEUESTATE_BY_SIZE
    \DESCRIPTION Access of QueueState using ComStackLib 
    \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib
  
  \ID SBSW_CSM_WRITE_TO_RTERESULT_BY_SIZE
    \DESCRIPTION Access of RteCallback and RteResult with same index using ComStackLib 
    \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib 

  \ID SBSW_CSM_WRITE_TO_RTERESULT_BY_JOBID
    \DESCRIPTION Access to RteResult via indirection over JobTable.
    \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib 

  \ID SBSW_CSM_WRITE_TO_QUEUESTATE_BY_JOBID
    \DESCRIPTION Access to QueueState via indirection over JobTable. 
    \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib 

  \ID SBSW_CSM_WRITE_TO_QUEUE_BY_LOCALIDX
    \DESCRIPTION Access to Queue via localQueueIndex which is always checked agaist its size via indirection over QueueInfo. 
    \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_CSM_CSL_VAR_ACCESS
    \DESCRIPTION A ComStackLib generated variable is accessed.
    \COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables address without pointer arithmetic.

  \ID SBSW_CSM_API_CALL_FORWARDING_PTR_WRAPPER
    \DESCRIPTION    The API call is forwarded to an existing API function.
                    The API is called with one or more pointers passed from the wrapper API function.
    \COUNTERMEASURE \N The called functions in the wrapper functions are API functions that are supposed to be silent.

SBSW_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN
  \ID COV_CSM_NON_RTE
    \ACCEPT TX
    \ACCEPT XF
    \REASON Ensures the variable or error code define exists if the CSM is used without RTE.
  \ID COV_CSM_USER_DEFINES
    \ACCEPT TX
    \ACCEPT XF
    \REASON Ensures the variable or error code define exists if the CSM is used.
  \ID COV_CSM_NOT_YET_SUPPORTED
    \ACCEPT XF
    \REASON This feature is not yet supported.
  \ID COV_CSM_LOCAL_DEFINE
    \ACCEPT TX
    \REASON CSM_LOCAL is not defined externally.
  \ID COV_CSM_CALLBACKCHECK
    \ACCEPT TX
    \REASON Only a memory optimization in case there is no callback defined for any job.
COV_JUSTIFICATION_END */
/**********************************************************************************************************************
 *  END OF FILE: CSM.C
 *********************************************************************************************************************/

