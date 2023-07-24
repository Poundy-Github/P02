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
 *              File: SecOC_Lcfg.h
 *   Generation Time: 2022-03-02 17:10:52
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/



#if !defined (SECOC_LCFG_H)
# define SECOC_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "SecOC_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/* Freshness Management function names */
#define GetTxFreshnessTruncData_FuncName  SecOC_GetTxFreshnessTruncData
#define GetTxFreshness_FuncName           SecOC_GetTxFreshness
#define SPduTxConfirmation_FuncName       SecOC_SPduTxConfirmation
#define GetRxFreshness_FuncName           SecOC_GetRxFreshness
#define GetRxFreshnessAuthData_FuncName   SecOC_GetRxFreshnessAuthData

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCDataSwitches  SecOC Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SECOC_AUTHENTICPDUDATACONTAINER                                                             STD_ON
#define SECOC_AUTHENTICSPLITPDUTRANSMIT                                                             STD_OFF  /**< Deactivateable: 'SecOC_AuthenticSplitPduTransmit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_AUTHENTICATORCACHE                                                                    STD_ON
#define SECOC_CANFDLENGTHCOMPVALUEINFO                                                              STD_OFF  /**< Deactivateable: 'SecOC_CanFDLengthCompValueInfo' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_LOWERLENGTHVALUEOFCANFDLENGTHCOMPVALUEINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_CanFDLengthCompValueInfo.LowerLengthValue' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_UPPERLENGTHVALUEOFCANFDLENGTHCOMPVALUEINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_CanFDLengthCompValueInfo.UpperLengthValue' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_CANCELTXTRANSMIT                                                                      STD_OFF  /**< Deactivateable: 'SecOC_CancelTxTransmit' Reason: '/ActiveEcuC/PduR/SecOC[0:PduRCancelTransmit] is configured to 'false'' */
#define SECOC_CRYPTOGRAPHICPDUTRANSMIT                                                              STD_OFF  /**< Deactivateable: 'SecOC_CryptographicPduTransmit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_CURRENTMESSAGELINKER                                                                  STD_OFF  /**< Deactivateable: 'SecOC_CurrentMessageLinker' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_DEVMODEENABLED                                                                        STD_ON
#define SECOC_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'SecOC_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'SecOC_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITIALIZED                                                                           STD_ON
#define SECOC_NUMBEROFMESSAGESTOOVERRIDE                                                            STD_ON
#define SECOC_RXAUTHENTICPDUSIZEOFFSET                                                              STD_ON
#define SECOC_RXBUILDATTEMPTSCOUNTER                                                                STD_ON
#define SECOC_RXIMMEDIATEPROCESSINGONGOING                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxImmediateProcessingOngoing' Reason: 'Neither immediate Rx callback processing nor immediate Rx Pdu processing is configured.' */
#define SECOC_RXPDUINFO                                                                             STD_ON
#define SECOC_AUTHDATAFRESHNESSLENOFRXPDUINFO                                                       STD_ON
#define SECOC_AUTHDATAFRESHNESSOFRXPDUINFO                                                          STD_ON
#define SECOC_AUTHDATAFRESHNESSSTARTBYTEPOSITIONOFRXPDUINFO                                         STD_ON
#define SECOC_AUTHINFOLENGTHOFRXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthInfoLength' Reason: 'Custom API is not configured.' */
#define SECOC_AUTHENTICEXTERNALIDOFRXPDUINFO                                                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAENDIDXOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataEndIdx' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATALENGTHOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataLength' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATASTARTIDXOFRXPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataStartIdx' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAUSEDOFRXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataUsed' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                                STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                                STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                              STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                                  STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFRXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFRXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFRXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFRXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                      STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFRXPDUINFO                          STD_ON
#define SECOC_AUTHENTICATIONLAYERIDOFRXPDUINFO                                                      STD_ON
#define SECOC_AUTHENTICATORCACHEENDIDXOFRXPDUINFO                                                   STD_ON
#define SECOC_AUTHENTICATORCACHELENGTHOFRXPDUINFO                                                   STD_ON
#define SECOC_AUTHENTICATORCACHESTARTIDXOFRXPDUINFO                                                 STD_ON
#define SECOC_BUILDATTEMPTSOFRXPDUINFO                                                              STD_ON
#define SECOC_CONTAINERHEADERSIZEOFRXPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.ContainerHeaderSize' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_DATAIDFIRSTBYTEOFRXPDUINFO                                                            STD_ON
#define SECOC_DATAIDOFRXPDUINFO                                                                     STD_ON
#define SECOC_DATAIDSECONDBYTEOFRXPDUINFO                                                           STD_ON
#define SECOC_EXTERNALFRESHNESSIDOFRXPDUINFO                                                        STD_ON
#define SECOC_NUMBEROFMESSAGESTOOVERRIDEIDXOFRXPDUINFO                                              STD_ON
#define SECOC_PDUPROCESSINGOFRXPDUINFO                                                              STD_ON
#define SECOC_PDUTYPEOFRXPDUINFO                                                                    STD_ON
#define SECOC_RXSECUREDPDUAREAINFOIDXOFRXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSecuredPduAreaInfoIdx' Reason: 'the optional indirection is deactivated because RxSecuredPduAreaInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSECUREDPDUAREAINFOUSEDOFRXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSecuredPduAreaInfoUsed' Reason: 'the optional indirection is deactivated because RxSecuredPduAreaInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSPLITMESSAGECOUNTERIDXOFRXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSplitMessageCounterIdx' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSPLITMESSAGECOUNTERUSEDOFRXPDUINFO                                                  STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.RxSplitMessageCounterUsed' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                                STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAENDIDXOFRXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataEndIdx' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATALENGTHOFRXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataLength' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATASTARTIDXOFRXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataStartIdx' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAUSEDOFRXPDUINFO                              STD_OFF  /**< Deactivateable: 'SecOC_RxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataUsed' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFRXPDUINFO                                      STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDULENGTHOFRXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                                STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTPSECUREDPDUUSEDOFRXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                        STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFRXPDUINFO                        STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                      STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFRXPDUINFO                          STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO                     STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFRXPDUINFO                         STD_ON
#define SECOC_SECUREDRXPDUVERFICATIONOFRXPDUINFO                                                    STD_ON
#define SECOC_TRUNCAUTHSTARTBITINBYTEOFRXPDUINFO                                                    STD_ON
#define SECOC_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFRXPDUINFO                                          STD_ON
#define SECOC_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFRXPDUINFO                                         STD_ON
#define SECOC_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                                          STD_ON
#define SECOC_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                            STD_ON
#define SECOC_VERIFYATTEMPTSOFRXPDUINFO                                                             STD_ON
#define SECOC_VERIFYOVERRIDESTATUSIDXOFRXPDUINFO                                                    STD_ON
#define SECOC_VERIFYRESULTIDXOFRXPDUINFO                                                            STD_ON
#define SECOC_WAITFORCALLBACKOFRXPDUINFO                                                            STD_ON
#define SECOC_TRUNCATEDAUTHENTICATIONLENGTHOFRXPDUINFO                                              STD_ON
#define SECOC_TRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                                              STD_ON
#define SECOC_RXPDUSTATE                                                                            STD_ON
#define SECOC_RXSECUREDPDUAREABUFFER                                                                STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_RXSECUREDPDUAREAINFO                                                                  STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_LENGTHOFRXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaInfo.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_OFFSETOFRXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduAreaInfo.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_RXSECUREDPDUINFO                                                                      STD_ON
#define SECOC_AUTHHEADERLENGTHOFRXSECUREDPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.AuthHeaderLength' Reason: 'the value of SecOC_AuthHeaderLengthOfRxSecuredPduInfo is always '0' due to this, the array is deactivated.' */
#define SECOC_CURRENTMESSAGELINKERENDIDXOFRXSECUREDPDUINFO                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.CurrentMessageLinkerEndIdx' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_CURRENTMESSAGELINKERLENGTHOFRXSECUREDPDUINFO                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.CurrentMessageLinkerLength' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_CURRENTMESSAGELINKERSTARTIDXOFRXSECUREDPDUINFO                                        STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.CurrentMessageLinkerStartIdx' Reason: 'The Parameter SecOCMaxMessageLinkerSizeOfRxPdus is == 0, so no Messagelinker is required.' */
#define SECOC_INVALIDHNDOFRXSECUREDPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.InvalidHnd' Reason: 'the value of SecOC_InvalidHndOfRxSecuredPduInfo is always 'false' due to this, the array is deactivated.' */
#define SECOC_MESSAGELINKLENOFRXSECUREDPDUINFO                                                      STD_ON
#define SECOC_MESSAGELINKPOSOFRXSECUREDPDUINFO                                                      STD_ON
#define SECOC_MESSAGELINKERSTARTBYTEINCRYPTOPDUOFRXSECUREDPDUINFO                                   STD_ON
#define SECOC_MESSAGETYPEOFRXSECUREDPDUINFO                                                         STD_ON
#define SECOC_MESSAGESLINKCRYPTOPDUSRCBITOFFSETOFRXSECUREDPDUINFO                                   STD_ON
#define SECOC_MINIMUMPDULENGTHOFRXSECUREDPDUINFO                                                    STD_ON
#define SECOC_PDUFIXLENGTHOFRXSECUREDPDUINFO                                                        STD_ON
#define SECOC_RXPDUINFOIDXOFRXSECUREDPDUINFO                                                        STD_ON
#define SECOC_RXSPLITMESSAGECOUNTERIDXOFRXSECUREDPDUINFO                                            STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.RxSplitMessageCounterIdx' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxSecuredPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_RXSPLITMESSAGECOUNTERUSEDOFRXSECUREDPDUINFO                                           STD_OFF  /**< Deactivateable: 'SecOC_RxSecuredPduInfo.RxSplitMessageCounterUsed' Reason: 'the optional indirection is deactivated because RxSplitMessageCounterUsedOfRxSecuredPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERENDIDXOFRXSECUREDPDUINFO                                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERLENGTHOFRXSECUREDPDUINFO                                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSTARTIDXOFRXSECUREDPDUINFO                                     STD_ON
#define SECOC_RXSPLITMESSAGECOUNTER                                                                 STD_OFF  /**< Deactivateable: 'SecOC_RxSplitMessageCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_RXTPWRITTENBYTESCOUNTER                                                               STD_ON
#define SECOC_SECUREDPDUDATACONTAINER                                                               STD_ON
#define SECOC_SENDDEFAULTAUTHENTICATION                                                             STD_ON
#define SECOC_SIZEOFAUTHENTICPDUDATACONTAINER                                                       STD_ON
#define SECOC_SIZEOFAUTHENTICATORCACHE                                                              STD_ON
#define SECOC_SIZEOFNUMBEROFMESSAGESTOOVERRIDE                                                      STD_ON
#define SECOC_SIZEOFRXAUTHENTICPDUSIZEOFFSET                                                        STD_ON
#define SECOC_SIZEOFRXBUILDATTEMPTSCOUNTER                                                          STD_ON
#define SECOC_SIZEOFRXPDUINFO                                                                       STD_ON
#define SECOC_SIZEOFRXPDUSTATE                                                                      STD_ON
#define SECOC_SIZEOFRXSECUREDPDUINFO                                                                STD_ON
#define SECOC_SIZEOFRXTPWRITTENBYTESCOUNTER                                                         STD_ON
#define SECOC_SIZEOFSECUREDPDUDATACONTAINER                                                         STD_ON
#define SECOC_SIZEOFSENDDEFAULTAUTHENTICATION                                                       STD_ON
#define SECOC_SIZEOFTRANSMITREQUEST                                                                 STD_ON
#define SECOC_SIZEOFTXAUTHENTICPDUINFO                                                              STD_ON
#define SECOC_SIZEOFTXAUTHENTICPDUSIZEOFFSET                                                        STD_ON
#define SECOC_SIZEOFTXBUILDATTEMPTSCOUNTER                                                          STD_ON
#define SECOC_SIZEOFTXPDUINFO                                                                       STD_ON
#define SECOC_SIZEOFTXPDUSTATE                                                                      STD_ON
#define SECOC_SIZEOFTXRESULTLENGTH                                                                  STD_ON
#define SECOC_SIZEOFTXSECUREDPDUINFO                                                                STD_ON
#define SECOC_SIZEOFTXTPWRITTENBYTESCOUNTER                                                         STD_ON
#define SECOC_SIZEOFVERIFICATIONSTATUSCALLOUT                                                       STD_ON
#define SECOC_SIZEOFVERIFICATIONSTATUSCALLOUTWITHSECUREDPDU                                         STD_ON
#define SECOC_SIZEOFVERIFYATTEMPTSCOUNTER                                                           STD_ON
#define SECOC_SIZEOFVERIFYOVERRIDESTATUS                                                            STD_ON
#define SECOC_SIZEOFVERIFYRESULT                                                                    STD_ON
#define SECOC_TRANSMITREQUEST                                                                       STD_ON
#define SECOC_TXAUTHENTICPDUINFO                                                                    STD_ON
#define SECOC_INVALIDHNDOFTXAUTHENTICPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxAuthenticPduInfo.InvalidHnd' Reason: 'the value of SecOC_InvalidHndOfTxAuthenticPduInfo is always 'false' due to this, the array is deactivated.' */
#define SECOC_MINIMUMPDULENGTHOFTXAUTHENTICPDUINFO                                                  STD_ON
#define SECOC_TXPDUINFOIDXOFTXAUTHENTICPDUINFO                                                      STD_ON
#define SECOC_TXAUTHENTICPDUSIZEOFFSET                                                              STD_ON
#define SECOC_TXBUILDATTEMPTSCOUNTER                                                                STD_ON
#define SECOC_TXIMMEDIATEPROCESSINGONGOING                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxImmediateProcessingOngoing' Reason: 'Neither immediate Tx callback processing nor immediate Tx Pdu processing is configured.' */
#define SECOC_TXPDUINFO                                                                             STD_ON
#define SECOC_ADDCANFDCONTAINERPDUPADDINGOFTXPDUINFO                                                STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AddCANFDContainerPduPadding' Reason: '/ActiveEcuC/SecOC/SecOCGeneral[0:SecOCCanFdPadding] is configured to 'false'' */
#define SECOC_AUTHINFOLENGTHOFTXPDUINFO                                                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthInfoLength' Reason: 'Custom API is not configured.' */
#define SECOC_AUTHENTICEXTERNALIDOFTXPDUINFO                                                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAENDIDXOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataEndIdx' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATALENGTHOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataLength' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATASTARTIDXOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataStartIdx' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUMETADATAUSEDOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.AuthenticPduDataContainerAuthenticPDUMetaDataUsed' Reason: 'the optional indirection is deactivated because AuthenticPduDataContainerAuthenticPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                                STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                                STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                              STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                                  STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFTXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFTXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFTXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFTXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFTXPDUINFO                        STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFTXPDUINFO                      STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFTXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUENDIDXOFTXPDUINFO                            STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDULENGTHOFTXPDUINFO                            STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUSTARTIDXOFTXPDUINFO                          STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUUSEDOFTXPDUINFO                              STD_ON
#define SECOC_AUTHENTICATIONLAYERIDOFTXPDUINFO                                                      STD_ON
#define SECOC_AUTHENTICATORCACHEENDIDXOFTXPDUINFO                                                   STD_ON
#define SECOC_AUTHENTICATORCACHELENGTHOFTXPDUINFO                                                   STD_ON
#define SECOC_AUTHENTICATORCACHESTARTIDXOFTXPDUINFO                                                 STD_ON
#define SECOC_BUILDATTEMPTSOFTXPDUINFO                                                              STD_ON
#define SECOC_CONFIRMATIONNEEDEDOFTXPDUINFO                                                         STD_ON
#define SECOC_DATAIDFIRSTBYTEOFTXPDUINFO                                                            STD_ON
#define SECOC_DATAIDSECONDBYTEOFTXPDUINFO                                                           STD_ON
#define SECOC_EXTERNALFRESHNESSIDOFTXPDUINFO                                                        STD_ON
#define SECOC_LOWERLAYERPDUTYPEOFTXPDUINFO                                                          STD_ON
#define SECOC_PDUPROCESSINGOFTXPDUINFO                                                              STD_ON
#define SECOC_PDUTYPEOFTXPDUINFO                                                                    STD_ON
#define SECOC_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                                    STD_ON
#define SECOC_SPDUTXCONFIRMATIONNEEDEDOFTXPDUINFO                                                   STD_ON
#define SECOC_SECUREDEXTERNALIDOFTXPDUINFO                                                          STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATAENDIDXOFTXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATALENGTHOFTXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATASTARTIDXOFTXPDUINFO                                STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHINFODATAUSEDOFTXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHENDIDXOFTXPDUINFO                           STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthEndIdx' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHLENGTHOFTXPDUINFO                           STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthLength' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHSTARTIDXOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthStartIdx' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHPDUHEADERLENGTHUSEDOFTXPDUINFO                             STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerAuthPduHeaderLengthUsed' Reason: 'no AuthPduHeaderLength is configured for tx pdus' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                                STD_ON
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAENDIDXOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataEndIdx' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATALENGTHOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataLength' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATASTARTIDXOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataStartIdx' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUMETADATAUSEDOFTXPDUINFO                              STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.SecuredPduDataContainerSecuredPDUMetaDataUsed' Reason: 'the optional indirection is deactivated because SecuredPduDataContainerSecuredPDUMetaDataUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFTXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFTXPDUINFO                                    STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFTXPDUINFO                                  STD_ON
#define SECOC_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFTXPDUINFO                                      STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFTXPDUINFO                        STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFTXPDUINFO                        STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFTXPDUINFO                      STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFTXPDUINFO                          STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFTXPDUINFO                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                       STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFTXPDUINFO                     STD_ON
#define SECOC_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFTXPDUINFO                         STD_ON
#define SECOC_TRUNCAUTHSTARTBITINBYTEOFTXPDUINFO                                                    STD_ON
#define SECOC_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFTXPDUINFO                                          STD_ON
#define SECOC_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFTXPDUINFO                                         STD_ON
#define SECOC_TXSECUREDPDUAREAINFOIDXOFTXPDUINFO                                                    STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSecuredPduAreaInfoIdx' Reason: 'the optional indirection is deactivated because TxSecuredPduAreaInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_TXSECUREDPDUAREAINFOUSEDOFTXPDUINFO                                                   STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSecuredPduAreaInfoUsed' Reason: 'the optional indirection is deactivated because TxSecuredPduAreaInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_TXSPLITPDUINFOIDXOFTXPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSplitPduInfoIdx' Reason: 'the optional indirection is deactivated because TxSplitPduInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_TXSPLITPDUINFOUSEDOFTXPDUINFO                                                         STD_OFF  /**< Deactivateable: 'SecOC_TxPduInfo.TxSplitPduInfoUsed' Reason: 'the optional indirection is deactivated because TxSplitPduInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define SECOC_WAITFORCALLBACKOFTXPDUINFO                                                            STD_ON
#define SECOC_TRUNCATEDAUTHENTICATIONLENGTHOFTXPDUINFO                                              STD_ON
#define SECOC_TRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                                              STD_ON
#define SECOC_TXPDUSTATE                                                                            STD_ON
#define SECOC_TXRESULTLENGTH                                                                        STD_ON
#define SECOC_TXSECUREDPDUAREABUFFER                                                                STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaBuffer' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUAREAINFO                                                                  STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_LENGTHOFTXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaInfo.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_OFFSETOFTXSECUREDPDUAREAINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduAreaInfo.Offset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSECUREDPDUINFO                                                                      STD_ON
#define SECOC_INVALIDHNDOFTXSECUREDPDUINFO                                                          STD_OFF  /**< Deactivateable: 'SecOC_TxSecuredPduInfo.InvalidHnd' Reason: 'the value of SecOC_InvalidHndOfTxSecuredPduInfo is always 'false' due to this, the array is deactivated.' */
#define SECOC_TXPDUINFOIDXOFTXSECUREDPDUINFO                                                        STD_ON
#define SECOC_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                                    STD_ON
#define SECOC_TXSPLITMESSAGECOUNTER                                                                 STD_OFF  /**< Deactivateable: 'SecOC_TxSplitMessageCounter' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXSPLITPDUINFO                                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define SECOC_AUTHSPLITPDUEXTERNALIDOFTXSPLITPDUINFO                                                STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.AuthSplitPduExternalId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_CYPTOGRAPHICPDUEXTERNALIDOFTXSPLITPDUINFO                                             STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.CyptographicPduExternalId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_MESSAGELINKLENOFTXSPLITPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.MessageLinkLen' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_MESSAGELINKPOSOFTXSPLITPDUINFO                                                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.MessageLinkPos' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_MESSAGESLINKCRYPTOPDUDESTBITOFFSETOFTXSPLITPDUINFO                                    STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.MessagesLinkCryptoPduDestBitOffset' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICSPLITPDUENDIDXOFTXSPLITPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerAuthenticSplitPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICSPLITPDULENGTHOFTXSPLITPDUINFO                        STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerAuthenticSplitPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERAUTHENTICSPLITPDUSTARTIDXOFTXSPLITPDUINFO                      STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerAuthenticSplitPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERCRYPTOGRAPHICPDUENDIDXOFTXSPLITPDUINFO                         STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerCryptographicPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERCRYPTOGRAPHICPDULENGTHOFTXSPLITPDUINFO                         STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerCryptographicPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERCRYPTOGRAPHICPDUSTARTIDXOFTXSPLITPDUINFO                       STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerCryptographicPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDUENDIDXOFTXSPLITPDUINFO                STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDULENGTHOFTXSPLITPDUINFO                STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDUSTARTIDXOFTXSPLITPDUINFO              STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERAUTHSPLITPDUUSEDOFTXSPLITPDUINFO                  STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerAuthSplitPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDUENDIDXOFTXSPLITPDUINFO                   STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDULENGTHOFTXSPLITPDUINFO                   STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDUSTARTIDXOFTXSPLITPDUINFO                 STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_SECUREDPDUDATACONTAINERMESSAGELINKERCRYPTOPDUUSEDOFTXSPLITPDUINFO                     STD_OFF  /**< Deactivateable: 'SecOC_TxSplitPduInfo.SecuredPduDataContainerMessageLinkerCryptoPduUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define SECOC_TXTPWRITTENBYTESCOUNTER                                                               STD_ON
#define SECOC_VERIFICATIONSTATUSCALLOUT                                                             STD_ON
#define SECOC_VERIFICATIONSTATUSCALLOUTWITHSECUREDPDU                                               STD_ON
#define SECOC_VERIFYATTEMPTSCOUNTER                                                                 STD_ON
#define SECOC_VERIFYOVERRIDESTATUS                                                                  STD_ON
#define SECOC_VERIFYRESULT                                                                          STD_ON
#define SECOC_PCCONFIG                                                                              STD_ON
#define SECOC_AUTHENTICPDUDATACONTAINEROFPCCONFIG                                                   STD_ON
#define SECOC_AUTHENTICATORCACHEOFPCCONFIG                                                          STD_ON
#define SECOC_DEVMODEENABLEDOFPCCONFIG                                                              STD_ON
#define SECOC_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'SecOC_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'SecOC_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SECOC_INITIALIZEDOFPCCONFIG                                                                 STD_ON
#define SECOC_NUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                                  STD_ON
#define SECOC_RXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                                    STD_ON
#define SECOC_RXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                      STD_ON
#define SECOC_RXPDUINFOOFPCCONFIG                                                                   STD_ON
#define SECOC_RXPDUSTATEOFPCCONFIG                                                                  STD_ON
#define SECOC_RXSECUREDPDUINFOOFPCCONFIG                                                            STD_ON
#define SECOC_RXTPWRITTENBYTESCOUNTEROFPCCONFIG                                                     STD_ON
#define SECOC_SECUREDPDUDATACONTAINEROFPCCONFIG                                                     STD_ON
#define SECOC_SENDDEFAULTAUTHENTICATIONOFPCCONFIG                                                   STD_ON
#define SECOC_SIZEOFAUTHENTICPDUDATACONTAINEROFPCCONFIG                                             STD_ON
#define SECOC_SIZEOFAUTHENTICATORCACHEOFPCCONFIG                                                    STD_ON
#define SECOC_SIZEOFNUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                            STD_ON
#define SECOC_SIZEOFRXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                              STD_ON
#define SECOC_SIZEOFRXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                STD_ON
#define SECOC_SIZEOFRXPDUINFOOFPCCONFIG                                                             STD_ON
#define SECOC_SIZEOFRXPDUSTATEOFPCCONFIG                                                            STD_ON
#define SECOC_SIZEOFRXSECUREDPDUINFOOFPCCONFIG                                                      STD_ON
#define SECOC_SIZEOFRXTPWRITTENBYTESCOUNTEROFPCCONFIG                                               STD_ON
#define SECOC_SIZEOFSECUREDPDUDATACONTAINEROFPCCONFIG                                               STD_ON
#define SECOC_SIZEOFSENDDEFAULTAUTHENTICATIONOFPCCONFIG                                             STD_ON
#define SECOC_SIZEOFTRANSMITREQUESTOFPCCONFIG                                                       STD_ON
#define SECOC_SIZEOFTXAUTHENTICPDUINFOOFPCCONFIG                                                    STD_ON
#define SECOC_SIZEOFTXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                              STD_ON
#define SECOC_SIZEOFTXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                STD_ON
#define SECOC_SIZEOFTXPDUINFOOFPCCONFIG                                                             STD_ON
#define SECOC_SIZEOFTXPDUSTATEOFPCCONFIG                                                            STD_ON
#define SECOC_SIZEOFTXRESULTLENGTHOFPCCONFIG                                                        STD_ON
#define SECOC_SIZEOFTXSECUREDPDUINFOOFPCCONFIG                                                      STD_ON
#define SECOC_SIZEOFTXTPWRITTENBYTESCOUNTEROFPCCONFIG                                               STD_ON
#define SECOC_SIZEOFVERIFICATIONSTATUSCALLOUTOFPCCONFIG                                             STD_ON
#define SECOC_SIZEOFVERIFICATIONSTATUSCALLOUTWITHSECUREDPDUOFPCCONFIG                               STD_ON
#define SECOC_SIZEOFVERIFYATTEMPTSCOUNTEROFPCCONFIG                                                 STD_ON
#define SECOC_SIZEOFVERIFYOVERRIDESTATUSOFPCCONFIG                                                  STD_ON
#define SECOC_SIZEOFVERIFYRESULTOFPCCONFIG                                                          STD_ON
#define SECOC_TRANSMITREQUESTOFPCCONFIG                                                             STD_ON
#define SECOC_TXAUTHENTICPDUINFOOFPCCONFIG                                                          STD_ON
#define SECOC_TXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                                    STD_ON
#define SECOC_TXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                      STD_ON
#define SECOC_TXPDUINFOOFPCCONFIG                                                                   STD_ON
#define SECOC_TXPDUSTATEOFPCCONFIG                                                                  STD_ON
#define SECOC_TXRESULTLENGTHOFPCCONFIG                                                              STD_ON
#define SECOC_TXSECUREDPDUINFOOFPCCONFIG                                                            STD_ON
#define SECOC_TXTPWRITTENBYTESCOUNTEROFPCCONFIG                                                     STD_ON
#define SECOC_VERIFICATIONSTATUSCALLOUTOFPCCONFIG                                                   STD_ON
#define SECOC_VERIFICATIONSTATUSCALLOUTWITHSECUREDPDUOFPCCONFIG                                     STD_ON
#define SECOC_VERIFYATTEMPTSCOUNTEROFPCCONFIG                                                       STD_ON
#define SECOC_VERIFYOVERRIDESTATUSOFPCCONFIG                                                        STD_ON
#define SECOC_VERIFYRESULTOFPCCONFIG                                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCMinNumericValueDefines  SecOC Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define SECOC_MIN_AUTHENTICPDUDATACONTAINER                                                         0u
#define SECOC_MIN_AUTHENTICATORCACHE                                                                0u
#define SECOC_MIN_NUMBEROFMESSAGESTOOVERRIDE                                                        0u
#define SECOC_MIN_RXAUTHENTICPDUSIZEOFFSET                                                          0u
#define SECOC_MIN_RXBUILDATTEMPTSCOUNTER                                                            0u
#define SECOC_MIN_RXTPWRITTENBYTESCOUNTER                                                           0u
#define SECOC_MIN_SECUREDPDUDATACONTAINER                                                           0u
#define SECOC_MIN_TXAUTHENTICPDUSIZEOFFSET                                                          0u
#define SECOC_MIN_TXBUILDATTEMPTSCOUNTER                                                            0u
#define SECOC_MIN_TXRESULTLENGTH                                                                    0u
#define SECOC_MIN_TXTPWRITTENBYTESCOUNTER                                                           0u
#define SECOC_MIN_VERIFYATTEMPTSCOUNTER                                                             0u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCMaxNumericValueDefines  SecOC Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define SECOC_MAX_AUTHENTICPDUDATACONTAINER                                                         255u
#define SECOC_MAX_AUTHENTICATORCACHE                                                                255u
#define SECOC_MAX_NUMBEROFMESSAGESTOOVERRIDE                                                        255u
#define SECOC_MAX_RXAUTHENTICPDUSIZEOFFSET                                                          65535u
#define SECOC_MAX_RXBUILDATTEMPTSCOUNTER                                                            65535u
#define SECOC_MAX_RXTPWRITTENBYTESCOUNTER                                                           4294967295u
#define SECOC_MAX_SECUREDPDUDATACONTAINER                                                           255u
#define SECOC_MAX_TXAUTHENTICPDUSIZEOFFSET                                                          65535u
#define SECOC_MAX_TXBUILDATTEMPTSCOUNTER                                                            65535u
#define SECOC_MAX_TXRESULTLENGTH                                                                    4294967295u
#define SECOC_MAX_TXTPWRITTENBYTESCOUNTER                                                           4294967295u
#define SECOC_MAX_VERIFYATTEMPTSCOUNTER                                                             65535u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCNoReferenceDefines  SecOC No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define SECOC_NO_AUTHENTICEXTERNALIDOFRXPDUINFO                                                     255u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                             65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                           65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                     65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                   65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                               65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                             65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                                 65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                               65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                               65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                             65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                     65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                   65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                    65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO                  65535u
#define SECOC_NO_AUTHENTICEXTERNALIDOFTXPDUINFO                                                     255u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                             65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                           65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFTXPDUINFO                     65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFTXPDUINFO                   65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUENDIDXOFTXPDUINFO                         65535u
#define SECOC_NO_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUSTARTIDXOFTXPDUINFO                       65535u
#define SECOC_NO_SECUREDEXTERNALIDOFTXPDUINFO                                                       255u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHINFODATAENDIDXOFTXPDUINFO                               65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHINFODATASTARTIDXOFTXPDUINFO                             65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                               65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                             65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFTXPDUINFO                                 65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFTXPDUINFO                               65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFTXPDUINFO                     65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFTXPDUINFO                   65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFTXPDUINFO                    65535u
#define SECOC_NO_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFTXPDUINFO                  65535u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCEnumExistsDefines  SecOC Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define SECOC_EXISTS_USE_AUTHDATAFRESHNESSOFRXPDUINFO                                               STD_OFF
#define SECOC_EXISTS_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO                                          STD_ON
#define SECOC_EXISTS_IMMEDIATE_PDUPROCESSINGOFRXPDUINFO                                             STD_OFF
#define SECOC_EXISTS_DEFERRED_PDUPROCESSINGOFRXPDUINFO                                              STD_ON
#define SECOC_EXISTS_IFPDU_PDUTYPEOFRXPDUINFO                                                       STD_ON
#define SECOC_EXISTS_TPPDU_PDUTYPEOFRXPDUINFO                                                       STD_OFF
#define SECOC_EXISTS_CRYPTO_PDUTYPEOFRXPDUINFO                                                      STD_OFF
#define SECOC_EXISTS_AUTHENTIC_PDUTYPEOFRXPDUINFO                                                   STD_OFF
#define SECOC_EXISTS_NORMAL_PDUTYPEOFRXPDUINFO                                                      STD_OFF
#define SECOC_EXISTS_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                              STD_ON
#define SECOC_EXISTS_FAILURE_ONLY_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                      STD_OFF
#define SECOC_EXISTS_NONE_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                              STD_OFF
#define SECOC_EXISTS_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                STD_ON
#define SECOC_EXISTS_FAILURE_ONLY_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO        STD_OFF
#define SECOC_EXISTS_NONE_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                STD_OFF
#define SECOC_EXISTS_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO                                           STD_ON
#define SECOC_EXISTS_AUTHENTIC_SPLIT_MESSAGETYPEOFRXSECUREDPDUINFO                                  STD_OFF
#define SECOC_EXISTS_CRYPTOGRAPHIC_MESSAGETYPEOFRXSECUREDPDUINFO                                    STD_OFF
#define SECOC_EXISTS_IFPDU_LOWERLAYERPDUTYPEOFTXPDUINFO                                             STD_ON
#define SECOC_EXISTS_TPPDU_LOWERLAYERPDUTYPEOFTXPDUINFO                                             STD_OFF
#define SECOC_EXISTS_CRYPTO_LOWERLAYERPDUTYPEOFTXPDUINFO                                            STD_OFF
#define SECOC_EXISTS_AUTHENTIC_LOWERLAYERPDUTYPEOFTXPDUINFO                                         STD_OFF
#define SECOC_EXISTS_NORMAL_LOWERLAYERPDUTYPEOFTXPDUINFO                                            STD_OFF
#define SECOC_EXISTS_IMMEDIATE_PDUPROCESSINGOFTXPDUINFO                                             STD_OFF
#define SECOC_EXISTS_DEFERRED_PDUPROCESSINGOFTXPDUINFO                                              STD_ON
#define SECOC_EXISTS_IFPDU_PDUTYPEOFTXPDUINFO                                                       STD_ON
#define SECOC_EXISTS_TPPDU_PDUTYPEOFTXPDUINFO                                                       STD_OFF
#define SECOC_EXISTS_CRYPTO_PDUTYPEOFTXPDUINFO                                                      STD_OFF
#define SECOC_EXISTS_AUTHENTIC_PDUTYPEOFTXPDUINFO                                                   STD_OFF
#define SECOC_EXISTS_NORMAL_PDUTYPEOFTXPDUINFO                                                      STD_OFF
#define SECOC_EXISTS_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                     STD_ON
#define SECOC_EXISTS_DONT_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                STD_OFF
#define SECOC_EXISTS_IFPDU_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                       STD_OFF
#define SECOC_EXISTS_TPPDU_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                       STD_OFF
#define SECOC_EXISTS_CRYPTO_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                      STD_OFF
#define SECOC_EXISTS_AUTHENTIC_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                   STD_OFF
#define SECOC_EXISTS_NORMAL_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCEnumDefines  SecOC Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO                                                 0x01u
#define SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO                                                     0x01u
#define SECOC_IFPDU_PDUTYPEOFRXPDUINFO                                                              0x00u
#define SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                                     0x00u
#define SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                       0x00u
#define SECOC_IDLE_RXPDUSTATE                                                                       0x00u
#define SECOC_COPYING_RXPDUSTATE                                                                    0x01u
#define SECOC_VERIFIED_RXPDUSTATE                                                                   0x02u
#define SECOC_PRE_VERIFY_START_RXPDUSTATE                                                           0x06u
#define SECOC_COPY_AUTHENTIC_PDU_TO_DATA_TO_AUTHENTICATE_RXPDUSTATE                                 0x03u
#define SECOC_FRESHNESS_VALUE_NEEDED_RXPDUSTATE                                                     0x04u
#define SECOC_ABORTED_RXPDUSTATE                                                                    0x05u
#define SECOC_UNVERIFIED_RXPDUSTATE                                                                 0x10u
#define SECOC_UNVERIFIED_VERIFICATION_TO_BE_STARTED_RXPDUSTATE                                      0x10u
#define SECOC_UNVERIFIED_VERIFICATION_STARTED_WAIT_FOR_CALLBACK_RXPDUSTATE                          0x11u
#define SECOC_UNVERIFIED_VERIFICATION_TO_BE_UPDATED_RXPDUSTATE                                      0x12u
#define SECOC_UNVERIFIED_VERIFICATION_UPDATED_WAIT_FOR_CALLBACK_RXPDUSTATE                          0x13u
#define SECOC_UNVERIFIED_VERIFICATION_TO_BE_FINISHED_RXPDUSTATE                                     0x14u
#define SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE                         0x15u
#define SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE                 0x16u
#define SECOC_UNVERIFIED_VERIFICATION_FINISHED_RXPDUSTATE                                           0x17u
#define SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO                                                  0x00u
#define SECOC_IDLE_TRANSMITREQUEST                                                                  0x00u
#define SECOC_TRANSMIT_TRANSMITREQUEST                                                              0x01u
#define SECOC_IFPDU_LOWERLAYERPDUTYPEOFTXPDUINFO                                                    0x00u
#define SECOC_DEFERRED_PDUPROCESSINGOFTXPDUINFO                                                     0x01u
#define SECOC_IFPDU_PDUTYPEOFTXPDUINFO                                                              0x00u
#define SECOC_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                            0x00u
#define SECOC_INVALID_SECURED_PDU_TXPDUSTATE                                                        0x00u
#define SECOC_PRE_REAUTHENTICATION_NEEDED_TXPDUSTATE                                                0x08u
#define SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE                                                    0x01u
#define SECOC_AUTHENTICATED_TXPDUSTATE                                                              0x02u
#define SECOC_TRANSMISSION_INITIATED_TXPDUSTATE                                                     0x03u
#define SECOC_COPYING_TXPDUSTATE                                                                    0x04u
#define SECOC_GET_DATA_TXPDUSTATE                                                                   0x06u
#define SECOC_DEVMODE_AUTHENTICATION_PATTERN_NEEDED_TXPDUSTATE                                      0x07u
#define SECOC_UNAUTHENTICATED_TXPDUSTATE                                                            0x10u
#define SECOC_UNAUTHENTICATED_TO_BE_STARTED_TXPDUSTATE                                              0x10u
#define SECOC_UNAUTHENTICATED_STARTED_WAIT_FOR_CALLBACK_TXPDUSTATE                                  0x11u
#define SECOC_UNAUTHENTICATED_TO_BE_UPDATED_TXPDUSTATE                                              0x12u
#define SECOC_UNAUTHENTICATED_UPDATED_WAIT_FOR_CALLBACK_TXPDUSTATE                                  0x13u
#define SECOC_UNAUTHENTICATED_TO_BE_FINISHED_TXPDUSTATE                                             0x14u
#define SECOC_UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK_TXPDUSTATE                                 0x15u
#define SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE                                                   0x16u
#define SECOC_NORMAL_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                             0x04u
#define SECOC_CANCEL_VERIFYOVERRIDESTATUS                                                           0x02u
#define SECOC_FAIL_N_TIMES_VERIFYOVERRIDESTATUS                                                     0x01u
#define SECOC_FAIL_INFINETE_VERIFYOVERRIDESTATUS                                                    0x00u
#define SECOC_PASS_VERIFYOVERRIDESTATUS                                                             0x28u
#define SECOC_PASS_N_TIMES_VERIFYOVERRIDESTATUS                                                     0x29u
#define SECOC_OVERRIDE_SKIP_UNTIL_LIMIT_VERIFYOVERRIDESTATUS                                        0x41u
#define SECOC_OVERRIDE_SKIP_UNTIL_NOTICE_VERIFYOVERRIDESTATUS                                       0x43u
#define SECOC_PASS_UNTIL_NOTICE_VERIFYOVERRIDESTATUS                                                0x40u
#define SECOC_PASS_UNTIL_LIMIT_VERIFYOVERRIDESTATUS                                                 0x42u
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCIsReducedToDefineDefines  SecOC Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SECOC_ISDEF_AUTHDATAFRESHNESSLENOFRXPDUINFO                                                 STD_OFF
#define SECOC_ISDEF_AUTHDATAFRESHNESSOFRXPDUINFO                                                    STD_OFF
#define SECOC_ISDEF_AUTHDATAFRESHNESSSTARTBYTEPOSITIONOFRXPDUINFO                                   STD_OFF
#define SECOC_ISDEF_AUTHENTICEXTERNALIDOFRXPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                        STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICATIONLAYERIDOFRXPDUINFO                                                STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHEENDIDXOFRXPDUINFO                                             STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHELENGTHOFRXPDUINFO                                             STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHESTARTIDXOFRXPDUINFO                                           STD_OFF
#define SECOC_ISDEF_BUILDATTEMPTSOFRXPDUINFO                                                        STD_OFF
#define SECOC_ISDEF_DATAIDFIRSTBYTEOFRXPDUINFO                                                      STD_OFF
#define SECOC_ISDEF_DATAIDOFRXPDUINFO                                                               STD_OFF
#define SECOC_ISDEF_DATAIDSECONDBYTEOFRXPDUINFO                                                     STD_OFF
#define SECOC_ISDEF_EXTERNALFRESHNESSIDOFRXPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_NUMBEROFMESSAGESTOOVERRIDEIDXOFRXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_PDUPROCESSINGOFRXPDUINFO                                                        STD_OFF
#define SECOC_ISDEF_PDUTYPEOFRXPDUINFO                                                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFRXPDUINFO                                STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDULENGTHOFRXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                          STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTPSECUREDPDUUSEDOFRXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFRXPDUINFO                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFRXPDUINFO                    STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO               STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFRXPDUINFO                   STD_OFF
#define SECOC_ISDEF_SECUREDRXPDUVERFICATIONOFRXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_TRUNCAUTHSTARTBITINBYTEOFRXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFRXPDUINFO                                    STD_OFF
#define SECOC_ISDEF_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFRXPDUINFO                                   STD_OFF
#define SECOC_ISDEF_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                                    STD_OFF
#define SECOC_ISDEF_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                      STD_OFF
#define SECOC_ISDEF_VERIFYATTEMPTSOFRXPDUINFO                                                       STD_OFF
#define SECOC_ISDEF_VERIFYOVERRIDESTATUSIDXOFRXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_VERIFYRESULTIDXOFRXPDUINFO                                                      STD_OFF
#define SECOC_ISDEF_WAITFORCALLBACKOFRXPDUINFO                                                      STD_OFF
#define SECOC_ISDEF_TRUNCATEDAUTHENTICATIONLENGTHOFRXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_TRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_MESSAGELINKLENOFRXSECUREDPDUINFO                                                STD_OFF
#define SECOC_ISDEF_MESSAGELINKPOSOFRXSECUREDPDUINFO                                                STD_OFF
#define SECOC_ISDEF_MESSAGELINKERSTARTBYTEINCRYPTOPDUOFRXSECUREDPDUINFO                             STD_OFF
#define SECOC_ISDEF_MESSAGETYPEOFRXSECUREDPDUINFO                                                   STD_OFF
#define SECOC_ISDEF_MESSAGESLINKCRYPTOPDUSRCBITOFFSETOFRXSECUREDPDUINFO                             STD_OFF
#define SECOC_ISDEF_MINIMUMPDULENGTHOFRXSECUREDPDUINFO                                              STD_OFF
#define SECOC_ISDEF_PDUFIXLENGTHOFRXSECUREDPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_RXPDUINFOIDXOFRXSECUREDPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERENDIDXOFRXSECUREDPDUINFO                                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERLENGTHOFRXSECUREDPDUINFO                                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSTARTIDXOFRXSECUREDPDUINFO                               STD_OFF
#define SECOC_ISDEF_MINIMUMPDULENGTHOFTXAUTHENTICPDUINFO                                            STD_OFF
#define SECOC_ISDEF_TXPDUINFOIDXOFTXAUTHENTICPDUINFO                                                STD_OFF
#define SECOC_ISDEF_AUTHENTICEXTERNALIDOFTXPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                          STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                          STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                        STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                            STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFTXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFTXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFTXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFTXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFTXPDUINFO                  STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFTXPDUINFO                STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFTXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUENDIDXOFTXPDUINFO                      STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDULENGTHOFTXPDUINFO                      STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUSTARTIDXOFTXPDUINFO                    STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUUSEDOFTXPDUINFO                        STD_OFF
#define SECOC_ISDEF_AUTHENTICATIONLAYERIDOFTXPDUINFO                                                STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHEENDIDXOFTXPDUINFO                                             STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHELENGTHOFTXPDUINFO                                             STD_OFF
#define SECOC_ISDEF_AUTHENTICATORCACHESTARTIDXOFTXPDUINFO                                           STD_OFF
#define SECOC_ISDEF_BUILDATTEMPTSOFTXPDUINFO                                                        STD_OFF
#define SECOC_ISDEF_CONFIRMATIONNEEDEDOFTXPDUINFO                                                   STD_OFF
#define SECOC_ISDEF_DATAIDFIRSTBYTEOFTXPDUINFO                                                      STD_OFF
#define SECOC_ISDEF_DATAIDSECONDBYTEOFTXPDUINFO                                                     STD_OFF
#define SECOC_ISDEF_EXTERNALFRESHNESSIDOFTXPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_LOWERLAYERPDUTYPEOFTXPDUINFO                                                    STD_OFF
#define SECOC_ISDEF_PDUPROCESSINGOFTXPDUINFO                                                        STD_OFF
#define SECOC_ISDEF_PDUTYPEOFTXPDUINFO                                                              STD_OFF
#define SECOC_ISDEF_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_SPDUTXCONFIRMATIONNEEDEDOFTXPDUINFO                                             STD_OFF
#define SECOC_ISDEF_SECUREDEXTERNALIDOFTXPDUINFO                                                    STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHINFODATAENDIDXOFTXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHINFODATALENGTHOFTXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHINFODATASTARTIDXOFTXPDUINFO                          STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHINFODATAUSEDOFTXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                          STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFTXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFTXPDUINFO                              STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFTXPDUINFO                            STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFTXPDUINFO                                STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFTXPDUINFO                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFTXPDUINFO                  STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFTXPDUINFO                STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFTXPDUINFO                    STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFTXPDUINFO                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                 STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFTXPDUINFO               STD_OFF
#define SECOC_ISDEF_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFTXPDUINFO                   STD_OFF
#define SECOC_ISDEF_TRUNCAUTHSTARTBITINBYTEOFTXPDUINFO                                              STD_OFF
#define SECOC_ISDEF_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFTXPDUINFO                                    STD_OFF
#define SECOC_ISDEF_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFTXPDUINFO                                   STD_OFF
#define SECOC_ISDEF_WAITFORCALLBACKOFTXPDUINFO                                                      STD_OFF
#define SECOC_ISDEF_TRUNCATEDAUTHENTICATIONLENGTHOFTXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_TRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                                        STD_OFF
#define SECOC_ISDEF_TXPDUINFOIDXOFTXSECUREDPDUINFO                                                  STD_OFF
#define SECOC_ISDEF_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                              STD_OFF
#define SECOC_ISDEF_VERIFICATIONSTATUSCALLOUT                                                       STD_OFF
#define SECOC_ISDEF_VERIFICATIONSTATUSCALLOUTWITHSECUREDPDU                                         STD_OFF
#define SECOC_ISDEF_AUTHENTICPDUDATACONTAINEROFPCCONFIG                                             STD_ON
#define SECOC_ISDEF_AUTHENTICATORCACHEOFPCCONFIG                                                    STD_ON
#define SECOC_ISDEF_DEVMODEENABLEDOFPCCONFIG                                                        STD_ON
#define SECOC_ISDEF_INITIALIZEDOFPCCONFIG                                                           STD_ON
#define SECOC_ISDEF_NUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                            STD_ON
#define SECOC_ISDEF_RXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                              STD_ON
#define SECOC_ISDEF_RXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                STD_ON
#define SECOC_ISDEF_RXPDUINFOOFPCCONFIG                                                             STD_ON
#define SECOC_ISDEF_RXPDUSTATEOFPCCONFIG                                                            STD_ON
#define SECOC_ISDEF_RXSECUREDPDUINFOOFPCCONFIG                                                      STD_ON
#define SECOC_ISDEF_RXTPWRITTENBYTESCOUNTEROFPCCONFIG                                               STD_ON
#define SECOC_ISDEF_SECUREDPDUDATACONTAINEROFPCCONFIG                                               STD_ON
#define SECOC_ISDEF_SENDDEFAULTAUTHENTICATIONOFPCCONFIG                                             STD_ON
#define SECOC_ISDEF_TRANSMITREQUESTOFPCCONFIG                                                       STD_ON
#define SECOC_ISDEF_TXAUTHENTICPDUINFOOFPCCONFIG                                                    STD_ON
#define SECOC_ISDEF_TXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                              STD_ON
#define SECOC_ISDEF_TXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                STD_ON
#define SECOC_ISDEF_TXPDUINFOOFPCCONFIG                                                             STD_ON
#define SECOC_ISDEF_TXPDUSTATEOFPCCONFIG                                                            STD_ON
#define SECOC_ISDEF_TXRESULTLENGTHOFPCCONFIG                                                        STD_ON
#define SECOC_ISDEF_TXSECUREDPDUINFOOFPCCONFIG                                                      STD_ON
#define SECOC_ISDEF_TXTPWRITTENBYTESCOUNTEROFPCCONFIG                                               STD_ON
#define SECOC_ISDEF_VERIFICATIONSTATUSCALLOUTOFPCCONFIG                                             STD_ON
#define SECOC_ISDEF_VERIFICATIONSTATUSCALLOUTWITHSECUREDPDUOFPCCONFIG                               STD_ON
#define SECOC_ISDEF_VERIFYATTEMPTSCOUNTEROFPCCONFIG                                                 STD_ON
#define SECOC_ISDEF_VERIFYOVERRIDESTATUSOFPCCONFIG                                                  STD_ON
#define SECOC_ISDEF_VERIFYRESULTOFPCCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCEqualsAlwaysToDefines  SecOC Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SECOC_EQ2_AUTHDATAFRESHNESSLENOFRXPDUINFO                                                   
#define SECOC_EQ2_AUTHDATAFRESHNESSOFRXPDUINFO                                                      
#define SECOC_EQ2_AUTHDATAFRESHNESSSTARTBYTEPOSITIONOFRXPDUINFO                                     
#define SECOC_EQ2_AUTHENTICEXTERNALIDOFRXPDUINFO                                                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                            
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                            
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                          
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                              
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFRXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFRXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFRXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFRXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFRXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFRXPDUINFO                  
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFRXPDUINFO                      
#define SECOC_EQ2_AUTHENTICATIONLAYERIDOFRXPDUINFO                                                  
#define SECOC_EQ2_AUTHENTICATORCACHEENDIDXOFRXPDUINFO                                               
#define SECOC_EQ2_AUTHENTICATORCACHELENGTHOFRXPDUINFO                                               
#define SECOC_EQ2_AUTHENTICATORCACHESTARTIDXOFRXPDUINFO                                             
#define SECOC_EQ2_BUILDATTEMPTSOFRXPDUINFO                                                          
#define SECOC_EQ2_DATAIDFIRSTBYTEOFRXPDUINFO                                                        
#define SECOC_EQ2_DATAIDOFRXPDUINFO                                                                 
#define SECOC_EQ2_DATAIDSECONDBYTEOFRXPDUINFO                                                       
#define SECOC_EQ2_EXTERNALFRESHNESSIDOFRXPDUINFO                                                    
#define SECOC_EQ2_NUMBEROFMESSAGESTOOVERRIDEIDXOFRXPDUINFO                                          
#define SECOC_EQ2_PDUPROCESSINGOFRXPDUINFO                                                          
#define SECOC_EQ2_PDUTYPEOFRXPDUINFO                                                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO                            
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFRXPDUINFO                                  
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDUENDIDXOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDULENGTHOFRXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDUSTARTIDXOFRXPDUINFO                            
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTPSECUREDPDUUSEDOFRXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFRXPDUINFO                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFRXPDUINFO                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFRXPDUINFO                  
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFRXPDUINFO                      
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFRXPDUINFO                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFRXPDUINFO                 
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFRXPDUINFO                     
#define SECOC_EQ2_SECUREDRXPDUVERFICATIONOFRXPDUINFO                                                
#define SECOC_EQ2_TRUNCAUTHSTARTBITINBYTEOFRXPDUINFO                                                
#define SECOC_EQ2_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFRXPDUINFO                                      
#define SECOC_EQ2_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFRXPDUINFO                                     
#define SECOC_EQ2_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO                                      
#define SECOC_EQ2_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO                        
#define SECOC_EQ2_VERIFYATTEMPTSOFRXPDUINFO                                                         
#define SECOC_EQ2_VERIFYOVERRIDESTATUSIDXOFRXPDUINFO                                                
#define SECOC_EQ2_VERIFYRESULTIDXOFRXPDUINFO                                                        
#define SECOC_EQ2_WAITFORCALLBACKOFRXPDUINFO                                                        
#define SECOC_EQ2_TRUNCATEDAUTHENTICATIONLENGTHOFRXPDUINFO                                          
#define SECOC_EQ2_TRUNCATEDFRESHNESSVALUELENGTHOFRXPDUINFO                                          
#define SECOC_EQ2_MESSAGELINKLENOFRXSECUREDPDUINFO                                                  
#define SECOC_EQ2_MESSAGELINKPOSOFRXSECUREDPDUINFO                                                  
#define SECOC_EQ2_MESSAGELINKERSTARTBYTEINCRYPTOPDUOFRXSECUREDPDUINFO                               
#define SECOC_EQ2_MESSAGETYPEOFRXSECUREDPDUINFO                                                     
#define SECOC_EQ2_MESSAGESLINKCRYPTOPDUSRCBITOFFSETOFRXSECUREDPDUINFO                               
#define SECOC_EQ2_MINIMUMPDULENGTHOFRXSECUREDPDUINFO                                                
#define SECOC_EQ2_PDUFIXLENGTHOFRXSECUREDPDUINFO                                                    
#define SECOC_EQ2_RXPDUINFOIDXOFRXSECUREDPDUINFO                                                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERENDIDXOFRXSECUREDPDUINFO                                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERLENGTHOFRXSECUREDPDUINFO                                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSTARTIDXOFRXSECUREDPDUINFO                                 
#define SECOC_EQ2_MINIMUMPDULENGTHOFTXAUTHENTICPDUINFO                                              
#define SECOC_EQ2_TXPDUINFOIDXOFTXAUTHENTICPDUINFO                                                  
#define SECOC_EQ2_AUTHENTICEXTERNALIDOFTXPDUINFO                                                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                            
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                            
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                          
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                              
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATEENDIDXOFTXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATELENGTHOFTXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERDATATOAUTHENTICATESTARTIDXOFTXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEENDIDXOFTXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUELENGTHOFTXPDUINFO                    
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUESTARTIDXOFTXPDUINFO                  
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFRESHNESSVERIFYVALUEUSEDOFTXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUENDIDXOFTXPDUINFO                        
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDULENGTHOFTXPDUINFO                        
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUSTARTIDXOFTXPDUINFO                      
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINERFULLAUTHENTICPDUUSEDOFTXPDUINFO                          
#define SECOC_EQ2_AUTHENTICATIONLAYERIDOFTXPDUINFO                                                  
#define SECOC_EQ2_AUTHENTICATORCACHEENDIDXOFTXPDUINFO                                               
#define SECOC_EQ2_AUTHENTICATORCACHELENGTHOFTXPDUINFO                                               
#define SECOC_EQ2_AUTHENTICATORCACHESTARTIDXOFTXPDUINFO                                             
#define SECOC_EQ2_BUILDATTEMPTSOFTXPDUINFO                                                          
#define SECOC_EQ2_CONFIRMATIONNEEDEDOFTXPDUINFO                                                     
#define SECOC_EQ2_DATAIDFIRSTBYTEOFTXPDUINFO                                                        
#define SECOC_EQ2_DATAIDSECONDBYTEOFTXPDUINFO                                                       
#define SECOC_EQ2_EXTERNALFRESHNESSIDOFTXPDUINFO                                                    
#define SECOC_EQ2_LOWERLAYERPDUTYPEOFTXPDUINFO                                                      
#define SECOC_EQ2_PDUPROCESSINGOFTXPDUINFO                                                          
#define SECOC_EQ2_PDUTYPEOFTXPDUINFO                                                                
#define SECOC_EQ2_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO                                                
#define SECOC_EQ2_SPDUTXCONFIRMATIONNEEDEDOFTXPDUINFO                                               
#define SECOC_EQ2_SECUREDEXTERNALIDOFTXPDUINFO                                                      
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHINFODATAENDIDXOFTXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHINFODATALENGTHOFTXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHINFODATASTARTIDXOFTXPDUINFO                            
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHINFODATAUSEDOFTXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFTXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDULENGTHOFTXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFTXPDUINFO                            
#define SECOC_EQ2_SECUREDPDUDATACONTAINERAUTHENTICPDUUSEDOFTXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUENDIDXOFTXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDULENGTHOFTXPDUINFO                                
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUSTARTIDXOFTXPDUINFO                              
#define SECOC_EQ2_SECUREDPDUDATACONTAINERSECUREDPDUUSEDOFTXPDUINFO                                  
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORENDIDXOFTXPDUINFO                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORLENGTHOFTXPDUINFO                    
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORSTARTIDXOFTXPDUINFO                  
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDAUTHENTICATORUSEDOFTXPDUINFO                      
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEENDIDXOFTXPDUINFO                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                   
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUESTARTIDXOFTXPDUINFO                 
#define SECOC_EQ2_SECUREDPDUDATACONTAINERTRUNCATEDFRESHNESSVALUEUSEDOFTXPDUINFO                     
#define SECOC_EQ2_TRUNCAUTHSTARTBITINBYTEOFTXPDUINFO                                                
#define SECOC_EQ2_TRUNCFRESHNESSVALUEFIRSTBYTESHIFTOFTXPDUINFO                                      
#define SECOC_EQ2_TRUNCFRESHNESSVALUESECONDBYTESHIFTOFTXPDUINFO                                     
#define SECOC_EQ2_WAITFORCALLBACKOFTXPDUINFO                                                        
#define SECOC_EQ2_TRUNCATEDAUTHENTICATIONLENGTHOFTXPDUINFO                                          
#define SECOC_EQ2_TRUNCATEDFRESHNESSVALUELENGTHOFTXPDUINFO                                          
#define SECOC_EQ2_TXPDUINFOIDXOFTXSECUREDPDUINFO                                                    
#define SECOC_EQ2_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO                                                
#define SECOC_EQ2_VERIFICATIONSTATUSCALLOUT                                                         
#define SECOC_EQ2_VERIFICATIONSTATUSCALLOUTWITHSECUREDPDU                                           
#define SECOC_EQ2_AUTHENTICPDUDATACONTAINEROFPCCONFIG                                               SecOC_AuthenticPduDataContainer
#define SECOC_EQ2_AUTHENTICATORCACHEOFPCCONFIG                                                      SecOC_AuthenticatorCache.raw
#define SECOC_EQ2_DEVMODEENABLEDOFPCCONFIG                                                          (&(SecOC_DevModeEnabled))
#define SECOC_EQ2_INITIALIZEDOFPCCONFIG                                                             (&(SecOC_Initialized))
#define SECOC_EQ2_NUMBEROFMESSAGESTOOVERRIDEOFPCCONFIG                                              SecOC_NumberOfMessagesToOverride.raw
#define SECOC_EQ2_RXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                                SecOC_RxAuthenticPduSizeOffset.raw
#define SECOC_EQ2_RXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                  SecOC_RxBuildAttemptsCounter.raw
#define SECOC_EQ2_RXPDUINFOOFPCCONFIG                                                               SecOC_RxPduInfo
#define SECOC_EQ2_RXPDUSTATEOFPCCONFIG                                                              SecOC_RxPduState.raw
#define SECOC_EQ2_RXSECUREDPDUINFOOFPCCONFIG                                                        SecOC_RxSecuredPduInfo
#define SECOC_EQ2_RXTPWRITTENBYTESCOUNTEROFPCCONFIG                                                 SecOC_RxTpWrittenBytesCounter.raw
#define SECOC_EQ2_SECUREDPDUDATACONTAINEROFPCCONFIG                                                 SecOC_SecuredPduDataContainer
#define SECOC_EQ2_SENDDEFAULTAUTHENTICATIONOFPCCONFIG                                               SecOC_SendDefaultAuthentication.raw
#define SECOC_EQ2_TRANSMITREQUESTOFPCCONFIG                                                         SecOC_TransmitRequest.raw
#define SECOC_EQ2_TXAUTHENTICPDUINFOOFPCCONFIG                                                      SecOC_TxAuthenticPduInfo
#define SECOC_EQ2_TXAUTHENTICPDUSIZEOFFSETOFPCCONFIG                                                SecOC_TxAuthenticPduSizeOffset.raw
#define SECOC_EQ2_TXBUILDATTEMPTSCOUNTEROFPCCONFIG                                                  SecOC_TxBuildAttemptsCounter.raw
#define SECOC_EQ2_TXPDUINFOOFPCCONFIG                                                               SecOC_TxPduInfo
#define SECOC_EQ2_TXPDUSTATEOFPCCONFIG                                                              SecOC_TxPduState.raw
#define SECOC_EQ2_TXRESULTLENGTHOFPCCONFIG                                                          SecOC_TxResultLength.raw
#define SECOC_EQ2_TXSECUREDPDUINFOOFPCCONFIG                                                        SecOC_TxSecuredPduInfo
#define SECOC_EQ2_TXTPWRITTENBYTESCOUNTEROFPCCONFIG                                                 SecOC_TxTpWrittenBytesCounter.raw
#define SECOC_EQ2_VERIFICATIONSTATUSCALLOUTOFPCCONFIG                                               SecOC_VerificationStatusCallout
#define SECOC_EQ2_VERIFICATIONSTATUSCALLOUTWITHSECUREDPDUOFPCCONFIG                                 SecOC_VerificationStatusCalloutWithSecuredPdu
#define SECOC_EQ2_VERIFYATTEMPTSCOUNTEROFPCCONFIG                                                   SecOC_VerifyAttemptsCounter.raw
#define SECOC_EQ2_VERIFYOVERRIDESTATUSOFPCCONFIG                                                    SecOC_VerifyOverrideStatus.raw
#define SECOC_EQ2_VERIFYRESULTOFPCCONFIG                                                            SecOC_VerifyResult.raw
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSymbolicInitializationPointers  SecOC Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define SecOC_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'SecOC' */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCInitializationSymbols  SecOC Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define SecOC_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'SecOC */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGeneral  SecOC General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define SECOC_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define SECOC_FINAL_MAGIC_NUMBER                                                                    0x961Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of SecOC */
#define SECOC_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'SecOC' is not configured to be postbuild capable. */
#define SECOC_INIT_DATA                                                                             SECOC_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define SECOC_INIT_DATA_HASH_CODE                                                                   1220421397  /**< the precompile constant to validate the initialization structure at initialization time of SecOC with a hashcode. The seed value is '0x961Eu' */
#define SECOC_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define SECOC_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer SecOC shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SecOCLTDataSwitches  SecOC Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SECOC_LTCONFIG                                                                              STD_OFF  /**< Deactivateable: 'SecOC_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCGetConstantDuplicatedRootDataMacros  SecOC Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define SecOC_GetAuthenticPduDataContainerOfPCConfig()                                              SecOC_AuthenticPduDataContainer  /**< the pointer to SecOC_AuthenticPduDataContainer */
#define SecOC_GetAuthenticatorCacheOfPCConfig()                                                     SecOC_AuthenticatorCache.raw  /**< the pointer to SecOC_AuthenticatorCache */
#define SecOC_GetDevModeEnabledOfPCConfig()                                                         (&(SecOC_DevModeEnabled))  /**< the pointer to SecOC_DevModeEnabled */
#define SecOC_GetInitializedOfPCConfig()                                                            (&(SecOC_Initialized))  /**< the pointer to SecOC_Initialized */
#define SecOC_GetNumberOfMessagesToOverrideOfPCConfig()                                             SecOC_NumberOfMessagesToOverride.raw  /**< the pointer to SecOC_NumberOfMessagesToOverride */
#define SecOC_GetRxAuthenticPduSizeOffsetOfPCConfig()                                               SecOC_RxAuthenticPduSizeOffset.raw  /**< the pointer to SecOC_RxAuthenticPduSizeOffset */
#define SecOC_GetRxBuildAttemptsCounterOfPCConfig()                                                 SecOC_RxBuildAttemptsCounter.raw  /**< the pointer to SecOC_RxBuildAttemptsCounter */
#define SecOC_GetRxPduInfoOfPCConfig()                                                              SecOC_RxPduInfo  /**< the pointer to SecOC_RxPduInfo */
#define SecOC_GetRxPduStateOfPCConfig()                                                             SecOC_RxPduState.raw  /**< the pointer to SecOC_RxPduState */
#define SecOC_GetRxSecuredPduInfoOfPCConfig()                                                       SecOC_RxSecuredPduInfo  /**< the pointer to SecOC_RxSecuredPduInfo */
#define SecOC_GetRxTpWrittenBytesCounterOfPCConfig()                                                SecOC_RxTpWrittenBytesCounter.raw  /**< the pointer to SecOC_RxTpWrittenBytesCounter */
#define SecOC_GetSecuredPduDataContainerOfPCConfig()                                                SecOC_SecuredPduDataContainer  /**< the pointer to SecOC_SecuredPduDataContainer */
#define SecOC_GetSendDefaultAuthenticationOfPCConfig()                                              SecOC_SendDefaultAuthentication.raw  /**< the pointer to SecOC_SendDefaultAuthentication */
#define SecOC_GetSizeOfAuthenticPduDataContainerOfPCConfig()                                        566u  /**< the number of accomplishable value elements in SecOC_AuthenticPduDataContainer */
#define SecOC_GetSizeOfAuthenticatorCacheOfPCConfig()                                               138u  /**< the number of accomplishable value elements in SecOC_AuthenticatorCache */
#define SecOC_GetSizeOfNumberOfMessagesToOverrideOfPCConfig()                                       14u  /**< the number of accomplishable value elements in SecOC_NumberOfMessagesToOverride */
#define SecOC_GetSizeOfRxPduInfoOfPCConfig()                                                        14u  /**< the number of accomplishable value elements in SecOC_RxPduInfo */
#define SecOC_GetSizeOfRxSecuredPduInfoOfPCConfig()                                                 14u  /**< the number of accomplishable value elements in SecOC_RxSecuredPduInfo */
#define SecOC_GetSizeOfSecuredPduDataContainerOfPCConfig()                                          512u  /**< the number of accomplishable value elements in SecOC_SecuredPduDataContainer */
#define SecOC_GetSizeOfTxAuthenticPduInfoOfPCConfig()                                               3u  /**< the number of accomplishable value elements in SecOC_TxAuthenticPduInfo */
#define SecOC_GetSizeOfTxPduInfoOfPCConfig()                                                        3u  /**< the number of accomplishable value elements in SecOC_TxPduInfo */
#define SecOC_GetSizeOfTxSecuredPduInfoOfPCConfig()                                                 3u  /**< the number of accomplishable value elements in SecOC_TxSecuredPduInfo */
#define SecOC_GetSizeOfVerificationStatusCalloutOfPCConfig()                                        1u  /**< the number of accomplishable value elements in SecOC_VerificationStatusCallout */
#define SecOC_GetSizeOfVerificationStatusCalloutWithSecuredPduOfPCConfig()                          1u  /**< the number of accomplishable value elements in SecOC_VerificationStatusCalloutWithSecuredPdu */
#define SecOC_GetSizeOfVerifyOverrideStatusOfPCConfig()                                             14u  /**< the number of accomplishable value elements in SecOC_VerifyOverrideStatus */
#define SecOC_GetSizeOfVerifyResultOfPCConfig()                                                     14u  /**< the number of accomplishable value elements in SecOC_VerifyResult */
#define SecOC_GetTransmitRequestOfPCConfig()                                                        SecOC_TransmitRequest.raw  /**< the pointer to SecOC_TransmitRequest */
#define SecOC_GetTxAuthenticPduInfoOfPCConfig()                                                     SecOC_TxAuthenticPduInfo  /**< the pointer to SecOC_TxAuthenticPduInfo */
#define SecOC_GetTxAuthenticPduSizeOffsetOfPCConfig()                                               SecOC_TxAuthenticPduSizeOffset.raw  /**< the pointer to SecOC_TxAuthenticPduSizeOffset */
#define SecOC_GetTxBuildAttemptsCounterOfPCConfig()                                                 SecOC_TxBuildAttemptsCounter.raw  /**< the pointer to SecOC_TxBuildAttemptsCounter */
#define SecOC_GetTxPduInfoOfPCConfig()                                                              SecOC_TxPduInfo  /**< the pointer to SecOC_TxPduInfo */
#define SecOC_GetTxPduStateOfPCConfig()                                                             SecOC_TxPduState.raw  /**< the pointer to SecOC_TxPduState */
#define SecOC_GetTxResultLengthOfPCConfig()                                                         SecOC_TxResultLength.raw  /**< the pointer to SecOC_TxResultLength */
#define SecOC_GetTxSecuredPduInfoOfPCConfig()                                                       SecOC_TxSecuredPduInfo  /**< the pointer to SecOC_TxSecuredPduInfo */
#define SecOC_GetTxTpWrittenBytesCounterOfPCConfig()                                                SecOC_TxTpWrittenBytesCounter.raw  /**< the pointer to SecOC_TxTpWrittenBytesCounter */
#define SecOC_GetVerificationStatusCalloutOfPCConfig()                                              SecOC_VerificationStatusCallout  /**< the pointer to SecOC_VerificationStatusCallout */
#define SecOC_GetVerificationStatusCalloutWithSecuredPduOfPCConfig()                                SecOC_VerificationStatusCalloutWithSecuredPdu  /**< the pointer to SecOC_VerificationStatusCalloutWithSecuredPdu */
#define SecOC_GetVerifyAttemptsCounterOfPCConfig()                                                  SecOC_VerifyAttemptsCounter.raw  /**< the pointer to SecOC_VerifyAttemptsCounter */
#define SecOC_GetVerifyOverrideStatusOfPCConfig()                                                   SecOC_VerifyOverrideStatus.raw  /**< the pointer to SecOC_VerifyOverrideStatus */
#define SecOC_GetVerifyResultOfPCConfig()                                                           SecOC_VerifyResult.raw  /**< the pointer to SecOC_VerifyResult */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetDuplicatedRootDataMacros  SecOC Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define SecOC_GetSizeOfRxAuthenticPduSizeOffsetOfPCConfig()                                         SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxAuthenticPduSizeOffset */
#define SecOC_GetSizeOfRxBuildAttemptsCounterOfPCConfig()                                           SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxBuildAttemptsCounter */
#define SecOC_GetSizeOfRxPduStateOfPCConfig()                                                       SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxPduState */
#define SecOC_GetSizeOfRxTpWrittenBytesCounterOfPCConfig()                                          SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_RxTpWrittenBytesCounter */
#define SecOC_GetSizeOfSendDefaultAuthenticationOfPCConfig()                                        SecOC_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_SendDefaultAuthentication */
#define SecOC_GetSizeOfTransmitRequestOfPCConfig()                                                  SecOC_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_TransmitRequest */
#define SecOC_GetSizeOfTxAuthenticPduSizeOffsetOfPCConfig()                                         SecOC_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_TxAuthenticPduSizeOffset */
#define SecOC_GetSizeOfTxBuildAttemptsCounterOfPCConfig()                                           SecOC_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_TxBuildAttemptsCounter */
#define SecOC_GetSizeOfTxPduStateOfPCConfig()                                                       SecOC_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_TxPduState */
#define SecOC_GetSizeOfTxResultLengthOfPCConfig()                                                   SecOC_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_TxResultLength */
#define SecOC_GetSizeOfTxTpWrittenBytesCounterOfPCConfig()                                          SecOC_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_TxTpWrittenBytesCounter */
#define SecOC_GetSizeOfVerifyAttemptsCounterOfPCConfig()                                            SecOC_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in SecOC_VerifyAttemptsCounter */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetDataMacros  SecOC Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define SecOC_GetAuthenticPduDataContainer(Index)                                                   (SecOC_GetAuthenticPduDataContainerOfPCConfig()[(Index)])
#define SecOC_GetAuthenticatorCache(Index)                                                          (SecOC_GetAuthenticatorCacheOfPCConfig()[(Index)])
#define SecOC_IsDevModeEnabled()                                                                    (((*(SecOC_GetDevModeEnabledOfPCConfig()))) != FALSE)
#define SecOC_IsInitialized()                                                                       (((*(SecOC_GetInitializedOfPCConfig()))) != FALSE)
#define SecOC_GetNumberOfMessagesToOverride(Index)                                                  (SecOC_GetNumberOfMessagesToOverrideOfPCConfig()[(Index)])
#define SecOC_GetRxAuthenticPduSizeOffset(Index)                                                    (SecOC_GetRxAuthenticPduSizeOffsetOfPCConfig()[(Index)])
#define SecOC_GetRxBuildAttemptsCounter(Index)                                                      (SecOC_GetRxBuildAttemptsCounterOfPCConfig()[(Index)])
#define SecOC_GetAuthDataFreshnessLenOfRxPduInfo(Index)                                             (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthDataFreshnessLenOfRxPduInfo)
#define SecOC_GetAuthDataFreshnessOfRxPduInfo(Index)                                                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthDataFreshnessOfRxPduInfo)
#define SecOC_GetAuthDataFreshnessStartBytePositionOfRxPduInfo(Index)                               (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthDataFreshnessStartBytePositionOfRxPduInfo)
#define SecOC_GetAuthenticExternalIdOfRxPduInfo(Index)                                              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticExternalIdOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo(Index)                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo(Index)                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo(Index)                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo(Index)            (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo)
#define SecOC_GetAuthenticationLayerIdOfRxPduInfo(Index)                                            (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticationLayerIdOfRxPduInfo)
#define SecOC_GetAuthenticatorCacheEndIdxOfRxPduInfo(Index)                                         (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheEndIdxOfRxPduInfo)
#define SecOC_GetAuthenticatorCacheLengthOfRxPduInfo(Index)                                         (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheLengthOfRxPduInfo)
#define SecOC_GetAuthenticatorCacheStartIdxOfRxPduInfo(Index)                                       (SecOC_GetRxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheStartIdxOfRxPduInfo)
#define SecOC_GetBuildAttemptsOfRxPduInfo(Index)                                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].BuildAttemptsOfRxPduInfo)
#define SecOC_GetDataIdFirstByteOfRxPduInfo(Index)                                                  (SecOC_GetRxPduInfoOfPCConfig()[(Index)].DataIdFirstByteOfRxPduInfo)
#define SecOC_GetDataIdOfRxPduInfo(Index)                                                           (SecOC_GetRxPduInfoOfPCConfig()[(Index)].DataIdOfRxPduInfo)
#define SecOC_GetDataIdSecondByteOfRxPduInfo(Index)                                                 (SecOC_GetRxPduInfoOfPCConfig()[(Index)].DataIdSecondByteOfRxPduInfo)
#define SecOC_GetExternalFreshnessIdOfRxPduInfo(Index)                                              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].ExternalFreshnessIdOfRxPduInfo)
#define SecOC_GetNumberOfMessagesToOverrideIdxOfRxPduInfo(Index)                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].NumberOfMessagesToOverrideIdxOfRxPduInfo)
#define SecOC_GetPduProcessingOfRxPduInfo(Index)                                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].PduProcessingOfRxPduInfo)
#define SecOC_GetPduTypeOfRxPduInfo(Index)                                                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].PduTypeOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduLengthOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo(Index)                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(Index)                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo(Index)                        (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo(Index)                      (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo(Index)              (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo(Index)            (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo(Index)             (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo(Index)             (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo(Index)           (SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo)
#define SecOC_IsSecuredRxPduVerficationOfRxPduInfo(Index)                                           ((SecOC_GetRxPduInfoOfPCConfig()[(Index)].SecuredRxPduVerficationOfRxPduInfo) != FALSE)
#define SecOC_GetTruncAuthStartBitInByteOfRxPduInfo(Index)                                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].TruncAuthStartBitInByteOfRxPduInfo)
#define SecOC_GetTruncFreshnessValueFirstByteShiftOfRxPduInfo(Index)                                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].TruncFreshnessValueFirstByteShiftOfRxPduInfo)
#define SecOC_GetTruncFreshnessValueSecondByteShiftOfRxPduInfo(Index)                               (SecOC_GetRxPduInfoOfPCConfig()[(Index)].TruncFreshnessValueSecondByteShiftOfRxPduInfo)
#define SecOC_GetVerificationStatusPropagationModeOfRxPduInfo(Index)                                (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerificationStatusPropagationModeOfRxPduInfo)
#define SecOC_GetVerificationStatusWithSecuredPduPropagationModeOfRxPduInfo(Index)                  (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerificationStatusWithSecuredPduPropagationModeOfRxPduInfo)
#define SecOC_GetVerifyAttemptsOfRxPduInfo(Index)                                                   (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerifyAttemptsOfRxPduInfo)
#define SecOC_GetVerifyOverrideStatusIdxOfRxPduInfo(Index)                                          (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerifyOverrideStatusIdxOfRxPduInfo)
#define SecOC_GetVerifyResultIdxOfRxPduInfo(Index)                                                  (SecOC_GetRxPduInfoOfPCConfig()[(Index)].VerifyResultIdxOfRxPduInfo)
#define SecOC_IsWaitForCallbackOfRxPduInfo(Index)                                                   ((SecOC_GetRxPduInfoOfPCConfig()[(Index)].WaitForCallbackOfRxPduInfo) != FALSE)
#define SecOC_GettruncatedAuthenticationLengthOfRxPduInfo(Index)                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].truncatedAuthenticationLengthOfRxPduInfo)
#define SecOC_GettruncatedFreshnessValueLengthOfRxPduInfo(Index)                                    (SecOC_GetRxPduInfoOfPCConfig()[(Index)].truncatedFreshnessValueLengthOfRxPduInfo)
#define SecOC_GetRxPduState(Index)                                                                  (SecOC_GetRxPduStateOfPCConfig()[(Index)])
#define SecOC_GetMessageLinkLenOfRxSecuredPduInfo(Index)                                            (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageLinkLenOfRxSecuredPduInfo)
#define SecOC_GetMessageLinkPosOfRxSecuredPduInfo(Index)                                            (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageLinkPosOfRxSecuredPduInfo)
#define SecOC_GetMessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo(Index)                         (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo)
#define SecOC_GetMessageTypeOfRxSecuredPduInfo(Index)                                               (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessageTypeOfRxSecuredPduInfo)
#define SecOC_GetMessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo(Index)                         (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo)
#define SecOC_GetMinimumPduLengthOfRxSecuredPduInfo(Index)                                          (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].MinimumPduLengthOfRxSecuredPduInfo)
#define SecOC_GetPduFixLengthOfRxSecuredPduInfo(Index)                                              (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].PduFixLengthOfRxSecuredPduInfo)
#define SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(Index)                                              (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxSecuredPduInfo)
#define SecOC_GetSecuredPduDataContainerEndIdxOfRxSecuredPduInfo(Index)                             (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerEndIdxOfRxSecuredPduInfo)
#define SecOC_GetSecuredPduDataContainerLengthOfRxSecuredPduInfo(Index)                             (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerLengthOfRxSecuredPduInfo)
#define SecOC_GetSecuredPduDataContainerStartIdxOfRxSecuredPduInfo(Index)                           (SecOC_GetRxSecuredPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerStartIdxOfRxSecuredPduInfo)
#define SecOC_GetRxTpWrittenBytesCounter(Index)                                                     (SecOC_GetRxTpWrittenBytesCounterOfPCConfig()[(Index)])
#define SecOC_GetSecuredPduDataContainer(Index)                                                     (SecOC_GetSecuredPduDataContainerOfPCConfig()[(Index)])
#define SecOC_IsSendDefaultAuthentication(Index)                                                    ((SecOC_GetSendDefaultAuthenticationOfPCConfig()[(Index)]) != FALSE)
#define SecOC_GetTransmitRequest(Index)                                                             (SecOC_GetTransmitRequestOfPCConfig()[(Index)])
#define SecOC_GetMinimumPduLengthOfTxAuthenticPduInfo(Index)                                        (SecOC_GetTxAuthenticPduInfoOfPCConfig()[(Index)].MinimumPduLengthOfTxAuthenticPduInfo)
#define SecOC_GetTxPduInfoIdxOfTxAuthenticPduInfo(Index)                                            (SecOC_GetTxAuthenticPduInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxAuthenticPduInfo)
#define SecOC_GetTxAuthenticPduSizeOffset(Index)                                                    (SecOC_GetTxAuthenticPduSizeOffsetOfPCConfig()[(Index)])
#define SecOC_GetTxBuildAttemptsCounter(Index)                                                      (SecOC_GetTxBuildAttemptsCounterOfPCConfig()[(Index)])
#define SecOC_GetAuthenticExternalIdOfTxPduInfo(Index)                                              (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticExternalIdOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfo(Index)                      (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo(Index)                      (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo(Index)                    (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfo(Index)                (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo(Index)                (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo(Index)              (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfo(Index)              (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo(Index)              (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo(Index)            (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfo(Index)                  (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo(Index)                  (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo)
#define SecOC_GetAuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfo(Index)                (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfo)
#define SecOC_GetAuthenticationLayerIdOfTxPduInfo(Index)                                            (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticationLayerIdOfTxPduInfo)
#define SecOC_GetAuthenticatorCacheEndIdxOfTxPduInfo(Index)                                         (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheEndIdxOfTxPduInfo)
#define SecOC_GetAuthenticatorCacheLengthOfTxPduInfo(Index)                                         (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheLengthOfTxPduInfo)
#define SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(Index)                                       (SecOC_GetTxPduInfoOfPCConfig()[(Index)].AuthenticatorCacheStartIdxOfTxPduInfo)
#define SecOC_GetBuildAttemptsOfTxPduInfo(Index)                                                    (SecOC_GetTxPduInfoOfPCConfig()[(Index)].BuildAttemptsOfTxPduInfo)
#define SecOC_IsConfirmationNeededOfTxPduInfo(Index)                                                ((SecOC_GetTxPduInfoOfPCConfig()[(Index)].ConfirmationNeededOfTxPduInfo) != FALSE)
#define SecOC_GetDataIdFirstByteOfTxPduInfo(Index)                                                  (SecOC_GetTxPduInfoOfPCConfig()[(Index)].DataIdFirstByteOfTxPduInfo)
#define SecOC_GetDataIdSecondByteOfTxPduInfo(Index)                                                 (SecOC_GetTxPduInfoOfPCConfig()[(Index)].DataIdSecondByteOfTxPduInfo)
#define SecOC_GetExternalFreshnessIdOfTxPduInfo(Index)                                              (SecOC_GetTxPduInfoOfPCConfig()[(Index)].ExternalFreshnessIdOfTxPduInfo)
#define SecOC_GetLowerLayerPduTypeOfTxPduInfo(Index)                                                (SecOC_GetTxPduInfoOfPCConfig()[(Index)].LowerLayerPduTypeOfTxPduInfo)
#define SecOC_GetPduProcessingOfTxPduInfo(Index)                                                    (SecOC_GetTxPduInfoOfPCConfig()[(Index)].PduProcessingOfTxPduInfo)
#define SecOC_GetPduTypeOfTxPduInfo(Index)                                                          (SecOC_GetTxPduInfoOfPCConfig()[(Index)].PduTypeOfTxPduInfo)
#define SecOC_GetProvideTruncTxFreshnessOfTxPduInfo(Index)                                          (SecOC_GetTxPduInfoOfPCConfig()[(Index)].ProvideTruncTxFreshnessOfTxPduInfo)
#define SecOC_IsSPduTxConfirmationNeededOfTxPduInfo(Index)                                          ((SecOC_GetTxPduInfoOfPCConfig()[(Index)].SPduTxConfirmationNeededOfTxPduInfo) != FALSE)
#define SecOC_GetSecuredExternalIdOfTxPduInfo(Index)                                                (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredExternalIdOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfo(Index)                        (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo(Index)                        (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfo(Index)                      (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfo(Index)                        (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduLengthOfTxPduInfo(Index)                        (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduLengthOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfo(Index)                      (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduEndIdxOfTxPduInfo(Index)                          (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduEndIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(Index)                          (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduLengthOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo(Index)                        (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfo(Index)              (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(Index)              (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo(Index)            (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfo(Index)             (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo(Index)             (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo)
#define SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfo(Index)           (SecOC_GetTxPduInfoOfPCConfig()[(Index)].SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfo)
#define SecOC_GetTruncAuthStartBitInByteOfTxPduInfo(Index)                                          (SecOC_GetTxPduInfoOfPCConfig()[(Index)].TruncAuthStartBitInByteOfTxPduInfo)
#define SecOC_GetTruncFreshnessValueFirstByteShiftOfTxPduInfo(Index)                                (SecOC_GetTxPduInfoOfPCConfig()[(Index)].TruncFreshnessValueFirstByteShiftOfTxPduInfo)
#define SecOC_GetTruncFreshnessValueSecondByteShiftOfTxPduInfo(Index)                               (SecOC_GetTxPduInfoOfPCConfig()[(Index)].TruncFreshnessValueSecondByteShiftOfTxPduInfo)
#define SecOC_IsWaitForCallbackOfTxPduInfo(Index)                                                   ((SecOC_GetTxPduInfoOfPCConfig()[(Index)].WaitForCallbackOfTxPduInfo) != FALSE)
#define SecOC_GettruncatedAuthenticationLengthOfTxPduInfo(Index)                                    (SecOC_GetTxPduInfoOfPCConfig()[(Index)].truncatedAuthenticationLengthOfTxPduInfo)
#define SecOC_GettruncatedFreshnessValueLengthOfTxPduInfo(Index)                                    (SecOC_GetTxPduInfoOfPCConfig()[(Index)].truncatedFreshnessValueLengthOfTxPduInfo)
#define SecOC_GetTxPduState(Index)                                                                  (SecOC_GetTxPduStateOfPCConfig()[(Index)])
#define SecOC_GetTxResultLength(Index)                                                              (SecOC_GetTxResultLengthOfPCConfig()[(Index)])
#define SecOC_GetTxPduInfoIdxOfTxSecuredPduInfo(Index)                                              (SecOC_GetTxSecuredPduInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSecuredPduInfo)
#define SecOC_GetTxSecuredPduTypeOfTxSecuredPduInfo(Index)                                          (SecOC_GetTxSecuredPduInfoOfPCConfig()[(Index)].TxSecuredPduTypeOfTxSecuredPduInfo)
#define SecOC_GetTxTpWrittenBytesCounter(Index)                                                     (SecOC_GetTxTpWrittenBytesCounterOfPCConfig()[(Index)])
#define SecOC_GetVerificationStatusCallout(Index)                                                   (SecOC_GetVerificationStatusCalloutOfPCConfig()[(Index)])
#define SecOC_GetVerificationStatusCalloutWithSecuredPdu(Index)                                     (SecOC_GetVerificationStatusCalloutWithSecuredPduOfPCConfig()[(Index)])
#define SecOC_GetVerifyAttemptsCounter(Index)                                                       (SecOC_GetVerifyAttemptsCounterOfPCConfig()[(Index)])
#define SecOC_GetVerifyOverrideStatus(Index)                                                        (SecOC_GetVerifyOverrideStatusOfPCConfig()[(Index)])
#define SecOC_GetVerifyResult(Index)                                                                (SecOC_GetVerifyResultOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetDeduplicatedDataMacros  SecOC Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define SecOC_IsAuthenticPduDataContainerAuthenticPduUsedOfRxPduInfo(Index)                         (((boolean)(SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_AuthenticPduDataContainer */
#define SecOC_IsAuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfo(Index)                 (((boolean)(SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_AuthenticPduDataContainer */
#define SecOC_IsSecuredPduDataContainerAuthenticPduUsedOfRxPduInfo(Index)                           (((boolean)(SecOC_GetSecuredPduDataContainerAuthenticPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerSecuredPduUsedOfRxPduInfo(Index)                             (((boolean)(SecOC_GetSecuredPduDataContainerSecuredPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTpSecuredPduUsedOfRxPduInfo(Index)                           (((boolean)(SecOC_GetSecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfo(Index)                 (((boolean)(SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfo(Index)                (((boolean)(SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_GetSizeOfAuthenticPduDataContainer()                                                  SecOC_GetSizeOfAuthenticPduDataContainerOfPCConfig()
#define SecOC_GetSizeOfAuthenticatorCache()                                                         SecOC_GetSizeOfAuthenticatorCacheOfPCConfig()
#define SecOC_GetSizeOfNumberOfMessagesToOverride()                                                 SecOC_GetSizeOfNumberOfMessagesToOverrideOfPCConfig()
#define SecOC_GetSizeOfRxAuthenticPduSizeOffset()                                                   SecOC_GetSizeOfRxAuthenticPduSizeOffsetOfPCConfig()
#define SecOC_GetSizeOfRxBuildAttemptsCounter()                                                     SecOC_GetSizeOfRxBuildAttemptsCounterOfPCConfig()
#define SecOC_GetSizeOfRxPduInfo()                                                                  SecOC_GetSizeOfRxPduInfoOfPCConfig()
#define SecOC_GetSizeOfRxPduState()                                                                 SecOC_GetSizeOfRxPduStateOfPCConfig()
#define SecOC_GetSizeOfRxSecuredPduInfo()                                                           SecOC_GetSizeOfRxSecuredPduInfoOfPCConfig()
#define SecOC_GetSizeOfRxTpWrittenBytesCounter()                                                    SecOC_GetSizeOfRxTpWrittenBytesCounterOfPCConfig()
#define SecOC_GetSizeOfSecuredPduDataContainer()                                                    SecOC_GetSizeOfSecuredPduDataContainerOfPCConfig()
#define SecOC_GetSizeOfSendDefaultAuthentication()                                                  SecOC_GetSizeOfSendDefaultAuthenticationOfPCConfig()
#define SecOC_GetSizeOfTransmitRequest()                                                            SecOC_GetSizeOfTransmitRequestOfPCConfig()
#define SecOC_GetSizeOfTxAuthenticPduInfo()                                                         SecOC_GetSizeOfTxAuthenticPduInfoOfPCConfig()
#define SecOC_GetSizeOfTxAuthenticPduSizeOffset()                                                   SecOC_GetSizeOfTxAuthenticPduSizeOffsetOfPCConfig()
#define SecOC_GetSizeOfTxBuildAttemptsCounter()                                                     SecOC_GetSizeOfTxBuildAttemptsCounterOfPCConfig()
#define SecOC_GetSizeOfTxPduInfo()                                                                  SecOC_GetSizeOfTxPduInfoOfPCConfig()
#define SecOC_GetSizeOfTxPduState()                                                                 SecOC_GetSizeOfTxPduStateOfPCConfig()
#define SecOC_GetSizeOfTxResultLength()                                                             SecOC_GetSizeOfTxResultLengthOfPCConfig()
#define SecOC_GetSizeOfTxSecuredPduInfo()                                                           SecOC_GetSizeOfTxSecuredPduInfoOfPCConfig()
#define SecOC_GetSizeOfTxTpWrittenBytesCounter()                                                    SecOC_GetSizeOfTxTpWrittenBytesCounterOfPCConfig()
#define SecOC_GetSizeOfVerificationStatusCallout()                                                  SecOC_GetSizeOfVerificationStatusCalloutOfPCConfig()
#define SecOC_GetSizeOfVerificationStatusCalloutWithSecuredPdu()                                    SecOC_GetSizeOfVerificationStatusCalloutWithSecuredPduOfPCConfig()
#define SecOC_GetSizeOfVerifyAttemptsCounter()                                                      SecOC_GetSizeOfVerifyAttemptsCounterOfPCConfig()
#define SecOC_GetSizeOfVerifyOverrideStatus()                                                       SecOC_GetSizeOfVerifyOverrideStatusOfPCConfig()
#define SecOC_GetSizeOfVerifyResult()                                                               SecOC_GetSizeOfVerifyResultOfPCConfig()
#define SecOC_IsAuthenticPduDataContainerAuthenticPduUsedOfTxPduInfo(Index)                         (((boolean)(SecOC_GetAuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_AuthenticPduDataContainer */
#define SecOC_IsAuthenticPduDataContainerFreshnessVerifyValueUsedOfTxPduInfo(Index)                 (((boolean)(SecOC_GetAuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_AuthenticPduDataContainer */
#define SecOC_IsAuthenticPduDataContainerFullAuthenticPduUsedOfTxPduInfo(Index)                     (((boolean)(SecOC_GetAuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_AuthenticPduDataContainer */
#define SecOC_IsSecuredPduDataContainerAuthInfoDataUsedOfTxPduInfo(Index)                           (((boolean)(SecOC_GetSecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerAuthenticPduUsedOfTxPduInfo(Index)                           (((boolean)(SecOC_GetSecuredPduDataContainerAuthenticPduLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerSecuredPduUsedOfTxPduInfo(Index)                             (((boolean)(SecOC_GetSecuredPduDataContainerSecuredPduLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTruncatedAuthenticatorUsedOfTxPduInfo(Index)                 (((boolean)(SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
#define SecOC_IsSecuredPduDataContainerTruncatedFreshnessValueUsedOfTxPduInfo(Index)                (((boolean)(SecOC_GetSecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to SecOC_SecuredPduDataContainer */
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSetDataMacros  SecOC Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define SecOC_SetAuthenticPduDataContainer(Index, Value)                                            SecOC_GetAuthenticPduDataContainerOfPCConfig()[(Index)] = (Value)
#define SecOC_SetAuthenticatorCache(Index, Value)                                                   SecOC_GetAuthenticatorCacheOfPCConfig()[(Index)] = (Value)
#define SecOC_SetDevModeEnabled(Value)                                                              (*(SecOC_GetDevModeEnabledOfPCConfig())) = (Value)
#define SecOC_SetInitialized(Value)                                                                 (*(SecOC_GetInitializedOfPCConfig())) = (Value)
#define SecOC_SetNumberOfMessagesToOverride(Index, Value)                                           SecOC_GetNumberOfMessagesToOverrideOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxAuthenticPduSizeOffset(Index, Value)                                             SecOC_GetRxAuthenticPduSizeOffsetOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxBuildAttemptsCounter(Index, Value)                                               SecOC_GetRxBuildAttemptsCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxPduState(Index, Value)                                                           SecOC_GetRxPduStateOfPCConfig()[(Index)] = (Value)
#define SecOC_SetRxTpWrittenBytesCounter(Index, Value)                                              SecOC_GetRxTpWrittenBytesCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetSecuredPduDataContainer(Index, Value)                                              SecOC_GetSecuredPduDataContainerOfPCConfig()[(Index)] = (Value)
#define SecOC_SetSendDefaultAuthentication(Index, Value)                                            SecOC_GetSendDefaultAuthenticationOfPCConfig()[(Index)] = (Value)
#define SecOC_SetTransmitRequest(Index, Value)                                                      SecOC_GetTransmitRequestOfPCConfig()[(Index)] = (Value)
#define SecOC_SetTxAuthenticPduSizeOffset(Index, Value)                                             SecOC_GetTxAuthenticPduSizeOffsetOfPCConfig()[(Index)] = (Value)
#define SecOC_SetTxBuildAttemptsCounter(Index, Value)                                               SecOC_GetTxBuildAttemptsCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetTxPduState(Index, Value)                                                           SecOC_GetTxPduStateOfPCConfig()[(Index)] = (Value)
#define SecOC_SetTxResultLength(Index, Value)                                                       SecOC_GetTxResultLengthOfPCConfig()[(Index)] = (Value)
#define SecOC_SetTxTpWrittenBytesCounter(Index, Value)                                              SecOC_GetTxTpWrittenBytesCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetVerifyAttemptsCounter(Index, Value)                                                SecOC_GetVerifyAttemptsCounterOfPCConfig()[(Index)] = (Value)
#define SecOC_SetVerifyOverrideStatus(Index, Value)                                                 SecOC_GetVerifyOverrideStatusOfPCConfig()[(Index)] = (Value)
#define SecOC_SetVerifyResult(Index, Value)                                                         SecOC_GetVerifyResultOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCGetAddressOfDataMacros  SecOC Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define SecOC_GetAddrAuthenticPduDataContainer(Index)                                               (&SecOC_GetAuthenticPduDataContainer(Index))
#define SecOC_GetAddrAuthenticatorCache(Index)                                                      (&SecOC_GetAuthenticatorCache(Index))
#define SecOC_GetAddrSecuredPduDataContainer(Index)                                                 (&SecOC_GetSecuredPduDataContainer(Index))
#define SecOC_GetAddrTxResultLength(Index)                                                          (&SecOC_GetTxResultLength(Index))
#define SecOC_GetAddrVerifyResult(Index)                                                            (&SecOC_GetVerifyResult(Index))
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCHasMacros  SecOC Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define SecOC_HasAuthenticPduDataContainer()                                                        (TRUE != FALSE)
#define SecOC_HasAuthenticatorCache()                                                               (TRUE != FALSE)
#define SecOC_HasDevModeEnabled()                                                                   (TRUE != FALSE)
#define SecOC_HasInitialized()                                                                      (TRUE != FALSE)
#define SecOC_HasNumberOfMessagesToOverride()                                                       (TRUE != FALSE)
#define SecOC_HasRxAuthenticPduSizeOffset()                                                         (TRUE != FALSE)
#define SecOC_HasRxBuildAttemptsCounter()                                                           (TRUE != FALSE)
#define SecOC_HasRxPduInfo()                                                                        (TRUE != FALSE)
#define SecOC_HasAuthDataFreshnessLenOfRxPduInfo()                                                  (TRUE != FALSE)
#define SecOC_HasAuthDataFreshnessOfRxPduInfo()                                                     (TRUE != FALSE)
#define SecOC_HasAuthDataFreshnessStartBytePositionOfRxPduInfo()                                    (TRUE != FALSE)
#define SecOC_HasAuthenticExternalIdOfRxPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo()                         (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduUsedOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo()                 (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticationLayerIdOfRxPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheEndIdxOfRxPduInfo()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheLengthOfRxPduInfo()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheStartIdxOfRxPduInfo()                                            (TRUE != FALSE)
#define SecOC_HasBuildAttemptsOfRxPduInfo()                                                         (TRUE != FALSE)
#define SecOC_HasDataIdFirstByteOfRxPduInfo()                                                       (TRUE != FALSE)
#define SecOC_HasDataIdOfRxPduInfo()                                                                (TRUE != FALSE)
#define SecOC_HasDataIdSecondByteOfRxPduInfo()                                                      (TRUE != FALSE)
#define SecOC_HasExternalFreshnessIdOfRxPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasNumberOfMessagesToOverrideIdxOfRxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HasPduProcessingOfRxPduInfo()                                                         (TRUE != FALSE)
#define SecOC_HasPduTypeOfRxPduInfo()                                                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduLengthOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduUsedOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduLengthOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduUsedOfRxPduInfo()                                 (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTpSecuredPduUsedOfRxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo()                 (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo()                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo()                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo()                (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfo()                    (TRUE != FALSE)
#define SecOC_HasSecuredRxPduVerficationOfRxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasTruncAuthStartBitInByteOfRxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasTruncFreshnessValueFirstByteShiftOfRxPduInfo()                                     (TRUE != FALSE)
#define SecOC_HasTruncFreshnessValueSecondByteShiftOfRxPduInfo()                                    (TRUE != FALSE)
#define SecOC_HasVerificationStatusPropagationModeOfRxPduInfo()                                     (TRUE != FALSE)
#define SecOC_HasVerificationStatusWithSecuredPduPropagationModeOfRxPduInfo()                       (TRUE != FALSE)
#define SecOC_HasVerifyAttemptsOfRxPduInfo()                                                        (TRUE != FALSE)
#define SecOC_HasVerifyOverrideStatusIdxOfRxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasVerifyResultIdxOfRxPduInfo()                                                       (TRUE != FALSE)
#define SecOC_HasWaitForCallbackOfRxPduInfo()                                                       (TRUE != FALSE)
#define SecOC_HastruncatedAuthenticationLengthOfRxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HastruncatedFreshnessValueLengthOfRxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HasRxPduState()                                                                       (TRUE != FALSE)
#define SecOC_HasRxSecuredPduInfo()                                                                 (TRUE != FALSE)
#define SecOC_HasMessageLinkLenOfRxSecuredPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasMessageLinkPosOfRxSecuredPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasMessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo()                              (TRUE != FALSE)
#define SecOC_HasMessageTypeOfRxSecuredPduInfo()                                                    (TRUE != FALSE)
#define SecOC_HasMessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo()                              (TRUE != FALSE)
#define SecOC_HasMinimumPduLengthOfRxSecuredPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasPduFixLengthOfRxSecuredPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasRxPduInfoIdxOfRxSecuredPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerEndIdxOfRxSecuredPduInfo()                                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerLengthOfRxSecuredPduInfo()                                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerStartIdxOfRxSecuredPduInfo()                                (TRUE != FALSE)
#define SecOC_HasRxTpWrittenBytesCounter()                                                          (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainer()                                                          (TRUE != FALSE)
#define SecOC_HasSendDefaultAuthentication()                                                        (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticPduDataContainer()                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticatorCache()                                                         (TRUE != FALSE)
#define SecOC_HasSizeOfNumberOfMessagesToOverride()                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfRxAuthenticPduSizeOffset()                                                   (TRUE != FALSE)
#define SecOC_HasSizeOfRxBuildAttemptsCounter()                                                     (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduInfo()                                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduState()                                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfRxSecuredPduInfo()                                                           (TRUE != FALSE)
#define SecOC_HasSizeOfRxTpWrittenBytesCounter()                                                    (TRUE != FALSE)
#define SecOC_HasSizeOfSecuredPduDataContainer()                                                    (TRUE != FALSE)
#define SecOC_HasSizeOfSendDefaultAuthentication()                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfTransmitRequest()                                                            (TRUE != FALSE)
#define SecOC_HasSizeOfTxAuthenticPduInfo()                                                         (TRUE != FALSE)
#define SecOC_HasSizeOfTxAuthenticPduSizeOffset()                                                   (TRUE != FALSE)
#define SecOC_HasSizeOfTxBuildAttemptsCounter()                                                     (TRUE != FALSE)
#define SecOC_HasSizeOfTxPduInfo()                                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfTxPduState()                                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfTxResultLength()                                                             (TRUE != FALSE)
#define SecOC_HasSizeOfTxSecuredPduInfo()                                                           (TRUE != FALSE)
#define SecOC_HasSizeOfTxTpWrittenBytesCounter()                                                    (TRUE != FALSE)
#define SecOC_HasSizeOfVerificationStatusCallout()                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfVerificationStatusCalloutWithSecuredPdu()                                    (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyAttemptsCounter()                                                      (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyOverrideStatus()                                                       (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyResult()                                                               (TRUE != FALSE)
#define SecOC_HasTransmitRequest()                                                                  (TRUE != FALSE)
#define SecOC_HasTxAuthenticPduInfo()                                                               (TRUE != FALSE)
#define SecOC_HasMinimumPduLengthOfTxAuthenticPduInfo()                                             (TRUE != FALSE)
#define SecOC_HasTxPduInfoIdxOfTxAuthenticPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasTxAuthenticPduSizeOffset()                                                         (TRUE != FALSE)
#define SecOC_HasTxBuildAttemptsCounter()                                                           (TRUE != FALSE)
#define SecOC_HasTxPduInfo()                                                                        (TRUE != FALSE)
#define SecOC_HasAuthenticExternalIdOfTxPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo()                         (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerAuthenticPduUsedOfTxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo()                 (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFreshnessVerifyValueUsedOfTxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfo()                       (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo()                       (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerFullAuthenticPduUsedOfTxPduInfo()                         (TRUE != FALSE)
#define SecOC_HasAuthenticationLayerIdOfTxPduInfo()                                                 (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheEndIdxOfTxPduInfo()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheLengthOfTxPduInfo()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheStartIdxOfTxPduInfo()                                            (TRUE != FALSE)
#define SecOC_HasBuildAttemptsOfTxPduInfo()                                                         (TRUE != FALSE)
#define SecOC_HasConfirmationNeededOfTxPduInfo()                                                    (TRUE != FALSE)
#define SecOC_HasDataIdFirstByteOfTxPduInfo()                                                       (TRUE != FALSE)
#define SecOC_HasDataIdSecondByteOfTxPduInfo()                                                      (TRUE != FALSE)
#define SecOC_HasExternalFreshnessIdOfTxPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasLowerLayerPduTypeOfTxPduInfo()                                                     (TRUE != FALSE)
#define SecOC_HasPduProcessingOfTxPduInfo()                                                         (TRUE != FALSE)
#define SecOC_HasPduTypeOfTxPduInfo()                                                               (TRUE != FALSE)
#define SecOC_HasProvideTruncTxFreshnessOfTxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasSPduTxConfirmationNeededOfTxPduInfo()                                              (TRUE != FALSE)
#define SecOC_HasSecuredExternalIdOfTxPduInfo()                                                     (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthInfoDataUsedOfTxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduLengthOfTxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfo()                           (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerAuthenticPduUsedOfTxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduEndIdxOfTxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduLengthOfTxPduInfo()                               (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo()                             (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerSecuredPduUsedOfTxPduInfo()                                 (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo()                   (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo()                 (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedAuthenticatorUsedOfTxPduInfo()                     (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfo()                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo()                  (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfo()                (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerTruncatedFreshnessValueUsedOfTxPduInfo()                    (TRUE != FALSE)
#define SecOC_HasTruncAuthStartBitInByteOfTxPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasTruncFreshnessValueFirstByteShiftOfTxPduInfo()                                     (TRUE != FALSE)
#define SecOC_HasTruncFreshnessValueSecondByteShiftOfTxPduInfo()                                    (TRUE != FALSE)
#define SecOC_HasWaitForCallbackOfTxPduInfo()                                                       (TRUE != FALSE)
#define SecOC_HastruncatedAuthenticationLengthOfTxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HastruncatedFreshnessValueLengthOfTxPduInfo()                                         (TRUE != FALSE)
#define SecOC_HasTxPduState()                                                                       (TRUE != FALSE)
#define SecOC_HasTxResultLength()                                                                   (TRUE != FALSE)
#define SecOC_HasTxSecuredPduInfo()                                                                 (TRUE != FALSE)
#define SecOC_HasTxPduInfoIdxOfTxSecuredPduInfo()                                                   (TRUE != FALSE)
#define SecOC_HasTxSecuredPduTypeOfTxSecuredPduInfo()                                               (TRUE != FALSE)
#define SecOC_HasTxTpWrittenBytesCounter()                                                          (TRUE != FALSE)
#define SecOC_HasVerificationStatusCallout()                                                        (TRUE != FALSE)
#define SecOC_HasVerificationStatusCalloutWithSecuredPdu()                                          (TRUE != FALSE)
#define SecOC_HasVerifyAttemptsCounter()                                                            (TRUE != FALSE)
#define SecOC_HasVerifyOverrideStatus()                                                             (TRUE != FALSE)
#define SecOC_HasVerifyResult()                                                                     (TRUE != FALSE)
#define SecOC_HasPCConfig()                                                                         (TRUE != FALSE)
#define SecOC_HasAuthenticPduDataContainerOfPCConfig()                                              (TRUE != FALSE)
#define SecOC_HasAuthenticatorCacheOfPCConfig()                                                     (TRUE != FALSE)
#define SecOC_HasDevModeEnabledOfPCConfig()                                                         (TRUE != FALSE)
#define SecOC_HasInitializedOfPCConfig()                                                            (TRUE != FALSE)
#define SecOC_HasNumberOfMessagesToOverrideOfPCConfig()                                             (TRUE != FALSE)
#define SecOC_HasRxAuthenticPduSizeOffsetOfPCConfig()                                               (TRUE != FALSE)
#define SecOC_HasRxBuildAttemptsCounterOfPCConfig()                                                 (TRUE != FALSE)
#define SecOC_HasRxPduInfoOfPCConfig()                                                              (TRUE != FALSE)
#define SecOC_HasRxPduStateOfPCConfig()                                                             (TRUE != FALSE)
#define SecOC_HasRxSecuredPduInfoOfPCConfig()                                                       (TRUE != FALSE)
#define SecOC_HasRxTpWrittenBytesCounterOfPCConfig()                                                (TRUE != FALSE)
#define SecOC_HasSecuredPduDataContainerOfPCConfig()                                                (TRUE != FALSE)
#define SecOC_HasSendDefaultAuthenticationOfPCConfig()                                              (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticPduDataContainerOfPCConfig()                                        (TRUE != FALSE)
#define SecOC_HasSizeOfAuthenticatorCacheOfPCConfig()                                               (TRUE != FALSE)
#define SecOC_HasSizeOfNumberOfMessagesToOverrideOfPCConfig()                                       (TRUE != FALSE)
#define SecOC_HasSizeOfRxAuthenticPduSizeOffsetOfPCConfig()                                         (TRUE != FALSE)
#define SecOC_HasSizeOfRxBuildAttemptsCounterOfPCConfig()                                           (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduInfoOfPCConfig()                                                        (TRUE != FALSE)
#define SecOC_HasSizeOfRxPduStateOfPCConfig()                                                       (TRUE != FALSE)
#define SecOC_HasSizeOfRxSecuredPduInfoOfPCConfig()                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfRxTpWrittenBytesCounterOfPCConfig()                                          (TRUE != FALSE)
#define SecOC_HasSizeOfSecuredPduDataContainerOfPCConfig()                                          (TRUE != FALSE)
#define SecOC_HasSizeOfSendDefaultAuthenticationOfPCConfig()                                        (TRUE != FALSE)
#define SecOC_HasSizeOfTransmitRequestOfPCConfig()                                                  (TRUE != FALSE)
#define SecOC_HasSizeOfTxAuthenticPduInfoOfPCConfig()                                               (TRUE != FALSE)
#define SecOC_HasSizeOfTxAuthenticPduSizeOffsetOfPCConfig()                                         (TRUE != FALSE)
#define SecOC_HasSizeOfTxBuildAttemptsCounterOfPCConfig()                                           (TRUE != FALSE)
#define SecOC_HasSizeOfTxPduInfoOfPCConfig()                                                        (TRUE != FALSE)
#define SecOC_HasSizeOfTxPduStateOfPCConfig()                                                       (TRUE != FALSE)
#define SecOC_HasSizeOfTxResultLengthOfPCConfig()                                                   (TRUE != FALSE)
#define SecOC_HasSizeOfTxSecuredPduInfoOfPCConfig()                                                 (TRUE != FALSE)
#define SecOC_HasSizeOfTxTpWrittenBytesCounterOfPCConfig()                                          (TRUE != FALSE)
#define SecOC_HasSizeOfVerificationStatusCalloutOfPCConfig()                                        (TRUE != FALSE)
#define SecOC_HasSizeOfVerificationStatusCalloutWithSecuredPduOfPCConfig()                          (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyAttemptsCounterOfPCConfig()                                            (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyOverrideStatusOfPCConfig()                                             (TRUE != FALSE)
#define SecOC_HasSizeOfVerifyResultOfPCConfig()                                                     (TRUE != FALSE)
#define SecOC_HasTransmitRequestOfPCConfig()                                                        (TRUE != FALSE)
#define SecOC_HasTxAuthenticPduInfoOfPCConfig()                                                     (TRUE != FALSE)
#define SecOC_HasTxAuthenticPduSizeOffsetOfPCConfig()                                               (TRUE != FALSE)
#define SecOC_HasTxBuildAttemptsCounterOfPCConfig()                                                 (TRUE != FALSE)
#define SecOC_HasTxPduInfoOfPCConfig()                                                              (TRUE != FALSE)
#define SecOC_HasTxPduStateOfPCConfig()                                                             (TRUE != FALSE)
#define SecOC_HasTxResultLengthOfPCConfig()                                                         (TRUE != FALSE)
#define SecOC_HasTxSecuredPduInfoOfPCConfig()                                                       (TRUE != FALSE)
#define SecOC_HasTxTpWrittenBytesCounterOfPCConfig()                                                (TRUE != FALSE)
#define SecOC_HasVerificationStatusCalloutOfPCConfig()                                              (TRUE != FALSE)
#define SecOC_HasVerificationStatusCalloutWithSecuredPduOfPCConfig()                                (TRUE != FALSE)
#define SecOC_HasVerifyAttemptsCounterOfPCConfig()                                                  (TRUE != FALSE)
#define SecOC_HasVerifyOverrideStatusOfPCConfig()                                                   (TRUE != FALSE)
#define SecOC_HasVerifyResultOfPCConfig()                                                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCIncrementDataMacros  SecOC Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define SecOC_IncAuthenticPduDataContainer(Index)                                                   SecOC_GetAuthenticPduDataContainer(Index)++
#define SecOC_IncAuthenticatorCache(Index)                                                          SecOC_GetAuthenticatorCache(Index)++
#define SecOC_IncNumberOfMessagesToOverride(Index)                                                  SecOC_GetNumberOfMessagesToOverride(Index)++
#define SecOC_IncRxAuthenticPduSizeOffset(Index)                                                    SecOC_GetRxAuthenticPduSizeOffset(Index)++
#define SecOC_IncRxBuildAttemptsCounter(Index)                                                      SecOC_GetRxBuildAttemptsCounter(Index)++
#define SecOC_IncRxTpWrittenBytesCounter(Index)                                                     SecOC_GetRxTpWrittenBytesCounter(Index)++
#define SecOC_IncSecuredPduDataContainer(Index)                                                     SecOC_GetSecuredPduDataContainer(Index)++
#define SecOC_IncTxAuthenticPduSizeOffset(Index)                                                    SecOC_GetTxAuthenticPduSizeOffset(Index)++
#define SecOC_IncTxBuildAttemptsCounter(Index)                                                      SecOC_GetTxBuildAttemptsCounter(Index)++
#define SecOC_IncTxResultLength(Index)                                                              SecOC_GetTxResultLength(Index)++
#define SecOC_IncTxTpWrittenBytesCounter(Index)                                                     SecOC_GetTxTpWrittenBytesCounter(Index)++
#define SecOC_IncVerifyAttemptsCounter(Index)                                                       SecOC_GetVerifyAttemptsCounter(Index)++
#define SecOC_IncVerifyResult(Index)                                                                SecOC_GetVerifyResult(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCDecrementDataMacros  SecOC Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define SecOC_DecAuthenticPduDataContainer(Index)                                                   SecOC_GetAuthenticPduDataContainer(Index)--
#define SecOC_DecAuthenticatorCache(Index)                                                          SecOC_GetAuthenticatorCache(Index)--
#define SecOC_DecNumberOfMessagesToOverride(Index)                                                  SecOC_GetNumberOfMessagesToOverride(Index)--
#define SecOC_DecRxAuthenticPduSizeOffset(Index)                                                    SecOC_GetRxAuthenticPduSizeOffset(Index)--
#define SecOC_DecRxBuildAttemptsCounter(Index)                                                      SecOC_GetRxBuildAttemptsCounter(Index)--
#define SecOC_DecRxTpWrittenBytesCounter(Index)                                                     SecOC_GetRxTpWrittenBytesCounter(Index)--
#define SecOC_DecSecuredPduDataContainer(Index)                                                     SecOC_GetSecuredPduDataContainer(Index)--
#define SecOC_DecTxAuthenticPduSizeOffset(Index)                                                    SecOC_GetTxAuthenticPduSizeOffset(Index)--
#define SecOC_DecTxBuildAttemptsCounter(Index)                                                      SecOC_GetTxBuildAttemptsCounter(Index)--
#define SecOC_DecTxResultLength(Index)                                                              SecOC_GetTxResultLength(Index)--
#define SecOC_DecTxTpWrittenBytesCounter(Index)                                                     SecOC_GetTxTpWrittenBytesCounter(Index)--
#define SecOC_DecVerifyAttemptsCounter(Index)                                                       SecOC_GetVerifyAttemptsCounter(Index)--
#define SecOC_DecVerifyResult(Index)                                                                SecOC_GetVerifyResult(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCAddDataMacros  SecOC Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define SecOC_AddAuthenticPduDataContainer(Index, Value)                                            SecOC_SetAuthenticPduDataContainer(Index, (SecOC_GetAuthenticPduDataContainer(Index) + Value))
#define SecOC_AddAuthenticatorCache(Index, Value)                                                   SecOC_SetAuthenticatorCache(Index, (SecOC_GetAuthenticatorCache(Index) + Value))
#define SecOC_AddNumberOfMessagesToOverride(Index, Value)                                           SecOC_SetNumberOfMessagesToOverride(Index, (SecOC_GetNumberOfMessagesToOverride(Index) + Value))
#define SecOC_AddRxAuthenticPduSizeOffset(Index, Value)                                             SecOC_SetRxAuthenticPduSizeOffset(Index, (SecOC_GetRxAuthenticPduSizeOffset(Index) + Value))
#define SecOC_AddRxBuildAttemptsCounter(Index, Value)                                               SecOC_SetRxBuildAttemptsCounter(Index, (SecOC_GetRxBuildAttemptsCounter(Index) + Value))
#define SecOC_AddRxTpWrittenBytesCounter(Index, Value)                                              SecOC_SetRxTpWrittenBytesCounter(Index, (SecOC_GetRxTpWrittenBytesCounter(Index) + Value))
#define SecOC_AddSecuredPduDataContainer(Index, Value)                                              SecOC_SetSecuredPduDataContainer(Index, (SecOC_GetSecuredPduDataContainer(Index) + Value))
#define SecOC_AddTxAuthenticPduSizeOffset(Index, Value)                                             SecOC_SetTxAuthenticPduSizeOffset(Index, (SecOC_GetTxAuthenticPduSizeOffset(Index) + Value))
#define SecOC_AddTxBuildAttemptsCounter(Index, Value)                                               SecOC_SetTxBuildAttemptsCounter(Index, (SecOC_GetTxBuildAttemptsCounter(Index) + Value))
#define SecOC_AddTxResultLength(Index, Value)                                                       SecOC_SetTxResultLength(Index, (SecOC_GetTxResultLength(Index) + Value))
#define SecOC_AddTxTpWrittenBytesCounter(Index, Value)                                              SecOC_SetTxTpWrittenBytesCounter(Index, (SecOC_GetTxTpWrittenBytesCounter(Index) + Value))
#define SecOC_AddVerifyAttemptsCounter(Index, Value)                                                SecOC_SetVerifyAttemptsCounter(Index, (SecOC_GetVerifyAttemptsCounter(Index) + Value))
#define SecOC_AddVerifyResult(Index, Value)                                                         SecOC_SetVerifyResult(Index, (SecOC_GetVerifyResult(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSubstractDataMacros  SecOC Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define SecOC_SubAuthenticPduDataContainer(Index, Value)                                            SecOC_SetAuthenticPduDataContainer(Index, (SecOC_GetAuthenticPduDataContainer(Index) - Value))
#define SecOC_SubAuthenticatorCache(Index, Value)                                                   SecOC_SetAuthenticatorCache(Index, (SecOC_GetAuthenticatorCache(Index) - Value))
#define SecOC_SubNumberOfMessagesToOverride(Index, Value)                                           SecOC_SetNumberOfMessagesToOverride(Index, (SecOC_GetNumberOfMessagesToOverride(Index) - Value))
#define SecOC_SubRxAuthenticPduSizeOffset(Index, Value)                                             SecOC_SetRxAuthenticPduSizeOffset(Index, (SecOC_GetRxAuthenticPduSizeOffset(Index) - Value))
#define SecOC_SubRxBuildAttemptsCounter(Index, Value)                                               SecOC_SetRxBuildAttemptsCounter(Index, (SecOC_GetRxBuildAttemptsCounter(Index) - Value))
#define SecOC_SubRxTpWrittenBytesCounter(Index, Value)                                              SecOC_SetRxTpWrittenBytesCounter(Index, (SecOC_GetRxTpWrittenBytesCounter(Index) - Value))
#define SecOC_SubSecuredPduDataContainer(Index, Value)                                              SecOC_SetSecuredPduDataContainer(Index, (SecOC_GetSecuredPduDataContainer(Index) - Value))
#define SecOC_SubTxAuthenticPduSizeOffset(Index, Value)                                             SecOC_SetTxAuthenticPduSizeOffset(Index, (SecOC_GetTxAuthenticPduSizeOffset(Index) - Value))
#define SecOC_SubTxBuildAttemptsCounter(Index, Value)                                               SecOC_SetTxBuildAttemptsCounter(Index, (SecOC_GetTxBuildAttemptsCounter(Index) - Value))
#define SecOC_SubTxResultLength(Index, Value)                                                       SecOC_SetTxResultLength(Index, (SecOC_GetTxResultLength(Index) - Value))
#define SecOC_SubTxTpWrittenBytesCounter(Index, Value)                                              SecOC_SetTxTpWrittenBytesCounter(Index, (SecOC_GetTxTpWrittenBytesCounter(Index) - Value))
#define SecOC_SubVerifyAttemptsCounter(Index, Value)                                                SecOC_SetVerifyAttemptsCounter(Index, (SecOC_GetVerifyAttemptsCounter(Index) - Value))
#define SecOC_SubVerifyResult(Index, Value)                                                         SecOC_SetVerifyResult(Index, (SecOC_GetVerifyResult(Index) - Value))
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCIterableTypes  SecOC Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate SecOC_AuthenticPduDataContainer */
typedef uint16_least SecOC_AuthenticPduDataContainerIterType;

