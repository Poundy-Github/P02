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
*File Name   : TM_Config.h                                                                                *
*                                                                                                         *
*Description : Tachometer module config file.                                                 		      *
*                                                                                                         *
*Author      : Chao feng                                                                                  *
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
#ifndef TM_CFG_H
#define TM_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "Rte_Common_Normal.h"
#include "logger.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
//#include "Com.h"
#include "VConfig.h"
#include "SWC_IPC_Application.h"
#ifndef TM_COMMON_RTE_H
#define TM_COMMON_RTE_H
#endif

/* TM Log */
#define SWC_TM_LOGOUT_ENBLE (TRUE)
#define SWC_TM_PRINT_WARN   fuel_warn
/**********************************************************************************************************
*																										  *
*																										  *
*	Project Configuration																				  *
*																										  *
*																										  *
**********************************************************************************************************/
	
#define TM_CFG_D077_PROJECT
#define TM_CFG_V71_PROJECT
#define TM_CFG_B30_PROJECT
#define TM_CFG_P01_PROJECT

#ifdef GWM_V35_PROJECT_TYPE_B02
#define GWM_V35_PROJECT_TYPE_B02_TM
#elif defined GWM_V35_PROJECT_TYPE_B03
#define GWM_V35_PROJECT_TYPE_B03_TM
#elif defined GWM_V35_PROJECT_TYPE_P03
#define GWM_V35_PROJECT_TYPE_P03_TM
#elif defined GWM_V35_PROJECT_TYPE_P05
#define GWM_V35_PROJECT_TYPE_P05_TM
#elif defined GWM_V35_PROJECT_TYPE_A07
#define GWM_V35_PROJECT_TYPE_A07_TM
#elif defined GWM_V35_PROJECT_TYPE_D01
#define GWM_V35_PROJECT_TYPE_D01_TM
#elif defined GWM_V35_PROJECT_TYPE_D02
#define GWM_V35_PROJECT_TYPE_D02_TM
#elif defined GWM_V35_PROJECT_TYPE_D03
#define GWM_V35_PROJECT_TYPE_D03_TM
#elif defined GWM_V35_PROJECT_TYPE_P02
#define GWM_V35_PROJECT_TYPE_P02_TM
#elif defined GWM_V35_PROJECT_TYPE_P01
#define GWM_V35_PROJECT_TYPE_P01_TM
#else
#endif

#ifdef GWM_V35_PROJECT_TYPE_B02_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P03_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_A07_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D01_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D02_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D03_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P02_TM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P01_TM
#include "ComEx_Cfg.h"
#else
#endif

/**********************************************************************************************************
*																								          *
*																								          *
*	System Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

#define TM_CFG_TACHOMETER_FUNCTION      (TRUE)
	
/*********************************************************************************************************/

#define TM_CFG_DEBUG				    (FALSE)

/*********************************************************************************************************/

#define TM_CFG_TIME_TASK_CYCLE		    (20)//(40u)//ms


/**********************************************************************************************************
*																								          *
*																								          *
*	Vehicle Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/
#define TM_CFG_VCONFIG_FUEL_TYPE_0x1	(0x1)//汽油类型
#define TM_CFG_VCONFIG_FUEL_TYPE_0x2	(0x2)
#define TM_CFG_VCONFIG_FUEL_TYPE_0x6	(0x6)
#define TM_CFG_VCONFIG_FUEL_TYPE_0x3	(0x3)//柴油类型
#define TM_CFG_VCONFIG_FUEL_TYPE_0x4	(0x4)
#define TM_CFG_VCONFIG_FUEL_TYPE_0x5	(0x5)
#define TM_CFG_VCONFIG_FUEL_TYPE_0x7	(0x7)
//Vehicle Config EngineType (Byte27:bit7-bit0) 动力形式
#define TM_CFG_VCONFIG_ENGINE_TYPE_EN01			(0x24)
#define TM_CFG_VCONFIG_ENGINE_TYPE_GW4N20		(0x1E)
#define TM_CFG_VCONFIG_ENGINE_TYPE_GW4N20_HEV	(0x42)
#define TM_CFG_VCONFIG_ENGINE_TYPE_E20N			(0x26)
#define TM_CFG_VCONFIG_ENGINE_TYPE_GW4N20_PHEV	(0x43)
#define TM_CFG_VCONFIG_ENGINE_TYPE_E20N_HEV		(0x33)
#define TM_CFG_VCONFIG_ENGINE_TYPE_E20N_PHEV	(0x34)
#define TM_CFG_VCONFIG_ENGINE_TYPE_4C20B        (0x1B)//R19

#define TM_CFG_GASOLINE_TYPE	(0)
#define TM_CFG_DIESEL_TYPE		(1)
/**********************************************************************************************************
*	Timer Interface Configuration 																		  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  TM_CFG_TIMER_NOT_USE            0x00                                          /***/
/***/          #define  TM_CFG_TIMER_USE_TASK_CYCLE     0x01                                          /***/
/***/          #define  TM_CFG_TIMER_USE_SYSTEM_TIMER   0x02                                          /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define TM_CFG_TIMER_MODE_CONFIG         (TM_CFG_TIMER_USE_TASK_CYCLE)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Input Signal Mode Configuration                                                                       *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  TM_CFG_INPUT_SIGNAL_FROM_CAN   0x01                                           /***/
/***/          #define  TM_CFG_INPUT_SIGNAL_FROM_PWM   0x02                                           /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define TM_CFG_INPUT_MODE   (TM_CFG_INPUT_SIGNAL_FROM_CAN)

