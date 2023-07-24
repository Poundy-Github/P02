/**
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.
* All Rights Reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are NOT permitted except as agreed by
* Nobo Automotive Technologies Co.,Ltd.
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
/**
 **********************************************************************************************************************
 * @file:      CConfig_Cfg.h
 * @author:    Nobo
 * @date:      2020-10-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-10-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %head of header file guard%
 */
#ifndef __CCONFIG_CFG_H
#define __CCONFIG_CFG_H


/*
 *  %header file%
 */
#include "CConfig.h"


/*
 *  %head of extern "C" declaration%
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *  %type definition%
 */

#define CCONFIG_RAW_DATA_SIZE (300u)

#define CCONFIG_KIND_BUFFER_SIZE (400u)

#define CCONFIG_KIND_RefreshRateDigSpd (0u)
#define CCONFIG_KIND_ZeroScale_ImperialSpeedo (1u)
#define CCONFIG_KIND_Fast_Resp (2u)
#define CCONFIG_KIND_DigitalRPM_Hysteresis (3u)
#define CCONFIG_KIND_AnalogRPM_Hysteresis (4u)
#define CCONFIG_KIND_DiagitalTacho_update_frequency (5u)
#define CCONFIG_KIND_GasolineCoolant_C_point (6u)
#define CCONFIG_KIND_GasolineCoolant_1_4_point (7u)
#define CCONFIG_KIND_GasolineCoolant_1_2_point1 (8u)
#define CCONFIG_KIND_GasolineCoolant_1_2_point2 (9u)
#define CCONFIG_KIND_GasolineCoolant__4_point (10u)
#define CCONFIG_KIND_GasolineCoolant_Redline_point (11u)
#define CCONFIG_KIND_GasolineCoolant_H_point (12u)
#define CCONFIG_KIND_DieselCoolant_C_point (13u)
#define CCONFIG_KIND_DieselCoolant_1_4_point (14u)
#define CCONFIG_KIND_DieselCoolant_1_2_point1 (15u)
#define CCONFIG_KIND_DieselCoolant_1_2_point2 (16u)
#define CCONFIG_KIND_DieselCoolant_3_4_point (17u)
#define CCONFIG_KIND_DieselCoolant_Redline_point (18u)
#define CCONFIG_KIND_DieselCoolant_H_point (19u)
#define CCONFIG_KIND_Error_Gasoline_Low (20u)
#define CCONFIG_KIND_Error_Gasoline_High (21u)
#define CCONFIG_KIND_Error_Detect_Time (22u)
#define CCONFIG_KIND_Error_Recover_Time (23u)
#define CCONFIG_KIND_Refuel_Delaytime (24u)
#define CCONFIG_KIND_Ref_Time (25u)
#define CCONFIG_KIND_Refuel_Speed (26u)
#define CCONFIG_KIND_Halt_Speed (27u)
#define CCONFIG_KIND_Damp_lowfuel (28u)
#define CCONFIG_KIND_Damp_run_fuelup (29u)
#define CCONFIG_KIND_Damp_run_fueldown (30u)
#define CCONFIG_KIND_Fuel_Distime (31u)
#define CCONFIG_KIND_Refuel_Conf_Time (32u)
#define CCONFIG_KIND_RefuelDamping2 (33u)
#define CCONFIG_KIND_Damp_idle (34u)
#define CCONFIG_KIND_LowFueldetecttime (35u)
#define CCONFIG_KIND_LowFuelReleasetime (36u)
#define CCONFIG_KIND_IFC_Avg_Conf_Time (37u)
#define CCONFIG_KIND_Refuel_Trigger1 (38u)
#define CCONFIG_KIND_Exception_Volume1 (39u)
#define CCONFIG_KIND_LFW_Trigger1 (40u)
#define CCONFIG_KIND_LFW_Release1 (41u)
#define CCONFIG_KIND_StripAgeFuelInitFuelCon1 (42u)
#define CCONFIG_KIND_StripAgeFuelInitFuelCon2 (43u)
#define CCONFIG_KIND_StripAgeFuelInitFuelCon3 (44u)
#define CCONFIG_KIND_Refuel_Trigger2 (45u)
#define CCONFIG_KIND_Exception_Volume2 (46u)
#define CCONFIG_KIND_LFW_Trigger2 (47u)
#define CCONFIG_KIND_LFW_Release2 (48u)
#define CCONFIG_KIND_StripAgeFuelInitFuelCon4 (49u)
#define CCONFIG_KIND_StripAgeFuelInitFuelCon5 (50u)
#define CCONFIG_KIND_StripAgeFuelInitFuelCon6 (51u)
#define CCONFIG_KIND_Refuel_Trigger3 (52u)
#define CCONFIG_KIND_Exception_Volume3 (53u)
#define CCONFIG_KIND_LFW_Trigger3 (54u)
#define CCONFIG_KIND_LFW_Release3 (55u)
#define CCONFIG_KIND_STripAgeInitTripBileage1 (56u)
#define CCONFIG_KIND_STripAgeInitTripBileage2 (57u)
#define CCONFIG_KIND_STripAgeInitTripBileage3 (58u)
#define CCONFIG_KIND_STripAgeInitTripBileage4 (59u)
#define CCONFIG_KIND_Refuel_Trigger4 (60u)
#define CCONFIG_KIND_Exception_Volume4 (61u)
#define CCONFIG_KIND_LFW_Trigger4 (62u)
#define CCONFIG_KIND_LFW_Release4 (63u)
#define CCONFIG_KIND_Refuel_Trigger5 (64u)
#define CCONFIG_KIND_Exception_Volume5 (65u)
#define CCONFIG_KIND_LFW_Trigger5 (66u)
#define CCONFIG_KIND_LFW_Release5 (67u)
#define CCONFIG_KIND_Horizontal_data (68u)
#define CCONFIG_KIND_X (69u)
#define CCONFIG_KIND_Y (70u)
#define CCONFIG_KIND_Chimedelaytime (71u)
#define CCONFIG_KIND_DrivDataARestTime (72u)
#define CCONFIG_KIND_RefreshRateAVS (73u)
#define CCONFIG_KIND_AVSMinDistanceThresh (74u)
#define CCONFIG_KIND_AVSBDisplayEnable (75u)
#define CCONFIG_KIND_AVSADisplayEnable (76u)
#define CCONFIG_KIND_TravelTimeADisplayEnable (77u)
#define CCONFIG_KIND_TravelTimeBDisplayEnable (78u)
#define CCONFIG_KIND_TravelTimeDisplayLimited (79u)
#define CCONFIG_KIND_RefreshRateAFC (80u)
#define CCONFIG_KIND_Max_fuelConPerCycle (81u)
#define CCONFIG_KIND_AFCMinDistanceThresh (82u)
#define CCONFIG_KIND_AFCADisplayEnable (83u)
#define CCONFIG_KIND_AFCBDisplayEnable (84u)
#define CCONFIG_KIND_RefreshRateIFC (85u)
#define CCONFIG_KIND_IFC_POC_Update (86u)
#define CCONFIG_KIND_IFCDisplayEnable (87u)
#define CCONFIG_KIND_DigitalSpeedDisplayEnable (88u)
#define CCONFIG_KIND_RefreshRateDTE (89u)
#define CCONFIG_KIND_RefreshRateDTEReFuel (90u)
#define CCONFIG_KIND_SFCMin (91u)
#define CCONFIG_KIND_SFCMax (92u)
#define CCONFIG_KIND_RangeIncThreshold (93u)
#define CCONFIG_KIND_RangeDecThreshold (94u)
#define CCONFIG_KIND_FastUpdateTime (95u)
#define CCONFIG_KIND_SlowUpdateTime (96u)
#define CCONFIG_KIND_IdleUpdateTime (97u)
#define CCONFIG_KIND_UnNormalUpdateTime (98u)
#define CCONFIG_KIND_RefreshRateTPMS (99u)
#define CCONFIG_KIND_TPMSDisplayEnable (100u)
#define CCONFIG_KIND_PHEV_HEVDTEDisplayEnable (101u)
#define CCONFIG_KIND_MaxDisplayPHEVRange (102u)
#define CCONFIG_KIND_PHEV_HEVCurrentDisplayEnable (103u)
#define CCONFIG_KIND_PHEVSOCDisplayEnable (104u)
#define CCONFIG_KIND_RefreshRatePHEVSOC (105u)
#define CCONFIG_KIND_AvailablePowerDisplayEnable (106u)
#define CCONFIG_KIND_MaxAvailablePower (107u)
#define CCONFIG_KIND_RefreshRateAvrgEgyCns (108u)
#define CCONFIG_KIND_AvrgEgyCnsDisplayEnable (109u)
#define CCONFIG_KIND_MaxvalueAvrgEgyCns (110u)
#define CCONFIG_KIND_RefreshRatemotorpower (111u)
#define CCONFIG_KIND_motorpowerDisplayEnable (112u)
#define CCONFIG_KIND_RefreshRateEVSOC (113u)
#define CCONFIG_KIND_EVSOCDisplayEnable (114u)
#define CCONFIG_KIND_RefreshRateEVDTE (115u)
#define CCONFIG_KIND_EVDTEDisplayEnable (116u)
#define CCONFIG_KIND_MaxvalueEVDTE (117u)
#define CCONFIG_KIND_RefreshRateCurrent (118u)
#define CCONFIG_KIND_EVCurrentDisplayEnable (119u)
#define CCONFIG_KIND_EVDrivDataARestTime (120u)
#define CCONFIG_KIND_RefreshRateEVAVS (121u)
#define CCONFIG_KIND_EVAVSMinDistanceThresh (122u)
#define CCONFIG_KIND_EVAVSADisplayEnable (123u)
#define CCONFIG_KIND_EVAVSBDisplayEnable (124u)
#define CCONFIG_KIND_EVTravelTimeDisplayLimited (125u)
#define CCONFIG_KIND_EVTravelTimeADisplayEnable (126u)
#define CCONFIG_KIND_EVTravelTimeBDisplayEnable (127u)
#define CCONFIG_KIND_FIXDISPLAY_1_GEAR_ENABLE (128u)
#define CCONFIG_KIND_FIXDISPLALY_2_SHIFT_GEAR_RECOMMEND_ENABLE (129u)
#define CCONFIG_KIND_DISPLAY_6_GEAR_ENABLE (130u)
#define CCONFIG_KIND_DISPLALY_6_SHIFT_GEAR_RECOMMEND_ENABLE (131u)
#define CCONFIG_KIND_FD_003_CLOCK_ENABLE (132u)
#define CCONFIG_KIND_FIXEDDISPLAY_1_ODO_ENABLE (133u)
#define CCONFIG_KIND_P_ODOBACK_ENABLE (134u)
#define CCONFIG_KIND_P_ODOBACK_WARNING_ENABLE (135u)
#define CCONFIG_KIND_ODOVIN_CheckInequalityTime (136u)
#define CCONFIG_KIND_ODObackup_DelayTime (137u)
#define CCONFIG_KIND_FD_009_DRIVE_MODE_2WD_ENABLE (138u)
#define CCONFIG_KIND_DriveModeShieldTime (139u)
#define CCONFIG_KIND_Maintenance_distance (140u)
#define CCONFIG_KIND_LowOilPressure_telltales_DelayTime (141u)
#define CCONFIG_KIND_LOW_telltales_CheckTime (142u)
#define CCONFIG_KIND_EPBRedlamp_lightorflashtime (143u)
#define CCONFIG_KIND_Tpms_flashtime (144u)
#define CCONFIG_KIND_BrakeFault_DelayTime (145u)
#define CCONFIG_KIND_DoortoRed_speedthreshold (146u)
#define CCONFIG_KIND_Doorallclosed_holdtime (147u)
#define CCONFIG_KIND_Tpms_delay (148u)
#define CCONFIG_KIND_AccelBrakeWrnDelayTime (149u)
#define CCONFIG_KIND_Telltaleinterruptdisplaytime (150u)
#define CCONFIG_KIND_Telltalepollingdisplaytime (151u)
#define CCONFIG_KIND_ADASsoundfieldEnable (152u)
#define CCONFIG_KIND_DrivDataARollovervalue (153u)
#define CCONFIG_KIND_DrivDataBRollovervalue (154u)
#define CCONFIG_KIND_DrivDataADisplayEnable (155u)
#define CCONFIG_KIND_DrivDataBDisplayEnable (156u)
#define CCONFIG_KIND_V1 (157u)
#define CCONFIG_KIND_V2 (158u)
#define CCONFIG_KIND_GasolineCoolant_Distime (159u)
#define CCONFIG_KIND_DieselCoolant_Distime (160u)
#define CCONFIG_KIND_RefreshRatePHEVDTE (161u)
#define CCONFIG_KIND_RefreshRateAvailablePower (162u)
#define CCONFIG_KIND_RefreshRatePower (163u)
#define CCONFIG_KIND_RefreshRateECODrvHabit (164u)
#define CCONFIG_KIND_RefreshRateChrgDuration (165u)
#define CCONFIG_KIND_RefreshRateDigitalPHEVSOC (166u)
#define CCONFIG_KIND_HMITimeOut (167u)
#define CCONFIG_KIND_RefreshRateEVECODrvHabit (168u)
#define CCONFIG_KIND_RefreshRateDigitalEVSOC (169u)
#define CCONFIG_KIND_ECODrvHabit_Distime (170u)
#define CCONFIG_KIND_IVITimeOut (171u)
#define CCONFIG_KIND_RefreshRateUrea (172u)
#define CCONFIG_KIND_Refuel_Trigger6 (173u)
#define CCONFIG_KIND_Exception_Volume6 (174u)
#define CCONFIG_KIND_LFW_Trigger6 (175u)
#define CCONFIG_KIND_LFW_Release6 (176u)
#define CCONFIG_KIND_Refuel_Trigger7 (177u)
#define CCONFIG_KIND_Exception_Volume7 (178u)
#define CCONFIG_KIND_LFW_Trigger7 (179u)
#define CCONFIG_KIND_LFW_Release7 (180u)
#define CCONFIG_KIND_AnalogSpeedDamping (181u)
#define CCONFIG_KIND_AnalogRPM_Damping (182u)
#define CCONFIG_KIND_PHEVSOC_Distime (183u)
#define CCONFIG_KIND_AccMax_Latitude (184u)
#define CCONFIG_KIND_AccMax_Longitude (185u)
#define CCONFIG_KIND_GValue_Hysteresis (186u)
#define CCONFIG_KIND_GValue_update_frequency (187u)
#define CCONFIG_KIND_Oilpressure_Distime (188u)
#define CCONFIG_KIND_Oiltemp_Distime (189u)
#define CCONFIG_KIND_GBall_move_time (190u)
#define CCONFIG_KIND_SteerWheelAng_Hysteresis (191u)
#define CCONFIG_KIND_EnrgFlowDisplayEnable (192u)
#define CCONFIG_KIND_RefreshRateEnrgFlow (193u)


#define CCONFIG_KIND_NUMBER (194u)
#define CCONFIG_KIND_SFCDefault (200u)

/*
 *  %function declaration%
 */
extern const CConfig_KindConfigType cConfig_kindConfigs[];

extern CConfig_ConfigType cConfig_config;

extern uint8 Get_Cconfig_Flag;
extern uint8 Cconfig_Response_Flag;

extern uint8 CconfigRequestUpdateLatestCount;
extern uint8 CconfigRequestUpdatePreCount;




uint64 CConfig_GetConfig(uint16 kindId, uint8 *buffer);

/*
 *  %bottom of extern "C" declaration%
 */
#ifdef __cplusplus
}
#endif

/*
 *  %bottom of header file guard%
 */
#endif
