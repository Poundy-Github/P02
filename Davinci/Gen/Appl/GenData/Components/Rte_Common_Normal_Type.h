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
 *             File:  Rte_Common_Normal_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <Common_Normal>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMMON_NORMAL_TYPE_H
# define RTE_COMMON_NORMAL_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_Fuction_Not_Available
#   define Cx0_Fuction_Not_Available (0U)
#  endif

#  ifndef Cx1_Fuction_Available
#   define Cx1_Fuction_Available (1U)
#  endif

#  ifndef Cx2_Performance_degradation
#   define Cx2_Performance_degradation (2U)
#  endif

#  ifndef Cx3_Reserved
#   define Cx3_Reserved (3U)
#  endif

#  ifndef Cx00_No_display
#   define Cx00_No_display (0U)
#  endif

#  ifndef Cx01_Unable_to_activate_ACC_due_to_speed_not_achive
#   define Cx01_Unable_to_activate_ACC_due_to_speed_not_achive (1U)
#  endif

#  ifndef Cx02_ACC_active_control_is_cancelled
#   define Cx02_ACC_active_control_is_cancelled (2U)
#  endif

#  ifndef Cx03_Resvered
#   define Cx03_Resvered (3U)
#  endif

#  ifndef Cx04_ACC_and_PEBS_temporary_unavailable
#   define Cx04_ACC_and_PEBS_temporary_unavailable (4U)
#  endif

#  ifndef Cx05_Unable_to_activate_ACC_due_to_other_limitation_except_speed_not_achive_
#   define Cx05_Unable_to_activate_ACC_due_to_other_limitation_except_speed_not_achive_ (5U)
#  endif

#  ifndef Cx06_ACC_and_PEBS_error
#   define Cx06_ACC_and_PEBS_error (6U)
#  endif

#  ifndef Cx07_ACC_temporary_unavailable
#   define Cx07_ACC_temporary_unavailable (7U)
#  endif

#  ifndef Cx08_Resvered
#   define Cx08_Resvered (8U)
#  endif

#  ifndef Cx09_Blindness
#   define Cx09_Blindness (9U)
#  endif

#  ifndef Cx0A_Resvered
#   define Cx0A_Resvered (10U)
#  endif

#  ifndef Cx1F_Resvered
#   define Cx1F_Resvered (31U)
#  endif

#  ifndef Cx0_Not_dectected
#   define Cx0_Not_dectected (0U)
#  endif

#  ifndef Cx1_Dectected
#   define Cx1_Dectected (1U)
#  endif

#  ifndef Cx2_Reserved
#   define Cx2_Reserved (2U)
#  endif

#  ifndef Cx3_Invalid
#   define Cx3_Invalid (3U)
#  endif

#  ifndef Cx0_Unkown
#   define Cx0_Unkown (0U)
#  endif

#  ifndef Cx1_Sedan
#   define Cx1_Sedan (1U)
#  endif

#  ifndef Cx2_Truck
#   define Cx2_Truck (2U)
#  endif

#  ifndef Cx3_Motorcycle
#   define Cx3_Motorcycle (3U)
#  endif

#  ifndef Cx4_Pedestrian
#   define Cx4_Pedestrian (4U)
#  endif

#  ifndef Cx5_Bicycle
#   define Cx5_Bicycle (5U)
#  endif

#  ifndef Cx6_Reserved
#   define Cx6_Reserved (6U)
#  endif

#  ifndef Cx7_Invalid
#   define Cx7_Invalid (7U)
#  endif

#  ifndef Cx00_OFF_Mode
#   define Cx00_OFF_Mode (0U)
#  endif

#  ifndef Cx01_Passive_Mode
#   define Cx01_Passive_Mode (1U)
#  endif

#  ifndef Cx02_StandBy_Mode
#   define Cx02_StandBy_Mode (2U)
#  endif

#  ifndef Cx03_Active_Control_Mode
#   define Cx03_Active_Control_Mode (3U)
#  endif

#  ifndef Cx04_Brake_Only_Mode
#   define Cx04_Brake_Only_Mode (4U)
#  endif

#  ifndef Cx05_Override
#   define Cx05_Override (5U)
#  endif

#  ifndef Cx06_Reserved
#   define Cx06_Reserved (6U)
#  endif

#  ifndef Cx07_ACC_and_PEBS_Failure_mode
#   define Cx07_ACC_and_PEBS_Failure_mode (7U)
#  endif

#  ifndef Cx08_ACC_Failure_mode
#   define Cx08_ACC_Failure_mode (8U)
#  endif

#  ifndef Cx09_Reserved
#   define Cx09_Reserved (9U)
#  endif

#  ifndef Cx1F_Reserved
#   define Cx1F_Reserved (31U)
#  endif

#  ifndef Cx00_Valid_value
#   define Cx00_Valid_value (0U)
#  endif

#  ifndef CxFE_Valid_value
#   define CxFE_Valid_value (254U)
#  endif

#  ifndef CxFF_No_display
#   define CxFF_No_display (255U)
#  endif

#  ifndef Cx0_No_display
#   define Cx0_No_display (0U)
#  endif

#  ifndef Cx1_Distance_1_one_bar
#   define Cx1_Distance_1_one_bar (1U)
#  endif

#  ifndef Cx2_Distance_2_two_bars
#   define Cx2_Distance_2_two_bars (2U)
#  endif

#  ifndef Cx3_Distance_3_three_bars
#   define Cx3_Distance_3_three_bars (3U)
#  endif

#  ifndef Cx4_Distance_4_four_bars
#   define Cx4_Distance_4_four_bars (4U)
#  endif

#  ifndef Cx5_Resvered
#   define Cx5_Resvered (5U)
#  endif

#  ifndef Cx7_Resvered
#   define Cx7_Resvered (7U)
#  endif

#  ifndef Cx1_TimeGap_1_1s
#   define Cx1_TimeGap_1_1s (1U)
#  endif

#  ifndef Cx2_TimeGap_2_1_4s
#   define Cx2_TimeGap_2_1_4s (2U)
#  endif

#  ifndef Cx3_TimeGap_3_1_8s
#   define Cx3_TimeGap_3_1_8s (3U)
#  endif

#  ifndef Cx4_TimeGap_4_2_1s
#   define Cx4_TimeGap_4_2_1s (4U)
#  endif

#  ifndef Cx5_Reserved
#   define Cx5_Reserved (5U)
#  endif

#  ifndef Cx7_Reserved
#   define Cx7_Reserved (7U)
#  endif

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_ON
#   define Cx1_ON (1U)
#  endif

#  ifndef Cx2_error
#   define Cx2_error (2U)
#  endif

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

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx0_No_intervention
#   define Cx0_No_intervention (0U)
#  endif

#  ifndef Cx1_Left_intervention
#   define Cx1_Left_intervention (1U)
#  endif

#  ifndef Cx2_Right_intervention
#   define Cx2_Right_intervention (2U)
#  endif

#  ifndef Cx1_Automatic_lane_change_function_failure
#   define Cx1_Automatic_lane_change_function_failure (1U)
#  endif

#  ifndef Cx2_Reserve
#   define Cx2_Reserve (2U)
#  endif

#  ifndef Cx3_Reserve
#   define Cx3_Reserve (3U)
#  endif

#  ifndef Cx0_no_failure
#   define Cx0_no_failure (0U)
#  endif

#  ifndef Cx1_failure
#   define Cx1_failure (1U)
#  endif

#  ifndef Cx0_Tone_0_No_Warning
#   define Cx0_Tone_0_No_Warning (0U)
#  endif

#  ifndef Cx1_Tone_1_APS_failed_tone
#   define Cx1_Tone_1_APS_failed_tone (1U)
#  endif

#  ifndef Cx2_Tone_2_APS_successful_tone
#   define Cx2_Tone_2_APS_successful_tone (2U)
#  endif

#  ifndef Cx3_Tone_3_APS_warning_tone
#   define Cx3_Tone_3_APS_warning_tone (3U)
#  endif

#  ifndef Cx4_Tone_4_APS_request_tone
#   define Cx4_Tone_4_APS_request_tone (4U)
#  endif

#  ifndef Cx0_Disable
#   define Cx0_Disable (0U)
#  endif

#  ifndef Cx1_Standby
#   define Cx1_Standby (1U)
#  endif

#  ifndef Cx2_Searching
#   define Cx2_Searching (2U)
#  endif

#  ifndef Cx3_Guidance
#   define Cx3_Guidance (3U)
#  endif

#  ifndef Cx4_Failed
#   define Cx4_Failed (4U)
#  endif

#  ifndef Cx5_Wait_for_Engine_restart
#   define Cx5_Wait_for_Engine_restart (5U)
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

#  ifndef Cx2_active
#   define Cx2_active (2U)
#  endif

#  ifndef Cx0_Invalid
#   define Cx0_Invalid (0U)
#  endif

#  ifndef Cx1_Valid
#   define Cx1_Valid (1U)
#  endif

