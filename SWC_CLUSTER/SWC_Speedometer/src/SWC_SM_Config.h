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
*File Name   : SM_Config.h                                                                                *
*                                                                                                         *
*Description : Speedometer module config file.                                                 		      *
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
#ifndef SM_CFG_H
#define SM_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Com.h"
#include "VConfig.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#include "logger.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
/* SM Log */
#define SWC_SM_LOGOUT_ENBLE (TRUE)
#define SWC_SM_PRINT_WARN   fuel_warn
/**********************************************************************************************************
*																								          *
*																								          *
*	Project Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/

#define SM_CFG_D077_PROJECT

/**********************************************************************************************************
*																								          *
*																								          *
*	System Configuration																				  *
*																								          *
*																								          *
**********************************************************************************************************/
	
#define SM_CFG_SPEEDOMETER_FUNCTION		(TRUE)
		
/*********************************************************************************************************/

#define SM_CFG_DEBUG				    (FALSE)

/*********************************************************************************************************/

#define SM_CFG_TIME_TASK_CYCLE		    (20u)//ms

/**********************************************************************************************************
*																								          *
*	Vehicle Configuration																				  *
*																								          *
**********************************************************************************************************/

#define SM_VEHICLE_CONFIG_UNIT
#define SM_CFG_METRIC_UNIT		(0)
#define SM_CFG_IMPERIAL_UNIT	(1)
#define SM_CFG_MENUSET_VEH_ODO_UNIT	(SM_CFG_METRIC_UNIT)
#define SM_CFG_ABS3_CAN			(0)
#define SM_CFG_ESP_CAN_FD		(1)

#define SM_CFG_TRANSMISSION_9DCT_GW		(0xF)
#define SM_CFG_TRANSMISSION_9HDCT_GW	(0x10)
#define SM_CFG_TRANSMISSION_9AT_GW		(0x27)
#define SM_CFG_TRANSMISSION_9HAT_GW		(0x28)
#define SM_CFG_TRANSMISSION_DHT1_GW		(0x12)/* 串联DHT */
#define SM_CFG_TRANSMISSION_DHT2_GW		(0x13)/* 混联DHT */
#define SM_CFG_TRANSMISSION_SG_GW		(0x14)	/* 单档减速箱 */
#define SM_CFG_TRANSMISSION_7DCT_GW		(0x7)
#define SM_CFG_TRANSMISSION_DCT300S_GW	(0x26)

#ifdef GWM_V35_PROJECT_TYPE_B02
#define GWM_V35_PROJECT_TYPE_B02_SM
#elif defined GWM_V35_PROJECT_TYPE_B03
#define GWM_V35_PROJECT_TYPE_B03_SM
#elif defined GWM_V35_PROJECT_TYPE_P03
#define GWM_V35_PROJECT_TYPE_P03_SM
#elif defined GWM_V35_PROJECT_TYPE_P05
#define GWM_V35_PROJECT_TYPE_P05_SM
#elif defined GWM_V35_PROJECT_TYPE_A07
#define GWM_V35_PROJECT_TYPE_A07_SM
#elif defined GWM_V35_PROJECT_TYPE_D01
#define GWM_V35_PROJECT_TYPE_D01_SM
#elif defined GWM_V35_PROJECT_TYPE_D02
#define GWM_V35_PROJECT_TYPE_D02_SM
#elif defined GWM_V35_PROJECT_TYPE_D03
#define GWM_V35_PROJECT_TYPE_D03_SM
#elif defined GWM_V35_PROJECT_TYPE_P02
#define GWM_V35_PROJECT_TYPE_P02_SM
#elif defined GWM_V35_PROJECT_TYPE_P01
#define GWM_V35_PROJECT_TYPE_P01_SM
#else
#endif

#ifdef GWM_V35_PROJECT_TYPE_B02_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P03_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_A07_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D01_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D02_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D03_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P02_SM
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P01_SM
#include "ComEx_Cfg.h"
#else
#endif

