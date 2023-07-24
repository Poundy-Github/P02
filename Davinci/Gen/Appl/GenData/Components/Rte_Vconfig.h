/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Vconfig.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Vconfig>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_VCONFIG_H
# define RTE_VCONFIG_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Os.h"
# include "Rte_Vconfig_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Vconfig_VconfigResponseFlag_VconfigResponseFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag (0U)
#  define Rte_InitValue_VconfigResponseFlag_VconfigResponseFlag (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Vconfig_ECUlevelNetworkConfigurationDataIdentifier_Element(P2VAR(uint8, AUTOMATIC, RTE_VCONFIG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Vconfig_ECUlevelNetworkConfigurationDataIdentifier_Element(P2VAR(Dcm_Data200ByteType, AUTOMATIC, RTE_VCONFIG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Vconfig_Vconfig_GetKindBuffers_AllKinds(P2CONST(uint8, AUTOMATIC, RTE_VCONFIG_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Vconfig_Vconfig_GetKindBuffers_AllKinds(P2CONST(VconfigKind_Allbuffers, AUTOMATIC, RTE_VCONFIG_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Vconfig_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_VCONFIG_APPL_VAR) Value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ECUlevelNetworkConfigurationDataIdentifier_Element Rte_Read_Vconfig_ECUlevelNetworkConfigurationDataIdentifier_Element
#  define Rte_Read_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag Rte_Read_Vconfig_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag
#  define Rte_Read_Vconfig_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(data) (*(data) = Rte_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_VconfigResponseFlag_VconfigResponseFlag Rte_Write_Vconfig_VconfigResponseFlag_VconfigResponseFlag
#  define Rte_Write_Vconfig_VconfigResponseFlag_VconfigResponseFlag(data) (Rte_Vconfig_VconfigResponseFlag_VconfigResponseFlag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_Vconfig_GetKindBuffers_AllKinds Rte_Write_Vconfig_Vconfig_GetKindBuffers_AllKinds


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_Os_Service_GetCounterValue Rte_Call_Vconfig_Os_Service_GetCounterValue


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length, uint8 OpStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_USBWriteECUlevelNetworkConfigurationData_USBWriteData ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData


# endif /* !defined(RTE_CORE) */


# define Vconfig_START_SEC_CODE
# include "Vconfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#  define RTE_RUNNABLE_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick
#  define RTE_RUNNABLE_VConfig_MainFunction VConfig_MainFunction
# endif

FUNC(Std_ReturnType, Vconfig_CODE) VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Vconfig_CODE) VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_VAR_NOINIT) updateTick); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Vconfig_CODE) VConfig_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Vconfig_STOP_SEC_CODE
# include "Vconfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK (1U)

#  define RTE_E_USBWriteECUlevelNetworkConfigurationData_E_OK (0U)

#  define RTE_E_USBWriteECUlevelNetworkConfigurationData_E_PENDING (10U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)

#  define RTE_E_VConfig_GetUpdateTick_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_VCONFIG_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
