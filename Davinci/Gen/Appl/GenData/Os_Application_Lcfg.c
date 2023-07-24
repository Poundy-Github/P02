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
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2022-04-12 19:43:17
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: OsApplication_NonTrust_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsApplication_NonTrust_OsCore0_Dyn;

/*! Dynamic application data: OsApplication_Trust_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_OsApplication_Trust_OsCore0_Dyn;

/*! Dynamic application data: SystemApplication_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_AlarmRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_GateWay_Common_GateWay_10msMainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_GateWay_Common_GateWay_5msMainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_100msMainFunction_),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_10msMainFunction_),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_A),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_20msMainFunction_B),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Normal_Common_Normal_5msMainFunction),
  NULL_PTR
};

/*! Object reference table for application counters: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_CounterRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_HookRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_SchTRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_TaskRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_FUEL_TC_ODO),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_GateWay),
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsApplication_NonTrust_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0_ServiceRefs[OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: OsApplication_NonTrust_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsApplication_NonTrust_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_OsApplication_NonTrust_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(OsApplication_NonTrust_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_OsApplication_NonTrust_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_OsApplication_NonTrust_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_OsApplication_NonTrust_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_OsApplication_NonTrust_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_OsApplication_NonTrust_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_OsApplication_NonTrust_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_OsApplication_NonTrust_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_OsApplication_NonTrust_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_NONTRUST_OSCORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ FALSE,
  /* .IsPriveleged         = */ FALSE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ OsApplication_NonTrust_OsCore0
};

/*! Object reference table for application alarms: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_AlarmRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BSW_COMM_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BSW_COMM_0_2ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BSW_COMM_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_BSW_DIAGNOSE_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_Default_BSW_1_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CConfig_CConfig_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Safety_Common_Safety_10msMainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Common_Safety_Common_Safety_50msMainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_DCM_Server_DCM_Server_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_DRIVERS_SAFE_0_100ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_DRIVERS_SAFE_0_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_DRIVERS_SAFE_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_EOL_EOL_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_FvM_FvM_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Gyro_Gyro_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_HSM_Hsm_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_IPC_IPC_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_IPC_IPC_STB_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Misc_Misc_MainFunction_500ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_Misc_NVM_Read_Speedup_Runnable),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SWC_LOW_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SYS_0_100ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SYS_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SYS_0_50ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SYS_0_5ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SecOc_Server_SecOc_Server_MainFunction),
  NULL_PTR
};

/*! Object reference table for application counters: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_CounterRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_COUNTERS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application hooks: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_HookRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrGlobalStatus),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_3),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrWakeup_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrWakeup_1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrWakeup_3),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTFICUIF0DFRQPE),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0EE_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0RI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0TEI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0TI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1EE_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1RI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1TEI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1TI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_RLIN_31_INTRLIN31),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_RLIN_32_INTRLIN32),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH13_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH15_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntErr4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntErr5),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntRx4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntRx5),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntTx4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntTx5),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_vHsmResponseIsr),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_SchTRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_TaskRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BSW_COMM),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_BSW_DIAGNOSE),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_DRIVERS_SAFE),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_BSW),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task_Trusted),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IPC),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SWC_LOW),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_SYS),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_TT_GEAR),
  NULL_PTR
};

/*! Object reference table for application trusted functions: OsApplication_Trust_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0_ServiceRefs[OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_SERVICES + 1u] =
{
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Csm_Decrypt),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Csm_Encrypt),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalGroupSet_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_CNA_SignalSet_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_IPC_DataSend_If_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_AppClearDTCInfo_AppClearDTCInfo),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_GetRxE2EStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_ComEx_SendSignal),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_GateWay_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ABS3_Counter),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ECM2_Counter),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_CanFrameCounter_Can_ESP_FD2_Counter),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToBAT_SetEventStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor1_ShortToGND_SetEventStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToBAT_SetEventStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_DiagnosticMonitor_Fuel_Sensor2_ShortToGND_SetEventStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_GetAes128Key),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_HsmKeyM_SetAes128Key),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_Hsm_Port_TrngGenerate),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_GetUTCTimeInMillis),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_IRTC_Service_UTC2PerpetualCalendar),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetPin),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_IoHwAb_Interface_GetVoltage),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_MaintainOdo_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_Trip_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_NvMService_AC3_SRBS_NvBlockNeed_Menu_WriteBlock),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetCounterValue),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_Os_Service_GetElapsedValue),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_GetRxE2EStatus),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCall_Common_Normal_rpCS_SWCNormal_ComEx_SendSignal),
  OS_SERVICE_CASTCONFIG_TF_2_SERVICE(OsCfg_Service_Rte_TrustedCom_SendSignal),
  NULL_PTR
};

/*! Application configuration data: OsApplication_Trust_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_OsApplication_Trust_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_OsApplication_Trust_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(OsApplication_Trust_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_OsApplication_Trust_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_OsApplication_Trust_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_OsApplication_Trust_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_OsApplication_Trust_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_OsApplication_Trust_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_OsApplication_Trust_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_OsApplication_Trust_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_OsApplication_Trust_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_OSAPPLICATION_TRUST_OSCORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ OsApplication_Trust_OsCore0
};

/*! Object reference table for application alarms: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_SystemTimer),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS + 1u] =
{
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS + 1u] =
{
  (Os_IsrCat1ConfigRefType) &OsCfg_Cat1Isr_System1msTick,
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(SystemApplication_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_App_OsApplication_NonTrust_OsCore0,
  &OsCfg_App_OsApplication_Trust_OsCore0,
  &OsCfg_App_SystemApplication_OsCore0,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
