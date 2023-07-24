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
/*      \file   Csm_Rte.h
 *      \brief  MICROSAR Crypto Service Manager (CSM) RTE
 *
 *      \details  Description of the MICROSAR Crypto Service Manager (CSM) service APIs used only by RTE
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_CancelJob43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_CancelJob43x( uint32 jobId, Crypto_OperationModeType mode )
 *  \note          Wrapper function of Csm_CancelJob(). Declared and called by Rte.
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  Csm_CancelJobNoOpMode()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_CancelJobNoOpMode( uint32 jobId )
 *  \note          Wrapper function of Csm_CancelJob(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_HashDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_HashDataRef(  uint32 jobId,
 *                                                                Crypto_OperationModeType mode,
 *                                                                P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                uint32 dataLength,
 *                                                                P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                                P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_Hash(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_MacGenerate43x()
 *********************************************************************************************************************/
/*! \fn           FUNC( Std_ReturnType, CSM_CODE ) Csm_MacGenerate43x(  uint32 jobId,
 *                                                                      Crypto_OperationModeType mode,
 *                                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                      uint32 dataLength,
 *                                                                      P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) macPtr,
 *                                                                      P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) macLengthPtr )
 *  \note          Wrapper function of Csm_MacGenerate(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_MacGenerateDataRef()
 *********************************************************************************************************************/
/*! \fn           FUNC( Std_ReturnType, CSM_CODE ) Csm_MacGenerateDataRef(  uint32 jobId,
 *                                                                      Crypto_OperationModeType mode,
 *                                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                      uint32 dataLength,
 *                                                                      P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) macPtr,
 *                                                                      P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) macLengthPtr )
 *  \note          Wrapper function of Csm_MacGenerate(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_MacVerify43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_MacVerify43x(  uint32 jobId,
 *                                                                     Crypto_OperationModeType mode,
 *                                                                     P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                     uint32 dataLength,
 *                                                                     P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) macPtr,
 *                                                                     uint32 macLength,
 *                                                    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr )
 *  \note          Wrapper function of Csm_MacVerify(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_MacVerifyDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_MacVerifyDataRef(  uint32 jobId,
 *                                                                     Crypto_OperationModeType mode,
 *                                                                     P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                     uint32 dataLength,
 *                                                                     P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) macPtr,
 *                                                                     uint32 macLength,
 *                                                    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr )
 *  \note          Wrapper function of Csm_MacVerify(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_Encrypt43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_Encrypt43x( uint32 jobId,
 *                                                                  Crypto_OperationModeType mode,
 *                                                                  P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                  uint32 dataLength,
 *                                                                  P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                                P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_Encrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_EncryptDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_EncryptDataRef( uint32 jobId,
 *                                                                  Crypto_OperationModeType mode,
 *                                                                  P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                  uint32 dataLength,
 *                                                                  P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                                P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_Encrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_Decrypt43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_Decrypt43x(  uint32 jobId,
 *                                                                   Crypto_OperationModeType mode,
 *                                                                   P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                   uint32 dataLength,
 *                                                                   P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                                   P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_Decrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_DecryptDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_DecryptDataRef(  uint32 jobId,
 *                                                                   Crypto_OperationModeType mode,
 *                                                                   P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                                   uint32 dataLength,
 *                                                                   P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                                   P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_Decrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_AEADEncrypt43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_AEADEncrypt43x(  uint32 jobId,
 *                                                                Crypto_OperationModeType mode,
 *                                                                P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) plaintextPtr,
 *                                                                uint32 plaintextLength,
 *                                                                P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) associatedDataPtr,
 *                                                                uint32 associatedDataLength,
 *                                                                P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) ciphertextPtr,
 *                                                                P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) ciphertextLengthPtr,
 *                                                                P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) tagPtr,
 *                                                                P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) tagLengthPtr )
 *  \note          Wrapper function of Csm_AEADEncrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_AEADEncryptDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_AEADEncryptDataRef(  uint32 jobId,
 *                                                                Crypto_OperationModeType mode,
 *                                                                P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) plaintextPtr,
 *                                                                uint32 plaintextLength,
 *                                                                P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) associatedDataPtr,
 *                                                                uint32 associatedDataLength,
 *                                                                P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) ciphertextPtr,
 *                                                                P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) ciphertextLengthPtr,
 *                                                                P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) tagPtr,
 *                                                                P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) tagLengthPtr )
 *  \note          Wrapper function of Csm_AEADEncrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_AEADDecrypt43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_AEADDecrypt43x( uint32 jobId,
 *                                                      Crypto_OperationModeType mode,
 *                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) ciphertextPtr,
 *                                                      uint32 ciphertextLength,
 *                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) associatedDataPtr,
 *                                                      uint32 associatedDataLength,
 *                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) tagPtr,
 *                                                      uint32 tagLength,
 *                                                      P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) plaintextPtr,
 *                                                      P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) plaintextLengthPtr,
 *                                                      P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr )
 *  \note          Wrapper function of Csm_AEADDecrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_AEADDecryptDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_AEADDecryptDataRef( uint32 jobId,
 *                                                      Crypto_OperationModeType mode,
 *                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) ciphertextPtr,
 *                                                      uint32 ciphertextLength,
 *                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) associatedDataPtr,
 *                                                      uint32 associatedDataLength,
 *                                                      P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) tagPtr,
 *                                                      uint32 tagLength,
 *                                                      P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) plaintextPtr,
 *                                                      P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) plaintextLengthPtr,
 *                                                      P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr )
 *  \note          Wrapper function of Csm_AEADDecrypt(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_SignatureGenerate43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_SignatureGenerate43x(  uint32 jobId,
 *                                                              Crypto_OperationModeType mode,
 *                                                              P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                              uint32 dataLength,
 *                                                              P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                              P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_SignatureGenerate(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_SignatureGenerateDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_SignatureGenerateDataRef(  uint32 jobId,
 *                                                              Crypto_OperationModeType mode,
 *                                                              P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                              uint32 dataLength,
 *                                                              P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                              P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_SignatureGenerate(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_SignatureVerify43x()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_SignatureVerify43x(  uint32 jobId,
 *                                                         Crypto_OperationModeType mode,
 *                                                         P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                         uint32 dataLength,
 *                                                         P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) signaturePtr,
 *                                                         uint32 signatureLength,
 *                                                         P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr )
 *  \note          Wrapper function of Csm_SignatureVerify(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_SignatureVerifyDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_SignatureVerifyDataRef(  uint32 jobId,
 *                                                         Crypto_OperationModeType mode,
 *                                                         P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) dataPtr,
 *                                                         uint32 dataLength,
 *                                                         P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) signaturePtr,
 *                                                         uint32 signatureLength,
 *                                                         P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr )
 *  \note          Wrapper function of Csm_SignatureVerify(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_RandomGenerateDataRef()
 *********************************************************************************************************************/