/**   \brief  type used to iterate SecOC_AuthenticatorCache */
typedef uint8_least SecOC_AuthenticatorCacheIterType;

/**   \brief  type used to iterate SecOC_NumberOfMessagesToOverride */
typedef uint8_least SecOC_NumberOfMessagesToOverrideIterType;

/**   \brief  type used to iterate SecOC_RxPduInfo */
typedef uint8_least SecOC_RxPduInfoIterType;

/**   \brief  type used to iterate SecOC_RxSecuredPduInfo */
typedef uint8_least SecOC_RxSecuredPduInfoIterType;

/**   \brief  type used to iterate SecOC_SecuredPduDataContainer */
typedef uint16_least SecOC_SecuredPduDataContainerIterType;

/**   \brief  type used to iterate SecOC_TxAuthenticPduInfo */
typedef uint8_least SecOC_TxAuthenticPduInfoIterType;

/**   \brief  type used to iterate SecOC_TxPduInfo */
typedef uint8_least SecOC_TxPduInfoIterType;

/**   \brief  type used to iterate SecOC_TxSecuredPduInfo */
typedef uint8_least SecOC_TxSecuredPduInfoIterType;

/**   \brief  type used to iterate SecOC_VerificationStatusCallout */
typedef uint8_least SecOC_VerificationStatusCalloutIterType;

