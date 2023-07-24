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

/**********************************************************************************************************
*File Name   : SWC_DM_Config.h                                                                            *
*                                                                                                         *
*Description : Driving mode module adaptation head file.                                                  *
*                                                                                                         *
*Author      : Li Jian                                                                                    *
*                                                                                                         *
*Platform    : MICROSAR OS                                                   						  	  *
*                                                                                                         *
*Compiler    : Green Hills MULTI IDE                                                                      *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family                                                       *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef DM_CFG_H
#define DM_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
* Pay Attention : Do Not Add Any Other Head File Here Without System Standard Head File !!!				  *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "SWC_WN_Config.h"
#include "logger.h"

// DM LOG
#define SWC_DM_LOGOUT_ENBLE TRUE
#define SWC_DM_PRINT_WARN   fuel_warn


// driving mode logic process state machine level
enum
{
	STATE_LOGIC_IDLE = 0,
	STATE_TRANSMIT_IGN_ON,
	STATE_IGNON_DELAY_PROCESS,
	STATE_LOGIC_GENERAL_PROCESS,
	STATE_LOGIC_FIRST_PROCESS,
	STATE_TRANSMIT_IGN_OFF,
};

/*Power Mode Status*/
typedef enum
{
    DM_enNULL_POWER_MODE = 0x0000,
    DM_enOFF = 0x0001,
    DM_enRUN = 0x0002,
    DM_enABNORMAL_VOLTAGE = 0x0004,
    DM_enSLEEP = 0x0008,
}DM_CFG_u32WorkPowerMode;

/*fuel vehicle has 4 logic case */
typedef enum
{
	DM_FUEL_LOGIC_CASE1 = 0,
	DM_FUEL_LOGIC_CASE2 = 1,
	DM_FUEL_LOGIC_CASE3 = 2,
	DM_FUEL_LOGIC_CASE4 = 3,
	DM_FUEL_LOGIC_CASE5 = 4,
	DM_FUEL_LOGIC_CASE_MAXNUM = 5,
	DM_FUEL_LOGIC_CASE_INVALID = 0xFF,
}DM_FUEL_enLogicCase;

/*driving mode eol config to fuel logic case*/
#define	DM_FUEL_EOL_CFG_MODE_MAXNUM			(72)
#define	DM_FUEL_EOL_CFG_NO_DRVINGMODE		(0)
#define	DM_FUEL_EOL_CFG_DRVINGMODE2LOGIC	\
{																	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 1 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 2 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 3 */	\
	DM_FUEL_LOGIC_CASE3,					/* Driving mode 4 */	\
	DM_FUEL_LOGIC_CASE3,					/* Driving mode 5 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 6 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 7 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 8 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 9 */	\
	DM_FUEL_LOGIC_CASE2,					/* Driving mode 10 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 11 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 12 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 13 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 14 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 15 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 16 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 17 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 18 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 19 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 20 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 21 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 22 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 23 */	\
	DM_FUEL_LOGIC_CASE2,					/* Driving mode 24 */	\
	DM_FUEL_LOGIC_CASE5,					/* Driving mode 25 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 26 */	\
	DM_FUEL_LOGIC_CASE5,					/* Driving mode 27 */	\
	DM_FUEL_LOGIC_CASE3,					/* Driving mode 28 */	\
	DM_FUEL_LOGIC_CASE3,					/* Driving mode 29 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 30 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 31 */	\
	DM_FUEL_LOGIC_CASE5,					/* Driving mode 32 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 33 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 34 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 35 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 36 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 37 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 38 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 39 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 40 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 41 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 42 */	\
	DM_FUEL_LOGIC_CASE3,					/* Driving mode 43 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 44 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 45 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 46 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 47 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 48 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 49 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 50 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 51 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 52 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 53 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 54 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 55 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 56 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 57 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 58 */	\
	DM_FUEL_LOGIC_CASE5,					/* Driving mode 59 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 60 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 61 */	\
	DM_FUEL_LOGIC_CASE1,					/* Driving mode 62 */	\
	DM_FUEL_LOGIC_CASE5,					/* Driving mode 63 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 64 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 65 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 66 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 67 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 68 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 69 */	\
	DM_FUEL_LOGIC_CASE3,					/* Driving mode 70 */	\
	DM_FUEL_LOGIC_CASE_INVALID,				/* Driving mode 71 */	\
	DM_FUEL_LOGIC_CASE4,					/* Driving mode 72 */	\
}

/* driving mode telltale id*/
typedef enum
{
	DM_enTT_NONE = 0,
    DM_enTT_FAIL,

    DM_enTT_FUEL_STD,
    DM_enTT_FUEL_ECO,
    DM_enTT_FUEL_SPORT,
    DM_enTT_FUEL_SNOW,
    DM_enTT_FUEL_MUD,
    DM_enTT_FUEL_SAND,
    DM_enTT_FUEL_4L,
    DM_enTT_FUEL_OFFROAD,
    DM_enTT_FUEL_ROCK,
    DM_enTT_FUEL_MUDSAND,
    DM_enTT_FUEL_MOUTAIN,
    DM_enTT_FUEL_POTHOLE,
    DM_enTT_FUEL_EXPERT,
    DM_enTT_FUEL_IMC,
    DM_enTT_FUEL_SPORTPLUS,
    DM_enTT_FUEL_TURBO,
    DM_enTT_FUEL_RACE,
	DM_enTT_FUEL_GRASSGRAVEL,
	DM_enTT_FUEL_UNEVEN,
	DM_enTT_FUEL_WADE4H,
	DM_enTT_FUEL_WADE4L,
	DM_enTT_FUEL_2H,
	DM_enTT_FUEL_4H,

    DM_enTT_HEV_NORMAL,
    DM_enTT_HEV_EV,
    DM_enTT_HEV_SAVE,
    DM_enTT_HEV_SPORT,
    DM_enTT_HEV_AWD,
    DM_enTT_HEV_SNOW,
    DM_enTT_HEV_MUD,
    DM_enTT_HEV_SAND,
    DM_enTT_HEV_SPORTPLUS,
    DM_enTT_HEV_ECO,

    DM_enTT_PHEV_NORMAL,
    DM_enTT_PHEV_EV,
    DM_enTT_PHEV_SAVE,
    DM_enTT_PHEV_SPORT,
    DM_enTT_PHEV_AWD,
    DM_enTT_PHEV_SNOW,
    DM_enTT_PHEV_MUD,
    DM_enTT_PHEV_SAND,
    DM_enTT_PHEV_SPORTPLUS,

    DM_enTT_EV_NORMAL,
    DM_enTT_EV_SPORT,
    DM_enTT_EV_ECO,
    DM_enTT_EV_AUTO,
    DM_enTT_EV_SNOW,

    DM_enTT_TelltaleMaxId,
}DM_CFG_enTelltaleId;

/* Hybrid Mode telltale id */
typedef enum
{
	DM_enTT_HMNONE = 0,
	DM_enTT_HMFAIL,

	DM_enTT_PHEVPS_HMHEV,
	DM_enTT_PHEVPS_HMEV,

	DM_enTT_PHEVP2_HMHEV,
	DM_enTT_PHEVP2_HMEV,
	DM_enTT_PHEVP2_HMSAVE,

	DM_enTT_HMTelltaleMaxId,
}DM_HMCFG_enTelltaleId;

//against driving mode need to place together
#define	DM_FUEL_MODE_LIST_NUMBER                 (23)
#define	DM_FUEL_MODE_START                       (enDM_StandardMode)
#define	DM_FUEL_MODE_END                         (enDM_4HMode)

#define	DM_FUEL_MODE_SELECT_LIST_NUMBER          (23)
#define	DM_FUEL_MODE_SELECT_START                (enDM_StandardSelect)
#define	DM_FUEL_MODE_SELECT_END                  (enDM_AutoSelect)