/*! \fn            FUNC( Std_ReturnType, CSM_CODE ) Csm_RandomGenerateDataRef( uint32 jobId,
 *                                                       P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) resultPtr,
 *                                                       P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) resultLengthPtr )
 *  \note          Wrapper function of Csm_RandomGenerate(). Declared and called by Rte.
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  Csm_KeyElementGet43x()
 *********************************************************************************************************************/
/*! \fn           FUNC( Std_ReturnType, CSM_CODE ) Csm_KeyElementGet43x( uint32 keyId,
                                                                   uint32 keyElementId,
                                                                   P2VAR( uint8, AUTOMATIC, CSM_APPL_VAR ) keyPtr,
                                                                   P2VAR( uint32, AUTOMATIC, CSM_APPL_VAR ) keyLengthPtr )
 *  \note         Wrapper function of Csm_KeyElementGet(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_CertificateParse43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_CertificateParse43x( uint32 keyId )
 *  \note          Wrapper function of Csm_CertificateParse(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_CertificateVerify43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_CertificateVerify43x( uint32 keyId,
 *                                                                          uint32 verifyKeyId,
 *                                                    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_VAR) verifyPtr)
 *  \note          Wrapper function of Csm_CertificateVerify(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_KeyCopy43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_KeyCopy43x( uint32 keyId, uint32 targetKeyId )
 *  \note          Wrapper function of Csm_KeyCopy(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_KeyDerive43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_KeyDerive43x( uint32 keyId, uint32 targetKeyId )
 *  \note          Wrapper function of Csm_KeyDerive(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_KeyElementCopy43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_KeyElementCopy43x( uint32 keyId,
 *                                                                       uint32 keyElementId,
 *                                                                       uint32 targetKeyId,
 *                                                                       uint32 targetKeyElementId )
 *  \note          Wrapper function of Csm_KeyElementCopy(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_KeyExchangeCalcPubVal43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_KeyExchangeCalcPubVal43x( uint32 keyId,
 *                                                            P2VAR(uint8, AUTOMATIC, CSM_APPL_VAR) publicValuePtr,
 *                                                            P2VAR(uint32, AUTOMATIC, CSM_APPL_VAR) publicValueLengthPtr )
 *  \note          Wrapper function of Csm_KeyExchangeCalcPubVal(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_KeyExchangeCalcSecret43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_KeyExchangeCalcSecret43x( uint32 keyId,
                                                         P2CONST(uint8, AUTOMATIC, CSM_APPL_VAR) partnerPublicValuePtr,
                                                         uint32 partnerPublicValueLength )
 *  \note          Wrapper function of Csm_KeyExchangeCalcSecret(). Declared and called by Rte.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Csm_KeyGenerate43x()
 *********************************************************************************************************************/
/*! \fn            FUNC(Std_ReturnType, CSM_CODE) Csm_KeyGenerate43x( uint32 keyId )
 *  \note          Wrapper function of Csm_KeyGenerate(). Declared and called by Rte.
 *********************************************************************************************************************/
