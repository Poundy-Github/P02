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
/*!       \file   FvM.c
 *        \brief  FvM source file
 *
 *      \details  This is the implementation of the Freshness Value Manager.
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

#define FVM_SOURCE
/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* PRQA  S 4304 EOF */ /* MD_MSR_AutosarBoolean */
/* *INDENT-ON* */


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FvM.h"
#include "SchM_FvM.h"
#include "Rte_SecOC.h"

#include "FvM_Lcfg.h"
#include "FvM_PBcfg.h"
#include "FvM_PBcfg.h"
#include "SecOC.h"
#include "SecOC_Cbk.h"
#include "vstdlib.h"

#if (FVM_SYNCMESSAGERECEPTIONTIMEOUTCOUNTER == STD_ON)
# include "Dem.h"
#endif

#if ((FVM_LATESTTRIPCOUNTERWITHOUTRESETCOUNTER == STD_ON) || (FVM_TRIPCOUNTERNVMBLOCKDESCRIPTOR == STD_ON))
# include "NvM.h"
#endif

#if (FVM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of FvM header file */
#if (  (FVM_SW_MAJOR_VERSION != 7u) \
    || (FVM_SW_MINOR_VERSION != 2u) \
    || (FVM_SW_PATCH_VERSION != 0u) )
# error "Vendor specific version numbers of <FvM>.c and <FvM>.h are inconsistent"
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FVM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON) && (FVM_STARTUPCYCLECOUNTER == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetVerifyOverrideStatus
**********************************************************************************************************************/
/*! \brief       Sets all rx freshness values to the passed override status.
 *  \details     -
 *  \pre         -
 *  \param[in]   overrideStatus
 *               0 ==> Override VerifyStatus to "Fail" until further notice.
 *               1 ==> Override VerifyStatus to "Fail" until NumberOfMessagesToOverride of the
 *                     corresponding SecOC processing is reached.
 *               2 ==> Cancel override of VerifyStatus.
 *               40 ==> Override VerifyStatus to "Pass" until further notice.
 *                      Only available if SecOCEnableForcedPassOverride is set to TRUE.
 *               41 ==> Override VerifyStatus to "Pass" until NumberOfMessagesToOverride of the
 *                      corresponding SecOC processing is reached.
 *                      Only available if SecOCEnableForcedPassOverride is set to TRUE.
 *               0x41 ==> Until NumberOfMessagesToOverride is reached, authenticator verification is not performed.
 *                        Only available if SecOCEnableForcedPassOverride is set to TRUE.
 *               0x43 ==> Authenticator verification is not performed until further notice.
 *                        Only available if SecOCEnableForcedPassOverride is set to TRUE.
 *               0x40 ==> Override VerifyStatus to "Pass" until further notice.
 *                        Only available if SecOCEnableForcedPassOverride is set to TRUE.
 *               0x42 ==> Override VerifyStatus to "Pass" until NumberOfMessagesToOverride of the
 *                        corresponding SecOC processing is reached.
 *                        Only available if SecOCEnableForcedPassOverride is set to TRUE.
 *  \context     TASK|ISR2
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetVerifyOverrideStatus(uint8 overrideStatus);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)    /* COV_FVM_VAR_SYNC_MSG_ALWAYS_ON */
/**********************************************************************************************************************
  FvM_FVJaspar_CheckSyncMessageValues
**********************************************************************************************************************/
/*!
 *  \brief      Checks the plausibility of the received sync message values.
    \details    -
    \pre        -
    \param[in]  latestFreshnessValueIdx  freshness value layout info id.
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_CheckSyncMessageValues(FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_CheckTripAndMessageCounter
**********************************************************************************************************************/
/*!
 *  \brief      Checks the plausibility of the received trip and message counter values.
    \details    -
    \pre        -
    \param[in]  latestFreshnessValueIdx  freshness value layout info id.
    \param[in]  previousFreshnessValueIdx  freshness value layout info id.
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_CheckTripAndMessageCounter(FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx, FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FVJaspar_TxProcessing_Jaspar
**********************************************************************************************************************/
/*!
 * \brief      Processes the Jaspar use case
 * \details    -
 * \pre        -
 * \param[in]      SecOCFreshnessValueID      Holds the identifier of the freshness value.
 * \param[out]     SecOCFreshnessValue        Holds the current freshness value.
 * \param[out]     SecOCTruncatedFreshnessValue Holds the truncated freshness to be included into the Secured I-PDU.
 * \param[in,out] SecOCTruncatedFreshnessValueLength  Provides the truncated freshness length configured for this freshness.
 * \return         Std_ReturnType
 *                 E_OK:     request successful
 *                 E_NOT_OK: request failed, a freshness value cannot be provided due to
 *                           general issues for freshness or this FreshnessValueId.
 *                 E_BUSY:   The freshness information can temporarily not be provided
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) SecOC_FVJaspar_TxProcessing_Jaspar(FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType SecOCFreshnessValueID, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue, P2CONST(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValueLength);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FVJaspar_TxProcessing_JasparWithoutResetCounter
**********************************************************************************************************************/
/*!
 * \brief      Processes the Jaspar use case
 * \details    -
 * \pre        -
 * \param[in]      SecOCFreshnessValueID      Holds the identifier of the freshness value.
 * \param[out]     SecOCFreshnessValue        Holds the current freshness value.
 * \param[out]     SecOCTruncatedFreshnessValue Holds the truncated freshness to be included into the Secured I-PDU.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) SecOC_FVJaspar_TxProcessing_JasparWithoutResetCounter(FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType SecOCFreshnessValueID, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue);
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON) || (FVM_TXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetTripCounter
**********************************************************************************************************************/
/*!
 *  \brief      Sets the Trip Counter Value.
    \details    -
    \pre        -
    \param[in]  freshnessValueLayoutId  freshness value layout info id.
    \param[in]  TripCounterValue        trip counter value
    \param[in]  tripCounterBitSize      trip counter bit size
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetTripCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 TripCounterValue, uint8 tripCounterBitSize);
#endif

#if((FVM_TXFRESHNESSVALUEINFO == STD_ON) || (FVM_RXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripCounter
**********************************************************************************************************************/
/*!
 * \brief      Returns the Trip Counter Value.
    \details   -
    \pre       -
    \param[in] freshnessValueLayoutId  freshness value layout info id.
    \param[in] tripCounterBitSize      trip counter bit size
    \return    trip counter value.
 */
LOCAL_INLINE FUNC(uint32, FVM_CODE) FvM_FVJaspar_GetTripCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint8 tripCounterBitSize);
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetResetCounter
**********************************************************************************************************************/
/*!
 * \brief      Sets the Reset Counter Value.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  ResetCounterValue       reset counter value
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetResetCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint64 ResetCounterValue);
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetCounter
**********************************************************************************************************************/
/*!
 * \brief      Returns the Reset Counter Value.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \return     reset counter value.
 */
LOCAL_INLINE FUNC(uint64, FVM_CODE) FvM_FVJaspar_GetResetCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId);
#endif

#if ((FVM_TXFRESHNESSVALUEINFO ==  STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetMessageCounter
**********************************************************************************************************************/
/*!
 * \brief      Sets the Message Counter Value.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  MessageCounterValue     message counter value
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetMessageCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 MessageCounterValue);
#endif

#if((FVM_TXFRESHNESSVALUEINFO == STD_ON) || (FVM_RXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetMessageCounter
**********************************************************************************************************************/
/*!
 * \brief      Returns the Message Counter Value.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \return     message counter value.
 */
LOCAL_INLINE FUNC(uint32, FVM_CODE) FvM_FVJaspar_GetMessageCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId);
#endif

#if (FVM_TXFRESHNESSVALUEINFO ==  STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_IncMessageCounter
**********************************************************************************************************************/
/*!
 * \brief      Increments the Message Counter Value.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  freshnessValueInfoIDx   freshness value id.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_IncMessageCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, FvM_SizeOfTxFreshnessValueInfoType freshnessValueInfoIDx);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_MessageCounterCarryProcessing
**********************************************************************************************************************/
/*!
 * \brief      Does Carry processing for the truncated Message Counter Value.
   \details    -
   \pre        -
   \param[in]  freshnessValueInfoId  freshness value id
   \return     E_OK       carry processing was successful.
               E_NOT_OK   carry processing failed.
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_MessageCounterCarryProcessing(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO ==  STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_SetResetFlag
**********************************************************************************************************************/
/*!
 * \brief      Sets the reset flag.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  ResetCounterValue       reset counter value
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetResetFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint64 ResetCounterValue);
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetFlagValueMask
**********************************************************************************************************************/
/*!
 * \brief      Get the reset flag value mask.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \return     reset flag value mask.
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetResetFlagValueMask(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId);
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetFlagOfResetCounter
**********************************************************************************************************************/
/*!
 * \brief      Get the reset flag of the the passed reset counter.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  ResetCounterValue       reset counter value
   \return     reset flag value.
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetResetFlagOfResetCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint64 ResetCounterValue);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetFlag
**********************************************************************************************************************/
/*!
 * \brief      Returns the Reset Flag Value.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \return     reset flag value.
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetResetFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId);
#endif

#if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO  == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripFlagOfTripCounter
**********************************************************************************************************************/
/*!
 * \brief      Returns the trip flag of the passed trip counter
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  TripCounterValue        trip counter value.
   \return     trip flag value.
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetTripFlagOfTripCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 TripCounterValue);
#endif

#if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO  == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripFlagValueMask
**********************************************************************************************************************/
/*!
 * \brief      Returns the mask of the trip flag.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \return     trip flag mask.
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetTripFlagValueMask(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId);
#endif

#if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO ==  STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_SetTripFlag
**********************************************************************************************************************/
/*!
 * \brief      Sets the trip flag to the buffer.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  TripCounterValue        Trip Counter Value.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetTripFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 TripCounterValue);
#endif

#if ((FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO == STD_ON) && (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripFlag
**********************************************************************************************************************/
/*!
 * \brief      Read trip flag from the buffer.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \return     trip flag.
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetTripFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId);
#endif

#if(FVM_TXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetLengthInBytes
**********************************************************************************************************************/
/*!
 * \brief      Returns the length in full bytes
   \details    -
   \pre        -
   \param[in]  lengthInBits  the length in bits
   \return     the length in full bytes
 */
LOCAL_INLINE FUNC(uint32, FVM_CODE) FvM_FVJaspar_GetLengthInBytes(uint32 lengthInBits);
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_CopyTruncFreshnessValueToBuffer
**********************************************************************************************************************/
/*!
 * \brief      Copies truncated freshness value to the freshness verify value buffer.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[in]  truncatedFreshnessValue truncated freshness value
   \param[in]  truncatedFreshnessBitLength truncated freshness value length in bit.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_CopyTruncFreshnessValueToBuffer(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessBitLength);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_CopyFreshnessVerifyValueToTruncFreshnessValue
**********************************************************************************************************************/
/*!
 * \brief      Copies freshness verify value to truncated freshness value buffer.
   \details    -
   \pre        -
   \param[in]  freshnessValueLayoutId  freshness value layout info id.
   \param[out] truncatedFreshnessValue truncated freshness value
   \param[in]  truncatedFreshnessBitLength truncated freshness value length in bit.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_CopyFreshnessVerifyValueToTruncFreshnessValue(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessBitLength);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxFreshnessVerifyValueLatestPreviousCompare
**********************************************************************************************************************/
/*!
 * \brief      Compares the Latest received with the Previous Trip/Rest Counter and updates the freshness verify value.
   \details    -
   \pre        -
   \param[in]  freshnessValueInfoId    freshness value info id.
   \param[in]  latestResetCounterWithOffset  offset that is taken into account if latest and previous Trip/Rest Counter are compared.
   \return     E_OK, if freshness verify value was updated and E_NOT_OK if not freshness verify value was not updated.
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxFreshnessVerifyValueLatestPreviousCompare(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint64 latestResetCounterWithOffset);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetPositiveOffestOfResetCounter
**********************************************************************************************************************/
/*!
 * \brief      Adds the offset to the reset counter with overflow protection.
   \details    -
   \pre        -
   \param[in]  offset                  offset value.
   \return     result value of calculation.
 */
LOCAL_INLINE FUNC(uint64, FVM_CODE) FvM_FVJaspar_GetPositiveOffestOfResetCounter(uint8 offset);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetNegativeOffestOfResetCounter
**********************************************************************************************************************/
/*!
s* \brief      Subtracts the offset of the reset counter with overflow protection.
   \details    -
   \pre        -
   \param[in]  offset                  offset value.
   \return     result value of calculation.
 */
