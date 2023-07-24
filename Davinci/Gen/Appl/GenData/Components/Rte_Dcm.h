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
 *             File:  Rte_Dcm.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <Dcm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DCM_H
# define RTE_DCM_H

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

# include "Rte_Dcm_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_Mode_Dcm_Dcm_Read_Mode_Dcm_Read_Mode(P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b(Dcm_CommunicationModeType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Dcm_Read_Mode_Dcm_Read_Mode Rte_Mode_Dcm_Dcm_Read_Mode_Dcm_Read_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b_DcmCommunicationControl_ComMConf_ComMChannel_CN_B30_for_SC_CAN_V3_2_c0d6c67b
#  define Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting
#  define Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Switch_DcmEcuReset_DcmEcuReset Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_DcmEcuReset_DcmEcuReset Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) supported); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeDiag1_IsDidAvailable DataServices_DIDRange_DidRangeDiag1_IsDidAvailable
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag1_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag1_ReadDidData(uint16 DID, P2VAR(Dcm_Data4000ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeDiag1_ReadDidData DataServices_DIDRange_DidRangeDiag1_ReadDidData
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag1_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag1_WriteDidData(uint16 DID, P2CONST(Dcm_Data4000ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeDiag1_WriteDidData DataServices_DIDRange_DidRangeDiag1_WriteDidData
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag2_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) supported); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeDiag2_IsDidAvailable DataServices_DIDRange_DidRangeDiag2_IsDidAvailable
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag2_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag2_ReadDidData(uint16 DID, P2VAR(Dcm_Data300ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeDiag2_ReadDidData DataServices_DIDRange_DidRangeDiag2_ReadDidData
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag2_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_DIDRange_DidRangeDiag2_WriteDidData(uint16 DID, P2CONST(Dcm_Data300ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeDiag2_WriteDidData DataServices_DIDRange_DidRangeDiag2_WriteDidData
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) DataServices_DIDRange_DidRangeEol1_IsDidAvailable(uint16 DID, Dcm_OpStatusType OpStatus, P2VAR(Dcm_DidSupportedType, AUTOMATIC, RTE_EOL_APPL_VAR) supported); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeEol1_IsDidAvailable DataServices_DIDRange_DidRangeEol1_IsDidAvailable
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) DataServices_DIDRange_DidRangeEol1_ReadDidData(uint16 DID, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_EOL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) DataServices_DIDRange_DidRangeEol1_ReadDidData(uint16 DID, P2VAR(Dcm_Data4000ByteType, AUTOMATIC, RTE_EOL_APPL_VAR) Data, Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_EOL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeEol1_ReadDidData DataServices_DIDRange_DidRangeEol1_ReadDidData
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) DataServices_DIDRange_DidRangeEol1_WriteDidData(uint16 DID, P2CONST(uint8, AUTOMATIC, RTE_EOL_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) DataServices_DIDRange_DidRangeEol1_WriteDidData(uint16 DID, P2CONST(Dcm_Data4000ByteType, AUTOMATIC, RTE_EOL_APPL_DATA) Data, Dcm_OpStatusType OpStatus, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_DIDRange_DidRangeEol1_WriteDidData DataServices_DIDRange_DidRangeEol1_WriteDidData
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_VehicleModel_VehicleModel_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_VehicleModel_VehicleModel_ConditionCheckRead DataServices_VehicleModel_VehicleModel_ConditionCheckRead
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_VehicleModel_VehicleModel_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_VehicleModel_VehicleModel_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_VehicleModel_VehicleModel_ReadData DataServices_VehicleModel_VehicleModel_ReadData
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_VehicleModel_VehicleModel_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) DataServices_VehicleModel_VehicleModel_WriteData(P2CONST(Dcm_Data20ByteType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_VehicleModel_VehicleModel_WriteData DataServices_VehicleModel_VehicleModel_WriteData
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_AMPCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AmpValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_AMPCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AmpValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AMPCalibration_RequestResults RoutineServices_AMPCalibration_RequestResults
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_AMPCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_RoutineStatusRecord, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AMPCalibration_Start RoutineServices_AMPCalibration_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMAutoCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMCalibrationResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMAutoCalibration_RequestResults RoutineServices_AVMAutoCalibration_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMAutoCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMAutoCalibration_Start RoutineServices_AVMAutoCalibration_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMEnvironmentCheck_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMEnvironmentCheck_RequestResults RoutineServices_AVMEnvironmentCheck_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMEnvironmentCheck_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMEnvironmentCheck_Start RoutineServices_AVMEnvironmentCheck_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualCalibration_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_ManualCalibrationResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualCalibration_RequestResults RoutineServices_AVMManualCalibration_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualCalibration_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualCalibration_Start RoutineServices_AVMManualCalibration_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualCalibration_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualCalibration_Stop RoutineServices_AVMManualCalibration_Stop
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualConerMove_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMManualConerMoveResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualConerMove_RequestResults RoutineServices_AVMManualConerMove_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualConerMove_Start(uint8 In_AVMManualConerMove, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualConerMove_Start RoutineServices_AVMManualConerMove_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualConerSelect_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualConerSelect_RequestResults RoutineServices_AVMManualConerSelect_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualConerSelect_Start(uint8 In_AVMManualConerSelect, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualConerSelect_Start RoutineServices_AVMManualConerSelect_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualCorrectValue_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMManualCorrectValue, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualCorrectValue_RequestResults RoutineServices_AVMManualCorrectValue_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualCorrectValue_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualCorrectValue_Start RoutineServices_AVMManualCorrectValue_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualViewSelect_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_AVMEnvironmentCheckResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualViewSelect_RequestResults RoutineServices_AVMManualViewSelect_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_AVMManualViewSelect_Start(uint8 In_AVMManualViewSelect, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMManualViewSelect_Start RoutineServices_AVMManualViewSelect_Start
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_AVMRegister_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AVMRegister, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMRegister_RequestResults RoutineServices_AVMRegister_RequestResults
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_AVMRegister_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_AVMRegister, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_AVMRegister_Start RoutineServices_AVMRegister_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_CableDiagnostics_Start(uint8 In_CableDiagnosticsControl, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_CableDiagnostics_Start RoutineServices_CableDiagnostics_Start
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_CheckEthernetIPPINGFunction_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF003, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_CheckEthernetIPPINGFunction_RequestResults RoutineServices_CheckEthernetIPPINGFunction_RequestResults
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_CheckEthernetIPPINGFunction_Start(uint32 In_Start, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_CheckEthernetIPPINGFunction_Start RoutineServices_CheckEthernetIPPINGFunction_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureFrontCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureFrontCamerParameters_RequestResults RoutineServices_ConfigureFrontCamerParameters_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureFrontCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureFrontCamerParameters_Start RoutineServices_ConfigureFrontCamerParameters_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureLeftCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureLeftCamerParameters_RequestResults RoutineServices_ConfigureLeftCamerParameters_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureLeftCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureLeftCamerParameters_Start RoutineServices_ConfigureLeftCamerParameters_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureRearCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureRearCamerParameters_RequestResults RoutineServices_ConfigureRearCamerParameters_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureRearCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureRearCamerParameters_Start RoutineServices_ConfigureRearCamerParameters_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureRightCamerParameters_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureRightCamerParameters_RequestResults RoutineServices_ConfigureRightCamerParameters_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ConfigureRightCamerParameters_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ConfigureRightCamerParameters_Start RoutineServices_ConfigureRightCamerParameters_Start
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_IVITouchTest_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_IVITouchTest_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_IVITouchTest_RequestResults RoutineServices_IVITouchTest_RequestResults
#  define RTE_START_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_EOL_APPL_CODE) RoutineServices_IVITouchTest_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_EOL_APPL_VAR) Out_0xF004, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_EOL_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_EOL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_IVITouchTest_Start RoutineServices_IVITouchTest_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ODOReset_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_OdoResetResult, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ODOReset_RequestResults RoutineServices_ODOReset_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ODOReset_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ODOReset_Start RoutineServices_ODOReset_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_PhyTestMode_Start(uint8 In_PortNumber, uint8 In_TestMode, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_PhyTestMode_Start RoutineServices_PhyTestMode_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_RequestCertificateStatus_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) DcmDspRoutineRequestResOutSignal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_RequestCertificateStatus_RequestResults RoutineServices_RequestCertificateStatus_RequestResults
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_RequestCertificateStatus_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_RequestCertificateStatus_Start RoutineServices_RequestCertificateStatus_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_ResetSwitchStatistics_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_ResetSwitchStatistics_Start RoutineServices_ResetSwitchStatistics_Start
#  define RTE_START_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DIDDATAPROCESS_APPL_CODE) RoutineServices_SystemRecovery_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) Out_SystemRcvrySts, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIDDATAPROCESS_APPL_VAR) ErrorCode); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DIDDATAPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RoutineServices_SystemRecovery_Start RoutineServices_SystemRecovery_Start
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_Level_EOL_Unlocked_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_Level_EOL_Unlocked_CompareKey(P2CONST(Dcm_Data8ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_Level_EOL_Unlocked_CompareKey SecurityAccess_Level_EOL_Unlocked_CompareKey
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) AttemptCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter SecurityAccess_Level_EOL_Unlocked_GetSecurityAttemptCounter
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_Level_EOL_Unlocked_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_Level_EOL_Unlocked_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_Level_EOL_Unlocked_GetSeed SecurityAccess_Level_EOL_Unlocked_GetSeed
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter SecurityAccess_Level_EOL_Unlocked_SetSecurityAttemptCounter
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_UnlockedL1_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_UnlockedL1_CompareKey(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_UnlockedL1_CompareKey SecurityAccess_UnlockedL1_CompareKey
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_UnlockedL1_GetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) AttemptCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_UnlockedL1_GetSecurityAttemptCounter SecurityAccess_UnlockedL1_GetSecurityAttemptCounter
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_UnlockedL1_GetSeed SecurityAccess_UnlockedL1_GetSeed
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) SecurityAccess_UnlockedL1_SetSecurityAttemptCounter(Dcm_OpStatusType OpStatus, uint8 AttemptCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_SecurityAccess_UnlockedL1_SetSecurityAttemptCounter SecurityAccess_UnlockedL1_SetSecurityAttemptCounter
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) ServiceRequestNotificationGwm_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestGWMNotification_Confirmation ServiceRequestNotificationGwm_Confirmation
#  define RTE_START_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) ServiceRequestNotificationGwm_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DCM_SERVER_APPL_CODE) ServiceRequestNotificationGwm_Indication(uint8 SID, P2CONST(Dcm_Data4095ByteType, AUTOMATIC, RTE_DCM_SERVER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_SERVER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_DCM_SERVER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestGWMNotification_Indication ServiceRequestNotificationGwm_Indication


# endif /* !defined(RTE_CORE) */


# define Dcm_START_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dcm_MainFunction Dcm_MainFunction
#  define RTE_RUNNABLE_GetActiveProtocol Dcm_GetActiveProtocol
#  define RTE_RUNNABLE_GetRequestKind Dcm_GetRequestKind
#  define RTE_RUNNABLE_GetSecurityLevel Dcm_GetSecurityLevel
#  define RTE_RUNNABLE_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_RUNNABLE_ResetToDefaultSession Dcm_ResetToDefaultSession
#  define RTE_RUNNABLE_SetActiveDiagnostic Dcm_SetActiveDiagnostic
# endif

FUNC(void, Dcm_CODE) Dcm_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetRequestKind(uint16 TesterSourceAddress, P2VAR(Dcm_RequestKindType, AUTOMATIC, RTE_DCM_APPL_VAR) RequestKind); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_ResetToDefaultSession(void); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_SetActiveDiagnostic(boolean active); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Dcm_STOP_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag1_E_NOT_OK (1U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DIDRange_DidRangeDiag2_E_NOT_OK (1U)

#  define RTE_E_DataServices_DIDRange_DidRangeEol1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DIDRange_DidRangeEol1_E_NOT_OK (1U)

#  define RTE_E_DataServices_VehicleModel_VehicleModel_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_VehicleModel_VehicleModel_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_AMPCalibration_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AMPCalibration_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AMPCalibration_E_NOT_OK (1U)

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

#  define RTE_E_RoutineServices_AVMRegister_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_AVMRegister_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_AVMRegister_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_CableDiagnostics_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_CableDiagnostics_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_CableDiagnostics_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_CheckEthernetIPPINGFunction_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_CheckEthernetIPPINGFunction_E_NOT_OK (1U)

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

#  define RTE_E_RoutineServices_IVITouchTest_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_IVITouchTest_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_IVITouchTest_E_NOT_OK (1U)

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

#  define RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_Level_EOL_Unlocked_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_Level_EOL_Unlocked_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DCM_H */

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

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
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
