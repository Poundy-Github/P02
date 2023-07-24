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
 *            Module: Lin
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Lin_Lcfg.c
 *   Generation Time: 2020-08-18 12:27:29
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


/* MICROSAR Lin Rh850 Generator */
/* 15.00.00 */
/* PRQA S 0303 EOF */ /* MD_LIN_0303 */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    &&&~ Includes
----------------------------------------------------------------------------- */
#include "Lin.h"
#include "Os.h"


/* -----------------------------------------------------------------------------
    &&&~ Interrupts
----------------------------------------------------------------------------- */
#define LIN_START_SEC_CODE_ISR
#include "MemMap.h"

ISR( LinIsr_30_Rh850Rlin_31_0 ){ Lin_Interrupt( 0 ); }
ISR( LinIsr_30_Rh850Rlin_32_0 ){ Lin_Interrupt( 1 ); }

#define LIN_STOP_SEC_CODE_ISR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* -----------------------------------------------------------------------------
    &&&~ Lin_Config (ComStackLib)
----------------------------------------------------------------------------- */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
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
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Lin_ChannelConfig
**********************************************************************************************************************/
/** 
  \var    Lin_ChannelConfig
  \brief  List of all Lin channel config
  \details
  Element               Description
  GlobalBaseAddress     RLIN global register address.
  ChannelBaseAddress    RLIN channel register address.
*/ 
#define LIN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Lin_ChannelConfigType, LIN_CONST) Lin_ChannelConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    GlobalBaseAddress                            ChannelBaseAddress                                                               Referable Keys */
  { /*     0 */ ((Lin_GlobalRegisterStructPtr)0xFFCE2040uL), ((Lin_RegisterStructPtr)0xFFCE2048uL) /* PRQA S 0324 */ /* MD_LIN_0324 */ },  /* [CN_LIN00_fd825f00] */
  { /*     1 */ ((Lin_GlobalRegisterStructPtr)0xFFCE2080uL), ((Lin_RegisterStructPtr)0xFFCE2088uL) /* PRQA S 0324 */ /* MD_LIN_0324 */ }   /* [CN_LIN00_fd825f00_001] */
};
#define LIN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Lin_ChannelData
**********************************************************************************************************************/
/** 
  \var    Lin_ChannelData
  \brief  RAM data for channels.
  \details
  Element          Description
  InternalState    Internal software state.
  DataBuffer       Data Buffer.
*/ 
#define LIN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Lin_ChannelDataUType, LIN_VAR_NOINIT) Lin_ChannelData;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CN_LIN00_fd825f00] */
  /*     1 */  /* [CN_LIN00_fd825f00_001] */

#define LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/





/* Hardware specific precompile data */
/* None */

