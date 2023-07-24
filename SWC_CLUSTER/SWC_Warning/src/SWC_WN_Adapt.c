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

/***********************************************************************************************************
**
**  Name:               SWC_WN_Adapt.c
**
**  Description:        
**
**  Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "VConfig.h"
#include "string.h"
#include "Rte_Common_Normal.h"
#include "IoHwAb_Cfg_RI.h"
#include "CConfig_Cfg.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_WN_Config.h"
#include "SWC_WN_Interface.h"
#include "SWC_WN_MemMap.h"
#include "SWC_WN_Adapt.h"

#ifdef GWM_V35_PROJECT_TYPE_B02
#define GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03
#define GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03
#define GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05
#define GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07
#define GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01
#define GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02
#define GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03
#define GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02
#define GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01
#define GWM_V35_PROJECT_TYPE_P01_WN

#else
#endif

#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#include "ComEx_Cfg.h"

#else
#endif
/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/


/**********************************************************************************************************
*                               Private Member                                                            *
**********************************************************************************************************/
#define SWC_WN_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_WN_MemMap.h"
static boolean m_ReadVehCfgFlag = FALSE;
static uint8 WN_u8SignalData = 0;
static uint16 WN_u16SignalData = 0;
/**********************************************************************************************************
*                               Local Configuration                                                       *
**********************************************************************************************************/
static uint16 LowOilPressure_telltales_DelayTime = 0; //uint: 0.1s
static uint16 BrakeFault_DelayTime = 0;               //uint: ms
static uint16 AccelBrakeWrnDelayTime = 0;             //uint: 0.1s
/**********************************************************************************************************
*                               Vehicle Configuration                                                     *
**********************************************************************************************************/
//Byte3 Bit7-bit0
static uint8 m_VehCfgTransmission = 0;
//Byte42 Bit7-bit3
static uint8 m_VehCfgEngCtrolUnit = 0;
//Byte28 Bit7-bit4
static uint8 m_VehCfgCruiseControl = 0;
//Byte2 Bit7-bit4
static uint8 m_VehCfgFuel = 0;
//Byte30 Bit7-bit4
static uint8 m_VehCfgElecPosition = 0;
//Byte4 Bit1-bit0
static uint8 m_VehCfgIdleStopAndGo = 0;
//Byte37 Bit3-bit2
static uint8 m_VehCfgElecEnManagement = 0;
//Byte31 Bit2-bit0
static uint8 m_VehCfgUpDownHill = 0;
//Byte33 Bit7-bit6
static uint8 m_VehCfgAVH = 0;
//Byte26 Bit7-bit5
static uint8 m_VehCfgParkingBrake = 0;
//Byte44 Bit1-bit0
static uint8 m_VehCfgTab = 0;
//Byte32 Bit4-bit2
static uint8 m_VehCfgSpeedOmeter = 0;
//Byte38 Bit5-bit4
static uint8 m_VehCfgSmartJuncBox = 0;
//Byte4 Bit7-bit6
static uint8 m_VehCfgDriveHandleType = 0;
//Byte59 Bit1-bit0
static uint8 m_VehCfgBodyDomainCtrl = 0;
//Byte4 Bit5-bit2
static uint8 m_VehCfgRegional = 0xFF;
//Byte11 Bit2-bit0
static uint8 m_VehCfgStartSystem = 0;
//Byte32 Bit1-bit0
static uint8 m_VehCfgParkingLamp = 0;
//Byte36 Bit5-bit4
static uint8 m_VehCfgAutoLightSys = 0;
//Byte36 Bit3-bit0
static uint8 m_VehCfgFrtWiperSys = 0;
//Byte11 Bit7-bit6
static uint8 m_VehCfgDrowWarnSys = 0;
//Byte39 Bit4-bit3
static uint8 m_VehCfgTpms = 0;
//Byte41 Bit3-bit2
static uint8 m_VehCfgEPark = 0;
//Byte40 Bit4-bit3
static uint8 m_VehCfgElecSteColumnLock = 0;
//Byte32 Bit7-bit5
static uint8 m_VehCfgSeatBelt = 0;
//Byte38 Bit7-bit6
static uint8 m_VehCfgSpeedReverse = 0;
//Byte49 Bit5-bit4
static uint8 m_VehCfgShiftedUnlockKey = 0;
//Byte30 Bit3-bit0
static uint8 m_VehCfgTransCase = 0;
//Byte25 Bit3-bit2
static uint8 m_VehCfgORCruiseControl = 0;
//Byte59 Bit3-bit2
static uint8 m_VehCfgOffRoadExpertMode = 0;
//Byte10 Bit3-bit0
static uint8 m_VehCfgFCWAEB = 0;
//Byte45 Bit7-bit5
static uint8 m_VehCfgHighwayAssist = 0;
//Byte2 Bit3-bit0
static uint8 m_VehCfgTrafficSign = 0;
//Byte53 Bit1-bit0
static uint8 m_VehCfgPedalControlSts = 0;
//Byte43 Bit7-bit4
static uint8 m_VehCfgQuickStart = 0;
//Byte43 Bit1-bit0
static uint8 m_VehCfgOusideTemp = 0;
//Byte37 Bit7-bit4
static uint8 m_VehCfgHeadLighting = 0;
//Byte59 Bit7-bit6
static uint8 m_VehCfgLongAssHiBeam = 0;
//Byte9 Bit3-bit0
static uint8 m_VehCfgHeadLampAdjust = 0;
//Byte33 Bit3-bit0
static uint8 m_VehCfgHeadLampBeamSys = 0;
//Byte60 Bit7-bit5
static uint8 m_VehCfgHeadLampCtrlFunc = 0;
//Byte28 Bit3-bit0
static uint8 m_VehCfgLimitedSlip = 0;
//Byte42 Bit2-bit0
static uint8 m_VehCfgWireless = 0;
//Byte51 Bit3-bit2
static uint8 m_VehCfgEngWaterPump = 0;
//Byte60 Bit1-bit0
static uint8 m_VehCfgV2VCharge = 0;
//Byte63 Bit4-bit3
static uint8 m_VehCfgDisVChargeConnect = 0;
//Byte51 Bit1-bit0
static uint8 m_VehCfgAirGrille = 0;
//Byte16 Bit1-bit0
static uint8 m_VehCfgVoiceFacial = 0;
//Byte68 Bit7-bit6
static uint8 m_VehCfgDMSType = 0;
//Byte25 Bit7-bit4
static uint8 m_VehCfgDrvModeOptionnal = 0;
//Byte52 Bit7-bit2
static uint8 m_VehCfgDrvMode2 = 0;
//Byte54 Bit3-bit0
static uint8 m_VehCfgPPMI = 0;
//Byte24 Bit3-bit0
static uint8 m_VehCfgNetService = 0;
//Byte46 Bit7-bit5
static uint8 m_VehCfgAEBJunctionAssist = 0;
//Byte45 Bit4-bit2
static uint8 m_VehCfgFCWB = 0;
//Byte17 Bit1-bit0
static uint8 m_VehCfgRearCollision = 0;
//Byte14 Bit7-bit6
static uint8 m_VehCfgLaneChangeAssist = 0;
//Byte20 Bit7-bit5
static uint8 m_VehCfgPASCTA = 0;
//Byte12 Bit3-bit0
static uint8 m_VehCfgLDWLKA = 0;
//Byte45 Bit1-bit0
static uint8 m_VehCfgEvasiveSteering = 0;
//Byte46 Bit4-bit3
static uint8 m_VehCfgEmergencySteering = 0;
//Byte12 Bit3-bit0
static uint8 m_VehCfgARHUD = 0;
//Byte55 Bit7-bit5
static uint8 m_VehCfgFuelTankSys = 0;
//Byte56 Bit7-bit5
static uint8 m_VehCfgDamper = 0;
//Byte31 Bit7-bit3
static uint8 m_VehCfgEMissionLevel = 0;
//Byte84 Bit3-bit2
static uint8 m_VehCfgUltravioletLamp = 0;
//Byte83 Bit1-bit0
static uint8 m_VehCfgPTCanType = 0;
//Byte80 Bit7-bit6
static uint8 m_VehCfgCentralModule = 0;
//Byte84 Bit7-bit6
static uint8 m_VehCfgAuxFuel = 0;
//Byte25 Bit1-bit0
static uint8 m_VehCfgSteeringSys = 0;
//Byte85 Bit7-bit4
static uint8 m_VehCfgDrvMode3 = 0;
//Byte26 Bit4-bit0
static uint8 m_VehCfgABS_EBD = 0;
//Byte80 Bit1-bit0
static uint8 m_VehCfgTSMFunc = 0;
//Byte59 Bit5-bit4
static uint8 m_VehCfgAFS = 0;
//Byte80 Bit3-bit2
static uint8 m_VehCfgFrontWheelBack = 0;
//Byte81 Bit7-bit4
static uint8 m_VehCfgDriverBelt = 0;
//Byte82 Bit3-bit2
static uint8 m_VehCfgNOH = 0;
//Byte92 Bit1-bit0
static uint8 m_VehCfgLowOil = 0;
//Byte84 Bit1-bit0 
static uint8 m_VehCfgV2X = 0;
//Byte92 Bit5-bit4
static uint8 m_VehCfgClutOvrHeatd = 0;
//Byte86 Bit7-bit6
static uint8 m_VehCfgOffroadThm = 0;
//Byte41 Bit7-bit4
static uint8 m_VehCfgRainShed = 0;
//Byte98 Bit5-bit3
static uint8 m_VehCfgOilLevel = 0;
//Byte90 Bit1-bit0
static uint8 m_VehCfgTCY = 0;
//Byte104 Bit3-Bit2
static uint8 m_VehCfgTFV = 0;
//Byte104 Bit3-Bit2
static uint8 m_VehCfgKAT = 0;
//Byte103 Bit7-Bit5
static uint8 m_VehCfgTFC = 0;
//Byte110 Bit3-Bit2
static uint8 m_VehCfgVDH = 0;
//Byte113 Bit7-Bit5
static uint8 m_VehCfgCBW = 0;
//Byte108 bit3-Bit0
static uint8 m_VehCfgGAC = 0;
//Byte98 bit2-Bit0
static uint8 m_VehCfgGAG = 0;
//Byte121 bit5-Bit3
static uint8 m_VehCfgE_Call = 0;
//Byte119 Bit1-Bit0
static uint8 m_VehCfgWashingLiquidLevelAlarm = 0;
//Byte122 Bit7-Bit6
static uint8 m_VehCfgComfortableStop = 0;
//Byte123 Bit1-Bit0
static uint8 m_VehCfgAutomaticPowerDownControl = 0;



#define SWC_WN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_WN_MemMap.h"

#define SWC_WN_START_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_WN_MemMap.h"
//Byte93 Bit2-Bit0
static uint8 m_VehCfgTrunkBoard = 0;
//Byte30 Bit3-Bit0
static uint8 m_VehCfgEAE = 0;
//Byte111 Bit7-bit6
static uint8 m_VehCfgChargingFlap = 0;


