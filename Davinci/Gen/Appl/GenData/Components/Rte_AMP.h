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
 *             File:  Rte_AMP.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <AMP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_AMP_H
# define RTE_AMP_H

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
# include "Rte_AMP_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_AMP_ppSR_AMPDeInitFinished_State;
extern VAR(uint16, RTE_VAR_INIT) Rte_EOL_EOL_AMPCalibration_AMPCalibration;
extern VAR(uint8, RTE_VAR_INIT) Rte_AMP_Sd_AMP_Notify_Message_Element;
extern VAR(uint32, RTE_VAR_INIT) Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EOL_AMPCalibration_AMPCalibration (0U)
#  define Rte_InitValue_Rc_AMP_Notify_Message_Element (0U)
#  define Rte_InitValue_Sd_AMP_Notify_Message_Element (0U)
#  define Rte_InitValue_ppSR_AMPDeInitFinished_State (FALSE)
#  define Rte_InitValue_rpSR_piDiagMonitorReInitFlag_ChangeCounter (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AMP_rpSR_Power_Out_SystemStateOut(P2VAR(SystemState_RecordType, AUTOMATIC, RTE_AMP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_AMP_Sd_IIC0_Notify_Message_Message(uint16 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_AVASDTCResults_AVASDTC(P2CONST(AVASDTCRet, AUTOMATIC, RTE_AMP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_EOL_AMPCalibrationRece_EOLReceive(P2CONST(uint8, AUTOMATIC, RTE_AMP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_EOL_AMPCalibrationRece_EOLReceive(P2CONST(A_U8_10, AUTOMATIC, RTE_AMP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(P2CONST(uint8, AUTOMATIC, RTE_AMP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue(P2CONST(EOL9Bytes, AUTOMATIC, RTE_AMP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AMP_Sd_AMP_Notify_Message_Element(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AMP_Os_Service_GetCounterValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_AMP_APPL_VAR) Value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AMP_Os_Service_GetElapsedValue(P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_AMP_APPL_VAR) Value, P2VAR(TimeInMicrosecondsType, AUTOMATIC, RTE_AMP_APPL_VAR) ElapsedValue); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint16 kindId, P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) kindConfig); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EOL_AMPCalibration_AMPCalibration Rte_Read_AMP_EOL_AMPCalibration_AMPCalibration
#  define Rte_Read_AMP_EOL_AMPCalibration_AMPCalibration(data) (*(data) = Rte_EOL_EOL_AMPCalibration_AMPCalibration, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_Rc_AMP_Notify_Message_Element Rte_Read_AMP_Rc_AMP_Notify_Message_Element
#  define Rte_Read_AMP_Rc_AMP_Notify_Message_Element(data) (*(data) = Rte_AMP_Sd_AMP_Notify_Message_Element, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Read_rpSR_Power_Out_SystemStateOut Rte_Read_AMP_rpSR_Power_Out_SystemStateOut
#  define Rte_Read_rpSR_piDiagMonitorReInitFlag_ChangeCounter Rte_Read_AMP_rpSR_piDiagMonitorReInitFlag_ChangeCounter
#  define Rte_Read_AMP_rpSR_piDiagMonitorReInitFlag_ChangeCounter(data) (*(data) = Rte_SocDtcProcess_pPSR_DiagMonitorReInitFlag_ChangeCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Send_Sd_IIC0_Notify_Message_Message Rte_Send_AMP_Sd_IIC0_Notify_Message_Message


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AVASDTCResults_AVASDTC Rte_Write_AMP_AVASDTCResults_AVASDTC
#  define Rte_Write_EOL_AMPCalibrationRece_EOLReceive Rte_Write_AMP_EOL_AMPCalibrationRece_EOLReceive
#  define Rte_Write_EOL_ReadAmpCalibrationValue_AmpCalibrationValue Rte_Write_AMP_EOL_ReadAmpCalibrationValue_AmpCalibrationValue
#  define Rte_Write_Sd_AMP_Notify_Message_Element Rte_Write_AMP_Sd_AMP_Notify_Message_Element
#  define Rte_Write_ppSR_AMPDeInitFinished_State Rte_Write_AMP_ppSR_AMPDeInitFinished_State
#  define Rte_Write_AMP_ppSR_AMPDeInitFinished_State(data) (Rte_AMP_ppSR_AMPDeInitFinished_State = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (mapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_Os_Service_GetCounterValue Rte_Call_AMP_Os_Service_GetCounterValue
#  define Rte_Call_Os_Service_GetElapsedValue Rte_Call_AMP_Os_Service_GetElapsedValue
#  define Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig Rte_Call_AMP_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_ResetEventStatus(Dem_EventIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DTC9A0101_FLShortAcross_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)90)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DTC9A0101_FLShortAcross_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)90, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0111_FLShortToGND_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)92)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0111_FLShortToGND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)92, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0112_FLShorttoBAT_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)91)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0112_FLShorttoBAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)91, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0113_FLOpen_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)87)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0113_FLOpen_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)87, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A011E_FLResistanceOutRange_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)89)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A011E_FLResistanceOutRange_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)89, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0125_FLOutputClip_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)88)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0125_FLOutputClip_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)88, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0201_FRShortAcross_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)96)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0201_FRShortAcross_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)96, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0211_FRShortToGND_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)98)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0211_FRShortToGND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)98, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0212_FRShorttoBAT_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)97)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0212_FRShorttoBAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)97, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0213_FROpen_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)93)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0213_FROpen_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)93, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A021E_FRResistanceOutRange_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)95)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A021E_FRResistanceOutRange_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)95, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0225_FROutputClip_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)94)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0225_FROutputClip_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)94, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0301_RLShortAcross_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)102)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0301_RLShortAcross_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)102, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0311_RLShortToGND_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)104)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0311_RLShortToGND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)104, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0312_RLShorttoBAT_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)103)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0312_RLShorttoBAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)103, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0313_RLOpen_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)99)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0313_RLOpen_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)99, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A031E_RLResistanceOutRange_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)101)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A031E_RLResistanceOutRange_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)101, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0325_RLOutputClip_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)100)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0325_RLOutputClip_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)100, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0401_RRShortAcross_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)108)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0401_RRShortAcross_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)108, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0411_RRShortToGND_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)110)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0411_RRShortToGND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)110, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0412_RRShorttoBAT_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)109)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0412_RRShorttoBAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)109, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0413_RROpen_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)105)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0413_RROpen_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)105, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A041E_RRResistanceOutRange_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)107)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A041E_RRResistanceOutRange_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)107, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0425_RROutputClip_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)106)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0425_RROutputClip_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)106, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0501_CenterShortAcross_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)84)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0501_CenterShortAcross_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)84, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0511_CneterShortToGND_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)86)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0511_CneterShortToGND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)86, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0512_CenterShorttoBAT_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)85)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0512_CenterShorttoBAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)85, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0513_CenterOpen_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)80)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0513_CenterOpen_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)80, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A051E_CenterResistanceOutRange_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)83)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A051E_CenterResistanceOutRange_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)83, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0525_CenterOutputClip_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)82)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0525_CenterOutputClip_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)82, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0601_WooferShortAcross_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)114)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0601_WooferShortAcross_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)114, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0611_WooferShortToGND_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)116)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0611_WooferShortToGND_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)116, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0612_WooferShorttoBAT_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)115)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0612_WooferShorttoBAT_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)115, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0613_WooferOpen_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)111)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0613_WooferOpen_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)111, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A061E_WooferResistanceOutRange_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)113)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A061E_WooferResistanceOutRange_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)113, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0625_WooferOutputClip_ResetEventStatus() (Dem_ResetEventStatus((Dem_EventIdType)112)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0625_WooferOutputClip_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)112, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetDTCOfEvent(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetEventFailed(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetEventTested(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetEventUdsStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_GetFaultDetectionCounter(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_ResetEventDebounceStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_ResetEventStatus() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0701_AVASShortAcross_SetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetDTCOfEvent(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetEventFailed(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetEventTested(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetEventUdsStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_GetFaultDetectionCounter(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_ResetEventDebounceStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_ResetEventStatus() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0711_AVASShortToGND_SetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetDTCOfEvent(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventFailed(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventTested(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetEventUdsStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_GetFaultDetectionCounter(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_ResetEventDebounceStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_ResetEventStatus() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0712_AVASShorttoBAT_SetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetDTCOfEvent(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetEventFailed(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetEventTested(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetEventUdsStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_GetFaultDetectionCounter(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_ResetEventDebounceStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_ResetEventStatus() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0713_AVASOpen_SetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetDTCOfEvent(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventFailed(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventTested(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetEventUdsStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_GetFaultDetectionCounter(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_ResetEventDebounceStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_ResetEventStatus() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A071E_AVASResistanceOutRange_SetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetDTCOfEvent(arg1, arg2) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetEventExtendedDataRecordEx(arg1, arg2, arg3) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetEventFailed(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetEventFreezeFrameDataEx(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetEventTested(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetEventUdsStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_GetFaultDetectionCounter(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_ResetEventDebounceStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_ResetEventStatus() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_DTC9A0725_AVASOutputClip_SetEventStatus(arg1) (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)53, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Call_NvMService_AC2_SRBS_Defs_NvBlockNeed_LC_Calibration2_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)60, arg1)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(A_u8_20, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration2_DefaultValue;
extern CONST(A_u8_20, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_LC_Calibration2_DefaultValue() (&(Rte_AMP_NvBlockNeed_LC_Calibration2_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_LC_Calibration2_DefaultValue() (&Rte_AMP_NvBlockNeed_LC_Calibration2_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_NvBlockNeed_LC_Calibration_DefaultValue() (&(Rte_AMP_NvBlockNeed_LC_Calibration_DefaultValue[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#   define Rte_CData_NvBlockNeed_LC_Calibration_DefaultValue() (&Rte_AMP_NvBlockNeed_LC_Calibration_DefaultValue) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(A_u8_20, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration2_MirrorBlock;
extern VAR(A_u8_20, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_AMP_NvBlockNeed_LC_Calibration_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_LC_Calibration2_MirrorBlock() (&((*RtePim_NvBlockNeed_LC_Calibration2_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_LC_Calibration2_MirrorBlock() RtePim_NvBlockNeed_LC_Calibration2_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_LC_Calibration2_MirrorBlock() \
  (&Rte_AMP_NvBlockNeed_LC_Calibration2_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_NvBlockNeed_LC_Calibration_MirrorBlock() (&((*RtePim_NvBlockNeed_LC_Calibration_MirrorBlock())[0]))
#  else
#   define Rte_Pim_NvBlockNeed_LC_Calibration_MirrorBlock() RtePim_NvBlockNeed_LC_Calibration_MirrorBlock()
#  endif
#  define RtePim_NvBlockNeed_LC_Calibration_MirrorBlock() \
  (&Rte_AMP_NvBlockNeed_LC_Calibration_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define AMP_START_SEC_CODE
# include "AMP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_AMP_EOL_Read_Operation AMP_EOL_Read_Operation
#  define RTE_RUNNABLE_AMP_Event_MainFunction AMP_Event_MainFunction
#  define RTE_RUNNABLE_AMP_MainFunction AMP_MainFunction
#  define RTE_RUNNABLE_EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2 EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2
#  define RTE_RUNNABLE_NvBlockNeed_LC_Calibration2_JobFinished NvBlockNeed_LC_Calibration2_JobFinished
#  define RTE_RUNNABLE_NvBlockNeed_LC_Calibration_JobFinished NvBlockNeed_LC_Calibration_JobFinished
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, AMP_CODE) AMP_EOL_Read_Operation(P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, AMP_CODE) AMP_EOL_Read_Operation(P2VAR(A_U8_10, AUTOMATIC, RTE_AMP_APPL_VAR) value); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, AMP_CODE) AMP_Event_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, AMP_CODE) AMP_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, AMP_CODE) EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(P2VAR(uint8, AUTOMATIC, RTE_AMP_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(void, AMP_CODE) EOL_Get_SpeakerStatus_0xFDD2_EOL_Get_SpeakerStatus_0xFDD2(P2VAR(EOL_4Bytes, AUTOMATIC, RTE_AMP_APPL_VAR) arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, AMP_CODE) NvBlockNeed_LC_Calibration2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, AMP_CODE) NvBlockNeed_LC_Calibration_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define AMP_STOP_SEC_CODE
# include "AMP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_AMP_EOL_Read_N_OK (1U)

#  define RTE_E_DiagnosticMonitor_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_DiagnosticMonitor_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_DiagnosticMonitor_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_Os_Service_E_OK (0U)

#  define RTE_E_Os_Service_E_OS_ID (3U)

#  define RTE_E_Os_Service_E_OS_VALUE (8U)

#  define RTE_E_VConfig_GetKindConfig_Std_ReturnType (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_AMP_H */

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
