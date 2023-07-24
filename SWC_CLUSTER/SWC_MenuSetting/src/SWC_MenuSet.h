/**********************************************************************************************************
*                                                                                                         *
*                          CONFIDENTIAL NOBO CORPORATION                              					  *
*                                                                                                         *
* Copyright @ 2019 - 2021 Nobo Automotive Technologies Co.,Ltd.                                           *
* All Rights Reserved.                                                                                    *
*                                                                                                         *
* Redistribution and use in source and binary forms, with or without                                      *
* modification, are NOT permitted except as agreed by                                                     *
* Nobo Automotive Technologies Co.,Ltd.                                                                   *
*                                                                                                         *
* Unless required by applicable law or agreed to in writing, software                                     *
* distributed under the License is distributed on an "AS IS" BASIS,                                       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*File Name   : SWC_MenuSet.h                                                                           *
*                                                                                                         *
*Description : MenuSet module application head file.                                      *
*                                                                                                         *
*Author      : hai hu                                                                       *
*                                                                                                         *
*Compiler    : Green Hills  [MULTI IDE 6.1.6]                                                             *
*                                                                                                         *
*Hardware    : Renesas microcontroller RH850 Family [RH850/D1M2]                                          *
*                                                                                                         *
*Version     : 1.0.0                                                                                      *
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef MenuSet_app_H
#define MenuSet_app_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
//#include "IPC_ClusterApp.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

/**********************************************************************************************************
*	Output Application Interface Accuary            													  *
**********************************************************************************************************/

#include "Std_Types.h"
#include "IPC_ClusterApp.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/


/**********************************************************************************************************
*																								          *
*																								          *
*	System Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

/*****************************************************************************
*                                 Type Decleration                           *
*----------------------------------------------------------------------------*
* Decleration of type shall be accompanied by a comment that explains the    *
* purpose and usage of the type.                                             *
******************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_D03
#define Menu_PROJECT_TYPE_D03   (1u)
#endif
/* Unit */
#define MENUSET_METRIC_UNIT		(0U)
#define MENUSET_IMPERIAL_UNIT	(1U)
	
#define MENUSET_NORMAL_METRIC_UNIT              (0U)
#define MENUSET_JANPAN_METRIC_UNIT              (1U)
#define MENUSET_ENGLISH_IMPERIAL_UNIT           (2U)
#define MENUSET_AMERICA_IMPERIAL_UNIT           (3U)
	
#define MENUSET_SPEED_KM_H                      (0U)
#define MENUSET_SPEED_MPH                       (1U)
	
#define MENUSET_DISTANCE_KM                     (0U)
#define MENUSET_DISTANCE_MILE                   (1U)
	
#define MENUSET_FUEL_L_100KM                    (0U)
#define MENUSET_FUEL_KM_L                       (1U)
#define MENUSET_FUEL_MPG_UK                     (2U)
#define MENUSET_FUEL_MPG_US                     (3U)
	
#define MENUSET_PRESSURE_KPA                    (0U)
#define MENUSET_PRESSURE_PSI                    (1U)
#define MENUSET_PRESSURE_BAR                    (2U)
	
#define MENUSET_TEMPERATURE_CELSIUS             (0U)
#define MENUSET_TEMPERATURE_FAHRENHEIT          (1U)

/* Theme */
#define MENUSET_CLASSIC_THEME	(0U)
//#define MENUSET_SPORTS_THEME	(1U)
//#define MENUSET_SCIENCE_THEME	(2U)

#define MENUSET_SCIENCE_THEME	                (0U)
#define MENUSET_FASHION_THEME                   (1U)
#define MENUSET_SPORTS_THEME                    (2U)
#define MENUSET_DEFAULT_THEME                   (MENUSET_SCIENCE_THEME)

/* sound volume */
#define MENUSET_SOUND_VOLUME_DEFAULT            (7U)
#define MENUSET_SOUND_VOLUME_MIN                (1U)
#define MENUSET_SOUND_VOLUME_MAX                (10U)

