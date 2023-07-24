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
 * @file:      VConfig_Cfg.c
 * @author:    Nobo
 * @date:      2020-6-14
 * @brief:
 **********************************************************************************************************************
 * @attention:
 *    1. date    : 2020-6-14
 *       author  : Nobo
 *       reviser : create
 **********************************************************************************************************************
*/

/*
 *  %header file in this project/library%
 */
#include "VConfig_Cfg.h"
#include "VConfig.h"
#include "Rte_Vconfig.h"
#include "DcmEx_Switch.h"

/*
 *  %third-party header file%
 */


/*
 *  %system/C-run-time header file%
 */


/*
 *  %typedef/macro defintion%
 */



/*
 *  %forward declaration%
 */


/*
 *  %global definition%
 */
#define VCONFIG_START_SEC_CONST_UNSPECIFIED
#include "VConfig_MemMap.h"

#define VCONFIG_KINDBUFSIZE    (600u)

static const VConfig_KindConfigType vconfig_kindConfigs[VCONFIG_KIND_NUMBER]=
{
    {0u, 0u, 7u},  /* VCONFIG_KIND_PROJECT_CODE */
    {1u, 3u, 7u},  /* VCONFIG_KIND_AUDIO_VIDEO_SYSTEM */
    {1u, 0u, 2u},  /* VCONFIG_KIND_SEAT_HEATING */
    {2u, 4u, 7u},  /* VCONFIG_KIND_FUEL */
    {2u, 0u, 3u},  /* VCONFIG_KIND_TRAFFIC_SIGN_WARNING */
    {3u, 0u, 7u},  /* VCONFIG_KIND_TRANSMISSION */
    {4u, 6u, 7u},  /* VCONFIG_KIND_DRIVE_HANDLE_TYPE */
    {4u, 2u, 5u},  /* VCONFIG_KIND_REGIONAL */
    {4u, 0u, 1u},  /* VCONFIG_KIND_IDLE_STOP_AND_GO */
    {5u, 0u, 7u},  /* VCONFIG_KIND_OUTSIDE_RR_VIEW_MIRROR */
    {6u, 0u, 7u},  /* VCONFIG_KIND_SALES_AREA */
    {7u, 6u, 7u},  /* VCONFIG_KIND_FRT_DEAD_ANGLE_SYSTEM */
    {7u, 0u, 5u},  /* VCONFIG_KIND_DRIVER_SEAT */
    {8u, 6u, 7u},  /* VCONFIG_KIND_HEAD_LAMP_AUTO_OFF */
    {8u, 3u, 5u},  /* VCONFIG_KIND_FRT_SEAT_COOLING_FRT_SEAT_MASSAGE */
    {8u, 0u, 2u},  /* VCONFIG_KIND_REVERSE_VIDEO */
    {9u, 4u, 7u},  /* VCONFIG_KIND_CLUSTER */
    {9u, 0u, 3u},  /* VCONFIG_KIND_HEAD_LAMP_ADJUSTMENT */
    {10u, 4u, 7u},  /* VCONFIG_KIND_MOOD_LAMP */
    {10u, 0u, 3u},  /* VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING */
    {11u, 6u, 7u},  /* VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM */
    {11u, 3u, 5u},  /* VCONFIG_KIND_AUTO_PARKING_SYSTEM */
    {11u, 0u, 2u},  /* VCONFIG_KIND_STARTING_SYSTEM */
    {12u, 6u, 7u},  /* VCONFIG_KIND_OMNIVIEW_SYSTEM */
    {12u, 4u, 5u},  /* VCONFIG_KIND_DR_OPEN_WARNING */
    {12u, 0u, 3u},  /* VCONFIG_KIND_LDW_LKA */
    {13u, 2u, 7u},  /* VCONFIG_KIND_AIR_CONDITIONER */
    {13u, 0u, 1u},  /* VCONFIG_KIND_AIR_QUALITY_SYSTEM */
    {14u, 6u, 7u},  /* VCONFIG_KIND_LANE_CHANGE_ASSIST */
    {14u, 4u, 5u},  /* VCONFIG_KIND_TELEMATICS */
    {14u, 2u, 3u},  /* VCONFIG_KIND_VOICE_RECOGNITION */
    {14u, 0u, 1u},  /* VCONFIG_KIND_HUMAN_COMPUTER_INTERACTION */
    {15u, 6u, 7u},  /* VCONFIG_KIND_INTELLIGENT_FRONT_CAMERA */
    {15u, 4u, 5u},  /* VCONFIG_KIND_REMOTE_RESERVATION_CHARGING */
    {15u, 0u, 3u},  /* VCONFIG_KIND_ELECTRIC_SOUND_REMINDER */
    {16u, 5u, 7u},  /* VCONFIG_KIND_NAVIGATION */
    {16u, 2u, 4u},  /* VCONFIG_KIND_PASS  WAIST_SUPPORTER */
    {16u, 0u, 1u},  /* VCONFIG_KIND_VOICE_&_FACIAL_RECOGNITION */
    {17u, 5u, 7u},  /* VCONFIG_KIND_DRIVER_WAIST_SUPPORTER */
    {17u, 2u, 4u},  /* VCONFIG_KIND_BRAKING_ENERGY_RECOVERY */
    {17u, 0u, 1u},  /* VCONFIG_KIND_REAR_COLLISION_WARNING */
    {18u, 3u, 7u},  /* VCONFIG_KIND_SPEAKER */
    {18u, 0u, 2u},  /* VCONFIG_KIND_DECK */
    {19u, 4u, 7u},  /* VCONFIG_KIND_REAR_PAS_SENSOR */
    {19u, 0u, 3u},  /* VCONFIG_KIND_FRONT_SENSOR */
    {20u, 5u, 7u},  /* VCONFIG_KIND_PAS_CTA */
    {20u, 2u, 4u},  /* VCONFIG_KIND_RR_DOOR_OPENING */
    {20u, 0u, 1u},  /* VCONFIG_KIND_BLUETOOTH */
    {21u, 5u, 7u},  /* VCONFIG_KIND_SEAT_CONTROL_MODULE */
    {21u, 2u, 4u},  /* VCONFIG_KIND_AIR_PURIFIER */
    {21u, 0u, 1u},  /* VCONFIG_KIND_FRAGRANCE_SYSTEM */
    {22u, 6u, 7u},  /* VCONFIG_KIND_DEFAULT_TEMPERATURE_UNIT */
    {22u, 4u, 5u},  /* VCONFIG_KIND_OFF_ROAD_INFORMATION_DISPLAY */
    {22u, 2u, 3u},  /* VCONFIG_KIND_DOOR_UNLOCK_MODE */
    {22u, 0u, 1u},  /* VCONFIG_KIND_REMOTE_CONTROL */
    {23u, 5u, 7u},  /* VCONFIG_KIND_TRAILING_HOOK */
    {23u, 2u, 4u},  /* VCONFIG_KIND_AMPLIFIER */
    {23u, 0u, 1u},  /* VCONFIG_KIND_INDOOR_AUTOMATIC_DEMISTING */
    {24u, 4u, 7u},  /* VCONFIG_KIND_VIDEO_DATA_RECORDER */
    {24u, 0u, 3u},  /* VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE */
    {25u, 4u, 7u},  /* VCONFIG_KIND_DRIVING_MODE_OPTIONAL(VEHICLE_CONFIGURATION_INFORMATION) */
    {25u, 2u, 3u},  /* VCONFIG_KIND_OFF_ROAD_CRUISE_CONTROL */
    {25u, 0u, 1u},  /* VCONFIG_KIND_STEERING_SYSTEM */
    {26u, 5u, 7u},  /* VCONFIG_KIND_PARKING_BRAKE */
    {26u, 0u, 4u},  /* VCONFIG_KIND_SERVICE_BRAKE */
    {27u, 0u, 7u},  /* VCONFIG_KIND_POWER_TRAIN_TYPE */
    {28u, 4u, 7u},  /* VCONFIG_KIND_CRUISE_CONTROL */
    {28u, 0u, 3u},  /* VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL */
    {29u, 0u, 7u},  /* VCONFIG_KIND_ELECTRIC_LANGUAGE */
    {30u, 4u, 7u},  /* VCONFIG_KIND_ELECTROMOTOR_POSITION */
    {30u, 0u, 3u},  /* VCONFIG_KIND_TRANSFER_CASE */
    {31u, 3u, 7u},  /* VCONFIG_KIND_EMISSION_LEVEL */
    {31u, 0u, 2u},  /* VCONFIG_KIND_UP_DOWN_HILL */
    {32u, 5u, 7u},  /* VCONFIG_KIND_SEAT_BELT */
    {32u, 2u, 4u},  /* VCONFIG_KIND_SPEEDOMETER */
    {32u, 0u, 1u},  /* VCONFIG_KIND_PARKING_LAMP */
    {33u, 6u, 7u},  /* VCONFIG_KIND_AVH */
    {33u, 4u, 5u},  /* VCONFIG_KIND_FRT_OUTER_SENSOR */
    {33u, 0u, 3u},  /* VCONFIG_KIND_HEAD_LAMP_BEAM_SYSTEM */
    {34u, 4u, 7u},  /* VCONFIG_KIND_FRT_BUMPER */
    {34u, 0u, 3u},  /* VCONFIG_KIND_RR_BUMPER */
    {35u, 4u, 7u},  /* VCONFIG_KIND_NORMAL_TIRE_PRESSURE */
    {35u, 0u, 3u},  /* VCONFIG_KIND_CLUSTER_UNIT_SYSTEM */
    {36u, 6u, 7u},  /* VCONFIG_KIND_CO_PILOT_AIRBAG_SWITCH */
    {36u, 4u, 5u},  /* VCONFIG_KIND_AUTO_LIGHT_SYSTEM */
    {36u, 0u, 3u},  /* VCONFIG_KIND_FRONT_WIPER_SYSTEM */
    {37u, 4u, 7u},  /* VCONFIG_KIND_HEAD_LAMP_LIGHTING */
    {37u, 2u, 3u},  /* VCONFIG_KIND_ELECTRICAL_ENERGY_MANAGEMENT */
    {37u, 0u, 1u},  /* VCONFIG_KIND_TYPE_OF_BOOSTER_BRAKE_PUMP */
    {38u, 6u, 7u},  /* VCONFIG_KIND_SPEED_SENSING_REVERSE */
    {38u, 4u, 5u},  /* VCONFIG_KIND_SMART_JUNCTION_BOX */
    {38u, 0u, 3u},  /* VCONFIG_KIND_HEAD_UP_DISPLAY */
    {39u, 5u, 7u},  /* VCONFIG_KIND_NIGHT_VISION_SYSTEM */
    {39u, 3u, 4u},  /* VCONFIG_KIND_TPMS */
    {39u, 0u, 2u},  /* VCONFIG_KIND_AC_GENERATOR_PROPERTIES */
    {40u, 5u, 7u},  /* VCONFIG_KIND_RADIATOR_GRILLE */
    {40u, 3u, 4u},  /* VCONFIG_KIND_ELECTRONIC_STEERING_COLUMN_LOCK */
    {40u, 0u, 2u},  /* VCONFIG_KIND_SMART_START_STOP_SWITCH_MEMORY_SETTING */
    {41u, 4u, 7u},  /* VCONFIG_KIND_DECK_COVER */
    {41u, 2u, 3u},  /* VCONFIG_KIND_E_PARK */
    {41u, 0u, 1u},  /* VCONFIG_KIND_ENGINE_IMMOBILIZER */
    {42u, 3u, 7u},  /* VCONFIG_KIND_ENGINE_CONTROL_UNIT */
    {42u, 0u, 2u},  /* VCONFIG_KIND_WIRELESS_POWER_CHARGER */
    {43u, 4u, 7u},  /* VCONFIG_KIND_QUICK_START */
    {43u, 2u, 3u},  /* VCONFIG_KIND_TRANSMISSION_IMMOBILIZER */
    {43u, 0u, 1u},  /* VCONFIG_KIND_OUSIDE_TEMPERATURE_DISPLAY */
    {44u, 2u, 7u},  /* VCONFIG_KIND_PRODUCT_NAME */
    {44u, 0u, 1u},  /* VCONFIG_KIND_TAB */
    {45u, 5u, 7u},  /* VCONFIG_KIND_HIGHWAY_ASSIST */
    {45u, 2u, 4u},  /* VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK */
    {45u, 0u, 1u},  /* VCONFIG_KIND_AUTO_EVASIVE_STEERING */
    {46u, 5u, 7u},  /* VCONFIG_KIND_AEB_JUNCTION_ASSIST */
    {46u, 3u, 4u},  /* VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT */
    {46u, 0u, 2u},  /* VCONFIG_KIND_COMBINATION_TYPE_OF_INFOTAINMENT_SYSTEM */
    {47u, 6u, 7u},  /* VCONFIG_KIND_STEERING_HEATING */
    {47u, 4u, 5u},  /* VCONFIG_KIND_HAPTIC_REMINDER_OF_ENHANCED_ASSIET_SYSTEMS */
    {47u, 2u, 3u},  /* VCONFIG_KIND_HAPTIC_REMINDER_OF_LANE_SUPPORT_SYSTEMS */
    {47u, 0u, 1u},  /* VCONFIG_KIND_SUPER_LOCK */
    {48u, 4u, 7u},  /* VCONFIG_KIND_SIDE_STEP */
    {48u, 0u, 3u},  /* VCONFIG_KIND_ANTENNA */
    {49u, 6u, 7u},  /* VCONFIG_KIND_ACTIVE_NOISE_REDUCTION_SYSTEM */
    {49u, 4u, 5u},  /* VCONFIG_KIND_SHIFTED_UNLOCK_KEY */
    {49u, 0u, 3u},  /* VCONFIG_KIND_DRIVER_WINDOW_OPERATING */
    {50u, 4u, 7u},  /* VCONFIG_KIND_PASSENGER_WINDOW_OPERATING */
    {50u, 0u, 3u},  /* VCONFIG_KIND_RR_1ST_WINDOW_OPERATING */
    {51u, 6u, 7u},  /* VCONFIG_KIND_SUN_ROOF_CONTROLLER */
    {51u, 4u, 5u},  /* VCONFIG_KIND_DYNAMIC_STEERING_TORQUE */
    {51u, 2u, 3u},  /* VCONFIG_KIND_ENGINE__MAIN__WATER_PUMP */
    {51u, 0u, 1u},  /* VCONFIG_KIND_ACTIVE_AIR_INTAKE_GRILLE */
    {52u, 2u, 7u},  /* VCONFIG_KIND_DRIVING_MODE_2 */
    {52u, 0u, 1u},  /* VCONFIG_KIND_CLUSTER_TIME_DISPLAY */
    {53u, 5u, 7u},  /* VCONFIG_KIND_DRIVING_MODE_SIGNAL_SELECT */
    {53u, 2u, 4u},  /* VCONFIG_KIND_AUXILIARY_CONSOLE_CENTRAL_LCD_SCREEN */
    {53u, 0u, 1u},  /* VCONFIG_KIND_PEDAL_CONTROL */
    {54u, 4u, 7u},  /* VCONFIG_KIND_MP5_SCREEN */
    {54u, 0u, 3u},  /* VCONFIG_KIND_FRT_SEAT_BELT */
    {55u, 5u, 7u},  /* VCONFIG_KIND_FUEL_TANK_SYSTEM */
    {55u, 0u, 4u},  /* VCONFIG_KIND_AIR_BAG */
    {56u, 5u, 7u},  /* VCONFIG_KIND_DAMPER */
    {56u, 2u, 4u},  /* VCONFIG_KIND_ACTIVE_ACCESS_SYSTEM */
    {56u, 0u, 1u},  /* VCONFIG_KIND_BATTERY_SENSOR */
    {57u, 6u, 7u},  /* VCONFIG_KIND_QUICK_INNER_LOOP_MODE */
    {57u, 4u, 5u},  /* VCONFIG_KIND_MEMORY_OF_DRIVING_MODE */
    {57u, 0u, 3u},  /* VCONFIG_KIND_RR_1ST_SEAT_COOLING_RR_1ST_SEAT_MASSAGE */
    {58u, 6u, 7u},  /* VCONFIG_KIND_BIDIRECTION_CHARGING */
    {58u, 4u, 5u},  /* VCONFIG_KIND_INTELLIGENT_INTERACTIVE_ROBOT */
    {58u, 0u, 3u},  /* VCONFIG_KIND_E_AXLE */
    {59u, 6u, 7u},  /* VCONFIG_KIND_LED_ULTRA_LONG_ASSISTED_HIGH_BEAM */
    {59u, 4u, 5u},  /* VCONFIG_KIND_ADAPTIVE_FRONT_LIGHTING_SYSTEM */
    {59u, 2u, 3u},  /* VCONFIG_KIND_OFF_ROAD_EXPERT_MODE */
    {59u, 0u, 1u},  /* VCONFIG_KIND_BODY_DOMAIN_CONTROLLER */
    {60u, 5u, 7u},  /* VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION */
    {60u, 3u, 4u},  /* VCONFIG_KIND_RSCA_PROTECTION_FUNCTION */
    {60u, 2u, 2u},  /* VCONFIG_KIND_MOOD_LAMP_PARTITION */
    {60u, 0u, 1u},  /* VCONFIG_KIND_VEHICLE_TO_VEHICLE_CHARGE */
    {61u, 4u, 7u},  /* VCONFIG_KIND_DVR */
    {61u, 2u, 3u},  /* VCONFIG_KIND_NFC_FUNCTION */
    {61u, 0u, 1u},  /* VCONFIG_KIND_AUDIO_PARSING_MULTI_COLOR_RHYTHM_MOOD_LAMP */
    {62u, 0u, 7u},  /* VCONFIG_KIND_SPECIAL_COUNTRY(EXPORT) */
    {63u, 5u, 7u},  /* VCONFIG_KIND_OMNIVIEW_SYSTEM(VEHICLE_CONFIGURATION_INFORMATION) */
    {63u, 3u, 4u},  /* VCONFIG_KIND_DISCHARGE_CONNECTING_DEVICE */
    {63u, 1u, 2u},  /* VCONFIG_KIND_A_C_SYSTEM */
    {63u, 0u, 0u},  /* VCONFIG_KIND_MOBILE_BLUETOOTH_KEY_SYSTEM */
    {64u, 6u, 7u},  /* VCONFIG_KIND_INST_REFUELING_PORT_ORIENTATION_DISPLAY */
    {64u, 3u, 5u},  /* VCONFIG_KIND_RR_A_C */
    {64u, 2u, 2u},  /* VCONFIG_KIND_ACTIVE_HEAT_PRESERVATION_FUNCTION_OF_BATTERY_PACK */
    {64u, 0u, 1u},  /* VCONFIG_KIND_BATTERY_TEMPERATURE_KEEP_WITH_GUN */
    {65u, 6u, 7u},  /* VCONFIG_KIND_HUT_ETHERNET_PORT */
    {65u, 4u, 5u},  /* VCONFIG_KIND_REMOTE_VEHICLE_ENVIRONMENT_VIEW */
    {65u, 1u, 3u},  /* VCONFIG_KIND_AVM_CAMERA_PARAMETERS */
    {65u, 0u, 0u},  /* VCONFIG_KIND_IESS_FUNCTION */
    {66u, 5u, 7u},  /* VCONFIG_KIND_DMS_CAMERA_PARAMETERS */
    {66u, 2u, 4u},  /* VCONFIG_KIND_DVR_CAMERA_PARAMETERS */
    {66u, 0u, 1u},  /* VCONFIG_KIND_FR_WINDSHIELD_HEATING_NOOZLE */
    {67u, 5u, 7u},  /* VCONFIG_KIND_OMS_CAMERA_PARAMETERS */
    {67u, 2u, 4u},  /* VCONFIG_KIND_RVC_CAMERA_PARAMETERS */
    {67u, 0u, 1u},  /* VCONFIG_KIND_VSG_TYPE */
    {68u, 6u, 7u},  /* VCONFIG_KIND_DMS_TYPE */
    {68u, 4u, 5u},  /* VCONFIG_KIND_ACC_SENSOR_CONTROL_MODULE */
    {68u, 3u, 3u},  /* VCONFIG_KIND_A_C_COMFORTABLE__MODE */
    {68u, 1u, 2u},  /* VCONFIG_KIND_FRT_SEAT__HEATING_LEVEL_TYPE */
    {68u, 0u, 0u},  /* VCONFIG_KIND_DRIVER_SEAT_COOLING */
    {69u, 6u, 7u},  /* VCONFIG_KIND_RR_1ST_SEAT_HEATING_LEVEL_TYPE */
    {69u, 4u, 5u},  /* VCONFIG_KIND_RR_2ND_SEAT_HEATING */
    {69u, 2u, 3u},  /* VCONFIG_KIND_PASSENGER_SEAT_COOLING */
    {69u, 0u, 1u},  /* VCONFIG_KIND_DRIVER_SEAT_MASSAGE */
    {70u, 6u, 7u},  /* VCONFIG_KIND_SEAT_MASSAGE_SWITCH_TYPE */
    {70u, 4u, 5u},  /* VCONFIG_KIND_PASSENGER_SEAT_MASSAGE */
    {70u, 2u, 3u},  /* VCONFIG_KIND_PASSENGER_SEAT_MEMORY_ASSISTANT */
    {70u, 0u, 1u},  /* VCONFIG_KIND_RR_1ST_SEAT_MEMORY_FUNCTION */
    {71u, 5u, 7u},  /* VCONFIG_KIND_SEAT_MEMORY_TYPE */
    {71u, 3u, 4u},  /* VCONFIG_KIND_WAIST_SUPPORTER_SWITCH_TYPE */
    {71u, 0u, 2u},  /* VCONFIG_KIND_RR_1ST_L_SEAT_ADJUSTMENT */
    {72u, 4u, 7u},  /* VCONFIG_KIND_PASSENGER_SEAT */
    {72u, 2u, 3u},  /* VCONFIG_KIND_RR_1ST_SEAT__WAIST_SUPPORTER */
    {72u, 0u, 1u},  /* VCONFIG_KIND_RR_1ST_SEAT_ADJUSTMENT */
    {73u, 5u, 7u},  /* VCONFIG_KIND_RR_1ST_R_SEAT_ADJUSTMENT */
    {73u, 3u, 4u},  /* VCONFIG_KIND_RR_2ND_SEAT_BACK_ADJUSTMENT */
    {73u, 2u, 2u},  /* VCONFIG_KIND_DRIVER_SEAT_CUSHION_FLANK */
    {73u, 1u, 1u},  /* VCONFIG_KIND_RR_1ST_SEAT_FAST_SET */
    {73u, 0u, 0u},  /* VCONFIG_KIND_RR_1ST_SEAT_ONE_CLICK_RESET */
    {74u, 6u, 7u},  /* VCONFIG_KIND_RR_1ST_SEAT_BACK_ADJUSTMENT */
    {74u, 4u, 5u},  /* VCONFIG_KIND_LEG_SUPPORTER */
    {74u, 2u, 3u},  /* VCONFIG_KIND_RR_1ST_SEAT_LEG_SUPPORTER */
    {74u, 0u, 1u},  /* VCONFIG_KIND_RR_2ND_SEAT_LEG_SUPPORTER */
    {75u, 7u, 7u},  /* VCONFIG_KIND_INTEGRATED_CHILD_SEAT */
    {75u, 6u, 6u},  /* VCONFIG_KIND_AC_MAX_FAST_COOLING */
    {75u, 3u, 4u},  /* VCONFIG_KIND_DOOR_MODULE_TYPE */
    {75u, 0u, 2u},  /* VCONFIG_KIND_STRG_COLUMN */
    {76u, 6u, 7u},  /* VCONFIG_KIND_OSRVM_ADJ_SWITCH_TYPE */
    {76u, 4u, 5u},  /* VCONFIG_KIND_FRT_SEAT_HEAT_SWITCH_TYPE */
    {76u, 2u, 3u},  /* VCONFIG_KIND_FRT_SEAT__ADJ_SWITCH_TYPE */
    {76u, 0u, 1u},  /* VCONFIG_KIND_WHEEL_HEAT_SWITCH_TYPE */
    {77u, 6u, 7u},  /* VCONFIG_KIND_TAIL_GATE_SWITCH_TYPE */
    {77u, 4u, 5u},  /* VCONFIG_KIND_SUN_ROOF_SHADE_SWITCH_TYPE */
    {77u, 2u, 3u},  /* VCONFIG_KIND_OMS_TYPE */
    {77u, 0u, 1u},  /* VCONFIG_KIND_OSRVM_FOLD_VIRTUAL_SW_CONTROL */
    {78u, 4u, 7u},  /* VCONFIG_KIND_TRIM__LEVEL */
    {78u, 2u, 3u},  /* VCONFIG_KIND_HUT_1000BASE_ETHERNET_PORT */
    {78u, 0u, 1u},  /* VCONFIG_KIND_ESP_SWITCH_TYPE */
    {79u, 6u, 7u},  /* VCONFIG_KIND_ESS_SYSTEM */
    {79u, 4u, 5u},  /* VCONFIG_KIND_GNSS_MODULE_TYPE */
    {79u, 0u, 3u},  /* VCONFIG_KIND_FULL_AUTO__INTEGRATED_PARKING_PIXELS */
    {80u, 6u, 7u},  /* VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE */
    {80u, 4u, 5u},  /* VCONFIG_KIND_BLOCKING_PROMPT_TYPE */
    {80u, 2u, 3u},  /* VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER */
    {80u, 0u, 1u},  /* VCONFIG_KIND_TRAILER_SWAY_MITIGATION_FUNCTION */
    {81u, 4u, 7u},  /* VCONFIG_KIND_DRIVER_BELT */
    {81u, 0u, 3u},  /* VCONFIG_KIND_FRONT_PASSENGER_BELT */
    {82u, 6u, 7u},  /* VCONFIG_KIND_GAME_GEAR */
    {82u, 4u, 5u},  /* VCONFIG_KIND_RR_SLIDING_WINDOW */
    {82u, 2u, 3u},  /* VCONFIG_KIND_NAVIGATION_ON_HIGHWAYPILOT */
    {82u, 0u, 1u},  /* VCONFIG_KIND_2ND_ROW_SEAT_CENTRE_ARMREST */
    {83u, 6u, 7u},  /* VCONFIG_KIND_DECK_LAMP */
    {83u, 4u, 5u},  /* VCONFIG_KIND_CONSOLE_DOCK_PORT */
    {83u, 2u, 3u},  /* VCONFIG_KIND_3RD_ROW_SEAT_ARMREST_DOCK_PORT */
    {83u, 0u, 1u},  /* VCONFIG_KIND_PT_CAN_BUS_TYPE */
    {84u, 6u, 7u},  /* VCONFIG_KIND_AUXILIARY_FUEL_TANK */
    {84u, 4u, 5u},  /* VCONFIG_KIND_AMBIENT_LIGHT_CONTROL */
    {84u, 2u, 3u},  /* VCONFIG_KIND_ULTRAVIOLET_GERMICIDAL_LAMP */
    {84u, 0u, 1u},  /* VCONFIG_KIND_VEHICLE_TO_X */
    {85u, 0u, 7u},  /* VCONFIG_KIND_DRIVING_MODE_3 */
    {86u, 6u, 7u},  /* VCONFIG_KIND_OFF_ROAD_THERMAL_MANAGEMENT_MODE */
    {86u, 3u, 5u},  /* VCONFIG_KIND_FRT_SEAT__COOLING_LEVEL_TYPE */
    {86u, 0u, 2u},  /* VCONFIG_KIND_2ND_ROW_SEAT_COOLING_LEVEL_TYPE */
    {87u, 5u, 7u},  /* VCONFIG_KIND_SEAT_HEATING_AUTO_TURN_ON */
    {87u, 2u, 4u},  /* VCONFIG_KIND_SEAT_COOLING_AUTO_TURN_ON */
    {87u, 0u, 1u},  /* VCONFIG_KIND_WATER_DEPTH_DETECTION */
    {88u, 5u, 7u},  /* VCONFIG_KIND_SECONG_ROGHT_SEAT_MASSAGE_PATTERN */
    {88u, 2u, 4u},  /* VCONFIG_KIND_SECOND_LEFT_SEAT_MASSAGE_PATTERN */
    {88u, 0u, 1u},  /* VCONFIG_KIND_SPORTS_MODE_LIGHTING_PROMPT_S_REPEATER */
    {89u, 5u, 7u},  /* VCONFIG_KIND_SECOND_ROW__SEAT_MASSAGE_SWITCH_TYPE */
    {89u, 2u, 4u},  /* VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_PATTERN */
    {89u, 0u, 1u},  /* VCONFIG_KIND_2ND_ROW_SEAT_WELCOME_FUNCTION */
    {90u, 5u, 7u},  /* VCONFIG_KIND_DRIVER_SEAT_MASSAGE_PATTERN */
    {90u, 2u, 4u},  /* VCONFIG_KIND_SPARE_TIRE_MTG */
    {90u, 0u, 1u},  /* VCONFIG_KIND_CHILD_PRESENCE_DETECTION */
    {91u, 5u, 7u},  /* VCONFIG_KIND_LIGHTING_SHOW_FUNCTION */
    {91u, 3u, 4u},  /* VCONFIG_KIND_LIGHTING_EXHIBITION_HALL_MODE */
    {91u, 0u, 2u},  /* VCONFIG_KIND_IBOOSTER(CONFIG) */
    {92u, 6u, 7u},  /* VCONFIG_KIND_CLOSE_TO_LIGHTING_FUNCTION */
    {92u, 4u, 5u},  /* VCONFIG_KIND_CLUTCH_OVERHEAT_REMINDER_FUNCTION */
    {92u, 2u, 3u},  /* VCONFIG_KIND_ENGINE_OIL_TEMPERATURE_DISPLAY */
    {92u, 0u, 1u},  /* VCONFIG_KIND_ENGINE_OIL_PRESSURE_ALARM_AND_DISPLAY */
    {93u, 3u, 7u},  /* VCONFIG_KIND_DRIVING_MODE_OPTIONAL */
    {93u, 0u, 2u},  /* VCONFIG_KIND_DECK_RR_PLATE */
    {94u, 4u, 7u},  /* VCONFIG_KIND_AVP_PIXELS */
    {94u, 0u, 3u},  /* VCONFIG_KIND_DRIVING_MODE_MASTER_CONTROL */
    {95u, 5u, 7u},  /* VCONFIG_KIND_CENTER_CONTROL_SW_MOUDLE */
    {95u, 3u, 4u},  /* VCONFIG_KIND_SREERING_MODE_OF_EXPERT */
    {95u, 0u, 2u},  /* VCONFIG_KIND_AVH_SWITCH_TYPE */
    {96u, 5u, 7u},  /* VCONFIG_KIND_DRIVER_SEAT_MASSAGE_STRENGTH_LEVEL */
    {96u, 2u, 4u},  /* VCONFIG_KIND_PASSENGER_SEAT_MASSAGE_STRENGTH_LEVEL */
    {96u, 0u, 1u},  /* VCONFIG_KIND_GESTURE_CALL */
    {97u, 5u, 7u},  /* VCONFIG_KIND_EPB_SWITCH_TYPE */
    {97u, 2u, 4u},  /* VCONFIG_KIND_HDC_SWITCH_TYPE */
    {97u, 0u, 1u},  /* VCONFIG_KIND_BLE_ACCOUNT_LOGIN */
    {98u, 6u, 7u},  /* VCONFIG_KIND_SPEED__SENSING_SUNROOF_SWITCH */
    {98u, 3u, 5u},  /* VCONFIG_KIND_OIL_LEVEL_DISPLAY_AND_ALARM */
    {98u, 0u, 2u},  /* VCONFIG_KIND_FRT_STABILIZER */
    {99u, 5u, 7u},  /* VCONFIG_KIND_3RD_ROW_SEAT_MASSAGE */
    {99u, 2u, 4u},  /* VCONFIG_KIND_3RD_ROW_SEAT_VENTILATION */
    {99u, 0u, 1u},  /* VCONFIG_KIND_VIRTUAL_SW_FOR_FRONT_FOG_LAMP */
    {100u, 6u, 7u},  /* VCONFIG_KIND_VIRTUAL_SW_FOR_REAR_FOG_LAMP */
    {100u, 4u, 5u},  /* VCONFIG_KIND_HEADLAMP_VIRTUAL_SW */
    {100u, 2u, 3u},  /* VCONFIG_KIND_VIRTUAL_SW_FOR_STRG_WHL_HANDLE_SHIFT */
    {100u, 0u, 1u},  /* VCONFIG_KIND_TAILGATE_ADJ_VIRTUAL_SW */
    {101u, 6u, 7u},  /* VCONFIG_KIND_WIPER_INTERMITTENT_LEVEL_VIRTUAL_SW */
    {101u, 4u, 5u},  /* VCONFIG_KIND_FRONT_PASSENGER_SEAT_WELCOME_FUNCTION */
    {101u, 0u, 3u},  /* VCONFIG_KIND_INSTRUMENT_STYLE */
    {102u, 5u, 7u},  /* VCONFIG_KIND_FRONT_PASSENGER_SCREEN */
    {102u, 2u, 4u},  /* VCONFIG_KIND_AC_UVC_STERILIZATION_LAMP */
    {102u, 0u, 1u},  /* VCONFIG_KIND_INTEGRATED_BRAKE_CONTROL_SYSTEM */
    {103u, 5u, 7u},  /* VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER */
    {103u, 0u, 4u},  /* VCONFIG_KIND_SUSPENSION_MODE(CONFIGURATION_INFORMATION) */
    {104u, 6u, 7u},  /* VCONFIG_KIND_WATER_TEMPERATURE_DISPLAY_OF_INSTRUMENT */
    {104u, 4u, 5u},  /* VCONFIG_KIND_HIGHWAY_PILOT(HWP) */
    {104u, 2u, 3u},  /* VCONFIG_KIND_AUTO_STOP_AT_ROADSIDE */
    {104u, 0u, 1u},  /* VCONFIG_KIND_SUPER_I_SPACE */
    {105u, 5u, 7u},  /* VCONFIG_KIND_CHILD_LOCK */
    {105u, 3u, 4u},  /* VCONFIG_KIND_REMOTE_PARKING */
    {105u, 0u, 2u},  /* VCONFIG_KIND_MUSIC__LIGHT_SHOW */
    {106u, 6u, 7u},  /* VCONFIG_KIND_STEERING_MODE */
    {106u, 3u, 5u},  /* VCONFIG_KIND_LOW_BEAM_HEIGHT_ADJ_VIRTUAL_SW */
    {106u, 0u, 2u},  /* VCONFIG_KIND_REAR_TRUNK_SPOILER */
    {107u, 6u, 7u},  /* VCONFIG_KIND_A_C_SELF_DRYING */
    {107u, 4u, 5u},  /* VCONFIG_KIND_A_C_TURNS_ON_AUTOMATICALLY */
    {107u, 2u, 3u},  /* VCONFIG_KIND_SHORT_TIME_RESIDENCE */
    {107u, 0u, 1u},  /* VCONFIG_KIND_DANGER_ONE_CLICK_RESCUE */
    {108u, 6u, 7u},  /* VCONFIG_KIND_ISS_LIGHT_SHOW_SWITCH */
    {108u, 4u, 5u},  /* VCONFIG_KIND_GAME_CENTER_FUNCTION */
    {108u, 0u, 3u},  /* VCONFIG_KIND_SUSPENSION_SPRING_TYPE */
    {109u, 6u, 7u},  /* VCONFIG_KIND_RAINY_AND_SNOWY_DAY_MODE */
    {109u, 4u, 5u},  /* VCONFIG_KIND_CAR_WASH_MODE */
    {109u, 2u, 3u},  /* VCONFIG_KIND_FRONT_HEADREST_NECK_BRACE */
    {109u, 0u, 1u},  /* VCONFIG_KIND_AUTO_DOOR_LOCK */
    {110u, 6u, 7u},  /* VCONFIG_KIND_WARM_MEN_MODE */
    {110u, 4u, 5u},  /* VCONFIG_KIND_CHILD_MODE */
    {110u, 2u, 3u},  /* VCONFIG_KIND_NAVIGATION_SLOWDOWN */
    {110u, 0u, 1u},  /* VCONFIG_KIND_WIRELESS_POWER_TRANSFER_SYSTEM */
    {111u, 6u, 7u},  /* VCONFIG_KIND_CHARGER_OPENING_COVER */
    {111u, 4u, 5u},  /* VCONFIG_KIND_VEHICLE_TO_LOAD_DISCHARGE */
    {111u, 2u, 3u},  /* VCONFIG_KIND_AI_INTERACTIVE_LIGHT */
    {111u, 0u, 1u},  /* VCONFIG_KIND_FRONT_WINDSHIELD_HEATING */
    {112u, 6u, 7u},  /* VCONFIG_KIND_DRIVER_SEAT_RHYTHM_FUNCTION */
    {112u, 4u, 5u},  /* VCONFIG_KIND_FRONT_PASSEN_SEAT_RHYTHM_FUNCTION */
    {112u, 2u, 3u},  /* VCONFIG_KIND_HIGH_LOW_AUTO__SWITCHING_BEAM_VIRTUAL_SW */
    {112u, 0u, 1u},  /* VCONFIG_KIND_TRAFFIC_LIGHT_AND_STOP_SIGN_CONTROL */
    {113u, 5u, 7u},  /* VCONFIG_KIND_CRUISE_OPERATION_MODE */
    {113u, 3u, 4u},  /* VCONFIG_KIND_SUPER_I_SPACE_KTV_MODE */
    {113u, 0u, 2u},  /* VCONFIG_KIND_DRIVER_HEADREST_SPEAKER */
    {114u, 6u, 7u},  /* VCONFIG_KIND_REFESHING_MODE */
    {114u, 4u, 5u},  /* VCONFIG_KIND_BRAKING_MODE */
    {114u, 2u, 3u},  /* VCONFIG_KIND_EXCLUSIVE_BUSINESS_MODE */
    {114u, 0u, 1u},  /* VCONFIG_KIND_STEERING_WHEEL_HEATING_AUTO_TURN_ON */
    {115u, 6u, 7u},  /* VCONFIG_KIND_IDC_L2 */
    {115u, 4u, 5u},  /* VCONFIG_KIND_IDC_L3 */
    {115u, 2u, 3u},  /* VCONFIG_KIND_VEHICLE_OTA_MODE_FOR_FOTA */
    {115u, 0u, 1u},  /* VCONFIG_KIND_2ND_ROW_SEAT_HEAT_SWITCH_TYPE */
    {116u, 5u, 7u},  /* VCONFIG_KIND_PASS_SEAT_MEMORY_TYPE */
    {116u, 2u, 4u},  /* VCONFIG_KIND_ELECTRONIC_TOLL_COLLECTION(ETC) */
    {116u, 0u, 1u},  /* VCONFIG_KIND_DRIVE_CURTAIN */
    {117u, 5u, 7u},  /* VCONFIG_KIND_DRIVER_SEAT_HEADREST_ADJUSTMENT */
    {117u, 2u, 4u},  /* VCONFIG_KIND_FRONT_PASSENGER_SEAT_HEADREST_ADJUSTMENT */
    {117u, 0u, 1u},  /* VCONFIG_KIND_TAB_SWITCH_TYPE */
    {118u, 5u, 7u},  /* VCONFIG_KIND_2ND_ROW_SEAT_HEADREST_ADJUSTMENT */
    {118u, 2u, 4u},  /* VCONFIG_KIND_CCO_TCC_SWITCH_TYPE */
    {118u, 0u, 1u},  /* VCONFIG_KIND_WATER_THERMOMETER_DISPLAY_PARAMETERS */
    {119u, 6u, 7u},  /* VCONFIG_KIND_SENTINEL_MODE */
    {119u, 4u, 5u},  /* VCONFIG_KIND_BLUETOOTH_ADAPTER */
    {119u, 2u, 3u},  /* VCONFIG_KIND_REAR_WHEEL_STEERING */
    {119u, 0u, 1u},  /* VCONFIG_KIND_WASHING_LIQUID_LEVEL_ALARM */
    {120u, 6u, 7u},  /* VCONFIG_KIND_AIR_SUSPENSION_JACK_MODE */
    {120u, 4u, 5u},  /* VCONFIG_KIND_AIR_SUSPENSION_TRAILER_MODE */
    {120u, 2u, 3u},  /* VCONFIG_KIND_AIR_SUSPENSION_AUTO_EASY_ACCESS_MODE */
    {120u, 0u, 1u},  /* VCONFIG_KIND_AIR_SUSPENSION_FOOT_KICK_LOADING_MODE */
    {121u, 6u, 7u},  /* VCONFIG_KIND_ULTRASONIC_ANTI_THEFT_IN_VEHCLE */
    {121u, 3u, 5u},  /* VCONFIG_KIND_EMERGENCY_CALL_SYSTEM(E_CALL) */
    {121u, 0u, 2u},  /* VCONFIG_KIND_STARRY_SKY_CEILING */
    {122u, 6u, 7u},  /* VCONFIG_KIND_COMFORTABLE_STOP */
    {122u, 4u, 5u},  /* VCONFIG_KIND_OMNIVIEW_AUTO_TURN_ON_AT_LOW_SPEED */
    {122u, 2u, 3u},  /* VCONFIG_KIND_CARE_MODE */
    {122u, 0u, 1u},  /* VCONFIG_KIND_SMOKING_MODE */
    {123u, 6u, 7u},  /* VCONFIG_KIND_STBS_AC_BUTTON */
    {123u, 4u, 5u},  /* VCONFIG_KIND_FRONT_BACK_VOICE_CALL */
    {123u, 2u, 3u},  /* VCONFIG_KIND_AC_NATURAL_WIND */
    {123u, 0u, 1u},  /* VCONFIG_KIND_AUTOMATIC_POWER_DOWN_CONTROL */
    {124u, 5u, 7u},  /* VCONFIG_KIND_SECOND_ROW_VOICE_BUTTON */
    {124u, 2u, 4u},  /* VCONFIG_KIND_THIRD_ROW_VOICE_BUTTON */
    {124u, 0u, 1u},  /* VCONFIG_KIND_STEERING_WHEEL_CORRECTION_ASSISTANCE */
    {125u, 5u, 7u},  /* VCONFIG_KIND_BARREL_INSTRUMENT_TYPE */
    {125u, 2u, 4u},  /* VCONFIG_KIND_CCU */
    {125u, 0u, 1u},  /* VCONFIG_KIND_UNLOCKING_LOCKING_PROMPT_SOUND */
    {126u, 5u, 7u},  /* VCONFIG_KIND_FRONT_AIR_OUTLET */
    {126u, 2u, 4u},  /* VCONFIG_KIND_CHARGER_OPENING_COVER(ELECTRIC)_SWITCH_TYPE */
    {126u, 0u, 1u},  /* VCONFIG_KIND_DOOR_E_UNLOCK */
    {127u, 5u, 7u},  /* VCONFIG_KIND_DRIVE_TYPE */
    {127u, 3u, 4u},  /* VCONFIG_KIND_REAR_WHEEL_LARGE_ANGLE_STEERING */
    {127u, 0u, 2u},  /* VCONFIG_KIND_MOBILE_DATA_CENTER(MDC) */
    {128u, 5u, 7u},  /* VCONFIG_KIND_STEERING_WHEEL_BUTTON */
    {128u, 3u, 4u},  /* VCONFIG_KIND_FRONT_RADAR_AUTO_TURN_ON */
    {128u, 0u, 2u},  /* VCONFIG_KIND_REAR_VIDEO */
    {129u, 6u, 7u},  /* VCONFIG_KIND_LOW_SPEED_AUTO_EMERGENCY_BRAKE(L_AEB) */
    {129u, 4u, 5u},  /* VCONFIG_KIND_MEDITATION_MODE */
    {129u, 2u, 3u},  /* VCONFIG_KIND_SECOND_ROW_AIR_SPEED_CONTROL_SWITCH */
    {129u, 0u, 1u},  /* VCONFIG_KIND_SECOND_ROW_A_C_LOCK_CONTROL_SWITCH */
    {130u, 4u, 7u},  /* VCONFIG_KIND_FIRST_ROW_TEMPERATURE_CONTROL_SWITCH */
    {130u, 0u, 3u},  /* VCONFIG_KIND_SECOND_ROW_TEMPERATURE_CONTROL_SWITCH */
    {131u, 5u, 7u},  /* VCONFIG_KIND_FIRST_ROW_AIR_MODE_CONTROL_SWITCH */
    {131u, 2u, 4u},  /* VCONFIG_KIND_SECOND_ROW_AIR_MODE_CONTROL_SWITCH */
    {131u, 0u, 1u},  /* VCONFIG_KIND_SECOND_ROW_A_C_ON_OFF_VIRTUAL_SW */
    {132u, 6u, 7u},  /* VCONFIG_KIND_OUTSIDE_VOICES */
    {132u, 3u, 5u},  /* VCONFIG_KIND_AEB_SWITCH_TYPE */
    {132u, 0u, 2u},  /* VCONFIG_KIND_CRYSTAL_CONSOLE_PANEL */
    {133u, 6u, 7u},  /* VCONFIG_KIND_WINDOW_SHORT_LIFT_DROP_FUNCTION */
    {133u, 3u, 5u},  /* VCONFIG_KIND_ELECTRIC_CHILDREN_LOCK_VIRTUAL_SW */
    {133u, 0u, 2u},  /* VCONFIG_KIND_DAB_BROADCAST */
    {134u, 6u, 7u},  /* VCONFIG_KIND_HIGH_LOW_PRESSURE_MODE_FOR_FOTA */
    {134u, 4u, 5u},  /* VCONFIG_KIND_WADE_MODE */
    {134u, 0u, 3u},  /* VCONFIG_KIND_CRYSTAL_PANEL_VIRTUAL_SWITCH_LINK_WPC */
    {135u, 5u, 7u},  /* VCONFIG_KIND_SECOND_RIGHT_SEAT_MASSAGE_STRENGTH_LEVEL */
    {135u, 2u, 4u},  /* VCONFIG_KIND_EPB_TYPE */
    {135u, 0u, 1u},  /* VCONFIG_KIND_WADE_SW_TYPE */
    {136u, 4u, 7u},  /* VCONFIG_KIND_DRIVER_DOOR_HANDLE */
    {136u, 2u, 3u},  /* VCONFIG_KIND_INTELLIGENT_CURVE_SW_TYPE */
    {137u, 4u, 7u},  /* VCONFIG_KIND_CLOSE_TO_LIGHTING_SHOW_VIRTUAL_SW */
    {137u, 0u, 3u},  /* VCONFIG_KIND_CLOSE_TO_LIGHTING_SHOW__LINK_SOUND_EFFECT_VIRTUAL_SW */
    {138u, 4u, 7u},  /* VCONFIG_KIND_LOCKING_LIGHT_SHOW_VIRTUAL_SW */
    {138u, 0u, 3u},  /* VCONFIG_KIND_UNLOCK_LIGHT_SHOW_VIRTUAL_SW */
};


