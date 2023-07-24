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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define CANIF_LCFG_SOURCE

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanNm Header Files  */ 
#include "CanNm_Cfg.h"
#include "CanNm_Cbk.h"
 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/




 /** 
  \brief  Wake-up validation function.
*/

FUNC(void, CANIF_APPL_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType CanWakeupEvents);

#define CANIF_STOP_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
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
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MappedTxBuffersConfigEndIdx                                                                                    MappedTxBuffersConfigStartIdx                                                                                          Referable Keys */
  { /*     0 */                          1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,                            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */ },  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     1 */                          0u  /* CanChannelWithoutTxBuffer */                                                 ,                            0u  /* CanChannelWithoutTxBuffer */                                                  },  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  { /*     2 */                          0u  /* CanChannelWithoutTxBuffer */                                                 ,                            0u  /* CanChannelWithoutTxBuffer */                                                  }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlConfig
  \details
  Element              Description
  RxDHRandomNumber1    Rx - DoubleHash - 1st random number.
  RxDHRandomNumber2    Rx - DoubleHash - 2nd random number.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlConfigType, CANIF_CONST) CanIf_CtrlConfig[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxDHRandomNumber1  RxDHRandomNumber2        Comment */
  { /*     0 */           0x1A15u,           0x59D4u },  /* [CAN channel with handle ID: 0] */
  { /*     1 */           0x0000u,           0x0000u },  /* [CAN channel with handle ID: 1] */
  { /*     2 */           0x0000u,           0x0000u }   /* [CAN channel with handle ID: 2] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_DataChecksumRxErrFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_DataChecksumRxErrFctType, CANIF_CONST) CanIf_DataChecksumRxErrFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlStatesIdx                                                                                        PduIdFirst                            PduIdLast                            TxBufferCfgIdx                                                                              TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 55 */,        0u  /* Unused, TxPduId 55 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex0 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx] */
  { /*     1 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 54 */,        0u  /* Unused, TxPduId 54 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx] */
  { /*     2 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 53 */,        0u  /* Unused, TxPduId 53 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex2 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx] */
  { /*     3 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 52 */,        0u  /* Unused, TxPduId 52 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex3 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx] */
  { /*     4 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 51 */,        0u  /* Unused, TxPduId 51 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex4 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx] */
  { /*     5 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 50 */,        0u  /* Unused, TxPduId 50 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex5 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx] */
  { /*     6 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 49 */,        0u  /* Unused, TxPduId 49 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex6 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx] */
  { /*     7 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 48 */,        0u  /* Unused, TxPduId 48 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex7 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx] */
  { /*     8 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 47 */,        0u  /* Unused, TxPduId 47 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex8 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx] */
  { /*     9 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 46 */,        0u  /* Unused, TxPduId 46 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex9 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx] */
  { /*    10 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 45 */,        0u  /* Unused, TxPduId 45 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex10 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx] */
  { /*    11 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 44 */,        0u  /* Unused, TxPduId 44 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex11 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx] */
  { /*    12 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 43 */,        0u  /* Unused, TxPduId 43 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex12 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx] */
  { /*    13 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 42 */,        0u  /* Unused, TxPduId 42 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex13 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx] */
  { /*    14 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 41 */,        0u  /* Unused, TxPduId 41 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex14 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx] */
  { /*    15 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 40 */,        0u  /* Unused, TxPduId 40 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex15 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx] */
  { /*    16 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 39 */,        0u  /* Unused, TxPduId 39 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex16 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx] */
  { /*    17 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 38 */,        0u  /* Unused, TxPduId 38 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex17 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx] */
  { /*    18 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         0u  /* Unused, TxPduId 0 */ ,        0u  /* Unused, TxPduId 37 */,                                     0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143 */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx] */
  { /*    19 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,         1u  /* RxPduId */           ,      145u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex19 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_efc035d8_Rx] */
  { /*    20 */            1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex20 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_001] */
  { /*    21 */            1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex21 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_001] */
  { /*    22 */            2u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex22 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_002] */
  { /*    23 */            2u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex23 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  }   /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_002] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MailBoxConfigIdx                                                                               Referable Keys */
  { /*     0 */              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxDHAdjust
**********************************************************************************************************************/
/** 
  \var    CanIf_RxDHAdjust
  \brief  Rx - DoubleHash - adjust values.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxDHAdjustType, CANIF_CONST) CanIf_RxDHAdjust[197] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxDHAdjust  */
  /*     0 */       0x00u,
  /*     1 */       0x01u,
  /*     2 */       0x02u,
  /*     3 */       0x12u,
  /*     4 */       0x04u,
  /*     5 */       0x05u,
  /*     6 */       0x6Eu,
  /*     7 */       0x07u,
  /*     8 */       0x08u,
  /*     9 */       0x09u,
  /*    10 */       0x0Au,
  /*    11 */       0x43u,
  /*    12 */       0x0Cu,
  /*    13 */       0x48u,
  /*    14 */       0x0Eu,
  /*    15 */       0x0Fu,
  /*    16 */       0x01u,
  /*    17 */       0x11u,
  /*    18 */       0x12u,
  /*    19 */       0x13u,
  /*    20 */       0x4Du,
  /*    21 */       0x15u,
  /*    22 */       0x65u,
  /*    23 */       0x17u,
  /*    24 */       0x27u,
  /*    25 */       0x11u,
  /*    26 */       0x1Au,
  /*    27 */       0x50u,
  /*    28 */       0x73u,
  /*    29 */       0x8Cu,
  /*    30 */       0x1Fu,
  /*    31 */       0x64u,
  /*    32 */       0x30u,
  /*    33 */       0x25u,
  /*    34 */       0x22u,
  /*    35 */       0x23u,
  /*    36 */       0x79u,
  /*    37 */       0x51u,
  /*    38 */       0x1Fu,
  /*    39 */       0x74u,
  /*    40 */       0x02u,
  /*    41 */       0x29u,
  /*    42 */       0x2Au,
  /*    43 */       0x02u,
  /*    44 */       0x2Eu,
  /*    45 */       0x35u,
  /*    46 */       0x47u,
  /*    47 */       0x2Fu,
  /*    48 */       0x61u,
  /*    49 */       0x7Fu,
  /* Index     RxDHAdjust  */
  /*    50 */       0x0Du,
  /*    51 */       0x2Cu,
  /*    52 */       0x1Au,
  /*    53 */       0x35u,
  /*    54 */       0x77u,
  /*    55 */       0x4Eu,
  /*    56 */       0x52u,
  /*    57 */       0x14u,
  /*    58 */       0x55u,
  /*    59 */       0x2Fu,
  /*    60 */       0x6Du,
  /*    61 */       0x57u,
  /*    62 */       0x7Fu,
  /*    63 */       0x3Fu,
  /*    64 */       0x06u,
  /*    65 */       0x41u,
  /*    66 */       0x4Fu,
  /*    67 */       0x46u,
  /*    68 */       0x6Du,
  /*    69 */       0x49u,
  /*    70 */       0x6Cu,
  /*    71 */       0x23u,
  /*    72 */       0x0Fu,
  /*    73 */       0x0Fu,
  /*    74 */       0x26u,
  /*    75 */       0x79u,
  /*    76 */       0x09u,
  /*    77 */       0x74u,
  /*    78 */       0x10u,
  /*    79 */       0x4Fu,
  /*    80 */       0x8Eu,
  /*    81 */       0x06u,
  /*    82 */       0x50u,
  /*    83 */       0x45u,
  /*    84 */       0x54u,
  /*    85 */       0x73u,
  /*    86 */       0x7Au,
  /*    87 */       0x81u,
  /*    88 */       0x71u,
  /*    89 */       0x0Du,
  /*    90 */       0x48u,
  /*    91 */       0x1Du,
  /*    92 */       0x33u,
  /*    93 */       0x5Du,
  /*    94 */       0x4Du,
  /*    95 */       0x76u,
  /*    96 */       0x71u,
  /*    97 */       0x1Du,
  /*    98 */       0x55u,
  /*    99 */       0x2Eu,
  /* Index     RxDHAdjust  */
  /*   100 */       0x50u,
  /*   101 */       0x65u,
  /*   102 */       0x66u,
  /*   103 */       0x81u,
  /*   104 */       0x68u,
  /*   105 */       0x52u,
  /*   106 */       0x6Au,
  /*   107 */       0x06u,
  /*   108 */       0x3Au,
  /*   109 */       0x7Cu,
  /*   110 */       0x8Bu,
  /*   111 */       0x6Fu,
  /*   112 */       0x16u,
  /*   113 */       0x27u,
  /*   114 */       0x55u,
  /*   115 */       0x07u,
  /*   116 */       0x36u,
  /*   117 */       0x12u,
  /*   118 */       0x21u,
  /*   119 */       0x23u,
  /*   120 */       0x74u,
  /*   121 */       0x79u,
  /*   122 */       0x6Eu,
  /*   123 */       0x64u,
  /*   124 */       0x23u,
  /*   125 */       0x19u,
  /*   126 */       0x7Eu,
  /*   127 */       0x25u,
  /*   128 */       0x80u,
  /*   129 */       0x68u,
  /*   130 */       0x4Fu,
  /*   131 */       0x83u,
  /*   132 */       0x84u,
  /*   133 */       0x4Au,
  /*   134 */       0x0Au,
  /*   135 */       0x87u,
  /*   136 */       0x88u,
  /*   137 */       0x42u,
  /*   138 */       0x0Bu,
  /*   139 */       0x06u,
  /*   140 */       0x8Cu,
  /*   141 */       0x8Du,
  /*   142 */       0x3Cu,
  /*   143 */       0x6Eu,
  /*   144 */       0x8Du,
  /*   145 */       0x54u,
  /*   146 */       0x41u,
  /*   147 */       0x01u,
  /*   148 */       0x02u,
  /*   149 */       0x3Cu,
  /* Index     RxDHAdjust  */
  /*   150 */       0x04u,
  /*   151 */       0x7Fu,
  /*   152 */       0x70u,
  /*   153 */       0x07u,
  /*   154 */       0x33u,
  /*   155 */       0x1Au,
  /*   156 */       0x2Du,
  /*   157 */       0x14u,
  /*   158 */       0x8Bu,
  /*   159 */       0x34u,
  /*   160 */       0x30u,
  /*   161 */       0x30u,
  /*   162 */       0x2Cu,
  /*   163 */       0x1Fu,
  /*   164 */       0x84u,
  /*   165 */       0x44u,
  /*   166 */       0x28u,
  /*   167 */       0x8Du,
  /*   168 */       0x16u,
  /*   169 */       0x72u,
  /*   170 */       0x2Bu,
  /*   171 */       0x3Du,
  /*   172 */       0x1Au,
  /*   173 */       0x75u,
  /*   174 */       0x4Au,
  /*   175 */       0x2Du,
  /*   176 */       0x22u,
  /*   177 */       0x24u,
  /*   178 */       0x5Eu,
  /*   179 */       0x72u,
  /*   180 */       0x20u,
  /*   181 */       0x5Fu,
  /*   182 */       0x24u,
  /*   183 */       0x05u,
  /*   184 */       0x1Cu,
  /*   185 */       0x85u,
  /*   186 */       0x5Du,
  /*   187 */       0x29u,
  /*   188 */       0x65u,
  /*   189 */       0x47u,
  /*   190 */       0x2Cu,
  /*   191 */       0x2Du,
  /*   192 */       0x2Eu,
  /*   193 */       0x72u,
  /*   194 */       0x3Au,
  /*   195 */       0x48u,
  /*   196 */       0x77u
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                                 Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanNm_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanNm_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanTp_RxIndication] */
  { /*     3 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  UpperPduId                PDU ID defined by upper layer.
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  IsCanNmRxPdu              TRUE: CAN-Nm Rx-PDU (for Wakeup validation), FALSE: No CAN-Nm Rx-PDU
  IsDataChecksumRxPdu       TRUE: Data checksum Rx-PDU, FALSE: None Data checksum Rx-PDU
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[146] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UpperPduId                                      RxPduCanId                                                                                      RxPduMask                                                                        IsCanNmRxPdu  IsDataChecksumRxPdu  RxIndicationFctListIdx                                RxPduDlc                              MsgType                         Comment                                                                                  Referable Keys */
  { /*     0 */ CanNmConf_CanNmRxPdu_CanNmRxPduRange_oB30_Rx  ,    0x0500u  /* Lower CanId of range: NMRange_oB30_for_SC_CAN_V3_2_bdc4688d_Rx, only 2.0-PDU */,   0x657Fu  /* Upper CanId of range: NMRange_oB30_for_SC_CAN_V3_2_bdc4688d_Rx */, TRUE        , TRUE               ,                     1u  /* CanNm_RxIndication */    ,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_NO_FD_CAN },  /* [PDU: NMRange_oB30_for_SC_CAN_V3_2_bdc4688d_Rx, Lower CanId of range: 0x500] */  /* [CanIfConf_CanIfRxPduCfg_NMRange_oB30_for_SC_CAN_V3_2_bdc4688d_Rx] */
  { /*     1 */ CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a46f9c70    ,    0x4773u  /* HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_030a1f56_Rx, only FD-PDU */                ,   0x07FFu  /* HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_030a1f56_Rx */               , FALSE       , TRUE               ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_030a1f56_Rx, CanId: 0x4773]        */  /* [CanIfConf_CanIfRxPduCfg_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_030a1f56_Rx] */
  { /*     2 */ CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_2185859a,    0x0773u  /* HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_20_5d31e3ec_Rx, only 2.0-PDU */            ,   0x07FFu  /* HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_20_5d31e3ec_Rx */            , FALSE       , TRUE               ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_NO_FD_CAN },  /* [PDU: HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_20_5d31e3ec_Rx, CanId: 0x773]      */  /* [CanIfConf_CanIfRxPduCfg_HUT_Phy_Req_Tp_oB30_for_SC_CAN_V3_2_20_5d31e3ec_Rx] */
  { /*     3 */ CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4ba4a7e4    ,    0x4760u  /* DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_9e7c1619_Rx, only FD-PDU */                ,   0x07FFu  /* DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_9e7c1619_Rx */               , FALSE       , TRUE               ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_9e7c1619_Rx, CanId: 0x4760]        */  /* [CanIfConf_CanIfRxPduCfg_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_9e7c1619_Rx] */
  { /*     4 */ CanTpConf_CanTpRxNPdu_CanTpRxNPdu_233f39d0    ,    0x0760u  /* DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_20_05fdfda7_Rx, only 2.0-PDU */            ,   0x07FFu  /* DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_20_05fdfda7_Rx */            , FALSE       , TRUE               ,                     2u  /* CanTp_RxIndication */    ,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_NO_FD_CAN },  /* [PDU: DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_20_05fdfda7_Rx, CanId: 0x760]      */  /* [CanIfConf_CanIfRxPduCfg_DiagFuncReq_Tp_oB30_for_SC_CAN_V3_2_20_05fdfda7_Rx] */
  { /*     5 */ PduRConf_PduRSrcPdu_PduRSrcPdu_9dcf459c       ,    0x0461u  /* GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_9379f94a_Rx, only FD-PDU */                ,   0x07FFu  /* GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_9379f94a_Rx */               , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_9379f94a_Rx, CanId: 0x461]         */  /* [CanIfConf_CanIfRxPduCfg_GW_Sync_Req_Sc_oB30_for_SC_CAN_V3_2_9379f94a_Rx] */
  { /*     6 */ PduRConf_PduRSrcPdu_PduRSrcPdu_7b4ae3ad       ,    0x03F1u  /* BMS30_oB30_for_SC_CAN_V3_2_457e1fbf_Rx, only FD-PDU */                         ,   0x07FFu  /* BMS30_oB30_for_SC_CAN_V3_2_457e1fbf_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS30_oB30_for_SC_CAN_V3_2_457e1fbf_Rx, CanId: 0x3f1]                  */  /* [CanIfConf_CanIfRxPduCfg_BMS30_oB30_for_SC_CAN_V3_2_457e1fbf_Rx] */
  { /*     7 */ PduRConf_PduRSrcPdu_PduRSrcPdu_3e24f09b       ,    0x03E9u  /* T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_3b96f3fe_Rx, only FD-PDU */                  ,   0x07FFu  /* T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_3b96f3fe_Rx */                 , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_3b96f3fe_Rx, CanId: 0x3e9]           */  /* [CanIfConf_CanIfRxPduCfg_T_BOX_FD3_Sc_oB30_for_SC_CAN_V3_2_3b96f3fe_Rx] */
  { /*     8 */ PduRConf_PduRSrcPdu_PduRSrcPdu_d7346016       ,    0x03E5u  /* AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx, only FD-PDU */                          ,   0x07FFu  /* AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx, CanId: 0x3e5]                   */  /* [CanIfConf_CanIfRxPduCfg_AMP3_oB30_for_SC_CAN_V3_2_e81cfa6e_Rx] */
  { /*     9 */ PduRConf_PduRSrcPdu_PduRSrcPdu_fc5d70a1       ,    0x03E3u  /* AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx, only FD-PDU */                       ,   0x07FFu  /* AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx, CanId: 0x3e3]                */  /* [CanIfConf_CanIfRxPduCfg_AMP2_Sc_oB30_for_SC_CAN_V3_2_85f1b9ac_Rx] */
  { /*    10 */ PduRConf_PduRSrcPdu_PduRSrcPdu_fd9dde52       ,    0x03E1u  /* AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx, only FD-PDU */                          ,   0x07FFu  /* AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx, CanId: 0x3e1]                   */  /* [CanIfConf_CanIfRxPduCfg_AMP1_oB30_for_SC_CAN_V3_2_c309c629_Rx] */
  { /*    11 */ PduRConf_PduRSrcPdu_PduRSrcPdu_41a1d6df       ,    0x03C2u  /* HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx, CanId: 0x3c2]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_HC7_oB30_for_SC_CAN_V3_2_144709d5_Rx] */
  { /*    12 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e1c6fd7b       ,    0x03BFu  /* BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx, only FD-PDU */                         ,   0x07FFu  /* BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx, CanId: 0x3bf]                  */  /* [CanIfConf_CanIfRxPduCfg_BMS22_oB30_for_SC_CAN_V3_2_21274140_Rx] */
  { /*    13 */ PduRConf_PduRSrcPdu_PduRSrcPdu_027a79b1       ,    0x03B7u  /* ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx, only FD-PDU */                         ,   0x07FFu  /* ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx, CanId: 0x3b7]                  */  /* [CanIfConf_CanIfRxPduCfg_ECM20_oB30_for_SC_CAN_V3_2_9cdc48c9_Rx] */
  { /*    14 */ PduRConf_PduRSrcPdu_PduRSrcPdu_ba5a64c9       ,    0x03B5u  /* ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx, only FD-PDU */                         ,   0x07FFu  /* ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx, CanId: 0x3b5]                  */  /* [CanIfConf_CanIfRxPduCfg_ECM19_oB30_for_SC_CAN_V3_2_488984df_Rx] */
  { /*    15 */ PduRConf_PduRSrcPdu_PduRSrcPdu_bcc5be8a       ,    0x03AEu  /* BMS66_oB30_for_SC_CAN_V3_2_d0cbb33b_Rx, only FD-PDU */                         ,   0x07FFu  /* BMS66_oB30_for_SC_CAN_V3_2_d0cbb33b_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS66_oB30_for_SC_CAN_V3_2_d0cbb33b_Rx, CanId: 0x3ae]                  */  /* [CanIfConf_CanIfRxPduCfg_BMS66_oB30_for_SC_CAN_V3_2_d0cbb33b_Rx] */
  { /*    16 */ PduRConf_PduRSrcPdu_PduRSrcPdu_ddd1fb68       ,    0x0395u  /* TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx, only FD-PDU */                      ,   0x07FFu  /* TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx */                     , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx, CanId: 0x395]               */  /* [CanIfConf_CanIfRxPduCfg_TPMS2_Sc_oB30_for_SC_CAN_V3_2_1c8c62f0_Rx] */
  { /*    17 */ PduRConf_PduRSrcPdu_PduRSrcPdu_889f2060       ,    0x0385u  /* AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx, only FD-PDU */                           ,   0x07FFu  /* AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx, CanId: 0x385]                    */  /* [CanIfConf_CanIfRxPduCfg_AC2_oB30_for_SC_CAN_V3_2_cda990a5_Rx] */
  { /*    18 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e6e62af0       ,    0x0371u  /* ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx, only FD-PDU */                          ,   0x07FFu  /* ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx, CanId: 0x371]                   */  /* [CanIfConf_CanIfRxPduCfg_ECM3_oB30_for_SC_CAN_V3_2_d6feaf92_Rx] */
  { /*    19 */ PduRConf_PduRSrcPdu_PduRSrcPdu_05f449b1       ,    0x035Eu  /* CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx, only FD-PDU */                           ,   0x07FFu  /* CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx, CanId: 0x35e]                    */  /* [CanIfConf_CanIfRxPduCfg_CP1_oB30_for_SC_CAN_V3_2_c9facce9_Rx] */
  { /*    20 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f51f0976       ,    0x0352u  /* BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx, only FD-PDU */                         ,   0x07FFu  /* BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx, CanId: 0x352]                  */  /* [CanIfConf_CanIfRxPduCfg_BMS19_oB30_for_SC_CAN_V3_2_c1d94ff7_Rx] */
  { /*    21 */ PduRConf_PduRSrcPdu_PduRSrcPdu_8d822981       ,    0x0351u  /* ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx, only FD-PDU */                       ,   0x07FFu  /* ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx, CanId: 0x351]                */  /* [CanIfConf_CanIfRxPduCfg_ABM1_Sc_oB30_for_SC_CAN_V3_2_acb4c490_Rx] */
  { /*    22 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4ded5b6d       ,    0x0350u  /* ECM24_oB30_for_SC_CAN_V3_2_f58bcd8b_Rx, only FD-PDU */                         ,   0x07FFu  /* ECM24_oB30_for_SC_CAN_V3_2_f58bcd8b_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM24_oB30_for_SC_CAN_V3_2_f58bcd8b_Rx, CanId: 0x350]                  */  /* [CanIfConf_CanIfRxPduCfg_ECM24_oB30_for_SC_CAN_V3_2_f58bcd8b_Rx] */
  { /*    23 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4b8049e3       ,    0x034Du  /* BCM18_oB30_for_SC_CAN_V3_2_4bcd4508_Rx, only FD-PDU */                         ,   0x07FFu  /* BCM18_oB30_for_SC_CAN_V3_2_4bcd4508_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM18_oB30_for_SC_CAN_V3_2_4bcd4508_Rx, CanId: 0x34d]                  */  /* [CanIfConf_CanIfRxPduCfg_BCM18_oB30_for_SC_CAN_V3_2_4bcd4508_Rx] */
  { /*    24 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4e859835       ,    0x0345u  /* BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx, only FD-PDU */                       ,   0x07FFu  /* BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx, CanId: 0x345]                */  /* [CanIfConf_CanIfRxPduCfg_BCM3_Sc_oB30_for_SC_CAN_V3_2_ae909a55_Rx] */
  { /*    25 */ PduRConf_PduRSrcPdu_PduRSrcPdu_5bb67826       ,    0x0344u  /* ETC3_oB30_for_SC_CAN_V3_2_5aaed6e3_Rx, only FD-PDU */                          ,   0x07FFu  /* ETC3_oB30_for_SC_CAN_V3_2_5aaed6e3_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ETC3_oB30_for_SC_CAN_V3_2_5aaed6e3_Rx, CanId: 0x344]                   */  /* [CanIfConf_CanIfRxPduCfg_ETC3_oB30_for_SC_CAN_V3_2_5aaed6e3_Rx] */
  { /*    26 */ PduRConf_PduRSrcPdu_PduRSrcPdu_31a98ace       ,    0x0341u  /* TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx, only FD-PDU */                      ,   0x07FFu  /* TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx */                     , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx, CanId: 0x341]               */  /* [CanIfConf_CanIfRxPduCfg_TPMS1_Sc_oB30_for_SC_CAN_V3_2_2ac39b2c_Rx] */
  { /*    27 */ PduRConf_PduRSrcPdu_PduRSrcPdu_7d041acd       ,    0x0333u  /* RFCM_R1_oB30_for_SC_CAN_V3_2_e80a1e77_Rx, only FD-PDU */                       ,   0x07FFu  /* RFCM_R1_oB30_for_SC_CAN_V3_2_e80a1e77_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: RFCM_R1_oB30_for_SC_CAN_V3_2_e80a1e77_Rx, CanId: 0x333]                */  /* [CanIfConf_CanIfRxPduCfg_RFCM_R1_oB30_for_SC_CAN_V3_2_e80a1e77_Rx] */
  { /*    28 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b0c290b6       ,    0x0332u  /* RFCM_L1_oB30_for_SC_CAN_V3_2_c3d527d2_Rx, only FD-PDU */                       ,   0x07FFu  /* RFCM_L1_oB30_for_SC_CAN_V3_2_c3d527d2_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: RFCM_L1_oB30_for_SC_CAN_V3_2_c3d527d2_Rx, CanId: 0x332]                */  /* [CanIfConf_CanIfRxPduCfg_RFCM_L1_oB30_for_SC_CAN_V3_2_c3d527d2_Rx] */
  { /*    29 */ PduRConf_PduRSrcPdu_PduRSrcPdu_69d7721a       ,    0x0330u  /* HCM_R2_oB30_for_SC_CAN_V3_2_8594005d_Rx, only FD-PDU */                        ,   0x07FFu  /* HCM_R2_oB30_for_SC_CAN_V3_2_8594005d_Rx */                       , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCM_R2_oB30_for_SC_CAN_V3_2_8594005d_Rx, CanId: 0x330]                 */  /* [CanIfConf_CanIfRxPduCfg_HCM_R2_oB30_for_SC_CAN_V3_2_8594005d_Rx] */
  { /*    30 */ PduRConf_PduRSrcPdu_PduRSrcPdu_9f68183c       ,    0x0325u  /* HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx, only FD-PDU */                          ,   0x07FFu  /* HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx, CanId: 0x325]                   */  /* [CanIfConf_CanIfRxPduCfg_HUD1_oB30_for_SC_CAN_V3_2_d4329b1b_Rx] */
  { /*    31 */ PduRConf_PduRSrcPdu_PduRSrcPdu_0aa73261       ,    0x0319u  /* BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx, only FD-PDU */                       ,   0x07FFu  /* BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx, CanId: 0x319]                */  /* [CanIfConf_CanIfRxPduCfg_BCM1_Sc_oB30_for_SC_CAN_V3_2_816c3588_Rx] */
  { /*    32 */ PduRConf_PduRSrcPdu_PduRSrcPdu_7dbaec87       ,    0x0317u  /* OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx, only FD-PDU */                          ,   0x07FFu  /* OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx, CanId: 0x317]                   */  /* [CanIfConf_CanIfRxPduCfg_OBC2_oB30_for_SC_CAN_V3_2_8fe92184_Rx] */
  { /*    33 */ PduRConf_PduRSrcPdu_PduRSrcPdu_5b2f6325       ,    0x0316u  /* OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx, only FD-PDU */                          ,   0x07FFu  /* OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx, CanId: 0x316]                   */  /* [CanIfConf_CanIfRxPduCfg_OBC1_oB30_for_SC_CAN_V3_2_5cce00c0_Rx] */
  { /*    34 */ PduRConf_PduRSrcPdu_PduRSrcPdu_600d7519       ,    0x0314u  /* HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx, CanId: 0x314]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_HC6_oB30_for_SC_CAN_V3_2_ee01dd1b_Rx] */
  { /*    35 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f8ac6ad4       ,    0x0311u  /* DOCK1_oB30_for_SC_CAN_V3_2_ad577210_Rx, only FD-PDU */                         ,   0x07FFu  /* DOCK1_oB30_for_SC_CAN_V3_2_ad577210_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DOCK1_oB30_for_SC_CAN_V3_2_ad577210_Rx, CanId: 0x311]                  */  /* [CanIfConf_CanIfRxPduCfg_DOCK1_oB30_for_SC_CAN_V3_2_ad577210_Rx] */
  { /*    36 */ PduRConf_PduRSrcPdu_PduRSrcPdu_ff0f949a       ,    0x030Fu  /* BCM19_oB30_for_SC_CAN_V3_2_bc202778_Rx, only FD-PDU */                         ,   0x07FFu  /* BCM19_oB30_for_SC_CAN_V3_2_bc202778_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM19_oB30_for_SC_CAN_V3_2_bc202778_Rx, CanId: 0x30f]                  */  /* [CanIfConf_CanIfRxPduCfg_BCM19_oB30_for_SC_CAN_V3_2_bc202778_Rx] */
  { /*    37 */ PduRConf_PduRSrcPdu_PduRSrcPdu_0a0aa92e       ,    0x030Du  /* HCM_R1_oB30_for_SC_CAN_V3_2_c6a7a6c6_Rx, only FD-PDU */                        ,   0x07FFu  /* HCM_R1_oB30_for_SC_CAN_V3_2_c6a7a6c6_Rx */                       , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCM_R1_oB30_for_SC_CAN_V3_2_c6a7a6c6_Rx, CanId: 0x30d]                 */  /* [CanIfConf_CanIfRxPduCfg_HCM_R1_oB30_for_SC_CAN_V3_2_c6a7a6c6_Rx] */
  { /*    38 */ PduRConf_PduRSrcPdu_PduRSrcPdu_1479e4f3       ,    0x030Au  /* RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx, only FD-PDU */                      ,   0x07FFu  /* RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx */                     , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx, CanId: 0x30a]               */  /* [CanIfConf_CanIfRxPduCfg_RSDS_FD2_oB30_for_SC_CAN_V3_2_636e054f_Rx] */
  { /*    39 */ PduRConf_PduRSrcPdu_PduRSrcPdu_696d66e7       ,    0x0308u  /* HCM_L1_oB30_for_SC_CAN_V3_2_838a93c0_Rx, only FD-PDU */                        ,   0x07FFu  /* HCM_L1_oB30_for_SC_CAN_V3_2_838a93c0_Rx */                       , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCM_L1_oB30_for_SC_CAN_V3_2_838a93c0_Rx, CanId: 0x308]                 */  /* [CanIfConf_CanIfRxPduCfg_HCM_L1_oB30_for_SC_CAN_V3_2_838a93c0_Rx] */
  { /*    40 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4ae12c6a       ,    0x0305u  /* BCM11_oB30_for_SC_CAN_V3_2_6e8f2dfc_Rx, only FD-PDU */                         ,   0x07FFu  /* BCM11_oB30_for_SC_CAN_V3_2_6e8f2dfc_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM11_oB30_for_SC_CAN_V3_2_6e8f2dfc_Rx, CanId: 0x305]                  */  /* [CanIfConf_CanIfRxPduCfg_BCM11_oB30_for_SC_CAN_V3_2_6e8f2dfc_Rx] */
  { /*    41 */ PduRConf_PduRSrcPdu_PduRSrcPdu_baba8622       ,    0x0304u  /* HCM_L2_oB30_for_SC_CAN_V3_2_c0b9355b_Rx, only FD-PDU */                        ,   0x07FFu  /* HCM_L2_oB30_for_SC_CAN_V3_2_c0b9355b_Rx */                       , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCM_L2_oB30_for_SC_CAN_V3_2_c0b9355b_Rx, CanId: 0x304]                 */  /* [CanIfConf_CanIfRxPduCfg_HCM_L2_oB30_for_SC_CAN_V3_2_c0b9355b_Rx] */
  { /*    42 */ PduRConf_PduRSrcPdu_PduRSrcPdu_698f1b71       ,    0x0303u  /* ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx, only FD-PDU */                         ,   0x07FFu  /* ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx, CanId: 0x303]                  */  /* [CanIfConf_CanIfRxPduCfg_ESCL2_oB30_for_SC_CAN_V3_2_c0f28acf_Rx] */
  { /*    43 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f3ee8ef3       ,    0x0302u  /* PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx, only FD-PDU */                         ,   0x07FFu  /* PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx, CanId: 0x302]                  */  /* [CanIfConf_CanIfRxPduCfg_PEPS4_oB30_for_SC_CAN_V3_2_4d06dcb3_Rx] */
  { /*    44 */ PduRConf_PduRSrcPdu_PduRSrcPdu_c31e0157       ,    0x02FDu  /* AC3_oB30_for_SC_CAN_V3_2_ea1dcaef_Rx, only FD-PDU */                           ,   0x07FFu  /* AC3_oB30_for_SC_CAN_V3_2_ea1dcaef_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC3_oB30_for_SC_CAN_V3_2_ea1dcaef_Rx, CanId: 0x2fd]                    */  /* [CanIfConf_CanIfRxPduCfg_AC3_oB30_for_SC_CAN_V3_2_ea1dcaef_Rx] */
  { /*    45 */ PduRConf_PduRSrcPdu_PduRSrcPdu_519dd205       ,    0x02FBu  /* VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx, only FD-PDU */                         ,   0x07FFu  /* VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx, CanId: 0x2fb]                  */  /* [CanIfConf_CanIfRxPduCfg_VMDR1_oB30_for_SC_CAN_V3_2_3fa04c0b_Rx] */
  { /*    46 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e5bf4bed       ,    0x02FAu  /* HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx, CanId: 0x2fa]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_PT4_oB30_for_SC_CAN_V3_2_f04552bd_Rx] */
  { /*    47 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e64ce2e4       ,    0x02F8u  /* AC6_oB30_for_SC_CAN_V3_2_5378f98d_Rx, only FD-PDU */                           ,   0x07FFu  /* AC6_oB30_for_SC_CAN_V3_2_5378f98d_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC6_oB30_for_SC_CAN_V3_2_5378f98d_Rx, CanId: 0x2f8]                    */  /* [CanIfConf_CanIfRxPduCfg_AC6_oB30_for_SC_CAN_V3_2_5378f98d_Rx] */
  { /*    48 */ PduRConf_PduRSrcPdu_PduRSrcPdu_ad774806       ,    0x02F7u  /* DDCM3_oB30_for_SC_CAN_V3_2_47eb1dc1_Rx, only FD-PDU */                         ,   0x07FFu  /* DDCM3_oB30_for_SC_CAN_V3_2_47eb1dc1_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DDCM3_oB30_for_SC_CAN_V3_2_47eb1dc1_Rx, CanId: 0x2f7]                  */  /* [CanIfConf_CanIfRxPduCfg_DDCM3_oB30_for_SC_CAN_V3_2_47eb1dc1_Rx] */
  { /*    49 */ PduRConf_PduRSrcPdu_PduRSrcPdu_67c45ddd       ,    0x02F0u  /* T_BOX_FD10_oB30_for_SC_CAN_V3_2_1bbcf88b_Rx, only FD-PDU */                    ,   0x07FFu  /* T_BOX_FD10_oB30_for_SC_CAN_V3_2_1bbcf88b_Rx */                   , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: T_BOX_FD10_oB30_for_SC_CAN_V3_2_1bbcf88b_Rx, CanId: 0x2f0]             */  /* [CanIfConf_CanIfRxPduCfg_T_BOX_FD10_oB30_for_SC_CAN_V3_2_1bbcf88b_Rx] */
    /* Index    UpperPduId                                      RxPduCanId                                                                                      RxPduMask                                                                        IsCanNmRxPdu  IsDataChecksumRxPdu  RxIndicationFctListIdx                                RxPduDlc                              MsgType                         Comment                                                                                  Referable Keys */
  { /*    50 */ PduRConf_PduRSrcPdu_PduRSrcPdu_47890b95       ,    0x02D4u  /* ECM16_oB30_for_SC_CAN_V3_2_3037abc8_Rx, only FD-PDU */                         ,   0x07FFu  /* ECM16_oB30_for_SC_CAN_V3_2_3037abc8_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM16_oB30_for_SC_CAN_V3_2_3037abc8_Rx, CanId: 0x2d4]                  */  /* [CanIfConf_CanIfRxPduCfg_ECM16_oB30_for_SC_CAN_V3_2_3037abc8_Rx] */
  { /*    51 */ PduRConf_PduRSrcPdu_PduRSrcPdu_403eb9f2       ,    0x02D3u  /* ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx, only FD-PDU */                         ,   0x07FFu  /* ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx, CanId: 0x2d3]                  */  /* [CanIfConf_CanIfRxPduCfg_ECM11_oB30_for_SC_CAN_V3_2_9a268e5b_Rx] */
  { /*    52 */ PduRConf_PduRSrcPdu_PduRSrcPdu_a3a226e0       ,    0x02D2u  /* AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx, only FD-PDU */                     ,   0x07FFu  /* AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx */                    , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx, CanId: 0x2d2]              */  /* [CanIfConf_CanIfRxPduCfg_AMP4_ANC1_oB30_for_SC_CAN_V3_2_778038f3_Rx] */
  { /*    53 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e351b728       ,    0x02D1u  /* SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx, only FD-PDU */                          ,   0x07FFu  /* SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx, CanId: 0x2d1]                   */  /* [CanIfConf_CanIfRxPduCfg_SCM1_oB30_for_SC_CAN_V3_2_a8dca609_Rx] */
  { /*    54 */ PduRConf_PduRSrcPdu_PduRSrcPdu_7d545289       ,    0x02D0u  /* AC7_oB30_for_SC_CAN_V3_2_74cca3c7_Rx, only FD-PDU */                           ,   0x07FFu  /* AC7_oB30_for_SC_CAN_V3_2_74cca3c7_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC7_oB30_for_SC_CAN_V3_2_74cca3c7_Rx, CanId: 0x2d0]                    */  /* [CanIfConf_CanIfRxPduCfg_AC7_oB30_for_SC_CAN_V3_2_74cca3c7_Rx] */
  { /*    55 */ PduRConf_PduRSrcPdu_PduRSrcPdu_d6092b8e       ,    0x02CFu  /* IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx, only FD-PDU */                       ,   0x07FFu  /* IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx, CanId: 0x2cf]                */  /* [CanIfConf_CanIfRxPduCfg_IFC_FD3_oB30_for_SC_CAN_V3_2_892173f6_Rx] */
  { /*    56 */ PduRConf_PduRSrcPdu_PduRSrcPdu_859010d7       ,    0x02CEu  /* DSC4_oB30_for_SC_CAN_V3_2_c9fc5f8d_Rx, only FD-PDU */                          ,   0x07FFu  /* DSC4_oB30_for_SC_CAN_V3_2_c9fc5f8d_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DSC4_oB30_for_SC_CAN_V3_2_c9fc5f8d_Rx, CanId: 0x2ce]                   */  /* [CanIfConf_CanIfRxPduCfg_DSC4_oB30_for_SC_CAN_V3_2_c9fc5f8d_Rx] */
  { /*    57 */ PduRConf_PduRSrcPdu_PduRSrcPdu_3e9300cb       ,    0x02CDu  /* PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx, only FD-PDU */                         ,   0x07FFu  /* PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx, CanId: 0x2cd]                  */  /* [CanIfConf_CanIfRxPduCfg_PDCM1_oB30_for_SC_CAN_V3_2_39eaea1a_Rx] */
  { /*    58 */ PduRConf_PduRSrcPdu_PduRSrcPdu_30c11829       ,    0x02CCu  /* AC4_oB30_for_SC_CAN_V3_2_1c104d19_Rx, only FD-PDU */                           ,   0x07FFu  /* AC4_oB30_for_SC_CAN_V3_2_1c104d19_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC4_oB30_for_SC_CAN_V3_2_1c104d19_Rx, CanId: 0x2cc]                    */  /* [CanIfConf_CanIfRxPduCfg_AC4_oB30_for_SC_CAN_V3_2_1c104d19_Rx] */
  { /*    59 */ PduRConf_PduRSrcPdu_PduRSrcPdu_79c46baf       ,    0x02CAu  /* DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx, only FD-PDU */                         ,   0x07FFu  /* DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx, CanId: 0x2ca]                  */  /* [CanIfConf_CanIfRxPduCfg_DDCM1_oB30_for_SC_CAN_V3_2_7340df60_Rx] */
  { /*    60 */ PduRConf_PduRSrcPdu_PduRSrcPdu_a928d770       ,    0x02C4u  /* BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx, only FD-PDU */                         ,   0x07FFu  /* BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx, CanId: 0x2c4]                  */  /* [CanIfConf_CanIfRxPduCfg_BMS35_oB30_for_SC_CAN_V3_2_dbc4f88d_Rx] */
  { /*    61 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4b2a6812       ,    0x02C1u  /* DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx, only FD-PDU */                          ,   0x07FFu  /* DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx, CanId: 0x2c1]                   */  /* [CanIfConf_CanIfRxPduCfg_DSM1_oB30_for_SC_CAN_V3_2_918c77ee_Rx] */
  { /*    62 */ PduRConf_PduRSrcPdu_PduRSrcPdu_c82f5918       ,    0x02BBu  /* GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx, only FD-PDU */                        ,   0x07FFu  /* GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx */                       , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx, CanId: 0x2bb]                 */  /* [CanIfConf_CanIfRxPduCfg_GW_FD1_oB30_for_SC_CAN_V3_2_002aed10_Rx] */
  { /*    63 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b0737289       ,    0x02BAu  /* WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx, only FD-PDU */                          ,   0x07FFu  /* WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx, CanId: 0x2ba]                   */  /* [CanIfConf_CanIfRxPduCfg_WPC1_oB30_for_SC_CAN_V3_2_08a4c96d_Rx] */
  { /*    64 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e3728613       ,    0x02B9u  /* DWD1_oB30_for_SC_CAN_V3_2_e70e0616_Rx, only FD-PDU */                          ,   0x07FFu  /* DWD1_oB30_for_SC_CAN_V3_2_e70e0616_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DWD1_oB30_for_SC_CAN_V3_2_e70e0616_Rx, CanId: 0x2b9]                   */  /* [CanIfConf_CanIfRxPduCfg_DWD1_oB30_for_SC_CAN_V3_2_e70e0616_Rx] */
  { /*    65 */ PduRConf_PduRSrcPdu_PduRSrcPdu_211c2779       ,    0x02B8u  /* ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx, only FD-PDU */                       ,   0x07FFu  /* ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx, CanId: 0x2b8]                */  /* [CanIfConf_CanIfRxPduCfg_ACC_FD4_oB30_for_SC_CAN_V3_2_c85366f8_Rx] */
  { /*    66 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f74b7e59       ,    0x02B4u  /* ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx, only FD-PDU */                       ,   0x07FFu  /* ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx, CanId: 0x2b4]                */  /* [CanIfConf_CanIfRxPduCfg_ACC_FD3_oB30_for_SC_CAN_V3_2_42104251_Rx] */
  { /*    67 */ PduRConf_PduRSrcPdu_PduRSrcPdu_0408d396       ,    0x02ABu  /* ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx, only FD-PDU */                    ,   0x07FFu  /* ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx */                   , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx, CanId: 0x2ab]             */  /* [CanIfConf_CanIfRxPduCfg_ACC_FD2_Sc_oB30_for_SC_CAN_V3_2_bd00e6e5_Rx] */
  { /*    68 */ PduRConf_PduRSrcPdu_PduRSrcPdu_a19a19e9       ,    0x02A8u  /* EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx, only FD-PDU */                          ,   0x07FFu  /* EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx, CanId: 0x2a8]                   */  /* [CanIfConf_CanIfRxPduCfg_EEM1_oB30_for_SC_CAN_V3_2_96620764_Rx] */
  { /*    69 */ PduRConf_PduRSrcPdu_PduRSrcPdu_feec0bf6       ,    0x02A3u  /* BCM14_oB30_for_SC_CAN_V3_2_f035cace_Rx, only FD-PDU */                         ,   0x07FFu  /* BCM14_oB30_for_SC_CAN_V3_2_f035cace_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM14_oB30_for_SC_CAN_V3_2_f035cace_Rx, CanId: 0x2a3]                  */  /* [CanIfConf_CanIfRxPduCfg_BCM14_oB30_for_SC_CAN_V3_2_f035cace_Rx] */
  { /*    70 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4ea26dbe       ,    0x029Fu  /* BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx, only FD-PDU */                          ,   0x07FFu  /* BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx, CanId: 0x29f]                   */  /* [CanIfConf_CanIfRxPduCfg_BCM8_oB30_for_SC_CAN_V3_2_207df679_Rx] */
  { /*    71 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b0ba9a32       ,    0x029Du  /* AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx, only FD-PDU */                           ,   0x07FFu  /* AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx, CanId: 0x29d]                    */  /* [CanIfConf_CanIfRxPduCfg_AC1_oB30_for_SC_CAN_V3_2_a5757e7b_Rx] */
  { /*    72 */ PduRConf_PduRSrcPdu_PduRSrcPdu_9b8498a5       ,    0x029Bu  /* HAP_FD7_oB30_for_SC_CAN_V3_2_3a38a501_Rx, only FD-PDU */                       ,   0x07FFu  /* HAP_FD7_oB30_for_SC_CAN_V3_2_3a38a501_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HAP_FD7_oB30_for_SC_CAN_V3_2_3a38a501_Rx, CanId: 0x29b]                */  /* [CanIfConf_CanIfRxPduCfg_HAP_FD7_oB30_for_SC_CAN_V3_2_3a38a501_Rx] */
  { /*    73 */ PduRConf_PduRSrcPdu_PduRSrcPdu_12ca8017       ,    0x0299u  /* AC14_oB30_for_SC_CAN_V3_2_44780039_Rx, only FD-PDU */                          ,   0x07FFu  /* AC14_oB30_for_SC_CAN_V3_2_44780039_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC14_oB30_for_SC_CAN_V3_2_44780039_Rx, CanId: 0x299]                   */  /* [CanIfConf_CanIfRxPduCfg_AC14_oB30_for_SC_CAN_V3_2_44780039_Rx] */
  { /*    74 */ PduRConf_PduRSrcPdu_PduRSrcPdu_fc620f42       ,    0x0298u  /* HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx, only FD-PDU */                       ,   0x07FFu  /* HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx, CanId: 0x298]                */  /* [CanIfConf_CanIfRxPduCfg_HAP_FD3_oB30_for_SC_CAN_V3_2_65c1fabb_Rx] */
  { /*    75 */ PduRConf_PduRSrcPdu_PduRSrcPdu_9304c641       ,    0x0295u  /* PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx, only FD-PDU */                         ,   0x07FFu  /* PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx, CanId: 0x295]                  */  /* [CanIfConf_CanIfRxPduCfg_PEPS2_oB30_for_SC_CAN_V3_2_10fa9b50_Rx] */
  { /*    76 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f7d6c790       ,    0x0290u  /* ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx, only FD-PDU */                       ,   0x07FFu  /* ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx, CanId: 0x290]                */  /* [CanIfConf_CanIfRxPduCfg_ECM_PT6_oB30_for_SC_CAN_V3_2_0acba12c_Rx] */
  { /*    77 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2618f07c       ,    0x028Du  /* BCM7_oB30_for_SC_CAN_V3_2_09245eaf_Rx, only FD-PDU */                          ,   0x07FFu  /* BCM7_oB30_for_SC_CAN_V3_2_09245eaf_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM7_oB30_for_SC_CAN_V3_2_09245eaf_Rx, CanId: 0x28d]                   */  /* [CanIfConf_CanIfRxPduCfg_BCM7_oB30_for_SC_CAN_V3_2_09245eaf_Rx] */
  { /*    78 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2db827e1       ,    0x0289u  /* HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx, only FD-PDU */                       ,   0x07FFu  /* HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx, CanId: 0x289]                */  /* [CanIfConf_CanIfRxPduCfg_HAP_FD6_oB30_for_SC_CAN_V3_2_c07e71cf_Rx] */
  { /*    79 */ PduRConf_PduRSrcPdu_PduRSrcPdu_96315e5d       ,    0x0287u  /* ALS1_oB30_for_SC_CAN_V3_2_fa40a3a9_Rx, only FD-PDU */                          ,   0x07FFu  /* ALS1_oB30_for_SC_CAN_V3_2_fa40a3a9_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ALS1_oB30_for_SC_CAN_V3_2_fa40a3a9_Rx, CanId: 0x287]                   */  /* [CanIfConf_CanIfRxPduCfg_ALS1_oB30_for_SC_CAN_V3_2_fa40a3a9_Rx] */
  { /*    80 */ PduRConf_PduRSrcPdu_PduRSrcPdu_04314b70       ,    0x0285u  /* BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx, only FD-PDU */                          ,   0x07FFu  /* BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx, CanId: 0x285]                   */  /* [CanIfConf_CanIfRxPduCfg_BMS8_oB30_for_SC_CAN_V3_2_b80b0dd9_Rx] */
  { /*    81 */ PduRConf_PduRSrcPdu_PduRSrcPdu_554b1989       ,    0x027Cu  /* AC8_oB30_for_SC_CAN_V3_2_6412f020_Rx, only FD-PDU */                           ,   0x07FFu  /* AC8_oB30_for_SC_CAN_V3_2_6412f020_Rx */                          , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AC8_oB30_for_SC_CAN_V3_2_6412f020_Rx, CanId: 0x27c]                    */  /* [CanIfConf_CanIfRxPduCfg_AC8_oB30_for_SC_CAN_V3_2_6412f020_Rx] */
  { /*    82 */ PduRConf_PduRSrcPdu_PduRSrcPdu_bcb0e91f       ,    0x0274u  /* HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx, only FD-PDU */                       ,   0x07FFu  /* HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx, CanId: 0x274]                */  /* [CanIfConf_CanIfRxPduCfg_HAP_FD2_oB30_for_SC_CAN_V3_2_9f872e75_Rx] */
  { /*    83 */ PduRConf_PduRSrcPdu_PduRSrcPdu_4c55e876       ,    0x0273u  /* Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx, only FD-PDU */                      ,   0x07FFu  /* Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx */                     , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx, CanId: 0x273]               */  /* [CanIfConf_CanIfRxPduCfg_Trailer1_oB30_for_SC_CAN_V3_2_8e004320_Rx] */
  { /*    84 */ PduRConf_PduRSrcPdu_PduRSrcPdu_d8f14722       ,    0x0271u  /* ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx, only FD-PDU */                          ,   0x07FFu  /* ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx, CanId: 0x271]                   */  /* [CanIfConf_CanIfRxPduCfg_ECM2_oB30_for_SC_CAN_V3_2_2eccb291_Rx] */
  { /*    85 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e2c2cfc0       ,    0x0268u  /* HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx, CanId: 0x268]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_HC3_oB30_for_SC_CAN_V3_2_4bbe566f_Rx] */
  { /*    86 */ PduRConf_PduRSrcPdu_PduRSrcPdu_dd38072b       ,    0x025Cu  /* BLE1_oB30_for_SC_CAN_V3_2_6fd972c2_Rx, only FD-PDU */                          ,   0x07FFu  /* BLE1_oB30_for_SC_CAN_V3_2_6fd972c2_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BLE1_oB30_for_SC_CAN_V3_2_6fd972c2_Rx, CanId: 0x25c]                   */  /* [CanIfConf_CanIfRxPduCfg_BLE1_oB30_for_SC_CAN_V3_2_6fd972c2_Rx] */
  { /*    87 */ PduRConf_PduRSrcPdu_PduRSrcPdu_0f6d129e       ,    0x0251u  /* TOD1_oB30_for_SC_CAN_V3_2_7b636dc1_Rx, only FD-PDU */                          ,   0x07FFu  /* TOD1_oB30_for_SC_CAN_V3_2_7b636dc1_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: TOD1_oB30_for_SC_CAN_V3_2_7b636dc1_Rx, CanId: 0x251]                   */  /* [CanIfConf_CanIfRxPduCfg_TOD1_oB30_for_SC_CAN_V3_2_7b636dc1_Rx] */
  { /*    88 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e8995c05       ,    0x0248u  /* HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx, CanId: 0x248]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_PT7_oB30_for_SC_CAN_V3_2_25ff29ae_Rx] */
  { /*    89 */ PduRConf_PduRSrcPdu_PduRSrcPdu_5424b305       ,    0x0246u  /* ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx, only FD-PDU */                          ,   0x07FFu  /* ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx, CanId: 0x246]                   */  /* [CanIfConf_CanIfRxPduCfg_ABS2_oB30_for_SC_CAN_V3_2_6e2325df_Rx] */
  { /*    90 */ PduRConf_PduRSrcPdu_PduRSrcPdu_bd6a4cb0       ,    0x0245u  /* ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx, only FD-PDU */                          ,   0x07FFu  /* ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx, CanId: 0x245]                   */  /* [CanIfConf_CanIfRxPduCfg_ABM2_oB30_for_SC_CAN_V3_2_b111794d_Rx] */
  { /*    91 */ PduRConf_PduRSrcPdu_PduRSrcPdu_9d6b32ca       ,    0x0244u  /* CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx, only FD-PDU */                          ,   0x07FFu  /* CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx, CanId: 0x244]                   */  /* [CanIfConf_CanIfRxPduCfg_CSA3_oB30_for_SC_CAN_V3_2_2d924efb_Rx] */
  { /*    92 */ PduRConf_PduRSrcPdu_PduRSrcPdu_1086a37c       ,    0x023Du  /* IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx, only FD-PDU */                    ,   0x07FFu  /* IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx */                   , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx, CanId: 0x23d]             */  /* [CanIfConf_CanIfRxPduCfg_IFC_FD2_Sc_oB30_for_SC_CAN_V3_2_ccd6702c_Rx] */
  { /*    93 */ PduRConf_PduRSrcPdu_PduRSrcPdu_5945cf07       ,    0x0238u  /* BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx, only FD-PDU */                         ,   0x07FFu  /* BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx, CanId: 0x238]                  */  /* [CanIfConf_CanIfRxPduCfg_BCM12_oB30_for_SC_CAN_V3_2_adc98d2d_Rx] */
  { /*    94 */ PduRConf_PduRSrcPdu_PduRSrcPdu_d36fcffa       ,    0x0236u  /* DCT_FD4_oB30_for_SC_CAN_V3_2_737de028_Rx, only FD-PDU */                       ,   0x07FFu  /* DCT_FD4_oB30_for_SC_CAN_V3_2_737de028_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DCT_FD4_oB30_for_SC_CAN_V3_2_737de028_Rx, CanId: 0x236]                */  /* [CanIfConf_CanIfRxPduCfg_DCT_FD4_oB30_for_SC_CAN_V3_2_737de028_Rx] */
  { /*    95 */ PduRConf_PduRSrcPdu_PduRSrcPdu_ec961e65       ,    0x0231u  /* ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx, only FD-PDU */                          ,   0x07FFu  /* ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx, CanId: 0x231]                   */  /* [CanIfConf_CanIfRxPduCfg_ABS1_oB30_for_SC_CAN_V3_2_bd04049b_Rx] */
  { /*    96 */ PduRConf_PduRSrcPdu_PduRSrcPdu_eb545357       ,    0x0227u  /* AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx, only FD-PDU */                    ,   0x07FFu  /* AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx */                   , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx, CanId: 0x227]             */  /* [CanIfConf_CanIfRxPduCfg_AEB_FD2_Sc_oB30_for_SC_CAN_V3_2_d523569e_Rx] */
  { /*    97 */ PduRConf_PduRSrcPdu_PduRSrcPdu_d470f3a2       ,    0x0222u  /* IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx, only FD-PDU */                       ,   0x07FFu  /* IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx, CanId: 0x222]                */  /* [CanIfConf_CanIfRxPduCfg_IFC_FD6_oB30_for_SC_CAN_V3_2_2c9ef882_Rx] */
  { /*    98 */ PduRConf_PduRSrcPdu_PduRSrcPdu_57f99d13       ,    0x0221u  /* DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx, only FD-PDU */                          ,   0x07FFu  /* DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx, CanId: 0x221]                   */  /* [CanIfConf_CanIfRxPduCfg_DCT5_oB30_for_SC_CAN_V3_2_3a3a1203_Rx] */
  { /*    99 */ PduRConf_PduRSrcPdu_PduRSrcPdu_a92a2a41       ,    0x0201u  /* HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx, CanId: 0x201]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_HP5_oB30_for_SC_CAN_V3_2_107ed299_Rx] */
    /* Index    UpperPduId                                      RxPduCanId                                                                                      RxPduMask                                                                        IsCanNmRxPdu  IsDataChecksumRxPdu  RxIndicationFctListIdx                                RxPduDlc                              MsgType                         Comment                                                                                  Referable Keys */
  { /*   100 */ PduRConf_PduRSrcPdu_PduRSrcPdu_7abf872e       ,    0x01FEu  /* T_BOX_FD9_oB30_for_SC_CAN_V3_2_18c22ff6_Rx, only FD-PDU */                     ,   0x07FFu  /* T_BOX_FD9_oB30_for_SC_CAN_V3_2_18c22ff6_Rx */                    , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: T_BOX_FD9_oB30_for_SC_CAN_V3_2_18c22ff6_Rx, CanId: 0x1fe]              */  /* [CanIfConf_CanIfRxPduCfg_T_BOX_FD9_oB30_for_SC_CAN_V3_2_18c22ff6_Rx] */
  { /*   101 */ PduRConf_PduRSrcPdu_PduRSrcPdu_3bf59e98       ,    0x01FAu  /* BLE5_oB30_for_SC_CAN_V3_2_39f30a4c_Rx, only FD-PDU */                          ,   0x07FFu  /* BLE5_oB30_for_SC_CAN_V3_2_39f30a4c_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BLE5_oB30_for_SC_CAN_V3_2_39f30a4c_Rx, CanId: 0x1fa]                   */  /* [CanIfConf_CanIfRxPduCfg_BLE5_oB30_for_SC_CAN_V3_2_39f30a4c_Rx] */
  { /*   102 */ PduRConf_PduRSrcPdu_PduRSrcPdu_eef15a54       ,    0x01F2u  /* ETC4_oB30_for_SC_CAN_V3_2_dfa38f29_Rx, only FD-PDU */                          ,   0x07FFu  /* ETC4_oB30_for_SC_CAN_V3_2_dfa38f29_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ETC4_oB30_for_SC_CAN_V3_2_dfa38f29_Rx, CanId: 0x1f2]                   */  /* [CanIfConf_CanIfRxPduCfg_ETC4_oB30_for_SC_CAN_V3_2_dfa38f29_Rx] */
  { /*   103 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f70df294       ,    0x01F1u  /* ETC2_oB30_for_SC_CAN_V3_2_a29ccbe0_Rx, only FD-PDU */                          ,   0x07FFu  /* ETC2_oB30_for_SC_CAN_V3_2_a29ccbe0_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ETC2_oB30_for_SC_CAN_V3_2_a29ccbe0_Rx, CanId: 0x1f1]                   */  /* [CanIfConf_CanIfRxPduCfg_ETC2_oB30_for_SC_CAN_V3_2_a29ccbe0_Rx] */
  { /*   104 */ PduRConf_PduRSrcPdu_PduRSrcPdu_fe5d78f6       ,    0x01E3u  /* BMS_FD14_oB30_for_SC_CAN_V3_2_d6fdd23c_Rx, only FD-PDU */                      ,   0x07FFu  /* BMS_FD14_oB30_for_SC_CAN_V3_2_d6fdd23c_Rx */                     , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS_FD14_oB30_for_SC_CAN_V3_2_d6fdd23c_Rx, CanId: 0x1e3]               */  /* [CanIfConf_CanIfRxPduCfg_BMS_FD14_oB30_for_SC_CAN_V3_2_d6fdd23c_Rx] */
  { /*   105 */ PduRConf_PduRSrcPdu_PduRSrcPdu_fa951420       ,    0x01E2u  /* HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx, CanId: 0x1e2]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_HC8_oB30_for_SC_CAN_V3_2_21f69208_Rx] */
  { /*   106 */ PduRConf_PduRSrcPdu_PduRSrcPdu_096bddaf       ,    0x01E1u  /* T_BOX_FD4_oB30_for_SC_CAN_V3_2_4f1f2ee0_Rx, only FD-PDU */                     ,   0x07FFu  /* T_BOX_FD4_oB30_for_SC_CAN_V3_2_4f1f2ee0_Rx */                    , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: T_BOX_FD4_oB30_for_SC_CAN_V3_2_4f1f2ee0_Rx, CanId: 0x1e1]              */  /* [CanIfConf_CanIfRxPduCfg_T_BOX_FD4_oB30_for_SC_CAN_V3_2_4f1f2ee0_Rx] */
  { /*   107 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b60b7e4e       ,    0x01DFu  /* DOCK2_oB30_for_SC_CAN_V3_2_6e11d2c1_Rx, only FD-PDU */                         ,   0x07FFu  /* DOCK2_oB30_for_SC_CAN_V3_2_6e11d2c1_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DOCK2_oB30_for_SC_CAN_V3_2_6e11d2c1_Rx, CanId: 0x1df]                  */  /* [CanIfConf_CanIfRxPduCfg_DOCK2_oB30_for_SC_CAN_V3_2_6e11d2c1_Rx] */
  { /*   108 */ PduRConf_PduRSrcPdu_PduRSrcPdu_32aaa87e       ,    0x01D9u  /* GW_OTA_oB30_for_SC_CAN_V3_2_556bd38c_Rx, only FD-PDU */                        ,   0x07FFu  /* GW_OTA_oB30_for_SC_CAN_V3_2_556bd38c_Rx */                       , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: GW_OTA_oB30_for_SC_CAN_V3_2_556bd38c_Rx, CanId: 0x1d9]                 */  /* [CanIfConf_CanIfRxPduCfg_GW_OTA_oB30_for_SC_CAN_V3_2_556bd38c_Rx] */
  { /*   109 */ PduRConf_PduRSrcPdu_PduRSrcPdu_0dc46ad2       ,    0x01C0u  /* HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx, CanId: 0x1c0]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_PT8_oB30_for_SC_CAN_V3_2_104eb273_Rx] */
  { /*   110 */ PduRConf_PduRSrcPdu_PduRSrcPdu_083bbb40       ,    0x019Fu  /* IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx, only FD-PDU */                       ,   0x07FFu  /* IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx, CanId: 0x19f]                */  /* [CanIfConf_CanIfRxPduCfg_IFC_FD5_oB30_for_SC_CAN_V3_2_f9248391_Rx] */
  { /*   111 */ PduRConf_PduRSrcPdu_PduRSrcPdu_6da5275e       ,    0x019Cu  /* R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_89d7921d_Rx, only FD-PDU */                    ,   0x07FFu  /* R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_89d7921d_Rx */                   , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_89d7921d_Rx, CanId: 0x19c]             */  /* [CanIfConf_CanIfRxPduCfg_R_PBOX1_Sc_oB30_for_SC_CAN_V3_2_89d7921d_Rx] */
  { /*   112 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b00d5adc       ,    0x019Bu  /* F_PBOX1_oB30_for_SC_CAN_V3_2_0d3fde0d_Rx, only FD-PDU */                       ,   0x07FFu  /* F_PBOX1_oB30_for_SC_CAN_V3_2_0d3fde0d_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: F_PBOX1_oB30_for_SC_CAN_V3_2_0d3fde0d_Rx, CanId: 0x19b]                */  /* [CanIfConf_CanIfRxPduCfg_F_PBOX1_oB30_for_SC_CAN_V3_2_0d3fde0d_Rx] */
  { /*   113 */ PduRConf_PduRSrcPdu_PduRSrcPdu_c16dc352       ,    0x018Bu  /* AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx, only FD-PDU */                       ,   0x07FFu  /* AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx, CanId: 0x18b]                */  /* [CanIfConf_CanIfRxPduCfg_AEB_FD1_oB30_for_SC_CAN_V3_2_0e351c33_Rx] */
  { /*   114 */ PduRConf_PduRSrcPdu_PduRSrcPdu_97f4128e       ,    0x0170u  /* ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx, only FD-PDU */                          ,   0x07FFu  /* ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx, CanId: 0x170]                   */  /* [CanIfConf_CanIfRxPduCfg_ESP8_oB30_for_SC_CAN_V3_2_5e47e6f6_Rx] */
  { /*   115 */ PduRConf_PduRSrcPdu_PduRSrcPdu_7ec73d99       ,    0x016Fu  /* RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx, only FD-PDU */                      ,   0x07FFu  /* RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx */                     , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx, CanId: 0x16f]               */  /* [CanIfConf_CanIfRxPduCfg_RSDS_FD1_oB30_for_SC_CAN_V3_2_5521fc93_Rx] */
  { /*   116 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f0fd4aaa       ,    0x016Bu  /* EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx, only FD-PDU */                          ,   0x07FFu  /* EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx, CanId: 0x16b]                   */  /* [CanIfConf_CanIfRxPduCfg_EPB1_oB30_for_SC_CAN_V3_2_139493e2_Rx] */
  { /*   117 */ PduRConf_PduRSrcPdu_PduRSrcPdu_a4a64142       ,    0x0165u  /* CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx, only FD-PDU */                          ,   0x07FFu  /* CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx, CanId: 0x165]                   */  /* [CanIfConf_CanIfRxPduCfg_CSA1_oB30_for_SC_CAN_V3_2_068772bc_Rx] */
  { /*   118 */ PduRConf_PduRSrcPdu_PduRSrcPdu_8df8116a       ,    0x015Eu  /* CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx, only FD-PDU */                        ,   0x07FFu  /* CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx */                       , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx, CanId: 0x15e]                 */  /* [CanIfConf_CanIfRxPduCfg_CR_FD1_oB30_for_SC_CAN_V3_2_6ad188d2_Rx] */
  { /*   119 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2b821b4f       ,    0x015Bu  /* HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx, only FD-PDU */                       ,   0x07FFu  /* HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx, CanId: 0x15b]                */  /* [CanIfConf_CanIfRxPduCfg_HAP_FD1_oB30_for_SC_CAN_V3_2_4a3d5566_Rx] */
  { /*   120 */ PduRConf_PduRSrcPdu_PduRSrcPdu_d642fa01       ,    0x0152u  /* ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx, only FD-PDU */                          ,   0x07FFu  /* ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx, CanId: 0x152]                   */  /* [CanIfConf_CanIfRxPduCfg_ELD1_oB30_for_SC_CAN_V3_2_7fd898d6_Rx] */
  { /*   121 */ PduRConf_PduRSrcPdu_PduRSrcPdu_567eb873       ,    0x014Fu  /* BMS65_oB30_for_SC_CAN_V3_2_138d13ea_Rx, only FD-PDU */                         ,   0x07FFu  /* BMS65_oB30_for_SC_CAN_V3_2_138d13ea_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS65_oB30_for_SC_CAN_V3_2_138d13ea_Rx, CanId: 0x14f]                  */  /* [CanIfConf_CanIfRxPduCfg_BMS65_oB30_for_SC_CAN_V3_2_138d13ea_Rx] */
  { /*   122 */ PduRConf_PduRSrcPdu_PduRSrcPdu_178af415       ,    0x014Au  /* HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx, CanId: 0x14a]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_PT5_oB30_for_SC_CAN_V3_2_0a038673_Rx] */
  { /*   123 */ PduRConf_PduRSrcPdu_PduRSrcPdu_bbdca1bb       ,    0x0147u  /* EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx, only FD-PDU */                       ,   0x07FFu  /* EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx, CanId: 0x147]                */  /* [CanIfConf_CanIfRxPduCfg_EPS_FD1_oB30_for_SC_CAN_V3_2_12526eab_Rx] */
  { /*   124 */ PduRConf_PduRSrcPdu_PduRSrcPdu_84656837       ,    0x0137u  /* ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx, only FD-PDU */                    ,   0x07FFu  /* ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx */                   , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx, CanId: 0x137]             */  /* [CanIfConf_CanIfRxPduCfg_ESP_FD2_Sc_oB30_for_SC_CAN_V3_2_a182ac89_Rx] */
  { /*   125 */ PduRConf_PduRSrcPdu_PduRSrcPdu_3dbe82da       ,    0x012Du  /* EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_3b0df78d_Rx, only FD-PDU */                  ,   0x07FFu  /* EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_3b0df78d_Rx */                 , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_3b0df78d_Rx, CanId: 0x12d]           */  /* [CanIfConf_CanIfRxPduCfg_EBOOSTER_FD1_oB30_for_SC_CAN_V3_2_3b0df78d_Rx] */
  { /*   126 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b05d026c       ,    0x0120u  /* Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx, only FD-PDU */                  ,   0x07FFu  /* Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx */                 , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx, CanId: 0x120]           */  /* [CanIfConf_CanIfRxPduCfg_Ibooster_FD2_oB30_for_SC_CAN_V3_2_5cce1132_Rx] */
  { /*   127 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e4bf60e1       ,    0x011Au  /* HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx, CanId: 0x11a]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_HP6_oB30_for_SC_CAN_V3_2_c5c4a98a_Rx] */
  { /*   128 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e6e6b472       ,    0x0117u  /* ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx, only FD-PDU */                       ,   0x07FFu  /* ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx, CanId: 0x117]                */  /* [CanIfConf_CanIfRxPduCfg_ECM_PT7_oB30_for_SC_CAN_V3_2_f08d75e2_Rx] */
  { /*   129 */ PduRConf_PduRSrcPdu_PduRSrcPdu_1a24f822       ,    0x0111u  /* ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx, only FD-PDU */                          ,   0x07FFu  /* ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx, CanId: 0x111]                   */  /* [CanIfConf_CanIfRxPduCfg_ECM1_oB30_for_SC_CAN_V3_2_fdeb93d5_Rx] */
  { /*   130 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2f545f03       ,    0x0109u  /* IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx, only FD-PDU */                          ,   0x07FFu  /* IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx, CanId: 0x109]                   */  /* [CanIfConf_CanIfRxPduCfg_IFC1_oB30_for_SC_CAN_V3_2_1b1d10af_Rx] */
  { /*   131 */ PduRConf_PduRSrcPdu_PduRSrcPdu_3d5474ec       ,    0x0102u  /* ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx, only FD-PDU */                          ,   0x07FFu  /* ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx, CanId: 0x102]                   */  /* [CanIfConf_CanIfRxPduCfg_ECM9_oB30_for_SC_CAN_V3_2_51bf62c9_Rx] */
  { /*   132 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b4401e79       ,    0x00F9u  /* HCU_HP8_oB30_for_SC_CAN_V3_2_0a33e699_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_HP8_oB30_for_SC_CAN_V3_2_0a33e699_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HP8_oB30_for_SC_CAN_V3_2_0a33e699_Rx, CanId: 0xf9]                 */  /* [CanIfConf_CanIfRxPduCfg_HCU_HP8_oB30_for_SC_CAN_V3_2_0a33e699_Rx] */
  { /*   133 */ PduRConf_PduRSrcPdu_PduRSrcPdu_60681d02       ,    0x00F1u  /* BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx, only FD-PDU */                          ,   0x07FFu  /* BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx, CanId: 0xf1]                    */  /* [CanIfConf_CanIfRxPduCfg_BMS4_oB30_for_SC_CAN_V3_2_4275844b_Rx] */
  { /*   134 */ PduRConf_PduRSrcPdu_PduRSrcPdu_e7765f6f       ,    0x00C8u  /* ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx, only FD-PDU */                         ,   0x07FFu  /* ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx */                        , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx, CanId: 0xc8]                   */  /* [CanIfConf_CanIfRxPduCfg_ESP11_oB30_for_SC_CAN_V3_2_e67254f2_Rx] */
  { /*   135 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b5841b10       ,    0x00BEu  /* P2M3_oB30_for_SC_CAN_V3_2_c252eb72_Rx, only FD-PDU */                          ,   0x07FFu  /* P2M3_oB30_for_SC_CAN_V3_2_c252eb72_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: P2M3_oB30_for_SC_CAN_V3_2_c252eb72_Rx, CanId: 0xbe]                    */  /* [CanIfConf_CanIfRxPduCfg_P2M3_oB30_for_SC_CAN_V3_2_c252eb72_Rx] */
  { /*   136 */ PduRConf_PduRSrcPdu_PduRSrcPdu_27578a55       ,    0x00ACu  /* P2M1_oB30_for_SC_CAN_V3_2_e947d735_Rx, only FD-PDU */                          ,   0x07FFu  /* P2M1_oB30_for_SC_CAN_V3_2_e947d735_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: P2M1_oB30_for_SC_CAN_V3_2_e947d735_Rx, CanId: 0xac]                    */  /* [CanIfConf_CanIfRxPduCfg_P2M1_oB30_for_SC_CAN_V3_2_e947d735_Rx] */
  { /*   137 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2768582c       ,    0x00A6u  /* DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx, only FD-PDU */                          ,   0x07FFu  /* DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx, CanId: 0xa6]                    */  /* [CanIfConf_CanIfRxPduCfg_DCT3_oB30_for_SC_CAN_V3_2_470556ca_Rx] */
  { /*   138 */ PduRConf_PduRSrcPdu_PduRSrcPdu_cca3ad41       ,    0x00A1u  /* CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx, only FD-PDU */                          ,   0x07FFu  /* CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx, CanId: 0xa1]                    */  /* [CanIfConf_CanIfRxPduCfg_CSA2_oB30_for_SC_CAN_V3_2_d5a053f8_Rx] */
  { /*   139 */ PduRConf_PduRSrcPdu_PduRSrcPdu_2b350323       ,    0x009Eu  /* HCU_HC16_oB30_for_SC_CAN_V3_2_1bcddd39_Rx, only FD-PDU */                      ,   0x07FFu  /* HCU_HC16_oB30_for_SC_CAN_V3_2_1bcddd39_Rx */                     , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_HC16_oB30_for_SC_CAN_V3_2_1bcddd39_Rx, CanId: 0x9e]                */  /* [CanIfConf_CanIfRxPduCfg_HCU_HC16_oB30_for_SC_CAN_V3_2_1bcddd39_Rx] */
  { /*   140 */ PduRConf_PduRSrcPdu_PduRSrcPdu_504d8e4d       ,    0x008Eu  /* ECM_PT5_oB30_for_SC_CAN_V3_2_df71da3f_Rx, only FD-PDU */                       ,   0x07FFu  /* ECM_PT5_oB30_for_SC_CAN_V3_2_df71da3f_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM_PT5_oB30_for_SC_CAN_V3_2_df71da3f_Rx, CanId: 0x8e]                 */  /* [CanIfConf_CanIfRxPduCfg_ECM_PT5_oB30_for_SC_CAN_V3_2_df71da3f_Rx] */
  { /*   141 */ PduRConf_PduRSrcPdu_PduRSrcPdu_c2625a73       ,    0x0084u  /* ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx, only FD-PDU */                          ,   0x07FFu  /* ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx, CanId: 0x84]                    */  /* [CanIfConf_CanIfRxPduCfg_ECM7_oB30_for_SC_CAN_V3_2_80d4d71c_Rx] */
  { /*   142 */ PduRConf_PduRSrcPdu_PduRSrcPdu_b939ffb6       ,    0x0082u  /* ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx, only FD-PDU */                          ,   0x07FFu  /* ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx */                         , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx, CanId: 0x82]                    */  /* [CanIfConf_CanIfRxPduCfg_ECM4_oB30_for_SC_CAN_V3_2_53f3f658_Rx] */
  { /*   143 */ PduRConf_PduRSrcPdu_PduRSrcPdu_41111e75       ,    0x0060u  /* HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx, only FD-PDU */                       ,   0x07FFu  /* HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx */                      , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      64u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx, CanId: 0x60]                 */  /* [CanIfConf_CanIfRxPduCfg_HCU_FD1_oB30_for_SC_CAN_V3_2_4c4e73be_Rx] */
  { /*   144 */ PduRConf_PduRSrcPdu_PduRSrcPdu_49fe1e9a       ,    0x0056u  /* GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx, only FD-PDU */                     ,   0x07FFu  /* GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx */                    , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,       8u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx, CanId: 0x56]               */  /* [CanIfConf_CanIfRxPduCfg_GLO_NASS1_oB30_for_SC_CAN_V3_2_cd0fc4aa_Rx] */
  { /*   145 */ PduRConf_PduRSrcPdu_PduRSrcPdu_8bd0b3d2       ,    0x0033u  /* T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_52ff33bb_Rx, only FD-PDU */                  ,   0x07FFu  /* T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_52ff33bb_Rx */                 , FALSE       , TRUE               ,                     3u  /* PduR_CanIfRxIndication */,      16u  /* DLC-Check is enabled */, CANIF_MSG_TYPE_FD_CAN    }   /* [PDU: T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_52ff33bb_Rx, CanId: 0x33]            */  /* [CanIfConf_CanIfRxPduCfg_T_BOX_FD1_Sc_oB30_for_SC_CAN_V3_2_52ff33bb_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TrcvModeIndicationFctType, CANIF_CONST) CanIf_TrcvModeIndicationFctPtr = CanSM_TransceiverModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvToCtrlMap
**********************************************************************************************************************/
/** 
  \var    CanIf_TrcvToCtrlMap
  \brief  Indirection table: logical transceiver index to CAN controller index.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TrcvToCtrlMapType, CANIF_CONST) CanIf_TrcvToCtrlMap[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TrcvToCtrlMap                                          */
  /*     0 */             1u  /* CAN controller handle ID (upper) */,
  /*     1 */             2u  /* CAN controller handle ID (upper) */,
  /*     2 */             0u  /* CAN controller handle ID (upper) */
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxBufferPrioByCanIdBaseIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                            Referable Keys */
  { /*     0 */                         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143 */,                                            38u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143 */,                                            38u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143 */,                                               0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143 */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[38] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduConfigIdx                                                                                                  Referable Keys */
  { /*     0 */             0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     1 */             1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx */    },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     2 */             2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx */                         },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     3 */             3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx */                         },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     4 */             4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx */                         },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     5 */             5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx */                         },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     6 */             6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx */                         },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     7 */             7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx */             },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     8 */             8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx */       },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*     9 */             9u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx */               },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    10 */            10u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx */               },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    11 */            11u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx */               },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    12 */            12u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx */               },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    13 */            13u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    14 */            14u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    15 */            15u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    16 */            16u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    17 */            17u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    18 */            18u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    19 */            19u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    20 */            20u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    21 */            21u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    22 */            22u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    23 */            23u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx */           },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    24 */            24u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    25 */            25u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    26 */            26u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    27 */            27u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    28 */            28u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    29 */            29u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    30 */            30u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    31 */            31u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    32 */            32u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    33 */            33u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx */            },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    34 */            34u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx */            },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    35 */            35u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx */              },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    36 */            36u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx */               },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
  { /*    37 */            37u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx */               }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanNm_TxConfirmation                  ,  /* [CanNm_TxConfirmation] */
  /*     2 */ CanTp_TxConfirmation                  ,  /* [CanTp_TxConfirmation] */
  /*     3 */ PduR_CanIfTxConfirmation                 /* [PduR_CanIfTxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CanId                       CAN identifier (16bit / 32bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[56] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UpperLayerTxPduId                                                   CanId    IsTxPduTruncation  CtrlStatesIdx                                                                                    MailBoxConfigIdx                                                                                                    TxConfirmationFctListIdx                                  TxPduLength        Comment                                                                Referable Keys */
  { /*     0 */ CanTpConf_CanTpTxNPdu_CanTpTxNPdu_2185859a                        , 0x07B3u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */
  { /*     1 */ CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_a46f9c70                    , 0x47B3u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx] */
  { /*     2 */ PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AF_Tx              , 0x47AFu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: ZCluster_Debug_Msg_0x7AF_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx] */
  { /*     3 */ PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AE_Tx              , 0x47AEu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: ZCluster_Debug_Msg_0x7AE_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx] */
  { /*     4 */ PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AD_Tx              , 0x47ADu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: ZCluster_Debug_Msg_0x7AD_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx] */
  { /*     5 */ PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AC_Tx              , 0x47ACu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: ZCluster_Debug_Msg_0x7AC_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx] */
  { /*     6 */ PduRConf_PduRDestPdu_DST_ZCluster_Debug_Msg_0x7AB_Tx              , 0x47ABu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: ZCluster_Debug_Msg_0x7AB_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx] */
  { /*     7 */ CanNmConf_CanNmTxPdu_HUT_NM_oB30_tx                               , 0x0509u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       1u  /* CanNm_TxConfirmation */    ,          8u },  /* [PDU: HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx]             */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx] */
  { /*     8 */ PduRConf_PduRDestPdu_HUT_Sync_Req_oB30_for_SC_CAN_V3_2_850087bd_Tx, 0x4462u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         16u },  /* [PDU: HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx] */
  { /*     9 */ PduRConf_PduRDestPdu_HUT4_oB30_for_SC_CAN_V3_2_1dca0563_Tx        , 0x436Du, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx] */
  { /*    10 */ PduRConf_PduRDestPdu_HUT3_oB30_for_SC_CAN_V3_2_06e1d559_Tx        , 0x436Bu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx] */
  { /*    11 */ PduRConf_PduRDestPdu_HUT2_oB30_for_SC_CAN_V3_2_ccdf26ca_Tx        , 0x4369u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx] */
  { /*    12 */ PduRConf_PduRDestPdu_HUT1_oB30_for_SC_CAN_V3_2_49ed343e_Tx        , 0x4367u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx] */
  { /*    13 */ PduRConf_PduRDestPdu_HUT17_oB30_for_SC_CAN_V3_2_4a1d7d30_Tx       , 0x433Bu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx] */
  { /*    14 */ PduRConf_PduRDestPdu_HUT25_oB30_for_SC_CAN_V3_2_bf449840_Tx       , 0x4339u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx] */
  { /*    15 */ PduRConf_PduRDestPdu_HUT10_oB30_for_SC_CAN_V3_2_5136ad0a_Tx       , 0x4331u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx] */
  { /*    16 */ PduRConf_PduRDestPdu_HUT20_oB30_for_SC_CAN_V3_2_eb63a91d_Tx       , 0x42DEu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx] */
  { /*    17 */ PduRConf_PduRDestPdu_HUT21_oB30_for_SC_CAN_V3_2_215d5a8e_Tx       , 0x42DDu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx] */
  { /*    18 */ PduRConf_PduRDestPdu_HUT22_oB30_for_SC_CAN_V3_2_a46f487a_Tx       , 0x42DAu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx] */
  { /*    19 */ PduRConf_PduRDestPdu_HUT23_oB30_for_SC_CAN_V3_2_6e51bbe9_Tx       , 0x42D8u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx] */
  { /*    20 */ PduRConf_PduRDestPdu_HUT43_oB30_for_SC_CAN_V3_2_c18ab586_Tx       , 0x41FDu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx] */
  { /*    21 */ PduRConf_PduRDestPdu_HUT41_oB30_for_SC_CAN_V3_2_8e8654e1_Tx       , 0x41FBu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx] */
  { /*    22 */ PduRConf_PduRDestPdu_HUT42_oB30_for_SC_CAN_V3_2_0bb44615_Tx       , 0x41F9u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx] */
  { /*    23 */ PduRConf_PduRDestPdu_HUT15_Sc_oB30_for_SC_CAN_V3_2_03f030a3_Tx    , 0x41EEu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         16u },  /* [PDU: HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx] */
  { /*    24 */ PduRConf_PduRDestPdu_HUT33_oB30_for_SC_CAN_V3_2_079d47e4_Tx       , 0x41EDu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx] */
  { /*    25 */ PduRConf_PduRDestPdu_HUT37_oB30_for_SC_CAN_V3_2_9984852a_Tx       , 0x41ECu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx] */
  { /*    26 */ PduRConf_PduRDestPdu_HUT39_oB30_for_SC_CAN_V3_2_afd3255e_Tx       , 0x41EBu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx] */
  { /*    27 */ PduRConf_PduRDestPdu_HUT30_oB30_for_SC_CAN_V3_2_82af5510_Tx       , 0x41E9u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx] */
  { /*    28 */ PduRConf_PduRDestPdu_HUT38_oB30_for_SC_CAN_V3_2_65edd6cd_Tx       , 0x41E7u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx] */
  { /*    29 */ PduRConf_PduRDestPdu_HUT36_oB30_for_SC_CAN_V3_2_53ba76b9_Tx       , 0x41E6u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx] */
  { /*    30 */ PduRConf_PduRDestPdu_HUT35_oB30_for_SC_CAN_V3_2_d688644d_Tx       , 0x41E5u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx] */
  { /*    31 */ PduRConf_PduRDestPdu_HUT46_oB30_for_SC_CAN_V3_2_95ad84db_Tx       , 0x41DDu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx] */
  { /*    32 */ PduRConf_PduRDestPdu_HUT45_oB30_for_SC_CAN_V3_2_109f962f_Tx       , 0x41DCu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx] */
  { /*    33 */ PduRConf_PduRDestPdu_HUT_FD5_oB30_for_SC_CAN_V3_2_02e08044_Tx     , 0x41DBu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx] */
  { /*    34 */ PduRConf_PduRDestPdu_HUT_FD4_oB30_for_SC_CAN_V3_2_c8de73d7_Tx     , 0x41DAu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx] */
  { /*    35 */ PduRConf_PduRDestPdu_HUT49_oB30_for_SC_CAN_V3_2_69c4d73c_Tx       , 0x41D1u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx] */
  { /*    36 */ PduRConf_PduRDestPdu_HUT6_oB30_for_SC_CAN_V3_2_52c6e404_Tx        , 0x404Au, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx] */
  { /*    37 */ PduRConf_PduRDestPdu_HUT7_oB30_for_SC_CAN_V3_2_98f81797_Tx        , 0x4044u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              18u  /* /ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx */                           ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx] */
  { /*    38 */ PduRConf_PduRDestPdu_HUT19_oB30_for_SC_CAN_V3_2_7c4add44_Tx       , 0x4415u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              17u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx] */
  { /*    39 */ PduRConf_PduRDestPdu_HUT12_oB30_for_SC_CAN_V3_2_1e3a4c6d_Tx       , 0x43AFu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              16u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx] */
  { /*    40 */ PduRConf_PduRDestPdu_HUT34_oB30_for_SC_CAN_V3_2_1cb697de_Tx       , 0x4370u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              15u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx] */
  { /*    41 */ PduRConf_PduRDestPdu_IP3_oB30_for_SC_CAN_V3_2_ad470001_Tx         , 0x434Au, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              14u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx */       ,                       3u  /* PduR_CanIfTxConfirmation */,         16u },  /* [PDU: IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx] */
  { /*    42 */ PduRConf_PduRDestPdu_HUT16_oB30_for_SC_CAN_V3_2_80238ea3_Tx       , 0x4348u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              13u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx] */
  { /*    43 */ PduRConf_PduRDestPdu_HUT13_oB30_for_SC_CAN_V3_2_d404bffe_Tx       , 0x431Cu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              12u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx] */
  { /*    44 */ PduRConf_PduRDestPdu_HUT31_oB30_for_SC_CAN_V3_2_4891a683_Tx       , 0x430Cu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              11u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx] */
  { /*    45 */ PduRConf_PduRDestPdu_DVR_FD1_oB30_for_SC_CAN_V3_2_d1b20623_Tx     , 0x42ECu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,              10u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx */   ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx] */
  { /*    46 */ PduRConf_PduRDestPdu_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_37cb1482_Tx  , 0x42C3u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               9u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx */,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx] */
  { /*    47 */ PduRConf_PduRDestPdu_HUT26_oB30_for_SC_CAN_V3_2_3a768ab4_Tx       , 0x42B6u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               8u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx] */
  { /*    48 */ PduRConf_PduRDestPdu_HUT27_oB30_for_SC_CAN_V3_2_f0487927_Tx       , 0x42B2u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               7u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx] */
  { /*    49 */ PduRConf_PduRDestPdu_IP1_oB30_for_SC_CAN_V3_2_e24be166_Tx         , 0x4293u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               6u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx */       ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx] */
    /* Index    UpperLayerTxPduId                                                   CanId    IsTxPduTruncation  CtrlStatesIdx                                                                                    MailBoxConfigIdx                                                                                                    TxConfirmationFctListIdx                                  TxPduLength        Comment                                                                Referable Keys */
  { /*    50 */ PduRConf_PduRDestPdu_IP2_Sc_oB30_for_SC_CAN_V3_2_3598fa68_Tx      , 0x427Fu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               5u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx */    ,                       3u  /* PduR_CanIfTxConfirmation */,         16u },  /* [PDU: IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx]             */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx] */
  { /*    51 */ PduRConf_PduRDestPdu_HUT32_oB30_for_SC_CAN_V3_2_cda3b477_Tx       , 0x426Fu, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               4u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx] */
  { /*    52 */ PduRConf_PduRDestPdu_DMS_FD1_oB30_for_SC_CAN_V3_2_3b8624c3_Tx     , 0x424Du, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               3u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx */   ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx] */
  { /*    53 */ PduRConf_PduRDestPdu_HUT_FD3_oB30_for_SC_CAN_V3_2_d3f5a3ed_Tx     , 0x4243u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               2u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx */   ,                       3u  /* PduR_CanIfTxConfirmation */,         64u },  /* [PDU: HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx] */
  { /*    54 */ PduRConf_PduRDestPdu_HUT40_oB30_for_SC_CAN_V3_2_44b8a772_Tx       , 0x4224u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               1u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx */     ,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx] */
  { /*    55 */ PduRConf_PduRDestPdu_HUT_FD2_oB30_for_SC_CAN_V3_2_19cb507e_Tx     , 0x4203u, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c */,               0u  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx */   ,                       3u  /* PduR_CanIfTxConfirmation */,         64u }   /* [PDU: HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element                          Description
  TxQueueIdx                       the index of the 0:1 relation pointing to CanIf_TxQueue
  TxQueueIndex2DataStartStopIdx    the index of the 0:1 relation pointing to CanIf_TxQueueIndex2DataStartStop
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[56] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueueIdx                                                                                                                      TxQueueIndex2DataStartStopIdx                                                                                                                            Comment                                                                                          Referable Keys */
  { /*     0 */                                   0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx */,                                                      0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx */ },  /* [HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     1 */                                   1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx */   ,                                                      1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx */    },  /* [HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx, BasicCAN TxPdu with Tx-buffer]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     2 */                                   2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx */                        ,                                                      2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx */                         },  /* [ZCluster_Debug_Msg_0x7AF_Tx, BasicCAN TxPdu with Tx-buffer]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     3 */                                   3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx */                        ,                                                      3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx */                         },  /* [ZCluster_Debug_Msg_0x7AE_Tx, BasicCAN TxPdu with Tx-buffer]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     4 */                                   4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx */                        ,                                                      4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx */                         },  /* [ZCluster_Debug_Msg_0x7AD_Tx, BasicCAN TxPdu with Tx-buffer]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     5 */                                   5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx */                        ,                                                      5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx */                         },  /* [ZCluster_Debug_Msg_0x7AC_Tx, BasicCAN TxPdu with Tx-buffer]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     6 */                                   6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx */                        ,                                                      6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx */                         },  /* [ZCluster_Debug_Msg_0x7AB_Tx, BasicCAN TxPdu with Tx-buffer]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     7 */                                   7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx */            ,                                                      7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx */             },  /* [HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx, BasicCAN TxPdu with Tx-buffer]             */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     8 */                                   8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx */      ,                                                      8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx */       },  /* [HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx, BasicCAN TxPdu with Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     9 */                                   9u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx */              ,                                                      9u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx */               },  /* [HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx, BasicCAN TxPdu with Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    10 */                                  10u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx */              ,                                                     10u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx */               },  /* [HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx, BasicCAN TxPdu with Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    11 */                                  11u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx */              ,                                                     11u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx */               },  /* [HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx, BasicCAN TxPdu with Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    12 */                                  12u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx */              ,                                                     12u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx */               },  /* [HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx, BasicCAN TxPdu with Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    13 */                                  13u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx */             ,                                                     13u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx */              },  /* [HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    14 */                                  14u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx */             ,                                                     14u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx */              },  /* [HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    15 */                                  15u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx */             ,                                                     15u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx */              },  /* [HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    16 */                                  16u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx */             ,                                                     16u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx */              },  /* [HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    17 */                                  17u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx */             ,                                                     17u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx */              },  /* [HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    18 */                                  18u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx */             ,                                                     18u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx */              },  /* [HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    19 */                                  19u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx */             ,                                                     19u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx */              },  /* [HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    20 */                                  20u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx */             ,                                                     20u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx */              },  /* [HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    21 */                                  21u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx */             ,                                                     21u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx */              },  /* [HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    22 */                                  22u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx */             ,                                                     22u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx */              },  /* [HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    23 */                                  23u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx */          ,                                                     23u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx */           },  /* [HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx, BasicCAN TxPdu with Tx-buffer]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    24 */                                  24u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx */             ,                                                     24u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx */              },  /* [HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    25 */                                  25u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx */             ,                                                     25u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx */              },  /* [HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    26 */                                  26u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx */             ,                                                     26u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx */              },  /* [HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    27 */                                  27u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx */             ,                                                     27u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx */              },  /* [HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    28 */                                  28u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx */             ,                                                     28u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx */              },  /* [HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    29 */                                  29u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx */             ,                                                     29u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx */              },  /* [HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    30 */                                  30u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx */             ,                                                     30u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx */              },  /* [HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    31 */                                  31u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx */             ,                                                     31u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx */              },  /* [HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    32 */                                  32u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx */             ,                                                     32u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx */              },  /* [HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    33 */                                  33u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx */           ,                                                     33u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx */            },  /* [HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx, BasicCAN TxPdu with Tx-buffer]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    34 */                                  34u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx */           ,                                                     34u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx */            },  /* [HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx, BasicCAN TxPdu with Tx-buffer]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    35 */                                  35u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx */             ,                                                     35u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx */              },  /* [HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    36 */                                  36u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx */              ,                                                     36u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx */               },  /* [HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx, BasicCAN TxPdu with Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    37 */                                  37u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx */              ,                                                     37u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx */               },  /* [HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx, BasicCAN TxPdu with Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*    38 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx */              },  /* [HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx] */
  { /*    39 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx */              },  /* [HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx] */
  { /*    40 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx */              },  /* [HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx] */
  { /*    41 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx */               , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx */                },  /* [IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx, FullCAN TxPdu NO Tx-buffer]                   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx] */
  { /*    42 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx */              },  /* [HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx] */
  { /*    43 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx */              },  /* [HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx] */
  { /*    44 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx */              },  /* [HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx] */
  { /*    45 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx */           , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx */            },  /* [DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx, FullCAN TxPdu NO Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx] */
  { /*    46 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx */        , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx */         },  /* [HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx, FullCAN TxPdu NO Tx-buffer]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx] */
  { /*    47 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx */              },  /* [HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx] */
  { /*    48 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx */              },  /* [HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx] */
  { /*    49 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx */               , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx */                },  /* [IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx, FullCAN TxPdu NO Tx-buffer]                   */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx] */
    /* Index    TxQueueIdx                                                                                                                      TxQueueIndex2DataStartStopIdx                                                                                                                            Comment                                                                                          Referable Keys */
  { /*    50 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx */            , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx */             },  /* [IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx, FullCAN TxPdu NO Tx-buffer]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx] */
  { /*    51 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx */              },  /* [HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx] */
  { /*    52 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx */           , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx */            },  /* [DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx, FullCAN TxPdu NO Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx] */
  { /*    53 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx */           , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx */            },  /* [HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx, FullCAN TxPdu NO Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx] */
  { /*    54 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx */             , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx */              },  /* [HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx, FullCAN TxPdu NO Tx-buffer]                 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx] */
  { /*    55 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx */           , CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx */            }   /* [HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx, FullCAN TxPdu NO Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueIndex2DataStartStop
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueIndex2DataStartStop
  \details
  Element                Description
  TxQueueDataEndIdx      the end index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataStartIdx    the start index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataLength      the number of relations pointing to CanIf_TxQueueData
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxQueueIndex2DataStartStopType, CANIF_CONST) CanIf_TxQueueIndex2DataStartStop[38] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueueDataEndIdx                                                                                            TxQueueDataStartIdx                                                                                            TxQueueDataLength                                                                                                  Comment                                                                   Referable Keys */
  { /*     0 */                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx */,                  0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx */,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx */ },  /* [Tx-PDU: HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */
  { /*     1 */               16u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx */   ,                  8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx */   ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx */    },  /* [Tx-PDU: HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx] */
  { /*     2 */               80u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx */                        ,                 16u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx */                        ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx */                         },  /* [Tx-PDU: ZCluster_Debug_Msg_0x7AF_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx] */
  { /*     3 */              144u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx */                        ,                 80u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx */                        ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx */                         },  /* [Tx-PDU: ZCluster_Debug_Msg_0x7AE_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx] */
  { /*     4 */              208u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx */                        ,                144u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx */                        ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx */                         },  /* [Tx-PDU: ZCluster_Debug_Msg_0x7AD_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx] */
  { /*     5 */              272u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx */                        ,                208u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx */                        ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx */                         },  /* [Tx-PDU: ZCluster_Debug_Msg_0x7AC_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx] */
  { /*     6 */              336u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx */                        ,                272u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx */                        ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx */                         },  /* [Tx-PDU: ZCluster_Debug_Msg_0x7AB_Tx]                         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx] */
  { /*     7 */              344u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx */            ,                336u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx */            ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx */             },  /* [Tx-PDU: HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx]             */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx] */
  { /*     8 */              360u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx */      ,                344u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx */      ,               16u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx */       },  /* [Tx-PDU: HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx] */
  { /*     9 */              368u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx */              ,                360u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx */              ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx */               },  /* [Tx-PDU: HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx] */
  { /*    10 */              376u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx */              ,                368u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx */              ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx */               },  /* [Tx-PDU: HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx] */
  { /*    11 */              384u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx */              ,                376u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx */              ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx */               },  /* [Tx-PDU: HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx] */
  { /*    12 */              392u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx */              ,                384u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx */              ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx */               },  /* [Tx-PDU: HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx] */
  { /*    13 */              400u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx */             ,                392u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx */              },  /* [Tx-PDU: HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx] */
  { /*    14 */              408u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx */             ,                400u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx */              },  /* [Tx-PDU: HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx] */
  { /*    15 */              416u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx */             ,                408u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx */              },  /* [Tx-PDU: HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx] */
  { /*    16 */              424u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx */             ,                416u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx */              },  /* [Tx-PDU: HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx] */
  { /*    17 */              432u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx */             ,                424u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx */              },  /* [Tx-PDU: HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx] */
  { /*    18 */              440u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx */             ,                432u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx */              },  /* [Tx-PDU: HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx] */
  { /*    19 */              448u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx */             ,                440u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx */              },  /* [Tx-PDU: HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx] */
  { /*    20 */              456u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx */             ,                448u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx */              },  /* [Tx-PDU: HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx] */
  { /*    21 */              464u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx */             ,                456u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx */              },  /* [Tx-PDU: HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx] */
  { /*    22 */              472u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx */             ,                464u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx */              },  /* [Tx-PDU: HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx] */
  { /*    23 */              488u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx */          ,                472u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx */          ,               16u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx */           },  /* [Tx-PDU: HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx] */
  { /*    24 */              496u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx */             ,                488u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx */              },  /* [Tx-PDU: HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx] */
  { /*    25 */              504u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx */             ,                496u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx */              },  /* [Tx-PDU: HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx] */
  { /*    26 */              512u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx */             ,                504u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx */              },  /* [Tx-PDU: HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx] */
  { /*    27 */              520u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx */             ,                512u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx */              },  /* [Tx-PDU: HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx] */
  { /*    28 */              528u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx */             ,                520u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx */              },  /* [Tx-PDU: HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx] */
  { /*    29 */              536u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx */             ,                528u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx */              },  /* [Tx-PDU: HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx] */
  { /*    30 */              544u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx */             ,                536u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx */              },  /* [Tx-PDU: HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx] */
  { /*    31 */              552u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx */             ,                544u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx */              },  /* [Tx-PDU: HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx] */
  { /*    32 */              560u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx */             ,                552u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx */              },  /* [Tx-PDU: HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx] */
  { /*    33 */              624u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx */           ,                560u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx */           ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx */            },  /* [Tx-PDU: HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx] */
  { /*    34 */              688u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx */           ,                624u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx */           ,               64u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx */            },  /* [Tx-PDU: HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx]            */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx] */
  { /*    35 */              696u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx */             ,                688u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx */             ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx */              },  /* [Tx-PDU: HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx] */
  { /*    36 */              704u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx */              ,                696u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx */              ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx */               },  /* [Tx-PDU: HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx] */
  { /*    37 */              712u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx */              ,                704u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx */              ,                8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx */               }   /* [Tx-PDU: HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  Controller             CAN controller handle ID
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Logical handle ID of target (CAN controller / transceiver)
  WakeUpTargetModule     Target for wake-up source: CAN controller / transceiver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Controller  WakeUpSource  WakeUpTargetAddress  WakeUpTargetModule              Comment */
  { /*     0 */         0u,          32u,                  0u, CANIF_WAKEUPREQUEST_CAN  },
  { /*     1 */         0u,          32u,                  2u, CANIF_WAKEUPREQUEST_TRCV }   /* [Only CanTrcvWakeupSource ] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpValidationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpValidationFctType, CANIF_CONST) CanIf_WakeUpValidationFctPtr = EcuM_ValidateWakeupEvent;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element                  Description
  CtrlMode                 Controller mode.
  PduMode                  PDU mode state.
  WakeUpValidationState    Wake-up validation state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_b4130143] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx] */
  /*     8 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx] */
  /*     9 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx] */
  /*    10 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx] */
  /*    11 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx] */
  /*    12 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx] */
  /*    13 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx] */
  /*    14 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx] */
  /*    15 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx] */
  /*    16 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx] */
  /*    17 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx] */
  /*    18 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx] */
  /*    19 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx] */
  /*    20 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx] */
  /*    21 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx] */
  /*    22 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx] */
  /*    23 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx] */
  /*    24 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx] */
  /*    25 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx] */
  /*    26 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx] */
  /*    27 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx] */
  /*    28 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx] */
  /*    29 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx] */
  /*    30 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx] */
  /*    31 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx] */
  /*    32 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx] */
  /*    33 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx] */
  /*    34 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx] */
  /*    35 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx] */
  /*    36 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx] */
  /*    37 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueData
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueData
  \brief  Variable declaration - Tx queue data.
*/ 
#define CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueDataUType, CANIF_VAR_NOINIT_FAST) CanIf_TxQueueData;  /* PRQA S 0759, 1514, 1533, 0612 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_20_228bf6a1_Tx] */
  /*     8 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx] */
  /*    15 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Phy_Resp_Tp_oB30_for_SC_CAN_V3_2_36a91054_Tx] */
  /*    16 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx] */
  /*    79 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AF_Tx] */
  /*    80 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx] */
  /*   143 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AE_Tx] */
  /*   144 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx] */
  /*   207 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AD_Tx] */
  /*   208 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx] */
  /*   271 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AC_Tx] */
  /*   272 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx] */
  /*   335 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ZCluster_Debug_Msg_0x7AB_Tx] */
  /*   336 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx] */
  /*   343 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_NM_oB30_for_SC_CAN_V3_2_5ab58849_Tx] */
  /*   344 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx] */
  /*   359 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_Sync_Req_oB30_for_SC_CAN_V3_2_67456da2_Tx] */
  /*   360 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx] */
  /*   367 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT4_oB30_for_SC_CAN_V3_2_5370efea_Tx] */
  /*   368 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx] */
  /*   375 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT3_oB30_for_SC_CAN_V3_2_d67db620_Tx] */
  /*   376 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx] */
  /*   383 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT2_oB30_for_SC_CAN_V3_2_2e4fab23_Tx] */
  /*   384 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx] */
  /*   391 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT1_oB30_for_SC_CAN_V3_2_fd688a67_Tx] */
  /*   392 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx] */
  /*   399 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT17_oB30_for_SC_CAN_V3_2_95789025_Tx] */
  /*   400 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx] */
  /*   407 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT25_oB30_for_SC_CAN_V3_2_50c4f666_Tx] */
  /*   408 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx] */
  /*   415 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT10_oB30_for_SC_CAN_V3_2_3f69b5b6_Tx] */
  /*   416 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx] */
  /*   423 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT20_oB30_for_SC_CAN_V3_2_ce7e1154_Tx] */
  /* Index        Referable Keys */
  /*   424 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx] */
  /*   431 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT21_oB30_for_SC_CAN_V3_2_39937324_Tx] */
  /*   432 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx] */
  /*   439 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT22_oB30_for_SC_CAN_V3_2_fad5d3f5_Tx] */
  /*   440 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx] */
  /*   447 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT23_oB30_for_SC_CAN_V3_2_0d38b185_Tx] */
  /*   448 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx] */
  /*   455 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT43_oB30_for_SC_CAN_V3_2_3466fe00_Tx] */
  /*   456 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx] */
  /*   463 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT41_oB30_for_SC_CAN_V3_2_00cd3ca1_Tx] */
  /*   464 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx] */
  /*   471 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT42_oB30_for_SC_CAN_V3_2_c38b9c70_Tx] */
  /*   472 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx] */
  /*   487 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT15_Sc_oB30_for_SC_CAN_V3_2_6348d3e5_Tx] */
  /*   488 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx] */
  /*   495 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT33_oB30_for_SC_CAN_V3_2_5dca2ddb_Tx] */
  /*   496 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx] */
  /*   503 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT37_oB30_for_SC_CAN_V3_2_349da899_Tx] */
  /*   504 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx] */
  /*   511 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT39_oB30_for_SC_CAN_V3_2_bbcee5fe_Tx] */
  /*   512 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx] */
  /*   519 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT30_oB30_for_SC_CAN_V3_2_9e8c8d0a_Tx] */
  /*   520 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx] */
  /*   527 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT38_oB30_for_SC_CAN_V3_2_4c23878e_Tx] */
  /*   528 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx] */
  /*   535 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT36_oB30_for_SC_CAN_V3_2_c370cae9_Tx] */
  /*   536 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx] */
  /*   543 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT35_oB30_for_SC_CAN_V3_2_00366a38_Tx] */
  /*   544 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx] */
  /*   551 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT46_oB30_for_SC_CAN_V3_2_aadc1932_Tx] */
  /*   552 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx] */
  /*   559 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT45_oB30_for_SC_CAN_V3_2_699ab9e3_Tx] */
  /*   560 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx] */
  /*   623 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD5_oB30_for_SC_CAN_V3_2_93a3c1ee_Tx] */
  /* Index        Referable Keys */
  /*   624 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx] */
  /*   687 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT_FD4_oB30_for_SC_CAN_V3_2_69e51520_Tx] */
  /*   688 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx] */
  /*   695 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT49_oB30_for_SC_CAN_V3_2_d2623625_Tx] */
  /*   696 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx] */
  /*   703 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT6_oB30_for_SC_CAN_V3_2_7865d3ad_Tx] */
  /*   704 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx] */
  /*   ... */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx] */
  /*   711 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/HUT7_oB30_for_SC_CAN_V3_2_8057ceae_Tx] */

#define CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