#define SWC_WN_STOP_SEC_GLOBALB_VAR_UNSPECIFIED
#include "SWC_WN_MemMap.h"
void WN_GetAllConfiguration(void)
{
    VconfigKind_Allbuffers All_VehCfg;
    CconfigKind_400Bytes LocalCfg;
    if (!m_ReadVehCfgFlag)
    {
        Rte_Read_Vconfig_GetKindBuffers_AllKinds(&All_VehCfg);
        if (All_VehCfg != NULL_PTR)
        {
            if (All_VehCfg[VCONFIG_KIND_INIT_FLAG] != 0)
            {
                m_ReadVehCfgFlag = TRUE;
                m_VehCfgTransmission = All_VehCfg[VCONFIG_KIND_TRANSMISSION];
                m_VehCfgEngCtrolUnit = All_VehCfg[VCONFIG_KIND_ENGINE_CONTROL_UNIT];
                m_VehCfgCruiseControl = All_VehCfg[VCONFIG_KIND_CRUISE_CONTROL];
                m_VehCfgFuel = All_VehCfg[VCONFIG_KIND_FUEL];
                m_VehCfgElecPosition = All_VehCfg[VCONFIG_KIND_ELECTROMOTOR_POSITION];
                m_VehCfgIdleStopAndGo = All_VehCfg[VCONFIG_KIND_IDLE_STOP_AND_GO];
                m_VehCfgElecEnManagement = All_VehCfg[VCONFIG_KIND_ELECTRICAL_ENERGY_MANAGEMENT];
                m_VehCfgUpDownHill = All_VehCfg[VCONFIG_KIND_UP_DOWN_HILL];
                m_VehCfgAVH = All_VehCfg[VCONFIG_KIND_AVH];
                m_VehCfgParkingBrake = All_VehCfg[VCONFIG_KIND_PARKING_BRAKE];
                m_VehCfgTab = All_VehCfg[VCONFIG_KIND_TAB];
                m_VehCfgSpeedOmeter = All_VehCfg[VCONFIG_KIND_SPEEDOMETER];
                m_VehCfgSmartJuncBox = All_VehCfg[VCONFIG_KIND_SMART_JUNCTION_BOX];
                m_VehCfgDriveHandleType = All_VehCfg[VCONFIG_KIND_DRIVE_HANDLE_TYPE];
                m_VehCfgBodyDomainCtrl = All_VehCfg[VCONFIG_KIND_BODY_DOMAIN_CONTROLLER];
                m_VehCfgRegional = All_VehCfg[VCONFIG_KIND_REGIONAL];
                m_VehCfgStartSystem = All_VehCfg[VCONFIG_KIND_STARTING_SYSTEM];
                m_VehCfgParkingLamp = All_VehCfg[VCONFIG_KIND_PARKING_LAMP];
                m_VehCfgAutoLightSys = All_VehCfg[VCONFIG_KIND_AUTO_LIGHT_SYSTEM];
                m_VehCfgFrtWiperSys = All_VehCfg[VCONFIG_KIND_FRONT_WIPER_SYSTEM];
                m_VehCfgDrowWarnSys = All_VehCfg[VCONFIG_KIND_DROWSINESS_WARNING_SYSTEM];
                m_VehCfgTpms = All_VehCfg[VCONFIG_KIND_TPMS];
                m_VehCfgEPark = All_VehCfg[VCONFIG_KIND_E_PARK];
                m_VehCfgElecSteColumnLock = All_VehCfg[VCONFIG_KIND_ELECTRONIC_STEERING_COLUMN_LOCK];
                m_VehCfgSeatBelt = All_VehCfg[VCONFIG_KIND_SEAT_BELT];
                m_VehCfgSpeedReverse = All_VehCfg[VCONFIG_KIND_SPEED_SENSING_REVERSE];
                m_VehCfgShiftedUnlockKey = All_VehCfg[VCONFIG_KIND_SHIFTED_UNLOCK_KEY];
                m_VehCfgTransCase = All_VehCfg[VCONFIG_KIND_TRANSFER_CASE];
                m_VehCfgORCruiseControl = All_VehCfg[VCONFIG_KIND_OFF_ROAD_CRUISE_CONTROL];
                m_VehCfgOffRoadExpertMode = All_VehCfg[VCONFIG_KIND_OFF_ROAD_EXPERT_MODE];
                m_VehCfgFCWAEB = All_VehCfg[VCONFIG_KIND_FORWARD_COLLISION_WARNING_AUTO_EMERGENCY_BRAKING];
                m_VehCfgHighwayAssist = All_VehCfg[VCONFIG_KIND_HIGHWAY_ASSIST];
                m_VehCfgTrafficSign = All_VehCfg[VCONFIG_KIND_TRAFFIC_SIGN_WARNING];
                m_VehCfgPedalControlSts = All_VehCfg[VCONFIG_KIND_PEDAL_CONTROL];
                m_VehCfgQuickStart = All_VehCfg[VCONFIG_KIND_QUICK_START];
                m_VehCfgOusideTemp = All_VehCfg[VCONFIG_KIND_OUSIDE_TEMPERATURE_DISPLAY];
                m_VehCfgHeadLighting = All_VehCfg[VCONFIG_KIND_HEAD_LAMP_LIGHTING];
                m_VehCfgLongAssHiBeam = All_VehCfg[VCONFIG_KIND_LED_ULTRA_LONG_ASSISTED_HIGH_BEAM];
                m_VehCfgHeadLampAdjust = All_VehCfg[VCONFIG_KIND_HEAD_LAMP_ADJUSTMENT];
                m_VehCfgHeadLampBeamSys = All_VehCfg[VCONFIG_KIND_HEAD_LAMP_BEAM_SYSTEM];
                m_VehCfgHeadLampCtrlFunc = All_VehCfg[VCONFIG_KIND_HEADLAMP_CONTROL_FUNCTION];
                m_VehCfgLimitedSlip = All_VehCfg[VCONFIG_KIND_LIMITED_SLIP_DIFFERRENTIAL];
                m_VehCfgWireless = All_VehCfg[VCONFIG_KIND_WIRELESS_POWER_CHARGER];
                m_VehCfgEngWaterPump = All_VehCfg[VCONFIG_KIND_ENGINE__MAIN__WATER_PUMP];
                m_VehCfgV2VCharge = All_VehCfg[VCONFIG_KIND_VEHICLE_TO_VEHICLE_CHARGE];
                m_VehCfgDisVChargeConnect = All_VehCfg[VCONFIG_KIND_DISCHARGE_CONNECTING_DEVICE];
                m_VehCfgAirGrille = All_VehCfg[VCONFIG_KIND_ACTIVE_AIR_INTAKE_GRILLE];
                m_VehCfgVoiceFacial = All_VehCfg[VCONFIG_KIND_VOICE_FACIAL_RECOGNITION];
                m_VehCfgDMSType = All_VehCfg[VCONFIG_KIND_DMS_TYPE];
                m_VehCfgDrvModeOptionnal = All_VehCfg[VCONFIG_KIND_DRIVING_MODE_OPTIONAL];
                m_VehCfgDrvMode2 = All_VehCfg[VCONFIG_KIND_DRIVING_MODE_2];
                m_VehCfgPPMI = All_VehCfg[VCONFIG_KIND_FRT_SEAT_BELT];
                m_VehCfgNetService = All_VehCfg[VCONFIG_KIND_INTELLIGENT_NETWORK_SERVICE];
                m_VehCfgAEBJunctionAssist = All_VehCfg[VCONFIG_KIND_AEB_JUNCTION_ASSIST];
                m_VehCfgFCWB = All_VehCfg[VCONFIG_KIND_FRONT_CROSS_WARNING_BREAK];
                m_VehCfgRearCollision = All_VehCfg[VCONFIG_KIND_REAR_COLLISION_WARNING];
                m_VehCfgLaneChangeAssist = All_VehCfg[VCONFIG_KIND_LANE_CHANGE_ASSIST];
                m_VehCfgPASCTA = All_VehCfg[VCONFIG_KIND_PAS_CTA];
                m_VehCfgLDWLKA = All_VehCfg[VCONFIG_KIND_LDW_LKA];
                m_VehCfgEvasiveSteering = All_VehCfg[VCONFIG_KIND_AUTO_EVASIVE_STEERING];
                m_VehCfgEmergencySteering = All_VehCfg[VCONFIG_KIND_EMERGENCY__STEERING_SUPPORT];
                m_VehCfgARHUD = All_VehCfg[VCONFIG_KIND_HEAD_UP_DISPLAY];
                m_VehCfgFuelTankSys = All_VehCfg[VCONFIG_KIND_FUEL_TANK_SYSTEM];
                m_VehCfgDamper = All_VehCfg[VCONFIG_KIND_DAMPER];
                m_VehCfgEMissionLevel = All_VehCfg[VCONFIG_KIND_EMISSION_LEVEL];
                m_VehCfgUltravioletLamp = All_VehCfg[VCONFIG_KIND_ULTRAVIOLET_GERMICIDAL_LAMP];
                m_VehCfgPTCanType = All_VehCfg[VCONFIG_KIND_PT_CAN_BUS_TYPE];
                m_VehCfgCentralModule = All_VehCfg[VCONFIG_KIND_CENTRAL_ELECTRONIC_MODULE];
                m_VehCfgAuxFuel = All_VehCfg[VCONFIG_KIND_AUXILIARY_FUEL_TANK];
                m_VehCfgSteeringSys = All_VehCfg[VCONFIG_KIND_STEERING_SYSTEM];
                m_VehCfgDrvMode3 = All_VehCfg[VCONFIG_KIND_DRIVING_MODE_3];
                m_VehCfgABS_EBD = All_VehCfg[VCONFIG_KIND_SERVICE_BRAKE];
                m_VehCfgTSMFunc = All_VehCfg[VCONFIG_KIND_TRAILER_SWAY_MITIGATION_FUNCTION];
                m_VehCfgAFS = All_VehCfg[VCONFIG_KIND_ADAPTIVE_FRONT_LIGHTING_SYSTEM];
				m_VehCfgFrontWheelBack = All_VehCfg[VCONFIG_KIND_STEERING_WHEEL_BACK_REMINDER];
                m_VehCfgNOH = All_VehCfg[VCONFIG_KIND_NAVIGATION_ON_HIGHWAYPILOT];
                m_VehCfgLowOil = All_VehCfg[VCONFIG_KIND_ENGINE_OIL_PRESSURE_ALARM_AND_DISPLAY];
                m_VehCfgV2X = All_VehCfg[VCONFIG_KIND_VEHICLE_TO_X];
                m_VehCfgClutOvrHeatd = All_VehCfg[VCONFIG_KIND_CLUTCH_OVERHEAT_REMINDER_FUNCTION];
                m_VehCfgDriverBelt = All_VehCfg[VCONFIG_KIND_DRIVER_BELT];
				m_VehCfgOffroadThm = All_VehCfg[VCONFIG_KIND_OFF_ROAD_THERMAL_MANAGEMENT_MODE];
				m_VehCfgRainShed = All_VehCfg[VCONFIG_KIND_DECK_COVER];
                m_VehCfgOilLevel = All_VehCfg[VCONFIG_KIND_OIL_LEVEL_DISPLAY_AND_ALARM];
                m_VehCfgTCY = All_VehCfg[VCONFIG_KIND_CHILD_PRESENCE_DETECTION];
                m_VehCfgTFV = All_VehCfg[VCONFIG_KIND_AUTO_STOP_AT_ROADSIDE];
				m_VehCfgTrunkBoard = All_VehCfg[VCONFIG_KIND_DECK_RR_PLATE];
				m_VehCfgKAT = All_VehCfg[VCONFIG_KIND_TRAILING_HOOK];
                m_VehCfgTFC = All_VehCfg[VCONFIG_KIND_INTELLIGENGT_DRIVING_CONTROLLER];
				m_VehCfgCBW = All_VehCfg[VCONFIG_KIND_CRUISE_OPERATION_MODE];
				m_VehCfgEAE = All_VehCfg[VCONFIG_KIND_TRANSFER_CASE];
				m_VehCfgChargingFlap = All_VehCfg[VCONFIG_KIND_CHARGER_OPENING_COVER];
                m_VehCfgVDH = All_VehCfg[VCONFIG_KIND_NAVIGATION_SLOWDOWN];
                m_VehCfgGAC = All_VehCfg[VCONFIG_KIND_SUSPENSION_SPRING_TYPE];
                m_VehCfgGAG = All_VehCfg[VCONFIG_KIND_FRT_STABILIZER];
				m_VehCfgE_Call = All_VehCfg[VCONFIG_KIND_EMERGENCY_CALL_SYSTEM_E_CALL];
                m_VehCfgWashingLiquidLevelAlarm = All_VehCfg[VCONFIG_KIND_WASHING_LIQUID_LEVEL_ALARM];
                m_VehCfgComfortableStop = All_VehCfg[VCONFIG_KIND_COMFORTABLE_STOP];
				m_VehCfgAutomaticPowerDownControl = All_VehCfg[VCONFIG_KIND_AUTOMATIC_POWER_DOWN_CONTROL];
            }
        }
        else
        {
            (void)SWC_WN_PRINT_WARN("Warning Vehicle config read error!\n");
        }
        
    }
    if (E_OK == Rte_Read_Cconfig_KindBuffers_400Bytes_CconfigKind_400Bytes(LocalCfg))
    {
        LowOilPressure_telltales_DelayTime = (uint16)CConfig_GetConfig(CCONFIG_KIND_LowOilPressure_telltales_DelayTime, LocalCfg);
        BrakeFault_DelayTime = (uint16)CConfig_GetConfig(CCONFIG_KIND_BrakeFault_DelayTime, LocalCfg);
        AccelBrakeWrnDelayTime = (uint16)CConfig_GetConfig(CCONFIG_KIND_AccelBrakeWrnDelayTime, LocalCfg);
    }
    else
    {
        LowOilPressure_telltales_DelayTime = 30;
        BrakeFault_DelayTime = 4000;
        AccelBrakeWrnDelayTime = 20;
    }
}

