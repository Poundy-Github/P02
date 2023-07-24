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
 *             File:  Rte_DCM_Server.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <DCM_Server>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DCM_SERVER_H
# define RTE_DCM_SERVER_H

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

# include "Rte_DCM_Server_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DCM_Server_ppSR_DCMServer_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DCM_Server_ppSR_DCMServer_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_DCM_Server_PiDcmUserCondition_Mode(uint8 nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DCM_Server_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DCM_Server_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_DcmRpSR_SG_ABS3_SG_ABS3 Rte_Read_DCM_Server_DcmRpSR_SG_ABS3_SG_ABS3
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_DCM_Server_DcmRpSR_SG_ABS3_SG_ABS3(data) (*(data) = Rte_C_SG_ABS3_0, ((Std_ReturnType)RTE_E_UNCONNECTED))
/* PRQA L:L1 */
#  define Rte_Read_ppSR_DCMServer_SpeedoInfo_Element Rte_Read_DCM_Server_ppSR_DCMServer_SpeedoInfo_Element
#  define Rte_Read_ppSR_DCMServer_TachoInfo_Element Rte_Read_DCM_Server_ppSR_DCMServer_TachoInfo_Element


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_DcmRpSR_SG_ABS3_SG_ABS3 Rte_IsUpdated_DCM_Server_DcmRpSR_SG_ABS3_SG_ABS3
#  define Rte_IsUpdated_DCM_Server_DcmRpSR_SG_ABS3_SG_ABS3() (FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_PiDcmUserCondition_Mode Rte_Switch_DCM_Server_PiDcmUserCondition_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Rte_Call_DCM_Server_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#  define Rte_Call_rpCS_ComEx_GetRxE2EStatus Rte_Call_DCM_Server_rpCS_ComEx_GetRxE2EStatus
#  define Rte_Call_rpCS_ComEx_SendSignal Rte_Call_DCM_Server_rpCS_ComEx_SendSignal


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)51, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)51, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_EOL_UnlockCnt_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)51, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)50, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)50, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeedSecAttemptCount_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)50, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_ComEx_ReceiveSignal ComEx_ReceiveSignal


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DCM_Server_NvBlockNeedSecAttemptCount_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeedSecAttemptCount_DefaultValue() (&(Rte_DCM_Server_NvBlockNeedSecAttemptCount_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeedSecAttemptCount_DefaultValue() (&Rte_DCM_Server_NvBlockNeedSecAttemptCount_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_EOLUnlockCnt_DefaultValue() (&(Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_EOLUnlockCnt_DefaultValue() (&Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeedSecAttemptCount_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeedSecAttmptCount_MirrorBlock;
extern VAR(A_200Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock;
extern VAR(A_17Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeed_Dcm_VIN_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeedSecAttemptCount_MirrorBlock() (&((*RtePim_NvBlockNeedSecAttemptCount_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeedSecAttemptCount_MirrorBlock() RtePim_NvBlockNeedSecAttemptCount_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeedSecAttemptCount_MirrorBlock() \
  (&Rte_DCM_Server_NvBlockNeedSecAttemptCount_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeedSecAttmptCount_MirrorBlock() (&((*RtePim_NvBlockNeedSecAttmptCount_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeedSecAttmptCount_MirrorBlock() RtePim_NvBlockNeedSecAttmptCount_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeedSecAttmptCount_MirrorBlock() \
  (&Rte_DCM_Server_NvBlockNeedSecAttmptCount_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock() (&((*RtePim_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock() RtePim_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock() \
  (&Rte_DCM_Server_NvBlockNeed_Dcm_ECUlevelNetworkConfigurationDataIdentifier_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_Dcm_VIN_MirrorBlock() (&((*RtePim_NvBlockNeed_Dcm_VIN_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_Dcm_VIN_MirrorBlock() RtePim_NvBlockNeed_Dcm_VIN_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_Dcm_VIN_MirrorBlock() \
  (&Rte_DCM_Server_NvBlockNeed_Dcm_VIN_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_EOLUnlockCnt_MirrorBlock() (&((*RtePim_NvBlockNeed_EOLUnlockCnt_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_EOLUnlockCnt_MirrorBlock() RtePim_NvBlockNeed_EOLUnlockCnt_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_EOLUnlockCnt_MirrorBlock() \
  (&Rte_DCM_Server_NvBlockNeed_EOLUnlockCnt_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define DCM_Server_START_SEC_CODE
# include "DCM_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DCM_Server_Init DCM_Server_Init
#  define RTE_RUNNABLE_DCM_Server_MainFunction DCM_Server_MainFunction
#  define RTE_RUNNABLE_SecurityAccess_Level_EOL_Unlocked_CompareKey SecurityAccess_Level_EOL_Unlocked_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter
#  define RTE_RUNNABLE_SecurityAccess_Level_EOL_Unlocked_GetSeed SecurityAccess_Level_EOL_Unlocked_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter
#  define RTE_RUNNABLE_SecurityAccess_UnlockedL1_CompareKey SecurityAccess_UnlockedL1_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_UnlockedL1_GetSecurityAttemptCounter SecurityAccess_UnlockedL1_GetSecurityAttemptCounter
#  define RTE_RUNNABLE_SecurityAccess_UnlockedL1_GetSeed SecurityAccess_UnlockedL1_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_UnlockedL1_SetSecurityAttemptCounter SecurityAccess_UnlockedL1_SetSecurityAttemptCounter
#  define RTE_RUNNABLE_ServiceRequestNotificationGwm_Confirmation ServiceRequestNotificationGwm_Confirmation
#  define RTE_RUNNABLE_ServiceRequestNotificationGwm_Indication ServiceRequestNotificationGwm_Indication
# endif

FUNC(void, DCM_Server_CODE) DCM_Server_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DCM_Server_CODE) DCM_Server_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_CompareKey(P2CONST(Dcm_Data8ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) AttemptCounter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_CompareKey(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) AttemptCounter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DCM_Server_CODE) SecurityAccess_UnlockedL1_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DCM_Server_CODE) ServiceRequestNotificationGwm_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DCM_Server_CODE) ServiceRequestNotificationGwm_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DCM_Server_CODE) ServiceRequestNotificationGwm_Indication(uint8 SID, P2CONST(Dcm_Data4095ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define DCM_Server_STOP_SEC_CODE
# include "DCM_Server_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DCM_SERVER_H */

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