#if (DIAG_USE_DCMEX != TRUE)

Std_ReturnType(*EventAavailableFunctionTable[DTC_SWITCH_NUMBER])(boolean result) = 
{
    Rte_Call_Vconfig_EventAvailable_0xA13011_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x927312_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA13111_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x927412_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x908B87_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x908887_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x908A87_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x908687_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x908587_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x908487_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30017_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30116_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30008_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30149_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30249_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30349_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30449_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30549_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30649_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30093_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA30157_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xA50157_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910011_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910012_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910013_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910087_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910111_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910112_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910113_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910187_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910287_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910387_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910487_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC10087_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC12287_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC10187_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC24187_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC24287_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD10B87_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD02687_SetEventAvailable,
#if (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_P05) || (defined GWM_V35_PROJECT_TYPE_A07)
    Rte_Call_Vconfig_EventAvailable_0xC14087_SetEventAvailable,
#else
    Rte_Call_Vconfig_EventAvailable_0xD00287_SetEventAvailable,
#endif
    Rte_Call_Vconfig_EventAvailable_0xC16487_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC13187_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC12887_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC20887_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC19987_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC20087_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC24687_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC24787_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC24387_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC2B387_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC19887_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC12787_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC29387_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC11187_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC1BB87_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD10887_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD10987_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD00487_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC10487_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC14387_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD00987_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC23087_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC15C87_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC11587_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD01587_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC14187_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD02987_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC11487_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC15887_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC23387_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC2B587_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xC25E87_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910511_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910512_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910513_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910611_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910612_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910613_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910711_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910712_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910713_SetEventAvailable,
#if (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_P05)
    Rte_Call_Vconfig_EventAvailable_0x9A0811_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0812_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0813_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0819_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910811_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910812_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910813_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x910887_SetEventAvailable,
#else
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
#endif
#if (defined GWM_V35_PROJECT_TYPE_B02) || (defined GWM_V35_PROJECT_TYPE_A07) || (defined GWM_V35_PROJECT_TYPE_B03) || (defined GWM_V35_PROJECT_TYPE_P03) || (defined GWM_V35_PROJECT_TYPE_P05)
    Rte_Call_Vconfig_EventAvailable_0x9A0101_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0111_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0112_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0113_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A011E_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0125_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0201_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0211_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0212_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0213_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A021E_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0225_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0301_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0311_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0312_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0313_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A031E_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0325_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0401_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0411_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0412_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0413_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A041E_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0425_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0501_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0511_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0512_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0513_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A051E_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0525_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0601_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0611_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0612_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0613_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A061E_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0625_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0701_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0711_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0712_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0713_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A071E_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x9A0725_SetEventAvailable,
#else
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
#endif
#ifdef GWM_V35_PROJECT_TYPE_P05
    Rte_Call_Vconfig_EventAvailable_0x95F811_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x95F812_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x95F813_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0xD12387_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x93F511_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x93F512_SetEventAvailable,
    Rte_Call_Vconfig_EventAvailable_0x93F513_SetEventAvailable
#else
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
#endif
};
#endif // (DIAG_USE_DCMEX != TRUE)

#define VCONFIG_STOP_SEC_CONST_UNSPECIFIED
#include "VConfig_MemMap.h"

#define VCONFIG_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "VConfig_MemMap.h"

static VConfig_KindType vconfig_kindDatas[VCONFIG_KINDBUFSIZE];
static uint8 vconfig_rawData[VCONFIG_RAW_DATA_SIZE];
static uint8 vconfig_rawDataBackup[VCONFIG_RAW_DATA_SIZE];

#define VCONFIG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "VConfig_MemMap.h"

#define VCONFIG_START_SEC_CONST_UNSPECIFIED
#include "VConfig_MemMap.h"

VConfig_ConfigType vconfig_config =
{
    VCONFIG_KIND_NUMBER,
    vconfig_kindConfigs,
    vconfig_kindDatas,
    VCONFIG_RAW_DATA_SIZE,
    vconfig_rawData,
    vconfig_rawDataBackup
};

#define VCONFIG_STOP_SEC_CONST_UNSPECIFIED
#include "VConfig_MemMap.h"
