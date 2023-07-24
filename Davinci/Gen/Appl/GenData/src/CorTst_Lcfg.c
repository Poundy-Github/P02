/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = CorTst_Lcfg.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Link-time parameters.                                   */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 *  V1.0.0:  27-Nov-2013 : Initial version
 *  V1.0.1:  15-Jan-2014 : As per CR 348, for the mantis issue #18244,
 *                         Copyright information is updated.
 *  V1.0.2:  06-Aug-2014 : As per CR 604 for mantis ticket #22252, following
 *                         changes are made:
 *                         1. MISRA C Rule Violations are added.
 *                         2. Changes are made at all relevant places
 *                         accordingly to append U or UL after numeric values.
 *  V2.0.0:  07-Sep-2016 : #ARDAABD-492
 *                         1. Updated to ASR 4.2.2
 *  V2.0.1:  20-Oct-2016 : #ARDAABD-573
 *                         1.Syze of arrays CorTst_GulResult
 *                         CorTst_GulNotResult, CorTst_GulSignature
 *                         was set to  CORTST_NUM_TEST_AVAILABLE
 *  V2.0.2:  24-Oct-2016 : #ARDAABD-574
 *                         1. Added generation of
 *                            CorTst_GstForegroundRemapFngIds
 *  V2.0.3:  14-Aug-2017 : Justification added for QAC warnings which cannot
 *                         be removed. Updated code with corresponding tags.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  2.0.5
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

 /*
 * INPUT FILE:    C:\Users\GW00191223\AppData\Local\Temp\DaVinci\Cfg-6874790\Generation\Cfg_Gen-1606880170386-0\AutosarFiles_ValGen172034617495837798\ExtGen_DrvCorTst_ECUC_4.2.2_8597882667511532847.arxml
 *                C:\Vector_35\CBD2000298_D00\ThirdParty\Mcal_Rh850F1x\Supply\ASR_RH850_F1KM_42.05.00\X1X\F1x\modules\cortst\generator\R422_CORTST_F1x_BSWMDT.arxml
 * GENERATED ON:   2 Dec 2020 - 14:23:32
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "CorTst.h"

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:0694) Array initializer is missing the optional {.   */
/* Rule          : MISRA-C:2004 Rule 9.2                                      */
/*                 REFERENCE - ISO:C90-6.5.7 Semantics                        */
/* Justification : Array initializer is missing the optional { because of the */
/*                 limitation in common generation tool code.                 */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0694)-1 and                           */
/*                 END Msg(4:0694)-1 tags in the code.                        */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : Msg(4:1290) An integer constant of 'essentially signed'    */
/*                 type is being converted to unsigned type on assignment.    */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/* Justification : The unsigned integer is used as index, value is generated. */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1290)-2 and                           */
/*                 END Msg(4:1290)-2 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                             QAC Warnings                                   **
*******************************************************************************/

/* 1. QAC Warning:                                                            */
/* Message       : (2:0832) Macro substitution in #include preprocessing      */
/*                 directive.                                                 */
/* Justification : Required to optimize MemMap inclusion because of ASR403    */
/*                 and ASR422 support.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0832)-1 and                           */
/*                 END Msg(2:0832)-1 tags in the code.                        */
/******************************************************************************/

/* 2. QAC Warning:                                                            */
/* Message       : (2:0862) This #include 'MemMap.h' directive is redundant.  */
/* Justification : Each header has implemented safety for multiple inclusion. */
/*                 Header will not be included multiple times.                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:0862)-2 and                           */
/*                 END Msg(2:0862)-2 tags in the code.                        */
/******************************************************************************/

/* 3. QAC Warning:                                                            */
/* Message       : (2:3211) The global identifier 'x' is defined here but is  */
/*                 not used in this translation unit.                         */
/* Justification : Implementation requirement as specified by AUTOSAR SWS to  */
/*                 generate global variables and arrays for CorTst driver.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3211)-3 and                           */
/*                 END Msg(2:3211)-3 tags in the code.                        */
/******************************************************************************/

/* 4. QAC Warning:                                                            */
/* Message       : (2:3674) Array size defined implicitly by the number of    */
/*                 initializers.                                              */
/* Justification : Implementation implicit design                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:3674)-4 and                           */
/*                 END Msg(2:3674)-4 tags in the code.                        */
/******************************************************************************/

