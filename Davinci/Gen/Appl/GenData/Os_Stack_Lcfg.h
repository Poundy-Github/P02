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
 *              File: Os_Stack_Lcfg.h
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_LCFG_H
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

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

# define OS_START_SEC_STACK_BSW_COMM_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: BSW_COMM */
/* User: [BSW_COMM] */
extern OS_STACK_DECLARE(OsCfg_Stack_BSW_COMM_Dyn, OS_CFG_SIZE_BSW_COMM_STACK);

# define OS_STOP_SEC_STACK_BSW_COMM_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_BSW_DIAGNOSE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: BSW_DIAGNOSE */
/* User: [BSW_DIAGNOSE] */
extern OS_STACK_DECLARE(OsCfg_Stack_BSW_DIAGNOSE_Dyn, OS_CFG_SIZE_BSW_DIAGNOSE_STACK);

# define OS_STOP_SEC_STACK_BSW_DIAGNOSE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_DRIVERS_SAFE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: DRIVERS_SAFE */
/* User: [DRIVERS_SAFE] */
extern OS_STACK_DECLARE(OsCfg_Stack_DRIVERS_SAFE_Dyn, OS_CFG_SIZE_DRIVERS_SAFE_STACK);

# define OS_STOP_SEC_STACK_DRIVERS_SAFE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_DEFAULT_BSW_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Default_BSW */
/* User: [Default_BSW] */
extern OS_STACK_DECLARE(OsCfg_Stack_Default_BSW_Dyn, OS_CFG_SIZE_DEFAULT_BSW_STACK);

# define OS_STOP_SEC_STACK_DEFAULT_BSW_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_FUEL_TC_ODO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: FUEL_TC_ODO */
/* User: [FUEL_TC_ODO] */
extern OS_STACK_DECLARE(OsCfg_Stack_FUEL_TC_ODO_Dyn, OS_CFG_SIZE_FUEL_TC_ODO_STACK);

# define OS_STOP_SEC_STACK_FUEL_TC_ODO_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_GATEWAY_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: GateWay */
/* User: [GateWay] */
extern OS_STACK_DECLARE(OsCfg_Stack_GateWay_Dyn, OS_CFG_SIZE_GATEWAY_STACK);

# define OS_STOP_SEC_STACK_GATEWAY_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_IPC_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: IPC */
/* User: [IPC] */
extern OS_STACK_DECLARE(OsCfg_Stack_IPC_Dyn, OS_CFG_SIZE_IPC_STACK);

# define OS_STOP_SEC_STACK_IPC_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore0_Error */
/* User: [ErrorHook_OsCore0, OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Error_Dyn, OS_CFG_SIZE_OSCORE0_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore0_Init */
/* User: [OsCore0, Os_CoreInitHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Init_Dyn, OS_CFG_SIZE_OSCORE0_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore0_Isr_Core */
/* User: [ADC0_SG1_CAT2_ISR, ADC1_SG1_CAT2_ISR, CanIsrGlobalStatus, CanIsrStatus_0, CanIsrStatus_1, CanIsrStatus_3, CanIsrWakeup_0, CanIsrWakeup_1, CanIsrWakeup_3, CounterIsr_SystemTimer, EXT_INTP_CH00_CAT2_ISR, EXT_INTP_CH01_CAT2_ISR, EXT_INTP_CH03_CAT2_ISR, EXT_INTP_CH04_CAT2_ISR, EXT_INTP_CH05_CAT2_ISR, EXT_INTP_CH09_CAT2_ISR, EXT_INTP_CH11_CAT2_ISR, EXT_INTP_CH12_CAT2_ISR, EXT_INTP_CH13_CAT2_ISR, EXT_INTP_CH18_CAT2_ISR, EXT_INTP_CH19_CAT2_ISR, EXT_INTP_CH20_CAT2_ISR, EXT_INTP_CH21_CAT2_ISR, INTFICUIF0DFRQPE, INTRIIC0EE_interrupt, INTRIIC0RI_interrupt, INTRIIC0TEI_interrupt, INTRIIC0TI_interrupt, INTRIIC1EE_interrupt, INTRIIC1RI_interrupt, INTRIIC1TEI_interrupt, INTRIIC1TI_interrupt, Lin_RLIN_31_INTRLIN31, Lin_RLIN_32_INTRLIN32, SPI_CSIH3_TIR_CAT2_ISR, TAUD0_CH13_CAT2_ISR, TAUD0_CH15_CAT2_ISR, Uart_IntErr4, Uart_IntErr5, Uart_IntRx4, Uart_IntRx5, Uart_IntTx4, Uart_IntTx5, vHsmResponseIsr] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore0_Kernel */
/* User: [OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Kernel_Dyn, OS_CFG_SIZE_OSCORE0_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core protection stack: OsCore0_Protection */
/* User: [OsCore0, ProtectionHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Protection_Dyn, OS_CFG_SIZE_OSCORE0_PROTECTION_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_PROTECTION_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core shutdown stack: OsCore0_Shutdown */
/* User: [OsCore0, ShutdownHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio4294967295 */
/* User: [IdleTask_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO49_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio49 */
/* User: [Default_Init_Task_Trusted] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio49_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO49_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO49_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio50 */
/* User: [Default_Init_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_SWC_LOW_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: SWC_LOW */
/* User: [SWC_LOW] */
extern OS_STACK_DECLARE(OsCfg_Stack_SWC_LOW_Dyn, OS_CFG_SIZE_SWC_LOW_STACK);

# define OS_STOP_SEC_STACK_SWC_LOW_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_SYS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: SYS */
/* User: [SYS] */
extern OS_STACK_DECLARE(OsCfg_Stack_SYS_Dyn, OS_CFG_SIZE_SYS_STACK);

# define OS_STOP_SEC_STACK_SYS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_TT_GEAR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: TT_GEAR */
/* User: [TT_GEAR] */
extern OS_STACK_DECLARE(OsCfg_Stack_TT_GEAR_Dyn, OS_CFG_SIZE_TT_GEAR_STACK);

# define OS_STOP_SEC_STACK_TT_GEAR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: BSW_COMM */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_BSW_COMM;

/*! Stack configuration data: BSW_DIAGNOSE */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_BSW_DIAGNOSE;

/*! Stack configuration data: DRIVERS_SAFE */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_DRIVERS_SAFE;

/*! Stack configuration data: Default_BSW */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Default_BSW;

/*! Stack configuration data: FUEL_TC_ODO */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_FUEL_TC_ODO;

/*! Stack configuration data: GateWay */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_GateWay;

/*! Stack configuration data: IPC */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_IPC;

/*! Stack configuration data: OsCore0_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Error;

/*! Stack configuration data: OsCore0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Init;

/*! Stack configuration data: OsCore0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Core;

/*! Stack configuration data: OsCore0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Kernel;

/*! Stack configuration data: OsCore0_Protection */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Protection;

/*! Stack configuration data: OsCore0_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Shutdown;

/*! Stack configuration data: OsCore0_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio4294967295;

/*! Stack configuration data: OsCore0_Task_Prio49 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio49;

/*! Stack configuration data: OsCore0_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio50;

/*! Stack configuration data: SWC_LOW */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_SWC_LOW;

/*! Stack configuration data: SYS */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_SYS;

/*! Stack configuration data: TT_GEAR */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_TT_GEAR;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
