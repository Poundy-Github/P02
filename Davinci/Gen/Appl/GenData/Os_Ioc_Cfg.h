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
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Ioc_Cfg.h
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_IOC_CFG_H
# define OS_IOC_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether IOC is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_IOC                              (STD_ON)

/*! Defines whether IOC callbacks are configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_IOC_HAS_CALLBACKS                (STD_OFF)

/* IOC communication defines: Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element */
# define OS_CFG_SIZE_IOC_RTE_COMMON_NORMAL_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_BUFFER       (0uL)
# define OS_CFG_NUM_IOC_RTE_COMMON_NORMAL_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_CALLBACKS     (0uL)

/* IOC communication defines: Rte_Power_Rc_Cluster_Shutdown_Status_Element */
# define OS_CFG_SIZE_IOC_RTE_POWER_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_BUFFER       (0uL)
# define OS_CFG_NUM_IOC_RTE_POWER_RC_CLUSTER_SHUTDOWN_STATUS_ELEMENT_CALLBACKS     (0uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_IOC_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Ioc_Cfg.h
 *********************************************************************************************************************/