uint32 WN_GetSingleConfig(WN_enConfigID ConfigID)
{
    uint32 ConfigValue = 0xffffffff;
    switch (ConfigID)
    {
    case WN_enCfg_LowOilPressure_telltales_DelayTime:
    {
        ConfigValue = LowOilPressure_telltales_DelayTime;
        break;
    }
    case WN_enCfg_BrakeFault_DelayTime:
    {
        ConfigValue = BrakeFault_DelayTime;
        break;
    }
    case WN_enCfg_AccelBrakeWrnDelayTime:
    {
        ConfigValue = AccelBrakeWrnDelayTime;
        break;
    }
    case WN_enCfg_Transmission:
    {
        ConfigValue = m_VehCfgTransmission;
        break;
    }
    case WN_enCfg_EngCtrolUnit:
    {
        ConfigValue = m_VehCfgEngCtrolUnit;
        break;
    }
    case WN_enCfg_CruiseControl:
    {
        ConfigValue = m_VehCfgCruiseControl;
        break;
    }
    case WN_enCfg_Fuel:
    {
        ConfigValue = m_VehCfgFuel;
        break;
    }
    case WN_enCfg_ElecPosition:
    {
        ConfigValue = m_VehCfgElecPosition;
        break;
    }
    case WN_enCfg_IdleStopAndGo:
    {
        ConfigValue = m_VehCfgIdleStopAndGo;
        break;
    }
    case WN_enCfg_ElecEnManagement:
    {
        ConfigValue = m_VehCfgElecEnManagement;
        break;
    }
    case WN_enCfg_UpDownHill:
    {
        ConfigValue = m_VehCfgUpDownHill;
        break;
    }
    case WN_enCfg_AVH:
    {
        ConfigValue = m_VehCfgAVH;
        break;
    }
    case WN_enCfg_ParkingBrake:
    {
        ConfigValue = m_VehCfgParkingBrake;
        break;
    }
    case WN_enCfg_Tab:
    {
        ConfigValue = m_VehCfgTab;
        break;
    }
    case WN_enCfg_SpeedOmeter:
    {
        ConfigValue = m_VehCfgSpeedOmeter;
        break;
    }
    case WN_enCfg_SmartJuncBox:
    {
        ConfigValue = m_VehCfgSmartJuncBox;
        break;
    }
    case WN_enCfg_DriveHandleType:
    {
        ConfigValue = m_VehCfgDriveHandleType;
        break;
    }
    case WN_enCfg_BodyDomainCtrl:
    {
        ConfigValue = m_VehCfgBodyDomainCtrl;
        break;
    }
    case WN_enCfg_Regional:
    {
        ConfigValue = m_VehCfgRegional;
        break;
    }
    case WN_enCfg_StartSystem:
    {
        ConfigValue = m_VehCfgStartSystem;
        break;
    }
    case WN_enCfg_ParkingLamp:
    {
        ConfigValue = m_VehCfgParkingLamp;
        break;
    }
    case WN_enCfg_AutoLightSys:
    {
        ConfigValue = m_VehCfgAutoLightSys;
        break;
    }
    case WN_enCfg_FrtWiperSys:
    {
        ConfigValue = m_VehCfgFrtWiperSys;
        break;
    }
    case WN_enCfg_DrowWarnSys:
    {
        ConfigValue = m_VehCfgDrowWarnSys;
        break;
    }
    case WN_enCfg_Tpms:
    {
        ConfigValue = m_VehCfgTpms;
        break;
    }
    case WN_enCfg_EPark:
    {
        ConfigValue = m_VehCfgEPark;
        break;
    }
    case WN_enCfg_ElecSteColumnLock:
    {
        ConfigValue = m_VehCfgElecSteColumnLock;
        break;
    }
    case WN_enCfg_SeatBelt:
    {
        ConfigValue = m_VehCfgSeatBelt;
        break;
    }
    case WN_enCfg_SpeedReverse:
    {
        ConfigValue = m_VehCfgSpeedReverse;
        break;
    }
    case WN_enCfg_ShiftedUnlockKey:
    {
        ConfigValue = m_VehCfgShiftedUnlockKey;
        break;
    }
    case WN_enCfg_TransCase:
    {
        ConfigValue = m_VehCfgTransCase;
        break;
    }
    case WN_enCfg_ORCruiseControl:
    {
        ConfigValue = m_VehCfgORCruiseControl;
        break;
    }
    case WN_enCfg_OffRoadExpertMode:
    {
        ConfigValue = m_VehCfgOffRoadExpertMode;
        break;
    }
    case WN_enCfg_FCWAEB:
    {
        ConfigValue = m_VehCfgFCWAEB;
        break;
    }
    case WN_enCfg_HighwayAssist:
    {
        ConfigValue = m_VehCfgHighwayAssist;
        break;
    }
    case WN_enCfg_TrafficSign:
    {
        ConfigValue = m_VehCfgTrafficSign;
        break;
    }
    case WN_enCfg_PedalControlSts:
    {
        ConfigValue = m_VehCfgPedalControlSts;
        break;
    }
    case WN_enCfg_QuickStart:
    {
        ConfigValue = m_VehCfgQuickStart;
        break;
    }
    case WN_enCfg_OusideTemp:
    {
        ConfigValue = m_VehCfgOusideTemp;
        break;
    }
    case WN_enCfg_HeadLighting:
    {
        ConfigValue = m_VehCfgHeadLighting;
        break;
    }
    case WN_enCfg_LongAssHiBeam:
    {
        ConfigValue = m_VehCfgLongAssHiBeam;
        break;
    }
    case WN_enCfg_HeadLampAdjust:
    {
        ConfigValue = m_VehCfgHeadLampAdjust;
        break;
    }
    case WN_enCfg_HeadLampBeamSys:
    {
        ConfigValue = m_VehCfgHeadLampBeamSys;
        break;
    }
    case WN_enCfg_HeadLampCtrlFunc:
    {
        ConfigValue = m_VehCfgHeadLampCtrlFunc;
        break;
    }
    case WN_enCfg_LimitedSlip:
    {
        ConfigValue = m_VehCfgLimitedSlip;
        break;
    }
    case WN_enCfg_Wireless:
    {
        ConfigValue = m_VehCfgWireless;
        break;
    }
    case WN_enCfg_EngWaterPump:
    {
        ConfigValue = m_VehCfgEngWaterPump;
        break;
    }
    case WN_enCfg_V2VCharge:
    {
        ConfigValue = m_VehCfgV2VCharge;
        break;
    }
    case WN_enCfg_DisVChargeConnect:
    {
        ConfigValue = m_VehCfgDisVChargeConnect;
        break;
    }
    case WN_enCfg_AirGrille:
    {
        ConfigValue = m_VehCfgAirGrille;
        break;
    }
    case WN_enCfg_VoiceFacial:
    {
        ConfigValue = m_VehCfgVoiceFacial;
        break;
    }
    case WN_enCfg_DMSType:
    {
        ConfigValue = m_VehCfgDMSType;
        break;
    }
    case WN_enCfg_DrvModeOptionnal:
    {
        ConfigValue = m_VehCfgDrvModeOptionnal;
        break;
    }
    case WN_enCfg_DrvMode2:
    {
        ConfigValue = m_VehCfgDrvMode2;
        break;
    }
    case WN_enCfg_PPMI:
    {
        ConfigValue = m_VehCfgPPMI;
        break;
    }
    case WN_enCfg_NetService:
    {
        ConfigValue = m_VehCfgNetService;
        break;
    }
    case WN_enCfg_AEBJunctionAssist:
    {
        ConfigValue = m_VehCfgAEBJunctionAssist;
        break;
    }
    case WN_enCfg_FCWB:
    {
        ConfigValue = m_VehCfgFCWB;
        break;
    }
    case WN_enCfg_RearCollision:
    {
        ConfigValue = m_VehCfgRearCollision;
        break;
    }
    case WN_enCfg_LaneChangeAssist:
    {
        ConfigValue = m_VehCfgLaneChangeAssist;
        break;
    }
    case WN_enCfg_PASCTA:
    {
        ConfigValue = m_VehCfgPASCTA;
        break;
    }
    case WN_enCfg_LDWLKA:
    {
        ConfigValue = m_VehCfgLDWLKA;
        break;
    }
    case WN_enCfg_EvasiveSteering:
    {
        ConfigValue = m_VehCfgEvasiveSteering;
        break;
    }
    case WN_enCfg_EmergencySteering:
    {
        ConfigValue = m_VehCfgEmergencySteering;
        break;
    }
    case WN_enCfg_ARHUD:
    {
        ConfigValue = m_VehCfgARHUD;
        break;
    }
    case WN_enCfg_FuelTankSys:
    {
        ConfigValue = m_VehCfgFuelTankSys;
        break;
    }
    case WN_enCfg_Damper:
    {
        ConfigValue = m_VehCfgDamper;
        break;
    }
    case WN_enCfg_EMissionLevel:
    {
        ConfigValue = m_VehCfgEMissionLevel;
        break;
    }
    case WN_enCfg_UltravioletLamp:
    {
        ConfigValue = m_VehCfgUltravioletLamp;
        break;
    }
    case WN_enCfg_PTCanType:
    {
        ConfigValue = m_VehCfgPTCanType;
        break;
    }
    case WN_enCfg_CentralModule:
    {
        ConfigValue = m_VehCfgCentralModule;
        break;
    }
    case WN_enCfg_AuxFuel:
    {
        ConfigValue = m_VehCfgAuxFuel;
        break;
    }
    case WN_enCfg_SteeringSys:
    {
        ConfigValue = m_VehCfgSteeringSys;
        break;
    }
    case WN_enCfg_DrvMode3:
    {
        ConfigValue = m_VehCfgDrvMode3;
        break;
    }
    case WN_enCfg_ABS_EBD:
    {
        ConfigValue = m_VehCfgABS_EBD;
        break;
    }
    case WN_enCfg_TSMFunc:
    {
        ConfigValue = m_VehCfgTSMFunc;
        break;
    }
    case WN_enCfg_AFS:
    {
        ConfigValue = m_VehCfgAFS;
        break;
    }
	case WN_enCfg_FrontWheelBack:
	{
		ConfigValue = m_VehCfgFrontWheelBack;
        break;
	}
    case WN_enCfg_NOH:
    {
        ConfigValue = m_VehCfgNOH;
        break;
    }
    case WN_enCfg_Eng_oil_display:
    {
        ConfigValue = m_VehCfgLowOil;
        break;
    }
    case WN_enCfg_V2X:
    {
        ConfigValue = m_VehCfgV2X;
        break;
    }
    case WN_enCfg_ClutOvrHeatd:
    {
        ConfigValue = m_VehCfgClutOvrHeatd;
        break;
    }
    case WN_enCfg_DriverBelt:
    {
        ConfigValue = m_VehCfgDriverBelt;
        break;
    }
	case WN_encfg_OffroadThm:
	{
		ConfigValue = m_VehCfgOffroadThm;
		break;
	}
	case WN_encfg_RainShed:
	{
		ConfigValue = m_VehCfgRainShed;
		break;
	}
    case WN_encfg_OilLevel:
    {
        ConfigValue = m_VehCfgOilLevel;
        break;
    }
    case WN_encfg_TCY:
    {
        ConfigValue = m_VehCfgTCY;
        break;
    }
    case WN_encfg_TFV:
    {
        ConfigValue = m_VehCfgTFV;
        break;
    }
	case WN_encfg_TrunkBoard:
	{
		ConfigValue = m_VehCfgTrunkBoard;
		break;
	}
	case WN_encfg_KAT:
    {
         ConfigValue = m_VehCfgKAT;
		 break;
    }
    case WN_encfg_TFC:
    {
        ConfigValue = m_VehCfgTFC;
        break;
    }
    case WN_encfg_VDH:
    {
        ConfigValue = m_VehCfgVDH;
        break;
    }
	case WN_enCfg_EAE:
	{
		ConfigValue = m_VehCfgEAE;
        break;
	}
	case WN_enCfg_ChargingFlap:
	{
		ConfigValue = m_VehCfgChargingFlap;
        break;
	}
	case WN_encfg_CBW:
    {
        ConfigValue = m_VehCfgCBW;
        break;
    }
    case WN_enCfg_GAC:
    {
        ConfigValue = m_VehCfgGAC;
        break;
    }
    case WN_enCfg_GAG:
    {
        ConfigValue = m_VehCfgGAG;
        break;
    }
	case WN_enCfg_E_Call:
    {
        ConfigValue = m_VehCfgE_Call;
        break;
    }
    case WN_encfg_WashingLiquidLevelAlarm:
    {
        ConfigValue = m_VehCfgWashingLiquidLevelAlarm;
        break;
    }
    case WN_encfg_ComfortableStop:
    {
        ConfigValue = m_VehCfgComfortableStop;
        break;
    }
	case WN_encfg_AutomaticPowerDownControl:
    {
		ConfigValue = m_VehCfgAutomaticPowerDownControl;
		break;
	}
    default:
    {
        ConfigValue = 0;
        break;
    }
    }
    return ConfigValue;
}

