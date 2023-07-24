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
 *              File: WdgM_Cfg.h
 *   Generation Time: 2020-09-24 10:30:04
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#if !defined (WDGM_CFG_H)
# define WDGM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Types.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
#define WDGM_CFG_MAJOR_VERSION (5u) 
#define WDGM_CFG_MINOR_VERSION (5u) 
#define WDGM_CFG_PATCH_VERSION (3u) 


# define WDGM_NR_OF_CHECKPOINTS           (3u) 
# define WDGM_NR_OF_ENTITIES              (3u) 
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u) 
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u) 
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u) 
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u) 
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u) 

/* Checkpoints for supervised entity 'WdgMSupervisedEntity_test' */ 
# define WdgMConf_WdgMCheckpoint_WdgMCheckpoint_test (0u) 
/* Checkpoints for supervised entity 'WdgMSupervisedEntity_GEAR' */ 
# define WdgMConf_WdgMCheckpoint_WdgMCheckpoint (0u) 
/* Checkpoints for supervised entity 'WdgMSupervisedEntity_TT' */ 
# define WdgMConf_WdgMCheckpoint_WdgMCheckpoint (0u) 
 

# define WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity_test (0u) 
# define WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity_GEAR (1u) 
# define WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity_TT (2u) 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0; 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Status reporting (WdgMStatusReportingMechanism) configured to WDGM_USE_NOTIFICATIONS
 */
#define WDGM_START_SEC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define WDGM_STOP_SEC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define WDGM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
/* 
 * Local callback routines for mode switch ports of core 0 
 */ 
/* Local state callback for supervised entity 'WdgMSupervisedEntity_test' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgM_GlobalStatusType Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'WdgMSupervisedEntity_GEAR' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE1(WdgM_GlobalStatusType Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
/* Local state callback for supervised entity 'WdgMSupervisedEntity_TT' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE2(WdgM_GlobalStatusType Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
 
/* 
 * Global callback routine for mode switch ports of core0 
 */ 
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgM_LocalStatusType Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 

#define WDGM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 

#endif /* WDGM_CFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/

