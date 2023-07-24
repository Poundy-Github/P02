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
 *             File:  Rte_DemMaster_0.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application header file for SW-C <DemMaster_0>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DEMMASTER_0_H
# define RTE_DEMMASTER_0_H

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

# include "Rte_DemMaster_0_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_open_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_short_to_battery_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_short_to_ground_Circuit_Short_To_Ground_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_ControlModuleCANBus_off_Bus_off_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_BacklightModuleError_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_ForceInductionFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_LowVoltage_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_NotReceiveBacklightValue_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_OverVoltage_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_TFT_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_TouchPanelFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_VibratorFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_VideoSignalConnectFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ASIC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_TCP_communication_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_AVM_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_ConsoleDisplay_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_DMS_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_DVR_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_IP_Display_Front_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_IVI_Display_Front_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_InCarCamera_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_PassengerDisplay_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_RVC_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_W_HUD_Missing_Message_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_GWSecOcFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_TBoxSecOcFailure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_software_module_running_error_Unexpected_Operation_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_open_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_open_Circuit_Open_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter(P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_CBFaultDetectCtr_A2B_open_Circuit_Open_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_open_Circuit_Open_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_A2B_short_to_battery_Circuit_Short_To_Battery_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_short_to_battery_Circuit_Short_To_Battery_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_A2B_short_to_ground_Circuit_Short_To_Ground_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_A2B_short_to_ground_Circuit_Short_To_Ground_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_ControlModuleCANBus_off_Bus_off_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_ControlModuleCANBus_off_Bus_off_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_BacklightModuleError_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_BacklightModuleError_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_ForceInductionFailure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_ForceInductionFailure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_LowVoltage_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_LowVoltage_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_NotReceiveBacklightValue_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_NotReceiveBacklightValue_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_OverVoltage_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_OverVoltage_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_TFT_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_TFT_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_TouchPanelFailure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_TouchPanelFailure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_VibratorFailure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_VibratorFailure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_HVAC_Display_VideoSignalConnectFailure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_HVAC_Display_VideoSignalConnectFailure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_IP_Display_ASIC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ASIC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_TCP_communication_Missing_Message_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_TCP_communication_Missing_Message_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_AVM_Missing_Message_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_AVM_Missing_Message_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_ConsoleDisplay_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_ConsoleDisplay_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_DMS_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_DMS_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_DVR_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_DVR_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_IP_Display_Front_Missing_Message_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_IP_Display_Front_Missing_Message_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_IVI_Display_Front_Missing_Message_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_IVI_Display_Front_Missing_Message_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_InCarCamera_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_InCarCamera_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_PassengerDisplay_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_PassengerDisplay_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_RVC_Missing_Message_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_RVC_Missing_Message_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Lost_communication_with_W_HUD_Missing_Message_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Lost_communication_with_W_HUD_Missing_Message_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_SecOC_GWSecOcFailure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_GWSecOcFailure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_SecOC_TBoxSecOcFailure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_TBoxSecOcFailure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_SecOC_software_module_running_error_Unexpected_Operation_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_SecOC_software_module_running_error_Unexpected_Operation_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM1_open_Circuit_Open_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_open_Circuit_Open_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM1_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM1_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM1_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM2_open_Circuit_Open_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_open_Circuit_Open_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM2_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter
#  define Rte_Call_CBFaultDetectCtr_TUNER_FM2_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter Rte_Call_DemMaster_0_CBFaultDetectCtr_TUNER_FM2_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd001_Vehicle_Speed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd001_Vehicle_Speed_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBReadData_DID_0xd001_Vehicle_Speed_ReadData CSDataServices_DID_0xd001_Vehicle_Speed_ReadData
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd002_EngineSpeed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd002_EngineSpeed_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBReadData_DID_0xd002_EngineSpeed_ReadData CSDataServices_DID_0xd002_EngineSpeed_ReadData
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd003_OperatingVoltage_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd003_OperatingVoltage_ReadData(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBReadData_DID_0xd003_OperatingVoltage_ReadData CSDataServices_DID_0xd003_OperatingVoltage_ReadData
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd004_Odometer_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd004_Odometer_ReadData(P2VAR(DataArrayType_uint8_3, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBReadData_DID_0xd004_Odometer_ReadData CSDataServices_DID_0xd004_Odometer_ReadData
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData(P2VAR(DataArrayType_uint8_4, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBReadData_DID_0xd005_DTC_Occurrence_Timer_ReadData CSDataServices_DID_0xd005_DTC_Occurrence_Timer_ReadData
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBReadData_DID_0xd006_ActualRotationSpeed_ReadData CSDataServices_DID_0xd006_ActualRotationSpeed_ReadData
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SOCDTCPROCESS_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBReadData_DID_0xd007_ActualRotationSpeed02_ReadData CSDataServices_DID_0xd007_ActualRotationSpeed02_ReadData
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) ClearDtcNotificationFinish_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ClearDtcNotification_DemEventMemorySet_DemClearDTCNotification_Finish_ClearDtcNotification ClearDtcNotificationFinish_ClearDtcNotification
#  define RTE_START_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(Std_ReturnType, RTE_SOCDTCPROCESS_APPL_CODE) ClearDtcNotificationStart_ClearDtcNotification(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  define RTE_STOP_SEC_SOCDTCPROCESS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_ClearDtcNotification_DemEventMemorySet_DemClearDTCNotification_Start_ClearDtcNotification ClearDtcNotificationStart_ClearDtcNotification


# endif /* !defined(RTE_CORE) */


# define DemMaster_0_START_SEC_CODE
# include "DemMaster_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ClearDTC Dem_ClearDTC
#  define RTE_RUNNABLE_Dem_MasterMainFunction Dem_MasterMainFunction
#  define RTE_RUNNABLE_GetDTCOfEvent Dem_GetDTCOfEvent
#  define RTE_RUNNABLE_GetDTCStatusAvailabilityMask Dem_GetDTCStatusAvailabilityMask
#  define RTE_RUNNABLE_GetDTCSuppression Dem_GetDTCSuppression
#  define RTE_RUNNABLE_GetDebouncingOfEvent Dem_GetDebouncingOfEvent
#  define RTE_RUNNABLE_GetEventAvailable Dem_GetEventAvailable
#  define RTE_RUNNABLE_GetEventEnableCondition Dem_GetEventEnableCondition
#  define RTE_RUNNABLE_GetEventExtendedDataRecordEx Dem_GetEventExtendedDataRecordEx
#  define RTE_RUNNABLE_GetEventFailed Dem_GetEventFailed
#  define RTE_RUNNABLE_GetEventFreezeFrameDataEx Dem_GetEventFreezeFrameDataEx
#  define RTE_RUNNABLE_GetEventMemoryOverflow Dem_GetEventMemoryOverflow
#  define RTE_RUNNABLE_GetEventStatus Dem_GetEventUdsStatus
#  define RTE_RUNNABLE_GetEventTested Dem_GetEventTested
#  define RTE_RUNNABLE_GetEventUdsStatus Dem_GetEventUdsStatus
#  define RTE_RUNNABLE_GetFaultDetectionCounter Dem_GetFaultDetectionCounter
#  define RTE_RUNNABLE_GetMonitorStatus Dem_GetMonitorStatus
#  define RTE_RUNNABLE_GetNumberOfEventMemoryEntries Dem_GetNumberOfEventMemoryEntries
#  define RTE_RUNNABLE_GetOperationCycleState Dem_GetOperationCycleState
#  define RTE_RUNNABLE_PostRunRequested Dem_PostRunRequested
#  define RTE_RUNNABLE_SelectDTC Dem_SelectDTC
#  define RTE_RUNNABLE_SetDTCSuppression Dem_SetDTCSuppression
#  define RTE_RUNNABLE_SetEnableCondition Dem_SetEnableCondition
#  define RTE_RUNNABLE_SetEventAvailable Dem_SetEventAvailable
#  define RTE_RUNNABLE_SetOperationCycleState Dem_SetOperationCycleState
# endif

FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_ClearDTC(uint8 parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DemMaster_0_CODE) Dem_MasterMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCOfEvent); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCStatusAvailabilityMask(uint8 ClientId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCStatusMask); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCSuppression(uint8 parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) SuppressionStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDebouncingOfEvent(Dem_EventIdType EventId, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DebouncingState); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventAvailable(Dem_EventIdType parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) AvailableStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventEnableCondition(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) ConditionFullfilled); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventFailed); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventMemoryOverflow(uint8 parg0, Dem_DTCOriginType parg1, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) OverflowIndication); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventTested); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetMonitorStatus(Dem_EventIdType EventId, P2VAR(Dem_MonitorStatusType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) MonitorStatus); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetNumberOfEventMemoryEntries(uint8 parg0, Dem_DTCOriginType parg1, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) NumberOfEventMemoryEntries); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetOperationCycleState(uint8 parg0, P2VAR(Dem_OperationCycleStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) CycleState); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_PostRunRequested(P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) IsRequested); /* PRQA S 3451, 0786, 3449, 0624 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SelectDTC(uint8 parg0, uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetDTCSuppression(uint8 parg0, boolean SuppressionStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetEnableCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetEventAvailable(Dem_EventIdType parg0, boolean AvailableStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetOperationCycleState(uint8 parg0, Dem_OperationCycleStateType CycleState); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define DemMaster_0_STOP_SEC_CODE
# include "DemMaster_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_DID_0xd001_Vehicle_Speed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd002_EngineSpeed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd003_OperatingVoltage_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd004_Odometer_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd005_DTC_Occurrence_Timer_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd006_ActualRotationSpeed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_DID_0xd007_ActualRotationSpeed02_E_NOT_OK (1U)

#  define RTE_E_CallbackGetFaultDetectCounter_E_NOT_OK (1U)

#  define RTE_E_ClearDTC_DEM_CLEAR_BUSY (5U)

#  define RTE_E_ClearDTC_DEM_CLEAR_FAILED (7U)

#  define RTE_E_ClearDTC_DEM_CLEAR_MEMORY_ERROR (6U)

#  define RTE_E_ClearDTC_DEM_PENDING (4U)

#  define RTE_E_ClearDTC_DEM_WRONG_DTC (8U)

#  define RTE_E_ClearDTC_DEM_WRONG_DTCORIGIN (9U)

#  define RTE_E_ClearDTC_E_NOT_OK (1U)

#  define RTE_E_ClearDTC_E_OK (0U)

#  define RTE_E_ClearDtcNotification_E_OK (0U)

#  define RTE_E_DTCSuppression_DEM_PENDING (4U)

#  define RTE_E_DTCSuppression_DEM_WRONG_DTC (8U)

#  define RTE_E_DTCSuppression_DEM_WRONG_DTCORIGIN (9U)

#  define RTE_E_DTCSuppression_E_NOT_OK (1U)

#  define RTE_E_DemServices_E_NOT_OK (1U)

#  define RTE_E_EnableCondition_E_NOT_OK (1U)

#  define RTE_E_EvMemOverflowIndication_E_NOT_OK (1U)

#  define RTE_E_EventAvailable_E_NOT_OK (1U)

#  define RTE_E_EventAvailable_E_OK (0U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_GeneralDiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DEMMASTER_0_H */

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
