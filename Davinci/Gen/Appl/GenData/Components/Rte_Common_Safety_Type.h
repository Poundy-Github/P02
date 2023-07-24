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
 *             File:  Rte_Common_Safety_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <Common_Safety>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMMON_SAFETY_TYPE_H
# define RTE_COMMON_SAFETY_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_Not_tirggered
#   define Cx0_Not_tirggered (0U)
#  endif

#  ifndef Cx1_AEB_JA_Function_Triggered_for_vehicle
#   define Cx1_AEB_JA_Function_Triggered_for_vehicle (1U)
#  endif

#  ifndef Cx2_AEB_JA_Function_Triggered_for_pedestrian
#   define Cx2_AEB_JA_Function_Triggered_for_pedestrian (2U)
#  endif

#  ifndef Cx3_reverse
#   define Cx3_reverse (3U)
#  endif

#  ifndef Cx0_No_display
#   define Cx0_No_display (0U)
#  endif

#  ifndef Cx1_error
#   define Cx1_error (1U)
#  endif

#  ifndef Cx2_FCWAEB_JA_temporarily_unavailable
#   define Cx2_FCWAEB_JA_temporarily_unavailable (2U)
#  endif

#  ifndef Cx3_FCWAEB_JA_Performance_degradation
#   define Cx3_FCWAEB_JA_Performance_degradation (3U)
#  endif

#  ifndef Cx0_No_warning
#   define Cx0_No_warning (0U)
#  endif

#  ifndef Cx1_Warning_for_vehicle
#   define Cx1_Warning_for_vehicle (1U)
#  endif

#  ifndef Cx2_Warning_for_pedestrian
#   define Cx2_Warning_for_pedestrian (2U)
#  endif

#  ifndef Cx0_No_failure
#   define Cx0_No_failure (0U)
#  endif

#  ifndef Cx1_Failure_when_AVH_is_on_need
#   define Cx1_Failure_when_AVH_is_on_need (1U)
#  endif

#  ifndef Cx2_Failure_when_is_not_on_need
#   define Cx2_Failure_when_is_not_on_need (2U)
#  endif

#  ifndef Cx3_Reserved
#   define Cx3_Reserved (3U)
#  endif

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_Standby
#   define Cx1_Standby (1U)
#  endif

#  ifndef Cx2_active
#   define Cx2_active (2U)
#  endif

#  ifndef Cx0_No_Error
#   define Cx0_No_Error (0U)
#  endif

#  ifndef Cx1_TM_power_unavailable
#   define Cx1_TM_power_unavailable (1U)
#  endif

#  ifndef Cx2_P2M_power_unavailable
#   define Cx2_P2M_power_unavailable (2U)
#  endif

#  ifndef Cx3_OBC_power_unavailable
#   define Cx3_OBC_power_unavailable (3U)
#  endif

#  ifndef Cx1_Warning
#   define Cx1_Warning (1U)
#  endif

#  ifndef Cx2_Derating
#   define Cx2_Derating (2U)
#  endif

#  ifndef Cx4_Reserved
#   define Cx4_Reserved (4U)
#  endif

#  ifndef Cx5_Error
#   define Cx5_Error (5U)
#  endif

#  ifndef Cx6_Reserved
#   define Cx6_Reserved (6U)
#  endif

#  ifndef Cx7_Emergency_Open
#   define Cx7_Emergency_Open (7U)
#  endif

#  ifndef Cx0_No_Display
#   define Cx0_No_Display (0U)
#  endif

#  ifndef Cx1_Speed_too_high_TransportCar_Wash_Mode_is_not_available
#   define Cx1_Speed_too_high_TransportCar_Wash_Mode_is_not_available (1U)
#  endif

#  ifndef Cx2_12V_battery_SOC_too_low_TransportCar_Wash_Mode_is_not_available
#   define Cx2_12V_battery_SOC_too_low_TransportCar_Wash_Mode_is_not_available (2U)
#  endif

#  ifndef Cx7_Reserved
#   define Cx7_Reserved (7U)
#  endif

#  ifndef Cx00_Valid_values
#   define Cx00_Valid_values (0U)
#  endif

#  ifndef CxFF_Valid_values
#   define CxFF_Valid_values (255U)
#  endif

#  ifndef Cx00_Valid_value
#   define Cx00_Valid_value (0U)
#  endif

#  ifndef CxFF_Valid_value
#   define CxFF_Valid_value (255U)
#  endif

#  ifndef Cx00_No_crash
#   define Cx00_No_crash (0U)
#  endif

#  ifndef Cx01_Reserved
#   define Cx01_Reserved (1U)
#  endif

#  ifndef Cx02_Front_First_level
#   define Cx02_Front_First_level (2U)
#  endif

#  ifndef Cx03_rear_crash_Reserved_
#   define Cx03_rear_crash_Reserved_ (3U)
#  endif

#  ifndef Cx04_Reserved
#   define Cx04_Reserved (4U)
#  endif

#  ifndef Cx07_Reserved
#   define Cx07_Reserved (7U)
#  endif

#  ifndef Cx08_Right_hand_side
#   define Cx08_Right_hand_side (8U)
#  endif

