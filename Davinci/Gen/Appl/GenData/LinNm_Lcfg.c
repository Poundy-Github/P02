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
 *            Module: LinNm
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LinNm_Lcfg.c
 *   Generation Time: 2020-07-09 11:40:50
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#include "ComStack_Types.h"
#include "NmStack_Types.h"
#include "LinNm_Cfg.h"

#define LINNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  System To LinNm Channel
 *********************************************************************************************************************/
CONST(NetworkHandleType, LINNM_CONST) LinNm_SystemToLinNmChannel[LinNm_NumberOfSystemChannels] = 
{
  0xFFu /*  ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b -> No LinNm channel  */ , 
  0u /*  ComMConf_ComMChannel_CN_LIN00_fd825f00 -> LinNmChannelConfig  */ 
};


/**********************************************************************************************************************
 *  LinNm To System Channel
 *********************************************************************************************************************/
CONST(NetworkHandleType, LINNM_CONST) LinNm_LinNmToSystemChannel[LinNm_NumberOfLinNmChannels] = 
{
  1u /*  LinNmChannelConfig -> ComMConf_ComMChannel_CN_LIN00_fd825f00  */ 
};

#define LINNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */ 



#define LINNM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Channel Data Structure
 *********************************************************************************************************************/
VAR(Nm_StateType, LINNM_VAR_NOINIT) LinNm_NmState[LinNm_NumberOfLinNmChannels];
VAR(Nm_ModeType, LINNM_VAR_NOINIT)  LinNm_NmMode [LinNm_NumberOfLinNmChannels];

#define LINNM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */



