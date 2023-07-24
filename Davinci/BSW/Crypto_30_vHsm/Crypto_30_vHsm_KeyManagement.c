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
/*      \file  Crypto_30_vHsm_KeyManagement.c
 *      \brief  MICROSAR vHsm Crypto Driver (Crypto)
 *
 *      \details  Implementation of the MICROSAR Crypto Driver (Crypto)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_KEYMANAGEMENT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm.h"
#include "Crypto_30_vHsm_Ipc.h"
#include "SchM_Crypto_30_vHsm.h"

#if ( CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
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
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ProcessKeyMJob()
 *********************************************************************************************************************/
 /*! \brief        Process key management job
 *  \details       Check if vHsm is busy, otherwise execute job
 *  \param[in]     keyMJob                 Pointer to a valid KeyM job structure.
 *  \return        E_OK                    Process job successful.
 *                 E_NOT_OK                Process job failed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ProcessKeyMJob(
  P2VAR(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) keyMJob);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_AllocateKeyMJob()
 *********************************************************************************************************************/
/*! \brief         Find a free job request Id
 *  \details       Locking the driver object has to be done outside this function.
 *  \param[out]    jobRequestIdPtr         Pointer to a free jobRequestId which is the same as a free driver object
 *  \return        E_OK                    Free management driver object has been found
 *                 E_NOT_OK                No free management driver objects available
 *  \pre           Function is called in an exclusive area.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_AllocateKeyMJob(
  P2VAR(Crypto_30_vHsm_JobRequestIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRequestIdPtr);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_AllocateKeyMJob()
 *********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_AllocateKeyMJob(
  P2VAR(Crypto_30_vHsm_JobRequestIdType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRequestIdPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  Crypto_30_vHsm_ManagementDriverObjectIterType mngObjectIdx;

  /* #10 Iterate oder all management driver object references */
  for (mngObjectIdx = 0u; mngObjectIdx < Crypto_30_vHsm_GetSizeOfManagementDriverObject(); mngObjectIdx++)
  {
    /* #30 Check if the driver object is currently not used */
    if (!Crypto_30_vHsm_IsLockOfJobRequest(Crypto_30_vHsm_GetInternalObjectIds(Crypto_30_vHsm_GetManagementDriverObject(mngObjectIdx))))
    {
      *jobRequestIdPtr = Crypto_30_vHsm_GetInternalObjectIds(Crypto_30_vHsm_GetManagementDriverObject(mngObjectIdx)); /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
      retVal = E_OK;
      break;
    }
  }

  /* #40 Return if a free driver object has been found */
  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ProcessKeyMJob()
 *********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ProcessKeyMJob(
  P2VAR(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) keyMJob)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  Crypto_30_vHsm_JobRequestIdType jobRequestId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0();

  if(Crypto_30_vHsm_AllocateKeyMJob(&jobRequestId) == E_OK) /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  {
    Crypto_30_vHsm_SetLockOfJobRequest(jobRequestId, TRUE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    Crypto_30_vHsm_SetProcessingTypeOfJobRequest(jobRequestId, CRYPTO_PROCESSING_SYNC); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

    Crypto_30_vHsm_SetInternalObjectIdOfJobRequest(jobRequestId, jobRequestId ); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

    SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0();

    if (keyMJob->action == CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTCOPYPARTIAL)
    {
      Crypto_30_vHsm_SetKindOfJobRequest(jobRequestId, CRYPTO_30_VHSM_KEYMANAGEMENT_COPY_PARTIAL_JOBKIND); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }
    else
    {
      Crypto_30_vHsm_SetKindOfJobRequest(jobRequestId, CRYPTO_30_VHSM_KEYMANAGEMENT_JOBKIND); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
    }
    Crypto_30_vHsm_SetKeyMJobOfJobRequest(jobRequestId, keyMJob); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */

    retVal = Crypto_30_vHsm_ProcessJobRequest(
      jobRequestId,
      CRYPTO_PROCESSING_SYNC,
      FALSE );

    if (retVal == E_OK)
    {
      retVal = (Std_ReturnType)Crypto_30_vHsm_GetResultOfJobRequest(jobRequestId);
    }

    Crypto_30_vHsm_SetLockOfJobRequest(jobRequestId, FALSE); /* SBSW_CRYPTO_30_VHSM_CSL01_JOBREQUEST */
  }
  else
  {
    SchM_Exit_Crypto_30_vHsm_CRYPTO_30_VHSM_EXCLUSIVE_AREA_0();

    retVal = CRYPTO_E_BUSY;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementIdsGet()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementIdsGet(
  uint32 cryptoKeyId,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) keyElementIdsPtr, /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) keyElementIdsLengthPtr) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00161] */
    errorId = CRYPTO_E_UNINIT;
  }
  else if (keyElementIdsPtr == NULL_PTR)
  {
    /* [SWS_Crypto_00162] */
    errorId = CRYPTO_E_PARAM_HANDLE;
  }
  else if (keyElementIdsLengthPtr == NULL_PTR)
  {
    errorId = CRYPTO_E_PARAM_HANDLE;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTIDSGET;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.secondaryCryptoKeyId = 0u;

    /* Set rest of parameters to default values */
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = (P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR))keyElementIdsPtr; /* PRQA S 0310 */ /* MD_CRYPTO_30_VHSM_0310_KEYELEMENT_CONTENT */
    keyMJob.inputOutput.outputLengthPtr = keyElementIdsLengthPtr;

    /* Multiply by 4 because given length is the number of uint32 elements. This way, there is no special handling in the IPC, because the length is now the number of bytes. */
    *keyElementIdsLengthPtr = *keyElementIdsLengthPtr * sizeof(uint32); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */

    /* Divide by 4 because length should be the number of uint32 elements. This way, there is no special handling in the IPC. */
    *keyElementIdsLengthPtr = *keyElementIdsLengthPtr / sizeof(uint32); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_ELEMENT_IDS_GET,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  CRYPTO_30_VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyCopy()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyCopy(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters */
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00156] */
    errorId = CRYPTO_E_UNINIT;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    /* #20 Set the parameters inside the job needed for this command */
    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYCOPY;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.secondaryCryptoKeyId = targetCryptoKeyId;

    /* #21 Set rest of parameters to default values */
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    /* #22 Execute the job */
    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  /* #30 Report Det if error happened */
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_COPY,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementCopy()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementCopy(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00149] */
    errorId = CRYPTO_E_UNINIT;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTCOPY;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.keyElementId = keyElementId;
    keyMJob.secondaryCryptoKeyId = targetCryptoKeyId;
    keyMJob.secondaryKeyElementId = targetKeyElementId;

    /* Set rest of parameters to default values */
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_ELEMENT_COPY,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementCopyPartial()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementCopyPartial(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 keyElementSourceOffset,
  uint32 keyElementTargetOffset,
  uint32 keyElementCopyLength,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00149] */
    errorId = CRYPTO_E_UNINIT;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTCOPYPARTIAL;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.keyElementId = keyElementId;
    keyMJob.secondaryCryptoKeyId = targetCryptoKeyId;
    keyMJob.secondaryKeyElementId = targetKeyElementId;
    keyMJob.inputOutput.keyElementCopyLength = keyElementCopyLength;
    keyMJob.inputOutput.keyElementSourceOffset = keyElementSourceOffset;
    keyMJob.inputOutput.keyElementTargetOffset = keyElementTargetOffset;

    /* Set rest of parameters to default values */
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_ELEMENT_COPY_PARTIAL,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/* [SWS_Crypto_91004] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementSet()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyPtr,
  uint32 keyLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized == CRYPTO_30_VHSM_UNINIT)
  {
    errorId = CRYPTO_E_UNINIT; /* [SWS_Crypto_00075] */
  }
  else if (keyPtr == NULL_PTR)
  {
    errorId = CRYPTO_E_PARAM_POINTER; /* [SWS_Crypto_00078] */
  }
