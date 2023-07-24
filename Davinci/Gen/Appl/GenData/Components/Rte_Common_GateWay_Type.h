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
 *             File:  Rte_Common_GateWay_Type.h
 *           Config:  HUT_V3_5.dpa
 *      ECU-Project:  HUT_V3_5
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  Application types header file for SW-C <Common_GateWay>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMMON_GATEWAY_TYPE_H
# define RTE_COMMON_GATEWAY_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_No_Display
#   define Cx0_No_Display (0U)
#  endif

#  ifndef Cx1_Override
#   define Cx1_Override (1U)
#  endif

#  ifndef Cx2_Deceleration
#   define Cx2_Deceleration (2U)
#  endif

#  ifndef Cx3_Reserved
#   define Cx3_Reserved (3U)
#  endif

#  ifndef Cx0_Fuction_Not_Available
#   define Cx0_Fuction_Not_Available (0U)
#  endif

#  ifndef Cx1_Fuction_Available
#   define Cx1_Fuction_Available (1U)
#  endif

#  ifndef Cx2_Performance_degradation
#   define Cx2_Performance_degradation (2U)
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

#  ifndef Cx1_Automatic_lane_change_function_failure
#   define Cx1_Automatic_lane_change_function_failure (1U)
#  endif

#  ifndef Cx2_Reserve
#   define Cx2_Reserve (2U)
#  endif

#  ifndef Cx3_Reserve
#   define Cx3_Reserve (3U)
#  endif

#  ifndef CxFF_Valid_value
#   define CxFF_Valid_value (255U)
#  endif

#  ifndef Cx00_Valid_values
#   define Cx00_Valid_values (0U)
#  endif

#  ifndef CxFF_Valid_values
#   define CxFF_Valid_values (255U)
#  endif

#  ifndef COMM_NO_COMMUNICATION
#   define COMM_NO_COMMUNICATION (0U)
#  endif

#  ifndef COMM_SILENT_COMMUNICATION
#   define COMM_SILENT_COMMUNICATION (1U)
#  endif

#  ifndef COMM_FULL_COMMUNICATION
#   define COMM_FULL_COMMUNICATION (2U)
#  endif

#  ifndef Cx2_cancle_parking
#   define Cx2_cancle_parking (2U)
#  endif

#  ifndef Cx3_invalid
#   define Cx3_invalid (3U)
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

#  ifndef Cx4_Reserved
#   define Cx4_Reserved (4U)
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

#  ifndef TC_ENERGY_RESP
#   define TC_ENERGY_RESP (0U)
#  endif

#  ifndef TC_ENERGY_PER_1KM
#   define TC_ENERGY_PER_1KM (1U)
#  endif

#  ifndef TC_ENERGY_DTE
#   define TC_ENERGY_DTE (2U)
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

#  ifndef Cx3_reserved
#   define Cx3_reserved (3U)
#  endif

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
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

#  ifndef CxE_Reserved
#   define CxE_Reserved (14U)
#  endif

#  ifndef CxF_Fault
#   define CxF_Fault (15U)
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

#  ifndef Cx0_No_Warning
#   define Cx0_No_Warning (0U)
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

#  ifndef Cx0_No_failure
#   define Cx0_No_failure (0U)
#  endif

#  ifndef Cx1_Failure
#   define Cx1_Failure (1U)
#  endif

#  ifndef Cx2_Signal_not_available
#   define Cx2_Signal_not_available (2U)
#  endif

#  ifndef Cx1_ON
#   define Cx1_ON (1U)
#  endif

#  ifndef Cx2_Internal_Error
#   define Cx2_Internal_Error (2U)
#  endif

#  ifndef Cx0_Valid_Value
#   define Cx0_Valid_Value (0U)
#  endif

#  ifndef Cx3_Valid_Value
#   define Cx3_Valid_Value (3U)
#  endif

#  ifndef Cx4_Initial_value
#   define Cx4_Initial_value (4U)
#  endif

#  ifndef Cx000_Invalid_value
#   define Cx000_Invalid_value (0U)
#  endif

#  ifndef Cx001_Reserved
#   define Cx001_Reserved (1U)
#  endif

#  ifndef Cx009_Reserved
#   define Cx009_Reserved (9U)
#  endif

#  ifndef Cx00A_Valid_value
#   define Cx00A_Valid_value (10U)
#  endif

#  ifndef Cx3E8_Valid_value
#   define Cx3E8_Valid_value (1000U)
#  endif

#  ifndef Cx3E9_Reserved
#   define Cx3E9_Reserved (1001U)
#  endif

#  ifndef Cx3FE_Reserved
#   define Cx3FE_Reserved (1022U)
#  endif

#  ifndef Cx3FF_Invalid_value
#   define Cx3FF_Invalid_value (1023U)
#  endif

#  ifndef Cx00_Valid_Value
#   define Cx00_Valid_Value (0U)
#  endif

#  ifndef CxC8_Valid_Value
#   define CxC8_Valid_Value (200U)
#  endif

#  ifndef CxC9_Reserved
#   define CxC9_Reserved (201U)
#  endif

#  ifndef CxFE_Reserved
#   define CxFE_Reserved (254U)
#  endif

#  ifndef CxFF_Invalid_Value
#   define CxFF_Invalid_Value (255U)
#  endif

#  ifndef Cx0_Chinese
#   define Cx0_Chinese (0U)
#  endif

#  ifndef Cx1_English
#   define Cx1_English (1U)
#  endif

#  ifndef Cx2_Russian
#   define Cx2_Russian (2U)
#  endif

#  ifndef Cx3_Spaish
#   define Cx3_Spaish (3U)
#  endif

#  ifndef Cx4_Portuguese
#   define Cx4_Portuguese (4U)
#  endif

#  ifndef Cx5_German
#   define Cx5_German (5U)
#  endif

#  ifndef Cx6_French
#   define Cx6_French (6U)
#  endif

#  ifndef Cx7_Italian
#   define Cx7_Italian (7U)
#  endif

#  ifndef Cx8_Arabic
#   define Cx8_Arabic (8U)
#  endif

#  ifndef Cx9_Thai
#   define Cx9_Thai (9U)
#  endif

#  ifndef CxA_Ukrainian
#   define CxA_Ukrainian (10U)
#  endif

#  ifndef CxB_Indonesian
#   define CxB_Indonesian (11U)
#  endif

#  ifndef CxC_Reserve
#   define CxC_Reserve (12U)
#  endif

#  ifndef CxF_Invalid_value
#   define CxF_Invalid_value (15U)
#  endif

#  ifndef Cx000_0_2000
#   define Cx000_0_2000 (0U)
#  endif

#  ifndef Cx7D0_0_2000
#   define Cx7D0_0_2000 (2000U)
#  endif

#  ifndef Cx7D1_Reserved
#   define Cx7D1_Reserved (2001U)
#  endif

#  ifndef CxFFE_Reserved
#   define CxFFE_Reserved (4094U)
#  endif

#  ifndef CxFFF_Invalid
#   define CxFFF_Invalid (4095U)
#  endif

#  ifndef Cx00_Valid
#   define Cx00_Valid (0U)
#  endif

#  ifndef CxFE_Valid
#   define CxFE_Valid (254U)
#  endif

#  ifndef CxFF_Invalid
#   define CxFF_Invalid (255U)
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

#  ifndef Cx0_Not_active
#   define Cx0_Not_active (0U)
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

#  ifndef Cx0_No_request
#   define Cx0_No_request (0U)
#  endif

#  ifndef Cx1_Request_park_Shift
#   define Cx1_Request_park_Shift (1U)
#  endif

#  ifndef Cx2_Invalid
#   define Cx2_Invalid (2U)
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

#  ifndef Cx0_No_select
#   define Cx0_No_select (0U)
#  endif

#  ifndef Cx1_Front_vertical_head_park_straight
#   define Cx1_Front_vertical_head_park_straight (1U)
#  endif

#  ifndef Cx2_Rear_vertical_tail_park_straight
#   define Cx2_Rear_vertical_tail_park_straight (2U)
#  endif

#  ifndef Cx1_Request_suspend
#   define Cx1_Request_suspend (1U)
#  endif

#  ifndef Cx2_Request_finish
#   define Cx2_Request_finish (2U)
#  endif

#  ifndef Cx0_No_action
#   define Cx0_No_action (0U)
#  endif

#  ifndef Cx1_Parking_in_car
#   define Cx1_Parking_in_car (1U)
#  endif

#  ifndef Cx2_Remote_parking
#   define Cx2_Remote_parking (2U)
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

#  ifndef Cx0_Release
#   define Cx0_Release (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  ifndef Cx2_Hold
#   define Cx2_Hold (2U)
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

#  ifndef Cx0_Segment_0
#   define Cx0_Segment_0 (0U)
#  endif

#  ifndef Cx1_Segment_1
#   define Cx1_Segment_1 (1U)
#  endif

#  ifndef Cx2_Segment_2
#   define Cx2_Segment_2 (2U)
#  endif

#  ifndef Cx3_Segment_3
#   define Cx3_Segment_3 (3U)
#  endif

#  ifndef Cx4_Segment_4
#   define Cx4_Segment_4 (4U)
#  endif

#  ifndef Cx5_Segment_5
#   define Cx5_Segment_5 (5U)
#  endif

#  ifndef Cx6_Segment_6
#   define Cx6_Segment_6 (6U)
#  endif

#  ifndef Cx7_Segment_7
#   define Cx7_Segment_7 (7U)
#  endif

#  ifndef Cx8_Segment_8
#   define Cx8_Segment_8 (8U)
#  endif

#  ifndef Cx9_Error
#   define Cx9_Error (9U)
#  endif

#  ifndef Cx000_Valid_value
#   define Cx000_Valid_value (0U)
#  endif

#  ifndef Cx7A8_Valid_value
#   define Cx7A8_Valid_value (1960U)
#  endif

#  ifndef Cx7A9_Invalid
#   define Cx7A9_Invalid (1961U)
#  endif

#  ifndef Cx7FF_Invalid
#   define Cx7FF_Invalid (2047U)
#  endif

#  ifndef Cx2D0_Valid_value
#   define Cx2D0_Valid_value (720U)
#  endif

#  ifndef Cx2D1_Invalid
#   define Cx2D1_Invalid (721U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_COMMON_GATEWAY_TYPE_H */
