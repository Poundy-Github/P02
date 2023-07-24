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
 *           Config:  D:/01Project/1-6-1/Davinci/Gen/HUT_V3_5.dpa
 *        SW-C Type:  Common_Safety
 *  Generation Time:  2021-01-06 17:47:13
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
 * HiBeamSts_F_Pbox
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * RFogLmpSts_R_Pbox
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Tgtgear_Down
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Tgtgear_Up
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
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
 * ABAActv_0x137: Boolean
 * ABAActv_0x145: Boolean
 * ABAavailable_0x137: Boolean
 * ABAavailable_0x145: Boolean
 * ABPActv_0x137: Boolean
 * ABPActv_0x145: Boolean
 * ABPAvailable_0x137: Boolean
 * ABPAvailable_0x145: Boolean
 * ABSActv_0x137: Boolean
 * ABSActv_0x265: Boolean
 * ABSFailSts_0x137: Boolean
 * ABSFailSts_0x265: Boolean
 * AEBAvailable_0x137: Boolean
 * AEBAvailable_0x145: Boolean
 * AEBBAActv_0x137: Boolean
 * AEBBAActv_0x145: Boolean
 * AEBIBActv_0x137: Boolean
 * AEBIBActv_0x145: Boolean
 * AEB_JA_Resp_3: Boolean
 * AEB_PedResp_3: Boolean
 * AEB_PedTrig_2: Boolean
 * AEB_VehResp_3: Boolean
 * AEB_VehTrig_2: Boolean
 * AWBActv_0x137: Boolean
 * AWBActv_0x145: Boolean
 * AWBAvailable_0x137: Boolean
 * AWBAvailable_0x145: Boolean
 * AirbFailLmpCmd_4: Boolean
 * BMS_PackCurr: Integer in interval [0...8191]
 * BMS_PackVolt: Integer in interval [0...255]
 * BMS_PowerDownCmplt: Boolean
 * BTCActv_0x137: Boolean
 * BTCActv_0x149: Boolean
 * BrkDskOvrheatd_0x137: Boolean
 * BrkDskOvrheatd_0x145: Boolean
 * CDDActv_0x137: Boolean
 * CDDActv_0x145: Boolean
 * CDDAvailable_0x137: Boolean
 * CDDAvailable_0x145: Boolean
 * CDPActv_0x137: Boolean
 * CDPActv_0x145: Boolean
 * CarWashMode_Sts: Boolean
 * DrvSBR_4: Boolean
 * EBDActv_0x137: Boolean
 * EBDActv_0x265: Boolean
 * EBDFailSts_0x137: Boolean
 * EBDFailSts_0x265: Boolean
 * EPS_TrqSnsrSts_0x147: Boolean
 * EPS_TrqSnsrSts_0x168: Boolean
 * ESPActvInfoLmp_0x137: Boolean
 * ESPActvInfoLmp_0x149: Boolean
 * ESPBrkLmpCtrl_0x137: Boolean
 * ESPBrkLmpCtrl_0x149: Boolean
 * ESPFailSts_0x137: Boolean
 * ESPFailSts_0x149: Boolean
 * ESPFuncOffSts_0x137: Boolean
 * ESPFuncOffSts_0x149: Boolean
 * ESP_MasterCylBrkPressVld_0x137: Boolean
 * ESP_MasterCylBrkPressVld_0x149: Boolean
 * ESP_MasterCylBrkPress_0x137_1: Integer in interval [0...65535]
 * ESP_MasterCylBrkPress_0x149_1: Integer in interval [0...65535]
 * HCU_12VSysErrLmpSts: Boolean
 * HCU_12VSysErr_1: Boolean
 * HCU_12VSysErr_2: Boolean
 * HCU_ConnectChrgLine_Indcn: Boolean
 * HCU_HybSysErr_1: Boolean
 * HCU_HybSysErr_2: Boolean
 * HCU_HybSysErr_3: Boolean
 * HCU_HybSysErr_4: Boolean
 * HCU_HybSysErr_5: Boolean
 * HCU_HybSysErr_6: Boolean
 * HCU_HybSysErr_7: Boolean
 * HCU_InhbChrgInfo: Boolean
 * HCU_OPDLmpSts: Boolean
 * HCU_OilTankCoverSts: Boolean
 * HCU_PowerRedWarnLmpCmd: Boolean
 * HCU_RdyLmpSts: Boolean
 * HCU_RemoveChrgLine_Indcn: Boolean
 * HCU_SOCLow_Indcn: Boolean
 * HCU_Shift_P_Indcn: Boolean
 * HCU_WadeModeSetSts: Boolean
 * IFC_NextLeLane_dy: Integer in interval [0...65535]
 * IFC_NextRiLane_dy: Integer in interval [0...65535]
 * MSRActv_0x137: Boolean
 * MSRActv_0x149: Boolean
 * NoBrkForce_0x137: Boolean
 * NoBrkForce_0x145: Boolean
 * OPDParkWarnReq: Boolean
 * PTCActv_0x137: Boolean
 * PTCActv_0x149: Boolean
 * PassSBR_4: Boolean
 * PressBrakePedalPointOut: Boolean
 * Rte_DT_SystemState_RecordType_5_1: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN
 * Rte_DT_SystemState_RecordType_7_1: Integer in interval [-32768...32767]
 * SecRowLSBR_4: Boolean
 * SecRowMidSBR_4: Boolean
 * SecRowRSBR_4: Boolean
 * TAB_Available_2: Boolean
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * VDCActv_0x137: Boolean
 * VDCActv_0x149: Boolean
 * VehOdoInfoSts_0x137: Boolean
 * VehOdoInfoSts_0x265: Boolean
 * VehSpdVld_0x137: Boolean
 * VehSpdVld_0x265: Boolean
 * VehSpd_0x137_1: Integer in interval [0...65535]
 * VehSpd_0x265_2: Integer in interval [0...65535]
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
 * dummy_BMS4_0: Integer in interval [0...255]
 * dummy_BMS4_1: Integer in interval [0...255]
 * dummy_BMS4_2: Integer in interval [0...255]
 * dummy_BMS4_3: Integer in interval [0...255]
 * dummy_BMS4_4: Integer in interval [0...255]
 * dummy_DCT7_0: Integer in interval [0...255]
 * dummy_DCT7_1: Integer in interval [0...255]
 * dummy_DCT7_2: Integer in interval [0...255]
 * dummy_DCT7_3: Boolean
 * dummy_DCT7_4: Integer in interval [0...255]
 * dummy_DCT7_5: Integer in interval [0...255]
 * dummy_DHT_FD1_10: Integer in interval [0...255]
 * dummy_DHT_FD1_11: Integer in interval [0...255]
 * dummy_DHT_FD1_12: Integer in interval [0...255]
 * dummy_DHT_FD1_13: Integer in interval [0...255]
 * dummy_DHT_FD1_8: Integer in interval [0...255]
 * dummy_DHT_FD1_9: Integer in interval [0...255]
 * dummy_EPB1_0: Integer in interval [0...255]
 * dummy_EPB1_1: Integer in interval [0...255]
 * dummy_EPB1_2: Boolean
 * dummy_EPB1_3: Integer in interval [0...255]
 * dummy_EPB1_4: Integer in interval [0...255]
 * dummy_EPB1_5: Integer in interval [0...255]
 * dummy_EPB1_6: Integer in interval [0...255]
 * dummy_EPB1_7: Integer in interval [0...255]
 * dummy_EPS1_0: Boolean
 * dummy_EPS1_1: Integer in interval [0...255]
 * dummy_EPS1_2: Integer in interval [0...255]
 * dummy_EPS1_3: Integer in interval [0...255]
 * dummy_EPS1_4: Integer in interval [0...255]
 * dummy_EPS1_5: Integer in interval [0...255]
 * dummy_EPS1_6: Integer in interval [0...255]
 * dummy_EPS1_7: Integer in interval [0...255]
 * dummy_EPS_FD1_10: Integer in interval [0...255]
 * dummy_EPS_FD1_11: Integer in interval [0...255]
 * dummy_EPS_FD1_12: Integer in interval [0...255]
 * dummy_EPS_FD1_13: Integer in interval [0...255]
 * dummy_EPS_FD1_14: Integer in interval [0...255]
 * dummy_EPS_FD1_15: Integer in interval [0...255]
 * dummy_EPS_FD1_8: Boolean
 * dummy_EPS_FD1_9: Integer in interval [0...255]
 * dummy_ESP1_0: Integer in interval [0...255]
 * dummy_ESP1_1: Integer in interval [0...255]
 * dummy_ESP1_2: Integer in interval [0...255]
 * dummy_ESP1_3: Integer in interval [0...255]
 * dummy_ESP1_4: Integer in interval [0...255]
 * dummy_ESP2_0: Boolean
 * dummy_ESP2_1: Integer in interval [0...255]
 * dummy_ESP2_2: Boolean
 * dummy_ESP2_3: Boolean
 * dummy_ESP2_4: Boolean
 * dummy_ESP2_5: Integer in interval [0...255]
 * dummy_ESP2_6: Boolean
 * dummy_ESP2_7: Integer in interval [0...255]
 * dummy_ESP_FD2_21: Integer in interval [0...255]
 * dummy_ESP_FD2_22: Integer in interval [0...255]
 * dummy_ESP_FD2_23: Integer in interval [0...255]
 * dummy_ESP_FD2_24: Integer in interval [0...255]
 * dummy_ESP_FD2_25: Integer in interval [0...255]
 * dummy_ESP_FD2_26: Boolean
 * dummy_ESP_FD2_27: Integer in interval [0...255]
 * dummy_ESP_FD2_28: Boolean
 * dummy_ESP_FD2_29: Boolean
 * dummy_ESP_FD2_30: Integer in interval [0...255]
 * dummy_ESP_FD2_31: Integer in interval [0...255]
 * dummy_ESP_FD2_32: Integer in interval [0...255]
 * dummy_ESP_FD2_33: Integer in interval [0...255]
 * dummy_ESP_FD2_37: Integer in interval [0...255]
 * dummy_ESP_FD2_38: Integer in interval [0...255]
 * dummy_ESP_FD2_39: Integer in interval [0...255]
 * dummy_ESP_FD2_40: Integer in interval [0...255]
 * dummy_HCU_HP5_0: Integer in interval [0...255]
 * dummy_HCU_HP5_1: Integer in interval [0...255]
 * dummy_HCU_HP5_2: Integer in interval [0...255]
 * dummy_HCU_HP5_3: Integer in interval [0...255]
 * dummy_HCU_HP5_4: Integer in interval [0...255]
 * dummy_HCU_PT4_0: Integer in interval [0...255]
 * dummy_HCU_PT4_1: Integer in interval [0...255]
 * dummy_HCU_PT4_2: Boolean
 * dummy_HCU_PT4_3: Integer in interval [0...255]
 * dummy_HCU_PT4_4: Integer in interval [0...255]
 * dummy_HCU_PT4_5: Integer in interval [0...255]
 * dummy_HCU_PT4_6: Integer in interval [0...255]
 * dummy_HCU_PT4_7: Boolean
 * dummy_HCU_PT7_0: Integer in interval [0...255]
 * dummy_HCU_PT7_1: Integer in interval [0...255]
 * dummy_HCU_PT7_2: Boolean
 * dummy_HCU_PT7_3: Integer in interval [0...255]
 * dummy_HCU_PT7_4: Integer in interval [0...255]
 * dummy_HCU_PT7_5: Boolean
 * dummy_HCU_PT7_6: Integer in interval [0...255]
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
 * AVHSts_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Standby (1U)
 *   Cx2_active (2U)
 *   Cx3_Reserved (3U)
 * BMS_BattPoweErr: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Error (0U)
 *   Cx1_TM_power_unavailable (1U)
 *   Cx2_P2M_power_unavailable (2U)
 *   Cx3_OBC_power_unavailable (3U)
 * BMS_ErrCategory: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_Error (0U)
 *   Cx1_Warning (1U)
 *   Cx2_Derating (2U)
 *   Cx3_Instrument_Display_Yellow_ (3U)
 *   Cx4_Range_Limited_Yellow_ (4U)
 *   Cx5_Pre_charge_Locked_Red_ (5U)
 *   Cx6_Delayed_Open_Red_ (6U)
 *   Cx7_Emergency_Open_Red_ (7U)
 * CarWashMode_StsDisp: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_Display (0U)
 *   Cx1_Speed_too_high_TransportCar_Wash_Mode_is_not_available (1U)
 *   Cx2_12V_battery_SOC_too_low_TransportCar_Wash_Mode_is_not_available (2U)
 *   Cx3_Reserved (3U)
 *   Cx7_Reserved (7U)
 * CheckSum_ABM1_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ABS3_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_ABS3_0x265: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_BMS4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * CheckSum_DCT7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * CheckSum_DHT1: Enumeration of integer in interval [0...255] with enumerators
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
 * CheckSum_HCU_PT7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * Checksum_AEB2_3: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_AEB3_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_value (0U)
 *   CxFF_Valid_value (255U)
 * Checksum_HCU_HP5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
 * Checksum_HCU_PT4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Valid_values (0U)
 *   CxFF_Valid_values (255U)
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
 * DrivingModDis_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Standard (0U)
 *   Cx01_Sport (1U)
 *   Cx02_Snow (2U)
 *   Cx03_Mud (3U)
 *   Cx04_Sand (4U)
 *   Cx05_4L_reserved_ (5U)
 *   Cx06_Economic (6U)
 *   Cx07_Mode_Unkown (7U)
 *   Cx08_Reserved (8U)
 *   Cx09_Sport_ (9U)
 *   Cx0A_Off_road (10U)
 *   Cx0B_Standard_2H_reserved_ (11U)
 *   Cx0C_Reserved (12U)
 *   Cx0D_Standard_4H_reserved_ (13U)
 *   Cx0E_Failed (14U)
 *   Cx0F_Invalid_Value (15U)
 *   Cx10_Snow_4H_reserved_ (16U)
 *   Cx11_Normal_4L_reserved_ (17U)
 *   Cx12_Rock_4L_reserved_ (18U)
 *   Cx13_Pothle_4L_reserved_ (19U)
 *   Cx14_MudSand_4L_reserved_ (20U)
 *   Cx15_Mountain_4L_reserved_ (21U)
 *   Cx16_reserved (22U)
 *   Cx1F_reserved (31U)
 * DrivingModReq_ESP_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_No_Terrain_Control (0U)
 *   Cx01_Standard (1U)
 *   Cx02_Sport (2U)
 *   Cx03_Snow_Nex (3U)
 *   Cx04_Reserved (4U)
 *   Cx05_Deep_Mud (5U)
 *   Cx06_Reserved (6U)
 *   Cx07_Soft_sand (7U)
 *   Cx08_Reserved (8U)
 *   Cx09_4L_reserved_ (9U)
 *   Cx0A_Economic (10U)
 *   Cx0B_Reserved (11U)
 *   Cx0C_Snow_TOD_reserved_ (12U)
 *   Cx0D_Off_road (13U)
 *   Cx0E_Sport_reserved_ (14U)
 *   Cx0F_nvalid_Value (15U)
 *   Cx10_Standard_2H_reserved_ (16U)
 *   Cx11_Reserved (17U)
 *   Cx12_Standard_4H_reserved_ (18U)
 *   Cx13_Snow_4H_reserved_ (19U)
 *   Cx14_Normal_4L_reserved_ (20U)
 *   Cx15_Rock_4L_reserved_ (21U)
 *   Cx16_Pothole_4L_reserved_ (22U)
 *   Cx17_MudSand_4L_reserved_ (23U)
 *   Cx18_Mountain_4L_reserved_ (24U)
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
 *   Cx8_Reserved (8U)
 *   CxF_Reserved (15U)
 * DrvFaiMsg_0x201: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_No_Message (0U)
 *   Cx1_Transmission_Malfunction (1U)
 *   Cx2_Transmission_P_engagement_fault (2U)
 *   Cx3_Transmission_P_disengagement_fault (3U)
 *   Cx4_Please_press_the_brake_pedal_untill_the_P_gear_reference_is_completed (4U)
 *   Cx5_Reference_is_not_completed_please_shift_gears_after_reference_is_completed (5U)
 *   Cx6_P_gear_reference_completed_please_released_the_brake_pedal (6U)
 *   Cx7_Reserved (7U)
 *   CxE_Reserved (14U)
 *   CxF_Transmission_limit_function (15U)
 * DrvFaiMsg_0x235: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_No_Message (0U)
 *   Cx1_Transmission_Malfunction (1U)
 *   Cx2_Transmission_P_engagement_fault (2U)
 *   Cx3_Transmission_P_disengagement_fault (3U)
 *   Cx4_Authentication_failure (4U)
 *   Cx5_Reserved (5U)
 *   CxE_Reserved (14U)
 *   CxF_transmission_limit_function (15U)
 * DrvGearDisp: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Neutral (0U)
 *   Cx1_E_Gear (1U)
 *   Cx2_L_Gear (2U)
 *   Cx3_M_Gear (3U)
 *   Cx4_H_Gear (4U)
 *   Cx5_S_Gear (5U)
 *   Cx6_X_Gear (6U)
 *   Cx7_Reserved (7U)
 * DrvGearDispSts_0x201: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Blank_No_display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_display_ (3U)
 * DrvGearDispSts_0x235: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Blank_No_display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_display_ (3U)
 * DrvModDispSts_0x201: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_BlankNo_Display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_Display_ (3U)
 * DrvModDispSts_0x235: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_BlankNo_Display (0U)
 *   Cx1_On (1U)
 *   Cx2_Flashing (2U)
 *   Cx3_Reserved_treat_as_BlankNo_Display_ (3U)
 * DrvModDisp_0x201: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_P (0U)
 *   Cx1_R (1U)
 *   Cx2_N (2U)
 *   Cx3_D (3U)
 *   Cx4_M (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * DrvModDisp_0x235: Enumeration of integer in interval [0...255] with enumerators
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
 * HCU_ACStsReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Disable (0U)
 *   Cx1_Derating (1U)
 *   Cx2_Normal (2U)
 *   Cx3_Invalid (3U)
 * HCU_BattPowerRedWarn: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Battery_temperature_is_low_power_may_decrease (1U)
 *   Cx2_Battery_temperature_is_high_power_may_decrease (2U)
 *   Cx3_Reserved (3U)
 * HCU_EgyRecFB: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Standard (0U)
 *   Cx1_Enhanced (1U)
 *   Cx2_Low (2U)
 *   Cx3_Not_Available (3U)
 * HCU_EnerSavePowerMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_action (0U)
 *   Cx1_Close_blower (1U)
 *   Cx2_Close_seat_heat (2U)
 *   Cx3_Close_both_blower_and_seat_heat (3U)
 * HCU_EnrgFlowInd: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_Mode_0_Vehicle_standstill (0U)
 *   Cx01_Engine_running_and_BSG_is_a_conventional_generator (1U)
 *   Cx02_Engine_Auto_stopped (2U)
 *   Cx03_Boost (3U)
 *   Cx04_Energy_Recovery (4U)
 *   Cx05_E_Creep (5U)
 *   Cx06_pure_engine_drive (6U)
 *   Cx07_Reserved (7U)
 *   Cx1F_Reserved (31U)
 * HCU_EnrgFlowInd_DHT: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_Mode_1_Vehicle_standstill_engine_not_start (0U)
 *   Cx01_mode_2_Vehicle_standstill_engine_start (1U)
 *   Cx02_mode_3_engine_idling_charging (2U)
 *   Cx03_mode_4_Pure_electricity_drive_T_Motor_ (3U)
 *   Cx04_mode_5_Engine_direct_drive_battery_not_working_ (4U)
 *   Cx05_mode_6_Series_drive_battery_not_working_T_Motor_ (5U)
 *   Cx06_mode_7_Engine_direct_drive_battery_discharging_ (6U)
 *   Cx07_mode_8_Series_drive_battery_discharging_ (7U)
 *   Cx08_mode_9_Engine_direct_drive_battery_charging_ (8U)
 *   Cx09_mode_10_Series_drive_battery_charging_ (9U)
 *   Cx0A_mode_11_Energy_recovery_T_Motor_ (10U)
 *   Cx0B_mode_12_T_Motor_Energy_recovery_T_Motor_Battery_charging (11U)
 *   Cx0C_mode_13_Plug_in_warming (12U)
 *   Cx0D_mode_14_Plug_in_charging_warming (13U)
 *   Cx0E_mode_15AC_charging (14U)
 *   Cx0F_mode_16_DC_charging (15U)
 *   Cx10_Reserved (16U)
 *   Cx3F_Reserved (63U)
 * HCU_HybSysErrLmpSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_Yellow_Light_ON (1U)
 *   Cx2_Red_Light_ON (2U)
 *   Cx3_Reserved (3U)
 * HCU_ModSwtFail: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_EV_not_available_due_to_low_battery_charge (1U)
 *   Cx2_EV_not_available_due_to_temporary_hybrid_system_limitations (2U)
 *   Cx3_SAVE_not_available_due_to_temporary_hybrid_system_limitations (3U)
 *   Cx4_AWD_not_available_due_to_temporary_hybrid_system_limitations (4U)
 *   Cx5_SPORT_not_available_due_to_temporary_hybrid_system_limitations (5U)
 *   Cx6_Manual_gear_change_drive_mode_goes_SPORT (6U)
 *   Cx7_Manual_gear_change_only_SPORT_available (7U)
 *   Cx8_EV_mode_available (8U)
 *   Cx9_Snow_not_available_due_to_temporary_hybrid_system_limitations (9U)
 *   CxA_Muddy_not_available_due_to_temporary_hybrid_system_limitations (10U)
 *   CxB_Sand_not_available_due_to_temporary_hybrid_system_limitations (11U)
 *   CxC_SPORT_Plus_Mode_not_available_due_to_temporary_hybrid_system_limitations (12U)
 *   CxD_ECO_Mode_not_available (13U)
 *   CxE_EV_not_available_due_to_engine_needs_to_start (14U)
 *   CxF_Reserved (15U)
 * HCU_OPDFail: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Normal_Default_ (0U)
 *   Cx1_OPD_function_not_available_due_to_temporary_hybrid_system_limitations (1U)
 *   Cx2_OPD_function_not_available_due_to_Snow_mode (2U)
 *   Cx3_Reserved (3U)
 * HCU_OPDSts: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Not_active (0U)
 *   Cx1_Active (1U)
 *   Cx2_Abnormal_quit (2U)
 *   Cx3_Cannot_active (3U)
 *   Cx4_Have_no_OPD_function (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * HCU_PrsBrkWarn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Press_brake_and_Unlock_button_to_shift (1U)
 *   Cx2_Press_Unlock_button_to_shift (2U)
 *   Cx3_Press_brake_to_shift (3U)
 * HCU_RefuReq: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_request (0U)
 *   Cx1_Refueling_request (1U)
 *   Cx2_When_vehicle_is_ready_inhibit_refuel (2U)
 *   Cx3_When_engine_is_run_inhibit_refuel (3U)
 *   Cx4_When_charger_is_connected_inhibit_refuel (4U)
 *   Cx5_Reserved (5U)
 *   Cx7_Reserved (7U)
 * HCU_ShftNotAlwd_Warn: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_warning (0U)
 *   Cx1_Vehicle_speed_too_high_shift_not_allowed (1U)
 *   Cx2_Engage_P_not_allowed_due_to_high_vehicle_speed (2U)
 *   Cx3_reserved (3U)
 * HDCCtrl_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_OFF (0U)
 *   Cx1_On_active_braking (1U)
 *   Cx2_On_not_active_braking (2U)
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
 * HiBeamSts_F_Pbox: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
 * PassSBR_Visual_4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Lamp_off (0U)
 *   Cx1_Lamp_on (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Lamp_blink_sound_remind (3U)
 * RFogLmpSts_R_Pbox: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_On (1U)
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
 * RollingCounter_BMS4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_DCT7: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_DHT1: Enumeration of integer in interval [0...255] with enumerators
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
 * RollingCounter_HCU_HP5: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_HCU_PT4: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Valid_value (0U)
 *   CxE_Valid_value (14U)
 *   CxF_Invalid_value (15U)
 * RollingCounter_HCU_PT7: Enumeration of integer in interval [0...255] with enumerators
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
 * TAB_Sts_2: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Function_OFF (0U)
 *   Cx1_Standby (1U)
 *   Cx2_Active (2U)
 *   Cx3_Failure (3U)
 * TCU_ClutchHotWarning: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Normal (0U)
 *   Cx1_Warnining (1U)
 *   Cx2_Degrading (2U)
 *   Cx3_ClutchOpen (3U)
 * TCU_ErrCategory: Enumeration of integer in interval [0...255] with enumerators
 *   Cx01_Warning (1U)
 *   Cx02_Partial_function_external (2U)
 *   Cx04_Partial_function_internal (4U)
 *   Cx08_Disable_NP (8U)
 *   Cx10_Diable (16U)
 *   Cx80_EOL_not_finish (128U)
 * Tgtgear_Down: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Gear_shiftdown_display_off (0U)
 *   Cx1_Gear_shiftdown_display_on (1U)
 * Tgtgear_Up: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Gear_shiftup_display_off (0U)
 *   Cx1_Gear_shiftup_display_on (1U)
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
 * VehStandstill_0x137: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_standstill (0U)
 *   Cx1_Standstill (1U)
 *   Cx2_InValid_values_short_unavailability_max_3s_ (2U)
 *   Cx3_Reserved (3U)
 * VehStandstill_0x145: Enumeration of integer in interval [0...255] with enumerators
 *   Cx0_Not_standstill (0U)
 *   Cx1_Standstill (1U)
 *   Cx2_Invalid_short_unavailability_maX_3s_ (2U)
 *   Cx3_Reserved (3U)
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
 *   EBDActv_0x265 of type EBDActv_0x265
 *   EBDFailSts_0x265 of type EBDFailSts_0x265
 *   RollingCounter_ABS3_0x265 of type RollingCounter_ABS3_0x265
 *   VehOdoInfo_0x265 of type VehOdoInfo_0x265
 *   VehOdoInfoSts_0x265 of type VehOdoInfoSts_0x265
 *   VehSpd_0x265 of type VehSpd_0x265_2
 *   VehSpdVld_0x265 of type VehSpdVld_0x265
 * SG_ABS3_ESP_FD2: Record with elements
 *   ABSActv_0x137 of type ABSActv_0x137
 *   ABSFailSts_0x137 of type ABSFailSts_0x137
 *   CheckSum_ABS3_0x137 of type CheckSum_ABS3_0x137
 *   dummy_ESP_FD2_37 of type dummy_ESP_FD2_37
 *   dummy_ESP_FD2_38 of type dummy_ESP_FD2_38
 *   dummy_ESP_FD2_39 of type dummy_ESP_FD2_39
 *   dummy_ESP_FD2_40 of type dummy_ESP_FD2_40
 *   EBDActv_0x137 of type EBDActv_0x137
 *   EBDFailSts_0x137 of type EBDFailSts_0x137
 *   RollingCounter_ABS3_0x137 of type RollingCounter_ABS3_0x137
 *   VehOdoInfo_0x137 of type VehOdoInfo_0x137
 *   VehOdoInfoSts_0x137 of type VehOdoInfoSts_0x137
 *   VehSpd_0x137 of type VehSpd_0x137_1
 *   VehSpdVld_0x137 of type VehSpdVld_0x137
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
 * SG_BMS4: Record with elements
 *   BMS_BattPoweErr of type BMS_BattPoweErr
 *   BMS_ErrCategory of type BMS_ErrCategory
 *   BMS_PackCurr of type BMS_PackCurr
 *   BMS_PackVolt of type BMS_PackVolt
 *   BMS_PowerDownCmplt of type BMS_PowerDownCmplt
 *   CheckSum_BMS4 of type CheckSum_BMS4
 *   dummy_BMS4_0 of type dummy_BMS4_0
 *   dummy_BMS4_1 of type dummy_BMS4_1
 *   dummy_BMS4_2 of type dummy_BMS4_2
 *   dummy_BMS4_3 of type dummy_BMS4_3
 *   dummy_BMS4_4 of type dummy_BMS4_4
 *   RollingCounter_BMS4 of type RollingCounter_BMS4
 * SG_DCT7: Record with elements
 *   CheckSum_DCT7 of type CheckSum_DCT7
 *   DCT_PrsBrk_Warn of type DCT_PrsBrk_Warn
 *   DCT_RaceModeSts of type DCT_RaceModeSts
 *   DCT_ShftNotAlwd_Warn of type DCT_ShftNotAlwd_Warn
 *   DCT_ShftRecom_M of type DCT_ShftRecom_M
 *   DrvAutoGearDisp of type DrvAutoGearDisp
 *   DrvWarnMsg of type DrvWarnMsg
 *   RollingCounter_DCT7 of type RollingCounter_DCT7
 *   DrvFaiMsg_0x235 of type DrvFaiMsg_0x235
 *   DrvGearDispSts_0x235 of type DrvGearDispSts_0x235
 *   DrvModDisp_0x235 of type DrvModDisp_0x235
 *   DrvModDispSts_0x235 of type DrvModDispSts_0x235
 *   dummy_DCT7_0 of type dummy_DCT7_0
 *   dummy_DCT7_1 of type dummy_DCT7_1
 *   dummy_DCT7_2 of type dummy_DCT7_2
 *   dummy_DCT7_3 of type dummy_DCT7_3
 *   dummy_DCT7_4 of type dummy_DCT7_4
 *   dummy_DCT7_5 of type dummy_DCT7_5
 * SG_DHT_FD1: Record with elements
 *   CheckSum_DHT1 of type CheckSum_DHT1
 *   dummy_DHT_FD1_8 of type dummy_DHT_FD1_8
 *   dummy_DHT_FD1_9 of type dummy_DHT_FD1_9
 *   dummy_DHT_FD1_10 of type dummy_DHT_FD1_10
 *   dummy_DHT_FD1_11 of type dummy_DHT_FD1_11
 *   dummy_DHT_FD1_12 of type dummy_DHT_FD1_12
 *   dummy_DHT_FD1_13 of type dummy_DHT_FD1_13
 *   RollingCounter_DHT1 of type RollingCounter_DHT1
 *   TCU_ClutchHotWarning of type TCU_ClutchHotWarning
 *   TCU_ErrCategory of type TCU_ErrCategory
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
 *   dummy_EPS1_0 of type dummy_EPS1_0
 *   dummy_EPS1_1 of type dummy_EPS1_1
 *   dummy_EPS1_2 of type dummy_EPS1_2
 *   dummy_EPS1_3 of type dummy_EPS1_3
 *   dummy_EPS1_4 of type dummy_EPS1_4
 *   dummy_EPS1_5 of type dummy_EPS1_5
 *   dummy_EPS1_6 of type dummy_EPS1_6
 *   dummy_EPS1_7 of type dummy_EPS1_7
 *   EPS_FailSts_0x168 of type EPS_FailSts_0x168
 *   EPS_SteerMod_0x168 of type EPS_SteerMod_0x168
 *   EPS_TrqSnsrSts_0x168 of type EPS_TrqSnsrSts_0x168
 *   RollingCounter_EPS1_0x168 of type RollingCounter_EPS1_0x168
 * SG_EPS1_FD1: Record with elements
 *   CheckSum_EPS1_0x147 of type CheckSum_EPS1_0x147
 *   dummy_EPS_FD1_0 of type dummy_EPS_FD1_8
 *   dummy_EPS_FD1_1 of type dummy_EPS_FD1_9
 *   dummy_EPS_FD1_2 of type dummy_EPS_FD1_10
 *   dummy_EPS_FD1_3 of type dummy_EPS_FD1_11
 *   dummy_EPS_FD1_4 of type dummy_EPS_FD1_12
 *   dummy_EPS_FD1_5 of type dummy_EPS_FD1_13
 *   dummy_EPS_FD1_6 of type dummy_EPS_FD1_14
 *   dummy_EPS_FD1_7 of type dummy_EPS_FD1_15
 *   EPS_FailSts_0x147 of type EPS_FailSts_0x147
 *   EPS_SteerMod_0x147 of type EPS_SteerMod_0x147
 *   EPS_TrqSnsrSts_0x147 of type EPS_TrqSnsrSts_0x147
 *   RollingCounter_EPS1_0x147 of type RollingCounter_EPS1_0x147
 * SG_ESP1: Record with elements
 *   BTCActv_0x149 of type BTCActv_0x149
 *   CheckSum_ESP1_0x149 of type CheckSum_ESP1_0x149
 *   dummy_ESP1_0 of type dummy_ESP1_0
 *   dummy_ESP1_1 of type dummy_ESP1_1
 *   dummy_ESP1_2 of type dummy_ESP1_2
 *   dummy_ESP1_3 of type dummy_ESP1_3
 *   dummy_ESP1_4 of type dummy_ESP1_4
 *   ESP_MasterCylBrkPress_0x149 of type ESP_MasterCylBrkPress_0x149_1
 *   ESP_MasterCylBrkPressVld_0x149 of type ESP_MasterCylBrkPressVld_0x149
 *   ESPActvInfoLmp_0x149 of type ESPActvInfoLmp_0x149
 *   ESPBrkLmpCtrl_0x149 of type ESPBrkLmpCtrl_0x149
 *   ESPFailSts_0x149 of type ESPFailSts_0x149
 *   ESPFuncOffSts_0x149 of type ESPFuncOffSts_0x149
 *   MSRActv_0x149 of type MSRActv_0x149
 *   PTCActv_0x149 of type PTCActv_0x149
 *   RollingCounter_ESP1_0x149 of type RollingCounter_ESP1_0x149
 *   VDCActv_0x149 of type VDCActv_0x149
 * SG_ESP1_ESP_FD2: Record with elements
 *   BTCActv_0x137 of type BTCActv_0x137
 *   CheckSum_ESP1_0x137 of type CheckSum_ESP1_0x137
 *   dummy_ESP_FD2_16 of type dummy_ESP_FD2_21
 *   dummy_ESP_FD2_17 of type dummy_ESP_FD2_22
 *   dummy_ESP_FD2_18 of type dummy_ESP_FD2_23
 *   dummy_ESP_FD2_19 of type dummy_ESP_FD2_24
 *   dummy_ESP_FD2_20 of type dummy_ESP_FD2_25
 *   ESP_MasterCylBrkPress_0x137 of type ESP_MasterCylBrkPress_0x137_1
 *   ESP_MasterCylBrkPressVld_0x137 of type ESP_MasterCylBrkPressVld_0x137
 *   ESPActvInfoLmp_0x137 of type ESPActvInfoLmp_0x137
 *   ESPBrkLmpCtrl_0x137 of type ESPBrkLmpCtrl_0x137
 *   ESPFailSts_0x137 of type ESPFailSts_0x137
 *   ESPFuncOffSts_0x137 of type ESPFuncOffSts_0x137
 *   MSRActv_0x137 of type MSRActv_0x137
 *   PTCActv_0x137 of type PTCActv_0x137
 *   RollingCounter_ESP1_0x137 of type RollingCounter_ESP1_0x137
 *   VDCActv_0x137 of type VDCActv_0x137
 * SG_ESP2: Record with elements
 *   DrivingModDis of type DrivingModDis_2
 *   DrivingModReq_ESP of type DrivingModReq_ESP_2
 *   TAB_Available of type TAB_Available_2
 *   TAB_Sts of type TAB_Sts_2
 *   ABAActv_0x145 of type ABAActv_0x145
 *   ABAavailable_0x145 of type ABAavailable_0x145
 *   ABPActv_0x145 of type ABPActv_0x145
 *   ABPAvailable_0x145 of type ABPAvailable_0x145
 *   AEBAvailable_0x145 of type AEBAvailable_0x145
 *   AEBBAActv_0x145 of type AEBBAActv_0x145
 *   AEBIBActv_0x145 of type AEBIBActv_0x145
 *   AVHErrSts_0x145 of type AVHErrSts_0x145
 *   AVHSts_0x145 of type AVHSts_0x145
 *   AWBActv_0x145 of type AWBActv_0x145
 *   AWBAvailable_0x145 of type AWBAvailable_0x145
 *   BrkDskOvrheatd_0x145 of type BrkDskOvrheatd_0x145
 *   CDDActv_0x145 of type CDDActv_0x145
 *   CDDAvailable_0x145 of type CDDAvailable_0x145
 *   CDPActv_0x145 of type CDPActv_0x145
 *   CheckSum_ESP2_0x145 of type CheckSum_ESP2_0x145
 *   dummy_ESP2_0 of type dummy_ESP2_0
 *   dummy_ESP2_1 of type dummy_ESP2_1
 *   dummy_ESP2_2 of type dummy_ESP2_2
 *   dummy_ESP2_3 of type dummy_ESP2_3
 *   dummy_ESP2_4 of type dummy_ESP2_4
 *   dummy_ESP2_5 of type dummy_ESP2_5
 *   dummy_ESP2_6 of type dummy_ESP2_6
 *   dummy_ESP2_7 of type dummy_ESP2_7
 *   HDCCtrl_0x145 of type HDCCtrl_0x145
 *   HDCFault_0x145 of type HDCFault_0x145
 *   NoBrkForce_0x145 of type NoBrkForce_0x145
 *   RollingCounter_ESP2_0x145 of type RollingCounter_ESP2_0x145
 *   VehStandstill_0x145 of type VehStandstill_0x145
 * SG_ESP2_ESP_FD2: Record with elements
 *   ABAActv_0x137 of type ABAActv_0x137
 *   ABAavailable_0x137 of type ABAavailable_0x137
 *   ABPActv_0x137 of type ABPActv_0x137
 *   ABPAvailable_0x137 of type ABPAvailable_0x137
 *   AEBAvailable_0x137 of type AEBAvailable_0x137
 *   AEBBAActv_0x137 of type AEBBAActv_0x137
 *   AEBIBActv_0x137 of type AEBIBActv_0x137
 *   AVHErrSts_0x137 of type AVHErrSts_0x137
 *   AVHSts_0x137 of type AVHSts_0x137
 *   AWBActv_0x137 of type AWBActv_0x137
 *   AWBAvailable_0x137 of type AWBAvailable_0x137
 *   BrkDskOvrheatd_0x137 of type BrkDskOvrheatd_0x137
 *   CDDActv_0x137 of type CDDActv_0x137
 *   CDDAvailable_0x137 of type CDDAvailable_0x137
 *   CDPActv_0x137 of type CDPActv_0x137
 *   CheckSum_ESP2_0x137 of type CheckSum_ESP2_0x137
 *   dummy_ESP_FD2_8 of type dummy_ESP_FD2_26
 *   dummy_ESP_FD2_9 of type dummy_ESP_FD2_27
 *   dummy_ESP_FD2_10 of type dummy_ESP_FD2_28
 *   dummy_ESP_FD2_11 of type dummy_ESP_FD2_29
 *   dummy_ESP_FD2_12 of type dummy_ESP_FD2_30
 *   dummy_ESP_FD2_13 of type dummy_ESP_FD2_31
 *   dummy_ESP_FD2_14 of type dummy_ESP_FD2_32
 *   dummy_ESP_FD2_15 of type dummy_ESP_FD2_33
 *   HDCCtrl_0x137 of type HDCCtrl_0x137
 *   HDCFault_0x137 of type HDCFault_0x137
 *   NoBrkForce_0x137 of type NoBrkForce_0x137
 *   RollingCounter_ESP2_0x137 of type RollingCounter_ESP2_0x137
 *   VehStandstill_0x137 of type VehStandstill_0x137
 * SG_HCU_HP5: Record with elements
 *   Checksum_HCU_HP5 of type Checksum_HCU_HP5
 *   DrvFaiMsg_0x201 of type DrvFaiMsg_0x201
 *   DrvGearDisp of type DrvGearDisp
 *   DrvGearDispSts_0x201 of type DrvGearDispSts_0x201
 *   DrvModDisp_0x201 of type DrvModDisp_0x201
 *   DrvModDispSts_0x201 of type DrvModDispSts_0x201
 *   dummy_HCU_HP5_0 of type dummy_HCU_HP5_0
 *   dummy_HCU_HP5_1 of type dummy_HCU_HP5_1
 *   dummy_HCU_HP5_2 of type dummy_HCU_HP5_2
 *   dummy_HCU_HP5_3 of type dummy_HCU_HP5_3
 *   dummy_HCU_HP5_4 of type dummy_HCU_HP5_4
 *   HCU_EnrgFlowInd_DHT of type HCU_EnrgFlowInd_DHT
 *   HCU_PrsBrkWarn of type HCU_PrsBrkWarn
 *   HCU_ShftNotAlwd_Warn of type HCU_ShftNotAlwd_Warn
 *   RollingCounter_HCU_HP5 of type RollingCounter_HCU_HP5
 * SG_HCU_PT4: Record with elements
 *   CarWashMode_Sts of type CarWashMode_Sts
 *   CarWashMode_StsDisp of type CarWashMode_StsDisp
 *   Checksum_HCU_PT4 of type Checksum_HCU_PT4
 *   dummy_HCU_PT4_0 of type dummy_HCU_PT4_0
 *   dummy_HCU_PT4_1 of type dummy_HCU_PT4_1
 *   dummy_HCU_PT4_2 of type dummy_HCU_PT4_2
 *   dummy_HCU_PT4_3 of type dummy_HCU_PT4_3
 *   dummy_HCU_PT4_4 of type dummy_HCU_PT4_4
 *   dummy_HCU_PT4_5 of type dummy_HCU_PT4_5
 *   dummy_HCU_PT4_6 of type dummy_HCU_PT4_6
 *   dummy_HCU_PT4_7 of type dummy_HCU_PT4_7
 *   HCU_ACStsReq of type HCU_ACStsReq
 *   HCU_BattPowerRedWarn of type HCU_BattPowerRedWarn
 *   HCU_ConnectChrgLine_Indcn of type HCU_ConnectChrgLine_Indcn
 *   HCU_EgyRecFB of type HCU_EgyRecFB
 *   HCU_EnerSavePowerMod of type HCU_EnerSavePowerMod
 *   HCU_InhbChrgInfo of type HCU_InhbChrgInfo
 *   HCU_OilTankCoverSts of type HCU_OilTankCoverSts
 *   HCU_OPDFail of type HCU_OPDFail
 *   HCU_RefuReq of type HCU_RefuReq
 *   HCU_RemoveChrgLine_Indcn of type HCU_RemoveChrgLine_Indcn
 *   HCU_Shift_P_Indcn of type HCU_Shift_P_Indcn
 *   HCU_SOCLow_Indcn of type HCU_SOCLow_Indcn
 *   HCU_WadeModeSetSts of type HCU_WadeModeSetSts
 *   OPDParkWarnReq of type OPDParkWarnReq
 *   RollingCounter_HCU_PT4 of type RollingCounter_HCU_PT4
 * SG_HCU_PT7: Record with elements
 *   CheckSum_HCU_PT7 of type CheckSum_HCU_PT7
 *   dummy_HCU_PT7_0 of type dummy_HCU_PT7_0
 *   dummy_HCU_PT7_1 of type dummy_HCU_PT7_1
 *   dummy_HCU_PT7_2 of type dummy_HCU_PT7_2
 *   dummy_HCU_PT7_3 of type dummy_HCU_PT7_3
 *   dummy_HCU_PT7_4 of type dummy_HCU_PT7_4
 *   dummy_HCU_PT7_5 of type dummy_HCU_PT7_5
 *   dummy_HCU_PT7_6 of type dummy_HCU_PT7_6
 *   HCU_12VSysErr_1 of type HCU_12VSysErr_1
 *   HCU_12VSysErr_2 of type HCU_12VSysErr_2
 *   HCU_12VSysErrLmpSts of type HCU_12VSysErrLmpSts
 *   HCU_EnrgFlowInd of type HCU_EnrgFlowInd
 *   HCU_HybSysErr_1 of type HCU_HybSysErr_1
 *   HCU_HybSysErr_2 of type HCU_HybSysErr_2
 *   HCU_HybSysErr_3 of type HCU_HybSysErr_3
 *   HCU_HybSysErr_4 of type HCU_HybSysErr_4
 *   HCU_HybSysErr_5 of type HCU_HybSysErr_5
 *   HCU_HybSysErr_6 of type HCU_HybSysErr_6
 *   HCU_HybSysErr_7 of type HCU_HybSysErr_7
 *   HCU_HybSysErrLmpSts of type HCU_HybSysErrLmpSts
 *   HCU_ModSwtFail of type HCU_ModSwtFail
 *   HCU_OPDLmpSts of type HCU_OPDLmpSts
 *   HCU_OPDSts of type HCU_OPDSts
 *   HCU_PowerRedWarnLmpCmd of type HCU_PowerRedWarnLmpCmd
 *   HCU_RdyLmpSts of type HCU_RdyLmpSts
 *   RollingCounter_HCU_PT7 of type RollingCounter_HCU_PT7
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
 *   Std_ReturnType Rte_Read_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox(HiBeamSts_F_Pbox *data)
 *   Std_ReturnType Rte_Read_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox(RFogLmpSts_R_Pbox *data)
 *   Std_ReturnType Rte_Read_SG_ABM1_SG_ABM1(SG_ABM1 *data)
 *   Std_ReturnType Rte_Read_SG_ABS3_SG_ABS3(SG_ABS3 *data)
 *   Std_ReturnType Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(SG_ABS3_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(SG_AEB2_AEB_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(SG_AEB3_AEB_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_BMS4_SG_BMS4(SG_BMS4 *data)
 *   Std_ReturnType Rte_Read_SG_DCT7_SG_DCT7(SG_DCT7 *data)
 *   Std_ReturnType Rte_Read_SG_DHT_FD1_SG_DHT_FD1(SG_DHT_FD1 *data)
 *   Std_ReturnType Rte_Read_SG_EPB1_SG_EPB1(SG_EPB1 *data)
 *   Std_ReturnType Rte_Read_SG_EPS1_SG_EPS1(SG_EPS1 *data)
 *   Std_ReturnType Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1(SG_EPS1_FD1 *data)
 *   Std_ReturnType Rte_Read_SG_ESP1_SG_ESP1(SG_ESP1 *data)
 *   Std_ReturnType Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(SG_ESP1_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_ESP2_SG_ESP2(SG_ESP2 *data)
 *   Std_ReturnType Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(SG_ESP2_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_SG_HCU_HP5_SG_HCU_HP5(SG_HCU_HP5 *data)
 *   Std_ReturnType Rte_Read_SG_HCU_PT4_SG_HCU_PT4(SG_HCU_PT4 *data)
 *   Std_ReturnType Rte_Read_SG_HCU_PT7_SG_HCU_PT7(SG_HCU_PT7 *data)
 *   Std_ReturnType Rte_Read_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(SG_IFC6_IFC_FD2 *data)
 *   Std_ReturnType Rte_Read_Tgtgear_Down_Tgtgear_Down(Tgtgear_Down *data)
 *   Std_ReturnType Rte_Read_Tgtgear_Up_Tgtgear_Up(Tgtgear_Up *data)
 *   Std_ReturnType Rte_Read_Vconfig_KindBuffers_400bytes_VconfigKind_400Bytes(uint8 *data)
 *     Argument data: uint8* is of type VconfigKind_400Bytes
 *   Std_ReturnType Rte_Read_piSR_E2ESwitchChangeTrigger_Element(uint8 *data)
 *   boolean Rte_IsUpdated_SG_ABM1_SG_ABM1(void)
 *   boolean Rte_IsUpdated_SG_ABS3_SG_ABS3(void)
 *   boolean Rte_IsUpdated_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_AEB2_AEB_FD2_SG_AEB2_AEB_FD2(void)
 *   boolean Rte_IsUpdated_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(void)
 *   boolean Rte_IsUpdated_SG_BMS4_SG_BMS4(void)
 *   boolean Rte_IsUpdated_SG_DCT7_SG_DCT7(void)
 *   boolean Rte_IsUpdated_SG_DHT_FD1_SG_DHT_FD1(void)
 *   boolean Rte_IsUpdated_SG_EPB1_SG_EPB1(void)
 *   boolean Rte_IsUpdated_SG_EPS1_SG_EPS1(void)
 *   boolean Rte_IsUpdated_SG_EPS1_FD1_SG_EPS1_FD1(void)
 *   boolean Rte_IsUpdated_SG_ESP1_SG_ESP1(void)
 *   boolean Rte_IsUpdated_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_ESP2_SG_ESP2(void)
 *   boolean Rte_IsUpdated_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(void)
 *   boolean Rte_IsUpdated_SG_HCU_HP5_SG_HCU_HP5(void)
 *   boolean Rte_IsUpdated_SG_HCU_PT4_SG_HCU_PT4(void)
 *   boolean Rte_IsUpdated_SG_HCU_PT7_SG_HCU_PT7(void)
 *   boolean Rte_IsUpdated_SG_IFC6_IFC_FD2_SG_IFC6_IFC_FD2(void)
 *   boolean Rte_IsUpdated_Tgtgear_Down_Tgtgear_Down(void)
 *   boolean Rte_IsUpdated_Tgtgear_Up_Tgtgear_Up(void)
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
 *   Std_ReturnType Rte_Read_HiBeamSts_F_Pbox_HiBeamSts_F_Pbox(HiBeamSts_F_Pbox *data)
 *   Std_ReturnType Rte_Read_RFogLmpSts_R_Pbox_RFogLmpSts_R_Pbox(RFogLmpSts_R_Pbox *data)
 *   Std_ReturnType Rte_Read_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(SG_ESP1_ESP_FD2 *data)
 *   Std_ReturnType Rte_Read_Tgtgear_Down_Tgtgear_Down(Tgtgear_Down *data)
 *   Std_ReturnType Rte_Read_Tgtgear_Up_Tgtgear_Up(Tgtgear_Up *data)
 *   boolean Rte_IsUpdated_SG_ESP1_ESP_FD2_SG_ESP1_ESP_FD2(void)
 *   boolean Rte_IsUpdated_Tgtgear_Down_Tgtgear_Down(void)
 *   boolean Rte_IsUpdated_Tgtgear_Up_Tgtgear_Up(void)
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
