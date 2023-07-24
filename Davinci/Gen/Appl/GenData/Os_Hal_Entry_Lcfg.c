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
 *              File: Os_Hal_Entry_Lcfg.c
 *   Generation Time: 2021-04-23 13:22:54
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_ENTRY_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Entry.h"

/* Os kernel module dependencies */
#include "Os_Isr_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Interrupt_Cfg.h"
#include "Os_Hal_Trap.h"


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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/

  extern void ECCTST_G3KH_SYSERR_ISR(void);
  extern void CORTST_G3KH_FETRAP_ISR(void);


  extern void CORTST_G3KH_EITRAP1_ISR(void);

  extern void CORTST_G3KH_MAE_ISR(void);
  extern void ECCTST_G3KH_FEINT_ISR(void);



/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CAT2 ISR HANDLER CORE 0
 *********************************************************************************************************************/

  extern void Os_Hal_Irq_ADC0_SG1_CAT2_ISR(void); 

  extern void Os_Hal_Irq_ADC1_SG1_CAT2_ISR(void); 

  extern void Os_Hal_Irq_CanIsrGlobalStatus(void); 

  extern void Os_Hal_Irq_CanIsrStatus_0(void); 

  extern void Os_Hal_Irq_CanIsrStatus_1(void); 

  extern void Os_Hal_Irq_CanIsrStatus_3(void); 

  extern void Os_Hal_Irq_CanIsrWakeup_0(void); 

  extern void Os_Hal_Irq_CanIsrWakeup_1(void); 

  extern void Os_Hal_Irq_CanIsrWakeup_3(void); 

  extern void Os_Hal_Irq_CounterIsr_SystemTimer(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH00_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH01_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH03_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH04_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH05_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH09_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH11_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH12_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH13_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH18_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH19_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH20_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH21_CAT2_ISR(void); 

  extern void Os_Hal_Irq_INTFICUIF0DFRQPE(void); 

  extern void Os_Hal_Irq_INTRIIC0EE_interrupt(void); 

  extern void Os_Hal_Irq_INTRIIC0RI_interrupt(void); 

  extern void Os_Hal_Irq_INTRIIC0TEI_interrupt(void); 

  extern void Os_Hal_Irq_INTRIIC0TI_interrupt(void); 

  extern void Os_Hal_Irq_INTRIIC1EE_interrupt(void); 

  extern void Os_Hal_Irq_INTRIIC1RI_interrupt(void); 

  extern void Os_Hal_Irq_INTRIIC1TEI_interrupt(void); 

  extern void Os_Hal_Irq_INTRIIC1TI_interrupt(void); 

  extern void Os_Hal_Irq_Lin_RLIN_31_INTRLIN31(void); 

  extern void Os_Hal_Irq_Lin_RLIN_32_INTRLIN32(void); 

  extern void Os_Hal_Irq_SPI_CSIH3_TIR_CAT2_ISR(void); 

  extern void Os_Hal_Irq_TAUD0_CH13_CAT2_ISR(void); 

  extern void Os_Hal_Irq_TAUD0_CH15_CAT2_ISR(void); 

  extern void Os_Hal_Irq_Uart_IntErr4(void); 

  extern void Os_Hal_Irq_Uart_IntErr5(void); 

  extern void Os_Hal_Irq_Uart_IntRx4(void); 

  extern void Os_Hal_Irq_Uart_IntRx5(void); 

  extern void Os_Hal_Irq_Uart_IntTx4(void); 

  extern void Os_Hal_Irq_Uart_IntTx5(void); 

  extern void Os_Hal_Irq_vHsmResponseIsr(void); 



/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/
