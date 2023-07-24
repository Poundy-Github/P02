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
 *              File: Os_Hal_Core_Lcfg.c
 *   Generation Time: 2021-04-23 13:22:54
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Core.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


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

#define OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore0 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore0 */
CONSTP2CONST(Os_IsrHwConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore0_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS + 1u] =
{
  &OsCfg_Isr_ADC0_SG1_CAT2_ISR_HwConfig,
  &OsCfg_Isr_CanIsrGlobalStatus_HwConfig,
  &OsCfg_Isr_CanIsrStatus_0_HwConfig,
  &OsCfg_Isr_CanIsrWakeup_0_HwConfig,
  &OsCfg_Isr_vHsmResponseIsr_HwConfig,
  NULL_PTR
};


/*! HAL core configuration data: OsCore0 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore0 =
{
  0
};

/*! HAL AUTOSAR core configuration data: OsCore0 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore0 =
{
  _OS_EXCVEC_CORE0_CODE_START,
  _OS_INTVEC_CORE0_CODE_START,
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core to thread configuration data. */
CONST(Os_Hal_Core2ThreadConfigType, OS_CONST) OsCfg_Hal_Core2Thread =
{
  /* .Core2Thread = */
  {
    &OsCfg_Hal_Core2Thread_OsCore0_Dyn, /* OS_CORE_ID_0 */
  }
};

/*! HAL system configuration data. */
CONST(Os_Hal_SystemConfigType, OS_CONST) OsCfg_Hal_System =
{
  1,
  {
    &OsCfg_Hal_CoreAsr_OsCore0,
    NULL_PTR
  }  
};

/*! Interrupt sources which are initialized by the hardware init core. */
CONSTP2CONST(Os_IsrHwConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_System_InterruptSourceRefs[OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS + 1u] =
{
  &OsCfg_Isr_ADC1_SG1_CAT2_ISR_HwConfig,
  &OsCfg_Isr_CanIsrStatus_1_HwConfig,
  &OsCfg_Isr_CanIsrStatus_3_HwConfig,
  &OsCfg_Cat1Isr_System1msTick_HwConfig,
  &OsCfg_Isr_CanIsrWakeup_1_HwConfig,
  &OsCfg_Isr_CanIsrWakeup_3_HwConfig,
  &OsCfg_Isr_CounterIsr_SystemTimer_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR_HwConfig,
  &OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR_HwConfig,
  &OsCfg_Isr_INTFICUIF0DFRQPE_HwConfig,
  &OsCfg_Isr_INTRIIC0EE_interrupt_HwConfig,
  &OsCfg_Isr_INTRIIC0RI_interrupt_HwConfig,
  &OsCfg_Isr_INTRIIC0TEI_interrupt_HwConfig,
  &OsCfg_Isr_INTRIIC0TI_interrupt_HwConfig,
  &OsCfg_Isr_INTRIIC1EE_interrupt_HwConfig,
  &OsCfg_Isr_INTRIIC1RI_interrupt_HwConfig,
  &OsCfg_Isr_INTRIIC1TEI_interrupt_HwConfig,
  &OsCfg_Isr_INTRIIC1TI_interrupt_HwConfig,
  &OsCfg_Isr_Lin_RLIN_31_INTRLIN31_HwConfig,
  &OsCfg_Isr_Lin_RLIN_32_INTRLIN32_HwConfig,
  &OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_HwConfig,
  &OsCfg_Isr_TAUD0_CH13_CAT2_ISR_HwConfig,
  &OsCfg_Isr_TAUD0_CH15_CAT2_ISR_HwConfig,
  &OsCfg_Isr_Uart_IntErr4_HwConfig,
  &OsCfg_Isr_Uart_IntErr5_HwConfig,
  &OsCfg_Isr_Uart_IntRx4_HwConfig,
  &OsCfg_Isr_Uart_IntRx5_HwConfig,
  &OsCfg_Isr_Uart_IntTx4_HwConfig,
  &OsCfg_Isr_Uart_IntTx5_HwConfig,
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
 *  END OF FILE: Os_Hal_Core_Lcfg.c
 *********************************************************************************************************************/

