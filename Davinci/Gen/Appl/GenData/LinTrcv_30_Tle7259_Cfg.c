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
 *            Module: LinTrcv
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LinTrcv_30_Tle7259_Cfg.c
 *   Generation Time: 2020-08-18 15:19:12
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

 
 
 /**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* Disable the following MISRA warnings because they would appear too often for individual suppression.
   See justification at the end of file */




/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */

#include "LinTrcv_30_Tle7259.h"


/* -----------------------------------------------------------------------------
    &&&~ VersionDefines
 ----------------------------------------------------------------------------- */
#if (DRVTRANS_LIN_30_TLE7259_GENTOOL_CFG5_MAJOR_VERSION != 0x07u)
# error "LinTrcv_30_Tle7259_Cfg.c : Incompatible DRVTRANS_30_TLE7259_GENTOOL_CFG5_MAJOR_VERSION in generated File!"
#endif

#if (DRVTRANS_LIN_30_TLE7259_GENTOOL_CFG5_MINOR_VERSION != 0x00u)
# error "LinTrcv_30_Tle7259_Cfg.c : Incompatible DRVTRANS_30_TLE7259_GENTOOL_CFG5_MINOR_VERSIONin generated File!"
#endif

#if (DRVTRANS_LIN_30_TLE7259_GENTOOL_CFG5_PATCH_VERSION != 0x00u)
# error "LinTrcv_30_Tle7259_Cfg.c : Incompatible DRVTRANS_30_TLE7259_GENTOOL_CFG5_PATCH_VERSION in generated File!"
#endif

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
  LinTrcv_30_Tle7259_Channel
**********************************************************************************************************************/
/** 
  \var    LinTrcv_30_Tle7259_Channel
  \details
  Element        Description
  ChannelUsed
  InitState  
*/ 
#define LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinTrcv_30_Tle7259_ChannelType, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_Channel[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelUsed  InitState                */
  { /*     0 */        TRUE, LINTRCV_TRCV_MODE_NORMAL },
  { /*     1 */        TRUE, LINTRCV_TRCV_MODE_NORMAL }
};
#define LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinTrcv_30_Tle7259_DioChannel
**********************************************************************************************************************/
/** 
  \var    LinTrcv_30_Tle7259_DioChannel
  \details
  Element     Description
  DioPinEn
  DioPinRx
  DioPinTx
*/ 
#define LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinTrcv_30_Tle7259_DioChannelType, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_DioChannel[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DioPinEn                           DioPinRx                           DioPinTx                          */
  { /*     0 */ DioConf_DioChannel_VIP_RLIN31_SLP, DioConf_DioChannel_VIP_RLIN31_RXD, DioConf_DioChannel_VIP_RLIN31_TXD },
  { /*     1 */ DioConf_DioChannel_VIP_RLIN32_SLP, DioConf_DioChannel_VIP_RLIN32_RXD, DioConf_DioChannel_VIP_RLIN32_TXD }
};
#define LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LinTrcv_30_Tle7259_WakeUpSourceMapping
**********************************************************************************************************************/
/** 
  \var    LinTrcv_30_Tle7259_WakeUpSourceMapping
  \brief  Struct to provide the required Pin state
  \details
  Element          Description
  WakeupByBusRx    Level of Rx pin when Bus wakeup is signalized
  WakeupByBusTx    Level of Tx pin when Bus wakeup is signalized
  WakeupByPinRx    Level of Rx pin when Pin wakeup is signalized
  WakeupByPinTx    Level of Tx pin when Pin wakeup is signalized
*/ 
#define LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LinTrcv_30_Tle7259_WakeUpSourceMappingType, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_WakeUpSourceMapping[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    WakeupByBusRx  WakeupByBusTx  WakeupByPinRx  WakeupByPinTx */
  { /*     0 */ STD_LOW      , STD_HIGH     , STD_LOW      , STD_LOW       },
  { /*     1 */ STD_LOW      , STD_HIGH     , STD_LOW      , STD_LOW       }
};
#define LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/* -----------------------------------------------------------------------------
    &&&~ Constants
 ----------------------------------------------------------------------------- */

#define LINTRCV_30_TLE7259_START_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(uint8, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_NrOfChannels = LINTRCV_30_TLE7259_NROFCHANNELS; /* PRQA S 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
CONST(uint8, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_InstanceId = LINTRCV_30_TLE7259_INSTANCE_ID;

#define LINTRCV_30_TLE7259_STOP_SEC_CONST_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define LINTRCV_30_TLE7259_START_SEC_CONST_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(uint32, LINTRCV_30_TLE7259_CONST) LinTrcv_30_Tle7259_WaitCount = LINTRCV_30_TLE7259_WAIT_COUNT;

#define LINTRCV_30_TLE7259_STOP_SEC_CONST_32BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* -----------------------------------------------------------------------------
    &&&~ Variables
 ----------------------------------------------------------------------------- */

#define LINTRCV_30_TLE7259_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(LinTrcv_30_Tle7259_ChannelDataType, LINTRCV_30_TLE7259_VAR_NOINIT) LinTrcv_30_Tle7259_ChannelData[LINTRCV_30_TLE7259_NROFCHANNELS];

#define LINTRCV_30_TLE7259_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */












