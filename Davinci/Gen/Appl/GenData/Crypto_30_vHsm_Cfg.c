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
 *            Module: Crypto_30_vHsm
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_vHsm_Cfg.c
 *   Generation Time: 2021-07-20 09:29:35
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm_Cfg.h"
#include "Crypto_30_vHsm.h"
#include "Crypto_30_vHsm_Ipc_Types.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL)
# define CRYPTO_30_VHSM_LOCAL static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL_INLINE)
# define CRYPTO_30_VHSM_LOCAL_INLINE LOCAL_INLINE
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
  Crypto_30_vHsm_DriverObject
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_DriverObject
  \brief  Contains parameters of /MICROSAR/Crypto_30_vHsm/Crypto/CryptoDriverObjects/CryptoDriverObject.
  \details
  Element     Description
  Id          Contains values of DefinitionRef: /MICROSAR/Crypto_30_vHsm/Crypto/CryptoDriverObjects/CryptoDriverObject/CryptoDriverObjectId.
  QueueIdx    the index of the 1:1 relation pointing to Crypto_30_vHsm_Queue
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_DriverObjectType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_DriverObject[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  QueueIdx        Referable Keys */
  { /*     0 */ 0u,       0u },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core, /ActiveEcuC/Crypto/CryptoDriverObjects] */
  { /*     1 */ 1u,       1u },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_CMAC:CryIfDriverObjectRef] */
  { /*     2 */ 2u,       2u },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_SecOC_Generate:CryIfDriverObjectRef] */
  { /*     3 */ 3u,       3u },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_SecOC_Verify:CryIfDriverObjectRef] */
  { /*     4 */ 4u,       4u },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_KeySetValid:CryIfDriverObjectRef] */
  { /*     5 */ 5u,       5u },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/Crypto/CryptovHsm:CryptoManagementDriverObject] */
  { /*     6 */ 6u,       6u },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv, /ActiveEcuC/Crypto/CryptoDriverObjects] */
  { /*     7 */ 7u,       7u }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio, /ActiveEcuC/Crypto/CryptoDriverObjects] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_InternalObjectIds
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_InternalObjectIdsType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_InternalObjectIds[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InternalObjectIds                                                                         */
  /*     0 */                 0u  /* CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Core */              ,
  /*     1 */                 1u  /* CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hal */               ,
  /*     2 */                 2u  /* CryptoConf_CryptoDriverObject_Crypto_30_Hsm_Hal_AesCmacGenerate */,
  /*     3 */                 3u  /* CryptoConf_CryptoDriverObject_Crypto_30_Hsm_Hal_AesCmacVerify */  ,
  /*     4 */                 4u  /* CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyM */              ,
  /*     5 */                 5u  /* CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyManagement */     ,
  /*     6 */                 6u  /* CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv */             ,
  /*     7 */                 7u  /* CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv_HighPrio */    
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ManagementDriverObject
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ManagementDriverObject
  \brief  Contains values of DefinitionRef: /MICROSAR/Crypto_30_vHsm/Crypto/CryptovHsm/CryptoManagementDriverObject.
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_ManagementDriverObjectType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ManagementDriverObject[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ManagementDriverObject                                          Referable Keys */
  /*     0 */ CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyManagement    /* [/ActiveEcuC/Crypto/CryptovHsm[0:CryptoManagementDriverObject], /ActiveEcuC/Crypto/CryptovHsm, /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_MemoryArea
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_MemoryArea
  \brief  Memory to which vHsm has direct access without the need of a copy.
  \details
  Element      Description
  AreaStart    Start address of area
  AreaStop     Stop address of area
  AreaType     Access type of area
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_MemoryAreaType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_MemoryArea[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AreaStart    AreaStop     AreaType                                        Referable Keys */
  { /*     0 */ 0x00000000u, 0x003FFFFFu, CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS      },  /* [/ActiveEcuC/Crypto/CryptovHsm/RH850_CodeFlash] */
  { /*     1 */ 0xFEEE8000u, 0xFEEFFFFFu, CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS },  /* [/ActiveEcuC/Crypto/CryptovHsm/RH850_GlobalRamA] */
  { /*     2 */ 0xFEFE8000u, 0xFEFFFFFFu, CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS      }   /* [/ActiveEcuC/Crypto/CryptovHsm/RH850_GlobalRamB] */
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjectInfo
  \details
  Element                     Description
  SharedDataBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  SharedDataBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  MaskedBits                  contains bitcoded the boolean data of Crypto_30_vHsm_BufferUsedOfObjectInfo, Crypto_30_vHsm_SharedDataBufferUsedOfObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_vHsm_ObjectInfoType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjectInfo[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SharedDataBufferEndIdx  SharedDataBufferStartIdx  MaskedBits */
  { /*     0 */                    35u,                       0u,      0x03u },
  { /*     1 */                    70u,                      35u,      0x03u },
  { /*     2 */                   201u,                      70u,      0x03u },
  { /*     3 */                   332u,                     201u,      0x03u },
  { /*     4 */                   367u,                     332u,      0x03u },
  { /*     5 */                   402u,                     367u,      0x03u },
  { /*     6 */                   437u,                     402u,      0x03u },
  { /*     7 */                   472u,                     437u,      0x03u }
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ChannelState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ChannelState
  \brief  Tracks which IPC channel is currently used.
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_ChannelStateType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_ChannelState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_DriverObjectLock
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_DriverObjectLockType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DriverObjectLock[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core, /ActiveEcuC/Crypto/CryptoDriverObjects] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_CMAC:CryIfDriverObjectRef] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_SecOC_Generate:CryIfDriverObjectRef] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_SecOC_Verify:CryIfDriverObjectRef] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_KeySetValid:CryIfDriverObjectRef] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/Crypto/CryptovHsm:CryptoManagementDriverObject] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv, /ActiveEcuC/Crypto/CryptoDriverObjects] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio, /ActiveEcuC/Crypto/CryptoDriverObjects] */

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_JobRequest
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_JobRequest
  \details
  Element                  Description
  InternalObjectId     
  OutputOffset         
  SecondaryOutputOffset
  UsedBuffer           
  Cancel               
  Kind                 
  Lock                 
  ProcessingType       
  Result               
  State                
  TrimmedOutputBuffer  
  CryptoJob            
  JobState             
  KeyMJob              
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Crypto_30_vHsm_JobRequestType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_JobRequest[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core, /ActiveEcuC/Crypto/CryptoDriverObjects] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_CMAC:CryIfDriverObjectRef] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_SecOC_Generate:CryIfDriverObjectRef] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_SecOC_Verify:CryIfDriverObjectRef] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/CryIf/CryIfChannel_KeySetValid:CryIfDriverObjectRef] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement, /ActiveEcuC/Crypto/CryptoDriverObjects, /ActiveEcuC/Crypto/CryptovHsm:CryptoManagementDriverObject] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv, /ActiveEcuC/Crypto/CryptoDriverObjects] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio, /ActiveEcuC/Crypto/CryptoDriverObjects] */

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_Output64PtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_Output64PtrDataBuffer
  \brief  Buffer for the Output64Ptr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_Output64PtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_Output64PtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_OutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_OutputLengthPtrDataBuffer
  \brief  Buffer for the outputLengthPtr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_OutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_OutputLengthPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_Queue
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_QueueUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
  \brief  Buffer for the secondaryOutputLengthPtr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SharedDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SharedDataBuffer
  \brief  Buffer for input and output data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_SharedDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SharedDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*    34 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*    35 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*    69 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*    70 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*   200 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*   201 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*   331 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*   332 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*   366 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*   367 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*   401 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*   402 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*   436 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*   437 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */
  /*   471 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_VerifyPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_VerifyPtrDataBuffer
  \brief  Buffer for the verifyPtr data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_vHsm_VerifyPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_VerifyPtrDataBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Core] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_Hal] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacGenerate] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_Hsm_Hal_AesCmacVerify] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyM] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_KeyManagement] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_vHsm_LibCv_HighPrio] */

#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
CONST(Crypto_30_vHsm_Ipc_MemoryLayoutType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_Ipc_MemoryLayout =
{
  /* protocolInformationOffset */
  0u,
  /* txChannelMemoryLayout[CRYPTO_30_VHSM_IPC_NUM_TX_CHANNELS] */
  {
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(0u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(0u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(0u) },
    { Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(1u), Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(1u), Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(1u) }  
  },
  /* rxChannelMemoryLayout[CRYPTO_30_VHSM_IPC_NUM_RX_CHANNELS] */
  {
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(0u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(0u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(0u) },
    { Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(1u), Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(1u), Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(1u) }  
  },
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (0u),  /* stackProtectionCanaryPE1Offset */  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (4u),  /* stackProtectionCanaryPE2Offset */  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (8u),  /* seedOffset */                      
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (12u), /* detModuleIdOffset */               
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (16u), /* detInstanceIdOffset */             
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (20u), /* detApiIdOffset */                  
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (24u), /* detErrorIdOffset */                
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (28u), /* readyFlagOffset */                 
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (32u), /* endRamExecFlagOffset */            
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (36u), /* ramExecFlagOffset */               
  Crypto_30_vHsm_Ipc_GetGlobalInfoOffset() + (40u)  /* detReportFlag */                   
};
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