#  ifndef Cx2_Init_value
#   define Cx2_Init_value (2U)
#  endif

#  ifndef Cx0_Non_Auto
#   define Cx0_Non_Auto (0U)
#  endif

#  ifndef Cx1_Auto
#   define Cx1_Auto (1U)
#  endif

#  ifndef Cx0_inactive
#   define Cx0_inactive (0U)
#  endif

#  ifndef Cx1_running_thermalrunaway
#   define Cx1_running_thermalrunaway (1U)
#  endif

#  ifndef Cx2_parking_thermalrunaway
#   define Cx2_parking_thermalrunaway (2U)
#  endif

#  ifndef Cx3_reserved
#   define Cx3_reserved (3U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
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

#  ifndef Cx000_Valid_value
#   define Cx000_Valid_value (0U)
#  endif

#  ifndef Cx3FE_Valid_value
#   define Cx3FE_Valid_value (1022U)
#  endif

#  ifndef Cx3FF_Invalid
#   define Cx3FF_Invalid (1023U)
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

#  ifndef Cx7_Emergency_Open
#   define Cx7_Emergency_Open (7U)
#  endif

#  ifndef Cx0_Default
#   define Cx0_Default (0U)
#  endif

#  ifndef Cx2_Off
#   define Cx2_Off (2U)
#  endif

#  ifndef Cx0_Normal
#   define Cx0_Normal (0U)
#  endif

#  ifndef Cx1_Need_to_charge
#   define Cx1_Need_to_charge (1U)
#  endif

#  ifndef Cx1_Warning_level_1
#   define Cx1_Warning_level_1 (1U)
#  endif

#  ifndef Cx2_Warning_level_2
#   define Cx2_Warning_level_2 (2U)
#  endif

#  ifndef Cx0_Not_Active
#   define Cx0_Not_Active (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx2_Stand_by
#   define Cx2_Stand_by (2U)
#  endif

#  ifndef Cx3_Failed
#   define Cx3_Failed (3U)
#  endif

#  define CCO_TgtVel_adt_LowerLimit (0U)
#  define CCO_TgtVel_adt_UpperLimit (31U)

#  ifndef Cx00_Valid_values
#   define Cx00_Valid_values (0U)
#  endif

#  ifndef Cx1F_Valid_values
#   define Cx1F_Valid_values (31U)
#  endif

#  ifndef Cx0_No_Warn
#   define Cx0_No_Warn (0U)
#  endif

#  ifndef Cx1_Please_Release_EPB
#   define Cx1_Please_Release_EPB (1U)
#  endif

#  ifndef Cx2_Please_slow_down
#   define Cx2_Please_slow_down (2U)
#  endif

#  ifndef Cx0_No_Blindness
#   define Cx0_No_Blindness (0U)
#  endif

#  ifndef Cx1_Blindness
#   define Cx1_Blindness (1U)
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

#  ifndef CxFF_Valid_values
#   define CxFF_Valid_values (255U)
#  endif

#  ifndef CxFF_Valid_value
#   define CxFF_Valid_value (255U)
#  endif

#  ifndef Cx00_Valid_Value
#   define Cx00_Valid_Value (0U)
#  endif

#  ifndef CxFF_Valid_Value
#   define CxFF_Valid_Value (255U)
#  endif

#  ifndef Cx0_No_coupling_thermal_failsafe
#   define Cx0_No_coupling_thermal_failsafe (0U)
#  endif

#  ifndef Cx1_coupling_thermal_failsafe
#   define Cx1_coupling_thermal_failsafe (1U)
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

#  ifndef Cx0_OFF_mode
#   define Cx0_OFF_mode (0U)
#  endif

#  ifndef Cx1_Idle_mode
#   define Cx1_Idle_mode (1U)
#  endif

#  ifndef Cx2_Ready_mode
#   define Cx2_Ready_mode (2U)
#  endif

#  ifndef Cx3_Active
#   define Cx3_Active (3U)
#  endif

#  ifndef Cx5_Warning_Level_1
#   define Cx5_Warning_Level_1 (5U)
#  endif

#  ifndef Cx6_Warning_Level_2
#   define Cx6_Warning_Level_2 (6U)
#  endif

#  ifndef Cx7_Warning_Level_3
#   define Cx7_Warning_Level_3 (7U)
#  endif

#  ifndef Cx8_Reserved
#   define Cx8_Reserved (8U)
#  endif

#  ifndef Cx9_Failure
#   define Cx9_Failure (9U)
#  endif

#  ifndef CxA_Reserved
#   define CxA_Reserved (10U)
#  endif

#  ifndef CxF_Reserved
#   define CxF_Reserved (15U)
#  endif

#  ifndef Cx1_Unable_to_activate_CruiseChauffer_due_to_other_limitation
#   define Cx1_Unable_to_activate_CruiseChauffer_due_to_other_limitation (1U)
#  endif

#  ifndef Cx2_CruiseChauffer_active_control_is_cancelled
#   define Cx2_CruiseChauffer_active_control_is_cancelled (2U)
#  endif

#  ifndef Cx3_CruiseChauffer_temporarily_unavailable
#   define Cx3_CruiseChauffer_temporarily_unavailable (3U)
#  endif

#  ifndef Cx4_Take_over_request
#   define Cx4_Take_over_request (4U)
#  endif

#  ifndef Cx5_Current_IGN_Cycle_Function_Inhibit
#   define Cx5_Current_IGN_Cycle_Function_Inhibit (5U)
#  endif

#  ifndef Cx6_Please_Keep_Attention
#   define Cx6_Please_Keep_Attention (6U)
#  endif

#  ifndef Cx7_To_cross_the_tunnel_please_take_over_in_time
#   define Cx7_To_cross_the_tunnel_please_take_over_in_time (7U)
#  endif

#  ifndef Cx8_Have_a_branch_road_ahead_Please_take_over_in_time
#   define Cx8_Have_a_branch_road_ahead_Please_take_over_in_time (8U)
#  endif

#  ifndef Cx9_Hands_off_warning
#   define Cx9_Hands_off_warning (9U)
#  endif

#  ifndef Cx0_Inactive
#   define Cx0_Inactive (0U)
#  endif

#  ifndef Cx2_Standby
#   define Cx2_Standby (2U)
#  endif

#  ifndef Cx1_Stand_by
#   define Cx1_Stand_by (1U)
#  endif

#  ifndef Cx2_Cruise
#   define Cx2_Cruise (2U)
#  endif

#  ifndef Cx3_Acceleration
#   define Cx3_Acceleration (3U)
#  endif

#  ifndef Cx4_Deceleration
#   define Cx4_Deceleration (4U)
#  endif

#  ifndef Cx5_Tip_up
#   define Cx5_Tip_up (5U)
#  endif

#  ifndef Cx6_Tip_dwon
#   define Cx6_Tip_dwon (6U)
#  endif

#  ifndef Cx7_Resume_from_above_vehicle_speed
#   define Cx7_Resume_from_above_vehicle_speed (7U)
#  endif

#  ifndef Cx8_Resume_from_below_vehicle_speed
#   define Cx8_Resume_from_below_vehicle_speed (8U)
#  endif

#  ifndef Cx9_Error
#   define Cx9_Error (9U)
#  endif

#  ifndef E_NOT_OK
#   define E_NOT_OK (1U)
#  endif

#  ifndef E_SMALL_BUFFER
#   define E_SMALL_BUFFER (2U)
#  endif

#  ifndef E_ENTROPY_EXHAUSTION
#   define E_ENTROPY_EXHAUSTION (3U)
#  endif

#  ifndef E_KEY_READ_FAIL
#   define E_KEY_READ_FAIL (4U)
#  endif

#  ifndef E_KEY_NOT_AVAILABLE
#   define E_KEY_NOT_AVAILABLE (5U)
#  endif

#  ifndef E_KEY_NOT_VALID
#   define E_KEY_NOT_VALID (6U)
#  endif

#  ifndef E_JOB_CANCELED
#   define E_JOB_CANCELED (7U)
#  endif

#  ifndef E_KEY_EMPTY
#   define E_KEY_EMPTY (8U)
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

#  ifndef Cx0_FaceIdentification
#   define Cx0_FaceIdentification (0U)
#  endif

#  ifndef Cx1_FaceEnrollment
#   define Cx1_FaceEnrollment (1U)
#  endif

#  ifndef Cx2_VoiceIdentification
#   define Cx2_VoiceIdentification (2U)
#  endif

#  ifndef Cx3_VoiceEnrollment
#   define Cx3_VoiceEnrollment (3U)
#  endif

#  ifndef Cx4_DeleteFaceData
#   define Cx4_DeleteFaceData (4U)
#  endif

#  ifndef Cx5_DeleteVoiceDate
#   define Cx5_DeleteVoiceDate (5U)
#  endif

#  ifndef Cx0_Unknow
#   define Cx0_Unknow (0U)
#  endif