/**   \brief  type used to iterate SecOC_VerificationStatusCalloutWithSecuredPdu */
typedef uint8_least SecOC_VerificationStatusCalloutWithSecuredPduIterType;

/**   \brief  type used to iterate SecOC_VerifyOverrideStatus */
typedef uint8_least SecOC_VerifyOverrideStatusIterType;

/**   \brief  type used to iterate SecOC_VerifyResult */
typedef uint8_least SecOC_VerifyResultIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCIterableTypesWithSizeRelations  SecOC Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate SecOC_RxAuthenticPduSizeOffset */
typedef SecOC_RxPduInfoIterType SecOC_RxAuthenticPduSizeOffsetIterType;

/**   \brief  type used to iterate SecOC_RxBuildAttemptsCounter */
typedef SecOC_RxPduInfoIterType SecOC_RxBuildAttemptsCounterIterType;

/**   \brief  type used to iterate SecOC_RxPduState */
typedef SecOC_RxPduInfoIterType SecOC_RxPduStateIterType;

/**   \brief  type used to iterate SecOC_RxTpWrittenBytesCounter */
typedef SecOC_RxPduInfoIterType SecOC_RxTpWrittenBytesCounterIterType;

/**   \brief  type used to iterate SecOC_SendDefaultAuthentication */
typedef SecOC_TxPduInfoIterType SecOC_SendDefaultAuthenticationIterType;

