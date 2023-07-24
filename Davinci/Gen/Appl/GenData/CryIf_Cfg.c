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
 *            Module: CryIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_Cfg.c
 *   Generation Time: 2020-11-05 12:20:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define CRYIF_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CryIf_Cfg.h"
#include "CryIf.h"
#include "Crypto_30_vHsm.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYIF_LOCAL)
# define CRYIF_LOCAL static
#endif

#if !defined (CRYIF_LOCAL_INLINE)
# define CRYIF_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CryIf_Channel
**********************************************************************************************************************/
/** 
  \var    CryIf_Channel
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfChannel.
  \details
  Element               Description
  DriverObjectRef       Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfDriverObjectRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
  Id                    Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfChannelId.
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                                  CryptoFunctionsIdx  Id        Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hal               ,                 0u, 0u },  /* [/ActiveEcuC/CryIf/CryIfChannel_CMAC, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue:CsmChannelRef, /ActiveEcuC/Csm/CsmQueues/CsmQueue_AES128:CsmChannelRef] */
  { /*     1 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyM              ,                 0u, 1u },  /* [/ActiveEcuC/CryIf/CryIfChannel_KeySetValid, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_KeySetValid:CsmChannelRef] */
  { /*     2 */ CryptoConf_CryptoDriverObject_Crypto_30_Hsm_Hal_AesCmacGenerate,                 0u, 2u },  /* [/ActiveEcuC/CryIf/CryIfChannel_SecOC_Generate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Generate:CsmChannelRef] */
  { /*     3 */ CryptoConf_CryptoDriverObject_Crypto_30_Hsm_Hal_AesCmacVerify  ,                 0u, 3u }   /* [/ActiveEcuC/CryIf/CryIfChannel_SecOC_Verify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Verify:CsmChannelRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_CryptoFunctions
**********************************************************************************************************************/
/** 
  \var    CryIf_CryptoFunctions
  \details
  Element                          Description
  SupportsKeyElementCopyPartial
  CancelJob                    
  CertificateParse             
  CertificateVerify            
  KeyCopy                      
  KeyDerive                    
  KeyElementCopy               
  KeyElementCopyPartial        
  KeyElementGet                
  KeyElementIdsGet             
  KeyElementSet                
  KeyExchangeCalcPubVal        
  KeyExchangeCalcSecret        
  KeyGenerate                  
  KeyValidSet                  
  ProcessJob                   
  RandomSeed                   
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SupportsKeyElementCopyPartial  CancelJob                 CertificateParse                 CertificateVerify                 KeyCopy                 KeyDerive                 KeyElementCopy                 KeyElementCopyPartial                 KeyElementGet                 KeyElementIdsGet                 KeyElementSet                 KeyExchangeCalcPubVal                 KeyExchangeCalcSecret                 KeyGenerate                 KeyValidSet                 ProcessJob                 RandomSeed                       Referable Keys */
  { /*     0 */                          TRUE, Crypto_30_vHsm_CancelJob, Crypto_30_vHsm_CertificateParse, Crypto_30_vHsm_CertificateVerify, Crypto_30_vHsm_KeyCopy, Crypto_30_vHsm_KeyDerive, Crypto_30_vHsm_KeyElementCopy, Crypto_30_vHsm_KeyElementCopyPartial, Crypto_30_vHsm_KeyElementGet, Crypto_30_vHsm_KeyElementIdsGet, Crypto_30_vHsm_KeyElementSet, Crypto_30_vHsm_KeyExchangeCalcPubVal, Crypto_30_vHsm_KeyExchangeCalcSecret, Crypto_30_vHsm_KeyGenerate, Crypto_30_vHsm_KeyValidSet, Crypto_30_vHsm_ProcessJob, Crypto_30_vHsm_RandomSeed }   /* [/ActiveEcuC/Crypto] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_Key
**********************************************************************************************************************/
/** 
  \var    CryIf_Key
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfKey.
  \details
  Element               Description
  Ref                   Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfKey/CryIfKeyRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Ref                                                         CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_CryIfKey_vHsm_Aggregated_hsm_hal_cmac,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey:CsmKeyRef] */
  { /*     1 */ CryptoConf_CryptoKey_vHsm_SecureBoot_Group_APPL           ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SecureBootAppKey, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SecureBootAppKey:CsmKeyRef] */
  { /*     2 */ CryptoConf_CryptoKey_CryIfKey_Aes128                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Aes128, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Aes128:CsmKeyRef] */
  { /*     3 */ CryptoConf_CryptoKey_vHsm_Hardware                        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Flash, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Flash:CsmKeyRef] */
  { /*     4 */ CryptoConf_CryptoKey_CryIfKey_Random                      ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_RandomSeed, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_RandomSeed:CsmKeyRef] */
  { /*     5 */ CryptoConf_CryptoKey_vHsm_SecureBoot_Segment_APPL_0       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SecureBootAPP_A, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SecureBootAPP_A:CsmKeyRef] */
  { /*     6 */ CryptoConf_CryptoKey_vHsm_SecureBoot_Segment_APPL_1       ,                 0u }   /* [/ActiveEcuC/CryIf/CryIfKey_SecureBootAPP_B, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SecureBootAPP_B:CsmKeyRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