#  ifndef Cx1_User_ID1
#   define Cx1_User_ID1 (1U)
#  endif

#  ifndef Cx2_User_ID2
#   define Cx2_User_ID2 (2U)
#  endif

#  ifndef Cx3_User_ID3
#   define Cx3_User_ID3 (3U)
#  endif

#  ifndef Cx4_User_ID4
#   define Cx4_User_ID4 (4U)
#  endif

#  ifndef Cx5_User_ID5
#   define Cx5_User_ID5 (5U)
#  endif

#  ifndef Cx6_User_ID6
#   define Cx6_User_ID6 (6U)
#  endif

#  ifndef CxB_Failed
#   define CxB_Failed (11U)
#  endif

#  ifndef CxC_Reserved
#   define CxC_Reserved (12U)
#  endif

#  ifndef CxE_Reserved
#   define CxE_Reserved (14U)
#  endif

#  ifndef CxF_Invalid
#   define CxF_Invalid (15U)
#  endif

#  ifndef Cx0_OK
#   define Cx0_OK (0U)
#  endif

#  ifndef Cx1_InProgress
#   define Cx1_InProgress (1U)
#  endif

#  ifndef Cx2_NOK
#   define Cx2_NOK (2U)
#  endif

#  ifndef Cx3_Start
#   define Cx3_Start (3U)
#  endif

#  ifndef Cx4_End
#   define Cx4_End (4U)
#  endif

#  ifndef Cx5_Moving_head_left_and_right
#   define Cx5_Moving_head_left_and_right (5U)
#  endif

#  ifndef DEM_EVENT_STATUS_PASSED
#   define DEM_EVENT_STATUS_PASSED (0U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED
#   define DEM_EVENT_STATUS_FAILED (1U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED
#   define DEM_EVENT_STATUS_PREPASSED (2U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED
#   define DEM_EVENT_STATUS_PREFAILED (3U)
#  endif

#  ifndef DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED
#   define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
#  endif

#  ifndef DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PASSED_CONDITIONS_NOT_FULFILLED (5U)
#  endif

#  ifndef DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_FAILED_CONDITIONS_NOT_FULFILLED (6U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PREPASSED_CONDITIONS_NOT_FULFILLED (7U)
#  endif

#  ifndef DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED
#   define DEM_EVENT_STATUS_PREFAILED_CONDITIONS_NOT_FULFILLED (8U)
#  endif

#  ifndef Cx0_Lamp_is_not_being_requested
#   define Cx0_Lamp_is_not_being_requested (0U)
#  endif

#  ifndef Cx1_Lamp_is_being_requested
#   define Cx1_Lamp_is_being_requested (1U)
#  endif

#  ifndef Cx0_No_distraction
#   define Cx0_No_distraction (0U)
#  endif

#  ifndef Cx1_Low_level_distraction
#   define Cx1_Low_level_distraction (1U)
#  endif

#  ifndef Cx2_Middle_level_distraction
#   define Cx2_Middle_level_distraction (2U)
#  endif

#  ifndef Cx3_High_level_distraction
#   define Cx3_High_level_distraction (3U)
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

#  ifndef Cx0_No_Drowsiness
#   define Cx0_No_Drowsiness (0U)
#  endif

#  ifndef Cx1_Low_level_Drowsiness
#   define Cx1_Low_level_Drowsiness (1U)
#  endif

#  ifndef Cx2_Middle_level_Drowsiness
#   define Cx2_Middle_level_Drowsiness (2U)
#  endif

#  ifndef Cx3_High_level_Drowsiness
#   define Cx3_High_level_Drowsiness (3U)
#  endif

#  ifndef Cx1_Warning_1
#   define Cx1_Warning_1 (1U)
#  endif

#  ifndef Cx2_Warning_2
#   define Cx2_Warning_2 (2U)
#  endif

#  ifndef Cx3_Not_available
#   define Cx3_Not_available (3U)
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

#  ifndef Cx0_Closed
#   define Cx0_Closed (0U)
#  endif

#  ifndef Cx1_Open
#   define Cx1_Open (1U)
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

#  ifndef CxF_Transmission_limit_function
#   define CxF_Transmission_limit_function (15U)
#  endif

#  ifndef Cx4_Authentication_failure
#   define Cx4_Authentication_failure (4U)
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

#  ifndef Cx1_Level_1
#   define Cx1_Level_1 (1U)
#  endif

#  ifndef Cx2_Level_2
#   define Cx2_Level_2 (2U)
#  endif

#  ifndef Cx3_Level_3
#   define Cx3_Level_3 (3U)
#  endif

#  ifndef Cx4_Level_4
#   define Cx4_Level_4 (4U)
#  endif

#  ifndef Cx5_Level_5
#   define Cx5_Level_5 (5U)
#  endif

#  ifndef Cx1_Left_Active
#   define Cx1_Left_Active (1U)
#  endif

#  ifndef Cx2_Right_active
#   define Cx2_Right_active (2U)
#  endif

#  ifndef Cx0_ELK_OFF_
#   define Cx0_ELK_OFF_ (0U)
#  endif

#  ifndef Cx1_ELK_Standby_
#   define Cx1_ELK_Standby_ (1U)
#  endif

#  ifndef Cx2_ELK_Enable_
#   define Cx2_ELK_Enable_ (2U)
#  endif

#  ifndef Cx3_ELK_Road_edge_Active_
#   define Cx3_ELK_Road_edge_Active_ (3U)
#  endif

#  ifndef Cx4_ELK_Oncoming_Active_oncoming_
#   define Cx4_ELK_Oncoming_Active_oncoming_ (4U)
#  endif

#  ifndef Cx5_ELK_Overtaking_Active_overtaking_
#   define Cx5_ELK_Overtaking_Active_overtaking_ (5U)
#  endif

#  ifndef Cx6_ELK_Failure
#   define Cx6_ELK_Failure (6U)
#  endif

#  ifndef Cx0_Nothing
#   define Cx0_Nothing (0U)
#  endif

#  ifndef Cx1_Authentication_failure
#   define Cx1_Authentication_failure (1U)
#  endif

#  ifndef Cx2_Authentication_success
#   define Cx2_Authentication_success (2U)
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

#  ifndef Cx0_No_warning_lamp
#   define Cx0_No_warning_lamp (0U)
#  endif

#  ifndef Cx1_Yellow_Lamp
#   define Cx1_Yellow_Lamp (1U)
#  endif

#  ifndef Cx2_Red_Lamp
#   define Cx2_Red_Lamp (2U)
#  endif

#  ifndef Cx0_No_error
#   define Cx0_No_error (0U)
#  endif

#  ifndef Cx1_Error
#   define Cx1_Error (1U)
#  endif

#  ifndef TC_ENERGY_RESP
#   define TC_ENERGY_RESP (0U)
#  endif

#  ifndef TC_ENERGY_PER_1KM
#   define TC_ENERGY_PER_1KM (1U)
#  endif

#  ifndef TC_ENERGY_DTE
#   define TC_ENERGY_DTE (2U)
#  endif

#  ifndef Cx0_No
#   define Cx0_No (0U)
#  endif

#  ifndef Cx1_Yes
#   define Cx1_Yes (1U)
#  endif

#  ifndef Cx0_SVS_off
#   define Cx0_SVS_off (0U)
#  endif

#  ifndef Cx1_SVS_on
#   define Cx1_SVS_on (1U)
#  endif

#  ifndef Cx2_Initial_value
#   define Cx2_Initial_value (2U)
#  endif

#  ifndef Cx0_AvailableOn
#   define Cx0_AvailableOn (0U)
#  endif

#  ifndef Cx1_Cross_country_expert_mode
#   define Cx1_Cross_country_expert_mode (1U)
#  endif

#  ifndef Cx2_FCTA_B_temporarily_unavailable
#   define Cx2_FCTA_B_temporarily_unavailable (2U)
#  endif

#  ifndef Cx3_FCTA_B_Performance_degradation
#   define Cx3_FCTA_B_Performance_degradation (3U)
#  endif

#  ifndef Cx1_tirggered
#   define Cx1_tirggered (1U)
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

#  ifndef Cx1_Low
#   define Cx1_Low (1U)
#  endif

#  ifndef Cx3_High
#   define Cx3_High (3U)
#  endif

#  ifndef Cx4_Not_available
#   define Cx4_Not_available (4U)
#  endif

#  ifndef Cx1_High
#   define Cx1_High (1U)
#  endif

#  ifndef Cx2_Not_available
#   define Cx2_Not_available (2U)
#  endif

#  ifndef Cx0_Tone_zero_No_warning
#   define Cx0_Tone_zero_No_warning (0U)
#  endif

#  ifndef Cx1_Tone_one_Long_beep
#   define Cx1_Tone_one_Long_beep (1U)
#  endif

#  ifndef Cx2_Tone_two_1_5_Hz
#   define Cx2_Tone_two_1_5_Hz (2U)
#  endif