/**********************************************************************************************************
*	Output Mode	Configuration																	          *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  TM_CFG_OUTPUT_ON_VIRTUAL   0x00                                               /***/
/***/          #define  TM_CFG_OUTPUT_ON_GAUGE     0x01                                               /***/
/***/          #define  TM_CFG_OUTPUT_ON_BAR       0x02                                               /***/
/***/          #define  TM_CFG_OUTPUT_ON_PWM_PORT  0x04                                               /***/
/***/          #define  TM_CFG_OUTPUT_ON_SBUS      0x08                                               /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define TM_CFG_OUTPUT_MODE   (TM_CFG_OUTPUT_ON_SBUS)

/*********************************************************************************************************/

#define TM_CFG_LOW_ACCURACY_OUTPUT_USE_ROUND_HYSTERESIS			  FALSE

/**********************************************************************************************************
*	Tachometer AntiDither Mode	Configuration													          *
**********************************************************************************************************/
/***/																								  /***/
/***/		   #define	TM_CFG_NO_ANTI_DITHER_MODE 			      0x00								  /***/
/***/		   #define	TM_CFG_THREAD_ANTI_DITHER_MODEL			  0x01								  /***/
/***/		   #define	TM_CFG_ANTI_DITHER_MODEL_FROM_CONFIG_CODE 0x02								  /***/
/***/																								  /***/
/*********************************************************************************************************/

#define TM_CFG_ANTI_DITHER_MODE     (TM_CFG_NO_ANTI_DITHER_MODE)

#define TM_CFG_ANTI_DITHER_MODE_D058
#define TM_CFG_ANTI_DITHER_NO_DOWN_VALUE 50

/*********************************************************************************************************/

/**********************************************************************************************************
*	Configuration Infomation Storage													          		  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE    0x01                           /***/
/***/          #define  TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_DISABLE   0x02                           /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/
/*********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
#define TM_CFG_GAUGE_TBL_SOURCE   (TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_DISABLE)

#endif 
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
	
#define TM_CFG_SBUS_SEND_CYCLE_SOURCE   (TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)

#endif
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)

#define TM_CFG_ANTI_DITHER_DAMPING_MODEL_CONFIG_SOURCE   (TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)

#endif
/*********************************************************************************************************/

/**********************************************************************************************************
*																										  *
*																										  *
*	Function Configuration																				  *
*																										  *
*																										  *
**********************************************************************************************************/

/**********************************************************************************************************
*	Tachometer Gauge Indicate Value Configuration 													      *
**********************************************************************************************************/

#define TM_CFG_VALUE_MIN           (0u)
#define TM_CFG_VALUE_MAX           (8000u)

/**********************************************************************************************************
*	Tachometer Calculate Value Configuration 			    									          *
**********************************************************************************************************/

#define TM_CFG_VALUE_FACTOR        (1u)

/*********************************************************************************************************/

#define TM_CFG_GAUGE_MIN           (TM_CFG_VALUE_MIN/TM_CFG_VALUE_FACTOR)  //Min speed =    0rpm
#define TM_CFG_GAUGE_MAX           (TM_CFG_VALUE_MAX/TM_CFG_VALUE_FACTOR)  //Max speed = 8000rpm

/**********************************************************************************************************
*	Tachometer Gauge Anti-Dither Mode Limit Value Configuration 										  *
**********************************************************************************************************/
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
	
	#define TM_CFG_ENTER_ANTI_DITHER_MODE_ENTER_TIME_MAXIMUM   30000/*30s*/

	#define TM_CFG_ENTER_ANTI_DITHER_MODE_ENTER_TIME_MINIMUM   1000/*1s*/

	#define TM_CFG_ENTER_ANTI_DITHER_MODE_DAMPING_TIME_MAXIMUM  30000/*30s*/

	#define TM_CFG_ENTER_ANTI_DITHER_MODE_DAMPING_TIME_MINIMUM  0/*0s*/

	#define TM_CFG_VALUE_ANTI_DITHER_LIMIT_MAXIMUM             (2000)/*2000rpms*/

	#define TM_CFG_VALUE_ANTI_DITHER_LIMIT_MINIMUM             (0)/*0rpms*/

#if (TM_CFG_ANTI_DITHER_DAMPING_MODEL_CONFIG_SOURCE == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)

	#define TM_CFG_ENTER_ANTI_DITHER_MODE_ENTER_TIME          10000 //modify by fchao in 20200518   ((UINT16)VsNvmBlkGaugeTbl.u16TachometerAntiDitherEnterTime * 1000)

	#define TM_CFG_ENTER_ANTI_DITHER_MODE_DAMPING_TIME        3000/*Define const from SRD*/

	#define TM_CFG_VALUE_ANTI_DITHER_LOW_LIMIT                500 //modify by fchao in 20200518   (VsNvmBlkGaugeTbl.u16TachometerAntiDitherModeLowLimit)

	#define TM_CFG_VALUE_ANTI_DITHER_HIGH_LIMIT               1300 //modify by fchao in 20200518   (VsNvmBlkGaugeTbl.u16TachometerAntiDitherModeHighLimit)