#  ifndef Cx09_Reserved
#   define Cx09_Reserved (9U)
#  endif

#  ifndef Cx0F_Reserved
#   define Cx0F_Reserved (15U)
#  endif

#  ifndef Cx10_Left_hand_side
#   define Cx10_Left_hand_side (16U)
#  endif

#  ifndef Cx11_Rollover_Reserved_
#   define Cx11_Rollover_Reserved_ (17U)
#  endif

#  ifndef Cx12_Static_Roll_Reserved_
#   define Cx12_Static_Roll_Reserved_ (18U)
#  endif

#  ifndef Cx13_Reserved
#   define Cx13_Reserved (19U)
#  endif

#  ifndef CxFF_Reserved
#   define CxFF_Reserved (255U)
#  endif

#  ifndef Cx1_Press_brake_and_Unlock_button_to_shift
#   define Cx1_Press_brake_and_Unlock_button_to_shift (1U)
#  endif

#  ifndef Cx2_Press_Unlock_button_to_shift
#   define Cx2_Press_Unlock_button_to_shift (2U)
#  endif

#  ifndef Cx3_Press_brake_to_shift
#   define Cx3_Press_brake_to_shift (3U)
#  endif

#  ifndef Cx0_Inactive
#   define Cx0_Inactive (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx2_Turn_Off
#   define Cx2_Turn_Off (2U)
#  endif

#  ifndef Cx3_Forbidden
#   define Cx3_Forbidden (3U)
#  endif

#  ifndef Cx4_Reserved_treat_as_0x0_inactive_
#   define Cx4_Reserved_treat_as_0x0_inactive_ (4U)
#  endif

#  ifndef Cx7_Reserved_treat_as_0x0_inactive_
#   define Cx7_Reserved_treat_as_0x0_inactive_ (7U)
#  endif

#  ifndef Cx1_Vehicle_speed_too_high_shift_not_allowed
#   define Cx1_Vehicle_speed_too_high_shift_not_allowed (1U)
#  endif

#  ifndef Cx2_Engage_P_not_allowed_due_to_high_vehicle_speed
#   define Cx2_Engage_P_not_allowed_due_to_high_vehicle_speed (2U)
#  endif

#  ifndef Cx3_Transmission_is_in_N_park_lock_is_not_locked
#   define Cx3_Transmission_is_in_N_park_lock_is_not_locked (3U)
#  endif

#  ifndef Cx0_No_Recommendation
#   define Cx0_No_Recommendation (0U)
#  endif

#  ifndef Cx1_Up_Shift
#   define Cx1_Up_Shift (1U)
#  endif

#  ifndef Cx2_Down_Shift
#   define Cx2_Down_Shift (2U)
#  endif

#  ifndef Cx00_Standard
#   define Cx00_Standard (0U)
#  endif

#  ifndef Cx01_Sport
#   define Cx01_Sport (1U)
#  endif

#  ifndef Cx02_Snow
#   define Cx02_Snow (2U)
#  endif

#  ifndef Cx03_Mud
#   define Cx03_Mud (3U)
#  endif

#  ifndef Cx04_Sand
#   define Cx04_Sand (4U)
#  endif

#  ifndef Cx05_4L_reserved_
#   define Cx05_4L_reserved_ (5U)
#  endif

#  ifndef Cx06_Economic
#   define Cx06_Economic (6U)
#  endif

#  ifndef Cx07_Mode_Unkown
#   define Cx07_Mode_Unkown (7U)
#  endif

#  ifndef Cx08_Reserved
#   define Cx08_Reserved (8U)
#  endif

#  ifndef Cx09_Sport_
#   define Cx09_Sport_ (9U)
#  endif

#  ifndef Cx0A_Off_road
#   define Cx0A_Off_road (10U)
#  endif

#  ifndef Cx0B_Standard_2H_reserved_
#   define Cx0B_Standard_2H_reserved_ (11U)
#  endif

#  ifndef Cx0C_Reserved
#   define Cx0C_Reserved (12U)
#  endif

#  ifndef Cx0D_Standard_4H_reserved_
#   define Cx0D_Standard_4H_reserved_ (13U)
#  endif

#  ifndef Cx0E_Failed
#   define Cx0E_Failed (14U)
#  endif

#  ifndef Cx0F_Invalid_Value
#   define Cx0F_Invalid_Value (15U)
#  endif

#  ifndef Cx10_Snow_4H_reserved_
#   define Cx10_Snow_4H_reserved_ (16U)
#  endif

#  ifndef Cx11_Normal_4L_reserved_
#   define Cx11_Normal_4L_reserved_ (17U)
#  endif

#  ifndef Cx12_Rock_4L_reserved_
#   define Cx12_Rock_4L_reserved_ (18U)
#  endif

#  ifndef Cx13_Pothle_4L_reserved_
#   define Cx13_Pothle_4L_reserved_ (19U)
#  endif

#  ifndef Cx14_MudSand_4L_reserved_
#   define Cx14_MudSand_4L_reserved_ (20U)
#  endif

#  ifndef Cx15_Mountain_4L_reserved_
#   define Cx15_Mountain_4L_reserved_ (21U)
#  endif