#  ifndef Cx3_Tone_three_3Hz
#   define Cx3_Tone_three_3Hz (3U)
#  endif

#  ifndef Cx0_Tone_zero_No_warning_
#   define Cx0_Tone_zero_No_warning_ (0U)
#  endif

#  ifndef Cx1_Tone_one_Long_beep_
#   define Cx1_Tone_one_Long_beep_ (1U)
#  endif

#  ifndef Cx2_Tone_two_1_5_Hz_
#   define Cx2_Tone_two_1_5_Hz_ (2U)
#  endif

#  ifndef Cx3_Tone_three_3Hz_
#   define Cx3_Tone_three_3Hz_ (3U)
#  endif

#  ifndef Cx1_Enable
#   define Cx1_Enable (1U)
#  endif

#  ifndef Cx2_Active
#   define Cx2_Active (2U)
#  endif

#  ifndef Cx0_Disable_
#   define Cx0_Disable_ (0U)
#  endif

#  ifndef Cx1_Enable_
#   define Cx1_Enable_ (1U)
#  endif

#  ifndef Cx2_Active_
#   define Cx2_Active_ (2U)
#  endif

#  ifndef Cx3_Failed_
#   define Cx3_Failed_ (3U)
#  endif

#  ifndef Cx1_Warning_Fuel_tank_cap_did_not_close_
#   define Cx1_Warning_Fuel_tank_cap_did_not_close_ (1U)
#  endif

#  ifndef Cx3_Fault_Fuel_tank_cap_did_not_open_
#   define Cx3_Fault_Fuel_tank_cap_did_not_open_ (3U)
#  endif

#  ifndef Cx0_No_Warning
#   define Cx0_No_Warning (0U)
#  endif

#  ifndef Cx1_GPF_is_regenerating
#   define Cx1_GPF_is_regenerating (1U)
#  endif

#  ifndef Cx2_GPF_need_to_regenerate
#   define Cx2_GPF_need_to_regenerate (2U)
#  endif

#  ifndef Cx0_Idle
#   define Cx0_Idle (0U)
#  endif

#  ifndef Cx1_Passed
#   define Cx1_Passed (1U)
#  endif

#  ifndef Cx2_Failed
#   define Cx2_Failed (2U)
#  endif

#  ifndef Cx3_Invalid_value
#   define Cx3_Invalid_value (3U)
#  endif

#  ifndef Cx0_Init
#   define Cx0_Init (0U)
#  endif

#  ifndef Cx1_Not_connect
#   define Cx1_Not_connect (1U)
#  endif

#  ifndef Cx2_connect
#   define Cx2_connect (2U)
#  endif

#  ifndef Cx1_Derating
#   define Cx1_Derating (1U)
#  endif

#  ifndef Cx2_Normal
#   define Cx2_Normal (2U)
#  endif

#  ifndef Cx0_Invaild
#   define Cx0_Invaild (0U)
#  endif

#  ifndef Cx1_Vaild
#   define Cx1_Vaild (1U)
#  endif

#  define HCU_AvailPower_TM_adt_LowerLimit (0U)
#  define HCU_AvailPower_TM_adt_UpperLimit (101U)

#  ifndef Cx64_Valid_values
#   define Cx64_Valid_values (100U)
#  endif

#  ifndef Cx65_invalid_values
#   define Cx65_invalid_values (101U)
#  endif

#  ifndef CxFF_invalid_values
#   define CxFF_invalid_values (255U)
#  endif

#  ifndef Cx1_PTC_heating_is_complete
#   define Cx1_PTC_heating_is_complete (1U)
#  endif

#  ifndef Cx2_Plug_in_heating_is_complete
#   define Cx2_Plug_in_heating_is_complete (2U)
#  endif

#  ifndef Cx1_Battery_temperature_is_too_low_plug_in_heating
#   define Cx1_Battery_temperature_is_too_low_plug_in_heating (1U)
#  endif

#  ifndef Cx2_Battery_temperature_is_low_vehicle_cannot_start_normal_Please_wait_battery_is_being_heating
#   define Cx2_Battery_temperature_is_low_vehicle_cannot_start_normal_Please_wait_battery_is_being_heating (2U)
#  endif

#  ifndef Cx1_Battery_temperature_is_low_power_may_decrease
#   define Cx1_Battery_temperature_is_low_power_may_decrease (1U)
#  endif

#  ifndef Cx2_Battery_temperature_is_high_power_may_decrease
#   define Cx2_Battery_temperature_is_high_power_may_decrease (2U)
#  endif

#  ifndef Cx1_Charging_
#   define Cx1_Charging_ (1U)
#  endif

#  ifndef Cx2_Delaying
#   define Cx2_Delaying (2U)
#  endif

#  ifndef Cx3_Charge_complete
#   define Cx3_Charge_complete (3U)
#  endif

#  ifndef Cx4_Charge_stopped
#   define Cx4_Charge_stopped (4U)
#  endif

#  ifndef Cx5_Charge_Initialize
#   define Cx5_Charge_Initialize (5U)
#  endif

#  ifndef Cx6_Heating_
#   define Cx6_Heating_ (6U)
#  endif

#  ifndef Cx7_Charging_and_Heating_
#   define Cx7_Charging_and_Heating_ (7U)
#  endif

#  ifndef Cx0_Not_indicate
#   define Cx0_Not_indicate (0U)
#  endif

#  ifndef Cx1_Indicate
#   define Cx1_Indicate (1U)
#  endif

#  ifndef Cx1_Green_Light_ON
#   define Cx1_Green_Light_ON (1U)
#  endif

#  ifndef Cx2_Red_Light_ON
#   define Cx2_Red_Light_ON (2U)
#  endif

#  ifndef Cx3_Yellow_Light_with_slanting_line
#   define Cx3_Yellow_Light_with_slanting_line (3U)
#  endif

#  ifndef Cx4_Red_Light_with_slanting_line
#   define Cx4_Red_Light_with_slanting_line (4U)
#  endif

#  ifndef Cx0_AutoNormal_Mode_started
#   define Cx0_AutoNormal_Mode_started (0U)
#  endif

#  ifndef Cx1_EV_Mode_started
#   define Cx1_EV_Mode_started (1U)
#  endif

#  ifndef Cx2_Save_Mode_started
#   define Cx2_Save_Mode_started (2U)
#  endif

#  ifndef Cx3_SPORT_Mode_started
#   define Cx3_SPORT_Mode_started (3U)
#  endif

#  ifndef Cx4_AWD_Normal_Mode_started
#   define Cx4_AWD_Normal_Mode_started (4U)
#  endif

#  ifndef Cx5_Snow_Mode_started
#   define Cx5_Snow_Mode_started (5U)
#  endif

#  ifndef Cx6_Muddy_Mode_started
#   define Cx6_Muddy_Mode_started (6U)
#  endif

#  ifndef Cx7_Sand_Mode_started
#   define Cx7_Sand_Mode_started (7U)
#  endif

#  ifndef Cx8_ECO
#   define Cx8_ECO (8U)
#  endif

#  ifndef Cx9_SPORT_Plus_Mode_started
#   define Cx9_SPORT_Plus_Mode_started (9U)
#  endif

#  define HCU_ECODrvHabit_Indcn_adt_LowerLimit (0U)
#  define HCU_ECODrvHabit_Indcn_adt_UpperLimit (201U)

#  ifndef CxC8_Valid_values
#   define CxC8_Valid_values (200U)
#  endif

#  ifndef CxC9_Reversed
#   define CxC9_Reversed (201U)
#  endif

#  ifndef CxFF_Reversed
#   define CxFF_Reversed (255U)
#  endif

#  ifndef Cx00_Vaild_value
#   define Cx00_Vaild_value (0U)
#  endif

#  ifndef Cx64_Vaild_value
#   define Cx64_Vaild_value (100U)
#  endif

#  ifndef Cx65_Reserved
#   define Cx65_Reserved (101U)
#  endif

#  ifndef Cx7E_Reserved
#   define Cx7E_Reserved (126U)
#  endif

#  ifndef Cx7F_Invalid
#   define Cx7F_Invalid (127U)
#  endif

#  ifndef Cx0_Not_active
#   define Cx0_Not_active (0U)
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

#  ifndef Cx1_Yellow_Light_ON
#   define Cx1_Yellow_Light_ON (1U)
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

#  ifndef Cx2_Abnormal_quit
#   define Cx2_Abnormal_quit (2U)
#  endif

#  ifndef Cx3_Cannot_active
#   define Cx3_Cannot_active (3U)
#  endif

#  ifndef Cx4_Have_no_OPD_function
#   define Cx4_Have_no_OPD_function (4U)
#  endif

#  ifndef Cx0_Race_Launch_is_available
#   define Cx0_Race_Launch_is_available (0U)
#  endif

