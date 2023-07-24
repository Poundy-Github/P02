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
 *             File:  Rte_SOCManager.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <SOCManager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SOCMANAGER_H
# define RTE_SOCMANAGER_H

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

# include "Rte_SOCManager_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_SOCManager_SeekDwnAndPageLPress_Timeout_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_SOCManager_ppSR_SocManager_SystemState;
extern VAR(boolean, RTE_VAR_INIT) Rte_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady;
extern VAR(uint16, RTE_VAR_INIT) Rte_EOL_EOL_KeepDownload_keepDownloadRID;
extern VAR(uint32, RTE_VAR_INIT) Rte_Upgrade_Sd_Upgrade_flag_Element;
extern VAR(DrvGearDisp, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element;
extern VAR(boolean, RTE_VAR_INIT) Rte_DidDataProcess_ppSR_System_Recovery_System_Recovery;
extern VAR(boolean, RTE_VAR_INIT) Rte_Upgrade_ppSR_Upgrade_System_Recovery_System_Recovery;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EOL_KeepDownload_keepDownloadRID (0U)
#  define Rte_InitValue_Rc_Upgrade_flag_Element (0U)
#  define Rte_InitValue_SeekDwnAndPageLPress_Timeout_Element (FALSE)
#  define Rte_InitValue_ppSR_SocManager_SystemState (0U)
#  define Rte_InitValue_rpSR_SOCManager_DrvGearDisp_Element (0U)
#  define Rte_InitValue_rpSR_SOCManager_GearMsgMiss_Element (0U)
#  define Rte_InitValue_rpSR_System_Recovery_System_Recovery (FALSE)
#  define Rte_InitValue_rpSR_Upgrade_System_Recovery_System_Recovery (FALSE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SOCManager_rpSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SOCManager_rpSR_SOCManager_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SOCManager_rpSR_SOCManager_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SOCManager_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_SOCMANAGER_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SOCManager_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EOL_KeepDownload_keepDownloadRID Rte_Read_SOCManager_EOL_KeepDownload_keepDownloadRID
#  define Rte_Read_SOCManager_EOL_KeepDownload_keepDownloadRID(data) (*(data) = Rte_EOL_EOL_KeepDownload_keepDownloadRID, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_Upgrade_flag_Element Rte_Read_SOCManager_Rc_Upgrade_flag_Element
#  define Rte_Read_SOCManager_Rc_Upgrade_flag_Element(data) (*(data) = Rte_Upgrade_Sd_Upgrade_flag_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_Power_Out_SystemStateOut Rte_Read_SOCManager_rpSR_Power_Out_SystemStateOut
#  define Rte_Read_rpSR_SOCManager_DrvGearDisp_Element Rte_Read_SOCManager_rpSR_SOCManager_DrvGearDisp_Element
#  define Rte_Read_SOCManager_rpSR_SOCManager_DrvGearDisp_Element(data) (*(data) = Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SOCManager_GearMsgMiss_Element Rte_Read_SOCManager_rpSR_SOCManager_GearMsgMiss_Element
#  define Rte_Read_SOCManager_rpSR_SOCManager_GearMsgMiss_Element(data) (*(data) = Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SOCManager_SpeedoInfo_Element Rte_Read_SOCManager_rpSR_SOCManager_SpeedoInfo_Element
#  define Rte_Read_rpSR_SOCManager_TachoInfo_Element Rte_Read_SOCManager_rpSR_SOCManager_TachoInfo_Element
#  define Rte_Read_rpSR_System_Recovery_System_Recovery Rte_Read_SOCManager_rpSR_System_Recovery_System_Recovery
#  define Rte_Read_SOCManager_rpSR_System_Recovery_System_Recovery(data) (*(data) = Rte_DidDataProcess_ppSR_System_Recovery_System_Recovery, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_Upgrade_System_Recovery_System_Recovery Rte_Read_SOCManager_rpSR_Upgrade_System_Recovery_System_Recovery
#  define Rte_Read_SOCManager_rpSR_Upgrade_System_Recovery_System_Recovery(data) (*(data) = Rte_Upgrade_ppSR_Upgrade_System_Recovery_System_Recovery, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SeekDwnAndPageLPress_Timeout_Element Rte_Write_SOCManager_SeekDwnAndPageLPress_Timeout_Element
#  define Rte_Write_SOCManager_SeekDwnAndPageLPress_Timeout_Element(data) (Rte_SOCManager_SeekDwnAndPageLPress_Timeout_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SocManager_SystemState Rte_Write_SOCManager_ppSR_SocManager_SystemState
#  define Rte_Write_SOCManager_ppSR_SocManager_SystemState(data) (Rte_SOCManager_ppSR_SocManager_SystemState = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady Rte_Write_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady
#  define Rte_Write_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady(data) (Rte_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_ComEx_GetRxE2EStatus Rte_Call_SOCManager_ComEx_GetRxE2EStatus
#  define Rte_Call_ComEx_SendSignal Rte_Call_SOCManager_ComEx_SendSignal


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ComEx_ReceiveSignal ComEx_ReceiveSignal
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)61)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)61)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_HealthSwitch_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)61, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_ExclusiveArea_SOCManager() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_Exit_ExclusiveArea_SOCManager() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SOCManager_NvBlockNeed_HealthSwitch_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_NvBlockNeed_HealthSwitch_DefaultValue() (Rte_SOCManager_NvBlockNeed_HealthSwitch_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_SOCManager_NvBlockNeed_HealthSwitch_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NvBlockNeed_HealthSwitch_MirrorBlock() \
  (&Rte_SOCManager_NvBlockNeed_HealthSwitch_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SOCManager_START_SEC_CODE
# include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_NvBlockNeed_HealthSwitch_JobFinished NvBlockNeed_HealthSwitch_JobFinished
#  define RTE_RUNNABLE_SOCManager_Init SOCManager_Init
#  define RTE_RUNNABLE_SOCManager_ManFunction SOCManager_ManFunction
# endif

FUNC(void, SOCManager_CODE) NvBlockNeed_HealthSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SOCManager_CODE) SOCManager_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SOCManager_CODE) SOCManager_ManFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SOCManager_STOP_SEC_CODE
# include "SOCManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_NvMService_AC3_Defs_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SOCMANAGER_H */

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
