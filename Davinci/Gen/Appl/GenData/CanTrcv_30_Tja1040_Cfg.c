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
 *            Module: CanTrcv
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTrcv_30_Tja1040_Cfg.c
 *   Generation Time: 2020-09-04 15:38:38
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "CanTrcv_30_Tja1040.h"

/**********************************************************************************************************************
  VERSION DEFINES (Adapted with: ESCAN00086365)
**********************************************************************************************************************/
#if (DRVTRANS_CAN_30_TJA1040_GENTOOL_CFG5_MAJOR_VERSION != 0x03u)
# error "CanTrcv_30_30_Tja1040_Cfg.c : Incompatible DRVTRANS_30_TJA1040_GENTOOL_CFG5_MAJOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_30_TJA1040_GENTOOL_CFG5_MINOR_VERSION != 0x02u)
# error "CanTrcv_30_30_Tja1040_Cfg.c : Incompatible DRVTRANS_30_TJA1040_GENTOOL_CFG5_MINOR_VERSION in generated File!"
#endif

#if (DRVTRANS_CAN_30_TJA1040_GENTOOL_CFG5_PATCH_VERSION != 0x00u)
# error "CanTrcv_30_30_Tja1040_Cfg.c : Incompatible DRVTRANS_30_TJA1040_GENTOOL_CFG5_PATCH_VERSION in generated File!"
#endif


/**********************************************************************************************************************
    ADDITIONAL (HW SPECIFIC)
**********************************************************************************************************************/



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
  CanTrcv_30_Tja1040_ChannelUsed
**********************************************************************************************************************/
#define CANTRCV_30_TJA1040_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1040_ChannelUsedType, CANTRCV_30_TJA1040_CONST) CanTrcv_30_Tja1040_ChannelUsed[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ChannelUsed  */
  /*     0 */         TRUE,
  /*     1 */         TRUE,
  /*     2 */         TRUE
};
#define CANTRCV_30_TJA1040_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1040_DioConfiguration
**********************************************************************************************************************/
/** 
  \var    CanTrcv_30_Tja1040_DioConfiguration
  \details
  Element    Description
  PinRXD 
  PinSTB 
*/ 
#define CANTRCV_30_TJA1040_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1040_DioConfigurationType, CANTRCV_30_TJA1040_CONST) CanTrcv_30_Tja1040_DioConfiguration[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PinRXD                           PinSTB                          */
  { /*     0 */ DioConf_DioChannel_VIP_CAN0_RXD, DioConf_DioChannel_VIP_CAN0_STB },
  { /*     1 */ DioConf_DioChannel_VIP_CAN1_RXD, DioConf_DioChannel_VIP_CAN1_STB },
  { /*     2 */ DioConf_DioChannel_VIP_CAN3_RXD, DioConf_DioChannel_VIP_CAN3_STB }
};
#define CANTRCV_30_TJA1040_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1040_WakeupByBusUsed
**********************************************************************************************************************/
#define CANTRCV_30_TJA1040_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1040_WakeupByBusUsedType, CANTRCV_30_TJA1040_CONST) CanTrcv_30_Tja1040_WakeupByBusUsed[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     WakeupByBusUsed  */
  /*     0 */            FALSE,
  /*     1 */            FALSE,
  /*     2 */             TRUE
};
#define CANTRCV_30_TJA1040_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTrcv_30_Tja1040_WakeupSource
**********************************************************************************************************************/
#define CANTRCV_30_TJA1040_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTrcv_30_Tja1040_WakeupSourceType, CANTRCV_30_TJA1040_CONST) CanTrcv_30_Tja1040_WakeupSource[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     WakeupSource  */
  /*     0 */         0x00u,
  /*     1 */         0x00u,
  /*     2 */         0x20u
};
#define CANTRCV_30_TJA1040_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/