#  ifndef Cx1_Race_Launch_is_not_available_due_to_ESP_is_not_OFF
#   define Cx1_Race_Launch_is_not_available_due_to_ESP_is_not_OFF (1U)
#  endif

#  ifndef Cx2_Race_Launch_is_not_available_due_to_temporary_hybrid_system_limitations
#   define Cx2_Race_Launch_is_not_available_due_to_temporary_hybrid_system_limitations (2U)
#  endif

#  ifndef Cx3_Race_Launch_is_not_available_due_to_battery_SOCtemperature_low
#   define Cx3_Race_Launch_is_not_available_due_to_battery_SOCtemperature_low (3U)
#  endif

#  ifndef Cx2_Timeout_protection
#   define Cx2_Timeout_protection (2U)
#  endif

#  ifndef Cx3_Super_race_launch_active
#   define Cx3_Super_race_launch_active (3U)
#  endif

#  ifndef Cx4_Super_race_launch_is_not_available_due_to_battery_available_power_low_normal_race_activated
#   define Cx4_Super_race_launch_is_not_available_due_to_battery_available_power_low_normal_race_activated (4U)
#  endif

#  ifndef Cx5_Super_race_launch_is_not_available_due_to_transmission_temperature_high_normal_race_activated
#   define Cx5_Super_race_launch_is_not_available_due_to_transmission_temperature_high_normal_race_activated (5U)
#  endif

#  ifndef Cx6_The_maximum_times_of_super_race_launch_is_reached_normal_race_activatedivated
#   define Cx6_The_maximum_times_of_super_race_launch_is_reached_normal_race_activatedivated (6U)
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

#  ifndef Cx1_On_active_braking
#   define Cx1_On_active_braking (1U)
#  endif

#  ifndef Cx2_On_not_active_braking
#   define Cx2_On_not_active_braking (2U)
#  endif

#  ifndef Cx1_Failure_when_HDC_is_on_need
#   define Cx1_Failure_when_HDC_is_on_need (1U)
#  endif

#  ifndef KEY_OK
#   define KEY_OK (0U)
#  endif

#  ifndef KEY_IS_INIT
#   define KEY_IS_INIT (1U)
#  endif

#  ifndef KEY_IS_INVALID
#   define KEY_IS_INVALID (2U)
#  endif

#  ifndef Cx1_Unable_to_activate_HWA_due_to_other_limitation
#   define Cx1_Unable_to_activate_HWA_due_to_other_limitation (1U)
#  endif

#  ifndef Cx2_HWA_active_control_is_cancelled
#   define Cx2_HWA_active_control_is_cancelled (2U)
#  endif

#  ifndef Cx3_Turn_off_the_turn_light
#   define Cx3_Turn_off_the_turn_light (3U)
#  endif

#  ifndef Cx4_Active_confirm
#   define Cx4_Active_confirm (4U)
#  endif

#  ifndef Cx5_Overtime_for_lane_change
#   define Cx5_Overtime_for_lane_change (5U)
#  endif

#  ifndef Cx6_lane_change_is_cancelled
#   define Cx6_lane_change_is_cancelled (6U)
#  endif

#  ifndef Cx7_HWA_temporary_unavailable
#   define Cx7_HWA_temporary_unavailable (7U)
#  endif

#  ifndef Cx8_Speed_is_too_low_to_support_lane_change
#   define Cx8_Speed_is_too_low_to_support_lane_change (8U)
#  endif

#  ifndef Cx9_HWA_need_to_restart_the_engine
#   define Cx9_HWA_need_to_restart_the_engine (9U)
#  endif

#  ifndef CxA_Take_over_request
#   define CxA_Take_over_request (10U)
#  endif

#  ifndef CxB_Please_Keep_Attention
#   define CxB_Please_Keep_Attention (11U)
#  endif

#  ifndef CxC_To_cross_the_tunnel_please_take_over_in_time
#   define CxC_To_cross_the_tunnel_please_take_over_in_time (12U)
#  endif

#  ifndef CxD_Have_a_branch_road_ahead_Please_take_over_in_time
#   define CxD_Have_a_branch_road_ahead_Please_take_over_in_time (13U)
#  endif

#  ifndef CxE_Reserve
#   define CxE_Reserve (14U)
#  endif

#  ifndef CxF_Reserve
#   define CxF_Reserve (15U)
#  endif

#  ifndef Cx1_left_satisfied
#   define Cx1_left_satisfied (1U)
#  endif

#  ifndef Cx2_right_satisfied
#   define Cx2_right_satisfied (2U)
#  endif

#  ifndef Cx3_left_not_satisfied
#   define Cx3_left_not_satisfied (3U)
#  endif

#  ifndef Cx4_right_not_satisfied
#   define Cx4_right_not_satisfied (4U)
#  endif

#  ifndef Cx5_reserved
#   define Cx5_reserved (5U)
#  endif

#  ifndef Cx7_reserved
#   define Cx7_reserved (7U)
#  endif

#  ifndef Cx1_left
#   define Cx1_left (1U)
#  endif

#  ifndef Cx2_right
#   define Cx2_right (2U)
#  endif

#  ifndef Cx1_Safstop
#   define Cx1_Safstop (1U)
#  endif

#  ifndef Cx2_Passive
#   define Cx2_Passive (2U)
#  endif

#  ifndef Cx3_Ready
#   define Cx3_Ready (3U)
#  endif

#  ifndef Cx4_Active
#   define Cx4_Active (4U)
#  endif

#  ifndef Cx5_Override
#   define Cx5_Override (5U)
#  endif

#  ifndef Cx6_Slow_retreat
#   define Cx6_Slow_retreat (6U)
#  endif

#  ifndef Cx7_Standstill
#   define Cx7_Standstill (7U)
#  endif

#  ifndef CxF_Fault
#   define CxF_Fault (15U)
#  endif

#  ifndef Cx1_Warning_Level_1
#   define Cx1_Warning_Level_1 (1U)
#  endif

#  ifndef Cx2_Warning_Level_2
#   define Cx2_Warning_Level_2 (2U)
#  endif

#  ifndef Cx3_Warning_Level_3
#   define Cx3_Warning_Level_3 (3U)
#  endif

#  ifndef Cx0_Warning_lamp_off
#   define Cx0_Warning_lamp_off (0U)
#  endif

#  ifndef Cx1_Warning_lamp_on
#   define Cx1_Warning_lamp_on (1U)
#  endif

#  ifndef Cx0_Calibration_Success
#   define Cx0_Calibration_Success (0U)
#  endif

#  ifndef Cx1_Calibration_In_Process
#   define Cx1_Calibration_In_Process (1U)
#  endif

#  ifndef Cx2_Calibration_Failed
#   define Cx2_Calibration_Failed (2U)
#  endif

#  ifndef Cx0_no_warning
#   define Cx0_no_warning (0U)
#  endif

#  ifndef Cx1_Level1_warning
#   define Cx1_Level1_warning (1U)
#  endif

#  ifndef Cx2_Level2_warning
#   define Cx2_Level2_warning (2U)
#  endif

#  ifndef Cx3_Level3_warning
#   define Cx3_Level3_warning (3U)
#  endif

#  ifndef Cx4_Level4_warning
#   define Cx4_Level4_warning (4U)
#  endif

#  ifndef Cx5_Level5_warning
#   define Cx5_Level5_warning (5U)
#  endif

#  ifndef Cx1_Solid_lane
#   define Cx1_Solid_lane (1U)
#  endif

#  ifndef Cx2_Dashed_lane
#   define Cx2_Dashed_lane (2U)
#  endif

#  ifndef Cx3_Rode_edge
#   define Cx3_Rode_edge (3U)
#  endif

#  ifndef Cx1_Speed_Limit_Confirm_Request
#   define Cx1_Speed_Limit_Confirm_Request (1U)
#  endif

#  ifndef Cx2_Speed_Limit_Take_Over_Request
#   define Cx2_Speed_Limit_Take_Over_Request (2U)
#  endif

#  ifndef Cx3_Resvered
#   define Cx3_Resvered (3U)
#  endif

#  ifndef Cx1_Left_Eva
#   define Cx1_Left_Eva (1U)
#  endif

#  ifndef Cx2_Right_Eva
#   define Cx2_Right_Eva (2U)
#  endif

#  ifndef Cx3_Res
#   define Cx3_Res (3U)
#  endif

#  ifndef Cx0_No_indicator
#   define Cx0_No_indicator (0U)
#  endif

#  ifndef Cx1_Active_indicator
#   define Cx1_Active_indicator (1U)
#  endif

#  ifndef Cx2_Passive_indicator
#   define Cx2_Passive_indicator (2U)
#  endif

#  ifndef Cx0_No_LDW_LKA_warning
#   define Cx0_No_LDW_LKA_warning (0U)
#  endif

#  ifndef Cx1_LDW_LKA_left_warning
#   define Cx1_LDW_LKA_left_warning (1U)
#  endif

#  ifndef Cx2_LDW_LKA_right_warning
#   define Cx2_LDW_LKA_right_warning (2U)
#  endif