#  ifndef Cx16_reserved
#   define Cx16_reserved (22U)
#  endif

#  ifndef Cx1F_reserved
#   define Cx1F_reserved (31U)
#  endif

#  ifndef Cx00_No_Terrain_Control
#   define Cx00_No_Terrain_Control (0U)
#  endif

#  ifndef Cx01_Standard
#   define Cx01_Standard (1U)
#  endif

#  ifndef Cx02_Sport
#   define Cx02_Sport (2U)
#  endif

#  ifndef Cx03_Snow_Nex
#   define Cx03_Snow_Nex (3U)
#  endif

#  ifndef Cx05_Deep_Mud
#   define Cx05_Deep_Mud (5U)
#  endif

#  ifndef Cx06_Reserved
#   define Cx06_Reserved (6U)
#  endif

#  ifndef Cx07_Soft_sand
#   define Cx07_Soft_sand (7U)
#  endif

#  ifndef Cx09_4L_reserved_
#   define Cx09_4L_reserved_ (9U)
#  endif

#  ifndef Cx0A_Economic
#   define Cx0A_Economic (10U)
#  endif

#  ifndef Cx0B_Reserved
#   define Cx0B_Reserved (11U)
#  endif

#  ifndef Cx0C_Snow_TOD_reserved_
#   define Cx0C_Snow_TOD_reserved_ (12U)
#  endif

#  ifndef Cx0D_Off_road
#   define Cx0D_Off_road (13U)
#  endif

#  ifndef Cx0E_Sport_reserved_
#   define Cx0E_Sport_reserved_ (14U)
#  endif

#  ifndef Cx0F_nvalid_Value
#   define Cx0F_nvalid_Value (15U)
#  endif

#  ifndef Cx10_Standard_2H_reserved_
#   define Cx10_Standard_2H_reserved_ (16U)
#  endif

#  ifndef Cx11_Reserved
#   define Cx11_Reserved (17U)
#  endif

#  ifndef Cx12_Standard_4H_reserved_
#   define Cx12_Standard_4H_reserved_ (18U)
#  endif

#  ifndef Cx13_Snow_4H_reserved_
#   define Cx13_Snow_4H_reserved_ (19U)
#  endif

#  ifndef Cx14_Normal_4L_reserved_
#   define Cx14_Normal_4L_reserved_ (20U)
#  endif

#  ifndef Cx15_Rock_4L_reserved_
#   define Cx15_Rock_4L_reserved_ (21U)
#  endif

#  ifndef Cx16_Pothole_4L_reserved_
#   define Cx16_Pothole_4L_reserved_ (22U)
#  endif

#  ifndef Cx17_MudSand_4L_reserved_
#   define Cx17_MudSand_4L_reserved_ (23U)
#  endif

#  ifndef Cx18_Mountain_4L_reserved_
#   define Cx18_Mountain_4L_reserved_ (24U)
#  endif

#  ifndef Cx19_Reserved
#   define Cx19_Reserved (25U)
#  endif

#  ifndef Cx1F_Reserved
#   define Cx1F_Reserved (31U)
#  endif

#  ifndef Cx0_Neutral
#   define Cx0_Neutral (0U)
#  endif

#  ifndef Cx1_1st_Gear
#   define Cx1_1st_Gear (1U)
#  endif

#  ifndef Cx2_2nd_Gear
#   define Cx2_2nd_Gear (2U)
#  endif

#  ifndef Cx3_3rd_Gear
#   define Cx3_3rd_Gear (3U)
#  endif

#  ifndef Cx4_4th_Gear
#   define Cx4_4th_Gear (4U)
#  endif

#  ifndef Cx5_5th_Gear
#   define Cx5_5th_Gear (5U)
#  endif

#  ifndef Cx6_6th_Gear
#   define Cx6_6th_Gear (6U)
#  endif

#  ifndef Cx7_7th_Gear
#   define Cx7_7th_Gear (7U)
#  endif

#  ifndef Cx8_Reserved
#   define Cx8_Reserved (8U)
#  endif

#  ifndef CxF_Reserved
#   define CxF_Reserved (15U)
#  endif

#  ifndef Cx0_No_Message
#   define Cx0_No_Message (0U)
#  endif

#  ifndef Cx1_Transmission_Malfunction
#   define Cx1_Transmission_Malfunction (1U)
#  endif

#  ifndef Cx2_Transmission_P_engagement_fault
#   define Cx2_Transmission_P_engagement_fault (2U)
#  endif

#  ifndef Cx3_Transmission_P_disengagement_fault
#   define Cx3_Transmission_P_disengagement_fault (3U)
#  endif

#  ifndef Cx4_Please_press_the_brake_pedal_untill_the_P_gear_reference_is_completed
#   define Cx4_Please_press_the_brake_pedal_untill_the_P_gear_reference_is_completed (4U)
#  endif

#  ifndef Cx5_Reference_is_not_completed_please_shift_gears_after_reference_is_completed
#   define Cx5_Reference_is_not_completed_please_shift_gears_after_reference_is_completed (5U)
#  endif