LOCAL_INLINE FUNC(uint64, FVM_CODE) FvM_FVJaspar_GetNegativeOffestOfResetCounter(uint8 offset);
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxFreshnessVerifyValueCalculation
**********************************************************************************************************************/
/*!
 * \brief      Does the Rx freshness verify value calculation.
   \details    -
   \pre        -
   \param[in]  freshnessValueInfoId    freshness value info id.
   \param[in]  offset                  offset value.
   \param[in]  negate                  TRUE  -> the negative offset is used.
                                       FALSE -> the positive offset is used.
   \return     E_OK, if successful and E_NOT_OK if not successful.
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxFreshnessVerifyValueCalculation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint8 offset, boolean negate);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxTripFlagEvaluation
**********************************************************************************************************************/
/*!
 * \brief      Evaluates the received Trip Flag
   \details    -
   \pre        -
   \param[in]  freshnessValueInfoId    freshness value info id.
   \param[in]  SecOCAuthVerifyAttempts Authentication Verify Attempts parameter.
   \return     E_OK, if successful and E_NOT_OK if not successful.
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxTripFlagEvaluation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint16 SecOCAuthVerifyAttempts);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoAttemptsEvaluation
**********************************************************************************************************************/
/*!
 * \brief      Evaluates the attempts counter and calculates the freshness value.
   \details    -
   \pre        -
   \param[in]  freshnessValueInfoId    freshness value info id.
   \param[in]  SecOCAuthVerifyAttempts Authentication Verify Attempts parameter.
   \param[in]  offset                  offset for the freshness value calculation.
   \param[in]  firstAttempt            TRUE if the first attempt is negated.
   \param[in]  secondAttempt           TRUE if the second attempt is negated.
   \return     E_OK, if successful and E_NOT_OK if not successful.
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoAttemptsEvaluation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint16 SecOCAuthVerifyAttempts, uint8 offset, boolean firstAttempt, boolean secondAttempt);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxResetFlagEvaluation
**********************************************************************************************************************/
/*!
 * \brief      Evaluates the received Rest Flag
   \details    -
   \pre        -
   \param[in]  freshnessValueInfoId    freshness value info id.
   \param[in]  SecOCAuthVerifyAttempts Authentication Verify Attempts parameter.
   \return     E_OK, if successful and E_NOT_OK if not successful.
   \trace      SPEC-2983913
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxResetFlagEvaluation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint16 SecOCAuthVerifyAttempts);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_SyncMessageVerificationStatusCallout
**********************************************************************************************************************/
/*!
 * \brief      Process the verification status callout for the sync messages.
   \details    -
   \pre        -
   \param[in]  verificationStatus    verification status.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_SyncMessageVerificationStatusCallout(SecOC_VerificationStatusType verificationStatus);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_JasparVerificationStatusCallout
**********************************************************************************************************************/
/*!
 * \brief      Process the verification status callout for the Jaspar messages.
   \details    -
   \pre        -
   \param[in]  verificationStatus    verification status.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_JasparVerificationStatusCallout(SecOC_VerificationStatusType verificationStatus);
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_JasparWithoutRestCounterVerificationStatusCallout
**********************************************************************************************************************/
/*!
 * \brief      Process the verification status callout for the Jaspar Without Reset Counter messages.
   \details    -
   \pre        -
   \param[in]  verificationStatus    verification status.
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_JasparWithoutRestCounterVerificationStatusCallout(SecOC_VerificationStatusType verificationStatus);
#endif

#if (FVM_RESETCOUNTERCYCLETIMECOUNTER == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_CopySrcToDest
**********************************************************************************************************************/
/*! \brief          Copies the data form the source value to the dest buffer.
 *  \details  -
 *  \param[in]      srcValue     source value
 *  \param[out]     destBuffer   destination buffer
 *  \param[in]      copyBitLen   length in bits.
 *  \param[in]      destBitOffset   dest bit in byte offset.
 *  \pre             Module must be initialized
 *  \context      TASK|ISR2
 *  \synchronous TRUE
 *  \reentrant  TRUE
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_CopySrcToDest(uint64 srcValue, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) destBuffer, uint16 copyBitLen, uint8 destBitOffset);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON) || (FVM_TXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetTripCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetTripCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 TripCounterValue, uint8 tripCounterBitSize)
{
  uint32 TripCounterValueIntern = TripCounterValue;
  uint8 bitsToCopy = tripCounterBitSize;
  FvM_FreshnessValueArrayIterType interVal = (FvM_FreshnessValueArrayIterType) FvM_GetFreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  for(; interVal > FvM_GetFreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); interVal--)
  {
    FvM_FreshnessValueArrayIterType destIdx = interVal - 1u;
    if((bitsToCopy % 8u) != 0u) /* COV_FVM_TRIP_COUNTER_BIT_COUNT */
    {
      uint8 remainingBits = (bitsToCopy % 8u);
      uint8 offset = 8u - remainingBits;
      uint8 tripCounterValueMask = 255u >> offset;
      uint8 unUsedBitsMask = 255u >> remainingBits;

      uint8 copyByte = (uint8) (TripCounterValueIntern & tripCounterValueMask) << offset;
      copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & unUsedBitsMask));

      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */

      TripCounterValueIntern = TripCounterValueIntern >> remainingBits;
      bitsToCopy = bitsToCopy - remainingBits;
    }
    else
    {
      uint8 copyByte = (uint8) (TripCounterValueIntern & 255u);
      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */
      TripCounterValueIntern = TripCounterValueIntern >> 8u;
      bitsToCopy = bitsToCopy - 8u;
    }
  }
}
#endif

#if((FVM_TXFRESHNESSVALUEINFO == STD_ON) || (FVM_RXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint32, FVM_CODE) FvM_FVJaspar_GetTripCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint8 tripCounterBitSize)
{
  uint32 TripCounterValue = 0u;
  uint8 bitsToCopy = tripCounterBitSize;
  FvM_FreshnessValueArrayIterType srcIdx = (FvM_FreshnessValueArrayIterType) FvM_GetFreshnessValueArrayTripCounterStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  for(; srcIdx < FvM_GetFreshnessValueArrayTripCounterEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); srcIdx++)
  {
    uint8 copyByte = 0u;
    if((bitsToCopy / 8u) > 0u)  /* COV_FVM_TRIP_COUNTER_BIT_COUNT */
    {
      copyByte = FvM_GetFreshnessValueArray(srcIdx);
      TripCounterValue = TripCounterValue << 8u;
      bitsToCopy = bitsToCopy - 8u;
    }
    else if(bitsToCopy > 0u)    /* COV_FVM_TRIP_COUNTER_BIT_COUNT */
    {
      uint8 unUsedBits = 8u - bitsToCopy;
      uint8 usedBitsLastByteMask = 255u << unUsedBits;

      copyByte = (uint8) (FvM_GetFreshnessValueArray(srcIdx) & usedBitsLastByteMask) >> unUsedBits;
      TripCounterValue = TripCounterValue << bitsToCopy;

      bitsToCopy = 0u;
    }
    else        /* COV_FVM_MISRA */
    {
      /* do nothing */
    }
    TripCounterValue = TripCounterValue + copyByte;
  }
  return TripCounterValue;
}
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetResetCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetResetCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint64 ResetCounterValue)
{
  uint64 ResetCounterValueIntern = ResetCounterValue;
  FvM_ResetCounterBitSizeType bitsToCopy = FvM_GetResetCounterBitSize();
  FvM_FreshnessValueArrayIterType interVal = FvM_GetFreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
# if (FVM_RESETCOUNTERFIRSTBITCOUNT ==  STD_ON)
  FvM_ResetCounterFirstBitCountType firstBitCount = FvM_GetResetCounterFirstBitCount();
# endif
# if (FVM_RESETCOUNTERLASTBITCOUNT == STD_ON)
  FvM_ResetCounterLastBitCountType lastBitCount = FvM_GetResetCounterLastBitCount();
# endif

  for(; interVal > FvM_GetFreshnessValueArrayResetCounterStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); interVal--)
  {
    FvM_FreshnessValueArrayIterType destIdx = interVal - 1u;
# if (FVM_RESETCOUNTERLASTBITCOUNT == STD_ON)
    if(lastBitCount != 0u)
    {
      uint8 unUsedBits = 8u - lastBitCount;
      uint8 resetCounterValueMask = 255u >> unUsedBits;
      uint8 unUsedBitsMask = 255u >> lastBitCount;

      uint8 copyByte = (uint8) (ResetCounterValueIntern & resetCounterValueMask) << unUsedBits;
      copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & unUsedBitsMask));
      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */

      ResetCounterValueIntern = ResetCounterValueIntern >> lastBitCount;
      bitsToCopy = bitsToCopy - lastBitCount;
      lastBitCount = 0u;
    }
    else
# endif
    if((bitsToCopy / 8u) > 0u)  /* COV_FVM_RESET_COUNTER_BIT_COUNT */
    {
      uint8 copyByte = (uint8) (ResetCounterValueIntern & 255u);
      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */
      ResetCounterValueIntern = ResetCounterValueIntern >> 8u;
      bitsToCopy = bitsToCopy - 8u;
    }
# if(FVM_RESETCOUNTERFIRSTBITCOUNT == STD_ON)
    else if(firstBitCount != 0u)        /* COV_FVM_RESET_COUNTER_BIT_COUNT */
    {
      uint8 unUsedBits = 8u - firstBitCount;
      uint8 resetCounterValueMask = 255u >> unUsedBits;
      uint8 unUsedBitsMask = 255u << firstBitCount;

      uint8 copyByte = (uint8) (ResetCounterValueIntern & resetCounterValueMask);
      copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & unUsedBitsMask));
      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */

      ResetCounterValueIntern = ResetCounterValueIntern >> firstBitCount;
      bitsToCopy = (FvM_ResetCounterBitSizeType) bitsToCopy - firstBitCount;
      firstBitCount = 0u;
    }
# endif
    else        /* COV_FVM_MISRA */
    {
      /* do nothing */
    }
  }
}
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint64, FVM_CODE) FvM_FVJaspar_GetResetCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId)
{
  uint64 ResetCounterValue = 0;
  FvM_ResetCounterBitSizeType bitsToCopy = FvM_GetResetCounterBitSize();
  FvM_FreshnessValueArrayIterType srcIdx = FvM_GetFreshnessValueArrayResetCounterStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
# if (FVM_RESETCOUNTERFIRSTBITCOUNT ==  STD_ON)
  FvM_ResetCounterFirstBitCountType firstBitCount = FvM_GetResetCounterFirstBitCount();
# endif
# if (FVM_RESETCOUNTERLASTBITCOUNT == STD_ON)
  FvM_ResetCounterLastBitCountType lastBitCount = FvM_GetResetCounterLastBitCount();
# endif

  for(; srcIdx < FvM_GetFreshnessValueArrayResetCounterEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); srcIdx++)
  {
    uint8 copyByte = 0u;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
# if (FVM_RESETCOUNTERFIRSTBITCOUNT ==  STD_ON)
    if(firstBitCount != 0u)
    {
      uint8 unUsedBits = 8u - firstBitCount;
      uint8 usedBitsMask = 255u >> unUsedBits;

      copyByte = (uint8) (FvM_GetFreshnessValueArray(srcIdx) & usedBitsMask);
      bitsToCopy = (FvM_ResetCounterBitSizeType) bitsToCopy - firstBitCount;
      firstBitCount = 0u;
    }
    else
# endif
    if((bitsToCopy / 8u) > 0u)  /* COV_FVM_RESET_COUNTER_BIT_COUNT */
    {
      copyByte = FvM_GetFreshnessValueArray(srcIdx);

      ResetCounterValue = ResetCounterValue << 8u;
      bitsToCopy = bitsToCopy - 8u;
    }
# if (FVM_RESETCOUNTERLASTBITCOUNT == STD_ON)
    else if(lastBitCount != 0u) /* PRQA S 2991, 2995 */ /* MD_FvM_2991, MD_FvM_2995 */ /* COV_FVM_RESET_COUNTER_BIT_COUNT */
    {
      uint8 unUsedBits = 8u - lastBitCount;
      uint8 usedBitsMask = 255u << unUsedBits;

      copyByte = (uint8) (FvM_GetFreshnessValueArray(srcIdx) & usedBitsMask) >> unUsedBits;
      ResetCounterValue = ResetCounterValue << bitsToCopy;

      bitsToCopy = 0u;
    }
# endif
    else        /* COV_FVM_MISRA */
    {
      /* do nothing */
    }
    ResetCounterValue = ResetCounterValue + copyByte;
  }
  return ResetCounterValue;
}
#endif

#if ((FVM_TXFRESHNESSVALUEINFO ==  STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetMessageCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetMessageCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 MessageCounterValue)
{
  uint32 MessageCounterValueIntern = MessageCounterValue;
  FvM_MessageCounterBitSizeOfFreshnessValueLayoutInfoType bitsToCopy = FvM_GetMessageCounterBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  FvM_FreshnessValueArrayIterType interVal = FvM_GetFreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
#if (FVM_FIRSTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
  FvM_FirstUsedBitsOfMessageCounterOfFreshnessValueLayoutInfoType firstBitCount = FvM_GetFirstUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
#endif
#if (FVM_LASTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
  FvM_LastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfoType lastBitCount = FvM_GetLastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
#endif


#if (FVM_LATESTTRIPCOUNTER  == STD_ON)
  /* zw: GW00204964
    * AUTOSAR: <AUTOSAR_SWS_SecureOnboardCommunication.pdf> 11.4.1 - 2.Slave ECU
    * 		At the maximum value of the reset counter
    *			The sender ECU generates an authenticator by fixing the message counter to the maximum value.
    * 			The receiver ECU verifies the authenticator by overwriting the message counter with the maximum value.
    *		At the maximum value of the message counter
    *			The sender ECU generates an authenticator by fixing the message counter to the maximum value.
    *			The receiver ECU verifies the authenticator by overwriting the message counter with the maximum value.
    *
    * GW SECOC: <V3.5_SRS_SWR75_Secoc_V1.9_20210630.pdf>  5.1 - (2) SALVE FVM:
    *		b.At the maximum value of the reset counter
    *			At the maximum value of the reset counter The sender ECU generates an authenticator by fixing the message counter to the maximum value.
    *		c.At the maximum value of the message counter
    *			The sender ECU generates an authenticator by fixing the message counter to the maximum value.
  */
  // if(FvM_FVJaspar_GetResetCounter(freshnessValueLayoutId) == FvM_GetResetCounterMax()) /* COV_FVM_REST_COUNTER_MAX_IN_MASTER_CONF */
  // {
  //   MessageCounterValueIntern = FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(freshnessValueLayoutId); /*GWM SPECIAL REQURST*/
  // }
#endif

  for(; interVal > FvM_GetFreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); interVal--)
  {
    FvM_FreshnessValueArrayIterType destIdx = interVal - 1u;
#if (FVM_LASTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
    if(lastBitCount != 0u)
    {
      uint8 unUsedBits = 8u - lastBitCount;
      uint8 messageCounterValueMask = 255u >> unUsedBits;
      uint8 unUsedBitsMask = 255u >> lastBitCount;

      uint8 copyByte = (uint8) (MessageCounterValueIntern & messageCounterValueMask) << unUsedBits;
      copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & unUsedBitsMask));
      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */

      MessageCounterValueIntern = MessageCounterValueIntern >> lastBitCount;
      bitsToCopy = bitsToCopy - lastBitCount;
      lastBitCount = 0u;
    }
    else
#endif
    if((bitsToCopy / 8u) > 0u)  /* COV_FVM_MESSAGE_COUNTER_BIT_COUNT */
    {
      uint8 copyByte = (uint8) MessageCounterValueIntern & 255u;        /* PRQA S 2985 */ /* MD_FvM_2985 */
      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */
      MessageCounterValueIntern = MessageCounterValueIntern >> 8;
      bitsToCopy = bitsToCopy - 8u;
    }
