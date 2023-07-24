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
/*      \file  Crypto_30_vHsm_Jobs.h
 *      \brief  Vector Hardware Security Module Firmware Jobs
 *
 *      \details  Implementation of the Vector Hardware Security Module Firmware Jobs
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_VHSM_JOBS_H)
# define CRYPTO_30_VHSM_JOBS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Crypto_30_vHsm.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
# define Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(objectId, usedBuffer) (&((P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA))Crypto_30_vHsm_GetAddrSharedDataBuffer(0u))[(Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(objectId) + (usedBuffer))]) /* PRQA S 3453 */  /* MD_MSR_FctLikeMacro */
# define Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(objectId) ((uint32)(((uint32)Crypto_30_vHsm_GetSharedDataBufferEndIdxOfObjectInfo(objectId) - (uint32)Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(objectId))*(uint32)4uL)) /* PRQA S 3453 */  /* MD_MSR_FctLikeMacro */

# define Crypto_30_vHsm_GetAddrOutputLengthPtrDataBufferOfObject(objectId) &Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(objectId) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_JOB_MACRO */
# define Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBufferOfObject(objectId) &Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(objectId) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_JOB_MACRO */
# define Crypto_30_vHsm_GetAddrOutput64PtrDataBufferOfObject(objectId) &Crypto_30_vHsm_GetOutput64PtrDataBuffer(objectId) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_JOB_MACRO */
# define Crypto_30_vHsm_GetAddrVerifyPtrDataBufferOfObject(objectId)  &Crypto_30_vHsm_GetVerifyPtrDataBuffer(objectId) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_JOB_MACRO */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

# define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Struct contains all information about the different buffer sizes for different job kinds */
extern CONST(Crypto_30_vHsm_JobResponseBufferSizeType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_JobBufferSize[CRYPTO_30_VHSM_NR_OF_JOBKINDS];

# define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CRYPTO_30_VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ReceiveResponse_CryptoJob()
 *********************************************************************************************************************/
/*!
 * \brief       Receive crypto job response.
 * \details     -
 * \param[in]   jobRequestId        Valid job request Id
 * \param[in]   jobResponseBuffer   Valid job response buffer with at least 8 bytes of storage
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ReceiveResponse_CryptoJob(
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ReceiveResponse_KeyMJob()
 *********************************************************************************************************************/
/*!
 * \brief       Receive key management job response.
 * \details     -
 * \param[in]   jobRequestId        Valid job request Id
 * \param[in]   jobResponseBuffer   Valid job response buffer with at least 4 bytes of storage
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ReceiveResponse_KeyMJob(
  Crypto_30_vHsm_JobRequestIdType jobRequestId,
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size CRYPTO_30_VHSM_CRYPTO_JOBTYPE_SERIALIZED_BUF_SIZE.
 * \param[in]     bufSize               Size of the available buffer
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob(
  uint32 jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  uint32 bufSize
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
# endif
  );

# if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_MacGen()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size CRYPTO_30_VHSM_CRYPTO_JOBTYPE_SERIALIZED_BUF_SIZE.
 * \param[in]     bufSize               Size of the available buffer
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_MacGen(
  uint32 jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  uint32 bufSize
#  if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#  endif
  );
# endif /* (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON) */

# if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_MacVer()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size CRYPTO_30_VHSM_CRYPTO_JOBTYPE_SERIALIZED_BUF_SIZE.
 * \param[in]     bufSize               Size of the available buffer
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_MacVer(
  uint32 jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  uint32 bufSize
#  if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#  endif
  );
# endif /* (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON) */

# if (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_KeyDerive()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a key derive job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size CRYPTO_30_VHSM_CRYPTO_JOBTYPE_SERIALIZED_BUF_SIZE.
 * \param[in]     bufSize               Size of the available buffer
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_KeyDerive(
  uint32 jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  uint32 bufSize);
# endif /* (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_KeyMJob()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a key management job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     keyMJobPtr            Valid pointer to job result object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the key job will be serialized.
 *                                      Must be at least of size CRYPTO_30_VHSM_KEYM_JOBTYPE_SERIALIZED_BUF_SIZE.
 * \param[in]     bufSize               Size of the available buffer
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_KeyMJob(
  uint32 jobRequestId,
  P2CONST(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyMJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  uint32 bufSize);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_KeyMJob_CopyPartial()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a key management job for key element copy partial
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     keyMJobPtr            Valid pointer to job result object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the key job will be serialized.
 *                                      Must be at least of size CRYPTO_30_VHSM_KEYM_JOBTYPE_SERIALIZED_BUF_SIZE.
 * \param[in]     bufSize               Size of the available buffer
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_KeyMJob_CopyPartial(
  uint32 jobRequestId,
  P2CONST(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyMJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  uint32 bufSize);

# define CRYPTO_30_VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* CRYPTO_30_VHSM_JOBS_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Jobs.h
 *********************************************************************************************************************/