#define	DM_FUEL_MODE_SWITCH_LIST_NUMBER          (23)
#define	DM_FUEL_MODE_SWITCH_START                (enDM_StandardSwitch)
#define	DM_FUEL_MODE_SWITCH_END                  (enDM_AutoSwitch)

#define	DM_EV_HEV_PHEV_MODE_START_LIST_NUMBER    (11)
#define	DM_EV_HEV_PHEV_MODE_START_START          (enDM_NORMALStart)
#define	DM_EV_HEV_PHEV_MODE_START_END            (enDM_StandardStart)


/* driving mode id*/
typedef enum
{
	// DM_FUEL_MODE_LIST
	// DM_FUEL_MODE_SELECT_LIST
	// DM_FUEL_MODE_SWITCH_LIST
	// DM_EV_HEV_PHEV_MODE_START_LIST

	enDM_StandardMode,
	enDM_SportMode,
	enDM_SnowMode,
	enDM_MuddyMode,
	enDM_SandMode,
	enDM_4LMode,
	enDM_EcoMode,
	enDM_IMCMode,
	enDM_SportPlusMode,
	enDM_OffRoadMode,
	enDM_ExpertMode,
	enDM_RockMode,
	enDM_PotholeMode,
	enDM_MuddySandMode,
	enDM_MountainMode,
	enDM_TurboMode,
	enDM_RaceMode,
	enDM_GrassGravelMode,
	enDM_UnevenMode,
	enDM_Wade4HMode,
	enDM_Wade4LMode,
	enDM_2HMode,
	enDM_4HMode,

	enDM_StandardSelect,
	enDM_SportSelect,
	enDM_SnowSelect,
	enDM_ExpertSelect,
	enDM_MuddySelect,
	enDM_2HSelect,
	enDM_SandSelect,
	enDM_4HSelect,
	enDM_4LSelect,
	enDM_EcoSelect,
	enDM_OffRoadSelect,
	enDM_SportPlusSelect,
	enDM_RockSelect,
	enDM_PotholeSelect,
	enDM_MuddySandSelect,
	enDM_MountainSelect,
	enDM_TurboSelect,
	enDM_RaceSelect,
	enDM_GrassGravelSelect,
	enDM_UnevenNexSelect,
	enDM_Wade4HSelect,
	enDM_Wade4LSelect,
	enDM_AutoSelect,

	enDM_StandardSwitch,
	enDM_SportSwitch,
	enDM_SnowSwitch,
	enDM_ExpertSwitch,
	enDM_MuddySwitch,
	enDM_2HSwitch,
	enDM_SandSwitch,
	enDM_4HSwitch,
	enDM_4LSwitch,
	enDM_EcoSwitch,
	enDM_OffRoadSwitch,
	enDM_SportPlusSwitch,
	enDM_RockSwitch,
	enDM_PotholeSwitch,
	enDM_MuddySandSwitch,
	enDM_MountainSwitch,
	enDM_TurboSwitch,
	enDM_RaceSwitch,
	enDM_GrassGravelSwitch,
	enDM_UnevenNexSwitch,
	enDM_Wade4HSwitch,
	enDM_Wade4LSwitch,
	enDM_AutoSwitch,

	enDM_NORMALStart,
	enDM_EvStart,
	enDM_SaveStart,
	enDM_SportStart,
	enDM_AwdStart,
	enDM_SnowStart,
	enDM_MuddyStart,
	enDM_SandStart,
	enDM_EcoStart,
	enDM_SportPlusStart,
	enDM_StandardStart,

	enDM_WarningMaxId,
	enDM_WarningInvaildId,
}DM_CFG_enDrvModId;

//#if (DM_FUEL_MODE_LIST_NUMBER != (DM_FUEL_MODE_END-DM_FUEL_MODE_START))
//#error DM_FUEL_MODE_LIST_NUMBER or DM_FUEL_MODE_START or DM_FUEL_MODE_END error!
//#endif

#define	DM_FUEL4_SCR_MODE_START             (DM_enWN_FUEL4_Standard)
#define	DM_FUEL4_SCR_MODE_END               (DM_enWN_FUEL4_4H)

#define	DM_FUEL_SCR_MODE_START              (DM_enWN_FUEL_Standard)
#define	DM_FUEL_SCR_MODE_END                (DM_enWN_FUEL_4H)

#define	DM_FUEL_SCR_MODE_SELECT_START       (DM_enWN_FUEL_StandardSelect)
#define	DM_FUEL_SCR_MODE_SELECT_END         (DM_enWN_FUEL_AutoSelect)

#define	DM_FUEL_SCR_MODE_SWITCH_START       (DM_enWN_FUEL_StandardModeSwitch)
#define	DM_FUEL_SCR_MODE_SWITCH_END         (DM_enWN_FUEL_AutoModeSwitch)

#define	DM_HEV_PHEV_SCR_MODE_START_START    (DM_enWN_HEV_PHEV_NORMALStart)
#define	DM_HEV_PHEV_SCR_MODE_START_END      (DM_enWN_HEV_PHEV_ECOStart)

#define	DM_EV_SCR_MODE_START_START          (DM_enWN_EV_StandardStart)
#define	DM_EV_SCR_MODE_START_END            (DM_enWN_EV_SnowStart)

