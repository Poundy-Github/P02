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
 *            Module: WdgM
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_Cfg.c
 *   Generation Time: 2020-09-24 13:13:46
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define WDGM_CFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "WdgM.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGM_CFG_C_MAJOR_VERSION (5u) 
#define WDGM_CFG_C_MINOR_VERSION (5u) 
#define WDGM_CFG_C_PATCH_VERSION (3u) 


/* Check the version of WdgM_Cfg header file */
#if ( (WDGM_CFG_MAJOR_VERSION != WDGM_CFG_C_MAJOR_VERSION) \
   || (WDGM_CFG_MINOR_VERSION != WDGM_CFG_C_MINOR_VERSION) \
   || (WDGM_CFG_PATCH_VERSION != WDGM_CFG_C_PATCH_VERSION) )
# error "Version numbers of WdgM_Cfg.c and WdgM_Cfg.h are inconsistent!"
#endif

#if !defined (WDGM_LOCAL) /* COV_WDGM_COMPATIBILITY */
# define WDGM_LOCAL static
#endif

#define WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for global shared data */ 
WDGM_LOCAL VAR(WdgM_DataGSType, WDGM_VAR_NOINIT) StatusGS_core0; 
WDGM_LOCAL VAR(WdgM_EntityGSType, WDGM_VAR_NOINIT) EntityGS [WDGM_NR_OF_ENTITIES]; 
#define WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


#define WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgMSupervisedEntity_test' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_0; 
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE0_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMCheckpoint_test' in 'WdgMSupervisedEntity_test' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_0; 
#define WDGM_SE0_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE1_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgMSupervisedEntity_GEAR' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_1; 
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE1_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMCheckpoint' in 'WdgMSupervisedEntity_GEAR' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_1; 
#define WDGM_SE1_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE2_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* RAM section for supervisedEntity 'WdgMSupervisedEntity_TT' */ 
WDGM_LOCAL VAR(WdgM_EntityStatusLType, WDGM_VAR_NOINIT) EntityStatusL_2; 
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
#define WDGM_SE2_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
/* Local Alive Counters for checkpoint 'WdgMCheckpoint' in 'WdgMSupervisedEntity_TT' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterLType, WDGM_VAR_NOINIT) Alive_CounterL_2; 
#define WDGM_SE2_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
 
#define WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 
 
/* Global Status for Supervised Entities */ 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_0; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_1; 
WDGM_LOCAL VAR(WdgM_EntityStatusGType, WDGM_VAR_NOINIT) EntityStatusG_2; 
 
/* Global Alive Counters for checkpoint 'WdgMCheckpoint_test' in supervised entity 'WdgMSupervisedEntity_test' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_0; 
 
/* Global Alive Counters for checkpoint 'WdgMCheckpoint' in supervised entity 'WdgMSupervisedEntity_GEAR' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_1; 
 
/* Global Alive Counters for checkpoint 'WdgMCheckpoint' in supervised entity 'WdgMSupervisedEntity_TT' */ 
WDGM_LOCAL VAR(WdgM_AliveCounterGType, WDGM_VAR_NOINIT) Alive_CounterG_2; 
 
/* RAM section for Global Status */ 
WDGM_LOCAL VAR(WdgM_DataGType, WDGM_VAR_NOINIT) StatusG_core0; 
 
/* Global variables */ 
WDGM_LOCAL VAR(WdgM_GlobalVariablesType, WDGM_VAR_NOINIT) GlobalVariables_core0; 
 
#define WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



WDGM_LOCAL CONST(WdgM_CheckPointType, WDGM_CONST) WdgMCheckPoint[WDGM_NR_OF_CHECKPOINTS] =
{
  {
    WdgMConf_WdgMCheckpoint_WdgMCheckpoint_test /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    20u /*  WdgMExpectedAliveIndications  */ , 
    19u /*  WdgMMinMargin  */ , 
    19u /*  WdgMMaxMargin  */ , 
    10u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_0 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_0 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMCheckpoint /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    10u /*  WdgMExpectedAliveIndications  */ , 
    9u /*  WdgMMinMargin  */ , 
    9u /*  WdgMMaxMargin  */ , 
    50u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_1 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_1 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMCheckpoint_WdgMCheckpoint /*  WdgMCheckpointId  */ , 
    FALSE /*  WdgMIsEndCheckpoint  */ , 
    FALSE /*  WdgMIsEndCheckpointGlobal  */ , 
    10u /*  WdgMExpectedAliveIndications  */ , 
    9u /*  WdgMMinMargin  */ , 
    9u /*  WdgMMaxMargin  */ , 
    10u /*  WdgMSupervisionReferenceCycle  */ , 
    &Alive_CounterL_2 /*  WdgMAliveLRef  */ , 
    &Alive_CounterG_2 /*  WdgMAliveGRef  */ , 
    FALSE /*  WdgMDeadlineMonitoring  */ , 
    0u /*  WdgMOutgoingDeadlineMax  */ , 
    0u /*  NrOfLocalTransitions  */ , 
    NULL_PTR /*  WdgMLocalTransitionRef  */ , 
    0u /*  NrOfGlobalTransitions  */ , 
    NULL_PTR /*  WdgMGlobalTransitionsRef  */ , 
    FALSE /*  WdgMStartsAGlobalTransition  */ , 
    0u /*  NrOfStartedGlobalTransitions  */ , 
    NULL_PTR /*  WdgMStartedGlobalTransitionIds  */ 
  } /*  [2]  */ 
};


