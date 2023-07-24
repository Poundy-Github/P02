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
 *             File:  Rte_CConfig.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <CConfig>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CCONFIG_H
# define RTE_CCONFIG_H

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

# include "Rte_CConfig_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CConfig_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(P2VAR(uint8, AUTOMATIC, RTE_CCONFIG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CConfig_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(P2VAR(Dcm_Data300ByteType, AUTOMATIC, RTE_CCONFIG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2CONST(uint8, AUTOMATIC, RTE_CCONFIG_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(P2CONST(CconfigKind_400Bytes, AUTOMATIC, RTE_CCONFIG_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag Rte_Read_CConfig_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag
#  define Rte_Read_CConfig_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(data) (*(data) = Rte_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_ECUlevelCConfigurationDataIdentifier_300Bytes_Element Rte_Read_CConfig_ECUlevelCConfigurationDataIdentifier_300Bytes_Element


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes Rte_Write_CConfig_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes
#  define Rte_Write_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag Rte_Write_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag
#  define Rte_Write_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(data) (Rte_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


# endif /* !defined(RTE_CORE) */


# define CConfig_START_SEC_CODE
# include "CConfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick
#  define RTE_RUNNABLE_CConfig_Init CConfig_Init
#  define RTE_RUNNABLE_CConfig_MainFunction CConfig_MainFunction
# endif

FUNC(Std_ReturnType, CConfig_CODE) CConfig_GetUpdateTick_OperationCConfig_GetUpdateTick(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_CCONFIG_APPL_VAR) updateTick); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CConfig_CODE) CConfig_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CConfig_CODE) CConfig_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define CConfig_STOP_SEC_CODE
# include "CConfig_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CConfig_GetUpdateTick_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CCONFIG_H */

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
