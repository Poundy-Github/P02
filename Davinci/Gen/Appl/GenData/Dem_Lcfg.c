/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Dem
 *           Program: MSR_Vector_SLP4
 *          Customer: Nobo Automotive Systems Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016513ABG
 *    License Scope : The usage is restricted to CBD2000298_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_Lcfg.c
 *   Generation Time: 2022-01-25 11:37:06
 *           Project: HUT_V3_5 - Version 1.0
 *          Delivery: CBD2000298_D00
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DemEnableConditionGroupRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dem/DemConfigSet/Lost_communication_with_AVM_Missing_Message/DemEventClass[0:DemEnableConditionGroupRef](value={empty}) (DefRef: /MICROSAR/Dem/DemConfigSet/DemEventParameter/DemEventClass/DemEnableConditionGroupRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DemEnableConditionGroupRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dem/DemConfigSet/Over_voltage_Circuit_Voltage_Above_Threshold/DemEventClass[0:DemEnableConditionGroupRef](value={empty}) (DefRef: /MICROSAR/Dem/DemConfigSet/DemEventParameter/DemEventClass/DemEnableConditionGroupRef)
 * 
 * [Warning] Cfg00022 - Missing parameter value 
 * - [Reduced Severity due to User-Defined Parameter] The value of reference DemEnableConditionGroupRef is missing or empty.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dem/DemConfigSet/Under_voltage_Circuit_Voltage_Below_Threshold/DemEventClass[0:DemEnableConditionGroupRef](value={empty}) (DefRef: /MICROSAR/Dem/DemConfigSet/DemEventParameter/DemEventClass/DemEnableConditionGroupRef)
 *********************************************************************************************************************/


/* configuration, interrupt handling implementations differ from the
 * source identification define used here. The naming
 * schemes for those files can be taken from this list:
 *
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE


/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */                                      /* Maximum '#if...' nesting exceeds 8 levels - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */                                      /* Number of macro definitions exceeds 1024 - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */                                          /* Identifier does not differ in 32 significant characters -- caused by Autosar algorithm for unique symbolic names. */
/* PRQA S 0612 EOF */ /* MD_DEM_1.1_612 */                                      /* The size of an object exceeds 32767 bytes - program is non-conforming -- caused by large user configuration. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "Dem.h"
#include "Os.h"
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"                                                               /* get: symbolic names for NvM block IDs */
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)
# include "J1939Nm.h"                                                           /* get: symbolic names for J1939Nm node IDs */
#endif
#if (DEM_CFG_USE_RTE == STD_ON)
/* DEM used with RTE */
# include "Rte_DemMaster_0.h"
#endif
#include "Dem_AdditionalIncludeCfg.h"                                           /* additional, configuration defined files */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Dem_Cfg_CallbackGetFdc
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_CallbackGetFdc
  \brief  DemCallbackGetFDC/DemCallbackGetFDCFnc of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceMonitorInternal
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_GetFDCFPtrType, DEM_CONST) Dem_Cfg_CallbackGetFdc[58] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CallbackGetFdc                                                                                                                                 Referable Keys */
  /*     0 */ Rte_Call_CBFaultDetectCtr_TUNER_FM2_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter                                       ,  /* [TUNER_FM2_short_to_groud_Circuit_Short_To_Ground] */
  /*     1 */ Rte_Call_CBFaultDetectCtr_TUNER_FM2_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter                                    ,  /* [TUNER_FM2_short_to_battary_Circuit_Short_To_Battery] */
  /*     2 */ Rte_Call_CBFaultDetectCtr_TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter                       ,  /* [TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold] */
  /*     3 */ Rte_Call_CBFaultDetectCtr_TUNER_FM2_open_Circuit_Open_GetFaultDetectionCounter                                                            ,  /* [TUNER_FM2_open_Circuit_Open] */
  /*     4 */ Rte_Call_CBFaultDetectCtr_TUNER_FM1_short_to_groud_Circuit_Short_To_Ground_GetFaultDetectionCounter                                       ,  /* [TUNER_FM1_short_to_groud_Circuit_Short_To_Ground] */
  /*     5 */ Rte_Call_CBFaultDetectCtr_TUNER_FM1_short_to_battary_Circuit_Short_To_Battery_GetFaultDetectionCounter                                    ,  /* [TUNER_FM1_short_to_battary_Circuit_Short_To_Battery] */
  /*     6 */ Rte_Call_CBFaultDetectCtr_TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold_GetFaultDetectionCounter                       ,  /* [TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold] */
  /*     7 */ Rte_Call_CBFaultDetectCtr_TUNER_FM1_open_Circuit_Open_GetFaultDetectionCounter                                                            ,  /* [TUNER_FM1_open_Circuit_Open] */
  /*     8 */ Rte_Call_CBFaultDetectCtr_Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter   ,  /* [Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure] */
  /*     9 */ Rte_Call_CBFaultDetectCtr_SecOC_software_module_running_error_Unexpected_Operation_GetFaultDetectionCounter                               ,  /* [SecOC_software_module_running_error_Unexpected_Operation] */
  /*    10 */ Rte_Call_CBFaultDetectCtr_SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure_GetFaultDetectionCounter                       ,  /* [SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure] */
  /*    11 */ Rte_Call_CBFaultDetectCtr_SecOC_TBoxSecOcFailure_GetFaultDetectionCounter                                                                 ,  /* [SecOC_TBoxSecOcFailure] */
  /*    12 */ Rte_Call_CBFaultDetectCtr_SecOC_GWSecOcFailure_GetFaultDetectionCounter                                                                   ,  /* [SecOC_GWSecOcFailure] */
  /*    13 */ Rte_Call_CBFaultDetectCtr_SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved_GetFaultDetectionCounter                ,  /* [SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved] */
  /*    14 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_W_HUD_Missing_Message_GetFaultDetectionCounter                                          ,  /* [Lost_communication_with_W_HUD_Missing_Message] */
  /*    15 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_RVC_Missing_Message_GetFaultDetectionCounter                                            ,  /* [Lost_communication_with_RVC_Missing_Message] */
  /*    16 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_PassengerDisplay_GetFaultDetectionCounter                                               ,  /* [Lost_communication_with_PassengerDisplay] */
  /*    17 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_InCarCamera_GetFaultDetectionCounter                                                    ,  /* [Lost_communication_with_InCarCamera] */
  /*    18 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_IVI_Display_Front_Missing_Message_GetFaultDetectionCounter                              ,  /* [Lost_communication_with_IVI_Display_Front_Missing_Message] */
  /*    19 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_IP_Display_Front_Missing_Message_GetFaultDetectionCounter                               ,  /* [Lost_communication_with_IP_Display_Front_Missing_Message] */
  /*    20 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_DVR_GetFaultDetectionCounter                                                            ,  /* [Lost_communication_with_DVR] */
  /*    21 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_DMS_GetFaultDetectionCounter                                                            ,  /* [Lost_communication_with_DMS] */
  /*    22 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_ConsoleDisplay_GetFaultDetectionCounter                                                 ,  /* [Lost_communication_with_ConsoleDisplay] */
  /*    23 */ Rte_Call_CBFaultDetectCtr_Lost_communication_with_AVM_Missing_Message_GetFaultDetectionCounter                                            ,  /* [Lost_communication_with_AVM_Missing_Message] */
  /*    24 */ Rte_Call_CBFaultDetectCtr_Lost_TCP_communication_Missing_Message_GetFaultDetectionCounter                                                 ,  /* [Lost_TCP_communication_Missing_Message] */
  /*    25 */ Rte_Call_CBFaultDetectCtr_IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure_GetFaultDetectionCounter                          ,  /* [IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure] */
  /*    26 */ Rte_Call_CBFaultDetectCtr_IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure_GetFaultDetectionCounter                        ,  /* [IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure] */
  /*    27 */ Rte_Call_CBFaultDetectCtr_IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter                           ,  /* [IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure] */
  /*    28 */ Rte_Call_CBFaultDetectCtr_IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter                            ,  /* [IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold] */
  /*    29 */ Rte_Call_CBFaultDetectCtr_IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter                             ,  /* [IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold] */
  /*    30 */ Rte_Call_CBFaultDetectCtr_IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter                       ,  /* [IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure] */
  /*    31 */ Rte_Call_CBFaultDetectCtr_IP_Display_ASIC_failure_Internal_Electronic_Failure_GetFaultDetectionCounter                                    ,  /* [IP_Display_ASIC_failure_Internal_Electronic_Failure] */
  /*    32 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure_GetFaultDetectionCounter ,  /* [INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure] */
  /*    33 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure_GetFaultDetectionCounter  ,  /* [INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure] */
  /*    34 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure_GetFaultDetectionCounter      ,  /* [INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure] */
  /*    35 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure_GetFaultDetectionCounter          ,  /* [INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure] */
  /*    36 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure_GetFaultDetectionCounter                  ,  /* [INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure] */
  /*    37 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold_GetFaultDetectionCounter             ,  /* [INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold] */
  /*    38 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold_GetFaultDetectionCounter              ,  /* [INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold] */
  /*    39 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range_GetFaultDetectionCounter                     ,  /* [INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range] */
  /*    40 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure_GetFaultDetectionCounter          ,  /* [INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure] */
  /*    41 */ Rte_Call_CBFaultDetectCtr_INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open_GetFaultDetectionCounter                   ,  /* [INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open] */
  /*    42 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_VideoSignalConnectFailure_GetFaultDetectionCounter                                                 ,  /* [HVAC_Display_VideoSignalConnectFailure] */
  /*    43 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_VibratorFailure_GetFaultDetectionCounter                                                           ,  /* [HVAC_Display_VibratorFailure] */
  /*    44 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_TouchPanelFailure_GetFaultDetectionCounter                                                         ,  /* [HVAC_Display_TouchPanelFailure] */
  /*    45 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_TFT_Failure_GetFaultDetectionCounter                                                               ,  /* [HVAC_Display_TFT_Failure] */
  /*    46 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_OverVoltage_GetFaultDetectionCounter                                                               ,  /* [HVAC_Display_OverVoltage] */
  /*    47 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_NotReceiveBacklightValue_GetFaultDetectionCounter                                                  ,  /* [HVAC_Display_NotReceiveBacklightValue] */
  /*    48 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_LowVoltage_GetFaultDetectionCounter                                                                ,  /* [HVAC_Display_LowVoltage] */
  /*    49 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_ForceInductionFailure_GetFaultDetectionCounter                                                     ,  /* [HVAC_Display_ForceInductionFailure] */
  /* Index     CallbackGetFdc                                                                                                                                 Referable Keys */
  /*    50 */ Rte_Call_CBFaultDetectCtr_HVAC_Display_BacklightModuleError_GetFaultDetectionCounter                                                      ,  /* [HVAC_Display_BacklightModuleError] */
  /*    51 */ Rte_Call_CBFaultDetectCtr_Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery_GetFaultDetectionCounter                           ,  /* [Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery] */
  /*    52 */ Rte_Call_CBFaultDetectCtr_Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect_GetFaultDetectionCounter                   ,  /* [Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect] */
  /*    53 */ Rte_Call_CBFaultDetectCtr_ControlModuleCANBus_off_Bus_off_GetFaultDetectionCounter                                                        ,  /* [ControlModuleCANBus_off_Bus_off] */
  /*    54 */ Rte_Call_CBFaultDetectCtr_A2B_short_to_ground_Circuit_Short_To_Ground_GetFaultDetectionCounter                                            ,  /* [A2B_short_to_ground_Circuit_Short_To_Ground] */
  /*    55 */ Rte_Call_CBFaultDetectCtr_A2B_short_to_battery_Circuit_Short_To_Battery_GetFaultDetectionCounter                                          ,  /* [A2B_short_to_battery_Circuit_Short_To_Battery] */
  /*    56 */ Rte_Call_CBFaultDetectCtr_A2B_open_Circuit_Open_GetFaultDetectionCounter                                                                  ,  /* [A2B_open_Circuit_Open] */
  /*    57 */ NULL_PTR                                                                                                                                     /* [#EVENT_INVALID, AVM_CamerOpenCircuit, AVM_CamerShortToBattery, AVM_CamerShortToGround, AbnormalWakeupSleep, AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE, FactoryModeNotClosed, Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, GPS_AntennaOpen, GPS_AntennaShortToBattery, GPS_AntennaShortToGround, GPS_OverCurrent, INVALID_SHORTNAME_Over_Temperature_Over_Temperature, Internal_DMS_CameraCircuitOpen, Internal_DMS_CameraShortToBattery, Internal_DMS_CameraShortToGround, Internal_DVR_CameraCircuitOpen, Internal_DVR_CameraShortToBattery, Internal_DVR_CameraShortToGround, Internal_OMS_CameraCircuitOpen, Internal_OMS_CameraShortToBattery, Internal_OMS_CameraShortToGround, LostComWithAVMFrontCamera, LostComWithAVMLeftCamera, LostComWithAVMRearCamera, LostComWithAVMRightCamera, Lost_Communication_With_Depth_Of_Water_Detection_Module, Lost_communication_with_SVC_Missing_Message, Mic_1_open_Circuit_Open, Mic_1_short_to_BAT_Circuit_Short_To_Battery, Mic_1_short_to_GND_Circuit_Short_To_Ground, Mic_2_open_Circuit_Open, Mic_2_short_to_BAT_Circuit_Short_To_Battery, Mic_2_short_to_GND_Circuit_Short_To_Ground, MissingBattery_Management_System, Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Missing_Airbag_Module_Missing_Message, Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Missing_Combination_Switch_Assembly_Missing_Message, Missing_Controler_Headlamp_Missing_Message, Missing_Controller_Pedal_Missing_Message, Missing_Driver_Door_Control_Module_Missing_Message, Missing_Driver_Seat_Memory_module, Missing_Elec_Region_Control_System_Body_Missing_Message, Missing_Electric_Park_Brake_controller, Missing_Electric_Power_Steering_system_Missing_Message, Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Missing_Electronic_Gerodisc_Missing_Message, Missing_Engine_Control_Module_Missing_Message, Missing_Front_Power_Box_Missing_Message, Missing_Gateway_Missing_Message, Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Missing_Ibooster, Missing_Intelligent_Driving_Controller_Level2, Missing_Nextrac_Torque_On_Demand_Missing_Message, Missing_Onboard_charger, Missing_Power_Lift_Gate_module, Missing_PrePretensioner_Mechatronic_Integrated, Missing_Rear_Heat_Vent_Seat_Module, Missing_Rear_Power_Box_Missing_Message, Missing_Right_Headlamp_Control_Module, Missing_Screen_touch_button_switch_controller_Missing_Message, Missing_Seat_Control_Module, Missing_Transmission_Control_Until_PTCAN_Missing_Message, Missing_Wireless_Power_Charger_Missing_Message, Over_voltage_Circuit_Voltage_Above_Threshold, RVC_CamerShortToBattery, RVC_CameraOpenCircuit, RVC_CameraShortToGround, Read_CPScreen_IDFailed, Read_ClusterScreenIDFailed, Read_CoDriverScreenIDFailed, Read_HUDScreen_IDFailed, Read_IVIScreen_IDFailed, SVC_CameraOpen, SVC_CameraShortToBattery, SVC_CameraShortToGround, ScreenCPDriverErr, ScreenClusterDriverErr, ScreenCoDriverErr, ScreenHUDDriverErr, ScreenIVIDriverErr, SecOC_Security_PDU_Verification_Failed_from_ESP, SecOC_Security_PDU_Verification_Failed_from_IDC_L2, SecOC_Security_PDU_Verification_Failed_from_IDC_L3, SecOC_Security_PDU_Verification_Failed_from_IFC, SecOC_Security_PDU_Verification_Failed_from_TCU, Speaker_AVAS_CircuitOpen, Speaker_AVAS_ResistanceOutOfRange, Speaker_AVAS_ShortAcross, Speaker_AVAS_ShortToBattery, Speaker_AVAS_ShortToGround, Speaker_AVAS_WaveformLackFidelity, Speaker_Center_open_Circuit_Open, Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Center_short_across_General_Electrical_Failure, Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Speaker_FL_open_Circuit_Open, Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FL_short_across_General_Electrical_Failure, Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Speaker_FR_open_Circuit_Open, Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FR_short_across_General_Electrical_Failure, Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Speaker_RL_open_Circuit_Open, Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RL_short_across_General_Electrical_Failure, Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Speaker_RR_open_Circuit_Open, Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RR_short_across_General_Electrical_Failure, Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Speaker_Woofer_open_Circuit_Open, Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, 
              Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Woofer_short_across_General_Electrical_Failure, Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Temperature_SensorError, Under_voltage_Circuit_Voltage_Below_Threshold, missing_Adaptive_Cruise_Control_system_Radar_Control_Module, missing_Driver_Monitoring_System_Missing_Message, missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, missing_Parking_Assistance_System_Missing_Message, missing_Passenger_Door_Control_Module_Missing_Message, missing_Right_Corner_Radar, missing_Right_Rear_Side_Detection_System_Missing_Message, missing_Telematics_control_Box_Missing_Message, missing_Trailer_Missing_Message, missing_Tyre_Pressure_Monitoring_Systems_Missing_Message] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDtcNotificationFinishTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDtcNotificationFinishTable
  \brief  ClearDTCNotification callback functions which are called when FINISHing a clear DTC operation.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_ClearDtcNotificationFPtrType, DEM_CONST) Dem_Cfg_ClearDtcNotificationFinishTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ClearDtcNotificationFinishTable                                                                          Comment */
  /*     0 */ Rte_Call_ClearDtcNotification_DemEventMemorySet_DemClearDTCNotification_Finish_ClearDtcNotification    /* [DemEventMemorySet_DemClearDTCNotification_Finish] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDtcNotificationStartTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDtcNotificationStartTable
  \brief  ClearDTCNotification callback functions which are called when STARTing a clear DTC operation.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_ClearDtcNotificationFPtrType, DEM_CONST) Dem_Cfg_ClearDtcNotificationStartTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ClearDtcNotificationStartTable                                                                          Comment */
  /*     0 */ Rte_Call_ClearDtcNotification_DemEventMemorySet_DemClearDTCNotification_Start_ClearDtcNotification    /* [DemEventMemorySet_DemClearDTCNotification_Start] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CycleIdTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_CycleIdTable
  \details
  Element        Description
  MaskedBits     contains bitcoded the boolean data of Dem_Cfg_EndsOnInitOfCycleIdTable, Dem_Cfg_UsedForAgingOfCycleIdTable
  OpCycleType    DemOperationCycleType of the DemOperationCycle: [DEM_CFG_OPCYC_IGNITION, DEM_CFG_OPCYC_OBD_DCY, DEM_CFG_OPCYC_OTHER, DEM_CFG_OPCYC_POWER, DEM_CFG_OPCYC_TIME, DEM_CFG_OPCYC_WARMUP, DEM_CFG_OPCYC_IGNITION_HYBRID, DEM_CFG_OPCYC_AGING]
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_CycleIdTableType, DEM_CONST) Dem_Cfg_CycleIdTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  OpCycleType                   Comment */
  { /*     0 */      0x01u, DEM_CFG_OPCYC_IGNITION },  /* [DemConf_DemOperationCycle_Ignition_on_off] */
  { /*     1 */      0x00u, DEM_CFG_OPCYC_POWER    }   /* [DemConf_DemOperationCycle_Power_up_down] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTable
  \details
  Element                                Description
  IdNumber                           
  CollectionSize                     
  DataElementTableCol2ElmtIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  DataElementTableCol2ElmtIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  MaskedBits                             contains bitcoded the boolean data of Dem_Cfg_DataElementTableCol2ElmtIndUsedOfDataCollectionTable, Dem_Cfg_UpdateOfDataCollectionTable
  StorageKind                        
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableType, DEM_CONST) Dem_Cfg_DataCollectionTable[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IdNumber  CollectionSize  DataElementTableCol2ElmtIndEndIdx                                  DataElementTableCol2ElmtIndStartIdx                                  MaskedBits  StorageKind                       Referable Keys */
  { /*     0 */  0x0000u,             0u, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE,      0x00u, DEM_CFG_EREC_TYPE_GLOBAL   },  /* [#NoDataCollectionConfigured] */
  { /*     1 */  0x0001u,             1u,                                                                1u,                                                                  0u,      0x03u, DEM_CFG_EREC_TYPE_INTERNAL },  /* [#EdrDTCOccurrenceCounter, Ext:ExtendedDataClass_4f5344cd] */
  { /*     2 */  0x0002u,             1u,                                                                2u,                                                                  1u,      0x03u, DEM_CFG_EREC_TYPE_INTERNAL },  /* [#EdrSelfAgingCounter, Ext:ExtendedDataClass_4f5344cd] */
  { /*     3 */  0xD006u,             2u,                                                                3u,                                                                  2u,      0x02u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidActualRotationSpeed, Ffm:FreezeFrameClass_80c88891] */
  { /*     4 */  0xD007u,             2u,                                                                4u,                                                                  3u,      0x02u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidActualRotationSpeed02, Ffm:FreezeFrameClass_80c88891] */
  { /*     5 */  0xD005u,             4u,                                                                5u,                                                                  4u,      0x02u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDTCOccurrenceTimer, Ffm:FreezeFrameClass_80c88891] */
  { /*     6 */  0xD002u,             2u,                                                                6u,                                                                  5u,      0x02u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidEngineSpeed, Ffm:FreezeFrameClass_80c88891] */
  { /*     7 */  0xD004u,             3u,                                                                7u,                                                                  6u,      0x02u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidOdometer, Ffm:FreezeFrameClass_80c88891] */
  { /*     8 */  0xD003u,             1u,                                                                8u,                                                                  7u,      0x02u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidOperatingVoltage, Ffm:FreezeFrameClass_80c88891] */
  { /*     9 */  0xD001u,             2u,                                                                9u,                                                                  8u,      0x02u, DEM_CFG_EREC_TYPE_USER     }   /* [#DidVehicleSpeed, Ffm:FreezeFrameClass_80c88891] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTableFfm2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTableFfm2CollInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataCollectionTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableFfm2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableFfm2CollInd[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataCollectionTableFfm2CollInd      Referable Keys */
  /*     0 */                              9u,  /* [Ffm:FreezeFrameClass_80c88891] */
  /*     1 */                              6u,  /* [Ffm:FreezeFrameClass_80c88891] */
  /*     2 */                              8u,  /* [Ffm:FreezeFrameClass_80c88891] */
  /*     3 */                              7u,  /* [Ffm:FreezeFrameClass_80c88891] */
  /*     4 */                              5u,  /* [Ffm:FreezeFrameClass_80c88891] */
  /*     5 */                              3u,  /* [Ffm:FreezeFrameClass_80c88891] */
  /*     6 */                              4u   /* [Ffm:FreezeFrameClass_80c88891] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTable
  \details
  Element         Description
  ElementKind     DataElement kind, returned by Dem_Cfg_DataCallbackType()
  ElementSize     Size of data element in Byte.
  ReadDataFunc    C-function for getting the data. Its signature depends on ElementKind: With value(s) DEM_CFG_DATA_FROM_CBK_WITH_EVENTID use: Std_ReturnType (*)(uint8* Buffer, uint16 EventId); - and use: Std_ReturnType (*)(uint8* Buffer); with the other values DEM_CFG_DATA_FROM_CBK, DEM_CFG_DATA_FROM_SR_PORT_BOOLEAN, DEM_CFG_DATA_FROM_SR_PORT_SINT16, DEM_CFG_DATA_FROM_SR_PORT_SINT16_INTEL, DEM_CFG_DATA_FROM_SR_PORT_SINT32, DEM_CFG_DATA_FROM_SR_PORT_SINT32_INTEL, DEM_CFG_DATA_FROM_SR_PORT_SINT8, DEM_CFG_DATA_FROM_SR_PORT_SINT8_N, DEM_CFG_DATA_FROM_SR_PORT_UINT16, DEM_CFG_DATA_FROM_SR_PORT_UINT16_INTEL, DEM_CFG_DATA_FROM_SR_PORT_UINT32, DEM_CFG_DATA_FROM_SR_PORT_UINT32_INTEL, DEM_CFG_DATA_FROM_SR_PORT_UINT8, DEM_CFG_DATA_FROM_SR_PORT_UINT8_N.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableType, DEM_CONST) Dem_Cfg_DataElementTable[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ElementKind                  ElementSize  ReadDataFunc                                                                                                                     Referable Keys */
  { /*     0 */ DEM_CFG_DATAELEMENT_INVALID,          0u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                      },  /* [#NoDataElementConfigured] */
  { /*     1 */ DEM_CFG_DATA_FROM_CBK      ,          3u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_0xd004_Odometer_ReadData              },  /* [#DID_0xd004_Odometer, DidOdometer] */
  { /*     2 */ DEM_CFG_DATA_FROM_CBK      ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_0xd003_OperatingVoltage_ReadData      },  /* [#DID_0xd003_OperatingVoltage, DidOperatingVoltage] */
  { /*     3 */ DEM_CFG_DATA_FROM_CBK      ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_0xd002_EngineSpeed_ReadData           },  /* [#DID_0xd002_EngineSpeed, DidEngineSpeed] */
  { /*     4 */ DEM_CFG_DATA_FROM_CBK      ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_0xd001_Vehicle_Speed_ReadData         },  /* [#DID_0xd001_Vehicle_Speed, DidVehicleSpeed] */
  { /*     5 */ DEM_CFG_DATA_FROM_OCCCTR   ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                      },  /* [#DTCOccurrenceCounter_DTCOccurrenceCounter, EdrDTCOccurrenceCounter] */
  { /*     6 */ DEM_CFG_DATA_FROM_CBK      ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_0xd006_ActualRotationSpeed_ReadData   },  /* [#DID_0xd006_ActualRotationSpeed, DidActualRotationSpeed] */
  { /*     7 */ DEM_CFG_DATA_FROM_AGINGCTR ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                      },  /* [#SelfAgingCounter_SelfAgingCounter, EdrSelfAgingCounter] */
  { /*     8 */ DEM_CFG_DATA_FROM_CBK      ,          4u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_0xd005_DTC_Occurrence_Timer_ReadData  },  /* [#DID_0xd005_DTC_Occurrence_Timer, DidDTCOccurrenceTimer] */
  { /*     9 */ DEM_CFG_DATA_FROM_CBK      ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_DID_0xd007_ActualRotationSpeed02_ReadData }   /* [#DID_0xd007_ActualRotationSpeed02, DidActualRotationSpeed02] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTableCol2ElmtInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTableCol2ElmtInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataElementTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableCol2ElmtIndType, DEM_CONST) Dem_Cfg_DataElementTableCol2ElmtInd[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataElementTableCol2ElmtInd      Referable Keys */
  /*     0 */                           5u,  /* [EdrDTCOccurrenceCounter] */
  /*     1 */                           7u,  /* [EdrSelfAgingCounter] */
  /*     2 */                           6u,  /* [DidActualRotationSpeed] */
  /*     3 */                           9u,  /* [DidActualRotationSpeed02] */
  /*     4 */                           8u,  /* [DidDTCOccurrenceTimer] */
  /*     5 */                           3u,  /* [DidEngineSpeed] */
  /*     6 */                           1u,  /* [DidOdometer] */
  /*     7 */                           2u,  /* [DidOperatingVoltage] */
  /*     8 */                           4u   /* [DidVehicleSpeed] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DebounceTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DebounceTable
  \details
  Element                   Description
  DecrementStepSize         (-1) * DemDebounceCounterDecrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  FailedThreshold           DemDebounceCounterFailedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  IncrementStepSize         DemDebounceCounterIncrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  PassedThreshold           DemDebounceCounterPassedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  EventDebounceAlgorithm    Used DemEventParameter/DemEventClass/DemDebounceAlgorithmClass
  MaskedBits                contains bitcoded the boolean data of Dem_Cfg_DebounceContinuousOfDebounceTable, Dem_Cfg_EventDebounceBehaviorOfDebounceTable, Dem_Cfg_JumpDownOfDebounceTable, Dem_Cfg_JumpUpOfDebounceTable, Dem_Cfg_StorageOfDebounceTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DebounceTableType, DEM_CONST) Dem_Cfg_DebounceTable[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DecrementStepSize  FailedThreshold  IncrementStepSize  PassedThreshold  EventDebounceAlgorithm                                                       MaskedBits        Referable Keys */
  { /*     0 */                -1,             127,                 1,            -128,  DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06u },  /* [AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core] */
  { /*     1 */                -1,             127,                 1,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_EXTERNAL_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06u },  /* [A2B_open_Circuit_Open, A2B_short_to_battery_Circuit_Short_To_Battery, A2B_short_to_ground_Circuit_Short_To_Ground, AVM_CamerOpenCircuit, AVM_CamerShortToBattery, AVM_CamerShortToGround, AbnormalWakeupSleep, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE, ControlModuleCANBus_off_Bus_off, Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect, Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery, FactoryModeNotClosed, Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, GPS_AntennaOpen, GPS_AntennaShortToBattery, GPS_AntennaShortToGround, GPS_OverCurrent, HVAC_Display_BacklightModuleError, HVAC_Display_ForceInductionFailure, HVAC_Display_LowVoltage, HVAC_Display_NotReceiveBacklightValue, HVAC_Display_OverVoltage, HVAC_Display_TFT_Failure, HVAC_Display_TouchPanelFailure, HVAC_Display_VibratorFailure, HVAC_Display_VideoSignalConnectFailure, INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open, INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure, INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range, INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold, INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold, INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure, INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_Over_Temperature_Over_Temperature, IP_Display_ASIC_failure_Internal_Electronic_Failure, IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure, IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold, IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold, IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure, IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure, IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure, Internal_DMS_CameraCircuitOpen, Internal_DMS_CameraShortToBattery, Internal_DMS_CameraShortToGround, Internal_DVR_CameraCircuitOpen, Internal_DVR_CameraShortToBattery, Internal_DVR_CameraShortToGround, Internal_OMS_CameraCircuitOpen, Internal_OMS_CameraShortToBattery, Internal_OMS_CameraShortToGround, LostComWithAVMFrontCamera, LostComWithAVMLeftCamera, LostComWithAVMRearCamera, LostComWithAVMRightCamera, Lost_Communication_With_Depth_Of_Water_Detection_Module, Lost_TCP_communication_Missing_Message, Lost_communication_with_AVM_Missing_Message, Lost_communication_with_ConsoleDisplay, Lost_communication_with_DMS, Lost_communication_with_DVR, Lost_communication_with_IP_Display_Front_Missing_Message, Lost_communication_with_IVI_Display_Front_Missing_Message, Lost_communication_with_InCarCamera, Lost_communication_with_PassengerDisplay, Lost_communication_with_RVC_Missing_Message, Lost_communication_with_SVC_Missing_Message, Lost_communication_with_W_HUD_Missing_Message, Mic_1_open_Circuit_Open, Mic_1_short_to_BAT_Circuit_Short_To_Battery, Mic_1_short_to_GND_Circuit_Short_To_Ground, Mic_2_open_Circuit_Open, Mic_2_short_to_BAT_Circuit_Short_To_Battery, Mic_2_short_to_GND_Circuit_Short_To_Ground, MissingBattery_Management_System, Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Missing_Airbag_Module_Missing_Message, Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Missing_Combination_Switch_Assembly_Missing_Message, Missing_Controler_Headlamp_Missing_Message, Missing_Controller_Pedal_Missing_Message, Missing_Driver_Door_Control_Module_Missing_Message, Missing_Driver_Seat_Memory_module, Missing_Elec_Region_Control_System_Body_Missing_Message, Missing_Electric_Park_Brake_controller, Missing_Electric_Power_Steering_system_Missing_Message, Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Missing_Electronic_Gerodisc_Missing_Message, Missing_Engine_Control_Module_Missing_Message, Missing_Front_Power_Box_Missing_Message, Missing_Gateway_Missing_Message, Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Missing_Ibooster, Missing_Intelligent_Driving_Controller_Level2, Missing_Nextrac_Torque_On_Demand_Missing_Message, Missing_Onboard_charger, Missing_Power_Lift_Gate_module, Missing_PrePretensioner_Mechatronic_Integrated, Missing_Rear_Heat_Vent_Seat_Module, Missing_Rear_Power_Box_Missing_Message, Missing_Right_Headlamp_Control_Module, Missing_Screen_touch_button_switch_controller_Missing_Message, Missing_Seat_Control_Module, Missing_Transmission_Control_Until_PTCAN_Missing_Message, Missing_Wireless_Power_Charger_Missing_Message, Over_voltage_Circuit_Voltage_Above_Threshold, RVC_CamerShortToBattery, RVC_CameraOpenCircuit, RVC_CameraShortToGround, Read_CPScreen_IDFailed, Read_ClusterScreenIDFailed, Read_CoDriverScreenIDFailed, Read_HUDScreen_IDFailed, Read_IVIScreen_IDFailed, SVC_CameraOpen, SVC_CameraShortToBattery, SVC_CameraShortToGround, ScreenCPDriverErr, ScreenClusterDriverErr, ScreenCoDriverErr, ScreenHUDDriverErr, 
            ScreenIVIDriverErr, SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved, SecOC_GWSecOcFailure, SecOC_Security_PDU_Verification_Failed_from_ESP, SecOC_Security_PDU_Verification_Failed_from_IDC_L2, SecOC_Security_PDU_Verification_Failed_from_IDC_L3, SecOC_Security_PDU_Verification_Failed_from_IFC, SecOC_Security_PDU_Verification_Failed_from_TCU, SecOC_TBoxSecOcFailure, SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure, SecOC_software_module_running_error_Unexpected_Operation, Speaker_AVAS_CircuitOpen, Speaker_AVAS_ResistanceOutOfRange, Speaker_AVAS_ShortAcross, Speaker_AVAS_ShortToBattery, Speaker_AVAS_ShortToGround, Speaker_AVAS_WaveformLackFidelity, Speaker_Center_open_Circuit_Open, Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Center_short_across_General_Electrical_Failure, Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Speaker_FL_open_Circuit_Open, Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FL_short_across_General_Electrical_Failure, Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Speaker_FR_open_Circuit_Open, Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FR_short_across_General_Electrical_Failure, Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Speaker_RL_open_Circuit_Open, Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RL_short_across_General_Electrical_Failure, Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Speaker_RR_open_Circuit_Open, Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RR_short_across_General_Electrical_Failure, Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Speaker_Woofer_open_Circuit_Open, Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Woofer_short_across_General_Electrical_Failure, Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure, TUNER_FM1_open_Circuit_Open, TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold, TUNER_FM1_short_to_battary_Circuit_Short_To_Battery, TUNER_FM1_short_to_groud_Circuit_Short_To_Ground, TUNER_FM2_open_Circuit_Open, TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold, TUNER_FM2_short_to_battary_Circuit_Short_To_Battery, TUNER_FM2_short_to_groud_Circuit_Short_To_Ground, Temperature_SensorError, Under_voltage_Circuit_Voltage_Below_Threshold, missing_Adaptive_Cruise_Control_system_Radar_Control_Module, missing_Driver_Monitoring_System_Missing_Message, missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, missing_Parking_Assistance_System_Missing_Message, missing_Passenger_Door_Control_Module_Missing_Message, missing_Right_Corner_Radar, missing_Right_Rear_Side_Detection_System_Missing_Message, missing_Telematics_control_Box_Missing_Message, missing_Trailer_Missing_Message, missing_Tyre_Pressure_Monitoring_Systems_Missing_Message] */
  { /*     2 */                 0,               0,                 0,               0,  DEM_CFG_DEM_CFG_DEBOUNCETYPE_INVALID_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x00u }   /* [#EVENT_INVALID] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DtcTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DtcTable
  \details
  Element           Description
  UdsDtc        
  FunctionalUnit
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DtcTableType, DEM_CONST) Dem_Cfg_DtcTable[202] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*     0 */ 0x00FFFFFFu,           255u },  /* [#NoUdsDtcConfigured, #NoObdDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */ 0x0095F813u,             0u },  /* [DTCClass_DTC_0x95f813] */
  { /*     2 */ 0x0095F812u,             0u },  /* [DTCClass_DTC_0x95f812] */
  { /*     3 */ 0x0095F811u,             0u },  /* [DTCClass_DTC_0x95f811] */
  { /*     4 */ 0x00C07388u,             0u },  /* [DTCClass_DTC_0xc07388] */
  { /*     5 */ 0x00E00083u,             0u },  /* [DTCClass_DTC_0xe00083] */
  { /*     6 */ 0x00E00C12u,             0u },  /* [DTCClass_DTC_0xe00c12] */
  { /*     7 */ 0x00927312u,             0u },  /* [DTCClass_DTC_0x927312] */
  { /*     8 */ 0x00A13011u,             0u },  /* [DTCClass_DTC_0xa13011] */
  { /*     9 */ 0x00927412u,             0u },  /* [DTCClass_DTC_0x927412] */
  { /*    10 */ 0x00A13111u,             0u },  /* [DTCClass_DTC_0xa13111] */
  { /*    11 */ 0x00E01113u,             0u },  /* [DTCClass_DTC_0xe01113] */
  { /*    12 */ 0x00E00208u,             0u },  /* [DTCClass_DTC_0xe00208] */
  { /*    13 */ 0x00E00784u,             0u },  /* [DTCClass_DTC_0xe00784] */
  { /*    14 */ 0x00A20116u,             0u },  /* [DTCClass_DTC_0xa20116] */
  { /*    15 */ 0x00A20017u,             0u },  /* [DTCClass_DTC_0xa20017] */
  { /*    16 */ 0x00A20249u,             0u },  /* [DTCClass_DTC_0xa20249] */
  { /*    17 */ 0x00A20449u,             0u },  /* [DTCClass_DTC_0xa20449] */
  { /*    18 */ 0x00A20149u,             0u },  /* [DTCClass_DTC_0xa20149] */
  { /*    19 */ 0x00A20008u,             0u },  /* [DTCClass_DTC_0xa20008] */
  { /*    20 */ 0x00A20349u,             0u },  /* [DTCClass_DTC_0xa20349] */
  { /*    21 */ 0x0092764Bu,             0u },  /* [DTCClass_DTC_0x92764b] */
  { /*    22 */ 0x00A10249u,             0u },  /* [DTCClass_DTC_0xa10249] */
  { /*    23 */ 0x00A30017u,             0u },  /* [DTCClass_DTC_0xa30017] */
  { /*    24 */ 0x00A30116u,             0u },  /* [DTCClass_DTC_0xa30116] */
  { /*    25 */ 0x00A30008u,             0u },  /* [DTCClass_DTC_0xa30008] */
  { /*    26 */ 0x00A30149u,             0u },  /* [DTCClass_DTC_0xa30149] */
  { /*    27 */ 0x00A30249u,             0u },  /* [DTCClass_DTC_0xa30249] */
  { /*    28 */ 0x00A30349u,             0u },  /* [DTCClass_DTC_0xa30349] */
  { /*    29 */ 0x00A30449u,             0u },  /* [DTCClass_DTC_0xa30449] */
  { /*    30 */ 0x00A30549u,             0u },  /* [DTCClass_DTC_0xa30549] */
  { /*    31 */ 0x00A30649u,             0u },  /* [DTCClass_DTC_0xa30649] */
  { /*    32 */ 0x00A10049u,             0u },  /* [DTCClass_DTC_0xa10049] */
  { /*    33 */ 0x00A10116u,             0u },  /* [DTCClass_DTC_0xa10116] */
  { /*    34 */ 0x00A10017u,             0u },  /* [DTCClass_DTC_0xa10017] */
  { /*    35 */ 0x00A10149u,             0u },  /* [DTCClass_DTC_0xa10149] */
  { /*    36 */ 0x00A10408u,             0u },  /* [DTCClass_DTC_0xa10408] */
  { /*    37 */ 0x00A10349u,             0u },  /* [DTCClass_DTC_0xa10349] */
  { /*    38 */ 0x00E00487u,             0u },  /* [DTCClass_DTC_0xe00487] */
  { /*    39 */ 0x00908A87u,             0u },  /* [DTCClass_DTC_0x908a87] */
  { /*    40 */ 0x00908D87u,             0u },  /* [DTCClass_DTC_0x908d87] */
  { /*    41 */ 0x00908E87u,             0u },  /* [DTCClass_DTC_0x908e87] */
  { /*    42 */ 0x00908487u,             0u },  /* [DTCClass_DTC_0x908487] */
  { /*    43 */ 0x00908887u,             0u },  /* [DTCClass_DTC_0x908887] */
  { /*    44 */ 0x00910087u,             0u },  /* [DTCClass_DTC_0x910087] */
  { /*    45 */ 0x00908787u,             0u },  /* [DTCClass_DTC_0x908787] */
  { /*    46 */ 0x00908B87u,             0u },  /* [DTCClass_DTC_0x908b87] */
  { /*    47 */ 0x00908687u,             0u },  /* [DTCClass_DTC_0x908687] */
  { /*    48 */ 0x0093F513u,             0u },  /* [DTCClass_DTC_0x93f513] */
  { /*    49 */ 0x00908587u,             0u },  /* [DTCClass_DTC_0x908587] */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*    50 */ 0x0093F512u,             0u },  /* [DTCClass_DTC_0x93f512] */
  { /*    51 */ 0x0093F511u,             0u },  /* [DTCClass_DTC_0x93f511] */
  { /*    52 */ 0x0093F613u,             0u },  /* [DTCClass_DTC_0x93f613] */
  { /*    53 */ 0x0093F612u,             0u },  /* [DTCClass_DTC_0x93f612] */
  { /*    54 */ 0x0093F611u,             0u },  /* [DTCClass_DTC_0x93f611] */
  { /*    55 */ 0x00C16487u,             0u },  /* [DTCClass_DTC_0xc16487] */
  { /*    56 */ 0x00C15187u,             0u },  /* [DTCClass_DTC_0xc15187] */
  { /*    57 */ 0x00D00487u,             0u },  /* [DTCClass_DTC_0xd00487] */
  { /*    58 */ 0x00D10687u,             0u },  /* [DTCClass_DTC_0xd10687] */
  { /*    59 */ 0x00C24187u,             0u },  /* [DTCClass_DTC_0xc24187] */
  { /*    60 */ 0x00D00987u,             0u },  /* [DTCClass_DTC_0xd00987] */
  { /*    61 */ 0x00C19987u,             0u },  /* [DTCClass_DTC_0xc19987] */
  { /*    62 */ 0x00C14087u,             0u },  /* [DTCClass_DTC_0xc14087] */
  { /*    63 */ 0x00C13187u,             0u },  /* [DTCClass_DTC_0xc13187] */
  { /*    64 */ 0x00C12287u,             0u },  /* [DTCClass_DTC_0xc12287] */
  { /*    65 */ 0x00C11587u,             0u },  /* [DTCClass_DTC_0xc11587] */
  { /*    66 */ 0x00C10087u,             0u },  /* [DTCClass_DTC_0xc10087] */
  { /*    67 */ 0x00D10887u,             0u },  /* [DTCClass_DTC_0xd10887] */
  { /*    68 */ 0x00C14687u,             0u },  /* [DTCClass_DTC_0xc14687] */
  { /*    69 */ 0x00C15887u,             0u },  /* [DTCClass_DTC_0xc15887] */
  { /*    70 */ 0x00C11487u,             0u },  /* [DTCClass_DTC_0xc11487] */
  { /*    71 */ 0x00D10987u,             0u },  /* [DTCClass_DTC_0xd10987] */
  { /*    72 */ 0x00D01587u,             0u },  /* [DTCClass_DTC_0xd01587] */
  { /*    73 */ 0x00C10187u,             0u },  /* [DTCClass_DTC_0xc10187] */
  { /*    74 */ 0x00D02987u,             0u },  /* [DTCClass_DTC_0xd02987] */
  { /*    75 */ 0x00D10017u,             0u },  /* [DTCClass_DTC_0xd10017] */
  { /*    76 */ 0x00D00E40u,             0u },  /* [DTCClass_DTC_0xd00e40] */
  { /*    77 */ 0x00D00A46u,             0u },  /* [DTCClass_DTC_0xd00a46] */
  { /*    78 */ 0x00EA0040u,             0u },  /* [DTCClass_DTC_0xea0040] */
  { /*    79 */ 0x00D00F94u,             0u },  /* [DTCClass_DTC_0xd00f94] */
  { /*    80 */ 0x009A0513u,             0u },  /* [DTCClass_DTC_0x9a0513] */
  { /*    81 */ 0x00EA0240u,             0u },  /* [DTCClass_DTC_0xea0240] */
  { /*    82 */ 0x009A0525u,             0u },  /* [DTCClass_DTC_0x9a0525] */
  { /*    83 */ 0x009A051Eu,             0u },  /* [DTCClass_DTC_0x9a051e] */
  { /*    84 */ 0x009A0501u,             0u },  /* [DTCClass_DTC_0x9a0501] */
  { /*    85 */ 0x009A0512u,             0u },  /* [DTCClass_DTC_0x9a0512] */
  { /*    86 */ 0x009A0511u,             0u },  /* [DTCClass_DTC_0x9a0511] */
  { /*    87 */ 0x009A0113u,             0u },  /* [DTCClass_DTC_0x9a0113] */
  { /*    88 */ 0x009A0125u,             0u },  /* [DTCClass_DTC_0x9a0125] */
  { /*    89 */ 0x009A011Eu,             0u },  /* [DTCClass_DTC_0x9a011e] */
  { /*    90 */ 0x009A0101u,             0u },  /* [DTCClass_DTC_0x9a0101] */
  { /*    91 */ 0x009A0112u,             0u },  /* [DTCClass_DTC_0x9a0112] */
  { /*    92 */ 0x009A0111u,             0u },  /* [DTCClass_DTC_0x9a0111] */
  { /*    93 */ 0x009A0213u,             0u },  /* [DTCClass_DTC_0x9a0213] */
  { /*    94 */ 0x009A0225u,             0u },  /* [DTCClass_DTC_0x9a0225] */
  { /*    95 */ 0x009A021Eu,             0u },  /* [DTCClass_DTC_0x9a021e] */
  { /*    96 */ 0x009A0201u,             0u },  /* [DTCClass_DTC_0x9a0201] */
  { /*    97 */ 0x009A0212u,             0u },  /* [DTCClass_DTC_0x9a0212] */
  { /*    98 */ 0x009A0211u,             0u },  /* [DTCClass_DTC_0x9a0211] */
  { /*    99 */ 0x009A0313u,             0u },  /* [DTCClass_DTC_0x9a0313] */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*   100 */ 0x009A0325u,             0u },  /* [DTCClass_DTC_0x9a0325] */
  { /*   101 */ 0x009A031Eu,             0u },  /* [DTCClass_DTC_0x9a031e] */
  { /*   102 */ 0x009A0301u,             0u },  /* [DTCClass_DTC_0x9a0301] */
  { /*   103 */ 0x009A0312u,             0u },  /* [DTCClass_DTC_0x9a0312] */
  { /*   104 */ 0x009A0311u,             0u },  /* [DTCClass_DTC_0x9a0311] */
  { /*   105 */ 0x009A0413u,             0u },  /* [DTCClass_DTC_0x9a0413] */
  { /*   106 */ 0x009A0425u,             0u },  /* [DTCClass_DTC_0x9a0425] */
  { /*   107 */ 0x009A041Eu,             0u },  /* [DTCClass_DTC_0x9a041e] */
  { /*   108 */ 0x009A0401u,             0u },  /* [DTCClass_DTC_0x9a0401] */
  { /*   109 */ 0x009A0412u,             0u },  /* [DTCClass_DTC_0x9a0412] */
  { /*   110 */ 0x009A0411u,             0u },  /* [DTCClass_DTC_0x9a0411] */
  { /*   111 */ 0x009A0613u,             0u },  /* [DTCClass_DTC_0x9a0613] */
  { /*   112 */ 0x009A0625u,             0u },  /* [DTCClass_DTC_0x9a0625] */
  { /*   113 */ 0x009A061Eu,             0u },  /* [DTCClass_DTC_0x9a061e] */
  { /*   114 */ 0x009A0601u,             0u },  /* [DTCClass_DTC_0x9a0601] */
  { /*   115 */ 0x009A0612u,             0u },  /* [DTCClass_DTC_0x9a0612] */
  { /*   116 */ 0x009A0611u,             0u },  /* [DTCClass_DTC_0x9a0611] */
  { /*   117 */ 0x00D01046u,             0u },  /* [DTCClass_DTC_0xd01046] */
  { /*   118 */ 0x009A1013u,             0u },  /* [DTCClass_DTC_0x9a1013] */
  { /*   119 */ 0x009A1019u,             0u },  /* [DTCClass_DTC_0x9a1019] */
  { /*   120 */ 0x009A1012u,             0u },  /* [DTCClass_DTC_0x9a1012] */
  { /*   121 */ 0x009A1011u,             0u },  /* [DTCClass_DTC_0x9a1011] */
  { /*   122 */ 0x009A1113u,             0u },  /* [DTCClass_DTC_0x9a1113] */
  { /*   123 */ 0x009A1119u,             0u },  /* [DTCClass_DTC_0x9a1119] */
  { /*   124 */ 0x009A1112u,             0u },  /* [DTCClass_DTC_0x9a1112] */
  { /*   125 */ 0x009A1111u,             0u },  /* [DTCClass_DTC_0x9a1111] */
  { /*   126 */ 0x00D10116u,             0u },  /* [DTCClass_DTC_0xd10116] */
  { /*   127 */ 0x00C2B387u,             0u },  /* [DTCClass_DTC_0xc2b387] */
  { /*   128 */ 0x00C14387u,             0u },  /* [DTCClass_DTC_0xc14387] */
  { /*   129 */ 0x00C24387u,             0u },  /* [DTCClass_DTC_0xc24387] */
  { /*   130 */ 0x00C20087u,             0u },  /* [DTCClass_DTC_0xc20087] */
  { /*   131 */ 0x00C23387u,             0u },  /* [DTCClass_DTC_0xc23387] */
  { /*   132 */ 0x00C19887u,             0u },  /* [DTCClass_DTC_0xc19887] */
  { /*   133 */ 0x00C14187u,             0u },  /* [DTCClass_DTC_0xc14187] */
  { /*   134 */ 0x00C12787u,             0u },  /* [DTCClass_DTC_0xc12787] */
  { /*   135 */ 0x00C12887u,             0u },  /* [DTCClass_DTC_0xc12887] */
  { /*   136 */ 0x00C11187u,             0u },  /* [DTCClass_DTC_0xc11187] */
  { /*   137 */ 0x00C20887u,             0u },  /* [DTCClass_DTC_0xc20887] */
  { /*   138 */ 0x00C29387u,             0u },  /* [DTCClass_DTC_0xc29387] */
  { /*   139 */ 0x00D02687u,             0u },  /* [DTCClass_DTC_0xd02687] */
  { /*   140 */ 0x00C25E87u,             0u },  /* [DTCClass_DTC_0xc25e87] */
  { /*   141 */ 0x00C15C87u,             0u },  /* [DTCClass_DTC_0xc15c87] */
  { /*   142 */ 0x00C1BB87u,             0u },  /* [DTCClass_DTC_0xc1bb87] */
  { /*   143 */ 0x00C23087u,             0u },  /* [DTCClass_DTC_0xc23087] */
  { /*   144 */ 0x00D10B87u,             0u },  /* [DTCClass_DTC_0xd10b87] */
  { /*   145 */ 0x00C24787u,             0u },  /* [DTCClass_DTC_0xc24787] */
  { /*   146 */ 0x00C24287u,             0u },  /* [DTCClass_DTC_0xc24287] */
  { /*   147 */ 0x00C24687u,             0u },  /* [DTCClass_DTC_0xc24687] */
  { /*   148 */ 0x00C10487u,             0u },  /* [DTCClass_DTC_0xc10487] */
  { /*   149 */ 0x00D12006u,             0u },  /* [DTCClass_DTC_0xd12006] */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*   150 */ 0x00C2B587u,             0u },  /* [DTCClass_DTC_0xc2b587] */
  { /*   151 */ 0x00910187u,             0u },  /* [DTCClass_DTC_0x910187] */
  { /*   152 */ 0x00910287u,             0u },  /* [DTCClass_DTC_0x910287] */
  { /*   153 */ 0x00910387u,             0u },  /* [DTCClass_DTC_0x910387] */
  { /*   154 */ 0x00910487u,             0u },  /* [DTCClass_DTC_0x910487] */
  { /*   155 */ 0x00A10093u,             0u },  /* [DTCClass_DTC_0xA10093] */
  { /*   156 */ 0x00A10157u,             0u },  /* [DTCClass_DTC_0xA10157] */
  { /*   157 */ 0x00A20093u,             0u },  /* [DTCClass_DTC_0xA20093] */
  { /*   158 */ 0x00A20157u,             0u },  /* [DTCClass_DTC_0xA20157] */
  { /*   159 */ 0x00910011u,             0u },  /* [DTCClass_DTC_0x910011] */
  { /*   160 */ 0x00A30093u,             0u },  /* [DTCClass_DTC_0xA30093] */
  { /*   161 */ 0x00910012u,             0u },  /* [DTCClass_DTC_0x910012] */
  { /*   162 */ 0x00A30157u,             0u },  /* [DTCClass_DTC_0xA30157] */
  { /*   163 */ 0x00910013u,             0u },  /* [DTCClass_DTC_0x910013] */
  { /*   164 */ 0x00A40093u,             0u },  /* [DTCClass_DTC_0xA40093] */
  { /*   165 */ 0x00A40157u,             0u },  /* [DTCClass_DTC_0xA40157] */
  { /*   166 */ 0x00910112u,             0u },  /* [DTCClass_DTC_0x910112] */
  { /*   167 */ 0x00A50093u,             0u },  /* [DTCClass_DTC_0xA50093] */
  { /*   168 */ 0x00910111u,             0u },  /* [DTCClass_DTC_0x910111] */
  { /*   169 */ 0x00A50157u,             0u },  /* [DTCClass_DTC_0xA50157] */
  { /*   170 */ 0x00910113u,             0u },  /* [DTCClass_DTC_0x910113] */
  { /*   171 */ 0x00927649u,             0u },  /* [DemDTCClass_0x927649] */
  { /*   172 */ 0x00910511u,             0u },  /* [DTCClass_DTC_0x910511] */
  { /*   173 */ 0x009A0701u,             0u },  /* [DTCClass_DTC_0x9A0701] */
  { /*   174 */ 0x00910611u,             0u },  /* [DTCClass_DTC_0x910611] */
  { /*   175 */ 0x009A0711u,             0u },  /* [DTCClass_DTC_0x9A0711] */
  { /*   176 */ 0x00910711u,             0u },  /* [DTCClass_DTC_0x910711] */
  { /*   177 */ 0x009A0712u,             0u },  /* [DTCClass_DTC_0x9A0712] */
  { /*   178 */ 0x00910512u,             0u },  /* [DTCClass_DTC_0x910512] */
  { /*   179 */ 0x009A0713u,             0u },  /* [DTCClass_DTC_0x9A0713] */
  { /*   180 */ 0x00910612u,             0u },  /* [DTCClass_DTC_0x910612] */
  { /*   181 */ 0x009A071Eu,             0u },  /* [DTCClass_DTC_0x9A071E] */
  { /*   182 */ 0x00910712u,             0u },  /* [DTCClass_DTC_0x910712] */
  { /*   183 */ 0x009A0725u,             0u },  /* [DTCClass_DTC_0x9A0725] */
  { /*   184 */ 0x00910513u,             0u },  /* [DTCClass_DTC_0x910513] */
  { /*   185 */ 0x00910613u,             0u },  /* [DTCClass_DTC_0x910613] */
  { /*   186 */ 0x00910713u,             0u },  /* [DTCClass_DTC_0x910713] */
  { /*   187 */ 0x009A0813u,             0u },  /* [DTCClass_DTC_0x9A0813] */
  { /*   188 */ 0x009A0811u,             0u },  /* [DTCClass_DTC_0x9A0811] */
  { /*   189 */ 0x009A0812u,             0u },  /* [DTCClass_DTC_0x9A0812] */
  { /*   190 */ 0x009A0819u,             0u },  /* [DTCClass_DTC_0x9A0819] */
  { /*   191 */ 0x00910811u,             0u },  /* [DTCClass_DTC_0x910811] */
  { /*   192 */ 0x00910812u,             0u },  /* [DTCClass_DTC_0x910812] */
  { /*   193 */ 0x00910813u,             0u },  /* [DTCClass_DTC_0x910813] */
  { /*   194 */ 0x00910887u,             0u },  /* [DTCClass_DTC_0x910887] */
  { /*   195 */ 0x00C15C40u,             0u },  /* [DTCClass_DTC_0xC15C40] */
  { /*   196 */ 0x00C15D40u,             0u },  /* [DTCClass_DTC_0xC15D40] */
  { /*   197 */ 0x00C14340u,             0u },  /* [DTCClass_DTC_0xC14340] */
  { /*   198 */ 0x00C10140u,             0u },  /* [DTCClass_DTC_0xC10140] */
  { /*   199 */ 0x00C41640u,             0u },  /* [DTCClass_DTC_0xC41640] */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*   200 */ 0x00D12387u,             0u },  /* [DTCClass_DTC_0xd12387] */
  { /*   201 */ 0x00F01200u,             0u }   /* [DTCClass_DTC_0xF01200] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupTableInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_EnableConditionGroupTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionGroupTableIndType, DEM_CONST) Dem_Cfg_EnableConditionGroupTableInd[21] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EnableConditionGroupTableInd      Referable Keys */
  /*     0 */                            0u,  /* [__Internal_ControlDtcSetting] */
  /*     1 */                            5u,  /* [__Internal_ControlDtcSetting] */
  /*     2 */                            6u,  /* [__Internal_ControlDtcSetting] */
  /*     3 */                            8u,  /* [__Internal_ControlDtcSetting] */
  /*     4 */                            9u,  /* [__Internal_ControlDtcSetting] */
  /*     5 */                            2u,  /* [__Internal_ControlDtcSetting] */
  /*     6 */                            7u,  /* [__Internal_ControlDtcSetting] */
  /*     7 */                            3u,  /* [__Internal_ControlDtcSetting] */
  /*     8 */                            4u,  /* [__Internal_ControlDtcSetting] */
  /*     9 */                            1u,  /* [__Internal_ControlDtcSetting] */
  /*    10 */                            8u,  /* [BatteryVoltag] */
  /*    11 */                            1u,  /* [BatteryVoltag] */
  /*    12 */                            2u,  /* [BatteryVoltag2] */
  /*    13 */                            7u,  /* [BatteryVoltag2] */
  /*    14 */                            3u,  /* [BatteryVoltag3] */
  /*    15 */                            4u,  /* [BatteryVoltag4] */
  /*    16 */                            5u,  /* [IgnOn] */
  /*    17 */                            8u,  /* [IgnOn] */
  /*    18 */                            7u,  /* [IgnOn] */
  /*    19 */                            6u,  /* [PowerModeOn] */
  /*    20 */                            9u   /* [Wakeup] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionInitTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionInitTable
  \details
  Element            Description
  FulfilledAtInit    Initial value: 'FALSE' condition is not fulfilled, 'TRUE' condition is fulfilled
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionInitTableType, DEM_CONST) Dem_Cfg_EnableConditionInitTable[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FulfilledAtInit */
  { /*     0 */            TRUE },
  { /*     1 */           FALSE },
  { /*     2 */           FALSE },
  { /*     3 */           FALSE },
  { /*     4 */           FALSE },
  { /*     5 */           FALSE },
  { /*     6 */           FALSE },
  { /*     7 */           FALSE }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionTable
  \brief  Map each EnableCondition(Id) to the referring EnableConditionGroups - this is reverse direction of the AUTOSAR configuration model.
  \details
  Element                                 Description
  EnableConditionGroupTableIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
  EnableConditionGroupTableIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionTableType, DEM_CONST) Dem_Cfg_EnableConditionTable[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EnableConditionGroupTableIndEndIdx  EnableConditionGroupTableIndStartIdx */
  { /*     0 */                                10u,                                   0u },
  { /*     1 */                                12u,                                  10u },
  { /*     2 */                                14u,                                  12u },
  { /*     3 */                                15u,                                  14u },
  { /*     4 */                                16u,                                  15u },
  { /*     5 */                                19u,                                  16u },
  { /*     6 */                                20u,                                  19u },
  { /*     7 */                                21u,                                  20u }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventAvailableDefault
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventAvailableDefaultType, DEM_CONST) Dem_Cfg_EventAvailableDefault[225] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EventAvailableDefault      Comment */
  /*     0 */                   TRUE,  /* [#EVENT_INVALID] */
  /*     1 */                  FALSE,  /* [A2B_open_Circuit_Open] */
  /*     2 */                  FALSE,  /* [A2B_short_to_battery_Circuit_Short_To_Battery] */
  /*     3 */                  FALSE,  /* [A2B_short_to_ground_Circuit_Short_To_Ground] */
  /*     4 */                  FALSE,  /* [ControlModuleCANBus_off_Bus_off] */
  /*     5 */                  FALSE,  /* [Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect] */
  /*     6 */                  FALSE,  /* [Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery] */
  /*     7 */                  FALSE,  /* [Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery] */
  /*     8 */                  FALSE,  /* [Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground] */
  /*     9 */                  FALSE,  /* [Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery] */
  /*    10 */                  FALSE,  /* [Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground] */
  /*    11 */                  FALSE,  /* [INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open] */
  /*    12 */                  FALSE,  /* [INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure] */
  /*    13 */                  FALSE,  /* [INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range] */
  /*    14 */                  FALSE,  /* [INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold] */
  /*    15 */                  FALSE,  /* [INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold] */
  /*    16 */                  FALSE,  /* [INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure] */
  /*    17 */                  FALSE,  /* [INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure] */
  /*    18 */                  FALSE,  /* [INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure] */
  /*    19 */                  FALSE,  /* [INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure] */
  /*    20 */                  FALSE,  /* [INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure] */
  /*    21 */                  FALSE,  /* [INVALID_SHORTNAME_Over_Temperature_Over_Temperature] */
  /*    22 */                  FALSE,  /* [IP_Display_ASIC_failure_Internal_Electronic_Failure] */
  /*    23 */                  FALSE,  /* [HVAC_Display_OverVoltage] */
  /*    24 */                  FALSE,  /* [HVAC_Display_LowVoltage] */
  /*    25 */                  FALSE,  /* [HVAC_Display_NotReceiveBacklightValue] */
  /*    26 */                  FALSE,  /* [HVAC_Display_BacklightModuleError] */
  /*    27 */                  FALSE,  /* [HVAC_Display_TFT_Failure] */
  /*    28 */                  FALSE,  /* [HVAC_Display_VideoSignalConnectFailure] */
  /*    29 */                  FALSE,  /* [HVAC_Display_TouchPanelFailure] */
  /*    30 */                  FALSE,  /* [HVAC_Display_VibratorFailure] */
  /*    31 */                  FALSE,  /* [HVAC_Display_ForceInductionFailure] */
  /*    32 */                  FALSE,  /* [IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure] */
  /*    33 */                  FALSE,  /* [IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold] */
  /*    34 */                  FALSE,  /* [IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold] */
  /*    35 */                  FALSE,  /* [IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure] */
  /*    36 */                  FALSE,  /* [IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure] */
  /*    37 */                  FALSE,  /* [IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure] */
  /*    38 */                  FALSE,  /* [Lost_TCP_communication_Missing_Message] */
  /*    39 */                  FALSE,  /* [Lost_communication_with_AVM_Missing_Message] */
  /*    40 */                  FALSE,  /* [Lost_communication_with_IP_Display_Front_Missing_Message] */
  /*    41 */                  FALSE,  /* [Lost_communication_with_IVI_Display_Front_Missing_Message] */
  /*    42 */                  FALSE,  /* [Lost_communication_with_InCarCamera] */
  /*    43 */                  FALSE,  /* [Lost_communication_with_ConsoleDisplay] */
  /*    44 */                  FALSE,  /* [Lost_communication_with_RVC_Missing_Message] */
  /*    45 */                  FALSE,  /* [Lost_communication_with_PassengerDisplay] */
  /*    46 */                  FALSE,  /* [Lost_communication_with_W_HUD_Missing_Message] */
  /*    47 */                  FALSE,  /* [Lost_communication_with_DMS] */
  /*    48 */                  FALSE,  /* [Mic_1_open_Circuit_Open] */
  /*    49 */                  FALSE,  /* [Lost_communication_with_DVR] */
  /* Index     EventAvailableDefault      Comment */
  /*    50 */                  FALSE,  /* [Mic_1_short_to_BAT_Circuit_Short_To_Battery] */
  /*    51 */                  FALSE,  /* [Mic_1_short_to_GND_Circuit_Short_To_Ground] */
  /*    52 */                  FALSE,  /* [Mic_2_open_Circuit_Open] */
  /*    53 */                  FALSE,  /* [Mic_2_short_to_BAT_Circuit_Short_To_Battery] */
  /*    54 */                  FALSE,  /* [Mic_2_short_to_GND_Circuit_Short_To_Ground] */
  /*    55 */                  FALSE,  /* [Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message] */
  /*    56 */                  FALSE,  /* [Missing_Airbag_Module_Missing_Message] */
  /*    57 */                  FALSE,  /* [Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message] */
  /*    58 */                  FALSE,  /* [Missing_Combination_Switch_Assembly_Missing_Message] */
  /*    59 */                  FALSE,  /* [Missing_Controler_Headlamp_Missing_Message] */
  /*    60 */                  FALSE,  /* [Missing_Controller_Pedal_Missing_Message] */
  /*    61 */                  FALSE,  /* [Missing_Driver_Door_Control_Module_Missing_Message] */
  /*    62 */                  FALSE,  /* [Missing_Elec_Region_Control_System_Body_Missing_Message] */
  /*    63 */                  FALSE,  /* [Missing_Electric_Power_Steering_system_Missing_Message] */
  /*    64 */                  FALSE,  /* [Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message] */
  /*    65 */                  FALSE,  /* [Missing_Electronic_Gerodisc_Missing_Message] */
  /*    66 */                  FALSE,  /* [Missing_Engine_Control_Module_Missing_Message] */
  /*    67 */                  FALSE,  /* [Missing_Front_Power_Box_Missing_Message] */
  /*    68 */                  FALSE,  /* [Missing_Gateway_Missing_Message] */
  /*    69 */                  FALSE,  /* [Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message] */
  /*    70 */                  FALSE,  /* [Missing_Nextrac_Torque_On_Demand_Missing_Message] */
  /*    71 */                  FALSE,  /* [Missing_Rear_Power_Box_Missing_Message] */
  /*    72 */                  FALSE,  /* [Missing_Screen_touch_button_switch_controller_Missing_Message] */
  /*    73 */                  FALSE,  /* [Missing_Transmission_Control_Until_PTCAN_Missing_Message] */
  /*    74 */                  FALSE,  /* [Missing_Wireless_Power_Charger_Missing_Message] */
  /*    75 */                  FALSE,  /* [Over_voltage_Circuit_Voltage_Above_Threshold] */
  /*    76 */                  FALSE,  /* [SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved] */
  /*    77 */                  FALSE,  /* [SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure] */
  /*    78 */                  FALSE,  /* [SecOC_TBoxSecOcFailure] */
  /*    79 */                  FALSE,  /* [SecOC_software_module_running_error_Unexpected_Operation] */
  /*    80 */                  FALSE,  /* [Speaker_Center_open_Circuit_Open] */
  /*    81 */                  FALSE,  /* [SecOC_GWSecOcFailure] */
  /*    82 */                  FALSE,  /* [Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure] */
  /*    83 */                  FALSE,  /* [Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range] */
  /*    84 */                  FALSE,  /* [Speaker_Center_short_across_General_Electrical_Failure] */
  /*    85 */                  FALSE,  /* [Speaker_Center_short_to_battery_Circuit_Short_To_Battery] */
  /*    86 */                  FALSE,  /* [Speaker_Center_short_to_ground_Circuit_Short_To_Ground] */
  /*    87 */                  FALSE,  /* [Speaker_FL_open_Circuit_Open] */
  /*    88 */                  FALSE,  /* [Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure] */
  /*    89 */                  FALSE,  /* [Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range] */
  /*    90 */                  FALSE,  /* [Speaker_FL_short_across_General_Electrical_Failure] */
  /*    91 */                  FALSE,  /* [Speaker_FL_short_to_battery_Circuit_Short_To_Battery] */
  /*    92 */                  FALSE,  /* [Speaker_FL_short_to_ground_Circuit_Short_To_Ground] */
  /*    93 */                  FALSE,  /* [Speaker_FR_open_Circuit_Open] */
  /*    94 */                  FALSE,  /* [Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure] */
  /*    95 */                  FALSE,  /* [Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range] */
  /*    96 */                  FALSE,  /* [Speaker_FR_short_across_General_Electrical_Failure] */
  /*    97 */                  FALSE,  /* [Speaker_FR_short_to_battery_Circuit_Short_To_Battery] */
  /*    98 */                  FALSE,  /* [Speaker_FR_short_to_ground_Circuit_Short_To_Ground] */
  /*    99 */                  FALSE,  /* [Speaker_RL_open_Circuit_Open] */
  /* Index     EventAvailableDefault      Comment */
  /*   100 */                  FALSE,  /* [Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure] */
  /*   101 */                  FALSE,  /* [Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range] */
  /*   102 */                  FALSE,  /* [Speaker_RL_short_across_General_Electrical_Failure] */
  /*   103 */                  FALSE,  /* [Speaker_RL_short_to_battery_Circuit_Short_To_Battery] */
  /*   104 */                  FALSE,  /* [Speaker_RL_short_to_ground_Circuit_Short_To_Ground] */
  /*   105 */                  FALSE,  /* [Speaker_RR_open_Circuit_Open] */
  /*   106 */                  FALSE,  /* [Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure] */
  /*   107 */                  FALSE,  /* [Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range] */
  /*   108 */                  FALSE,  /* [Speaker_RR_short_across_General_Electrical_Failure] */
  /*   109 */                  FALSE,  /* [Speaker_RR_short_to_battery_Circuit_Short_To_Battery] */
  /*   110 */                  FALSE,  /* [Speaker_RR_short_to_ground_Circuit_Short_To_Ground] */
  /*   111 */                  FALSE,  /* [Speaker_Woofer_open_Circuit_Open] */
  /*   112 */                  FALSE,  /* [Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure] */
  /*   113 */                  FALSE,  /* [Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range] */
  /*   114 */                  FALSE,  /* [Speaker_Woofer_short_across_General_Electrical_Failure] */
  /*   115 */                  FALSE,  /* [Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery] */
  /*   116 */                  FALSE,  /* [Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground] */
  /*   117 */                  FALSE,  /* [Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure] */
  /*   118 */                  FALSE,  /* [TUNER_FM1_open_Circuit_Open] */
  /*   119 */                  FALSE,  /* [TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold] */
  /*   120 */                  FALSE,  /* [TUNER_FM1_short_to_battary_Circuit_Short_To_Battery] */
  /*   121 */                  FALSE,  /* [TUNER_FM1_short_to_groud_Circuit_Short_To_Ground] */
  /*   122 */                  FALSE,  /* [TUNER_FM2_open_Circuit_Open] */
  /*   123 */                  FALSE,  /* [TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold] */
  /*   124 */                  FALSE,  /* [TUNER_FM2_short_to_battary_Circuit_Short_To_Battery] */
  /*   125 */                  FALSE,  /* [TUNER_FM2_short_to_groud_Circuit_Short_To_Ground] */
  /*   126 */                  FALSE,  /* [Under_voltage_Circuit_Voltage_Below_Threshold] */
  /*   127 */                  FALSE,  /* [missing_Driver_Monitoring_System_Missing_Message] */
  /*   128 */                  FALSE,  /* [missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message] */
  /*   129 */                  FALSE,  /* [missing_Parking_Assistance_System_Missing_Message] */
  /*   130 */                  FALSE,  /* [missing_Passenger_Door_Control_Module_Missing_Message] */
  /*   131 */                  FALSE,  /* [missing_Right_Rear_Side_Detection_System_Missing_Message] */
  /*   132 */                  FALSE,  /* [missing_Telematics_control_Box_Missing_Message] */
  /*   133 */                  FALSE,  /* [missing_Trailer_Missing_Message] */
  /*   134 */                  FALSE,  /* [missing_Tyre_Pressure_Monitoring_Systems_Missing_Message] */
  /*   135 */                  FALSE,  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE] */
  /*   136 */                  FALSE,  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY] */
  /*   137 */                  FALSE,  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE] */
  /*   138 */                  FALSE,  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE] */
  /*   139 */                  FALSE,  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE] */
  /*   140 */                  FALSE,  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE] */
  /*   141 */                  FALSE,  /* [AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE] */
  /*   142 */                  FALSE,  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE] */
  /*   143 */                  FALSE,  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE] */
  /*   144 */                  FALSE,  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY] */
  /*   145 */                  FALSE,  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED] */
  /*   146 */                  FALSE,  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE] */
  /*   147 */                  FALSE,  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY] */
  /*   148 */                  FALSE,  /* [AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core] */
  /*   149 */                  FALSE,  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED] */
  /* Index     EventAvailableDefault      Comment */
  /*   150 */                  FALSE,  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE] */
  /*   151 */                  FALSE,  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY] */
  /*   152 */                  FALSE,  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED] */
  /*   153 */                  FALSE,  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE] */
  /*   154 */                  FALSE,  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE] */
  /*   155 */                  FALSE,  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE] */
  /*   156 */                  FALSE,  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE] */
  /*   157 */                  FALSE,  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE] */
  /*   158 */                  FALSE,  /* [Missing_Electric_Park_Brake_controller] */
  /*   159 */                  FALSE,  /* [MissingBattery_Management_System] */
  /*   160 */                  FALSE,  /* [Missing_Driver_Seat_Memory_module] */
  /*   161 */                  FALSE,  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN] */
  /*   162 */                  FALSE,  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN] */
  /*   163 */                  FALSE,  /* [Missing_Ibooster] */
  /*   164 */                  FALSE,  /* [Missing_Intelligent_Driving_Controller_Level2] */
  /*   165 */                  FALSE,  /* [Missing_Onboard_charger] */
  /*   166 */                  FALSE,  /* [Missing_Power_Lift_Gate_module] */
  /*   167 */                  FALSE,  /* [Missing_PrePretensioner_Mechatronic_Integrated] */
  /*   168 */                  FALSE,  /* [Missing_Rear_Heat_Vent_Seat_Module] */
  /*   169 */                  FALSE,  /* [Missing_Right_Headlamp_Control_Module] */
  /*   170 */                  FALSE,  /* [Missing_Seat_Control_Module] */
  /*   171 */                  FALSE,  /* [missing_Adaptive_Cruise_Control_system_Radar_Control_Module] */
  /*   172 */                  FALSE,  /* [FactoryModeNotClosed] */
  /*   173 */                  FALSE,  /* [missing_Right_Corner_Radar] */
  /*   174 */                  FALSE,  /* [LostComWithAVMFrontCamera] */
  /*   175 */                  FALSE,  /* [LostComWithAVMRearCamera] */
  /*   176 */                  FALSE,  /* [LostComWithAVMLeftCamera] */
  /*   177 */                  FALSE,  /* [LostComWithAVMRightCamera] */
  /*   178 */                  FALSE,  /* [Read_ClusterScreenIDFailed] */
  /*   179 */                  FALSE,  /* [ScreenClusterDriverErr] */
  /*   180 */                  FALSE,  /* [Read_IVIScreen_IDFailed] */
  /*   181 */                  FALSE,  /* [ScreenIVIDriverErr] */
  /*   182 */                  FALSE,  /* [RVC_CameraShortToGround] */
  /*   183 */                  FALSE,  /* [Read_CPScreen_IDFailed] */
  /*   184 */                  FALSE,  /* [RVC_CamerShortToBattery] */
  /*   185 */                  FALSE,  /* [ScreenCPDriverErr] */
  /*   186 */                  FALSE,  /* [RVC_CameraOpenCircuit] */
  /*   187 */                  FALSE,  /* [Read_CoDriverScreenIDFailed] */
  /*   188 */                  FALSE,  /* [ScreenCoDriverErr] */
  /*   189 */                  FALSE,  /* [AVM_CamerShortToBattery] */
  /*   190 */                  FALSE,  /* [Read_HUDScreen_IDFailed] */
  /*   191 */                  FALSE,  /* [AVM_CamerShortToGround] */
  /*   192 */                  FALSE,  /* [ScreenHUDDriverErr] */
  /*   193 */                  FALSE,  /* [AVM_CamerOpenCircuit] */
  /*   194 */                  FALSE,  /* [Temperature_SensorError] */
  /*   195 */                  FALSE,  /* [Internal_DMS_CameraShortToGround] */
  /*   196 */                  FALSE,  /* [Speaker_AVAS_ShortAcross] */
  /*   197 */                  FALSE,  /* [Internal_DVR_CameraShortToGround] */
  /*   198 */                  FALSE,  /* [Speaker_AVAS_ShortToGround] */
  /*   199 */                  FALSE,  /* [Internal_OMS_CameraShortToGround] */
  /* Index     EventAvailableDefault      Comment */
  /*   200 */                  FALSE,  /* [Speaker_AVAS_ShortToBattery] */
  /*   201 */                  FALSE,  /* [Internal_DMS_CameraShortToBattery] */
  /*   202 */                  FALSE,  /* [Speaker_AVAS_CircuitOpen] */
  /*   203 */                  FALSE,  /* [Internal_DVR_CameraShortToBattery] */
  /*   204 */                  FALSE,  /* [Speaker_AVAS_ResistanceOutOfRange] */
  /*   205 */                  FALSE,  /* [Internal_OMS_CameraShortToBattery] */
  /*   206 */                  FALSE,  /* [Speaker_AVAS_WaveformLackFidelity] */
  /*   207 */                  FALSE,  /* [Internal_DMS_CameraCircuitOpen] */
  /*   208 */                  FALSE,  /* [Internal_DVR_CameraCircuitOpen] */
  /*   209 */                  FALSE,  /* [Internal_OMS_CameraCircuitOpen] */
  /*   210 */                  FALSE,  /* [GPS_AntennaOpen] */
  /*   211 */                  FALSE,  /* [GPS_AntennaShortToGround] */
  /*   212 */                  FALSE,  /* [GPS_AntennaShortToBattery] */
  /*   213 */                  FALSE,  /* [GPS_OverCurrent] */
  /*   214 */                  FALSE,  /* [SVC_CameraShortToGround] */
  /*   215 */                  FALSE,  /* [SVC_CameraShortToBattery] */
  /*   216 */                  FALSE,  /* [SVC_CameraOpen] */
  /*   217 */                  FALSE,  /* [Lost_communication_with_SVC_Missing_Message] */
  /*   218 */                  FALSE,  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L2] */
  /*   219 */                  FALSE,  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L3] */
  /*   220 */                  FALSE,  /* [SecOC_Security_PDU_Verification_Failed_from_IFC] */
  /*   221 */                  FALSE,  /* [SecOC_Security_PDU_Verification_Failed_from_TCU] */
  /*   222 */                  FALSE,  /* [SecOC_Security_PDU_Verification_Failed_from_ESP] */
  /*   223 */                  FALSE,  /* [Lost_Communication_With_Depth_Of_Water_Detection_Module] */
  /*   224 */                  FALSE   /* [AbnormalWakeupSleep] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventTable
  \details
  Element                         Description
  AgingCycleCounterThreshold      DemAgingCycleCounterThreshold of the DemEventParameter/DemEventClass, if AgingAllowedOfEventTable==FALSE we use '255' here, too.
  AgingCycleId                    DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef
  CallbackGetFdcIdx               the index of the 1:1 relation pointing to Dem_Cfg_CallbackGetFdc
  DebounceTableIdx                the index of the 1:1 relation pointing to Dem_Cfg_DebounceTable
  DtcTableIdx                     the index of the 1:1 relation pointing to Dem_Cfg_DtcTable
  EnableConditionGroupTableIdx    the index of the 1:1 relation pointing to Dem_Cfg_EnableConditionGroupTable
  EventKind                       DemEventKind of the DemEventParameter
  EventPriority                   DemEventParameter/DemEventClass/DemEventPriority, values [1..255] for the configuration range [1..255].
  FreezeFrameNumTableEndIdx       the end index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameNumTableStartIdx     the start index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameTableStdFFIdx        the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable
  MaskedBits                      contains bitcoded the boolean data of Dem_Cfg_AgingAllowedOfEventTable, Dem_Cfg_DtrTableIndUsedOfEventTable, Dem_Cfg_EventLatchTFOfEventTable, Dem_Cfg_FreezeFrameNumTableUsedOfEventTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventTableType, DEM_CONST) Dem_Cfg_EventTable[225] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                               CallbackGetFdcIdx  DebounceTableIdx  DtcTableIdx  EnableConditionGroupTableIdx  EventKind                                         EventPriority  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  MaskedBits        Referable Keys */
  { /*     0 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               56u,               1u,          1u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [#EVENT_INVALID, Satellite#0] */
  { /*     1 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               56u,               1u,          1u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [A2B_open_Circuit_Open, Satellite#0] */
  { /*     2 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               55u,               1u,          2u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [A2B_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  { /*     3 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               54u,               1u,          3u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [A2B_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  { /*     4 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               53u,               1u,          4u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [ControlModuleCANBus_off_Bus_off, Satellite#0] */
  { /*     5 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               52u,               1u,          5u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect, Satellite#0] */
  { /*     6 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               51u,               1u,          6u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery, Satellite#0] */
  { /*     7 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,          7u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  { /*     8 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,          8u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  { /*     9 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,          9u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  { /*    10 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         10u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  { /*    11 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               41u,               1u,         11u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open, Satellite#0] */
  { /*    12 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               40u,               1u,         12u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure, Satellite#0] */
  { /*    13 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               39u,               1u,         13u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range, Satellite#0] */
  { /*    14 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               38u,               1u,         14u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  { /*    15 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               37u,               1u,         15u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  { /*    16 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               36u,               1u,         16u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure, Satellite#0] */
  { /*    17 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               35u,               1u,         17u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure, Satellite#0] */
  { /*    18 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               34u,               1u,         18u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure, Satellite#0] */
  { /*    19 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               33u,               1u,         19u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure, Satellite#0] */
  { /*    20 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               32u,               1u,         20u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure, Satellite#0] */
  { /*    21 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         21u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [INVALID_SHORTNAME_Over_Temperature_Over_Temperature, Satellite#0] */
  { /*    22 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               31u,               1u,         22u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [IP_Display_ASIC_failure_Internal_Electronic_Failure, Satellite#0] */
  { /*    23 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               46u,               1u,         23u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_OverVoltage, Satellite#0] */
  { /*    24 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               48u,               1u,         24u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_LowVoltage, Satellite#0] */
  { /*    25 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               47u,               1u,         25u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_NotReceiveBacklightValue, Satellite#0] */
  { /*    26 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               50u,               1u,         26u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_BacklightModuleError, Satellite#0] */
  { /*    27 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               45u,               1u,         27u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_TFT_Failure, Satellite#0] */
  { /*    28 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               42u,               1u,         28u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_VideoSignalConnectFailure, Satellite#0] */
  { /*    29 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               44u,               1u,         29u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_TouchPanelFailure, Satellite#0] */
  { /*    30 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               43u,               1u,         30u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_VibratorFailure, Satellite#0] */
  { /*    31 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               49u,               1u,         31u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [HVAC_Display_ForceInductionFailure, Satellite#0] */
  { /*    32 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               30u,               1u,         32u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure, Satellite#0] */
  { /*    33 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               29u,               1u,         33u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  { /*    34 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               28u,               1u,         34u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  { /*    35 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               27u,               1u,         35u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure, Satellite#0] */
  { /*    36 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               26u,               1u,         36u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure, Satellite#0] */
  { /*    37 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               25u,               1u,         37u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure, Satellite#0] */
  { /*    38 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               24u,               1u,         38u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_TCP_communication_Missing_Message, Satellite#0] */
  { /*    39 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               23u,               1u,         39u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_AVM_Missing_Message, Satellite#0] */
  { /*    40 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               19u,               1u,         40u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_IP_Display_Front_Missing_Message, Satellite#0] */
  { /*    41 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               18u,               1u,         41u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_IVI_Display_Front_Missing_Message, Satellite#0] */
  { /*    42 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               17u,               1u,         42u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_InCarCamera, Satellite#0] */
  { /*    43 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               22u,               1u,         43u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_ConsoleDisplay, Satellite#0] */
  { /*    44 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               15u,               1u,         44u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_RVC_Missing_Message, Satellite#0] */
  { /*    45 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               16u,               1u,         45u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_PassengerDisplay, Satellite#0] */
  { /*    46 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               14u,               1u,         46u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_W_HUD_Missing_Message, Satellite#0] */
  { /*    47 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               21u,               1u,         47u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_DMS, Satellite#0] */
  { /*    48 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         48u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Mic_1_open_Circuit_Open, Satellite#0] */
  { /*    49 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               20u,               1u,         49u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_DVR, Satellite#0] */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                               CallbackGetFdcIdx  DebounceTableIdx  DtcTableIdx  EnableConditionGroupTableIdx  EventKind                                         EventPriority  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  MaskedBits        Referable Keys */
  { /*    50 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         50u,                           7u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Mic_1_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  { /*    51 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         51u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Mic_1_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  { /*    52 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         52u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Mic_2_open_Circuit_Open, Satellite#0] */
  { /*    53 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         53u,                           7u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Mic_2_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  { /*    54 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         54u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Mic_2_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  { /*    55 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         55u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Satellite#0] */
  { /*    56 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         56u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Airbag_Module_Missing_Message, Satellite#0] */
  { /*    57 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         57u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Satellite#0] */
  { /*    58 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         58u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Combination_Switch_Assembly_Missing_Message, Satellite#0] */
  { /*    59 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         59u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Controler_Headlamp_Missing_Message, Satellite#0] */
  { /*    60 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         60u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Controller_Pedal_Missing_Message, Satellite#0] */
  { /*    61 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         61u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Driver_Door_Control_Module_Missing_Message, Satellite#0] */
  { /*    62 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         62u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Elec_Region_Control_System_Body_Missing_Message, Satellite#0] */
  { /*    63 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         63u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Electric_Power_Steering_system_Missing_Message, Satellite#0] */
  { /*    64 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         64u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Satellite#0] */
  { /*    65 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         65u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Electronic_Gerodisc_Missing_Message, Satellite#0] */
  { /*    66 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         66u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Engine_Control_Module_Missing_Message, Satellite#0] */
  { /*    67 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         67u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Front_Power_Box_Missing_Message, Satellite#0] */
  { /*    68 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         68u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Gateway_Missing_Message, Satellite#0] */
  { /*    69 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         69u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Satellite#0] */
  { /*    70 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         70u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Nextrac_Torque_On_Demand_Missing_Message, Satellite#0] */
  { /*    71 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         71u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Rear_Power_Box_Missing_Message, Satellite#0] */
  { /*    72 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         72u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Screen_touch_button_switch_controller_Missing_Message, Satellite#0] */
  { /*    73 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         73u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Transmission_Control_Until_PTCAN_Missing_Message, Satellite#0] */
  { /*    74 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         74u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Wireless_Power_Charger_Missing_Message, Satellite#0] */
  { /*    75 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         75u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  { /*    76 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               13u,               1u,         76u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved, Satellite#0] */
  { /*    77 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               10u,               1u,         77u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure, Satellite#0] */
  { /*    78 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               11u,               1u,         78u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_TBoxSecOcFailure, Satellite#0] */
  { /*    79 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                9u,               1u,         79u,                           5u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_software_module_running_error_Unexpected_Operation, Satellite#0] */
  { /*    80 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         80u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Center_open_Circuit_Open, Satellite#0] */
  { /*    81 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               12u,               1u,         81u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_GWSecOcFailure, Satellite#0] */
  { /*    82 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         82u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  { /*    83 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         83u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  { /*    84 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         84u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Center_short_across_General_Electrical_Failure, Satellite#0] */
  { /*    85 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         85u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  { /*    86 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         86u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  { /*    87 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         87u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FL_open_Circuit_Open, Satellite#0] */
  { /*    88 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         88u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  { /*    89 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         89u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  { /*    90 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         90u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FL_short_across_General_Electrical_Failure, Satellite#0] */
  { /*    91 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         91u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  { /*    92 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         92u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  { /*    93 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         93u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FR_open_Circuit_Open, Satellite#0] */
  { /*    94 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         94u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  { /*    95 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         95u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  { /*    96 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         96u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FR_short_across_General_Electrical_Failure, Satellite#0] */
  { /*    97 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         97u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  { /*    98 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         98u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  { /*    99 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,         99u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RL_open_Circuit_Open, Satellite#0] */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                               CallbackGetFdcIdx  DebounceTableIdx  DtcTableIdx  EnableConditionGroupTableIdx  EventKind                                         EventPriority  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  MaskedBits        Referable Keys */
  { /*   100 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        100u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  { /*   101 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        101u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  { /*   102 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        102u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RL_short_across_General_Electrical_Failure, Satellite#0] */
  { /*   103 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        103u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  { /*   104 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        104u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  { /*   105 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        105u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RR_open_Circuit_Open, Satellite#0] */
  { /*   106 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        106u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  { /*   107 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        107u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  { /*   108 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        108u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RR_short_across_General_Electrical_Failure, Satellite#0] */
  { /*   109 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        109u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  { /*   110 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        110u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  { /*   111 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        111u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Woofer_open_Circuit_Open, Satellite#0] */
  { /*   112 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        112u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  { /*   113 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        113u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  { /*   114 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        114u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Woofer_short_across_General_Electrical_Failure, Satellite#0] */
  { /*   115 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        115u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  { /*   116 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        116u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  { /*   117 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                8u,               1u,        117u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure, Satellite#0] */
  { /*   118 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                7u,               1u,        118u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM1_open_Circuit_Open, Satellite#0] */
  { /*   119 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                6u,               1u,        119u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold, Satellite#0] */
  { /*   120 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                5u,               1u,        120u,                           7u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM1_short_to_battary_Circuit_Short_To_Battery, Satellite#0] */
  { /*   121 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                4u,               1u,        121u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM1_short_to_groud_Circuit_Short_To_Ground, Satellite#0] */
  { /*   122 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                3u,               1u,        122u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM2_open_Circuit_Open, Satellite#0] */
  { /*   123 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                2u,               1u,        123u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold, Satellite#0] */
  { /*   124 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                1u,               1u,        124u,                           7u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM2_short_to_battary_Circuit_Short_To_Battery, Satellite#0] */
  { /*   125 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,                0u,               1u,        125u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [TUNER_FM2_short_to_groud_Circuit_Short_To_Ground, Satellite#0] */
  { /*   126 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        126u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Under_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  { /*   127 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        127u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Driver_Monitoring_System_Missing_Message, Satellite#0] */
  { /*   128 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        128u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, Satellite#0] */
  { /*   129 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        129u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Parking_Assistance_System_Missing_Message, Satellite#0] */
  { /*   130 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        130u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Passenger_Door_Control_Module_Missing_Message, Satellite#0] */
  { /*   131 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        131u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Right_Rear_Side_Detection_System_Missing_Message, Satellite#0] */
  { /*   132 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        132u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Telematics_control_Box_Missing_Message, Satellite#0] */
  { /*   133 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        133u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Trailer_Missing_Message, Satellite#0] */
  { /*   134 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        134u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Tyre_Pressure_Monitoring_Systems_Missing_Message, Satellite#0] */
  { /*   135 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  { /*   136 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*   137 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE, Satellite#0] */
  { /*   138 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE, Satellite#0] */
  { /*   139 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE, Satellite#0] */
  { /*   140 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE, Satellite#0] */
  { /*   141 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  { /*   142 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE, Satellite#0] */
  { /*   143 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE, Satellite#0] */
  { /*   144 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*   145 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED, Satellite#0] */
  { /*   146 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE, Satellite#0] */
  { /*   147 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*   148 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               0u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core, Satellite#0] */
  { /*   149 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED, Satellite#0] */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                               CallbackGetFdcIdx  DebounceTableIdx  DtcTableIdx  EnableConditionGroupTableIdx  EventKind                                         EventPriority  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  MaskedBits        Referable Keys */
  { /*   150 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE, Satellite#0] */
  { /*   151 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY, Satellite#0] */
  { /*   152 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED, Satellite#0] */
  { /*   153 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE, Satellite#0] */
  { /*   154 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE, Satellite#0] */
  { /*   155 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE, Satellite#0] */
  { /*   156 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE, Satellite#0] */
  { /*   157 */                       255u, /*no AgingCycle*/ 2U                     ,               57u,               1u,          0u,                           0u, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,      0x00u },  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE, Satellite#0] */
  { /*   158 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        135u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Electric_Park_Brake_controller, Satellite#0] */
  { /*   159 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        136u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [MissingBattery_Management_System, Satellite#0] */
  { /*   160 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        137u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Driver_Seat_Memory_module, Satellite#0] */
  { /*   161 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        138u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Satellite#0] */
  { /*   162 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        139u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Satellite#0] */
  { /*   163 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        140u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Ibooster, Satellite#0] */
  { /*   164 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        141u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Intelligent_Driving_Controller_Level2, Satellite#0] */
  { /*   165 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        142u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Onboard_charger, Satellite#0] */
  { /*   166 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        143u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Power_Lift_Gate_module, Satellite#0] */
  { /*   167 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        144u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_PrePretensioner_Mechatronic_Integrated, Satellite#0] */
  { /*   168 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        145u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Rear_Heat_Vent_Seat_Module, Satellite#0] */
  { /*   169 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        146u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Right_Headlamp_Control_Module, Satellite#0] */
  { /*   170 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        147u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Missing_Seat_Control_Module, Satellite#0] */
  { /*   171 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        148u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Adaptive_Cruise_Control_system_Radar_Control_Module, Satellite#0] */
  { /*   172 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        149u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [FactoryModeNotClosed, Satellite#0] */
  { /*   173 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        150u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [missing_Right_Corner_Radar, Satellite#0] */
  { /*   174 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        151u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [LostComWithAVMFrontCamera, Satellite#0] */
  { /*   175 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        152u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [LostComWithAVMRearCamera, Satellite#0] */
  { /*   176 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        153u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [LostComWithAVMLeftCamera, Satellite#0] */
  { /*   177 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        154u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [LostComWithAVMRightCamera, Satellite#0] */
  { /*   178 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        155u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Read_ClusterScreenIDFailed, Satellite#0] */
  { /*   179 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        156u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [ScreenClusterDriverErr, Satellite#0] */
  { /*   180 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        157u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Read_IVIScreen_IDFailed, Satellite#0] */
  { /*   181 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        158u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [ScreenIVIDriverErr, Satellite#0] */
  { /*   182 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        159u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [RVC_CameraShortToGround, Satellite#0] */
  { /*   183 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        160u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Read_CPScreen_IDFailed, Satellite#0] */
  { /*   184 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        161u,                           7u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [RVC_CamerShortToBattery, Satellite#0] */
  { /*   185 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        162u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [ScreenCPDriverErr, Satellite#0] */
  { /*   186 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        163u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [RVC_CameraOpenCircuit, Satellite#0] */
  { /*   187 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        164u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Read_CoDriverScreenIDFailed, Satellite#0] */
  { /*   188 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        165u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [ScreenCoDriverErr, Satellite#0] */
  { /*   189 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        166u,                           3u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [AVM_CamerShortToBattery, Satellite#0] */
  { /*   190 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        167u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Read_HUDScreen_IDFailed, Satellite#0] */
  { /*   191 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        168u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [AVM_CamerShortToGround, Satellite#0] */
  { /*   192 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        169u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [ScreenHUDDriverErr, Satellite#0] */
  { /*   193 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        170u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [AVM_CamerOpenCircuit, Satellite#0] */
  { /*   194 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        171u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Temperature_SensorError, Satellite#0] */
  { /*   195 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        172u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_DMS_CameraShortToGround, Satellite#0] */
  { /*   196 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        173u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_AVAS_ShortAcross, Satellite#0] */
  { /*   197 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        174u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_DVR_CameraShortToGround, Satellite#0] */
  { /*   198 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        175u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_AVAS_ShortToGround, Satellite#0] */
  { /*   199 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        176u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_OMS_CameraShortToGround, Satellite#0] */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                               CallbackGetFdcIdx  DebounceTableIdx  DtcTableIdx  EnableConditionGroupTableIdx  EventKind                                         EventPriority  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  MaskedBits        Referable Keys */
  { /*   200 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        177u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_AVAS_ShortToBattery, Satellite#0] */
  { /*   201 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        178u,                           4u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_DMS_CameraShortToBattery, Satellite#0] */
  { /*   202 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        179u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_AVAS_CircuitOpen, Satellite#0] */
  { /*   203 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        180u,                           4u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_DVR_CameraShortToBattery, Satellite#0] */
  { /*   204 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        181u,                           1u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_AVAS_ResistanceOutOfRange, Satellite#0] */
  { /*   205 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        182u,                           4u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_OMS_CameraShortToBattery, Satellite#0] */
  { /*   206 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        183u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Speaker_AVAS_WaveformLackFidelity, Satellite#0] */
  { /*   207 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        184u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_DMS_CameraCircuitOpen, Satellite#0] */
  { /*   208 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        185u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_DVR_CameraCircuitOpen, Satellite#0] */
  { /*   209 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        186u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Internal_OMS_CameraCircuitOpen, Satellite#0] */
  { /*   210 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        187u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [GPS_AntennaOpen, Satellite#0] */
  { /*   211 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        188u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [GPS_AntennaShortToGround, Satellite#0] */
  { /*   212 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        189u,                           7u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [GPS_AntennaShortToBattery, Satellite#0] */
  { /*   213 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        190u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [GPS_OverCurrent, Satellite#0] */
  { /*   214 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        191u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SVC_CameraShortToGround, Satellite#0] */
  { /*   215 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        192u,                           3u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SVC_CameraShortToBattery, Satellite#0] */
  { /*   216 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        193u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SVC_CameraOpen, Satellite#0] */
  { /*   217 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        194u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_communication_with_SVC_Missing_Message, Satellite#0] */
  { /*   218 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        195u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L2, Satellite#0] */
  { /*   219 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        196u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L3, Satellite#0] */
  { /*   220 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        197u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_Security_PDU_Verification_Failed_from_IFC, Satellite#0] */
  { /*   221 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        198u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_Security_PDU_Verification_Failed_from_TCU, Satellite#0] */
  { /*   222 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        199u,                           5u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [SecOC_Security_PDU_Verification_Failed_from_ESP, Satellite#0] */
  { /*   223 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        200u,                           8u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u },  /* [Lost_Communication_With_Depth_Of_Water_Detection_Module, Satellite#0] */
  { /*   224 */                        40u, DemConf_DemOperationCycle_Ignition_on_off,               57u,               1u,        201u,                           0u, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,                                               1u,                                                 0u,                       1u,      0x05u }   /* [AbnormalWakeupSleep, Satellite#0] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataTable
  \details
  Element                                   Description
  DataCollectionTableEdr2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
  DataCollectionTableEdr2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_ExtendedDataTableType, DEM_CONST) Dem_Cfg_ExtendedDataTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableEdr2CollIndEndIdx                                DataCollectionTableEdr2CollIndStartIdx                                      Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE, DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE },  /* [#NoExtendedDataRecordConfigured, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE, AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE] */
  { /*     1 */                                                                 2u,                                                                   0u }   /* [#ExtendedDataClass_4f5344cd, #EVENT_INVALID, A2B_open_Circuit_Open, A2B_short_to_battery_Circuit_Short_To_Battery, A2B_short_to_ground_Circuit_Short_To_Ground, ControlModuleCANBus_off_Bus_off, Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect, Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery, Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open, INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure, INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range, INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold, INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold, INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure, INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_Over_Temperature_Over_Temperature, IP_Display_ASIC_failure_Internal_Electronic_Failure, HVAC_Display_OverVoltage, HVAC_Display_LowVoltage, HVAC_Display_NotReceiveBacklightValue, HVAC_Display_BacklightModuleError, HVAC_Display_TFT_Failure, HVAC_Display_VideoSignalConnectFailure, HVAC_Display_TouchPanelFailure, HVAC_Display_VibratorFailure, HVAC_Display_ForceInductionFailure, IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure, IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold, IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold, IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure, IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure, IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure, Lost_TCP_communication_Missing_Message, Lost_communication_with_AVM_Missing_Message, Lost_communication_with_IP_Display_Front_Missing_Message, Lost_communication_with_IVI_Display_Front_Missing_Message, Lost_communication_with_InCarCamera, Lost_communication_with_ConsoleDisplay, Lost_communication_with_RVC_Missing_Message, Lost_communication_with_PassengerDisplay, Lost_communication_with_W_HUD_Missing_Message, Lost_communication_with_DMS, Mic_1_open_Circuit_Open, Lost_communication_with_DVR, Mic_1_short_to_BAT_Circuit_Short_To_Battery, Mic_1_short_to_GND_Circuit_Short_To_Ground, Mic_2_open_Circuit_Open, Mic_2_short_to_BAT_Circuit_Short_To_Battery, Mic_2_short_to_GND_Circuit_Short_To_Ground, Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Missing_Airbag_Module_Missing_Message, Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Missing_Combination_Switch_Assembly_Missing_Message, Missing_Controler_Headlamp_Missing_Message, Missing_Controller_Pedal_Missing_Message, Missing_Driver_Door_Control_Module_Missing_Message, Missing_Elec_Region_Control_System_Body_Missing_Message, Missing_Electric_Power_Steering_system_Missing_Message, Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Missing_Electronic_Gerodisc_Missing_Message, Missing_Engine_Control_Module_Missing_Message, Missing_Front_Power_Box_Missing_Message, Missing_Gateway_Missing_Message, Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Missing_Nextrac_Torque_On_Demand_Missing_Message, Missing_Rear_Power_Box_Missing_Message, Missing_Screen_touch_button_switch_controller_Missing_Message, Missing_Transmission_Control_Until_PTCAN_Missing_Message, Missing_Wireless_Power_Charger_Missing_Message, Over_voltage_Circuit_Voltage_Above_Threshold, SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved, SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure, SecOC_TBoxSecOcFailure, SecOC_software_module_running_error_Unexpected_Operation, Speaker_Center_open_Circuit_Open, SecOC_GWSecOcFailure, Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Center_short_across_General_Electrical_Failure, Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Speaker_FL_open_Circuit_Open, Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FL_short_across_General_Electrical_Failure, Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Speaker_FR_open_Circuit_Open, Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FR_short_across_General_Electrical_Failure, Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Speaker_RL_open_Circuit_Open, Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RL_short_across_General_Electrical_Failure, Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Speaker_RR_open_Circuit_Open, Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RR_short_across_General_Electrical_Failure, Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Speaker_Woofer_open_Circuit_Open, Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Woofer_short_across_General_Electrical_Failure, Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure, TUNER_FM1_open_Circuit_Open, TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold, TUNER_FM1_short_to_battary_Circuit_Short_To_Battery, TUNER_FM1_short_to_groud_Circuit_Short_To_Ground, TUNER_FM2_open_Circuit_Open, TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold, TUNER_FM2_short_to_battary_Circuit_Short_To_Battery, TUNER_FM2_short_to_groud_Circuit_Short_To_Ground, Under_voltage_Circuit_Voltage_Below_Threshold, missing_Driver_Monitoring_System_Missing_Message, missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, missing_Parking_Assistance_System_Missing_Message, missing_Passenger_Door_Control_Module_Missing_Message, missing_Right_Rear_Side_Detection_System_Missing_Message, 
            missing_Telematics_control_Box_Missing_Message, missing_Trailer_Missing_Message, missing_Tyre_Pressure_Monitoring_Systems_Missing_Message, Missing_Electric_Park_Brake_controller, MissingBattery_Management_System, Missing_Driver_Seat_Memory_module, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Missing_Ibooster, Missing_Intelligent_Driving_Controller_Level2, Missing_Onboard_charger, Missing_Power_Lift_Gate_module, Missing_PrePretensioner_Mechatronic_Integrated, Missing_Rear_Heat_Vent_Seat_Module, Missing_Right_Headlamp_Control_Module, Missing_Seat_Control_Module, missing_Adaptive_Cruise_Control_system_Radar_Control_Module, FactoryModeNotClosed, missing_Right_Corner_Radar, LostComWithAVMFrontCamera, LostComWithAVMRearCamera, LostComWithAVMLeftCamera, LostComWithAVMRightCamera, Read_ClusterScreenIDFailed, ScreenClusterDriverErr, Read_IVIScreen_IDFailed, ScreenIVIDriverErr, RVC_CameraShortToGround, Read_CPScreen_IDFailed, RVC_CamerShortToBattery, ScreenCPDriverErr, RVC_CameraOpenCircuit, Read_CoDriverScreenIDFailed, ScreenCoDriverErr, AVM_CamerShortToBattery, Read_HUDScreen_IDFailed, AVM_CamerShortToGround, ScreenHUDDriverErr, AVM_CamerOpenCircuit, Temperature_SensorError, Internal_DMS_CameraShortToGround, Speaker_AVAS_ShortAcross, Internal_DVR_CameraShortToGround, Speaker_AVAS_ShortToGround, Internal_OMS_CameraShortToGround, Speaker_AVAS_ShortToBattery, Internal_DMS_CameraShortToBattery, Speaker_AVAS_CircuitOpen, Internal_DVR_CameraShortToBattery, Speaker_AVAS_ResistanceOutOfRange, Internal_OMS_CameraShortToBattery, Speaker_AVAS_WaveformLackFidelity, Internal_DMS_CameraCircuitOpen, Internal_DVR_CameraCircuitOpen, Internal_OMS_CameraCircuitOpen, GPS_AntennaOpen, GPS_AntennaShortToGround, GPS_AntennaShortToBattery, GPS_OverCurrent, SVC_CameraShortToGround, SVC_CameraShortToBattery, SVC_CameraOpen, Lost_communication_with_SVC_Missing_Message, SecOC_Security_PDU_Verification_Failed_from_IDC_L2, SecOC_Security_PDU_Verification_Failed_from_IDC_L3, SecOC_Security_PDU_Verification_Failed_from_IFC, SecOC_Security_PDU_Verification_Failed_from_TCU, SecOC_Security_PDU_Verification_Failed_from_ESP, Lost_Communication_With_Depth_Of_Water_Detection_Module, AbnormalWakeupSleep] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameTable
  \details
  Element                                   Description
  DataCollectionTableFfm2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  DataCollectionTableFfm2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  RecordSize                                Summarized size of did data that is stored in Dem_Cfg_PrimaryEntryType.SnapshotData[][] (i.e. typically without size of dids containing internal data elements).
  RecordSizeUds                             Summarized size of did data, did numbers and snapshot header (i.e. dynamical payload size of the uds response message).
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameTableType, DEM_CONST) Dem_Cfg_FreezeFrameTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableFfm2CollIndEndIdx                               DataCollectionTableFfm2CollIndStartIdx                               RecordSize  RecordSizeUds        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE, DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE,         0u,            0u },  /* [#NoFreezeFrameConfigured, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE, AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE, AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED, AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE, AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE, AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE, AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE] */
  { /*     1 */                                                                7u,                                                                  0u,        16u,           32u }   /* [#FreezeFrameClass_80c88891, #EVENT_INVALID, A2B_open_Circuit_Open, A2B_short_to_battery_Circuit_Short_To_Battery, A2B_short_to_ground_Circuit_Short_To_Ground, ControlModuleCANBus_off_Bus_off, Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect, Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery, Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open, INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure, INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range, INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold, INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold, INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure, INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure, INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure, INVALID_SHORTNAME_Over_Temperature_Over_Temperature, IP_Display_ASIC_failure_Internal_Electronic_Failure, HVAC_Display_OverVoltage, HVAC_Display_LowVoltage, HVAC_Display_NotReceiveBacklightValue, HVAC_Display_BacklightModuleError, HVAC_Display_TFT_Failure, HVAC_Display_VideoSignalConnectFailure, HVAC_Display_TouchPanelFailure, HVAC_Display_VibratorFailure, HVAC_Display_ForceInductionFailure, IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure, IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold, IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold, IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure, IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure, IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure, Lost_TCP_communication_Missing_Message, Lost_communication_with_AVM_Missing_Message, Lost_communication_with_IP_Display_Front_Missing_Message, Lost_communication_with_IVI_Display_Front_Missing_Message, Lost_communication_with_InCarCamera, Lost_communication_with_ConsoleDisplay, Lost_communication_with_RVC_Missing_Message, Lost_communication_with_PassengerDisplay, Lost_communication_with_W_HUD_Missing_Message, Lost_communication_with_DMS, Mic_1_open_Circuit_Open, Lost_communication_with_DVR, Mic_1_short_to_BAT_Circuit_Short_To_Battery, Mic_1_short_to_GND_Circuit_Short_To_Ground, Mic_2_open_Circuit_Open, Mic_2_short_to_BAT_Circuit_Short_To_Battery, Mic_2_short_to_GND_Circuit_Short_To_Ground, Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Missing_Airbag_Module_Missing_Message, Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Missing_Combination_Switch_Assembly_Missing_Message, Missing_Controler_Headlamp_Missing_Message, Missing_Controller_Pedal_Missing_Message, Missing_Driver_Door_Control_Module_Missing_Message, Missing_Elec_Region_Control_System_Body_Missing_Message, Missing_Electric_Power_Steering_system_Missing_Message, Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Missing_Electronic_Gerodisc_Missing_Message, Missing_Engine_Control_Module_Missing_Message, Missing_Front_Power_Box_Missing_Message, Missing_Gateway_Missing_Message, Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Missing_Nextrac_Torque_On_Demand_Missing_Message, Missing_Rear_Power_Box_Missing_Message, Missing_Screen_touch_button_switch_controller_Missing_Message, Missing_Transmission_Control_Until_PTCAN_Missing_Message, Missing_Wireless_Power_Charger_Missing_Message, Over_voltage_Circuit_Voltage_Above_Threshold, SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved, SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure, SecOC_TBoxSecOcFailure, SecOC_software_module_running_error_Unexpected_Operation, Speaker_Center_open_Circuit_Open, SecOC_GWSecOcFailure, Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Center_short_across_General_Electrical_Failure, Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Speaker_FL_open_Circuit_Open, Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FL_short_across_General_Electrical_Failure, Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Speaker_FR_open_Circuit_Open, Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_FR_short_across_General_Electrical_Failure, Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Speaker_RL_open_Circuit_Open, Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RL_short_across_General_Electrical_Failure, Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Speaker_RR_open_Circuit_Open, Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_RR_short_across_General_Electrical_Failure, Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Speaker_Woofer_open_Circuit_Open, Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Speaker_Woofer_short_across_General_Electrical_Failure, Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure, TUNER_FM1_open_Circuit_Open, TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold, TUNER_FM1_short_to_battary_Circuit_Short_To_Battery, TUNER_FM1_short_to_groud_Circuit_Short_To_Ground, TUNER_FM2_open_Circuit_Open, TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold, TUNER_FM2_short_to_battary_Circuit_Short_To_Battery, TUNER_FM2_short_to_groud_Circuit_Short_To_Ground, Under_voltage_Circuit_Voltage_Below_Threshold, missing_Driver_Monitoring_System_Missing_Message, missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, missing_Parking_Assistance_System_Missing_Message, missing_Passenger_Door_Control_Module_Missing_Message, missing_Right_Rear_Side_Detection_System_Missing_Message, 
            missing_Telematics_control_Box_Missing_Message, missing_Trailer_Missing_Message, missing_Tyre_Pressure_Monitoring_Systems_Missing_Message, Missing_Electric_Park_Brake_controller, MissingBattery_Management_System, Missing_Driver_Seat_Memory_module, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Missing_Ibooster, Missing_Intelligent_Driving_Controller_Level2, Missing_Onboard_charger, Missing_Power_Lift_Gate_module, Missing_PrePretensioner_Mechatronic_Integrated, Missing_Rear_Heat_Vent_Seat_Module, Missing_Right_Headlamp_Control_Module, Missing_Seat_Control_Module, missing_Adaptive_Cruise_Control_system_Radar_Control_Module, FactoryModeNotClosed, missing_Right_Corner_Radar, LostComWithAVMFrontCamera, LostComWithAVMRearCamera, LostComWithAVMLeftCamera, LostComWithAVMRightCamera, Read_ClusterScreenIDFailed, ScreenClusterDriverErr, Read_IVIScreen_IDFailed, ScreenIVIDriverErr, RVC_CameraShortToGround, Read_CPScreen_IDFailed, RVC_CamerShortToBattery, ScreenCPDriverErr, RVC_CameraOpenCircuit, Read_CoDriverScreenIDFailed, ScreenCoDriverErr, AVM_CamerShortToBattery, Read_HUDScreen_IDFailed, AVM_CamerShortToGround, ScreenHUDDriverErr, AVM_CamerOpenCircuit, Temperature_SensorError, Internal_DMS_CameraShortToGround, Speaker_AVAS_ShortAcross, Internal_DVR_CameraShortToGround, Speaker_AVAS_ShortToGround, Internal_OMS_CameraShortToGround, Speaker_AVAS_ShortToBattery, Internal_DMS_CameraShortToBattery, Speaker_AVAS_CircuitOpen, Internal_DVR_CameraShortToBattery, Speaker_AVAS_ResistanceOutOfRange, Internal_OMS_CameraShortToBattery, Speaker_AVAS_WaveformLackFidelity, Internal_DMS_CameraCircuitOpen, Internal_DVR_CameraCircuitOpen, Internal_OMS_CameraCircuitOpen, GPS_AntennaOpen, GPS_AntennaShortToGround, GPS_AntennaShortToBattery, GPS_OverCurrent, SVC_CameraShortToGround, SVC_CameraShortToBattery, SVC_CameraOpen, Lost_communication_with_SVC_Missing_Message, SecOC_Security_PDU_Verification_Failed_from_IDC_L2, SecOC_Security_PDU_Verification_Failed_from_IDC_L3, SecOC_Security_PDU_Verification_Failed_from_IFC, SecOC_Security_PDU_Verification_Failed_from_TCU, SecOC_Security_PDU_Verification_Failed_from_ESP, Lost_Communication_With_Depth_Of_Water_Detection_Module, AbnormalWakeupSleep] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryBlockId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryBlockId
  \brief  The array contains these items: Admin, Status, 20 * Primary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryBlockIdType, DEM_CONST) Dem_Cfg_MemoryBlockId[22] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryBlockId                                                           Comment */
  /*     0 */ NvMConf_NvMBlockDescriptor_DemAdminDataBlock /*NvMBlockId=2*/      ,  /* [Dem_AdminData] */
  /*     1 */ NvMConf_NvMBlockDescriptor_DemStatusDataBlock /*NvMBlockId=3*/     ,  /* [Dem_StatusData] */
  /*     2 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock0 /*NvMBlockId=4*/   ,  /* [Dem_PrimaryEntry0] */
  /*     3 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock1 /*NvMBlockId=5*/   ,  /* [Dem_PrimaryEntry1] */
  /*     4 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock2 /*NvMBlockId=6*/   ,  /* [Dem_PrimaryEntry2] */
  /*     5 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock3 /*NvMBlockId=7*/   ,  /* [Dem_PrimaryEntry3] */
  /*     6 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock4 /*NvMBlockId=8*/   ,  /* [Dem_PrimaryEntry4] */
  /*     7 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock5 /*NvMBlockId=9*/   ,  /* [Dem_PrimaryEntry5] */
  /*     8 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock6 /*NvMBlockId=10*/  ,  /* [Dem_PrimaryEntry6] */
  /*     9 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock7 /*NvMBlockId=11*/  ,  /* [Dem_PrimaryEntry7] */
  /*    10 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock8 /*NvMBlockId=12*/  ,  /* [Dem_PrimaryEntry8] */
  /*    11 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock9 /*NvMBlockId=14*/  ,  /* [Dem_PrimaryEntry9] */
  /*    12 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock10 /*NvMBlockId=16*/ ,  /* [Dem_PrimaryEntry10] */
  /*    13 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock11 /*NvMBlockId=18*/ ,  /* [Dem_PrimaryEntry11] */
  /*    14 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock12 /*NvMBlockId=20*/ ,  /* [Dem_PrimaryEntry12] */
  /*    15 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock13 /*NvMBlockId=22*/ ,  /* [Dem_PrimaryEntry13] */
  /*    16 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock14 /*NvMBlockId=24*/ ,  /* [Dem_PrimaryEntry14] */
  /*    17 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock15 /*NvMBlockId=26*/ ,  /* [Dem_PrimaryEntry15] */
  /*    18 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock16 /*NvMBlockId=27*/ ,  /* [Dem_PrimaryEntry16] */
  /*    19 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock17 /*NvMBlockId=28*/ ,  /* [Dem_PrimaryEntry17] */
  /*    20 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock18 /*NvMBlockId=32*/ ,  /* [Dem_PrimaryEntry18] */
  /*    21 */ NvMConf_NvMBlockDescriptor_DemPrimaryDataBlock19 /*NvMBlockId=30*/    /* [Dem_PrimaryEntry19] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryBlockIdToMemoryEntryId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryBlockIdToMemoryEntryId
  \brief  The array contains these items: Admin, Status, 20 * Primary
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryEntryHandleType, DEM_CONST) Dem_Cfg_MemoryBlockIdToMemoryEntryId[22] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryBlockIdToMemoryEntryId        Comment */
  /*     0 */ DEM_MEMORYENTRY_HANDLE_INVALID ,  /* [Dem_AdminData] */
  /*     1 */ DEM_MEMORYENTRY_HANDLE_INVALID ,  /* [Dem_StatusData] */
  /*     2 */ 0u                             ,  /* [Dem_PrimaryEntry0] */
  /*     3 */ 1u                             ,  /* [Dem_PrimaryEntry1] */
  /*     4 */ 2u                             ,  /* [Dem_PrimaryEntry2] */
  /*     5 */ 3u                             ,  /* [Dem_PrimaryEntry3] */
  /*     6 */ 4u                             ,  /* [Dem_PrimaryEntry4] */
  /*     7 */ 5u                             ,  /* [Dem_PrimaryEntry5] */
  /*     8 */ 6u                             ,  /* [Dem_PrimaryEntry6] */
  /*     9 */ 7u                             ,  /* [Dem_PrimaryEntry7] */
  /*    10 */ 8u                             ,  /* [Dem_PrimaryEntry8] */
  /*    11 */ 9u                             ,  /* [Dem_PrimaryEntry9] */
  /*    12 */ 10u                            ,  /* [Dem_PrimaryEntry10] */
  /*    13 */ 11u                            ,  /* [Dem_PrimaryEntry11] */
  /*    14 */ 12u                            ,  /* [Dem_PrimaryEntry12] */
  /*    15 */ 13u                            ,  /* [Dem_PrimaryEntry13] */
  /*    16 */ 14u                            ,  /* [Dem_PrimaryEntry14] */
  /*    17 */ 15u                            ,  /* [Dem_PrimaryEntry15] */
  /*    18 */ 16u                            ,  /* [Dem_PrimaryEntry16] */
  /*    19 */ 17u                            ,  /* [Dem_PrimaryEntry17] */
  /*    20 */ 18u                            ,  /* [Dem_PrimaryEntry18] */
  /*    21 */ 19u                               /* [Dem_PrimaryEntry19] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataPtr
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataPtr
  \brief  The array contains these items: Admin, Status, 20 * Primary
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_NvDataPtrType, DEM_CONST) Dem_Cfg_MemoryDataPtr[22] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryDataPtr                                                                                   Comment */
  /*     0 */ (Dem_NvDataPtrType) &Dem_Cfg_GetAdminData()         /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_AdminData] */
  /*     1 */ (Dem_NvDataPtrType) &Dem_Cfg_GetStatusData()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_StatusData] */
  /*     2 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_0()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry0] */
  /*     3 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_1()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry1] */
  /*     4 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_2()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry2] */
  /*     5 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_3()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry3] */
  /*     6 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_4()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry4] */
  /*     7 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_5()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry5] */
  /*     8 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_6()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry6] */
  /*     9 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_7()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry7] */
  /*    10 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_8()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry8] */
  /*    11 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_9()    /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry9] */
  /*    12 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_10()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry10] */
  /*    13 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_11()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry11] */
  /*    14 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_12()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry12] */
  /*    15 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_13()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry13] */
  /*    16 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_14()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry14] */
  /*    17 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_15()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry15] */
  /*    18 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_16()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry16] */
  /*    19 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_17()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry17] */
  /*    20 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_18()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry18] */
  /*    21 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_19()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_PrimaryEntry19] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataSize
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataSize
  \brief  The array contains these items: Admin, Status, 20 * Primary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryDataSizeType, DEM_CONST) Dem_Cfg_MemoryDataSize[22] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryDataSize                                                         Comment */
  /*     0 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetAdminData())       ,  /* [Dem_AdminData] */
  /*     1 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetStatusData())      ,  /* [Dem_StatusData] */
  /*     2 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_0())  ,  /* [Dem_PrimaryEntry0] */
  /*     3 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_1())  ,  /* [Dem_PrimaryEntry1] */
  /*     4 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_2())  ,  /* [Dem_PrimaryEntry2] */
  /*     5 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_3())  ,  /* [Dem_PrimaryEntry3] */
  /*     6 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_4())  ,  /* [Dem_PrimaryEntry4] */
  /*     7 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_5())  ,  /* [Dem_PrimaryEntry5] */
  /*     8 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_6())  ,  /* [Dem_PrimaryEntry6] */
  /*     9 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_7())  ,  /* [Dem_PrimaryEntry7] */
  /*    10 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_8())  ,  /* [Dem_PrimaryEntry8] */
  /*    11 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_9())  ,  /* [Dem_PrimaryEntry9] */
  /*    12 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_10()) ,  /* [Dem_PrimaryEntry10] */
  /*    13 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_11()) ,  /* [Dem_PrimaryEntry11] */
  /*    14 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_12()) ,  /* [Dem_PrimaryEntry12] */
  /*    15 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_13()) ,  /* [Dem_PrimaryEntry13] */
  /*    16 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_14()) ,  /* [Dem_PrimaryEntry14] */
  /*    17 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_15()) ,  /* [Dem_PrimaryEntry15] */
  /*    18 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_16()) ,  /* [Dem_PrimaryEntry16] */
  /*    19 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_17()) ,  /* [Dem_PrimaryEntry17] */
  /*    20 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_18()) ,  /* [Dem_PrimaryEntry18] */
  /*    21 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_19())    /* [Dem_PrimaryEntry19] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntry
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryEntry
  \brief  The array contains these items: 20 * Primary, ReadoutBuffer; size = DEM_CFG_GLOBAL_PRIMARY_SIZE + DEM_CFG_GLOBAL_SECONDARY_SIZE + DEM_CFG_NUMBER_OF_READOUTBUFFERS * DEM_CFG_NUMBER_OF_SUBEVENT_DATA_READOUTBUFFERS
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_SharedMemoryEntryPtrType, DEM_CONST) Dem_Cfg_MemoryEntry[21] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryEntry                                                                                          Comment */
  /*     0 */ &Dem_Cfg_GetPrimaryEntry_0()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry0] */
  /*     1 */ &Dem_Cfg_GetPrimaryEntry_1()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry1] */
  /*     2 */ &Dem_Cfg_GetPrimaryEntry_2()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry2] */
  /*     3 */ &Dem_Cfg_GetPrimaryEntry_3()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry3] */
  /*     4 */ &Dem_Cfg_GetPrimaryEntry_4()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry4] */
  /*     5 */ &Dem_Cfg_GetPrimaryEntry_5()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry5] */
  /*     6 */ &Dem_Cfg_GetPrimaryEntry_6()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry6] */
  /*     7 */ &Dem_Cfg_GetPrimaryEntry_7()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry7] */
  /*     8 */ &Dem_Cfg_GetPrimaryEntry_8()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry8] */
  /*     9 */ &Dem_Cfg_GetPrimaryEntry_9()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry9] */
  /*    10 */ &Dem_Cfg_GetPrimaryEntry_10()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry10] */
  /*    11 */ &Dem_Cfg_GetPrimaryEntry_11()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry11] */
  /*    12 */ &Dem_Cfg_GetPrimaryEntry_12()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry12] */
  /*    13 */ &Dem_Cfg_GetPrimaryEntry_13()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry13] */
  /*    14 */ &Dem_Cfg_GetPrimaryEntry_14()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry14] */
  /*    15 */ &Dem_Cfg_GetPrimaryEntry_15()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry15] */
  /*    16 */ &Dem_Cfg_GetPrimaryEntry_16()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry16] */
  /*    17 */ &Dem_Cfg_GetPrimaryEntry_17()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry17] */
  /*    18 */ &Dem_Cfg_GetPrimaryEntry_18()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry18] */
  /*    19 */ &Dem_Cfg_GetPrimaryEntry_19()                            /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [Dem_PrimaryEntry19] */
  /*    20 */ &Dem_Cfg_GetReadoutBuffer(0).ReadOutBufferData[0].Data   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_Cfg_ReadoutBuffer[0].ReadOutBufferData[0].Data] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_Cfg_MemoryEntryInit = { 0 };  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_TimeSeriesEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_TimeSeriesEntryType, DEM_CONST) Dem_Cfg_TimeSeriesEntryInit = { 0 };  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_AdminData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_AdminData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDTCTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDTCTable
  \brief  size = DEM_CFG_NUMBER_OF_CLEARDTCS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_ClearDTC_DataType, DEM_VAR_NOINIT) Dem_Cfg_ClearDTCTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CommitBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_CommitBufferType, DEM_VAR_NOINIT) Dem_Cfg_CommitBuffer;  /* PRQA S 1514, 1533, 0759 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_MSR_Union */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DTCSelectorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DTCSelectorTable
  \brief  size = DEM_CFG_NUMBER_OF_DTCSELECTORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_DTCSelector_DataType, DEM_VAR_NOINIT) Dem_Cfg_DTCSelectorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionFulfilled
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionFulfilled
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition ID. Table value: current condition state 'FALSE' not fulfilled, 'TRUE' fulfilled.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionFulfilledType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionFulfilled[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupCounter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupCounter
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionGroupCounterType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupCounter[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#EnableConditionGroup_BatteryVoltage, __Internal_ControlDtcSetting, BatteryVoltag] */
  /*     2 */  /* [#EnableConditionGroup_BatteryVoltage2, __Internal_ControlDtcSetting, BatteryVoltag2] */
  /*     3 */  /* [#EnableConditionGroup_BatteryVoltage3, __Internal_ControlDtcSetting, BatteryVoltag3] */
  /*     4 */  /* [#EnableConditionGroup_BatteryVoltage4, __Internal_ControlDtcSetting, BatteryVoltag4] */
  /*     5 */  /* [#EnableConditionGroup_IgnOn, __Internal_ControlDtcSetting, IgnOn] */
  /*     6 */  /* [#EnableConditionGroup_PowerModeOn, __Internal_ControlDtcSetting, PowerModeOn] */
  /*     7 */  /* [#EnableConditionGroup_VIPBatteryVoltage2AndIgnOn, __Internal_ControlDtcSetting, BatteryVoltag2, IgnOn] */
  /*     8 */  /* [#EnableConditionGroup_VIPBatteryVoltageAndIgnOn, __Internal_ControlDtcSetting, BatteryVoltag, IgnOn] */
  /*     9 */  /* [#EnableConditionGroup_Wakeup, __Internal_ControlDtcSetting, Wakeup] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupState
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupState
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EnableConditionGroupStateType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupState[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#EnableConditionGroup_BatteryVoltage, __Internal_ControlDtcSetting, BatteryVoltag] */
  /*     2 */  /* [#EnableConditionGroup_BatteryVoltage2, __Internal_ControlDtcSetting, BatteryVoltag2] */
  /*     3 */  /* [#EnableConditionGroup_BatteryVoltage3, __Internal_ControlDtcSetting, BatteryVoltag3] */
  /*     4 */  /* [#EnableConditionGroup_BatteryVoltage4, __Internal_ControlDtcSetting, BatteryVoltag4] */
  /*     5 */  /* [#EnableConditionGroup_IgnOn, __Internal_ControlDtcSetting, IgnOn] */
  /*     6 */  /* [#EnableConditionGroup_PowerModeOn, __Internal_ControlDtcSetting, PowerModeOn] */
  /*     7 */  /* [#EnableConditionGroup_VIPBatteryVoltage2AndIgnOn, __Internal_ControlDtcSetting, BatteryVoltag2, IgnOn] */
  /*     8 */  /* [#EnableConditionGroup_VIPBatteryVoltageAndIgnOn, __Internal_ControlDtcSetting, BatteryVoltag, IgnOn] */
  /*     9 */  /* [#EnableConditionGroup_Wakeup, __Internal_ControlDtcSetting, Wakeup] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventDebounceValue
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventDebounceValue
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EventDebounceValueType, DEM_VAR_NOINIT) Dem_Cfg_EventDebounceValue[225];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [#EVENT_INVALID, Satellite#0] */
  /*     1 */  /* [A2B_open_Circuit_Open, Satellite#0] */
  /*     2 */  /* [A2B_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*     3 */  /* [A2B_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*     4 */  /* [ControlModuleCANBus_off_Bus_off, Satellite#0] */
  /*     5 */  /* [Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect, Satellite#0] */
  /*     6 */  /* [Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery, Satellite#0] */
  /*     7 */  /* [Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*     8 */  /* [Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*     9 */  /* [Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*    10 */  /* [Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*    11 */  /* [INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open, Satellite#0] */
  /*    12 */  /* [INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure, Satellite#0] */
  /*    13 */  /* [INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range, Satellite#0] */
  /*    14 */  /* [INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  /*    15 */  /* [INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  /*    16 */  /* [INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    17 */  /* [INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    18 */  /* [INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure, Satellite#0] */
  /*    19 */  /* [INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure, Satellite#0] */
  /*    20 */  /* [INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    21 */  /* [INVALID_SHORTNAME_Over_Temperature_Over_Temperature, Satellite#0] */
  /*    22 */  /* [IP_Display_ASIC_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    23 */  /* [HVAC_Display_OverVoltage, Satellite#0] */
  /*    24 */  /* [HVAC_Display_LowVoltage, Satellite#0] */
  /*    25 */  /* [HVAC_Display_NotReceiveBacklightValue, Satellite#0] */
  /*    26 */  /* [HVAC_Display_BacklightModuleError, Satellite#0] */
  /*    27 */  /* [HVAC_Display_TFT_Failure, Satellite#0] */
  /*    28 */  /* [HVAC_Display_VideoSignalConnectFailure, Satellite#0] */
  /*    29 */  /* [HVAC_Display_TouchPanelFailure, Satellite#0] */
  /*    30 */  /* [HVAC_Display_VibratorFailure, Satellite#0] */
  /*    31 */  /* [HVAC_Display_ForceInductionFailure, Satellite#0] */
  /*    32 */  /* [IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure, Satellite#0] */
  /*    33 */  /* [IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  /*    34 */  /* [IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  /*    35 */  /* [IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    36 */  /* [IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure, Satellite#0] */
  /*    37 */  /* [IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    38 */  /* [Lost_TCP_communication_Missing_Message, Satellite#0] */
  /*    39 */  /* [Lost_communication_with_AVM_Missing_Message, Satellite#0] */
  /*    40 */  /* [Lost_communication_with_IP_Display_Front_Missing_Message, Satellite#0] */
  /*    41 */  /* [Lost_communication_with_IVI_Display_Front_Missing_Message, Satellite#0] */
  /*    42 */  /* [Lost_communication_with_InCarCamera, Satellite#0] */
  /*    43 */  /* [Lost_communication_with_ConsoleDisplay, Satellite#0] */
  /*    44 */  /* [Lost_communication_with_RVC_Missing_Message, Satellite#0] */
  /*    45 */  /* [Lost_communication_with_PassengerDisplay, Satellite#0] */
  /*    46 */  /* [Lost_communication_with_W_HUD_Missing_Message, Satellite#0] */
  /*    47 */  /* [Lost_communication_with_DMS, Satellite#0] */
  /*    48 */  /* [Mic_1_open_Circuit_Open, Satellite#0] */
  /*    49 */  /* [Lost_communication_with_DVR, Satellite#0] */
  /* Index        Referable Keys */
  /*    50 */  /* [Mic_1_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*    51 */  /* [Mic_1_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*    52 */  /* [Mic_2_open_Circuit_Open, Satellite#0] */
  /*    53 */  /* [Mic_2_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*    54 */  /* [Mic_2_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*    55 */  /* [Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Satellite#0] */
  /*    56 */  /* [Missing_Airbag_Module_Missing_Message, Satellite#0] */
  /*    57 */  /* [Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Satellite#0] */
  /*    58 */  /* [Missing_Combination_Switch_Assembly_Missing_Message, Satellite#0] */
  /*    59 */  /* [Missing_Controler_Headlamp_Missing_Message, Satellite#0] */
  /*    60 */  /* [Missing_Controller_Pedal_Missing_Message, Satellite#0] */
  /*    61 */  /* [Missing_Driver_Door_Control_Module_Missing_Message, Satellite#0] */
  /*    62 */  /* [Missing_Elec_Region_Control_System_Body_Missing_Message, Satellite#0] */
  /*    63 */  /* [Missing_Electric_Power_Steering_system_Missing_Message, Satellite#0] */
  /*    64 */  /* [Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Satellite#0] */
  /*    65 */  /* [Missing_Electronic_Gerodisc_Missing_Message, Satellite#0] */
  /*    66 */  /* [Missing_Engine_Control_Module_Missing_Message, Satellite#0] */
  /*    67 */  /* [Missing_Front_Power_Box_Missing_Message, Satellite#0] */
  /*    68 */  /* [Missing_Gateway_Missing_Message, Satellite#0] */
  /*    69 */  /* [Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Satellite#0] */
  /*    70 */  /* [Missing_Nextrac_Torque_On_Demand_Missing_Message, Satellite#0] */
  /*    71 */  /* [Missing_Rear_Power_Box_Missing_Message, Satellite#0] */
  /*    72 */  /* [Missing_Screen_touch_button_switch_controller_Missing_Message, Satellite#0] */
  /*    73 */  /* [Missing_Transmission_Control_Until_PTCAN_Missing_Message, Satellite#0] */
  /*    74 */  /* [Missing_Wireless_Power_Charger_Missing_Message, Satellite#0] */
  /*    75 */  /* [Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  /*    76 */  /* [SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved, Satellite#0] */
  /*    77 */  /* [SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure, Satellite#0] */
  /*    78 */  /* [SecOC_TBoxSecOcFailure, Satellite#0] */
  /*    79 */  /* [SecOC_software_module_running_error_Unexpected_Operation, Satellite#0] */
  /*    80 */  /* [Speaker_Center_open_Circuit_Open, Satellite#0] */
  /*    81 */  /* [SecOC_GWSecOcFailure, Satellite#0] */
  /*    82 */  /* [Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*    83 */  /* [Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*    84 */  /* [Speaker_Center_short_across_General_Electrical_Failure, Satellite#0] */
  /*    85 */  /* [Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*    86 */  /* [Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*    87 */  /* [Speaker_FL_open_Circuit_Open, Satellite#0] */
  /*    88 */  /* [Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*    89 */  /* [Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*    90 */  /* [Speaker_FL_short_across_General_Electrical_Failure, Satellite#0] */
  /*    91 */  /* [Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*    92 */  /* [Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*    93 */  /* [Speaker_FR_open_Circuit_Open, Satellite#0] */
  /*    94 */  /* [Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*    95 */  /* [Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*    96 */  /* [Speaker_FR_short_across_General_Electrical_Failure, Satellite#0] */
  /*    97 */  /* [Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*    98 */  /* [Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*    99 */  /* [Speaker_RL_open_Circuit_Open, Satellite#0] */
  /* Index        Referable Keys */
  /*   100 */  /* [Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*   101 */  /* [Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*   102 */  /* [Speaker_RL_short_across_General_Electrical_Failure, Satellite#0] */
  /*   103 */  /* [Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*   104 */  /* [Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*   105 */  /* [Speaker_RR_open_Circuit_Open, Satellite#0] */
  /*   106 */  /* [Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*   107 */  /* [Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*   108 */  /* [Speaker_RR_short_across_General_Electrical_Failure, Satellite#0] */
  /*   109 */  /* [Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*   110 */  /* [Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*   111 */  /* [Speaker_Woofer_open_Circuit_Open, Satellite#0] */
  /*   112 */  /* [Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*   113 */  /* [Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*   114 */  /* [Speaker_Woofer_short_across_General_Electrical_Failure, Satellite#0] */
  /*   115 */  /* [Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*   116 */  /* [Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*   117 */  /* [Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure, Satellite#0] */
  /*   118 */  /* [TUNER_FM1_open_Circuit_Open, Satellite#0] */
  /*   119 */  /* [TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold, Satellite#0] */
  /*   120 */  /* [TUNER_FM1_short_to_battary_Circuit_Short_To_Battery, Satellite#0] */
  /*   121 */  /* [TUNER_FM1_short_to_groud_Circuit_Short_To_Ground, Satellite#0] */
  /*   122 */  /* [TUNER_FM2_open_Circuit_Open, Satellite#0] */
  /*   123 */  /* [TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold, Satellite#0] */
  /*   124 */  /* [TUNER_FM2_short_to_battary_Circuit_Short_To_Battery, Satellite#0] */
  /*   125 */  /* [TUNER_FM2_short_to_groud_Circuit_Short_To_Ground, Satellite#0] */
  /*   126 */  /* [Under_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  /*   127 */  /* [missing_Driver_Monitoring_System_Missing_Message, Satellite#0] */
  /*   128 */  /* [missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, Satellite#0] */
  /*   129 */  /* [missing_Parking_Assistance_System_Missing_Message, Satellite#0] */
  /*   130 */  /* [missing_Passenger_Door_Control_Module_Missing_Message, Satellite#0] */
  /*   131 */  /* [missing_Right_Rear_Side_Detection_System_Missing_Message, Satellite#0] */
  /*   132 */  /* [missing_Telematics_control_Box_Missing_Message, Satellite#0] */
  /*   133 */  /* [missing_Trailer_Missing_Message, Satellite#0] */
  /*   134 */  /* [missing_Tyre_Pressure_Monitoring_Systems_Missing_Message, Satellite#0] */
  /*   135 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*   136 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   137 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE, Satellite#0] */
  /*   138 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE, Satellite#0] */
  /*   139 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE, Satellite#0] */
  /*   140 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE, Satellite#0] */
  /*   141 */  /* [AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*   142 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE, Satellite#0] */
  /*   143 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE, Satellite#0] */
  /*   144 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   145 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED, Satellite#0] */
  /*   146 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE, Satellite#0] */
  /*   147 */  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   148 */  /* [AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core, Satellite#0] */
  /*   149 */  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED, Satellite#0] */
  /* Index        Referable Keys */
  /*   150 */  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE, Satellite#0] */
  /*   151 */  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   152 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED, Satellite#0] */
  /*   153 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE, Satellite#0] */
  /*   154 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE, Satellite#0] */
  /*   155 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE, Satellite#0] */
  /*   156 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE, Satellite#0] */
  /*   157 */  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE, Satellite#0] */
  /*   158 */  /* [Missing_Electric_Park_Brake_controller, Satellite#0] */
  /*   159 */  /* [MissingBattery_Management_System, Satellite#0] */
  /*   160 */  /* [Missing_Driver_Seat_Memory_module, Satellite#0] */
  /*   161 */  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Satellite#0] */
  /*   162 */  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Satellite#0] */
  /*   163 */  /* [Missing_Ibooster, Satellite#0] */
  /*   164 */  /* [Missing_Intelligent_Driving_Controller_Level2, Satellite#0] */
  /*   165 */  /* [Missing_Onboard_charger, Satellite#0] */
  /*   166 */  /* [Missing_Power_Lift_Gate_module, Satellite#0] */
  /*   167 */  /* [Missing_PrePretensioner_Mechatronic_Integrated, Satellite#0] */
  /*   168 */  /* [Missing_Rear_Heat_Vent_Seat_Module, Satellite#0] */
  /*   169 */  /* [Missing_Right_Headlamp_Control_Module, Satellite#0] */
  /*   170 */  /* [Missing_Seat_Control_Module, Satellite#0] */
  /*   171 */  /* [missing_Adaptive_Cruise_Control_system_Radar_Control_Module, Satellite#0] */
  /*   172 */  /* [FactoryModeNotClosed, Satellite#0] */
  /*   173 */  /* [missing_Right_Corner_Radar, Satellite#0] */
  /*   174 */  /* [LostComWithAVMFrontCamera, Satellite#0] */
  /*   175 */  /* [LostComWithAVMRearCamera, Satellite#0] */
  /*   176 */  /* [LostComWithAVMLeftCamera, Satellite#0] */
  /*   177 */  /* [LostComWithAVMRightCamera, Satellite#0] */
  /*   178 */  /* [Read_ClusterScreenIDFailed, Satellite#0] */
  /*   179 */  /* [ScreenClusterDriverErr, Satellite#0] */
  /*   180 */  /* [Read_IVIScreen_IDFailed, Satellite#0] */
  /*   181 */  /* [ScreenIVIDriverErr, Satellite#0] */
  /*   182 */  /* [RVC_CameraShortToGround, Satellite#0] */
  /*   183 */  /* [Read_CPScreen_IDFailed, Satellite#0] */
  /*   184 */  /* [RVC_CamerShortToBattery, Satellite#0] */
  /*   185 */  /* [ScreenCPDriverErr, Satellite#0] */
  /*   186 */  /* [RVC_CameraOpenCircuit, Satellite#0] */
  /*   187 */  /* [Read_CoDriverScreenIDFailed, Satellite#0] */
  /*   188 */  /* [ScreenCoDriverErr, Satellite#0] */
  /*   189 */  /* [AVM_CamerShortToBattery, Satellite#0] */
  /*   190 */  /* [Read_HUDScreen_IDFailed, Satellite#0] */
  /*   191 */  /* [AVM_CamerShortToGround, Satellite#0] */
  /*   192 */  /* [ScreenHUDDriverErr, Satellite#0] */
  /*   193 */  /* [AVM_CamerOpenCircuit, Satellite#0] */
  /*   194 */  /* [Temperature_SensorError, Satellite#0] */
  /*   195 */  /* [Internal_DMS_CameraShortToGround, Satellite#0] */
  /*   196 */  /* [Speaker_AVAS_ShortAcross, Satellite#0] */
  /*   197 */  /* [Internal_DVR_CameraShortToGround, Satellite#0] */
  /*   198 */  /* [Speaker_AVAS_ShortToGround, Satellite#0] */
  /*   199 */  /* [Internal_OMS_CameraShortToGround, Satellite#0] */
  /* Index        Referable Keys */
  /*   200 */  /* [Speaker_AVAS_ShortToBattery, Satellite#0] */
  /*   201 */  /* [Internal_DMS_CameraShortToBattery, Satellite#0] */
  /*   202 */  /* [Speaker_AVAS_CircuitOpen, Satellite#0] */
  /*   203 */  /* [Internal_DVR_CameraShortToBattery, Satellite#0] */
  /*   204 */  /* [Speaker_AVAS_ResistanceOutOfRange, Satellite#0] */
  /*   205 */  /* [Internal_OMS_CameraShortToBattery, Satellite#0] */
  /*   206 */  /* [Speaker_AVAS_WaveformLackFidelity, Satellite#0] */
  /*   207 */  /* [Internal_DMS_CameraCircuitOpen, Satellite#0] */
  /*   208 */  /* [Internal_DVR_CameraCircuitOpen, Satellite#0] */
  /*   209 */  /* [Internal_OMS_CameraCircuitOpen, Satellite#0] */
  /*   210 */  /* [GPS_AntennaOpen, Satellite#0] */
  /*   211 */  /* [GPS_AntennaShortToGround, Satellite#0] */
  /*   212 */  /* [GPS_AntennaShortToBattery, Satellite#0] */
  /*   213 */  /* [GPS_OverCurrent, Satellite#0] */
  /*   214 */  /* [SVC_CameraShortToGround, Satellite#0] */
  /*   215 */  /* [SVC_CameraShortToBattery, Satellite#0] */
  /*   216 */  /* [SVC_CameraOpen, Satellite#0] */
  /*   217 */  /* [Lost_communication_with_SVC_Missing_Message, Satellite#0] */
  /*   218 */  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L2, Satellite#0] */
  /*   219 */  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L3, Satellite#0] */
  /*   220 */  /* [SecOC_Security_PDU_Verification_Failed_from_IFC, Satellite#0] */
  /*   221 */  /* [SecOC_Security_PDU_Verification_Failed_from_TCU, Satellite#0] */
  /*   222 */  /* [SecOC_Security_PDU_Verification_Failed_from_ESP, Satellite#0] */
  /*   223 */  /* [Lost_Communication_With_Depth_Of_Water_Detection_Module, Satellite#0] */
  /*   224 */  /* [AbnormalWakeupSleep, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventInternalStatus
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Event_InternalStatusType, DEM_VAR_NOINIT) Dem_Cfg_EventInternalStatus[225];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [#EVENT_INVALID, Satellite#0] */
  /*     1 */  /* [A2B_open_Circuit_Open, Satellite#0] */
  /*     2 */  /* [A2B_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*     3 */  /* [A2B_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*     4 */  /* [ControlModuleCANBus_off_Bus_off, Satellite#0] */
  /*     5 */  /* [Ethernet_CRC_Errors_Value_of_Signal_Protection_Calculation_Incorrect, Satellite#0] */
  /*     6 */  /* [Ethernet_signal_lines_short_circuit_Circuit_Short_To_Battery, Satellite#0] */
  /*     7 */  /* [Fuel_sensor1_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*     8 */  /* [Fuel_sensor1_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*     9 */  /* [Fuel_sensor2_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*    10 */  /* [Fuel_sensor2_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*    11 */  /* [INVALID_SHORTNAME_GW_Ethernet_signal_lines_open_circuit_Circuit_Open, Satellite#0] */
  /*    12 */  /* [INVALID_SHORTNAME_GW_Ethernet_unexpected_Link_Loss_Bus_Signal_Message_Failure, Satellite#0] */
  /*    13 */  /* [INVALID_SHORTNAME_GW_Insufficient_SQI_Signal_Below_Allowable_Range, Satellite#0] */
  /*    14 */  /* [INVALID_SHORTNAME_HUT_Display_Low_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  /*    15 */  /* [INVALID_SHORTNAME_HUT_Display_Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  /*    16 */  /* [INVALID_SHORTNAME_HUT_Display_TFT_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    17 */  /* [INVALID_SHORTNAME_HUT_Display_Touch_Panel_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    18 */  /* [INVALID_SHORTNAME_HUT_Display_backlight_module_status_Internal_Electronic_Failure, Satellite#0] */
  /*    19 */  /* [INVALID_SHORTNAME_HUT_Display_not_received_backlight_value_Bus_Signal_Message_Failure, Satellite#0] */
  /*    20 */  /* [INVALID_SHORTNAME_HUT_Display_video_signal_connect_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    21 */  /* [INVALID_SHORTNAME_Over_Temperature_Over_Temperature, Satellite#0] */
  /*    22 */  /* [IP_Display_ASIC_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    23 */  /* [HVAC_Display_OverVoltage, Satellite#0] */
  /*    24 */  /* [HVAC_Display_LowVoltage, Satellite#0] */
  /*    25 */  /* [HVAC_Display_NotReceiveBacklightValue, Satellite#0] */
  /*    26 */  /* [HVAC_Display_BacklightModuleError, Satellite#0] */
  /*    27 */  /* [HVAC_Display_TFT_Failure, Satellite#0] */
  /*    28 */  /* [HVAC_Display_VideoSignalConnectFailure, Satellite#0] */
  /*    29 */  /* [HVAC_Display_TouchPanelFailure, Satellite#0] */
  /*    30 */  /* [HVAC_Display_VibratorFailure, Satellite#0] */
  /*    31 */  /* [HVAC_Display_ForceInductionFailure, Satellite#0] */
  /*    32 */  /* [IP_Display_ICD_Dimming_module_status_Internal_Electronic_Failure, Satellite#0] */
  /*    33 */  /* [IP_Display_ICD_Low_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  /*    34 */  /* [IP_Display_ICD_Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  /*    35 */  /* [IP_Display_ICD_screen_IC_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    36 */  /* [IP_Display_IIC_communication_failure_Bus_Signal_Message_Failure, Satellite#0] */
  /*    37 */  /* [IP_Display_PRNDM_Telltale_failure_Internal_Electronic_Failure, Satellite#0] */
  /*    38 */  /* [Lost_TCP_communication_Missing_Message, Satellite#0] */
  /*    39 */  /* [Lost_communication_with_AVM_Missing_Message, Satellite#0] */
  /*    40 */  /* [Lost_communication_with_IP_Display_Front_Missing_Message, Satellite#0] */
  /*    41 */  /* [Lost_communication_with_IVI_Display_Front_Missing_Message, Satellite#0] */
  /*    42 */  /* [Lost_communication_with_InCarCamera, Satellite#0] */
  /*    43 */  /* [Lost_communication_with_ConsoleDisplay, Satellite#0] */
  /*    44 */  /* [Lost_communication_with_RVC_Missing_Message, Satellite#0] */
  /*    45 */  /* [Lost_communication_with_PassengerDisplay, Satellite#0] */
  /*    46 */  /* [Lost_communication_with_W_HUD_Missing_Message, Satellite#0] */
  /*    47 */  /* [Lost_communication_with_DMS, Satellite#0] */
  /*    48 */  /* [Mic_1_open_Circuit_Open, Satellite#0] */
  /*    49 */  /* [Lost_communication_with_DVR, Satellite#0] */
  /* Index        Referable Keys */
  /*    50 */  /* [Mic_1_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*    51 */  /* [Mic_1_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*    52 */  /* [Mic_2_open_Circuit_Open, Satellite#0] */
  /*    53 */  /* [Mic_2_short_to_BAT_Circuit_Short_To_Battery, Satellite#0] */
  /*    54 */  /* [Mic_2_short_to_GND_Circuit_Short_To_Ground, Satellite#0] */
  /*    55 */  /* [Missing_AC_Air_Condition_Rear_Front_Control_panel_Missing_Message, Satellite#0] */
  /*    56 */  /* [Missing_Airbag_Module_Missing_Message, Satellite#0] */
  /*    57 */  /* [Missing_Around_View_Monitoring_system_Highly_Automatic_Parking_Integration_Park_Assistant_System_Missing_Message, Satellite#0] */
  /*    58 */  /* [Missing_Combination_Switch_Assembly_Missing_Message, Satellite#0] */
  /*    59 */  /* [Missing_Controler_Headlamp_Missing_Message, Satellite#0] */
  /*    60 */  /* [Missing_Controller_Pedal_Missing_Message, Satellite#0] */
  /*    61 */  /* [Missing_Driver_Door_Control_Module_Missing_Message, Satellite#0] */
  /*    62 */  /* [Missing_Elec_Region_Control_System_Body_Missing_Message, Satellite#0] */
  /*    63 */  /* [Missing_Electric_Power_Steering_system_Missing_Message, Satellite#0] */
  /*    64 */  /* [Missing_Electrical_Stable_Program_Antilock_Brake_System_Missing_Message, Satellite#0] */
  /*    65 */  /* [Missing_Electronic_Gerodisc_Missing_Message, Satellite#0] */
  /*    66 */  /* [Missing_Engine_Control_Module_Missing_Message, Satellite#0] */
  /*    67 */  /* [Missing_Front_Power_Box_Missing_Message, Satellite#0] */
  /*    68 */  /* [Missing_Gateway_Missing_Message, Satellite#0] */
  /*    69 */  /* [Missing_Head_Up_Display_Augmented_Reality_Head_Up_Display_Missing_Message, Satellite#0] */
  /*    70 */  /* [Missing_Nextrac_Torque_On_Demand_Missing_Message, Satellite#0] */
  /*    71 */  /* [Missing_Rear_Power_Box_Missing_Message, Satellite#0] */
  /*    72 */  /* [Missing_Screen_touch_button_switch_controller_Missing_Message, Satellite#0] */
  /*    73 */  /* [Missing_Transmission_Control_Until_PTCAN_Missing_Message, Satellite#0] */
  /*    74 */  /* [Missing_Wireless_Power_Charger_Missing_Message, Satellite#0] */
  /*    75 */  /* [Over_voltage_Circuit_Voltage_Above_Threshold, Satellite#0] */
  /*    76 */  /* [SecOC_FV_synchronization_authentication_message_failed_ISO_SAE_Reserved, Satellite#0] */
  /*    77 */  /* [SecOC_key_storage_exception_Calibration_Parameter_Memory_Failure, Satellite#0] */
  /*    78 */  /* [SecOC_TBoxSecOcFailure, Satellite#0] */
  /*    79 */  /* [SecOC_software_module_running_error_Unexpected_Operation, Satellite#0] */
  /*    80 */  /* [Speaker_Center_open_Circuit_Open, Satellite#0] */
  /*    81 */  /* [SecOC_GWSecOcFailure, Satellite#0] */
  /*    82 */  /* [Speaker_Center_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*    83 */  /* [Speaker_Center_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*    84 */  /* [Speaker_Center_short_across_General_Electrical_Failure, Satellite#0] */
  /*    85 */  /* [Speaker_Center_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*    86 */  /* [Speaker_Center_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*    87 */  /* [Speaker_FL_open_Circuit_Open, Satellite#0] */
  /*    88 */  /* [Speaker_FL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*    89 */  /* [Speaker_FL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*    90 */  /* [Speaker_FL_short_across_General_Electrical_Failure, Satellite#0] */
  /*    91 */  /* [Speaker_FL_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*    92 */  /* [Speaker_FL_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*    93 */  /* [Speaker_FR_open_Circuit_Open, Satellite#0] */
  /*    94 */  /* [Speaker_FR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*    95 */  /* [Speaker_FR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*    96 */  /* [Speaker_FR_short_across_General_Electrical_Failure, Satellite#0] */
  /*    97 */  /* [Speaker_FR_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*    98 */  /* [Speaker_FR_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*    99 */  /* [Speaker_RL_open_Circuit_Open, Satellite#0] */
  /* Index        Referable Keys */
  /*   100 */  /* [Speaker_RL_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*   101 */  /* [Speaker_RL_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*   102 */  /* [Speaker_RL_short_across_General_Electrical_Failure, Satellite#0] */
  /*   103 */  /* [Speaker_RL_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*   104 */  /* [Speaker_RL_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*   105 */  /* [Speaker_RR_open_Circuit_Open, Satellite#0] */
  /*   106 */  /* [Speaker_RR_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*   107 */  /* [Speaker_RR_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*   108 */  /* [Speaker_RR_short_across_General_Electrical_Failure, Satellite#0] */
  /*   109 */  /* [Speaker_RR_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*   110 */  /* [Speaker_RR_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*   111 */  /* [Speaker_Woofer_open_Circuit_Open, Satellite#0] */
  /*   112 */  /* [Speaker_Woofer_output_waveform_lack_fidelity_Signal_Shape_Waveform_Failure, Satellite#0] */
  /*   113 */  /* [Speaker_Woofer_resistance_out_of_range_Circuit_Resistance_Out_of_Range, Satellite#0] */
  /*   114 */  /* [Speaker_Woofer_short_across_General_Electrical_Failure, Satellite#0] */
  /*   115 */  /* [Speaker_Woofer_short_to_battery_Circuit_Short_To_Battery, Satellite#0] */
  /*   116 */  /* [Speaker_Woofer_short_to_ground_Circuit_Short_To_Ground, Satellite#0] */
  /*   117 */  /* [Synchronization_counter_data_NVM_erasure_failed_Calibration_Parameter_Memory_Failure, Satellite#0] */
  /*   118 */  /* [TUNER_FM1_open_Circuit_Open, Satellite#0] */
  /*   119 */  /* [TUNER_FM1_over_current_detection_Circuit_Current_Above_Threshold, Satellite#0] */
  /*   120 */  /* [TUNER_FM1_short_to_battary_Circuit_Short_To_Battery, Satellite#0] */
  /*   121 */  /* [TUNER_FM1_short_to_groud_Circuit_Short_To_Ground, Satellite#0] */
  /*   122 */  /* [TUNER_FM2_open_Circuit_Open, Satellite#0] */
  /*   123 */  /* [TUNER_FM2_over_current_detection_Circuit_Current_Above_Threshold, Satellite#0] */
  /*   124 */  /* [TUNER_FM2_short_to_battary_Circuit_Short_To_Battery, Satellite#0] */
  /*   125 */  /* [TUNER_FM2_short_to_groud_Circuit_Short_To_Ground, Satellite#0] */
  /*   126 */  /* [Under_voltage_Circuit_Voltage_Below_Threshold, Satellite#0] */
  /*   127 */  /* [missing_Driver_Monitoring_System_Missing_Message, Satellite#0] */
  /*   128 */  /* [missing_Intelligent_Forward_View_Camera_Lane_Detection_Warning_system_Intelligent_Forward_Camera_Missing_Message, Satellite#0] */
  /*   129 */  /* [missing_Parking_Assistance_System_Missing_Message, Satellite#0] */
  /*   130 */  /* [missing_Passenger_Door_Control_Module_Missing_Message, Satellite#0] */
  /*   131 */  /* [missing_Right_Rear_Side_Detection_System_Missing_Message, Satellite#0] */
  /*   132 */  /* [missing_Telematics_control_Box_Missing_Message, Satellite#0] */
  /*   133 */  /* [missing_Trailer_Missing_Message, Satellite#0] */
  /*   134 */  /* [missing_Tyre_Pressure_Monitoring_Systems_Missing_Message, Satellite#0] */
  /*   135 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*   136 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   137 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_LVI_FAILURE, Satellite#0] */
  /*   138 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_INCONCISTENCY_RESF_FAILURE, Satellite#0] */
  /*   139 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CVM_SETTING_FAILURE, Satellite#0] */
  /*   140 */  /* [AutoCreatedDemEvent_McuDemEventParameterRefs_MCU_E_CLOCK_FAILURE, Satellite#0] */
  /*   141 */  /* [AutoCreatedDemEvent_PortDemEventParameterRefs_PORT_E_WRITE_TIMEOUT_FAILURE, Satellite#0] */
  /*   142 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMER_FAILURE, Satellite#0] */
  /*   143 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_DIAG_FAILURE, Satellite#0] */
  /*   144 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   145 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_REWRITE_FAILED, Satellite#0] */
  /*   146 */  /* [AutoCreatedDemEvent_PwmDemEventParameterRefs_PWM_E_TIMEOUT_FAILURE, Satellite#0] */
  /*   147 */  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   148 */  /* [AutoCreatedDemEvent_CortstDemEventParameterRefs_RAMTST_E_Core, Satellite#0] */
  /*   149 */  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_ECC_FAILED, Satellite#0] */
  /* Index        Referable Keys */
  /*   150 */  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_FLSTEST_FAILURE, Satellite#0] */
  /*   151 */  /* [AutoCreatedDemEvent_FlststDemEventParameterRefs_FLSTST_E_REG_WRITE_VERIFY, Satellite#0] */
  /*   152 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_ECC_FAILED, Satellite#0] */
  /*   153 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_MIAN_RAM_FAILURE, Satellite#0] */
  /*   154 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_PART_RAM_FAILURE, Satellite#0] */
  /*   155 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RAM_FAILURE, Satellite#0] */
  /*   156 */  /* [AutoCreatedDemEvent_RamtstDemEventParameterRefs_RAMTST_E_RUNFL_RAM_FAILURE, Satellite#0] */
  /*   157 */  /* [AutoCreatedDemEvent_GptDemEventParameterRefs_GPT_E_TIMEOUT_FAILURE, Satellite#0] */
  /*   158 */  /* [Missing_Electric_Park_Brake_controller, Satellite#0] */
  /*   159 */  /* [MissingBattery_Management_System, Satellite#0] */
  /*   160 */  /* [Missing_Driver_Seat_Memory_module, Satellite#0] */
  /*   161 */  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_HCCAN, Satellite#0] */
  /*   162 */  /* [Missing_Hybrid_Vehicle_Control_Unit_Vehicle_control_unit_PTCAN, Satellite#0] */
  /*   163 */  /* [Missing_Ibooster, Satellite#0] */
  /*   164 */  /* [Missing_Intelligent_Driving_Controller_Level2, Satellite#0] */
  /*   165 */  /* [Missing_Onboard_charger, Satellite#0] */
  /*   166 */  /* [Missing_Power_Lift_Gate_module, Satellite#0] */
  /*   167 */  /* [Missing_PrePretensioner_Mechatronic_Integrated, Satellite#0] */
  /*   168 */  /* [Missing_Rear_Heat_Vent_Seat_Module, Satellite#0] */
  /*   169 */  /* [Missing_Right_Headlamp_Control_Module, Satellite#0] */
  /*   170 */  /* [Missing_Seat_Control_Module, Satellite#0] */
  /*   171 */  /* [missing_Adaptive_Cruise_Control_system_Radar_Control_Module, Satellite#0] */
  /*   172 */  /* [FactoryModeNotClosed, Satellite#0] */
  /*   173 */  /* [missing_Right_Corner_Radar, Satellite#0] */
  /*   174 */  /* [LostComWithAVMFrontCamera, Satellite#0] */
  /*   175 */  /* [LostComWithAVMRearCamera, Satellite#0] */
  /*   176 */  /* [LostComWithAVMLeftCamera, Satellite#0] */
  /*   177 */  /* [LostComWithAVMRightCamera, Satellite#0] */
  /*   178 */  /* [Read_ClusterScreenIDFailed, Satellite#0] */
  /*   179 */  /* [ScreenClusterDriverErr, Satellite#0] */
  /*   180 */  /* [Read_IVIScreen_IDFailed, Satellite#0] */
  /*   181 */  /* [ScreenIVIDriverErr, Satellite#0] */
  /*   182 */  /* [RVC_CameraShortToGround, Satellite#0] */
  /*   183 */  /* [Read_CPScreen_IDFailed, Satellite#0] */
  /*   184 */  /* [RVC_CamerShortToBattery, Satellite#0] */
  /*   185 */  /* [ScreenCPDriverErr, Satellite#0] */
  /*   186 */  /* [RVC_CameraOpenCircuit, Satellite#0] */
  /*   187 */  /* [Read_CoDriverScreenIDFailed, Satellite#0] */
  /*   188 */  /* [ScreenCoDriverErr, Satellite#0] */
  /*   189 */  /* [AVM_CamerShortToBattery, Satellite#0] */
  /*   190 */  /* [Read_HUDScreen_IDFailed, Satellite#0] */
  /*   191 */  /* [AVM_CamerShortToGround, Satellite#0] */
  /*   192 */  /* [ScreenHUDDriverErr, Satellite#0] */
  /*   193 */  /* [AVM_CamerOpenCircuit, Satellite#0] */
  /*   194 */  /* [Temperature_SensorError, Satellite#0] */
  /*   195 */  /* [Internal_DMS_CameraShortToGround, Satellite#0] */
  /*   196 */  /* [Speaker_AVAS_ShortAcross, Satellite#0] */
  /*   197 */  /* [Internal_DVR_CameraShortToGround, Satellite#0] */
  /*   198 */  /* [Speaker_AVAS_ShortToGround, Satellite#0] */
  /*   199 */  /* [Internal_OMS_CameraShortToGround, Satellite#0] */
  /* Index        Referable Keys */
  /*   200 */  /* [Speaker_AVAS_ShortToBattery, Satellite#0] */
  /*   201 */  /* [Internal_DMS_CameraShortToBattery, Satellite#0] */
  /*   202 */  /* [Speaker_AVAS_CircuitOpen, Satellite#0] */
  /*   203 */  /* [Internal_DVR_CameraShortToBattery, Satellite#0] */
  /*   204 */  /* [Speaker_AVAS_ResistanceOutOfRange, Satellite#0] */
  /*   205 */  /* [Internal_OMS_CameraShortToBattery, Satellite#0] */
  /*   206 */  /* [Speaker_AVAS_WaveformLackFidelity, Satellite#0] */
  /*   207 */  /* [Internal_DMS_CameraCircuitOpen, Satellite#0] */
  /*   208 */  /* [Internal_DVR_CameraCircuitOpen, Satellite#0] */
  /*   209 */  /* [Internal_OMS_CameraCircuitOpen, Satellite#0] */
  /*   210 */  /* [GPS_AntennaOpen, Satellite#0] */
  /*   211 */  /* [GPS_AntennaShortToGround, Satellite#0] */
  /*   212 */  /* [GPS_AntennaShortToBattery, Satellite#0] */
  /*   213 */  /* [GPS_OverCurrent, Satellite#0] */
  /*   214 */  /* [SVC_CameraShortToGround, Satellite#0] */
  /*   215 */  /* [SVC_CameraShortToBattery, Satellite#0] */
  /*   216 */  /* [SVC_CameraOpen, Satellite#0] */
  /*   217 */  /* [Lost_communication_with_SVC_Missing_Message, Satellite#0] */
  /*   218 */  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L2, Satellite#0] */
  /*   219 */  /* [SecOC_Security_PDU_Verification_Failed_from_IDC_L3, Satellite#0] */
  /*   220 */  /* [SecOC_Security_PDU_Verification_Failed_from_IFC, Satellite#0] */
  /*   221 */  /* [SecOC_Security_PDU_Verification_Failed_from_TCU, Satellite#0] */
  /*   222 */  /* [SecOC_Security_PDU_Verification_Failed_from_ESP, Satellite#0] */
  /*   223 */  /* [Lost_Communication_With_Depth_Of_Water_Detection_Module, Satellite#0] */
  /*   224 */  /* [AbnormalWakeupSleep, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterInfoTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterInfoTable
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FilterData_InfoType, DEM_VAR_NOINIT) Dem_Cfg_FilterInfoTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterReportedEvents
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterReportedEvents
  \brief  size = ceiling( DEM_G_NUMBER_OF_EVENTS / 8 )
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FilterReportedEventsType, DEM_VAR_NOINIT) Dem_Cfg_FilterReportedEvents[29];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameIteratorTable
  \brief  size = DEM_CFG_NUMBER_OF_FREEZEFRAMEITERATORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FreezeFrameIterator_FilterType, DEM_VAR_NOINIT) Dem_Cfg_FreezeFrameIteratorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryCommitNumber
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryCommitNumber
  \brief  The array contains these items: Admin, Status, 20 * Primary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_MemoryCommitNumberType, DEM_VAR_NOINIT) Dem_Cfg_MemoryCommitNumber[22];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryStatus
  \brief  The array contains these items: Admin, Status, 20 * Primary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryStatusType, DEM_VAR_NOINIT) Dem_Cfg_MemoryStatus[22];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_PrimaryChronology
  \brief  size = DEM_CFG_GLOBAL_PRIMARY_SIZE
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryIndexType, DEM_VAR_NOINIT) Dem_Cfg_PrimaryChronology[20];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_0;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_1;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_10
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_10;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_11
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_11;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_12
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_12;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_13
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_13;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_14
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_14;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_15
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_15;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_16
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_16;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_17
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_17;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_18
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_18;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_19
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_19;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_2;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_3;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_4;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_5;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_6;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_7;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_8
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_8;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_9
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_9;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReadoutBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReadoutBufferEntryType, DEM_VAR_NOINIT) Dem_Cfg_ReadoutBuffer[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReportedEventsOfFilter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ReportedEventsOfFilter
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReportedEventsType, DEM_VAR_NOINIT) Dem_Cfg_ReportedEventsOfFilter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SatelliteInfo0
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_SatelliteInfo0
  \brief  Buffer for satellite data on OsApplication "0"
*/ 
#define DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_SatelliteInfoType0, DEM_VAR_ZERO_INIT) Dem_Cfg_SatelliteInfo0 = {0};  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StatusData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_StatusData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/



/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.c     [Vector, VARIANT-PRE-COMPILE, 19.00.00.118535]
**********************************************************************************************************************/

