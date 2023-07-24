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
 *              File: Os_Hal_MemoryProtection_Lcfg.c
 *   Generation Time: 2022-04-18 19:42:38
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_MEMORYPROTECTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_MemoryProtection_Cfg.h"
#include "Os_Hal_MemoryProtection_Lcfg.h"
#include "Os_Hal_MemoryProtection.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


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

/*! HAL memory protection configuration data: OsCore0 */
CONST(Os_Hal_MpCoreConfigType, OS_CONST) OsCfg_Hal_Mp_OsCore0 =
{
  /* MaxDynAppRegions    = 1 */
  /* MaxDynThreadRegions = 1 */

  /* Regions        = */ (uint32)(OS_HAL_MPU_REGION_COUNT_CORE0-1u),
  /* MpuRegionID    = */ (uint32)0x000003FFuL,

  {
    /* MPU region 0: dynamic region for stack */
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* MPU region 1: dynamic region for thread data */
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* MPU region 2: dynamic region for application data */
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* MPU region 3: static region {SUPERVISOR=[X, W, R], USER=[X, W, R]} */
    /* start address = */ (uint32)0x0uL,                                                    
    /* end address   = */ (uint32)0xfebbffffuL,                                                      
    /* access rights = */ (uint32)0x000000FFuL
  },
  {
    /* MPU region 4: static region {SUPERVISOR=[X, W, R]} */
    /* start address = */ (uint32)0xfeee80f0uL,                                                    
    /* end address   = */ (uint32)0xfeefffffuL,                                                      
    /* access rights = */ (uint32)0x000000F8uL
  },
  {
    /* MPU region 5: static region {SUPERVISOR=[X, W, R]} */
    /* start address = */ (uint32)0xff000000uL,                                                    
    /* end address   = */ (uint32)0xffffffffuL,                                                      
    /* access rights = */ (uint32)0x000000F8uL
  },
  {
    /* MPU region 6: static region {SUPERVISOR=[X, W, R], USER=[X, W, R]} */
    /* start address = */ (uint32)0xff200000uL,                                                    
    /* end address   = */ (uint32)0xff21ffffuL,                                                      
    /* access rights = */ (uint32)0x000000FFuL
  },
  {
    /* MPU region 7: static region {SUPERVISOR=[W, R], USER=[W, R]} */
    /* start address = */ (uint32)__ghs_rramstart,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)__ghs_rramend,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000DBuL
  },
  {
    /* MPU region 8: static region {SUPERVISOR=[X, W, R]} */
    /* start address = */ (uint32)STACK_END,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)__ghs_ramend,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000F8uL
  },
  {
    /* MPU region 9: static region {SUPERVISOR=[W, R], USER=[W, R]} */
    /* start address = */ (uint32)RTE_SHARE_VAR_START,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)RTE_SHARE_VAR_END,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000DBuL
  },
  {
    /* MPU region 10: static region {SUPERVISOR=[X, W, R], USER=[R]} */
    /* start address = */ (uint32)TRUST_VAR_START,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)STACK_START,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000F9uL
  },
  {
    /* MPU region 11: static region {SUPERVISOR=[W, R], USER=[W, R]} */
    /* start address = */ (uint32)0x0uL,                                                    
    /* end address   = */ (uint32)0x0000ffffuL,                                                      
    /* access rights = */ (uint32)0x000000DBuL
  },
  {
    /* MPU region 12: static region {SUPERVISOR=[X, W, R]} */
    /* start address = */ (uint32)__ghs_grambstart,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)__ghs_grambend,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000F8uL
  },
  {
    /* MPU region 13: static region {SUPERVISOR=[W, R], USER=[W, R]} */
    /* start address = */ (uint32)IPC_SHARE_VAR_START,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)IPC_SHARE_VAR_END,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000DBuL
  },
  {
    /* MPU region 14: static region {SUPERVISOR=[R], USER=[R]} */
    /* start address = */ (uint32)STACK_START,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)STACK_END,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000C9uL
  },
  {
    /* MPU region 15: static region {USER=[W, R]} */
    /* start address = */ (uint32)GLOBAL_RAMB_NONTRUST_VAR_START,                                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)GLOBAL_RAMB_NONTRUST_VAR_END,                                                      /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000C3uL
  },
}
;

/*! HAL memory protection configuration data: OsApplication_NonTrust_OsCore0 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication_NonTrust_OsCore0 =
{
  /* Regions = */ (uint32)2,
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)NONTRUST_VAR_START,                                              /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)NONTRUST_VAR_END,                                                /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000C3uL
  },
}
;

