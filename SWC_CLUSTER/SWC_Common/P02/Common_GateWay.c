/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Common_GateWay.c
 *           Config:  D:/IntegerationProject/VIP_P02/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Common_GateWay
 *  Generation Time:  2021-08-06 17:08:09
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Common_GateWay>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ComEx_SignalGroupIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * ComEx_SignalIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * ComM_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ServiceIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_Common_GateWay.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_IPC_Interface.h"
#include "SWC_IPC_CANMatrix.h"
#include "SWC_AL_Interface.h"

#include "SWC_CA_Config.h"
#include "SWC_CA_Interface.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ACC_LeTgtDx: Integer in interval [0...65535]
 * ACC_LeTgtDy: Integer in interval [0...255]
 * ACC_ObjDetecte_4: Boolean
 * ACC_PotentialTgtDx: Integer in interval [0...65535]
 * ACC_PotentialTgtDy: Integer in interval [0...255]
 * ACC_RiTgtDx: Integer in interval [0...65535]
 * ACC_RiTgtDy: Integer in interval [0...255]
 * ACC_RlvTgtDx: Integer in interval [0...65535]
 * ACC_RlvTgtDy: Integer in interval [0...255]
 * ACC_TakeOverReq_4: Boolean
 * ADAS_DriverInloop_Monitor_2: Integer in interval [0...255]
 * ALC_Resp: Boolean
 * ComEx_ConstSignalDataType: DataReference
 * ComEx_SignalGroupIdType: Integer in interval [0...65535]
 * ComEx_SignalIdType: Integer in interval [0...65535]
 * ContnPrkgReqValid: Boolean
 * DetVideoLost: Boolean
 * HWA_Resp: Boolean
 * ICA_HandsOffResp: Boolean
 * IP_ACCErr: Boolean
 * IP_AvgFuelCons: Integer in interval [0...4095]
 * IP_Err: Boolean
 * IP_InstFuelCons: Integer in interval [0...16383]
 * IP_InstFuelConsUnit: Boolean
 * IP_VINcompr: Boolean
 * IP_VehSpdDisp: Integer in interval [0...511]
 * IP_VehSpdUnit: Boolean
 * IP_VehTotDistanceValid: Boolean
 * IP_VehTotDistance_2: Integer in interval [0...4294967295]
 * ISL_Resp: Boolean
 * Longctrl_DecelToStopReq_DVR: Boolean
 * Longctrl_Decel_ReqValue_DVR_1: Integer in interval [0...255]
 * Longctrl_Decel_Req_DVR: Boolean
 * Longctrl_DrvOFF_Req_DVR: Boolean
 * Longctrl_EngTrqReqActive_DVR: Boolean
 * Longctrl_EngTrqReq_DVR_1: Integer in interval [0...65535]
 * Longctrl_HCUTrqReqActive_DVR: Boolean
 * Longctrl_HCUTrqReq_DVR_2: Integer in interval [0...65535]
 * Longctrl_VehHldReq_DVR: Boolean
 * PrkStraightContinueReq_HUT: Boolean
 * PrkStraightStrtReq_HUT: Boolean
 * PrkStraightSts_HUT: Boolean
 * PrkStraightSwtReq_HUT: Boolean
 * PrkStraightVehStrtReq_HUT_Valid: Boolean
 * PrkgCtrlModReqValid: Boolean
 * Rte_DT_IPC_Config_Type_0: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_0: Integer in interval [0...65535]
 * Rte_DT_MenuSetData_t_1: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_10: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_11: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_12: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_2: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_3: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_4: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_5: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_6: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_7: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_8: Integer in interval [0...255]
 * Rte_DT_MenuSetData_t_9: Integer in interval [0...255]
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * dummy_ACC_FD2_11: Integer in interval [0...255]
 * dummy_ACC_FD2_12: Boolean
 * dummy_ACC_FD2_13: Integer in interval [0...255]
 * dummy_ACC_FD2_14: Integer in interval [0...255]
 * dummy_ACC_FD2_15: Integer in interval [0...255]
 * dummy_ACC_FD2_16: Boolean
 * dummy_ACC_FD2_17: Boolean
 * dummy_ACC_FD2_18: Integer in interval [0...255]
 * dummy_ACC_FD2_19: Integer in interval [0...255]
 * dummy_ACC_FD2_20: Boolean
 * dummy_ACC_FD2_4: Boolean
 * dummy_ACC_FD2_5: Boolean
 * dummy_ACC_FD2_6: Integer in interval [0...255]
 * dummy_ACC_FD2_7: Integer in interval [0...255]
 * sint64: Integer in interval [-9223372036854775808...9223372036854775807] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ACC_EgoStatus: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Display (0U)
 *   Cx1_Override (1U)
 *   Cx2_Deceleration (2U)
 *   Cx3_Reserved (3U)
 * ACC_FctSts_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Fuction_Not_Available (0U)
 *   Cx1_Fuction_Available (1U)
 *   Cx2_Performance_degradation (2U)
 *   Cx3_Reserved (3U)
 * ACC_InterSysInfoDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_display (0U)
 *   Cx01_Unable_to_activate_ACC_due_to_speed_not_achive (1U)
 *   Cx02_ACC_active_control_is_cancelled (2U)
 *   Cx03_Resvered (3U)
 *   Cx04_ACC_and_PEBS_temporary_unavailable (4U)
 *   Cx05_Unable_to_activate_ACC_due_to_other_limitation_except_speed_not_achive_ (5U)
 *   Cx06_ACC_and_PEBS_error (6U)
 *   Cx07_ACC_temporary_unavailable (7U)
 *   Cx08_Resvered (8U)
 *   Cx09_Blindness (9U)
 *   Cx0A_Resvered (10U)
 *   Cx1F_Resvered (31U)
 * ACC_LeTargrtDection: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_dectected (0U)
 *   Cx1_Dectected (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ACC_LeTgtTyp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Unkown (0U)
 *   Cx1_Sedan (1U)
 *   Cx2_Truck (2U)
 *   Cx3_Motorcycle (3U)
 *   Cx4_Pedestrian (4U)
 *   Cx5_Bicycle (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * ACC_ModDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_OFF_Mode (0U)
 *   Cx01_Passive_Mode (1U)
 *   Cx02_StandBy_Mode (2U)
 *   Cx03_Active_Control_Mode (3U)
 *   Cx04_Brake_Only_Mode (4U)
 *   Cx05_Override (5U)
 *   Cx06_Reserved (6U)
 *   Cx07_ACC_and_PEBS_Failure_mode (7U)
 *   Cx08_ACC_Failure_mode (8U)
 *   Cx09_Reserved (9U)
 *   Cx1F_Reserved (31U)
 * ACC_PotentialTgtDetn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_dectected (0U)
 *   Cx1_Dectected (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ACC_PotentialTgtTyp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Unkown (0U)
 *   Cx1_Sedan (1U)
 *   Cx2_Truck (2U)
 *   Cx3_Motorcycle (3U)
 *   Cx4_Pedestrian (4U)
 *   Cx5_Bicycle (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * ACC_RiTargrtDetn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_dectected (0U)
 *   Cx1_Dectected (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ACC_RiTgtTyp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Unkown (0U)
 *   Cx1_Sedan (1U)
 *   Cx2_Truck (2U)
 *   Cx3_Motorcycle (3U)
 *   Cx4_Pedestrian (4U)
 *   Cx5_Bicycle (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * ACC_RlvTgtDetn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_dectected (0U)
 *   Cx1_Dectected (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ACC_RlvTgtTyp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Unkown (0U)
 *   Cx1_Sedan (1U)
 *   Cx2_Truck (2U)
 *   Cx3_Motorcycle (3U)
 *   Cx4_Pedestrian (4U)
 *   Cx5_Bicycle (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Invalid (7U)
 * ACC_SpdSetValue_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFE_Valid_value (254U)
 *   CxFF_No_display (255U)
 * ACC_TgtObjBarDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Distance_1_one_bar (1U)
 *   Cx2_Distance_2_two_bars (2U)
 *   Cx3_Distance_3_three_bars (3U)
 *   Cx4_Distance_4_four_bars (4U)
 *   Cx5_Resvered (5U)
 *   Cx7_Resvered (7U)
 * ACC_TimeGapSet_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_TimeGap_1_1s (1U)
 *   Cx2_TimeGap_2_1_4s (2U)
 *   Cx3_TimeGap_3_1_8s (3U)
 *   Cx4_TimeGap_4_2_1s (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * ALC_InterSysInfoDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Automatic_lane_change_function_failure (1U)
 *   Cx2_Reserve (2U)
 *   Cx3_Reserve (3U)
 * CheckSum_HUT32: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * CheckSum_IP2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * Checksum_ACC3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_ACC4_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_ACC6: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_ACC7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_ACC8_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 *   COMM_NO_COMMUNICATION (0U)
 *   COMM_SILENT_COMMUNICATION (1U)
 *   COMM_FULL_COMMUNICATION (2U)
 * ContnPrkgReq: Enumeration of integer in interval [0...255] with enumerators
 *   Cx2_cancle_parking (2U)
 *   Cx3_invalid (3U)
 * CruCha_ModDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF_mode (0U)
 *   Cx1_Idle_mode (1U)
 *   Cx2_Ready_mode (2U)
 *   Cx3_Active (3U)
 *   Cx4_Reserved (4U)
 *   Cx5_Warning_Level_1 (5U)
 *   Cx6_Warning_Level_2 (6U)
 *   Cx7_Warning_Level_3 (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Failure (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * CruChar_InterSysInfoDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Unable_to_activate_CruiseChauffer_due_to_other_limitation (1U)
 *   Cx2_CruiseChauffer_active_control_is_cancelled (2U)
 *   Cx3_CruiseChauffer_temporarily_unavailable (3U)
 *   Cx4_Take_over_request (4U)
 *   Cx5_Current_IGN_Cycle_Function_Inhibit (5U)
 *   Cx6_Please_Keep_Attention (6U)
 *   Cx7_To_cross_the_tunnel_please_take_over_in_time (7U)
 *   Cx8_Have_a_branch_road_ahead_Please_take_over_in_time (8U)
 *   Cx9_Hands_off_warning (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * EnergyInfoDataType: Enumeration of integer in interval [0...255] with enumerators
 *   TC_ENERGY_RESP (0U)
 *   TC_ENERGY_PER_1KM (1U)
 *   TC_ENERGY_DTE (2U)
 * HWA_InterSysInfoDisp_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Unable_to_activate_HWA_due_to_other_limitation (1U)
 *   Cx2_HWA_active_control_is_cancelled (2U)
 *   Cx3_Turn_off_the_turn_light (3U)
 *   Cx4_Active_confirm (4U)
 *   Cx5_Overtime_for_lane_change (5U)
 *   Cx6_lane_change_is_cancelled (6U)
 *   Cx7_HWA_temporary_unavailable (7U)
 *   Cx8_Speed_is_too_low_to_support_lane_change (8U)
 *   Cx9_HWA_need_to_restart_the_engine (9U)
 *   CxA_Take_over_request (10U)
 *   CxB_Please_Keep_Attention (11U)
 *   CxC_To_cross_the_tunnel_please_take_over_in_time (12U)
 *   CxD_Have_a_branch_road_ahead_Please_take_over_in_time (13U)
 *   CxE_Reserve (14U)
 *   CxF_Reserve (15U)
 * HWA_LaneChangeReq_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_left_satisfied (1U)
 *   Cx2_right_satisfied (2U)
 *   Cx3_left_not_satisfied (3U)
 *   Cx4_right_not_satisfied (4U)
 *   Cx5_reserved (5U)
 *   Cx7_reserved (7U)
 * HWA_LaneChange_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_left (1U)
 *   Cx2_right (2U)
 *   Cx3_reserved (3U)
 * HWA_ModDisp_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_Safstop (1U)
 *   Cx2_Passive (2U)
 *   Cx3_Ready (3U)
 *   Cx4_Active (4U)
 *   Cx5_Override (5U)
 *   Cx6_Slow_retreat (6U)
 *   Cx7_Standstill (7U)
 *   Cx8_Reserved (8U)
 *   CxE_Reserved (14U)
 *   CxF_Fault (15U)
 * HWA_SnvtySet_Resp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High_sensitivity (1U)
 *   Cx2_Low_sensitivity (2U)
 *   Cx3_Reserved (3U)
 * HWA_warning_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Warning (0U)
 *   Cx1_Warning_Level_1 (1U)
 *   Cx2_Warning_Level_2 (2U)
 *   Cx3_Warning_Level_3 (3U)
 * IP_ABMWarnLmpFailrSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure (1U)
 *   Cx2_Signal_not_available (2U)
 *   Cx3_Reserved (3U)
 * IP_BattChrgLmpSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 *   Cx2_Internal_Error (2U)
 *   Cx3_Reserved (3U)
 * IP_CurrTheme: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Valid_Value (0U)
 *   Cx3_Valid_Value (3U)
 *   Cx4_Initial_value (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * IP_DrvSeatBeltWarnLmpFailSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure (1U)
 *   Cx2_Signal_not_available (2U)
 *   Cx3_Reserved (3U)
 * IP_EngOilPressLowLmpSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 *   Cx2_Internal_Error (2U)
 *   Cx3_Reserved (3U)
 * IP_FuelAuxTankR: Enumeration of integer in interval [0...1023] with enumerators
 *   Cx000_Invalid_value (0U)
 *   Cx001_Reserved (1U)
 *   Cx009_Reserved (9U)
 *   Cx00A_Valid_value (10U)
 *   Cx3E8_Valid_value (1000U)
 *   Cx3E9_Reserved (1001U)
 *   Cx3FE_Reserved (1022U)
 *   Cx3FF_Invalid_value (1023U)
 * IP_FuelLvlInfo: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_Value (0U)
 *   CxC8_Valid_Value (200U)
 *   CxC9_Reserved (201U)
 *   CxFE_Reserved (254U)
 *   CxFF_Invalid_Value (255U)
 * IP_FuelLvlLowLmpSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_ON (1U)
 *   Cx2_Internal_Error (2U)
 *   Cx3_Reserved (3U)
 * IP_FuelMainTankR: Enumeration of integer in interval [0...1023] with enumerators
 *   Cx000_Invalid_value (0U)
 *   Cx001_Reserved (1U)
 *   Cx009_Reserved (9U)
 *   Cx00A_Valid_value (10U)
 *   Cx3E8_Valid_value (1000U)
 *   Cx3E9_Reserved (1001U)
 *   Cx3FE_Reserved (1022U)
 *   Cx3FF_Invalid_value (1023U)
 * IP_LagueSet: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Chinese (0U)
 *   Cx1_English (1U)
 *   Cx2_Russian (2U)
 *   Cx3_Spaish (3U)
 *   Cx4_Portuguese (4U)
 *   Cx5_German (5U)
 *   Cx6_French (6U)
 *   Cx7_Italian (7U)
 *   Cx8_Arabic (8U)
 *   Cx9_Thai (9U)
 *   CxA_Ukrainian (10U)
 *   CxB_Indonesian (11U)
 *   CxC_Reserve (12U)
 *   CxE_Reserve (14U)
 *   CxF_Invalid_value (15U)
 * IP_PassSeatBeltWarnLmpFailSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure (1U)
 *   Cx2_Signal_not_available (2U)
 *   Cx3_Reserved (3U)
 * IP_RemainDistance: Enumeration of integer in interval [0...4095] with enumerators
 *   Cx000_0_2000 (0U)
 *   Cx7D0_0_2000 (2000U)
 *   Cx7D1_Reserved (2001U)
 *   CxFFE_Reserved (4094U)
 *   CxFFF_Invalid (4095U)
 * IP_VelSpdDisp_Mile: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid (0U)
 *   CxFE_Valid (254U)
 *   CxFF_Invalid (255U)
 * ISL_InterSysInfoDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Speed_Limit_Confirm_Request (1U)
 *   Cx2_Speed_Limit_Take_Over_Request (2U)
 *   Cx3_Resvered (3U)
 * Longctrl_HazActv: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_active (0U)
 *   Cx1_AEB_active (1U)
 *   Cx2_Safestop_active (2U)
 *   Cx3_Reserved (3U)
 * Longctrl_ModSts_DVR: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF_mode (0U)
 *   Cx1_Passive_mode_Reject_ (1U)
 *   Cx2_Passive_mode_Stand_by_ (2U)
 *   Cx3_Active_Control_mode (3U)
 *   Cx4_Brake_only_mode (4U)
 *   Cx5_Override (5U)
 *   Cx6_Standstill (6U)
 *   Cx7_Failure_mode_Longctrl (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Shut_off (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * Longctrl_ParkShiftReq_DVR: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_request (0U)
 *   Cx1_Request_park_Shift (1U)
 *   Cx2_Invalid (2U)
 *   Cx3_Reserved (3U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * NvM_ServiceIdType: Enumeration of integer in interval [6...12] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_READ_BLOCK (6U)
 *   NVM_WRITE_BLOCK (7U)
 *   NVM_RESTORE_BLOCK_DEFAULTS (8U)
 *   NVM_ERASE_BLOCK (9U)
 *   NVM_INVALIDATE_NV_BLOCK (11U)
 *   NVM_READ_ALL (12U)
 * PrkStraightModSel_HUT: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_select (0U)
 *   Cx1_Front_vertical_head_park_straight (1U)
 *   Cx2_Rear_vertical_tail_park_straight (2U)
 *   Cx3_Reserved (3U)
 * PrkStraightSuspendOrFinishReq_HUT: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_request (0U)
 *   Cx1_Request_suspend (1U)
 *   Cx2_Request_finish (2U)
 *   Cx3_Reserved (3U)
 * PrkgCtrlModReq: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_action (0U)
 *   Cx1_Parking_in_car (1U)
 *   Cx2_Remote_parking (2U)
 *   Cx3_Reserved (3U)
 * Request_driveoff: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_no_request (0U)
 *   Cx1_The_front_car_has_started (1U)
 *   Cx2_The_front_car_has_started_Please_pay_attention_to_the_road_environment (2U)
 *   Cx3_The_front_car_has_started_please_keep_your_attention (3U)
 *   Cx4_The_front_car_has_started_please_take_over_the_car (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * RollingCounter_ACC3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC4_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC6: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ACC8_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_HUT32: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_IP2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * Rte_DT_SystemState_RecordType_0: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_Cluster_OFF (0U)
 *   SYSTEMSTATE_Cluster_STANDBY (1U)
 *   SYSTEMSTATE_Cluster_ON (2U)
 *   SYSTEMSTATE_Cluster_STARTUP (3U)
 *   SYSTEMSTATE_Cluster_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_1: Enumeration of integer in interval [0.0...255] with enumerators
 *   SYSTEMSTATE_IVI_OFF (0U)
 *   SYSTEMSTATE_IVI_STANDBY (1U)
 *   SYSTEMSTATE_IVI_ON (2U)
 *   SYSTEMSTATE_IVI_SHUTDOWN (3U)
 *   SYSTEMSTATE_IVI_ON_NORMAL (5U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (7U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (8U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (9U)
 *   SYSTEMSTATE_IVI_REMOTE (4U)
 * Rte_DT_SystemState_RecordType_2: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_HUD_OFF (0U)
 *   SYSTEMSTATE_HUD_STANDBY (1U)
 *   SYSTEMSTATE_HUD_ON (2U)
 *   SYSTEMSTATE_HUD_STARTUP (3U)
 *   SYSTEMSTATE_HUD_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_3: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_CONSOLE_OFF (0U)
 *   SYSTEMSTATE_CONSOLE_STANDBY (1U)
 *   SYSTEMSTATE_CONSOLE_ON (2U)
 *   SYSTEMSTATE_CONSOLE_STARTUP (3U)
 *   SYSTEMSTATE_CONSOLE_SHUTDOWN (4U)
 * Rte_DT_SystemState_RecordType_4: Enumeration of integer in interval [0...255] with enumerators
 *   KL15OFF (0U)
 *   KL15ON (1U)
 * Rte_DT_SystemState_RecordType_5_0: Enumeration of integer in interval [0...255] with enumerators
 *   VOLTAGE_OUT_LOWSLEEP (0U)
 *   VOLTAGE_OUT_NORMAL (1U)
 *   VOLTAGE_OUT_HIGHALARM (2U)
 *   VOLTAGE_OUT_HIGHSLEEP (3U)
 *   VOLTAGE_OUT_LOWALARM (4U)
 *   VOLTAGE_OUT_NUM (5U)
 * Rte_DT_SystemState_RecordType_6: Enumeration of integer in interval [0...255] with enumerators
 *   SYSTEMSTATE_SP_OFF (0U)
 *   SYSTEMSTATE_SP_SHUTDOWN (1U)
 *   SYSTEMSTATE_SP_STANDBY (2U)
 *   SYSTEMSTATE_SP_SOCOFF (3U)
 * Rte_DT_SystemState_RecordType_7_0: Enumeration of integer in interval [0...255] with enumerators
 *   TEMP_LOW_SLEEP (0U)
 *   TEMP_NORMAL (1U)
 *   TEMP_HIGH_PROTECT (2U)
 *   TEMP_HIGH_SLEEP (3U)
 *   TEMP_STATE_NUM (4U)
 *   TEMP_STATE_INIT (255U)
 * ScrnOpSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Release (0U)
 *   Cx1_Pressed (1U)
 *   Cx2_Hold (2U)
 *   Cx3_Reserved (3U)
 * TJA_ACC_SelSts_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_off (0U)
 *   Cx1_ACC_selected (1U)
 *   Cx2_TJAICA_selected (2U)
 *   Cx3_Off_selected (3U)
 *   Cx4_ACC_on (4U)
 *   Cx5_TJAICA_on (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * TJA_ICA_InterSysInfoDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Unable_to_activate_TJAICA_due_to_other_limitation (1U)
 *   Cx2_TJAICA_active_control_is_cancelled (2U)
 *   Cx3_TJAICA_temporarily_unavailable (3U)
 *   Cx4_Current_IGN_Cycle_Function_Inhibit (4U)
 *   Cx5_Resvered (5U)
 *   Cx7_Resvered (7U)
 * TJA_ICA_ModDisp_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF_mode (0U)
 *   Cx1_Passive_mode (1U)
 *   Cx2_Active_mode (2U)
 *   Cx3_Ready_mode (3U)
 *   Cx4_Failure (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * VolLampDispSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Segment_0 (0U)
 *   Cx1_Segment_1 (1U)
 *   Cx2_Segment_2 (2U)
 *   Cx3_Segment_3 (3U)
 *   Cx4_Segment_4 (4U)
 *   Cx5_Segment_5 (5U)
 *   Cx6_Segment_6 (6U)
 *   Cx7_Segment_7 (7U)
 *   Cx8_Segment_8 (8U)
 *   Cx9_Error (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * XLvl: Enumeration of integer in interval [0...2047] with enumerators
 *   Cx000_Valid_value (0U)
 *   Cx7A8_Valid_value (1960U)
 *   Cx7A9_Invalid (1961U)
 *   Cx7FF_Invalid (2047U)
 * YLvl: Enumeration of integer in interval [0...2047] with enumerators
 *   Cx000_Valid_value (0U)
 *   Cx2D0_Valid_value (720U)
 *   Cx2D1_Invalid (721U)
 *   Cx7FF_Invalid (2047U)
 *
 * Array Types:
 * ============
 * ABM1_0x351: Array with 16 element(s) of type uint8
 * ABS1_0x231: Array with 8 element(s) of type uint8
 * ABS2_0x246: Array with 8 element(s) of type uint8
 * ABS3_0x265: Array with 16 element(s) of type uint8
 * AC1_0x29D: Array with 8 element(s) of type uint8
 * AC2_0x385: Array with 8 element(s) of type uint8
 * ACC_FD2_0x2AB: Array with 64 element(s) of type uint8
 * ACC_FD3_0x2B4: Array with 64 element(s) of type uint8
 * ACC_FD4_0x2B8: Array with 64 element(s) of type uint8
 * AEB_FD2_0x227: Array with 64 element(s) of type uint8
 * AMP2_0x3E3: Array with 16 element(s) of type uint8
 * AMP3_0x3E5: Array with 8 element(s) of type uint8
 * A_20Bytes: Array with 20 element(s) of type uint8
 * BCM12_0x238: Array with 8 element(s) of type uint8
 * BCM1_0x319: Array with 16 element(s) of type uint8
 * BCM3_0x345: Array with 16 element(s) of type uint8
 * BCM6_0x28C: Array with 8 element(s) of type uint8
 * BCM8_0x29F: Array with 8 element(s) of type uint8
 * BMS19_0x352: Array with 8 element(s) of type uint8
 * BMS22_0x3BF: Array with 8 element(s) of type uint8
 * BMS30_0x3F1: Array with 8 element(s) of type uint8
 * BMS35_0x2C4: Array with 8 element(s) of type uint8
 * BMS4_0xF1: Array with 8 element(s) of type uint8
 * BMS8_0x285: Array with 8 element(s) of type uint8
 * BMS_FD14_0x1E3: Array with 8 element(s) of type uint8
 * CP1_0x35E: Array with 8 element(s) of type uint8
 * CR_FD1_0x15E: Array with 64 element(s) of type uint8
 * CSA1_0x165: Array with 8 element(s) of type uint8
 * CSA2_0xA1: Array with 8 element(s) of type uint8
 * CSA3_0x244: Array with 8 element(s) of type uint8
 * CconfigKind_400Bytes: Array with 400 element(s) of type uint8
 * ComEx_SignalDataType: Array with 64 element(s) of type uint8
 * DCT3_0xA6: Array with 8 element(s) of type uint8
 * DCT5_0x221: Array with 8 element(s) of type uint8
 * DCT7_0x235: Array with 16 element(s) of type uint8
 * DDCM1_0x2CA: Array with 8 element(s) of type uint8
 * DHT_FD1_0xC1: Array with 64 element(s) of type uint8
 * DMS_FD1_0x24D: Array with 64 element(s) of type uint8
 * DSM1_0x2C1: Array with 8 element(s) of type uint8
 * ECM11_0x2D3: Array with 8 element(s) of type uint8
 * ECM1_0x111: Array with 8 element(s) of type uint8
 * ECM2_0x271: Array with 8 element(s) of type uint8
 * ECM3_0x371: Array with 8 element(s) of type uint8
 * ECM_PT7_0x117: Array with 8 element(s) of type uint8
 * ECM_VIN: Array with 8 element(s) of type uint8
 * EEM1_0x2A8: Array with 8 element(s) of type uint8
 * ELD1_0x152: Array with 8 element(s) of type uint8
 * EOL13Bytes: Array with 13 element(s) of type uint8
 * EOL4Bytes: Array with 4 element(s) of type uint8
 * EOL_15Bytes: Array with 15 element(s) of type uint8
 * EPB1_0x16B: Array with 8 element(s) of type uint8
 * EPS1_0x168: Array with 8 element(s) of type uint8
 * EPS_FD1_0x147: Array with 64 element(s) of type uint8
 * ESCL2_0x303: Array with 8 element(s) of type uint8
 * ESP10_0xD8: Array with 8 element(s) of type uint8
 * ESP11_0xC8: Array with 8 element(s) of type uint8
 * ESP1_0x149: Array with 16 element(s) of type uint8
 * ESP2_0x145: Array with 16 element(s) of type uint8
 * ESP8_0x170: Array with 8 element(s) of type uint8
 * ESP_FD2_0x137: Array with 64 element(s) of type uint8
 * EventSignalType: Array with 64 element(s) of type uint8
 * FPAS1_0x26D: Array with 8 element(s) of type uint8
 * F_PBox1_0x19B: Array with 8 element(s) of type uint8
 * GW_FD1_0x2BB: Array with 64 element(s) of type uint8
 * HAP_FD1_0x15B: Array with 64 element(s) of type uint8
 * HAP_FD2_0x274: Array with 64 element(s) of type uint8
 * HAP_FD3_0x298: Array with 64 element(s) of type uint8
 * HAP_FD6_0x289: Array with 64 element(s) of type uint8
 * HAP_FD7_0x29B: Array with 64 element(s) of type uint8
 * HC1_0x287: Array with 8 element(s) of type uint8
 * HCM_L1_0x308: Array with 8 element(s) of type uint8
 * HCM_R1_0x30D: Array with 8 element(s) of type uint8
 * HCU_FD1_0x60: Array with 64 element(s) of type uint8
 * HCU_HC3_0x268: Array with 8 element(s) of type uint8
 * HCU_HC6_0x314: Array with 8 element(s) of type uint8
 * HCU_HC7_0x3C2: Array with 8 element(s) of type uint8
 * HCU_HC8_0x1E2: Array with 8 element(s) of type uint8
 * HCU_HP5_0x201: Array with 8 element(s) of type uint8
 * HCU_HP6_0x11A: Array with 8 element(s) of type uint8
 * HCU_PT4_0x2FA: Array with 8 element(s) of type uint8
 * HCU_PT5_0x14A: Array with 8 element(s) of type uint8
 * HCU_PT7_0x248: Array with 8 element(s) of type uint8
 * HCU_PT8_0x1C0: Array with 8 element(s) of type uint8
 * HUD1_0x325: Array with 8 element(s) of type uint8
 * HUT10_0x331: Array with 8 element(s) of type uint8
 * HUT13_0x31C: Array with 8 element(s) of type uint8
 * HUT15_0x1EE: Array with 16 element(s) of type uint8
 * HUT16_0x348: Array with 8 element(s) of type uint8
 * HUT17_0x33B: Array with 8 element(s) of type uint8
 * HUT19_0x415: Array with 8 element(s) of type uint8
 * HUT1_0x367: Array with 8 element(s) of type uint8
 * HUT20_0x2DE: Array with 8 element(s) of type uint8
 * HUT21_0x2DD: Array with 8 element(s) of type uint8
 * HUT22_0x2DA: Array with 8 element(s) of type uint8
 * HUT23_0x2D8: Array with 8 element(s) of type uint8
 * HUT25_0x339: Array with 8 element(s) of type uint8
 * HUT26_0x2B6: Array with 8 element(s) of type uint8
 * HUT2_0x369: Array with 8 element(s) of type uint8
 * HUT30_0x1E9: Array with 8 element(s) of type uint8
 * HUT32_0x26F: Array with 8 element(s) of type uint8
 * HUT33_0x1ED: Array with 8 element(s) of type uint8
 * HUT34_0x370: Array with 8 element(s) of type uint8
 * HUT35_0x1E5: Array with 8 element(s) of type uint8
 * HUT39_0x1EB: Array with 8 element(s) of type uint8
 * HUT3_0x36B: Array with 8 element(s) of type uint8
 * HUT40_0x2CE: Array with 8 element(s) of type uint8
 * HUT4_0x36D: Array with 8 element(s) of type uint8
 * HUT6_0x4A: Array with 8 element(s) of type uint8
 * HUT_FD1_0x2C3: Array with 64 element(s) of type uint8
 * HUT_FD4_0x1DA: Array with 64 element(s) of type uint8
 * HUT_IP1_0x293: Array with 8 element(s) of type uint8
 * HUT_IP2_0x27F: Array with 16 element(s) of type uint8
 * HUT_IP3_0x34A: Array with 16 element(s) of type uint8
 * Haldex1_0x251: Array with 8 element(s) of type uint8
 * IFC_FD2_0x23D: Array with 64 element(s) of type uint8
 * IFC_FD3_0x2CF: Array with 64 element(s) of type uint8
 * IFC_FD5_0x19F: Array with 64 element(s) of type uint8
 * IFC_FD6_0x222: Array with 64 element(s) of type uint8
 * IPC_Config_Type: Array with 60 element(s) of type Rte_DT_IPC_Config_Type_0
 * NVM_IPC_CAN_Type: Array with 120 element(s) of type uint8
 * OBC1_0x316: Array with 8 element(s) of type uint8
 * OBC2_0x317: Array with 8 element(s) of type uint8
 * PDCM1_0x2CD: Array with 8 element(s) of type uint8
 * PEPS2_0x295: Array with 8 element(s) of type uint8
 * PEPS4_0x302: Array with 8 element(s) of type uint8
 * PLG_1_0x2FE: Array with 8 element(s) of type uint8
 * RPAS1_0x26E: Array with 8 element(s) of type uint8
 * RPAS2_0x2ED: Array with 8 element(s) of type uint8
 * RSDS_FD1_0x16F: Array with 64 element(s) of type uint8
 * RSDS_FD2_0x30A: Array with 64 element(s) of type uint8
 * R_PBox1_0x19C: Array with 16 element(s) of type uint8
 * SCM1_0x2D1: Array with 8 element(s) of type uint8
 * TMCU_FD3_0x3C9: Array with 8 element(s) of type uint8
 * TPMS1_0x341: Array with 16 element(s) of type uint8
 * TPMS2_0x395: Array with 16 element(s) of type uint8
 * T_Box_FD1_0x33: Array with 16 element(s) of type uint8
 * T_Box_FD3_0x3E9: Array with 16 element(s) of type uint8
 * Trailer1_0x273: Array with 8 element(s) of type uint8
 * VSG1_0x2E1: Array with 8 element(s) of type uint8
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 * VconfigKind_400Bytes: Array with 400 element(s) of type uint8
 * WPC1_0x2BA: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * DateTimeType_t: Record with elements
 *   u16Year of type uint16
 *   u8Month of type uint8
 *   u8Day of type uint8
 *   u8Hour of type uint8
 *   u8Minutes of type uint8
 *   u8Seconds of type uint8
 *   u8TimeMode of type uint8
 * EnergyInfoIdDataType: Record with elements
 *   ModuleId of type uint32
 *   ClientId of type uint32
 * FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE: Record with elements
 *   Fuel_Fast_Fill_Status of type uint8
 *   Fuel_Fast_Fill_Status_Aux of type uint8
 *   Fuel_Init_Complete_Status of type uint8
 *   Fuel_Init_Complete_Status_Aux of type uint8
 *   Fuel_Level_Display_Percent of type uint16
 *   Fuel_Level_Display_Percent_Aux of type uint16
 *   Fuel_Level_Display_Segment of type uint8
 *   Fuel_Warning_Status_Aux of type uint8
 *   Fuel_Warning_Status of type uint8
 *   Fuel_Sensor_Error_Status_Aux of type uint8
 *   Fuel_Sensor_Error_Status of type uint8
 *   Fuel_Level_Display_Value of type uint32
 *   Fuel_Level_Display_Value_Aux of type uint32
 *   Fuel_Level_Calculate_Value_Aux of type uint16
 *   Fuel_Level_Calculate_Value of type uint16
 *   Fuel_Sensor_Raw_Value_A of type uint16
 *   Fuel_Sensor_Raw_Value_B of type uint16
 *   Fuel_Sensor_Switch of type uint8
 * MenuSetData_t: Record with elements
 *   NaviLimitSpeed of type Rte_DT_MenuSetData_t_0
 *   OverSpeedEnable of type Rte_DT_MenuSetData_t_1
 *   Language of type Rte_DT_MenuSetData_t_2
 *   ClusterTheme of type Rte_DT_MenuSetData_t_3
 *   OdometerUnit of type Rte_DT_MenuSetData_t_4
 *   TemperatureUnit of type Rte_DT_MenuSetData_t_5
 *   TirePressureUnit of type Rte_DT_MenuSetData_t_6
 *   TripComputerId of type Rte_DT_MenuSetData_t_7
 *   InteractiveCarId of type Rte_DT_MenuSetData_t_8
 *   DrivingModeMemorySwitch of type Rte_DT_MenuSetData_t_9
 *   TimeUnit of type Rte_DT_MenuSetData_t_10
 *   HighwayAssistSwitch of type Rte_DT_MenuSetData_t_11
 *   LaneChangeAssistSwitch of type Rte_DT_MenuSetData_t_12
 *   Cluster_Sunrise_Sunset_Mode of type uint8
 *   Cluster_Auto_Mode of type uint8
 *   DrvgModeMemReq of type uint8
 *   DrvingModReq_HUT of type uint8
 * Rte_DT_SystemState_RecordType_5: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_5_0
 *   value of type Rte_DT_SystemState_RecordType_5_1
 * Rte_DT_SystemState_RecordType_7: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_7_0
 *   temperature of type Rte_DT_SystemState_RecordType_7_1
 * SG_ACC3_ACC_FD2: Record with elements
 *   ALC_InterSysInfoDisp of type ALC_InterSysInfoDisp
 *   ALC_Resp of type ALC_Resp
 *   Checksum_ACC3 of type Checksum_ACC3
 *   HWA_Resp of type HWA_Resp
 *   HWA_SnvtySet_Resp of type HWA_SnvtySet_Resp
 *   ICA_HandsOffResp of type ICA_HandsOffResp
 *   ISL_Resp of type ISL_Resp
 *   Longctrl_Decel_Req_DVR of type Longctrl_Decel_Req_DVR
 *   Longctrl_Decel_ReqValue_DVR of type Longctrl_Decel_ReqValue_DVR_1
 *   Longctrl_DecelToStopReq_DVR of type Longctrl_DecelToStopReq_DVR
 *   Longctrl_DrvOFF_Req_DVR of type Longctrl_DrvOFF_Req_DVR
 *   Longctrl_EngTrqReq_DVR of type Longctrl_EngTrqReq_DVR_1
 *   Longctrl_EngTrqReqActive_DVR of type Longctrl_EngTrqReqActive_DVR
 *   Longctrl_HCUTrqReqActive_DVR of type Longctrl_HCUTrqReqActive_DVR
 *   Longctrl_ModSts_DVR of type Longctrl_ModSts_DVR
 *   Longctrl_ParkShiftReq_DVR of type Longctrl_ParkShiftReq_DVR
 *   Longctrl_VehHldReq_DVR of type Longctrl_VehHldReq_DVR
 *   RollingCounter_ACC3 of type RollingCounter_ACC3
 *   dummy_ACC_FD2_4 of type dummy_ACC_FD2_4
 *   dummy_ACC_FD2_5 of type dummy_ACC_FD2_5
 *   dummy_ACC_FD2_6 of type dummy_ACC_FD2_6
 *   dummy_ACC_FD2_7 of type dummy_ACC_FD2_7
 * SG_ACC4_ACC_FD2: Record with elements
 *   ACC_FctSts of type ACC_FctSts_4
 *   ACC_InterSysInfoDisp of type ACC_InterSysInfoDisp_4
 *   ACC_ModDisp of type ACC_ModDisp_4
 *   ACC_ObjDetecte of type ACC_ObjDetecte_4
 *   ACC_SpdSetValue of type ACC_SpdSetValue_4
 *   ACC_TakeOverReq of type ACC_TakeOverReq_4
 *   ACC_TgtObjBarDisp of type ACC_TgtObjBarDisp_4
 *   ACC_TimeGapSet of type ACC_TimeGapSet_4
 *   Checksum_ACC4 of type Checksum_ACC4_4
 *   ISL_InterSysInfoDisp of type ISL_InterSysInfoDisp_4
 *   RollingCounter_ACC4 of type RollingCounter_ACC4_4
 *   TJA_ACC_SelSts of type TJA_ACC_SelSts_4
 *   TJA_ICA_InterSysInfoDisp of type TJA_ICA_InterSysInfoDisp_4
 *   TJA_ICA_ModDisp of type TJA_ICA_ModDisp_4
 *   CruCha_ModDisp of type CruCha_ModDisp
 *   CruChar_InterSysInfoDisp of type CruChar_InterSysInfoDisp
 *   Longctrl_HazActv of type Longctrl_HazActv
 *   dummy_ACC_FD2_8 of type dummy_ACC_FD2_16
 *   dummy_ACC_FD2_9 of type dummy_ACC_FD2_17
 *   dummy_ACC_FD2_10 of type dummy_ACC_FD2_18
 * SG_ACC6_ACC_FD2: Record with elements
 *   ACC_EgoStatus of type ACC_EgoStatus
 *   ACC_PotentialTgtDetn of type ACC_PotentialTgtDetn
 *   ACC_PotentialTgtDx of type ACC_PotentialTgtDx
 *   ACC_PotentialTgtDy of type ACC_PotentialTgtDy
 *   ACC_PotentialTgtTyp of type ACC_PotentialTgtTyp
 *   ACC_RlvTgtDetn of type ACC_RlvTgtDetn
 *   ACC_RlvTgtDx of type ACC_RlvTgtDx
 *   ACC_RlvTgtDy of type ACC_RlvTgtDy
 *   ACC_RlvTgtTyp of type ACC_RlvTgtTyp
 *   Checksum_ACC6 of type Checksum_ACC6
 *   dummy_ACC_FD2_16 of type dummy_ACC_FD2_16
 *   dummy_ACC_FD2_17 of type dummy_ACC_FD2_17
 *   dummy_ACC_FD2_18 of type dummy_ACC_FD2_18
 *   RollingCounter_ACC6 of type RollingCounter_ACC6
 * SG_ACC7_ACC_FD2: Record with elements
 *   ACC_LeTargrtDection of type ACC_LeTargrtDection
 *   ACC_LeTgtDx of type ACC_LeTgtDx
 *   ACC_LeTgtDy of type ACC_LeTgtDy
 *   ACC_LeTgtTyp of type ACC_LeTgtTyp
 *   ACC_RiTargrtDetn of type ACC_RiTargrtDetn
 *   ACC_RiTgtDx of type ACC_RiTgtDx
 *   ACC_RiTgtDy of type ACC_RiTgtDy
 *   ACC_RiTgtTyp of type ACC_RiTgtTyp
 *   Checksum_ACC7 of type Checksum_ACC7
 *   dummy_ACC_FD2_19 of type dummy_ACC_FD2_19
 *   dummy_ACC_FD2_20 of type dummy_ACC_FD2_20
 *   Request_driveoff of type Request_driveoff
 *   RollingCounter_ACC7 of type RollingCounter_ACC7
 * SG_ACC8_ACC_FD2: Record with elements
 *   ADAS_DriverInloop_Monitor of type ADAS_DriverInloop_Monitor_2
 *   Checksum_ACC8 of type Checksum_ACC8_2
 *   HWA_InterSysInfoDisp of type HWA_InterSysInfoDisp_2
 *   HWA_LaneChange of type HWA_LaneChange_2
 *   HWA_LaneChangeReq of type HWA_LaneChangeReq_2
 *   HWA_ModDisp of type HWA_ModDisp_2
 *   HWA_warning of type HWA_warning_2
 *   Longctrl_HCUTrqReq_DVR of type Longctrl_HCUTrqReq_DVR_2
 *   RollingCounter_ACC8 of type RollingCounter_ACC8_2
 *   dummy_ACC_FD2_11 of type dummy_ACC_FD2_11
 *   dummy_ACC_FD2_12 of type dummy_ACC_FD2_12
 *   dummy_ACC_FD2_13 of type dummy_ACC_FD2_13
 *   dummy_ACC_FD2_14 of type dummy_ACC_FD2_14
 *   dummy_ACC_FD2_15 of type dummy_ACC_FD2_15
 * SG_HUT32: Record with elements
 *   CheckSum_HUT32 of type CheckSum_HUT32
 *   ContnPrkgReq of type ContnPrkgReq
 *   ContnPrkgReqValid of type ContnPrkgReqValid
 *   DetVideoLost of type DetVideoLost
 *   PrkgCtrlModReq of type PrkgCtrlModReq
 *   PrkgCtrlModReqValid of type PrkgCtrlModReqValid
 *   PrkStraightContinueReq_HUT of type PrkStraightContinueReq_HUT
 *   PrkStraightModSel_HUT of type PrkStraightModSel_HUT
 *   PrkStraightStrtReq_HUT of type PrkStraightStrtReq_HUT
 *   PrkStraightSts_HUT of type PrkStraightSts_HUT
 *   PrkStraightSuspendOrFinishReq_HUT of type PrkStraightSuspendOrFinishReq_HUT
 *   PrkStraightSwtReq_HUT of type PrkStraightSwtReq_HUT
 *   PrkStraightVehStrtReq_HUT_Valid of type PrkStraightVehStrtReq_HUT_Valid
 *   RollingCounter_HUT32 of type RollingCounter_HUT32
 *   ScrnOpSts of type ScrnOpSts
 *   VolLampDispSts of type VolLampDispSts
 *   XLvl of type XLvl
 *   YLvl of type YLvl
 * SG_HUT_IP2: Record with elements
 *   CheckSum_IP2 of type CheckSum_IP2
 *   IP_ABMWarnLmpFailrSts of type IP_ABMWarnLmpFailrSts
 *   IP_ACCErr of type IP_ACCErr
 *   IP_BattChrgLmpSts of type IP_BattChrgLmpSts
 *   IP_DrvSeatBeltWarnLmpFailSts of type IP_DrvSeatBeltWarnLmpFailSts
 *   IP_EngOilPressLowLmpSts of type IP_EngOilPressLowLmpSts
 *   IP_Err of type IP_Err
 *   IP_FuelLvlInfo of type IP_FuelLvlInfo
 *   IP_FuelLvlLowLmpSts of type IP_FuelLvlLowLmpSts
 *   IP_PassSeatBeltWarnLmpFailSts of type IP_PassSeatBeltWarnLmpFailSts
 *   IP_VehSpdUnit of type IP_VehSpdUnit
 *   IP_VehTotDistance of type IP_VehTotDistance_2
 *   IP_VehTotDistanceValid of type IP_VehTotDistanceValid
 *   IP_VINcompr of type IP_VINcompr
 *   RollingCounter_IP2 of type RollingCounter_IP2
 * SystemState_RecordType: Record with elements
 *   ClusterState of type Rte_DT_SystemState_RecordType_0
 *   IVIState of type Rte_DT_SystemState_RecordType_1
 *   HUDState of type Rte_DT_SystemState_RecordType_2
 *   ConsoleState of type Rte_DT_SystemState_RecordType_3
 *   KL15State of type Rte_DT_SystemState_RecordType_4
 *   s_PowerVoltage of type Rte_DT_SystemState_RecordType_5
 *   SP_State of type Rte_DT_SystemState_RecordType_6
 *   s_TempVoltage of type Rte_DT_SystemState_RecordType_7
 * TC_MODULE_OUTPUT_DATA_STRUCT_RTE: Record with elements
 *   u16AFE_1st_Display_Output_Data of type uint16
 *   u16AFE_2st_Display_Output_Data of type uint16
 *   u32AFE_1st_Fuel_Trip_Value of type uint32
 *   u32AFE_1st_Fuel_Consumption_Value of type uint32
 *   u32AFE_2st_Fuel_Trip_Value of type uint32
 *   u32AFE_2st_Fuel_Consumption_Value of type uint32
 *   u16IFE_Calculate_Output_Data of type uint16
 *   u16IFE_Display_Output_Data of type uint16
 *   u32IFE_Fuel_Trip_Value of type uint32
 *   u32IFE_Fuel_Consumption_Value of type uint32
 *   u32IFE_Fuel_Consumption_Can_Signal of type uint32
 *   u16AVS_1st_Display_Output_Data of type uint16
 *   u16AVS_2st_Display_Output_Data of type uint16
 *   u32AVS_1st_Driving_Time_Value of type uint32
 *   u32AVS_2st_Driving_Time_Value of type uint32
 *   u32AVS_1st_Fuel_Trip_Value of type uint32
 *   u32AVS_2st_Fuel_Trip_Value of type uint32
 *   u8DrivingTime_1st_Display_Hour of type uint8
 *   u8DrivingTime_2st_Display_Hour of type uint8
 *   u8DrivingTime_1st_Display_Minute of type uint8
 *   u8DrivingTime_2st_Display_Minute of type uint8
 *   u16DTE_Fuel_Tank_Volume of type uint16
 *   u16DTE_Fuel_Tank_Volume_Aux of type uint16
 *   u8DTE_Fuel_Stage_Consumption of type uint8
 *   u8DTE_Fuel_Stage_Consumption_Aux of type uint8
 *   u16DTE_Display_Output_Data of type uint16
 *   u16DTE_Display_Output_Data_Aux of type uint16
 *   u16DTE_Calculate_Output_Data of type uint16
 *   u16SFC_Output_Data of type uint16
 *   u8IFC_Poc_Update of type uint8
 *   u16IFC_Poc_Calculate_Value of type uint16
 *   u16SFC_For_Fuel_Output_Data of type uint16
 *   u16IFC_Poc_For_Fuel_Calculate_Rate of type uint16
 *   u16IFC_Poc_For_Fuel_Calculate_Rate_Aux of type uint16
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_NvBlockNeed_Block_IPC_CAN_Data_MirrorBlock(void)
 *     Returnvalue: uint8* is of type NVM_IPC_CAN_Type
 *   Rte_DT_IPC_Config_Type_0 *Rte_Pim_NvBlockNeed_Block_IPC_Config_Data_MirrorBlock(void)
 *     Returnvalue: Rte_DT_IPC_Config_Type_0* is of type IPC_Config_Type
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint8 *Rte_CData_NvBlockNeed_Block_IPC_CAN_Data_DefaultValue(void)
 *     Returnvalue: uint8* is of type NVM_IPC_CAN_Type
 *   Rte_DT_IPC_Config_Type_0 *Rte_CData_NvBlockNeed_Block_IPC_Config_Data_DefaultValue(void)
 *     Returnvalue: Rte_DT_IPC_Config_Type_0* is of type IPC_Config_Type
 *
 *********************************************************************************************************************/


#define Common_GateWay_START_SEC_CODE
#include "Common_GateWay_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_GW_List_Deinit
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Deinit> of PortPrototype <Common_GW_List>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_GW_List_Deinit(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GW_List_Deinit_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) Common_GW_List_Deinit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GW_List_Deinit
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_GW_List_Int
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Int> of PortPrototype <Common_GW_List>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_GW_List_Int(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GW_List_Int_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) Common_GW_List_Int(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GW_List_Int
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_GateWay_10msMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   uint8 *Rte_IRead_Common_GateWay_10msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes(void)
 *     Returnvalue: uint8* is of type VconfigKind_157Bytes
 *   SystemState_RecordType *Rte_IRead_Common_GateWay_10msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut(void)
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_Common_GateWay_10msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes(void)
 *   Std_ReturnType Rte_IStatus_Common_GateWay_10msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_10msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) Common_GateWay_10msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_10msMainFunction
 *********************************************************************************************************************/

	vCA_Process_msTassk();
	vCA_Interface_msTask();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_GateWay_5msMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ABM1_0x351_ABM1_0x351(uint8 *data)
 *     Argument data: uint8* is of type ABM1_0x351
 *   Std_ReturnType Rte_Read_ABS1_0x231_ABS1_0x231(uint8 *data)
 *     Argument data: uint8* is of type ABS1_0x231
 *   Std_ReturnType Rte_Read_ABS2_0x246_ABS2_0x246(uint8 *data)
 *     Argument data: uint8* is of type ABS2_0x246
 *   Std_ReturnType Rte_Read_ABS3_0x265_ABS3_0x265(uint8 *data)
 *     Argument data: uint8* is of type ABS3_0x265
 *   Std_ReturnType Rte_Read_AC1_0x29D_AC1_0x29D(uint8 *data)
 *     Argument data: uint8* is of type AC1_0x29D
 *   Std_ReturnType Rte_Read_AC2_0x385_AC2_0x385(uint8 *data)
 *     Argument data: uint8* is of type AC2_0x385
 *   Std_ReturnType Rte_Read_ACC_FD2_0x2AB_ACC_FD2_0x2AB(uint8 *data)
 *     Argument data: uint8* is of type ACC_FD2_0x2AB
 *   Std_ReturnType Rte_Read_ACC_FD3_0x2B4_ACC_FD3_0x2B4(uint8 *data)
 *     Argument data: uint8* is of type ACC_FD3_0x2B4
 *   Std_ReturnType Rte_Read_ACC_FD4_0x2B8_ACC_FD4_0x2B8(uint8 *data)
 *     Argument data: uint8* is of type ACC_FD4_0x2B8
 *   Std_ReturnType Rte_Read_AEB_FD2_0x227_AEB_FD2_0x227(uint8 *data)
 *     Argument data: uint8* is of type AEB_FD2_0x227
 *   Std_ReturnType Rte_Read_AMP2_0x3E3_AMP2_0x3E3(uint8 *data)
 *     Argument data: uint8* is of type AMP2_0x3E3
 *   Std_ReturnType Rte_Read_AMP3_0x3E5_AMP3_0x3E5(uint8 *data)
 *     Argument data: uint8* is of type AMP3_0x3E5
 *   Std_ReturnType Rte_Read_BCM12_0x238_BCM12_0x238(uint8 *data)
 *     Argument data: uint8* is of type BCM12_0x238
 *   Std_ReturnType Rte_Read_BCM1_0x319_BCM1_0x319(uint8 *data)
 *     Argument data: uint8* is of type BCM1_0x319
 *   Std_ReturnType Rte_Read_BCM3_0x345_BCM3_0x345(uint8 *data)
 *     Argument data: uint8* is of type BCM3_0x345
 *   Std_ReturnType Rte_Read_BCM6_0x28C_BCM6_0x28C(uint8 *data)
 *     Argument data: uint8* is of type BCM6_0x28C
 *   Std_ReturnType Rte_Read_BCM8_0x29F_BCM8_0x29F(uint8 *data)
 *     Argument data: uint8* is of type BCM8_0x29F
 *   Std_ReturnType Rte_Read_BMS19_0x352_BMS19_0x352(uint8 *data)
 *     Argument data: uint8* is of type BMS19_0x352
 *   Std_ReturnType Rte_Read_BMS22_0x3BF_BMS22_0x3BF(uint8 *data)
 *     Argument data: uint8* is of type BMS22_0x3BF
 *   Std_ReturnType Rte_Read_BMS30_0x3F1_BMS30_0x3F1(uint8 *data)
 *     Argument data: uint8* is of type BMS30_0x3F1
 *   Std_ReturnType Rte_Read_BMS35_0x2C4_BMS35_0x2C4(uint8 *data)
 *     Argument data: uint8* is of type BMS35_0x2C4
 *   Std_ReturnType Rte_Read_BMS4_0xF1_BMS4_0xF1(uint8 *data)
 *     Argument data: uint8* is of type BMS4_0xF1
 *   Std_ReturnType Rte_Read_BMS8_0x285_BMS8_0x285(uint8 *data)
 *     Argument data: uint8* is of type BMS8_0x285
 *   Std_ReturnType Rte_Read_BMS_FD14_0x1E3_BMS_FD14_0x1E3(uint8 *data)
 *     Argument data: uint8* is of type BMS_FD14_0x1E3
 *   Std_ReturnType Rte_Read_CP1_0x35E_CP1_0x35E(uint8 *data)
 *     Argument data: uint8* is of type CP1_0x35E
 *   Std_ReturnType Rte_Read_CR_FD1_0x15E_CR_FD1_0x15E(uint8 *data)
 *     Argument data: uint8* is of type CR_FD1_0x15E
 *   Std_ReturnType Rte_Read_CSA1_0x165_CSA1_0x165(uint8 *data)
 *     Argument data: uint8* is of type CSA1_0x165
 *   Std_ReturnType Rte_Read_CSA2_0xA1_CSA2_0xA1(uint8 *data)
 *     Argument data: uint8* is of type CSA2_0xA1
 *   Std_ReturnType Rte_Read_CSA3_0x244_CSA3_0x244(uint8 *data)
 *     Argument data: uint8* is of type CSA3_0x244
 *   Std_ReturnType Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(uint8 *data)
 *     Argument data: uint8* is of type CconfigKind_400Bytes
 *   Std_ReturnType Rte_Read_DCT3_0xA6_DCT3_0xA6(uint8 *data)
 *     Argument data: uint8* is of type DCT3_0xA6
 *   Std_ReturnType Rte_Read_DCT5_0x221_DCT5_0x221(uint8 *data)
 *     Argument data: uint8* is of type DCT5_0x221
 *   Std_ReturnType Rte_Read_DCT7_0x235_DCT7_0x235(uint8 *data)
 *     Argument data: uint8* is of type DCT7_0x235
 *   Std_ReturnType Rte_Read_DDCM1_0x2CA_DDCM1_0x2CA(uint8 *data)
 *     Argument data: uint8* is of type DDCM1_0x2CA
 *   Std_ReturnType Rte_Read_DHT_FD1_0xC1_DHT_FD1_0xC1(uint8 *data)
 *     Argument data: uint8* is of type DHT_FD1_0xC1
 *   Std_ReturnType Rte_Read_DMS_FD1_0x24D_DMS_FD1_0x24D(uint8 *data)
 *     Argument data: uint8* is of type DMS_FD1_0x24D
 *   Std_ReturnType Rte_Read_DSM1_0x2C1_DSM1_0x2C1(uint8 *data)
 *     Argument data: uint8* is of type DSM1_0x2C1
 *   Std_ReturnType Rte_Read_ECM11_0x2D3_ECM11_0x2D3(uint8 *data)
 *     Argument data: uint8* is of type ECM11_0x2D3
 *   Std_ReturnType Rte_Read_ECM19_0x3B5_ECM19_0x3B5(uint8 *data)
 *     Argument data: uint8* is of type ECM_VIN
 *   Std_ReturnType Rte_Read_ECM1_0x111_ECM1_0x111(uint8 *data)
 *     Argument data: uint8* is of type ECM1_0x111
 *   Std_ReturnType Rte_Read_ECM2_0x271_ECM2_0x271(uint8 *data)
 *     Argument data: uint8* is of type ECM2_0x271
 *   Std_ReturnType Rte_Read_ECM3_0x371_ECM3_0x371(uint8 *data)
 *     Argument data: uint8* is of type ECM3_0x371
 *   Std_ReturnType Rte_Read_ECM_PT7_0x117_ECM_PT7_0x117(uint8 *data)
 *     Argument data: uint8* is of type ECM_PT7_0x117
 *   Std_ReturnType Rte_Read_EEM1_0x2A8_EEM1_0x2A8(uint8 *data)
 *     Argument data: uint8* is of type EEM1_0x2A8
 *   Std_ReturnType Rte_Read_ELD1_0x152_ELD1_0x152(uint8 *data)
 *     Argument data: uint8* is of type ELD1_0x152
 *   Std_ReturnType Rte_Read_EOL_PartNumber_0xF187_PartNumber_0xF187(uint8 *data)
 *     Argument data: uint8* is of type EOL13Bytes
 *   Std_ReturnType Rte_Read_EOL_ReadHardVersion_0xF193_ReadHardVersion_0xF193(uint8 *data)
 *     Argument data: uint8* is of type EOL_15Bytes
 *   Std_ReturnType Rte_Read_EOL_ReadSerialNumber_ProductData_0xF18C_ReadSerialNumber_ProductData_0xF18C(uint8 *data)
 *     Argument data: uint8* is of type A_20Bytes
 *   Std_ReturnType Rte_Read_EOL_VIPSoftwareVersion_0xFD01_VIPSoftwareVersion_0xFD01(uint8 *data)
 *     Argument data: uint8* is of type EOL4Bytes
 *   Std_ReturnType Rte_Read_EPB1_0x16B_EPB1_0x16B(uint8 *data)
 *     Argument data: uint8* is of type EPB1_0x16B
 *   Std_ReturnType Rte_Read_EPS1_0x168_EPS1_0x168(uint8 *data)
 *     Argument data: uint8* is of type EPS1_0x168
 *   Std_ReturnType Rte_Read_EPS_FD1_0x147_EPS_FD1_0x147(uint8 *data)
 *     Argument data: uint8* is of type EPS_FD1_0x147
 *   Std_ReturnType Rte_Read_ESCL2_0x303_ESCL2_0x303(uint8 *data)
 *     Argument data: uint8* is of type ESCL2_0x303
 *   Std_ReturnType Rte_Read_ESP10_0xD8_ESP10_0xD8(uint8 *data)
 *     Argument data: uint8* is of type ESP10_0xD8
 *   Std_ReturnType Rte_Read_ESP11_0xC8_ESP11_0xC8(uint8 *data)
 *     Argument data: uint8* is of type ESP11_0xC8
 *   Std_ReturnType Rte_Read_ESP1_0x149_ESP1_0x149(uint8 *data)
 *     Argument data: uint8* is of type ESP1_0x149
 *   Std_ReturnType Rte_Read_ESP2_0x145_ESP2_0x145(uint8 *data)
 *     Argument data: uint8* is of type ESP2_0x145
 *   Std_ReturnType Rte_Read_ESP8_0x170_ESP8_0x170(uint8 *data)
 *     Argument data: uint8* is of type ESP8_0x170
 *   Std_ReturnType Rte_Read_ESP_FD2_0x137_ESP_FD2_0x137(uint8 *data)
 *     Argument data: uint8* is of type ESP_FD2_0x137
 *   Std_ReturnType Rte_Read_FPAS1_0x26D_FPAS1_0x26D(uint8 *data)
 *     Argument data: uint8* is of type FPAS1_0x26D
 *   Std_ReturnType Rte_Read_F_PBox1_0x19B_F_PBox1_0x19B(uint8 *data)
 *     Argument data: uint8* is of type F_PBox1_0x19B
 *   Std_ReturnType Rte_Read_GW_FD1_0x2BB_GW_FD1_0x2BB(uint8 *data)
 *     Argument data: uint8* is of type GW_FD1_0x2BB
 *   Std_ReturnType Rte_Read_HAP_FD1_0x15B_HAP_FD1_0x15B(uint8 *data)
 *     Argument data: uint8* is of type HAP_FD1_0x15B
 *   Std_ReturnType Rte_Read_HAP_FD2_0x274_HAP_FD2_0x274(uint8 *data)
 *     Argument data: uint8* is of type HAP_FD2_0x274
 *   Std_ReturnType Rte_Read_HAP_FD3_0x298_HAP_FD3_0x298(uint8 *data)
 *     Argument data: uint8* is of type HAP_FD3_0x298
 *   Std_ReturnType Rte_Read_HAP_FD6_0x289_HAP_FD6_0x289(uint8 *data)
 *     Argument data: uint8* is of type HAP_FD6_0x289
 *   Std_ReturnType Rte_Read_HAP_FD7_0x29B_HAP_FD7_0x29B(uint8 *data)
 *     Argument data: uint8* is of type HAP_FD7_0x29B
 *   Std_ReturnType Rte_Read_HC1_0x287_HC1_0x287(uint8 *data)
 *     Argument data: uint8* is of type HC1_0x287
 *   Std_ReturnType Rte_Read_HCM_L1_0x308_HCM_L1_0x308(uint8 *data)
 *     Argument data: uint8* is of type HCM_L1_0x308
 *   Std_ReturnType Rte_Read_HCM_R1_0x30D_HCM_R1_0x30D(uint8 *data)
 *     Argument data: uint8* is of type HCM_R1_0x30D
 *   Std_ReturnType Rte_Read_HCU_FD1_0x60_HCU_FD1_0x60(uint8 *data)
 *     Argument data: uint8* is of type HCU_FD1_0x60
 *   Std_ReturnType Rte_Read_HCU_HC3_0x268_HCU_HC3_0x268(uint8 *data)
 *     Argument data: uint8* is of type HCU_HC3_0x268
 *   Std_ReturnType Rte_Read_HCU_HC6_0x314_HCU_HC6_0x314(uint8 *data)
 *     Argument data: uint8* is of type HCU_HC6_0x314
 *   Std_ReturnType Rte_Read_HCU_HC7_0x3C2_HCU_HC7_0x3C2(uint8 *data)
 *     Argument data: uint8* is of type HCU_HC7_0x3C2
 *   Std_ReturnType Rte_Read_HCU_HC8_0x1E2_HCU_HC8_0x1E2(uint8 *data)
 *     Argument data: uint8* is of type HCU_HC8_0x1E2
 *   Std_ReturnType Rte_Read_HCU_HP5_0x201_HCU_HP5_0x201(uint8 *data)
 *     Argument data: uint8* is of type HCU_HP5_0x201
 *   Std_ReturnType Rte_Read_HCU_HP6_0x11A_HCU_HP6_0x11A(uint8 *data)
 *     Argument data: uint8* is of type HCU_HP6_0x11A
 *   Std_ReturnType Rte_Read_HCU_PT4_0x2FA_HCU_PT4_0x2FA(uint8 *data)
 *     Argument data: uint8* is of type HCU_PT4_0x2FA
 *   Std_ReturnType Rte_Read_HCU_PT5_0x14A_HCU_PT5_0x14A(uint8 *data)
 *     Argument data: uint8* is of type HCU_PT5_0x14A
 *   Std_ReturnType Rte_Read_HCU_PT7_0x248_HCU_PT7_0x248(uint8 *data)
 *     Argument data: uint8* is of type HCU_PT7_0x248
 *   Std_ReturnType Rte_Read_HCU_PT8_0x1C0_HCU_PT8_0x1C0(uint8 *data)
 *     Argument data: uint8* is of type HCU_PT8_0x1C0
 *   Std_ReturnType Rte_Read_HUD1_0x325_HUD1_0x325(uint8 *data)
 *     Argument data: uint8* is of type HUD1_0x325
 *   Std_ReturnType Rte_Read_Haldex1_0x251_Haldex1_0x251(uint8 *data)
 *     Argument data: uint8* is of type Haldex1_0x251
 *   Std_ReturnType Rte_Read_IFC_FD2_0x23D_IFC_FD2_0x23D(uint8 *data)
 *     Argument data: uint8* is of type IFC_FD2_0x23D
 *   Std_ReturnType Rte_Read_IFC_FD3_0x2CF_IFC_FD3_0x2CF(uint8 *data)
 *     Argument data: uint8* is of type IFC_FD3_0x2CF
 *   Std_ReturnType Rte_Read_IFC_FD5_0x19F_IFC_FD5_0x19F(uint8 *data)
 *     Argument data: uint8* is of type IFC_FD5_0x19F
 *   Std_ReturnType Rte_Read_IFC_FD6_0x222_IFC_FD6_0x222(uint8 *data)
 *     Argument data: uint8* is of type IFC_FD6_0x222
 *   Std_ReturnType Rte_Read_OBC1_0x316_OBC1_0x316(uint8 *data)
 *     Argument data: uint8* is of type OBC1_0x316
 *   Std_ReturnType Rte_Read_OBC2_0x317_OBC2_0x317(uint8 *data)
 *     Argument data: uint8* is of type OBC2_0x317
 *   Std_ReturnType Rte_Read_PDCM1_0x2CD_PDCM1_0x2CD(uint8 *data)
 *     Argument data: uint8* is of type PDCM1_0x2CD
 *   Std_ReturnType Rte_Read_PEPS2_0x295_PEPS2_0x295(uint8 *data)
 *     Argument data: uint8* is of type PEPS2_0x295
 *   Std_ReturnType Rte_Read_PEPS4_0x302_PEPS4_0x302(uint8 *data)
 *     Argument data: uint8* is of type PEPS4_0x302
 *   Std_ReturnType Rte_Read_PLG_1_0x2FE_PLG_1_0x2FE(uint8 *data)
 *     Argument data: uint8* is of type PLG_1_0x2FE
 *   Std_ReturnType Rte_Read_RPAS1_0x26E_RPAS1_0x26E(uint8 *data)
 *     Argument data: uint8* is of type RPAS1_0x26E
 *   Std_ReturnType Rte_Read_RPAS2_0x2ED_RPAS2_0x2ED(uint8 *data)
 *     Argument data: uint8* is of type RPAS2_0x2ED
 *   Std_ReturnType Rte_Read_RSDS_FD1_0x16F_RSDS_FD1_0x16F(uint8 *data)
 *     Argument data: uint8* is of type RSDS_FD1_0x16F
 *   Std_ReturnType Rte_Read_RSDS_FD2_0x30A_RSDS_FD2_0x30A(uint8 *data)
 *     Argument data: uint8* is of type RSDS_FD2_0x30A
 *   Std_ReturnType Rte_Read_R_PBox1_0x19C_R_PBox1_0x19C(uint8 *data)
 *     Argument data: uint8* is of type R_PBox1_0x19C
 *   Std_ReturnType Rte_Read_Rc_CanOutout_IP_EBDFailSts_IP_EBDFailSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_CheckSum_IP2(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_ABMWarnLmpFailrSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_ACCErr(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_AvgFuelCons(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_BattChrgLmpSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_CurrTheme(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_DrvSeatBeltWarnLmpFailSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_EBDFailSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_EngOilPressLowLmpSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_Err(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_FuelAuxTankR(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_FuelLvlInfo(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_FuelLvlLowLmpSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_FuelMainTankR(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_InstFuelCons(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_InstFuelConsUnit(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_LagueSet(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_PassSeatBeltWarnLmpFailSts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_RemainDistance(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_VINcompr(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_VehSpdDisp(uint16 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_VehSpdUnit(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_VehTotDistance(uint32 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_VehTotDistanceValid(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_IP_VelSpdDisp_Mile(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_RollingCounter_IP2(uint8 *data)
 *   Std_ReturnType Rte_Read_Rc_CanOutputViaGateway_dummy_HUT_IP2_0(uint8 *data)
 *   Std_ReturnType Rte_Read_SCM1_0x2D1_SCM1_0x2D1(uint8 *data)
 *     Argument data: uint8* is of type SCM1_0x2D1
 *   Std_ReturnType Rte_Read_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(SG_ACC3_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(SG_ACC4_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2(SG_ACC6_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2(SG_ACC7_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(SG_ACC8_ACC_FD2 *data)
 *   Std_ReturnType Rte_Read_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9(uint8 *data)
 *     Argument data: uint8* is of type TMCU_FD3_0x3C9
 *   Std_ReturnType Rte_Read_TPMS1_0x341_TPMS1_0x341(uint8 *data)
 *     Argument data: uint8* is of type TPMS1_0x341
 *   Std_ReturnType Rte_Read_TPMS2_0x395_TPMS2_0x395(uint8 *data)
 *     Argument data: uint8* is of type TPMS2_0x395
 *   Std_ReturnType Rte_Read_T_Box_FD1_0x33_T_Box_FD1_0x33(uint8 *data)
 *     Argument data: uint8* is of type T_Box_FD1_0x33
 *   Std_ReturnType Rte_Read_T_Box_FD3_0x3E9_T_Box_FD3_0x3E9(uint8 *data)
 *     Argument data: uint8* is of type T_Box_FD3_0x3E9
 *   Std_ReturnType Rte_Read_Trailer1_0x273_Trailer1_0x273(uint8 *data)
 *     Argument data: uint8* is of type Trailer1_0x273
 *   Std_ReturnType Rte_Read_VSG1_0x2E1_VSG1_0x2E1(uint8 *data)
 *     Argument data: uint8* is of type VSG1_0x2E1
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_400bytes_VconfigKind_400Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_400Bytes
 *   Std_ReturnType Rte_Read_WPC1_0x2BA_WPC1_0x2BA(uint8 *data)
 *     Argument data: uint8* is of type WPC1_0x2BA
 *   Std_ReturnType Rte_Read_piSR_E2ESwitchChangeTrigger_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCGateWay_DtcInfoForIPErrorStatus_Element(uint8 *data)
 *   Std_ReturnType Rte_Read_rpSR_SWCGateWay_MenuSetData_Element(MenuSetData_t *data)
 *   boolean Rte_IsUpdated_ABM1_0x351_ABM1_0x351(void)
 *   boolean Rte_IsUpdated_ABS1_0x231_ABS1_0x231(void)
 *   boolean Rte_IsUpdated_ABS2_0x246_ABS2_0x246(void)
 *   boolean Rte_IsUpdated_ABS3_0x265_ABS3_0x265(void)
 *   boolean Rte_IsUpdated_AC1_0x29D_AC1_0x29D(void)
 *   boolean Rte_IsUpdated_ACC_FD2_0x2AB_ACC_FD2_0x2AB(void)
 *   boolean Rte_IsUpdated_ACC_FD3_0x2B4_ACC_FD3_0x2B4(void)
 *   boolean Rte_IsUpdated_ACC_FD4_0x2B8_ACC_FD4_0x2B8(void)
 *   boolean Rte_IsUpdated_AEB_FD2_0x227_AEB_FD2_0x227(void)
 *   boolean Rte_IsUpdated_AMP2_0x3E3_AMP2_0x3E3(void)
 *   boolean Rte_IsUpdated_AMP3_0x3E5_AMP3_0x3E5(void)
 *   boolean Rte_IsUpdated_BCM12_0x238_BCM12_0x238(void)
 *   boolean Rte_IsUpdated_BCM1_0x319_BCM1_0x319(void)
 *   boolean Rte_IsUpdated_BCM3_0x345_BCM3_0x345(void)
 *   boolean Rte_IsUpdated_BCM6_0x28C_BCM6_0x28C(void)
 *   boolean Rte_IsUpdated_BCM8_0x29F_BCM8_0x29F(void)
 *   boolean Rte_IsUpdated_BMS19_0x352_BMS19_0x352(void)
 *   boolean Rte_IsUpdated_BMS22_0x3BF_BMS22_0x3BF(void)
 *   boolean Rte_IsUpdated_BMS30_0x3F1_BMS30_0x3F1(void)
 *   boolean Rte_IsUpdated_BMS35_0x2C4_BMS35_0x2C4(void)
 *   boolean Rte_IsUpdated_BMS4_0xF1_BMS4_0xF1(void)
 *   boolean Rte_IsUpdated_BMS8_0x285_BMS8_0x285(void)
 *   boolean Rte_IsUpdated_CP1_0x35E_CP1_0x35E(void)
 *   boolean Rte_IsUpdated_CR_FD1_0x15E_CR_FD1_0x15E(void)
 *   boolean Rte_IsUpdated_CSA1_0x165_CSA1_0x165(void)
 *   boolean Rte_IsUpdated_CSA2_0xA1_CSA2_0xA1(void)
 *   boolean Rte_IsUpdated_CSA3_0x244_CSA3_0x244(void)
 *   boolean Rte_IsUpdated_DCT3_0xA6_DCT3_0xA6(void)
 *   boolean Rte_IsUpdated_DCT5_0x221_DCT5_0x221(void)
 *   boolean Rte_IsUpdated_DCT7_0x235_DCT7_0x235(void)
 *   boolean Rte_IsUpdated_DDCM1_0x2CA_DDCM1_0x2CA(void)
 *   boolean Rte_IsUpdated_DHT_FD1_0xC1_DHT_FD1_0xC1(void)
 *   boolean Rte_IsUpdated_DMS_FD1_0x24D_DMS_FD1_0x24D(void)
 *   boolean Rte_IsUpdated_DSM1_0x2C1_DSM1_0x2C1(void)
 *   boolean Rte_IsUpdated_ECM11_0x2D3_ECM11_0x2D3(void)
 *   boolean Rte_IsUpdated_ECM1_0x111_ECM1_0x111(void)
 *   boolean Rte_IsUpdated_ECM2_0x271_ECM2_0x271(void)
 *   boolean Rte_IsUpdated_ECM3_0x371_ECM3_0x371(void)
 *   boolean Rte_IsUpdated_ECM_PT7_0x117_ECM_PT7_0x117(void)
 *   boolean Rte_IsUpdated_EEM1_0x2A8_EEM1_0x2A8(void)
 *   boolean Rte_IsUpdated_ELD1_0x152_ELD1_0x152(void)
 *   boolean Rte_IsUpdated_EPB1_0x16B_EPB1_0x16B(void)
 *   boolean Rte_IsUpdated_EPS1_0x168_EPS1_0x168(void)
 *   boolean Rte_IsUpdated_EPS_FD1_0x147_EPS_FD1_0x147(void)
 *   boolean Rte_IsUpdated_ESCL2_0x303_ESCL2_0x303(void)
 *   boolean Rte_IsUpdated_ESP10_0xD8_ESP10_0xD8(void)
 *   boolean Rte_IsUpdated_ESP11_0xC8_ESP11_0xC8(void)
 *   boolean Rte_IsUpdated_ESP1_0x149_ESP1_0x149(void)
 *   boolean Rte_IsUpdated_ESP2_0x145_ESP2_0x145(void)
 *   boolean Rte_IsUpdated_ESP8_0x170_ESP8_0x170(void)
 *   boolean Rte_IsUpdated_ESP_FD2_0x137_ESP_FD2_0x137(void)
 *   boolean Rte_IsUpdated_FPAS1_0x26D_FPAS1_0x26D(void)
 *   boolean Rte_IsUpdated_F_PBox1_0x19B_F_PBox1_0x19B(void)
 *   boolean Rte_IsUpdated_GW_FD1_0x2BB_GW_FD1_0x2BB(void)
 *   boolean Rte_IsUpdated_HAP_FD1_0x15B_HAP_FD1_0x15B(void)
 *   boolean Rte_IsUpdated_HAP_FD2_0x274_HAP_FD2_0x274(void)
 *   boolean Rte_IsUpdated_HAP_FD3_0x298_HAP_FD3_0x298(void)
 *   boolean Rte_IsUpdated_HAP_FD6_0x289_HAP_FD6_0x289(void)
 *   boolean Rte_IsUpdated_HAP_FD7_0x29B_HAP_FD7_0x29B(void)
 *   boolean Rte_IsUpdated_HC1_0x287_HC1_0x287(void)
 *   boolean Rte_IsUpdated_HCM_L1_0x308_HCM_L1_0x308(void)
 *   boolean Rte_IsUpdated_HCM_R1_0x30D_HCM_R1_0x30D(void)
 *   boolean Rte_IsUpdated_HCU_FD1_0x60_HCU_FD1_0x60(void)
 *   boolean Rte_IsUpdated_HCU_HC3_0x268_HCU_HC3_0x268(void)
 *   boolean Rte_IsUpdated_HCU_HC6_0x314_HCU_HC6_0x314(void)
 *   boolean Rte_IsUpdated_HCU_HC7_0x3C2_HCU_HC7_0x3C2(void)
 *   boolean Rte_IsUpdated_HCU_HP5_0x201_HCU_HP5_0x201(void)
 *   boolean Rte_IsUpdated_HCU_HP6_0x11A_HCU_HP6_0x11A(void)
 *   boolean Rte_IsUpdated_HCU_PT4_0x2FA_HCU_PT4_0x2FA(void)
 *   boolean Rte_IsUpdated_HCU_PT5_0x14A_HCU_PT5_0x14A(void)
 *   boolean Rte_IsUpdated_HCU_PT7_0x248_HCU_PT7_0x248(void)
 *   boolean Rte_IsUpdated_HCU_PT8_0x1C0_HCU_PT8_0x1C0(void)
 *   boolean Rte_IsUpdated_HUD1_0x325_HUD1_0x325(void)
 *   boolean Rte_IsUpdated_Haldex1_0x251_Haldex1_0x251(void)
 *   boolean Rte_IsUpdated_IFC_FD2_0x23D_IFC_FD2_0x23D(void)
 *   boolean Rte_IsUpdated_IFC_FD3_0x2CF_IFC_FD3_0x2CF(void)
 *   boolean Rte_IsUpdated_IFC_FD5_0x19F_IFC_FD5_0x19F(void)
 *   boolean Rte_IsUpdated_IFC_FD6_0x222_IFC_FD6_0x222(void)
 *   boolean Rte_IsUpdated_OBC1_0x316_OBC1_0x316(void)
 *   boolean Rte_IsUpdated_OBC2_0x317_OBC2_0x317(void)
 *   boolean Rte_IsUpdated_PDCM1_0x2CD_PDCM1_0x2CD(void)
 *   boolean Rte_IsUpdated_PEPS2_0x295_PEPS2_0x295(void)
 *   boolean Rte_IsUpdated_PEPS4_0x302_PEPS4_0x302(void)
 *   boolean Rte_IsUpdated_PLG_1_0x2FE_PLG_1_0x2FE(void)
 *   boolean Rte_IsUpdated_RPAS1_0x26E_RPAS1_0x26E(void)
 *   boolean Rte_IsUpdated_RPAS2_0x2ED_RPAS2_0x2ED(void)
 *   boolean Rte_IsUpdated_RSDS_FD1_0x16F_RSDS_FD1_0x16F(void)
 *   boolean Rte_IsUpdated_RSDS_FD2_0x30A_RSDS_FD2_0x30A(void)
 *   boolean Rte_IsUpdated_R_PBox1_0x19C_R_PBox1_0x19C(void)
 *   boolean Rte_IsUpdated_SCM1_0x2D1_SCM1_0x2D1(void)
 *   boolean Rte_IsUpdated_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC6_ACC_FD2_SG_ACC6_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC7_ACC_FD2_SG_ACC7_ACC_FD2(void)
 *   boolean Rte_IsUpdated_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(void)
 *   boolean Rte_IsUpdated_TMCU_FD3_0x3C9_TMCU_FD3_0x3C9(void)
 *   boolean Rte_IsUpdated_TPMS2_0x395_TPMS2_0x395(void)
 *   boolean Rte_IsUpdated_T_Box_FD1_0x33_T_Box_FD1_0x33(void)
 *   boolean Rte_IsUpdated_VSG1_0x2E1_VSG1_0x2E1(void)
 *   boolean Rte_IsUpdated_WPC1_0x2BA_WPC1_0x2BA(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   uint8 *Rte_IRead_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes(void)
 *     Returnvalue: uint8* is of type VconfigKind_157Bytes
 *   FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Fuel_Set_Module_Data_Element(void)
 *   SystemState_RecordType *Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut(void)
 *   sint64 Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_ReceiveRTCTime_SleepDateTime(void)
 *   sint64 Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_ReceiveRTCTime_UtcTime(void)
 *   TC_MODULE_OUTPUT_DATA_STRUCT_RTE *Rte_IRead_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_TC_Module_Output_Data_Element(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HUT10_0x331_HUT10_0x331(const uint8 *data)
 *     Argument data: uint8* is of type HUT10_0x331
 *   Std_ReturnType Rte_Write_HUT13_0x31C_HUT13_0x31C(const uint8 *data)
 *     Argument data: uint8* is of type HUT13_0x31C
 *   Std_ReturnType Rte_Write_HUT15_0x1EE_HUT15_0x1EE(const uint8 *data)
 *     Argument data: uint8* is of type HUT15_0x1EE
 *   Std_ReturnType Rte_Write_HUT16_0x348_HUT16_0x348(const uint8 *data)
 *     Argument data: uint8* is of type HUT16_0x348
 *   Std_ReturnType Rte_Write_HUT17_0x33B_HUT17_0x33B(const uint8 *data)
 *     Argument data: uint8* is of type HUT17_0x33B
 *   Std_ReturnType Rte_Write_HUT19_0x415_HUT19_0x415(const uint8 *data)
 *     Argument data: uint8* is of type HUT19_0x415
 *   Std_ReturnType Rte_Write_HUT1_0x367_HUT1_0x367(const uint8 *data)
 *     Argument data: uint8* is of type HUT1_0x367
 *   Std_ReturnType Rte_Write_HUT20_0x2DE_HUT20_0x2DE(const uint8 *data)
 *     Argument data: uint8* is of type HUT20_0x2DE
 *   Std_ReturnType Rte_Write_HUT21_0x2DD_HUT21_0x2DD(const uint8 *data)
 *     Argument data: uint8* is of type HUT21_0x2DD
 *   Std_ReturnType Rte_Write_HUT22_0x2DA_HUT22_0x2DA(const uint8 *data)
 *     Argument data: uint8* is of type HUT22_0x2DA
 *   Std_ReturnType Rte_Write_HUT23_0x2D8_HUT23_0x2D8(const uint8 *data)
 *     Argument data: uint8* is of type HUT23_0x2D8
 *   Std_ReturnType Rte_Write_HUT25_0x339_HUT25_0x339(const uint8 *data)
 *     Argument data: uint8* is of type HUT25_0x339
 *   Std_ReturnType Rte_Write_HUT26_0x2B6_HUT26_0x2B6(const uint8 *data)
 *     Argument data: uint8* is of type HUT26_0x2B6
 *   Std_ReturnType Rte_Write_HUT2_0x369_HUT2_0x369(const uint8 *data)
 *     Argument data: uint8* is of type HUT2_0x369
 *   Std_ReturnType Rte_Write_HUT30_0x1E9_HUT30_0x1E9(const uint8 *data)
 *     Argument data: uint8* is of type HUT30_0x1E9
 *   Std_ReturnType Rte_Write_HUT32_0x26F_HUT32_0x26F(const uint8 *data)
 *     Argument data: uint8* is of type HUT32_0x26F
 *   Std_ReturnType Rte_Write_HUT33_0x1ED_HUT33_0x1ED(const uint8 *data)
 *     Argument data: uint8* is of type HUT33_0x1ED
 *   Std_ReturnType Rte_Write_HUT34_0x370_HUT34_0x370(const uint8 *data)
 *     Argument data: uint8* is of type HUT34_0x370
 *   Std_ReturnType Rte_Write_HUT35_0x1E5_HUT35_0x1E5(const uint8 *data)
 *     Argument data: uint8* is of type HUT35_0x1E5
 *   Std_ReturnType Rte_Write_HUT39_0x1EB_HUT39_0x1EB(const uint8 *data)
 *     Argument data: uint8* is of type HUT39_0x1EB
 *   Std_ReturnType Rte_Write_HUT3_0x36B_HUT3_0x36B(const uint8 *data)
 *     Argument data: uint8* is of type HUT3_0x36B
 *   Std_ReturnType Rte_Write_HUT40_0x2CE_HUT40_0x2CE(const uint8 *data)
 *     Argument data: uint8* is of type HUT40_0x2CE
 *   Std_ReturnType Rte_Write_HUT4_0x36D_HUT4_0x36D(const uint8 *data)
 *     Argument data: uint8* is of type HUT4_0x36D
 *   Std_ReturnType Rte_Write_HUT6_0x4A_HUT6_0x4A(const uint8 *data)
 *     Argument data: uint8* is of type HUT6_0x4A
 *   Std_ReturnType Rte_Write_HUT_FD1_0x2C3_HUT_FD1_0x2C3(const uint8 *data)
 *     Argument data: uint8* is of type HUT_FD1_0x2C3
 *   Std_ReturnType Rte_Write_HUT_FD4_0x1DA_HUT_FD4_0x1DA(const uint8 *data)
 *     Argument data: uint8* is of type HUT_FD4_0x1DA
 *   Std_ReturnType Rte_Write_HUT_IP1_0x293_HUT_IP1_0x293(const uint8 *data)
 *     Argument data: uint8* is of type HUT_IP1_0x293
 *   Std_ReturnType Rte_Write_HUT_IP2_0x27F_HUT_IP2_0x27F(const uint8 *data)
 *     Argument data: uint8* is of type HUT_IP2_0x27F
 *   Std_ReturnType Rte_Write_HUT_IP3_0x34A_HUT_IP3_0x34A(const uint8 *data)
 *     Argument data: uint8* is of type HUT_IP3_0x34A
 *   Std_ReturnType Rte_Write_IP_AvgFuelCons_IP_AvgFuelCons(IP_AvgFuelCons data)
 *   Std_ReturnType Rte_Write_IP_CurrTheme_IP_CurrTheme(IP_CurrTheme data)
 *   Std_ReturnType Rte_Write_IP_FuelAuxTankR_IP_FuelAuxTankR(IP_FuelAuxTankR data)
 *   Std_ReturnType Rte_Write_IP_FuelMainTankR_IP_FuelMainTankR(IP_FuelMainTankR data)
 *   Std_ReturnType Rte_Write_IP_InstFuelCons_IP_InstFuelCons(IP_InstFuelCons data)
 *   Std_ReturnType Rte_Write_IP_InstFuelConsUnit_IP_InstFuelConsUnit(IP_InstFuelConsUnit data)
 *   Std_ReturnType Rte_Write_IP_LagueSet_IP_LagueSet(IP_LagueSet data)
 *   Std_ReturnType Rte_Write_IP_RemainDistance_IP_RemainDistance(IP_RemainDistance data)
 *   Std_ReturnType Rte_Write_IP_VehSpdDisp_IP_VehSpdDisp(IP_VehSpdDisp data)
 *   Std_ReturnType Rte_Write_IP_VelSpdDisp_Mile_IP_VelSpdDisp_Mile(IP_VelSpdDisp_Mile data)
 *   Std_ReturnType Rte_Write_SG_HUT32_SG_HUT32(const SG_HUT32 *data)
 *   Std_ReturnType Rte_Write_SG_HUT_IP2_SG_HUT_IP2(const SG_HUT_IP2 *data)
 *   Std_ReturnType Rte_Write_SocReadyFlag_Element(uint8 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCGateWay_EnergyInfoId_Data(const EnergyInfoIdDataType *data)
 *   Std_ReturnType Rte_Write_ppSR_SWCGateWay_S2M_Information_SpeedValue(uint16 data)
 *   Std_ReturnType Rte_Write_ppSR_SWCGateWay_S2M_Information_TachoValue(uint16 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CNA_SignalSet_Operation(uint16 signalId, uint32 *value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CNA_SignalSet_Std_ReturnType
 *   Std_ReturnType Rte_Call_IPC_DataSend_If_Operation(uint8 *p_msg, uint16 len, uint8 priority)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IPC_DataSend_If_E_N_OK
 *   Std_ReturnType Rte_Call_rcCS_SWCGateWay_ReceiveSafetyGearCRC_Callback(uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rcCS_SWCGateWay_ReceiveSafetyTTCRC_Callback(uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rcCS_SWCNormal_ChimeCallback_Operation(uint8 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rcCS_SWCNormal_HMIResetTC_Callback(uint8 *data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rcCS_SWCNormal_ReceiveMenuSetting_Callback(uint8 *data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rcCS_SWCNormal_TTCallback_Operation(uint8 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rcCS_SWCNormal_WrnCallback_Operation(uint8 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_AppClearDTCInfo_AppClearDTCInfo(uint8 OpStatus, uint8 *Result)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_AppReadDtcInfomation_AppReadDtcInformation(uint8 *DtcInfo)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_GetCANMatrixVersionInfo_Data(uint8 *data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_GetVehicleModeInfo_Data(uint8 *data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_AdasStatus_Callback(uint8 *data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_CNA_SignalSetNoTrigger_Operation(uint16 signalId, uint8 *value)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CNA_SignalSetNoTrigger_Std_ReturnType
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_CNA_SignalSet_U8N_Operation(uint16 signalId, uint8 *value)
 *     Argument value: uint8* is of type EventSignalType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CNA_SignalSet_U8N_Std_ReturnType
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_ComEx_GetRxE2EStatus(ComEx_SignalGroupIdType GroupId, uint32 *E2eStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_ComEx_ReceiveSignal(ComEx_SignalIdType SignalId, uint8 *SignalDataPtr, uint8 Length)
 *     Argument SignalDataPtr: uint8* is of type ComEx_SignalDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED, RTE_E_ComEx_COMEX_NEVER_RECEIVED, RTE_E_ComEx_COMEX_UPDATE_RECEIVED, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_ComEx_SendSignal(ComEx_SignalIdType SignalId, ComEx_ConstSignalDataType SignalDataPtr, uint8 Length)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComEx_COMEX_ERROR_PARAM, RTE_E_ComEx_E_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_E2ESwitchStatusRead_Operation(uint8 Length, uint8 *Data, uint8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_E2ESwitchStatusWrite_Operation(uint8 Length, uint8 *Data, uint8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_GetVinNumber_Operation(uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_ReceiveHMIPowerMode_Callback(uint8 *data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_ReceiveMenuTheme_Callback(uint8 *data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_ReceiveSafetyGearCRC_Callback(uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_ReceiveSafetyTTCRC_Callback(uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_SecOcSwitchStatusRead_Operation(uint8 Length, uint8 *Data, uint8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_SecOcSwitchStatusWrite_Operation(uint8 Length, uint8 *Data, uint8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_TC_EnergyInfo_Operation(EnergyInfoDataType Id, uint8 *Data)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateWay_TC_EnergyInfoResp_Operation(EnergyInfoDataType Id, boolean Resp)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rpCS_SWCGateway_UTCTime_UTC2PerpetualCalendar(sint64 utc, DateTimeType_t *date)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IRTC_Service_E_NOT_OK
 *   Std_ReturnType Rte_Call_rpCS_SWCSafety_TTCallback_Operation(uint8 *arg)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ComM_UserRequest_GetCurrentComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_GetMaxComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_GetRequestedComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_CAN_Data_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_RestoreBlockDefaults(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_Defs_NvBlockNeed_Block_IPC_Config_Data_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_Defs_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_Common_GateWay_5msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes(void)
 *   Std_ReturnType Rte_IStatus_Common_GateWay_5msMainFunction_rpSR_SWCGateWay_Power_Out_SystemStateOut(void)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea(void)
 *   void Rte_Exit_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_5msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) Common_GateWay_5msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_5msMainFunction
 *********************************************************************************************************************/

	IPC_CanRepeaterTask();
	IPC_ManagerTask();
	IPC_ApplicationTask();
	ALCM_API_vTimeTask();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_GateWay_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea(void)
 *   void Rte_Exit_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) Common_GateWay_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_Init
 *********************************************************************************************************************/
	IPC_CanRepeaterInit();
	IPC_ManagerInit();
	IPC_ApplicationInit();
	ALCM_API_vColdInit();

	vCA_Process_Init();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_GateWay_Nomal2Standby_Callbcak
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Nomal2StandbyCallback> of PortPrototype <rpCS_Common_GateWay_PowerTransfer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_GateWay_Nomal2Standby_Callbcak(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_Nomal2Standby_Callbcak_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) Common_GateWay_Nomal2Standby_Callbcak(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_Nomal2Standby_Callbcak
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_GateWay_Standby2Nomal_Callbcak
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Standby2NomalCallback> of PortPrototype <rpCS_Common_GateWay_PowerTransfer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_GateWay_Standby2Nomal_Callbcak(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_Standby2Nomal_Callbcak_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) Common_GateWay_Standby2Nomal_Callbcak(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_GateWay_Standby2Nomal_Callbcak
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IPC_API_SetEventTxSignalBuffer_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCGateWay_IPC_API_SetEventTxSignalBuffer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void IPC_API_SetEventTxSignalBuffer_Operation(uint32 EventIndex, uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_API_SetEventTxSignalBuffer_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) IPC_API_SetEventTxSignalBuffer_Operation(uint32 EventIndex, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_API_SetEventTxSignalBuffer_Operation
 *********************************************************************************************************************/

	IPC_API_SetEventTxSignalBuffer( EventIndex , (void*)Data );

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IPC_Send_IPC_Send
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IPC_Send> of PortPrototype <IPC_Send>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType IPC_Send_IPC_Send(uint8 Id_u8, uint8 *data_s, uint16 len_u16, boolean Imm_bool)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_IPC_Send_Std_ReturnType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_Send_IPC_Send_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Common_GateWay_CODE) IPC_Send_IPC_Send(uint8 Id_u8, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) data_s, uint16 len_u16, boolean Imm_bool) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_Send_IPC_Send (returns application error)
 *********************************************************************************************************************/
	IPC_API_AppMsgTransmit(Id_u8,data_s,len_u16,Imm_bool);

	return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IPC_TransmitSignal_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <ppCS_SWCGateWay_IPC_TransmitSignal>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void IPC_TransmitSignal_Callback(uint32 SignalIndex, uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_TransmitSignal_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) IPC_TransmitSignal_Callback(uint32 SignalIndex, P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_TransmitSignal_Callback
 *********************************************************************************************************************/

	IPC_API_UploadEventTxSignalCallback( SignalIndex , (void*) Data );

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IPC_Tx_E2E_CanMsg_HUT32_CallBack
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallBack> of PortPrototype <ppCS_SWCGateWay_IPC_Tx_E2E_CanMsg_HUT32>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void IPC_Tx_E2E_CanMsg_HUT32_CallBack(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_Tx_E2E_CanMsg_HUT32_CallBack_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) IPC_Tx_E2E_CanMsg_HUT32_CallBack(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_Tx_E2E_CanMsg_HUT32_CallBack
 *********************************************************************************************************************/

	IPC_API_E2eTxCanMsgDownLoadCallback( SWC_IPC_CAN_MSG_HUT32 );

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IPC_Tx_E2E_CanMsg_HUT_IP2_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <ppCS_SWCGateWay_IPC_Tx_E2E_CanMsg_HUT_IP2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void IPC_Tx_E2E_CanMsg_HUT_IP2_Callback(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_Tx_E2E_CanMsg_HUT_IP2_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) IPC_Tx_E2E_CanMsg_HUT_IP2_Callback(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IPC_Tx_E2E_CanMsg_HUT_IP2_Callback
 *********************************************************************************************************************/

//   IPC_API_E2eTxCanMsgDownLoadCallback( SWC_IPC_CAN_MSG_IP2 );

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_IPC_CAN_Data_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <JobFinished> of PortPrototype <NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NvMNotifyJobFinished_NvBlockNeed_Block_IPC_Config_Data_JobFinished
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ppCS_SWCNormal_Callback_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppCS_SWCNormal_Callback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void ppCS_SWCNormal_Callback_Operation(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_Callback_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_GateWay_CODE) ppCS_SWCNormal_Callback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_GATEWAY_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ppCS_SWCNormal_Callback_Operation
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Common_GateWay_STOP_SEC_CODE
#include "Common_GateWay_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: runnable implementation:SWC_CAN_Init)  ***********************************/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:SWC_CAN_Init_doc)  ************************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:SWC_CAN_MainFunction_doc)  ****************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:SWC_CAN_MainFunction)  ***************************/
	IPC_MainFunTask();
	IPC_ManageMainFunTask();
/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:E2ESwitchChangeIndication)  **********************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:E2ESwitchChangeIndication_doc)  ***********************/


/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