boolean EolConfig_Trans_CANFD(void)
{
    boolean CANFDFlag = FALSE;

#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    CANFDFlag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    if (m_VehCfgPTCanType == 1)
    {
        CANFDFlag = TRUE;
    }
    else
    {
        CANFDFlag = FALSE;
    }
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    CANFDFlag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    if (m_VehCfgPTCanType == 1)
    {
        CANFDFlag = TRUE;
    }
    else
    {
        CANFDFlag = FALSE;
    }
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    if (m_VehCfgPTCanType == 1)
    {
        CANFDFlag = TRUE;
    }
    else
    {
        CANFDFlag = FALSE;
    }
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    CANFDFlag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    CANFDFlag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    CANFDFlag = TRUE;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	if (m_VehCfgPTCanType == 1)
	{
		CANFDFlag = TRUE;
	}
	else
	{
		CANFDFlag = FALSE;
	}
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	CANFDFlag = TRUE;

#else
#endif

    return CANFDFlag;
}

uint8 WN_Return_u8VSG_Sts_APIGet(AVASDTCRet *strAVASDTCRte)
{
    uint8 u8VSG_Sts = 0;
    if((1 == (*strAVASDTCRte).Open) || (1 == (*strAVASDTCRte).ShortAcross) \
        || (1 == (*strAVASDTCRte).ShorttoGND) || (1 == (*strAVASDTCRte).Clip) \
        || (1 == (*strAVASDTCRte).OutofRange) || (1 == (*strAVASDTCRte).ShorttoBAT))
    {
        u8VSG_Sts = 1;  //VSG fault on
    }
    return u8VSG_Sts;
}

uint8 WN_Builtin_AVAS_Sts_APIGet(uint8 *SignalValue)
{
    uint8 result = RTE_E_INVALID;
    AVASDTCRet strAVASDTCRte;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN   
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    result = Rte_Read_AVASDTCResults_AVASDTC(&strAVASDTCRte);
    *SignalValue = WN_Return_u8VSG_Sts_APIGet(&strAVASDTCRte);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    result = Rte_Read_AVASDTCResults_AVASDTC(&strAVASDTCRte);
    *SignalValue = WN_Return_u8VSG_Sts_APIGet(&strAVASDTCRte);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN

#else
#endif

    return result;
}

uint8 WN_EngClntTempWarn_SignalGet(boolean *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = FALSE;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_EngClntTempWarn_EngClntTempWarn(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGCLNTTEMPWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));