#  ifndef Cx6_P_gear_reference_completed_please_released_the_brake_pedal
#   define Cx6_P_gear_reference_completed_please_released_the_brake_pedal (6U)
#  endif

#  ifndef CxE_Reserved
#   define CxE_Reserved (14U)
#  endif

#  ifndef CxF_Transmission_limit_function
#   define CxF_Transmission_limit_function (15U)
#  endif

#  ifndef Cx4_Authentication_failure
#   define Cx4_Authentication_failure (4U)
#  endif

#  ifndef Cx5_Reserved
#   define Cx5_Reserved (5U)
#  endif

#  ifndef CxF_transmission_limit_function
#   define CxF_transmission_limit_function (15U)
#  endif

#  ifndef Cx1_E_Gear
#   define Cx1_E_Gear (1U)
#  endif

#  ifndef Cx2_L_Gear
#   define Cx2_L_Gear (2U)
#  endif

#  ifndef Cx3_M_Gear
#   define Cx3_M_Gear (3U)
#  endif

#  ifndef Cx4_H_Gear
#   define Cx4_H_Gear (4U)
#  endif

#  ifndef Cx5_S_Gear
#   define Cx5_S_Gear (5U)
#  endif

#  ifndef Cx6_X_Gear
#   define Cx6_X_Gear (6U)
#  endif

#  ifndef Cx0_Blank_No_display
#   define Cx0_Blank_No_display (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  ifndef Cx2_Flashing
#   define Cx2_Flashing (2U)
#  endif

#  ifndef Cx3_Reserved_treat_as_BlankNo_display_
#   define Cx3_Reserved_treat_as_BlankNo_display_ (3U)
#  endif

#  ifndef Cx0_BlankNo_Display
#   define Cx0_BlankNo_Display (0U)
#  endif

#  ifndef Cx3_Reserved_treat_as_BlankNo_Display_
#   define Cx3_Reserved_treat_as_BlankNo_Display_ (3U)
#  endif

#  ifndef Cx0_P
#   define Cx0_P (0U)
#  endif

#  ifndef Cx1_R
#   define Cx1_R (1U)
#  endif

#  ifndef Cx2_N
#   define Cx2_N (2U)
#  endif

#  ifndef Cx3_D
#   define Cx3_D (3U)
#  endif

#  ifndef Cx4_M
#   define Cx4_M (4U)
#  endif

#  ifndef Cx0_Lamp_off
#   define Cx0_Lamp_off (0U)
#  endif

#  ifndef Cx1_Lamp_on
#   define Cx1_Lamp_on (1U)
#  endif

#  ifndef Cx2_Reserved
#   define Cx2_Reserved (2U)
#  endif

#  ifndef Cx3_Lamp_blink_sound_remind
#   define Cx3_Lamp_blink_sound_remind (3U)
#  endif

#  ifndef Cx0_No_Text
#   define Cx0_No_Text (0U)
#  endif

#  ifndef Cx1_PressBrake
#   define Cx1_PressBrake (1U)
#  endif

#  ifndef Cx2_TransToo_Hot
#   define Cx2_TransToo_Hot (2U)
#  endif

#  ifndef Cx0_Undefined
#   define Cx0_Undefined (0U)
#  endif

#  ifndef Cx1_No_Error
#   define Cx1_No_Error (1U)
#  endif

#  ifndef Cx2_Error
#   define Cx2_Error (2U)
#  endif

#  ifndef Cx3_Diagnosis
#   define Cx3_Diagnosis (3U)
#  endif

#  ifndef Cx2_Lamp_flash
#   define Cx2_Lamp_flash (2U)
#  endif

#  ifndef Cx0_Released
#   define Cx0_Released (0U)
#  endif

#  ifndef Cx1_Closed
#   define Cx1_Closed (1U)
#  endif

#  ifndef Cx2_In_progress
#   define Cx2_In_progress (2U)
#  endif

#  ifndef Cx3_unknown
#   define Cx3_unknown (3U)
#  endif

#  ifndef Cx1_Gradient_too_high
#   define Cx1_Gradient_too_high (1U)
#  endif

#  ifndef Cx2_Park_brake_force_not_enough
#   define Cx2_Park_brake_force_not_enough (2U)
#  endif

#  ifndef Cx3_Park_brake_system_overheated
#   define Cx3_Park_brake_system_overheated (3U)
#  endif

#  ifndef Cx4_Remind_driver_to_apply_safety_belt
#   define Cx4_Remind_driver_to_apply_safety_belt (4U)
#  endif

#  ifndef Cx5_Park_brake_maintenance_mode
#   define Cx5_Park_brake_maintenance_mode (5U)
#  endif

#  ifndef Cx6_Roller_bench_mode
#   define Cx6_Roller_bench_mode (6U)
#  endif

#  ifndef Cx7_Please_Release_EPB
#   define Cx7_Please_Release_EPB (7U)
#  endif

#  ifndef Cx8_Please_Release_Rear_ELD
#   define Cx8_Please_Release_Rear_ELD (8U)
#  endif

#  ifndef Cx9_Reserved
#   define Cx9_Reserved (9U)
#  endif