WDGM_LOCAL CONST(WdgM_SupervisedEntityType, WDGM_CONST) WdgMSupervisedEntity[WDGM_NR_OF_ENTITIES] =
{
  {
    WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity_test /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMCheckpoint_test /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[0] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    50u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    3u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE0 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_0 /*  EntityStatusLRef  */ , 
    &EntityStatusG_0 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [0]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity_GEAR /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMCheckpoint /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[1] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    50u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE1 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_1 /*  EntityStatusLRef  */ , 
    &EntityStatusG_1 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [1]  */ , 
  {
    WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity_TT /*  WdgMSupervisedEntity  */ , 
    FALSE /*  WdgMEnableEntityDeactivation  */ , 
    WdgMConf_WdgMCheckpoint_WdgMCheckpoint /*  WdgMCheckpointLocInitialId  */ , 
    1u /*  NrOfCheckpoints  */ , 
    &WdgMCheckPoint[2] /*  WdgMCheckpointRef  */ , 
    WDGM_LOCAL_STATUS_OK /*  WdgMInitialStatus  */ , 
    50u /*  WdgMFailedSupervisionRefCycleTol  */ , 
    0u /*  WdgMFailedDeadlineRefCycleTol  */ , 
    0u /*  WdgMDeadlineReferenceCycle  */ , 
    0u /*  WdgMFailedProgramFlowRefCycleTol  */ , 
    0u /*  WdgMProgramFlowReferenceCycle  */ , 
    FALSE /*  WdgMProgramFlowMonitoring  */ , 
    WDGM_INVALID_OSAPPLICATION /*  OSApplication  */ , 
    WdgM_LocalStatusChangeNotificationSE2 /*  WdgM_LocalStatusChangeNotification  */ , 
    &EntityStatusL_2 /*  EntityStatusLRef  */ , 
    &EntityStatusG_2 /*  EntityStatusGRef  */ , 
    0u /*  WdgMEntityCoreId  */ 
  } /*  [2]  */ 
};


WDGM_LOCAL CONST(WdgM_TriggerModeType, WDGM_CONST) WdgMTriggerMode_core0[WDGM_NR_OF_WATCHDOGS_CORE0 * WDGM_NR_OF_TRIGGER_MODES_CORE0] = 
{
  {
    512u /*   (condition value)  WdgMTriggerTimeout  */ , 
    51u /*  WdgMTicksPerSecond[Hz]=100 , WdgMTriggerTimeoutTicks  */ , 
    WDGIF_FAST_MODE /*  WdgMWatchdogMode  */ , 
    0u /*  WdgMDeviceIndex  */ 
  } /*  WdgMTriggerModeId 0  */ 
}; 
 
WDGM_LOCAL CONST(WdgM_WatchdogDeviceType, WDGM_CONST) WdgMWatchdogDevice0[WDGM_NR_OF_WATCHDOGS_CORE0] = 
{
  {
    &WdgMTriggerMode_core0[0] /*  WdgMTriggerModeRef  */ 
  } /*  [0]  */ 
}; 


WDGM_LOCAL CONST(WdgM_CallersType, WDGM_CONST) WdgMAllowedCallers[WDGM_NR_OF_ALLOWED_CALLERS] =
{
  {
    0u /*  WdgMAllowedCaller  */ 
  } /*  [0]  */ 
};


CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0 = 
{
  5u /*  WdgMConfigMajorVersion  */ , 
  5u /*  WdgMConfigMinorVersion  */ , 
  0u /*  WdgMConfigId  */ , 
  0u /*  WdgMInitialTriggerModeId  */ , 
  0u /*  WdgMExpiredSupervisionCycleTol  */ , 
  WDGM_INVALID_SE_ID /*  WdgMGlobInitialEntityId  */ , 
  WDGM_INVALID_CP_ID /*  WdgMGlobInitialCheckpointId  */ , 
  WDGM_NR_OF_GLOBAL_TRANSITIONS /*  NrOfGlobalTransitions  */ , 
  NULL_PTR /*  WdgMGlobalTransitions  */ , 
  WDGM_NR_OF_WATCHDOGS_CORE0 /*  NrOfWatchdogDevices  */ , 
  WDGM_NR_OF_TRIGGER_MODES_CORE0 /*  NrOfTriggerModes  */ , 
  WdgMWatchdogDevice0 /*  WdgMWatchdogDeviceRef  */ , 
  WDGM_NR_OF_ALLOWED_CALLERS /*  NrOfAllowedCallers  */ , 
  WdgMAllowedCallers /*  WdgMCallersRef  */ , 
  WDGM_NR_OF_ENTITIES /*  NrOfSupervisedEntities  */ , 
  WdgMSupervisedEntity /*  WdgMSupervisedEntityRef  */ , 
  &StatusG_core0 /*  DataGRef  */ , 
  &StatusGS_core0 /*  DataGSRef  */ , 
  EntityGS /*  EntityGSRef  */ , 
  NULL_PTR /*  GlobalTransitionFlagsGSRef  */ , 
  WdgM_GlobalStatusChangeNotificationCore0 /*  WdgM_GlobalStatusChangeNotification  */ , 
  &GlobalVariables_core0 /*  WdgMGlobalVariables  */ , 
  0u /*  WdgMModeCoreAssignment  */ , 
  0 /*  WdgMOsCounter  */ , 
  20u /*  WdgMConfigChecksum  */ 
}; 
 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.c
 *********************************************************************************************************************/

