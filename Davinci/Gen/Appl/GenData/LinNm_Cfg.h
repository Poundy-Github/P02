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
 *              File: LinNm_Cfg.h
 *   Generation Time: 2020-08-03 12:00:59
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined(LINNM_CFG_H)
#define LINNM_CFG_H

/* Nm_AsrNmLin CFG5 Generatorversion 3.02.00 */

/**********************************************************************************************************************
 *  Includes
 *********************************************************************************************************************/
#include "ComStack_Types.h"
#include "NmStack_Types.h"


/**********************************************************************************************************************
 *  Defines
 *********************************************************************************************************************/
#define LINNM_BUS_SYNCHRONIZATION_ENABLED       STD_OFF
#define LINNM_COM_CONTROL_ENABLED               STD_ON
#define LINNM_COM_USER_DATA_SUPPORT             STD_ON
#define LINNM_COORDINATOR_SYNC_SUPPORT          STD_OFF
#define LINNM_NODE_DETECTION_ENABLED            STD_ON
#define LINNM_NODE_ID_ENABLED                   STD_ON
#define LINNM_PASSIVE_MODE_ENABLED              STD_OFF
#define LINNM_REMOTE_SLEEP_INDICATION_ENABLED   STD_OFF
#define LINNM_STATE_CHANGE_IND_ENABLED          STD_OFF
#define LINNM_SYNCHRONIZATIONPOINT_ENABLED      STD_OFF
#define LINNM_USER_DATA_ENABLED                 STD_ON
#define LINNM_VERSION_INFO_API                  STD_OFF

#define LINNM_DEV_ERROR_DETECT                  STD_ON
#define LINNM_DEV_ERROR_REPORT                  STD_ON

#define LinNm_NumberOfLinNmChannels             1u
#define LinNm_NumberOfSystemChannels            2u

 
/**********************************************************************************************************************
 *  General Defines
 *********************************************************************************************************************/
#ifndef LINNM_USE_DUMMY_STATEMENT
#define LINNM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINNM_DUMMY_STATEMENT
#define LINNM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINNM_DUMMY_STATEMENT_CONST
#define LINNM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef LINNM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define LINNM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef LINNM_ATOMIC_VARIABLE_ACCESS
#define LINNM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef LINNM_PROCESSOR_RH850_1651
#define LINNM_PROCESSOR_RH850_1651
#endif
#ifndef LINNM_COMP_GREENHILLS
#define LINNM_COMP_GREENHILLS
#endif
#ifndef LINNM_GEN_GENERATOR_MSR
#define LINNM_GEN_GENERATOR_MSR
#endif
#ifndef LINNM_CPUTYPE_BITORDER_LSB2MSB
#define LINNM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef LINNM_CONFIGURATION_VARIANT_PRECOMPILE
#define LINNM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef LINNM_CONFIGURATION_VARIANT_LINKTIME
#define LINNM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef LINNM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define LINNM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef LINNM_CONFIGURATION_VARIANT
#define LINNM_CONFIGURATION_VARIANT LINNM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef LINNM_POSTBUILD_VARIANT_SUPPORT
#define LINNM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



/**********************************************************************************************************************
 *  Extern Declarations
 *********************************************************************************************************************/
#define LINNM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */

extern CONST(NetworkHandleType, LINNM_CONST) LinNm_SystemToLinNmChannel[LinNm_NumberOfSystemChannels];
extern CONST(NetworkHandleType, LINNM_CONST) LinNm_LinNmToSystemChannel[LinNm_NumberOfLinNmChannels];

#define LINNM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  Channel Data Structures
 *********************************************************************************************************************/
#define LINNM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */

extern VAR(Nm_StateType, LINNM_VAR_NOINIT) LinNm_NmState[LinNm_NumberOfLinNmChannels];
extern VAR(Nm_ModeType, LINNM_VAR_NOINIT)  LinNm_NmMode [LinNm_NumberOfLinNmChannels];

#define LINNM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_MemMap */


#endif