#  ifndef Cx1_LDW_error
#   define Cx1_LDW_error (1U)
#  endif

#  ifndef Cx2_LKA_error
#   define Cx2_LKA_error (2U)
#  endif

#  ifndef Cx3_LCK_error
#   define Cx3_LCK_error (3U)
#  endif

#  ifndef Cx4_ELK_error
#   define Cx4_ELK_error (4U)
#  endif

#  ifndef Cx5_ESS_error
#   define Cx5_ESS_error (5U)
#  endif

#  ifndef Cx1_LDW_on
#   define Cx1_LDW_on (1U)
#  endif

#  ifndef Cx2_LKA_on
#   define Cx2_LKA_on (2U)
#  endif

#  ifndef Cx3_LCK_ON
#   define Cx3_LCK_ON (3U)
#  endif

#  ifndef Cx0_No_warning_and_Intervention
#   define Cx0_No_warning_and_Intervention (0U)
#  endif

#  ifndef Cx1_Left_warning
#   define Cx1_Left_warning (1U)
#  endif

#  ifndef Cx2_Right_warning
#   define Cx2_Right_warning (2U)
#  endif

#  ifndef Cx3_Left_Intervention
#   define Cx3_Left_Intervention (3U)
#  endif

#  ifndef Cx4_Right_Intervention
#   define Cx4_Right_Intervention (4U)
#  endif

#  ifndef Cx5_Both_Intervention
#   define Cx5_Both_Intervention (5U)
#  endif

#  ifndef Cx6_Left_warn_only_reminder
#   define Cx6_Left_warn_only_reminder (6U)
#  endif

#  ifndef Cx7_Right_warn_only_reminder
#   define Cx7_Right_warn_only_reminder (7U)
#  endif

#  ifndef Cx0_Voice
#   define Cx0_Voice (0U)
#  endif

#  ifndef Cx1_Haptic
#   define Cx1_Haptic (1U)
#  endif

#  ifndef Cx2_Voice_Haptic
#   define Cx2_Voice_Haptic (2U)
#  endif

#  ifndef Cx0_Not_Avaliable
#   define Cx0_Not_Avaliable (0U)
#  endif

#  ifndef Cx1_Left_Lane_Marker_Available
#   define Cx1_Left_Lane_Marker_Available (1U)
#  endif

#  ifndef Cx2_Right_Lane_Marker_Available
#   define Cx2_Right_Lane_Marker_Available (2U)
#  endif

#  ifndef Cx3_Both_Lane_Markers_Available
#   define Cx3_Both_Lane_Markers_Available (3U)
#  endif

#  ifndef Cx1_AEB_active
#   define Cx1_AEB_active (1U)
#  endif

#  ifndef Cx2_Safestop_active
#   define Cx2_Safestop_active (2U)
#  endif

#  ifndef Cx1_Passive_mode_Reject_
#   define Cx1_Passive_mode_Reject_ (1U)
#  endif

#  ifndef Cx2_Passive_mode_Stand_by_
#   define Cx2_Passive_mode_Stand_by_ (2U)
#  endif

#  ifndef Cx3_Active_Control_mode
#   define Cx3_Active_Control_mode (3U)
#  endif

#  ifndef Cx4_Brake_only_mode
#   define Cx4_Brake_only_mode (4U)
#  endif

#  ifndef Cx6_Standstill
#   define Cx6_Standstill (6U)
#  endif

#  ifndef Cx7_Failure_mode_Longctrl
#   define Cx7_Failure_mode_Longctrl (7U)
#  endif

#  ifndef Cx9_Shut_off
#   define Cx9_Shut_off (9U)
#  endif

#  ifndef Cx1_Request_park_Shift
#   define Cx1_Request_park_Shift (1U)
#  endif

#  ifndef Cx2_Invalid
#   define Cx2_Invalid (2U)
#  endif

#  ifndef Cx2_Reservrd
#   define Cx2_Reservrd (2U)
#  endif

#  ifndef Cx3_Reservrd
#   define Cx3_Reservrd (3U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef NVM_READ_BLOCK
#   define NVM_READ_BLOCK (6U)
#  endif

#  ifndef NVM_WRITE_BLOCK
#   define NVM_WRITE_BLOCK (7U)
#  endif

#  ifndef NVM_RESTORE_BLOCK_DEFAULTS
#   define NVM_RESTORE_BLOCK_DEFAULTS (8U)
#  endif

#  ifndef NVM_ERASE_BLOCK
#   define NVM_ERASE_BLOCK (9U)
#  endif

#  ifndef NVM_INVALIDATE_NV_BLOCK
#   define NVM_INVALIDATE_NV_BLOCK (11U)
#  endif

#  ifndef NVM_READ_ALL
#   define NVM_READ_ALL (12U)
#  endif

#  ifndef Cx0_Not_connected
#   define Cx0_Not_connected (0U)
#  endif

#  ifndef Cx1_Connected
#   define Cx1_Connected (1U)
#  endif

#  ifndef Cx1_ACCIGN1IGN2_Relay_failure_ACC_Reserved_
#   define Cx1_ACCIGN1IGN2_Relay_failure_ACC_Reserved_ (1U)
#  endif

#  ifndef Cx00_value
#   define Cx00_value (0U)
#  endif

#  ifndef Cx63_value
#   define Cx63_value (99U)
#  endif

#  ifndef Cx64_Finish
#   define Cx64_Finish (100U)
#  endif

#  ifndef Cx65_reserved
#   define Cx65_reserved (101U)
#  endif

#  ifndef Cx7F_reserved
#   define Cx7F_reserved (127U)
#  endif

#  ifndef Cx1_Failure
#   define Cx1_Failure (1U)
#  endif

#  ifndef Cx0_Tone_0_No_warning
#   define Cx0_Tone_0_No_warning (0U)
#  endif

#  ifndef Cx1_Tone_1_Long_beep
#   define Cx1_Tone_1_Long_beep (1U)
#  endif

#  ifndef Cx2_Tone_2_1_5_Hz
#   define Cx2_Tone_2_1_5_Hz (2U)
#  endif

#  ifndef Cx3_Tone_3_3Hz
#   define Cx3_Tone_3_3Hz (3U)
#  endif

#  ifndef Cx1_Triggered
#   define Cx1_Triggered (1U)
#  endif

#  ifndef Cx1_Warning_level_1_2Hz_
#   define Cx1_Warning_level_1_2Hz_ (1U)
#  endif

#  ifndef Cx2_Warning_level_2_4Hz_
#   define Cx2_Warning_level_2_4Hz_ (2U)
#  endif

#  ifndef Cx3_Warning_level_3_
#   define Cx3_Warning_level_3_ (3U)
#  endif

#  ifndef Cx1_RCW_level_1
#   define Cx1_RCW_level_1 (1U)
#  endif

#  ifndef Cx2_RCW_level_2
#   define Cx2_RCW_level_2 (2U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Trailer
#   define Cx1_Trailer (1U)
#  endif

#  ifndef Cx0_UnLocked
#   define Cx0_UnLocked (0U)
#  endif

#  ifndef Cx1_Locked
#   define Cx1_Locked (1U)
#  endif

#  ifndef Cx2_Over_Speed_Warning
#   define Cx2_Over_Speed_Warning (2U)
#  endif

#  ifndef Cx3_Driving_Mode_Select_Error
#   define Cx3_Driving_Mode_Select_Error (3U)
#  endif

#  ifndef Cx4_Lock_Request_Deny
#   define Cx4_Lock_Request_Deny (4U)
#  endif

#  ifndef CxD_Reserved
#   define CxD_Reserved (13U)
#  endif

#  ifndef CxE_Fault
#   define CxE_Fault (14U)
#  endif

#  ifndef Cx0_Normal_mode
#   define Cx0_Normal_mode (0U)
#  endif

#  ifndef Cx1_Remote_mode
#   define Cx1_Remote_mode (1U)
#  endif

#  ifndef Cx0_no_request
#   define Cx0_no_request (0U)
#  endif

#  ifndef Cx1_The_front_car_has_started
#   define Cx1_The_front_car_has_started (1U)
#  endif

#  ifndef Cx2_The_front_car_has_started_Please_pay_attention_to_the_road_environment
#   define Cx2_The_front_car_has_started_Please_pay_attention_to_the_road_environment (2U)
#  endif

#  ifndef Cx3_The_front_car_has_started_please_keep_your_attention
#   define Cx3_The_front_car_has_started_please_keep_your_attention (3U)
#  endif

#  ifndef Cx4_The_front_car_has_started_please_take_over_the_car
#   define Cx4_The_front_car_has_started_please_take_over_the_car (4U)
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

#  ifndef Cx1_ACC_reserved_
#   define Cx1_ACC_reserved_ (1U)
#  endif

#  ifndef Cx2_ON
#   define Cx2_ON (2U)
#  endif