/**   \brief  type used to iterate SecOC_TransmitRequest */
typedef SecOC_TxPduInfoIterType SecOC_TransmitRequestIterType;

/**   \brief  type used to iterate SecOC_TxAuthenticPduSizeOffset */
typedef SecOC_TxPduInfoIterType SecOC_TxAuthenticPduSizeOffsetIterType;

/**   \brief  type used to iterate SecOC_TxBuildAttemptsCounter */
typedef SecOC_TxPduInfoIterType SecOC_TxBuildAttemptsCounterIterType;

/**   \brief  type used to iterate SecOC_TxPduState */
typedef SecOC_TxPduInfoIterType SecOC_TxPduStateIterType;

/**   \brief  type used to iterate SecOC_TxResultLength */
typedef SecOC_TxPduInfoIterType SecOC_TxResultLengthIterType;

/**   \brief  type used to iterate SecOC_TxTpWrittenBytesCounter */
typedef SecOC_TxPduInfoIterType SecOC_TxTpWrittenBytesCounterIterType;

/**   \brief  type used to iterate SecOC_VerifyAttemptsCounter */
typedef SecOC_RxPduInfoIterType SecOC_VerifyAttemptsCounterIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCValueTypes  SecOC Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for SecOC_AuthenticPduDataContainer */
typedef uint8 SecOC_AuthenticPduDataContainerType;

