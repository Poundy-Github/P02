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
 *              File: Os_Alarm_Lcfg.h
 *   Generation Time: 2021-08-25 11:16:40
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_ALARM_LCFG_H
# define OS_ALARM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Alarm_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

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

/*! Alarm configuration data: Rte_Al_TE2_BSW_COMM_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_COMM_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_BSW_COMM_0_2ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_COMM_0_2ms;

/*! Alarm configuration data: Rte_Al_TE2_BSW_COMM_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_COMM_0_5ms;

/*! Alarm configuration data: Rte_Al_TE2_BSW_DIAGNOSE_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_BSW_DIAGNOSE_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_Default_BSW_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_Default_BSW_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_0_5ms;

/*! Alarm configuration data: Rte_Al_TE2_Default_BSW_1_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_Default_BSW_1_5ms;

/*! Alarm configuration data: Rte_Al_TE_CConfig_CConfig_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CConfig_CConfig_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_ */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_ */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_ */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B;

/*! Alarm configuration data: Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction;

/*! Alarm configuration data: Rte_Al_TE_DCM_Server_DCM_Server_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DCM_Server_DCM_Server_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_DRIVERS_SAFE_0_100ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DRIVERS_SAFE_0_100ms;

/*! Alarm configuration data: Rte_Al_TE_DRIVERS_SAFE_0_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DRIVERS_SAFE_0_50ms;

/*! Alarm configuration data: Rte_Al_TE_DRIVERS_SAFE_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_DRIVERS_SAFE_0_5ms;

/*! Alarm configuration data: Rte_Al_TE_EOL_EOL_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_EOL_EOL_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_FvM_FvM_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_FvM_FvM_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_Gyro_Gyro_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Gyro_Gyro_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_HSM_Hsm_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_HSM_Hsm_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_IPC_IPC_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_IPC_IPC_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_IPC_IPC_STB_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_IPC_IPC_STB_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_Misc_Misc_MainFunction_500ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Misc_Misc_MainFunction_500ms;

/*! Alarm configuration data: Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable;

/*! Alarm configuration data: Rte_Al_TE_SWC_LOW_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SWC_LOW_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_SYS_0_100ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SYS_0_100ms;

/*! Alarm configuration data: Rte_Al_TE_SYS_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SYS_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_SYS_0_50ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SYS_0_50ms;

/*! Alarm configuration data: Rte_Al_TE_SYS_0_5ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SYS_0_5ms;

/*! Alarm configuration data: Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for alarms. */
extern CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1];            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ALARM_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Lcfg.h
 *********************************************************************************************************************/