#  ifndef Cx3_Crank
#   define Cx3_Crank (3U)
#  endif

#  ifndef Cx0_Function_OFF
#   define Cx0_Function_OFF (0U)
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

#  ifndef Cx0_Select_lever_in_position_P_
#   define Cx0_Select_lever_in_position_P_ (0U)
#  endif

#  ifndef Cx1_Reserved
#   define Cx1_Reserved (1U)
#  endif

#  ifndef Cx5_Select_lever_in_position_D_
#   define Cx5_Select_lever_in_position_D_ (5U)
#  endif

#  ifndef Cx6_Select_lever_in_position_N_
#   define Cx6_Select_lever_in_position_N_ (6U)
#  endif

#  ifndef Cx7_Select_lever_in_position_R_
#   define Cx7_Select_lever_in_position_R_ (7U)
#  endif

#  ifndef Cx8_Select_lever_in_position_M_
#   define Cx8_Select_lever_in_position_M_ (8U)
#  endif

#  ifndef CxE_Intermediate_position
#   define CxE_Intermediate_position (14U)
#  endif

#  ifndef Cx0_off
#   define Cx0_off (0U)
#  endif

#  ifndef Cx1_ACC_selected
#   define Cx1_ACC_selected (1U)
#  endif

#  ifndef Cx2_TJAICA_selected
#   define Cx2_TJAICA_selected (2U)
#  endif

#  ifndef Cx3_Off_selected
#   define Cx3_Off_selected (3U)
#  endif

#  ifndef Cx4_ACC_on
#   define Cx4_ACC_on (4U)
#  endif

#  ifndef Cx5_TJAICA_on
#   define Cx5_TJAICA_on (5U)
#  endif

#  ifndef Cx0_No_Follow
#   define Cx0_No_Follow (0U)
#  endif

#  ifndef Cx1_Follow_Vehicle
#   define Cx1_Follow_Vehicle (1U)
#  endif

#  ifndef Cx1_Unable_to_activate_TJAICA_due_to_other_limitation
#   define Cx1_Unable_to_activate_TJAICA_due_to_other_limitation (1U)
#  endif

#  ifndef Cx2_TJAICA_active_control_is_cancelled
#   define Cx2_TJAICA_active_control_is_cancelled (2U)
#  endif

#  ifndef Cx3_TJAICA_temporarily_unavailable
#   define Cx3_TJAICA_temporarily_unavailable (3U)
#  endif

#  ifndef Cx4_Current_IGN_Cycle_Function_Inhibit
#   define Cx4_Current_IGN_Cycle_Function_Inhibit (4U)
#  endif

#  ifndef Cx1_Passive_mode
#   define Cx1_Passive_mode (1U)
#  endif

#  ifndef Cx2_Active_mode
#   define Cx2_Active_mode (2U)
#  endif

#  ifndef Cx3_Ready_mode
#   define Cx3_Ready_mode (3U)
#  endif

#  ifndef Cx4_Failure
#   define Cx4_Failure (4U)
#  endif

#  ifndef Cx00_No_Display
#   define Cx00_No_Display (0U)
#  endif

#  ifndef Cx01_SPL_5
#   define Cx01_SPL_5 (1U)
#  endif

#  ifndef Cx02_SPL_10
#   define Cx02_SPL_10 (2U)
#  endif

#  ifndef Cx03_SPL_15
#   define Cx03_SPL_15 (3U)
#  endif

#  ifndef Cx04_SPL_20
#   define Cx04_SPL_20 (4U)
#  endif

#  ifndef Cx05_SPL_25
#   define Cx05_SPL_25 (5U)
#  endif

#  ifndef Cx06_SPL_30
#   define Cx06_SPL_30 (6U)
#  endif

#  ifndef Cx07_SPL_35
#   define Cx07_SPL_35 (7U)
#  endif

#  ifndef Cx08_SPL_40
#   define Cx08_SPL_40 (8U)
#  endif

#  ifndef Cx09_SPL_45
#   define Cx09_SPL_45 (9U)
#  endif

#  ifndef Cx0A_SPL_50
#   define Cx0A_SPL_50 (10U)
#  endif

#  ifndef Cx0B_SPL_55
#   define Cx0B_SPL_55 (11U)
#  endif

#  ifndef Cx0C_SPL_60
#   define Cx0C_SPL_60 (12U)
#  endif

#  ifndef Cx0D_SPL_65
#   define Cx0D_SPL_65 (13U)
#  endif

#  ifndef Cx0E_SPL_70
#   define Cx0E_SPL_70 (14U)
#  endif

#  ifndef Cx0F_SPL_75
#   define Cx0F_SPL_75 (15U)
#  endif

#  ifndef Cx10_SPL_80
#   define Cx10_SPL_80 (16U)
#  endif

#  ifndef Cx11_SPL_85
#   define Cx11_SPL_85 (17U)
#  endif

#  ifndef Cx12_SPL_90
#   define Cx12_SPL_90 (18U)
#  endif

#  ifndef Cx13_SPL_95
#   define Cx13_SPL_95 (19U)
#  endif

#  ifndef Cx14_SPL_100
#   define Cx14_SPL_100 (20U)
#  endif

#  ifndef Cx15_SPL_105
#   define Cx15_SPL_105 (21U)
#  endif

#  ifndef Cx16_SPL_110
#   define Cx16_SPL_110 (22U)
#  endif

#  ifndef Cx17_SPL_115
#   define Cx17_SPL_115 (23U)
#  endif

#  ifndef Cx18_SPL_120
#   define Cx18_SPL_120 (24U)
#  endif

#  ifndef Cx19_SPL_125
#   define Cx19_SPL_125 (25U)
#  endif

#  ifndef Cx1A_SPL_130
#   define Cx1A_SPL_130 (26U)
#  endif

#  ifndef Cx1B_SPL_135
#   define Cx1B_SPL_135 (27U)
#  endif

#  ifndef Cx1C_SPL_140
#   define Cx1C_SPL_140 (28U)
#  endif

#  ifndef Cx1D_SPL_145
#   define Cx1D_SPL_145 (29U)
#  endif

#  ifndef Cx1E_SPL_150
#   define Cx1E_SPL_150 (30U)
#  endif

#  ifndef Cx3E_Reserved
#   define Cx3E_Reserved (62U)
#  endif

#  ifndef Cx3F_Invalid
#   define Cx3F_Invalid (63U)
#  endif

#  ifndef Cx0_Null
#   define Cx0_Null (0U)
#  endif

#  ifndef Cx1_Implicit
#   define Cx1_Implicit (1U)
#  endif

#  ifndef Cx2_Explicit
#   define Cx2_Explicit (2U)
#  endif

#  ifndef Cx0_No_Speed_Limit
#   define Cx0_No_Speed_Limit (0U)
#  endif

#  ifndef Cx1_Speed_Limit
#   define Cx1_Speed_Limit (1U)
#  endif

#  ifndef Cx2_Speed_Limit_Cancel
#   define Cx2_Speed_Limit_Cancel (2U)
#  endif

#  ifndef Cx1_Fusion_mode
#   define Cx1_Fusion_mode (1U)
#  endif

#  ifndef Cx2_Vision_mode
#   define Cx2_Vision_mode (2U)
#  endif

#  ifndef Cx3_Navigation_only_mode
#   define Cx3_Navigation_only_mode (3U)
#  endif

#  ifndef Cx00_None
#   define Cx00_None (0U)
#  endif

#  ifndef Cx01_Snow
#   define Cx01_Snow (1U)
#  endif

#  ifndef Cx02_Fog
#   define Cx02_Fog (2U)
#  endif

#  ifndef Cx03_ThunderStorm
#   define Cx03_ThunderStorm (3U)
#  endif

#  ifndef Cx04_Rain
#   define Cx04_Rain (4U)
#  endif

#  ifndef Cx05_FWay
#   define Cx05_FWay (5U)
#  endif

#  ifndef Cx06_EFWay
#   define Cx06_EFWay (6U)
#  endif

#  ifndef Cx07_Straight
#   define Cx07_Straight (7U)
#  endif

#  ifndef Cx08_FrontageLeft
#   define Cx08_FrontageLeft (8U)
#  endif

#  ifndef Cx09_TurnLeftRight
#   define Cx09_TurnLeftRight (9U)
#  endif

#  ifndef Cx0A_FrontageRight
#   define Cx0A_FrontageRight (10U)
#  endif

#  ifndef Cx0B_Right
#   define Cx0B_Right (11U)
#  endif

#  ifndef Cx0C_TurnRight
#   define Cx0C_TurnRight (12U)
#  endif

#  ifndef Cx0D_Left
#   define Cx0D_Left (13U)
#  endif

#  ifndef Cx0E_TurnLeft
#   define Cx0E_TurnLeft (14U)
#  endif

#  ifndef Cx0F_RelieveNoOvertake
#   define Cx0F_RelieveNoOvertake (15U)
#  endif

