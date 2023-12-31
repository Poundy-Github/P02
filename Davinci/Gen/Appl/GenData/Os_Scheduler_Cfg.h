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
 *              File: Os_Scheduler_Cfg.h
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_SCHEDULER_CFG_H
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether round robin scheduling is enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_SCHEDULE_ROUND_ROB_ENABLED       (STD_OFF)

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (9u)

/* Number of task queue activation slots: OsCore0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS     (4u)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE8_OSCORE0_SLOTS     (2u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