/* 5. QAC Warning:                                                            */
/* Message       : (2:2022) A tentative definition is being used. It is       */
/*                 appropriate to include an explicit initializer?            */
/* Justification : Implementation requirement as specified by AUTOSAR SWS to  */
/*                 generate global variables and arrays for CorTst driver.    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:2022)-5 and                           */
/*                 END Msg(2:2022)-5 tags in the code.                        */
/******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define CORTST_LCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define CORTST_LCFG_C_AR_RELEASE_MINOR_VERSION  2U
#define CORTST_LCFG_C_AR_RELEASE_REVISION_VERSION  2U

/* File version information */
#define CORTST_LCFG_C_SW_MAJOR_VERSION  1U
#define CORTST_LCFG_C_SW_MINOR_VERSION  1U

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CORTST_LTTYPES_AR_RELEASE_MAJOR_VERSION != \
      CORTST_LCFG_C_AR_RELEASE_MAJOR_VERSION)
 #error "CorTst_Lcfg.c : Mismatch in Release Major Version"
#endif

#if (CORTST_LTTYPES_AR_RELEASE_MINOR_VERSION != \
      CORTST_LCFG_C_AR_RELEASE_MINOR_VERSION)
 #error "CorTst_Lcfg.c : Mismatch in Release Minor Version"
#endif

#if (CORTST_LTTYPES_AR_RELEASE_REVISION_VERSION != \
      CORTST_LCFG_C_AR_RELEASE_REVISION_VERSION)
 #error "CorTst_Lcfg.c : Mismatch in Release Revision Version"
#endif

#if (CORTST_LTTYPES_SW_MAJOR_VERSION != CORTST_LCFG_C_SW_MAJOR_VERSION)
  #error "CorTst_Lcfg.c : Mismatch in Software Major Version"
#endif

#if (CORTST_LTTYPES_SW_MINOR_VERSION != CORTST_LCFG_C_SW_MINOR_VERSION)
  #error "CorTst_Lcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data Types                                  **
*******************************************************************************/
#define CORTST_START_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Implements: CORTST_ESDD_UD_037 */
/* Global GstBackground Config set */
/* QAC Warning: START Msg(2:3674)-4 */
/* QAC Warning: START Msg(2:3211)-3 */
/* MISRA Violation: START Msg(4:0694)-1 */
/* CONST(CorTst_ConfigType, CORTST_CONST) CorTst_GstBGModeSelConfig[]; */
/* END Msg(4:0694)-1 */
/* END Msg(2:3211)-3 */
/* END Msg(2:3674)-4 */

/* Implements: CORTST_ESDD_UD_038 */
/* Global GstForeground Config set */
/* QAC Warning: START Msg(2:3674)-4 */
/* MISRA Violation: START Msg(4:0694)-1 */
CONST(CorTst_ConfigType, CORTST_CONST) CorTst_GstFGModeSelConfig[] =
{
  /* Index: 0 - CorTstFGModeSelConfigSet */
  {
    /* blCorTstModule_CST_CPU_arithmetic_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_arithmetic_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_arithmetic_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_arithmetic_4 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_bit_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_bit_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_bitinsert_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_bitsearch_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_boolean_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_branch_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_cond_br_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_cond_data_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_cond_data_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_cond_data_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_condition_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_condition_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_data_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_data_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_div_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_div_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_hsdiv_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_ifu_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_ipu_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_jump_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_load_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_load_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_loadlink_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_loadstore_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_loop_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_lsu_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_lsu_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_mac_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_memory_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_memory_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_mul_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_mul_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_mul_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_mul_4 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_saturated_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_saturated_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_saturated_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_saturated_4 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_shift_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_shift_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_shift_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_shift_4 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_special_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_special_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_special_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_special_4 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_special_5 */
    CORTST_FALSE,

    /* blCorTstModule_CST_CPU_special_6 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_special_7 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_store_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_store_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_syscall_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_CPU_trap_1 */
    CORTST_FALSE,

    /* blCorTstModule_CST_CPU_trap_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_calc_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_calc_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_calc_3 */
    CORTST_FALSE,

    /* blCorTstModule_CST_FPU_calc_4 */
    CORTST_FALSE,

    /* blCorTstModule_CST_FPU_calc_5 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_calc_6 */
    CORTST_FALSE,

    /* blCorTstModule_CST_FPU_cmov_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_cmov_2 */
    CORTST_FALSE,

    /* blCorTstModule_CST_FPU_cmp_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_cmp_2 */
    CORTST_FALSE,

    /* blCorTstModule_CST_FPU_cvt_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_cvt_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_cvt_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_fmul_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_fmul_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_fmul_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_fmul_4 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_roundoff_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_FPU_roundoff_2 */
    CORTST_FALSE,

    /* blCorTstModule_CST_FPU_roundoff_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_exc_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_fpu_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_fpu_2 */
    CORTST_FALSE,

    /* blCorTstModule_CST_SRU_loadstore_1 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_loadstore_2 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_loadstore_3 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_loadstore_4 */
    CORTST_FALSE,

    /* blCorTstModule_CST_SRU_loadstore_5 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_loadstore_6 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_loadstore_7 */
    CORTST_TRUE,

    /* blCorTstModule_CST_SRU_loadstore_8 */
    CORTST_FALSE,

    /* blCorTstModule_CST_SRU_mpu_1 */
    CORTST_TRUE
  }
};