/* driving mode warning id*/
typedef enum
{
	// DM_FUEL4_SCR_MODE_LIST
	// DM_FUEL_SCR_MODE_LIST
	// DM_FUEL_SCR_MODE_SELECT_LIST
	// DM_FUEL_SCR_MODE_SWITCH_LIST
	// DM_HEV_PHEV_SCR_MODE_START_LIST
	// DM_EV_SCR_MODE_START_LIST

	DM_enWN_FUEL4_Standard,
	DM_enWN_FUEL4_Sport,
	DM_enWN_FUEL4_Snow,
	DM_enWN_FUEL4_Muddy,
	DM_enWN_FUEL4_Sand,
	DM_enWN_FUEL4_4L,
	DM_enWN_FUEL4_ECO,
	DM_enWN_FUEL4_IMC,
	DM_enWN_FUEL4_SportPlus,
	DM_enWN_FUEL4_OffRoad,
	DM_enWN_FUEL4_Expert,
	DM_enWN_FUEL4_Rock,
	DM_enWN_FUEL4_Pothole,
	DM_enWN_FUEL4_MuddySand,
	DM_enWN_FUEL4_Mountain,
	DM_enWN_FUEL4_Turbo,
	DM_enWN_FUEL4_Race,
	DM_enWN_FUEL4_GrassGravel,
	DM_enWN_FUEL4_Uneven,
	DM_enWN_FUEL4_Wade4H,
	DM_enWN_FUEL4_Wade4L,
	DM_enWN_FUEL4_2H,
	DM_enWN_FUEL4_4H,

	DM_enWN_FUEL_Standard,
	DM_enWN_FUEL_Sport,
	DM_enWN_FUEL_Snow,
	DM_enWN_FUEL_Muddy,
	DM_enWN_FUEL_Sand,
	DM_enWN_FUEL_4L,
	DM_enWN_FUEL_ECO,
	DM_enWN_FUEL_IMC,
	DM_enWN_FUEL_SportPlus,
	DM_enWN_FUEL_OffRoad,
	DM_enWN_FUEL_Expert,
	DM_enWN_FUEL_Rock,
	DM_enWN_FUEL_Pothole,
	DM_enWN_FUEL_MuddySand,
	DM_enWN_FUEL_Mountain,
	DM_enWN_FUEL_Turbo,
	DM_enWN_FUEL_Race,
	DM_enWN_FUEL_GrassGravel,
	DM_enWN_FUEL_Uneven,
	DM_enWN_FUEL_Wade4H,
	DM_enWN_FUEL_Wade4L,
	DM_enWN_FUEL_2H,
	DM_enWN_FUEL_4H,

	DM_enWN_FUEL_StandardSelect,
	DM_enWN_FUEL_SportSelect,
	DM_enWN_FUEL_SnowSelect,
	DM_enWN_FUEL_ExpertSelect,
	DM_enWN_FUEL_MuddySelect,
	DM_enWN_FUEL_2HSelect,
	DM_enWN_FUEL_SandSelect,
	DM_enWN_FUEL_4HSelect,
	DM_enWN_FUEL_4LSelect,
	DM_enWN_FUEL_ECOSelect,
	DM_enWN_FUEL_OffRoadSelect,
	DM_enWN_FUEL_SportPlusSelect,
	DM_enWN_FUEL_RockSelect,
	DM_enWN_FUEL_PotholeSelect,
	DM_enWN_FUEL_MuddySandSelect,
	DM_enWN_FUEL_MountainSelect,
	DM_enWN_FUEL_TurboSelect,
	DM_enWN_FUEL_RaceSelect,
	DM_enWN_FUEL_GrassGravelSelect,
	DM_enWN_FUEL_UnevenNexSelect,
	DM_enWN_FUEL_Wade4HSelect,
	DM_enWN_FUEL_Wade4LSelect,
	DM_enWN_FUEL_AutoSelect,

	DM_enWN_FUEL_StandardModeSwitch,
	DM_enWN_FUEL_SportModeSwitch,
	DM_enWN_FUEL_SnowModeSwitch,
	DM_enWN_FUEL_ExpertModeSwitch,
	DM_enWN_FUEL_MuddyModeSwitch,
	DM_enWN_FUEL_2HModeSwitch,
	DM_enWN_FUEL_SandModeSwitch,
	DM_enWN_FUEL_4HModeSwitch,
	DM_enWN_FUEL_4LModeSwitch,
	DM_enWN_FUEL_ECOModeSwitch,
	DM_enWN_FUEL_OffRoadModeSwitch,
	DM_enWN_FUEL_SportPlusModeSwitch,
	DM_enWN_FUEL_RockModeSwitch,
	DM_enWN_FUEL_PotholeModeSwitch,
	DM_enWN_FUEL_MuddySandModeSwitch,
	DM_enWN_FUEL_MountainModeSwitch,
	DM_enWN_FUEL_TurboSwitch,
	DM_enWN_FUEL_RaceModeSwitch,
	DM_enWN_FUEL_GrassGravelModeSwitch,
	DM_enWN_FUEL_UnevenNexModeSwitch,
	DM_enWN_FUEL_Wade4HModeSwitch,
	DM_enWN_FUEL_Wade4LModeSwitch,
	DM_enWN_FUEL_AutoModeSwitch,

	DM_enWN_HEV_PHEV_NORMALStart,
	DM_enWN_HEV_PHEV_EVStart,
	DM_enWN_HEV_PHEV_SAVEStart,
	DM_enWN_HEV_PHEV_SPORTStart,
	DM_enWN_HEV_PHEV_AWDStart,
	DM_enWN_HEV_PHEV_SNOWStart,
	DM_enWN_HEV_PHEV_MUDDYStart,
	DM_enWN_HEV_PHEV_SANDStart,
	DM_enWN_HEV_PHEV_SPORTPStart,
	DM_enWN_HEV_PHEV_ECOStart,

	DM_enWN_EV_StandardStart,
	DM_enWN_EV_SportStart,
	DM_enWN_EV_EcoStart,
	DM_enWN_EV_AutoStart,
	DM_enWN_EV_SnowStart,

	/*if not only case 1 has prompt information, we need more warning screen to display prompt information*/

	DM_enWN_WarningMaxId,
	DM_enWN_WarningInvaildId,
}DM_CFG_enWarningId;

/* driving mode warning status array length*/
#define	DM_WARNING_CONTROL_SATAUS_BYTE_NUM		(15)

// logic process function point typedef
typedef boolean (*IgnOnDelayTmrGetFun_t)(uint32 *time);
typedef boolean (*GeneralProcess_t)(void);

typedef struct
{
	GeneralProcess_t	VehicleInfoGet;
	IgnOnDelayTmrGetFun_t IgnOnDelayTmrGetFun;
	GeneralProcess_t	TransIntoNormal;
	GeneralProcess_t	TransExitNormal;
	GeneralProcess_t	FirstLogicProcess;
	GeneralProcess_t	GeneralLogicProcess;
}DM_DrvModAttr_t;

typedef struct
{
	uint8 u8DrvModStates;
	uint8 u8VehicleIndex;
	boolean u8DrvModEnable;
	uint32 u32IgnDelayTime;

	uint8 u8DrvModWarningControlStatus[DM_WARNING_CONTROL_SATAUS_BYTE_NUM];
	uint8 u8DrvModFixedControlStatus;
	uint8 u8HybridModControlStatus;

	union
    {
        uint32 u32PowerModeStatus; /*The status of power mode*/
        struct
        {
            uint16_least WN_Off               :1 ;
            uint16_least WN_Run               :1 ;
            uint16_least WN_AbnormalVoltage   :1 ;
            uint16_least Reserved             :29;
        }stPowerModeStatus;
    }unPowerModeStatus;
}DM_MainObject_t;

typedef struct
{
	uint8 u8DrvModSigValue;
	uint8 u8IMCActvSigValue;
	uint8 u8DrvModVehType;
}DM_SwitchSoundSigOut;

// fuel vehicle
boolean FDM_Fuel_IsFuelVehicle(void);
boolean FDM_Fuel_DelayTimeGet(uint32* time);
boolean FDM_Fuel_TransIntoNormal(void);
boolean FDM_Fuel_TransExitNormal(void);
boolean FDM_Fuel_FirstLogicProcess(void);
boolean FDM_Fuel_GeneralLogicProcess(void);
void FDM_Fuel_SecondTrigTimerCount(void);

// HEV+DHT PHEV+DHT vehicle
boolean FDM_HEVPHEVPS_IsHEVDHTVehicle(void);
boolean FDM_HEVPHEVPS_DelayTimeGet(uint32* time);
boolean FDM_HEVPHEVPS_TransIntoNormal(void);
boolean FDM_HEVPHEVPS_TransExitNormal(void);
boolean FDM_HEVPHEVPS_FirstLogicProcess(void);
boolean FDM_HEVPHEVPS_GeneralLogicProcess(void);

// PHEV+P2/P2+P4 vehicle
boolean FDM_PHEVP2P4_IsPHEVP2Vehicle(void);
boolean FDM_PHEVP2P4_DelayTimeGet(uint32* time);
boolean FDM_PHEVP2P4_TransIntoNormal(void);
boolean FDM_PHEVP2P4_TransExitNormal(void);
boolean FDM_PHEVP2P4_FirstLogicProcess(void);
boolean FDM_PHEVP2P4_GeneralLogicProcess(void);

// EV EV+one pedal
boolean FDM_EV_IsEVVehicle(void);
boolean FDM_EV_DelayTimeGet(uint32* time);
boolean FDM_EV_TransIntoNormal(void);
boolean FDM_EV_TransExitNormal(void);
boolean FDM_EV_FirstLogicProcess(void);
boolean FDM_EV_GeneralLogicProcess(void);