/**********************************************************************************************************
*	Timer Interface Configuration 																		  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  SM_CFG_TIMER_NOT_USE            0x00                                          /***/
/***/          #define  SM_CFG_TIMER_USE_TASK_CYCLE     0x01                                          /***/
/***/          #define  SM_CFG_TIMER_USE_SYSTEM_TIMER   0x02                                          /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define SM_CFG_TIMER_MODE_CONFIG         (SM_CFG_TIMER_USE_TASK_CYCLE)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Input Signal Mode Configuration                                                                       *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  SM_CFG_INPUT_SIGNAL_FROM_CAN   0x01                                           /***/
/***/          #define  SM_CFG_INPUT_SIGNAL_FROM_PWM   0x02                                           /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define SM_CFG_INPUT_MODE   SM_CFG_INPUT_SIGNAL_FROM_CAN

/**********************************************************************************************************
*	Output Mode	Configuration																	          *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  SM_CFG_OUTPUT_ON_VIRTUAL   0x00                                               /***/
/***/          #define  SM_CFG_OUTPUT_ON_GAUGE     0x01                                               /***/
/***/          #define  SM_CFG_OUTPUT_ON_BAR       0x02                                               /***/
/***/          #define  SM_CFG_OUTPUT_ON_PWM_PORT  0x04                                               /***/
/***/          #define  SM_CFG_OUTPUT_ON_SBUS      0x08                                               /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define SM_CFG_OUTPUT_MODE   SM_CFG_OUTPUT_ON_SBUS

/*********************************************************************************************************/

/**********************************************************************************************************
*	Configuration Infomation Storage													          		  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE    0x01                           /***/
/***/          #define  SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_DISABLE   0x02                           /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

/*********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
#define SM_CFG_GAUGE_TBL_SOURCE   (SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_DISABLE)

#endif

#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
	
#define SM_CFG_SBUS_SEND_CYCLE_SOURCE   (SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)

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
*	Speedometer Gauge Indicate Value Configuration 													      *
**********************************************************************************************************/
/* not PHEV Vehicle Model */
#define SM_CFG_VALUE_MIN           (0u)
#define SM_CFG_VALUE_MAX           ((SM__stMainObject.u8PowerType == 1) ? (26000u) : (24000u))
#define SM_CFG_VALUE_IMPERIAL_MAX  ((SM__stMainObject.u8PowerType == 1) ? (18000u) : (16000u))//(16000u)
/**********************************************************************************************************
*   Speedometer Calculate Value Configuration                                                             *
**********************************************************************************************************/

#define SM_CFG_VALUE_FACTOR        (SM_CFG_VALUE_FACTOR1/100)
#define SM_CFG_VALUE_FACTOR1        (10000u)

/*********************************************************************************************************/

#define SM_CFG_GAUGE_MIN           (SM_CFG_VALUE_MIN/SM_CFG_VALUE_FACTOR)  /*Min speed =   0km/h*/
#define SM_CFG_GAUGE_MAX           (SM_CFG_VALUE_MAX/SM_CFG_VALUE_FACTOR)  /*Max speed = 220km/h*/

/*********************************************************************************************************/

/**********************************************************************************************************
*	Speedometer Calculate Configuration 													              *
**********************************************************************************************************/

#define SM_CFG_SPEED_VALUE_INTERFACE_ROUND_CONFIG    ((boolean)1)//(TRUE)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Speedometer Power Mode Configuration 														          *
**********************************************************************************************************/
/*The power state from power module*/
#define SM_CFG_POWER_STATE                     TRUE //modify by fchao in 20200518 (FSM_u8Get_SuperState())

/*********************************************************************************************************/

#define SM_CFG_POWER_STATE_CHECK_OK            TRUE //modify by fchao in 20200518 (SM_CFG_POWER_STATE == NORMAL)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Speedometer Work Mode Configuration 																  *
**********************************************************************************************************/
/*The module working mode configuration*/

#define SM_CFG_DIAGNOSIS_MODE_ENABLE           (FALSE)

#define SM_CFG_EOL_MODE_ENABLE                 (FALSE)

#define SM_CFG_ETM_MODE_ENABLE                 (FALSE)

/*********************************************************************************************************/