#  ifndef Cx10_NoOvertake
#   define Cx10_NoOvertake (16U)
#  endif

#  ifndef Cx11_StopGiveWay
#   define Cx11_StopGiveWay (17U)
#  endif

#  ifndef Cx12_GiveWay
#   define Cx12_GiveWay (18U)
#  endif

#  ifndef Cx13_NoPass
#   define Cx13_NoPass (19U)
#  endif

#  ifndef Cx14_NoEntry
#   define Cx14_NoEntry (20U)
#  endif

#  ifndef Cx15_NoCar
#   define Cx15_NoCar (21U)
#  endif

#  ifndef Cx16_NoTruck
#   define Cx16_NoTruck (22U)
#  endif

#  ifndef Cx17_NoBus
#   define Cx17_NoBus (23U)
#  endif

#  ifndef Cx18_NoTurnaround
#   define Cx18_NoTurnaround (24U)
#  endif

#  ifndef Cx19_NoStraightLeftTurn
#   define Cx19_NoStraightLeftTurn (25U)
#  endif

#  ifndef Cx1A_NoStraightRightTurn
#   define Cx1A_NoStraightRightTurn (26U)
#  endif

#  ifndef Cx1B_NoLeftRightTurn
#   define Cx1B_NoLeftRightTurn (27U)
#  endif

#  ifndef Cx1C_NoLeftTurn
#   define Cx1C_NoLeftTurn (28U)
#  endif

#  ifndef Cx1D_NoRightTurn
#   define Cx1D_NoRightTurn (29U)
#  endif

#  ifndef Cx1E_NoStraight
#   define Cx1E_NoStraight (30U)
#  endif

#  ifndef Cx1F_WarnKids
#   define Cx1F_WarnKids (31U)
#  endif

#  ifndef Cx20_WarnPed
#   define Cx20_WarnPed (32U)
#  endif

#  ifndef Cx21_WarnBike
#   define Cx21_WarnBike (33U)
#  endif

#  ifndef Cx22_WarnWorks
#   define Cx22_WarnWorks (34U)
#  endif

#  ifndef Cx23_WarnWildanimal
#   define Cx23_WarnWildanimal (35U)
#  endif

#  ifndef Cx24_WarnCattle
#   define Cx24_WarnCattle (36U)
#  endif

#  ifndef Cx25_AccidentProneSection
#   define Cx25_AccidentProneSection (37U)
#  endif

#  ifndef Cx26_Town
#   define Cx26_Town (38U)
#  endif

#  ifndef Cx27_Slow
#   define Cx27_Slow (39U)
#  endif

#  ifndef Cx28_SharpTurnR
#   define Cx28_SharpTurnR (40U)
#  endif

#  ifndef Cx29_SharpTurnL
#   define Cx29_SharpTurnL (41U)
#  endif

#  ifndef Cx2A_ReverseCurveL
#   define Cx2A_ReverseCurveL (42U)
#  endif

#  ifndef Cx2B_ReverseCurveR
#   define Cx2B_ReverseCurveR (43U)
#  endif

#  ifndef Cx2C_ContinuousBend
#   define Cx2C_ContinuousBend (44U)
#  endif

#  ifndef Cx2D_Crossroads
#   define Cx2D_Crossroads (45U)
#  endif

#  ifndef Cx2E_ConfluenceR
#   define Cx2E_ConfluenceR (46U)
#  endif

#  ifndef Cx2F_ConfluenceL
#   define Cx2F_ConfluenceL (47U)
#  endif

#  ifndef Cx30_RainWetness
#   define Cx30_RainWetness (48U)
#  endif

#  ifndef Cx31_SnowIcy
#   define Cx31_SnowIcy (49U)
#  endif

#  ifndef Cx32_Time
#   define Cx32_Time (50U)
#  endif

#  ifndef Cx33_Distance_For
#   define Cx33_Distance_For (51U)
#  endif

#  ifndef Cx34_Distance_In
#   define Cx34_Distance_In (52U)
#  endif

#  ifndef Cx35_Straight
#   define Cx35_Straight (53U)
#  endif

#  ifndef Cx36_FrontageLeft
#   define Cx36_FrontageLeft (54U)
#  endif

#  ifndef Cx37_TurnLeftRight
#   define Cx37_TurnLeftRight (55U)
#  endif

#  ifndef Cx38_FrontageRight
#   define Cx38_FrontageRight (56U)
#  endif

#  ifndef Cx39_Right
#   define Cx39_Right (57U)
#  endif

#  ifndef Cx3A_Turn_Right
#   define Cx3A_Turn_Right (58U)
#  endif

#  ifndef Cx3B_Left
#   define Cx3B_Left (59U)
#  endif

#  ifndef Cx3C_Turn_Left
#   define Cx3C_Turn_Left (60U)
#  endif

#  ifndef Cx3D_Highway_Start
#   define Cx3D_Highway_Start (61U)
#  endif

#  ifndef Cx3E_Highway_End
#   define Cx3E_Highway_End (62U)
#  endif

#  ifndef Cx3F_Mortorway_Start
#   define Cx3F_Mortorway_Start (63U)
#  endif

#  ifndef Cx40_Mortorway_End
#   define Cx40_Mortorway_End (64U)
#  endif

#  ifndef Cx41_City_Entry
#   define Cx41_City_Entry (65U)
#  endif

#  ifndef Cx42_City_Exit
#   define Cx42_City_Exit (66U)
#  endif

#  ifndef Cx43_Residential_zones_Entry
#   define Cx43_Residential_zones_Entry (67U)
#  endif

#  ifndef Cx44_Residential_zones_Exit
#   define Cx44_Residential_zones_Exit (68U)
#  endif

#  ifndef Cx45_Trailer
#   define Cx45_Trailer (69U)
#  endif

#  ifndef Cx46_Reserved
#   define Cx46_Reserved (70U)
#  endif

#  ifndef CxFE_Reserved
#   define CxFE_Reserved (254U)
#  endif

#  ifndef CxFF_Invalid
#   define CxFF_Invalid (255U)
#  endif

#  ifndef Cx00_No_error
#   define Cx00_No_error (0U)
#  endif

#  ifndef Cx01_Error
#   define Cx01_Error (1U)
#  endif

#  ifndef Cx02_Standby_Battery_Error
#   define Cx02_Standby_Battery_Error (2U)
#  endif

#  ifndef Cx03_Reserved
#   define Cx03_Reserved (3U)
#  endif

#  ifndef Cx1_valid
#   define Cx1_valid (1U)
#  endif

#  ifndef Cx0_Not_Initialized
#   define Cx0_Not_Initialized (0U)
#  endif

#  ifndef Cx1_Normal
#   define Cx1_Normal (1U)
#  endif

#  ifndef Cx2_Faulty
#   define Cx2_Faulty (2U)
#  endif

#  ifndef Cx0_Trailer_off
#   define Cx0_Trailer_off (0U)
#  endif

#  ifndef Cx1_Trailer_on
#   define Cx1_Trailer_on (1U)
#  endif

#  ifndef Cx0_Normal_Mode
#   define Cx0_Normal_Mode (0U)
#  endif

#  ifndef Cx1_Transport_Mode
#   define Cx1_Transport_Mode (1U)
#  endif

#  ifndef Cx0_sound_1
#   define Cx0_sound_1 (0U)
#  endif

#  ifndef Cx1_sound_2
#   define Cx1_sound_2 (1U)
#  endif

#  ifndef Cx2_sound_3
#   define Cx2_sound_3 (2U)
#  endif

#  ifndef Cx0_Standby
#   define Cx0_Standby (0U)
#  endif

#  ifndef Cx1_Sound_on
#   define Cx1_Sound_on (1U)
#  endif

#  ifndef Cx2_Fault
#   define Cx2_Fault (2U)
#  endif

#  ifndef Cx3_OFF
#   define Cx3_OFF (3U)
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

#  ifndef Cx0_No_Fault
#   define Cx0_No_Fault (0U)
#  endif

#  ifndef Cx1_Foreign_Object_Detection_FOD
#   define Cx1_Foreign_Object_Detection_FOD (1U)
#  endif

#  ifndef Cx2_Over_Voltage_Protection_OVP
#   define Cx2_Over_Voltage_Protection_OVP (2U)
#  endif

#  ifndef Cx3_Low_Voltage_Protection_LVP
#   define Cx3_Low_Voltage_Protection_LVP (3U)
#  endif

#  ifndef Cx4_Over_Temperature_Protection_OTP
#   define Cx4_Over_Temperature_Protection_OTP (4U)
#  endif

#  ifndef Cx5_System_Fault
#   define Cx5_System_Fault (5U)
#  endif

#  ifndef Cx0_No_need_to_remind
#   define Cx0_No_need_to_remind (0U)
#  endif

#  ifndef Cx1_Remind_forgotten_phone
#   define Cx1_Remind_forgotten_phone (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_COMMON_NORMAL_TYPE_H */