#  ifndef Cx0_No_fault
#   define Cx0_No_fault (0U)
#  endif

#  ifndef Cx1_Permanent_Error_Detected
#   define Cx1_Permanent_Error_Detected (1U)
#  endif

#  ifndef Cx2_Intermittent_Error_Detected
#   define Cx2_Intermittent_Error_Detected (2U)
#  endif

#  ifndef Cx0_Comfort_Mode
#   define Cx0_Comfort_Mode (0U)
#  endif

#  ifndef Cx1_sport_mode
#   define Cx1_sport_mode (1U)
#  endif

#  ifndef Cx2_Handiness_Mode
#   define Cx2_Handiness_Mode (2U)
#  endif

#  ifndef Cx2_FCWAEB_P_temporarily_unavailable
#   define Cx2_FCWAEB_P_temporarily_unavailable (2U)
#  endif

#  ifndef Cx3_FCWAEB_P_Performance_degradation
#   define Cx3_FCWAEB_P_Performance_degradation (3U)
#  endif

#  ifndef Cx2_FCWAEB_V_temporarily_unavailable
#   define Cx2_FCWAEB_V_temporarily_unavailable (2U)
#  endif

#  ifndef Cx3_FCWAEB_V_Performance_degradation
#   define Cx3_FCWAEB_V_Performance_degradation (3U)
#  endif

#  ifndef Cx0_Normal
#   define Cx0_Normal (0U)
#  endif

#  ifndef Cx1_High_sensitivity
#   define Cx1_High_sensitivity (1U)
#  endif

#  ifndef Cx2_Low_sensitivity
#   define Cx2_Low_sensitivity (2U)
#  endif

#  ifndef Cx1_Latent_warning
#   define Cx1_Latent_warning (1U)
#  endif

#  ifndef Cx2_warning_Level_1
#   define Cx2_warning_Level_1 (2U)
#  endif

#  ifndef Cx3_warning_Level_2
#   define Cx3_warning_Level_2 (3U)
#  endif

#  ifndef Cx0_Disable
#   define Cx0_Disable (0U)
#  endif

#  ifndef Cx1_Derating
#   define Cx1_Derating (1U)
#  endif

#  ifndef Cx2_Normal
#   define Cx2_Normal (2U)
#  endif

#  ifndef Cx3_Invalid
#   define Cx3_Invalid (3U)
#  endif

#  ifndef Cx1_Battery_temperature_is_low_power_may_decrease
#   define Cx1_Battery_temperature_is_low_power_may_decrease (1U)
#  endif

#  ifndef Cx2_Battery_temperature_is_high_power_may_decrease
#   define Cx2_Battery_temperature_is_high_power_may_decrease (2U)
#  endif

#  ifndef Cx0_Standard
#   define Cx0_Standard (0U)
#  endif

#  ifndef Cx1_Enhanced
#   define Cx1_Enhanced (1U)
#  endif

#  ifndef Cx2_Low
#   define Cx2_Low (2U)
#  endif

#  ifndef Cx3_Not_Available
#   define Cx3_Not_Available (3U)
#  endif

#  ifndef Cx0_No_action
#   define Cx0_No_action (0U)
#  endif

#  ifndef Cx1_Close_blower
#   define Cx1_Close_blower (1U)
#  endif

#  ifndef Cx2_Close_seat_heat
#   define Cx2_Close_seat_heat (2U)
#  endif

#  ifndef Cx3_Close_both_blower_and_seat_heat
#   define Cx3_Close_both_blower_and_seat_heat (3U)
#  endif

#  ifndef Cx00_Mode_0_Vehicle_standstill
#   define Cx00_Mode_0_Vehicle_standstill (0U)
#  endif

#  ifndef Cx01_Engine_running_and_BSG_is_a_conventional_generator
#   define Cx01_Engine_running_and_BSG_is_a_conventional_generator (1U)
#  endif

#  ifndef Cx02_Engine_Auto_stopped
#   define Cx02_Engine_Auto_stopped (2U)
#  endif

#  ifndef Cx03_Boost
#   define Cx03_Boost (3U)
#  endif

#  ifndef Cx04_Energy_Recovery
#   define Cx04_Energy_Recovery (4U)
#  endif

#  ifndef Cx05_E_Creep
#   define Cx05_E_Creep (5U)
#  endif

#  ifndef Cx06_pure_engine_drive
#   define Cx06_pure_engine_drive (6U)
#  endif

#  ifndef Cx00_Mode_1_Vehicle_standstill_engine_not_start
#   define Cx00_Mode_1_Vehicle_standstill_engine_not_start (0U)
#  endif

#  ifndef Cx01_mode_2_Vehicle_standstill_engine_start
#   define Cx01_mode_2_Vehicle_standstill_engine_start (1U)
#  endif

#  ifndef Cx02_mode_3_engine_idling_charging
#   define Cx02_mode_3_engine_idling_charging (2U)
#  endif

#  ifndef Cx03_mode_4_Pure_electricity_drive_T_Motor_
#   define Cx03_mode_4_Pure_electricity_drive_T_Motor_ (3U)
#  endif