/**********************************************************************************************************
*	CAN Message Configuration 																		      *
**********************************************************************************************************/
#if((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/*********************************************************************************************************/
#ifdef GWM_V35_PROJECT_TYPE_B02_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_B03_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_NEVER_RECEIVED & (status)) == RTE_E_NEVER_RECEIVED) || ((RTE_E_MAX_AGE_EXCEEDED & (status)) == RTE_E_MAX_AGE_EXCEEDED) || ((RTE_E_COM_STOPPED & (status)) == RTE_E_COM_STOPPED))
#elif defined GWM_V35_PROJECT_TYPE_P03_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P05_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_A07_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D01_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D02_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D03_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P02_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P01_SM
#define GET_CAN_MESSAGE_MISSING_SM(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#else
#endif

#define VEHICLE_SPEED_INVALID (0)
#define VEHICLE_SPEED_VALID (1)
/* ABS3 0x265 CAN MSG*/
#define SM_CFG_CAN_ABS3_MSG_MISSING(status) 		(GET_CAN_MESSAGE_MISSING_SM(status))

#define SM_CFG_CAN_ABS_VEHICLE_SPEED_STATUS_INVALID    (FALSE) 

/* ESP_FD2 0x137 CANFD message */
#define SM_CFG_CAN_ESP_FD2_MSG_MISSING(status) 		(GET_CAN_MESSAGE_MISSING_SM(status))

/*********************************************************************************************************/

#define SM_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK       (TRUE)

#define SM_CFG_CAN_MSG_VEHICLE_SPEED_INVALID_COUNT_LIMIT   (2)

#define SM_CFG_CAN_MSG_VEHICLE_SPEED_VALID_COUNT_LIMIT     (1)

/*********************************************************************************************************/
#endif 
/*********************************************************************************************************/
#define SM_CFG_TARGET_SEPPED_ADJUST_CRUISE
#ifdef SM_CFG_TARGET_SEPPED_ADJUST_CRUISE

#define SM_CFG_CRUISE_CFG_ENABLE				FALSE//TRUE //modify by fchao in 20200518 (0x01 == System_Conf_F1A1->Sys_Conf_Data.Cruise_Control)

#define SM_CFG_CAN_MSG_CRUISE_VALID				TRUE //modify by fchao in 20200518 (CanIL_u8GetMsgDummy_108FirstReceived()!= FALSE && CanIL_u8GetMsgDummy_108Timeout() == FALSE)

#define SM_CFG_CAN_MSG_CRUISE_SPEED_VALID		TRUE //modify by fchao in 20200518 (CanIL_u8GetMsgDummy_204FirstReceived()!= FALSE && CanIL_u8GetMsgDummy_204Timeout() == FALSE && CanIL_u8GetCruiseSpeedSetting_EMS() < 0xFE)

#define SM_CFG_CAN_MSG_CRUISE_SET				TRUE //modify by fchao in 20200518 (0x02 == CanIL_u8GetCruiseControlSt())

#define SM_CFG_CAN_MSG_CRUISE_SPEED_VALUE		0 //modify by fchao in 20200518 (CanIL_u8GetCruiseSpeedSetting_EMS())


#define SM_CFG_ACC_CRUISE_CFG_ENABLE			FALSE//TRUE //modify by fchao in 20200518 (0x02 == System_Conf_F1A1->Sys_Conf_Data.Cruise_Control)

#define SM_CFG_CAN_MSG_ACC_CRUISE_VALID			TRUE //modify by fchao in 20200518 (CanIL_u8GetMsgDummy_110FirstReceived()!= FALSE && CanIL_u8GetMsgDummy_110Timeout() == FALSE)

#define SM_CFG_CAN_MSG_ACC_CRUISE_SPEED_VALID	TRUE //modify by fchao in 20200518 (CanIL_u8GetMsgDummy_260FirstReceived()!= FALSE && CanIL_u8GetMsgDummy_260Timeout() == FALSE && CanIL_u8GetCruiseSpeedSetting_ACC() < 0xFE)

#define SM_CFG_CAN_MSG_ACC_CRUISE_SET			TRUE //modify by fchao in 20200518 (CanIL_u8GetWorkingSt_ACC() >= 2 && CanIL_u8GetWorkingSt_ACC() <= 4)

#define SM_CFG_CAN_MSG_ACC_CRUISE_SPEED_VALUE	0 //modify by fchao in 20200518 (CanIL_u8GetCruiseSpeedSetting_ACC())

#define SM_CFG_CAN_MSG_DEFINENT_SPEED			2
#endif