/* driving mode each vehicle logic process function*/
#define DM_CFG_LOGIC_PROCESS_INVAILD_ITEM		(0xFF)
#define	DM_CFG_LOGIC_PROCESS_ITEM				(4)
#define DM_CFG_LOGIC_PROCESS_ATTRIBUTE  {	\
	{										\
		FDM_Fuel_IsFuelVehicle, 			\
		FDM_Fuel_DelayTimeGet, 				\
		FDM_Fuel_TransIntoNormal, 			\
		FDM_Fuel_TransExitNormal, 			\
		FDM_Fuel_FirstLogicProcess,			\
		FDM_Fuel_GeneralLogicProcess		\
	},										\
											\
	{										\
		FDM_HEVPHEVPS_IsHEVDHTVehicle, 		\
		FDM_HEVPHEVPS_DelayTimeGet, 		\
		FDM_HEVPHEVPS_TransIntoNormal, 		\
		FDM_HEVPHEVPS_TransExitNormal, 		\
		FDM_HEVPHEVPS_FirstLogicProcess,	\
		FDM_HEVPHEVPS_GeneralLogicProcess	\
	},										\
											\
	{										\
		FDM_PHEVP2P4_IsPHEVP2Vehicle, 		\
		FDM_PHEVP2P4_DelayTimeGet, 			\
		FDM_PHEVP2P4_TransIntoNormal, 		\
		FDM_PHEVP2P4_TransExitNormal, 		\
		FDM_PHEVP2P4_FirstLogicProcess,		\
		FDM_PHEVP2P4_GeneralLogicProcess	\
	},										\
											\
	{										\
		FDM_EV_IsEVVehicle, 				\
		FDM_EV_DelayTimeGet, 				\
		FDM_EV_TransIntoNormal, 			\
		FDM_EV_TransExitNormal, 			\
		FDM_EV_FirstLogicProcess,			\
		FDM_EV_GeneralLogicProcess			\
	},										\
}

#if 0
#define	DM_CFG_ID_DRVMOD_TO_WRN		{																\
	(uint8)WN_enDM_B30_Standard,               /*V0.42	DM_enWN_B30_Standard			*/			\
	(uint8)WN_enDM_B30_Sport,                  /*V0.42	DM_enWN_B30_Sport				*/			\
	(uint8)WN_enDM_B30_ECO,                    /*V0.42	DM_enWN_B30_ECO,				*/			\
	(uint8)WN_enDM_B30_Snow,                   /*V0.42	DM_enWN_B30_Snow,				*/			\
	(uint8)WN_enDM_B30_Muddy,                  /*V0.42	DM_enWN_B30_Muddy,				*/			\
	(uint8)WN_enDM_B30_Sand,                   /*V0.42	DM_enWN_B30_Sand,				*/			\
	(uint8)WN_enDM_B30_OffRoad,                /*V0.42	DM_enWN_B30_OffRoad,			*/			\
																									\
	(uint8)WN_enDM_H9_StandardSelect,          /*V0.42	DM_enWN_H9_StandardSelect,		*/			\
	(uint8)WN_enDM_H9_SportSelect,             /*V0.42	DM_enWN_H9_SportSelect, 		*/			\
	(uint8)WN_enDM_H9_SnowSelect,              /*V0.42	DM_enWN_H9_SnowSelect,			*/			\
	(uint8)WN_enDM_H9_MuddySelect,             /*V0.42	DM_enWN_H9_MuddySelect, 		*/			\
	(uint8)WN_enDM_H9_SandSelect,              /*V0.42	DM_enWN_H9_SandSelect,			*/			\
	(uint8)WN_enDM_H9_ECOSelect,               /*V0.42	DM_enWN_H9_ECOSelect,			*/			\
																									\
	(uint8)WN_enDM_H9_ModeSwitch,              /*V0.42	DM_enWN_H9_ModeSwitch,			*/			\
	(uint8)WN_enDM_H9_4LModeSwitch,            /*V0.42	DM_enWN_H9_4LModeSwitch,		*/			\
																									\
	(uint8)WN_enDM_H9_B30_AUTOStart,           /*V0.42	DM_enWN_H9_B30_AUTOStart,		*/			\
	(uint8)WN_enDM_H9_B30_EVStart,             /*V0.42	DM_enWN_H9_B30_EVStart, 		*/			\
	(uint8)WN_enDM_H9_B30_SAVEStart,           /*V0.42	DM_enWN_H9_B30_SAVEStart,		*/			\
	(uint8)WN_enDM_H9_B30_SPORTStart,          /*V0.42	DM_enWN_H9_B30_SPORTStart,		*/			\
	(uint8)WN_enDM_H9_B30_AWDStart,            /*V0.42	DM_enWN_H9_B30_AWDStart,		*/			\
	(uint8)WN_enDM_H9_B30_SNOWStart,           /*V0.42	DM_enWN_H9_B30_SNOWStart,		*/			\
	(uint8)WN_enDM_H9_B30_MUDDYStart,          /*V0.42	DM_enWN_H9_B30_MUDDYStart,		*/			\
	(uint8)WN_enDM_H9_B30_SANDStart,           /*V0.42	DM_enWN_H9_B30_SANDStart,		*/			\
	(uint8)WN_enDM_H9_B30_SPORTPStart,         /*V0.42	DM_enWN_H9_B30_SPORTPStart, 	*/			\
																									\
	(uint8)WN_enDM_H9_Standard,                /*V0.42	DM_enWN_H9_Standard,			*/			\
	(uint8)WN_enDM_H9_Sport,                   /*V0.42	DM_enWN_H9_Sport,				*/			\
	(uint8)WN_enDM_H9_Snow,                    /*V0.42	DM_enWN_H9_Snow,				*/			\
	(uint8)WN_enDM_H9_Muddy,                   /*V0.42	DM_enWN_H9_Muddy,				*/			\
	(uint8)WN_enDM_H9_Sand,                    /*V0.42	DM_enWN_H9_Sand,				*/			\
	(uint8)WN_enDM_H9_ECO,                     /*V0.42	DM_enWN_H9_ECO, 				*/			\
	(uint8)WN_enDM_H9_4LMode,                  /*V0.42	DM_enWN_H9_4LMode,				*/			\
																									\
	(uint8)WN_enDM_V51EV_StandardStart,        /*V0.42	DM_enWN_V51EV_StandardStart,	*/			\
	(uint8)WN_enDM_V51EV_SportStart,           /*V0.42	DM_enWN_V51EV_SportStart,		*/			\
	(uint8)WN_enDM_V51EV_SnowSelec,            /*V0.42	DM_enWN_V51EV_SnowSelec,		*/			\
	(uint8)WN_enDM_V51EV_EcoStart,             /*V0.42	DM_enWN_V51EV_EcoStart, 		*/			\
	(uint8)WN_enDM_V51EV_AutoStart,            /*V0.42	DM_enWN_V51EV_AutoStart,		*/			\
	(uint8)WN_enDM_V51EV_SnowStart,            /*V0.42	DM_enWN_V51EV_SnowStart,		*/			\
	(uint8)WN_enDM_V51EV_SinPedalStart,        /*V0.42	DM_enWN_V51EV_SinPedalStart,	*/			\
	(uint8)WN_enDM_V51EV_SinPedalQuit,         /*V0.42	DM_enWN_V51EV_SinPedalQuit, 	*/			\
}
#endif

typedef struct
{
	DM_CFG_enDrvModId  ModStartIndex;
	DM_CFG_enDrvModId  ModEndIndex;
	DM_CFG_enWarningId ModScrStartIndex;
	DM_CFG_enWarningId ModScrEndIndex;
	DM_CFG_enWarningId Mod2ScrTab[DM_FUEL_MODE_LIST_NUMBER];
}DM_Fuel4_tstMod2Scr;

