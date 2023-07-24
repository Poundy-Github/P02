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
 *              File: WdgM_StatusNotifications_Core0.c
 *   Generation Time: 2020-09-24 10:30:08
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define WDGM_STATUS_NOTIFICATIONS_CORE_0_C

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Rte_WdgM_SystemApplication_OsCore0.h" 

#define WDGM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WdgM_GlobalStatusChangeNotificationCore0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the global status of core 0
 *              changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgM_GlobalStatusType status)
{
  (void) Rte_Call_globalStateChangeCbk_Core0_GlobalStatusCallback(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              WdgMSupervisedEntity_test changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgM_LocalStatusType status)
{
  (void) Rte_Call_localStateChangeCbk_WdgMSupervisedEntity_test_LocalStatusCallback(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE1
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              WdgMSupervisedEntity_GEAR changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE1(WdgM_LocalStatusType status)
{
  (void) Rte_Call_localStateChangeCbk_WdgMSupervisedEntity_GEAR_LocalStatusCallback(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE2
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              WdgMSupervisedEntity_TT changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE2(WdgM_LocalStatusType status)
{
  (void) Rte_Call_localStateChangeCbk_WdgMSupervisedEntity_TT_LocalStatusCallback(status);
}

#define WDGM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: WdgM_StatusNotifications_Core0.h
 *********************************************************************************************************************/

