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
 *            Module: Csm
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.c
 *   Generation Time: 2022-03-02 17:10:51
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define CSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Cfg.h"
#include "CryIf.h"
#include "Rte_Csm.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CSM_LOCAL)
# define CSM_LOCAL static
#endif

#if !defined (CSM_LOCAL_INLINE)
# define CSM_LOCAL_INLINE LOCAL_INLINE
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
  Csm_BswCallbacks
**********************************************************************************************************************/
/** 
  \var    Csm_BswCallbacks
  \details
  Element           Description
  CallbackFunc43
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_BswCallbacksType, CSM_CONST) Csm_BswCallbacks[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CallbackFunc43                  Referable Keys */
  { /*     0 */ CsmJob_CMAC_Generate_Cbk },  /* [/ActiveEcuC/Csm/CsmCallbacks/CsmJob_CMAC_Generate] */
  { /*     1 */ CsmJob_CMAC_Verify_Cbk   },  /* [/ActiveEcuC/Csm/CsmCallbacks/CsmJob_CMAC_Verify] */
  { /*     2 */ CsmJob_KeySetValid_Cbk   }   /* [/ActiveEcuC/Csm/CsmCallbacks/CsmJob_KeySetValid] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Callout
**********************************************************************************************************************/
/** 
  \var    Csm_Callout
  \brief  Contains parameters of /MICROSAR/Csm/CsmCallouts/CsmCallout.
  \details
  Element               Description
  PostJobCalloutFunc    Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPostJobCalloutFunc.
  PreJobCalloutFunc     Contains values of DefinitionRef: /MICROSAR/Csm/CsmCallouts/CsmCallout/CsmPreJobCalloutFunc.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_CalloutType, CSM_CONST) Csm_Callout[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PostJobCalloutFunc          PreJobCalloutFunc                Referable Keys */
  { /*     0 */ CSM_Aes128_Callout_Post   , CSM_Aes128_Callout_Pre    },  /* [/ActiveEcuC/Csm/CsmCallouts/CSM_Aes128_Callout, /ActiveEcuC/Csm/CsmCallouts, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt:CsmJobCalloutRef] */
  { /*     1 */ CSM_SecOcSync_Callout_Post, CSM_SecOcSync_Callout_Pre },  /* [/ActiveEcuC/Csm/CsmCallouts/CSM_SecOcSync_Callout, /ActiveEcuC/Csm/CsmCallouts, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ:CsmJobCalloutRef] */
  { /*     2 */ CSM_SecOc_CsmCallout_Post , CSM_SecOc_CsmCallout_Pre  },  /* [/ActiveEcuC/Csm/CsmCallouts/CSM_SecOc_CsmCallout, /ActiveEcuC/Csm/CsmCallouts, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1:CsmJobCalloutRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3:CsmJobCalloutRef] */
  { /*     3 */ CSM_SetKey_Callout_Post   , CSM_SetKey_Callout_Pre    }   /* [/ActiveEcuC/Csm/CsmCallouts/CSM_SetKey_Callout, /ActiveEcuC/Csm/CsmCallouts, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid:CsmJobCalloutRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_CalloutInfo
**********************************************************************************************************************/
/** 
  \var    Csm_CalloutInfo
  \brief  Reference Table to Callouts and Jobs
  \details
  Element        Description
  CalloutIdx     the index of the 1:1 relation pointing to Csm_Callout
  JobTableIdx    the index of the 1:1 relation pointing to Csm_JobTable
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_CalloutInfoType, CSM_CONST) Csm_CalloutInfo[25] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CalloutIdx  JobTableIdx        Referable Keys */
  { /*     0 */         1u,         17u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ] */
  { /*     1 */         0u,          0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt] */
  { /*     2 */         0u,          1u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt] */
  { /*     3 */         3u,         24u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid] */
  { /*     4 */         2u,          2u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15] */
  { /*     5 */         2u,          3u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1] */
  { /*     6 */         2u,          4u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2] */
  { /*     7 */         2u,          5u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1] */
  { /*     8 */         2u,          8u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2] */
  { /*     9 */         2u,          9u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2] */
  { /*    10 */         2u,         10u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2] */
  { /*    11 */         2u,         11u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1] */
  { /*    12 */         2u,         12u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3] */
  { /*    13 */         2u,         13u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7] */
  { /*    14 */         2u,          6u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4] */
  { /*    15 */         2u,         14u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1] */
  { /*    16 */         2u,         15u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2] */
  { /*    17 */         2u,          7u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1] */
  { /*    18 */         2u,         16u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2] */
  { /*    19 */         2u,         18u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2] */
  { /*    20 */         2u,         19u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1] */
  { /*    21 */         2u,         20u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1] */
  { /*    22 */         2u,         21u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2] */
  { /*    23 */         2u,         22u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1] */
  { /*    24 */         2u,         23u }   /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[27] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobInfo           Referable Keys */
  /*     0 */ {0uL, 0uL}   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt] */
  /*     1 */ {1uL, 0uL}   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt] */
  /*     2 */ {2uL, 60uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15] */
  /*     3 */ {3uL, 60uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1] */
  /*     4 */ {4uL, 60uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2] */
  /*     5 */ {5uL, 3uL}   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1] */
  /*     6 */ {6uL, 3uL}   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4] */
  /*     7 */ {7uL, 3uL}   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1] */
  /*     8 */ {8uL, 4uL}   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2] */
  /*     9 */ {9uL, 5uL}   ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2] */
  /*    10 */ {10uL, 6uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2] */
  /*    11 */ {11uL, 7uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1] */
  /*    12 */ {12uL, 8uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3] */
  /*    13 */ {13uL, 9uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7] */
  /*    14 */ {14uL, 10uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1] */
  /*    15 */ {15uL, 11uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2] */
  /*    16 */ {16uL, 12uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2] */
  /*    17 */ {17uL, 50uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ] */
  /*    18 */ {18uL, 14uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2] */
  /*    19 */ {19uL, 15uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1] */
  /*    20 */ {20uL, 18uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1] */
  /*    21 */ {21uL, 19uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2] */
  /*    22 */ {22uL, 16uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1] */
  /*    23 */ {23uL, 17uL} ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3] */
  /*    24 */ {24uL, 0uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid] */
  /*    25 */ {25uL, 0uL}  ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random] */
  /*    26 */ {26uL, 0uL}     /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureBoot_Generate] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobPrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Csm_JobPrimitiveInfo
  \brief  const uint32 callbackId; const Crypto_PrimitiveInfoType* primitiveInfo; const uint32 secureCounterId; const uint32 cryIfKeyId; const Crypto_ProcessingType processingType; const bool callbackUpdateNotification
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[27] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobPrimitiveInfo                                                                                                             Referable Keys */
  /*     0 */ {0uL, &Csm_PrimitiveInfo[3], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey_Aes128, CRYPTO_PROCESSING_ASYNC, FALSE}          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt] */
  /*     1 */ {1uL, &Csm_PrimitiveInfo[4], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey_Aes128, CRYPTO_PROCESSING_ASYNC, FALSE}          ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt] */
  /*     2 */ {2uL, &Csm_PrimitiveInfo[0], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15] */
  /*     3 */ {2uL, &Csm_PrimitiveInfo[0], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1] */
  /*     4 */ {2uL, &Csm_PrimitiveInfo[0], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2] */
  /*     5 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1] */
  /*     6 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4] */
  /*     7 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1] */
  /*     8 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2] */
  /*     9 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2] */
  /*    10 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2] */
  /*    11 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1] */
  /*    12 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3] */
  /*    13 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7] */
  /*    14 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1] */
  /*    15 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2] */
  /*    16 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2] */
  /*    17 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ] */
  /*    18 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2] */
  /*    19 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1] */
  /*    20 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1] */
  /*    21 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2] */
  /*    22 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1] */
  /*    23 */ {3uL, &Csm_PrimitiveInfo[1], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey, CRYPTO_PROCESSING_ASYNC, FALSE}                 ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3] */
  /*    24 */ {4uL, &Csm_PrimitiveInfo[6], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey_Flash, CRYPTO_PROCESSING_ASYNC, FALSE}           ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid] */
  /*    25 */ {0uL, &Csm_PrimitiveInfo[5], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey_RandomSeed, CRYPTO_PROCESSING_SYNC, FALSE}       ,  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random] */
  /*    26 */ {0uL, &Csm_PrimitiveInfo[7], 0x000000FFuL, CryIfConf_CryIfKey_CryIfKey_SecureBootAppKey, CRYPTO_PROCESSING_SYNC, FALSE}    /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureBoot_Generate] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobTable
**********************************************************************************************************************/
/** 
  \var    Csm_JobTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmJobs/CsmJob.
  \details
  Element            Description
  BswCallbacksIdx    the index of the 0:1 relation pointing to Csm_BswCallbacks
  CalloutInfoIdx     the index of the 0:1 relation pointing to Csm_CalloutInfo
  CsmKeyIdIdx        the index of the 1:1 relation pointing to one of Csm_Key
  MaskedBits         contains bitcoded the boolean data of Csm_BswCallbacksUsedOfJobTable, Csm_CalloutInfoUsedOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable, Csm_RteCallbackUsedOfJobTable
  Priority           Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx        the index of the 1:1 relation pointing to one of Csm_QueueInfo
  RteCallbackIdx     the index of the 0:1 relation pointing to Csm_RteCallback
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[27] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BswCallbacksIdx                   CalloutInfoIdx                   CsmKeyIdIdx  MaskedBits  Priority  QueueRefIdx  RteCallbackIdx                         Referable Keys */
  { /*     0 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,                              1u,          1u,      0x05u,       0u,          1u,                              0u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt, /ActiveEcuC/Csm/CsmJobs] */
  { /*     1 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,                              2u,          1u,      0x05u,       0u,          1u,                              1u },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt, /ActiveEcuC/Csm/CsmJobs] */
  { /*     2 */                               0u,                              4u,          0u,      0x0Cu,      60u,          3u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/HUT15_Sc_oB30_for_SC_CAN_V3_2_d2d608b6_Tx:SecOCTxAuthServiceConfigRef] */
  { /*     3 */                               0u,                              5u,          0u,      0x0Cu,      60u,          3u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_e0e5cc6a_Tx:SecOCTxAuthServiceConfigRef] */
  { /*     4 */                               0u,                              6u,          0u,      0x0Cu,      60u,          3u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/IP2_Sc_oB30_for_SC_CAN_V3_2_bf1dcb66_Tx:SecOCTxAuthServiceConfigRef] */
  { /*     5 */                               1u,                              7u,          0u,      0x0Cu,       3u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/ABM1_Sc_oB30_for_SC_CAN_V3_2_a346d8c1_Rx:SecOCRxAuthServiceConfigRef] */
  { /*     6 */                               1u,                             14u,          0u,      0x0Cu,       3u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4, /ActiveEcuC/Csm/CsmJobs] */
  { /*     7 */                               1u,                             17u,          0u,      0x0Cu,       3u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1, /ActiveEcuC/Csm/CsmJobs] */
  { /*     8 */                               1u,                              8u,          0u,      0x0Cu,       4u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_21d026ea_Rx:SecOCRxAuthServiceConfigRef] */
  { /*     9 */                               1u,                              9u,          0u,      0x0Cu,       5u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_cb95b5fe_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    10 */                               1u,                             10u,          0u,      0x0Cu,       6u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/AMP2_Sc_oB30_for_SC_CAN_V3_2_b40eb813_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    11 */                               1u,                             11u,          0u,      0x0Cu,       7u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/BCM1_Sc_oB30_for_SC_CAN_V3_2_cf14c4a7_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    12 */                               1u,                             12u,          0u,      0x0Cu,       8u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/BCM3_Sc_oB30_for_SC_CAN_V3_2_5f72e2fa_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    13 */                               1u,                             13u,          0u,      0x0Cu,       9u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7, /ActiveEcuC/Csm/CsmJobs] */
  { /*    14 */                               1u,                             15u,          0u,      0x0Cu,      10u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1, /ActiveEcuC/Csm/CsmJobs] */
  { /*    15 */                               1u,                             16u,          0u,      0x0Cu,      11u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2, /ActiveEcuC/Csm/CsmJobs] */
  { /*    16 */                               1u,                             18u,          0u,      0x0Cu,      12u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_49635fc5_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    17 */                               1u,                              0u,          0u,      0x0Cu,      50u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_922ee695_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    18 */                               1u,                             19u,          0u,      0x0Cu,      14u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_9b0c0f4a_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    19 */                               1u,                             20u,          0u,      0x0Cu,      15u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_1bc17110_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    20 */                               1u,                             21u,          0u,      0x0Cu,      18u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/TPMS1_Sc_oB30_for_SC_CAN_V3_2_fd4c9b31_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    21 */                               1u,                             22u,          0u,      0x0Cu,      19u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/TPMS2_Sc_oB30_for_SC_CAN_V3_2_c8a12d62_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    22 */                               1u,                             23u,          0u,      0x0Cu,      16u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_c35f86d3_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    23 */                               1u,                             24u,          0u,      0x0Cu,      17u,          4u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3, /ActiveEcuC/Csm/CsmJobs, /ActiveEcuC/SecOC/T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_5339a08e_Rx:SecOCRxAuthServiceConfigRef] */
  { /*    24 */                               2u,                              3u,          2u,      0x0Cu,       0u,          2u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid, /ActiveEcuC/Csm/CsmJobs] */
  { /*    25 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          3u,      0x00u,       0u,          0u, CSM_NO_RTECALLBACKIDXOFJOBTABLE },  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random, /ActiveEcuC/Csm/CsmJobs] */
  { /*    26 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE, CSM_NO_CALLOUTINFOIDXOFJOBTABLE,          6u,      0x00u,       0u,          0u, CSM_NO_RTECALLBACKIDXOFJOBTABLE }   /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureBoot_Generate, /ActiveEcuC/Csm/CsmJobs] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Key
**********************************************************************************************************************/
/** 
  \var    Csm_Key
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmKeys/CsmKey.
  \details
  Element       Description
  CryIfKeyId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef.
  UsePort       Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyUsePort.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_KeyType, CSM_CONST) Csm_Key[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                    UsePort        Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey                 ,    TRUE },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3:CsmJobKeyRef] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_Aes128          ,   FALSE },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Aes128, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt:CsmJobKeyRef] */
  { /*     2 */ CryIfConf_CryIfKey_CryIfKey_Flash           ,   FALSE },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Flash, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid:CsmJobKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_CryIfKey_RandomSeed      ,    TRUE },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_RandomSeed, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobKeyRef] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_SecureBootAPP_A ,   FALSE },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SecureBootAPP_A, /ActiveEcuC/Csm/CsmKeys] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_SecureBootAPP_B ,   FALSE },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SecureBootAPP_B, /ActiveEcuC/Csm/CsmKeys] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_SecureBootAppKey,   FALSE }   /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SecureBootAppKey, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureBoot_Generate:CsmJobKeyRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PrimitiveInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                  Referable Keys */
  /*     0 */ {16uL, CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, 16uL, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}      ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Generate/CsmMacGenerate/CsmPrimitives_Generate] */
  /*     1 */ {0uL, CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, 16uL, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}         ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Verify/CsmMacVerify/CsmPrimitives_Verify] */
  /*     2 */ {0uL, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_RSA, 16uL, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}            ,  /* [/ActiveEcuC/Csm/CsmPrimitives_RSA/CsmDecrypt/CsmPrimitives_RSA] */
  /*     3 */ {16uL, CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, 16uL, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}           ,  /* [/ActiveEcuC/Csm/CsmPrimitives_AES128_Decrypt/CsmDecrypt/CsmPrimitives_AES128_Decrypt] */
  /*     4 */ {16uL, CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, 16uL, CRYPTO_ALGOMODE_CBC, CRYPTO_ALGOFAM_NOT_SET}}           ,  /* [/ActiveEcuC/Csm/CsmPrimitives_AES128_Encrypt/CsmEncrypt/CsmPrimitives_AES128_Encrypt] */
  /*     5 */ {16uL, CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, 0uL, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}} ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Random/CsmRandomGenerate/CsmPrimitives_Random] */
  /*     6 */ {0uL, CRYPTO_KEYSETVALID, {CRYPTO_ALGOFAM_NOT_SET, 0uL, CRYPTO_ALGOMODE_NOT_SET, CRYPTO_ALGOFAM_NOT_SET}} ,  /* [/ActiveEcuC/Csm/CsmJobKeySetValidConfig/CsmJobKeySetValid/CsmJobKeySetValidConfig] */
  /*     7 */ {16uL, CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, 16uL, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}      ,  /* [/ActiveEcuC/Csm/CsmPrimitives_SecureBoot/CsmMacGenerate/CsmPrimitives_SecureBoot] */
  /*     8 */ {0uL, CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, 16uL, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}         ,  /* [/ActiveEcuC/Csm/CsmPrimitives_Verify_SYN/CsmMacVerify/CsmPrimitives_Verify_SYN] */
  /*     9 */ {16uL, CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, 16uL, CRYPTO_ALGOMODE_CMAC, CRYPTO_ALGOFAM_NOT_SET}}         /* [/ActiveEcuC/Csm/CsmPrimitives_Generate_SYN/CsmMacGenerate/CsmPrimitives_Generate_SYN] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueInfo
**********************************************************************************************************************/
/** 
  \var    Csm_QueueInfo
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmQueues/CsmQueue.
  \details
  Element                        Description
  ChannelId                      Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  TriggerAsynchJobsInCallback    Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmTriggerAsynchJobsInCallback.
  QueueEndIdx                    the end index of the 1:n relation pointing to Csm_Queue
  QueueLength                    the number of relations pointing to Csm_Queue
  QueueStartIdx                  the start index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                           TriggerAsynchJobsInCallback  QueueEndIdx  QueueLength  QueueStartIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_CryIfChannel_CMAC          ,                       FALSE,         17u,          1u,           16u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureBoot_Generate:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_CryIfChannel_CMAC          ,                       FALSE,         22u,          1u,           21u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES128, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt:CsmJobQueueRef] */
  { /*     2 */ CryIfConf_CryIfChannel_CryIfChannel_KeySetValid   ,                       FALSE,         18u,          1u,           17u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeySetValid, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_CryIfChannel_SecOC_Generate,                        TRUE,         21u,          3u,           18u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Generate, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2:CsmJobQueueRef] */
  { /*     4 */ CryIfConf_CryIfChannel_CryIfChannel_SecOC_Verify  ,                        TRUE,         16u,         16u,            0u }   /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Verify, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3:CsmJobQueueRef] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_RteCallback
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Csm_RteCallbackFuncType, CSM_CONST) Csm_RteCallback[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RteCallback                                                           Referable Keys */
  /*     0 */ Rte_Call_CsmJob_Aes128_Decrypt_Cbk_Callback_CallbackNotification ,  /* [/ActiveEcuC/Csm/CsmCallbacks/CsmJob_Aes128_Decrypt] */
  /*     1 */ Rte_Call_CsmJob_Aes128_Encrypt_Cbk_Callback_CallbackNotification    /* [/ActiveEcuC/Csm/CsmCallbacks/CsmJob_Aes128_Encrypt] */
};
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_CalloutState
**********************************************************************************************************************/
/** 
  \var    Csm_CalloutState
  \brief  Holds current state of the pre and post job callout processing.
  \details
  Element         Description
  CalloutState
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_CalloutStateUType, CSM_VAR_NOINIT) Csm_CalloutState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Job
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_JobUType, CSM_VAR_NOINIT) Csm_Job;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid] */
  /*    25 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_Random] */
  /*    26 */  /* [/ActiveEcuC/Csm/CsmJobs/CsmJob_SecureBoot_Generate] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Queue
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Verify] */
  /*   ... */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Verify] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Verify] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeySetValid] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Generate] */
  /*   ... */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Generate] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Generate] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES128] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueState
**********************************************************************************************************************/
/** 
  \var    Csm_QueueState
  \brief  Stores state of the asynchronous job queue.
  \details
  Element            Description
  PauseProcessing
  QueueIdx           the index of the 1:1 relation pointing to Csm_Queue
  ReservedIndexes
  SortNeeded     
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_SecureBoot_Generate:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES128, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_Aes128_Encrypt:CsmJobQueueRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_KeySetValid, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_KeySetValid:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Generate, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT15:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_FD1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Generate_HUT_IP2:CsmJobQueueRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_SecOC_Verify, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ABM1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ACC_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AEB_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_AMP2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_BCM3:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT7:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_DCT_FD4:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_ESP_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_GW_SYNC_REQ:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_IFC_FD2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_R_PBox1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_TPMS2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/CsmJob_CMAC_Verify_T_Box_FD3:CsmJobQueueRef] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_RteCallbackOccured
**********************************************************************************************************************/
/** 
  \var    Csm_RteCallbackOccured
  \brief  Variable which stores if a Callback for RTE occurred which needs to be handled in MainFunction.
*/ 
#define CSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_RteCallbackOccuredType, CSM_VAR_NOINIT) Csm_RteCallbackOccured;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_RteResult
**********************************************************************************************************************/
/** 
  \var    Csm_RteResult
  \brief  Contains the results of occurred callbacks which need to be delayed to MainFunction.
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Csm_RteResultUType, CSM_VAR_NOINIT) Csm_RteResult;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmCallbacks/CsmJob_Aes128_Decrypt] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmCallbacks/CsmJob_Aes128_Encrypt] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