typedef struct
{
	DM_CFG_enDrvModId  ModStartIndex;
	DM_CFG_enDrvModId  ModEndIndex;
	DM_CFG_enWarningId ModScrStartIndex;
	DM_CFG_enWarningId ModScrEndIndex;
	DM_CFG_enWarningId Mod2ScrTab[DM_FUEL_MODE_LIST_NUMBER];

	DM_CFG_enDrvModId  ModSelectStartIndex;
	DM_CFG_enDrvModId  ModSelectEndIndex;
	DM_CFG_enWarningId ModSelectScrStartIndex;
	DM_CFG_enWarningId ModSelectScrEndIndex;
	DM_CFG_enWarningId ModSelect2ScrTab[DM_FUEL_MODE_SELECT_LIST_NUMBER];

	DM_CFG_enDrvModId  ModSwitchStartIndex;
	DM_CFG_enDrvModId  ModSwitchEndIndex;
	DM_CFG_enWarningId ModSwitchScrStartIndex;
	DM_CFG_enWarningId ModSwitchScrEndIndex;
	DM_CFG_enWarningId ModSwitch2ScrTab[DM_FUEL_MODE_SWITCH_LIST_NUMBER];
}DM_Fuel_tstMod2Scr;

typedef struct
{
	DM_CFG_enDrvModId  ModStartIndex;
	DM_CFG_enDrvModId  ModEndIndex;
	DM_CFG_enWarningId ModScrStartIndex;
	DM_CFG_enWarningId ModScrEndIndex;
	DM_CFG_enWarningId Mod2ScrTab[DM_EV_HEV_PHEV_MODE_START_LIST_NUMBER];
}DM_HEV_tstMod2Scr;

typedef struct
{
	DM_CFG_enDrvModId  ModStartIndex;
	DM_CFG_enDrvModId  ModEndIndex;
	DM_CFG_enWarningId ModScrStartIndex;
	DM_CFG_enWarningId ModScrEndIndex;
	DM_CFG_enWarningId Mod2ScrTab[DM_EV_HEV_PHEV_MODE_START_LIST_NUMBER];
}DM_PHEV_tstMod2Scr;

typedef struct
{
	DM_CFG_enDrvModId  ModStartIndex;
	DM_CFG_enDrvModId  ModEndIndex;
	DM_CFG_enWarningId ModScrStartIndex;
	DM_CFG_enWarningId ModScrEndIndex;
	DM_CFG_enWarningId Mod2ScrTab[DM_EV_HEV_PHEV_MODE_START_LIST_NUMBER];
}DM_EV_tstMod2Scr;

typedef struct
{
	uint32 u16SecondaryTriggerAutoModeTmr;
	uint32 u16SecondaryTrigger4LModeTmr;
	uint32 u16SecondaryTriggerXXModeTmr;
}FDM_tstDM_SecondaryTriggerTmrCnt;

/* dis signal to telltale id */
#define	DM_SIGNAL_DIS_2_TT_ICON					\
{												\
	DM_enTT_FUEL_STD,		/*Standard	 	*/	\
	DM_enTT_FUEL_SPORT,		/*Sport	  	 	*/	\
	DM_enTT_FUEL_SNOW,		/*Snow	  	 	*/	\
	DM_enTT_FUEL_MUD,		/*Mud			*/	\
	DM_enTT_FUEL_SAND,		/*Sand		 	*/	\
	DM_enTT_FUEL_4L, 		/*4L		 	*/	\
	DM_enTT_FUEL_ECO,		/*Economic	 	*/	\
	DM_enTT_NONE,			/*Unknown	 	*/	\
	DM_enTT_FUEL_IMC,		/*Auto		 	*/	\
	DM_enTT_FUEL_SPORTPLUS,	/*Sport+	 	*/	\
	DM_enTT_FUEL_OFFROAD,	/*Off road		*/	\
	DM_enTT_FUEL_STD,		/*Standard_2H	*/	\
	DM_enTT_FUEL_EXPERT, 	/*Expert		*/	\
	DM_enTT_FUEL_STD,		/*Standard_4H	*/	\
	DM_enTT_FAIL,			/*Failed		*/	\
	DM_enTT_NONE,			/*Invalid Value	*/	\
	DM_enTT_FUEL_SNOW,		/*Snow_4H		*/	\
	DM_enTT_FUEL_STD,		/*Normal_4L		*/	\
	DM_enTT_FUEL_ROCK,		/*Rock_4L		*/	\
	DM_enTT_FUEL_POTHOLE,	/*Pothole _4L	*/	\
	DM_enTT_FUEL_MUDSAND,	/*Mud/Sand_4L	*/	\
	DM_enTT_FUEL_MOUTAIN,	/*Mountain_4L	*/	\
	DM_enTT_FUEL_TURBO,		/*TURBO			*/	\
	DM_enTT_FUEL_RACE,		/*RACE			*/	\
	DM_enTT_FUEL_GRASSGRAVEL, /*GRASS/GRAVEL	*/	\
	DM_enTT_FUEL_UNEVEN,	/*UNEVEN Nex	*/	\
	DM_enTT_FUEL_WADE4H,	/*WADE_4H		*/	\
	DM_enTT_FUEL_WADE4L,	/*WADE_4L		*/	\
	DM_enTT_FUEL_2H,		/*2H			*/	\
	DM_enTT_FUEL_4H,		/*4H			*/	\
	DM_enTT_NONE,			/*Reserved		*/	\
	DM_enTT_NONE,			/*Reserved		*/	\
}

/* dis signal to "XX mode" id */
#define	DM_SIGNAL_DIS_2_WN_DMMODE					\
{													\
	enDM_StandardMode,								\
	enDM_SportMode,									\
	enDM_SnowMode,									\
	enDM_MuddyMode,									\
	enDM_SandMode,									\
	enDM_4LMode,									\
	enDM_EcoMode,									\
	enDM_WarningInvaildId,							\
	enDM_IMCMode,									\
	enDM_SportPlusMode,								\
	enDM_OffRoadMode,								\
	enDM_StandardMode,								\
	enDM_ExpertMode,								\
	enDM_StandardMode,								\
	enDM_WarningInvaildId,							\
	enDM_WarningInvaildId,							\
	enDM_SnowMode,									\
	enDM_StandardMode,								\
	enDM_RockMode,									\
	enDM_PotholeMode,								\
	enDM_MuddySandMode,								\
	enDM_MountainMode,								\
	enDM_TurboMode,									\
	enDM_RaceMode,									\
	enDM_GrassGravelMode,							\
	enDM_PotholeMode,								\
	enDM_Wade4HMode,								\
	enDM_Wade4LMode,								\
	enDM_2HMode,									\
	enDM_4HMode,									\
	enDM_WarningInvaildId,							\
	enDM_WarningInvaildId,							\
}

/* esp signal to "XX mode select " id */
#define	DM_SIGNAL_ESP_2_WN_DMSELECT		\
{										\
	enDM_WarningInvaildId,				\
	enDM_StandardSelect,				\
	enDM_SportSelect,                 	\
	enDM_SnowSelect,					\
	enDM_ExpertSelect,					\
	enDM_MuddySelect,					\
	enDM_2HSelect,				        \
	enDM_SandSelect,					\
	enDM_4HSelect,				        \
	enDM_4LSelect,						\
	enDM_EcoSelect,						\
	enDM_WarningInvaildId,				\
	enDM_SnowSelect,					\
	enDM_OffRoadSelect,					\
	enDM_SportPlusSelect,				\
	enDM_WarningInvaildId,				\
	enDM_StandardSelect,				\
	enDM_WarningInvaildId,				\
	enDM_StandardSelect,				\
	enDM_SnowSelect,					\
	enDM_StandardSelect,				\
	enDM_RockSelect,					\
	enDM_PotholeSelect,					\
	enDM_MuddySandSelect,				\
	enDM_MountainSelect,				\
	enDM_TurboSelect,					\
	enDM_RaceSelect,					\
	enDM_GrassGravelSelect,				\
	enDM_PotholeSelect,					\
	enDM_Wade4HSelect,					\
	enDM_Wade4LSelect,					\
	enDM_WarningInvaildId,				\
}