#else

	#define TM_CFG_ENTER_ANTI_DITHER_MODE_ENTER_TIME          10000//10s for enter anti dither

	#define TM_CFG_ENTER_ANTI_DITHER_MODE_DAMPING_TIME        3000

	#define TM_CFG_VALUE_ANTI_DITHER_LOW_LIMIT                500  //Min speed =  500rpm

	#define TM_CFG_VALUE_ANTI_DITHER_HIGH_LIMIT               1300 //Max speed = 900rpm

#endif

#endif 
/*********************************************************************************************************/

/*********************************************************************************************************/

/**********************************************************************************************************
*	Tachometer Calculate Configuration 													                  *
**********************************************************************************************************/

#define TM_CFG_ENGINE_SPEED_VALUE_INTERFACE_ROUND_CONFIG    ((boolean)1)//(TRUE)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Tachometer Power Mode Configuration 														          *
**********************************************************************************************************/
/*The power state from power module*/
#define TM_CFG_POWER_STATE                     TRUE //modify by fchao in 20200518 (FSM_u8Get_SuperState())

/*********************************************************************************************************/

#define TM_CFG_POWER_STATE_CHECK_OK            TRUE //modify by fchao in 20200518  (TM_CFG_POWER_STATE == NORMAL)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Tachometer Work Mode Configuration 																      *
**********************************************************************************************************/
/*The module working mode configuration*/

#define TM_CFG_DIAGNOSIS_MODE_ENABLE           (FALSE)

#define TM_CFG_EOL_MODE_ENABLE                 (FALSE)

#define TM_CFG_ETM_MODE_ENABLE                 (FALSE)

/*********************************************************************************************************/


/**********************************************************************************************************
*	CAN Message Configuration 																		      *
**********************************************************************************************************/
#if((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/*********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_B03_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_NEVER_RECEIVED & (status)) == RTE_E_NEVER_RECEIVED) || ((RTE_E_MAX_AGE_EXCEEDED & (status)) == RTE_E_MAX_AGE_EXCEEDED) || ((RTE_E_COM_STOPPED & (status)) == RTE_E_COM_STOPPED))
#elif defined GWM_V35_PROJECT_TYPE_P03_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P05_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_A07_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D01_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D02_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D03_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P02_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P01_TM
#define GET_CAN_MESSAGE_MISSING_TM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#else
#endif

/*0x94 CAN MSG*/

#define TM_CFG_CAN_EMS_MSG_HAS_RECEIVED       TRUE //modify by fchao in 20200518   (CanIL_u8GetMsgDummy_094FirstReceived() != FALSE)

#define TM_CFG_CAN_EMS_MSG_NOT_MISSING        TRUE //modify by fchao in 20200518   (CanIL_u8GetMsgDummy_094Timeout() == FALSE)

#define TM_CFG_CAN_EMS_ENGINE_SPEED           TRUE //modify by fchao in 20200518   (CanIL_u16GetEngineSpeed())

#define TM_CFG_CAN_EMS_ENGINE_SPEED_INVALID   TRUE //modify by fchao in 20200518   (CanIL_u16GetEngineSpeed() >= 0xFFFEu) 

#define TM_CFG_CAN_EMS_ENGINE_SPEED_STATUS_INVALID (FALSE)

/* P01 project 0x2D3 CAM MSG */

#define TM_CFG_CAN_ECM11_MSG_MISSING(status) 		(GET_CAN_MESSAGE_MISSING_TM(status))
#define TM_CFG_CAN_ECM1_MSG_MISSING(status) 		(GET_CAN_MESSAGE_MISSING_TM(status))

/* V71,B30 */
#define TM_CFG_CAN_DCT3_MSG_MISSING(status) 		(GET_CAN_MESSAGE_MISSING_TM(status))

/* ENABLE fast respond */
#define TM_CFG_FAST_RESPOND	(1)
#define TM_CFG_NOT_FAST_RESPOND (0)

#define SM_CFG_DIGITAL_RPM_HYSTERESIS	(1)

/* internal configuration NVM */
#define TM_CFG_DIGITAL_RPM_HYSTERESIS	(TM__stMainObject.stCConfig.u16DigitalRPMHysteresis)  /* 数字显示转速的迟滞 unit：rpm */
#define TM_CFG_DIGITAL_TACHO_UPDATE_FREQUENCY (50u)/* 数字显示转速的刷新频率，配置为10ms的倍数 */
#define TM_CFG_FAST_RESP	(TM__stMainObject.stCConfig.boFastRespondFlg)/* 0x0:Disable fast respond; 0x1:Enable fast respond */