/**   \brief  value based type definition for SecOC_AuthenticatorCache */
typedef uint8 SecOC_AuthenticatorCacheType;

/**   \brief  value based type definition for SecOC_DevModeEnabled */
typedef boolean SecOC_DevModeEnabledType;

/**   \brief  value based type definition for SecOC_Initialized */
typedef boolean SecOC_InitializedType;

/**   \brief  value based type definition for SecOC_NumberOfMessagesToOverride */
typedef uint8 SecOC_NumberOfMessagesToOverrideType;

/**   \brief  value based type definition for SecOC_RxAuthenticPduSizeOffset */
typedef uint16 SecOC_RxAuthenticPduSizeOffsetType;

/**   \brief  value based type definition for SecOC_RxBuildAttemptsCounter */
typedef uint16 SecOC_RxBuildAttemptsCounterType;

/**   \brief  value based type definition for SecOC_AuthDataFreshnessLenOfRxPduInfo */
typedef uint8 SecOC_AuthDataFreshnessLenOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthDataFreshnessOfRxPduInfo */
typedef uint8 SecOC_AuthDataFreshnessOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthDataFreshnessStartBytePositionOfRxPduInfo */
typedef uint8 SecOC_AuthDataFreshnessStartBytePositionOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticExternalIdOfRxPduInfo */
typedef uint8 SecOC_AuthenticExternalIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduUsedOfRxPduInfo */
typedef boolean SecOC_AuthenticPduDataContainerAuthenticPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfo */
typedef boolean SecOC_AuthenticPduDataContainerFreshnessVerifyValueUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticationLayerIdOfRxPduInfo */
typedef uint16 SecOC_AuthenticationLayerIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheEndIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheLengthOfRxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheStartIdxOfRxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_BuildAttemptsOfRxPduInfo */
typedef uint8 SecOC_BuildAttemptsOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdFirstByteOfRxPduInfo */
typedef uint8 SecOC_DataIdFirstByteOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdOfRxPduInfo */
typedef uint16 SecOC_DataIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdSecondByteOfRxPduInfo */
typedef uint8 SecOC_DataIdSecondByteOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_ExternalFreshnessIdOfRxPduInfo */
typedef uint8 SecOC_ExternalFreshnessIdOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_NumberOfMessagesToOverrideIdxOfRxPduInfo */
typedef uint8 SecOC_NumberOfMessagesToOverrideIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_PduProcessingOfRxPduInfo */
typedef uint8 SecOC_PduProcessingOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_PduTypeOfRxPduInfo */
typedef uint8 SecOC_PduTypeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerAuthenticPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerAuthenticPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerSecuredPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerSecuredPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTpSecuredPduUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTpSecuredPduUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTruncatedAuthenticatorUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTruncatedFreshnessValueUsedOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredRxPduVerficationOfRxPduInfo */
typedef boolean SecOC_SecuredRxPduVerficationOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncAuthStartBitInByteOfRxPduInfo */
typedef uint8 SecOC_TruncAuthStartBitInByteOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncFreshnessValueFirstByteShiftOfRxPduInfo */
typedef uint8 SecOC_TruncFreshnessValueFirstByteShiftOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncFreshnessValueSecondByteShiftOfRxPduInfo */
typedef uint8 SecOC_TruncFreshnessValueSecondByteShiftOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerificationStatusPropagationModeOfRxPduInfo */
typedef uint8 SecOC_VerificationStatusPropagationModeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerificationStatusWithSecuredPduPropagationModeOfRxPduInfo */
typedef uint8 SecOC_VerificationStatusWithSecuredPduPropagationModeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerifyAttemptsOfRxPduInfo */
typedef uint8 SecOC_VerifyAttemptsOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerifyOverrideStatusIdxOfRxPduInfo */
typedef uint8 SecOC_VerifyOverrideStatusIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_VerifyResultIdxOfRxPduInfo */
typedef uint8 SecOC_VerifyResultIdxOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_WaitForCallbackOfRxPduInfo */
typedef boolean SecOC_WaitForCallbackOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_truncatedAuthenticationLengthOfRxPduInfo */
typedef uint8 SecOC_truncatedAuthenticationLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_truncatedFreshnessValueLengthOfRxPduInfo */
typedef uint8 SecOC_truncatedFreshnessValueLengthOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_RxPduState */
typedef uint8 SecOC_RxPduStateType;

