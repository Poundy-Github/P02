/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: SecOC
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecOC_Cot.h
 *   Generation Time: 2020-11-11 17:41:41
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (SECOC_COT_H)
# define SECOC_COT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SecOC_Types.h"
#include "SecOC_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define SECOC_START_SEC_APPL_CODE
#include "MemMap.h"   /* PRQA S 5087 */  /* MD_MSR_MemMap */

 /* configuratble SecOC verification status callouts */ 
FUNC(void, SECOC_APPL_CODE) FvM_VerificationStatusCallout(SecOC_VerificationStatusType verificationStatus);
FUNC(void, SECOC_APPL_CODE) SecOc_Verification_Status_Callout_With_Secured_Pdu(SecOC_VerificationStatusType verificationStatus, const PduInfoType* receivedSecuredPDU, uint8* fullfreshnessValue, uint32 fullfreshnessValueLength);


/***********************************************************************************************************************
 *  SecOC_GetTxFreshnessTruncData()
 **********************************************************************************************************************/
/*!
 * \brief     Getter for freshness and truncated freshness values on transmission side.
 * \details   This interface is used by the SecOC to obtain the current freshness value. The 
 *            interface function provides also the truncated freshness transmitted in the secured I-PDU. 
 * \param[in]  SecOCFreshnessValueID      Holds the identifier of the freshness value. 
 * \param[out] SecOCFreshnessValue        Holds the current freshness value.
 * \param[in, out]  SecOCFreshnessValueLength Holds the length of the provided freshness in bits.
 * \param[out] SecOCTruncatedFreshnessValue  Holds the truncated freshness to be included into the Secured I-PDU. The parameter is optional. 
 * \param[in, out]  SecOCTruncatedFreshnessValueLength Provides the truncated freshness length configured for this freshness. 
 *                                                     The function may adapt the value if needed or can leave it unchanged if the configured 
 *                                                     length and provided length is the same. 
 * \return     Std_ReturnType
 *              E_OK:     request successful 
 *              E_NOT_OK: request failed, a freshness value cannot be provided due to 
 *                        general issues for freshness or this FreshnessValueId.  
 *              E_BUSY:   The freshness information can temporarily not be provided 
 * \context    TASK
 * \synchronous TRUE
 * \reentrant  TRUE, for different FreshnessValueIDs.
 */
FUNC(Std_ReturnType, SECOC_APPL_CODE) SecOC_GetTxFreshnessTruncData(uint16 SecOCFreshnessValueID,  P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,  P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue, P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValueLength);

/***********************************************************************************************************************
 *  SecOC_SPduTxConfirmation()
 **********************************************************************************************************************/
/*!
 * \brief     Confirmation of initiated transmission.
 * \details   This interface is used by the SecOC to indicate that the Secured I-PDU has been initiated for transmission.  
 * \param[in]  SecOCFreshnessValueID     Holds the identifier of the freshness value. 
 * \return     none.
 * \context    TASK
 * \synchronous TRUE
 * \reentrant  TRUE, for different FreshnessValueIDs.
 */ 
FUNC(void, SECOC_APPL_CODE) SecOC_SPduTxConfirmation(uint16 SecOCFreshnessValueID);

/***********************************************************************************************************************
 *  SecOC_GetRxFreshness()
 **********************************************************************************************************************/
/*!
 * \brief     Getter for freshness values on reception side.
 * \details   This interface is used by the SecOC to obtain the current freshness value.  
 * \param[in]  SecOCFreshnessValueID      Holds the identifier of the freshness value. 
 * \param[in]  SecOCTruncatedFreshnessValue Holds the truncated freshness value that was contained in the Secured I-PDU.
 * \param[in]  SecOCTruncatedFreshnessValueLength  Holds the length in bits of the truncated freshness value. 
 * \param[in]  SecOCAuthVerifyAttempts     Holds the number of authentication verify attempts of this PDU since the last reception. 
 *                                         The value is 0 for the first attempt and incremented on every unsuccessful verification attempt. 
 * \param[out] SecOCFreshnessValue         Holds the number of authentication verify attempts of this PDU since the last reception. 
 *                                         The value is 0 for the first attempt and incremented on every unsuccessful verification attempt. 
 * \param[in, out] SecOCFreshnessValueLength Holds the length in bits of the freshness value. 
 * \return     Std_ReturnType
 *              E_OK:     request successful 
 *              E_NOT_OK: request failed, a freshness value cannot be provided due to 
 *                        general issues for freshness or this FreshnessValueId.  
 *              E_BUSY:   The freshness information can temporarily not be provided 
 * \context    TASK
 * \synchronous TRUE
 * \reentrant  TRUE, for different FreshnessValueIDs.
 */ 
