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
 *              File: Os_Ioc_Lcfg.h
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_IOC_LCFG_H
# define OS_IOC_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Ioc_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! IOC core configuration data: OsCore0 */
extern CONST(Os_IocReadConfigType, OS_CONST) OsCfg_IocRecv_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element;
extern CONST(Os_IocReadConfigType, OS_CONST) OsCfg_IocRecv_Rte_Power_Rc_Cluster_Shutdown_Status_Element;
extern CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_0;
extern CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Common_Normal_Rc_Cluster_Shutdown_Status_Element_1;
extern CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_0;
extern CONST(Os_IocWriteConfigType, OS_CONST) OsCfg_IocSend_Rte_Power_Rc_Cluster_Shutdown_Status_Element_1;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_IOC_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Ioc_Lcfg.h
 *********************************************************************************************************************/