#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CruiseCtrlSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_CruiseCtrlSts_CruiseCtrlSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TgtCrsVehSpd_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_TgtCrsVehSpd_TgtCrsVehSpd(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TGTCRSVEHSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CruiseCtrlSts_PHEV_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_CruiseCtrlSts_PHEV_CruiseCtrlSts_PHEV(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC 4.1 DEL Msg
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CRUISECTRLSTS_PHEV, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SS_Screen_tip_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_SS_Screen_tip_SS_Screen_tip(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SS_SCREEN_TIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TranPMode_Sts_SignalGet(boolean *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = FALSE;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_TranPMode_Sts_TranPMode_Sts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRANPMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvPwrSysErr_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LvPwrSysErr_LvPwrSysErr(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVPWRSYSERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Stat_PwrSv_Lvl_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_Stat_PwrSv_Lvl_Stat_PwrSv_Lvl(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STAT_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Dyn_PwrSv_Lvl_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_Dyn_PwrSv_Lvl_Dyn_PwrSv_Lvl(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DYN_PWRSV_LVL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HDCFault_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ESP2 SG_ESP2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ESP2_SG_ESP2(&SG_ESP2_Tmp);
    *SignalValue = SG_ESP2_Tmp.HDCFault_0x145;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT_0X145, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AVHErrSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ESP2 SG_ESP2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ESP2_SG_ESP2(&SG_ESP2_Tmp);
    *SignalValue = SG_ESP2_Tmp.AVHErrSts_0x145;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS_0X145, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HDCFaultFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ESP2_ESP_FD2 SG_ESP2_ESP_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(&SG_ESP2_ESP_FD2_Tmp);
    *SignalValue = SG_ESP2_ESP_FD2_Tmp.HDCFault_0x137;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT_0X137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC 4.1 DEL msg
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HDCFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));

#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AVHErrStsFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ESP2_ESP_FD2 SG_ESP2_ESP_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ESP2_ESP_FD2_SG_ESP2_ESP_FD2(&SG_ESP2_ESP_FD2_Tmp);
    *SignalValue = SG_ESP2_ESP_FD2_Tmp.AVHErrSts_0x137;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS_0X137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC 4.1 DEL MSG
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AVHERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_EPBTextDisp_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_EPB1 SG_EPB1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_EPB1_SG_EPB1(&SG_EPB1_Tmp);
    *SignalValue = SG_EPB1_Tmp.EPBTextDisp;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_EPBTextDispTab_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	 Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPBTEXTDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EngSpdVldty_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_EngSpdVldty_EngSpdVldty(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPDVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EngSpd_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EngSpd_ForIP_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGSPD_FORIP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BrkFldWarn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKFLDWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKFLDWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_RdyLmpSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_RdyLmpSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RDYLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_PressBrakePedalPointOut_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_EPB1 SG_EPB1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_EPB1_SG_EPB1(&SG_EPB1_Tmp);
    *SignalValue = (uint8)SG_EPB1_Tmp.PressBrakePedalPointOut;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSBRAKEPEDALPOINTOUT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrvDoorSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_DrvDoorSts_DrvDoorSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_PassengerDoorSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_PassengerDoorSts_PassengerDoorSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSENGERDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LRDoorSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LRDoorSts_LRDoorSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RRDoorSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RRDoorSts_RRDoorSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRDOORSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TrunkSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_TrunkSts_TrunkSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HoodSts_F_Pbox_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HoodSts_F_Pbox_HoodSts_F_Pbox(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HOODSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RFogLmpFailSts_R_Pbox_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RFogLmpFailSts_R_Pbox_RFogLmpFailSts_R_Pbox(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RFOGLMPFAILSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_PosnLmpOutpSts_R_Pbox_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_PosnLmpOutpSts_R_Pbox_PosnLmpOutpSts_R_Pbox(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POSNLMPOUTPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_AutoLmpSwtSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0xFF;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    //TBD
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_AutoLmpSwtSts_AutoLmpSwtSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSWTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSWTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSWTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSWTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSWTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSWTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSWTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SysPowerMod_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_SysPowerMod_SysPowerMod(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSPOWERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LBrkLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LBrkLmpFailSts_LBrkLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HiPosnBrkLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HiPosnBrkLmpFailSts_HiPosnBrkLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HIPOSNBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RBrkLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RBrkLmpFailSts_RBrkLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RBRKLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LicPlateLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LicPlateLmpFailSts_LicPlateLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LICPLATELMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RvsLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RvsLmpFailSts_RvsLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RVSLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LRPosnLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LRPosnLmpFailSts_LRPosnLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RRPosnLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RRPosnLmpFailSts_RRPosnLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRPOSNLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ParkLmpSts_R_Pbox_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_ParkLmpSts_R_Pbox_ParkLmpSts_R_Pbox(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PARKLMPSTS_R_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLSFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RLSFailSts_RLSFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLSFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrowsyDrvDetWarn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_DrowsyDrvDetWarn_DrowsyDrvDetWarn(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DROWSYDRVDETWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FLTirePressIndSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FLTirePressIndSts_FLTirePressIndSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FRTirePressIndSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FRTirePressIndSts_FRTirePressIndSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLTirePressIndSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RLTirePressIndSts_RLTirePressIndSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RRTirePressIndSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RRTirePressIndSts_RRTirePressIndSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIREPRESSINDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FLTireTempSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FLTireTempSts_FLTireTempSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FastChrgnLidSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SlowChrgnLidSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FastChrgnLidAlarm_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SlowChrgnLidAlarm_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FRTireTempSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FRTireTempSts_FRTireTempSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLTireTempSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RLTireTempSts_RLTireTempSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RRTireTempSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RRTireTempSts_RRTireTempSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RRTIRETEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WarnKeyInCarWhenExit_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_WarnKeyInCarWhenExit_WarnKeyInCarWhenExit(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNKEYINCARWHENEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WarnVldKeyNotFound_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_WarnVldKeyNotFound_WarnVldKeyNotFound(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNVLDKEYNOTFOUND, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WarnEngStrtNotMeet_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_WarnEngStrtNotMeet_WarnEngStrtNotMeet(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WarnEngStrtNotMeetMT_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNENGSTRTNOTMEET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_PowerRlyFault_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_PowerRlyFault_PowerRlyFault(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_POWERRLYFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WarnPowerNotInOffPosn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_WarnPowerNotInOffPosn_WarnPowerNotInOffPosn(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNPOWERNOTINOFFPOSN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RotSteerWheel_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RotSteerWheel_RotSteerWheel(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ROTSTEERWHEEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ROTSTEERWHEEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ROTSTEERWHEEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ROTSTEERWHEEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ROTSTEERWHEEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ROTSTEERWHEEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ROTSTEERWHEEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrvSBR_Visual_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ABM1 SG_ABM1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ABM1_SG_ABM1(&SG_ABM1_Tmp);
    *SignalValue = SG_ABM1_Tmp.DrvSBR_Visual;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_PassSBR_Visual_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ABM1 SG_ABM1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ABM1_SG_ABM1(&SG_ABM1_Tmp);
    *SignalValue = SG_ABM1_Tmp.PassSBR_Visual;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PASSSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_SecRowLSBR_Visual_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ABM1 SG_ABM1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ABM1_SG_ABM1(&SG_ABM1_Tmp);
    *SignalValue = SG_ABM1_Tmp.SecRowLSBR_Visual;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWLSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_SecRowMidSBR_Visual_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ABM1 SG_ABM1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ABM1_SG_ABM1(&SG_ABM1_Tmp);
    *SignalValue = SG_ABM1_Tmp.SecRowMidSBR_Visual;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWMIDSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_SecRowRSBR_Visual_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ABM1 SG_ABM1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ABM1_SG_ABM1(&SG_ABM1_Tmp);
    *SignalValue = SG_ABM1_Tmp.SecRowRSBR_Visual;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SECROWRSBR_VISUAL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrvWarnMsg_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_DCT7 SG_DCT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_DCT7_SG_DCT7(&SG_DCT7_Tmp);
    *SignalValue = SG_DCT7_Tmp.DrvWarnMsg;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrvWarnMsgFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //No function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVWARNMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_ClutchHotWarning_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_CLUTCHHOTWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_DHT_FD1 SG_DHT_FD1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_DHT_FD1_SG_DHT_FD1(&SG_DHT_FD1_Tmp);
    *SignalValue = SG_DHT_FD1_Tmp.TCU_ClutchHotWarning;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrvFaiMsg_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_DCT7 SG_DCT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_DCT7_SG_DCT7(&SG_DCT7_Tmp);
    *SignalValue = SG_DCT7_Tmp.DrvFaiMsg_0x235;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrvFaiMsgFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG_0X236, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //lack CAM FD Msg
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrvFaiMsgHCU_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG_0X201, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_HP5 SG_HCU_HP5_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_HP5_SG_HCU_HP5(&SG_HCU_HP5_Tmp);
    *SignalValue = SG_HCU_HP5_Tmp.DrvFaiMsg_0x201;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRVFAIMSG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_ErrCategory_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_DHT_FD1 SG_DHT_FD1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_DHT_FD1_SG_DHT_FD1(&SG_DHT_FD1_Tmp);
    *SignalValue = SG_DHT_FD1_Tmp.TCU_ErrCategory;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DCT_PrsBrk_Warn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_DCT7 SG_DCT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_DCT7_SG_DCT7(&SG_DCT7_Tmp);
    *SignalValue = SG_DCT7_Tmp.DCT_PrsBrk_Warn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DCT_PrsBrk_WarnFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //NO Function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_PRSBRK_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}


uint8 WN_4L_Warn_0x137_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_4L_Warn_0x137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_4L_Warn_0x137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ACC_TimeGapSet_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TIMEGAPSET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TIMEGAPSET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TIMEGAPSET, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}


uint8 WN_ACC_FctSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_FCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_FCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_FCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Request_driveoff_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_HP5 SG_HCU_HP5_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REQUEST_DRIVEOFF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REQUEST_DRIVEOFF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REQUEST_DRIVEOFF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_PrsBrkWarn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_PRSBRKWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_HP5 SG_HCU_HP5_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_HP5_SG_HCU_HP5(&SG_HCU_HP5_Tmp);
    *SignalValue = SG_HCU_HP5_Tmp.HCU_PrsBrkWarn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DCT_ShftNotAlwd_Warn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_DCT7 SG_DCT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_DCT7_SG_DCT7(&SG_DCT7_Tmp);
    *SignalValue = SG_DCT7_Tmp.DCT_ShftNotAlwd_Warn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DCT_ShftNotAlwd_WarnFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Lack CAN FD Msg
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ShftNotAlwd_Warn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_HP5 SG_HCU_HP5_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_HP5_SG_HCU_HP5(&SG_HCU_HP5_Tmp);
    *SignalValue = SG_HCU_HP5_Tmp.HCU_ShftNotAlwd_Warn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHFTNOTALWD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DiagLmpReq_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_DiagLmpReq_DiagLmpReq(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // CAN Msg TBD
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DIAGLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CouplingThermWarning_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_CouplingThermWarning_CouplingThermWarning(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
// CAN Msg TBD
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_COUPLINGTHERMWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EspFuncOffSts_mode_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_EspFuncOffSts_mode_EspFuncOffSts_mode(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //NO Function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESPFUNCOFFSTS_MODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Navigation_Speed_Down_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CCO_Active_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_CCO_Active_CCO_Active(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_ACTIVE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CCO_TgtVel_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_CCO_TgtVel_CCO_TgtVel(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_TGTVEL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CCO_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    //R11 delete
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_CCO_Warn_CCO_Warn(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ACC_InterSysInfoDisp_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ACC4_ACC_FD2 SG_ACC4_ACC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(&SG_ACC4_ACC_FD2_Tmp);
    *SignalValue = SG_ACC4_ACC_FD2_Tmp.ACC_InterSysInfoDisp;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_ACC_TakeOverReq_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ACC4_ACC_FD2 SG_ACC4_ACC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(&SG_ACC4_ACC_FD2_Tmp);
    *SignalValue = (uint8)SG_ACC4_ACC_FD2_Tmp.ACC_TakeOverReq;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_TAKEOVERREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_TJA_ICA_InterSysInfoDisp_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ACC4_ACC_FD2 SG_ACC4_ACC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(&SG_ACC4_ACC_FD2_Tmp);
    *SignalValue = SG_ACC4_ACC_FD2_Tmp.TJA_ICA_InterSysInfoDisp;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TJA_ICA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_ISL_InterSysInfoDisp_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ACC4_ACC_FD2 SG_ACC4_ACC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ACC4_ACC_FD2_SG_ACC4_ACC_FD2(&SG_ACC4_ACC_FD2_Tmp);
    *SignalValue = SG_ACC4_ACC_FD2_Tmp.ISL_InterSysInfoDisp;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_InterSysInfoDisp_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ACC8_ACC_FD2 SG_ACC8_ACC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(&SG_ACC8_ACC_FD2_Tmp);
    *SignalValue = SG_ACC8_ACC_FD2_Tmp.HWA_InterSysInfoDisp;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_warning_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ACC8_ACC_FD2 SG_ACC8_ACC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ACC8_ACC_FD2_SG_ACC8_ACC_FD2(&SG_ACC8_ACC_FD2_Tmp);
    *SignalValue = SG_ACC8_ACC_FD2_Tmp.HWA_warning;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_ALC_InterSysInfoDisp_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ACC3_ACC_FD2 SG_ACC3_ACC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ACC3_ACC_FD2_SG_ACC3_ACC_FD2(&SG_ACC3_ACC_FD2_Tmp);
    *SignalValue = SG_ACC3_ACC_FD2_Tmp.ALC_InterSysInfoDisp;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALC_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_SOCLow_Indcn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SOCLOW_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = (uint8)SG_HCU_PT4_Tmp.HCU_SOCLow_Indcn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SOCLOW_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SOCLOW_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SOCLOW_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SOCLOW_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_RemoveChrgLine_Indcn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REMOVECHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = (uint8)SG_HCU_PT4_Tmp.HCU_RemoveChrgLine_Indcn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REMOVECHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REMOVECHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REMOVECHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REMOVECHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REMOVECHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_Shift_P_Indcn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHIFT_P_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = (uint8)SG_HCU_PT4_Tmp.HCU_Shift_P_Indcn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHIFT_P_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHIFT_P_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHIFT_P_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_SHIFT_P_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ConnectChrgLine_Indcn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CONNECTCHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = SG_HCU_PT4_Tmp.HCU_ConnectChrgLine_Indcn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CONNECTCHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CONNECTCHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CONNECTCHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CONNECTCHRGLINE_INDCN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_RefuReq_Indcn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REFUREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = SG_HCU_PT4_Tmp.HCU_RefuReq;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REFUREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REFUREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REFUREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_REFUREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_InhbChrgInfo_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_INHBCHRGINFO, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = (uint8)SG_HCU_PT4_Tmp.HCU_InhbChrgInfo;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_INHBCHRGINFO, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_INHBCHRGINFO, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_INHBCHRGINFO, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_INHBCHRGINFO, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_OPDParkWarnReq_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OPDPARKWARNREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = (uint8)SG_HCU_PT4_Tmp.OPDParkWarnReq;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OPDPARKWARNREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OPDPARKWARNREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OPDPARKWARNREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OPDPARKWARNREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_CarWashMode_Sts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CARWASHMODE_STS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = (uint8)SG_HCU_PT4_Tmp.CarWashMode_Sts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_CarWashMode_StsDisp_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CARWASHMODE_STSDISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = SG_HCU_PT4_Tmp.CarWashMode_StsDisp;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HybSysErr_5_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_HybSysErr_5;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HybSysErr_3_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_HybSysErr_3;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HybSysErr_6_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_HybSysErr_6;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HybSysErr_7_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_HybSysErr_7;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HybSysErr_4_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_HybSysErr_4;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HybSysErr_1_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_HybSysErr_1;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HybSysErr_2_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_HybSysErr_2;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_HYBSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_12VSysErr_1_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_12VSysErr_1;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_12VSysErr_2_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = (uint8)SG_HCU_PT7_Tmp.HCU_12VSysErr_2;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_12VSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_1_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_1_HCU_ChrgSysErr_1(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_2_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_2_HCU_ChrgSysErr_2(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_3_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_3_HCU_ChrgSysErr_3(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_4_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_4_HCU_ChrgSysErr_4(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_5_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_5_HCU_ChrgSysErr_5(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_6_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_6_HCU_ChrgSysErr_6(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_7_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_7_HCU_ChrgSysErr_7(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChrgSysErr_8_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_8, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChrgSysErr_8_HCU_ChrgSysErr_8(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_8, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_8, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_8, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHRGSYSERR_8, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BMS_ErrCategory_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_BMS4 SG_BMS4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_BMS4_SG_BMS4(&SG_BMS4_Tmp);
    *SignalValue = SG_BMS4_Tmp.BMS_ErrCategory;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_ERRCATEGORY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_VSG_Sts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    //TBD
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_VSG_Sts_VSG_Sts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //NO Function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_BattLowTemWarn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWTEMWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_BattLowTemWarn_HCU_BattLowTemWarn(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWTEMWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWTEMWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWTEMWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWTEMWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ChargSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_ChargSts_HCU_ChargSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //NO Function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_CHARGSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_EVContnsDistance_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_EVContnsDistance_HCU_EVContnsDistance(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_EVCONTNSDISTANCE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BMS_BattHeatRunaway_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTHEATRUNAWAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_BMS_BattHeatRunaway_BMS_BattHeatRunaway(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTHEATRUNAWAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTHEATRUNAWAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTHEATRUNAWAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTHEATRUNAWAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTHEATRUNAWAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTHEATRUNAWAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BMS_BattKeepTempSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTKEEPTEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_BMS_BattKeepTempSts_BMS_BattKeepTempSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTKEEPTEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTKEEPTEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTKEEPTEMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BMS_BattSOC_SignalGet(uint16 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTSOC, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_BMS_BattSOC_BMS_BattSOC(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    // Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTSOC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTSOC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_BATTSOC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BMS_SOCLowWarn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_BMS_SOCLowWarn_BMS_SOCLowWarn(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_SOCLOWWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}




uint8 WN_BMS_StsCC2Line_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_OBC_ConnectSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_OBC_ConnectSts_OBC_ConnectSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_CONNECTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_DrvMod_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_DRVMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_DrvMod_HCU_DrvMod(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_DRVMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_DRVMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_DRVMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BMS_ChrgDurationTime_SignalGet(uint16 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_BMS_ChrgDurationTime_BMS_ChrgDurationTime(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BMS_CHRGDURATIONTIME, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BrkPedalSts_BCM_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_BrkPedalSts_BCM_BrkPedalSts_BCM(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BRKPEDALSTS_BCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_AccelPedlPosnDiagc_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_AccelPedlPosnDiagc_AccelPedlPosnDiagc(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDLPOSNDIAGC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_AccelPedalPosnVldty_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_AccelPedalPosnVldty_AccelPedalPosnVldty(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACCELPEDALPOSNVLDTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_AccelPedalPosn_Diag_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_AccelPedalPosn_Diag_HCU_AccelPedalPosn_Diag(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_AccelPedalPosn_DiagValid_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAGVALID, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_AccelPedalPosn_DiagValid_HCU_AccelPedalPosn_DiagValid(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAGVALID, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAGVALID, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAGVALID, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAGVALID, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAGVALID, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_ACCELPEDALPOSN_DIAGVALID, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_VehSpdVld_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ABS3 SG_ABS3_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ABS3_SG_ABS3(&SG_ABS3_Tmp);
    *SignalValue = (uint8)SG_ABS3_Tmp.VehSpdVld_0x265;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD_0X265, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD_0X265, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_VehSpdVldFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_ABS3_ESP_FD2 SG_ABS3_ESP_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_ABS3_ESP_FD2_SG_ABS3_ESP_FD2(&SG_ABS3_ESP_FD2_Tmp);
    *SignalValue = (uint8)SG_ABS3_ESP_FD2_Tmp.VehSpdVld_0x137;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD_0X137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VEHSPDVLD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_EMS_AuthenResult_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_EMS_AuthenResult_EMS_AuthenResult(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EMS_AUTHENRESULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCUImmoAuthRes_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCUIMMOAUTHRES, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCUImmoAuthRes_HCUImmoAuthRes(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCUIMMOAUTHRES, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCUIMMOAUTHRES, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCUIMMOAUTHRES, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCUIMMOAUTHRES, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCUIMMOAUTHRES, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCUIMMOAUTHRES, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ModSwtFail_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_MODSWTFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT7 SG_HCU_PT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT7_SG_HCU_PT7(&SG_HCU_PT7_Tmp);
    *SignalValue = SG_HCU_PT7_Tmp.HCU_ModSwtFail;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_MODSWTFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_MODSWTFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_MODSWTFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_MODSWTFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_MODSWTFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_MODSWTFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_FTIVFault_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FTIVFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FTIVFault_FTIVFault(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FTIVFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FTIVFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FTIVFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FTIVFAULT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_RaceLaunchSts_0x84_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_RaceLaunchSts_0x60_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_RaceLaunchSts_HCU_RaceLaunchSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHSTS_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_RaceLaunchAvail_0x84_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X84, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_RaceLaunchAvail_0x60_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_RaceLaunchAvail_HCU_RaceLaunchAvail(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_RACELAUNCHAVAIL_0X60, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DCT_RaceModeSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_DCT7 SG_DCT7_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_DCT7_SG_DCT7(&SG_DCT7_Tmp);
    *SignalValue = SG_DCT7_Tmp.DCT_RaceModeSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_RACEMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_DCT_RaceModeStsFD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_RACEMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_RACEMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_RACEMODESTS, (uint8 *)SignalValue, sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //NO Function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_RACEMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_RACEMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DCT_RACEMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_GPF_Warning_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_GPF_Warning_GPF_Warning(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_GPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ACAmbTemp_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_ACAmbTemp_ACAmbTemp(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACAMBTEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LLasHdLmpDiagSig_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    //R11 delete
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LLasHdLmpDiagSig_LLasHdLmpDiagSig(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPDIAGSIG, (uint8 *)SignalValue, sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLasHdLmpDiagSig_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    //R11 delete
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RLasHdLmpDiagSig_RLasHdLmpDiagSig(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPDIAGSIG, (uint8 *)SignalValue, sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPDIAGSIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LasHdLmpSts_F_PBOX_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LASHDLMPSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LasHdLmpSts_F_Pbox_LasHdLmpSts_F_Pbox(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LASHDLMPSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LASHDLMPSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LASHDLMPSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LASHDLMPSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LASHDLMPSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LASHDLMPSTS_F_PBOX, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ALS_FailSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HC1 SG_HC1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HC1_SG_HC1(&SG_HC1_Tmp);
    *SignalValue = (uint8)SG_HC1_Tmp.ALS_FailSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//no signal
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//no signal
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_LeftHighBeamFailSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HC1 SG_HC1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HC1_SG_HC1(&SG_HC1_Tmp);
    *SignalValue = (uint8)SG_HC1_Tmp.LeftHighBeamFailSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_RightHighBeamFailSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HC1 SG_HC1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HC1_SG_HC1(&SG_HC1_Tmp);
    *SignalValue = (uint8)SG_HC1_Tmp.RightHighBeamFailSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //NO function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_LLowBeamFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LLowBeamFailSts_LLowBeamFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLowBeamFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RLowBeamFailSts_RLowBeamFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LHiBeamFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LHiBeamFailSts_LHiBeamFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RHiBeamFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RHiBeamFailSts_RHiBeamFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));

#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LHeadLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_LHeadLmpFailSts_LHeadLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RHeadLmpFailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RHeadLmpFailSts_RHeadLmpFailSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHEADLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FuelTankCapWarning_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUELTANKCAPWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FuelTankCapWarning_FuelTankCapWarning(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUELTANKCAPWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUELTANKCAPWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUELTANKCAPWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUELTANKCAPWARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RearELDLckSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RearELDLckSts_RearELDLckSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARELDLCKSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //NO Function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WPC_FaultSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_WPC_FaultSts_WPC_FaultSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WPC_PhoneReminder_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_WPC_PhoneReminder_WPC_PhoneReminder(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_PHONEREMINDER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EWP_ERR_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EWP_ERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_EWP_Err_EWP_Err(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EWP_ERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EWP_ERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EWP_ERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EWP_ERR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_BattLowHeatSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWHEATSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_HCU_BattLowHeatSts_HCU_BattLowHeatSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWHEATSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWHEATSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWHEATSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTLOWHEATSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DistrctnLvl_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrowsnsLvl_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DMSProc_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DMSProcResult_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DMSProcSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_PressReliProgs_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSRELIPROGS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_PressReliProgs_PressReliProgs(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSRELIPROGS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSRELIPROGS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSRELIPROGS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PRESSRELIPROGS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_T_Box_SysErrSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_T_Box_SysErrSts_T_Box_SysErrSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_T_BOX_SYSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FCW_Warn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_AEB3_AEB_FD2 SG_AEB3_AEB_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(&SG_AEB3_AEB_FD2_Tmp);
    *SignalValue = SG_AEB3_AEB_FD2_Tmp.FCW_Warn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AEB_VehTrig_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_AEB3_AEB_FD2 SG_AEB3_AEB_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(&SG_AEB3_AEB_FD2_Tmp);
    *SignalValue = (uint8)SG_AEB3_AEB_FD2_Tmp.AEB_VehTrig;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_VEHTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AEB_PedTrig_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_AEB3_AEB_FD2 SG_AEB3_AEB_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(&SG_AEB3_AEB_FD2_Tmp);
    *SignalValue = SG_AEB3_AEB_FD2_Tmp.AEB_PedTrig;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_PEDTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_FCW_AEB_VehFctSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_AEB3_AEB_FD2 SG_AEB3_AEB_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(&SG_AEB3_AEB_FD2_Tmp);
    *SignalValue = SG_AEB3_AEB_FD2_Tmp.FCW_AEB_VehFctSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCW_AEB_VEHFCTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AEB_JABrkTrig_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_AEB3_AEB_FD2 SG_AEB3_AEB_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_AEB3_AEB_FD2_SG_AEB3_AEB_FD2(&SG_AEB3_AEB_FD2_Tmp);
    *SignalValue = SG_AEB3_AEB_FD2_Tmp.AEB_JABrkTrig;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AEB_JABRKTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_FCTA_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FCTA_Warn_FCTA_Warn(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R15 Del
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FCTBTrig_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FCTBTrig_FCTBTrig(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R15 Del
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTBTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CR_BliSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_CR_BliSts_CR_BliSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R15 Del
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CR_BLISTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FCTA_B_FuncSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_FCTA_B_FuncSts_FCTA_B_FuncSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R15 Del
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FCTA_B_FUNCSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RSDS_RCW_Trigger_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RSDS_RCW_Trigger_RSDS_RCW_Trigger(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_RCW_TRIGGER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RSDS_TrailerSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RSDS_TrailerSts_RSDS_TrailerSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RSDS_BrkgTrig_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_RSDS_BrkgTrig_RSDS_BrkgTrig(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RSDS_BRKGTRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TSRSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_TSRSts_TSRSts(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_IFCCalibrationSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = SG_IFC4_IFC_FD2_Tmp.IFCCalibrationSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFCCALIBRATIONSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_CameraBlockageSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = (uint8)SG_IFC4_IFC_FD2_Tmp.CameraBlockageSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CAMERABLOCKAGESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_LSSErrSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = SG_IFC4_IFC_FD2_Tmp.LSSErrSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LSSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_IFC_Handsoffwarn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = SG_IFC4_IFC_FD2_Tmp.IFC_Handsoffwarn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IFC_HANDSOFFWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AESintervention_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = SG_IFC4_IFC_FD2_Tmp.AESintervention;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_ESSintervention_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = SG_IFC4_IFC_FD2_Tmp.ESSintervention;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSINTERVENTION, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_LCKStsIndcr_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = SG_IFC4_IFC_FD2_Tmp.LCKStsIndcr;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LCKSTSINDCR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AESSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC3_IFC_FD2 SG_IFC3_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2(&SG_IFC3_IFC_FD2_Tmp);
    *SignalValue = SG_IFC3_IFC_FD2_Tmp.AESSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_AESErrSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC3_IFC_FD2 SG_IFC3_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2(&SG_IFC3_IFC_FD2_Tmp);
    *SignalValue = (uint8)SG_IFC3_IFC_FD2_Tmp.AESErrSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AESERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_ESSSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC3_IFC_FD2 SG_IFC3_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2(&SG_IFC3_IFC_FD2_Tmp);
    *SignalValue = SG_IFC3_IFC_FD2_Tmp.ESSSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_ESSErrSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC3_IFC_FD2 SG_IFC3_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC3_IFC_FD2_SG_IFC3_IFC_FD2(&SG_IFC3_IFC_FD2_Tmp);
    *SignalValue = (uint8)SG_IFC3_IFC_FD2_Tmp.ESSErrSts;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ESSERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_BattPowerRedWarn_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTPOWERREDWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = SG_HCU_PT4_Tmp.HCU_BattPowerRedWarn;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTPOWERREDWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTPOWERREDWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_BATTPOWERREDWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_OPDFail_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_HCU_PT4 SG_HCU_PT4_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_HCU_PT4_SG_HCU_PT4(&SG_HCU_PT4_Tmp);
    *SignalValue = SG_HCU_PT4_Tmp.HCU_OPDFail;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_OPDFAIL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_GearChngPorNTXT_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_GEARCHNGPORNTXT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_GEARCHNGPORNTXT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_GEARCHNGPORNTXT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_GEARCHNGPORNTXT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_GEARCHNGPORNTXT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_GEARCHNGPORNTXT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HCU_GEARCHNGPORNTXT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_LLowBeamFailSts_HCM_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLowBeamFailSts_HCM_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLOWBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LHiBeamFailSts_HCM_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RHiBeamFailSts_HCM_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RHIBEAMFAILSTS_HCM, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EPS_FailSts_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_EPS1 SG_EPS1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_EPS1_SG_EPS1(&SG_EPS1_Tmp);
    *SignalValue = SG_EPS1_Tmp.EPS_FailSts_0x168;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X168, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X168, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X168, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_EPS_FailSts_FD_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_EPS1_FD1 SG_EPS1_FD1_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_EPS1_FD1_SG_EPS1_FD1(&SG_EPS1_FD1_Tmp);
    *SignalValue = SG_EPS1_FD1_Tmp.EPS_FailSts_0x147;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS_0X147, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    // DBC V4.1 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_EPS_FAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_high_temp_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_HIGH_TEMP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_gearbox_faulty_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_GEARBOX_FAULTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_P_faulty_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_P_FAULTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_release_button_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_RELEASE_BUTTON, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_step_P_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_STEP_P, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Shift_not_allowed_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_SHIFT_NOT_ALLOWED_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_limphome_D_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_LIMPHOME_D, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_limphome_P_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_LIMPHOME_P, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_gearbox_N_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_GEARBOX_N, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_shifter_faulty_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_SHIFTER_FAULTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_drive_faulty_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_DRIVE_FAULTY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_vehicle_P_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_VEHICLE_P, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_prohibit_P_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_PROHIBIT_P, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TCU_Warn_driver_leaves_car_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TCU_WARN_DRIVER_LEAVES_CAR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TAB_SwtShift_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TAB_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SCRSysWarnDisplay_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DPF_Warning_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DPF_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SystemOperMod_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //CAN MSG TBD
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SYSTEMOPERMOD, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ShiftSysStuinLow_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTSYSSTUINLOW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTSYSSTUINLOW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTSYSSTUINLOW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTSYSSTUINLOW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTSYSSTUINLOW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTSYSSTUINLOW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFTSYSSTUINLOW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_FuncProtnSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUNCPROTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUNCPROTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUNCPROTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUNCPROTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUNCPROTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUNCPROTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FUNCPROTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Over_Spd_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN_0X145, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Over_Spd_Warn_FD_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN_0X137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OVER_SPD_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Shift_N_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN_0X145, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Shift_N_Warn_FD_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN_0X137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SHIFT_N_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}
uint8 WN_FourLWarn_FD_SignalGet(uint8 *SignalValue)
{
	uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN_0X137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}
uint8 WN_FourLWarn_SignalGet(uint8 *SignalValue)
{
	uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_FOURL_WARN_0X145, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_AntLostFlg_SignalGet(uint8 *SignalValue)
{
	uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ANTLOSTFLG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}


uint8 WN_TSM_Trailer_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSM_TRAILER_0X149, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
    //no function
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TSM_Trailer_FD_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSM_TRAILER_0X137, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSM_TRAILER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TSM_TRAILER, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_AutoLmpsts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0xFF;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
    //no function
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RainshedSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAINSHEDSTS_R, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAINSHEDSTS_R, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
    //no function
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ELKMainState_SignalGet(uint8 *SignalValue)
{
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    SG_IFC4_IFC_FD2 SG_IFC4_IFC_FD2_Tmp = {0};
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Read_SG_IFC4_IFC_FD2_SG_IFC4_IFC_FD2(&SG_IFC4_IFC_FD2_Tmp);
    *SignalValue = SG_IFC4_IFC_FD2_Tmp.ELKMainState;
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	uint8 Rte_ReturnSts = RTE_E_INVALID;
	*SignalValue = 0;
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ELKMAINSTATE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#endif
    return Rte_ReturnSts;
}

uint8 WN_UVCAntiVirusFdbk_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_ReturnSts = Rte_Read_UVCAntiVirusFdbk_UVCAntiVirusFdbk(SignalValue);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UVCAntiVirusFdbk, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
 	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UVCAntiVirusFdbk, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CCO_SwtShift_Warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CCO_SWTSHIFT_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_SteerCorrnRmn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN_0X168, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SteerCorrnRmn_FD_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN_0X147, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STEERCORRNRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LAFSstatus_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //TBD
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}
uint8 WN_RAFSstatus_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //TBD
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAFSSTATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LLasHdLmpfailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    //R11 delete
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLasHdLmpfailSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    //R11 delete
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPFAILSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LLasHdLmpSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RLasHdLmpSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RLASHDLMPSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WarnLmpReq_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	// Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_AGS_Failure_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AGS_FAILURE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    //R11 delete
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AGS_FAILURE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AGS_FAILURE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AGS_FAILURE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AGS_FAILURE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AGS_FAILURE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_WarnInfoDisp_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_NOH_SysInfoDisplay_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_SYSINFODISPLAY, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_NOH_DistToExit_SignalGet(uint16 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_DISTTOEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_DISTTOEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_DISTTOEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_DISTTOEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_DISTTOEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_DISTTOEXIT, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_FCW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_FCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_FCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_FCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_FCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_FCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_BSW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_BSW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_BSW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_BSW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_BSW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_BSW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_LCW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_PPMIRErrSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PPMIRERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PPMIRERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#endif
    return Rte_ReturnSts;
}


uint8 WN_V2X_EBW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EBW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EBW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EBW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EBW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EBW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_ICW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_ICW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_ICW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_ICW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_ICW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_ICW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_LTA_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LTA, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LTA, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LTA, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LTA, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_LTA, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_AVW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_AVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_AVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_AVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_AVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_AVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_EVW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_EVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_CLW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_CLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_CLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_CLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_CLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_CLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_VRUCW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_VRUCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_VRUCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_VRUCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_VRUCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_VRUCW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_RLVW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_RLVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_RLVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_RLVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_RLVW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_DNPW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_DNPW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_DNPW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_DNPW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_DNPW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_DNPW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_HLW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_HLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_HLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_HLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_HLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_HLW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_V2X_TJW_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_TJW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//R14 DEL
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_TJW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_TJW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_TJW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_V2X_TJW, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_ECM_ClutovrheatdSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_P05_WN	
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_CLUTOVRHEATDSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#endif
    return Rte_ReturnSts;
}

uint8 WN_MRC_TakOver_Req_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MRC_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MRC_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MRC_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MRC_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MRC_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_MRC_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_NOH_WarnInfoDisplay_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_NOH_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_PPMIErrSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN 
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PPMIERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PPMIERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));//R5 delete
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PPMIERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	// Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PPMIERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PPMIERRSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}
uint8 WN_ECM_OffroadThmSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ECM_OFFROADTHMSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN

#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Wade_SW_warn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADE_SW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADE_SW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADE_SW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADE_SW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADE_SW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADE_SW_WARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_IDC_L2_TurnLightReq_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_IDC_L2_TURNLIGHTREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WadeModeWarn_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADEMODEWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADEMODEWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADEMODEWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADEMODEWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADEMODEWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WADEMODEWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ACC_SpdSetValue_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_SPDSETVALUE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_SPDSETVALUE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_SPDSETVALUE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_SPDSETVALUE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_SPDSETVALUE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ACC_SPDSETVALUE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RWPC_FaultSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RWPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RWPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RWPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RWPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RWPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrivingModReq_ESP_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODREQ_ESP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_DrivingModDis_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_DRIVINGMODDIS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ALSDrvSide_FB_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALSDRVSIDE_FB, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ALSDRVSIDE_FB, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RWPC_L_FaultSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RWPC_L_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RWPC_L_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_TakOver_Trig_SignalGet_ICU1_5(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_TakOver_Trig_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_TRIG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
//TBD CAN Msg
#elif defined GWM_V35_PROJECT_TYPE_P01_WN

#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_TakOver_Req_SignalGet_ICU1_5(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_TakOver_Req_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
//TBD CAN Msg
#endif
    return Rte_ReturnSts;
}

uint8 WN_IntelligentEvaActSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_TAKOVER_REQ,(uint8 *)SignalValue,(uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,(uint8 *)SignalValue,(uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,(uint8 *)SignalValue,(uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,(uint8 *)SignalValue,(uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,(uint8 *)SignalValue,(uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_INTELLIGENTEVAACTSTS,(uint8 *)SignalValue,(uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#endif
    return Rte_ReturnSts;
}

uint8 WN_AutoShiftSts_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOSHIFTSTS, (uint8 *)SignalValue, sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOSHIFTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));//R15
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOSHIFTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));//R15
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOSHIFTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOSHIFTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOSHIFTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));//R15
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOSHIFTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));//R15
#endif
    return Rte_ReturnSts;
}


uint8 WN_LNT_Warning_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    //TBD
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LNT_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_ModSwtFail_0x204_SignalGet(uint8 *SignalValue)//R15 delete
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    //TBD
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_P02_WN//no function
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#endif
    return Rte_ReturnSts;
}

uint8 WN_ISL_InterSysInfoDisp_ICU1_5_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ISL_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TarLvlChg_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TARLVLCHG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TARLVLCHG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TARLVLCHG, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RearLvlSts_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARLVLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARLVLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARLVLSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_AutoEasyAcsSts_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOEASYACSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOEASYACSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_AUTOEASYACSSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TrailerSts_VDC_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS_VDC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS_VDC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS_VDC, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_JackModeSts_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_JACKMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_JACKMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_JACKMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_RearLvlKickModeSts_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARLVLKICKMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARLVLKICKMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_REARLVLKICKMODESTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlVehMode_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLVEHMODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLVEHMODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLVEHMODE, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRmn_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRMN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlWarnLmpReq_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLWARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLWARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLWARNLMPREQ, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EngOilLowPresWrn_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
   
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EngOilLvlWrn_SignalGet(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLVLWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLVLWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLVLWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLVLWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLVLWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLVLWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_VMDR_FctnSts_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VMDR_FCTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	// Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VMDR_FCTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_VMDR_FCTNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ECM24_EngOilLowPresWrn_SignalGet(uint8 *SignalValue)
{
	 uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_ENGOILLOWPRESWRN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#endif
    return Rte_ReturnSts;
}

uint8 WN_WPC_FaultSts_SignalGet_P03_P05(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN//add for P02 HMI based on P03 2021/10/22
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WPC_FaultSts_SignalGet_D01(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //R17 DEL
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WPC_FaultSts_SignalGet_D01_D03_P05(uint8 *SignalValue)//R12
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_WPC_FAULTSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}
uint8 WN_ECM13_RainshedSts_FL_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAINSHEDSTS_FL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAINSHEDSTS_FL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}
uint8 WN_ECM13_RainshedSts_FR_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAINSHEDSTS_FR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_RAINSHEDSTS_FR, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}
uint8 WN_ECM13_TrunkSts_Y_SignalGet(uint8 *SignalValue)
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS_Y, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRUNKSTS_Y, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_ECM24_BarConnSts_SignalGet(uint8 *SignalValue)//R13
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BARCONNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BARCONNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_BARCONNSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_StartModSts_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STARTMODSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STARTMODSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_STARTMODSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TrailerhookSts_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TrailerSts_SignalGet(uint8 *SignalValue)//R13
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_TRAILERSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TrailerhookFltSt_SignalGet(uint8 *SignalValue)//R13
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_VehicleParkRemind_SignalGet(uint8 *SignalValue)//R13
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TrailerhookClsRemind_SignalGet(uint8 *SignalValue)//R13
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TrailerConnectRemind_SignalGet(uint8 *SignalValue)//R13
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_InterSysInfoDisp_SignalGet_ICU1_5(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INTERSYSINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}


uint8 WN_HWA_InhibitWarn_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_INHIBITWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_HWA_INHIBITWARN, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_warning_SignalGet_ICU1_5(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNING, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_WarnInfoDisp_SignalGet_ICU1_5(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
//TBD
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_HWA_WARNINFODISP, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRestrcn1_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN1, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRestrcn2_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRestrcn3_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN3, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRestrcn4_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN4, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRestrcn5_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN5, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRestrcn6_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN6, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LvlCtrlRestrcn7_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_LVLCTRLRESTRCN7, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_NavDecActive_SignalGet(uint8 *SignalValue)//R14
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_SCRSysWarnDisplay_B2_SignalGet(uint8 *SignalValue)//R15
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY_B2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY_B2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_SCRSYSWARNDISPLAY_B2, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_UreaRemainDist_SignalGet(uint16 *SignalValue)//R15
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
	Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UREAREMAINDIST, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UREAREMAINDIST, (uint8 *)SignalValue, (uint8)sizeof(WN_u16SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    //Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_UREAREMAINDIST, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_WshngLiquidLvlWarn_SignalGet(uint8 *SignalValue)//R15 TBD
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    //no function
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
//TBD
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_CST_Status_SignalGet(uint8 *SignalValue)//R15
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CST_STATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CST_STATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_CST_STATUS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}



uint8 WN_PDCU_EvSave_disl_SignalGet(uint8 *SignalValue)//R15
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_EVSAVE_DISL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_EVSAVE_DISL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_EVSAVE_DISL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_EVSAVE_DISL, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_OBC_ModSts_SignalGet(uint8 *SignalValue)//R15
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_MODSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_MODSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OBC_MODSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_OBC_ModSts_EV_SignalGet(uint8 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_OBC_CCLineConnectSts_SignalGet(uint8 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_EVCC_PPLineSts_SignalGet(uint8 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HP5_AvailabilityOfARF_SignalGet(uint8 *SignalValue)//P02 DBCv2.0
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_AVAILABILITYOFARF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_AVAILABILITYOFARF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_AVAILABILITYOFARF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_AVAILABILITYOFARF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_AVAILABILITYOFARF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_AVAILABILITYOFARF, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HCU_HP5_lossenPedalPrompt_SignalGet(uint8 *SignalValue)//P02 DBCv2.0
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_LOSSENPEDALPROMPT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_LOSSENPEDALPROMPT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_LOSSENPEDALPROMPT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_LOSSENPEDALPROMPT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_LOSSENPEDALPROMPT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
	//Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_PDCU_LOSSENPEDALPROMPT, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_T_Box_SysErrSts_0x56_SignalGet(uint8 *SignalValue)//R17
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_OilBoxSplySts_SignalGet(uint8 *SignalValue)//R17
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_ReturnSts = Rte_Call_rpCS_SWCNormal_ComEx_ReceiveSignal(COMEX_SIGNAL_RX_OILBOXSPLYSTS, (uint8 *)SignalValue, (uint8)sizeof(WN_u8SignalData));
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_HWA_Text_Lib_SignalGet(uint8 *SignalValue)//R17
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_TJA_FollowSts_SignalGet(uint8 *SignalValue)//R17
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_LaneAvailability_SignalGet(uint8 *SignalValue)//R17
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_MidELDLckSwtReq_SignalGet(uint8 *SignalValue)//R17
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_PowerRelsOverSpdWarn_SignalGet(uint8 *SignalValue)//R17
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_VCU_CrsCtrlSts_SignalGet(uint8 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_VCU_CrsSpd_SignalGet(uint8 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_VCU_ChrgnSts_SignalGet(uint8 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_Phone_ChrgnMode(uint8 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

uint8 WN_BMS_SOC(uint16 *SignalValue)//R18
{
    uint8 Rte_ReturnSts = RTE_E_INVALID;
    *SignalValue = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
#elif defined GWM_V35_PROJECT_TYPE_P02_WN 
#elif defined GWM_V35_PROJECT_TYPE_P01_WN 
#else
#endif
    return Rte_ReturnSts;
}

void WN_PIN_C3_IOGet(uint8 *Data)
{
    *Data = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_OPL_IDL, Data);
#else
#endif
}

void WN_PIN_C4_IOGet(uint8 *Data)
{
    *Data = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_BSF_IDL, Data);
#else
#endif
}

void WN_PIN_C1_IOGet(uint8 *Data)
{
    *Data = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Call_IoHwAb_Interface_GetPin(RI_IoHwAb_DIn_PinInCfg_VIP_SI_IDH, Data);
#else
#endif
}

void WN_MenuSetData_APIGet(MenuSetData_t *Data)
{
    memset(Data, 0, sizeof(MenuSetData_t));
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Read_rpSR_SWCNormal_MenuSetData_Element(Data);
#else
#endif
}

void WN_TachoInfo_APIGet(s_TachoInfo_t *Data)
{
    memset(Data, 0, sizeof(s_TachoInfo_t));
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Read_rpSR_SWCNormal_TachoInfo_Element(Data);
#else
#endif
}

void WN_SpeedoInfo_APIGet(s_SpeedoInfo_t *Data)
{
    memset(Data, 0, sizeof(s_SpeedoInfo_t));
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Read_rpSR_SWCNormal_SpeedoInfo_Element(Data);
#else
#endif
}

void WN_OdoRteGetParament_APIGet(s_OdoRteGetParament_t *Data)
{
    memset(Data, 0, sizeof(s_OdoRteGetParament_t));
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Read_rpSR_SWCNormal_OdoParament_Element(Data);
#else
#endif
}

void WN_Overspeed_Enable_APIGet(uint8 *Data)
{
    *Data = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedEnable_Element(Data);
#else
#endif
}

void WN_Set_Overspeed_APIGet(uint16 *Data)
{
    *Data = 0;
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Read_rpSR_SWCNormal_MenuSet_OverSpeedLimit_Element(Data);
#else
#endif
}

void WN_LowFuel_Active_APIGet(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE *Data)
{
    memset(Data, 0, sizeof(FUEL_MODULE_OUTPUT_DATA_STRUCT_RTE));
#ifdef GWM_V35_PROJECT_TYPE_B02_WN
    Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_B03_WN
    Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P03_WN
    Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P05_WN
    Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_A07_WN
    Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D01_WN
    Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D02_WN
    Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_D03_WN
	Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P02_WN
	Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#elif defined GWM_V35_PROJECT_TYPE_P01_WN
	Rte_Read_rpSR_SWCNormal_Fuel_Set_Module_Data_Element(Data);
#else
#endif
}
/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Zhang Bin
**
**  Date    :      2021/01/25     Original Version
**
**********************************************************************************************************/

#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