#  ifndef Cx04_mode_5_Engine_direct_drive_battery_not_working_
#   define Cx04_mode_5_Engine_direct_drive_battery_not_working_ (4U)
#  endif

#  ifndef Cx05_mode_6_Series_drive_battery_not_working_T_Motor_
#   define Cx05_mode_6_Series_drive_battery_not_working_T_Motor_ (5U)
#  endif

#  ifndef Cx06_mode_7_Engine_direct_drive_battery_discharging_
#   define Cx06_mode_7_Engine_direct_drive_battery_discharging_ (6U)
#  endif

#  ifndef Cx07_mode_8_Series_drive_battery_discharging_
#   define Cx07_mode_8_Series_drive_battery_discharging_ (7U)
#  endif

#  ifndef Cx08_mode_9_Engine_direct_drive_battery_charging_
#   define Cx08_mode_9_Engine_direct_drive_battery_charging_ (8U)
#  endif

#  ifndef Cx09_mode_10_Series_drive_battery_charging_
#   define Cx09_mode_10_Series_drive_battery_charging_ (9U)
#  endif

#  ifndef Cx0A_mode_11_Energy_recovery_T_Motor_
#   define Cx0A_mode_11_Energy_recovery_T_Motor_ (10U)
#  endif

#  ifndef Cx0B_mode_12_T_Motor_Energy_recovery_T_Motor_Battery_charging
#   define Cx0B_mode_12_T_Motor_Energy_recovery_T_Motor_Battery_charging (11U)
#  endif

#  ifndef Cx0C_mode_13_Plug_in_warming
#   define Cx0C_mode_13_Plug_in_warming (12U)
#  endif

#  ifndef Cx0D_mode_14_Plug_in_charging_warming
#   define Cx0D_mode_14_Plug_in_charging_warming (13U)
#  endif

#  ifndef Cx0E_mode_15AC_charging
#   define Cx0E_mode_15AC_charging (14U)
#  endif

#  ifndef Cx0F_mode_16_DC_charging
#   define Cx0F_mode_16_DC_charging (15U)
#  endif

#  ifndef Cx10_Reserved
#   define Cx10_Reserved (16U)
#  endif

#  ifndef Cx3F_Reserved
#   define Cx3F_Reserved (63U)
#  endif

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx1_Yellow_Light_ON
#   define Cx1_Yellow_Light_ON (1U)
#  endif

#  ifndef Cx2_Red_Light_ON
#   define Cx2_Red_Light_ON (2U)
#  endif

#  ifndef Cx0_Default
#   define Cx0_Default (0U)
#  endif

#  ifndef Cx1_EV_not_available_due_to_low_battery_charge
#   define Cx1_EV_not_available_due_to_low_battery_charge (1U)
#  endif

#  ifndef Cx2_EV_not_available_due_to_temporary_hybrid_system_limitations
#   define Cx2_EV_not_available_due_to_temporary_hybrid_system_limitations (2U)
#  endif

#  ifndef Cx3_SAVE_not_available_due_to_temporary_hybrid_system_limitations
#   define Cx3_SAVE_not_available_due_to_temporary_hybrid_system_limitations (3U)
#  endif

#  ifndef Cx4_AWD_not_available_due_to_temporary_hybrid_system_limitations
#   define Cx4_AWD_not_available_due_to_temporary_hybrid_system_limitations (4U)
#  endif

#  ifndef Cx5_SPORT_not_available_due_to_temporary_hybrid_system_limitations
#   define Cx5_SPORT_not_available_due_to_temporary_hybrid_system_limitations (5U)
#  endif

#  ifndef Cx6_Manual_gear_change_drive_mode_goes_SPORT
#   define Cx6_Manual_gear_change_drive_mode_goes_SPORT (6U)
#  endif

#  ifndef Cx7_Manual_gear_change_only_SPORT_available
#   define Cx7_Manual_gear_change_only_SPORT_available (7U)
#  endif

#  ifndef Cx8_EV_mode_available
#   define Cx8_EV_mode_available (8U)
#  endif

#  ifndef Cx9_Snow_not_available_due_to_temporary_hybrid_system_limitations
#   define Cx9_Snow_not_available_due_to_temporary_hybrid_system_limitations (9U)
#  endif

#  ifndef CxA_Muddy_not_available_due_to_temporary_hybrid_system_limitations
#   define CxA_Muddy_not_available_due_to_temporary_hybrid_system_limitations (10U)
#  endif

#  ifndef CxB_Sand_not_available_due_to_temporary_hybrid_system_limitations
#   define CxB_Sand_not_available_due_to_temporary_hybrid_system_limitations (11U)
#  endif

#  ifndef CxC_SPORT_Plus_Mode_not_available_due_to_temporary_hybrid_system_limitations
#   define CxC_SPORT_Plus_Mode_not_available_due_to_temporary_hybrid_system_limitations (12U)
#  endif

#  ifndef CxD_ECO_Mode_not_available
#   define CxD_ECO_Mode_not_available (13U)
#  endif

#  ifndef CxE_EV_not_available_due_to_engine_needs_to_start
#   define CxE_EV_not_available_due_to_engine_needs_to_start (14U)
#  endif

