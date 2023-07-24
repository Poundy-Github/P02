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
 *             File:  Common_Safety.c
 *           Config:  D:/01Project/1-25-2/Davinci_P05/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Common_Safety
 *  Generation Time:  2021-01-26 19:33:09
 *
 *        Generator:  MICROSAR RTE Generator Version 4.22.0
 *                    RTE Core Version 1.22.0
 *          License:  CBD2000298
 *
 *      Description:  C-Code implementation template for SW-C <Common_Safety>
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
 * TimeInMicrosecondsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * WdgM_CheckpointIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 *
 * Operation Prototypes:
 * =====================
 * GetCounterValue of Port Interface Os_Service
 *   This service reads the current count value of a counter (returning either the hardware timer ticks if counter is driven by hardware or the software ticks when user drives counter).
 *
 * GetElapsedValue of Port Interface Os_Service
 *   This service gets the number of ticks between the current tick value and a previously read tick value.
 *
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   Indicates to the Watchdog Manager that a Checkpoint within a Supervised Entity has been reached.
 *
 *********************************************************************************************************************/

#include "Rte_Common_Safety.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_TT_Safety.h"
#include "SWC_Gear.h"
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
 * ABSActv_0x137: Boolean
 * ABSActv_0x265: Boolean
 * ABSFailSts_0x137: Boolean
 * ABSFailSts_0x265: Boolean
 * AEB_JA_Resp_3: Boolean
 * AEB_PedResp_3: Boolean
 * AEB_PedTrig_2: Boolean
 * AEB_VehResp_3: Boolean
 * AEB_VehTrig_2: Boolean
 * AirbFailLmpCmd_4: Boolean
 * CDPActv_0x137: Boolean
 * CDPActv_0x145: Boolean
 * DrvSBR_4: Boolean
 * EBDFailSts_0x137: Boolean
 * EBDFailSts_0x265: Boolean
 * ESPActvInfoLmp_0x137: Boolean
 * ESPActvInfoLmp_0x149: Boolean
 * ESPFailSts_0x137: Boolean
 * ESPFailSts_0x149: Boolean
 * ESPFuncOffSts_0x137: Boolean
 * ESPFuncOffSts_0x149: Boolean
 * FFogLmpSts_F_PBOX: Boolean
 * FourL_Warn_0x137: Boolean
 * FourL_Warn_0x145: Boolean
 * HiBeamSts_F_PBOX: Boolean
 * HiPosnBrkLmpFailSts: Boolean
 * HoodSts_F_PBOX: Boolean
 * IFC_NextLeLane_dy: Integer in interval [0...65535]
 * IFC_NextRiLane_dy: Integer in interval [0...65535]
 * LBrkLmpFailSts: Boolean
 * LHeadLmpFailSts: Boolean
 * LHiBeamFailSts: Boolean
 * LLasHdLmpDiagSig: Boolean
 * LLowBeamFailSts: Boolean
 * LRPosnLmpFailSts: Boolean
 * LTurnLmpSts_R_PBOX: Boolean
 * LasHdLmpSts_F_PBOX: Boolean
 * LicPlateLmpFailSts: Boolean
 * Over_Spd_Warn_0x137: Boolean
 * Over_Spd_Warn_0x145: Boolean
 * ParkLmpSts_R_PBOX: Boolean
 * PassSBR_4: Boolean
 * PosnLmpOutpSts_R_PBOX: Boolean
 * PressBrakePedalPointOut: Boolean
 * RBrkLmpFailSts: Boolean
 * RFogLmpFailSts_R_PBOX: Boolean
 * RFogLmpSts_R_PBOX: Boolean
 * RHeadLmpFailSts: Boolean
 * RHiBeamFailSts: Boolean
 * RLasHdLmpDiagSig: Boolean
 * RLowBeamFailSts: Boolean
 * RRPosnLmpFailSts: Boolean
 * RTurnLmpSts_R_PBOX: Boolean
 * RWinHeatgFailSts: Boolean
 * RWinHeatgIconRlyCmd: Boolean
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * RvsLmpFailSts: Boolean
 * SecRowLSBR_4: Boolean
 * SecRowMidSBR_4: Boolean
 * SecRowRSBR_4: Boolean
 * Shift_N_Warn_0x137: Boolean
 * Shift_N_Warn_0x145: Boolean
 * SteerCorrnResp_0x147: Boolean
 * SteerCorrnResp_0x168: Boolean
 * TCU_Warn_P_faulty: Boolean
 * TCU_Warn_drive_faulty: Boolean
 * TCU_Warn_driver_leaves_car: Boolean
 * TCU_Warn_gearbox_N: Boolean
 * TCU_Warn_gearbox_faulty: Boolean
 * TCU_Warn_high_temp: Boolean
 * TCU_Warn_limphome_D: Boolean
 * TCU_Warn_limphome_P: Boolean
 * TCU_Warn_prohibit_P: Boolean
 * TCU_Warn_release_button: Boolean
 * TCU_Warn_shifter_faulty: Boolean
 * TCU_Warn_step_P: Boolean
 * TCU_Warn_vehicle_P: Boolean
 * TCU_gear_flashing: Boolean
 * TRANS_OIL_TEMP_0x236: Integer in interval [0...255]
 * TRANS_OIL_TEMP_0xc6: Integer in interval [0...255]
 * TSM_Trailer_0x137: Boolean
 * TSM_Trailer_0x149: Boolean
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * VehOdoInfoSts_0x137: Boolean
 * VehOdoInfoSts_0x265: Boolean
 * VehSpdVld_0x137: Boolean
 * VehSpdVld_0x265: Boolean
 * VehSpd_0x137_2: Integer in interval [0...65535]
 * VehSpd_0x265: Integer in interval [0...65535]
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * boolean: Boolean (standard type)
 * dummy_ABM1_0: Boolean
 * dummy_ABM1_1: Boolean
 * dummy_ABM1_2: Integer in interval [0...255]
 * dummy_ABM1_3: Integer in interval [0...255]
 * dummy_ABM1_4: Integer in interval [0...255]
 * dummy_ABM1_5: Integer in interval [0...255]
 * dummy_ABS3_0: Integer in interval [0...255]
 * dummy_ABS3_1: Integer in interval [0...255]
 * dummy_ABS3_2: Integer in interval [0...255]
 * dummy_ABS3_3: Integer in interval [0...255]
 * dummy_AEB_FD2_22: Integer in interval [0...255]
 * dummy_AEB_FD2_23: Integer in interval [0...255]
 * dummy_AEB_FD2_24: Integer in interval [0...255]
 * dummy_AEB_FD2_25: Integer in interval [0...255]
 * dummy_AEB_FD2_26: Integer in interval [0...255]
 * dummy_AEB_FD2_27: Integer in interval [0...255]
 * dummy_AEB_FD2_28: Integer in interval [0...255]
 * dummy_AEB_FD2_29: Integer in interval [0...255]
 * dummy_AEB_FD2_30: Boolean
 * dummy_AEB_FD2_31: Integer in interval [0...255]
 * dummy_AEB_FD2_32: Integer in interval [0...255]
 * dummy_AEB_FD2_33: Integer in interval [0...255]
 * dummy_AEB_FD2_34: Integer in interval [0...255]
 * dummy_AEB_FD2_35: Integer in interval [0...255]
 * dummy_DCT_FD4_10: Boolean
 * dummy_DCT_FD4_11: Integer in interval [0...255]
 * dummy_DCT_FD4_8: Integer in interval [0...255]
 * dummy_DCT_FD4_9: Integer in interval [0...255]
 * dummy_EPB1_0: Integer in interval [0...255]
 * dummy_EPB1_1: Integer in interval [0...255]
 * dummy_EPB1_2: Boolean
 * dummy_EPB1_3: Integer in interval [0...255]
 * dummy_EPB1_4: Integer in interval [0...255]
 * dummy_EPB1_5: Integer in interval [0...255]
 * dummy_EPB1_6: Integer in interval [0...255]
 * dummy_EPB1_7: Integer in interval [0...255]
 * dummy_EPS1_10: Integer in interval [0...255]
 * dummy_EPS1_11: Integer in interval [0...255]
 * dummy_EPS1_12: Integer in interval [0...255]
 * dummy_EPS1_13: Integer in interval [0...255]
 * dummy_EPS1_14: Integer in interval [0...255]
 * dummy_EPS1_15: Boolean
 * dummy_EPS1_8: Integer in interval [0...255]
 * dummy_EPS1_9: Integer in interval [0...255]
 * dummy_EPS_FD1_24: Integer in interval [0...255]
 * dummy_EPS_FD1_25: Integer in interval [0...255]
 * dummy_EPS_FD1_26: Integer in interval [0...255]
 * dummy_EPS_FD1_27: Integer in interval [0...255]
 * dummy_EPS_FD1_28: Integer in interval [0...255]
 * dummy_EPS_FD1_29: Integer in interval [0...255]
 * dummy_EPS_FD1_30: Integer in interval [0...255]
 * dummy_EPS_FD1_31: Boolean
 * dummy_ESP1_13: Boolean
 * dummy_ESP1_14: Integer in interval [0...255]
 * dummy_ESP1_15: Integer in interval [0...255]
 * dummy_ESP1_16: Integer in interval [0...255]
 * dummy_ESP1_17: Integer in interval [0...255]
 * dummy_ESP1_18: Integer in interval [0...255]
 * dummy_ESP1_19: Integer in interval [0...255]
 * dummy_ESP1_20: Integer in interval [0...255]
 * dummy_ESP2_10: Integer in interval [0...255]
 * dummy_ESP2_11: Boolean
 * dummy_ESP2_12: Boolean
 * dummy_ESP2_13: Integer in interval [0...255]
 * dummy_ESP2_14: Integer in interval [0...255]
 * dummy_ESP2_8: Integer in interval [0...255]
 * dummy_ESP2_9: Integer in interval [0...255]
 * dummy_ESP_FD2_34: Integer in interval [0...255]
 * dummy_ESP_FD2_35: Integer in interval [0...255]
 * dummy_ESP_FD2_36: Integer in interval [0...255]
 * dummy_ESP_FD2_41: Integer in interval [0...255]
 * dummy_ESP_FD2_42: Integer in interval [0...255]
 * dummy_ESP_FD2_43: Integer in interval [0...255]
 * dummy_ESP_FD2_44: Integer in interval [0...255]
 * dummy_ESP_FD2_45: Integer in interval [0...255]
 * dummy_ESP_FD2_46: Integer in interval [0...255]
 * dummy_ESP_FD2_47: Boolean
 * dummy_ESP_FD2_48: Integer in interval [0...255]
 * dummy_ESP_FD2_49: Integer in interval [0...255]
 * dummy_ESP_FD2_57: Integer in interval [0...255]
 * dummy_ESP_FD2_58: Integer in interval [0...255]
 * dummy_ESP_FD2_59: Integer in interval [0...255]
 * dummy_ESP_FD2_60: Boolean
 * dummy_ESP_FD2_61: Boolean
 * dummy_ESP_FD2_62: Integer in interval [0...255]
 * dummy_ESP_FD2_63: Integer in interval [0...255]
 * dummy_IFC_FD2_17: Integer in interval [0...255]
 * dummy_IFC_FD2_18: Integer in interval [0...255]
 * dummy_IFC_FD2_19: Integer in interval [0...255]
 * dummy_IFC_FD2_20: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * AEB_JABrkTrig_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_tirggered (0U)
 *   Cx1_AEB_JA_Function_Triggered_for_vehicle (1U)
 *   Cx2_AEB_JA_Function_Triggered_for_pedestrian (2U)
 *   Cx3_reverse (3U)
 * AEB_JAFuncSts_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_error (1U)
 *   Cx2_FCWAEB_JA_temporarily_unavailable (2U)
 *   Cx3_FCWAEB_JA_Performance_degradation (3U)
 * AEB_JA_Warn_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Warning_for_vehicle (1U)
 *   Cx2_Warning_for_pedestrian (2U)
 *   Cx3_reverse (3U)
 * AVHErrSts_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_AVH_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * AVHErrSts_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_AVH_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * AVHSts_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Standby (1U)
 *   Cx2_active (2U)
 *   Cx3_Reserved (3U)
 * AVHSts_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Standby (1U)
 *   Cx2_active (2U)
 *   Cx3_Reserved (3U)
 * CheckSum_ABM1_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ABS3_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_DCT7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_EPB1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_EPS1_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_EPS1_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ESP1_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ESP1_0x149: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ESP2_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ESP2_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * Checksum_AEB2_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_AEB3_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_IFC6: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * CrashOutputSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_crash (0U)
 *   Cx01_Reserved (1U)
 *   Cx02_Front_First_level (2U)
 *   Cx03_rear_crash_Reserved_ (3U)
 *   Cx04_Reserved (4U)
 *   Cx07_Reserved (7U)
 *   Cx08_Right_hand_side (8U)
 *   Cx09_Reserved (9U)
 *   Cx0F_Reserved (15U)
 *   Cx10_Left_hand_side (16U)
 *   Cx11_Rollover_Reserved_ (17U)
 *   Cx12_Static_Roll_Reserved_ (18U)
 *   Cx13_Reserved (19U)
 *   CxFF_Reserved (255U)
 * DCT_PrsBrk_Warn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Press_brake_and_Unlock_button_to_shift (1U)
 *   Cx2_Press_Unlock_button_to_shift (2U)
 *   Cx3_Press_brake_to_shift (3U)
 * DCT_RaceModeSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 *   Cx2_Turn_Off (2U)
 *   Cx3_Forbidden (3U)
 *   Cx4_Reserved_treat_as_0x0_inactive_ (4U)
 *   Cx7_Reserved_treat_as_0x0_inactive_ (7U)
 * DCT_ShftNotAlwd_Warn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Vehicle_speed_too_high_shift_not_allowed (1U)
 *   Cx2_Engage_P_not_allowed_due_to_high_vehicle_speed (2U)
 *   Cx3_Transmission_is_in_N_park_lock_is_not_locked (3U)
 * DCT_ShftRecom_M: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Recommendation (0U)
 *   Cx1_Up_Shift (1U)
 *   Cx2_Down_Shift (2U)
 *   Cx3_Reserved (3U)
 * DisplayGear: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Current_gear_N (0U)
 *   Cx1_Current_gear_1 (1U)
 *   Cx2_Current_gear_2 (2U)
 *   Cx3_Current_gear_3 (3U)
 *   Cx4_Current_gear_4 (4U)
 *   Cx5_Current_gear_5 (5U)
 *   Cx6_Current_gear_6 (6U)
 *   Cx7_Current_gear_7 (7U)
 *   Cx8_Current_gear_8 (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Current_gear_R (11U)
 *   CxC_Reserved (12U)
 *   CxD_Current_gear_P (13U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid_Value (15U)
 * DrivingModDis_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Standard (0U)
 *   Cx01_Sport (1U)
 *   Cx02_Snow (2U)
 *   Cx03_Mud (3U)
 *   Cx04_Sand (4U)
 *   Cx05_4L (5U)
 *   Cx06_Economic (6U)
 *   Cx07_Mode_Unkown (7U)
 *   Cx08_AUTO (8U)
 *   Cx09_Sport_ (9U)
 *   Cx0A_Off_road (10U)
 *   Cx0B_Stand_2H (11U)
 *   Cx0C_Expert (12U)
 *   Cx0D_Stand_4H (13U)
 *   Cx0E_Failed (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Snow_4H (16U)
 *   Cx11_Normal_4L (17U)
 *   Cx12_Rock_4L (18U)
 *   Cx13_Pothle_4L (19U)
 *   Cx14_MudSand_4L (20U)
 *   Cx15_Mountain_4L (21U)
 *   Cx16_reserved (22U)
 *   Cx1F_reserved (31U)
 * DrivingModDis_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Standard (0U)
 *   Cx01_Sport (1U)
 *   Cx02_Snow (2U)
 *   Cx03_Mud (3U)
 *   Cx04_Sand (4U)
 *   Cx05_4L (5U)
 *   Cx06_Economic (6U)
 *   Cx07_Mode_Unkown (7U)
 *   Cx08_AUTO (8U)
 *   Cx09_Sport_ (9U)
 *   Cx0A_Off_road (10U)
 *   Cx0B_Stand_2H (11U)
 *   Cx0C_Expert (12U)
 *   Cx0D_Stand_4H (13U)
 *   Cx0E_Failed (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Snow_4H (16U)
 *   Cx11_Normal_4L (17U)
 *   Cx12_Rock_4L (18U)
 *   Cx13_Pothle_4L (19U)
 *   Cx14_MudSand_4L (20U)
 *   Cx15_Mountain_4L (21U)
 *   Cx16_reserved (22U)
 *   Cx1F_reserved (31U)
 * DrivingModReq_ESP_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_Terrain_Control (0U)
 *   Cx01_Standard (1U)
 *   Cx02_Sport (2U)
 *   Cx03_Snow_Nex (3U)
 *   Cx04_Expert (4U)
 *   Cx05_Deep_Mud (5U)
 *   Cx06_Reserved (6U)
 *   Cx07_Soft_sand (7U)
 *   Cx08_Reserved (8U)
 *   Cx09_4L (9U)
 *   Cx0A_Economic (10U)
 *   Cx0B_Reserved (11U)
 *   Cx0C_Snow_TOD (12U)
 *   Cx0D_Off_road (13U)
 *   Cx0E_Sport_ (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Standard_2H (16U)
 *   Cx11_Reserved (17U)
 *   Cx12_Standard_4H (18U)
 *   Cx13_Snow_4H (19U)
 *   Cx14_Normal_4L (20U)
 *   Cx15_Rock_4L (21U)
 *   Cx16_Pothole_4L (22U)
 *   Cx17_MudSand_4L (23U)
 *   Cx18_Mountain_4L (24U)
 *   Cx19_Reserved (25U)
 *   Cx1F_Reserved (31U)
 * DrivingModReq_ESP_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_Terrain_Control (0U)
 *   Cx01_Standard (1U)
 *   Cx02_Sport (2U)
 *   Cx03_Snow_Nex (3U)
 *   Cx04_Expert (4U)
 *   Cx05_Deep_Mud (5U)
 *   Cx06_Reserved (6U)
 *   Cx07_Soft_sand (7U)
 *   Cx08_Reserved (8U)
 *   Cx09_4L (9U)
 *   Cx0A_Economic (10U)
 *   Cx0B_Reserved (11U)
 *   Cx0C_Snow_TOD (12U)
 *   Cx0D_Off_road (13U)
 *   Cx0E_Sport_ (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Stand_2H (16U)
 *   Cx11_Reserved (17U)
 *   Cx12_Stand_4H (18U)
 *   Cx13_Snow_4H (19U)
 *   Cx14_Normal_4L (20U)
 *   Cx15_Rock_4L (21U)
 *   Cx16_Pothole_4L (22U)
 *   Cx17_MudSand_4L (23U)
 *   Cx18_Mountain_4L (24U)
 *   Cx19_Reserved (25U)
 *   Cx1F_Reserved (31U)
 * DrvAutoGearDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Neutral (0U)
 *   Cx1_1st_Gear (1U)
 *   Cx2_2nd_Gear (2U)
 *   Cx3_3rd_Gear (3U)
 *   Cx4_4th_Gear (4U)
 *   Cx5_5th_Gear (5U)
 *   Cx6_6th_Gear (6U)
 *   Cx7_7th_Gear (7U)
 *   Cx8_8th_Gear (8U)
 *   Cx9_9th_Gear (9U)
 *   CxA_Reserved (10U)
 *   CxF_Reserved (15U)
 * DrvFaiMsg: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Message (0U)
 *   Cx1_Transmission_Malfunction (1U)
 *   Cx2_Transmission_P_engagement_fault (2U)
 *   Cx3_Transmission_P_disengagement_fault (3U)
 *   Cx4_Authentication_failure (4U)
 *   Cx5_Reserved (5U)
 *   CxE_Reserved (14U)
 *   CxF_transmission_limit_function (15U)
 * DrvGearDispSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Blank_No_display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_display_ (3U)
 * DrvModDispSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_BlankNo_Display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_Display_ (3U)
 * DrvModDisp_0x236: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_P (0U)
 *   Cx1_R (1U)
 *   Cx2_N (2U)
 *   Cx3_D (3U)
 *   Cx4_M (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * DrvModDisp_0xc6: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_P (0U)
 *   Cx1_R (1U)
 *   Cx2_N (2U)
 *   Cx3_D (3U)
 *   Cx4_M (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * DrvSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * DrvWarnMsg: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Text (0U)
 *   Cx1_PressBrake (1U)
 *   Cx2_TransToo_Hot (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * EPBErrSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Undefined (0U)
 *   Cx1_No_Error (1U)
 *   Cx2_Error (2U)
 *   Cx3_Diagnosis (3U)
 * EPBRedLmpSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Lamp_flash (2U)
 *   Cx3_Reserved (3U)
 * EPBSts: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Released (0U)
 *   Cx1_Closed (1U)
 *   Cx2_In_progress (2U)
 *   Cx3_unknown (3U)
 * EPBTextDisp: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_Gradient_too_high (1U)
 *   Cx2_Park_brake_force_not_enough (2U)
 *   Cx3_Park_brake_system_overheated (3U)
 *   Cx4_Remind_driver_to_apply_safety_belt (4U)
 *   Cx5_Park_brake_maintenance_mode (5U)
 *   Cx6_Roller_bench_mode (6U)
 *   Cx7_Please_Release_EPB (7U)
 *   Cx8_Please_Release_Rear_ELD (8U)
 *   Cx9_Reserved (9U)
 *   CxF_Reserved (15U)
 * EPS_FailSts_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_fault (0U)
 *   Cx1_Permanent_Error_Detected (1U)
 *   Cx2_Intermittent_Error_Detected (2U)
 *   Cx3_Reserved (3U)
 * EPS_FailSts_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_fault (0U)
 *   Cx1_Permanent_Error_Detected (1U)
 *   Cx2_Intermittent_Error_Detected (2U)
 *   Cx3_Reserved (3U)
 * EPS_SteerMod_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Comfort_Mode (0U)
 *   Cx1_sport_mode (1U)
 *   Cx2_Handiness_Mode (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * EPS_SteerMod_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Comfort_Mode (0U)
 *   Cx1_sport_mode (1U)
 *   Cx2_Handiness_Mode (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * FCW_AEB_PedFctSts_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_error (1U)
 *   Cx2_FCWAEB_P_temporarily_unavailable (2U)
 *   Cx3_FCWAEB_P_Performance_degradation (3U)
 * FCW_AEB_VehFctSts_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_display (0U)
 *   Cx1_error (1U)
 *   Cx2_FCWAEB_V_temporarily_unavailable (2U)
 *   Cx3_FCWAEB_V_Performance_degradation (3U)
 * FCW_Snvty_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_High_sensitivity (1U)
 *   Cx2_Low_sensitivity (2U)
 *   Cx3_Reserved (3U)
 * FCW_Warn_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Latent_warning (1U)
 *   Cx2_warning_Level_1 (2U)
 *   Cx3_warning_Level_2 (3U)
 * HDCCtrl_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_On_active_braking (1U)
 *   Cx2_On_not_active_braking (2U)
 *   Cx3_Reserved (3U)
 * HDCCtrl_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_On_active_braking (1U)
 *   Cx2_On_not_active_braking (2U)
 *   Cx3_Reserved (3U)
 * HDCFault_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_HDC_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * HDCFault_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Failure_when_HDC_is_on_need (1U)
 *   Cx2_Failure_when_is_not_on_need (2U)
 *   Cx3_Reserved (3U)
 * LTurnLmpFailSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Short_circuit (1U)
 *   Cx2_Open_circuit (2U)
 *   Cx3_Reserved (3U)
 * PassSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * RTurnLmpFailSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Short_circuit (1U)
 *   Cx2_Open_circuit (2U)
 *   Cx3_Reserved (3U)
 * RollingCounter_ABM1_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ABS3_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_AEB2_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_AEB3_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_DCT7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_EPB1: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_EPS1_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_EPS1_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ESP1_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ESP1_0x149: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ESP2_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_ESP2_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_IFC6: Enumeration of integer in interval [0...255] with enumerators
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
 *   SYSTEMSTATE_IVI_ON_NORMAL (4U)
 *   SYSTEMSTATE_IVI_ON_POWER_ERROR (5U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_1 (6U)
 *   SYSTEMSTATE_IVI_ON_POWER_SAVE_2 (7U)
 *   SYSTEMSTATE_IVI_ON_LOCAL (8U)
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
 * SecRowLSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * SecRowMidSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * SecRowRSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * ShiftRecommend_M: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Recommendation (0U)
 *   Cx1_Up_Shift (1U)
 *   Cx2_Down_Shift (2U)
 *   Cx3_Reserved (3U)
 * SteerCorrnRmn_0x147: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Tip (0U)
 *   Cx1_Tip_return_finish (1U)
 *   Cx2_Tip_return_R (2U)
 *   Cx3_Tip_return_L (3U)
 * SteerCorrnRmn_0x168: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Tip (0U)
 *   Cx1_Tip_return_finish (1U)
 *   Cx2_Tip_return_R (2U)
 *   Cx3_Tip_return_L (3U)
 * TAB_Sts_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Function_OFF (0U)
 *   Cx1_Standby (1U)
 *   Cx2_Active (2U)
 *   Cx3_Failure (3U)
 * TAB_Sts_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Function_OFF (0U)
 *   Cx1_Standby (1U)
 *   Cx2_Active (2U)
 *   Cx3_Failure (3U)
 * TCU_Shift_not_allowed_Warn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Vehicle_speed_too_high_shift_not_allowed (1U)
 *   Cx2_Reversed (2U)
 *   Cx3_Reversed (3U)
 * TrsmStNID_0x236: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Break_down_powerflow (1U)
 *   Cx2_CSN_or_NUN_active (2U)
 *   Cx3_Geneate_power_flow (3U)
 *   Cx4_Reserve (4U)
 *   Cx7_Reserve (7U)
 * TrsmStNID_0xc6: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Break_down_powerflow (1U)
 *   Cx2_CSN_or_NUN_active (2U)
 *   Cx3_Geneate_power_flow (3U)
 *   Cx4_Reserve (4U)
 *   Cx7_Reserve (7U)
 * VehOdoInfo_0x137: Enumeration of integer in interval [0...65535] with enumerators
 *   Cx000_Valid_values (0U)
 *   Cx3E7_Valid_values (999U)
 *   Cx3E8_Reserved (1000U)
 *   Cx3FF_Reserved (1023U)
 * VehOdoInfo_0x265: Enumeration of integer in interval [0...65535] with enumerators
 *   Cx000_Valid_values (0U)
 *   Cx3E7_Valid_values (999U)
 *   Cx3E8_Reserved (1000U)
 *   Cx3FF_Reserved (1023U)
 *
 * Array Types:
 * ============
 * CconfigKind_400Bytes: Array with 400 element(s) of type uint8
 * VconfigKind_157Bytes: Array with 400 element(s) of type uint8
 * VconfigKind_400Bytes: Array with 400 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Rte_DT_SystemState_RecordType_5: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_5_0
 *   value of type Rte_DT_SystemState_RecordType_5_1
 * Rte_DT_SystemState_RecordType_7: Record with elements
 *   state of type Rte_DT_SystemState_RecordType_7_0
 *   temperature of type Rte_DT_SystemState_RecordType_7_1
 * SG_ABM1: Record with elements
 *   AirbFailLmpCmd of type AirbFailLmpCmd_4
 *   CheckSum_ABM1 of type CheckSum_ABM1_4
 *   DrvSBR of type DrvSBR_4
 *   DrvSBR_Visual of type DrvSBR_Visual_4
 *   PassSBR of type PassSBR_4
 *   PassSBR_Visual of type PassSBR_Visual_4
 *   RollingCounter_ABM1 of type RollingCounter_ABM1_4
 *   SecRowLSBR of type SecRowLSBR_4
 *   SecRowLSBR_Visual of type SecRowLSBR_Visual_4
 *   SecRowMidSBR of type SecRowMidSBR_4
 *   SecRowMidSBR_Visual of type SecRowMidSBR_Visual_4
 *   SecRowRSBR of type SecRowRSBR_4
 *   SecRowRSBR_Visual of type SecRowRSBR_Visual_4
 *   CrashOutputSts of type CrashOutputSts
 *   dummy_ABM1_0 of type dummy_ABM1_0
 *   dummy_ABM1_1 of type dummy_ABM1_1
 *   dummy_ABM1_2 of type dummy_ABM1_2
 *   dummy_ABM1_3 of type dummy_ABM1_3
 *   dummy_ABM1_4 of type dummy_ABM1_4
 *   dummy_ABM1_5 of type dummy_ABM1_5
 * SG_ABS3: Record with elements
 *   ABSActv_0x265 of type ABSActv_0x265
 *   ABSFailSts_0x265 of type ABSFailSts_0x265
 *   CheckSum_ABS3_0x265 of type CheckSum_ABS3_0x265
 *   dummy_ABS3_0 of type dummy_ABS3_0
 *   dummy_ABS3_1 of type dummy_ABS3_1
 *   dummy_ABS3_2 of type dummy_ABS3_2
 *   dummy_ABS3_3 of type dummy_ABS3_3
 *   EBDFailSts_0x265 of type EBDFailSts_0x265
 *   RollingCounter_ABS3_0x265 of type RollingCounter_ABS3_0x265
 *   VehOdoInfo_0x265 of type VehOdoInfo_0x265
 *   VehOdoInfoSts_0x265 of type VehOdoInfoSts_0x265
 *   VehSpd_0x265 of type VehSpd_0x265
 *   VehSpdVld_0x265 of type VehSpdVld_0x265
 * SG_ABS3_ESP_FD2: Record with elements
 *   ABSActv_0x137 of type ABSActv_0x137
 *   ABSFailSts_0x137 of type ABSFailSts_0x137
 *   CheckSum_ABS3_0x137 of type CheckSum_ABS3_0x137
 *   dummy_ESP_FD2_39 of type dummy_ESP_FD2_41
 *   dummy_ESP_FD2_40 of type dummy_ESP_FD2_42
 *   EBDFailSts_0x137 of type EBDFailSts_0x137
 *   RollingCounter_ABS3_0x137 of type RollingCounter_ABS3_0x137
 *   VehOdoInfo_0x137 of type VehOdoInfo_0x137
 *   VehOdoInfoSts_0x137 of type VehOdoInfoSts_0x137
 *   VehSpd_0x137 of type VehSpd_0x137_2
 *   VehSpdVld_0x137 of type VehSpdVld_0x137
 *   dummy_ESP_FD2_41 of type dummy_ESP_FD2_43
 *   dummy_ESP_FD2_42 of type dummy_ESP_FD2_44
 * SG_AEB2_AEB_FD2: Record with elements
 *   AEB_JA_Resp of type AEB_JA_Resp_3
 *   AEB_PedResp of type AEB_PedResp_3
 *   AEB_VehResp of type AEB_VehResp_3
 *   Checksum_AEB2 of type Checksum_AEB2_3
 *   FCW_Snvty of type FCW_Snvty_3
 *   RollingCounter_AEB2 of type RollingCounter_AEB2_3
 *   dummy_AEB_FD2_8 of type dummy_AEB_FD2_22
 *   dummy_AEB_FD2_9 of type dummy_AEB_FD2_23
 *   dummy_AEB_FD2_10 of type dummy_AEB_FD2_24
 *   dummy_AEB_FD2_11 of type dummy_AEB_FD2_25
 *   dummy_AEB_FD2_12 of type dummy_AEB_FD2_26
 *   dummy_AEB_FD2_13 of type dummy_AEB_FD2_27
 *   dummy_AEB_FD2_14 of type dummy_AEB_FD2_28
 * SG_AEB3_AEB_FD2: Record with elements
 *   AEB_JA_Warn of type AEB_JA_Warn_2
 *   AEB_JABrkTrig of type AEB_JABrkTrig_2
 *   AEB_JAFuncSts of type AEB_JAFuncSts_2
 *   AEB_PedTrig of type AEB_PedTrig_2
 *   AEB_VehTrig of type AEB_VehTrig_2
 *   Checksum_AEB3 of type Checksum_AEB3_2
 *   FCW_AEB_PedFctSts of type FCW_AEB_PedFctSts_2
 *   FCW_AEB_VehFctSts of type FCW_AEB_VehFctSts_2
 *   FCW_Warn of type FCW_Warn_2
 *   RollingCounter_AEB3 of type RollingCounter_AEB3_2
 *   dummy_AEB_FD2_15 of type dummy_AEB_FD2_29
 *   dummy_AEB_FD2_16 of type dummy_AEB_FD2_30
 *   dummy_AEB_FD2_17 of type dummy_AEB_FD2_31
 *   dummy_AEB_FD2_18 of type dummy_AEB_FD2_32
 *   dummy_AEB_FD2_19 of type dummy_AEB_FD2_33
 *   dummy_AEB_FD2_20 of type dummy_AEB_FD2_34
 *   dummy_AEB_FD2_21 of type dummy_AEB_FD2_35
 * SG_DCT_FD4: Record with elements
 *   CheckSum_DCT7 of type CheckSum_DCT7
 *   DCT_PrsBrk_Warn of type DCT_PrsBrk_Warn
 *   DCT_RaceModeSts of type DCT_RaceModeSts
 *   DCT_ShftNotAlwd_Warn of type DCT_ShftNotAlwd_Warn
 *   DCT_ShftRecom_M of type DCT_ShftRecom_M
 *   DrvAutoGearDisp of type DrvAutoGearDisp
 *   DrvFaiMsg of type DrvFaiMsg
 *   DrvGearDispSts of type DrvGearDispSts
 *   DrvModDisp_0x236 of type DrvModDisp_0x236
 *   DrvModDispSts of type DrvModDispSts
 *   DrvWarnMsg of type DrvWarnMsg
 *   dummy_DCT_FD4_8 of type dummy_DCT_FD4_8
 *   dummy_DCT_FD4_9 of type dummy_DCT_FD4_9
 *   dummy_DCT_FD4_10 of type dummy_DCT_FD4_10
 *   dummy_DCT_FD4_11 of type dummy_DCT_FD4_11
 *   RollingCounter_DCT7 of type RollingCounter_DCT7
 *   TRANS_OIL_TEMP_0x236 of type TRANS_OIL_TEMP_0x236
 *   TrsmStNID_0x236 of type TrsmStNID_0x236
 * SG_EPB1: Record with elements
 *   CheckSum_EPB1 of type CheckSum_EPB1
 *   EPBErrSts of type EPBErrSts
 *   EPBRedLmpSts of type EPBRedLmpSts
 *   EPBSts of type EPBSts
 *   EPBTextDisp of type EPBTextDisp
 *   PressBrakePedalPointOut of type PressBrakePedalPointOut
 *   RollingCounter_EPB1 of type RollingCounter_EPB1
 *   dummy_EPB1_0 of type dummy_EPB1_0
 *   dummy_EPB1_1 of type dummy_EPB1_1
 *   dummy_EPB1_2 of type dummy_EPB1_2
 *   dummy_EPB1_3 of type dummy_EPB1_3
 *   dummy_EPB1_4 of type dummy_EPB1_4
 *   dummy_EPB1_5 of type dummy_EPB1_5
 *   dummy_EPB1_6 of type dummy_EPB1_6
 *   dummy_EPB1_7 of type dummy_EPB1_7
 * SG_EPS1: Record with elements
 *   CheckSum_EPS1_0x168 of type CheckSum_EPS1_0x168
 *   dummy_EPS1_0 of type dummy_EPS1_8
 *   dummy_EPS1_1 of type dummy_EPS1_9
 *   dummy_EPS1_2 of type dummy_EPS1_10
 *   dummy_EPS1_3 of type dummy_EPS1_11
 *   dummy_EPS1_4 of type dummy_EPS1_12
 *   dummy_EPS1_5 of type dummy_EPS1_13
 *   dummy_EPS1_6 of type dummy_EPS1_14
 *   dummy_EPS1_7 of type dummy_EPS1_15
 *   EPS_FailSts_0x168 of type EPS_FailSts_0x168
 *   EPS_SteerMod_0x168 of type EPS_SteerMod_0x168
 *   RollingCounter_EPS1_0x168 of type RollingCounter_EPS1_0x168
 *   SteerCorrnResp_0x168 of type SteerCorrnResp_0x168
 *   SteerCorrnRmn_0x168 of type SteerCorrnRmn_0x168
 * SG_EPS1_FD1: Record with elements
 *   CheckSum_EPS1_0x147 of type CheckSum_EPS1_0x147
 *   dummy_EPS_FD1_0 of type dummy_EPS_FD1_24
 *   dummy_EPS_FD1_1 of type dummy_EPS_FD1_25
 *   dummy_EPS_FD1_2 of type dummy_EPS_FD1_26
 *   dummy_EPS_FD1_3 of type dummy_EPS_FD1_27
 *   dummy_EPS_FD1_4 of type dummy_EPS_FD1_28
 *   dummy_EPS_FD1_5 of type dummy_EPS_FD1_29
 *   dummy_EPS_FD1_6 of type dummy_EPS_FD1_30
 *   dummy_EPS_FD1_7 of type dummy_EPS_FD1_31
 *   EPS_FailSts_0x147 of type EPS_FailSts_0x147
 *   EPS_SteerMod_0x147 of type EPS_SteerMod_0x147
 *   RollingCounter_EPS1_0x147 of type RollingCounter_EPS1_0x147
 *   SteerCorrnResp_0x147 of type SteerCorrnResp_0x147
 *   SteerCorrnRmn_0x147 of type SteerCorrnRmn_0x147
 * SG_ESP1: Record with elements
 *   CheckSum_ESP1_0x149 of type CheckSum_ESP1_0x149
 *   dummy_ESP1_0 of type dummy_ESP1_13
 *   dummy_ESP1_1 of type dummy_ESP1_14
 *   dummy_ESP1_2 of type dummy_ESP1_15
 *   dummy_ESP1_3 of type dummy_ESP1_16
 *   dummy_ESP1_4 of type dummy_ESP1_17
 *   ESPActvInfoLmp_0x149 of type ESPActvInfoLmp_0x149
 *   ESPFailSts_0x149 of type ESPFailSts_0x149
 *   ESPFuncOffSts_0x149 of type ESPFuncOffSts_0x149
 *   RollingCounter_ESP1_0x149 of type RollingCounter_ESP1_0x149
 *   dummy_ESP1_5 of type dummy_ESP1_18
 *   dummy_ESP1_6 of type dummy_ESP1_19
 *   dummy_ESP1_7 of type dummy_ESP1_20
 *   TSM_Trailer_0x149 of type TSM_Trailer_0x149
 * SG_ESP1_ESP_FD2: Record with elements
 *   CheckSum_ESP1_0x137 of type CheckSum_ESP1_0x137
 *   dummy_ESP_FD2_16 of type dummy_ESP_FD2_34
 *   dummy_ESP_FD2_17 of type dummy_ESP_FD2_35
 *   dummy_ESP_FD2_18 of type dummy_ESP_FD2_36
 *   dummy_ESP_FD2_19 of type dummy_ESP_FD2_45
 *   dummy_ESP_FD2_20 of type dummy_ESP_FD2_46
 *   ESPActvInfoLmp_0x137 of type ESPActvInfoLmp_0x137
 *   ESPFailSts_0x137 of type ESPFailSts_0x137
 *   ESPFuncOffSts_0x137 of type ESPFuncOffSts_0x137
 *   RollingCounter_ESP1_0x137 of type RollingCounter_ESP1_0x137
 *   dummy_ESP_FD2_15 of type dummy_ESP_FD2_47
 *   dummy_ESP_FD2_21 of type dummy_ESP_FD2_48
 *   dummy_ESP_FD2_22 of type dummy_ESP_FD2_49
 *   TSM_Trailer_0x137 of type TSM_Trailer_0x137
 * SG_ESP2: Record with elements
 *   AVHErrSts_0x145 of type AVHErrSts_0x145
 *   AVHSts_0x145 of type AVHSts_0x145
 *   CDPActv_0x145 of type CDPActv_0x145
 *   CheckSum_ESP2_0x145 of type CheckSum_ESP2_0x145
 *   dummy_ESP2_0 of type dummy_ESP2_8
 *   dummy_ESP2_1 of type dummy_ESP2_9
 *   dummy_ESP2_2 of type dummy_ESP2_10
 *   dummy_ESP2_3 of type dummy_ESP2_11
 *   dummy_ESP2_4 of type dummy_ESP2_12
 *   dummy_ESP2_5 of type dummy_ESP2_13
 *   dummy_ESP2_6 of type dummy_ESP2_14
 *   HDCCtrl_0x145 of type HDCCtrl_0x145
 *   HDCFault_0x145 of type HDCFault_0x145
 *   RollingCounter_ESP2_0x145 of type RollingCounter_ESP2_0x145
 *   DrivingModDis_0x145 of type DrivingModDis_0x145
 *   DrivingModReq_ESP_0x145 of type DrivingModReq_ESP_0x145
 *   FourL_Warn_0x145 of type FourL_Warn_0x145
 *   Over_Spd_Warn_0x145 of type Over_Spd_Warn_0x145
 *   Shift_N_Warn_0x145 of type Shift_N_Warn_0x145
 *   TAB_Sts_0x145 of type TAB_Sts_0x145
 * SG_ESP2_ESP_FD2: Record with elements
 *   AVHErrSts_0x137 of type AVHErrSts_0x137
 *   AVHSts_0x137 of type AVHSts_0x137
 *   CDPActv_0x137 of type CDPActv_0x137
 *   CheckSum_ESP2_0x137 of type CheckSum_ESP2_0x137
 *   dummy_ESP_FD2_8 of type dummy_ESP_FD2_57
 *   dummy_ESP_FD2_9 of type dummy_ESP_FD2_58
 *   dummy_ESP_FD2_10 of type dummy_ESP_FD2_59
 *   dummy_ESP_FD2_11 of type dummy_ESP_FD2_60
 *   dummy_ESP_FD2_12 of type dummy_ESP_FD2_61
 *   dummy_ESP_FD2_13 of type dummy_ESP_FD2_62
 *   dummy_ESP_FD2_14 of type dummy_ESP_FD2_63
 *   HDCCtrl_0x137 of type HDCCtrl_0x137
 *   HDCFault_0x137 of type HDCFault_0x137
 *   RollingCounter_ESP2_0x137 of type RollingCounter_ESP2_0x137
 *   DrivingModDis_0x137 of type DrivingModDis_0x137
 *   DrivingModReq_ESP_0x137 of type DrivingModReq_ESP_0x137
 *   FourL_Warn_0x137 of type FourL_Warn_0x137
 *   Over_Spd_Warn_0x137 of type Over_Spd_Warn_0x137
 *   Shift_N_Warn_0x137 of type Shift_N_Warn_0x137
 *   TAB_Sts_0x137 of type TAB_Sts_0x137
 * SG_IFC6_IFC_FD2: Record with elements
 *   Checksum_IFC6 of type Checksum_IFC6
 *   dummy_IFC_FD2_17 of type dummy_IFC_FD2_17
 *   dummy_IFC_FD2_18 of type dummy_IFC_FD2_18
 *   dummy_IFC_FD2_19 of type dummy_IFC_FD2_19
 *   dummy_IFC_FD2_20 of type dummy_IFC_FD2_20
 *   IFC_NextLeLane_dy of type IFC_NextLeLane_dy
 *   IFC_NextRiLane_dy of type IFC_NextRiLane_dy
 *   RollingCounter_IFC6 of type RollingCounter_IFC6
 * SystemState_RecordType: Record with elements
 *   ClusterState of type Rte_DT_SystemState_RecordType_0
 *   IVIState of type Rte_DT_SystemState_RecordType_1
 *   HUDState of type Rte_DT_SystemState_RecordType_2
 *   ConsoleState of type Rte_DT_SystemState_RecordType_3
 *   KL15State of type Rte_DT_SystemState_RecordType_4
 *   s_PowerVoltage of type Rte_DT_SystemState_RecordType_5
 *   SP_State of type Rte_DT_SystemState_RecordType_6
 *   s_TempVoltage of type Rte_DT_SystemState_RecordType_7
 *
 *********************************************************************************************************************/


#define Common_Safety_START_SEC_CODE
#include "Common_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_SF_List_Deinit
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Deinit> of PortPrototype <Common_SF_List>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_SF_List_Deinit(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_SF_List_Deinit_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) Common_SF_List_Deinit(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_SF_List_Deinit
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_SF_List_Int
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Int> of PortPrototype <Common_SF_List>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_SF_List_Int(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_SF_List_Int_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) Common_SF_List_Int(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_SF_List_Int
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Safety_10msMainFunction
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(uint8 *data)
 *     Argument data: uint8* is of type CconfigKind_400Bytes
 *   Std_ReturnType Rte_Read_DCT9_DisplayGear(DisplayGear *data)
 *   Std_ReturnType Rte_Read_DCT9_DrvModDisp_0xc6(DrvModDisp_0xc6 *data)
 *   Std_ReturnType Rte_Read_DCT9_ShiftRecommend_M(ShiftRecommend_M *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Shift_not_allowed_Warn(TCU_Shift_not_allowed_Warn *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_P_faulty(TCU_Warn_P_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_drive_faulty(TCU_Warn_drive_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_driver_leaves_car(TCU_Warn_driver_leaves_car *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_gearbox_N(TCU_Warn_gearbox_N *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_gearbox_faulty(TCU_Warn_gearbox_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_high_temp(TCU_Warn_high_temp *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_limphome_D(TCU_Warn_limphome_D *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_limphome_P(TCU_Warn_limphome_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_prohibit_P(TCU_Warn_prohibit_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_release_button(TCU_Warn_release_button *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_shifter_faulty(TCU_Warn_shifter_faulty *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_step_P(TCU_Warn_step_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_Warn_vehicle_P(TCU_Warn_vehicle_P *data)
 *   Std_ReturnType Rte_Read_DCT9_TCU_gear_flashing(TCU_gear_flashing *data)
 *   Std_ReturnType Rte_Read_DCT9_TRANS_OIL_TEMP_0xc6(TRANS_OIL_TEMP_0xc6 *data)
 *   Std_ReturnType Rte_Read_DCT9_TrsmStNID_0xc6(TrsmStNID_0xc6 *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_FFogLmpSts_F_PBOX(FFogLmpSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_HiBeamSts_F_PBOX(HiBeamSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_HoodSts_F_PBOX(HoodSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LHeadLmpFailSts(LHeadLmpFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LHiBeamFailSts(LHiBeamFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LLasHdLmpDiagSig(LLasHdLmpDiagSig *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LLowBeamFailSts(LLowBeamFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_LasHdLmpSts_F_PBOX(LasHdLmpSts_F_PBOX *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RHeadLmpFailSts(RHeadLmpFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RHiBeamFailSts(RHiBeamFailSts *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RLasHdLmpDiagSig(RLasHdLmpDiagSig *data)
 *   Std_ReturnType Rte_Read_F_PBOX1_RLowBeamFailSts(RLowBeamFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_HiPosnBrkLmpFailSts(HiPosnBrkLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LBrkLmpFailSts(LBrkLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LRPosnLmpFailSts(LRPosnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LTurnLmpFailSts(LTurnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LTurnLmpSts_R_PBOX(LTurnLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_LicPlateLmpFailSts(LicPlateLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_ParkLmpSts_R_PBOX(ParkLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_PosnLmpOutpSts_R_PBOX(PosnLmpOutpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RBrkLmpFailSts(RBrkLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RFogLmpFailSts_R_PBOX(RFogLmpFailSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RFogLmpSts_R_PBOX(RFogLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RRPosnLmpFailSts(RRPosnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RTurnLmpFailSts(RTurnLmpFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RTurnLmpSts_R_PBOX(RTurnLmpSts_R_PBOX *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RWinHeatgFailSts(RWinHeatgFailSts *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RWinHeatgIconRlyCmd(RWinHeatgIconRlyCmd *data)
 *   Std_ReturnType Rte_Read_R_PBOX1_RvsLmpFailSts(RvsLmpFailSts *data)
 *   Std_ReturnType Rte_Read_SG_ABM1_SG_ABM1(SG_ABM1 *data)
 *   Std_ReturnType Rte_Read_SG_ABS3_SG_ABS3(SG_ABS3 *data)
 *   Std_ReturnType Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(SG_ABS3_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(SG_AEB2_AEB_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(SG_AEB3_AEB_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_DCT_FD4_SG_DCT_FD4(SG_DCT_FD4 *data)
 *   Std_ReturnType Rte_Read_SG_EPB1_SG_EPB1(SG_EPB1 *data)
 *   Std_ReturnType Rte_Read_SG_EPS1_SG_EPS1(SG_EPS1 *data)
 *   Std_ReturnType Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1(SG_EPS1_FD1 *data)
 *   Std_ReturnType Rte_Read_SG_ESP1_SG_ESP1(SG_ESP1 *data)
 *   Std_ReturnType Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(SG_ESP1_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ESP2_SG_ESP2(SG_ESP2 *data)
 *   Std_ReturnType Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(SG_ESP2_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(SG_IFC6_IFC_FD2 *data)
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_400bytes_VconfigKind_400Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_400Bytes
 *   Std_ReturnType Rte_Read_piSR_E2ESwitchChangeTrigger_Element(uint8 *data)
 *   boolean Rte_IsUpdated_DCT9_DisplayGear(void)
 *   boolean Rte_IsUpdated_DCT9_DrvModDisp_0xc6(void)
 *   boolean Rte_IsUpdated_DCT9_ShiftRecommend_M(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Shift_not_allowed_Warn(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_P_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_drive_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_driver_leaves_car(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_gearbox_N(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_gearbox_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_high_temp(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_limphome_D(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_limphome_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_prohibit_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_release_button(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_shifter_faulty(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_step_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_Warn_vehicle_P(void)
 *   boolean Rte_IsUpdated_DCT9_TCU_gear_flashing(void)
 *   boolean Rte_IsUpdated_DCT9_TRANS_OIL_TEMP_0xc6(void)
 *   boolean Rte_IsUpdated_DCT9_TrsmStNID_0xc6(void)
 *   boolean Rte_IsUpdated_F_PBOX1_FFogLmpSts_F_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_HiPosnBrkLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LBrkLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LRPosnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LTurnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LTurnLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_LicPlateLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_ParkLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_PosnLmpOutpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RBrkLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RFogLmpFailSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RFogLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RRPosnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RTurnLmpFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RTurnLmpSts_R_PBOX(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RWinHeatgFailSts(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RWinHeatgIconRlyCmd(void)
 *   boolean Rte_IsUpdated_R_PBOX1_RvsLmpFailSts(void)
 *   boolean Rte_IsUpdated_SG_ABM1_SG_ABM1(void)
 *   boolean Rte_IsUpdated_SG_ABS3_SG_ABS3(void)
 *   boolean Rte_IsUpdated_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(void)
 *   boolean Rte_IsUpdated_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(void)
 *   boolean Rte_IsUpdated_SG_DCT_FD4_SG_DCT_FD4(void)
 *   boolean Rte_IsUpdated_SG_EPB1_SG_EPB1(void)
 *   boolean Rte_IsUpdated_SG_EPS1_SG_EPS1(void)
 *   boolean Rte_IsUpdated_SG_EPS1_FD1_SG_EPS1_FD1(void)
 *   boolean Rte_IsUpdated_SG_ESP1_SG_ESP1(void)
 *   boolean Rte_IsUpdated_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_ESP2_SG_ESP2(void)
 *   boolean Rte_IsUpdated_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   uint8 *Rte_IRead_Common_Safety_10msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes(void)
 *     Returnvalue: uint8* is of type VconfigKind_157Bytes
 *   SystemState_RecordType *Rte_IRead_Common_Safety_10msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_CheckSum_IP2(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_ABMWarnLmpFailrSts(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_ACCErr(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_BattChrgLmpSts(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_DrvSeatBeltWarnLmpFailSts(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_EngOilPressLowLmpSts(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_Err(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_FuelLvlInfo(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_FuelLvlLowLmpSts(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_PassSeatBeltWarnLmpFailSts(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_VINcompr(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_VehSpdUnit(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_VehTotDistance(uint32 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_IP_VehTotDistanceValid(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_RollingCounter_IP2(uint8 data)
 *   Std_ReturnType Rte_Write_SafetyCanOutputViaNormal_dummy_HUT_IP2_0(uint8 data)
 *   Std_ReturnType Rte_Write_Sd_CanOutPut_IP_EBDFailSts_IP_EBDFailSts(uint8 data)
 *   Std_ReturnType Rte_Write_tiSR_SWC_TT_SelfCheck_Element(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IPC_Send_IPC_Send(uint8 Id_u8, uint8 *data_s, uint16 len_u16, boolean Imm_bool)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IPC_Send_Std_ReturnType
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetPin(uint8 Id, boolean *Pin)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_Interface_GetVoltage(uint8 Id, uint32 *Voltage)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAb_Interface_E_NOT_OK
 *   Std_ReturnType Rte_Call_VConfig_GetKindConfig_Operation_VConfig_GetKindConfig(uint8 kindId, uint8 *kindConfig)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetKindConfig_Std_ReturnType
 *   Std_ReturnType Rte_Call_VConfig_GetUpdateTick_OperationVConfig_GetUpdateTick(TimeInMicrosecondsType *updateTick)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_VConfig_GetUpdateTick_Std_ReturnType
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Os_Service_GetCounterValue(TimeInMicrosecondsType *Value)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID
 *   Std_ReturnType Rte_Call_Os_Service_GetElapsedValue(TimeInMicrosecondsType *Value, TimeInMicrosecondsType *ElapsedValue)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Os_Service_E_OK, RTE_E_Os_Service_E_OS_ID, RTE_E_Os_Service_E_OS_VALUE
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_TT_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Rx Status:
 *   ----------
 *   Std_ReturnType Rte_IStatus_Common_Safety_10msMainFunction_Vconfig_KindBuffers_VconfigKind_157Bytes(void)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_Safety(void)
 *   void Rte_Exit_ExclusiveArea_Safety(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_10msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) Common_Safety_10msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_10msMainFunction
 *********************************************************************************************************************/
  STT_Function_Safety_TimeTask();
  (void)Rte_Call_WdgM_AliveSupervision_TT_CheckpointReached(0);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Safety_50msMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(SG_ESP1_ESP_FD2 *data)
 *   boolean Rte_IsUpdated_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(void)
 *
 *   Implicit S/R API:
 *   -----------------
 *   SystemState_RecordType *Rte_IRead_Common_Safety_50msMainFunction_rpSR_SWCSafety_Power_Out_SystemStateOut(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IPC_Send_IPC_Send(uint8 Id_u8, uint8 *data_s, uint16 len_u16, boolean Imm_bool)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IPC_Send_Std_ReturnType
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_WdgM_AliveSupervision_Gear_CheckpointReached(WdgM_CheckpointIdType CPID)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_Safety(void)
 *   void Rte_Exit_ExclusiveArea_Safety(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_50msMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) Common_Safety_50msMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_50msMainFunction
 *********************************************************************************************************************/
	GearMdl_Gear_app_tsk();
  (void)Rte_Call_WdgM_AliveSupervision_Gear_CheckpointReached(0);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Safety_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) Common_Safety_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_Init
 *********************************************************************************************************************/
	GearMdl_Gear_cold_init();
  STT_Function_Safety_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Safety_Nomal2Standby_Callbcak
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Nomal2StandbyCallback> of PortPrototype <rpCS_Common_Safety_PowerTransfer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_Safety_Nomal2Standby_Callbcak(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_Nomal2Standby_Callbcak_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) Common_Safety_Nomal2Standby_Callbcak(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_Nomal2Standby_Callbcak
 *********************************************************************************************************************/
  STT_Function_Safety_PreOff_Logic();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Common_Safety_Standby2Nomal_Callbcak
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Standby2NomalCallback> of PortPrototype <rpCS_Common_Safety_PowerTransfer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Common_Safety_Standby2Nomal_Callbcak(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_Standby2Nomal_Callbcak_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) Common_Safety_Standby2Nomal_Callbcak(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Common_Safety_Standby2Nomal_Callbcak
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SafetyMode_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <ppSR_SafetyMode>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SafetyMode_Operation(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SafetyMode_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) SafetyMode_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SafetyMode_Operation
 *********************************************************************************************************************/
  STT_TTErrorCallback(arg);
  RTE_API_GearErrorCallback(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCSafety_ReceiveSafetyGearCRC_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCSafety_ReceiveSafetyGearCRC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCSafety_ReceiveSafetyGearCRC_Callback(uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCSafety_ReceiveSafetyGearCRC_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) svCS_SWCSafety_ReceiveSafetyGearCRC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCSafety_ReceiveSafetyGearCRC_Callback
 *********************************************************************************************************************/
	IPC_API_ReceiveSafetyGearCRCCallback(Data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCSafety_ReceiveSafetyTTCRC_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Callback> of PortPrototype <svCS_SWCSafety_ReceiveSafetyTTCRC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCSafety_ReceiveSafetyTTCRC_Callback(uint8 *Data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCSafety_ReceiveSafetyTTCRC_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) svCS_SWCSafety_ReceiveSafetyTTCRC_Callback(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCSafety_ReceiveSafetyTTCRC_Callback
 *********************************************************************************************************************/

	IPC_API_ReceiveSafetyTTCRCCallback(Data);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: svCS_SWCSafety_TTCallback_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <svCS_SWCSafety_TTCallback>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void svCS_SWCSafety_TTCallback_Operation(uint8 *arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCSafety_TTCallback_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Common_Safety_CODE) svCS_SWCSafety_TTCallback_Operation(P2VAR(uint8, AUTOMATIC, RTE_COMMON_SAFETY_APPL_VAR) arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: svCS_SWCSafety_TTCallback_Operation
 *********************************************************************************************************************/
  TT_Api_Get_TTSelfCheck_Sts(arg);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Common_Safety_STOP_SEC_CODE
#include "Common_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
/***  Start of saved code (symbol: runnable implementation:Gear_MainFunction)  ******************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:TT_MainFunction_doc)  *********************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:TT_MainFunction)  ********************************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:Gear_MainFunction_doc)  *******************************/


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