#define TM_CFG_FUEL_TYPE_GASOLINE_TACHO_VALUE_MAX	(8000u)/* unit rpm */
#define TM_CFG_FUEL_TYPE_DIESEL_TACHO_VALUE_MAX		(6000u)
#define TM_CFG_DIESEL_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE	(4500u)
#define TM_CFG_GASOLINE_TYPE_ENGINE_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE	(6300u)
#define TM_CFG_GASOLINE_TYPE_OTHER_ENGINE_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE	(6000u)
#define TM_CFG_GASOLINE_TYPE_ENGINE_TYPE_RED_ZONE_LOW_THRESHOLD_VALUE_4C20B (5500u)//R19

/*********************************************************************************************************/

#define TM_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK      (TRUE)

#define TM_CFG_CAN_MSG_ENGINE_SPEED_INVALID_COUNT_LIMIT   (2)

#define TM_CFG_CAN_MSG_ENGINE_SPEED_VALID_COUNT_LIMIT     (1)

/*********************************************************************************************************/
#endif 
/*********************************************************************************************************/

/**********************************************************************************************************
*	PWM Configuration 																		   	          *
**********************************************************************************************************/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/*********************************************************************************************************/

#define TM_CFG_PWM_STATUS_CHECK_OK           (FALSE)

#define TM_CFG_PWM_ENGINE_SPEED_VALUE_VALID  (FALSE)

#define TM_CFG_PWM_ENGINE_SPEED              ((uint16)0)

#define TM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT   (2)

/*********************************************************************************************************/
#endif 
/*********************************************************************************************************/

/**********************************************************************************************************
*	SBUS Configuration 																		              *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
/*********************************************************************************************************/

#define TM_CFG_SEND_ENGINE_SPEED_SBUS_MSG(Message)           () //modify by fchao in 20200518  (BC_vSetTargetTach(Message))

/*********************************************************************************************************/

#define TM_CFG_ENGINE_SPEED_SBUS_MSG_SEND_TIME_CYCLE_MAXIMUM  3000/*3 sec*/

#if (TM_CFG_SBUS_SEND_CYCLE_SOURCE  == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_DISABLE)

#define TM_CFG_ENGINE_SPEED_SBUS_MSG_SEND_TIME_CYCLE          10 //modify by fchao in 20200518  ((UINT16)VsNvmBlkGaugeTbl.u16TachometerUpdateCycle*10)

#else 

#define TM_CFG_ENGINE_SPEED_SBUS_MSG_SEND_TIME_CYCLE          (uint16)(TM__stMainObject.stCConfig.u16RefreshRateDiagitalRPM*10u) /*0.5 sec*/

#endif 
/*********************************************************************************************************/
#endif 
/**********************************************************************************************************
*	Tachometer Gauge Damping Configuration 														          *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  TM_CFG_NO_DAMPING_MODEL          0x00                                         /***/
/***/          #define  TM_CFG_THREAD_DAMPING_MODEL      0x01                                         /***/
/***/          #define  TM_CFG_KX_PLUS_B_DAMPING_MODEL   0x02                                         /***/
/***/          #define  TM_CFG_PID_DAMPING_MODEL         0x03                                         /***/
/***/          #define  TM_CFG_MODEL_FROM_CONFIG_CODE    0x04                                         /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define TM_CFG_DAMPING_MODEL   (TM_CFG_NO_DAMPING_MODEL)

/*********************************************************************************************************/
#if (TM_CFG_DAMPING_MODEL == TM_CFG_THREAD_DAMPING_MODEL)
/**********************************************************************************************************
*                                                                                                         *
* Current += Para or Current -= Para                                                                      *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*                                                                                                         *
*                 (MaxValue - MinValue) * TimeTaskCycle(ms)                                               *
*DampingValue = ---------------------------------------------                                             *
*                     SweepFullDialMinTime(ms)(From SRD)                                                  *
*                                                                                                         *
*                 (8000 - 0) * 40(ms)                                                                     *
*DampingValue = ----------------------- = 213                                                             *
*                       1500(ms)                                                                          *
*                                                                                                         *
**********************************************************************************************************/

#define TM_CFG_THREAD_DAMPING_MODEL_C     \
	(uint16)(((TM_CFG_VALUE_MAX - TM_CFG_VALUE_MIN)*TM_CFG_TIME_TASK_CYCLE)/1500)

/**********************************************************************************************************
*                                                                                                         *
*                 (Max - Min)                                                                             *
*DampingValue = ---------------                                                                           *
*                  TaskCycle                                                                              *
*                                                                                                         *
**********************************************************************************************************/



/**********************************************************************************************************
*                                                                                                         *
* Current += (Target - Current) / K + B) or Current -= (Current - Target) / K + B)                        *
*                                                                                                         *
**********************************************************************************************************/
#elif (TM_CFG_DAMPING_MODEL == TM_CFG_KX_PLUS_B_DAMPING_MODEL)
typedef struct
{
	uint16 u16K1;
	uint16 u16K2;
	uint16 u16B;
}TM_CFG_tstDAMPING_MODEL_KXPB_PARAMETER; 
/*********************************************************************************************************/