#if (FVM_FIRSTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
    else if(firstBitCount != 0u)        /* COV_FVM_MESSAGE_COUNTER_BIT_COUNT */
    {
      uint8 unUsedBits = 8u - firstBitCount;
      uint8 messageCounterValueMask = 255u >> unUsedBits;
      uint8 unUsedBitsMask = 255u << firstBitCount;

      uint8 copyByte = (uint8) (MessageCounterValueIntern & messageCounterValueMask);
      copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & unUsedBitsMask));
      FvM_SetFreshnessValueArray(destIdx, copyByte);    /* SBSW_FVM_CSL03 */

      MessageCounterValueIntern = MessageCounterValueIntern >> firstBitCount;
      bitsToCopy = (FvM_MessageCounterBitSizeOfFreshnessValueLayoutInfoType) bitsToCopy - firstBitCount;
      firstBitCount = 0u;
    }
#endif
    else        /* COV_FVM_MISRA */
    {
      /* do nothing */
    }
  }
}
#endif

#if((FVM_TXFRESHNESSVALUEINFO == STD_ON) || (FVM_RXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetMessageCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint32, FVM_CODE) FvM_FVJaspar_GetMessageCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId)
{
  uint32 MessageCounterValue = 0u;
  FvM_MessageCounterBitSizeOfFreshnessValueLayoutInfoType bitsToCopy = FvM_GetMessageCounterBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
  FvM_FreshnessValueArrayIterType srcIdx = FvM_GetFreshnessValueArrayMessageCounterStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
#if (FVM_FIRSTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
  FvM_FirstUsedBitsOfMessageCounterOfFreshnessValueLayoutInfoType firstBitCount = FvM_GetFirstUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
#endif
#if (FVM_LASTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
  FvM_LastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfoType lastBitCount = FvM_GetLastUsedBitsOfMessageCounterOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
#endif

  for(; srcIdx < FvM_GetFreshnessValueArrayMessageCounterEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); srcIdx++)
  {
    uint8 copyByte = 0u;
#if (FVM_FIRSTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
    if(firstBitCount != 0u)
    {
      uint8 unUsedBits = (uint8) (8u - firstBitCount);
      uint8 usedBitsFirstByteMask = 255u >> unUsedBits;

      copyByte = (uint8) (FvM_GetFreshnessValueArray(srcIdx) & usedBitsFirstByteMask);
      bitsToCopy = (FvM_MessageCounterBitSizeOfFreshnessValueLayoutInfoType) bitsToCopy - firstBitCount;
      firstBitCount = 0u;
    }
    else
#endif
    if((bitsToCopy / 8u) > 0u)  /* COV_FVM_MESSAGE_COUNTER_BIT_COUNT */
    {
      {
        copyByte = FvM_GetFreshnessValueArray(srcIdx);
      }

      MessageCounterValue = MessageCounterValue << 8u;
      bitsToCopy = bitsToCopy - 8u;
    }
#if (FVM_LASTUSEDBITSOFMESSAGECOUNTEROFFRESHNESSVALUELAYOUTINFO == STD_ON)
    else if(lastBitCount != 0u) /* COV_FVM_MESSAGE_COUNTER_BIT_COUNT */
    {
      uint8 unUsedBits = 8u - lastBitCount;
      uint8 usedBitsLastByteMask = 255u << unUsedBits;

      copyByte = (uint8) ((FvM_GetFreshnessValueArray(srcIdx) & usedBitsLastByteMask) >> unUsedBits);
      MessageCounterValue = MessageCounterValue << lastBitCount;

      lastBitCount = 0u;
      bitsToCopy = 0u;
    }
#endif
    else        /* COV_FVM_MISRA */
    {
      /* do nothing */
    }
    MessageCounterValue = MessageCounterValue + copyByte;
  }
  return MessageCounterValue;
}
#endif

#if (FVM_TXFRESHNESSVALUEINFO ==  STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_IncMessageCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_IncMessageCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, FvM_SizeOfTxFreshnessValueInfoType freshnessValueInfoIDx)
{
  uint32 MessageCounterValue = FvM_FVJaspar_GetMessageCounter(freshnessValueLayoutId);
  if(MessageCounterValue != FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(freshnessValueLayoutId))
  {
    MessageCounterValue++;
    FvM_FVJaspar_SetMessageCounter(freshnessValueLayoutId, MessageCounterValue);
# if ((FVM_TXMESSAGECOUNTERMAXNOTIFICATION == STD_ON) || (FVM_TXMESSAGECOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION == STD_ON))
    if(MessageCounterValue == FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(freshnessValueLayoutId))
    {
      switch (FvM_GetProcessingTypeOfTxFreshnessValueInfo(freshnessValueInfoIDx))
      {
#  if (FVM_TXMESSAGECOUNTERMAXNOTIFICATION == STD_ON)
        case FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO:
          FvM_GetTxMessageCounterMaxNotification(0) (FvM_GetTxProcessingInfoIdxOfTxFreshnessValueInfo(freshnessValueInfoIDx)); /* SBSW_FVM_CSL_FCT_PTR */
          break;
#  endif
#  if (FVM_TXMESSAGECOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION == STD_ON)
        case FVM_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO:
          FvM_GetTxMessageCounterWithoutResetCounterMaxNotification(0) (FvM_GetTxProcessingInfoIdxOfTxFreshnessValueInfo(freshnessValueInfoIDx));      /* SBSW_FVM_CSL_FCT_PTR */
          break;
#  endif
        default:       /* COV_FVM_MISRA */
          /* do nothing */
          break;
      }
    }
# endif
  }
  FVM_DUMMY_STATEMENT(freshnessValueInfoIDx);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_MessageCounterCarryProcessing
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_MessageCounterCarryProcessing(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId)
{
  Std_ReturnType ret = E_OK;
  FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(freshnessValueInfoId);
  FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(freshnessValueInfoId);
  uint32 previousMessageCounter = FvM_FVJaspar_GetMessageCounter(previousFreshnessValueIdx);
  uint32 latestMessageCounter = FvM_FVJaspar_GetMessageCounter(latestFreshnessValueIdx);
  if((latestMessageCounter <= previousMessageCounter) && (latestMessageCounter != FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)))
  {
    latestMessageCounter = latestMessageCounter + FvM_GetMessageCounterHighBitsIncValueOfRxFreshnessValueInfo(freshnessValueInfoId);
    if(latestMessageCounter > FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(latestFreshnessValueIdx))
    {
      ret = E_NOT_OK;
    }
    else
    {
      FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx, latestMessageCounter);
    }
  }
  return ret;
}
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO ==  STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_SetResetFlag
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetResetFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint64 ResetCounterValue)
{
  FvM_FreshnessValueArrayIterType destIdx = FvM_GetFreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
  uint8 copyByte = FvM_FVJaspar_GetResetFlagOfResetCounter(freshnessValueLayoutId, ResetCounterValue);

  copyByte = copyByte << FvM_GetResetFlagEndPaddingBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
  copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & FvM_GetResetFlagUnUsedBitMaskOfFreshnessValueLayoutInfo(freshnessValueLayoutId)));
  FvM_SetFreshnessValueArray(destIdx, copyByte);        /* SBSW_FVM_CSL03 */
}
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetFlagValueMask
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetResetFlagValueMask(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId)
{
  FvM_ResetFlagBitSizeOfFreshnessValueLayoutInfoType bitCount = FvM_GetResetFlagBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  uint8 unUsedBits = 8u - bitCount;
  uint8 resetFlagValueMask = 255u >> unUsedBits;

  FVM_DUMMY_STATEMENT(freshnessValueLayoutId);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint !e438 */
  return resetFlagValueMask;
}
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetFlagOfResetCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetResetFlagOfResetCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint64 ResetCounterValue)
{
  uint8 resetFlagValueMask = FvM_FVJaspar_GetResetFlagValueMask(freshnessValueLayoutId);
  uint8 resetFlag = (uint8) (ResetCounterValue & resetFlagValueMask);
  return resetFlag;
}
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetResetFlag
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetResetFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId)
{
  FvM_FreshnessValueArrayIterType srcIdx = FvM_GetFreshnessValueArrayResetFlagIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  uint8 resetFlag = FvM_GetFreshnessValueArray(srcIdx) & FvM_GetResetFlagCopyBitMaskOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
  resetFlag = resetFlag >> FvM_GetResetFlagEndPaddingBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  return resetFlag;
}
#endif

#if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO  == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripFlagOfTripCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetTripFlagOfTripCounter(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 TripCounterValue)
{
  uint8 tripFlagValueMask = FvM_FVJaspar_GetTripFlagValueMask(freshnessValueLayoutId);
  uint8 tripFlag = (uint8) (TripCounterValue & tripFlagValueMask);
  return tripFlag;
}
#endif

#if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO  == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripFlagValueMask
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetTripFlagValueMask(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId)
{
  FvM_TripFlagSizeOfFreshnessValueLayoutInfoType bitCount = FvM_GetTripFlagSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  uint8 unUsedBits = 8u - bitCount;
  uint8 tripFlagValueMask = 255u >> unUsedBits;

  FVM_DUMMY_STATEMENT(freshnessValueLayoutId);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint !e438 */
  return tripFlagValueMask;
}
#endif

#if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO ==  STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_SetTripFlag
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetTripFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, uint32 TripCounterValue)
{
  if(FvM_IsFreshnessValueArrayTripFlagUsedOfFreshnessValueLayoutInfo(freshnessValueLayoutId))   /* PRQA S 2991 */ /* MD_FvM_2991 */
  {
    FvM_FreshnessValueArrayIterType destIdx = FvM_GetFreshnessValueArrayTripFlagIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
    uint8 copyByte = FvM_FVJaspar_GetTripFlagOfTripCounter(freshnessValueLayoutId, TripCounterValue);

    copyByte = copyByte << FvM_GetEndPaddingBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
    copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & FvM_GetTripFlagUnUsedBitMaskOfFreshnessValueLayoutInfo(freshnessValueLayoutId)));
    FvM_SetFreshnessValueArray(destIdx, copyByte);      /* SBSW_FVM_CSL03 */
  }
}
#endif

#if ((FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO == STD_ON) && (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_GetTripFlag
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint8, FVM_CODE) FvM_FVJaspar_GetTripFlag(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId)
{
  FvM_FreshnessValueArrayIterType srcIdx = FvM_GetFreshnessValueArrayTripFlagIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  uint8 tripFlag = FvM_GetFreshnessValueArray(srcIdx) & FvM_GetTripFlagCopyBitMaskOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
  tripFlag = tripFlag >> FvM_GetEndPaddingBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  return tripFlag;
}
#endif

#if(FVM_TXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetLengthInBytes
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint32, FVM_CODE) FvM_FVJaspar_GetLengthInBytes(uint32 lengthInBits)
{
  uint32 fullBytes = lengthInBits >> 3u;
  if((lengthInBits & 7u) != 0u) /* COV_FVM_BYTE_LENGTH */
  {
    fullBytes++;
  }
  return fullBytes;
}
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO  == STD_ON) || (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_CopyTruncFreshnessValueToBuffer
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_CopyTruncFreshnessValueToBuffer(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessBitLength)
{
  FvM_FreshnessValueArrayIterType destIdx = FvM_GetFreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  uint8 bitOffset = FvM_GetEndPaddingBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
  uint8 unUsedBits = 8u - bitOffset;
  uint8 srcIdx = 0u;
  uint8 copyByte = 0u;          /* PRQA S 2981 */ /* MD_MSR_RetVal */
  for(; destIdx < FvM_GetFreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId); destIdx++)
  {
    if((bitOffset != 0u) || ((truncatedFreshnessBitLength & 7u) != 0u)) /* COV_FVM_TX_ONLY_CONF_TX_tx_xx */
    {
      copyByte = (uint8) (truncatedFreshnessValue[srcIdx] << bitOffset);
      if((destIdx + 1u) < FvM_GetFreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId))
      {
        copyByte = (uint8) (copyByte | (truncatedFreshnessValue[srcIdx + 1u] >> unUsedBits));
      }
      else if((truncatedFreshnessBitLength + bitOffset) < 8u)   /* COV_FVM_TX_ONLY_CONF_XF */
      {
        uint8 startOffset = (uint8) (8u - (truncatedFreshnessBitLength + bitOffset));
        uint8 trucFvMask = (uint8) (255u >> startOffset);
        uint8 fvVerifyMaks = (uint8) (255u << (truncatedFreshnessBitLength + bitOffset));

        copyByte = (uint8) (copyByte & trucFvMask);
        copyByte = (uint8) (copyByte | (FvM_GetFreshnessValueArray(destIdx) & fvVerifyMaks));
      }
      else      /* COV_FVM_MISRA */
      {
        /* do nothing */
      }
    }
    else
    {
      copyByte = truncatedFreshnessValue[srcIdx];
    }
    FvM_SetFreshnessValueArray(destIdx, copyByte);      /* SBSW_FVM_CSL03 */
    srcIdx++;
  }
}
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_CopyFreshnessVerifyValueToTruncFreshnessValue
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_CopyFreshnessVerifyValueToTruncFreshnessValue(FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessBitLength)
{
  FvM_FreshnessValueArrayIterType srcIdx = FvM_GetFreshnessValueArrayTruncatedFreshnessValueStartIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId);

  uint8 bitOffset = FvM_GetEndPaddingBitSizeOfFreshnessValueLayoutInfo(freshnessValueLayoutId);
  uint8 unUsedBits = 8u - bitOffset;
  uint8 copyByte = 0u;          /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint32 destIdx = 0u;
  uint32 destByteLength = FvM_FVJaspar_GetLengthInBytes(truncatedFreshnessBitLength);

  for(; destIdx < destByteLength; destIdx++)
  {
    if((bitOffset != 0u) || ((truncatedFreshnessBitLength & 7u) != 0u)) /* COV_FVM_TRUNC_FRESHNESS_COPY_TX_tx_xx */ /* PRQA S 2995, 2991 */ /* MD_FvM_2995, MD_FvM_2991 */
    {
      copyByte = (uint8) (FvM_GetFreshnessValueArray(srcIdx) >> bitOffset);
      if((srcIdx + 1u) < FvM_GetFreshnessValueArrayTruncatedFreshnessValueEndIdxOfFreshnessValueLayoutInfo(freshnessValueLayoutId))
      {
        copyByte = (uint8) (copyByte | ((uint8) (FvM_GetFreshnessValueArray(srcIdx + 1u) << unUsedBits)));
      }
      else if((truncatedFreshnessBitLength + bitOffset) < 8u)   /* COV_FVM_TRUNC_FRESHNESS_COPY_XF */
      {
        uint8 startOffset = (uint8) (8u - (truncatedFreshnessBitLength + bitOffset));
        uint8 trucFvMask = (uint8) (255u >> startOffset);
        uint8 fvVerifyMaks = (uint8) (255u << (truncatedFreshnessBitLength + bitOffset));

        copyByte = (uint8) (copyByte & trucFvMask);
        copyByte = (uint8) (copyByte | (truncatedFreshnessValue[destIdx] & fvVerifyMaks));
      }
      else
      {
        /* do nothing */
      }
    }
    else
    {
      copyByte = FvM_GetFreshnessValueArray(srcIdx); /* PRQA S 2880 */ /* MD_FvM_2880 */
    }
    truncatedFreshnessValue[destIdx] = copyByte;        /* SBSW_FVM_PTR_WRITE_ACCESS */
    srcIdx++;
  }
}
#endif