/*! HAL memory protection configuration data: OsApplication_Trust_OsCore0 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_OsApplication_Trust_OsCore0 =
{
  /* Regions = */ (uint32)2,
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }
}
;

/*! HAL memory protection configuration data: SystemApplication_OsCore0 */
CONST(Os_Hal_MpAppConfigType, OS_CONST) OsCfg_Hal_Mp_SystemApplication_OsCore0 =
{
  /* Regions = */ (uint32)2,
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }
}
;

/*! HAL memory protection configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ADC0_SG1_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_ADC1_SG1_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CanIsrGlobalStatus */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrGlobalStatus =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CanIsrStatus_0 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrStatus_0 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CanIsrStatus_1 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrStatus_1 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CanIsrStatus_3 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrStatus_3 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CanIsrWakeup_0 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrWakeup_0 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CanIsrWakeup_1 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrWakeup_1 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CanIsrWakeup_3 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CanIsrWakeup_3 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_CounterIsr_SystemTimer =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH00_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH00_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH01_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH01_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH03_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH04_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH04_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH05_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH05_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH09_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH09_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH11_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH11_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH12_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH12_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH13_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH13_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH18_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH18_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH19_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH19_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH20_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH20_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: EXT_INTP_CH21_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EXT_INTP_CH21_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTFICUIF0DFRQPE */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTFICUIF0DFRQPE =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC0EE_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0EE_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC0RI_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0RI_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC0TEI_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0TEI_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC0TI_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC0TI_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC1EE_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1EE_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC1RI_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1RI_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC1TEI_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1TEI_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: INTRIIC1TI_interrupt */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_INTRIIC1TI_interrupt =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Lin_RLIN_31_INTRLIN31 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Lin_RLIN_31_INTRLIN31 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Lin_RLIN_32_INTRLIN32 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Lin_RLIN_32_INTRLIN32 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: TAUD0_CH13_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TAUD0_CH13_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: TAUD0_CH15_CAT2_ISR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TAUD0_CH15_CAT2_ISR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Uart_IntErr4 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntErr4 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Uart_IntErr5 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntErr5 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Uart_IntRx4 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntRx4 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Uart_IntRx5 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntRx5 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Uart_IntTx4 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntTx4 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Uart_IntTx5 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Uart_IntTx5 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: vHsmResponseIsr */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_vHsmResponseIsr =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)STACK_START,                                  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* end address   = */ (uint32)STACK_END,                                    /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
    /* access rights = */ (uint32)0x000000D8uL
  }, 
}
;

/*! HAL memory protection configuration data: BSW_COMM */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BSW_COMM =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: BSW_DIAGNOSE */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_BSW_DIAGNOSE =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: DRIVERS_SAFE */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_DRIVERS_SAFE =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Default_BSW */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Default_BSW =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Default_Init_Task */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Default_Init_Task =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: Default_Init_Task_Trusted */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_Default_Init_Task_Trusted =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: FUEL_TC_ODO */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_FUEL_TC_ODO =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: GateWay */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_GateWay =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: IPC */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IPC =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_IdleTask_OsCore0 =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: SWC_LOW */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SWC_LOW =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: SYS */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_SYS =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

/*! HAL memory protection configuration data: TT_GEAR */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_TT_GEAR =
{
  /* Regions = */ (uint32)1,  
  /* ASID    = */ (uint32)0x000003FFuL,
  {
    /* start address = */ (uint32)0x0uL,
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  },
  {
    /* start address = */ (uint32)0x0uL,    
    /* end address   = */ (uint32)0x0uL,
    /* access rights = */ (uint32)0x0uL
  }, 
}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL memory protection configuration data: SystemMpu */
CONST(Os_Hal_MpSystemConfigType, OS_CONST) OsCfg_Hal_Mp_SystemMpu =
{  
  0u /* not used because no system MPU */
};

/*! HAL memory protection configuration data: EmptyThread */
CONST(Os_Hal_MpThreadConfigType, OS_CONST) OsCfg_Hal_Mp_EmptyThread =
{
  /* Regions = */ (uint32)0,  
  /* ASID    = */ (uint32)0x000003FFuL,
}
;

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
 *  END OF FILE: Os_Hal_MemoryProtection_Lcfg.c
 *********************************************************************************************************************/
