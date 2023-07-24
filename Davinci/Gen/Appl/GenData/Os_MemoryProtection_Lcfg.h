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
 *              File: Os_MemoryProtection_Lcfg.h
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_MEMORYPROTECTION_LCFG_H
# define OS_MEMORYPROTECTION_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_MemoryProtection_Types.h"

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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data */
extern CONST(Os_MpCoreConfigType, OS_CONST) OsCfg_Mp_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_NonTrust_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_OsApplication_Trust_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SystemApplication_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC0_SG1_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_ADC1_SG1_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrGlobalStatus;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrStatus_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrStatus_1;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrStatus_3;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrWakeup_0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrWakeup_1;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CanIsrWakeup_3;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_CounterIsr_SystemTimer;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH00_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH01_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH03_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH04_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH05_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH09_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH11_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH12_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH13_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH18_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH19_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH20_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_EXT_INTP_CH21_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTFICUIF0DFRQPE;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0EE_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0RI_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0TEI_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC0TI_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1EE_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1RI_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1TEI_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_INTRIIC1TI_interrupt;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Lin_RLIN_31_INTRLIN31;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Lin_RLIN_32_INTRLIN32;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SPI_CSIH3_TIR_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TAUD0_CH13_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TAUD0_CH15_CAT2_ISR;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntErr4;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntErr5;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntRx4;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntRx5;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntTx4;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Uart_IntTx5;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_vHsmResponseIsr;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BSW_COMM;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_BSW_DIAGNOSE;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_DRIVERS_SAFE;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Default_BSW;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Default_Init_Task;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_Default_Init_Task_Trusted;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_FUEL_TC_ODO;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_GateWay;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IPC;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_IdleTask_OsCore0;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SWC_LOW;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_SYS;
extern CONST(Os_MpAccessRightsType, OS_CONST) OsCfg_Mp_TT_GEAR;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory protection configuration data */
extern CONST(Os_MpSystemConfigType, OS_CONST) OsCfg_Mp_SystemMpu;

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_MEMORYPROTECTION_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection_Lcfg.h
 *********************************************************************************************************************/
