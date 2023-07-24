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
 *             File:  Rte_Misc.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Misc>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_MISC_H
# define RTE_MISC_H

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
# include "Rte_Misc_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount;
extern VAR(uint8, RTE_VAR_INIT) Rte_Power_IVI_10MIN_Backup_flag_Element;
extern VAR(reset_type, RTE_VAR_INIT) Rte_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource;
extern VAR(DrvGearDisp, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element;
extern VAR(uint8, RTE_VAR_INIT) Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element;
extern VAR(uint32, RTE_VAR_INIT) Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EOL_ReadGPSSatelliteCount_GPSSatelliteCount (0U)
#  define Rte_InitValue_IVI_10MIN_Backup_flag_Element (0U)
#  define Rte_InitValue_Rc_ResetReason_ResetSource (0U)
#  define Rte_InitValue_rpSR_piDiagMonitorReInitFlag_ChangeCounter (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Misc_tiSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_MISC_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(P2CONST(uint8, AUTOMATIC, RTE_MISC_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(P2CONST(EOL3Bytes, AUTOMATIC, RTE_MISC_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Misc_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_MISC_APPL_VAR) Value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Misc_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_MISC_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_MISC_APPL_VAR) ElapsedValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_IVI_10MIN_Backup_flag_Element Rte_Read_Misc_IVI_10MIN_Backup_flag_Element
#  define Rte_Read_Misc_IVI_10MIN_Backup_flag_Element(data) (*(data) = Rte_Power_IVI_10MIN_Backup_flag_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_ResetReason_ResetSource Rte_Read_Misc_Rc_ResetReason_ResetSource
#  define Rte_Read_Misc_Rc_ResetReason_ResetSource(data) (*(data) = Rte_BswM_Provide_BswMRteModeRequestPort_ResetReason_ResetSource, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_Misc_DrvGearDisp_Element Rte_Read_Misc_rpSR_Misc_DrvGearDisp_Element
#  define Rte_Read_Misc_rpSR_Misc_DrvGearDisp_Element(data) (*(data) = Rte_Common_Safety_ppSR_SWCSafety_DrvGearDisp_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_Misc_GearMsgMiss_Element Rte_Read_Misc_rpSR_Misc_GearMsgMiss_Element
#  define Rte_Read_Misc_rpSR_Misc_GearMsgMiss_Element(data) (*(data) = Rte_Common_Safety_ppSR_SWCSafety_GearMsgMiss_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter Rte_Read_Misc_rpSR_piDiagMonitorReInitFlag_ChangeCounter
#  define Rte_Read_Misc_rpSR_piDiagMonitorReInitFlag_ChangeCounter(data) (*(data) = Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_tiSR_Power_Out_SystemStateOut Rte_Read_Misc_tiSR_Power_Out_SystemStateOut


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0 Rte_Write_Misc_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0
#  define Rte_Write_EOL_ReadGPSSatelliteCount_GPSSatelliteCount Rte_Write_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount
#  define Rte_Write_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount(data) (Rte_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_Os_Service_GetCounterValue Rte_Call_Misc_Os_Service_GetCounterValue
#  define Rte_Call_Os_Service_GetElapsedValue Rte_Call_Misc_Os_Service_GetElapsedValue


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FM1_OpenCircuit_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)118, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FM1_OverCurrent_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)119, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FM1_ShortToBattary_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)120, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FM1_ShortToGround_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)121, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FM2_OpenCircuit_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)122, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FM2_OverCurrent_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)123, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FM2_ShortToBattary_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)124, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FM2_ShortToGround_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)125, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_GNSS_OpenCircuit_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)210, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_GNSS_OverCurrent_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)213, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_GNSS_ShortToBattary_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)212, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_GNSS_ShortToGround_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)211, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Mic_1_open_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)48, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Mic_1_short_to_BAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)50, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Mic_1_short_to_GND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)51, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Mic_2_open_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)52, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Mic_2_short_to_BAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_Mic_2_short_to_GND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)54, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_RVC_CamerShortToBattery_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)184, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_RVC_CameraOpenCircuit_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)186, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_RVC_CameraShortToGround_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)182, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetVoltage(uint8 Id, P2VAR(uint32, AUTOMATIC, RTE_VAR_NOINIT) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAb_Interface_GetVoltage IoHwAb_GetVoltage
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetPin(uint8 Id, boolean Digital); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IoHwAb_Interface_SetPin IoHwAb_SetPin
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)49)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)49, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)49)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)49, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)49, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_Defs_NvBlockNeed_ResetInfomation_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)49, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_VCONFIG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_VCONFIG_APPL_CODE) VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_VCONFIG_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rcCS_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig VConfig_GetKindConfig_Operation_VConfig_GetKindConfig
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_Mics_ComEx_ReceiveSignal ComEx_ReceiveSignal


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_ExclusiveArea_Misc() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#  define Rte_Exit_ExclusiveArea_Misc() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */ /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(NvmResetInformation_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Misc_NvBlockNeed_ResetInfomation_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_ResetInfomation_DefaultValue() (&(Rte_Misc_NvBlockNeed_ResetInfomation_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_ResetInfomation_DefaultValue() (&Rte_Misc_NvBlockNeed_ResetInfomation_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(NvmResetInformation_t, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Misc_NvBlockNeed_ResetInfomation_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_ResetInfomation_MirrorBlock() (&((*RtePim_NvBlockNeed_ResetInfomation_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_ResetInfomation_MirrorBlock() RtePim_NvBlockNeed_ResetInfomation_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_ResetInfomation_MirrorBlock() \
  (&Rte_Misc_NvBlockNeed_ResetInfomation_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Misc_START_SEC_CODE
# include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EOL_0xFD16_EOL_FactoryReset EOL_0xFD16_EOL_FactoryReset
#  define RTE_RUNNABLE_EOL_0xFDD1_EOL_ReadMICStatus EOL_0xFDD1_EOL_ReadMICStatus
#  define RTE_RUNNABLE_EOL_0xFDD9_EOL_WriteValueForDispalyEnable EOL_0xFDD9_EOL_WriteValueForDispalyEnable
#  define RTE_RUNNABLE_EOL_0xFDE1_EOL_ReadWatchDogCnt EOL_0xFDE1_EOL_ReadWatchDogCnt
#  define RTE_RUNNABLE_EOL_0xFDE2_EOL_ReadResetInformation EOL_0xFDE2_EOL_ReadResetInformation
#  define RTE_RUNNABLE_Misc_Init Misc_Init
#  define RTE_RUNNABLE_Misc_MainFunction Misc_MainFunction
#  define RTE_RUNNABLE_Misc_MainFunction_100ms Misc_MainFunction_100ms
#  define RTE_RUNNABLE_Misc_MainFunction_500ms Misc_MainFunction_500ms
#  define RTE_RUNNABLE_Misc_MainFunction_50ms Misc_MainFunction_50ms
#  define RTE_RUNNABLE_NVM_Read_Speedup_Runnable NVM_Read_Speedup_Runnable
#  define RTE_RUNNABLE_WdgM_GlobalStatusCallback WdgM_GlobalStatusCallback
#  define RTE_RUNNABLE_WdgM_LocalStatusCallback_Gear WdgM_LocalStatusCallback_Gear
#  define RTE_RUNNABLE_WdgM_LocalStatusCallback_Power WdgM_LocalStatusCallback_Power
#  define RTE_RUNNABLE_WdgM_LocalStatusCallback_TT WdgM_LocalStatusCallback_TT
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Misc_CODE) EOL_0xFD16_EOL_FactoryReset(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Misc_CODE) EOL_0xFD16_EOL_FactoryReset(P2VAR(A_1Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Misc_CODE) EOL_0xFDD1_EOL_ReadMICStatus(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Misc_CODE) EOL_0xFDD1_EOL_ReadMICStatus(P2VAR(EOL_3Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Misc_CODE) EOL_0xFDD9_EOL_WriteValueForDispalyEnable(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Misc_CODE) EOL_0xFDD9_EOL_WriteValueForDispalyEnable(P2VAR(EOL_2Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Misc_CODE) EOL_0xFDE1_EOL_ReadWatchDogCnt(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Misc_CODE) EOL_0xFDE1_EOL_ReadWatchDogCnt(P2VAR(EOL_4Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Misc_CODE) EOL_0xFDE2_EOL_ReadResetInformation(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, Misc_CODE) EOL_0xFDE2_EOL_ReadResetInformation(P2VAR(EOL_64Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, Misc_CODE) Misc_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Misc_CODE) Misc_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Misc_CODE) Misc_MainFunction_100ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Misc_CODE) Misc_MainFunction_500ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Misc_CODE) Misc_MainFunction_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Misc_CODE) NVM_Read_Speedup_Runnable(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Misc_CODE) WdgM_GlobalStatusCallback(WdgM_GlobalStatusType Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Misc_CODE) WdgM_LocalStatusCallback_Gear(WdgM_LocalStatusType Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Misc_CODE) WdgM_LocalStatusCallback_Power(WdgM_LocalStatusType Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Misc_CODE) WdgM_LocalStatusCallback_TT(WdgM_LocalStatusType Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Misc_STOP_SEC_CODE
# include "Misc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_IoHwAb_Interface_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_Defs_E_NOT_OK (1U)

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_Os_Service_E_OS_VALUE (8U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_MISC_H */

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