#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxFreshnessVerifyValueLatestPreviousCompare
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxFreshnessVerifyValueLatestPreviousCompare(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint64 latestResetCounterWithOffset)
{
  Std_ReturnType ret = E_OK;    /* PRQA S 2981 */ /* MD_MSR_RetVal */
  FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(freshnessValueInfoId);
  FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(freshnessValueInfoId);
  uint64 previousReceivedResetCounter = FvM_FVJaspar_GetResetCounter(previousFreshnessValueIdx);
  uint32 previousReceivedTripCounter = FvM_FVJaspar_GetTripCounter(previousFreshnessValueIdx, FvM_GetTripCounterBitSize());

  if((previousReceivedTripCounter == FvM_GetLatestTripCounter()) && (previousReceivedResetCounter == latestResetCounterWithOffset))
  {
    ret = FvM_FVJaspar_MessageCounterCarryProcessing((FvM_RxFreshnessValueInfoIterType) freshnessValueInfoId);
  }
  else if((latestResetCounterWithOffset > previousReceivedResetCounter) || (FvM_GetLatestTripCounter() > previousReceivedTripCounter))
  {
    FvM_FVJaspar_SetTripCounter(latestFreshnessValueIdx, FvM_GetLatestTripCounter(), FvM_GetTripCounterBitSize());
    FvM_FVJaspar_SetResetCounter(latestFreshnessValueIdx, latestResetCounterWithOffset);
    /* zw: GW00204964
     * AUTOSAR: <AUTOSAR_SWS_SecureOnboardCommunication.pdf> 11.4.1 - 2.Slave ECU
     * 		At the maximum value of the reset counter
     *			The sender ECU generates an authenticator by fixing the message counter to the maximum value.
     * 			The receiver ECU verifies the authenticator by overwriting the message counter with the maximum value.
     *		At the maximum value of the message counter
     *			The sender ECU generates an authenticator by fixing the message counter to the maximum value.
     *			The receiver ECU verifies the authenticator by overwriting the message counter with the maximum value.
     *
     * GW SECOC: <V3.5_SRS_SWR75_Secoc_V1.9_20210630.pdf>  5.1 - (2) SALVE FVM:
     *		b.At the maximum value of the reset counter
     *			At the maximum value of the reset counter The sender ECU generates an authenticator by fixing the message counter to the maximum value.
     *		c.At the maximum value of the message counter
     *			The sender ECU generates an authenticator by fixing the message counter to the maximum value.
    */
    // GW SECOC : Do not set message Count to maximum if resetcount reaches maximum (zw GW00204964)
    // if(latestResetCounterWithOffset == FvM_GetResetCounterMax())
    // {
    //   FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx, FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
    // }
    // else
    {
      FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx, FvM_FVJaspar_GetMessageCounter(latestFreshnessValueIdx) & FvM_GetMessageCounterLowerBitsMaskOfRxFreshnessValueInfo(freshnessValueInfoId));
    }
  }
  else
  {
    ret = E_NOT_OK;
  }
  return ret;
}
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetPositiveOffestOfResetCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint64, FVM_CODE) FvM_FVJaspar_GetPositiveOffestOfResetCounter(uint8 offset)
{
  uint64 retValue;
  if((FvM_GetResetCounterMax() - FvM_GetLatestResetCounter()) >= offset)        /* COV_FVM_ALWAYS_TRUE_DEF_PROGRAMMING */
  {
    retValue = (uint64) (FvM_GetLatestResetCounter() + offset);
  }
  else
  {
    retValue = FvM_GetResetCounterMax();
  }
  return retValue;
}
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_GetNegativeOffestOfResetCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(uint64, FVM_CODE) FvM_FVJaspar_GetNegativeOffestOfResetCounter(uint8 offset)
{
  uint64 retValue;
  if(FvM_GetLatestResetCounter() >= offset)
  {
    retValue = (uint64) (FvM_GetLatestResetCounter() - offset);
  }
  else
  {
    retValue = 0u;
  }
  return retValue;
}
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxFreshnessVerifyValueCalculation
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxFreshnessVerifyValueCalculation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint8 offset, boolean negate)
{
  Std_ReturnType ret = E_OK;    /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint64 latestResetCounterWithOffsetFirstTry;
  uint64 latestResetCounterWithOffsetSecoundTry;

  if(negate == TRUE)
  {
    latestResetCounterWithOffsetFirstTry = FvM_FVJaspar_GetNegativeOffestOfResetCounter(offset);
    latestResetCounterWithOffsetSecoundTry = FvM_FVJaspar_GetPositiveOffestOfResetCounter(offset);
  }
  else
  {
    latestResetCounterWithOffsetFirstTry = FvM_FVJaspar_GetPositiveOffestOfResetCounter(offset);
    latestResetCounterWithOffsetSecoundTry = FvM_FVJaspar_GetNegativeOffestOfResetCounter(offset);
  }

  ret = FvM_FVJaspar_DoRxFreshnessVerifyValueLatestPreviousCompare(freshnessValueInfoId, latestResetCounterWithOffsetFirstTry);

  if(ret != E_OK)
  {
    ret = FvM_FVJaspar_DoRxFreshnessVerifyValueLatestPreviousCompare(freshnessValueInfoId, latestResetCounterWithOffsetSecoundTry);
  }

  return ret;
}
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxTripFlagEvaluation
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxTripFlagEvaluation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint16 SecOCAuthVerifyAttempts)
{
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
# if(FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO == STD_ON)
  boolean doResetFlagEvaluation = TRUE;
  FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(freshnessValueInfoId);
  if(FvM_IsFreshnessValueArrayTripFlagUsedOfFreshnessValueLayoutInfo(latestFreshnessValueIdx))  /* PRQA S 2991 */ /* MD_FvM_2991 */
  {
    uint8 receivedTripFlag = FvM_FVJaspar_GetTripFlag(latestFreshnessValueIdx);
    uint8 latestTripFlag = FvM_FVJaspar_GetTripFlagOfTripCounter(latestFreshnessValueIdx, FvM_GetLatestTripCounter());
    if(receivedTripFlag != latestTripFlag)
    {
      FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(freshnessValueInfoId);
      uint32 previousReceivedTripCounter = FvM_FVJaspar_GetTripCounter(previousFreshnessValueIdx, FvM_GetTripCounterBitSize());
      if(previousReceivedTripCounter == FvM_GetLatestTripCounter())   /* COV_FVM_ALWAYS_TRUE_TRIP_FLAG */
      {
        FvM_FVJaspar_SetTripCounter(latestFreshnessValueIdx, FvM_GetLatestTripCounter() + 1u, FvM_GetTripCounterBitSize());
        FvM_FVJaspar_SetResetCounter(latestFreshnessValueIdx, 1u);
        FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx, FvM_FVJaspar_GetMessageCounter(latestFreshnessValueIdx) & FvM_GetMessageCounterLowerBitsMaskOfRxFreshnessValueInfo(freshnessValueInfoId));
        ret = E_OK;
      }
      else
      {
        ret = FvM_FVJaspar_MessageCounterCarryProcessing((FvM_RxFreshnessValueInfoIterType) freshnessValueInfoId);
      }
      doResetFlagEvaluation = FALSE;
    }
  }

  if(doResetFlagEvaluation == TRUE)
# endif
  {
    ret = FvM_FVJaspar_DoRxResetFlagEvaluation(freshnessValueInfoId, SecOCAuthVerifyAttempts);
  }
  return ret;
}  /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoAttemptsEvaluation
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoAttemptsEvaluation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint16 SecOCAuthVerifyAttempts, uint8 offset, boolean firstAttempt, boolean secondAttempt)
{
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  if(SecOCAuthVerifyAttempts == 0u)
  {
    ret = FvM_FVJaspar_DoRxFreshnessVerifyValueCalculation((FvM_RxFreshnessValueInfoIterType) freshnessValueInfoId, offset, firstAttempt);
  }
  else if(SecOCAuthVerifyAttempts == 1u)        /* COV_FVM_ALWAYS_TRUE_MISRA */
  {
    ret = FvM_FVJaspar_DoRxFreshnessVerifyValueCalculation((FvM_RxFreshnessValueInfoIterType) freshnessValueInfoId, offset, secondAttempt);
  }
  else
  {
    /* do nothing */
  }
  return ret;
}
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_DoRxResetFlagEvaluation
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_DoRxResetFlagEvaluation(FvM_RxFreshnessValueInfoIterType freshnessValueInfoId, uint16 SecOCAuthVerifyAttempts)
{
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(freshnessValueInfoId);
  uint8 receivedResetFlag = FvM_FVJaspar_GetResetFlag(latestFreshnessValueIdx);
  uint8 latestResetFlag = FvM_FVJaspar_GetResetFlagOfResetCounter(latestFreshnessValueIdx, (uint64) FvM_GetLatestResetCounter());
  uint8 resetFlagValueMask = FvM_FVJaspar_GetResetFlagValueMask(latestFreshnessValueIdx);

  if(latestResetFlag == receivedResetFlag)
  {
    ret = FvM_FVJaspar_DoRxFreshnessVerifyValueCalculation((FvM_RxFreshnessValueInfoIterType) freshnessValueInfoId, 0u, FALSE);
  }
  else if((((uint8) (latestResetFlag - 1u)) & resetFlagValueMask) == receivedResetFlag)
  {
    ret = FvM_FVJaspar_DoAttemptsEvaluation(freshnessValueInfoId, SecOCAuthVerifyAttempts, 1u, TRUE, FALSE);
  }
  else if(((latestResetFlag + 1u) & resetFlagValueMask) == receivedResetFlag)
  {
    ret = FvM_FVJaspar_DoAttemptsEvaluation(freshnessValueInfoId, SecOCAuthVerifyAttempts, 1u, FALSE, TRUE);
  }
  else if((((uint8) (latestResetFlag - 2u)) & resetFlagValueMask) == receivedResetFlag) /* COV_FVM_ALWAYS_TRUE_MISRA */
  {
    ret = FvM_FVJaspar_DoAttemptsEvaluation(freshnessValueInfoId, SecOCAuthVerifyAttempts, 2u, TRUE, FALSE);
  }
  else
  {
    /* do nothing */
  }
  return ret;
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if ((FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON) && (FVM_STARTUPCYCLECOUNTER == STD_ON))
/**********************************************************************************************************************
  FvM_FVJaspar_SetVerifyOverrideStatus
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVJaspar_SetVerifyOverrideStatus(uint8 overrideStatus)
{
  FvM_RxFreshnessValueInfoIterType rxFreshnessValueId = 0u;
  for(; rxFreshnessValueId < FvM_GetSizeOfRxFreshnessValueInfo(); rxFreshnessValueId++)
  {
# if(FVM_INVALIDHNDOFRXFRESHNESSVALUEINFO == STD_ON)
    if(!FvM_IsInvalidHndOfRxFreshnessValueInfo(rxFreshnessValueId))
# endif
    {
      if(FvM_GetProcessingTypeOfRxFreshnessValueInfo(rxFreshnessValueId) == FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO)
      {
        (void) SecOC_VerifyStatusOverride((uint16) rxFreshnessValueId, overrideStatus, 255u);
      }
    }
  }
}
#endif


#if(FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)    /* COV_FVM_VAR_SYNC_MSG_ALWAYS_ON */
/**********************************************************************************************************************
  FvM_FVJaspar_CheckSyncMessageValues
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_CheckSyncMessageValues(FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx)
{
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint32 receivedTripCounter = FvM_FVJaspar_GetTripCounter(latestFreshnessValueIdx, FvM_GetTripCounterBitSize());
  uint64 receivedResetCounter = FvM_FVJaspar_GetResetCounter(latestFreshnessValueIdx);

  if(receivedTripCounter > FvM_GetLatestTripCounter())
  {
    ret = E_OK;
  }
  else if ((receivedTripCounter == FvM_GetLatestTripCounter()) && (receivedResetCounter == FvM_GetLatestResetCounter()))
  {
    ret = FVM_RETURN_VALUE_FOR_SAME_TRIP_RESET_COUNTER_SYNC_MESSAGE;
  }
  else if((receivedTripCounter == FvM_GetLatestTripCounter()) && (receivedResetCounter > FvM_GetLatestResetCounter()))
  {
    ret = E_OK;
  }
  else if((FvM_GetLatestTripCounter() + FvM_GetClearAcceptanceWindow()) >= FvM_GetTripCounterMax())     /* PRQA S 2985 */ /* MD_FvM_2985_ClearAcceptanceWindow */
  {
    if((receivedTripCounter >= 1u) && (receivedTripCounter <= (FvM_GetClearAcceptanceWindow() + 1u)))
    {
      ret = E_OK;
    }
  }
  else
  {
    /* do nothing */
  }
  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVJaspar_CheckTripAndMessageCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) FvM_FVJaspar_CheckTripAndMessageCounter(FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx, FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx)
{
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint64 previousTripCounter = (uint64) FvM_FVJaspar_GetTripCounter(previousFreshnessValueIdx, FvM_GetTripCounterWithoutResetcounterBitSize());
  uint64 latestTripCounter = (uint64) FvM_FVJaspar_GetTripCounter(latestFreshnessValueIdx, FvM_GetTripCounterWithoutResetcounterBitSize());

  if(previousTripCounter <= latestTripCounter)
  {
    if(previousTripCounter == latestTripCounter)
    {
      uint32 previousMessageCounter = FvM_FVJaspar_GetMessageCounter(previousFreshnessValueIdx);
      uint32 latestMessageCounter = FvM_FVJaspar_GetMessageCounter(latestFreshnessValueIdx);
      if((previousMessageCounter < latestMessageCounter) || (FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(previousFreshnessValueIdx) == latestMessageCounter))
      {
        ret = E_OK;
      }
    }
    else
    {
      ret = E_OK;
    }
  }
  else if((previousTripCounter + FvM_GetClearAcceptanceWindowWithoutResetCounter()) >= FvM_GetTripCounterWithoutResetCounterMax())
  {
    if((latestTripCounter >= 1u) && (latestTripCounter <= (FvM_GetClearAcceptanceWindowWithoutResetCounter() + 1u)))
    {
      ret = E_OK;
    }
  }
  else  /* COV_FVM_MISRA */
  {
    /* do nothing */
  }
  return ret;
}
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FVJaspar_TxProcessing_Jaspar
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(Std_ReturnType, FVM_CODE) SecOC_FVJaspar_TxProcessing_Jaspar(FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType SecOCFreshnessValueID, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue, P2CONST(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValueLength)
{
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
# if(FVM_TX_USE_DEFAULT_FRESHNESS_VALUE_DURING_START_UP == STD_OFF)
  if(FvM_GetSyncState() == FVM_IN_SYNC_SYNCSTATE)
# elif(FVM_RECEPTIONTIMEOUTFORTRANSMISSIONCOUNTER == STD_ON)
  if(FvM_GetReceptionTimeoutForTransmissionCounter() == 0u)
# endif
  {
    FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo(SecOCFreshnessValueID);
    FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo(SecOCFreshnessValueID);
    uint32 previousTripCounter = FvM_FVJaspar_GetTripCounter(previousFreshnessValueIdx, FvM_GetTripCounterBitSize());
    uint64 previousResetCounter = FvM_FVJaspar_GetResetCounter(previousFreshnessValueIdx);

    if((FvM_GetLatestTripCounter() == previousTripCounter) && (FvM_GetLatestResetCounter() == previousResetCounter))
    {
      FvM_FVJaspar_IncMessageCounter(latestFreshnessValueIdx, SecOCFreshnessValueID);
    }
    else
    {
      FvM_FVJaspar_SetTripCounter(latestFreshnessValueIdx, FvM_GetLatestTripCounter(), FvM_GetTripCounterBitSize());
      FvM_FVJaspar_SetResetCounter(latestFreshnessValueIdx, FvM_GetLatestResetCounter());
      FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx, 1u);
      FvM_FVJaspar_SetResetFlag(latestFreshnessValueIdx, (uint32) FvM_GetLatestResetCounter());
# if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO == STD_ON)
      FvM_FVJaspar_SetTripFlag(latestFreshnessValueIdx, FvM_GetLatestTripCounter());
# endif
    }
    VStdMemCpyRamToRam(SecOCFreshnessValue,     /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_SECOC_MEM_CPY_RAM2RAM */
                       FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));

    FvM_FVJaspar_CopyFreshnessVerifyValueToTruncFreshnessValue(latestFreshnessValueIdx, SecOCTruncatedFreshnessValue, *SecOCTruncatedFreshnessValueLength);     /* SBSW_FVM_CHECKED_POINTER_1 */

    ret = E_OK;
  }