/**   \brief  value based type definition for SecOC_MessageLinkLenOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageLinkLenOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessageLinkPosOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageLinkPosOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessageTypeOfRxSecuredPduInfo */
typedef uint8 SecOC_MessageTypeOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo */
typedef uint8 SecOC_MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_MinimumPduLengthOfRxSecuredPduInfo */
typedef uint8 SecOC_MinimumPduLengthOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_PduFixLengthOfRxSecuredPduInfo */
typedef uint8 SecOC_PduFixLengthOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_RxPduInfoIdxOfRxSecuredPduInfo */
typedef uint8 SecOC_RxPduInfoIdxOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerEndIdxOfRxSecuredPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerEndIdxOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerLengthOfRxSecuredPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerLengthOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerStartIdxOfRxSecuredPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerStartIdxOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_RxTpWrittenBytesCounter */
typedef PduLengthType SecOC_RxTpWrittenBytesCounterType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainer */
typedef uint8 SecOC_SecuredPduDataContainerType;

/**   \brief  value based type definition for SecOC_SendDefaultAuthentication */
typedef boolean SecOC_SendDefaultAuthenticationType;

/**   \brief  value based type definition for SecOC_SizeOfAuthenticPduDataContainer */
typedef uint16 SecOC_SizeOfAuthenticPduDataContainerType;

/**   \brief  value based type definition for SecOC_SizeOfAuthenticatorCache */
typedef uint8 SecOC_SizeOfAuthenticatorCacheType;

/**   \brief  value based type definition for SecOC_SizeOfNumberOfMessagesToOverride */
typedef uint8 SecOC_SizeOfNumberOfMessagesToOverrideType;

/**   \brief  value based type definition for SecOC_SizeOfRxAuthenticPduSizeOffset */
typedef uint8 SecOC_SizeOfRxAuthenticPduSizeOffsetType;

/**   \brief  value based type definition for SecOC_SizeOfRxBuildAttemptsCounter */
typedef uint8 SecOC_SizeOfRxBuildAttemptsCounterType;

/**   \brief  value based type definition for SecOC_SizeOfRxPduInfo */
typedef uint8 SecOC_SizeOfRxPduInfoType;

/**   \brief  value based type definition for SecOC_SizeOfRxPduState */
typedef uint8 SecOC_SizeOfRxPduStateType;

/**   \brief  value based type definition for SecOC_SizeOfRxSecuredPduInfo */
typedef uint8 SecOC_SizeOfRxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SizeOfRxTpWrittenBytesCounter */
typedef uint8 SecOC_SizeOfRxTpWrittenBytesCounterType;

/**   \brief  value based type definition for SecOC_SizeOfSecuredPduDataContainer */
typedef uint16 SecOC_SizeOfSecuredPduDataContainerType;

/**   \brief  value based type definition for SecOC_SizeOfSendDefaultAuthentication */
typedef uint8 SecOC_SizeOfSendDefaultAuthenticationType;

/**   \brief  value based type definition for SecOC_SizeOfTransmitRequest */
typedef uint8 SecOC_SizeOfTransmitRequestType;

/**   \brief  value based type definition for SecOC_SizeOfTxAuthenticPduInfo */
typedef uint8 SecOC_SizeOfTxAuthenticPduInfoType;

/**   \brief  value based type definition for SecOC_SizeOfTxAuthenticPduSizeOffset */
typedef uint8 SecOC_SizeOfTxAuthenticPduSizeOffsetType;

/**   \brief  value based type definition for SecOC_SizeOfTxBuildAttemptsCounter */
typedef uint8 SecOC_SizeOfTxBuildAttemptsCounterType;

/**   \brief  value based type definition for SecOC_SizeOfTxPduInfo */
typedef uint8 SecOC_SizeOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SizeOfTxPduState */
typedef uint8 SecOC_SizeOfTxPduStateType;

/**   \brief  value based type definition for SecOC_SizeOfTxResultLength */
typedef uint8 SecOC_SizeOfTxResultLengthType;

/**   \brief  value based type definition for SecOC_SizeOfTxSecuredPduInfo */
typedef uint8 SecOC_SizeOfTxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_SizeOfTxTpWrittenBytesCounter */
typedef uint8 SecOC_SizeOfTxTpWrittenBytesCounterType;

/**   \brief  value based type definition for SecOC_SizeOfVerificationStatusCallout */
typedef uint8 SecOC_SizeOfVerificationStatusCalloutType;

/**   \brief  value based type definition for SecOC_SizeOfVerificationStatusCalloutWithSecuredPdu */
typedef uint8 SecOC_SizeOfVerificationStatusCalloutWithSecuredPduType;

/**   \brief  value based type definition for SecOC_SizeOfVerifyAttemptsCounter */
typedef uint8 SecOC_SizeOfVerifyAttemptsCounterType;

/**   \brief  value based type definition for SecOC_SizeOfVerifyOverrideStatus */
typedef uint8 SecOC_SizeOfVerifyOverrideStatusType;

/**   \brief  value based type definition for SecOC_SizeOfVerifyResult */
typedef uint8 SecOC_SizeOfVerifyResultType;

/**   \brief  value based type definition for SecOC_TransmitRequest */
typedef uint8 SecOC_TransmitRequestType;

/**   \brief  value based type definition for SecOC_MinimumPduLengthOfTxAuthenticPduInfo */
typedef uint8 SecOC_MinimumPduLengthOfTxAuthenticPduInfoType;

/**   \brief  value based type definition for SecOC_TxPduInfoIdxOfTxAuthenticPduInfo */
typedef uint8 SecOC_TxPduInfoIdxOfTxAuthenticPduInfoType;

/**   \brief  value based type definition for SecOC_TxAuthenticPduSizeOffset */
typedef uint16 SecOC_TxAuthenticPduSizeOffsetType;

/**   \brief  value based type definition for SecOC_TxBuildAttemptsCounter */
typedef uint16 SecOC_TxBuildAttemptsCounterType;

/**   \brief  value based type definition for SecOC_AuthenticExternalIdOfTxPduInfo */
typedef uint8 SecOC_AuthenticExternalIdOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerAuthenticPduLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerAuthenticPduUsedOfTxPduInfo */
typedef boolean SecOC_AuthenticPduDataContainerAuthenticPduUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFreshnessVerifyValueUsedOfTxPduInfo */
typedef boolean SecOC_AuthenticPduDataContainerFreshnessVerifyValueUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo */
typedef uint8 SecOC_AuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfo */
typedef uint16 SecOC_AuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticPduDataContainerFullAuthenticPduUsedOfTxPduInfo */
typedef boolean SecOC_AuthenticPduDataContainerFullAuthenticPduUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticationLayerIdOfTxPduInfo */
typedef uint16 SecOC_AuthenticationLayerIdOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheEndIdxOfTxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheLengthOfTxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_AuthenticatorCacheStartIdxOfTxPduInfo */
typedef uint8 SecOC_AuthenticatorCacheStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_BuildAttemptsOfTxPduInfo */
typedef uint8 SecOC_BuildAttemptsOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_ConfirmationNeededOfTxPduInfo */
typedef boolean SecOC_ConfirmationNeededOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdFirstByteOfTxPduInfo */
typedef uint8 SecOC_DataIdFirstByteOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_DataIdSecondByteOfTxPduInfo */
typedef uint8 SecOC_DataIdSecondByteOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_ExternalFreshnessIdOfTxPduInfo */
typedef uint8 SecOC_ExternalFreshnessIdOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_LowerLayerPduTypeOfTxPduInfo */
typedef uint8 SecOC_LowerLayerPduTypeOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_PduProcessingOfTxPduInfo */
typedef uint8 SecOC_PduProcessingOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_PduTypeOfTxPduInfo */
typedef uint8 SecOC_PduTypeOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_ProvideTruncTxFreshnessOfTxPduInfo */
typedef uint8 SecOC_ProvideTruncTxFreshnessOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SPduTxConfirmationNeededOfTxPduInfo */
typedef boolean SecOC_SPduTxConfirmationNeededOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredExternalIdOfTxPduInfo */
typedef uint8 SecOC_SecuredExternalIdOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerAuthInfoDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthInfoDataUsedOfTxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerAuthInfoDataUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduLengthOfTxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerAuthenticPduLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerAuthenticPduUsedOfTxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerAuthenticPduUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduEndIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerSecuredPduEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduLengthOfTxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerSecuredPduLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerSecuredPduStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerSecuredPduUsedOfTxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerSecuredPduUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedAuthenticatorUsedOfTxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTruncatedAuthenticatorUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo */
typedef uint8 SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfo */
typedef uint16 SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_SecuredPduDataContainerTruncatedFreshnessValueUsedOfTxPduInfo */
typedef boolean SecOC_SecuredPduDataContainerTruncatedFreshnessValueUsedOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncAuthStartBitInByteOfTxPduInfo */
typedef uint8 SecOC_TruncAuthStartBitInByteOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncFreshnessValueFirstByteShiftOfTxPduInfo */
typedef uint8 SecOC_TruncFreshnessValueFirstByteShiftOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_TruncFreshnessValueSecondByteShiftOfTxPduInfo */
typedef uint8 SecOC_TruncFreshnessValueSecondByteShiftOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_WaitForCallbackOfTxPduInfo */
typedef boolean SecOC_WaitForCallbackOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_truncatedAuthenticationLengthOfTxPduInfo */
typedef uint8 SecOC_truncatedAuthenticationLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_truncatedFreshnessValueLengthOfTxPduInfo */
typedef uint8 SecOC_truncatedFreshnessValueLengthOfTxPduInfoType;