/* esp signal to "XX mode switch " id */
#define	DM_SIGNAL_ESP_2_WN_DMSWITCH		\
{										\
	enDM_WarningInvaildId,				\
	enDM_StandardSwitch,				\
	enDM_SportSwitch,					\
	enDM_SnowSwitch,					\
	enDM_ExpertSwitch,					\
	enDM_MuddySwitch,					\
	enDM_2HSwitch,				        \
	enDM_SandSwitch,					\
	enDM_4HSwitch,				        \
	enDM_WarningInvaildId,				\
	enDM_EcoSwitch,						\
	enDM_WarningInvaildId,				\
	enDM_SnowSwitch,					\
	enDM_OffRoadSwitch,					\
	enDM_SportPlusSwitch,				\
	enDM_WarningInvaildId,				\
	enDM_StandardSwitch,				\
	enDM_WarningInvaildId,				\
	enDM_StandardSwitch,				\
	enDM_SnowSwitch,					\
	enDM_StandardSwitch,				\
	enDM_RockSwitch,					\
	enDM_PotholeSwitch,					\
	enDM_MuddySandSwitch,				\
	enDM_MountainSwitch,				\
	enDM_TurboSwitch,					\
	enDM_RaceSwitch,				    \
	enDM_GrassGravelSwitch,				\
	enDM_PotholeSwitch,					\
	enDM_Wade4HSwitch,				    \
	enDM_Wade4LSwitch,				    \
	enDM_WarningInvaildId,				\
}

/* Dis signal to match Esp signal */
#define	DM_SIGNAL_ESP_2_WN_DMSWITCH_TOMODE		\
{												\
	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F,		\
	DM_SIGNAL_DRIVINGMODDIS_STANDARD,			\
	DM_SIGNAL_DRIVINGMODDIS_SPORT,				\
	DM_SIGNAL_DRIVINGMODDIS_SNOW,				\
	DM_SIGNAL_DRIVINGMODDIS_EXPERT,				\
	DM_SIGNAL_DRIVINGMODDIS_MUD,				\
	DM_SIGNAL_DRIVINGMODDIS_2H,		            \
	DM_SIGNAL_DRIVINGMODDIS_SAND,				\
	DM_SIGNAL_DRIVINGMODDIS_4H,		            \
	DM_SIGNAL_DRIVINGMODDIS_4L,					\
	DM_SIGNAL_DRIVINGMODDIS_ECONOMIC,			\
	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F,		\
	DM_SIGNAL_DRIVINGMODDIS_SNOW,				\
	DM_SIGNAL_DRIVINGMODDIS_OFFROAD,			\
	DM_SIGNAL_DRIVINGMODDIS_SPORTPLUS,			\
	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F,		\
	DM_SIGNAL_DRIVINGMODDIS_STANDARD_2H,		\
	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F,		\
	DM_SIGNAL_DRIVINGMODDIS_STANDARD_4H,		\
	DM_SIGNAL_DRIVINGMODDIS_SNOW_4H,			\
	DM_SIGNAL_DRIVINGMODDIS_NORMAL_4L,			\
	DM_SIGNAL_DRIVINGMODDIS_ROCK_4l,			\
	DM_SIGNAL_DRIVINGMODDIS_POTHLE_4L,			\
	DM_SIGNAL_DRIVINGMODDIS_MUDSAND_4L,		    \
	DM_SIGNAL_DRIVINGMODDIS_MOUNTAIN_4L,		\
	DM_SIGNAL_DRIVINGMODDIS_TURBO,				\
	DM_SIGNAL_DRIVINGMODDIS_RACE,				\
	DM_SIGNAL_DRIVINGMODDIS_GRASSGRAVEL,		\
	DM_SIGNAL_DRIVINGMODDIS_UNEVENNEX,			\
	DM_SIGNAL_DRIVINGMODDIS_WADE_4H,			\
	DM_SIGNAL_DRIVINGMODDIS_WADE_4L,			\
	DM_SIGNAL_DRIVINGMODDIS_INVALID_0x1F,		\
}

/* PHEV+PARA_P2: hcuOper signal to telltale id */
#define	DM_SIGNAL_HCUOPER_2_TT_ICONPP2		\
{									\
	DM_enTT_PHEVP2_HMHEV,			\
	DM_enTT_PHEVP2_HMEV,			\
	DM_enTT_PHEVP2_HMSAVE,			\
	DM_enTT_HMFAIL,					\
}

/* PHEV+PS/PS_P4: hybMod signal to telltale id */
#define	DM_SIGNAL_HCUHYB_2_TT_ICONPS		\
{									\
	DM_enTT_PHEVPS_HMHEV,			\
	DM_enTT_PHEVPS_HMEV,			\
	DM_enTT_HMFAIL,					\
	DM_enTT_HMFAIL,					\
}

/* HEV+PS/PS_P4, PHEV+PS/PS_P4: signal to telltale id */
#define	DM_SIGNAL_HCU_2_TT_ICON		\
{									\
    DM_enTT_HEV_NORMAL,				\
    DM_enTT_HEV_EV,					\
    DM_enTT_HEV_SAVE,				\
    DM_enTT_HEV_SPORT,				\
    DM_enTT_HEV_AWD,				\
    DM_enTT_HEV_SNOW,				\
    DM_enTT_HEV_MUD,				\
    DM_enTT_HEV_SAND,				\
    DM_enTT_HEV_ECO,				\
    DM_enTT_HEV_SPORTPLUS,			\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
}

/* HEV+PS/PS_P4, PHEV+PS/PS_P4: signal to "XX mode start" id */
#define	DM_SIGNAL_HCU_2_WN_DMSTART		\
{										\
	enDM_NORMALStart,					\
	enDM_EvStart,						\
	enDM_SaveStart,						\
	enDM_SportStart,					\
	enDM_AwdStart,						\
	enDM_SnowStart,						\
	enDM_MuddyStart,					\
	enDM_SandStart,						\
	enDM_EcoStart,						\
	enDM_SportPlusStart,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
}

/* PHEV+P2/P2_P4: dis signal to telltale id */
#define	DM_SIGNAL_HCUDISP_2_TT_ICON		\
{									\
    DM_enTT_HEV_NORMAL,				\
    DM_enTT_HEV_EV,					\
    DM_enTT_HEV_SAVE,				\
    DM_enTT_HEV_SPORT,				\
    DM_enTT_HEV_AWD,				\
    DM_enTT_HEV_SNOW,				\
    DM_enTT_HEV_MUD,				\
    DM_enTT_HEV_SAND,				\
    DM_enTT_FAIL,					\
    DM_enTT_HEV_SPORTPLUS,			\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
    DM_enTT_FAIL,					\
}

/* PHEV+P2/P2_P4: dis signal to "XX mode start" id */
#define	DM_SIGNAL_HCUDISP_2_WN_DMSTART	\
{										\
	enDM_NORMALStart,					\
	enDM_EvStart,						\
	enDM_SaveStart,						\
	enDM_SportStart,					\
	enDM_AwdStart,						\
	enDM_SnowStart,						\
	enDM_MuddyStart,					\
	enDM_SandStart,						\
	enDM_WarningInvaildId,				\
	enDM_SportPlusStart,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
}

/* EV: signal to telltale id */
#define	DM_SIGNAL_VCUDRVMOD_2_TT_ICON	\
{										\
    DM_enTT_EV_NORMAL,					\
    DM_enTT_EV_SPORT,					\
    DM_enTT_EV_ECO,						\
    DM_enTT_NONE,						\
    DM_enTT_EV_AUTO,					\
    DM_enTT_EV_SNOW,					\
    DM_enTT_NONE,						\
    DM_enTT_NONE,						\
}