# if(FVM_TX_USE_DEFAULT_FRESHNESS_VALUE_DURING_START_UP == STD_OFF)
  else
  {
    ret = E_BUSY;
  }
# endif
  return ret;
}  /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  SecOC_FVJaspar_TxProcessing_JasparWithoutResetCounter
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) SecOC_FVJaspar_TxProcessing_JasparWithoutResetCounter(FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType SecOCFreshnessValueID, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue)
{
  FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo(SecOCFreshnessValueID);
  FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo(SecOCFreshnessValueID);
  uint32 previousTripCounter = FvM_FVJaspar_GetTripCounter(previousFreshnessValueIdx, FvM_GetTripCounterWithoutResetcounterBitSize());

  if(FvM_GetLatestTripCounterWithoutResetCounter() == previousTripCounter)
  {
    FvM_FVJaspar_IncMessageCounter(latestFreshnessValueIdx, SecOCFreshnessValueID);
  }
  else
  {
    FvM_FVJaspar_SetTripCounter(latestFreshnessValueIdx, FvM_GetLatestTripCounterWithoutResetCounter(), FvM_GetTripCounterWithoutResetcounterBitSize());
    FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx, 1u);
  }

  VStdMemCpyRamToRam(SecOCFreshnessValue,       /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_SECOC_MEM_CPY_RAM2RAM */
                     FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
  VStdMemCpyRamToRam(SecOCTruncatedFreshnessValue,      /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_SECOC_MEM_CPY_RAM2RAM */
                     FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
}
#endif


#if(FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_SyncMessageVerificationStatusCallout
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_SyncMessageVerificationStatusCallout(SecOC_VerificationStatusType verificationStatus)
{
  if((verificationStatus.verificationStatus == SECOC_VERIFICATIONSUCCESS)
#  if(FVM_DEVMODEENABLED == STD_ON)
      || (FvM_IsDevModeEnabled() && (verificationStatus.verificationStatus != SECOC_FRESHNESSFAILURE))
#  endif
  )
  {
    FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(verificationStatus.freshnessValueID);
    uint32 newTripCounter = FvM_FVJaspar_GetTripCounter(latestFreshnessValueIdx, FvM_GetTripCounterBitSize());
    uint64 newResetCounter = FvM_FVJaspar_GetResetCounter(latestFreshnessValueIdx);
    uint32 oldTripCounterValue = FvM_GetLatestTripCounter();

    if(newTripCounter < oldTripCounterValue)
    {
      VStdMemClr(FvM_GetAddrFreshnessValueArray(0), FvM_GetSizeOfFreshnessValueArray());  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_MEM_CPY_CLR */
    }

    FvM_SetLatestTripCounter(newTripCounter);     /* SBSW_FVM_CSL_VAR_ACCESS */
    FvM_SetLatestResetCounter(newResetCounter);   /* SBSW_FVM_CSL_VAR_ACCESS */

#  if(FVM_TRIPCOUNTERNVMBLOCKDESCRIPTOR == STD_ON)
    if(newTripCounter != oldTripCounterValue)
    {
      /* Write updated trip counter to NvM */
      (void) NvM_WriteBlock(FvM_GetTripCounterNvMBlockDescriptor(0), &FvM_GetLatestTripCounter());        /* PRQA S 0315 */ /* MD_FvM_0315_NvMWriteBlock */ /* SBSW_FVM_FUNC_CALL */
    }
#  endif

#  if (FVM_TRIPCOUNTERMAXNOTIFICATION == STD_ON)
    if(newTripCounter == FvM_GetTripCounterMax())
    {
      FvM_GetTripCounterMaxNotification(0) ();    /* SBSW_FVM_CSL_FCT_PTR */
    }
#  endif
#  if (FVM_RESETCOUNTERMAXNOTIFICATION == STD_ON)
    if(newResetCounter == FvM_GetResetCounterMax())
    {
      FvM_GetResetCounterMaxNotification(0) ();   /* SBSW_FVM_CSL_FCT_PTR */
    }
#  endif
#  if(FVM_SYNCSTATE == STD_ON)
    if(FvM_GetSyncState() != FVM_IN_SYNC_SYNCSTATE)
    {
      FvM_SetSyncState(FVM_IN_SYNC_SYNCSTATE);    /* SBSW_FVM_CSL_VAR_ACCESS */
    }
#  endif
#  if (FVM_SYNCMESSAGERECEPTIONTIMEOUTCOUNTER == STD_ON)
    FvM_SetSyncMessageReceptionTimeoutCounter(FvM_GetSyncMessageReceptionTimeoutCnt() + 1u);      /* SBSW_FVM_CSL_VAR_ACCESS */
    (void) Dem_SetEventStatus(FvM_GetDemEventIdReference(0), DEM_EVENT_STATUS_PASSED);
#  endif

#  if (FVM_RECEPTIONTIMEOUTFORTRANSMISSIONCOUNTER == STD_ON)
    FvM_SetReceptionTimeoutForTransmissionCounter(0u);    /* SBSW_FVM_CSL_VAR_ACCESS */
#  endif
  }
}
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_JasparVerificationStatusCallout
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_JasparVerificationStatusCallout(SecOC_VerificationStatusType verificationStatus)
{
#  if((FVM_USE_DEFAULT_FRESHNESS_VALUE_IF_OUT_OF_SYNC_AFTER_START_UP_TIME == STD_OFF) && (FVM_SYNCSTATE == STD_ON))
  if(FvM_GetSyncState() == FVM_IN_SYNC_SYNCSTATE)
#  endif
  {
    if(verificationStatus.verificationStatus == SECOC_VERIFICATIONSUCCESS)
    {
      FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(verificationStatus.freshnessValueID);
      FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(verificationStatus.freshnessValueID);
      VStdMemCpyRamToRam(FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(previousFreshnessValueIdx)),        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_CSL03 */
                         FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(previousFreshnessValueIdx));
#  if(FVM_RXMESSAGECOUNTERMAXNOTIFICATION == STD_ON)
      if(FvM_FVJaspar_GetMessageCounter(previousFreshnessValueIdx) == FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(previousFreshnessValueIdx))
      {
        FvM_GetRxMessageCounterMaxNotification(0) (verificationStatus.freshnessValueID);  /* SBSW_FVM_CSL_FCT_PTR */
      }
#  endif
    }
  }
}
#endif

#if(FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_JasparWithoutRestCounterVerificationStatusCallout
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_JasparWithoutRestCounterVerificationStatusCallout(SecOC_VerificationStatusType verificationStatus)
{
  if(verificationStatus.verificationStatus == SECOC_VERIFICATIONSUCCESS)
  {
    FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(verificationStatus.freshnessValueID);
#  if(FVM_DEVMODEENABLED == STD_ON)
    if(!FvM_IsDevModeEnabled())
#  endif
    {
      FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(verificationStatus.freshnessValueID);
      VStdMemCpyRamToRam(FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(previousFreshnessValueIdx)),  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_CSL03 */
                         FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(previousFreshnessValueIdx));
    }
#  if(FVM_RXMESSAGECOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION == STD_ON)
    if(FvM_FVJaspar_GetMessageCounter(previousFreshnessValueIdx) == FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(previousFreshnessValueIdx))
    {
      FvM_GetRxMessageCounterWithoutResetCounterMaxNotification(0) (verificationStatus.freshnessValueID); /* SBSW_FVM_CSL_FCT_PTR */
    }
#  endif
#  if(FVM_RXTRIPCOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION == STD_ON)
    if(FvM_FVJaspar_GetTripCounter(previousFreshnessValueIdx, FvM_GetTripCounterWithoutResetcounterBitSize()) == FvM_GetTripCounterWithoutResetCounterMax())
    {
      FvM_GetRxTripCounterWithoutResetCounterMaxNotification(0) (verificationStatus.freshnessValueID); /* SBSW_FVM_CSL_FCT_PTR */
    }
#  endif
  }
}
#endif


#if (FVM_RESETCOUNTERCYCLETIMECOUNTER == STD_ON)
/**********************************************************************************************************************
  FvM_FVConstruction_CopySrcToDest
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
LOCAL_INLINE FUNC(void, FVM_CODE) FvM_FVConstruction_CopySrcToDest(uint64 srcValue, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) destBuffer, uint16 copyBitLen, uint8 destBitOffset)
{
  uint16 bitsToBeCopied = copyBitLen;
  uint64 valueToBeCopied = srcValue;
  uint8 numLeftShift;
  uint8 numRightShift;
  uint8 destByteCnt = (uint8) ((copyBitLen + destBitOffset) / 8u);

  if(destBitOffset != 0u) /* COV_TRIP_REST_COUNTER_BIT_SIZE_MASTER */
  {
    numLeftShift = destBitOffset;
    numRightShift = 8u - destBitOffset;
  }
  else
  {
    numLeftShift = 0u;
  }

  if(((copyBitLen + destBitOffset) % 8u) != 0u)  /* COV_TRIP_REST_COUNTER_BIT_SIZE_MASTER */
  {
    destByteCnt++;
  }

  for(; destByteCnt > 0u; destByteCnt--)
  {
    uint8 destByteIdx = (uint8) (destByteCnt - 1u);
    uint8 srcCopyByte = (uint8) (valueToBeCopied & 0xFFu);
    uint8 firstByte = srcCopyByte;
    valueToBeCopied = valueToBeCopied >> 8u;

    if(numLeftShift != 0u) /* COV_TRIP_REST_COUNTER_BIT_SIZE_MASTER */
    {
      if(bitsToBeCopied >= numRightShift) /* COV_TRIP_REST_COUNTER_BIT_SIZE_MASTER */
      {
        firstByte = firstByte << numLeftShift;
        bitsToBeCopied = bitsToBeCopied - numRightShift;
        destBuffer[destByteIdx] = firstByte | (destBuffer[destByteIdx] & ((uint8) (0xFFu >> numRightShift))); /* SBSW_FVM_COPY_SRC_TO_DEST */
        if(bitsToBeCopied >= numLeftShift) /* COV_TRIP_REST_COUNTER_BIT_SIZE_MASTER */
        {
          uint8 secondByte = srcCopyByte;
          secondByte = secondByte >> numRightShift;
          bitsToBeCopied = bitsToBeCopied - ((uint8) (8u - numRightShift));
          destBuffer[(uint8) (destByteIdx - 1u)] = secondByte | (destBuffer[(uint8) (destByteIdx - 1u)] & ((uint8) (0xFFu << numLeftShift))); /* SBSW_FVM_COPY_SRC_TO_DEST */
        }
      }
    }
    else
    {
      if(bitsToBeCopied < 8u)
      {
        uint8 firstByteMask = (uint8) (0xFFu >> (8u - bitsToBeCopied));
        uint8 destBufferMask = (uint8) (0xFFu << bitsToBeCopied);

        firstByte = (firstByte & firstByteMask) | (destBuffer[destByteIdx] & destBufferMask);
        bitsToBeCopied = 0u;
      }
      else
      {
        bitsToBeCopied = bitsToBeCopied - 8u;
      }
      destBuffer[destByteIdx] = firstByte; /* SBSW_FVM_COPY_SRC_TO_DEST */
    }
  }
} /* PRQA S 6060, 6030 */ /* MD_MSR_STPAR, MD_MSR_STCYC */
#endif



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FvM_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FVM_CODE) FvM_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  FvM_SetInitialized(FALSE);    /* SBSW_FVM_CSL_VAR_ACCESS */
#if (FVM_LATESTTRIPCOUNTERWITHOUTRESETCOUNTER == STD_ON)
  FvM_SetTripCounterReadErrorDetectedFlag(FALSE); /* SBSW_FVM_CSL_VAR_ACCESS */
