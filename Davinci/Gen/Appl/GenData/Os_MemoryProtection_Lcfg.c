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
 *              File: Os_MemoryProtection_Lcfg.c
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_MEMORYROTECTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_MemoryProtection.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_MemoryProtection_Lcfg.h"


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

/*! Memory protection configuration data: OsCore0 */
CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore0 =
{
  /* .HwConfig = */ &OsCfg_Hal_Mp_OsCore0
};

/*! Memory protection configuration data: OsApplication_NonTrust_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_NonTrust_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_NonTrust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: OsApplication_Trust_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_Trust_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: SystemApplication_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EmptyThread
};

/*! Memory protection configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC0_SG1_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_ADC0_SG1_CAT2_ISR
};

/*! Memory protection configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC1_SG1_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_ADC1_SG1_CAT2_ISR
};

/*! Memory protection configuration data: CanIsrGlobalStatus */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrGlobalStatus =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CanIsrGlobalStatus
};

/*! Memory protection configuration data: CanIsrStatus_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrStatus_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CanIsrStatus_0
};

/*! Memory protection configuration data: CanIsrStatus_1 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrStatus_1 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CanIsrStatus_1
};

/*! Memory protection configuration data: CanIsrStatus_3 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrStatus_3 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CanIsrStatus_3
};

/*! Memory protection configuration data: CanIsrWakeup_0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrWakeup_0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CanIsrWakeup_0
};

/*! Memory protection configuration data: CanIsrWakeup_1 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrWakeup_1 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CanIsrWakeup_1
};

/*! Memory protection configuration data: CanIsrWakeup_3 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrWakeup_3 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CanIsrWakeup_3
};

/*! Memory protection configuration data: CounterIsr_SystemTimer */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CounterIsr_SystemTimer =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_CounterIsr_SystemTimer
};

/*! Memory protection configuration data: EXT_INTP_CH00_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH00_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH00_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH01_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH01_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH01_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH03_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH03_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH04_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH04_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH04_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH05_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH05_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH05_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH09_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH09_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH09_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH11_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH11_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH11_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH12_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH12_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH12_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH13_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH13_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH13_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH18_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH18_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH18_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH19_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH19_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH19_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH20_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH20_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH20_CAT2_ISR
};

/*! Memory protection configuration data: EXT_INTP_CH21_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH21_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_EXT_INTP_CH21_CAT2_ISR
};

/*! Memory protection configuration data: INTFICUIF0DFRQPE */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTFICUIF0DFRQPE =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTFICUIF0DFRQPE
};

/*! Memory protection configuration data: INTRIIC0EE_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0EE_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC0EE_interrupt
};

/*! Memory protection configuration data: INTRIIC0RI_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0RI_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC0RI_interrupt
};

/*! Memory protection configuration data: INTRIIC0TEI_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0TEI_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC0TEI_interrupt
};

/*! Memory protection configuration data: INTRIIC0TI_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0TI_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC0TI_interrupt
};

/*! Memory protection configuration data: INTRIIC1EE_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1EE_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC1EE_interrupt
};

/*! Memory protection configuration data: INTRIIC1RI_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1RI_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC1RI_interrupt
};

/*! Memory protection configuration data: INTRIIC1TEI_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1TEI_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC1TEI_interrupt
};

/*! Memory protection configuration data: INTRIIC1TI_interrupt */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1TI_interrupt =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_INTRIIC1TI_interrupt
};

/*! Memory protection configuration data: Lin_RLIN_31_INTRLIN31 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Lin_RLIN_31_INTRLIN31 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Lin_RLIN_31_INTRLIN31
};

/*! Memory protection configuration data: Lin_RLIN_32_INTRLIN32 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Lin_RLIN_32_INTRLIN32 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Lin_RLIN_32_INTRLIN32
};

/*! Memory protection configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SPI_CSIH3_TIR_CAT2_ISR
};

/*! Memory protection configuration data: TAUD0_CH13_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TAUD0_CH13_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TAUD0_CH13_CAT2_ISR
};

/*! Memory protection configuration data: TAUD0_CH15_CAT2_ISR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TAUD0_CH15_CAT2_ISR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TAUD0_CH15_CAT2_ISR
};

/*! Memory protection configuration data: Uart_IntErr4 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntErr4 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Uart_IntErr4
};

/*! Memory protection configuration data: Uart_IntErr5 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntErr5 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Uart_IntErr5
};

/*! Memory protection configuration data: Uart_IntRx4 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntRx4 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Uart_IntRx4
};

/*! Memory protection configuration data: Uart_IntRx5 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntRx5 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Uart_IntRx5
};

/*! Memory protection configuration data: Uart_IntTx4 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntTx4 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Uart_IntTx4
};

/*! Memory protection configuration data: Uart_IntTx5 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntTx5 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Uart_IntTx5
};

/*! Memory protection configuration data: vHsmResponseIsr */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_vHsmResponseIsr =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_vHsmResponseIsr
};

/*! Memory protection configuration data: BSW_COMM */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BSW_COMM =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_BSW_COMM
};

/*! Memory protection configuration data: BSW_DIAGNOSE */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BSW_DIAGNOSE =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_BSW_DIAGNOSE
};

/*! Memory protection configuration data: DRIVERS_SAFE */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_DRIVERS_SAFE =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_DRIVERS_SAFE
};

/*! Memory protection configuration data: Default_BSW */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Default_BSW =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Default_BSW
};

/*! Memory protection configuration data: Default_Init_Task */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Default_Init_Task =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Default_Init_Task
};

/*! Memory protection configuration data: Default_Init_Task_Trusted */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Default_Init_Task_Trusted =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_Default_Init_Task_Trusted
};

/*! Memory protection configuration data: FUEL_TC_ODO */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_FUEL_TC_ODO =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_NonTrust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_FUEL_TC_ODO
};

/*! Memory protection configuration data: GateWay */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_GateWay =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_NonTrust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_GateWay
};

/*! Memory protection configuration data: IPC */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IPC =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_IPC
};

/*! Memory protection configuration data: IdleTask_OsCore0 */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore0 =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_SystemApplication_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_IdleTask_OsCore0
};

/*! Memory protection configuration data: SWC_LOW */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SWC_LOW =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SWC_LOW
};

/*! Memory protection configuration data: SYS */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SYS =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_SYS
};

/*! Memory protection configuration data: TT_GEAR */
CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TT_GEAR =
{
  /* .AppAccessRights    = */ &OsCfg_Hal_Mp_OsApplication_Trust_OsCore0,
  /* .ThreadAccessRights = */ &OsCfg_Hal_Mp_TT_GEAR
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data: SystemMpu */
CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu =
{
  /* .HwConfig = */ &OsCfg_Hal_Mp_SystemMpu
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
 *  END OF FILE: Os_MemoryProtection_Lcfg.c
 *********************************************************************************************************************/