#  ifndef Cx0_Normal_Default_
#   define Cx0_Normal_Default_ (0U)
#  endif

#  ifndef Cx1_OPD_function_not_available_due_to_temporary_hybrid_system_limitations
#   define Cx1_OPD_function_not_available_due_to_temporary_hybrid_system_limitations (1U)
#  endif

#  ifndef Cx2_OPD_function_not_available_due_to_Snow_mode
#   define Cx2_OPD_function_not_available_due_to_Snow_mode (2U)
#  endif

#  ifndef Cx0_Not_active
#   define Cx0_Not_active (0U)
#  endif

#  ifndef Cx2_Abnormal_quit
#   define Cx2_Abnormal_quit (2U)
#  endif

#  ifndef Cx3_Cannot_active
#   define Cx3_Cannot_active (3U)
#  endif

#  ifndef Cx4_Have_no_OPD_function
#   define Cx4_Have_no_OPD_function (4U)
#  endif

#  ifndef Cx0_No_request
#   define Cx0_No_request (0U)
#  endif

#  ifndef Cx1_Refueling_request
#   define Cx1_Refueling_request (1U)
#  endif

#  ifndef Cx2_When_vehicle_is_ready_inhibit_refuel
#   define Cx2_When_vehicle_is_ready_inhibit_refuel (2U)
#  endif

#  ifndef Cx3_When_engine_is_run_inhibit_refuel
#   define Cx3_When_engine_is_run_inhibit_refuel (3U)
#  endif

#  ifndef Cx4_When_charger_is_connected_inhibit_refuel
#   define Cx4_When_charger_is_connected_inhibit_refuel (4U)
#  endif

#  ifndef Cx3_reserved
#   define Cx3_reserved (3U)
#  endif

#  ifndef Cx1_On_active_braking
#   define Cx1_On_active_braking (1U)
#  endif

#  ifndef Cx2_On_not_active_braking
#   define Cx2_On_not_active_braking (2U)
#  endif

#  ifndef Cx1_Failure_when_HDC_is_on_need
#   define Cx1_Failure_when_HDC_is_on_need (1U)
#  endif

#  ifndef Cx0_Valid_value
#   define Cx0_Valid_value (0U)
#  endif

#  ifndef CxE_Valid_value
#   define CxE_Valid_value (14U)
#  endif

#  ifndef CxF_Invalid_value
#   define CxF_Invalid_value (15U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_OFF
#   define SYSTEMSTATE_Cluster_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_STANDBY
#   define SYSTEMSTATE_Cluster_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_ON
#   define SYSTEMSTATE_Cluster_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_STARTUP
#   define SYSTEMSTATE_Cluster_STARTUP (3U)
#  endif

#  ifndef SYSTEMSTATE_Cluster_SHUTDOWN
#   define SYSTEMSTATE_Cluster_SHUTDOWN (4U)
#  endif

#  ifndef SYSTEMSTATE_IVI_OFF
#   define SYSTEMSTATE_IVI_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_IVI_STANDBY
#   define SYSTEMSTATE_IVI_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON
#   define SYSTEMSTATE_IVI_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_IVI_SHUTDOWN
#   define SYSTEMSTATE_IVI_SHUTDOWN (3U)
#  endif

#  ifndef SYSTEMSTATE_IVI_REMOTE
#   define SYSTEMSTATE_IVI_REMOTE (4U)
#  endif

#  ifndef SYSTEMSTATE_IVI_DEMO
#   define SYSTEMSTATE_IVI_DEMO (5U)
#  endif

#  ifndef SYSTEMSTATE_IVI_AWAKEHOLD
#   define SYSTEMSTATE_IVI_AWAKEHOLD (6U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_NORMAL
#   define SYSTEMSTATE_IVI_ON_NORMAL (7U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_POWER_ERROR
#   define SYSTEMSTATE_IVI_ON_POWER_ERROR (8U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_POWER_SAVE_1
#   define SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (9U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_POWER_SAVE_2
#   define SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (10U)
#  endif

#  ifndef SYSTEMSTATE_IVI_ON_LOCAL
#   define SYSTEMSTATE_IVI_ON_LOCAL (11U)
#  endif

#  ifndef SYSTEMSTATE_HUD_OFF
#   define SYSTEMSTATE_HUD_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_HUD_STANDBY
#   define SYSTEMSTATE_HUD_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_HUD_ON
#   define SYSTEMSTATE_HUD_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_HUD_STARTUP
#   define SYSTEMSTATE_HUD_STARTUP (3U)
#  endif

#  ifndef SYSTEMSTATE_HUD_SHUTDOWN
#   define SYSTEMSTATE_HUD_SHUTDOWN (4U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_OFF
#   define SYSTEMSTATE_CONSOLE_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_STANDBY
#   define SYSTEMSTATE_CONSOLE_STANDBY (1U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_ON
#   define SYSTEMSTATE_CONSOLE_ON (2U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_STARTUP
#   define SYSTEMSTATE_CONSOLE_STARTUP (3U)
#  endif

#  ifndef SYSTEMSTATE_CONSOLE_SHUTDOWN
#   define SYSTEMSTATE_CONSOLE_SHUTDOWN (4U)
#  endif