#endif
}

/**********************************************************************************************************************
  FvM_DeInit
**********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
*/
FUNC(void, FVM_CODE) FvM_DeInit(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_INVALID_REQUEST;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    FvM_SetInitialized(FALSE);  /* SBSW_FVM_CSL_VAR_ACCESS */
  }

#if(FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_DEINIT, errorId);
  }
#endif

  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 *  FvM_Init()
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
FUNC(void, FVM_CODE) FvM_Init(P2CONST(FvM_ConfigType, AUTOMATIC, FVM_PBCFG) ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (FVM_DEV_ERROR_DETECT == STD_ON)    /* COV_FVM_VAR_DEV_ERROR_DETECT */
  /* Check initialization state of the component */
  if(FvM_IsInitialized())
  {
    errorId = FVM_E_ALREADY_INITIALIZED;
  }
  /* Check parameter 'ConfigPtr' */
  else if(ConfigPtr != NULL_PTR)
  {
    errorId = FVM_E_PARAM_CONFIG;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (FVM_FRESHNESSVALUEARRAY == STD_ON)
    VStdMemClr(FvM_GetAddrFreshnessValueArray(0), FvM_GetSizeOfFreshnessValueArray());  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_MEM_CPY_CLR */
#endif
#if (FVM_STARTUPCYCLECOUNTER == STD_ON)
    FvM_SetStartUpCycleCounter(FvM_GetStartUpCycleCnt());       /* SBSW_FVM_CSL_VAR_ACCESS */
# if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
    FvM_FVJaspar_SetVerifyOverrideStatus(SECOC_OVERRIDE_VERIFICATION_STATUS_PASS_UNTIL_NOTICE);
# endif
#endif

#if (FVM_SYNCMESSAGERECEPTIONTIMEOUTCOUNTER == STD_ON)
    FvM_SetSyncMessageReceptionTimeoutCounter(FvM_GetSyncMessageReceptionTimeoutCnt() + 1u);    /* SBSW_FVM_CSL_VAR_ACCESS */
#endif

#if (FVM_RECEPTIONTIMEOUTFORTRANSMISSIONCOUNTER == STD_ON)
    FvM_SetReceptionTimeoutForTransmissionCounter(FvM_GetReceptionTimeoutForTransmissionCnt()); /* SBSW_FVM_CSL_VAR_ACCESS */
#endif

#if (FVM_SYNCSTATE == STD_ON)
# if(FVM_STARTUPCYCLECOUNTER == STD_ON)
    FvM_SetSyncState(FVM_INITIAL_OUT_OF_SYNC_SYNCSTATE);        /* SBSW_FVM_CSL_VAR_ACCESS */
# else
    FvM_SetSyncState(FVM_INVALID_OUT_OF_SYNC_SYNCSTATE);        /* SBSW_FVM_CSL_VAR_ACCESS */
# endif
#endif

#if (FVM_LATESTTRIPCOUNTER == STD_ON)
# if (FVM_TRIPCOUNTERNVMBLOCKDESCRIPTOR == STD_OFF)
    FvM_SetLatestTripCounter(0);        /* SBSW_FVM_CSL_VAR_ACCESS */
# endif

# if(FVM_RESETCOUNTERCYCLETIMECOUNTER == STD_ON)
    FvM_SetLatestResetCounter(1);       /* SBSW_FVM_CSL_VAR_ACCESS */
    FvM_IncLatestTripCounter();       /* SBSW_FVM_CSL_VAR_ACCESS */

    (void) NvM_WriteBlock(FvM_GetTripCounterNvMBlockDescriptor(0), &FvM_GetLatestTripCounter());        /* PRQA S 0315 */ /* MD_FvM_0315_NvMWriteBlock */ /* SBSW_FVM_FUNC_CALL */

    FvM_SetResetCounterCycleTimeCounter(FvM_GetResetCounterCycleTime()); /* SBSW_FVM_CSL_VAR_ACCESS */
# else
    FvM_SetLatestResetCounter(0);       /* SBSW_FVM_CSL_VAR_ACCESS */
# endif

# if (FVM_TRIPFLAGSIZEOFFRESHNESSVALUELAYOUTINFO == STD_ON)
    {
      FvM_FreshnessValueLayoutInfoIterType freshnessValueLayoutId = 0u;
      for(; freshnessValueLayoutId < FvM_GetSizeOfFreshnessValueLayoutInfo(); freshnessValueLayoutId++)
      {
        FvM_FVJaspar_SetTripFlag(freshnessValueLayoutId, FvM_GetLatestTripCounter());
      }
    }
# endif
#endif

#if(FVM_LATESTTRIPCOUNTERWITHOUTRESETCOUNTER == STD_ON)
  /* If NvM read error was detected the Latest Trip Counter Value is set to the maximum value and is not written back to NvM */
  if(FvM_IsTripCounterReadErrorDetectedFlag())
  {
    FvM_SetLatestTripCounterWithoutResetCounter(FvM_GetTripCounterWithoutResetCounterMax()); /* SBSW_FVM_CSL_VAR_ACCESS */
#  if (FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO ==  STD_ON)
    {
      FvM_TxFreshnessValueInfoIterType txFreshnessValueInfo = 0;
      for(; txFreshnessValueInfo < FvM_GetSizeOfTxFreshnessValueInfo(); txFreshnessValueInfo++)
      {
        if(FvM_GetProcessingTypeOfTxFreshnessValueInfo(txFreshnessValueInfo) == FVM_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO)  /* PRQA S 2741 */ /* MD_FvM_2741 */ /* COV_FVM_WITHOUT_RESETCOUNTER_TX */
        {
          FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo(txFreshnessValueInfo);
          FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo(txFreshnessValueInfo);
          FvM_FVJaspar_SetTripCounter(latestFreshnessValueIdx, FvM_GetLatestTripCounterWithoutResetCounter(), FvM_GetTripCounterWithoutResetcounterBitSize());
          FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx,  FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
          FvM_FVJaspar_SetTripCounter(previousFreshnessValueIdx, FvM_GetLatestTripCounterWithoutResetCounter(), FvM_GetTripCounterWithoutResetcounterBitSize());
          FvM_FVJaspar_SetMessageCounter(previousFreshnessValueIdx,  FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(previousFreshnessValueIdx));
        }
      }
    }
#  endif
  }
  else
  {
    /* Latest Trip Counter Value is read form NvM and is incremented during start up */
    if(FvM_GetTripCounterWithoutResetCounterMax() == FvM_GetLatestTripCounterWithoutResetCounter())
    {
      FvM_SetLatestTripCounterWithoutResetCounter(0);   /* SBSW_FVM_CSL_VAR_ACCESS */
    }
    FvM_IncLatestTripCounterWithoutResetCounter();      /* SBSW_FVM_CSL_VAR_ACCESS */
    /* Write updated trip counter to NvM */
    (void) NvM_WriteBlock(FvM_GetTripCounterWithoutResetCounterNvMBlockDescriptor(0), &FvM_GetLatestTripCounterWithoutResetCounter());  /* PRQA S 0315 */ /* MD_FvM_0315_NvMWriteBlock */ /* SBSW_FVM_FUNC_CALL */
  }

# if(FVM_TRIPCOUNTERWITHOUTRESETCOUNTERMAXNOTIFICATION == STD_ON)
    if(FvM_GetTripCounterWithoutResetCounterMax() == FvM_GetLatestTripCounterWithoutResetCounter())
    {
      FvM_GetTripCounterWithoutResetCounterMaxNotification(0) ();       /* SBSW_FVM_CSL_FCT_PTR */
    }
# endif
#endif

#if(FVM_DEVMODEENABLED == STD_ON)
    FvM_SetDevModeEnabled(FALSE);       /* SBSW_FVM_CSL_VAR_ACCESS */
#endif
    FvM_SetInitialized(TRUE);   /* SBSW_FVM_CSL_VAR_ACCESS */
  }
  /* ----- Development Error Report --------------------------------------- */
#if (FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_INIT, errorId);
  }
#else
  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint !e438 */
#endif
  FVM_DUMMY_STATEMENT(ConfigPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint !e438 */
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */

#if (FVM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  FvM_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, FVM_CODE) FvM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FVM_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (FVM_DEV_ERROR_DETECT == STD_ON)   /* COV_FVM_VAR_DEV_ERROR_DETECT */
  if(versioninfo == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (FVM_VENDOR_ID);    /* SBSW_FVM_CHECKED_POINTER */
    versioninfo->moduleID = (FVM_MODULE_ID);    /* SBSW_FVM_CHECKED_POINTER */
    versioninfo->sw_major_version = (FVM_SW_MAJOR_VERSION);     /* SBSW_FVM_CHECKED_POINTER */
    versioninfo->sw_minor_version = (FVM_SW_MINOR_VERSION);     /* SBSW_FVM_CHECKED_POINTER */
    versioninfo->sw_patch_version = (FVM_SW_PATCH_VERSION);     /* SBSW_FVM_CHECKED_POINTER */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_GET_VERSION_INFO, errorId);
  }
# else
  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint !e438 */
# endif
}
#endif

#if(FVM_RXFRESHNESSVALUEINFO == STD_ON) /* COV_FVM_VAR_SYNC_MSG_ALWAYS_ON */
/**********************************************************************************************************************
 *  FvM_VerificationStatusCallout()
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
FUNC(void, FVM_CODE) FvM_VerificationStatusCallout(SecOC_VerificationStatusType verificationStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_UNINIT;
  }
# if(FVM_DEV_ERROR_DETECT == STD_ON)    /* COV_FVM_VAR_DEV_ERROR_DETECT */
  else if(verificationStatus.freshnessValueID >= FvM_GetSizeOfRxFreshnessValueInfo())
  {
    errorId = FVM_E_PARAM;
  }
#  if(FVM_INVALIDHNDOFRXFRESHNESSVALUEINFO == STD_ON)
  else if(FvM_IsInvalidHndOfRxFreshnessValueInfo(verificationStatus.freshnessValueID))
  {
    errorId = FVM_E_PARAM;
  }
#  endif
# endif
  else
  {
    SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_RX_FRESHNESS();
    /* ----- Implementation ----------------------------------------------- */
    switch (FvM_GetProcessingTypeOfRxFreshnessValueInfo(verificationStatus.freshnessValueID))
    {
# if(FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
      case FVM_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO:
      {
        FvM_FVConstruction_SyncMessageVerificationStatusCallout(verificationStatus);
      }
        break;
# endif
# if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
      case FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO:
      {
        FvM_FVConstruction_JasparVerificationStatusCallout(verificationStatus);
      }
        break;
# endif
# if(FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
      case FVM_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO:
      {
        FvM_FVConstruction_JasparWithoutRestCounterVerificationStatusCallout(verificationStatus);
      }
        break;
# endif
      default: /* COV_FVM_MISRA */
        /* do nothing */
        break;
    }
    SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_RX_FRESHNESS();
  }
  /* ----- Development Error Report --------------------------------------- */
# if (FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_VERIFICATION_STATUS_CALLOUT, errorId);
  }
# else
  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint !e438 */
# endif
}  /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif



#if(FVM_TXPROCESSINGINFO == STD_ON)
/**********************************************************************************************************************
 *  SecOC_GetTxFreshnessTruncData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, FVM_CODE) SecOC_GetTxFreshnessTruncData(uint16 SecOCFreshnessValueID, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue, P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue, P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValueLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_UNINIT;
  }
# if(FVM_DEV_ERROR_DETECT == STD_ON)    /* COV_FVM_VAR_DEV_ERROR_DETECT */
  else if(SecOCFreshnessValueID >= FvM_GetSizeOfTxProcessingInfo())
  {
    errorId = FVM_E_PARAM;
  }
#  if (FVM_INVALIDHNDOFTXPROCESSINGINFO == STD_ON)
  else if(FvM_IsInvalidHndOfTxProcessingInfo(SecOCFreshnessValueID))
  {
    errorId = FVM_E_PARAM;
  }