/* language */
#define MENUSET_LANGUAGE_CHINESE                (0U) /* 汉语 */
#define MENUSET_LANGUAGE_ENGLISH                (1U) /* 英语 */
#define MENUSET_LANGUAGE_RUSSIAN                (2U) /* 俄语 */
#define MENUSET_LANGUAGE_SPAISH                 (3U) /* 西班牙语 */
#define MENUSET_LANGUAGE_PORTUGUESE             (4U) /* 葡萄牙语 */
#define MENUSET_LANGUAGE_GERMAN                 (5U) /* 德语 */
#define MENUSET_LANGUAGE_FRENCH                 (6U) /* 法语 */
#define MENUSET_LANGUAGE_ITALIAN                (7U) /* 意大利语 */
#define MENUSET_LANGUAGE_ARABIC                 (8U) /* 阿拉伯语 */
#define MENUSET_LANGUAGE_THAI                   (9U) /* 泰语 */
#define MENUSET_LANGUAGE_UKRAINIAN              (10U) /* 乌克兰语 */
#define MENUSET_LANGUAGE_INDONESIAN             (11U) /* 印尼语 */

/* skin color */
#define MENUSET_SKINCOLOR_BLUE                  (0U)
#define MENUSET_SKINCOLOR_RED                   (1U)
#define MENUSET_SKINCOLOR_GOLDEN                (2U)

/* over speed */
#define MENUSET_SPEED_SWITCH_OFF                (0U)
#define MENUSET_SPEED_SWITCH_ON                 (1U)

#define MENUSET_SPEED_LIMIT_KM_H_DEFAULT        (120U)
#define MENUSET_SPEED_LIMIT_MPH_DEFAULT         (75U)

#define MENUSET_SPEED_LIMIT_MAX                 (48U)
#define MENUSET_SPEED_DEFAULT                   (24U)
#define MENUSET_SPEED_DEFAULT_MIN               (6U)

#define MENUSET_SPEED_OS_LIMIT_FACTORY          (5U)
#define MENUSET_SPEED_IMPERIA_CONTROL           (2U)

#define MENUSET_SPEED_LIST_ROW                  (49U)
#define MENUSET_SPEED_LIST_COLUMN               (3U)
#define MENUSET_UNIT_CHANGE_ERROR               (0xFF)

/*soc to mcu set item*/
#define SetNaviLimitSpeedValue		(0U)
#define SetNaviLimitSpeedEnable		(1U)
#define SetLanguage					(2U)
#define SetClusterTheme				(3U)
#define SetOdometerUnits			(4U)
#define SetTemperatureUnits			(5U)
#define SetTirePressureUnits		(6U)
#define SetTripComputerId			(7U)
#define SetInteractiveCard			(8U)
#define SetDrivingModeMemorySwitch	(9U)
#define SetTimeUnits				(10U)
#define SetHighwayAssistSwitch		(11U)
#define SetLaneChangeAssistSwitch	(12U)
#define SetSunriseSunsetMode		(13U)
#define SetAutoMode					(14U)
#define SetClusterDrivingMode		(15U)
#define SetClusterDrivingMem		(16U)
#define SetDataSyncFlg				(18U)
/*soc to mcu set OffroadInfo*/
#define SetBaroPressure             (0U)
#define SetHeilvl                   (1U)
#define SetHeilvlSign               (2U)
#define SetPitchAngle               (3U)
#define SetPitchAngleSign           (4U)
#define setGeoGraphic               (5U)
#define setSteerWheel               (6U)
#define setSteerWheelSign           (7U)

/*print nvm fail count max*/
#define NVM_WRITE_FAIL_MAX	(5U)

/**********************************************************************************************************
* IPC Rte Interface Type Definenation                                                                     *
**********************************************************************************************************/