#  ifndef KL15OFF
#   define KL15OFF (0U)
#  endif

#  ifndef KL15ON
#   define KL15ON (1U)
#  endif

#  ifndef VOLTAGE_OUT_LOWSLEEP
#   define VOLTAGE_OUT_LOWSLEEP (0U)
#  endif

#  ifndef VOLTAGE_OUT_NORMAL
#   define VOLTAGE_OUT_NORMAL (1U)
#  endif

#  ifndef VOLTAGE_OUT_HIGHALARM
#   define VOLTAGE_OUT_HIGHALARM (2U)
#  endif

#  ifndef VOLTAGE_OUT_HIGHSLEEP
#   define VOLTAGE_OUT_HIGHSLEEP (3U)
#  endif

#  ifndef VOLTAGE_OUT_LOWALARM
#   define VOLTAGE_OUT_LOWALARM (4U)
#  endif

#  ifndef VOLTAGE_OUT_NUM
#   define VOLTAGE_OUT_NUM (5U)
#  endif

#  ifndef SYSTEMSTATE_SP_OFF
#   define SYSTEMSTATE_SP_OFF (0U)
#  endif

#  ifndef SYSTEMSTATE_SP_SHUTDOWN
#   define SYSTEMSTATE_SP_SHUTDOWN (1U)
#  endif

#  ifndef SYSTEMSTATE_SP_STANDBY
#   define SYSTEMSTATE_SP_STANDBY (2U)
#  endif

#  ifndef SYSTEMSTATE_SP_SOCOFF
#   define SYSTEMSTATE_SP_SOCOFF (3U)
#  endif

#  ifndef TEMP_LOW_SLEEP
#   define TEMP_LOW_SLEEP (0U)
#  endif

#  ifndef TEMP_NORMAL
#   define TEMP_NORMAL (1U)
#  endif

#  ifndef TEMP_HIGH_PROTECT
#   define TEMP_HIGH_PROTECT (2U)
#  endif

#  ifndef TEMP_HIGH_SLEEP
#   define TEMP_HIGH_SLEEP (3U)
#  endif

#  ifndef TEMP_STATE_NUM
#   define TEMP_STATE_NUM (4U)
#  endif

#  ifndef TEMP_STATE_INIT
#   define TEMP_STATE_INIT (255U)
#  endif

#  ifndef Cx0_Function_OFF
#   define Cx0_Function_OFF (0U)
#  endif

#  ifndef Cx2_Active
#   define Cx2_Active (2U)
#  endif

#  ifndef Cx3_Failure
#   define Cx3_Failure (3U)
#  endif

#  ifndef Cx1_Warnining
#   define Cx1_Warnining (1U)
#  endif

#  ifndef Cx2_Degrading
#   define Cx2_Degrading (2U)
#  endif

#  ifndef Cx3_ClutchOpen
#   define Cx3_ClutchOpen (3U)
#  endif

#  ifndef Cx01_Warning
#   define Cx01_Warning (1U)
#  endif

#  ifndef Cx02_Partial_function_external
#   define Cx02_Partial_function_external (2U)
#  endif

#  ifndef Cx04_Partial_function_internal
#   define Cx04_Partial_function_internal (4U)
#  endif

#  ifndef Cx08_Disable_NP
#   define Cx08_Disable_NP (8U)
#  endif

#  ifndef Cx10_Diable
#   define Cx10_Diable (16U)
#  endif

#  ifndef Cx80_EOL_not_finish
#   define Cx80_EOL_not_finish (128U)
#  endif

#  ifndef Cx0_Gear_shiftdown_display_off
#   define Cx0_Gear_shiftdown_display_off (0U)
#  endif

#  ifndef Cx1_Gear_shiftdown_display_on
#   define Cx1_Gear_shiftdown_display_on (1U)
#  endif

#  ifndef Cx0_Gear_shiftup_display_off
#   define Cx0_Gear_shiftup_display_off (0U)
#  endif

#  ifndef Cx1_Gear_shiftup_display_on
#   define Cx1_Gear_shiftup_display_on (1U)
#  endif

#  ifndef Cx000_Valid_values
#   define Cx000_Valid_values (0U)
#  endif

#  ifndef Cx3E7_Valid_values
#   define Cx3E7_Valid_values (999U)
#  endif

#  ifndef Cx3E8_Reserved
#   define Cx3E8_Reserved (1000U)
#  endif

#  ifndef Cx3FF_Reserved
#   define Cx3FF_Reserved (1023U)
#  endif

#  ifndef Cx0_Not_standstill
#   define Cx0_Not_standstill (0U)
#  endif

#  ifndef Cx1_Standstill
#   define Cx1_Standstill (1U)
#  endif

#  ifndef Cx2_InValid_values_short_unavailability_max_3s_
#   define Cx2_InValid_values_short_unavailability_max_3s_ (2U)
#  endif

#  ifndef Cx2_Invalid_short_unavailability_maX_3s_
#   define Cx2_Invalid_short_unavailability_maX_3s_ (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_COMMON_SAFETY_TYPE_H */