/* END Msg(4:0694)-1 */
/* END Msg(2:3674)-4 */

/* Implements: CORTST_ESDD_UD_066 */
/* QAC Warning: START Msg(2:3674)-4 */
/* QAC Warning: START Msg(2:3211)-3 */
/* MISRA Violation: START Msg(4:1290)-2 */
/* Internal GstForeground Remap ID */
CONST(CorTst_ForegroundIdRemap, CORTST_CONST) CorTst_GstRemapFngIds[] =
{
  /* Index: 0 - 0 */
  {
    /* id */
    0,

    /* pGstFGModeSelConfig */
    &CorTst_GstFGModeSelConfig[0]
  }
};


/* END Msg(4:1290)-2 */
/* END Msg(2:3211)-3 */
/* END Msg(2:3674)-4 */

#define CORTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define CORTST_START_SEC_CONST_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

/* Structure for Test complete Notification */
/* QAC Warning: START Msg(2:3211)-3 */
CONST(CorTst_NotifyFuncType, CORTST_CONST) CorTst_GstTestNotifyFunc =
{
  /* Index: 0 - pTestCompleteNotificationPointer  */
  NULL_PTR
};


/* END Msg(2:3211)-3 */

#define CORTST_STOP_SEC_CONST_UNSPECIFIED
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */

#define CORTST_START_SEC_BUFFER_CODE
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* QAC Warning: START Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:2022)-5 */
/* Buffer to store result of each core test */
 VAR(volatile long, AUTOMATIC) CorTst_GulResult[CORTST_NUM_TEST_AVAILABLE];
/* END Msg(2:2022)-5 */
/* END Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:2022)-5 */
/* Buffer to store NOT result of each core test */
 VAR(volatile long, AUTOMATIC) CorTst_GulNotResult[CORTST_NUM_TEST_AVAILABLE];
/* END Msg(2:2022)-5 */
/* END Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:2022)-5 */
/* Buffer to store signature of each core test */
 VAR(volatile long, AUTOMATIC) CorTst_GulSignature[CORTST_NUM_TEST_AVAILABLE];
/* END Msg(2:2022)-5 */
/* END Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:3211)-3 */
/* QAC Warning: START Msg(2:2022)-5 */
/* Buffer to store NOT signature of each core test */
 VAR(volatile long, AUTOMATIC) \
                            CorTst_GulNotSignature[CORTST_NUM_TEST_AVAILABLE];
/* END Msg(2:2022)-5 */
/* END Msg(2:3211)-3 */
#define CORTST_STOP_SEC_BUFFER_CODE
/* QAC Warning: START Msg(2:0862)-2 */
/* QAC Warning: START Msg(2:0832)-1 */
#include MEMMAP_FILE
/* END Msg(2:0832)-1 */
/* END Msg(2:0862)-2 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
