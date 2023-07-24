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
 *              File: Os_Hal_Context_Lcfg.h
 *   Generation Time: 2021-04-23 13:22:54
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CONTEXT_LCFG_H
# define OS_HAL_CONTEXT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"


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

# define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ProtectionHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ProtectionHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic ISR2 level context data: Level5 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn;

/*! HAL dynamic ISR2 level context data: Level6 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn;

/*! HAL dynamic ISR2 level context data: Level7 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn;

/*! HAL dynamic task context data: BSW_COMM */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_COMM_Dyn;


/*! HAL dynamic task context data: BSW_DIAGNOSE */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BSW_DIAGNOSE_Dyn;


/*! HAL dynamic task context data: DRIVERS_SAFE */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_DRIVERS_SAFE_Dyn;


/*! HAL dynamic task context data: Default_BSW */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_BSW_Dyn;


/*! HAL dynamic task context data: Default_Init_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;


/*! HAL dynamic task context data: Default_Init_Task_Trusted */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Trusted_Dyn;


/*! HAL dynamic task context data: FUEL_TC_ODO */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_FUEL_TC_ODO_Dyn;


/*! HAL dynamic task context data: GateWay */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_GateWay_Dyn;


/*! HAL dynamic task context data: IPC */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IPC_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;


/*! HAL dynamic task context data: SWC_LOW */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SWC_LOW_Dyn;


/*! HAL dynamic task context data: SYS */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_SYS_Dyn;


/*! HAL dynamic task context data: TT_GEAR */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_TT_GEAR_Dyn;


/*! HAL exception context data: OsCore0 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

# define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0;

/*! HAL hook context configuration data: ProtectionHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ProtectionHook_OsCore0;

/*! HAL ISR2 context configuration data: ADC0_SG1_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0_SG1_CAT2_ISR;

/*! HAL ISR2 context configuration data: ADC1_SG1_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1_SG1_CAT2_ISR;

/*! HAL ISR2 context configuration data: CanIsrGlobalStatus */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrGlobalStatus;

/*! HAL ISR2 context configuration data: CanIsrStatus_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_0;

/*! HAL ISR2 context configuration data: CanIsrStatus_1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_1;

/*! HAL ISR2 context configuration data: CanIsrStatus_3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_3;

/*! HAL ISR2 context configuration data: CanIsrWakeup_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrWakeup_0;

/*! HAL ISR2 context configuration data: CanIsrWakeup_1 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrWakeup_1;

/*! HAL ISR2 context configuration data: CanIsrWakeup_3 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrWakeup_3;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer;

/*! HAL ISR2 context configuration data: EXT_INTP_CH00_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH00_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH01_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH01_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH03_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH03_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH04_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH04_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH05_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH05_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH09_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH09_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH11_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH11_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH12_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH12_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH13_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH13_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH18_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH18_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH19_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH19_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH20_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH20_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH21_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH21_CAT2_ISR;

/*! HAL ISR2 context configuration data: INTFICUIF0DFRQPE */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTFICUIF0DFRQPE;

/*! HAL ISR2 context configuration data: INTRIIC0EE_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0EE_interrupt;

/*! HAL ISR2 context configuration data: INTRIIC0RI_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0RI_interrupt;

/*! HAL ISR2 context configuration data: INTRIIC0TEI_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0TEI_interrupt;

/*! HAL ISR2 context configuration data: INTRIIC0TI_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC0TI_interrupt;

/*! HAL ISR2 context configuration data: INTRIIC1EE_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1EE_interrupt;

/*! HAL ISR2 context configuration data: INTRIIC1RI_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1RI_interrupt;

/*! HAL ISR2 context configuration data: INTRIIC1TEI_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1TEI_interrupt;

/*! HAL ISR2 context configuration data: INTRIIC1TI_interrupt */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTRIIC1TI_interrupt;

/*! HAL ISR2 context configuration data: Lin_RLIN_31_INTRLIN31 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Lin_RLIN_31_INTRLIN31;

/*! HAL ISR2 context configuration data: Lin_RLIN_32_INTRLIN32 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Lin_RLIN_32_INTRLIN32;

/*! HAL ISR2 context configuration data: SPI_CSIH3_TIR_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH3_TIR_CAT2_ISR;

/*! HAL ISR2 context configuration data: TAUD0_CH13_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH13_CAT2_ISR;

/*! HAL ISR2 context configuration data: TAUD0_CH15_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH15_CAT2_ISR;

/*! HAL ISR2 context configuration data: Uart_IntErr4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntErr4;

/*! HAL ISR2 context configuration data: Uart_IntErr5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntErr5;

/*! HAL ISR2 context configuration data: Uart_IntRx4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntRx4;

/*! HAL ISR2 context configuration data: Uart_IntRx5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntRx5;

/*! HAL ISR2 context configuration data: Uart_IntTx4 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntTx4;

/*! HAL ISR2 context configuration data: Uart_IntTx5 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Uart_IntTx5;

/*! HAL ISR2 context configuration data: vHsmResponseIsr */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_vHsmResponseIsr;

/*! HAL task context configuration data: BSW_COMM */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_COMM;

/*! HAL task context configuration data: BSW_DIAGNOSE */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BSW_DIAGNOSE;

/*! HAL task context configuration data: DRIVERS_SAFE */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_DRIVERS_SAFE;

/*! HAL task context configuration data: Default_BSW */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_BSW;

/*! HAL task context configuration data: Default_Init_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task;

/*! HAL task context configuration data: Default_Init_Task_Trusted */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task_Trusted;

/*! HAL task context configuration data: FUEL_TC_ODO */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_FUEL_TC_ODO;

/*! HAL task context configuration data: GateWay */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_GateWay;

/*! HAL task context configuration data: IPC */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IPC;

/*! HAL task context configuration data: IdleTask_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0;

/*! HAL task context configuration data: SWC_LOW */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SWC_LOW;

/*! HAL task context configuration data: SYS */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SYS;

/*! HAL task context configuration data: TT_GEAR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TT_GEAR;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
extern CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.h
 *********************************************************************************************************************/
