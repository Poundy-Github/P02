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
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Lcfg.c
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#define CAN_LCFG_SOURCE

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */


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
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanIfChannelId      Comment */
  /*     0 */              0u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  /*     1 */              1u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  /*     2 */              2u   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ChannelData
**********************************************************************************************************************/
/** 
  \var    Can_ChannelData
  \brief  Controller specific information
  \details
  Element           Description
  FifoProcCount     Maximum number FIFO messages processed per event
  FrStartIndex      Start index of used receive rules (FullCAN + BasicCAN)
  FrTotalCount      Number of used receive rules (FullCAN + BasicCAN)
  RxBcMask          Bitmask of Rx BasicCAN objects (receive FIFO buffer 7-0)
  RxBcStartIndex    Start index of used receive FIFO buffers
  RxBcStopIndex     Stop index of used receive FIFO buffers
  TxIntMask0        Bitmask of Tx interrupt objects (transmit buffer 31-0)
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ChannelDataType, CAN_CONST) Can_ChannelData[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FifoProcCount  FrStartIndex  FrTotalCount  RxBcMask  RxBcStartIndex  RxBcStopIndex  TxIntMask0        Comment */
  { /*     0 */          255u,           2u,         147u,    0x04u,             2u,            3u,      0x00u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     1 */          255u,           0u,           1u,    0x01u,             0u,            1u,      0x00u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  { /*     2 */          255u,           1u,           1u,    0x02u,             1u,            2u,      0x00u }   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                            Description
  CanControllerDefaultBaudrate   
  CanControllerDefaultBaudrateIdx
  MailboxRxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxRxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxTxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxFullEndIdx                the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxFullLength                the number of relations pointing to Can_Mailbox
  MailboxTxFullStartIdx              the start index of the 0:n relation pointing to Can_Mailbox
  RxBasicHwStart                 
  RxBasicHwStop                  
  RxFullHwStart                  
  RxFullHwStop                   
  TxBasicHwStart                 
  TxBasicHwStop                  
  TxFullHwStart                  
  TxFullHwStop                   
  UnusedHwStart                  
  UnusedHwStop                   
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CanControllerDefaultBaudrate  CanControllerDefaultBaudrateIdx  MailboxRxBasicEndIdx                                                                                                                                                              MailboxRxBasicLength                                                                                                                                                              MailboxRxBasicStartIdx                                                                                                                                                              MailboxTxBasicEndIdx                                                                                                                                                              MailboxTxBasicLength                                                                                                                                                              MailboxTxBasicStartIdx                                                                                                                                                              MailboxTxFullEndIdx                                                                                                                                                                                      MailboxTxFullLength                                                                                                                                                             MailboxTxFullStartIdx                                                                                                                                                                                      RxBasicHwStart  RxBasicHwStop  RxFullHwStart  RxFullHwStop  TxBasicHwStart  TxBasicHwStop  TxFullHwStart  TxFullHwStop  UnusedHwStart  UnusedHwStop        Comment                                           Referable Keys */
  { /*     0 */                         500u,                              0u,                  20u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                    19u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                  19u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                    18u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                                          18u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                 18u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,                                             0u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */    ,             2u,            3u,           21u,          21u,             0u,            3u,            3u,          21u,            0u,           0u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     1 */                         500u,                              0u,                  22u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                    21u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                  21u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                    20u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */, CAN_NO_MAILBOXTXFULLENDIDXOFCONTROLLERCONFIG  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                  0u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */, CAN_NO_MAILBOXTXFULLSTARTIDXOFCONTROLLERCONFIG  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,             0u,            1u,            1u,           1u,             0u,            1u,            1u,           1u,            0u,           0u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  { /*     2 */                         500u,                              0u,                  24u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                    23u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                  23u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                    22u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */, CAN_NO_MAILBOXTXFULLENDIDXOFCONTROLLERCONFIG  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,                  0u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */, CAN_NO_MAILBOXTXFULLSTARTIDXOFCONTROLLERCONFIG  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController) */,             1u,            2u,            2u,           2u,             0u,            1u,            1u,           1u,            0u,           0u }   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitFilterRules
**********************************************************************************************************************/
/** 
  \var    Can_InitFilterRules
  \brief  Rx BasicCAN acceptance filters
  \details
  Element    Description
  Code       Initialization value for the receive rule ID register
  Mask       Initialization value for the receive rule mask register
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitFilterRulesType, CAN_CONST) Can_InitFilterRules[149] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Code     Mask           Comment */
  { /*     0 */ 0x01C0u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1c0 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     1 */ 0x01D9u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1D9 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     2 */ 0x01DFu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1df (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     3 */ 0x01E1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1e1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     4 */ 0x01E2u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1e2 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     5 */ 0x01E3u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1e3 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     6 */ 0x01F1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1F1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     7 */ 0x01F2u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1F2 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     8 */ 0x01FAu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1FA (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*     9 */ 0x01FEu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x1fe (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    10 */ 0x02A3u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2A3 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    11 */ 0x02A8u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2a8 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    12 */ 0x02ABu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2ab (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    13 */ 0x02B4u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2b4 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    14 */ 0x02B8u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2b8 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    15 */ 0x02B9u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2b9 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    16 */ 0x02BAu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2ba (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    17 */ 0x02BBu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2bb (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    18 */ 0x02C1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2c1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    19 */ 0x02C4u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2c4 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    20 */ 0x02CAu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2ca (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    21 */ 0x02CCu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2cc (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    22 */ 0x02CDu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2cd (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    23 */ 0x02CEu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2ce (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    24 */ 0x02CFu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2cf (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    25 */ 0x02D0u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2d0 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    26 */ 0x02D1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2D1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    27 */ 0x02D2u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2d2 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    28 */ 0x02D3u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2d3 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    29 */ 0x02D4u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2d4 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    30 */ 0x02F0u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2f0 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    31 */ 0x02F7u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2f7 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    32 */ 0x02F8u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2f8 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    33 */ 0x02FAu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2fa (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    34 */ 0x02FDu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2fd (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    35 */ 0x03AEu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3ae (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    36 */ 0x03B5u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3b5 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    37 */ 0x03B7u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3b7 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    38 */ 0x03BFu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3bf (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    39 */ 0x03C2u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3c2 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    40 */ 0x03E1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3e1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    41 */ 0x03E3u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3e3 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    42 */ 0x03E5u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3e5 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    43 */ 0x03E9u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3e9 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    44 */ 0x03F1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x3f1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    45 */ 0x008Eu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x8e (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    46 */ 0x009Eu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x9E (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    47 */ 0x011Au, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x11a (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    48 */ 0x012Du, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x12d (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    49 */ 0x014Au, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x14a (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
    /* Index    Code     Mask           Comment */
  { /*    50 */ 0x014Fu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x14f (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    51 */ 0x015Bu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x15b (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    52 */ 0x015Eu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x15e (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    53 */ 0x016Bu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x16B (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    54 */ 0x016Fu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x16f (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    55 */ 0x018Bu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x18b (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    56 */ 0x019Bu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x19b (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    57 */ 0x019Cu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x19c (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    58 */ 0x019Fu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x19f (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    59 */ 0x023Du, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x23d (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    60 */ 0x025Cu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x25C (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    61 */ 0x027Cu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x27c (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    62 */ 0x028Du, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x28D (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    63 */ 0x029Bu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x29B (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    64 */ 0x029Du, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x29d (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    65 */ 0x029Fu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x29f (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    66 */ 0x030Au, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x30a (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    67 */ 0x030Du, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x30d (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    68 */ 0x0033u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x33 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    69 */ 0x034Du, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x34d (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    70 */ 0x035Eu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x35e (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    71 */ 0x050Au, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x50a (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    72 */ 0x0060u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x60 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    73 */ 0x0082u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x82 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    74 */ 0x0084u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x84 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    75 */ 0x0102u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x102 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    76 */ 0x0109u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x109 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    77 */ 0x0111u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x111 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    78 */ 0x0117u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x117 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    79 */ 0x0120u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x120 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    80 */ 0x0137u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x137 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    81 */ 0x0147u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x147 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    82 */ 0x0152u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x152 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    83 */ 0x0165u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x165 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    84 */ 0x0170u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x170 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    85 */ 0x0201u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x201 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    86 */ 0x0221u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x221 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    87 */ 0x0222u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x222 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    88 */ 0x0227u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x227 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    89 */ 0x0231u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x231 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    90 */ 0x0236u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x236 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    91 */ 0x0238u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x238 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    92 */ 0x0244u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x244 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    93 */ 0x0245u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x245 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    94 */ 0x0246u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x246 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    95 */ 0x0248u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x248 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    96 */ 0x0251u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x251 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    97 */ 0x0268u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x268 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    98 */ 0x0271u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x271 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*    99 */ 0x0273u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x273 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
    /* Index    Code     Mask           Comment */
  { /*   100 */ 0x0274u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x274 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   101 */ 0x0285u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x285 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   102 */ 0x0287u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x287 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   103 */ 0x0289u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x289 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   104 */ 0x0290u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x290 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   105 */ 0x0295u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x295 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   106 */ 0x0298u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x298 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   107 */ 0x0299u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x299 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   108 */ 0x0302u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x302 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   109 */ 0x0303u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x303 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   110 */ 0x0304u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x304 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   111 */ 0x0305u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x305 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   112 */ 0x0308u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x308 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   113 */ 0x0311u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x311 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   114 */ 0x0314u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x314 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   115 */ 0x0316u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x316 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   116 */ 0x0317u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x317 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   117 */ 0x0319u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x319 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   118 */ 0x0325u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x325 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   119 */ 0x0330u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x330 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   120 */ 0x0332u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x332 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   121 */ 0x0333u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x333 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   122 */ 0x0341u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x341 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   123 */ 0x0344u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x344 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   124 */ 0x0345u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x345 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   125 */ 0x0350u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x350 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   126 */ 0x0351u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x351 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   127 */ 0x0352u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x352 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   128 */ 0x0371u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x371 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   129 */ 0x0385u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x385 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   130 */ 0x0395u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x395 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   131 */ 0x0461u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x461 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   132 */ 0x0501u, 0x0780u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x501 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   133 */ 0x0536u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x536 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   134 */ 0x0760u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x760 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   135 */ 0x0773u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x773 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   136 */ 0x00A1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0xa1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   137 */ 0x00A6u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0xa6 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   138 */ 0x00ACu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0xac (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   139 */ 0x00BEu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0xbe (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   140 */ 0x00C8u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0xc8 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   141 */ 0x00F1u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0xf1 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   142 */ 0x00F9u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0xf9 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   143 */ 0x0056u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x056 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   144 */ 0x030Fu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x30F (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   145 */ 0x02FBu, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x2FB (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   146 */ 0x0517u, 0x07FFu },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanFilterMaskRx_0x517 (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx)] */
  { /*   147 */ 0x0000u, 0x0000u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - CanFilterMask (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_001)] */
  { /*   148 */ 0x0000u, 0x0000u }   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - CanFilterMask (CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_002)] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectBaudrate      Comment */
  /*     0 */                500u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanControllerBaudrateConfig] */
  /*     1 */                500u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - CanControllerBaudrateConfig] */
  /*     2 */                500u   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBitTiming
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBitTiming
  \brief  Initialization values for the channel nominal bit rate configuration registers
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectBitTimingType, CAN_CONST) Can_InitObjectBitTiming[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectBitTiming      Comment */
  /*     0 */          0x0F3E2000u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanControllerBaudrateConfig] */
  /*     1 */          0x0F3E0000u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - CanControllerBaudrateConfig] */
  /*     2 */          0x0F3E0000u   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBitTimingData
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBitTimingData
  \brief  Initialization values for the channel data bit rate configuration registers
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectBitTimingDataType, CAN_CONST) Can_InitObjectBitTimingData[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectBitTimingData      Comment */
  /*     0 */              0x044D0000u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanControllerBaudrateConfig - CanControllerFdBaudrateConfig] */
  /*     1 */              0x004D0000u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - CanControllerBaudrateConfig - CanControllerFdBaudrateConfig] */
  /*     2 */              0x004D0000u   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - CanControllerBaudrateConfig - CanControllerFdBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectCanFdConfig
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectCanFdConfig
  \brief  Initialization values for the channel CAN FD configuration registers
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectCanFdConfigType, CAN_CONST) Can_InitObjectCanFdConfig[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectCanFdConfig      Comment */
  /*     0 */            0x000F0200u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanControllerBaudrateConfig - CanControllerFdBaudrateConfig] */
  /*     1 */            0x00010200u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - CanControllerBaudrateConfig - CanControllerFdBaudrateConfig] */
  /*     2 */            0x00010200u   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - CanControllerBaudrateConfig - CanControllerFdBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectFdBrsConfig
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectFdBrsConfig
  \brief  FD config ('BaudrateObject' as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectFdBrsConfigType, CAN_CONST) Can_InitObjectFdBrsConfig[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectFdBrsConfig              */
  /*     0 */  CAN_FD_RXTX_INITOBJECTFDBRSCONFIG,
  /*     1 */  CAN_FD_RXTX_INITOBJECTFDBRSCONFIG,
  /*     2 */  CAN_FD_RXTX_INITOBJECTFDBRSCONFIG
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectStartIndex      Comment */
  /*     0 */                    0u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  /*     1 */                    1u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  /*     2 */                    2u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
  /*     3 */                    3u   /* [stop index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_LogToPhys
**********************************************************************************************************************/
/** 
  \var    Can_LogToPhys
  \brief  Logical to physical controller mapping
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_LogToPhysType, CAN_CONST) Can_LogToPhys[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     LogToPhys      Comment */
  /*     0 */         3u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  /*     1 */         0u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  /*     2 */         1u   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  ActiveSendData     
  IDValue            
  ActiveSendObject   
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_ControllerConfig
  FdPadding          
  HwHandle           
  MailboxSize        
  MailboxType        
  MaxDataLen         
  MemorySectionsIndex
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActiveSendData  IDValue  ActiveSendObject  ControllerConfigIdx                                                                          FdPadding  HwHandle  MailboxSize  MailboxType                                    MaxDataLen  MemorySectionsIndex        Comment                                                                     Referable Keys */
  { /*     0 */             0u, 0x0203u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       3u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  3u },  /* [CanHardwareObject_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx]    */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     1 */             0u, 0x0224u,               1u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       4u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  4u },  /* [CanHardwareObject_HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     2 */             0u, 0x0243u,               2u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       5u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  5u },  /* [CanHardwareObject_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx]    */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     3 */             0u, 0x024Du,               3u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       6u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  6u },  /* [CanHardwareObject_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx]    */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     4 */             0u, 0x026Fu,               4u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       7u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  7u },  /* [CanHardwareObject_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     5 */             0u, 0x027Fu,               5u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       8u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  8u },  /* [CanHardwareObject_IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     6 */             0u, 0x0293u,               6u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       9u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  9u },  /* [CanHardwareObject_IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx]        */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     7 */             0u, 0x02B2u,               7u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      10u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 10u },  /* [CanHardwareObject_HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     8 */             0u, 0x02B6u,               8u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      11u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 11u },  /* [CanHardwareObject_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*     9 */             0u, 0x02C3u,               9u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      12u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 12u },  /* [CanHardwareObject_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx] */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    10 */             0u, 0x02ECu,              10u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      13u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 13u },  /* [CanHardwareObject_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx]    */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    11 */             0u, 0x030Cu,              11u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      14u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 14u },  /* [CanHardwareObject_HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    12 */             0u, 0x031Cu,              12u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      15u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 15u },  /* [CanHardwareObject_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    13 */             0u, 0x0348u,              13u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      16u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 16u },  /* [CanHardwareObject_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    14 */             0u, 0x034Au,              14u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      17u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 17u },  /* [CanHardwareObject_IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx]        */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    15 */             0u, 0x0370u,              15u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      18u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 18u },  /* [CanHardwareObject_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    16 */             0u, 0x03AFu,              16u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      19u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 19u },  /* [CanHardwareObject_HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    17 */             0u, 0x0415u,              17u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,      20u,          1u,      CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 20u },  /* [CanHardwareObject_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    18 */             0u, 0x0000u,              18u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       0u,          3u, CAN_TX_BASICCAN_MUX_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  0u },  /* [CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx]                            */  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    19 */             0u, 0x0000u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c */    ,        0u,       2u,        128u,     CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 98u },  /* [CN_B30_for_SC_CAN_V3_2_efc035d8_Rx]                            */  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_efc035d8_Rx (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    20 */           192u, 0x0000u,              21u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 */,        0u,       0u,          1u,     CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 32u },  /* [CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_001]                        */  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    21 */             0u, 0x0000u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 */,        0u,       0u,        128u,     CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 96u },  /* [CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_001]                        */  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    22 */           256u, 0x0000u,              22u,                  2u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 */,        0u,       0u,          1u,     CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 64u },  /* [CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_002]                        */  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
  { /*    23 */             0u, 0x0000u,               0u,                  2u  /* /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 */,        0u,       1u,        128u,     CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 97u }   /* [CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_002]                        */  /* [/ActiveEcuC/Can/CanConfigSet/CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 (DefRef: /MICROSAR/Can_Rh850Rscanfd/Can/CanConfigSet/CanController)] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionInfo
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionInfo
  \brief  Memory section description
  \details
  Element               Description
  MemorySectionStart
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionInfoType, CAN_CONST) Can_MemorySectionInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MemorySectionStart        Comment */
  { /*     0 */                 0u },  /* [MemorySection: TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     1 */                32u },  /* [MemorySection: TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  { /*     2 */                64u }   /* [MemorySection: TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionObjects
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionObjects
  \brief  Memory section objects description
  \details
  Element           Description
  HwHandle      
  MailboxElement
  MailboxHandle 
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionObjectsType, CAN_CONST) Can_MemorySectionObjects[96] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*     0 */       0u,             0u,           18u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx] */
  { /*     1 */       1u,             1u,           18u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx] */
  { /*     2 */       2u,             2u,           18u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx] */
  { /*     3 */       3u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT_FD2_oB30_for_SC_CAN_V3_2_19e0e547_Tx] */
  { /*     4 */       4u,             0u,            1u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT40_oB30_for_SC_CAN_V3_2_f7205ed1_Tx] */
  { /*     5 */       5u,             0u,            2u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT_FD3_oB30_for_SC_CAN_V3_2_e3a63189_Tx] */
  { /*     6 */       6u,             0u,            3u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_DMS_FD1_oB30_for_SC_CAN_V3_2_1702aefa_Tx] */
  { /*     7 */       7u,             0u,            4u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT32_oB30_for_SC_CAN_V3_2_aa274fab_Tx] */
  { /*     8 */       8u,             0u,            5u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_IP2_Sc_oB30_for_SC_CAN_V3_2_fb13b195_Tx] */
  { /*     9 */       9u,             0u,            6u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_IP1_oB30_for_SC_CAN_V3_2_c2bc6804_Tx] */
  { /*    10 */      10u,             0u,            7u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT27_oB30_for_SC_CAN_V3_2_646f34c7_Tx] */
  { /*    11 */      11u,             0u,            8u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT26_oB30_for_SC_CAN_V3_2_938256b7_Tx] */
  { /*    12 */      12u,             0u,            9u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT_FD1_Sc_oB30_for_SC_CAN_V3_2_ad4f6083_Tx] */
  { /*    13 */      13u,             0u,           10u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_DVR_FD1_oB30_for_SC_CAN_V3_2_2030c8ae_Tx] */
  { /*    14 */      14u,             0u,           11u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT31_oB30_for_SC_CAN_V3_2_6961ef7a_Tx] */
  { /*    15 */      15u,             0u,           12u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT13_oB30_for_SC_CAN_V3_2_fc2f1567_Tx] */
  { /*    16 */      16u,             0u,           13u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT16_oB30_for_SC_CAN_V3_2_6295f255_Tx] */
  { /*    17 */      17u,             0u,           14u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_IP3_oB30_for_SC_CAN_V3_2_8dd4dc90_Tx] */
  { /*    18 */      18u,             0u,           15u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT34_oB30_for_SC_CAN_V3_2_f7db0848_Tx] */
  { /*    19 */      19u,             0u,           16u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT12_oB30_for_SC_CAN_V3_2_0bc27717_Tx] */
  { /*    20 */      20u,             0u,           17u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - CanHardwareObject_HUT19_oB30_for_SC_CAN_V3_2_1a2bdd42_Tx] */
  { /*    21 */      21u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    22 */      22u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    23 */      23u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    24 */      24u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    25 */      25u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    26 */      26u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    27 */      27u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    28 */      28u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    29 */      29u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    30 */      30u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    31 */      31u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c - Reserved] */
  { /*    32 */       0u,             0u,           20u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_001] */
  { /*    33 */       1u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    34 */       2u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    35 */       3u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    36 */       4u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    37 */       5u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    38 */       6u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    39 */       7u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    40 */       8u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    41 */       9u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    42 */      10u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    43 */      11u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    44 */      12u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    45 */      13u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    46 */      14u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    47 */      15u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    48 */      16u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    49 */      17u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*    50 */      18u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    51 */      19u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    52 */      20u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    53 */      21u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    54 */      22u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    55 */      23u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    56 */      24u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    57 */      25u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    58 */      26u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    59 */      27u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    60 */      28u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    61 */      29u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    62 */      30u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    63 */      31u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - Reserved] */
  { /*    64 */       0u,             0u,           22u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - CN_B30_for_SC_CAN_V3_2_c0d6c67b_Tx_002] */
  { /*    65 */       1u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    66 */       2u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    67 */       3u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    68 */       4u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    69 */       5u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    70 */       6u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    71 */       7u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    72 */       8u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    73 */       9u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    74 */      10u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    75 */      11u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    76 */      12u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    77 */      13u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    78 */      14u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    79 */      15u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    80 */      16u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    81 */      17u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    82 */      18u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    83 */      19u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    84 */      20u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    85 */      21u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    86 */      22u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    87 */      23u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    88 */      24u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    89 */      25u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    90 */      26u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    91 */      27u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    92 */      28u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    93 */      29u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    94 */      30u,             0u,            0u },  /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
  { /*    95 */      31u,             0u,            0u }   /* [TxBuffer_CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - Reserved] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_OsIsrId
**********************************************************************************************************************/
/** 
  \var    Can_OsIsrId
  \brief  OS ISR IDs of the the channel specific interrupts
  \details
  Element        Description
  IsrStatusId    Status ISR ID
  IsrWakeupId    Wakeup ISR ID
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_OsIsrIdType, CAN_CONST) Can_OsIsrId[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IsrStatusId     IsrWakeupId           Comment */
  { /*     0 */ CanIsrStatus_3, CanIsrWakeup_3 },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  { /*     1 */ CanIsrStatus_0, CanIsrWakeup_0 },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  { /*     2 */ CanIsrStatus_1, CanIsrWakeup_1 }   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_RxFifoData
**********************************************************************************************************************/
/** 
  \var    Can_RxFifoData
  \brief  Rx BasicCan FIFO specific information
  \details
  Element                   Description
  Controller                Logical index of the controller the FIFO is used on
  FifoDepth                 Initialization value for the depth of the FIFO buffer
  FifoPayloadStorageSize    Initialization value for the payload storage size of the FIFO buffer
  FilterStartIndex          Start index for filters in Can_InitFilterRules
  FilterStopIndex           Stop index for filters in Can_InitFilterRules
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_RxFifoDataType, CAN_CONST) Can_RxFifoData[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Controller  FifoDepth  FifoPayloadStorageSize  FilterStartIndex  FilterStopIndex        Comment */
  { /*     0 */         1u,     0x07u,                  0x00u,             147u,            148u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001 - CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_001] */
  { /*     1 */         2u,     0x07u,                  0x00u,             148u,            149u },  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002 - CN_B30_for_SC_CAN_V3_2_efc035d8_Rx_002] */
  { /*     2 */         0u,     0x07u,                  0x07u,               0u,            147u }   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c - CN_B30_for_SC_CAN_V3_2_efc035d8_Rx] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_WakeupSourceRef
**********************************************************************************************************************/
/** 
  \var    Can_WakeupSourceRef
  \brief  wakeup Source for channel
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_WakeupSourceRefType, CAN_CONST) Can_WakeupSourceRef[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     WakeupSourceRef      Comment */
  /*     0 */              32u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c] */
  /*     1 */               0u,  /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_001] */
  /*     2 */               0u   /* [CT_B30_for_SC_CAN_V3_2_4a04dc9c_002] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendData
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendData
  \brief  stored data for cancellation or TxFifo confirmation API2
*/ 
#define CAN_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ActiveSendDataType, CAN_VAR_NOINIT) Can_ActiveSendData[320];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  Pdu        buffered PduId for confirmation or cancellation
  State      send state like cancelled or send activ
  PduInfo    buffered ID to evaluate send priority and used as cancel notification parameters and TxFifo confirmation API2
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[23];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                      Description
  BusOffCounter                Counter to determine forced busoff recovery
  BusOffTransitionRequest      CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01
  CanInterruptCounter          CAN interrupt disable counter for each controller
  IsBusOff                     CAN state for each controller: busoff occur
  IsWakeup                     CAN state for each controller: wakeup occur
  LastInitObject               last set baudrate for reinit
  LogStatus                    CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  ModeTransitionRequest        CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06
  RamCheckTransitionRequest    CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00
  CanInterruptOldStatus        last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                  hw loop timeout for each controller
  RxTmpBuf                     Temporary buffer for received messages
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




