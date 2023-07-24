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
 *              File: Os_Isr_Lcfg.c
 *   Generation Time: 2021-04-23 13:22:55
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: ADC0_SG1_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC0_SG1_CAT2_ISR_Dyn;

/*! Dynamic ISR data: ADC1_SG1_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC1_SG1_CAT2_ISR_Dyn;

/*! Dynamic ISR data: CanIsrGlobalStatus */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrGlobalStatus_Dyn;

/*! Dynamic ISR data: CanIsrStatus_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrStatus_0_Dyn;

/*! Dynamic ISR data: CanIsrStatus_1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrStatus_1_Dyn;

/*! Dynamic ISR data: CanIsrStatus_3 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrStatus_3_Dyn;

/*! Dynamic ISR data: CanIsrWakeup_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrWakeup_0_Dyn;

/*! Dynamic ISR data: CanIsrWakeup_1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrWakeup_1_Dyn;

/*! Dynamic ISR data: CanIsrWakeup_3 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrWakeup_3_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH00_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH01_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH03_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH04_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH05_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH09_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH11_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH12_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH13_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH18_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH19_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH20_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH21_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR_Dyn;

/*! Dynamic ISR data: INTFICUIF0DFRQPE */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTFICUIF0DFRQPE_Dyn;

/*! Dynamic ISR data: INTRIIC0EE_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC0EE_interrupt_Dyn;

/*! Dynamic ISR data: INTRIIC0RI_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC0RI_interrupt_Dyn;

/*! Dynamic ISR data: INTRIIC0TEI_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC0TEI_interrupt_Dyn;

/*! Dynamic ISR data: INTRIIC0TI_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC0TI_interrupt_Dyn;

/*! Dynamic ISR data: INTRIIC1EE_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC1EE_interrupt_Dyn;

/*! Dynamic ISR data: INTRIIC1RI_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC1RI_interrupt_Dyn;

/*! Dynamic ISR data: INTRIIC1TEI_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC1TEI_interrupt_Dyn;

/*! Dynamic ISR data: INTRIIC1TI_interrupt */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTRIIC1TI_interrupt_Dyn;