/**********************************************************************************************************
*	Hysteresis Configuration 																		   	          *
**********************************************************************************************************/
#define SM_CFG_DIGITAL_SPEED_HYSTERESIS   TRUE
/**********************************************************************************************************
*	PWM Configuration 																		   	          *
**********************************************************************************************************/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
/*********************************************************************************************************/

#define SM_CFG_PWM_STATUS_CHECK_OK           0//(TESTBIT(vsp50_get_VSpeedStatus_U8(),VSP50_MISSING|VSP50_SPEED_NEVER_RECEIVED|VSP50_SPEED_INVALID_DETECTED)==FALSE)

#define SM_CFG_PWM_SPEED_VALUE_VALID         0//(TESTBIT(vsp50_get_VSpeedStatus_U8(),VSP50_SPEED_INVALID)==FALSE)

#define SM_CFG_PWM_VEHICLE_SPEED             0//((UINT16)vsp50_get_10factVSpeed_U16())

#define SM_CFG_PWM_SIGNAL_VALUE_INVALID_COUNT_LIMIT   (2)

/*********************************************************************************************************/
#endif 
/*********************************************************************************************************/

/**********************************************************************************************************
*	SBUS Configuration 																		              *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
/*********************************************************************************************************/

/*********************************************************************************************************/
#define SM_CFG_REFRESH_RATE_DIGSPD	(SM__stMainObject.u16CcfgRefreshRateDigSpd)//200ms NVM configuration
#define SM_CFG_VEHICLE_SPEED_SBUS_MSG_SEND_TIME_CYCLE_MAXIMUM  3000/*3 sec*/

#if (SM_CFG_SBUS_SEND_CYCLE_SOURCE  == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)

#define SM_CFG_VEHICLE_SPEED_SBUS_MSG_SEND_TIME_CYCLE         (SM_CFG_REFRESH_RATE_DIGSPD)//modify by fchao in 20200518 ((UINT16)VsNvmBlkGaugeTbl.u16SpeedometerUpdateCycle*10)

#else 

#define SM_CFG_VEHICLE_SPEED_SBUS_MSG_SEND_TIME_CYCLE          500/*0.5 sec*/
			
#endif // (SM_CFG_SBUS_SEND_CYCLE_SOURCE  == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
/*********************************************************************************************************/
#endif //((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
/**********************************************************************************************************
*	Speedometer Gauge Damping Configuration 														      *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  SM_CFG_NO_DAMPING_MODEL          0x00                                         /***/
/***/          #define  SM_CFG_THREAD_DAMPING_MODEL      0x01                                         /***/
/***/          #define  SM_CFG_KX_PLUS_B_DAMPING_MODEL   0x02                                         /***/
/***/          #define  SM_CFG_PID_DAMPING_MODEL         0x03                                         /***/
/***/          #define  SM_CFG_MODEL_FROM_CONFIG_CODE    0x04                                         /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define SM_CFG_DAMPING_MODEL   (SM_CFG_NO_DAMPING_MODEL)

/*********************************************************************************************************/
#if (SM_CFG_DAMPING_MODEL == SM_CFG_THREAD_DAMPING_MODEL)
/**********************************************************************************************************
*                                                                                                         *
* Current += Para or Current -= Para                                                                      *
*                                                                                                         *
**********************************************************************************************************/

/**********************************************************************************************************
*                                                                                                         *
*                 (MaxValue - MinValue) * TimeTaskCycle(ms)                                               *
* DampingValue = ---------------------------------------------                                            *
*                     SweepFullDialMinTime(ms)(From SRD)                                                  *
*                                                                                                         *
*                 (22000 - 0) * 40(ms)                                                                    *
* DampingValue = ------------------------ = 293                                                           *
*                       1500(ms)                                                                          *
*                                                                                                         *
**********************************************************************************************************/

#define SM_CFG_THREAD_DAMPING_MODEL_C     \
	(uint16)(((SM_CFG_VALUE_MAX - SM_CFG_VALUE_MIN)*SM_CFG_TIME_TASK_CYCLE)/2000)

/*********************************************************************************************************/
#elif (SM_CFG_DAMPING_MODEL == SM_CFG_KX_PLUS_B_DAMPING_MODEL)
/**********************************************************************************************************
*                                                                                                         *
* Current += (Target - Current) / K + B) or Current -= (Current - Target) / K + B)                        *
*                                                                                                         *
**********************************************************************************************************/
typedef struct
{
	uint16 u16K1;
	uint16 u16K2;
	uint16 u16B;
}SM_CFG_tstDAMPING_MODEL_KXPB_PARAMETER; 
/*********************************************************************************************************/

