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
 *              File: Os_Hal_MemoryProtection_Lcfg.h
 *   Generation Time: 2021-09-03 11:40:30
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_MEMORYPROTECTION_LCFG_H
# define OS_HAL_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_MemoryProtection_Types.h"

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

/* Start/end address label declarations */
extern uint8 GLOBAL_RAMB_NONTRUST_VAR_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 GLOBAL_RAMB_NONTRUST_VAR_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 IPC_SHARE_VAR_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 IPC_SHARE_VAR_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 NONTRUST_VAR_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 NONTRUST_VAR_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 RTE_SHARE_VAR_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 RTE_SHARE_VAR_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 STACK_END[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 STACK_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 TRUST_VAR_START[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __ghs_grambend[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __ghs_grambstart[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __ghs_ramend[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __ghs_rramend[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 __ghs_rramstart[];                       /* PRQA S 0289, 1002, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.11_3684_LinkerSymbol */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: OsCore0 */
extern CONST(Os_Hal_MpCoreConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore0;

/*! HAL memory protection configuration data: OsApplication_NonTrust_OsCore0 */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication_NonTrust_OsCore0;

/*! HAL memory protection configuration data: OsApplication_Trust_OsCore0 */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication_Trust_OsCore0;

/*! HAL memory protection configuration data: SystemApplication_OsCore0 */
extern CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_SystemApplication_OsCore0;

/*! HAL memory protection configuration data: ADC0_SG1_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ADC0_SG1_CAT2_ISR;

/*! HAL memory protection configuration data: ADC1_SG1_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ADC1_SG1_CAT2_ISR;

/*! HAL memory protection configuration data: CanIsrGlobalStatus */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrGlobalStatus;

/*! HAL memory protection configuration data: CanIsrStatus_0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrStatus_0;

/*! HAL memory protection configuration data: CanIsrStatus_1 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrStatus_1;

/*! HAL memory protection configuration data: CanIsrStatus_3 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrStatus_3;

/*! HAL memory protection configuration data: CanIsrWakeup_0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrWakeup_0;

/*! HAL memory protection configuration data: CanIsrWakeup_1 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrWakeup_1;

/*! HAL memory protection configuration data: CanIsrWakeup_3 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrWakeup_3;

/*! HAL memory protection configuration data: CounterIsr_SystemTimer */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CounterIsr_SystemTimer;

/*! HAL memory protection configuration data: EXT_INTP_CH00_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH00_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH01_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH01_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH03_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH03_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH04_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH04_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH05_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH05_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH09_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH09_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH11_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH11_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH12_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH12_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH13_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH13_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH18_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH18_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH19_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH19_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH20_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH20_CAT2_ISR;

/*! HAL memory protection configuration data: EXT_INTP_CH21_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH21_CAT2_ISR;

/*! HAL memory protection configuration data: INTFICUIF0DFRQPE */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTFICUIF0DFRQPE;

/*! HAL memory protection configuration data: INTRIIC0EE_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0EE_interrupt;

/*! HAL memory protection configuration data: INTRIIC0RI_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0RI_interrupt;

/*! HAL memory protection configuration data: INTRIIC0TEI_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0TEI_interrupt;

/*! HAL memory protection configuration data: INTRIIC0TI_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0TI_interrupt;

/*! HAL memory protection configuration data: INTRIIC1EE_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1EE_interrupt;

/*! HAL memory protection configuration data: INTRIIC1RI_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1RI_interrupt;

/*! HAL memory protection configuration data: INTRIIC1TEI_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1TEI_interrupt;

/*! HAL memory protection configuration data: INTRIIC1TI_interrupt */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1TI_interrupt;

/*! HAL memory protection configuration data: Lin_RLIN_31_INTRLIN31 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Lin_RLIN_31_INTRLIN31;

/*! HAL memory protection configuration data: Lin_RLIN_32_INTRLIN32 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Lin_RLIN_32_INTRLIN32;

/*! HAL memory protection configuration data: SPI_CSIH3_TIR_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIH3_TIR_CAT2_ISR;

/*! HAL memory protection configuration data: TAUD0_CH13_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TAUD0_CH13_CAT2_ISR;

/*! HAL memory protection configuration data: TAUD0_CH15_CAT2_ISR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TAUD0_CH15_CAT2_ISR;

/*! HAL memory protection configuration data: Uart_IntErr4 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntErr4;

/*! HAL memory protection configuration data: Uart_IntErr5 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntErr5;

/*! HAL memory protection configuration data: Uart_IntRx4 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntRx4;

/*! HAL memory protection configuration data: Uart_IntRx5 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntRx5;

/*! HAL memory protection configuration data: Uart_IntTx4 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntTx4;

/*! HAL memory protection configuration data: Uart_IntTx5 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntTx5;

/*! HAL memory protection configuration data: vHsmResponseIsr */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_vHsmResponseIsr;

/*! HAL memory protection configuration data: BSW_COMM */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BSW_COMM;

/*! HAL memory protection configuration data: BSW_DIAGNOSE */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BSW_DIAGNOSE;

/*! HAL memory protection configuration data: DRIVERS_SAFE */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_DRIVERS_SAFE;

/*! HAL memory protection configuration data: Default_BSW */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Default_BSW;

/*! HAL memory protection configuration data: Default_Init_Task */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Default_Init_Task;

/*! HAL memory protection configuration data: Default_Init_Task_Trusted */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Default_Init_Task_Trusted;

/*! HAL memory protection configuration data: FUEL_TC_ODO */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_FUEL_TC_ODO;

/*! HAL memory protection configuration data: GateWay */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_GateWay;

/*! HAL memory protection configuration data: IPC */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IPC;

/*! HAL memory protection configuration data: IdleTask_OsCore0 */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IdleTask_OsCore0;

/*! HAL memory protection configuration data: SWC_LOW */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SWC_LOW;

/*! HAL memory protection configuration data: SYS */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SYS;

/*! HAL memory protection configuration data: TT_GEAR */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TT_GEAR;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: SystemMpu */
extern CONST(Os_Hal_MpSystemConfigType, OS_CONST) OsCfg_Hal_Mp_SystemMpu;

/*! HAL memory protection configuration data: EmptyThread */
extern CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EmptyThread;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
