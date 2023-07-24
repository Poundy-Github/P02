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
 *              File: Os_Isr_Lcfg.h
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_ISR_LCFG_H
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

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

/*! ISR configuration data: CORTST_G3KH_EITRAP1_CAT1_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_EITRAP1_CAT1_ISR_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_EITRAP1_CAT1_ISR;

/*! ISR configuration data: CORTST_G3KH_FETRAP_CAT1_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_FETRAP_CAT1_ISR_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_FETRAP_CAT1_ISR;

/*! ISR configuration data: CORTST_G3KH_MAE_CAT1_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_MAE_CAT1_ISR_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_MAE_CAT1_ISR;

/*! ISR configuration data: ECCTST_G3KH_FEINT_CAT1_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_FEINT_CAT1_ISR_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_FEINT_CAT1_ISR;

/*! ISR configuration data: ECCTST_G3KH_SYSERR_CAT1_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_SYSERR_CAT1_ISR_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_SYSERR_CAT1_ISR;

/*! ISR configuration data: System1msTick */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_System1msTick_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_System1msTick;

/*! ISR configuration data: ADC0_SG1_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR;

/*! ISR configuration data: ADC1_SG1_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR;

/*! ISR configuration data: CanIsrGlobalStatus */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalStatus_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalStatus;

/*! ISR configuration data: CanIsrStatus_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0;

/*! ISR configuration data: CanIsrStatus_1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_1;

/*! ISR configuration data: CanIsrStatus_3 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_3_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_3;

/*! ISR configuration data: CanIsrWakeup_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_0;

/*! ISR configuration data: CanIsrWakeup_1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_1;

/*! ISR configuration data: CanIsrWakeup_3 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_3_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_3;

/*! ISR configuration data: CounterIsr_SystemTimer */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer;

/*! ISR configuration data: EXT_INTP_CH00_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH01_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH03_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH04_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH05_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH09_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH11_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH12_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH13_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH18_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH19_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH20_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH21_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR;

/*! ISR configuration data: INTFICUIF0DFRQPE */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTFICUIF0DFRQPE_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTFICUIF0DFRQPE;

/*! ISR configuration data: INTRIIC0EE_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0EE_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0EE_interrupt;

/*! ISR configuration data: INTRIIC0RI_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0RI_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0RI_interrupt;

/*! ISR configuration data: INTRIIC0TEI_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TEI_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TEI_interrupt;

/*! ISR configuration data: INTRIIC0TI_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TI_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TI_interrupt;

/*! ISR configuration data: INTRIIC1EE_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1EE_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1EE_interrupt;

/*! ISR configuration data: INTRIIC1RI_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1RI_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1RI_interrupt;

/*! ISR configuration data: INTRIIC1TEI_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TEI_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TEI_interrupt;

/*! ISR configuration data: INTRIIC1TI_interrupt */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TI_interrupt_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TI_interrupt;

/*! ISR configuration data: Lin_RLIN_31_INTRLIN31 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_31_INTRLIN31_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_31_INTRLIN31;

/*! ISR configuration data: Lin_RLIN_32_INTRLIN32 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_32_INTRLIN32_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_32_INTRLIN32;

/*! ISR configuration data: SPI_CSIH3_TIR_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR;

/*! ISR configuration data: TAUD0_CH13_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH13_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH13_CAT2_ISR;

/*! ISR configuration data: TAUD0_CH15_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH15_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH15_CAT2_ISR;

/*! ISR configuration data: Uart_IntErr4 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr4_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr4;

/*! ISR configuration data: Uart_IntErr5 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr5_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr5;

/*! ISR configuration data: Uart_IntRx4 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx4_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx4;

/*! ISR configuration data: Uart_IntRx5 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx5_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx5;

/*! ISR configuration data: Uart_IntTx4 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx4_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx4;

/*! ISR configuration data: Uart_IntTx5 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx5_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx5;

/*! ISR configuration data: vHsmResponseIsr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/