#define SM_CFG_KXPB_DAMPING_MODEL_K1                            (1)

#define SM_CFG_KXPB_DAMPING_MODEL_K2                            (20)

#define SM_CFG_KXPB_DAMPING_MODEL_B                             (20)

/**********************************************************************************************************
*                                                                                                         *
* PID Control Model                                                                                       *
*                                                                                                         *
**********************************************************************************************************/
#elif (SM_CFG_DAMPING_MODEL == SM_CFG_PID_DAMPING_MODEL)
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
}SM_CFG_tstDAMPING_MODEL_PID_PARAMETER;
/*********************************************************************************************************/
/*Prefilter Ratio */
#define SM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_1              (75)
#define SM_CFG_PID_DAMPING_MODEL_PREFILTER_RATIO_2              (100)

/*PID Filter*/
#define SM_CFG_PID_DAMPING_MODEL_KP1                            (1)
#define SM_CFG_PID_DAMPING_MODEL_KP2                            (20)

#define SM_CFG_PID_DAMPING_MODEL_TI1                            (1)
#define SM_CFG_PID_DAMPING_MODEL_TI2                            (400)

#define SM_CFG_PID_DAMPING_MODEL_TD1                            (18)
#define SM_CFG_PID_DAMPING_MODEL_TD2                            (100)

#define SM_CFG_PID_DAMPING_MODEL_C                              (1)

#endif //(SM_CFG_DAMPING_MODEL)
/**********************************************************************************************************
*	Speedometer Gauge Table Configuration 														          *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*********************************************************************************************************/

#define SM_CFG_GAUGE_ONE_DEGREE_STEPS	                (12)

/*********************************************************************************************************/
#if (SM_CFG_GAUGE_TBL_SOURCE  == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	
#define SM_CFG_GAUGE_EEPROM_TBL                         (VsNvmBlkGaugeTbl.au16SpeedometerGaugeTbl)
			
#endif // (SM_CFG_GAUGE_TBL_SOURCE  == SM_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
/*********************************************************************************************************/
#define SM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET			(3)
	