/* EV: signal to "XX mode start" id */
#define DM_SIGNAL_VCUDRVMOD_2_WN_START	\
{										\
	enDM_StandardStart,					\
	enDM_SportStart,					\
	enDM_EcoStart,						\
	enDM_WarningInvaildId,				\
	enDM_NORMALStart, 					\
	enDM_SnowStart, 					\
	enDM_WarningInvaildId,				\
	enDM_WarningInvaildId,				\
}

/*Drive mode id transform to waring id table*/
#define	DM_FUEL4_DMMODE_2_WN_SCREEN									\
{																	\
	DM_FUEL_MODE_START,												\
	DM_FUEL_MODE_END,												\
	DM_FUEL4_SCR_MODE_START,										\
	DM_FUEL4_SCR_MODE_END,											\
	{																\
		DM_enWN_FUEL4_Standard,		/*enDM_StandardMode,	*/		\
		DM_enWN_FUEL4_Sport,		/*enDM_SportMode, 		*/		\
		DM_enWN_FUEL4_Snow,			/*enDM_SnowMode,		*/		\
		DM_enWN_FUEL4_Muddy,		/*enDM_MuddyMode, 		*/		\
		DM_enWN_FUEL4_Sand,			/*enDM_SandMode,		*/		\
		DM_enWN_FUEL4_4L,			/*enDM_4LMode,			*/		\
		DM_enWN_FUEL4_ECO,			/*enDM_EcoMode,			*/		\
		DM_enWN_FUEL4_IMC,			/*enDM_IMCMode,			*/		\
		DM_enWN_FUEL4_SportPlus,	/*enDM_SportPlusMode,	*/		\
		DM_enWN_FUEL4_OffRoad,		/*enDM_OffRoadMode,		*/		\
		DM_enWN_FUEL4_Expert,		/*enDM_ExpertMode,		*/		\
		DM_enWN_FUEL4_Rock,			/*enDM_RockMode,		*/		\
		DM_enWN_FUEL4_Pothole,		/*enDM_PotholeMode,		*/		\
		DM_enWN_FUEL4_MuddySand,	/*enDM_MuddySandMode,	*/		\
		DM_enWN_FUEL4_Mountain,		/*enDM_MountainMode,	*/		\
		DM_enWN_FUEL4_Turbo, 		/*enDM_TurboMode,		*/		\
		DM_enWN_FUEL4_Race,			/*enDM_RaceMode,		*/		\
		DM_enWN_FUEL4_GrassGravel,	/*enDM_Grass/GravelMode,*/		\
		DM_enWN_FUEL4_Uneven,		/*enDM_UnevenMode,		*/		\
		DM_enWN_FUEL4_Wade4H,		/*enDM_Wade4HMode,		*/		\
		DM_enWN_FUEL4_Wade4L,		/*enDM_Wade4LMode,		*/		\
		DM_enWN_FUEL4_2H,			/*enDM_2H,				*/		\
		DM_enWN_FUEL4_4H,			/*enDM_4H,				*/		\
	},																\
}

#define	DM_FUEL_DMMODE_2_WN_SCREEN										\
{																		\
	DM_FUEL_MODE_START,													\
	DM_FUEL_MODE_END,													\
	DM_FUEL_SCR_MODE_START,												\
	DM_FUEL_SCR_MODE_END,												\
	{																	\
		DM_enWN_FUEL_Standard,			/*enDM_StandardMode,	*/		\
		DM_enWN_FUEL_Sport,				/*enDM_SportMode, 		*/		\
		DM_enWN_FUEL_Snow,				/*enDM_SnowMode,		*/		\
		DM_enWN_FUEL_Muddy,				/*enDM_MuddyMode, 		*/		\
		DM_enWN_FUEL_Sand,				/*enDM_SandMode,		*/		\
		DM_enWN_FUEL_4L,				/*enDM_4LMode,			*/		\
		DM_enWN_FUEL_ECO,				/*enDM_EcoMode,			*/		\
		DM_enWN_FUEL_IMC,				/*enDM_IMCMode,			*/		\
		DM_enWN_FUEL_SportPlus,			/*enDM_SportPlusMode,	*/		\
		DM_enWN_FUEL_OffRoad,			/*enDM_OffRoadMode,		*/		\
		DM_enWN_FUEL_Expert,			/*enDM_ExpertMode,		*/		\
		DM_enWN_FUEL_Rock,				/*enDM_RockMode,		*/		\
		DM_enWN_FUEL_Pothole,			/*enDM_PotholeMode,		*/		\
		DM_enWN_FUEL_MuddySand,			/*enDM_MuddySandMode,	*/		\
		DM_enWN_FUEL_Mountain,			/*enDM_MountainMode,	*/		\
		DM_enWN_FUEL_Turbo,				/*enDM_TurboMode,		*/		\
		DM_enWN_FUEL_Race,				/*enDM_RaceMode,		*/		\
		DM_enWN_FUEL_GrassGravel,		/*enDM_GrassGravelMode,	*/		\
		DM_enWN_FUEL_Uneven,			/*enDM_UnevenMode,		*/		\
		DM_enWN_FUEL_Wade4H,			/*enDM_Wade4HMode,		*/		\
		DM_enWN_FUEL_Wade4L,			/*enDM_Wade4LMode,		*/		\
		DM_enWN_FUEL_2H,				/*enDM_2HMode,			*/		\
		DM_enWN_FUEL_4H,				/*enDM_4HMode,			*/		\
	},														        	\
																		\
	DM_FUEL_MODE_SELECT_START,											\
	DM_FUEL_MODE_SELECT_END,											\
	DM_FUEL_SCR_MODE_SELECT_START,										\
	DM_FUEL_SCR_MODE_SELECT_END,										\
	{																	\
		DM_enWN_FUEL_StandardSelect,	 /*enDM_StandardSelect,		*/	\
		DM_enWN_FUEL_SportSelect,		 /*enDM_SportSelect,		*/	\
		DM_enWN_FUEL_SnowSelect,		 /*enDM_SnowSelect,			*/	\
		DM_enWN_FUEL_ExpertSelect,		 /*enDM_ExpertSelect,		*/	\
		DM_enWN_FUEL_MuddySelect,		 /*enDM_MuddySelect,		*/	\
		DM_enWN_FUEL_2HSelect,		     /*enDM_2HSelect,		    */	\
		DM_enWN_FUEL_SandSelect,		 /*enDM_SandSelect,			*/	\
		DM_enWN_FUEL_4HSelect,		     /*enDM_4HSelect,			*/	\
		DM_enWN_FUEL_4LSelect,			 /*enDM_4LSelect,			*/	\
		DM_enWN_FUEL_ECOSelect, 		 /*enDM_EcoSelect, 			*/	\
		DM_enWN_FUEL_OffRoadSelect, 	 /*enDM_OffRoadSelect, 		*/	\
		DM_enWN_FUEL_SportPlusSelect,	 /*enDM_SportPlusSelect,	*/	\
		DM_enWN_FUEL_RockSelect,		 /*enDM_RockSelect,			*/	\
		DM_enWN_FUEL_PotholeSelect, 	 /*enDM_PotholeSelect, 		*/	\
		DM_enWN_FUEL_MuddySandSelect,	 /*enDM_MuddySandSelect,	*/	\
		DM_enWN_FUEL_MountainSelect,	 /*enDM_MountainSelect,		*/	\
		DM_enWN_FUEL_TurboSelect,		 /*enDM_TurboSelect,		*/	\
		DM_enWN_FUEL_RaceSelect,		 /*enDM_RaceSelect,		    */	\
        DM_enWN_FUEL_GrassGravelSelect,	 /*enDM_GrassGravelSelect,	*/	\
    	DM_enWN_FUEL_UnevenNexSelect,	 /*enDM_UnevenNexSelect,	*/	\
   	 	DM_enWN_FUEL_Wade4HSelect,		 /*enDM_Wade4HSelect,		*/	\
    	DM_enWN_FUEL_Wade4LSelect,		 /*enDM_Wade4LSelect,		*/	\
		DM_enWN_FUEL_AutoSelect,		 /*enDM_AutoSelect,         */	\
	},																	\
																		\
	DM_FUEL_MODE_SWITCH_START,											\
	DM_FUEL_MODE_SWITCH_END,											\
	DM_FUEL_SCR_MODE_SWITCH_START,										\
	DM_FUEL_SCR_MODE_SWITCH_END,										\
	{																	\
		DM_enWN_FUEL_StandardModeSwitch,	/*enDM_StandardSwitch,	*/	\
		DM_enWN_FUEL_SportModeSwitch,		/*enDM_SportSwitch,		*/	\
		DM_enWN_FUEL_SnowModeSwitch,		/*enDM_SnowSwitch,		*/	\
		DM_enWN_FUEL_ExpertModeSwitch,		/*enDM_ExpertSwitch,	*/	\
		DM_enWN_FUEL_MuddyModeSwitch,		/*enDM_MuddySwitch,		*/	\
		DM_enWN_FUEL_2HModeSwitch,		    /*enDM_2HSwitch,		*/	\
		DM_enWN_FUEL_SandModeSwitch,		/*enDM_SandSwitch,		*/	\
		DM_enWN_FUEL_4HModeSwitch,		    /*enDM_4HSwitch,		*/	\
		DM_enWN_FUEL_4LModeSwitch,			/*enDM_4LSwitch,		*/	\
		DM_enWN_FUEL_ECOModeSwitch, 		/*enDM_EcoSwitch, 		*/	\
		DM_enWN_FUEL_OffRoadModeSwitch, 	/*enDM_OffRoadSwitch, 	*/	\
		DM_enWN_FUEL_SportPlusModeSwitch,	/*enDM_SportPlusSwitch,	*/	\
		DM_enWN_FUEL_RockModeSwitch,		/*enDM_RockSwitch,		*/	\
		DM_enWN_FUEL_PotholeModeSwitch, 	/*enDM_PotholeSwitch, 	*/	\
		DM_enWN_FUEL_MuddySandModeSwitch,	/*enDM_MuddySandSwitch,	*/	\
		DM_enWN_FUEL_MountainModeSwitch,	/*enDM_MountainSwitch,	*/	\
		DM_enWN_FUEL_TurboSwitch,			/*enDM_TurboSwitch,		*/	\
		DM_enWN_FUEL_RaceModeSwitch,		/*enDM_RaceSwitch,		*/	\
		DM_enWN_FUEL_GrassGravelModeSwitch,  /*enDM_GrassGravelSwitch, */	\
		DM_enWN_FUEL_UnevenNexModeSwitch,	/*enDM_UnevenNexSwitch,	*/	\
		DM_enWN_FUEL_Wade4HModeSwitch, 		/*enDM_Wade4HSwitch,	*/	\
		DM_enWN_FUEL_Wade4LModeSwitch,		/*enDM_Wade4LSwitch,	*/	\
		DM_enWN_FUEL_AutoModeSwitch,		/*enDM_AutoSwitch,		*/	\
	},																	\
}