typedef Std_ReturnType (*MenuSet_RteWrite)(uint8 Data);
typedef Std_ReturnType (*MenuSet_IPCSend)(uint8 Data);

typedef enum
{
	MENUSET_UNIT_SYSTEM,
	MENUSET_SPEED_UNIT,
	MENUSET_DISTANCE_UNIT,
	MENUSET_FUEL_CONSUMPTION_UNIT,
	MENUSET_TEMP_UNIT,
	MENUSET_PRESS_UNIT,
	MENUSET_THEME,
	MENUSET_LANGUAGE,
	MENUSET_NAVILIMITSPEED,
	MENUSET_TYPE_MAX
}MENUSET_TYPE;
#if 0
typedef struct
{
    /*set over speed(30~240km/h)/(20~150mph)*/
    uint16 NaviLimitSpeed;
    /*0:OFF turn off over speed warning; 1:ON Turn on over speed warning;*/
    uint8 OverSpeedEnable;
    uint8 Language;
    /*0:default theme;*/
    uint8 ClusterTheme;
    /*0:Normal Metric; 1:Janpan Metric; 2:Imperial UK; 3:Imperial US;*/
    uint8 OdometerUnit;
    /*0:Celsius  ; 1:Fahrenheit*/
    uint8 TemperatureUnit;
    /*0: kpa ; 1:psi ; 2:bar*/
    uint8 TirePressureUnit;
    uint8 TripComputerId;
    uint8 InteractiveCarId;
    /*0: switch off  ; 1:switch on ; 2:Invalid*/
    uint8 DrivingModeMemorySwitch;
    /*0:24 hours   ; 1:12 hours*/
    uint8 TimeUnit;
    uint8 HighwayAssistSwitch;
    uint8 LaneChangeAssistSwitch;
}MenuSetData_t;
#endif

typedef struct
{
	uint8 MenuSet_array[MENUSET_TYPE_MAX];
}MenuSet_str;

typedef struct
{
	MENUSET_TYPE type;
	//void (*callBackFunc)(void);
	MenuSet_RteWrite RteWrite;
	MenuSet_IPCSend IPC_Send;
}MenuSetAttribute_t;

typedef struct
{
	uint8 MenuSetTypeNum;
	MenuSetAttribute_t* MenuSetAttribute;
}MenuSetObject_t;

typedef struct
{
	uint8 OverSpeedEnable;
	uint8 UnitSystem;
	uint8 Language;
	uint8 Outside_Temperature_Unit;
	uint8 TPMS_Unit;
}MenuSet_Vconfig_t;

/*can output data struct*/
typedef struct
{
	uint8 Menu_LagueSet;
	uint8 Menu_CurrTheme;
}MenuCanOutput_t;

/**********************************************************************************************************
*																								          *
*	Rte Configuration																				  *
*																								          *
**********************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IPC_Send(IPC_M2S_ClusterAppAPPMenuSetting_t *data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MenuSet_ppSR_Element(MenuSetData_t *data);
FUNC(void, RTE_CODE) IPC_API_ReceiveMenuSettingCallback(uint8 *data);
FUNC(void, RTE_CODE) IPC_API_ReceiveMenuThemeCallback(uint8 *data);
FUNC(void, RTE_CODE) IPC_API_ReceiveMenuOffroadInfoCallback(uint8 *data);

#define Rte_Write_ppSR_SWCNormal_MenuSet_Element Rte_Write_MenuSet_ppSR_Element
#define Rte_Call_rpCS_MenuSet_IPC_Send Rte_Call_IPC_Send
//#define Rte_IPC_API_ReceiveMenuSettingCallback IPC_API_ReceiveMenuSettingCallback
/*****************************************************************************
*                                 Global Function Prototypes                 *
******************************************************************************/
extern void MenuSetMdl_MenuSet_cold_init(void);
extern void MenuSetMdl_MenuSet_warm_init(void);
extern void MenuSetMdl_MenuSet_app_tsk(void);

#endif
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/