FUNC(Std_ReturnType, SECOC_APPL_CODE) SecOC_GetRxFreshness(uint16 SecOCFreshnessValueID,  P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue,  uint32 SecOCTruncatedFreshnessValueLength, uint16 SecOCAuthVerifyAttempts, P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue, P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength);


# if (SECOC_CUSTOM_AUTHENTICATION_API == STD_ON)
/***********************************************************************************************************************
 *  SecOC_GenerateAuthenticationInfo()
 **********************************************************************************************************************/
/*!
 * \brief       Custom callout for calculating the authenticator value
 * \details     The authenticator must be calculated inside this callout using the customer algorithms.
 * \param[in]   txFreshnessId                Id of the freshness value.
 * \param[in]   txAuthenticPduInfoPtr        Pointer to the authentic Pdu which shall be used as input for the Authenticator calculation.
 * \param[out]  txAuthenticatorPtr           Pointer to the authenticator buffer. Write the calculated authenticator to this buffer.
 * \param[in]   txAuthenticatorLength        Length of the authenticator buffer.
 * \return      E_OK                         Calculation successful.
 *              E_NOT_OK                     Calculation failed.
 *              SECOC_E_BUSY                 Calculation can not be executed at this moment. The SecOC will call the API again depending on the Build Attempts counter.
 * \context     TASK
 * \synchronous TRUE
 * \reentrant   TRUE, for different FreshnessValueIDs.
 */ 
FUNC(Std_ReturnType, SECOC_APPL_CODE) SecOC_GenerateAuthenticationInfo(uint16 txFreshnessId,
                                                                       P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) txAuthenticPduInfoPtr,
                                                                       P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) txAuthenticatorPtr,
                                                                       uint32 txAuthenticatorLength);

/***********************************************************************************************************************
 *  SecOC_VerifyAuthenticationInfo()
 **********************************************************************************************************************/
/*!
 * \brief       Custom callout for the verification of the received secured Pdu
 * \details     The authenticator must be verified inside this callout using the customer algorithms.  
 * \param[in]   rxFreshnessId            Id of the freshness value.
 * \param[in]   rxAuthenticPduInfoPtr    Pointer to the authentic Pdu.
 * \param[in]   rxAuthenticatorPtr       Pointer to the authenticator buffer. 
 * \param[in]   rxAuthenticatorLength    Length of the authenticator buffer. 
 * \param[out]  verifyResultPtr          Pointer to result buffer.  
 * \return      E_OK                     Verification successful. 
 *              E_NOT_OK                 Verification failed.  
 *              SECOC_E_BUSY             Verification can not be executed at this moment. The SecOC will call the API again depending on the Build Attempts counter.
 * \context     TASK
 * \synchronous TRUE
 * \reentrant   TRUE, for different FreshnessValueIDs.
 */ 
FUNC(Std_ReturnType, SECOC_APPL_CODE) SecOC_VerifyAuthenticationInfo(uint16 rxFreshnessId, 
                                                                     P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) rxAuthenticPduInfoPtr, 
                                                                     P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) rxAuthenticatorPtr,
                                                                     uint32 rxAuthenticatorLength,
                                                                     P2VAR(Crypto_VerifyResultType, AUTOMATIC, SECOC_APPL_DATA) verifyResultPtr);
# endif

#define SECOC_STOP_SEC_APPL_CODE
#include "MemMap.h"   /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif  /* SECOC_COT_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Cot.h
**********************************************************************************************************************/