/**   \brief  value based type definition for SecOC_TxPduState */
typedef uint8 SecOC_TxPduStateType;

/**   \brief  value based type definition for SecOC_TxResultLength */
typedef uint32 SecOC_TxResultLengthType;

/**   \brief  value based type definition for SecOC_TxPduInfoIdxOfTxSecuredPduInfo */
typedef uint8 SecOC_TxPduInfoIdxOfTxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_TxSecuredPduTypeOfTxSecuredPduInfo */
typedef uint8 SecOC_TxSecuredPduTypeOfTxSecuredPduInfoType;

/**   \brief  value based type definition for SecOC_TxTpWrittenBytesCounter */
typedef PduLengthType SecOC_TxTpWrittenBytesCounterType;

/**   \brief  value based type definition for SecOC_VerifyAttemptsCounter */
typedef uint16 SecOC_VerifyAttemptsCounterType;

/**   \brief  value based type definition for SecOC_VerifyOverrideStatus */
typedef uint8 SecOC_VerifyOverrideStatusType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SecOCPCStructTypes  SecOC Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in SecOC_RxPduInfo */
/*! \spec weak type invariant () { 
 * (self.AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer()) &&
 * (self.AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer()) &&
 * (self.AuthenticatorCacheStartIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticatorCache()) &&
 * (self.AuthenticatorCacheEndIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticatorCache()) &&
 * (self.VerifyResultIdxOfRxPduInfo < SecOC_GetSizeOfVerifyResult()) &&
 * (self.NumberOfMessagesToOverrideIdxOfRxPduInfo < SecOC_GetSizeOfNumberOfMessagesToOverride()) &&
 * (self.VerifyOverrideStatusIdxOfRxPduInfo < SecOC_GetSizeOfVerifyOverrideStatus()) &&
 * (!((self.SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerSecuredPduLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerSecuredPduLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo != 0u)) || (self.AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo != 0u)) || (self.AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo != 0u)) || (self.AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo != 0u)) || (self.AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo != 0u)) || (self.SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer()))
 * } */
typedef struct sSecOC_RxPduInfoType
{
  SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfoType AuthenticPduDataContainerAuthenticPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfoType AuthenticPduDataContainerAuthenticPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfoType AuthenticPduDataContainerDataToAuthenticateEndIdxOfRxPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfoType AuthenticPduDataContainerDataToAuthenticateStartIdxOfRxPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticationLayerIdOfRxPduInfoType AuthenticationLayerIdOfRxPduInfo;
  SecOC_DataIdOfRxPduInfoType DataIdOfRxPduInfo;
  SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfoType SecuredPduDataContainerAuthenticPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfoType SecuredPduDataContainerAuthenticPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfoType SecuredPduDataContainerSecuredPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfoType SecuredPduDataContainerSecuredPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfoType SecuredPduDataContainerTpSecuredPduEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfoType SecuredPduDataContainerTpSecuredPduStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredRxPduVerficationOfRxPduInfoType SecuredRxPduVerficationOfRxPduInfo;
  SecOC_WaitForCallbackOfRxPduInfoType WaitForCallbackOfRxPduInfo;
  SecOC_AuthDataFreshnessOfRxPduInfoType AuthDataFreshnessOfRxPduInfo;
  SecOC_AuthDataFreshnessLenOfRxPduInfoType AuthDataFreshnessLenOfRxPduInfo;
  SecOC_AuthDataFreshnessStartBytePositionOfRxPduInfoType AuthDataFreshnessStartBytePositionOfRxPduInfo;
  SecOC_AuthenticExternalIdOfRxPduInfoType AuthenticExternalIdOfRxPduInfo;
  SecOC_AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfoType AuthenticPduDataContainerAuthenticPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfoType AuthenticPduDataContainerDataToAuthenticateLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticatorCacheEndIdxOfRxPduInfoType AuthenticatorCacheEndIdxOfRxPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_AuthenticatorCache */
  SecOC_AuthenticatorCacheLengthOfRxPduInfoType AuthenticatorCacheLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticatorCache */
  SecOC_AuthenticatorCacheStartIdxOfRxPduInfoType AuthenticatorCacheStartIdxOfRxPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_AuthenticatorCache */
  SecOC_BuildAttemptsOfRxPduInfoType BuildAttemptsOfRxPduInfo;
  SecOC_DataIdFirstByteOfRxPduInfoType DataIdFirstByteOfRxPduInfo;
  SecOC_DataIdSecondByteOfRxPduInfoType DataIdSecondByteOfRxPduInfo;
  SecOC_ExternalFreshnessIdOfRxPduInfoType ExternalFreshnessIdOfRxPduInfo;
  SecOC_NumberOfMessagesToOverrideIdxOfRxPduInfoType NumberOfMessagesToOverrideIdxOfRxPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_NumberOfMessagesToOverride */
  SecOC_PduProcessingOfRxPduInfoType PduProcessingOfRxPduInfo;
  SecOC_PduTypeOfRxPduInfoType PduTypeOfRxPduInfo;
  SecOC_SecuredPduDataContainerAuthenticPduLengthOfRxPduInfoType SecuredPduDataContainerAuthenticPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduLengthOfRxPduInfoType SecuredPduDataContainerSecuredPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfoType SecuredPduDataContainerTpSecuredPduLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueLengthOfRxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_TruncAuthStartBitInByteOfRxPduInfoType TruncAuthStartBitInByteOfRxPduInfo;
  SecOC_TruncFreshnessValueFirstByteShiftOfRxPduInfoType TruncFreshnessValueFirstByteShiftOfRxPduInfo;
  SecOC_TruncFreshnessValueSecondByteShiftOfRxPduInfoType TruncFreshnessValueSecondByteShiftOfRxPduInfo;
  SecOC_VerificationStatusPropagationModeOfRxPduInfoType VerificationStatusPropagationModeOfRxPduInfo;
  SecOC_VerificationStatusWithSecuredPduPropagationModeOfRxPduInfoType VerificationStatusWithSecuredPduPropagationModeOfRxPduInfo;
  SecOC_VerifyAttemptsOfRxPduInfoType VerifyAttemptsOfRxPduInfo;
  SecOC_VerifyOverrideStatusIdxOfRxPduInfoType VerifyOverrideStatusIdxOfRxPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_VerifyOverrideStatus */
  SecOC_VerifyResultIdxOfRxPduInfoType VerifyResultIdxOfRxPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_VerifyResult */
  SecOC_truncatedAuthenticationLengthOfRxPduInfoType truncatedAuthenticationLengthOfRxPduInfo;
  SecOC_truncatedFreshnessValueLengthOfRxPduInfoType truncatedFreshnessValueLengthOfRxPduInfo;
} SecOC_RxPduInfoType;

/**   \brief  type used in SecOC_RxSecuredPduInfo */
/*! \spec weak type invariant () { 
 * (self.RxPduInfoIdxOfRxSecuredPduInfo < SecOC_GetSizeOfRxPduInfo()) &&
 * (self.SecuredPduDataContainerStartIdxOfRxSecuredPduInfo < SecOC_GetSizeOfSecuredPduDataContainer()) &&
 * (self.SecuredPduDataContainerEndIdxOfRxSecuredPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())
 * } */
typedef struct sSecOC_RxSecuredPduInfoType
{
  SecOC_SecuredPduDataContainerEndIdxOfRxSecuredPduInfoType SecuredPduDataContainerEndIdxOfRxSecuredPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerStartIdxOfRxSecuredPduInfoType SecuredPduDataContainerStartIdxOfRxSecuredPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_MessageLinkLenOfRxSecuredPduInfoType MessageLinkLenOfRxSecuredPduInfo;
  SecOC_MessageLinkPosOfRxSecuredPduInfoType MessageLinkPosOfRxSecuredPduInfo;
  SecOC_MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfoType MessageLinkerStartByteInCryptoPduOfRxSecuredPduInfo;
  SecOC_MessageTypeOfRxSecuredPduInfoType MessageTypeOfRxSecuredPduInfo;
  SecOC_MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfoType MessagesLinkCryptoPduSrcBitOffsetOfRxSecuredPduInfo;
  SecOC_MinimumPduLengthOfRxSecuredPduInfoType MinimumPduLengthOfRxSecuredPduInfo;
  SecOC_PduFixLengthOfRxSecuredPduInfoType PduFixLengthOfRxSecuredPduInfo;
  SecOC_RxPduInfoIdxOfRxSecuredPduInfoType RxPduInfoIdxOfRxSecuredPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_RxPduInfo */
  SecOC_SecuredPduDataContainerLengthOfRxSecuredPduInfoType SecuredPduDataContainerLengthOfRxSecuredPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
} SecOC_RxSecuredPduInfoType;

/**   \brief  type used in SecOC_TxAuthenticPduInfo */
/*! \spec weak type invariant () { 
 * (self.TxPduInfoIdxOfTxAuthenticPduInfo < SecOC_GetSizeOfTxPduInfo())
 * } */
typedef struct sSecOC_TxAuthenticPduInfoType
{
  SecOC_MinimumPduLengthOfTxAuthenticPduInfoType MinimumPduLengthOfTxAuthenticPduInfo;
  SecOC_TxPduInfoIdxOfTxAuthenticPduInfoType TxPduInfoIdxOfTxAuthenticPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_TxPduInfo */
} SecOC_TxAuthenticPduInfoType;

/**   \brief  type used in SecOC_TxPduInfo */
/*! \spec weak type invariant () { 
 * (self.AuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer()) &&
 * (self.AuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer()) &&
 * (self.AuthenticatorCacheStartIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticatorCache()) &&
 * (self.AuthenticatorCacheEndIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticatorCache()) &&
 * (!((self.SecuredPduDataContainerAuthenticPduLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerAuthenticPduLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerSecuredPduLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerSecuredPduLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerSecuredPduEndIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo != 0u)) || (self.AuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo != 0u)) || (self.AuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo != 0u)) || (self.AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo != 0u)) || (self.AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.SecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo != 0u)) || (self.SecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfo < SecOC_GetSizeOfSecuredPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo != 0u)) || (self.AuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer())) &&
 * (!((self.AuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo != 0u)) || (self.AuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfo < SecOC_GetSizeOfAuthenticPduDataContainer()))
 * } */
typedef struct sSecOC_TxPduInfoType
{
  SecOC_AuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfoType AuthenticPduDataContainerAuthenticPduEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfoType AuthenticPduDataContainerAuthenticPduStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfoType AuthenticPduDataContainerDataToAuthenticateEndIdxOfTxPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfoType AuthenticPduDataContainerDataToAuthenticateStartIdxOfTxPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfoType AuthenticPduDataContainerFullAuthenticPduEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfoType AuthenticPduDataContainerFullAuthenticPduStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticationLayerIdOfTxPduInfoType AuthenticationLayerIdOfTxPduInfo;
  SecOC_SecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfoType SecuredPduDataContainerAuthInfoDataEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfoType SecuredPduDataContainerAuthInfoDataStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfoType SecuredPduDataContainerAuthenticPduEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfoType SecuredPduDataContainerAuthenticPduStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduEndIdxOfTxPduInfoType SecuredPduDataContainerSecuredPduEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduStartIdxOfTxPduInfoType SecuredPduDataContainerSecuredPduStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer */
  SecOC_ConfirmationNeededOfTxPduInfoType ConfirmationNeededOfTxPduInfo;
  SecOC_SPduTxConfirmationNeededOfTxPduInfoType SPduTxConfirmationNeededOfTxPduInfo;
  SecOC_WaitForCallbackOfTxPduInfoType WaitForCallbackOfTxPduInfo;
  SecOC_AuthenticExternalIdOfTxPduInfoType AuthenticExternalIdOfTxPduInfo;
  SecOC_AuthenticPduDataContainerAuthenticPduLengthOfTxPduInfoType AuthenticPduDataContainerAuthenticPduLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfoType AuthenticPduDataContainerDataToAuthenticateLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfoType AuthenticPduDataContainerFreshnessVerifyValueLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfoType AuthenticPduDataContainerFullAuthenticPduLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticPduDataContainer */
  SecOC_AuthenticatorCacheEndIdxOfTxPduInfoType AuthenticatorCacheEndIdxOfTxPduInfo;  /**< the end index of the 1:n relation pointing to SecOC_AuthenticatorCache */
  SecOC_AuthenticatorCacheLengthOfTxPduInfoType AuthenticatorCacheLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_AuthenticatorCache */
  SecOC_AuthenticatorCacheStartIdxOfTxPduInfoType AuthenticatorCacheStartIdxOfTxPduInfo;  /**< the start index of the 1:n relation pointing to SecOC_AuthenticatorCache */
  SecOC_BuildAttemptsOfTxPduInfoType BuildAttemptsOfTxPduInfo;
  SecOC_DataIdFirstByteOfTxPduInfoType DataIdFirstByteOfTxPduInfo;
  SecOC_DataIdSecondByteOfTxPduInfoType DataIdSecondByteOfTxPduInfo;
  SecOC_ExternalFreshnessIdOfTxPduInfoType ExternalFreshnessIdOfTxPduInfo;
  SecOC_LowerLayerPduTypeOfTxPduInfoType LowerLayerPduTypeOfTxPduInfo;
  SecOC_PduProcessingOfTxPduInfoType PduProcessingOfTxPduInfo;
  SecOC_PduTypeOfTxPduInfoType PduTypeOfTxPduInfo;
  SecOC_ProvideTruncTxFreshnessOfTxPduInfoType ProvideTruncTxFreshnessOfTxPduInfo;
  SecOC_SecuredExternalIdOfTxPduInfoType SecuredExternalIdOfTxPduInfo;
  SecOC_SecuredPduDataContainerAuthInfoDataLengthOfTxPduInfoType SecuredPduDataContainerAuthInfoDataLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerAuthenticPduLengthOfTxPduInfoType SecuredPduDataContainerAuthenticPduLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerSecuredPduLengthOfTxPduInfoType SecuredPduDataContainerSecuredPduLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfoType SecuredPduDataContainerTruncatedAuthenticatorLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_SecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfoType SecuredPduDataContainerTruncatedFreshnessValueLengthOfTxPduInfo;  /**< the number of relations pointing to SecOC_SecuredPduDataContainer */
  SecOC_TruncAuthStartBitInByteOfTxPduInfoType TruncAuthStartBitInByteOfTxPduInfo;
  SecOC_TruncFreshnessValueFirstByteShiftOfTxPduInfoType TruncFreshnessValueFirstByteShiftOfTxPduInfo;
  SecOC_TruncFreshnessValueSecondByteShiftOfTxPduInfoType TruncFreshnessValueSecondByteShiftOfTxPduInfo;
  SecOC_truncatedAuthenticationLengthOfTxPduInfoType truncatedAuthenticationLengthOfTxPduInfo;
  SecOC_truncatedFreshnessValueLengthOfTxPduInfoType truncatedFreshnessValueLengthOfTxPduInfo;
} SecOC_TxPduInfoType;

/**   \brief  type used in SecOC_TxSecuredPduInfo */
/*! \spec weak type invariant () { 
 * (self.TxPduInfoIdxOfTxSecuredPduInfo < SecOC_GetSizeOfTxPduInfo())
 * } */
typedef struct sSecOC_TxSecuredPduInfoType
{
  SecOC_TxPduInfoIdxOfTxSecuredPduInfoType TxPduInfoIdxOfTxSecuredPduInfo;  /**< the index of the 1:1 relation pointing to SecOC_TxPduInfo */
  SecOC_TxSecuredPduTypeOfTxSecuredPduInfoType TxSecuredPduTypeOfTxSecuredPduInfo;
} SecOC_TxSecuredPduInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCSymbolicStructTypes  SecOC Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to SecOC_AuthenticatorCache */
typedef struct SecOC_AuthenticatorCacheStructSTag
{
  SecOC_AuthenticatorCacheType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType PaddingByte_bed3de0c[126];
  SecOC_AuthenticatorCacheType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticatorCache[11];
  SecOC_AuthenticatorCacheType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticatorCache[6];
  SecOC_AuthenticatorCacheType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticatorCache[6];
} SecOC_AuthenticatorCacheStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_NumberOfMessagesToOverride */
typedef struct SecOC_NumberOfMessagesToOverrideStructSTag
{
  SecOC_NumberOfMessagesToOverrideType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  SecOC_NumberOfMessagesToOverrideType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  SecOC_NumberOfMessagesToOverrideType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  SecOC_NumberOfMessagesToOverrideType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  SecOC_NumberOfMessagesToOverrideType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  SecOC_NumberOfMessagesToOverrideType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  SecOC_NumberOfMessagesToOverrideType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  SecOC_NumberOfMessagesToOverrideType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  SecOC_NumberOfMessagesToOverrideType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  SecOC_NumberOfMessagesToOverrideType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  SecOC_NumberOfMessagesToOverrideType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  SecOC_NumberOfMessagesToOverrideType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  SecOC_NumberOfMessagesToOverrideType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  SecOC_NumberOfMessagesToOverrideType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_NumberOfMessagesToOverrideStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxAuthenticPduSizeOffset */
typedef struct SecOC_RxAuthenticPduSizeOffsetStructSTag
{
  SecOC_RxAuthenticPduSizeOffsetType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  SecOC_RxAuthenticPduSizeOffsetType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  SecOC_RxAuthenticPduSizeOffsetType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  SecOC_RxAuthenticPduSizeOffsetType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  SecOC_RxAuthenticPduSizeOffsetType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  SecOC_RxAuthenticPduSizeOffsetType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  SecOC_RxAuthenticPduSizeOffsetType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  SecOC_RxAuthenticPduSizeOffsetType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  SecOC_RxAuthenticPduSizeOffsetType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  SecOC_RxAuthenticPduSizeOffsetType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  SecOC_RxAuthenticPduSizeOffsetType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  SecOC_RxAuthenticPduSizeOffsetType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  SecOC_RxAuthenticPduSizeOffsetType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  SecOC_RxAuthenticPduSizeOffsetType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_RxAuthenticPduSizeOffsetStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxBuildAttemptsCounter */
typedef struct SecOC_RxBuildAttemptsCounterStructSTag
{
  SecOC_RxBuildAttemptsCounterType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  SecOC_RxBuildAttemptsCounterType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  SecOC_RxBuildAttemptsCounterType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  SecOC_RxBuildAttemptsCounterType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  SecOC_RxBuildAttemptsCounterType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  SecOC_RxBuildAttemptsCounterType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  SecOC_RxBuildAttemptsCounterType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  SecOC_RxBuildAttemptsCounterType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  SecOC_RxBuildAttemptsCounterType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  SecOC_RxBuildAttemptsCounterType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  SecOC_RxBuildAttemptsCounterType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  SecOC_RxBuildAttemptsCounterType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  SecOC_RxBuildAttemptsCounterType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  SecOC_RxBuildAttemptsCounterType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_RxBuildAttemptsCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxPduState */
typedef struct SecOC_RxPduStateStructSTag
{
  SecOC_RxPduStateType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  SecOC_RxPduStateType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  SecOC_RxPduStateType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  SecOC_RxPduStateType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  SecOC_RxPduStateType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  SecOC_RxPduStateType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  SecOC_RxPduStateType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  SecOC_RxPduStateType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  SecOC_RxPduStateType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  SecOC_RxPduStateType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  SecOC_RxPduStateType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  SecOC_RxPduStateType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  SecOC_RxPduStateType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  SecOC_RxPduStateType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_RxPduStateStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_RxTpWrittenBytesCounter */
typedef struct SecOC_RxTpWrittenBytesCounterStructSTag
{
  SecOC_RxTpWrittenBytesCounterType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  SecOC_RxTpWrittenBytesCounterType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  SecOC_RxTpWrittenBytesCounterType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  SecOC_RxTpWrittenBytesCounterType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  SecOC_RxTpWrittenBytesCounterType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  SecOC_RxTpWrittenBytesCounterType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  SecOC_RxTpWrittenBytesCounterType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  SecOC_RxTpWrittenBytesCounterType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  SecOC_RxTpWrittenBytesCounterType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  SecOC_RxTpWrittenBytesCounterType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  SecOC_RxTpWrittenBytesCounterType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  SecOC_RxTpWrittenBytesCounterType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  SecOC_RxTpWrittenBytesCounterType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  SecOC_RxTpWrittenBytesCounterType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_RxTpWrittenBytesCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_SendDefaultAuthentication */
typedef struct SecOC_SendDefaultAuthenticationStructSTag
{
  SecOC_SendDefaultAuthenticationType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx;
  SecOC_SendDefaultAuthenticationType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx;
  SecOC_SendDefaultAuthenticationType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx;
} SecOC_SendDefaultAuthenticationStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_TransmitRequest */
typedef struct SecOC_TransmitRequestStructSTag
{
  SecOC_TransmitRequestType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx;
  SecOC_TransmitRequestType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx;
  SecOC_TransmitRequestType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx;
} SecOC_TransmitRequestStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_TxAuthenticPduSizeOffset */
typedef struct SecOC_TxAuthenticPduSizeOffsetStructSTag
{
  SecOC_TxAuthenticPduSizeOffsetType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx;
  SecOC_TxAuthenticPduSizeOffsetType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx;
  SecOC_TxAuthenticPduSizeOffsetType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx;
} SecOC_TxAuthenticPduSizeOffsetStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_TxBuildAttemptsCounter */
typedef struct SecOC_TxBuildAttemptsCounterStructSTag
{
  SecOC_TxBuildAttemptsCounterType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx;
  SecOC_TxBuildAttemptsCounterType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx;
  SecOC_TxBuildAttemptsCounterType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx;
} SecOC_TxBuildAttemptsCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_TxPduState */
typedef struct SecOC_TxPduStateStructSTag
{
  SecOC_TxPduStateType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx;
  SecOC_TxPduStateType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx;
  SecOC_TxPduStateType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx;
} SecOC_TxPduStateStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_TxResultLength */
typedef struct SecOC_TxResultLengthStructSTag
{
  SecOC_TxResultLengthType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx;
  SecOC_TxResultLengthType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx;
  SecOC_TxResultLengthType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx;
} SecOC_TxResultLengthStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_TxTpWrittenBytesCounter */
typedef struct SecOC_TxTpWrittenBytesCounterStructSTag
{
  SecOC_TxTpWrittenBytesCounterType HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx;
  SecOC_TxTpWrittenBytesCounterType HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx;
  SecOC_TxTpWrittenBytesCounterType IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx;
} SecOC_TxTpWrittenBytesCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_VerifyAttemptsCounter */
typedef struct SecOC_VerifyAttemptsCounterStructSTag
{
  SecOC_VerifyAttemptsCounterType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  SecOC_VerifyAttemptsCounterType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  SecOC_VerifyAttemptsCounterType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  SecOC_VerifyAttemptsCounterType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  SecOC_VerifyAttemptsCounterType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  SecOC_VerifyAttemptsCounterType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  SecOC_VerifyAttemptsCounterType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  SecOC_VerifyAttemptsCounterType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  SecOC_VerifyAttemptsCounterType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  SecOC_VerifyAttemptsCounterType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  SecOC_VerifyAttemptsCounterType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  SecOC_VerifyAttemptsCounterType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  SecOC_VerifyAttemptsCounterType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  SecOC_VerifyAttemptsCounterType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_VerifyAttemptsCounterStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_VerifyOverrideStatus */
typedef struct SecOC_VerifyOverrideStatusStructSTag
{
  SecOC_VerifyOverrideStatusType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  SecOC_VerifyOverrideStatusType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  SecOC_VerifyOverrideStatusType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  SecOC_VerifyOverrideStatusType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  SecOC_VerifyOverrideStatusType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  SecOC_VerifyOverrideStatusType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  SecOC_VerifyOverrideStatusType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  SecOC_VerifyOverrideStatusType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  SecOC_VerifyOverrideStatusType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  SecOC_VerifyOverrideStatusType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  SecOC_VerifyOverrideStatusType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  SecOC_VerifyOverrideStatusType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  SecOC_VerifyOverrideStatusType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  SecOC_VerifyOverrideStatusType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_VerifyOverrideStatusStructSType;

/**   \brief  type to be used as symbolic data element access to SecOC_VerifyResult */
typedef struct SecOC_VerifyResultStructSTag
{
  Csm_VerifyResultType ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx;
  Csm_VerifyResultType ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx;
  Csm_VerifyResultType AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx;
  Csm_VerifyResultType AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx;
  Csm_VerifyResultType BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx;
  Csm_VerifyResultType BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx;
  Csm_VerifyResultType ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx;
  Csm_VerifyResultType GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx;
  Csm_VerifyResultType IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx;
  Csm_VerifyResultType R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx;
  Csm_VerifyResultType TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx;
  Csm_VerifyResultType TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx;
  Csm_VerifyResultType T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx;
  Csm_VerifyResultType T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx;
} SecOC_VerifyResultStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCUnionIndexAndSymbolTypes  SecOC Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access SecOC_AuthenticatorCache in an index and symbol based style. */
typedef union SecOC_AuthenticatorCacheUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_AuthenticatorCacheType raw[138];
  SecOC_AuthenticatorCacheStructSType str;
} SecOC_AuthenticatorCacheUType;

/**   \brief  type to access SecOC_NumberOfMessagesToOverride in an index and symbol based style. */
typedef union SecOC_NumberOfMessagesToOverrideUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_NumberOfMessagesToOverrideType raw[14];
  SecOC_NumberOfMessagesToOverrideStructSType str;
} SecOC_NumberOfMessagesToOverrideUType;

/**   \brief  type to access SecOC_RxAuthenticPduSizeOffset in an index and symbol based style. */
typedef union SecOC_RxAuthenticPduSizeOffsetUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxAuthenticPduSizeOffsetType raw[14];
  SecOC_RxAuthenticPduSizeOffsetStructSType str;
} SecOC_RxAuthenticPduSizeOffsetUType;

/**   \brief  type to access SecOC_RxBuildAttemptsCounter in an index and symbol based style. */
typedef union SecOC_RxBuildAttemptsCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxBuildAttemptsCounterType raw[14];
  SecOC_RxBuildAttemptsCounterStructSType str;
} SecOC_RxBuildAttemptsCounterUType;

/**   \brief  type to access SecOC_RxPduState in an index and symbol based style. */
typedef union SecOC_RxPduStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxPduStateType raw[14];
  SecOC_RxPduStateStructSType str;
} SecOC_RxPduStateUType;

/**   \brief  type to access SecOC_RxTpWrittenBytesCounter in an index and symbol based style. */
typedef union SecOC_RxTpWrittenBytesCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_RxTpWrittenBytesCounterType raw[14];
  SecOC_RxTpWrittenBytesCounterStructSType str;
} SecOC_RxTpWrittenBytesCounterUType;

/**   \brief  type to access SecOC_SendDefaultAuthentication in an index and symbol based style. */
typedef union SecOC_SendDefaultAuthenticationUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_SendDefaultAuthenticationType raw[3];
  SecOC_SendDefaultAuthenticationStructSType str;
} SecOC_SendDefaultAuthenticationUType;