#  endif
  else if(SecOCFreshnessValue == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
  else if(SecOCFreshnessValueLength == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
  else if(SecOCTruncatedFreshnessValue == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
  else if(SecOCTruncatedFreshnessValueLength == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
# if(FVM_TXFRESHNESSVALUEINFOUSEDOFTXPROCESSINGINFO == STD_ON)
    if(FvM_IsTxFreshnessValueInfoUsedOfTxProcessingInfo(SecOCFreshnessValueID)) /* PRQA S 2741 */ /* MD_FvM_2741 */ /* COV_FVM_NO_MASTER_CONF */
    {
      FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType txFreshnessValueInfoIdx = FvM_GetTxFreshnessValueInfoIdxOfTxProcessingInfo(SecOCFreshnessValueID);
      ret = E_OK; /* PRQA S 2982 */ /* MD_FvM_2982 */
#  if(FVM_DEV_ERROR_DETECT == STD_ON)    /* COV_FVM_VAR_DEV_ERROR_DETECT */
      if(*SecOCFreshnessValueLength != ((uint32) (FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(FvM_GetFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo(txFreshnessValueInfoIdx))) << 3u))
      {
        errorId = FVM_E_PARAM;
        ret = E_NOT_OK;
      }
      else if(FvM_FVJaspar_GetLengthInBytes(*SecOCTruncatedFreshnessValueLength) > FvM_GetFreshnessValueArrayTruncatedFreshnessValueLengthOfFreshnessValueLayoutInfo(FvM_GetFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo(txFreshnessValueInfoIdx)))
      {
        errorId = FVM_E_PARAM;
        ret = E_NOT_OK;
      }
      else
#  endif
      {
       SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_TX_FRESHNESS();
        switch (FvM_GetProcessingTypeOfTxFreshnessValueInfo(txFreshnessValueInfoIdx))
        {
#  if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
          case FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO:
          {
            ret = SecOC_FVJaspar_TxProcessing_Jaspar(txFreshnessValueInfoIdx, SecOCFreshnessValue, SecOCTruncatedFreshnessValue, SecOCTruncatedFreshnessValueLength); /* SBSW_FVM_CHECKED_POINTER_1 */
          }
          break;
#  endif
#  if (FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO == STD_ON)
          case FVM_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFTXFRESHNESSVALUEINFO:
          {
            SecOC_FVJaspar_TxProcessing_JasparWithoutResetCounter(txFreshnessValueInfoIdx, SecOCFreshnessValue, SecOCTruncatedFreshnessValue);        /* SBSW_FVM_CHECKED_POINTER_1 */
          }
          break;
#  endif
          default: /* COV_FVM_MISRA */
            /* do nothing */
            break;
        }
        SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_TX_FRESHNESS();
      }
    }
    else
# endif
    {
# if (FVM_RESETCOUNTERCYCLETIMECOUNTER == STD_ON)
      FvM_ResetCounterBitSizeType tripResetSyncBitCount = FvM_GetTripCounterBitSize() + FvM_GetResetCounterBitSize();
      if((*SecOCFreshnessValueLength >= *SecOCTruncatedFreshnessValueLength) && (*SecOCTruncatedFreshnessValueLength >= tripResetSyncBitCount))
      {
        uint8 freshnessValueByteLength = (uint8) (*SecOCFreshnessValueLength / 8u);
        uint8 tripCounterOffset = (8u - (tripResetSyncBitCount % 8u)) % 8u;
        SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_TX_FRESHNESS();
        FvM_FVConstruction_CopySrcToDest((uint64) FvM_GetLatestTripCounter(), SecOCFreshnessValue, FvM_GetTripCounterBitSize(), (uint8) (FvM_GetResetCounterBitSize() % 8u)); /* SBSW_FVM_CHECKED_POINTER_1 */

        FvM_FVConstruction_CopySrcToDest(FvM_GetLatestResetCounter(), &(SecOCFreshnessValue[(FvM_GetTripCounterBitSize() + tripCounterOffset) / 8u]), FvM_GetResetCounterBitSize(), 0u); /* SBSW_FVM_CHECKED_POINTER_1 */

        VStdMemCpyRamToRam(SecOCTruncatedFreshnessValue,      /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_SECOC_MEM_CPY_RAM2RAM */
                           SecOCFreshnessValue, freshnessValueByteLength);
        SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_TX_FRESHNESS();
        ret = E_OK;
      }
      else
      {
        errorId = FVM_E_PARAM;
        ret = E_NOT_OK;
      }
# endif
    }
  }
  /* ----- Development Error Report --------------------------------------- */
# if(FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_GET_TX_FRESHNESS, errorId);
  }
# endif

  FVM_DUMMY_STATEMENT(SecOCFreshnessValueID);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(SecOCTruncatedFreshnessValueLength);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(SecOCFreshnessValueLength);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(SecOCTruncatedFreshnessValue);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(SecOCFreshnessValue);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return ret;
}  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if(FVM_TXPROCESSINGINFO == STD_ON)
/**********************************************************************************************************************
 *  SecOC_SPduTxConfirmation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, FVM_CODE) SecOC_SPduTxConfirmation(uint16 SecOCFreshnessValueID)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_UNINIT;
  }
# if(FVM_DEV_ERROR_DETECT == STD_ON)    /* COV_FVM_VAR_DEV_ERROR_DETECT */
  else if(SecOCFreshnessValueID >= FvM_GetSizeOfTxProcessingInfo())
  {
    errorId = FVM_E_PARAM;
  }
#  if (FVM_INVALIDHNDOFTXPROCESSINGINFO == STD_ON)
  else if(FvM_IsInvalidHndOfTxProcessingInfo(SecOCFreshnessValueID))
  {
    errorId = FVM_E_PARAM;
  }
#  endif
# endif
  else
  {
# if(FVM_TXFRESHNESSVALUEINFOUSEDOFTXPROCESSINGINFO == STD_ON)
    if(FvM_IsTxFreshnessValueInfoUsedOfTxProcessingInfo(SecOCFreshnessValueID)) /* PRQA S 2741 */ /* MD_FvM_2741 */ /* COV_FVM_NO_MASTER_CONF */
    {
      FvM_TxFreshnessValueInfoIdxOfTxProcessingInfoType txFreshnessValueInfoIdx = FvM_GetTxFreshnessValueInfoIdxOfTxProcessingInfo(SecOCFreshnessValueID);
      SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_TX_FRESHNESS();
      {
        FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoPreviousIdxOfTxFreshnessValueInfo(txFreshnessValueInfoIdx);
        FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = (FvM_FreshnessValueLayoutInfoIterType) FvM_GetFreshnessValueLayoutInfoLatestIdxOfTxFreshnessValueInfo(txFreshnessValueInfoIdx);
        VStdMemCpyRamToRam(FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(previousFreshnessValueIdx)), FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(previousFreshnessValueIdx));     /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_CSL03 */
      }
      SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_TX_FRESHNESS();
    }
# endif
  }
  /* ----- Development Error Report --------------------------------------- */
# if(FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_TX_FRESHNESS_CONFIRMATION, errorId);
  }
# endif
  FVM_DUMMY_STATEMENT(SecOCFreshnessValueID);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if(FVM_RXFRESHNESSVALUEINFO == STD_ON) /* COV_FVM_VAR_SYNC_MSG_ALWAYS_ON */
/**********************************************************************************************************************
 *  SecOC_GetRxFreshness()
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
FUNC(Std_ReturnType, FVM_CODE) SecOC_GetRxFreshness(uint16 SecOCFreshnessValueID, P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue, uint32 SecOCTruncatedFreshnessValueLength, uint16 SecOCAuthVerifyAttempts, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue, P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType ret = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_UNINIT;
  }
# if(FVM_DEV_ERROR_DETECT == STD_ON)    /* COV_FVM_VAR_DEV_ERROR_DETECT */
  else if(SecOCFreshnessValueID >= FvM_GetSizeOfRxFreshnessValueInfo())
  {
    errorId = FVM_E_PARAM;
  }
#  if(FVM_INVALIDHNDOFRXFRESHNESSVALUEINFO == STD_ON)
  else if(FvM_IsInvalidHndOfRxFreshnessValueInfo(SecOCFreshnessValueID))
  {
    errorId = FVM_E_PARAM;
  }
#  endif
  else if(SecOCTruncatedFreshnessValue == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
  else if(SecOCFreshnessValue == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
  else if(SecOCFreshnessValueLength == NULL_PTR)
  {
    errorId = FVM_E_PARAM_POINTER;
  }
  else if(*SecOCFreshnessValueLength != ((uint32) (FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(SecOCFreshnessValueID))) << 3u))
  {
    errorId = FVM_E_PARAM;
  }
# endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_RX_FRESHNESS();
    switch (FvM_GetProcessingTypeOfRxFreshnessValueInfo(SecOCFreshnessValueID))
    {
# if (FVM_EXISTS_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
      case FVM_JASPAR_FRESHNESS_SYNC_MESSAGE_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO:
      {
        FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(SecOCFreshnessValueID);
        FvM_FVJaspar_CopyTruncFreshnessValueToBuffer(latestFreshnessValueIdx, SecOCTruncatedFreshnessValue, SecOCTruncatedFreshnessValueLength);        /* SBSW_FVM_CONST_POINTER */

        ret = FvM_FVJaspar_CheckSyncMessageValues(latestFreshnessValueIdx);

        if(ret == E_OK)
        {
          VStdMemCpyRamToRam(SecOCFreshnessValue,       /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_SECOC_MEM_CPY_RAM2RAM */
                             FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
        }
      }
        break;
# endif
# if(FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
      case FVM_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO:
#  if((FVM_USE_DEFAULT_FRESHNESS_VALUE_IF_OUT_OF_SYNC_AFTER_START_UP_TIME == STD_OFF) && (FVM_SYNCSTATE == STD_ON))
        if(FvM_GetSyncState() == FVM_IN_SYNC_SYNCSTATE)
#  endif
        {
          FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(SecOCFreshnessValueID);
          FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(SecOCFreshnessValueID);

          VStdMemCpyRamToRam(FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)),    /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_CSL03 */
                             FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(previousFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
          FvM_FVJaspar_CopyTruncFreshnessValueToBuffer(latestFreshnessValueIdx, SecOCTruncatedFreshnessValue, SecOCTruncatedFreshnessValueLength);      /* SBSW_FVM_CONST_POINTER */

          ret = FvM_FVJaspar_DoRxTripFlagEvaluation((FvM_RxFreshnessValueInfoIterType) SecOCFreshnessValueID, SecOCAuthVerifyAttempts);

          if(ret == E_OK)       /* COV_FVM_2BIT_RESET_FLAG */
          {
            /* start of add for GWM requirement daijinshi 2021-1-19 */
            if(SecOCAuthVerifyAttempts > 0)
            {
                uint32 latestMessageCounter = FvM_FVJaspar_GetMessageCounter(latestFreshnessValueIdx);
                latestMessageCounter += (0x4000 * SecOCAuthVerifyAttempts);
                if(latestMessageCounter >= FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(latestFreshnessValueIdx))
                {
                    latestMessageCounter = FvM_GetMessageCounterMaxValueOfFreshnessValueLayoutInfo(latestFreshnessValueIdx);
                }
                FvM_FVJaspar_SetMessageCounter(latestFreshnessValueIdx, latestMessageCounter);
            }
            /* end of daijinshi add for GWM requirement daijinshi 2021-1-19 */
            VStdMemCpyRamToRam(SecOCFreshnessValue,     /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_SECOC_MEM_CPY_RAM2RAM */
                               FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
          }
        }
#  if((FVM_USE_DEFAULT_FRESHNESS_VALUE_IF_OUT_OF_SYNC_AFTER_START_UP_TIME == STD_OFF) && (FVM_SYNCSTATE == STD_ON))
#   if (FVM_STARTUPCYCLECOUNTER == STD_ON)
        else if(FvM_GetSyncState() == FVM_INITIAL_OUT_OF_SYNC_SYNCSTATE)
        {
          ret = E_OK;
        }
#   endif
        else
        {
          ret = E_NOT_OK;
        }
#  endif
        break;
# endif
# if(FVM_EXISTS_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
      case FVM_JASPAR_FRESHNESS_WITHOUT_RESET_COUNTER_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO:
      {
        FvM_FreshnessValueLayoutInfoIterType previousFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoPreviousIdxOfRxFreshnessValueInfo(SecOCFreshnessValueID);
        FvM_FreshnessValueLayoutInfoIterType latestFreshnessValueIdx = FvM_GetFreshnessValueLayoutInfoLatestIdxOfRxFreshnessValueInfo(SecOCFreshnessValueID);

        VStdMemCpyRamToRam(FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)),      /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_CSL03 */
                           SecOCTruncatedFreshnessValue, FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));

#  if(FVM_DEVMODEENABLED == STD_ON)
        if(FvM_IsDevModeEnabled())
        {
          ret = E_OK;
        }
        else
#  endif
        {
          ret = FvM_FVJaspar_CheckTripAndMessageCounter(latestFreshnessValueIdx, previousFreshnessValueIdx);
        }

        if(ret == E_OK)
        {
          VStdMemCpyRamToRam(SecOCFreshnessValue,       /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_SECOC_MEM_CPY_RAM2RAM */
                             FvM_GetAddrFreshnessValueArray(FvM_GetFreshnessValueArrayCompleteFreshnessStartIdxOfFreshnessValueLayoutInfo(latestFreshnessValueIdx)), FvM_GetFreshnessValueArrayCompleteFreshnessLengthOfFreshnessValueLayoutInfo(latestFreshnessValueIdx));
        }
      }
        break;
# endif
      default: /* COV_FVM_MISRA */
        /* do nothing */
        break;
    }
    SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_RX_FRESHNESS();
  }

  /* ----- Development Error Report --------------------------------------- */
# if(FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_GET_RX_FRESHNESS, errorId);
  }
# endif


  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(SecOCFreshnessValueLength);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(SecOCAuthVerifyAttempts); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FVM_DUMMY_STATEMENT(SecOCTruncatedFreshnessValueLength);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return ret;
}  /* PRQA S 6030, 6050, 6060, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
#endif

#if (FVM_MAINFUNCTION_API == STD_ON)
/**********************************************************************************************************************
  FvM_MainFunction
**********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, FVM_CODE) FvM_MainFunction(void)
{
  if(FvM_IsInitialized())
  {
# if (FVM_STARTUPCYCLECOUNTER == STD_ON)        /* COV_FVM_VAR_DEPENDENT_SWITCH */
    if(FvM_GetStartUpCycleCounter() != 0u)
    {
      FvM_DecStartUpCycleCounter();     /* SBSW_FVM_CSL_VAR_ACCESS */
      if(FvM_GetStartUpCycleCounter() == 0u)
      {
#  if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
        FvM_FVJaspar_SetVerifyOverrideStatus(SECOC_OVERRIDE_VERIFICATION_STATUS_CANCEL);
#  endif
#  if (FVM_SYNCSTATE == STD_ON)
        if(FvM_GetSyncState() == FVM_INITIAL_OUT_OF_SYNC_SYNCSTATE)
        {
          FvM_SetSyncState(FVM_INVALID_OUT_OF_SYNC_SYNCSTATE);  /* SBSW_FVM_CSL_VAR_ACCESS */
        }
#  endif
      }
    }
# endif

