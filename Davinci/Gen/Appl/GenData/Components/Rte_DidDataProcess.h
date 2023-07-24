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
 *             File:  Rte_DidDataProcess.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <DidDataProcess>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DIDDATAPROCESS_H
# define RTE_DIDDATAPROCESS_H

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

# include "Rte_DidDataProcess_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element;
extern VAR(boolean, RTE_VAR_INIT) Rte_DidDataProcess_ppSR_System_Recovery_System_Recovery;
extern VAR(uint8, RTE_VAR_INIT) Rte_Vconfig_VconfigResponseFlag_VconfigResponseFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag (0U)
#  define Rte_InitValue_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag (0U)
#  define Rte_InitValue_VconfigResponseFlag_VconfigResponseFlag (0U)
#  define Rte_InitValue_piSR_E2ESwitchChangeTrigger_Element (0U)
#  define Rte_InitValue_ppSR_System_Recovery_System_Recovery (FALSE)
#  define Rte_InitValue_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_SR_RpVehSparePartNumber_SparePartNumber(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_SR_RpVehSparePartNumber_SparePartNumber(P2VAR(EOL_13Bytes, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_Vconfig_GetKindBuffers_AllKinds(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_Vconfig_GetKindBuffers_AllKinds(P2VAR(VconfigKind_Allbuffers, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_ppSR_Diag_SpeedoInfo_Element(P2VAR(s_SpeedoInfo_t, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_ppSR_Diag_TachoInfo_Element(P2VAR(s_TachoInfo_t, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_rpSR_OdoParament_Element(P2VAR(s_OdoRteGetParament_t, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DidDataProcess_rpSR_Power_Out_DidProcess_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element(P2CONST(Dcm_Data200ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element(P2CONST(Dcm_Data300ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_tiSR_VIN_Element(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DidDataProcess_tiSR_VIN_Element(P2CONST(A_17Bytes, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(uint8, RTE_CODE) Rte_Mode_DidDataProcess_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DidDataProcess_rpCS_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DidDataProcess_rpCS_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation(P2VAR(Diag_9Bytes, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_SR_RpVehSparePartNumber_SparePartNumber Rte_Read_DidDataProcess_SR_RpVehSparePartNumber_SparePartNumber
#  define Rte_Read_VconfigResponseFlag_VconfigResponseFlag Rte_Read_DidDataProcess_VconfigResponseFlag_VconfigResponseFlag
#  define Rte_Read_DidDataProcess_VconfigResponseFlag_VconfigResponseFlag(data) (*(data) = Rte_Vconfig_VconfigResponseFlag_VconfigResponseFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Vconfig_GetKindBuffers_AllKinds Rte_Read_DidDataProcess_Vconfig_GetKindBuffers_AllKinds
#  define Rte_Read_ppSR_Diag_SpeedoInfo_Element Rte_Read_DidDataProcess_ppSR_Diag_SpeedoInfo_Element
#  define Rte_Read_ppSR_Diag_TachoInfo_Element Rte_Read_DidDataProcess_ppSR_Diag_TachoInfo_Element
#  define Rte_Read_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag Rte_Read_DidDataProcess_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag
#  define Rte_Read_DidDataProcess_rpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag(data) (*(data) = Rte_CConfig_tpSR_ClusterConfigResponseFlag_ClusterConfigResponseFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_OdoParament_Element Rte_Read_DidDataProcess_rpSR_OdoParament_Element
#  define Rte_Read_rpSR_Power_Out_DidProcess_SystemStateOut Rte_Read_DidDataProcess_rpSR_Power_Out_DidProcess_SystemStateOut


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag Rte_Write_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag
#  define Rte_Write_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag(data) (Rte_DidDataProcess_CconfigRequestUpdateFlag_CconfigRequestUpdateFlag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ECUlevelNetworkConfigurationDataIdentifier_Element Rte_Write_DidDataProcess_ECUlevelNetworkConfigurationDataIdentifier_Element
#  define Rte_Write_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag Rte_Write_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag
#  define Rte_Write_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag(data) (Rte_DidDataProcess_VconfigRequestUpdateFlag_VconfigRequestUpdateFlag = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_piSR_E2ESwitchChangeTrigger_Element Rte_Write_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element
#  define Rte_Write_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element(data) (Rte_DidDataProcess_piSR_E2ESwitchChangeTrigger_Element = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_piSR_SecOcSwitchChangeTrigger_Element Rte_Write_DidDataProcess_piSR_SecOcSwitchChangeTrigger_Element
#  define Rte_Write_DidDataProcess_piSR_SecOcSwitchChangeTrigger_Element(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element Rte_Write_DidDataProcess_ppSR_ECUlevelCConfigurationDataIdentifier_300Bytes_Element
#  define Rte_Write_ppSR_System_Recovery_System_Recovery Rte_Write_DidDataProcess_ppSR_System_Recovery_System_Recovery
#  define Rte_Write_DidDataProcess_ppSR_System_Recovery_System_Recovery(data) (Rte_DidDataProcess_ppSR_System_Recovery_System_Recovery = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_tiSR_VIN_Element Rte_Write_DidDataProcess_tiSR_VIN_Element


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Mode_DidDataProcess_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_rpCS_ComEx_GetRxE2EStatus Rte_Call_DidDataProcess_rpCS_ComEx_GetRxE2EStatus
#  define Rte_Call_rpCS_ComEx_SendSignal Rte_Call_DidDataProcess_rpCS_ComEx_SendSignal
#  define Rte_Call_rpCS_Fuel_Api_ParamentGetCsPort_Operation Rte_Call_DidDataProcess_rpCS_Fuel_Api_ParamentGetCsPort_Operation


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CAN_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_CAN_SERVER_APPL_CODE) Can_Server_AbnormalWakeupSleepRecord_Get(P2VAR(uint8, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_CAN_SERVER_APPL_CODE) Can_Server_AbnormalWakeupSleepRecord_Get(P2VAR(A_80Bytes, AUTOMATIC, RTE_CAN_SERVER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_CAN_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Can_Server_AbnormalWakeupSleepRecord_Get(arg1) (Can_Server_AbnormalWakeupSleepRecord_Get(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DCMServices_GetActiveProtocol Dcm_GetActiveProtocol
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetRequestKind(uint16 TesterSourceAddress, P2VAR(Dcm_RequestKindType, AUTOMATIC, RTE_DCM_APPL_VAR) RequestKind); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DCMServices_GetRequestKind Dcm_GetRequestKind
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DCMServices_GetSecurityLevel Dcm_GetSecurityLevel
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DCMServices_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_ResetToDefaultSession(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DCMServices_ResetToDefaultSession Dcm_ResetToDefaultSession
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_SetActiveDiagnostic(boolean active); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DCMServices_SetActiveDiagnostic Dcm_SetActiveDiagnostic
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetDTCOfEvent(Dem_EventIdType parg0, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DTCOfEvent); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetDTCOfEvent(arg1, arg2) (Dem_GetDTCOfEvent((Dem_EventIdType)172, arg1, arg2)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType parg0, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (Dem_GetEventExtendedDataRecordEx((Dem_EventIdType)172, arg1, arg2, arg3)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFailed(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) EventFailed); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventFailed(arg1) (Dem_GetEventFailed((Dem_EventIdType)172, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType parg0, uint8 RecordNumber, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) BufSize); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (Dem_GetEventFreezeFrameDataEx((Dem_EventIdType)172, arg1, arg2, arg3, arg4)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventUdsStatus(Dem_EventIdType parg0, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) UDSStatusByte); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)172, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventTested(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) EventTested); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventTested(arg1) (Dem_GetEventTested((Dem_EventIdType)172, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetEventUdsStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)172, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType parg0, P2VAR(sint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_GetFaultDetectionCounter(arg1) (Dem_GetFaultDetectionCounter((Dem_EventIdType)172, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_ResetEventDebounceStatus(Dem_EventIdType parg0, Dem_DebounceResetStatusType DebounceResetStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_ResetEventDebounceStatus(arg1) (Dem_ResetEventDebounceStatus((Dem_EventIdType)172, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_ResetEventStatus(Dem_EventIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)172)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticMonitor_FactoryModeNotClosed_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)172, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_SOCDTCPROCESS_APPL_CODE) IPCIviReportDtcStatus_IpcIviReportDtcSts(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) data, uint8 length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IPCIviReportDtcStatus_IpcIviReportDtcSts(arg1, arg2) (IPCIviReportDtcStatus_IpcIviReportDtcSts(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_SOCDTCPROCESS_APPL_CODE) IPCSocReportDtcStatus_IpcSocReportDtcStatus(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_IPCSocReportDtcStatus_IpcSocReportDtcStatus(arg1, arg2) (IPCSocReportDtcStatus_IpcSocReportDtcStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)62, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)52, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)52, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)52, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ClusterInternalConfiguration_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)52, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)54, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)54, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)54, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_E2ESwitch_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)54, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)31, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)31, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)31, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_ECUlevelNetworkConfigurationData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)31, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)29, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)29, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)29, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_FactoryMode_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)29, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_SecOcSwitch_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)55, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)33, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)33, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)33, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VIN_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)33, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)34, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)34, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)34, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleMode_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)34, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_NvBlockNeed_VehicleSoftwareVersion_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)59, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) TC_Api_ParamentGetCsPort_1_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_TC_Api_ParamentGetCsPort_Operation(arg1) (TC_Api_ParamentGetCsPort_1_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_COMMON_NORMAL_APPL_CODE) RTE_Odo_Api_ParamentSetFunction(uint8 SetId, P2VAR(uint32, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_cpCS_OdoSetParament_Operation RTE_Odo_Api_ParamentSetFunction
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) svCS_GetTankResistanceValue_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) TankResistanceValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ppCS_GetTankResistanceValue_Operation(arg1) (svCS_GetTankResistanceValue_Operation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
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
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) Odo_Api_ParamentGetCsPortGetData(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_Odo_Api_ParamentGetCsPort_Operation(arg1, arg2) (Odo_Api_ParamentGetCsPortGetData(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(A_8Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue;
extern CONST(A_300Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_E2ESwitch_DefaultValue;
extern CONST(A_200Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_FactoryMode_DefaultValue;
extern CONST(Dcm_Data4ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_HUTInternalConfiguration_DefaultValue;
extern CONST(A_8Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_MasterSlaveStatus_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_DefaultValue;
extern CONST(A_28Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_SwitchARLTable_DefaultValue;
extern CONST(A_17Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_VIN_DefaultValue;
extern CONST(Dcm_Data20ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleMode_DefaultValue;
extern CONST(A_30Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_ClusterInternalConfiguration_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_ClusterInternalConfiguration_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_E2ESwitch_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_E2ESwitch_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_E2ESwitch_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_E2ESwitch_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_FactoryMode_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_FactoryMode_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_FactoryMode_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_FactoryMode_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_HUTInternalConfiguration_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_HUTInternalConfiguration_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_HUTInternalConfiguration_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_HUTInternalConfiguration_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_MasterSlaveStatus_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_MasterSlaveStatus_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_MasterSlaveStatus_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_MasterSlaveStatus_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_SecOcSwitch_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_SecOcSwitch_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_SwitchARLTable_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_SwitchARLTable_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_SwitchARLTable_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_SwitchARLTable_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_VIN_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_VIN_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_VIN_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_VIN_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_VehicleMode_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_VehicleMode_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_VehicleMode_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_VehicleMode_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_VehicleSoftwareVersion_DefaultValue() (&(Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_VehicleSoftwareVersion_DefaultValue() (&Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(A_8Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock;
extern VAR(A_300Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_E2ESwitch_MirrorBlock;
extern VAR(A_200Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_FactoryMode_MirrorBlock;
extern VAR(Dcm_Data4ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_HUTInternalConfiguration_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_MirrorBlock;
extern VAR(A_17Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_VIN_MirrorBlock;
extern VAR(Dcm_Data20ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleMode_MirrorBlock;
extern VAR(A_30Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock() (&((*RtePim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock() RtePim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock() (&((*RtePim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock() RtePim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_ClusterInternalConfiguration_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock() (&((*RtePim_NvBlockNeed_E2ESwitch_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_E2ESwitch_MirrorBlock() RtePim_NvBlockNeed_E2ESwitch_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_E2ESwitch_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_E2ESwitch_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock() (&((*RtePim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock() RtePim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_ECUlevelNetworkConfigurationData_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock() (&((*RtePim_NvBlockNeed_FactoryMode_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_FactoryMode_MirrorBlock() RtePim_NvBlockNeed_FactoryMode_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_FactoryMode_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_FactoryMode_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock() (&((*RtePim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock() RtePim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_HUTInternalConfiguration_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_HUTInternalConfiguration_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock() (&((*RtePim_NvBlockNeed_SecOcSwitch_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_SecOcSwitch_MirrorBlock() RtePim_NvBlockNeed_SecOcSwitch_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_SecOcSwitch_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_SecOcSwitch_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_VIN_MirrorBlock() (&((*RtePim_NvBlockNeed_VIN_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_VIN_MirrorBlock() RtePim_NvBlockNeed_VIN_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_VIN_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_VIN_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock() (&((*RtePim_NvBlockNeed_VehicleMode_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_VehicleMode_MirrorBlock() RtePim_NvBlockNeed_VehicleMode_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_VehicleMode_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_VehicleMode_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock() (&((*RtePim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock() RtePim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock() \
  (&Rte_DidDataProcess_NvBlockNeed_VehicleSoftwareVersion_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define DidDataProcess_START_SEC_CODE
# include "DidDataProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AppGetVinNumberFunction AppGetVinNumberFunction
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeDiag1_IsDidAvailable DataServices_DIDRange_DidRangeDiag1_IsDidAvailable
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeDiag1_ReadDidData DataServices_DIDRange_DidRangeDiag1_ReadDidData
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeDiag1_WriteDidData DataServices_DIDRange_DidRangeDiag1_WriteDidData
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeDiag2_IsDidAvailable DataServices_DIDRange_DidRangeDiag2_IsDidAvailable
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeDiag2_ReadDidData DataServices_DIDRange_DidRangeDiag2_ReadDidData
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeDiag2_WriteDidData DataServices_DIDRange_DidRangeDiag2_WriteDidData
#  define RTE_RUNNABLE_DataServices_VehicleModel_VehicleModel_ConditionCheckRead DataServices_VehicleModel_VehicleModel_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_VehicleModel_VehicleModel_ReadData DataServices_VehicleModel_VehicleModel_ReadData
#  define RTE_RUNNABLE_DataServices_VehicleModel_VehicleModel_WriteData DataServices_VehicleModel_VehicleModel_WriteData
#  define RTE_RUNNABLE_DidDataProcess_Init DidDataProcess_Init
#  define RTE_RUNNABLE_DidDataProcess_MainFunction DidDataProcess_MainFunction
#  define RTE_RUNNABLE_E2ESwitchStatusRead E2ESwitchStatusRead
#  define RTE_RUNNABLE_E2ESwitchStatusWrite E2ESwitchStatusWrite
#  define RTE_RUNNABLE_GetCANMatrixVersionInfo_Data GetCANMatrixVersionInfo_Data
#  define RTE_RUNNABLE_GetVehicleModeInfo_Data GetVehicleModeInfo_Data
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished
#  define RTE_RUNNABLE_RoutineServices_AVMAutoCalibration_RequestResults RoutineServices_AVMAutoCalibration_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMAutoCalibration_Start RoutineServices_AVMAutoCalibration_Start
#  define RTE_RUNNABLE_RoutineServices_AVMEnvironmentCheck_RequestResults RoutineServices_AVMEnvironmentCheck_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMEnvironmentCheck_Start RoutineServices_AVMEnvironmentCheck_Start
#  define RTE_RUNNABLE_RoutineServices_AVMManualCalibration_RequestResults RoutineServices_AVMManualCalibration_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMManualCalibration_Start RoutineServices_AVMManualCalibration_Start
#  define RTE_RUNNABLE_RoutineServices_AVMManualCalibration_Stop RoutineServices_AVMManualCalibration_Stop
#  define RTE_RUNNABLE_RoutineServices_AVMManualConerMove_RequestResults RoutineServices_AVMManualConerMove_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMManualConerMove_Start RoutineServices_AVMManualConerMove_Start
#  define RTE_RUNNABLE_RoutineServices_AVMManualConerSelect_RequestResults RoutineServices_AVMManualConerSelect_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMManualConerSelect_Start RoutineServices_AVMManualConerSelect_Start
#  define RTE_RUNNABLE_RoutineServices_AVMManualCorrectValue_RequestResults RoutineServices_AVMManualCorrectValue_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMManualCorrectValue_Start RoutineServices_AVMManualCorrectValue_Start
#  define RTE_RUNNABLE_RoutineServices_AVMManualViewSelect_RequestResults RoutineServices_AVMManualViewSelect_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMManualViewSelect_Start RoutineServices_AVMManualViewSelect_Start
#  define RTE_RUNNABLE_RoutineServices_CableDiagnostics_Start RoutineServices_CableDiagnostics_Start
#  define RTE_RUNNABLE_RoutineServices_ConfigureFrontCamerParameters_RequestResults RoutineServices_ConfigureFrontCamerParameters_RequestResults
#  define RTE_RUNNABLE_RoutineServices_ConfigureFrontCamerParameters_Start RoutineServices_ConfigureFrontCamerParameters_Start
#  define RTE_RUNNABLE_RoutineServices_ConfigureLeftCamerParameters_RequestResults RoutineServices_ConfigureLeftCamerParameters_RequestResults
#  define RTE_RUNNABLE_RoutineServices_ConfigureLeftCamerParameters_Start RoutineServices_ConfigureLeftCamerParameters_Start
#  define RTE_RUNNABLE_RoutineServices_ConfigureRearCamerParameters_RequestResults RoutineServices_ConfigureRearCamerParameters_RequestResults
#  define RTE_RUNNABLE_RoutineServices_ConfigureRearCamerParameters_Start RoutineServices_ConfigureRearCamerParameters_Start
#  define RTE_RUNNABLE_RoutineServices_ConfigureRightCamerParameters_RequestResults RoutineServices_ConfigureRightCamerParameters_RequestResults
#  define RTE_RUNNABLE_RoutineServices_ConfigureRightCamerParameters_Start RoutineServices_ConfigureRightCamerParameters_Start
#  define RTE_RUNNABLE_RoutineServices_ODOReset_RequestResults RoutineServices_ODOReset_RequestResults
#  define RTE_RUNNABLE_RoutineServices_ODOReset_Start RoutineServices_ODOReset_Start
#  define RTE_RUNNABLE_RoutineServices_PhyTestMode_Start RoutineServices_PhyTestMode_Start
#  define RTE_RUNNABLE_RoutineServices_RequestCertificateStatus_RequestResults RoutineServices_RequestCertificateStatus_RequestResults
#  define RTE_RUNNABLE_RoutineServices_RequestCertificateStatus_Start RoutineServices_RequestCertificateStatus_Start
#  define RTE_RUNNABLE_RoutineServices_ResetSwitchStatistics_Start RoutineServices_ResetSwitchStatistics_Start
#  define RTE_RUNNABLE_RoutineServices_SystemRecovery_Start RoutineServices_SystemRecovery_Start
#  define RTE_RUNNABLE_SecOcSwitchStatusRead SecOcSwitchStatusRead
#  define RTE_RUNNABLE_SecOcSwitchStatusWrite SecOcSwitchStatusWrite
#  define RTE_RUNNABLE_ppCS_Diag_ReadDidData_Operation ppCS_Diag_ReadDidData_Operation
#  define RTE_RUNNABLE_ppCS_Diag_WriteDidData_Operation ppCS_Diag_WriteDidData_Operation
#  define RTE_RUNNABLE_ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData
# endif

FUNC(void, DidDataProcess_CODE) AppGetVinNumberFunction(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) supported); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_ReadDidData(uint16 DID, P2VAR(Dcm_Data4000ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag1_WriteDidData(uint16 DID, P2CONST(Dcm_Data4000ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) supported); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_ReadDidData(uint16 DID, P2VAR(Dcm_Data300ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_DIDRange_DidRangeDiag2_WriteDidData(uint16 DID, P2CONST(Dcm_Data300ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DidDataProcess_CODE) DataServices_VehicleModel_VehicleModel_WriteData(P2CONST(Dcm_Data20ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, DidDataProcess_CODE) DidDataProcess_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DidDataProcess_CODE) DidDataProcess_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DidDataProcess_CODE) E2ESwitchStatusRead(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) E2ESwitchStatusWrite(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) GetCANMatrixVersionInfo_Data(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) GetVehicleModeInfo_Data(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_ClusterDisplayHMIAdjustmentOffset_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_ClusterInternalConfiguration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_E2ESwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_ECUlevelNetworkConfigurationData_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_FactoryMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_SecOcSwitch_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_VIN_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_VehicleMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) NvMNotifyJobFinished_NvBlockNeed_VehicleSoftwareVersion_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMAutoCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMCalibrationResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMAutoCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMEnvironmentCheck_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMEnvironmentCheck_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_ManualCalibrationResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCalibration_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerMove_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMManualConerMoveResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerMove_Start(uint8 In_AVMManualConerMove, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerSelect_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualConerSelect_Start(uint8 In_AVMManualConerSelect, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCorrectValue_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMManualCorrectValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualCorrectValue_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualViewSelect_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_AVMManualViewSelect_Start(uint8 In_AVMManualViewSelect, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_CableDiagnostics_Start(uint8 In_CableDiagnosticsControl, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureFrontCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureFrontCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureLeftCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureLeftCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRearCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRearCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRightCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ConfigureRightCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ODOReset_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_OdoResetResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ODOReset_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_PhyTestMode_Start(uint8 In_PortNumber, uint8 In_TestMode, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_RequestCertificateStatus_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_RequestCertificateStatus_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_ResetSwitchStatistics_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) RoutineServices_SystemRecovery_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_SystemRcvrySts, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) SecOcSwitchStatusRead(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DidDataProcess_CODE) SecOcSwitchStatusWrite(uint8 Length, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) ppCS_Diag_ReadDidData_Operation(uint16 dataId, uint8 opStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) ppCS_Diag_WriteDidData_Operation(uint16 dataId, uint8 opStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DidDataProcess_CODE) ppCS_USBWriteECUlevelNetworkConfigurationData_USBWriteData(P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length, uint8 OpStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define DidDataProcess_STOP_SEC_CODE
# include "DidDataProcess_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag1_E_NOT_OK (1U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag2_E_NOT_OK (1U)

#  define RTE_E_DataServices_VehicleModel_VehicleModel_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_VehicleModel_VehicleModel_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMAutoCalibration_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMAutoCalibration_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMAutoCalibration_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMEnvironmentCheck_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMEnvironmentCheck_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMEnvironmentCheck_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMManualCalibration_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMManualCalibration_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMManualCalibration_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMManualConerMove_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMManualConerMove_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMManualConerMove_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMManualConerSelect_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMManualConerSelect_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMManualConerSelect_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMManualCorrectValue_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMManualCorrectValue_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMManualCorrectValue_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMManualViewSelect_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMManualViewSelect_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMManualViewSelect_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_CableDiagnostics_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_CableDiagnostics_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_CableDiagnostics_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ConfigureFrontCamerParameters_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ConfigureFrontCamerParameters_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ConfigureFrontCamerParameters_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ConfigureLeftCamerParameters_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ConfigureLeftCamerParameters_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ConfigureLeftCamerParameters_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ConfigureRearCamerParameters_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ConfigureRearCamerParameters_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ConfigureRearCamerParameters_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ConfigureRightCamerParameters_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ConfigureRightCamerParameters_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ConfigureRightCamerParameters_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ODOReset_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ODOReset_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ODOReset_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_PhyTestMode_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_PhyTestMode_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_PhyTestMode_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_RequestCertificateStatus_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_RequestCertificateStatus_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_RequestCertificateStatus_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_ResetSwitchStatistics_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_ResetSwitchStatistics_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_ResetSwitchStatistics_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_SystemRecovery_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_SystemRecovery_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_SystemRecovery_E_NOT_OK (1U)

#  define RTE_E_USBWriteECUlevelNetworkConfigurationData_E_NOT_OK (1U)

#  define RTE_E_USBWriteECUlevelNetworkConfigurationData_E_OK (0U)

#  define RTE_E_USBWriteECUlevelNetworkConfigurationData_E_PENDING (10U)

#  define RTE_E_piCS_Diag_ReadDidData_DCM_E_PENDING (10U)

#  define RTE_E_piCS_Diag_ReadDidData_E_NOT_OK (1U)

#  define RTE_E_piCS_Diag_WriteDidData_DCM_E_PENDING (10U)

#  define RTE_E_piCS_Diag_WriteDidData_E_NOT_OK (1U)

#  define RTE_E_tiCS_OdoSetParament_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DIDDATAPROCESS_H */

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