#define TM_CFG_KXPB_DAMPING_MODEL_K1                            (1)

#define TM_CFG_KXPB_DAMPING_MODEL_K2                            (20)

#define TM_CFG_KXPB_DAMPING_MODEL_B                             (20)

/**********************************************************************************************************
*                                                                                                         *
* PID Control Model                                                                                       *
*                                                                                                         *
**********************************************************************************************************/
#elif (TM_CFG_DAMPING_MODEL == TM_CFG_PID_DAMPING_MODEL)
typedef struct
{
	uint32 u32PrefilterRatio1;
	uint32 u32PrefilterRatio2;
	sint32 s32PID_Kp1;
	sint32 s32PID_Kp2;
	sint32 s32PID_Ti1;
	sint32 s32PID_Ti2;
	sint32 s32PID_Td1;
	sint32 s32PID_Td2;
	sint32 s32PID_C;
}TM_CFG_tstDAMPING_MODEL_PID_PARAMETER;
/*********************************************************************************************************/
/*Prefilter Ratio */
#define TM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_1              (70)
#define TM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_2              (100)

/*PID Filter*/
#define TM_CFG_PID_DAMPING_MODEL_KP1                            (1)
#define TM_CFG_PID_DAMPING_MODEL_KP2                            (20)

#define TM_CFG_PID_DAMPING_MODEL_TI1                            (1)
#define TM_CFG_PID_DAMPING_MODEL_TI2                            (400)

#define TM_CFG_PID_DAMPING_MODEL_TD1                            (18)
#define TM_CFG_PID_DAMPING_MODEL_TD2                            (100)

#define TM_CFG_PID_DAMPING_MODEL_C                              (1)


/*********************************************************************************************************/
#endif //(TM_CFG_DAMPING_MODEL == TM_CFG_THREAD_DAMPING_MODEL)
/*********************************************************************************************************/
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)

#define TM_CFG_ANTI_DITHER_DAMPING_MODEL_C(Max,Min,Cycle)  (uint16)((Max - Min)/Cycle)

#endif //(TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
/*********************************************************************************************************/
/**********************************************************************************************************
*	Tachometer Gauge Table Configuration 														          *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*********************************************************************************************************/

#define TM_CFG_GAUGE_ONE_DEGREE_STEPS	                (12)

/*********************************************************************************************************/
#if (TM_CFG_GAUGE_TBL_SOURCE  == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	
#define TM_CFG_GAUGE_EEPROM_TBL                         (VsNvmBlkGaugeTbl.au16TachometerGaugeTbl)
			
#endif // (TM_CFG_GAUGE_TBL_SOURCE  == TM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
/*********************************************************************************************************/
#define TM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET			(2)

