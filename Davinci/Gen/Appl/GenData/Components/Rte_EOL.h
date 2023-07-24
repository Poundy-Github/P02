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
 *             File:  Rte_EOL.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <EOL>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_EOL_H
# define RTE_EOL_H

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

# include "Rte_EOL_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_INIT) Rte_EOL_EOL_AMPCalibration_AMPCalibration;
extern VAR(uint16, RTE_VAR_INIT) Rte_EOL_EOL_KeepDownload_keepDownloadRID;
extern VAR(uint8, RTE_VAR_INIT) Rte_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount;
extern VAR(boolean, RTE_VAR_INIT) Rte_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EOL_AMPCalibration_AMPCalibration (0U)
#  define Rte_InitValue_EOL_ReadGPSSatelliteCount_GPSSatelliteCount (0U)
#  define Rte_InitValue_rpSR_SocManager_SocFactoryResetState_SocFactoryResetReady (FALSE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_AMPCalibrationRece_EOLReceive(P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_AMPCalibrationRece_EOLReceive(P2VAR(A_U8_10, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_BatteryVoltage_0xFD10_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_KL15Status_0xFD15_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0(P2VAR(EOL3Bytes, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EOL_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(P2VAR(EOL9Bytes, AUTOMATIC, RTE_EOL_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187(P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187(P2CONST(EOL13Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(P2CONST(EOL_15Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(P2CONST(A_20Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_SRpVehSparePartNumber_SparePartNumber(P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_SRpVehSparePartNumber_SparePartNumber(P2CONST(EOL_13Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(P2CONST(EOL4Bytes, AUTOMATIC, RTE_EOL_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(uint8, RTE_CODE) Rte_Mode_EOL_DcmControlDtcSetting_DcmControlDtcSetting(void);
FUNC(uint8, RTE_CODE) Rte_Mode_EOL_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void);
FUNC(uint8, RTE_CODE) Rte_Mode_EOL_DcmEcuReset_DcmEcuReset(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_EOL_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, P2VAR(uint32, AUTOMATIC, RTE_EOL_APPL_VAR) E2eStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_EOL_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster(P2VAR(EOL_6Bytes, AUTOMATIC, RTE_EOL_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EOL_AMPCalibrationRece_EOLReceive Rte_Read_EOL_EOL_AMPCalibrationRece_EOLReceive
#  define Rte_Read_EOL_BatteryVoltage_0xFD10_SystemStateOut Rte_Read_EOL_EOL_BatteryVoltage_0xFD10_SystemStateOut
#  define Rte_Read_EOL_KL15Status_0xFD15_SystemStateOut Rte_Read_EOL_EOL_KL15Status_0xFD15_SystemStateOut
#  define Rte_Read_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0 Rte_Read_EOL_EOL_RadioAntennaStatus_0xFDD0_RadioAntennaStatus_0xFDD0
#  define Rte_Read_EOL_ReadAmpCalibrationValue_AmpCalibrationValue Rte_Read_EOL_EOL_ReadAmpCalibrationValue_AmpCalibrationValue
#  define Rte_Read_EOL_ReadGPSSatelliteCount_GPSSatelliteCount Rte_Read_EOL_EOL_ReadGPSSatelliteCount_GPSSatelliteCount
#  define Rte_Read_EOL_EOL_ReadGPSSatelliteCount_GPSSatelliteCount(data) (*(data) = Rte_Misc_EOL_ReadGPSSatelliteCount_GPSSatelliteCount, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_SocManager_SocFactoryResetState_SocFactoryResetReady Rte_Read_EOL_rpSR_SocManager_SocFactoryResetState_SocFactoryResetReady
#  define Rte_Read_EOL_rpSR_SocManager_SocFactoryResetState_SocFactoryResetReady(data) (*(data) = Rte_SOCManager_ppSR_SocManager_SocFactoryResetState_SocFactoryResetReady, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_EOL_AMPCalibration_AMPCalibration Rte_Write_EOL_EOL_AMPCalibration_AMPCalibration
#  define Rte_Write_EOL_EOL_AMPCalibration_AMPCalibration(data) (Rte_EOL_EOL_AMPCalibration_AMPCalibration = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_EOL_KeepDownload_keepDownloadRID Rte_Write_EOL_EOL_KeepDownload_keepDownloadRID
#  define Rte_Write_EOL_EOL_KeepDownload_keepDownloadRID(data) (Rte_EOL_EOL_KeepDownload_keepDownloadRID = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Write_EOL_PartNumber_0xF187_PartNumber_0xF187 Rte_Write_EOL_EOL_PartNumber_0xF187_PartNumber_0xF187
#  define Rte_Write_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193 Rte_Write_EOL_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193
#  define Rte_Write_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C Rte_Write_EOL_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C
#  define Rte_Write_EOL_SRpVehSparePartNumber_SparePartNumber Rte_Write_EOL_EOL_SRpVehSparePartNumber_SparePartNumber
#  define Rte_Write_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01 Rte_Write_EOL_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmControlDtcSetting_DcmControlDtcSetting Rte_Mode_EOL_DcmControlDtcSetting_DcmControlDtcSetting
#  define Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Mode_EOL_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Mode_DcmEcuReset_DcmEcuReset Rte_Mode_EOL_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_EOL_ComEx_GetRxE2EStatus Rte_Call_EOL_EOL_ComEx_GetRxE2EStatus
#  define Rte_Call_EOL_ComEx_SendSignal Rte_Call_EOL_EOL_ComEx_SendSignal
#  define Rte_Call_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster Rte_Call_EOL_EOL_ReadDID0xFDD8_EOL_GetReadHardInputForCluster
#  define Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Rte_Call_EOL_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AMP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_AMP_APPL_CODE) AMP_EOL_Read_Operation(P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_AMP_APPL_CODE) AMP_EOL_Read_Operation(P2VAR(A_U8_10, AUTOMATIC, RTE_AMP_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_AMP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_AMP_EOL_Read_Operation AMP_EOL_Read_Operation
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
#  define RTE_START_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFD16_EOL_FactoryReset(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFD16_EOL_FactoryReset(P2VAR(A_1Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_0xFD16_EOL_FactoryReset(arg1) (EOL_0xFD16_EOL_FactoryReset(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_POWER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_POWER_APPL_CODE) EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17(P2VAR(EOL_Struct_3Element, AUTOMATIC, RTE_POWER_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_POWER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17(arg1) (EOL_0xFD17_EOL_Get_MCUAMP_Temperature_0xFD17(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDD1_EOL_ReadMICStatus(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDD1_EOL_ReadMICStatus(P2VAR(EOL_3Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_0xFDD1_EOL_ReadMICStatus(arg1) (EOL_0xFDD1_EOL_ReadMICStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDD9_EOL_WriteValueForDispalyEnable(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDD9_EOL_WriteValueForDispalyEnable(P2VAR(EOL_2Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_0xFDD9_EOL_WriteValueForDispalyEnable(arg1) (EOL_0xFDD9_EOL_WriteValueForDispalyEnable(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDE1_EOL_ReadWatchDogCnt(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDE1_EOL_ReadWatchDogCnt(P2VAR(EOL_4Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_0xFDE1_EOL_ReadWatchDogCnt(arg1) (EOL_0xFDE1_EOL_ReadWatchDogCnt(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDE2_EOL_ReadResetInformation(P2VAR(uint8, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_MISC_APPL_CODE) EOL_0xFDE2_EOL_ReadResetInformation(P2VAR(EOL_64Bytes, AUTOMATIC, RTE_MISC_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_MISC_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_0xFDE2_EOL_ReadResetInformation(arg1) (EOL_0xFDE2_EOL_ReadResetInformation(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(uint8, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_COMEX_APPL_CODE) ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, P2VAR(ComEx_SignalDataType, AUTOMATIC, RTE_COMEX_APPL_VAR) SignalDataPtr, uint8 Length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_COMEX_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_ComEx_ReceiveSignal ComEx_ReceiveSignal
#  define RTE_START_SEC_AMP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AMP_APPL_CODE) EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_AMP_APPL_CODE) EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(P2VAR(EOL_4Bytes, AUTOMATIC, RTE_AMP_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_AMP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(arg1) (EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_0xF187_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)46, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_0xF187_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)46, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_0xF187_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)46, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_0xF187_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)46, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF18C_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)35, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF18C_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)35, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF18C_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)35, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF18C_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)35, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF193_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)36, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF193_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)36, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF193_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)36, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF193_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)36, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF195_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)37, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF195_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)37, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF195_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)37, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xF195_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)37, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD00_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)38, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD00_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)38, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD00_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)38, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD00_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)38, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD19_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)39, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD19_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)39, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD19_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)39, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFD19_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)39, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE20_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)40, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE20_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)40, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE20_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)40, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE20_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)40, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE21_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)41, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE21_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)41, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE21_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)41, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE21_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)41, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE22_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)42, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE22_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)42, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE22_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)42, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE22_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)42, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE23_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)43, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE23_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)43, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE23_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)43, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE23_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)43, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE24_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)44, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE24_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)44, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE24_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)44, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE24_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)44, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE25_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)45, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE25_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)45, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE25_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)45, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_0xFE25_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)45, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) ppCS_Diag_ReadDidData_Operation(uint16 dataId, uint8 opStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ppCS_Diag_ReadDidData_Operation ppCS_Diag_ReadDidData_Operation
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) ppCS_Diag_WriteDidData_Operation(uint16 dataId, uint8 opStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) data, uint16 length, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ppCS_Diag_WriteDidData_Operation ppCS_Diag_WriteDidData_Operation
#  define RTE_START_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, RTE_COMMON_NORMAL_APPL_CODE) Odo_Api_ParamentGetCsPortGetData(uint8 Id, P2VAR(uint8, AUTOMATIC, RTE_COMMON_NORMAL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_COMMON_NORMAL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_rpCS_EOL_Odo_Api_ParamentGetCsPort_Operation(arg1, arg2) (Odo_Api_ParamentGetCsPortGetData(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(EOL_13Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF187_DefaultValue;
extern CONST(A_20Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF18C_DefaultValue;
extern CONST(EOL_15Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF193_DefaultValue;
extern CONST(A_17Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xF195_DefaultValue;
extern CONST(RW_0xFD00, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFD00_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFD19_DefaultValue;
extern CONST(EOL_2Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFDD9_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE20_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE21_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE22_DefaultValue;
extern CONST(EOL_2Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE23_DefaultValue;
extern CONST(A_1Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE24_DefaultValue;
extern CONST(EOL_2Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_0xFE25_DefaultValue;
extern CONST(A_20Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_EOLUIN_DefaultValue;
extern CONST(EOL4Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_EnterEOLSession_DefaultValue;
extern CONST(A_20Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_EOL_NvBlockNeed_UIN_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xF187_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xF187_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xF187_DefaultValue() (&Rte_EOL_NvBlockNeed_0xF187_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xF18C_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xF18C_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xF18C_DefaultValue() (&Rte_EOL_NvBlockNeed_0xF18C_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xF193_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xF193_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xF193_DefaultValue() (&Rte_EOL_NvBlockNeed_0xF193_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xF195_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xF195_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xF195_DefaultValue() (&Rte_EOL_NvBlockNeed_0xF195_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFD00_DefaultValue() ((P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &(Rte_EOL_NvBlockNeed_0xFD00_DefaultValue[0][0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFD00_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFD00_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFD19_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xFD19_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFD19_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFD19_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFDD9_DefaultValue() ((P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &(Rte_EOL_NvBlockNeed_0xFDD9_DefaultValue[0][0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFDD9_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFDD9_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFE20_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xFE20_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFE20_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFE20_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFE21_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xFE21_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFE21_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFE21_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFE22_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xFE22_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFE22_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFE22_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFE23_DefaultValue() ((P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &(Rte_EOL_NvBlockNeed_0xFE23_DefaultValue[0][0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFE23_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFE23_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFE24_DefaultValue() (&(Rte_EOL_NvBlockNeed_0xFE24_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFE24_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFE24_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_0xFE25_DefaultValue() ((P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &(Rte_EOL_NvBlockNeed_0xFE25_DefaultValue[0][0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_0xFE25_DefaultValue() (&Rte_EOL_NvBlockNeed_0xFE25_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_EOLUIN_DefaultValue() (&(Rte_EOL_NvBlockNeed_EOLUIN_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_EOLUIN_DefaultValue() (&Rte_EOL_NvBlockNeed_EOLUIN_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_EnterEOLSession_DefaultValue() (&(Rte_EOL_NvBlockNeed_EnterEOLSession_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_EnterEOLSession_DefaultValue() (&Rte_EOL_NvBlockNeed_EnterEOLSession_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_UIN_DefaultValue() (&(Rte_EOL_NvBlockNeed_UIN_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_UIN_DefaultValue() (&Rte_EOL_NvBlockNeed_UIN_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(EOL_13Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF187_MirrorBlock;
extern VAR(A_20Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF18C_MirrorBlock;
extern VAR(EOL_15Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF193_MirrorBlock;
extern VAR(A_17Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xF195_MirrorBlock;
extern VAR(RW_0xFD00, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFD00_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFD19_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE20_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE21_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE22_MirrorBlock;
extern VAR(EOL_2Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE23_MirrorBlock;
extern VAR(A_1Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE24_MirrorBlock;
extern VAR(EOL_2Bytes, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_NvBlockNeed_0xFE25_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xF187_MirrorBlock() (&((*RtePim_NvBlockNeed_0xF187_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xF187_MirrorBlock() RtePim_NvBlockNeed_0xF187_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xF187_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xF187_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xF18C_MirrorBlock() (&((*RtePim_NvBlockNeed_0xF18C_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xF18C_MirrorBlock() RtePim_NvBlockNeed_0xF18C_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xF18C_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xF18C_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xF193_MirrorBlock() (&((*RtePim_NvBlockNeed_0xF193_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xF193_MirrorBlock() RtePim_NvBlockNeed_0xF193_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xF193_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xF193_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xF195_MirrorBlock() (&((*RtePim_NvBlockNeed_0xF195_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xF195_MirrorBlock() RtePim_NvBlockNeed_0xF195_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xF195_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xF195_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFD00_MirrorBlock() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_NvBlockNeed_0xFD00_MirrorBlock())[0][0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFD00_MirrorBlock() RtePim_NvBlockNeed_0xFD00_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFD00_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFD00_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFD19_MirrorBlock() (&((*RtePim_NvBlockNeed_0xFD19_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFD19_MirrorBlock() RtePim_NvBlockNeed_0xFD19_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFD19_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFD19_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFE20_MirrorBlock() (&((*RtePim_NvBlockNeed_0xFE20_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFE20_MirrorBlock() RtePim_NvBlockNeed_0xFE20_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFE20_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFE20_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFE21_MirrorBlock() (&((*RtePim_NvBlockNeed_0xFE21_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFE21_MirrorBlock() RtePim_NvBlockNeed_0xFE21_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFE21_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFE21_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFE22_MirrorBlock() (&((*RtePim_NvBlockNeed_0xFE22_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFE22_MirrorBlock() RtePim_NvBlockNeed_0xFE22_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFE22_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFE22_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFE23_MirrorBlock() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_NvBlockNeed_0xFE23_MirrorBlock())[0][0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFE23_MirrorBlock() RtePim_NvBlockNeed_0xFE23_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFE23_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFE23_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFE24_MirrorBlock() (&((*RtePim_NvBlockNeed_0xFE24_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFE24_MirrorBlock() RtePim_NvBlockNeed_0xFE24_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFE24_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFE24_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_0xFE25_MirrorBlock() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_NvBlockNeed_0xFE25_MirrorBlock())[0][0]))
#  else
#   define Rte_Pim_NvBlockNeed_0xFE25_MirrorBlock() RtePim_NvBlockNeed_0xFE25_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_0xFE25_MirrorBlock() \
  (&Rte_EOL_NvBlockNeed_0xFE25_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define EOL_START_SEC_CODE
# include "EOL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeEol1_IsDidAvailable DataServices_DIDRange_DidRangeEol1_IsDidAvailable
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeEol1_ReadDidData DataServices_DIDRange_DidRangeEol1_ReadDidData
#  define RTE_RUNNABLE_DataServices_DIDRange_DidRangeEol1_WriteDidData DataServices_DIDRange_DidRangeEol1_WriteDidData
#  define RTE_RUNNABLE_EOL_Init EOL_Init
#  define RTE_RUNNABLE_EOL_MainFunction EOL_MainFunction
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xF187_JobFinished NvMNotifyJobFinished_0xF187_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xF18C_JobFinished NvMNotifyJobFinished_0xF18C_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xF193_JobFinished NvMNotifyJobFinished_0xF193_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xF195_JobFinished NvMNotifyJobFinished_0xF195_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFD00_JobFinished NvMNotifyJobFinished_0xFD00_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFD19_JobFinished NvMNotifyJobFinished_0xFD19_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFE20_JobFinished NvMNotifyJobFinished_0xFE20_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFE21_JobFinished NvMNotifyJobFinished_0xFE21_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFE22_JobFinished NvMNotifyJobFinished_0xFE22_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFE23_JobFinished NvMNotifyJobFinished_0xFE23_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFE24_JobFinished NvMNotifyJobFinished_0xFE24_JobFinished
#  define RTE_RUNNABLE_NvMNotifyJobFinished_0xFE25_JobFinished NvMNotifyJobFinished_0xFE25_JobFinished
#  define RTE_RUNNABLE_RoutineServices_AMPCalibration_RequestResults RoutineServices_AMPCalibration_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AMPCalibration_Start RoutineServices_AMPCalibration_Start
#  define RTE_RUNNABLE_RoutineServices_AVMRegister_RequestResults RoutineServices_AVMRegister_RequestResults
#  define RTE_RUNNABLE_RoutineServices_AVMRegister_Start RoutineServices_AVMRegister_Start
#  define RTE_RUNNABLE_RoutineServices_CheckEthernetIPPINGFunction_RequestResults RoutineServices_CheckEthernetIPPINGFunction_RequestResults
#  define RTE_RUNNABLE_RoutineServices_CheckEthernetIPPINGFunction_Start RoutineServices_CheckEthernetIPPINGFunction_Start
#  define RTE_RUNNABLE_RoutineServices_IVITouchTest_RequestResults RoutineServices_IVITouchTest_RequestResults
#  define RTE_RUNNABLE_RoutineServices_IVITouchTest_Start RoutineServices_IVITouchTest_Start
# endif

FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_EOL_APPL_VAR) supported); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_EOL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_ReadDidData(uint16 DID, P2VAR(Dcm_Data4000ByteType, AUTOMATIC, RTE_EOL_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_EOL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, EOL_CODE) DataServices_DIDRange_DidRangeEol1_WriteDidData(uint16 DID, P2CONST(Dcm_Data4000ByteType, AUTOMATIC, RTE_EOL_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, EOL_CODE) EOL_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, EOL_CODE) EOL_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF187_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF18C_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF193_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xF195_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFD00_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFD19_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE20_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE21_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE22_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE23_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE24_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_CODE) NvMNotifyJobFinished_0xFE25_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AMPCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AmpValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AMPCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AmpValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AMPCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_RoutineStatusRecord, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AVMRegister_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AVMRegister, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_AVMRegister_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AVMRegister, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_CheckEthernetIPPINGFunction_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF003, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_CheckEthernetIPPINGFunction_Start(uint32 In_Start, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_IVITouchTest_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_IVITouchTest_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, EOL_CODE) RoutineServices_IVITouchTest_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define EOL_STOP_SEC_CODE
# include "EOL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_AMP_EOL_Read_N_OK (1U)

#  define RTE_E_ComEx_COMEX_ERROR_PARAM (1U)

#  define RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED (2U)

#  define RTE_E_ComEx_COMEX_NEVER_RECEIVED (4U)

#  define RTE_E_ComEx_COMEX_UPDATE_RECEIVED (8U)

#  define RTE_E_ComEx_E_OK (0U)

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_DIDRange_DidRangeEol1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DIDRange_DidRangeEol1_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AMPCalibration_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AMPCalibration_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AMPCalibration_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AVMRegister_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMRegister_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMRegister_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_CheckEthernetIPPINGFunction_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_IVITouchTest_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_IVITouchTest_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_IVITouchTest_E_NOT_OK (1U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)

#  define RTE_E_piCS_Diag_ReadDidData_DCM_E_PENDING (10U)

#  define RTE_E_piCS_Diag_ReadDidData_E_NOT_OK (1U)

#  define RTE_E_piCS_Diag_WriteDidData_DCM_E_PENDING (10U)

#  define RTE_E_piCS_Diag_WriteDidData_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_EOL_H */

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