# if (FVM_SYNCMESSAGERECEPTIONTIMEOUTCOUNTER == STD_ON)
    SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_SYNC_STATE();

    FvM_DecSyncMessageReceptionTimeoutCounter();        /* SBSW_FVM_CSL_VAR_ACCESS */
    if(FvM_GetSyncMessageReceptionTimeoutCounter() == 0u)
    {
      FvM_SetSyncMessageReceptionTimeoutCounter(FvM_GetSyncMessageReceptionTimeoutCnt());       /* SBSW_FVM_CSL_VAR_ACCESS */
      SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_SYNC_STATE();
      (void) Dem_SetEventStatus(FvM_GetDemEventIdReference(0), DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_SYNC_STATE();
    }
# endif

# if (FVM_RECEPTIONTIMEOUTFORTRANSMISSIONCOUNTER == STD_ON)
    SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_SYNC_STATE();
    if(FvM_GetReceptionTimeoutForTransmissionCounter() != 0u)
    {
      FvM_DecReceptionTimeoutForTransmissionCounter();  /* SBSW_FVM_CSL_VAR_ACCESS */
    }
    SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_SYNC_STATE();
# endif

# if (FVM_RESETCOUNTERCYCLETIMECOUNTER == STD_ON)
    FvM_DecResetCounterCycleTimeCounter(); /* SBSW_FVM_CSL_VAR_ACCESS */
    if(FvM_GetResetCounterCycleTimeCounter() == 0u)
    {
      FvM_SetResetCounterCycleTimeCounter(FvM_GetResetCounterCycleTime()); /* SBSW_FVM_CSL_VAR_ACCESS */
      /* increment Reset Counter and update Signals */
      SchM_Enter_FvM_FVM_EXCLUSIVE_AREA_BOTH_FRESHNESS();
      FvM_IncLatestResetCounter(); /* SBSW_FVM_CSL_VAR_ACCESS */
      SchM_Exit_FvM_FVM_EXCLUSIVE_AREA_BOTH_FRESHNESS();
    }
# endif
  }
}
#endif

#if (FVM_STARTUPCYCLECOUNTER == STD_ON)
/**********************************************************************************************************************
  FvM_RestartStartUpAcceptanceTime
**********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 */
FUNC(void, FVM_CODE) FvM_RestartStartUpAcceptanceTime(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_UNINIT;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    FvM_SetStartUpCycleCounter(FvM_GetStartUpCycleCnt());       /* SBSW_FVM_CSL_VAR_ACCESS */
# if (FVM_EXISTS_JASPAR_FRESHNESS_PROCESSINGTYPEOFRXFRESHNESSVALUEINFO == STD_ON)
    FvM_FVJaspar_SetVerifyOverrideStatus(SECOC_OVERRIDE_VERIFICATION_STATUS_PASS_UNTIL_NOTICE);
# endif
# if (FVM_SYNCSTATE == STD_ON)
    FvM_SetSyncState(FVM_INITIAL_OUT_OF_SYNC_SYNCSTATE);        /* SBSW_FVM_CSL_VAR_ACCESS */
# endif
  }
  /* ----- Development Error Report --------------------------------------- */
# if(FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_FVM_RESTART_START_UP_ACCEPTANCE_TIME, errorId);
  }
# endif
  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if(FVM_DEVMODEENABLED == STD_ON)
/***********************************************************************************************************************
 *  FvM_SetDevelopmentMode()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FUNC(void, FVM_CODE) FvM_SetDevelopmentMode(boolean enableDevMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_UNINIT;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    FvM_SetDevModeEnabled(enableDevMode);       /* SBSW_FVM_CSL_VAR_ACCESS */
  }
  /* ----- Development Error Report --------------------------------------- */
# if(FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_SET_DEVELOPMENT_MODE, errorId);
  }
# endif

  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (FVM_LATESTTRIPCOUNTER  == STD_ON)
/***********************************************************************************************************************
 *  FvM_ResetTripAndResetCounter()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FUNC(void, FVM_CODE) FvM_ResetTripAndResetCounter(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = FVM_E_NO_ERROR;       /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  if(!FvM_IsInitialized())
  {
    errorId = FVM_E_UNINIT;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    FvM_SetLatestTripCounter(0);        /* SBSW_FVM_CSL_VAR_ACCESS */
    FvM_SetLatestResetCounter(0);       /* SBSW_FVM_CSL_VAR_ACCESS */

# if (FVM_FRESHNESSVALUEARRAY == STD_ON)
    VStdMemClr(FvM_GetAddrFreshnessValueArray(0), FvM_GetSizeOfFreshnessValueArray());  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_FVM_MEM_CPY_CLR */
# endif
# if(FVM_TRIPCOUNTERNVMBLOCKDESCRIPTOR == STD_ON)
    (void) NvM_WriteBlock(FvM_GetTripCounterNvMBlockDescriptor(0), &FvM_GetLatestTripCounter());        /* PRQA S 0315 */ /* MD_FvM_0315_NvMWriteBlock */ /* SBSW_FVM_FUNC_CALL */
# endif
  }
  /* ----- Development Error Report --------------------------------------- */
# if(FVM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != FVM_E_NO_ERROR)
  {
    (void) Det_ReportError(FVM_MODULE_ID, FVM_INSTANCE_ID_DET, FVM_SID_RESET_TRIP_AND_RESET_COUNTER, errorId);
  }
# endif

  FVM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif


#if (FVM_LATESTTRIPCOUNTERWITHOUTRESETCOUNTER == STD_ON)
/***********************************************************************************************************************
 *  FvM_TripCounterReadErrorDetected()
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 */
FUNC(void, FVM_CODE) FvM_TripCounterReadErrorDetected(void)
{
  FvM_SetTripCounterReadErrorDetectedFlag(TRUE); /* SBSW_FVM_CSL_VAR_ACCESS */
}
#endif

#define FVM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

  MD_FvM_0315_NvMWriteBlock: Misra Dir 1.1
     Reason:      The function 'NvM_WriteBlock' from the NVRAM Manager has a void pointer as a function parameter.
     Risk:        No risk, because the underlying pointer type is known.
     Prevention:  No prevention necessary.

  MD_FvM_2985: Misra Rule 2.2
     Reason:      The implementation is clearer with the &-operation with the ff value.
     Risk:        No risk.
     Prevention:  No prevention necessary.

    MD_FvM_2985_ClearAcceptanceWindow: Misra Rule 2.2
     Reason:      If the ClearAcceptanceWindow is 0 the operation has no effect.
     Risk:        No risk.
     Prevention:  No prevention necessary.

  MD_FvM_2991: Misra Rule 14.3
     Reason:      The value of the if-controlling expression depends on the configuration.
     Risk:        No risk.
     Prevention:  No prevention necessary.

 MD_FvM_2741: Misra Rule 14.3
     Reason:      The value of the if-controlling expression depends on the configuration.
     Risk:        No risk.
     Prevention:  No prevention necessary.

  MD_FvM_2995: Misra Rule 2.2
     Reason:      The value of the logical operation depends on the configuration.
     Risk:        No risk.
     Prevention:  No prevention necessary.

  MD_FvM_2880: Misra Rule 2.1
     Reason:      Code is unreachable due to the configuration.
     Risk:        No risk.
     Prevention:  No prevention necessary.

  MD_FvM_2982: Misra Rule 2.2
     Reason:      Dependent on the configuration the value of the object is never being used before modified.
     Risk:        No risk.
     Prevention:  No prevention necessary.
*/
/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_FVM_CSL03
    \DESCRIPTION Access to Table1 via indirection over Table2.
    \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_FVM_CONST_POINTER
    \DESCRIPTION Pointer is handed over to a function
    \COUNTERMEASURE \N The pointer references a constant memory location (P2CONST). Therefore it can not be written.

  \ID SBSW_FVM_CHECKED_POINTER
    \DESCRIPTION Pointer write access
    \COUNTERMEASURE \R It is checked at runtime that the pointer is no NULL_PTR. The caller has to ensure that the pointer references a valid memory location.

  \ID SBSW_FVM_CHECKED_POINTER_1
    \DESCRIPTION Pointer is handed over to a function
    \COUNTERMEASURE \R It is checked at runtime that the pointer is no NULL_PTR. The caller has to ensure that the pointer references a valid memory location.
                       The length of the buffer is checked for sufficient length.

  \ID SBSW_FVM_MEM_CPY_CLR
    \DESCRIPTION A Pointer is handed to a function to clear the corresponding memory.
    \COUNTERMEASURE \N The address is read via a ComStackLib macro and is valid. The corresponding size is also read via the corresponding ComStackLib macro and ensures that only the correct length is cleared.

  \ID SBSW_FVM_CSL_FCT_PTR
    \DESCRIPTION A Function Pointer is called.
    \COUNTERMEASURE \N The function pointer is read using a ComStackLib macro and is therefore valid. Only one function pointer is written to the corresponding table, therefore it can always be read using index 0.

  \ID SBSW_SECOC_MEM_CPY_RAM2RAM
    \DESCRIPTION Call to copy RAM data to RAM
    \COUNTERMEASURE \R The passed pointers are either read by ComStackLib macros or are passed through and checked at the beginning of the function. The caller has to ensure that it references a valid memory location.
                    \R The size of the copy operation is checked against the freshness value length provided by the caller.

  \ID SBSW_FVM_PTR_WRITE_ACCESS
    \DESCRIPTION A pointer is written
    \COUNTERMEASURE \R The passed pointer is passed through and checked in the calling function. The caller has to ensure that it references a valid memory location.
                    \R The size of the pointer is checked in the calling function.

  \ID SBSW_FVM_CSL_VAR_ACCESS
    \DESCRIPTION A ComStackLib generated variable is accessed.
    \COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables address without pointer arithmetic.

  \ID SBSW_FVM_FUNC_CALL
    \DESCRIPTION A Function is called.
    \COUNTERMEASURE \N The passed parameter are read via a ComStackLib macro and are valid.

  \ID SBSW_FVM_COPY_SRC_TO_DEST
    \DESCRIPTION Array write access.
    \COUNTERMEASURE \N The destByteIdx is calculated with respect to the passed copyBitLen.

  \ID SBSW_FVM_FUNC_CALL_STACK_PARAM
    \DESCRIPTION A Function is called.
    \COUNTERMEASURE \N The passed address parameter belongs to a stack value and is valid.

   SBSW_JUSTIFICATION_END */
/* START_COVERAGE_JUSTIFICATION

  \ID COV_FVM_VAR_DEV_ERROR_DETECT
    \ACCEPT TX
    \REASON Det error detection must always be enabled for SafeBsw.

  \ID COV_FVM_VAR_SYNC_MSG_ALWAYS_ON
    \ACCEPT TX
    \REASON This switch is always on. A Rx sync message does always exist in the FvM.

  \ID COV_FVM_VAR_DEPENDENT_SWITCH
    \ACCEPT TX
    \REASON The nested switch depends on a previous switch.

  \ID COV_FVM_RESET_COUNTER_BIT_COUNT
    \ACCEPT TX
    \REASON Due to the configuration this condition evaluates always to true. The Reset Counter bit size is fixed for one configuration.

  \ID COV_FVM_TRIP_COUNTER_BIT_COUNT
    \ACCEPT TX
    \ACCEPT XX
    \ACCEPT XF
    \REASON Due to the configuration this condition evaluates always to true. The Trip Counter bit size is fixed for one configuration.

  \ID COV_FVM_MESSAGE_COUNTER_BIT_COUNT
    \ACCEPT TX
    \ACCEPT XF
    \REASON Due to the configuration this condition evaluates always to true or false.

  \ID COV_FVM_MISRA
    \ACCEPT X
    \ACCEPT XF
    \REASON [MSR_COV_MISRA]

   \ID COV_FVM_ALWAYS_TRUE_MISRA
    \ACCEPT TX
    \REASON [MSR_COV_MISRA]

   \ID COV_FVM_2BIT_RESET_FLAG
    \ACCEPT TX
    \REASON In configurations with 2 bit reset flag the evaluation will always be successful.

   \ID COV_FVM_TX_ONLY_CONF_TX_tx_xx
    \ACCEPT TX tx xx
    \REASON In Tx Only configurations the Sync message is the only Rx message and has fix layout.

   \ID COV_FVM_TX_ONLY_CONF_XF
    \ACCEPT XF
    \REASON In Tx Only configurations the Sync message is the only Rx message and has fix layout.

   \ID COV_FVM_TX_ONLY_CONF_TX
    \ACCEPT TX
    \REASON In Tx Only configurations the Sync message is the only Rx message and has fix layout.

   \ID COV_FVM_TRUNC_FRESHNESS_COPY_TX_tx_xx
    \ACCEPT TX tx xx
    \REASON Due to the configuration the offset will always be true.

   \ID COV_FVM_TRUNC_FRESHNESS_COPY_XF
    \ACCEPT XF
    \REASON Due to the configuration the sum of truncated Freshness length and offset is never smaller than 8.

   \ID COV_FVM_BYTE_LENGTH
    \ACCEPT XF
    \ACCEPT TX
    \REASON Due to the configuration the result always evaluates one way.

   \ID COV_FVM_WITHOUT_RESETCOUNTER_TX
    \ACCEPT TX
    \REASON The statement is always true if only Without ResetCounter processings exist.

   \ID COV_FVM_ALWAYS_TRUE_TRIP_FLAG
    \ACCEPT TX
    \REASON Due to the Specification the else is required.

   \ID COV_FVM_ALWAYS_TRUE_DEF_PROGRAMMING
    \ACCEPT TX
    \REASON Due to defensive programming.

   \ID COV_FVM_NO_MASTER_CONF
    \ACCEPT TX
    \REASON The FvM has not the role master.

  \ID COV_FVM_REST_COUNTER_MAX_IN_MASTER_CONF
    \ACCEPT XF
    \REASON The FvM has the role master and the reset counter cannot be reached in acceptable time.

  \ID COV_REST_COUNTER_CYCLE_TIME
    \ACCEPT TX
    \REASON In the Master Only Configuration there should always be a rest counter cycle time.

    \ID COV_TRIP_REST_COUNTER_BIT_SIZE_MASTER
    \ACCEPT TX
    \ACCEPT XF
    \ACCEPT XX
    \REASON The condition depends on the layout of the trip reset counter sync message.

END_COVERAGE_JUSTIFICATION
*/


/**********************************************************************************************************************
 *  END OF FILE: FvM.c
 *********************************************************************************************************************/
