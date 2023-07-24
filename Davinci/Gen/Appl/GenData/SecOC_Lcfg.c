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
 *              File: SecOC_Lcfg.c
 *   Generation Time: 2022-03-02 17:10:51
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#define V_IL_ASRSECOC_LCFG_SOURCE
/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA  S 3673 EOF */ /* MD_MSR_Rule8.13 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

# include "SecOC.h"
# include "SecOC_Lcfg.h"
# include "PduR_SecOC.h"
# include "SecOC_Cbk.h"
# include "SecOC_Types.h"
# include "SchM_SecOC.h"


/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
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
CONST(SecOC_RxPduInfoType, SECOC_CONST) SecOC_RxPduInfo[14] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AuthenticPduDataContainerAuthenticPduEndIdx                      AuthenticPduDataContainerAuthenticPduStartIdx                      AuthenticPduDataContainerDataToAuthenticateEndIdx  AuthenticPduDataContainerDataToAuthenticateStartIdx  AuthenticPduDataContainerFreshnessVerifyValueEndIdx  AuthenticPduDataContainerFreshnessVerifyValueStartIdx  AuthenticationLayerId                          DataId  SecuredPduDataContainerAuthenticPduEndIdx                      SecuredPduDataContainerAuthenticPduStartIdx                      SecuredPduDataContainerSecuredPduEndIdx  SecuredPduDataContainerSecuredPduStartIdx  SecuredPduDataContainerTpSecuredPduEndIdx  SecuredPduDataContainerTpSecuredPduStartIdx  SecuredPduDataContainerTruncatedAuthenticatorEndIdx  SecuredPduDataContainerTruncatedAuthenticatorStartIdx  SecuredPduDataContainerTruncatedFreshnessValueEndIdx  SecuredPduDataContainerTruncatedFreshnessValueStartIdx  SecuredRxPduVerfication  WaitForCallback  AuthDataFreshness                            AuthDataFreshnessLen  AuthDataFreshnessStartBytePosition  AuthenticExternalId                      AuthenticPduDataContainerAuthenticPduLength  AuthenticPduDataContainerDataToAuthenticateLength  AuthenticPduDataContainerFreshnessVerifyValueLength  AuthenticatorCacheEndIdx  AuthenticatorCacheLength  AuthenticatorCacheStartIdx  BuildAttempts  DataIdFirstByte  DataIdSecondByte  ExternalFreshnessId  NumberOfMessagesToOverrideIdx  PduProcessing                            PduType                         SecuredPduDataContainerAuthenticPduLength  SecuredPduDataContainerSecuredPduLength  SecuredPduDataContainerTpSecuredPduLength  SecuredPduDataContainerTruncatedAuthenticatorLength  SecuredPduDataContainerTruncatedFreshnessValueLength  TruncAuthStartBitInByte  TruncFreshnessValueFirstByteShift  TruncFreshnessValueSecondByteShift  VerificationStatusPropagationMode                        VerificationStatusWithSecuredPduPropagationMode                        VerifyAttempts  VerifyOverrideStatusIdx  VerifyResultIdx  truncatedAuthenticationLength  truncatedFreshnessValueLength        Referable Keys */
  { /*     0 */                                                             10u,                                                                2u,                                               18u,                                                  0u,                                                 18u,                                                   10u, CsmConf_CsmJob_CsmJob_CMAC_Verify_ABM1       ,   849u,                                                            8u,                                                              0u,                                     16u,                                        0u,                                       16u,                                          0u,                                                 16u,                                                   10u,                                                  10u,                                                     8u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_d83550c6,                                          8u,                                               18u,                                                  8u,                       6u,                       6u,                         0u,            3u,           0x03u,            0x51u,                  0u,                            0u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      0u,              0u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  { /*     1 */                                                             78u,                                                               22u,                                               86u,                                                 20u,                                                 86u,                                                   78u, CsmConf_CsmJob_CsmJob_CMAC_Verify_ACC_FD2    ,   683u,                                                           72u,                                                             16u,                                     80u,                                       16u,                                       80u,                                         16u,                                                 80u,                                                   74u,                                                  74u,                                                    72u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_f58e3bbb,                                         56u,                                               66u,                                                  8u,                      14u,                       6u,                         8u,            3u,           0x02u,            0xABu,                  1u,                            1u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                       56u,                                     64u,                                       64u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      1u,              1u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  { /*     2 */                                                            146u,                                                               90u,                                              154u,                                                 88u,                                                154u,                                                  146u, CsmConf_CsmJob_CsmJob_CMAC_Verify_AEB_FD2    ,   551u,                                                          136u,                                                             80u,                                    144u,                                       80u,                                      144u,                                         80u,                                                144u,                                                  138u,                                                 138u,                                                   136u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_9f2d3fb1,                                         56u,                                               66u,                                                  8u,                      22u,                       6u,                        16u,            3u,           0x02u,            0x27u,                  2u,                            2u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                       56u,                                     64u,                                       64u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      2u,              2u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  { /*     3 */                                                            166u,                                                              158u,                                              174u,                                                156u,                                                174u,                                                  166u, CsmConf_CsmJob_CsmJob_CMAC_Verify_AMP2       ,   995u,                                                          152u,                                                            144u,                                    160u,                                      144u,                                      160u,                                        144u,                                                160u,                                                  154u,                                                 154u,                                                   152u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_b145d381,                                          8u,                                               18u,                                                  8u,                      30u,                       6u,                        24u,            3u,           0x03u,            0xE3u,                  3u,                            3u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      3u,              3u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  { /*     4 */                                                            186u,                                                              178u,                                              194u,                                                176u,                                                194u,                                                  186u, CsmConf_CsmJob_CsmJob_CMAC_Verify_BCM1       ,   793u,                                                          168u,                                                            160u,                                    176u,                                      160u,                                      176u,                                        160u,                                                176u,                                                  170u,                                                 170u,                                                   168u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_f3e4daaa,                                          8u,                                               18u,                                                  8u,                      38u,                       6u,                        32u,            3u,           0x03u,            0x19u,                  4u,                            4u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      4u,              4u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  { /*     5 */                                                            206u,                                                              198u,                                              214u,                                                196u,                                                214u,                                                  206u, CsmConf_CsmJob_CsmJob_CMAC_Verify_BCM3       ,   837u,                                                          184u,                                                            176u,                                    192u,                                      176u,                                      192u,                                        176u,                                                192u,                                                  186u,                                                 186u,                                                   184u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_22dd6f7f,                                          8u,                                               18u,                                                  8u,                      46u,                       6u,                        40u,            3u,           0x03u,            0x45u,                  5u,                            5u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      5u,              5u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  { /*     6 */                                                            274u,                                                              218u,                                              282u,                                                216u,                                                282u,                                                  274u, CsmConf_CsmJob_CsmJob_CMAC_Verify_ESP_FD2    ,   311u,                                                          248u,                                                            192u,                                    256u,                                      192u,                                      256u,                                        192u,                                                256u,                                                  250u,                                                 250u,                                                   248u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_fb298bdb,                                         56u,                                               66u,                                                  8u,                      54u,                       6u,                        48u,            3u,           0x01u,            0x37u,                  6u,                            6u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                       56u,                                     64u,                                       64u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      6u,              6u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  { /*     7 */ SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO, SECOC_NO_AUTHENTICPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO,                                              291u,                                                284u,                                                291u,                                                  286u, CsmConf_CsmJob_CsmJob_CMAC_Verify_GW_SYNC_REQ,  1121u, SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUENDIDXOFRXPDUINFO, SECOC_NO_SECUREDPDUDATACONTAINERAUTHENTICPDUSTARTIDXOFRXPDUINFO,                                    272u,                                      256u,                                      272u,                                        256u,                                                272u,                                                  261u,                                                 261u,                                                   256u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_f6108157,                                          0u,                                                7u,                                                  5u,                      67u,                      11u,                        56u,           10u,           0x04u,            0x61u,                  7u,                            7u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        0u,                                     16u,                                       16u,                                                 11u,                                                   5u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,            10u,                      7u,              7u,                           88u,                           40u },  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  { /*     8 */                                                            350u,                                                              294u,                                              358u,                                                292u,                                                358u,                                                  350u, CsmConf_CsmJob_CsmJob_CMAC_Verify_IFC_FD2    ,   573u,                                                          328u,                                                            272u,                                    336u,                                      272u,                                      336u,                                        272u,                                                336u,                                                  330u,                                                 330u,                                                   328u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_39a1bd74,                                         56u,                                               66u,                                                  8u,                      74u,                       6u,                        68u,            3u,           0x02u,            0x3Du,                  8u,                            8u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                       56u,                                     64u,                                       64u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                      8u,              8u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  { /*     9 */                                                            370u,                                                              362u,                                              378u,                                                360u,                                                378u,                                                  370u, CsmConf_CsmJob_CsmJob_CMAC_Verify_R_PBox1    ,   412u,                                                          344u,                                                            336u,                                    352u,                                      336u,                                      352u,                                        336u,                                                352u,                                                  346u,                                                 346u,                                                   344u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_4bb0d0d6,                                          8u,                                               18u,                                                  8u,                      82u,                       6u,                        76u,            1u,           0x01u,            0x9Cu,                  9u,                            9u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             1u,                      9u,              9u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  { /*    10 */                                                            390u,                                                              382u,                                              398u,                                                380u,                                                398u,                                                  390u, CsmConf_CsmJob_CsmJob_CMAC_Verify_TPMS1      ,   833u,                                                          360u,                                                            352u,                                    368u,                                      352u,                                      368u,                                        352u,                                                368u,                                                  362u,                                                 362u,                                                   360u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_94956a34,                                          8u,                                               18u,                                                  8u,                      90u,                       6u,                        84u,            3u,           0x03u,            0x41u,                 10u,                           10u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                     10u,             10u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  { /*    11 */                                                            410u,                                                              402u,                                              418u,                                                400u,                                                418u,                                                  410u, CsmConf_CsmJob_CsmJob_CMAC_Verify_TPMS2      ,   917u,                                                          376u,                                                            368u,                                    384u,                                      368u,                                      384u,                                        368u,                                                384u,                                                  378u,                                                 378u,                                                   376u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_fd18d504,                                          8u,                                               18u,                                                  8u,                      98u,                       6u,                        92u,            3u,           0x03u,            0x95u,                 11u,                           11u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                     11u,             11u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  { /*    12 */                                                            430u,                                                              422u,                                              438u,                                                420u,                                                438u,                                                  430u, CsmConf_CsmJob_CsmJob_CMAC_Verify_T_Box_FD1  ,    51u,                                                          392u,                                                            384u,                                    400u,                                      384u,                                      400u,                                        384u,                                                400u,                                                  394u,                                                 394u,                                                   392u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_098f2493,                                          8u,                                               18u,                                                  8u,                     106u,                       6u,                       100u,            3u,           0x00u,            0x33u,                 12u,                           12u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                     12u,             12u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  { /*    13 */                                                            450u,                                                              442u,                                              458u,                                                440u,                                                458u,                                                  450u, CsmConf_CsmJob_CsmJob_CMAC_Verify_T_Box_FD3  ,  1001u,                                                          408u,                                                            400u,                                    416u,                                      400u,                                      416u,                                        400u,                                                416u,                                                  410u,                                                 410u,                                                   408u,                    TRUE,            TRUE, SECOC_DONT_USE_AUTHDATAFRESHNESSOFRXPDUINFO,                   0u,                                 0u, PduRConf_PduRSrcPdu_PduRSrcPdu_118b1947,                                          8u,                                               18u,                                                  8u,                     114u,                       6u,                       108u,            3u,           0x03u,            0xE9u,                 13u,                           13u, SECOC_DEFERRED_PDUPROCESSINGOFRXPDUINFO, SECOC_IFPDU_PDUTYPEOFRXPDUINFO,                                        8u,                                     16u,                                       16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u, SECOC_BOTH_VERIFICATIONSTATUSPROPAGATIONMODEOFRXPDUINFO, SECOC_BOTH_VERIFICATIONSTATUSWITHSECUREDPDUPROPAGATIONMODEOFRXPDUINFO,             3u,                     13u,             13u,                           48u,                           16u }   /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */
};
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
CONST(SecOC_RxSecuredPduInfoType, SECOC_CONST) SecOC_RxSecuredPduInfo[14] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SecuredPduDataContainerEndIdx  SecuredPduDataContainerStartIdx  MessageLinkLen  MessageLinkPos  MessageLinkerStartByteInCryptoPdu  MessageType                                 MessagesLinkCryptoPduSrcBitOffset  MinimumPduLength  PduFixLength  RxPduInfoIdx  SecuredPduDataContainerLength        Referable Keys */
  { /*     0 */                           16u,                              0u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           0u,                           16u },  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer] */
  { /*     1 */                           80u,                             16u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           1u,                           64u },  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer] */
  { /*     2 */                          144u,                             80u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           2u,                           64u },  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer] */
  { /*     3 */                          160u,                            144u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           3u,                           16u },  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer] */
  { /*     4 */                          176u,                            160u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           4u,                           16u },  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer] */
  { /*     5 */                          192u,                            176u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           5u,                           16u },  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer] */
  { /*     6 */                          256u,                            192u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           6u,                           64u },  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer] */
  { /*     7 */                          272u,                            256u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,              16u,          16u,           7u,                           16u },  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx/SecOCRxSecuredPduLayer] */
  { /*     8 */                          336u,                            272u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           8u,                           64u },  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer] */
  { /*     9 */                          352u,                            336u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,           9u,                           16u },  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer] */
  { /*    10 */                          368u,                            352u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,          10u,                           16u },  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer] */
  { /*    11 */                          384u,                            368u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,          11u,                           16u },  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer] */
  { /*    12 */                          400u,                            384u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,          12u,                           16u },  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer] */
  { /*    13 */                          416u,                            400u,             0u,             0u,                                0u, SECOC_NORMAL_MESSAGETYPEOFRXSECUREDPDUINFO,                                0u,               8u,           8u,          13u,                           16u }   /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer] */
};
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
CONST(SecOC_TxAuthenticPduInfoType, SECOC_CONST) SecOC_TxAuthenticPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MinimumPduLength  TxPduInfoIdx        Referable Keys */
  { /*     0 */               0u,           0u },  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx] */
  { /*     1 */               0u,           1u },  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx] */
  { /*     2 */               0u,           2u }   /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx] */
};
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
CONST(SecOC_TxPduInfoType, SECOC_CONST) SecOC_TxPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AuthenticPduDataContainerAuthenticPduEndIdx  AuthenticPduDataContainerAuthenticPduStartIdx  AuthenticPduDataContainerDataToAuthenticateEndIdx  AuthenticPduDataContainerDataToAuthenticateStartIdx  AuthenticPduDataContainerFreshnessVerifyValueEndIdx  AuthenticPduDataContainerFreshnessVerifyValueStartIdx  AuthenticPduDataContainerFullAuthenticPduEndIdx  AuthenticPduDataContainerFullAuthenticPduStartIdx  AuthenticationLayerId                        SecuredPduDataContainerAuthInfoDataEndIdx  SecuredPduDataContainerAuthInfoDataStartIdx  SecuredPduDataContainerAuthenticPduEndIdx  SecuredPduDataContainerAuthenticPduStartIdx  SecuredPduDataContainerSecuredPduEndIdx  SecuredPduDataContainerSecuredPduStartIdx  SecuredPduDataContainerTruncatedAuthenticatorEndIdx  SecuredPduDataContainerTruncatedAuthenticatorStartIdx  SecuredPduDataContainerTruncatedFreshnessValueEndIdx  SecuredPduDataContainerTruncatedFreshnessValueStartIdx  ConfirmationNeeded  SPduTxConfirmationNeeded  WaitForCallback  AuthenticExternalId                                            AuthenticPduDataContainerAuthenticPduLength  AuthenticPduDataContainerDataToAuthenticateLength  AuthenticPduDataContainerFreshnessVerifyValueLength  AuthenticPduDataContainerFullAuthenticPduLength  AuthenticatorCacheEndIdx  AuthenticatorCacheLength  AuthenticatorCacheStartIdx  BuildAttempts  DataIdFirstByte  DataIdSecondByte  ExternalFreshnessId  LowerLayerPduType                         PduProcessing                            PduType                         ProvideTruncTxFreshness                           SecuredExternalId                        SecuredPduDataContainerAuthInfoDataLength  SecuredPduDataContainerAuthenticPduLength  SecuredPduDataContainerSecuredPduLength  SecuredPduDataContainerTruncatedAuthenticatorLength  SecuredPduDataContainerTruncatedFreshnessValueLength  TruncAuthStartBitInByte  TruncFreshnessValueFirstByteShift  TruncFreshnessValueSecondByteShift  truncatedAuthenticationLength  truncatedFreshnessValueLength        Referable Keys */
  { /*     0 */                                        470u,                                          462u,                                              478u,                                                460u,                                                478u,                                                  470u,                                            470u,                                              462u, CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT15  ,                                      432u,                                        424u,                                      424u,                                        416u,                                    432u,                                      416u,                                                432u,                                                  426u,                                                 426u,                                                   424u,               TRUE,                     TRUE,            TRUE,   PduRConf_PduRDestPdu_HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx,                                          8u,                                               18u,                                                  8u,                                              8u,                     122u,                       6u,                       116u,            3u,           0x01u,            0xEEu,                  0u, SECOC_IFPDU_LOWERLAYERPDUTYPEOFTXPDUINFO, SECOC_DEFERRED_PDUPROCESSINGOFTXPDUINFO, SECOC_IFPDU_PDUTYPEOFTXPDUINFO, SECOC_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO, PduRConf_PduRSrcPdu_PduRSrcPdu_bee506b7,                                        8u,                                        8u,                                     16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  { /*     1 */                                        538u,                                          482u,                                              546u,                                                480u,                                                546u,                                                  538u,                                            538u,                                              482u, CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT_FD1,                                      496u,                                        488u,                                      488u,                                        432u,                                    496u,                                      432u,                                                496u,                                                  490u,                                                 490u,                                                   488u,               TRUE,                     TRUE,            TRUE, PduRConf_PduRDestPdu_HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx,                                         56u,                                               66u,                                                  8u,                                             56u,                     130u,                       6u,                       124u,            3u,           0x02u,            0xC3u,                  1u, SECOC_IFPDU_LOWERLAYERPDUTYPEOFTXPDUINFO, SECOC_DEFERRED_PDUPROCESSINGOFTXPDUINFO, SECOC_IFPDU_PDUTYPEOFTXPDUINFO, SECOC_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO, PduRConf_PduRSrcPdu_PduRSrcPdu_373da34d,                                        8u,                                       56u,                                     64u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u,                           48u,                           16u },  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  { /*     2 */                                        558u,                                          550u,                                              566u,                                                548u,                                                566u,                                                  558u,                                            558u,                                              550u, CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT_IP2,                                      512u,                                        504u,                                      504u,                                        496u,                                    512u,                                      496u,                                                512u,                                                  506u,                                                 506u,                                                   504u,               TRUE,                     TRUE,            TRUE,     PduRConf_PduRDestPdu_IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx,                                          8u,                                               18u,                                                  8u,                                              8u,                     138u,                       6u,                       132u,            1u,           0x02u,            0x7Fu,                  2u, SECOC_IFPDU_LOWERLAYERPDUTYPEOFTXPDUINFO, SECOC_DEFERRED_PDUPROCESSINGOFTXPDUINFO, SECOC_IFPDU_PDUTYPEOFTXPDUINFO, SECOC_PROVIDE_PROVIDETRUNCTXFRESHNESSOFTXPDUINFO, PduRConf_PduRSrcPdu_PduRSrcPdu_bb663806,                                        8u,                                        8u,                                     16u,                                                  6u,                                                   2u,                      0u,                                0u,                                 0u,                           48u,                           16u }   /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */
};
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
CONST(SecOC_TxSecuredPduInfoType, SECOC_CONST) SecOC_TxSecuredPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInfoIdx  TxSecuredPduType                                       Referable Keys */
  { /*     0 */           0u, SECOC_NORMAL_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO },  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer] */
  { /*     1 */           1u, SECOC_NORMAL_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO },  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer] */
  { /*     2 */           2u, SECOC_NORMAL_TXSECUREDPDUTYPEOFTXSECUREDPDUINFO }   /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer] */
};
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
CONST(SecOCVerificationStatusCalloutType, SECOC_CONST) SecOC_VerificationStatusCallout[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     VerificationStatusCallout      */
  /*     0 */ FvM_VerificationStatusCallout 
};
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
CONST(SecOCVerificationStatusCalloutWithSecuredPduType, SECOC_CONST) SecOC_VerificationStatusCalloutWithSecuredPdu[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     VerificationStatusCalloutWithSecuredPdu             */
  /*     0 */ SecOc_Verification_Status_Callout_With_Secured_Pdu 
};
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
VAR(SecOC_AuthenticPduDataContainerType, SECOC_VAR_NOINIT) SecOC_AuthenticPduDataContainer[566];  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxSecOCDataFirstByteID] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxSecOCDataSecondByteID] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullAuthenticPdu] */
  /*     9 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullAuthenticPdu] */
  /*    10 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate] */
  /*    17 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxDataToAuthenticate] */
  /*    18 */  /* [PaddingByte_bed3de0c] */
  /*    19 */  /* [PaddingByte_bed3de0c] */
  /*    20 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxSecOCDataFirstByteID] */
  /*    21 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxSecOCDataSecondByteID] */
  /*    22 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullAuthenticPdu] */
  /*    77 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullAuthenticPdu] */
  /*    78 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate] */
  /*    85 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxDataToAuthenticate] */
  /*    86 */  /* [PaddingByte_bed3de0c] */
  /*    87 */  /* [PaddingByte_bed3de0c] */
  /*    88 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxSecOCDataFirstByteID] */
  /*    89 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxSecOCDataSecondByteID] */
  /*    90 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullAuthenticPdu] */
  /*   145 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullAuthenticPdu] */
  /*   146 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate] */
  /*   153 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxDataToAuthenticate] */
  /*   154 */  /* [PaddingByte_bed3de0c] */
  /*   155 */  /* [PaddingByte_bed3de0c] */
  /*   156 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxSecOCDataFirstByteID] */
  /*   157 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxSecOCDataSecondByteID] */
  /*   158 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullAuthenticPdu] */
  /*   165 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullAuthenticPdu] */
  /*   166 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate] */
  /*   173 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxDataToAuthenticate] */
  /*   174 */  /* [PaddingByte_bed3de0c] */
  /*   175 */  /* [PaddingByte_bed3de0c] */
  /*   176 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxSecOCDataFirstByteID] */
  /*   177 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxSecOCDataSecondByteID] */
  /*   178 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullAuthenticPdu] */
  /*   185 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullAuthenticPdu] */
  /*   186 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate] */
  /*   193 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxDataToAuthenticate] */
  /*   194 */  /* [PaddingByte_bed3de0c] */
  /*   195 */  /* [PaddingByte_bed3de0c] */
  /* Index        Referable Keys */
  /*   196 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxSecOCDataFirstByteID] */
  /*   197 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxSecOCDataSecondByteID] */
  /*   198 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullAuthenticPdu] */
  /*   205 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullAuthenticPdu] */
  /*   206 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate] */
  /*   213 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxDataToAuthenticate] */
  /*   214 */  /* [PaddingByte_bed3de0c] */
  /*   215 */  /* [PaddingByte_bed3de0c] */
  /*   216 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxSecOCDataFirstByteID] */
  /*   217 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxSecOCDataSecondByteID] */
  /*   218 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullAuthenticPdu] */
  /*   273 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullAuthenticPdu] */
  /*   274 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate] */
  /*   281 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxDataToAuthenticate] */
  /*   282 */  /* [PaddingByte_bed3de0c] */
  /*   283 */  /* [PaddingByte_bed3de0c] */
  /*   284 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxDataToAuthenticate, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxSecOCDataFirstByteID] */
  /*   285 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxDataToAuthenticate, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxSecOCDataSecondByteID] */
  /*   286 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxDataToAuthenticate] */
  /*   290 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxDataToAuthenticate] */
  /*   291 */  /* [PaddingByte_bed3de0c] */
  /*   292 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxSecOCDataFirstByteID] */
  /*   293 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxSecOCDataSecondByteID] */
  /*   294 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullAuthenticPdu] */
  /*   349 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullAuthenticPdu] */
  /*   350 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate] */
  /*   357 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxDataToAuthenticate] */
  /*   358 */  /* [PaddingByte_bed3de0c] */
  /*   359 */  /* [PaddingByte_bed3de0c] */
  /*   360 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxSecOCDataFirstByteID] */
  /*   361 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxSecOCDataSecondByteID] */
  /*   362 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullAuthenticPdu] */
  /*   369 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullAuthenticPdu] */
  /*   370 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate] */
  /*   377 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxDataToAuthenticate] */
  /*   378 */  /* [PaddingByte_bed3de0c] */
  /*   379 */  /* [PaddingByte_bed3de0c] */
  /*   380 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxSecOCDataFirstByteID] */
  /*   381 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxSecOCDataSecondByteID] */
  /*   382 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullAuthenticPdu] */
  /*   389 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullAuthenticPdu] */
  /* Index        Referable Keys */
  /*   390 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate] */
  /*   397 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxDataToAuthenticate] */
  /*   398 */  /* [PaddingByte_bed3de0c] */
  /*   399 */  /* [PaddingByte_bed3de0c] */
  /*   400 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxSecOCDataFirstByteID] */
  /*   401 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxSecOCDataSecondByteID] */
  /*   402 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullAuthenticPdu] */
  /*   409 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullAuthenticPdu] */
  /*   410 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate] */
  /*   417 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxDataToAuthenticate] */
  /*   418 */  /* [PaddingByte_bed3de0c] */
  /*   419 */  /* [PaddingByte_bed3de0c] */
  /*   420 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxSecOCDataFirstByteID] */
  /*   421 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxSecOCDataSecondByteID] */
  /*   422 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullAuthenticPdu] */
  /*   429 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullAuthenticPdu] */
  /*   430 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate] */
  /*   437 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxDataToAuthenticate] */
  /*   438 */  /* [PaddingByte_bed3de0c] */
  /*   439 */  /* [PaddingByte_bed3de0c] */
  /*   440 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxSecOCDataFirstByteID] */
  /*   441 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxSecOCDataSecondByteID] */
  /*   442 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullAuthenticPdu] */
  /*   449 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullAuthenticPdu] */
  /*   450 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate] */
  /*   457 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFreshnessVerifyValue, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxDataToAuthenticate] */
  /*   458 */  /* [PaddingByte_bed3de0c] */
  /*   459 */  /* [PaddingByte_bed3de0c] */
  /*   460 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxSecOCDataFirstByteID] */
  /*   461 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxSecOCDataSecondByteID] */
  /*   462 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullAuthenticPdu] */
  /*   469 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullAuthenticPdu] */
  /*   470 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate] */
  /*   477 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxDataToAuthenticate] */
  /*   478 */  /* [PaddingByte_bed3de0c] */
  /*   479 */  /* [PaddingByte_bed3de0c] */
  /*   480 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxSecOCDataFirstByteID] */
  /*   481 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxSecOCDataSecondByteID] */
  /*   482 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullAuthenticPdu] */
  /*   537 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullAuthenticPdu] */
  /* Index        Referable Keys */
  /*   538 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate] */
  /*   545 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxDataToAuthenticate] */
  /*   546 */  /* [PaddingByte_bed3de0c] */
  /*   547 */  /* [PaddingByte_bed3de0c] */
  /*   548 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxSecOCDataFirstByteID] */
  /*   549 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxSecOCDataSecondByteID] */
  /*   550 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullAuthenticPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullAuthenticPdu] */
  /*   557 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullAuthenticPdu] */
  /*   558 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate] */
  /*   ... */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate] */
  /*   565 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFreshnessVerifyValue, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxDataToAuthenticate] */

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
VAR(SecOC_AuthenticatorCacheUType, SECOC_VAR_NOINIT) SecOC_AuthenticatorCache;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticatorCache] */
  /*     5 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticatorCache] */
  /*     6 */  /* [PaddingByte_bed3de0c] */
  /*     7 */  /* [PaddingByte_bed3de0c] */
  /*     8 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticatorCache] */
  /*    13 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticatorCache] */
  /*    14 */  /* [PaddingByte_bed3de0c] */
  /*    15 */  /* [PaddingByte_bed3de0c] */
  /*    16 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticatorCache] */
  /*    21 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticatorCache] */
  /*    22 */  /* [PaddingByte_bed3de0c] */
  /*    23 */  /* [PaddingByte_bed3de0c] */
  /*    24 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticatorCache] */
  /*    29 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticatorCache] */
  /*    30 */  /* [PaddingByte_bed3de0c] */
  /*    31 */  /* [PaddingByte_bed3de0c] */
  /*    32 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticatorCache] */
  /*    37 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticatorCache] */
  /*    38 */  /* [PaddingByte_bed3de0c] */
  /*    39 */  /* [PaddingByte_bed3de0c] */
  /*    40 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticatorCache] */
  /*    45 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticatorCache] */
  /*    46 */  /* [PaddingByte_bed3de0c] */
  /*    47 */  /* [PaddingByte_bed3de0c] */
  /*    48 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticatorCache] */
  /*    53 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticatorCache] */
  /*    54 */  /* [PaddingByte_bed3de0c] */
  /*    55 */  /* [PaddingByte_bed3de0c] */
  /*    56 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticatorCache] */
  /*    66 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticatorCache] */
  /*    67 */  /* [PaddingByte_bed3de0c] */
  /*    68 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticatorCache] */
  /*    73 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticatorCache] */
  /*    74 */  /* [PaddingByte_bed3de0c] */
  /*    75 */  /* [PaddingByte_bed3de0c] */
  /*    76 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticatorCache] */
  /*    81 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticatorCache] */
  /*    82 */  /* [PaddingByte_bed3de0c] */
  /*    83 */  /* [PaddingByte_bed3de0c] */
  /*    84 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticatorCache] */
  /*    89 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticatorCache] */
  /* Index        Referable Keys */
  /*    90 */  /* [PaddingByte_bed3de0c] */
  /*    91 */  /* [PaddingByte_bed3de0c] */
  /*    92 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticatorCache] */
  /*    97 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticatorCache] */
  /*    98 */  /* [PaddingByte_bed3de0c] */
  /*    99 */  /* [PaddingByte_bed3de0c] */
  /*   100 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticatorCache] */
  /*   105 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticatorCache] */
  /*   106 */  /* [PaddingByte_bed3de0c] */
  /*   107 */  /* [PaddingByte_bed3de0c] */
  /*   108 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticatorCache] */
  /*   113 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticatorCache] */
  /*   114 */  /* [PaddingByte_bed3de0c] */
  /*   115 */  /* [PaddingByte_bed3de0c] */
  /*   116 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticatorCache] */
  /*   121 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticatorCache] */
  /*   122 */  /* [PaddingByte_bed3de0c] */
  /*   123 */  /* [PaddingByte_bed3de0c] */
  /*   124 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticatorCache] */
  /*   129 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticatorCache] */
  /*   130 */  /* [PaddingByte_bed3de0c] */
  /*   131 */  /* [PaddingByte_bed3de0c] */
  /*   132 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticatorCache] */
  /*   ... */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticatorCache] */
  /*   137 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticatorCache] */

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
VAR(SecOC_DevModeEnabledType, SECOC_VAR_ZERO_INIT) SecOC_DevModeEnabled = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(SecOC_InitializedType, SECOC_VAR_ZERO_INIT) SecOC_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(SecOC_NumberOfMessagesToOverrideUType, SECOC_VAR_NOINIT) SecOC_NumberOfMessagesToOverride;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

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
VAR(SecOC_RxAuthenticPduSizeOffsetUType, SECOC_VAR_NOINIT) SecOC_RxAuthenticPduSizeOffset;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

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
VAR(SecOC_RxBuildAttemptsCounterUType, SECOC_VAR_NOINIT) SecOC_RxBuildAttemptsCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

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
volatile VAR(SecOC_RxPduStateUType, SECOC_VAR_NOINIT) SecOC_RxPduState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

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
VAR(SecOC_RxTpWrittenBytesCounterUType, SECOC_VAR_NOINIT) SecOC_RxTpWrittenBytesCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

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
VAR(SecOC_SecuredPduDataContainerType, SECOC_VAR_NOINIT) SecOC_SecuredPduDataContainer[512];  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*     7 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ABM1_oB30_for_SC_CAN_V3_2_d004cc2e_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*     8 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticInfo, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*     9 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticInfo, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*    10 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticInfo, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticInfo, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*    15 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxFullSecuredPdu, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxAuthenticInfo, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_RxTpSecuredPdu] */
  /*    16 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*    71 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_oB30_for_SC_CAN_V3_2_c4f72cb9_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*    72 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticInfo, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*    73 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticInfo, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*    74 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticInfo, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticInfo, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*    79 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxFullSecuredPdu, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxAuthenticInfo, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_RxTpSecuredPdu] */
  /*    80 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   135 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_oB30_for_SC_CAN_V3_2_9fb3d7e9_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   136 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticInfo, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   137 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticInfo, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   138 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticInfo, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticInfo, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   143 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxFullSecuredPdu, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAuthenticInfo, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxAEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_RxTpSecuredPdu] */
  /*   144 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   151 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/AMP2_oB30_for_SC_CAN_V3_2_908de48a_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   152 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticInfo, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   153 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticInfo, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   154 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticInfo, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticInfo, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   159 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxFullSecuredPdu, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAuthenticInfo, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxAMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_RxTpSecuredPdu] */
  /*   160 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   167 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/BCM1_oB30_for_SC_CAN_V3_2_64cc1f5a_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   168 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   169 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   170 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   175 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxBCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_RxTpSecuredPdu] */
  /*   176 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   183 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/BCM3_oB30_for_SC_CAN_V3_2_4a9cd6da_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   184 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   185 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   186 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   191 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxFullSecuredPdu, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxAuthenticInfo, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxBCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_RxTpSecuredPdu] */
  /*   192 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /*   247 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_oB30_for_SC_CAN_V3_2_c451c518_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /* Index        Referable Keys */
  /*   248 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticInfo, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /*   249 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticInfo, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /*   250 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticInfo, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticInfo, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /*   255 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxFullSecuredPdu, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxAuthenticInfo, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_RxTpSecuredPdu] */
  /*   256 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFullSecuredPdu, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticInfo, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFullSecuredPdu, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticInfo, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTpSecuredPdu] */
  /*   260 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFullSecuredPdu, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticInfo, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTpSecuredPdu] */
  /*   261 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFullSecuredPdu, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticInfo, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFullSecuredPdu, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticInfo, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTpSecuredPdu] */
  /*   271 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxFullSecuredPdu, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxAuthenticInfo, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxGW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_RxTpSecuredPdu] */
  /*   272 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   327 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_oB30_for_SC_CAN_V3_2_c695b455_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   328 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticInfo, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   329 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticInfo, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   330 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticInfo, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticInfo, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   335 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxFullSecuredPdu, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxAuthenticInfo, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxIFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_RxTpSecuredPdu] */
  /*   336 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   343 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_oB30_for_SC_CAN_V3_2_3929a458_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   344 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticInfo, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   345 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticInfo, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   346 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticInfo, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticInfo, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   351 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxFullSecuredPdu, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxAuthenticInfo, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxR_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_RxTpSecuredPdu] */
  /*   352 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   359 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/TPMS1_oB30_for_SC_CAN_V3_2_c5efa96f_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   360 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   361 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   362 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   367 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_RxTpSecuredPdu] */
  /*   368 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   375 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/TPMS2_oB30_for_SC_CAN_V3_2_fc97042f_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   376 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   377 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   378 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   383 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxFullSecuredPdu, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxAuthenticInfo, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_RxTpSecuredPdu] */
  /*   384 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /*   391 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_oB30_for_SC_CAN_V3_2_bf5dcd7a_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /*   392 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /*   393 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /*   394 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /*   399 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxT_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_RxTpSecuredPdu] */
  /* Index        Referable Keys */
  /*   400 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   407 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_oB30_for_SC_CAN_V3_2_910d04fa_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   408 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   409 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTruncatedFreshnessValue, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   410 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   415 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx/SecOCRxSecuredPduLayer, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxFullSecuredPdu, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTruncatedAuthenticator, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxAuthenticInfo, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxT_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_RxTpSecuredPdu] */
  /*   416 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   423 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/HUT15_oB30_for_SC_CAN_V3_2_d46de065_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   424 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTruncatedFreshnessValue, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   425 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTruncatedFreshnessValue, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   426 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   431 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxHUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_TxTpSecuredPdu] */
  /*   432 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   487 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_oB30_for_SC_CAN_V3_2_612942c0_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   488 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTruncatedFreshnessValue, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   489 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTruncatedFreshnessValue, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   490 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   495 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxFullSecuredPdu, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxAuthenticInfo, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxHUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_TxTpSecuredPdu] */
  /*   496 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */
  /*   503 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/EcuC/EcucPduCollection/IP2_oB30_for_SC_CAN_V3_2_24e97840_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */
  /*   504 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTruncatedFreshnessValue, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticInfo, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */
  /*   505 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTruncatedFreshnessValue, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticInfo, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */
  /*   506 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticInfo, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */
  /*   ... */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticInfo, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */
  /*   511 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx/SecOCTxSecuredPduLayer, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxFullSecuredPdu, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTruncatedAuthenticator, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxAuthenticInfo, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxIP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_TxTpSecuredPdu] */

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
volatile VAR(SecOC_SendDefaultAuthenticationUType, SECOC_VAR_NOINIT) SecOC_SendDefaultAuthentication;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */

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
VAR(SecOC_TransmitRequestUType, SECOC_VAR_NOINIT) SecOC_TransmitRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */

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
VAR(SecOC_TxAuthenticPduSizeOffsetUType, SECOC_VAR_NOINIT) SecOC_TxAuthenticPduSizeOffset;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */

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
VAR(SecOC_TxBuildAttemptsCounterUType, SECOC_VAR_NOINIT) SecOC_TxBuildAttemptsCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */

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
volatile VAR(SecOC_TxPduStateUType, SECOC_VAR_NOINIT) SecOC_TxPduState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */

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
VAR(SecOC_TxResultLengthUType, SECOC_VAR_NOINIT) SecOC_TxResultLength;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */

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
VAR(SecOC_TxTpWrittenBytesCounterUType, SECOC_VAR_NOINIT) SecOC_TxTpWrittenBytesCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx] */

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
VAR(SecOC_VerifyAttemptsCounterUType, SECOC_VAR_NOINIT) SecOC_VerifyAttemptsCounter;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

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
VAR(SecOC_VerifyOverrideStatusUType, SECOC_VAR_NOINIT) SecOC_VerifyOverrideStatus;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

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
VAR(SecOC_VerifyResultUType, SECOC_VAR_NOINIT) SecOC_VerifyResult;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx] */
  /*     1 */  /* [/ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx] */
  /*     2 */  /* [/ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx] */
  /*     3 */  /* [/ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx] */
  /*     4 */  /* [/ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx] */
  /*     5 */  /* [/ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx] */
  /*     6 */  /* [/ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx] */
  /*     7 */  /* [/ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx] */
  /*     8 */  /* [/ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx] */
  /*     9 */  /* [/ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx] */
  /*    10 */  /* [/ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx] */
  /*    11 */  /* [/ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx] */
  /*    12 */  /* [/ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx] */
  /*    13 */  /* [/ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx] */