#define TM_CFG_GAUGE_ROM_TBL \
{   /*Min x value = 0                    Max x value = 8000*/\
	{ (uint16)(TM_CFG_VALUE_MIN),        (uint16)(TM_CFG_VALUE_MAX)},\
	/* x = 0rpm electronic zero position.y = (  0 degree + 3)*12 = 36 micro steps */\
	{ (uint16)(TM_CFG_VALUE_MIN),        (uint16)((  0+TM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*TM_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 4000                          y = (  0 degree + 3)*12 = 36 micro steps*/\
	{ (uint16)(4000),                    (uint16)((  0+TM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*TM_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 8000rpm                       y = (  0 degree + 3)*12 = 36 micro steps*/\
	{ (uint16)(TM_CFG_VALUE_MAX),        (uint16)((  0+TM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*TM_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	{ (uint16)0xFFFF,                    (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                    (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                    (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                    (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                    (uint16)0xFFFF},\
}
/*********************************************************************************************************/
#endif // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*********************************************************************************************************/

/**********************************************************************************************************
*	Tachometer Bar Table Configuration 														          *
**********************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
/*********************************************************************************************************/

#define TM_CFG_BAR_DISPLAY_STEPS	     (16)

/*********************************************************************************************************/

/* Step StepUpInclude   StepUp                     StepDownInclude  StepDown
        EqualValue      LimitValue                 EqualValue       LimitValue*/
#define TM_CFG_BAR_ROM_TBL {\
/* 0*/ {FALSE ,(uint16)( 500*TM_CFG_VALUE_FACTOR),  0 ,0/*Not concerned*/                  },\
/* 1*/ {FALSE ,(uint16)(1000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 450*TM_CFG_VALUE_FACTOR)},\
/* 2*/ {FALSE ,(uint16)(1500*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 950*TM_CFG_VALUE_FACTOR)},\
/* 3*/ {FALSE ,(uint16)(2000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(1450*TM_CFG_VALUE_FACTOR)},\
/* 4*/ {FALSE ,(uint16)(2500*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(1950*TM_CFG_VALUE_FACTOR)},\
/* 5*/ {FALSE ,(uint16)(3000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(2450*TM_CFG_VALUE_FACTOR)},\
/* 6*/ {FALSE ,(uint16)(3500*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(2950*TM_CFG_VALUE_FACTOR)},\
/* 7*/ {FALSE ,(uint16)(4000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(3450*TM_CFG_VALUE_FACTOR)},\
/* 8*/ {FALSE ,(uint16)(4500*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(3950*TM_CFG_VALUE_FACTOR)},\
/* 9*/ {FALSE ,(uint16)(5000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(4450*TM_CFG_VALUE_FACTOR)},\
/*10*/ {FALSE ,(uint16)(5000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(4950*TM_CFG_VALUE_FACTOR)},\
/*11*/ {FALSE ,(uint16)(6000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(5450*TM_CFG_VALUE_FACTOR)},\
/*12*/ {FALSE ,(uint16)(6500*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(5950*TM_CFG_VALUE_FACTOR)},\
/*13*/ {FALSE ,(uint16)(7000*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(6450*TM_CFG_VALUE_FACTOR)},\
/*14*/ {FALSE ,(uint16)(7500*TM_CFG_VALUE_FACTOR),  FALSE,(uint16)(6950*TM_CFG_VALUE_FACTOR)},\
/*15*/ {0 ,0 ,/*Not concerned*/                    FALSE,(uint16)(7450*TM_CFG_VALUE_FACTOR)},\
}

/*********************************************************************************************************/	
#endif  // ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*	Other function Configuration 																		  *
**********************************************************************************************************/

#define TM_CFG_CONDITION_OF_VEHIALE_IS_RUNNING	    (5 <= SM_API_u16GetRealVehicleSpeed(VALID_INPUT,ACCUACY_1KM))

/**********************************************************************************************************
*																								          *
*																								          *
*	Main Object structure																				  *
*																								          *
*																								          *
**********************************************************************************************************/
/**********************************************************************************************************
*	System Status  																		                  *
**********************************************************************************************************/
typedef enum
{	
/*Normal Status*/			
  	TM_SYS_DEFAULT = 0x0000u,
	TM_SYS_RUNNING = 0x0001u,

/*Abnormal Status*/	
	TM_SYS_FAILD = 0x0010u,
	TM_ROM_GAUGE_TBL_ERROR = 0x0020u,
	TM_EEPROM_GAUGE_TBL_ERROR = 0x0040u,
	TM_IGN_OFF = 0x0080u,
	TM_EMS_CAN_MSG_INVALID = 0x0100u,
	TM_PWM_SIGNAL_INVALID = 0x0200u,
	TM_ALL_INPUT_INVALID = 0x0400u,

	TM_KEEP_PREVIOUS = 0xFFFF
}TM_CFG_enSYSTEM_STATUS;

/**********************************************************************************************************
*	Main Object Structure Definition  																	  *
**********************************************************************************************************/
typedef struct
{	
	/*****************************************************************************************************/
	/*System Status*/
	/******************************************************************************************************/
	union
	{
		uint32 u32SysErrStatus; /*The error status of tachometer function*/
		struct
		{	
			uint32 NormalStatusReserved      :4 ;
			
			uint32 System_Faild              :1 ;
			uint32 ROM_Gauge_Table_Error     :1 ;
			uint32 EEPROM_Gauge_Table_Error  :1 ;
			uint32 IGN_Off                   :1 ;
			uint32 EMS_CAN_MSG_Invalid       :1 ;
			uint32 PWM_Signal_Invalid        :1 ;
			uint32 All_Input_Invalid         :1 ;
			uint32 Reserved                  :21;
		}stSysErrStatus;	
	}unSysErrStatus;
	/*****************************************************************************************************/
	/*Basic Function*/
	/******************************************************************************************************/
	uint16 u16LastTargetEngineSpeed;	/*The last time target indicate engine speed*/
	uint16 u16FilterTargetEngineSpeed;	/*The last time target indicate engine speed*/
	uint16 u16FilterLastTargetEngineSpeed;	/*The last time target indicate engine speed*/
	uint16 u16TargetEngineSpeed;		/*The target value of engine speed*/
	uint16 u16CurrentEngineSpeed;		/*The current output value of engine speed*/
	uint16 u16LastCurrentEngineSpeed;		/*The last time current output value of engine speed*/
	uint16 u16VaildEngineSpeed;         /*The engine speed from high priority vaild source*/
	/******************************************************************************************************/	
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)	
 	uint16 u16EngineSpeedFromCAN;		/*The engine speed from CAN Msg*/
 	uint16 u16EngineSpeedFromCANBak;		/*The engine speed from CAN Msg for Telltale*/
 	uint16 u16EngSpdForEngSts;		/*The engine speed for engine running status*/
#endif 
	/******************************************************************************************************/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)		
	uint16 u16EngineSpeedFromPWM;		/*The engine speed from PWM*/
#endif 
	/******************************************************************************************************/
	/*Output On Gauge*/
	/******************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	uint16 u16GaugeMaxMotorStepCounts;      /*The max step motor counts*/
 	uint16 u16GaugeMinMotorStepCounts;      /*The min step motor counts*/
 	uint16 u16GaugeTargetStepCounts;        /*The target step motor counts*/
	uint16 u16GaugeCurrentStepCounts;       /*The current step motor counts*/
	uint16 u16GaugeTable[9][2];             /*The gauge point table*/
#endif 
	/******************************************************************************************************/
	/*Output On Bar*/
	/******************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_BAR) != FALSE)
	uint16 u16BarTargetStepCounts;		    /*The target bar step counts*/
	uint16 u16BarCurrentStepCounts;		    /*The current bar step counts*/
#endif  
	/******************************************************************************************************/
	/*Output On SBUS*/
	/******************************************************************************************************/
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
	uint16 u16SBUSSendCycle;				/*The SBUS message send cycle*/
	uint32 u32SBUSMessage;                  /*The SBUS message*/
#endif
	/******************************************************************************************************/
	/*Anti Dither Mode Function*/
	/******************************************************************************************************/
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
	uint16  u16AntiDitherModeLowLimit;
	uint16  u16AntiDitherModeHighLimit;
	uint16  u16AntiDitherModeEnterTime;
	uint16  u16AntiDitherModeDampingTime;
	uint16  u16AntiDitherModeFlag;
#endif
	/******************************************************************************************************/
	/*Other Function*/
	/******************************************************************************************************/


	/******************************************************************************************************/
	/*Count Function*/
	/******************************************************************************************************/
	struct
	{
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		uint8 u8ECMEngineSpeedValueInvalidCount;      /*ECM CAN engine speed value invalid count*/
		uint8 u8ECMEngineSpeedValueValidCount;        /*ECM CAN engine speed value invalid count*/
		uint8 u8EMSEngineSpeedStatusInvalidCount;     /*EMS CAN engine speed status invalid count*/
		uint8 u8EMSEngineSpeedStatusValidCount;       /*EMS CAN engine speed status invalid count*/
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
		uint8 u8PWMValueInvalidCount;		          /*PWM signal vehicle speed value invalid count*/
#endif //((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	}stCount;
	/******************************************************************************************************/
	/*Timer Function*/
	/******************************************************************************************************/
#if (TM_CFG_TIMER_MODE_CONFIG == TM_CFG_TIMER_USE_TASK_CYCLE)
	struct
	{
#if ((TM_CFG_OUTPUT_MODE & TM_CFG_OUTPUT_ON_SBUS) != FALSE)
		uint16 u16SBUS_MessageTick;              /*SBUS Send timer tick*/
#endif
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
		uint16  u8AntiDitherModeTick ;		     /*Time out tick for anti dither mode */
#endif
		uint16  u8ReservedTick ;				     /*Time out tick */
	}stTimer;
#endif 
	/******************************************************************************************************/
	union
	{
		uint32 u32FuncFlag;                   /*the flag of tachometer function*/
		struct
		{	
			uint32 FirstUpdate              :2 ;  /*First update without damping,0 is default,1 is enable ,2 is done,3 is closed*/
			uint32 AntiDither     	        :1 ;  /*Anti-dither mode,0 is default,1 is enable*/
			uint32 GaugeTableSource         :2 ;  /*Gauge table source mode,0 is default,1 is ROM ,2 is EEPROM*/
			uint32 EMSValueInvalidButKeep   :1 ;  /*EMS CAN value invalid but keep previous flag,0 is disable,1 is enable*/
			uint32 PWMValueInvalidButKeep   :1 ;  /*PWM signal value invalid but keep previous flag,0 is disable,1 is enable*/
			uint32 IncreaseClimate          :1 ;  /*Bar increase climate flag,0 is decrease,1 is increase*/
			uint32 Reserved                 :24;  /*Reserved bitfileds*/
		}stFuncFlag;	
	}unFunctionFlag;
	/******************************************************************************************************/
	/*Vehicle Configuration Function*/
	/******************************************************************************************************/
	struct
	{		
		uint16 u16RedZoneThreshold;
		uint16 u16TachoValueMax;
		uint8 u8FuelType;
		boolean boFastRespondFlg;
	}stVConfig;
	
	/******************************************************************************************************/
	/*Cluster Internal Configuration Function*/
	/******************************************************************************************************/
	struct
	{		
		uint16 u16AnalogRPMHysteresis;		/* 0~500 rpm factor:1 default:26 rpm */
		uint16 u16DigitalRPMHysteresis;	/* 0~500 rpm factor:1 default:26 rpm */
		uint16 u16RefreshRateDiagitalRPM;/*Diagital Tacho update frequency 20~3000ms factor:10 default:100ms */
		boolean boFastRespondFlg;			/* 0x0:Disable fast response; 0x1:Enable fast response */
	}stCConfig;
}TM_CFG_tstMAIN_OBJECT;  /*The tachometer object type*/
/**********************************************************************************************************
*	Flag Operation 																		                  *
**********************************************************************************************************/
typedef struct 
{
	uint32  u32FlagBitIndex;
	uint8   u32FlagBitLen;
	uint32  u32ColdInitSetValue;
	uint32  u32WarmInitSetValue;
	uint32  u32WakeUpSetValue;
	uint32  u32SleepSetValue;
	uint32  u32EnterAbnormalSetValue;
	uint32  u32ExitAbnormalSetValue;
}TM_CFG_tstFLAG_ATTRIBUTE;

typedef enum
{				
  	TM_FLAG_DEFAULT  = 0x00,
	TM_FLAG_CLEAR    = 0x00,
	TM_FLAG_PREVIOUS = 0xFFFF		
}TM_CFG_enFLAG_OPERATION;  

typedef enum
{
	TM_COLD_INIT ,
	TM_WARM_INIT ,
	TM_WAKE_UP ,
	TM_SLEEP ,
	TM_ENTER_ABNORMAL,
	TM_EXIT_ABNORMAL
}TM_CFG_enFLAG_PROCESS_STAGE;

/*FlagName               	        FlagBit  FlagBit  SetValueWhen       SetValueWhen       SetValueWhen       SetValueWhen      SetValueWhen       SetValueWhen
									Index	 Length   ColdInit           WarmInit           WakeUp             Sleep             EnterAbnormal      ExitAbnormal  */
#define TM_CFG_FLAG_ATTRIBUTE    {\
/*First Update Flag*/            {    0 ,      2,     3 /*3 is closed */,3 ,                3 ,                3 ,               3 ,                3           },\
/*Anti-dither Mode Flag*/		 {	  2 ,	   1,	  TM_FLAG_DEFAULT ,  TM_FLAG_DEFAULT ,  TM_FLAG_DEFAULT ,  TM_FLAG_DEFAULT , TM_FLAG_CLEAR ,    TM_FLAG_CLEAR },\
/*Gauge Table Source Flag*/		 {	  3 ,	   2,	  TM_FLAG_PREVIOUS , TM_FLAG_PREVIOUS , TM_FLAG_CLEAR ,    TM_FLAG_CLEAR ,   TM_FLAG_PREVIOUS , TM_FLAG_PREVIOUS},\
/*EMS Value Keep Previous*/      {    5 ,      1,     TM_FLAG_DEFAULT ,  TM_FLAG_DEFAULT ,  TM_FLAG_DEFAULT,   TM_FLAG_DEFAULT,  TM_FLAG_PREVIOUS , TM_FLAG_PREVIOUS },\
/*PWM Value Keep Previous*/      {	  6 ,	   1,	  TM_FLAG_DEFAULT ,  TM_FLAG_DEFAULT ,	TM_FLAG_DEFAULT,   TM_FLAG_DEFAULT,  TM_FLAG_PREVIOUS , TM_FLAG_PREVIOUS },\
/*Increase Climate Flag*/		 {	  7 ,	   1,	  1/*1 is increase*/,1 ,                1 ,                1 ,               1 ,                1           },\
								 {	 32 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },\
							     }
								 
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfGetEngineSpeedFromCANRawValue                                               *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#define SWC_TM_START_SEC_CODE
#include "SWC_TM_MemMap.h" 

#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
void TM_CFG_vFormulaOfGetEngineSpeedFromCANRawValue(TM_CFG_tstMAIN_OBJECT* stMainObject);
#endif 
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfGetEngineSpeedFromPWMRawValue                                              *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if ((TM_CFG_INPUT_MODE & TM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
void TM_CFG_vFormulaOfGetEngineSpeedFromPWMRawValue(TM_CFG_tstMAIN_OBJECT* stMainObject);
#endif
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfGetTargetIndicateSpeedFromRealSpeed                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
void TM_CFG_vFormulaOfGetTargetIndicateEngineSpeedFromRealEngineSpeed(TM_CFG_tstMAIN_OBJECT* stMainObject);
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfUserDefinedDampingOperation                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_DAMPING_MODEL == TM_CFG_MODEL_FROM_CONFIG_CODE)
void TM_CFG_vFormulaOfUserDefinedDampingOperation(TM_CFG_tstMAIN_OBJECT* stMainObject);
#endif
/**********************************************************************************************************
*Function   : TM_CFG_vEnterOrExitAntiDitherMode                                                           *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_ANTI_DITHER_MODE != TM_CFG_NO_ANTI_DITHER_MODE)
void TM_CFG_vEnterOrExitAntiDitherMode(TM_CFG_tstMAIN_OBJECT* stMainObject);
#endif
/**********************************************************************************************************
*Function   : TM_CFG_vFormulaOfUserDefinedAntiDitherDampingOperation                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-12                                                                                  *
**********************************************************************************************************/
#if (TM_CFG_ANTI_DITHER_MODE == TM_CFG_ANTI_DITHER_MODEL_FROM_CONFIG_CODE)
void TM_CFG_vFormulaOfUserDefinedAntiDitherDampingOperation(TM_CFG_tstMAIN_OBJECT* stMainObject);
#endif 
/**********************************************************************************************************
*Function   : TM_CFG_vVehicleConfig                                      *
*                                                                                                         *
*Description: TBD                                                                                         *
*                                                                                                         *
*Parameter	: TM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: hai hu                                                                                   *
*                                                                                                         *
*Date		: 2020-07-7                                                                                  *
**********************************************************************************************************/
void TM_CFG_vVehicleConfig(TM_CFG_tstMAIN_OBJECT* stMainObject);
#define SWC_TM_STOP_SEC_CODE
#include "SWC_TM_MemMap.h" 

/*********************************************************************************************************/
#endif //TM_CFG_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