/**   \brief  type to access SecOC_TransmitRequest in an index and symbol based style. */
typedef union SecOC_TransmitRequestUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_TransmitRequestType raw[3];
  SecOC_TransmitRequestStructSType str;
} SecOC_TransmitRequestUType;

/**   \brief  type to access SecOC_TxAuthenticPduSizeOffset in an index and symbol based style. */
typedef union SecOC_TxAuthenticPduSizeOffsetUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_TxAuthenticPduSizeOffsetType raw[3];
  SecOC_TxAuthenticPduSizeOffsetStructSType str;
} SecOC_TxAuthenticPduSizeOffsetUType;

/**   \brief  type to access SecOC_TxBuildAttemptsCounter in an index and symbol based style. */
typedef union SecOC_TxBuildAttemptsCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_TxBuildAttemptsCounterType raw[3];
  SecOC_TxBuildAttemptsCounterStructSType str;
} SecOC_TxBuildAttemptsCounterUType;

/**   \brief  type to access SecOC_TxPduState in an index and symbol based style. */
typedef union SecOC_TxPduStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_TxPduStateType raw[3];
  SecOC_TxPduStateStructSType str;
} SecOC_TxPduStateUType;

/**   \brief  type to access SecOC_TxResultLength in an index and symbol based style. */
typedef union SecOC_TxResultLengthUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_TxResultLengthType raw[3];
  SecOC_TxResultLengthStructSType str;
} SecOC_TxResultLengthUType;

/**   \brief  type to access SecOC_TxTpWrittenBytesCounter in an index and symbol based style. */
typedef union SecOC_TxTpWrittenBytesCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_TxTpWrittenBytesCounterType raw[3];
  SecOC_TxTpWrittenBytesCounterStructSType str;
} SecOC_TxTpWrittenBytesCounterUType;

/**   \brief  type to access SecOC_VerifyAttemptsCounter in an index and symbol based style. */
typedef union SecOC_VerifyAttemptsCounterUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_VerifyAttemptsCounterType raw[14];
  SecOC_VerifyAttemptsCounterStructSType str;
} SecOC_VerifyAttemptsCounterUType;

/**   \brief  type to access SecOC_VerifyOverrideStatus in an index and symbol based style. */
typedef union SecOC_VerifyOverrideStatusUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  SecOC_VerifyOverrideStatusType raw[14];
  SecOC_VerifyOverrideStatusStructSType str;
} SecOC_VerifyOverrideStatusUType;

/**   \brief  type to access SecOC_VerifyResult in an index and symbol based style. */
typedef union SecOC_VerifyResultUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Csm_VerifyResultType raw[14];
  SecOC_VerifyResultStructSType str;
} SecOC_VerifyResultUType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCRootPointerTypes  SecOC Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to SecOC_AuthenticPduDataContainer */
typedef P2VAR(SecOC_AuthenticPduDataContainerType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_AuthenticPduDataContainerPtrType;

/**   \brief  type used to point to SecOC_AuthenticatorCache */
typedef P2VAR(SecOC_AuthenticatorCacheType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_AuthenticatorCachePtrType;

/**   \brief  type used to point to SecOC_DevModeEnabled */
typedef P2VAR(SecOC_DevModeEnabledType, TYPEDEF, SECOC_VAR_ZERO_INIT) SecOC_DevModeEnabledPtrType;

/**   \brief  type used to point to SecOC_Initialized */
typedef P2VAR(SecOC_InitializedType, TYPEDEF, SECOC_VAR_ZERO_INIT) SecOC_InitializedPtrType;

/**   \brief  type used to point to SecOC_NumberOfMessagesToOverride */
typedef P2VAR(SecOC_NumberOfMessagesToOverrideType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_NumberOfMessagesToOverridePtrType;

/**   \brief  type used to point to SecOC_RxAuthenticPduSizeOffset */
typedef P2VAR(SecOC_RxAuthenticPduSizeOffsetType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_RxAuthenticPduSizeOffsetPtrType;

/**   \brief  type used to point to SecOC_RxBuildAttemptsCounter */
typedef P2VAR(SecOC_RxBuildAttemptsCounterType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_RxBuildAttemptsCounterPtrType;

/**   \brief  type used to point to SecOC_RxPduInfo */
typedef P2CONST(SecOC_RxPduInfoType, TYPEDEF, SECOC_CONST) SecOC_RxPduInfoPtrType;

/**   \brief  type used to point to SecOC_RxPduState */
typedef P2VAR(volatile SecOC_RxPduStateType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_RxPduStatePtrType;

/**   \brief  type used to point to SecOC_RxSecuredPduInfo */
typedef P2CONST(SecOC_RxSecuredPduInfoType, TYPEDEF, SECOC_CONST) SecOC_RxSecuredPduInfoPtrType;

/**   \brief  type used to point to SecOC_RxTpWrittenBytesCounter */
typedef P2VAR(SecOC_RxTpWrittenBytesCounterType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_RxTpWrittenBytesCounterPtrType;

/**   \brief  type used to point to SecOC_SecuredPduDataContainer */
typedef P2VAR(SecOC_SecuredPduDataContainerType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_SecuredPduDataContainerPtrType;

/**   \brief  type used to point to SecOC_SendDefaultAuthentication */
typedef P2VAR(volatile SecOC_SendDefaultAuthenticationType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_SendDefaultAuthenticationPtrType;

/**   \brief  type used to point to SecOC_TransmitRequest */
typedef P2VAR(SecOC_TransmitRequestType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_TransmitRequestPtrType;

/**   \brief  type used to point to SecOC_TxAuthenticPduInfo */
typedef P2CONST(SecOC_TxAuthenticPduInfoType, TYPEDEF, SECOC_CONST) SecOC_TxAuthenticPduInfoPtrType;

/**   \brief  type used to point to SecOC_TxAuthenticPduSizeOffset */
typedef P2VAR(SecOC_TxAuthenticPduSizeOffsetType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_TxAuthenticPduSizeOffsetPtrType;

/**   \brief  type used to point to SecOC_TxBuildAttemptsCounter */
typedef P2VAR(SecOC_TxBuildAttemptsCounterType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_TxBuildAttemptsCounterPtrType;

/**   \brief  type used to point to SecOC_TxPduInfo */
typedef P2CONST(SecOC_TxPduInfoType, TYPEDEF, SECOC_CONST) SecOC_TxPduInfoPtrType;

/**   \brief  type used to point to SecOC_TxPduState */
typedef P2VAR(volatile SecOC_TxPduStateType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_TxPduStatePtrType;

/**   \brief  type used to point to SecOC_TxResultLength */
typedef P2VAR(SecOC_TxResultLengthType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_TxResultLengthPtrType;

/**   \brief  type used to point to SecOC_TxSecuredPduInfo */
typedef P2CONST(SecOC_TxSecuredPduInfoType, TYPEDEF, SECOC_CONST) SecOC_TxSecuredPduInfoPtrType;

/**   \brief  type used to point to SecOC_TxTpWrittenBytesCounter */
typedef P2VAR(SecOC_TxTpWrittenBytesCounterType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_TxTpWrittenBytesCounterPtrType;

/**   \brief  type used to point to SecOC_VerificationStatusCallout */
typedef P2CONST(SecOCVerificationStatusCalloutType, TYPEDEF, SECOC_CONST) SecOC_VerificationStatusCalloutPtrType;

/**   \brief  type used to point to SecOC_VerificationStatusCalloutWithSecuredPdu */
typedef P2CONST(SecOCVerificationStatusCalloutWithSecuredPduType, TYPEDEF, SECOC_CONST) SecOC_VerificationStatusCalloutWithSecuredPduPtrType;

/**   \brief  type used to point to SecOC_VerifyAttemptsCounter */
typedef P2VAR(SecOC_VerifyAttemptsCounterType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_VerifyAttemptsCounterPtrType;

/**   \brief  type used to point to SecOC_VerifyOverrideStatus */
typedef P2VAR(SecOC_VerifyOverrideStatusType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_VerifyOverrideStatusPtrType;

/**   \brief  type used to point to SecOC_VerifyResult */
typedef P2VAR(Csm_VerifyResultType, TYPEDEF, SECOC_VAR_NOINIT) SecOC_VerifyResultPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SecOCPCRootValueTypes  SecOC Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in SecOC_PCConfig */
typedef struct sSecOC_PCConfigType
{
  uint8 SecOC_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} SecOC_PCConfigType;

typedef SecOC_PCConfigType SecOC_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  SecOC_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_RxPduInfo
  \details
  Element                                                   Description
  AuthenticPduDataContainerAuthenticPduEndIdx               the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerAuthenticPduStartIdx             the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateEndIdx         the end index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateStartIdx       the start index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueEndIdx       the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueStartIdx     the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticationLayerId                                 
  DataId                                                
  SecuredPduDataContainerAuthenticPduEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduEndIdx                   the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduStartIdx                 the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorEndIdx       the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorStartIdx     the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueEndIdx      the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueStartIdx    the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredRxPduVerfication                               
  WaitForCallback                                       
  AuthDataFreshness                                     
  AuthDataFreshnessLen                                  
  AuthDataFreshnessStartBytePosition                    
  AuthenticExternalId                                   
  AuthenticPduDataContainerAuthenticPduLength               the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateLength         the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueLength       the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticatorCacheEndIdx                                  the end index of the 1:n relation pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheLength                                  the number of relations pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheStartIdx                                the start index of the 1:n relation pointing to SecOC_AuthenticatorCache
  BuildAttempts                                         
  DataIdFirstByte                                       
  DataIdSecondByte                                      
  ExternalFreshnessId                                   
  NumberOfMessagesToOverrideIdx                             the index of the 1:1 relation pointing to SecOC_NumberOfMessagesToOverride
  PduProcessing                                         
  PduType                                               
  SecuredPduDataContainerAuthenticPduLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduLength                   the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTpSecuredPduLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorLength       the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueLength      the number of relations pointing to SecOC_SecuredPduDataContainer
  TruncAuthStartBitInByte                               
  TruncFreshnessValueFirstByteShift                     
  TruncFreshnessValueSecondByteShift                    
  VerificationStatusPropagationMode                     
  VerificationStatusWithSecuredPduPropagationMode       
  VerifyAttempts                                        
  VerifyOverrideStatusIdx                                   the index of the 1:1 relation pointing to SecOC_VerifyOverrideStatus
  VerifyResultIdx                                           the index of the 1:1 relation pointing to SecOC_VerifyResult
  truncatedAuthenticationLength                         
  truncatedFreshnessValueLength                         
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOC_RxPduInfoType, SECOC_CONST) SecOC_RxPduInfo[14];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxSecuredPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_RxSecuredPduInfo
  \details
  Element                              Description
  SecuredPduDataContainerEndIdx        the end index of the 1:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerStartIdx      the start index of the 1:n relation pointing to SecOC_SecuredPduDataContainer
  MessageLinkLen                   
  MessageLinkPos                   
  MessageLinkerStartByteInCryptoPdu
  MessageType                      
  MessagesLinkCryptoPduSrcBitOffset
  MinimumPduLength                 
  PduFixLength                     
  RxPduInfoIdx                         the index of the 1:1 relation pointing to SecOC_RxPduInfo
  SecuredPduDataContainerLength        the number of relations pointing to SecOC_SecuredPduDataContainer
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOC_RxSecuredPduInfoType, SECOC_CONST) SecOC_RxSecuredPduInfo[14];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxAuthenticPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_TxAuthenticPduInfo
  \details
  Element             Description
  MinimumPduLength
  TxPduInfoIdx        the index of the 1:1 relation pointing to SecOC_TxPduInfo
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOC_TxAuthenticPduInfoType, SECOC_CONST) SecOC_TxAuthenticPduInfo[3];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_TxPduInfo
  \details
  Element                                                   Description
  AuthenticPduDataContainerAuthenticPduEndIdx               the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerAuthenticPduStartIdx             the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateEndIdx         the end index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateStartIdx       the start index of the 1:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueEndIdx       the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueStartIdx     the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFullAuthenticPduEndIdx           the end index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFullAuthenticPduStartIdx         the start index of the 0:n relation pointing to SecOC_AuthenticPduDataContainer
  AuthenticationLayerId                                 
  SecuredPduDataContainerAuthInfoDataEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthInfoDataStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduEndIdx                 the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduStartIdx               the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduEndIdx                   the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduStartIdx                 the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorEndIdx       the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorStartIdx     the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueEndIdx      the end index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueStartIdx    the start index of the 0:n relation pointing to SecOC_SecuredPduDataContainer
  ConfirmationNeeded                                    
  SPduTxConfirmationNeeded                              
  WaitForCallback                                       
  AuthenticExternalId                                   
  AuthenticPduDataContainerAuthenticPduLength               the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerDataToAuthenticateLength         the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFreshnessVerifyValueLength       the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticPduDataContainerFullAuthenticPduLength           the number of relations pointing to SecOC_AuthenticPduDataContainer
  AuthenticatorCacheEndIdx                                  the end index of the 1:n relation pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheLength                                  the number of relations pointing to SecOC_AuthenticatorCache
  AuthenticatorCacheStartIdx                                the start index of the 1:n relation pointing to SecOC_AuthenticatorCache
  BuildAttempts                                         
  DataIdFirstByte                                       
  DataIdSecondByte                                      
  ExternalFreshnessId                                   
  LowerLayerPduType                                     
  PduProcessing                                         
  PduType                                               
  ProvideTruncTxFreshness                               
  SecuredExternalId                                     
  SecuredPduDataContainerAuthInfoDataLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerAuthenticPduLength                 the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerSecuredPduLength                   the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedAuthenticatorLength       the number of relations pointing to SecOC_SecuredPduDataContainer
  SecuredPduDataContainerTruncatedFreshnessValueLength      the number of relations pointing to SecOC_SecuredPduDataContainer
  TruncAuthStartBitInByte                               
  TruncFreshnessValueFirstByteShift                     
  TruncFreshnessValueSecondByteShift                    
  truncatedAuthenticationLength                         
  truncatedFreshnessValueLength                         
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOC_TxPduInfoType, SECOC_CONST) SecOC_TxPduInfo[3];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxSecuredPduInfo
**********************************************************************************************************************/
/** 
  \var    SecOC_TxSecuredPduInfo
  \details
  Element             Description
  TxPduInfoIdx        the index of the 1:1 relation pointing to SecOC_TxPduInfo
  TxSecuredPduType
*/ 
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOC_TxSecuredPduInfoType, SECOC_CONST) SecOC_TxSecuredPduInfo[3];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerificationStatusCallout
**********************************************************************************************************************/
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOCVerificationStatusCalloutType, SECOC_CONST) SecOC_VerificationStatusCallout[1];
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerificationStatusCalloutWithSecuredPdu
**********************************************************************************************************************/
#define SECOC_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(SecOCVerificationStatusCalloutWithSecuredPduType, SECOC_CONST) SecOC_VerificationStatusCalloutWithSecuredPdu[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SECOC_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_AuthenticPduDataContainer
**********************************************************************************************************************/
#define SECOC_START_SEC_CRYPTO_DRV_ALIGNED_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_AuthenticPduDataContainerType, SECOC_VAR_NOINIT) SecOC_AuthenticPduDataContainer[566];
#define SECOC_STOP_SEC_CRYPTO_DRV_ALIGNED_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_AuthenticatorCache
**********************************************************************************************************************/
#define SECOC_START_SEC_CRYPTO_DRV_ALIGNED_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_AuthenticatorCacheUType, SECOC_VAR_NOINIT) SecOC_AuthenticatorCache;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_CRYPTO_DRV_ALIGNED_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_DevModeEnabled
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_DevModeEnabledType, SECOC_VAR_ZERO_INIT) SecOC_DevModeEnabled;
#define SECOC_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_Initialized
**********************************************************************************************************************/
/** 
  \var    SecOC_Initialized
  \brief  Initialization state of SecOC. TRUE, if SecOC_Init() has been called, else FALSE.
*/ 
#define SECOC_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_InitializedType, SECOC_VAR_ZERO_INIT) SecOC_Initialized;
#define SECOC_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_NumberOfMessagesToOverride
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_NumberOfMessagesToOverrideUType, SECOC_VAR_NOINIT) SecOC_NumberOfMessagesToOverride;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxAuthenticPduSizeOffset
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_RxAuthenticPduSizeOffsetUType, SECOC_VAR_NOINIT) SecOC_RxAuthenticPduSizeOffset;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxBuildAttemptsCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_RxBuildAttemptsCounterUType, SECOC_VAR_NOINIT) SecOC_RxBuildAttemptsCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxPduState
**********************************************************************************************************************/
/** 
  \var    SecOC_RxPduState
  \brief  The state variable is volatile because it is used to ensure data consistency
*/ 
#define SECOC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(SecOC_RxPduStateUType, SECOC_VAR_NOINIT) SecOC_RxPduState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_RxTpWrittenBytesCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_RxTpWrittenBytesCounterUType, SECOC_VAR_NOINIT) SecOC_RxTpWrittenBytesCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_SecuredPduDataContainer
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_SecuredPduDataContainerType, SECOC_VAR_NOINIT) SecOC_SecuredPduDataContainer[512];
#define SECOC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_SendDefaultAuthentication
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(SecOC_SendDefaultAuthenticationUType, SECOC_VAR_NOINIT) SecOC_SendDefaultAuthentication;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TransmitRequest
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_TransmitRequestUType, SECOC_VAR_NOINIT) SecOC_TransmitRequest;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxAuthenticPduSizeOffset
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_TxAuthenticPduSizeOffsetUType, SECOC_VAR_NOINIT) SecOC_TxAuthenticPduSizeOffset;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxBuildAttemptsCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_TxBuildAttemptsCounterUType, SECOC_VAR_NOINIT) SecOC_TxBuildAttemptsCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxPduState
**********************************************************************************************************************/
/** 
  \var    SecOC_TxPduState
  \brief  The state variable is volatile because it is used to ensure data consistency
*/ 
#define SECOC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(SecOC_TxPduStateUType, SECOC_VAR_NOINIT) SecOC_TxPduState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxResultLength
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_TxResultLengthUType, SECOC_VAR_NOINIT) SecOC_TxResultLength;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_TxTpWrittenBytesCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_TxTpWrittenBytesCounterUType, SECOC_VAR_NOINIT) SecOC_TxTpWrittenBytesCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyAttemptsCounter
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_VerifyAttemptsCounterUType, SECOC_VAR_NOINIT) SecOC_VerifyAttemptsCounter;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyOverrideStatus
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_VerifyOverrideStatusUType, SECOC_VAR_NOINIT) SecOC_VerifyOverrideStatus;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SecOC_VerifyResult
**********************************************************************************************************************/
#define SECOC_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(SecOC_VerifyResultUType, SECOC_VAR_NOINIT) SecOC_VerifyResult;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define SECOC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* SECOC_LCFG_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Lcfg.h
**********************************************************************************************************************/


