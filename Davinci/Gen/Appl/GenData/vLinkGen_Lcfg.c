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
 *            Module: vLinkGen
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Lcfg.c
 *   Generation Time: 2020-12-12 14:39:40
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#define VLINKGEN_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vLinkGen_Lcfg.h"

#pragma ghs nowarning 32

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

/* Memory region blocks to be initialized with zeros in stage Early */
const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Memory region blocks to be initialized with zeros in stage One */
const vLinkGen_MemArea vLinkGen_ZeroInit_One_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Memory region blocks to be initialized with zeros in stage HardReset */
const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS] =
{
  { /*  LOCAL_RAM_0  */ 
     /*  .Start  */ (uint32)0xFEBC0000uL, 
     /*  .End  */ (uint32)0xFEC00000uL, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with zeros in stage Early */
const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS] =
{
  { /*  STACK_C0  */ 
     /*  .Start  */ (uint32)_STACK_C0_START, 
     /*  .End  */ (uint32)_STACK_C0_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with zeros in stage Zero */
const vLinkGen_MemArea vLinkGen_ZeroInit_Zero_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with zeros in stage One */
const vLinkGen_MemArea vLinkGen_ZeroInit_One_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS] =
{
  { /*  OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT  */ 
     /*  .Start  */ (uint32)_OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_START, 
     /*  .End  */ (uint32)_OS_OsApplication_NonTrust_OsCore0_VAR_ZERO_INIT_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT  */ 
     /*  .Start  */ (uint32)_OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_START, 
     /*  .End  */ (uint32)_OS_OsApplication_Trust_OsCore0_VAR_ZERO_INIT_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_OsApplication_VAR_ZERO_INIT  */ 
     /*  .Start  */ (uint32)_OS_OsApplication_VAR_ZERO_INIT_START, 
     /*  .End  */ (uint32)_OS_OsApplication_VAR_ZERO_INIT_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_DATA_CORE0_VAR_ZERO_INIT  */ 
     /*  .Start  */ (uint32)_OS_DATA_CORE0_VAR_ZERO_INIT_START, 
     /*  .End  */ (uint32)_OS_DATA_CORE0_VAR_ZERO_INIT_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_GLOBALSHARED_VAR_ZERO_INIT  */ 
     /*  .Start  */ (uint32)_OS_GLOBALSHARED_VAR_ZERO_INIT_START, 
     /*  .End  */ (uint32)_OS_GLOBALSHARED_VAR_ZERO_INIT_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  bss  */ 
     /*  .Start  */ (uint32)_bss_START, 
     /*  .End  */ (uint32)_bss_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  sbss  */ 
     /*  .Start  */ (uint32)_sbss_START, 
     /*  .End  */ (uint32)_sbss_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  zbss  */ 
     /*  .Start  */ (uint32)_zbss_START, 
     /*  .End  */ (uint32)_zbss_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with zeros in stage Two */
const vLinkGen_MemArea vLinkGen_ZeroInit_Two_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with zeros in stage Three */
const vLinkGen_MemArea vLinkGen_ZeroInit_Three_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with zeros in stage HardReset */
const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with concrete data in stage Zero */
const vLinkGen_RamMemArea vLinkGen_Init_Zero_Groups[VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with concrete data in stage One */
const vLinkGen_RamMemArea vLinkGen_Init_One_Groups[VLINKGEN_CFG_NUM_INIT_ONE_GROUPS] =
{
  { /*  OS_OsApplication_NonTrust_OsCore0_VAR_INIT  */ 
     /*  .Start  */ (uint32)_OS_OsApplication_NonTrust_OsCore0_VAR_INIT_START, 
     /*  .End  */ (uint32)_OS_OsApplication_NonTrust_OsCore0_VAR_INIT_LIMIT, 
     /*  .Romstart  */ (uint32)_OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM_START, 
     /*  .Romend  */ (uint32)_OS_OsApplication_NonTrust_OsCore0_VAR_INIT_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_OsApplication_Trust_OsCore0_VAR_INIT  */ 
     /*  .Start  */ (uint32)_OS_OsApplication_Trust_OsCore0_VAR_INIT_START, 
     /*  .End  */ (uint32)_OS_OsApplication_Trust_OsCore0_VAR_INIT_LIMIT, 
     /*  .Romstart  */ (uint32)_OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM_START, 
     /*  .Romend  */ (uint32)_OS_OsApplication_Trust_OsCore0_VAR_INIT_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_OsApplication_VAR_INIT  */ 
     /*  .Start  */ (uint32)_OS_OsApplication_VAR_INIT_START, 
     /*  .End  */ (uint32)_OS_OsApplication_VAR_INIT_LIMIT, 
     /*  .Romstart  */ (uint32)_OS_OsApplication_VAR_INIT_ROM_START, 
     /*  .Romend  */ (uint32)_OS_OsApplication_VAR_INIT_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_DATA_CORE0_VAR_INIT  */ 
     /*  .Start  */ (uint32)_OS_DATA_CORE0_VAR_INIT_START, 
     /*  .End  */ (uint32)_OS_DATA_CORE0_VAR_INIT_LIMIT, 
     /*  .Romstart  */ (uint32)_OS_DATA_CORE0_VAR_INIT_ROM_START, 
     /*  .Romend  */ (uint32)_OS_DATA_CORE0_VAR_INIT_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_DATA_SHARED_VAR_INIT  */ 
     /*  .Start  */ (uint32)_OS_DATA_SHARED_VAR_INIT_START, 
     /*  .End  */ (uint32)_OS_DATA_SHARED_VAR_INIT_LIMIT, 
     /*  .Romstart  */ (uint32)_OS_DATA_SHARED_VAR_INIT_ROM_START, 
     /*  .Romend  */ (uint32)_OS_DATA_SHARED_VAR_INIT_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  OS_GLOBALSHARED_VAR_INIT  */ 
     /*  .Start  */ (uint32)_OS_GLOBALSHARED_VAR_INIT_START, 
     /*  .End  */ (uint32)_OS_GLOBALSHARED_VAR_INIT_LIMIT, 
     /*  .Romstart  */ (uint32)_OS_GLOBALSHARED_VAR_INIT_ROM_START, 
     /*  .Romend  */ (uint32)_OS_GLOBALSHARED_VAR_INIT_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  data  */ 
     /*  .Start  */ (uint32)_data_START, 
     /*  .End  */ (uint32)_data_LIMIT, 
     /*  .Romstart  */ (uint32)_data_ROM_START, 
     /*  .Romend  */ (uint32)_data_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  sdata  */ 
     /*  .Start  */ (uint32)_sdata_START, 
     /*  .End  */ (uint32)_sdata_LIMIT, 
     /*  .Romstart  */ (uint32)_sdata_ROM_START, 
     /*  .Romend  */ (uint32)_sdata_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  { /*  zdata  */ 
     /*  .Start  */ (uint32)_zdata_START, 
     /*  .End  */ (uint32)_zdata_LIMIT, 
     /*  .Romstart  */ (uint32)_zdata_ROM_START, 
     /*  .Romend  */ (uint32)_zdata_ROM_LIMIT, 
     /*  .Core  */ 0uL, 
     /*  .Alignment  */ 0uL
  }, 
  {
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with concrete data in stage Two */
const vLinkGen_RamMemArea vLinkGen_Init_Two_Groups[VLINKGEN_CFG_NUM_INIT_TWO_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with concrete data in stage Three */
const vLinkGen_RamMemArea vLinkGen_Init_Three_Groups[VLINKGEN_CFG_NUM_INIT_THREE_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Section groups to be initialized with concrete data in stage HardReset */
const vLinkGen_RamMemArea vLinkGen_Init_HardReset_Groups[VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS] =
{
  {
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL, 
    0uL
  }
};

/* Memory region blocks to be initialized with zeros in stage Early */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_BlocksSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS, 
  vLinkGen_ZeroInit_Early_Blocks
};

/* Memory region blocks to be initialized with zeros in stage One */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_BlocksSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS, 
  vLinkGen_ZeroInit_One_Blocks
};

/* Memory region blocks to be initialized with zeros in stage HardReset */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_BlocksSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS, 
  vLinkGen_ZeroInit_HardReset_Blocks
};

/* Section groups to be initialized with zeros in stage Early */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS, 
  vLinkGen_ZeroInit_Early_Groups
};

/* Section groups to be initialized with zeros in stage Zero */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Zero_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS, 
  vLinkGen_ZeroInit_Zero_Groups
};

/* Section groups to be initialized with zeros in stage One */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS, 
  vLinkGen_ZeroInit_One_Groups
};

/* Section groups to be initialized with zeros in stage Two */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Two_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS, 
  vLinkGen_ZeroInit_Two_Groups
};

/* Section groups to be initialized with zeros in stage Three */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Three_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS, 
  vLinkGen_ZeroInit_Three_Groups
};

/* Section groups to be initialized with zeros in stage HardReset */
const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_GroupsSet =
{
  VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS, 
  vLinkGen_ZeroInit_HardReset_Groups
};

/* Section groups to be initialized with concrete data in stage Zero */
const vLinkGen_RamMemAreaSet vLinkGen_Init_Zero_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS, 
  vLinkGen_Init_Zero_Groups
};

/* Section groups to be initialized with concrete data in stage One */
const vLinkGen_RamMemAreaSet vLinkGen_Init_One_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_ONE_GROUPS, 
  vLinkGen_Init_One_Groups
};

/* Section groups to be initialized with concrete data in stage Two */
const vLinkGen_RamMemAreaSet vLinkGen_Init_Two_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_TWO_GROUPS, 
  vLinkGen_Init_Two_Groups
};

/* Section groups to be initialized with concrete data in stage Three */
const vLinkGen_RamMemAreaSet vLinkGen_Init_Three_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_THREE_GROUPS, 
  vLinkGen_Init_Three_Groups
};

/* Section groups to be initialized with concrete data in stage HardReset */
const vLinkGen_RamMemAreaSet vLinkGen_Init_HardReset_GroupsSet =
{
  VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS, 
  vLinkGen_Init_HardReset_Groups
};

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
 *  END OF FILE: vLinkGen_Lcfg.c
 *********************************************************************************************************************/
