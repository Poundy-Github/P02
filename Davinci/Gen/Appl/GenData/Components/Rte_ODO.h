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
 *             File:  Rte_ODO.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <ODO>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ODO_H
# define RTE_ODO_H

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
# include "Rte_ODO_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ODO_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ODO_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ODO_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_ODO_APPL_VAR) Value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_ODO_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_ODO_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_ODO_APPL_VAR) ElapsedValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock Rte_Call_ODO_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_ReadBlock
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock Rte_Call_ODO_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_WriteBlock
#  define Rte_Call_Os_Service_GetCounterValue Rte_Call_ODO_Os_Service_GetCounterValue
#  define Rte_Call_Os_Service_GetElapsedValue Rte_Call_ODO_Os_Service_GetElapsedValue


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)13)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)13, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)13)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)13, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_1_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)13, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)14)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)14, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)14)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)14, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)14, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)14, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_2_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)14, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)15)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)15, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)15)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)15, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)15, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)15, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_3_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)15, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)16)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)16, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)16)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)16, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)16, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)16, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_4_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)16, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)17)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)17, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)17)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)17, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)17, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)17, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC3_SRBS_Defs_NvBlockNeed_Block_ODO_5_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)17, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_1_DefaultValue;
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_2_DefaultValue;
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_3_DefaultValue;
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_4_DefaultValue;
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_5_DefaultValue;
extern CONST(NVMBlockMaintain_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_ODO_NvBlockNeed_Block_MaintainOdo_DefaultValue;
extern CONST(NVMBlockTrip, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_ODO_NvBlockNeed_Block_Trip_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_NvBlockNeed_Block_ODO_1_DefaultValue() (Rte_ODO_NvBlockNeed_Block_ODO_1_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_CData_NvBlockNeed_Block_ODO_2_DefaultValue() (Rte_ODO_NvBlockNeed_Block_ODO_2_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_CData_NvBlockNeed_Block_ODO_3_DefaultValue() (Rte_ODO_NvBlockNeed_Block_ODO_3_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_CData_NvBlockNeed_Block_ODO_4_DefaultValue() (Rte_ODO_NvBlockNeed_Block_ODO_4_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_CData_NvBlockNeed_Block_ODO_5_DefaultValue() (Rte_ODO_NvBlockNeed_Block_ODO_5_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_MaintainOdo_DefaultValue() (&(Rte_ODO_NvBlockNeed_Block_MaintainOdo_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_MaintainOdo_DefaultValue() (&Rte_ODO_NvBlockNeed_Block_MaintainOdo_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_Block_Trip_DefaultValue() (&(Rte_ODO_NvBlockNeed_Block_Trip_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_Block_Trip_DefaultValue() (&Rte_ODO_NvBlockNeed_Block_Trip_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_1_MirrorBlock;
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_2_MirrorBlock;
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_3_MirrorBlock;
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_4_MirrorBlock;
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_ODO_NvBlockNeed_Block_ODO_5_MirrorBlock;
extern VAR(NVMBlockMaintain_Type, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_ODO_NvBlockNeed_Block_MaintainOdo_MirrorBlock;
extern VAR(NVMBlockTrip, RTE_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP) Rte_ODO_NvBlockNeed_Block_Trip_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_NonTrust_OsCore0_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvBlockNeed_Block_ODO_1_MirrorBlock() \
  (&Rte_ODO_NvBlockNeed_Block_ODO_1_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvBlockNeed_Block_ODO_2_MirrorBlock() \
  (&Rte_ODO_NvBlockNeed_Block_ODO_2_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvBlockNeed_Block_ODO_3_MirrorBlock() \
  (&Rte_ODO_NvBlockNeed_Block_ODO_3_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvBlockNeed_Block_ODO_4_MirrorBlock() \
  (&Rte_ODO_NvBlockNeed_Block_ODO_4_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvBlockNeed_Block_ODO_5_MirrorBlock() \
  (&Rte_ODO_NvBlockNeed_Block_ODO_5_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_MaintainOdo_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_MaintainOdo_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_MaintainOdo_MirrorBlock() RtePim_NvBlockNeed_Block_MaintainOdo_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_MaintainOdo_MirrorBlock() \
  (&Rte_ODO_NvBlockNeed_Block_MaintainOdo_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Block_Trip_MirrorBlock() (&((*RtePim_NvBlockNeed_Block_Trip_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Block_Trip_MirrorBlock() RtePim_NvBlockNeed_Block_Trip_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Block_Trip_MirrorBlock() \
  (&Rte_ODO_NvBlockNeed_Block_Trip_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define ODO_START_SEC_CODE
# include "ODO_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished
#  define RTE_RUNNABLE_ODO_Init ODO_Init
#  define RTE_RUNNABLE_ODO_MainFunction ODO_MainFunction
#  define RTE_RUNNABLE_Odo_Api_IrqTimeTask Odo_Api_IrqTimeTask
#  define RTE_RUNNABLE_Odo_Api_PkgRrobinTask Odo_Api_PkgRrobinTask
#  define RTE_RUNNABLE_Odo_Api_TimeTask Odo_Api_TimeTask
# endif

FUNC(void, ODO_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_MaintainOdo_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ODO_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ODO_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ODO_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_3_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ODO_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_4_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ODO_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_ODO_5_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ODO_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_Trip_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ODO_CODE) ODO_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ODO_CODE) ODO_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ODO_CODE) Odo_Api_IrqTimeTask(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ODO_CODE) Odo_Api_PkgRrobinTask(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ODO_CODE) Odo_Api_TimeTask(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define ODO_STOP_SEC_CODE
# include "ODO_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_Os_Service_E_OS_VALUE (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ODO_H */

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