#define SECOC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


/* CSM callback functions */
/**********************************************************************************************************************
  CsmJob_CMAC_Generate_Cbk
**********************************************************************************************************************/
/** \internal
  #10 Switch over the JobId to get the related PDU.
   #20 If the passed result is E_OK, set the state machine to the next mainfunction based processing state.
    #20 If the PDU state UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK is reaced, copy the Authenticator to the secured PDU buffer.
   #30 If the passed Reuslt is BUSY, increment the build attempts.
   #40 Otherwise, discard the PDU.
    \endinternal
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) CsmJob_CMAC_Generate_Cbk(P2VAR(Crypto_JobType, AUTOMATIC, AUTOMATIC) job, Csm_ResultType result)
{
  switch(job->jobId)
  {
    case CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT_FD1:  /* HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx */
    {
      SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxAuthenticPduInfo(1);
      SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       if(result == E_OK)
       {
         if(SecOC_GetTxPduState(txPduInfoIdx) == SECOC_UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK_TXPDUSTATE)
         {
            SecOC_GetArrayByteAligned(SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduInfoIdx)), SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo(txPduInfoIdx)), (uint16) SecOC_GettruncatedAuthenticationLengthOfTxPduInfo(txPduInfoIdx), 0u, (uint8) ((8u - SecOC_GetTruncAuthStartBitInByteOfTxPduInfo(txPduInfoIdx)) & 7u), FALSE);     /* SBSW_SECOC_PTR2FUNC_6 */
            SecOC_SetTxPduState(txPduInfoIdx, SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       }
       else if(result == SECOC_E_BUSY)
       {
         SecOC_SetTxPduState(txPduInfoIdx, SECOC_UNAUTHENTICATED_TO_BE_STARTED_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         SecOC_Authenticate_IncrementAndCheckBuildAttempts(txPduInfoIdx);
         SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       }
       else
       {
         if(SecOC_IsDevModeEnabled())
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_DEVMODE_AUTHENTICATION_PATTERN_NEEDED_TXPDUSTATE);        /* SBSW_SECOC_CSL02 */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
         else
         if(SecOC_IsSendDefaultAuthentication(txPduInfoIdx))
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_DEVMODE_AUTHENTICATION_PATTERN_NEEDED_TXPDUSTATE);        /* SBSW_SECOC_CSL02 */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
         else
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_INVALID_SECURED_PDU_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_SetTransmitRequest(txPduInfoIdx, SECOC_IDLE_TRANSMITREQUEST); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
       }
       break;
     }
    case CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT15:  /* HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx */
    {
      SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxAuthenticPduInfo(0);
      SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       if(result == E_OK)
       {
         if(SecOC_GetTxPduState(txPduInfoIdx) == SECOC_UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK_TXPDUSTATE)
         {
            SecOC_GetArrayByteAligned(SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduInfoIdx)), SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo(txPduInfoIdx)), (uint16) SecOC_GettruncatedAuthenticationLengthOfTxPduInfo(txPduInfoIdx), 0u, (uint8) ((8u - SecOC_GetTruncAuthStartBitInByteOfTxPduInfo(txPduInfoIdx)) & 7u), FALSE);     /* SBSW_SECOC_PTR2FUNC_6 */
            SecOC_SetTxPduState(txPduInfoIdx, SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       }
       else if(result == SECOC_E_BUSY)
       {
         SecOC_SetTxPduState(txPduInfoIdx, SECOC_UNAUTHENTICATED_TO_BE_STARTED_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         SecOC_Authenticate_IncrementAndCheckBuildAttempts(txPduInfoIdx);
         SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       }
       else
       {
         if(SecOC_IsDevModeEnabled())
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_DEVMODE_AUTHENTICATION_PATTERN_NEEDED_TXPDUSTATE);        /* SBSW_SECOC_CSL02 */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
         else
         if(SecOC_IsSendDefaultAuthentication(txPduInfoIdx))
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_DEVMODE_AUTHENTICATION_PATTERN_NEEDED_TXPDUSTATE);        /* SBSW_SECOC_CSL02 */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
         else
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_INVALID_SECURED_PDU_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_SetTransmitRequest(txPduInfoIdx, SECOC_IDLE_TRANSMITREQUEST); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
       }
       break;
     }
    case CsmConf_CsmJob_CsmJob_CMAC_Generate_HUT_IP2:  /* IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx */
    {
      SecOC_TxPduInfoIterType txPduInfoIdx = SecOC_GetTxPduInfoIdxOfTxAuthenticPduInfo(2);
      SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       if(result == E_OK)
       {
         if(SecOC_GetTxPduState(txPduInfoIdx) == SECOC_UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK_TXPDUSTATE)
         {
            SecOC_GetArrayByteAligned(SecOC_GetAddrAuthenticatorCache(SecOC_GetAuthenticatorCacheStartIdxOfTxPduInfo(txPduInfoIdx)), SecOC_GetAddrSecuredPduDataContainer(SecOC_GetSecuredPduDataContainerTruncatedAuthenticatorStartIdxOfTxPduInfo(txPduInfoIdx)), (uint16) SecOC_GettruncatedAuthenticationLengthOfTxPduInfo(txPduInfoIdx), 0u, (uint8) ((8u - SecOC_GetTruncAuthStartBitInByteOfTxPduInfo(txPduInfoIdx)) & 7u), FALSE);     /* SBSW_SECOC_PTR2FUNC_6 */
            SecOC_SetTxPduState(txPduInfoIdx, SECOC_UNAUTHENTICATED_FINISHED_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       }
       else if(result == SECOC_E_BUSY)
       {
         SecOC_SetTxPduState(txPduInfoIdx, SECOC_UNAUTHENTICATED_TO_BE_STARTED_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         SecOC_Authenticate_IncrementAndCheckBuildAttempts(txPduInfoIdx);
         SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
       }
       else
       {
         if(SecOC_IsDevModeEnabled())
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_DEVMODE_AUTHENTICATION_PATTERN_NEEDED_TXPDUSTATE);        /* SBSW_SECOC_CSL02 */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
         else
         if(SecOC_IsSendDefaultAuthentication(txPduInfoIdx))
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_DEVMODE_AUTHENTICATION_PATTERN_NEEDED_TXPDUSTATE);        /* SBSW_SECOC_CSL02 */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
         else
         {
           SecOC_SetTxPduState(txPduInfoIdx, SECOC_INVALID_SECURED_PDU_TXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_SetTransmitRequest(txPduInfoIdx, SECOC_IDLE_TRANSMITREQUEST); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE();
         }
       }
       break;
     }
    default:   /* COV_SECOC_MISRA */
      break;
  }
  SECOC_DUMMY_STATEMENT(job);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
/**********************************************************************************************************************
  CsmJob_CMAC_Verify_Cbk
**********************************************************************************************************************/
/** \internal
  #10 Switch over the JobId to get the related PDU.
   #20 If the passed result is E_OK, set the state machine to the next mainfunction based processing state.
    #20 If the PDU state UNAUTHENTICATED_FINISHED_WAIT_FOR_CALLBACK is reaced, copy the Authenticator to the secured PDU buffer.
   #30 If the passed Reuslt is BUSY, increment the build attempts.
   #40 Otherwise, discard the PDU.
    \endinternal
**********************************************************************************************************************/
FUNC(void, SECOC_CODE) CsmJob_CMAC_Verify_Cbk(P2VAR(Crypto_JobType, AUTOMATIC, AUTOMATIC) job, Csm_ResultType result)
{
  switch(job->jobId)
  {
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_ESP_FD2:  /* ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(6);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_BCM3:  /* BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(5);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_T_Box_FD1:  /* T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(12);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_TPMS2:  /* TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(11);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_ABM1:  /* ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(0);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_ACC_FD2:  /* ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(1);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_GW_SYNC_REQ:  /* GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(7);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_BCM1:  /* BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(4);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_IFC_FD2:  /* IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(8);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_AMP2:  /* AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(3);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_TPMS1:  /* TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(10);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_AEB_FD2:  /* AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(2);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_T_Box_FD3:  /* T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(13);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    case CsmConf_CsmJob_CsmJob_CMAC_Verify_R_PBox1:  /* R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx */
    {
       SecOC_RxPduInfoIterType rxPduInfoIdx = SecOC_GetRxPduInfoIdxOfRxSecuredPduInfo(9);
       if(SecOC_GetRxPduState(rxPduInfoIdx) != SECOC_IDLE_RXPDUSTATE)
       {
         if(result == E_OK)
         {
           if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_UNVERIFIED_VERIFICATION_FINISHED_WAIT_FOR_CALLBACK_RXPDUSTATE)
           {
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
         }
         else if(result == SECOC_E_BUSY)
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           SecOC_Verify_IncrementBuildAttempts(rxPduInfoIdx);
         }
         else
         {
           SecOC_SetRxPduState(rxPduInfoIdx, SECOC_IDLE_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
         }
         if(SecOC_GetRxPduState(rxPduInfoIdx) == SECOC_IDLE_RXPDUSTATE) 
         {
           if(SecOC_IsDevModeEnabled())
           {
              SecOC_SetVerifyResult(SecOC_GetVerifyResultIdxOfRxPduInfo(rxPduInfoIdx), CRYPTO_E_VER_NOT_OK);  /* SBSW_SECOC_CSL02 */
              SecOC_SetRxPduState(rxPduInfoIdx, SECOC_UNVERIFIED_VERIFICATION_FINISHED_VERIFICATION_RESULT_READY_RXPDUSTATE); /* SBSW_SECOC_CSL80_GENERATED_HANDLES */
           }
           else
           {
           }
         }
       }
       break;
    }
    default:   /* COV_SECOC_MISRA */
      break;
  }
  SECOC_DUMMY_STATEMENT(job);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/* SBSW_JUSTIFICATION_BEGIN
    
  \ID SBSW_SECOC_CSL80_GENERATED_HANDLES
    \DESCRIPTION Access of Table1, via indirection over Table2 with same index via indirection over Table 3.
    \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib. The source handle for the indirection is generated and therefore valid.

  \ID SBSW_SECOC_CSL_POINTER
    \DESCRIPTION A pointer is passed to a function.
    \COUNTERMEASURE \N The pointer is read with generated macros of the ComStackLib. Therefore they are always valid.

   SBSW_JUSTIFICATION_END */

/**********************************************************************************************************************
  END OF FILE: SecOC_Lcfg.c
**********************************************************************************************************************/


