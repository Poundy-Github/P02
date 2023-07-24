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
 *            Module: WdgIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgIf_Lcfg.c
 *   Generation Time: 2020-09-24 10:30:05
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.32 SP1
 *
 *
 *********************************************************************************************************************/

#define WDGIF_LCFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SRV_Wdg.h" 
#include "WdgIf_Lcfg.h" 
#include "WdgIf.h" 


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGIF_LCFG_C_MAJOR_VERSION (2u) 
#define WDGIF_LCFG_C_MINOR_VERSION (2u) 
#define WDGIF_LCFG_C_PATCH_VERSION (1u) 

/* Check the version of WdgIf header file */
#if ( (WDGIF_SW_MAJOR_VERSION != (5u)) \
   || (WDGIF_SW_MINOR_VERSION != (4u)) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf.h are inconsistent!"
#endif

/* Check the version of WdgIf_Lcfg header file */
#if ( (WDGIF_LCFG_MAJOR_VERSION != WDGIF_LCFG_C_MAJOR_VERSION) \
   || (WDGIF_LCFG_MINOR_VERSION != WDGIF_LCFG_C_MINOR_VERSION) \
   || (WDGIF_LCFG_PATCH_VERSION != WDGIF_LCFG_C_PATCH_VERSION) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf_Lcfg.h are inconsistent!"
#endif

#if !defined (WDGIF_LOCAL) /* COV_WDGIF_COMPATIBILITY */
# define WDGIF_LOCAL static
#endif

#define WDGIF_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

WDGIF_LOCAL const WdgIf_InterfaceFunctionsType wdgifdevice_functions = 
{
  SRV_Wdg_SetMode /*  Wdg_SetMode  */ , 
  SRV_Wdg_SetTriggerCondition /*  Wdg_SetTriggerCondition  */ 
}; /* WdgGeneral */ 


WDGIF_LOCAL const WdgIf_InterfaceFunctionsPerWdgDeviceType WdgIf_FunctionsPerWdg [WDGIF_NUMBER_OF_WDGIFDEVICES] =
{
  {
    &wdgifdevice_functions /*  WdgFunctions  */ 
  } /*  [0]  */ 
};

const WdgIf_InterfaceType WdgIf_Interface =
{
  WDGIF_NUMBER_OF_WDGIFDEVICES /*  NumOfWdgs  */ , 
  WdgIf_FunctionsPerWdg /*  WdgFunctionsPerDevice  */ 
};

#define WDGIF_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  END OF FILE: WdgIf_Lcfg.c
 *********************************************************************************************************************/

