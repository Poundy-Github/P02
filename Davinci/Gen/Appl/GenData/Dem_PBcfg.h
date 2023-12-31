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
 *            Module: Dem
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_PBcfg.h
 *   Generation Time: 2021-06-16 10:34:04
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DemEnableConditionGroupRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dem/DemConfigSet/Lost_communication_with_AVM_Missing_Message/DemEventClass[0:DemEnableConditionGroupRef](value={empty}) (DefRef: /MICROSAR/Dem/DemConfigSet/DemEventParameter/DemEventClass/DemEnableConditionGroupRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DemEnableConditionGroupRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dem/DemConfigSet/Over_voltage_Circuit_Voltage_Above_Threshold/DemEventClass[0:DemEnableConditionGroupRef](value={empty}) (DefRef: /MICROSAR/Dem/DemConfigSet/DemEventParameter/DemEventClass/DemEnableConditionGroupRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DemEnableConditionGroupRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dem/DemConfigSet/Under_voltage_Circuit_Voltage_Below_Threshold/DemEventClass[0:DemEnableConditionGroupRef](value={empty}) (DefRef: /MICROSAR/Dem/DemConfigSet/DemEventParameter/DemEventClass/DemEnableConditionGroupRef)
 *********************************************************************************************************************/

/* configuration, interrupt handling and callback headers use different names
 * for the multiple inclusion protection define, shown in this example. The
 * appropriate names for these files can be taken from this list:
 *
 * Dem_Cfg.h:                   DEM_CFG_H
 * Dem_Lcfg.h:                  DEM_LCFG_H
 * Dem_PBcfg.h:                 DEM_PBFG_H
 * Dem_AdditionalIncludeCfg.h:  DEM_ADDITIONALINCLUDECFG_H
 * Dem_Swc.h:                   DEM_SWC_H
 * Dem_Swc_Types.h:             DEM_SWC_TYPES_H
 */
#if !defined (DEM_PBCFG_H)
# define DEM_PBCFG_H

/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */                                          /* Identifier does not differ in 32 significant characters. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPBDataSwitches  Dem_Cfg Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define DEM_PBCONFIG                                                                                STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is COMPILETIME_CHECKING. */
#define DEM_CFG_LTCONFIGIDXOFPBCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is COMPILETIME_CHECKING. */
#define DEM_CFG_PCCONFIGIDXOFPBCONFIG                                                               STD_ON  /**< This preprocessing switch is always STD_ON because the PrecompilePreprocessingStrategy is COMPILETIME_CHECKING. */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPBIsReducedToDefineDefines  Dem_Cfg Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define DEM_CFG_ISDEF_LTCONFIGIDXOFPBCONFIG                                                         STD_OFF
#define DEM_CFG_ISDEF_PCCONFIGIDXOFPBCONFIG                                                         STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPBEqualsAlwaysToDefines  Dem_Cfg Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define DEM_CFG_EQ2_LTCONFIGIDXOFPBCONFIG                                                           
#define DEM_CFG_EQ2_PCCONFIGIDXOFPBCONFIG                                                           
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPBGetRootDataMacros  Dem_Cfg Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Dem_Cfg_GetLTConfigIdxOfPBConfig()                                                          0u
#define Dem_Cfg_GetPCConfigIdxOfPBConfig()                                                          0u
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPBHasMacros  Dem_Cfg Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Dem_HasPBConfig()                                                                           (FALSE != FALSE)
#define Dem_Cfg_HasLTConfigIdxOfPBConfig()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasPCConfigIdxOfPBConfig()                                                          (FALSE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/* PRQA S 3453 ROOT_TYPE_0850 */ /* MD_MSR_MacroArgumentEmpty */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPBValueTypes  Dem_Cfg Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Dem_Cfg_LTConfigIdxOfPBConfig */
typedef uint8 Dem_Cfg_LTConfigIdxOfPBConfigType;

/**   \brief  value based type definition for Dem_Cfg_PCConfigIdxOfPBConfig */
typedef uint8 Dem_Cfg_PCConfigIdxOfPBConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPBRootValueTypes  Dem_Cfg Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Dem_PBConfig */
typedef struct sDem_PBConfigType
{
  uint8 Dem_PBConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_PBConfigType;

/** 
  \}
*/ 


/* PRQA L:ROOT_TYPE_0850 */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  Justification of MISRA deviations
**********************************************************************************************************************/


#endif  /* DEM_PBCFG_H */
/**********************************************************************************************************************
  END OF FILE: Dem_PBcfg.h     [Vector, VARIANT-PRE-COMPILE, 19.00.00.118535]
**********************************************************************************************************************/

