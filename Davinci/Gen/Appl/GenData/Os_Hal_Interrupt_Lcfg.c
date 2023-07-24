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
 *              File: Os_Hal_Interrupt_Lcfg.c
 *   Generation Time: 2021-04-23 13:22:54
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC0_SG1_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 18uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 18uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)18uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC0_SG1_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC1_SG1_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 213uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 213uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)213uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC1_SG1_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CORTST_G3KH_EITRAP1_CAT1_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CORTST_G3KH_EITRAP1_CAT1_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0uL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0uL,
  /* .IntChannel  = */ (uint32)5uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)0uL,
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CORTST_G3KH_EITRAP1_CAT1_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CORTST_G3KH_FETRAP_CAT1_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CORTST_G3KH_FETRAP_CAT1_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0uL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0uL,
  /* .IntChannel  = */ (uint32)3uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)0uL,
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CORTST_G3KH_FETRAP_CAT1_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CORTST_G3KH_MAE_CAT1_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CORTST_G3KH_MAE_CAT1_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0uL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0uL,
  /* .IntChannel  = */ (uint32)12uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)0uL,
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CORTST_G3KH_MAE_CAT1_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrGlobalStatus */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrGlobalStatus =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 22uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 22uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)22uL,
  /* .IntLevel    = */ (uint32)7uL,
  /* .IntMask     = */ (uint32)(0x0000FF80uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrGlobalStatus =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrStatus_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrStatus_0 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 24uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 24uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)24uL,
  /* .IntLevel    = */ (uint32)1uL,
  /* .IntMask     = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrStatus_0 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrStatus_1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrStatus_1 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 113uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 113uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)113uL,
  /* .IntLevel    = */ (uint32)1uL,
  /* .IntMask     = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrStatus_1 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrStatus_3 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrStatus_3 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 220uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 220uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)220uL,
  /* .IntLevel    = */ (uint32)1uL,
  /* .IntMask     = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrStatus_3 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrWakeup_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrWakeup_0 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 25uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 25uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)25uL,
  /* .IntLevel    = */ (uint32)1uL,
  /* .IntMask     = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrWakeup_0 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrWakeup_1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrWakeup_1 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 114uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 114uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)114uL,
  /* .IntLevel    = */ (uint32)1uL,
  /* .IntMask     = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrWakeup_1 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrWakeup_3 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrWakeup_3 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 221uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 221uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)221uL,
  /* .IntLevel    = */ (uint32)1uL,
  /* .IntMask     = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrWakeup_3 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 277uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 277uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)277uL,
  /* .IntLevel    = */ (uint32)12uL,
  /* .IntMask     = */ (uint32)(0x0000F000uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: ECCTST_G3KH_FEINT_CAT1_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ECCTST_G3KH_FEINT_CAT1_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0uL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0uL,
  /* .IntChannel  = */ (uint32)15uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)0uL,
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ECCTST_G3KH_FEINT_CAT1_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: ECCTST_G3KH_SYSERR_CAT1_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ECCTST_G3KH_SYSERR_CAT1_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)0uL,
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)0uL,
  /* .IntChannel  = */ (uint32)1uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)0uL,
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ECCTST_G3KH_SYSERR_CAT1_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH00_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH00_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 37uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 37uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)37uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH00_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH01_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH01_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 38uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 38uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)38uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH01_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH03_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 43uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 43uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)43uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH03_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH04_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH04_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 44uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 44uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)44uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH04_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH05_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH05_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 45uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 45uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)45uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH05_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH09_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH09_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 205uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 205uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)205uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH09_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH11_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH11_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 47uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 47uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)47uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH11_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH12_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH12_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 131uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 131uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)131uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH12_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH13_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH13_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 206uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 206uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)206uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH13_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH18_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH18_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 370uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 370uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)370uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH18_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH19_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH19_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 371uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 371uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)371uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH19_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH20_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH20_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 372uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 372uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)372uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH20_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH21_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH21_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 373uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 373uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)373uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH21_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTFICUIF0DFRQPE */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTFICUIF0DFRQPE =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 359uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 359uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)359uL,
  /* .IntLevel    = */ (uint32)15uL,
  /* .IntMask     = */ (uint32)(0x00008000uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTFICUIF0DFRQPE =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC0EE_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC0EE_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 77uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 77uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)77uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC0EE_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC0RI_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC0RI_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 78uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 78uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)78uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC0RI_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC0TEI_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC0TEI_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 79uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 79uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)79uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC0TEI_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC0TI_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC0TI_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 76uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 76uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)76uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC0TI_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC1EE_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC1EE_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 241uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 241uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)241uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC1EE_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC1RI_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC1RI_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 242uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 242uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)242uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC1RI_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC1TEI_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC1TEI_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 243uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 243uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)243uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC1TEI_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTRIIC1TI_interrupt */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTRIIC1TI_interrupt =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 240uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 240uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)240uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTRIIC1TI_interrupt =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Lin_RLIN_31_INTRLIN31 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_RLIN_31_INTRLIN31 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 120uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 120uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)120uL,
  /* .IntLevel    = */ (uint32)10uL,
  /* .IntMask     = */ (uint32)(0x0000FC00uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Lin_RLIN_31_INTRLIN31 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Lin_RLIN_32_INTRLIN32 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Lin_RLIN_32_INTRLIN32 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 164uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 164uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)164uL,
  /* .IntLevel    = */ (uint32)10uL,
  /* .IntMask     = */ (uint32)(0x0000FC00uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Lin_RLIN_32_INTRLIN32 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 159uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 159uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)159uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: System1msTick */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_System1msTick =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 81uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 81uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)81uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_System1msTick =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: TAUD0_CH13_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH13_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 54uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 54uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)54uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH13_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: TAUD0_CH15_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH15_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 55uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 55uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)55uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH15_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Uart_IntErr4 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart_IntErr4 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 235uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 235uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)235uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Uart_IntErr4 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Uart_IntErr5 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart_IntErr5 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 239uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 239uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)239uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Uart_IntErr5 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Uart_IntRx4 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart_IntRx4 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 234uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 234uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)234uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Uart_IntRx4 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Uart_IntRx5 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart_IntRx5 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 238uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 238uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)238uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Uart_IntRx5 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Uart_IntTx4 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart_IntTx4 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 233uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 233uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)233uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Uart_IntTx4 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: Uart_IntTx5 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_Uart_IntTx5 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 237uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 237uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)237uL,
  /* .IntLevel    = */ (uint32)6uL,
  /* .IntMask     = */ (uint32)(0x0000FFC0uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_Uart_IntTx5 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: vHsmResponseIsr */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_vHsmResponseIsr =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 7uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 7uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)7uL,
  /* .IntLevel    = */ (uint32)8uL,
  /* .IntMask     = */ (uint32)(0x0000FF00uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_vHsmResponseIsr =
{
  /* .Dummy         = */ (uint32)0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