#define SM_CFG_GAUGE_ROM_TBL \
{ 	/*Min x value = 0                   Max x value = 22000*/\
	{ (uint16)(SM_CFG_VALUE_MIN),       (uint16)(SM_CFG_VALUE_MAX)},\
	/* 0km/h electronic zero position.  y = (0 degree + 3)*12 = 0 micro steps */\
	{ (uint16)(SM_CFG_VALUE_MIN),       (uint16)((0+SM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*SM_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x =   0km/h                      y = (0 degree + 3)*12 = 0 micro steps*/\
	{ (uint16)(0*SM_CFG_VALUE_FACTOR),  (uint16)((0+SM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*SM_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 220km/h                      y = (0 degree + 3)*12 = 0 micro steps*/\
	{ (uint16)(SM_CFG_VALUE_MAX),       (uint16)((0+SM_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*SM_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	{ (uint16)0xFFFF,                   (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                   (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                   (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                   (uint16)0xFFFF},\
	{ (uint16)0xFFFF,                   (uint16)0xFFFF},\
}
/*********************************************************************************************************/
#endif // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*********************************************************************************************************/

/**********************************************************************************************************
*	Speedometer Bar Table Configuration 														          *
**********************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
/*********************************************************************************************************/

#define SM_CFG_BAR_DISPLAY_STEPS	     (16)

/*********************************************************************************************************/

/* Step StepUpInclude   StepUp                     StepDownInclude  StepDown
        EqualValue      LimitValue                 EqualValue       LimitValue*/
#define SM_CFG_BAR_ROM_TBL {\
/* 0*/ {FALSE ,(uint16)( 10*SM_CFG_VALUE_FACTOR),  0 ,0/*Not concerned*/                  },\
/* 1*/ {FALSE ,(uint16)( 20*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)(	8*SM_CFG_VALUE_FACTOR)},\
/* 2*/ {FALSE ,(uint16)( 30*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 18*SM_CFG_VALUE_FACTOR)},\
/* 3*/ {FALSE ,(uint16)( 40*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 28*SM_CFG_VALUE_FACTOR)},\
/* 4*/ {FALSE ,(uint16)( 50*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 38*SM_CFG_VALUE_FACTOR)},\
/* 5*/ {FALSE ,(uint16)( 60*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 48*SM_CFG_VALUE_FACTOR)},\
/* 6*/ {FALSE ,(uint16)( 70*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 58*SM_CFG_VALUE_FACTOR)},\
/* 7*/ {FALSE ,(uint16)( 80*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 68*SM_CFG_VALUE_FACTOR)},\
/* 8*/ {FALSE ,(uint16)( 90*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 78*SM_CFG_VALUE_FACTOR)},\
/* 9*/ {FALSE ,(uint16)(100*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 88*SM_CFG_VALUE_FACTOR)},\
/*10*/ {FALSE ,(uint16)(120*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)( 98*SM_CFG_VALUE_FACTOR)},\
/*11*/ {FALSE ,(uint16)(140*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)(118*SM_CFG_VALUE_FACTOR)},\
/*12*/ {FALSE ,(uint16)(160*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)(138*SM_CFG_VALUE_FACTOR)},\
/*13*/ {FALSE ,(uint16)(180*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)(158*SM_CFG_VALUE_FACTOR)},\
/*14*/ {FALSE ,(uint16)(200*SM_CFG_VALUE_FACTOR),  FALSE,(uint16)(178*SM_CFG_VALUE_FACTOR)},\
/*15*/ {0 ,0 ,/*Not concerned*/                    FALSE,(uint16)(198*SM_CFG_VALUE_FACTOR)},\
}

/*********************************************************************************************************/	
#endif  // ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
/**********************************************************************************************************
*	Other function Configuration 																		  *
**********************************************************************************************************/


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
  	SM_SYS_DEFAULT = 0x0000u,
	SM_SYS_RUNNING = 0x0001u,

/*Abnormal Status*/	
	SM_SYS_FAILD = 0x0010u,
	SM_ROM_GAUGE_TBL_ERROR = 0x0020u,
	SM_EEPROM_GAUGE_TBL_ERROR = 0x0040u,
	SM_IGN_OFF = 0x0080u,
	SM_ABS_CAN_MSG_INVALID = 0x0100u,
	SM_PWM_SIGNAL_INVALID = 0x0200u,
	SM_ALL_INPUT_INVALID = 0x0400u,

	SM_KEEP_PREVIOUS = 0xFFFF
}SM_CFG_enSYSTEM_STATUS;

/**********************************************************************************************************
*	Main Object Structure Definition  																	  *
**********************************************************************************************************/
typedef struct
{	
	/*****************************************************************************************************/
	/*System Status*/
	/*****************************************************************************************************/
	union
	{
		uint32 u32SysErrStatus; /*The error status of speedometer function*/
		struct
		{	
			uint32 NormalStatusReserved      :4 ;
			
			uint32 System_Faild              :1 ;
			uint32 ROM_Gauge_Table_Error     :1 ;
			uint32 EEPROM_Gauge_Table_Error  :1 ;
			uint32 IGN_Off                   :1 ;
			uint32 ABS_CAN_MSG_Invalid       :1 ;
			uint32 PWM_Signal_Invalid        :1 ;
			uint32 All_Input_Invalid         :1 ;
			uint32 Reserved                  :21;
		}stSysErrStatus;	
	}unSysErrStatus;
	/*****************************************************************************************************/
	/*Basic Function*/
	/*****************************************************************************************************/
	uint32 u16LastTargetIndicateSpeed;  /*The last time target indicate vehicle speed*/
	uint32 u16TargetIndicateSpeed;      /*The target indicate vehicle speed*/
	uint32 u16CurrentIndicateSpeed;     /*The current indicate vehicle speed*/
	uint32 u16LastCurrentIndicateSpeed; /*The last time current indicate vehicle speed*/
	uint32 u32VaildRealSpeed;           /*The real vehicle speed from high priority vaild source*/
	uint16 u16VehSpdMax;
	uint16 u16CcfgRefreshRateDigSpd;	/*Diagital Speedo update frequency, 0~3000ms factor:1 default:200ms*/
	uint8 u8MenuUnit;					/* The Vehicle Speed unit switched by Menu Settings */
	uint8 u8CANType;					/* 0:CAN ; 1:CANFD */
	uint8 u8PowerType;					/* 0:not PHEV 1:PHEV */
	/*****************************************************************************************************/	
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)	
 	uint32 u32RealSpeedFromCAN;         /*The real vehicle speed from CAN Msg*/
 	uint32 u32RealSpeedFromCANBak;         /*The real vehicle speed from CAN Msg ,backup for TC module*/

#endif 
	/*****************************************************************************************************/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)		
	uint16 u16RealSpeedFromPWM;         /*The real vehicle speed from PWM*/
#endif 
	/*****************************************************************************************************/
	/*Output On Gauge*/
	/*****************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	uint16 u16GaugeMaxMotorStepCounts;      /*The max step motor counts*/
 	uint16 u16GaugeMinMotorStepCounts;      /*The min step motor counts*/
 	uint16 u16GaugeTargetStepCounts;        /*The target step motor counts*/
	uint16 u16GaugeCurrentStepCounts;       /*The current step motor counts*/
	uint16 u16GaugeTable[9][2];             /*The gauge point table*/
#endif 
	/*****************************************************************************************************/
	/*Output On Bar*/
	/*****************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_BAR) != FALSE)
	uint16 u16BarTargetStepCounts;		    /*The target bar step counts*/
	uint16 u16BarCurrentStepCounts;		    /*The current bar step counts*/
#endif  
	/*****************************************************************************************************/
	/*Output On SBUS*/
	/*****************************************************************************************************/
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
	uint16 u16SBUSSendCycle;				/*The SBUS message send cycle*/
	uint32 u32SBUSMessage;                  /*The SBUS message*/
#endif  
	/*****************************************************************************************************/
	/*Other Function*/
	/*****************************************************************************************************/
	

	/*****************************************************************************************************/
	/*Count Function*/
	/*****************************************************************************************************/
	struct
	{
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		uint8 u8ABSVehicleSpeedValueInvalidCount;      /*ABS CAN vehicle speed value invalid count*/
		uint8 u8ABSVehicleSpeedValueValidCount;        /*ABS CAN vehicle speed value invalid count*/
		uint8 u8ABSVehicleSpeedStatusInvalidCount;     /*ABS CAN vehicle speed status invalid count*/
		uint8 u8ABSVehicleSpeedStatusValidCount;       /*ABS CAN vehicle speed status invalid count*/
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
		uint8 u8PWMValueInvalidCount;                  /*PWM value invalid count*/
#endif //((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
	}stCount;
	/*****************************************************************************************************/
	/*Timer Function*/
	/*****************************************************************************************************/
#if (SM_CFG_TIMER_MODE_CONFIG == SM_CFG_TIMER_USE_TASK_CYCLE)
	struct
	{
#if ((SM_CFG_OUTPUT_MODE & SM_CFG_OUTPUT_ON_SBUS) != FALSE)
		uint16 u16SBUS_MessageTick;              /*SBUS Send timer tick*/
#endif
		uint16 u16ReservedTick ;				 /*Time out tick */
	}stTimer;
#endif 
	/*****************************************************************************************************/
	union
	{
		uint32 u32FuncFlag;                   /*the flag of speedometer function*/
		struct
		{	
			uint32 FirstUpdate              :2 ;  /*First update without damping,0 is default,1 is enable ,2 is done,3 is closed*/
			uint32 GaugeTableSource         :2 ;  /*Gauge table source mode,0 is default,1 is ROM ,2 is EEPROM*/
			uint32 ABSValueInvalidButKeep   :1 ;  /*ABS CAN value invalid but keep previous flag,0 is disable,1 is enable*/
			uint32 PWMValueInvalidButKeep   :1 ;  /*PWM signal value invalid but keep previous flag,0 is disable,1 is enable*/
			uint32 IncreaseClimate          :1 ;  /*Bar increase climate flag,0 is decrease,1 is increase*/
			uint32 Reserved                 :25;  /*Reserved bitfileds*/
		}stFuncFlag;	
	}unFunctionFlag;
}SM_CFG_tstMAIN_OBJECT;  /*The speedometer object type*/
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
}SM_CFG_tstFLAG_ATTRIBUTE;

typedef enum
{				
  	SM_FLAG_DEFAULT  = 0x00,
	SM_FLAG_CLEAR    = 0x00,
	SM_FLAG_PREVIOUS = 0xFFFF		
}SM_CFG_enFLAG_OPERATION;  

typedef enum
{
	SM_COLD_INIT ,
	SM_WARM_INIT ,
	SM_WAKE_UP ,
	SM_SLEEP ,
	SM_ENTER_ABNORMAL,
	SM_EXIT_ABNORMAL
}SM_CFG_enFLAG_PROCESS_STAGE;

/*FlagName                          FlagBit  FlagBit  SetValueWhen       SetValueWhen       SetValueWhen       SetValueWhen      SetValueWhen       SetValueWhen
									Index	 Length   ColdInit           WarmInit           WakeUp             Sleep             EnterAbnormal      ExitAbnormal  */
#define SM_CFG_FLAG_ATTRIBUTE    {\
/*First Update Flag*/            {    0 ,      2,     3 /*3 is closed */,3 ,                3 ,                3 ,               3 ,                3           },\
/*Gauge Table Source Flag*/      {    2 ,      2,     SM_FLAG_PREVIOUS , SM_FLAG_PREVIOUS , SM_FLAG_DEFAULT,   SM_FLAG_DEFAULT,  SM_FLAG_PREVIOUS , SM_FLAG_PREVIOUS },\
/*ABS Value Keep Previous*/      {    4 ,      1,     SM_FLAG_DEFAULT ,  SM_FLAG_DEFAULT ,  SM_FLAG_DEFAULT,   SM_FLAG_DEFAULT,  SM_FLAG_PREVIOUS , SM_FLAG_PREVIOUS },\
/*PWM Value Keep Previous*/      {	  5 ,	   1,	  SM_FLAG_DEFAULT ,  SM_FLAG_DEFAULT ,	SM_FLAG_DEFAULT,   SM_FLAG_DEFAULT,  SM_FLAG_PREVIOUS , SM_FLAG_PREVIOUS },\
/*Increase Climate Flag*/		 {	  6 ,	   1,	  1/*1 is increase*/,1 ,                1 ,                1 ,               1 ,                1           },\
								 {	 32 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },\
							     }

/**********************************************************************************************************
*Function   : SM_CFG_vFormulaOfGetRealSpeedFromCANRawValue                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define Common_Normal_START_SEC_CODE
#include "Common_Normal_MemMap.h" 

#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
void SM_CFG_vFormulaOfGetRealSpeedFromCANRawValue(SM_CFG_tstMAIN_OBJECT* stMainObject);
#endif
/**********************************************************************************************************
*Function   : SM_CFG_vFormulaOfGetRealSpeedFromPWMRawValue                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((SM_CFG_INPUT_MODE & SM_CFG_INPUT_SIGNAL_FROM_PWM) != FALSE)
void SM_CFG_vFormulaOfGetRealSpeedFromPWMRawValue(SM_CFG_tstMAIN_OBJECT* stMainObject);
#endif
/**********************************************************************************************************
*Function   : SM_CFG_vFormulaOfGetTargetIndicateSpeedFromRealSpeed                                        *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void SM_CFG_vFormulaOfGetTargetIndicateSpeedFromRealSpeed(SM_CFG_tstMAIN_OBJECT* stMainObject);
/**********************************************************************************************************
*Function	: SM_CFG_vFormulaOfUserDefinedDampingOperation												  *
*																										  *
*Description: TBD																						  *
*																										  *
*Parameter	: SM_CFG_tstMAIN_OBJECT* stMainObject														  *
*																										  *
*Return 	: void																						  *
*																										  *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (SM_CFG_DAMPING_MODEL == SM_CFG_MODEL_FROM_CONFIG_CODE)
	void SM_CFG_vFormulaOfUserDefinedDampingOperation(SM_CFG_tstMAIN_OBJECT* stMainObject);
#endif

void SM_CFG_vVehicleConfig(SM_CFG_tstMAIN_OBJECT* stMainObject);
#define Common_Normal_STOP_SEC_CODE
#include "Common_Normal_MemMap.h" 

/*********************************************************************************************************/
#endif //SM_CFG_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