# if (CRYPTO_30_VHSM_KEY_ELEMENT_DELETE_SUPPORT == STD_OFF)
  else if (keyLength == 0u)
  {
    errorId = CRYPTO_E_PARAM_VALUE; /* [SWS_Crypto_00079] */
  }
# endif
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTSET;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.keyElementId = keyElementId;
    keyMJob.inputOutput.inputPtr = keyPtr;
    keyMJob.inputOutput.inputLength = keyLength;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    /* Check if the code flash operation has finished */
    if ((keyElementId == CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION)
      && (keyLength == 1u)
      && (keyPtr[0] == CRYPTO_30_VHSM_CODEFLASH_STOP))
    {
      /* Indicate the end of the RAM execution */
      Crypto_30_vHsm_Ipc_EndRamExec(); /* PRQA S 0310, 3305, 4404 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* SBSW_CRYPTO_30_VHSM_SET_VALUE_IN_IPC */

      /* Wait until the vHsm indicates that it is not any longer running in the RAM loop. */
      while (Crypto_30_vHsm_Ipc_IsRamExec() == TRUE) /* PRQA S 0310, 3305, 4340 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* COV_CRYPTO_30_VHSM_NO_FLASH_SYNC_SUPPORT_IN_VHSM */
      {
#if (CRYPTO_30_VHSM_WAITLOOPCALLOUTOFVHSM == STD_ON)
        Crypto_30_vHsm_GetWaitLoopCalloutOfvHsm()();
#endif
      }
    }

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */

    /* Check if this was the start of a code flash operation */
    if ((keyElementId == CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION)
      && (keyLength == 1u)
      && (keyPtr[0] == CRYPTO_30_VHSM_CODEFLASH_START)
      && (retVal == E_OK)) /* COV_CRYPTO_30_VHSM_NO_FLASH_SYNC_SUPPORT_IN_VHSM */
    {
      /* Wait until the vHsm is in the RAM loop. */
      while (Crypto_30_vHsm_Ipc_IsRamExec() != TRUE) /* PRQA S 0310, 3305, 4340 */ /* MD_CRYPTO_30_VHSM_IPC_MACRO */ /* COV_CRYPTO_30_VHSM_NO_FLASH_SYNC_SUPPORT_IN_VHSM */
      {
#if (CRYPTO_30_VHSM_WAITLOOPCALLOUTOFVHSM == STD_ON)
        Crypto_30_vHsm_GetWaitLoopCalloutOfvHsm()();
#endif
      }
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_ELEMENT_SET,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/* [SWS_Crypto_91005] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyValidSet()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyValidSet(
  uint32 cryptoKeyId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CRYPTO_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    errorId = CRYPTO_E_UNINIT; /* [SWS_Crypto_00082] */
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYVALIDSET;
    keyMJob.cryptoKeyId = cryptoKeyId;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_VALID_SET,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/* [SWS_Crypto_91006] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyElementGet()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) resultLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CRYPTO_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00085] */
    errorId = CRYPTO_E_UNINIT;
  }
  else if (resultPtr == NULL_PTR)
  {
    /* [SWS_Crypto_00088] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else if (resultLengthPtr == NULL_PTR)
  {
    /* [SWS_Crypto_00089] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else if (*resultLengthPtr == 0u)
  {
    /* [SWS_Crypto_00090] */
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTGET;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.keyElementId = keyElementId;
    keyMJob.inputOutput.outputPtr = resultPtr;
    keyMJob.inputOutput.outputLengthPtr = resultLengthPtr;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_ELEMENT_GET,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/* [SWS_Crypto_91013] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_RandomSeed()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_RandomSeed(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) entropyPtr,
  uint32 entropyLength)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00128] */
    errorId = CRYPTO_E_UNINIT;
  }
  else if (entropyPtr == NULL_PTR)
  {
    /* [SWS_Crypto_00130] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else if (entropyLength == 0u)
  {
    /* [SWS_Crypto_00131] */
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_RANDOMSEED;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.inputOutput.inputPtr = (P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA))entropyPtr;
    keyMJob.inputOutput.inputLength = entropyLength;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_RANDOM_SEED,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/* [SWS_Crypto_91007] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyGenerate()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyGenerate(
  uint32 cryptoKeyId)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00094] */
    errorId = CRYPTO_E_UNINIT;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYGENERATE;
    keyMJob.cryptoKeyId = cryptoKeyId;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_GENERATE,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/* [SWS_Crypto_91008] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyDerive()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00097] */
    errorId = CRYPTO_E_UNINIT;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYDERIVE;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.secondaryCryptoKeyId = targetCryptoKeyId;

    /* Set rest of parameters to default values */
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_DERIVE,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/* [SWS_Crypto_91009] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyExchangeCalcPubVal()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyExchangeCalcPubVal(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) publicValuePtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) publicValueLengthPtr)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00103] */
    errorId = CRYPTO_E_UNINIT;
  }
  else if (publicValuePtr == NULL_PTR)
  {
    /* [SWS_Crypto_00105] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else if (publicValueLengthPtr == NULL_PTR)
  {
    /* [SWS_Crypto_00106] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else if (*publicValueLengthPtr == 0u)
  {
    /* [SWS_Crypto_00107] */
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYEXCHANGECALCPUBVAL;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.inputOutput.outputPtr = publicValuePtr;
    keyMJob.inputOutput.outputLengthPtr = publicValueLengthPtr;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_EXCHANGE_CALC_PUB_VAL,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/* [SWS_Crypto_91010] */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_KeyExchangeCalcSecret()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_KeyExchangeCalcSecret(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) partnerPublicValuePtr,
  uint32 partnerPublicValueLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00111] */
    errorId = CRYPTO_E_UNINIT;
  }
  else if (partnerPublicValuePtr == NULL_PTR)
  {
    /* [SWS_Crypto_00113] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else if (partnerPublicValueLength == 0u)
  {
    /* [SWS_Crypto_00115] */
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_KEYEXCHANGECALCSECRET;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.inputOutput.inputPtr = (P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA))partnerPublicValuePtr;
    keyMJob.inputOutput.inputLength = partnerPublicValueLength;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_KEY_EXCHANGE_CALC_SECRET,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_CertificateParse()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_CertificateParse(
  uint32 cryptoKeyId)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00168] */
    errorId = CRYPTO_E_UNINIT;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_CERTIFICATEPARSE;
    keyMJob.cryptoKeyId = cryptoKeyId;

    /* Set rest of parameters to default values */
    keyMJob.secondaryCryptoKeyId = 0u;
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;
    keyMJob.inputOutput.outputPtr = NULL_PTR;
    keyMJob.inputOutput.outputLengthPtr = NULL_PTR;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_CERTIFICATE_PARSE,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_CertificateVerify()
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
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_CertificateVerify(
  uint32 cryptoKeyId,
  uint32 verifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) verifyPtr) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  if (Crypto_30_vHsm_ModuleInitialized != CRYPTO_30_VHSM_INITIALIZED)
  {
    /* [SWS_Crypto_00172] */
    errorId = CRYPTO_E_UNINIT;
  }
  else if (verifyPtr == NULL_PTR)
  {
    /* [SWS_Crypto_00175] */
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else
#endif
  {
    Crypto_30_vHsm_KeyM_JobType keyMJob;
    uint32 verifylength = sizeof(Crypto_VerifyResultType);

    keyMJob.action = CRYPTO_30_VHSM_KEYM_ACTION_CERTIFICATEVERIFY;
    keyMJob.cryptoKeyId = cryptoKeyId;
    keyMJob.secondaryCryptoKeyId = verifyCryptoKeyId;
    /* OutputPtr is used instead of verifyPtr which is not  */
    keyMJob.inputOutput.outputLengthPtr = &verifylength;
    keyMJob.inputOutput.outputPtr = (P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR))verifyPtr;

    /* Set rest of parameters to default values */
    keyMJob.keyElementId = 0u;
    keyMJob.secondaryKeyElementId = 0u;
    keyMJob.inputOutput.inputPtr = NULL_PTR;
    keyMJob.inputOutput.inputLength = 0u;

    retVal = Crypto_30_vHsm_ProcessKeyMJob(&keyMJob); /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError((uint16)CRYPTO_30_VHSM_MODULE_ID,
      CRYPTO_30_VHSM_INSTANCE_ID,
      CRYPTO_30_VHSM_SID_CERTIFICATE_VERIFY,
      errorId);
  }
#else
  CRYPTO_30_VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_KeyManagement.c
 *********************************************************************************************************************/