#define	DM_DHT_DMSTART_2_WN_SCREEN											\
{																			\
	DM_EV_HEV_PHEV_MODE_START_START,										\
	DM_EV_HEV_PHEV_MODE_START_END,											\
	DM_HEV_PHEV_SCR_MODE_START_START,										\
	DM_HEV_PHEV_SCR_MODE_START_END,											\
	{																		\
		DM_enWN_HEV_PHEV_NORMALStart, 	/*enDM_NORMAL, 					*/	\
		DM_enWN_HEV_PHEV_EVStart,		/*enDM_EvStart,					*/	\
		DM_enWN_HEV_PHEV_SAVEStart, 	/*enDM_SaveStart, 				*/	\
		DM_enWN_HEV_PHEV_SPORTStart,	/*enDM_SportStart,				*/	\
		DM_enWN_HEV_PHEV_AWDStart,		/*enDM_AwdStart,				*/	\
		DM_enWN_HEV_PHEV_SNOWStart, 	/*enDM_SnowStart, 				*/	\
		DM_enWN_HEV_PHEV_MUDDYStart,	/*enDM_MuddyStart,				*/	\
		DM_enWN_HEV_PHEV_SANDStart, 	/*enDM_SandStart, 				*/	\
		DM_enWN_HEV_PHEV_ECOStart,		/*enDM_EcoStart,				*/	\
		DM_enWN_HEV_PHEV_SPORTPStart,	/*enDM_SportPlusStart,			*/	\
		DM_enWN_WarningInvaildId,		/*enDM_StandardStart			*/	\
	}																		\
}

#define	DM_PHEV_DMSTART_2_WN_SCREEN											\
{																			\
	DM_EV_HEV_PHEV_MODE_START_START,										\
	DM_EV_HEV_PHEV_MODE_START_END,											\
	DM_HEV_PHEV_SCR_MODE_START_START,										\
	DM_HEV_PHEV_SCR_MODE_START_END,											\
	{																		\
		DM_enWN_HEV_PHEV_NORMALStart, 	/*enDM_NORMALStart, 			*/	\
		DM_enWN_HEV_PHEV_EVStart,		/*enDM_EvStart,					*/	\
		DM_enWN_HEV_PHEV_SAVEStart, 	/*enDM_SaveStart, 				*/	\
		DM_enWN_HEV_PHEV_SPORTStart,	/*enDM_SportStart,				*/	\
		DM_enWN_HEV_PHEV_AWDStart,		/*enDM_AwdStart,				*/	\
		DM_enWN_HEV_PHEV_SNOWStart, 	/*enDM_SnowStart, 				*/	\
		DM_enWN_HEV_PHEV_MUDDYStart,	/*enDM_MuddyStart,				*/	\
		DM_enWN_HEV_PHEV_SANDStart, 	/*enDM_SandStart, 				*/	\
		DM_enWN_WarningInvaildId,		/*enDM_EcoStart,				*/	\
		DM_enWN_HEV_PHEV_SPORTPStart,	/*enDM_SportPlusStart,			*/	\
		DM_enWN_WarningInvaildId,		/*enDM_StandardStart			*/	\
	}																		\
}

#define	DM_EV_DRVMOD_2_WN_SCREEN											\
{																			\
																			\
	DM_EV_HEV_PHEV_MODE_START_START,										\
	DM_EV_HEV_PHEV_MODE_START_END,											\
	DM_EV_SCR_MODE_START_START,												\
	DM_EV_SCR_MODE_START_END,												\
	{																		\
		DM_enWN_EV_AutoStart, 			/*enDM_AutoStart, 				*/	\
		DM_enWN_WarningInvaildId,		/*enDM_EvStart,					*/	\
		DM_enWN_WarningInvaildId, 		/*enDM_SaveStart, 				*/	\
		DM_enWN_EV_SportStart,			/*enDM_SportStart,				*/	\
		DM_enWN_WarningInvaildId,		/*enDM_AwdStart,				*/	\
		DM_enWN_EV_SnowStart, 			/*enDM_SnowStart, 				*/	\
		DM_enWN_WarningInvaildId,		/*enDM_MuddyStart,				*/	\
		DM_enWN_WarningInvaildId, 		/*enDM_SandStart, 				*/	\
		DM_enWN_EV_EcoStart,			/*enDM_EcoStart,				*/	\
		DM_enWN_WarningInvaildId,		/*enDM_SportPlusStart,			*/	\
		DM_enWN_EV_StandardStart,		/*enDM_StandardStart			*/	\
	},																		\
}

#endif

