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
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2021-04-23 13:22:54
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ProtectionHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ProtectionHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic task context data: BSW_COMM */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_COMM_Dyn;

/*! HAL dynamic task context data: BSW_DIAGNOSE */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_DIAGNOSE_Dyn;

/*! HAL dynamic task context data: DRIVERS_SAFE */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_DRIVERS_SAFE_Dyn;

/*! HAL dynamic task context data: Default_BSW */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_BSW_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;

/*! HAL dynamic task context data: Default_Init_Task_Trusted */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Trusted_Dyn;

/*! HAL dynamic task context data: FUEL_TC_ODO */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_FUEL_TC_ODO_Dyn;

/*! HAL dynamic task context data: GateWay */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_GateWay_Dyn;

/*! HAL dynamic task context data: IPC */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IPC_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: SWC_LOW */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SWC_LOW_Dyn;

/*! HAL dynamic task context data: SYS */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SYS_Dyn;

/*! HAL dynamic task context data: TT_GEAR */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_TT_GEAR_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperOs_CoreInitHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperStatusHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperStatusHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL hook context configuration data: ProtectionHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ProtectionHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Protection_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Protection_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperProtectionHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)0uL, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL ISR2 context configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0_SG1_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_ADC0_SG1_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1_SG1_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_ADC1_SG1_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrGlobalStatus */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrGlobalStatus =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrGlobalStatus, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrStatus_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrStatus_0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrStatus_1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_1 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrStatus_1, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrStatus_3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_3 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrStatus_3, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrWakeup_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrWakeup_0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrWakeup_0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrWakeup_1 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrWakeup_1 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrWakeup_1, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrWakeup_3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrWakeup_3 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrWakeup_3, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Os_TimerPitIsr, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH00_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH00_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH00_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH01_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH01_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH01_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH03_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH03_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH04_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH04_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH04_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH05_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH05_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH05_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH09_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH09_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH09_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH11_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH11_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH11_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH12_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH12_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH12_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH13_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH13_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH13_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH18_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH18_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH18_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH19_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH19_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH19_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH20_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH20_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH20_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH21_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH21_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH21_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTFICUIF0DFRQPE */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTFICUIF0DFRQPE =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTFICUIF0DFRQPE, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC0EE_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0EE_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC0EE_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC0RI_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0RI_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC0RI_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC0TEI_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0TEI_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC0TEI_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC0TI_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0TI_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC0TI_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC1EE_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1EE_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC1EE_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC1RI_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1RI_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC1RI_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC1TEI_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1TEI_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC1TEI_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTRIIC1TI_interrupt */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1TI_interrupt =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_INTRIIC1TI_interrupt, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Lin_RLIN_31_INTRLIN31 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Lin_RLIN_31_INTRLIN31 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_LinIsr_30_Rh850Rlin_31_0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Lin_RLIN_32_INTRLIN32 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Lin_RLIN_32_INTRLIN32 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_LinIsr_30_Rh850Rlin_32_0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_SPI_CSIH3_TIR_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: TAUD0_CH13_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH13_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_TAUD0_CH13_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: TAUD0_CH15_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH15_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_TAUD0_CH15_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Uart_IntErr4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntErr4 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Uart_IntErr4, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Uart_IntErr5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntErr5 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Uart_IntErr5, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Uart_IntRx4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntRx4 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Uart_IntRx4, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Uart_IntRx5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntRx5 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Uart_IntRx5, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Uart_IntTx4 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntTx4 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Uart_IntTx4, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: Uart_IntTx5 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntTx5 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Uart_IntTx5, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: vHsmResponseIsr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_vHsmResponseIsr =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_vHsmResponseIsr, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL task context configuration data: BSW_COMM */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_COMM =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_BSW_COMM_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_BSW_COMM_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_BSW_COMM, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: BSW_DIAGNOSE */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_DIAGNOSE =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_BSW_DIAGNOSE_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_BSW_DIAGNOSE_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_BSW_DIAGNOSE, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: DRIVERS_SAFE */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DRIVERS_SAFE =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_DRIVERS_SAFE_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_DRIVERS_SAFE_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_DRIVERS_SAFE, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: Default_BSW */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_BSW =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_Default_BSW_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Default_BSW_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Default_BSW, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: Default_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Default_Init_Task, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: Default_Init_Task_Trusted */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task_Trusted =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio49_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio49_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Default_Init_Task_Trusted, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: FUEL_TC_ODO */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_FUEL_TC_ODO =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_FUEL_TC_ODO_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_FUEL_TC_ODO_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_FUEL_TC_ODO, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x40018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: GateWay */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GateWay =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_GateWay_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_GateWay_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_GateWay, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x40018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: IPC */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IPC =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_IPC_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_IPC_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_IPC, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Os_IdleTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: SWC_LOW */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SWC_LOW =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_SWC_LOW_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_SWC_LOW_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_SWC_LOW, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: SYS */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SYS =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_SYS_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_SYS_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_SYS, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: TT_GEAR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TT_GEAR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_TT_GEAR_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_TT_GEAR_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_TT_GEAR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackEnd   = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn) /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