/*! Dynamic ISR data: Lin_RLIN_31_INTRLIN31 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Lin_RLIN_31_INTRLIN31_Dyn;

/*! Dynamic ISR data: Lin_RLIN_32_INTRLIN32 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Lin_RLIN_32_INTRLIN32_Dyn;

/*! Dynamic ISR data: SPI_CSIH3_TIR_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_Dyn;

/*! Dynamic ISR data: TAUD0_CH13_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TAUD0_CH13_CAT2_ISR_Dyn;

/*! Dynamic ISR data: TAUD0_CH15_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TAUD0_CH15_CAT2_ISR_Dyn;

/*! Dynamic ISR data: Uart_IntErr4 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart_IntErr4_Dyn;

/*! Dynamic ISR data: Uart_IntErr5 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart_IntErr5_Dyn;

/*! Dynamic ISR data: Uart_IntRx4 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart_IntRx4_Dyn;

/*! Dynamic ISR data: Uart_IntRx5 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart_IntRx5_Dyn;

/*! Dynamic ISR data: Uart_IntTx4 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart_IntTx4_Dyn;

/*! Dynamic ISR data: Uart_IntTx5 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_Uart_IntTx5_Dyn;

/*! Dynamic ISR data: vHsmResponseIsr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_vHsmResponseIsr_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC0_SG1_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ADC0_SG1_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC0_SG1_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC0_SG1_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_ADC0_SG1_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_ADC0_SG1_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ ADC0_SG1_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC1_SG1_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ADC1_SG1_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC1_SG1_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC1_SG1_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_ADC1_SG1_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_ADC1_SG1_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ ADC1_SG1_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CORTST_G3KH_EITRAP1_CAT1_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_EITRAP1_CAT1_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CORTST_G3KH_EITRAP1_CAT1_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CORTST_G3KH_EITRAP1_CAT1_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_EITRAP1_CAT1_ISR =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_CORTST_G3KH_EITRAP1_CAT1_ISR_HwConfig,
};
/*! ISR configuration data: CORTST_G3KH_FETRAP_CAT1_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_FETRAP_CAT1_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CORTST_G3KH_FETRAP_CAT1_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CORTST_G3KH_FETRAP_CAT1_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_FETRAP_CAT1_ISR =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_CORTST_G3KH_FETRAP_CAT1_ISR_HwConfig,
};
/*! ISR configuration data: CORTST_G3KH_MAE_CAT1_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_MAE_CAT1_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CORTST_G3KH_MAE_CAT1_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CORTST_G3KH_MAE_CAT1_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_CORTST_G3KH_MAE_CAT1_ISR =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_CORTST_G3KH_MAE_CAT1_ISR_HwConfig,
};
/*! ISR configuration data: CanIsrGlobalStatus */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalStatus_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrGlobalStatus,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrGlobalStatus,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalStatus =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrGlobalStatus,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrGlobalStatus_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CanIsrGlobalStatus,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrGlobalStatus_HwConfig,
  /* .IsrId                     = */ CanIsrGlobalStatus,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrStatus_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrStatus_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrStatus_0,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrStatus_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrStatus_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CanIsrStatus_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrStatus_0_HwConfig,
  /* .IsrId                     = */ CanIsrStatus_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrStatus_1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrStatus_1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrStatus_1,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrStatus_1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrStatus_1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CanIsrStatus_1,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrStatus_1_HwConfig,
  /* .IsrId                     = */ CanIsrStatus_1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrStatus_3 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_3_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrStatus_3,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrStatus_3,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_3 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrStatus_3,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrStatus_3_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CanIsrStatus_3,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrStatus_3_HwConfig,
  /* .IsrId                     = */ CanIsrStatus_3,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrWakeup_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrWakeup_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrWakeup_0,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrWakeup_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrWakeup_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CanIsrWakeup_0,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrWakeup_0_HwConfig,
  /* .IsrId                     = */ CanIsrWakeup_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrWakeup_1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrWakeup_1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrWakeup_1,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrWakeup_1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrWakeup_1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CanIsrWakeup_1,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrWakeup_1_HwConfig,
  /* .IsrId                     = */ CanIsrWakeup_1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrWakeup_3 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_3_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrWakeup_3,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrWakeup_3,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrWakeup_3 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrWakeup_3,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level7_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrWakeup_3_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CanIsrWakeup_3,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrWakeup_3_HwConfig,
  /* .IsrId                     = */ CanIsrWakeup_3,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_CounterIsr_SystemTimer,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CounterIsr_SystemTimer_HwConfig,
  /* .IsrId                     = */ CounterIsr_SystemTimer,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_SystemTimer)
};
/*! ISR configuration data: ECCTST_G3KH_FEINT_CAT1_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_FEINT_CAT1_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ECCTST_G3KH_FEINT_CAT1_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ECCTST_G3KH_FEINT_CAT1_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_FEINT_CAT1_ISR =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_ECCTST_G3KH_FEINT_CAT1_ISR_HwConfig,
};
/*! ISR configuration data: ECCTST_G3KH_SYSERR_CAT1_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_SYSERR_CAT1_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ECCTST_G3KH_SYSERR_CAT1_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ECCTST_G3KH_SYSERR_CAT1_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_ECCTST_G3KH_SYSERR_CAT1_ISR =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_ECCTST_G3KH_SYSERR_CAT1_ISR_HwConfig,
};
/*! ISR configuration data: EXT_INTP_CH00_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH00_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH00_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH00_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH00_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH00_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH01_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH01_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH01_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH01_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH01_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH01_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH03_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH03_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH03_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH03_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH03_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH04_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH04_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH04_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH04_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH04_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH04_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: EXT_INTP_CH05_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH05_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH05_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH05_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH05_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH05_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: EXT_INTP_CH09_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH09_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH09_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH09_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH09_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH09_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH11_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH11_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH11_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH11_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH11_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH11_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH12_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH12_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH12_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH12_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH12_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH12_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH13_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH13_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH13_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH13_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH13_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH13_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH18_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH18_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH18_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH18_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH18_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH18_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH19_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH19_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH19_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH19_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH19_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH19_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH20_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH20_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH20_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH20_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH20_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH20_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: EXT_INTP_CH21_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH21_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH21_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH21_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_EXT_INTP_CH21_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH21_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTFICUIF0DFRQPE */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTFICUIF0DFRQPE_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTFICUIF0DFRQPE,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTFICUIF0DFRQPE,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTFICUIF0DFRQPE =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTFICUIF0DFRQPE,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTFICUIF0DFRQPE_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTFICUIF0DFRQPE,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTFICUIF0DFRQPE_HwConfig,
  /* .IsrId                     = */ INTFICUIF0DFRQPE,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC0EE_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0EE_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC0EE_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC0EE_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0EE_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC0EE_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC0EE_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC0EE_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC0EE_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC0EE_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC0RI_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0RI_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC0RI_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC0RI_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0RI_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC0RI_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC0RI_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC0RI_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC0RI_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC0RI_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC0TEI_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TEI_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC0TEI_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC0TEI_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TEI_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC0TEI_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC0TEI_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC0TEI_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC0TEI_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC0TEI_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC0TI_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TI_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC0TI_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC0TI_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC0TI_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC0TI_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC0TI_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC0TI_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC0TI_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC0TI_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC1EE_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1EE_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC1EE_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC1EE_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1EE_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC1EE_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC1EE_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC1EE_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC1EE_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC1EE_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC1RI_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1RI_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC1RI_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC1RI_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1RI_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC1RI_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC1RI_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC1RI_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC1RI_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC1RI_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC1TEI_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TEI_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC1TEI_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC1TEI_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TEI_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC1TEI_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC1TEI_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC1TEI_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC1TEI_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC1TEI_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTRIIC1TI_interrupt */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TI_interrupt_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTRIIC1TI_interrupt,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTRIIC1TI_interrupt,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTRIIC1TI_interrupt =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTRIIC1TI_interrupt,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTRIIC1TI_interrupt_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_INTRIIC1TI_interrupt,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTRIIC1TI_interrupt_HwConfig,
  /* .IsrId                     = */ INTRIIC1TI_interrupt,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Lin_RLIN_31_INTRLIN31 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_31_INTRLIN31_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Lin_RLIN_31_INTRLIN31,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Lin_RLIN_31_INTRLIN31,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_31_INTRLIN31 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Lin_RLIN_31_INTRLIN31,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Lin_RLIN_31_INTRLIN31_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Lin_RLIN_31_INTRLIN31,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Lin_RLIN_31_INTRLIN31_HwConfig,
  /* .IsrId                     = */ Lin_RLIN_31_INTRLIN31,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Lin_RLIN_32_INTRLIN32 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_32_INTRLIN32_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Lin_RLIN_32_INTRLIN32,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Lin_RLIN_32_INTRLIN32,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Lin_RLIN_32_INTRLIN32 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Lin_RLIN_32_INTRLIN32,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Lin_RLIN_32_INTRLIN32_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Lin_RLIN_32_INTRLIN32,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Lin_RLIN_32_INTRLIN32_HwConfig,
  /* .IsrId                     = */ Lin_RLIN_32_INTRLIN32,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SPI_CSIH3_TIR_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SPI_CSIH3_TIR_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIH3_TIR_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_SPI_CSIH3_TIR_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ SPI_CSIH3_TIR_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ FALSE
}
;
/*! ISR configuration data: System1msTick */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_System1msTick_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_System1msTick,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_System1msTick,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_System1msTick =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_System1msTick_HwConfig,
};
/*! ISR configuration data: TAUD0_CH13_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH13_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TAUD0_CH13_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TAUD0_CH13_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH13_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TAUD0_CH13_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TAUD0_CH13_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_TAUD0_CH13_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TAUD0_CH13_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ TAUD0_CH13_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TAUD0_CH15_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH15_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TAUD0_CH15_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TAUD0_CH15_CAT2_ISR,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH15_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TAUD0_CH15_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TAUD0_CH15_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_TAUD0_CH15_CAT2_ISR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TAUD0_CH15_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ TAUD0_CH15_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Uart_IntErr4 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr4_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Uart_IntErr4,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Uart_IntErr4,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr4 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart_IntErr4,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart_IntErr4_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Uart_IntErr4,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Uart_IntErr4_HwConfig,
  /* .IsrId                     = */ Uart_IntErr4,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Uart_IntErr5 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr5_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Uart_IntErr5,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Uart_IntErr5,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntErr5 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart_IntErr5,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart_IntErr5_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Uart_IntErr5,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Uart_IntErr5_HwConfig,
  /* .IsrId                     = */ Uart_IntErr5,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Uart_IntRx4 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx4_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Uart_IntRx4,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Uart_IntRx4,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx4 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart_IntRx4,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart_IntRx4_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Uart_IntRx4,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Uart_IntRx4_HwConfig,
  /* .IsrId                     = */ Uart_IntRx4,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Uart_IntRx5 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx5_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Uart_IntRx5,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Uart_IntRx5,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntRx5 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart_IntRx5,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart_IntRx5_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Uart_IntRx5,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Uart_IntRx5_HwConfig,
  /* .IsrId                     = */ Uart_IntRx5,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Uart_IntTx4 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx4_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Uart_IntTx4,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Uart_IntTx4,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx4 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart_IntTx4,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart_IntTx4_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Uart_IntTx4,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Uart_IntTx4_HwConfig,
  /* .IsrId                     = */ Uart_IntTx4,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: Uart_IntTx5 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx5_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_Uart_IntTx5,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_Uart_IntTx5,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_Uart_IntTx5 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Uart_IntTx5,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level6_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_Uart_IntTx5_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_Uart_IntTx5,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_Uart_IntTx5_HwConfig,
  /* .IsrId                     = */ Uart_IntTx5,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: vHsmResponseIsr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_vHsmResponseIsr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_vHsmResponseIsr,
  /* .IsMapped                  = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_vHsmResponseIsr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_vHsmResponseIsr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trust_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ &OsCfg_Mp_vHsmResponseIsr,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_vHsmResponseIsr_HwConfig,
  /* .IsrId                     = */ vHsmResponseIsr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrGlobalStatus),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_3),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrWakeup_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrWakeup_1),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrWakeup_3),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH00_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH01_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH04_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH05_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH09_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH11_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH12_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH13_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH18_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH19_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH20_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH21_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTFICUIF0DFRQPE),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0EE_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0RI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0TEI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC0TI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1EE_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1RI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1TEI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTRIIC1TI_interrupt),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_RLIN_31_INTRLIN31),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Lin_RLIN_32_INTRLIN32),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH13_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH15_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntErr4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntErr5),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntRx4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntRx5),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntTx4),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_Uart_IntTx5),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_vHsmResponseIsr),
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
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/
