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
*File Name   : CL_Config.h                                                                                *
*                                                                                                         *
*Description : Coolant module config file.                                                 		          *
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
#ifndef CL_CFG_H
#define CL_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "VConfig.h"
#include "logger.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/

#ifdef GWM_V35_PROJECT_TYPE_B02
#define GWM_V35_PROJECT_TYPE_B02_CL
#elif defined GWM_V35_PROJECT_TYPE_B03
#define GWM_V35_PROJECT_TYPE_B03_CL
#elif defined GWM_V35_PROJECT_TYPE_P03
#define GWM_V35_PROJECT_TYPE_P03_CL
#elif defined GWM_V35_PROJECT_TYPE_P05
#define GWM_V35_PROJECT_TYPE_P05_CL
#elif defined GWM_V35_PROJECT_TYPE_A07
#define GWM_V35_PROJECT_TYPE_A07_CL
#elif defined GWM_V35_PROJECT_TYPE_D01
#define GWM_V35_PROJECT_TYPE_D01_CL
#elif defined GWM_V35_PROJECT_TYPE_D02
#define GWM_V35_PROJECT_TYPE_D02_CL
#elif defined GWM_V35_PROJECT_TYPE_D03
#define GWM_V35_PROJECT_TYPE_D03_CL
#elif defined GWM_V35_PROJECT_TYPE_P02
#define GWM_V35_PROJECT_TYPE_P02_CL
#elif defined GWM_V35_PROJECT_TYPE_P01
#define GWM_V35_PROJECT_TYPE_P01_CL
#else
#endif

#ifdef GWM_V35_PROJECT_TYPE_B02_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P05_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P03_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_A07_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D01_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D02_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_D03_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P02_CL
#include "ComEx_Cfg.h"
#elif defined GWM_V35_PROJECT_TYPE_P01_CL
#include "ComEx_Cfg.h"
#else
#endif

/**********************************************************************************************************
*																								          *
*																								          *
*	System Configuration																				  *
*																								          *
*																								          *
***********************************************************************************************************/
extern sint16 g_coolantPointVal[8];

#define CL_CFG_COOLANT_FUNCTION      (TRUE)

/* CL Log */
#define SWC_CL_LOGOUT_ENBLE (TRUE)
#define SWC_CL_PRINT_WARN   fuel_warn

/*********************************************************************************************************/

#define CL_CFG_DEBUG				 (FALSE)
#define CL_CFG_OFFSET                ((sint8)50)
/*********************************************************************************************************/

#define CL_CFG_TIME_TASK_CYCLE		    (40u)//ms
/**********************************************************************************************************
*	Vehicle Configuration																				  *
**********************************************************************************************************/
#define CL_CFG_GASOLINE_TYPE	(0)
#define CL_CFG_DIESEL_TYPE		(1)
#define CL_CFG_NO_DISPLAY		(3)
/**********************************************************************************************************
*	Timer Interface Configuration 																		  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  CL_CFG_TIMER_NOT_USE            0x00                                          /***/
/***/          #define  CL_CFG_TIMER_USE_TASK_CYCLE     0x01                                          /***/
/***/          #define  CL_CFG_TIMER_USE_SYSTEM_TIMER   0x02                                          /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define CL_CFG_TIMER_MODE_CONFIG         (CL_CFG_TIMER_USE_TASK_CYCLE)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Input Signal Mode Configuration                                                                       *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  CL_CFG_INPUT_SIGNAL_FROM_CAN   0x01                                           /***/
/***/          #define  CL_CFG_INPUT_SIGNAL_FROM_ADC   0x02                                           /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define CL_CFG_INPUT_MODE   (CL_CFG_INPUT_SIGNAL_FROM_CAN)

/**********************************************************************************************************
*	Output Mode	Configuration																	          *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  CL_CFG_OUTPUT_ON_VIRTUAL   0x00                                               /***/
/***/          #define  CL_CFG_OUTPUT_ON_GAUGE     0x01                                               /***/
/***/          #define  CL_CFG_OUTPUT_ON_BAR       0x02                                               /***/
/***/          #define  CL_CFG_OUTPUT_ON_SBUS      0x04                                               /***/
/***/          #define  CL_CFG_OUTPUT_ON_TLC       0x08                                               /***/
/*********************************************************************************************************/

#define CL_CFG_OUTPUT_MODE   (CL_CFG_OUTPUT_ON_BAR | CL_CFG_OUTPUT_ON_TLC | CL_CFG_OUTPUT_ON_SBUS)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Configuration Infomation Storage													          		  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE    0x01                           /***/
/***/          #define  CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_DISABLE   0x02                           /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

/*********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
	
#define CL_CFG_GAUGE_TBL_SOURCE   (CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)

#endif 
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
	
#define CL_CFG_SBUS_SEND_CYCLE_SOURCE   (CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_DISABLE)

#endif
/*********************************************************************************************************/

/**********************************************************************************************************
*																										  *
*																										  *
*	Function Configuration																				  *
*																										  *
*																										  *
**********************************************************************************************************/

#define CL_CFG_REAL_VALUE_MIN       ((sint16)-4800)//Real min temperature =   -48C
#define CL_CFG_REAL_VALUE_MAX       ((sint16)14250)//Real max temperature =   142.5C

/**********************************************************************************************************
*   Coolant Calculate Value Configuration                                                                 *
**********************************************************************************************************/

#define CL_CFG_VALUE_FACTOR        (100u)

/*********************************************************************************************************/

#define CL_CFG_VALUE_MIN           (0u)    //Min temperature =   0C
#define CL_CFG_VALUE_MAX           (14250u)//Max temperature = 142.5C

/**********************************************************************************************************
*	Coolant Gauge Indicate Value Configuration 													          *
**********************************************************************************************************/

#define CL_CFG_GAUGE_MIN           (4500u)  //Min display temperature = 44.25C
#define CL_CFG_GAUGE_MAX           (13050u) //Max display temperature = 130.5C

/*********************************************************************************************************/
/**********************************************************************************************************
*	Coolant Bar Indicate Value Configuration 													          *
**********************************************************************************************************/

#define CL_CFG_BAR_MIN             (4500u)  //Min display temperature = 42.75C
#define CL_CFG_BAR_MAX             (13050u) //Max display temperature = 130.5C

/*********************************************************************************************************/


/*********************************************************************************************************/

/**********************************************************************************************************
*	Coolant Calculate Configuration 													                  *
**********************************************************************************************************/

#define CM_CFG_REAL_TEMPERATRUE_VALUE_INTERFACE_ROUND_CONFIG		((boolean)FALSE)

/*********************************************************************************************************/

/**********************************************************************************************************
*	Coolant Power Mode Configuration 														          *
**********************************************************************************************************/
/*Power Mode Status*/
typedef enum
{
	CL_enNULL_POWER_MODE = 0x0000,
	CL_enOFF = 0x0001,
	CL_enRUN = 0x0002,
	CL_enABNORMAL_VOLTAGE = 0x0004,
}CL_CFG_enWorkPowerMode;
/*********************************************************************************************************/
/*The power state from power module*/
#define CL_CFG_POWER_STATE                         TRUE // modify by fchao in 20200519 (FSM_u8Get_SuperState())
	
/*********************************************************************************************************/
	
#define CL_CFG_POWER_STATE_IS_OFF                FALSE // modify by fchao in 20200519 (FSM_u8Get_SuperState())  (LIMITED == CL_CFG_POWER_STATE)
#define CL_CFG_POWER_STATE_IS_RUN                TRUE // modify by fchao in 20200519 (FSM_u8Get_SuperState()) (NORMAL == CL_CFG_POWER_STATE)
#define CL_CFG_POWER_STATE_IS_ABNORMAL_VOLTAGE   FALSE // modify by fchao in 20200519 (FSM_u8Get_SuperState())  (ABNVOLT == CL_CFG_POWER_STATE)

#define CL_CFG_SRART_PRECHECK 				   	 TRUE // modify by fchao in 20200519  ((NORMAL == CL_CFG_POWER_STATE) && (ga_fuel_sync_ready()==1))

/*********************************************************************************************************/

/**********************************************************************************************************
*	Coolant Work Mode Configuration 																  *
**********************************************************************************************************/
/*The module working mode configuration*/

#define CL_CFG_DIAGNOSIS_MODE_ENABLE           (FALSE)

#define CL_CFG_EOL_MODE_ENABLE                 (FALSE)

#define CL_CFG_ETM_MODE_ENABLE                 (FALSE)

/*********************************************************************************************************/


/**********************************************************************************************************
*	CAN Message Configuration 																		      *
**********************************************************************************************************/
#if((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/*********************************************************************************************************/
#define RTE_E_NEVER_RECEIVED (133U)
#define RTE_E_MAX_AGE_EXCEEDED (64U)

#ifdef GWM_V35_PROJECT_TYPE_B02_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_B03_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_NEVER_RECEIVED & (status)) == RTE_E_NEVER_RECEIVED) || ((RTE_E_MAX_AGE_EXCEEDED & (status)) == RTE_E_MAX_AGE_EXCEEDED) || ((RTE_E_COM_STOPPED & (status)) == RTE_E_COM_STOPPED))
#elif defined GWM_V35_PROJECT_TYPE_P03_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P05_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_A07_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D01_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D02_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_D03_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P02_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#elif defined GWM_V35_PROJECT_TYPE_P01_CL
#define GET_CAN_MESSAGE_MISSING_CL(status)		(((RTE_E_ComEx_COMEX_ERROR_PARAM & (status)) == RTE_E_ComEx_COMEX_ERROR_PARAM) || ((RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED & (status)) == RTE_E_ComEx_COMEX_MAX_AGE_EXCEEDED) || ((RTE_E_ComEx_COMEX_NEVER_RECEIVED & (status)) == RTE_E_ComEx_COMEX_NEVER_RECEIVED))
#else
#endif
/* ECM3 0x371 CAN MSG 100ms */

#define CL_CFG_CAN_ECM3_MSG_MISSING(status) 		(GET_CAN_MESSAGE_MISSING_CL(status))

#define CL_CFG_CAN_ECM3_TEMPERATURE                   0 // modify by fchao in 20200519 (CanIL_u8GetEngineTemp())

#define CL_CFG_CAN_ECM3_TEMPERATURE_INVALID           FALSE // modify by fchao in 20200519 (CanIL_u8GetEngineTemp() >= 0xFE)

#define CL_CFG_CAN_ECM3_TEMPERATURE_STATUS_INVALID    (CL_EngClntTempVldty) 

/*********************************************************************************************************/

#define CL_CFG_CAN_MSG_VALID_COUNT_PLUS_IN_TIME_TASK     (TRUE)

#define CL_CFG_CAN_MSG_TEMPERATURE_INVALID_COUNT_LIMIT   (2)

#define CL_CFG_CAN_MSG_TEMPERATURE_VALID_COUNT_LIMIT     (1)

/*********************************************************************************************************/
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
/*********************************************************************************************************/

/**********************************************************************************************************
*	ADC Configuration 																		   	          *
**********************************************************************************************************/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
/*********************************************************************************************************/

#define CL_CFG_ADC_STATUS_CHECK_OK           (FALSE)

#define CL_CFG_ADC_TEMPERATURE_VALUE_VALID   (FALSE)

#define CL_CFG_ADC_TEMPERATURE               ((uint16)0)

#define CL_CFG_ADC_SIGNAL_VALUE_INVALID_COUNT_LIMIT   (2)

/*********************************************************************************************************/
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
/*********************************************************************************************************/

/**********************************************************************************************************
*	SBUS Configuration 																		              *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
/*********************************************************************************************************/

#define CL_CFG_SEND_TEMPERATURE_SBUS_MSG(Message)     () // modify by fchao in 20200519  (NW_SIL_TX_EngineCoolantIndicated_DATA(Message))

/*********************************************************************************************************/

#define CL_CFG_TEMPERATURE_SBUS_MSG_SEND_TIME_CYCLE_MAXIMUM     2000/*2 sec*/

#if (CL_CFG_SBUS_SEND_CYCLE_SOURCE  == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)

#define CL_CFG_TEMPERATURE_SBUS_MSG_SEND_TIME_CYCLE             40 // modify by fchao in 20200519  VsNvmBlkGaugeTbl.u16CoolantUpdateCycle

#else 

#define CL_CFG_TEMPERATURE_SBUS_MSG_SEND_TIME_CYCLE             40/*0.5 sec*/

#endif //(CL_CFG_SBUS_SEND_CYCLE_SOURCE  == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
/*********************************************************************************************************/
#endif //((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
/**********************************************************************************************************
*	Coolant Damping Configuration 														                  *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  CL_CFG_NO_DAMPING_MODEL          0x01                                         /***/
/***/          #define  CL_CFG_THREAD_DAMPING_MODEL      0x02                                         /***/
/***/          #define  CL_CFG_KX_PLUS_B_DAMPING_MODEL   0x03                                         /***/
/***/          #define  CL_CFG_MODEL_FROM_CONFIG_CODE    0x04                                         /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define CL_CFG_DAMPING_MODEL   (CL_CFG_NO_DAMPING_MODEL)

/*********************************************************************************************************/

#define CL_CFG_IGN_ON_FIRST_INDICATE_WITH_NO_DAMPING          (TRUE)

#define CL_CFG_INPUT_VALID_FIRST_INDICATE_WITH_NO_DAMPING     (TRUE)

#define CL_CFG_INPUT_INVALID_RETURN_TO_ZERO_WITH_NO_DAMPING   (TRUE)

/*********************************************************************************************************/
#if (CL_CFG_DAMPING_MODEL == CL_CFG_THREAD_DAMPING_MODEL)
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
*                 (13050 - 4425) * 40(ms)                                                                 *
* DampingValue = ----------------------- = 11                                                             *
*                      30000(ms)                                                                          *
*                                                                                                         *
**********************************************************************************************************/

#define CL_CFG_THREAD_DAMPING_MODEL_PARAMETER_DEFAULT_VALUE     \
	(uint16)(((CL_CFG_GAUGE_MAX - CL_CFG_GAUGE_MIN)*CL_CFG_TIME_TASK_CYCLE)/30000)

/*********************************************************************************************************/
#elif (CL_CFG_DAMPING_MODEL == CL_CFG_KX_PLUS_B_DAMPING_MODEL)
/**********************************************************************************************************
*                                                                                                         *
* Current += (Target - Current) / K + B) or Current -= (Current - Target) / K + B)                        *
*                                                                                                         *
**********************************************************************************************************/

#define CL_CFG_KXPB_DAMPING_MODEL_PARAMETER_K1_DEFAULT_VALUE    (1)

#define CL_CFG_KXPB_DAMPING_MODEL_PARAMETER_K2_DEFAULT_VALUE    (20)

#define CL_CFG_KXPB_DAMPING_MODEL_PARAMETER_B_DEFAULT_VALUE     (40)
	
/*********************************************************************************************************/
#endif //(CL_CFG_DAMPING_MODEL)
/**********************************************************************************************************
*	Coolant Gauge Table Configuration 														          *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*********************************************************************************************************/

#define CL_CFG_GAUGE_ONE_DEGREE_STEPS	                (12)

/*********************************************************************************************************/
#if (CL_CFG_GAUGE_TBL_SOURCE  == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
	
#define CL_CFG_GAUGE_EEPROM_TBL                         () // modify by fchao in 20200519  (VsNvmBlkGaugeTbl.au16CoolantGaugeTbl)
			
#endif // (CL_CFG_GAUGE_TBL_SOURCE  == CL_CFG_CONFIG_INFO_STORAGE_IN_EEPROM_ENABLE)
/*********************************************************************************************************/
#define CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET			(3)
	
#define CL_CFG_GAUGE_ROM_TBL \
{ 	/*Min x value = 4425               Max x value = 13050*/\
	{ (uint16)(CL_CFG_GAUGE_MIN),      (uint16)(CL_CFG_GAUGE_MAX)},\
	/* 0km/h electronic zero position. y =   36 micro steps*/\
	{ (uint16)(CL_CFG_GAUGE_MIN),      (uint16)((          0+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 5025                        y =  192 micro steps*/\
	{ (uint16)(5025u),                 (uint16)((((104/8)*1)+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 8025                        y =  504 micro steps*/\
	{ (uint16)(8025u),                 (uint16)((((104/8)*3)+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 9975                        y =  660 micro steps*/\
	{ (uint16)(9975u),                 (uint16)((((104/8)*4)+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 10500                       y =  816 micro steps*/\
	{ (uint16)(10500u),                (uint16)((((104/8)*5)+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 11475                       y =  972 micro steps*/\
	{ (uint16)(11475u),                (uint16)((((104/8)*6)+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 13500                       y =  1128 micro steps*/\
	{ (uint16)(12000u),                (uint16)((((104/8)*7)+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
	/* x = 13500                       y =  1284 micro steps*/\
	{ (uint16)(CL_CFG_GAUGE_MAX),      (uint16)((        104+CL_CFG_GAUGE_ELEC_ZREO_POSITION_OFFSET)*CL_CFG_GAUGE_ONE_DEGREE_STEPS)},\
}
/*********************************************************************************************************/
#endif // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)
/*********************************************************************************************************/

/**********************************************************************************************************
*	Coolant Bar Table Configuration 														          *
**********************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
/*********************************************************************************************************/

#define CL_CFG_BAR_DISPLAY_STEPS	     (9)

#define CL_CFG_BAR_STEPS_DAMPING	     (TRUE)
#if (CL_CFG_BAR_STEPS_DAMPING != FALSE)
#define CL_CFG_STEP_COUNTS_DAMPING_PARAMETER_DEFAULT_VALUE     \
	(uint16)(30000/((CL_CFG_BAR_DISPLAY_STEPS - 1)*CL_CFG_TIME_TASK_CYCLE))

#define CL_CFG_STEP_COUNTS_QUICKDAMPING_PARAMETER_DEFAULT_VALUE     \
	(uint16)(1420/((CL_CFG_BAR_DISPLAY_STEPS - 1)*CL_CFG_TIME_TASK_CYCLE))

#endif
/*********************************************************************************************************/

/* Step StepUpInclude   StepUp                     StepDownInclude  StepDown
        EqualValue      LimitValue                 EqualValue       LimitValue*/
#define CL_CFG_BAR_ROM_TBL {\
/* 0*/ {(boolean)TRUE ,(uint16)( 55*CL_CFG_VALUE_FACTOR),  (boolean)0    ,(uint16)0/*Not concerned*/       },\
/* 1*/ {(boolean)TRUE ,(uint16)( 62*CL_CFG_VALUE_FACTOR),  (boolean)FALSE,(uint16)(	52*CL_CFG_VALUE_FACTOR)},\
/* 2*/ {(boolean)TRUE ,(uint16)( 69*CL_CFG_VALUE_FACTOR),  (boolean)FALSE,(uint16)( 59*CL_CFG_VALUE_FACTOR)},\
/* 3*/ {(boolean)TRUE ,(uint16)( 76*CL_CFG_VALUE_FACTOR),  (boolean)FALSE,(uint16)( 66*CL_CFG_VALUE_FACTOR)},\
/* 4*/ {(boolean)TRUE ,(uint16)( 107*CL_CFG_VALUE_FACTOR), (boolean)FALSE,(uint16)( 73*CL_CFG_VALUE_FACTOR)},\
/* 5*/ {(boolean)TRUE ,(uint16)( 110*CL_CFG_VALUE_FACTOR), (boolean)FALSE,(uint16)( 104*CL_CFG_VALUE_FACTOR)},\
/* 6*/ {(boolean)TRUE ,(uint16)( 113*CL_CFG_VALUE_FACTOR), (boolean)FALSE,(uint16)( 107*CL_CFG_VALUE_FACTOR)},\
/* 7*/ {(boolean)TRUE ,(uint16)( 115*CL_CFG_VALUE_FACTOR), (boolean)FALSE,(uint16)( 110*CL_CFG_VALUE_FACTOR)},\
/* 8*/ {(boolean)0    ,(uint16)0/*Not concerned*/ ,        (boolean)FALSE,(uint16)( 112*CL_CFG_VALUE_FACTOR)},\
}

/*********************************************************************************************************/	
#endif  // ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
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
  	CL_SYS_DEFAULT = 0x0000u,
	CL_SYS_RUNNING = 0x0001u,

/*Abnormal Status*/	
	CL_SYS_FAILD = 0x0010u,
	CL_ROM_GAUGE_TBL_ERROR = 0x0020u,
	CL_EEPROM_GAUGE_TBL_ERROR = 0x0040u,
	CL_IGN_OFF = 0x0080u,
	CL_ECM3_CAN_MSG_INVALID = 0x0100u,
	CL_ADC_SIGNAL_INVALID = 0x0200u,
	CL_ALL_INPUT_INVALID = 0x0400u,
	CL_VOL_ABNORMAL = 0x0800u,
	CL_KEEP_PREVIOUS = 0xFFFF
}CL_CFG_enSYSTEM_STATUS;

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
		uint32 u32SysErrStatus; /*The error status of Coolant function*/
	}unSysErrStatus;
	/*****************************************************************************************************/
	/*Basic Function*/
	/******************************************************************************************************/
	union
	{
		uint32 u32PowerModeStatus; /*The status of power mode*/
	}unPowerModeStatus;
	/******************************************************************************************************/
	uint16 u16LastTargetIndicateTemperature;  /*The last time target indicate engine temperature*/
	uint16 u16TargetIndicateTemperature;      /*The target indicate engine temperature*/
	uint16 u16CurrentIndicateTemperature;     /*The current indicate engine temperature*/
	sint16 s16ValidRealTemperature;           /*The valid real engine temperature*/
	uint8 uEngClntTempVldty;
	/******************************************************************************************************/	
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)	
	sint16 s16RealTemperatureFromCAN;         /*The real engine temperature from CAN Msg*/
#endif 
	/******************************************************************************************************/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)		
	sint16 s16RealTemperatureFromADC;         /*The real engine temperature from AD Channel*/
#endif 
	/******************************************************************************************************/
	/*Output On Gauge*/
	/******************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_GAUGE) != FALSE)	
	uint16 u16GaugeMaxMotorStepCounts;      /*The max step motor counts*/
 	uint16 u16GaugeMinMotorStepCounts;      /*The min step motor counts*/
 	uint16 u16GaugeTargetStepCounts;        /*The target step motor counts*/
	uint16 u16GaugeCurrentStepCounts;       /*The current step motor counts*/
	uint16 u16GaugeTable[9][2];             /*The gauge point table*/
#endif 
	/******************************************************************************************************/
	/*Output On Bar*/
	/******************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_BAR) != FALSE)
	uint16 u16BarTargetStepCounts;		    /*The target bar step counts*/
	uint16 u16BarCurrentStepCounts;		    /*The current bar step counts*/
 #if (CL_CFG_BAR_STEPS_DAMPING != FALSE)
	uint16 u16BarStepDampingCounts;
 #endif
#endif  
	/******************************************************************************************************/
	/*Output On SBUS*/
	/******************************************************************************************************/
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
	uint16 u16SBUSSendCycle;				/*The SBUS message send cycle*/
	uint32 u32SBUSMessage;                  /*The SBUS message*/
#endif
	/******************************************************************************************************/
	/*Other Function*/
	/******************************************************************************************************/
	

	/******************************************************************************************************/
	/*Count Function*/
	/******************************************************************************************************/
	struct
	{
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
		uint8 u8ECM3TemperatureValueInvalidCount;      /*ECM3 CAN engine Temperature value invalid count*/
		uint8 u8ECM3TemperatureValueValidCount;        /*ECM3 CAN engine Temperature value invalid count*/
		uint8 u8ECM3TemperatureStatusInvalidCount;     /*ECM3 CAN engine Temperature status invalid count*/
		uint8 u8ECM3TemperatureStatusValidCount;       /*ECM3 CAN engine Temperature status invalid count*/
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
		uint8 u8ADCValueInvalidCount;		          /*ADC signal vehicle speed value invalid count*/
#endif //((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
	}stCount;
	/******************************************************************************************************/
	/*Timer Function*/
	/******************************************************************************************************/
#if (CL_CFG_TIMER_MODE_CONFIG == CL_CFG_TIMER_USE_TASK_CYCLE)
	struct
	{
#if ((CL_CFG_OUTPUT_MODE & CL_CFG_OUTPUT_ON_SBUS) != FALSE)
		uint16 u16SBUS_MessageTick;              /*SBUS Send timer tick*/
#endif
		uint8 u8ReservedTick ;				  /*Time out tick */
	}stTimer;
#endif 
	/******************************************************************************************************/
	union
	{
		uint32 u32FuncFlag;                   /*the flag of speedometer function*/
		struct
		{	
			uint32 FirstUpdate              :2 ;  /*First update without damping,0 is default,1 is enable ,2 is done,3 is closed*/
			uint32 StepUpdateNoDamp         :2 ;  /*First update without damping,0 is default,1 is enable ,2 is done,3 Quick damping*/
			uint32 GaugeTableSource         :2 ;  /*Gauge table source mode,0 is default,1 is ROM ,2 is EEPROM*/
			uint32 ECM3ValueInvalidButKeep   :1 ;  /*ECM3 CAN value invalid but keep previous flag,0 is disable,1 is enable*/
			uint32 ADCValueInvalidButKeep   :1 ;  /*ADC signal value invalid but keep previous flag,0 is disable,1 is enable*/
			uint32 IncreaseClimate          :1 ;  /*Bar increase climate flag,0 is decrease,1 is increase*/
			uint32 Reserved                 :23;  /*Reserved bitfileds*/
		}stFuncFlag;	
	}unFunctionFlag;
	
	/******************************************************************************************************/
	/*Vehicle Configuration Function*/
	/******************************************************************************************************/
	struct
	{		
		uint8 u8FuelType;
	}stVConfig;
}CL_CFG_tstMAIN_OBJECT;  /*The coolant object type*/
/*********************************************************************************************************
*	Flag Operation 																		                 *
*********************************************************************************************************/
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
}CL_CFG_tstFLAG_ATTRIBUTE;

typedef enum
{				
  	CL_FLAG_DEFAULT  = 0x00,
	CL_FLAG_CLEAR    = 0x00,
	CL_FLAG_PREVIOUS = 0xFFFF		
}CL_CFG_enFLAG_OPERATION;  

typedef enum
{
	CL_COLD_INIT ,
	CL_WARM_INIT ,
	CL_WAKE_UP ,
	CL_SLEEP ,
	CL_ENTER_ABNORMAL,
	CL_EXIT_ABNORMAL
}CL_CFG_enFLAG_PROCESS_STAGE;

/*FlagName               	        FlagBit  FlagBit  SetValueWhen       SetValueWhen       SetValueWhen       SetValueWhen      SetValueWhen       SetValueWhen
									Index	 Length   ColdInit           WarmInit           WakeUp             Sleep             EnterAbnormal      ExitAbnormal  */
#define CL_CFG_FLAG_ATTRIBUTE    {\
/*First Update Flag*/            {    0 ,      2,     1/*1 is enable */, 1 ,                1 ,                1 ,               1 ,                1           },\
/*Gauge Table Source Flag*/      {    2 ,      2,     CL_FLAG_PREVIOUS , CL_FLAG_PREVIOUS , CL_FLAG_DEFAULT,   CL_FLAG_DEFAULT,  CL_FLAG_PREVIOUS , CL_FLAG_PREVIOUS },\
/*ECM3 Value Keep Previous*/      {    4 ,      1,     CL_FLAG_DEFAULT ,  CL_FLAG_DEFAULT ,  CL_FLAG_DEFAULT,   CL_FLAG_DEFAULT,  CL_FLAG_PREVIOUS , CL_FLAG_PREVIOUS },\
/*ADC Value Keep Previous*/      {	  5 ,	   1,	  CL_FLAG_DEFAULT ,  CL_FLAG_DEFAULT ,	CL_FLAG_DEFAULT,   CL_FLAG_DEFAULT,  CL_FLAG_PREVIOUS , CL_FLAG_PREVIOUS },\
/*Increase Climate Flag*/		 {	  6 ,	   1,	  1/*1 is increase*/,1 ,                1 ,                1 ,               CL_FLAG_PREVIOUS , CL_FLAG_PREVIOUS },\
								 {	 32 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },\
							     }

/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfGetRealTemperatureFromCANRawValue                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#define SWC_CL_START_SEC_CODE
#include "SWC_CL_MemMap.h" 

#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_CAN) != FALSE)
void CL_CFG_vFormulaOfGetRealTemperatureFromCANRawValue(CL_CFG_tstMAIN_OBJECT* stMainObject);
#endif 
/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfGetRealTemperatureFromADCRawValue                                          *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if ((CL_CFG_INPUT_MODE & CL_CFG_INPUT_SIGNAL_FROM_ADC) != FALSE)
void CL_CFG_vFormulaOfGetRealTemperatureFromADCRawValue(CL_CFG_tstMAIN_OBJECT* stMainObject);
#endif 
/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfGetTargetIndicateTemperatureFromRealTemperature                            *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
void CL_CFG_vFormulaOfGetTargetIndicateTemperatureFromRealTemperature(CL_CFG_tstMAIN_OBJECT* stMainObject);

/**********************************************************************************************************
*Function   : CL_CFG_vFormulaOfUserDefinedDampingOperation                                                *
*                                                                                                         *
*Description: TBD 	                                                                                      *
*                                                                                                         *
*Parameter	: CL_CFG_tstMAIN_OBJECT* stMainObject                                                         *
*                                                                                                         *
*Return 	: void                                                                                        *
*                                                                                                         *
*Author 	: Chao Feng                                                                                   *
*                                                                                                         *
*Date		: 2020-05-18                                                                                  *
**********************************************************************************************************/
#if (CL_CFG_DAMPING_MODEL == CL_CFG_MODEL_FROM_CONFIG_CODE)
void CL_CFG_vFormulaOfUserDefinedDampingOperation(CL_CFG_tstMAIN_OBJECT* stMainObject);
#endif

void CL_CFG_vVehicleConfig(CL_CFG_tstMAIN_OBJECT* stMainObject);

#define SWC_CL_STOP_SEC_CODE
#include "SWC_CL_MemMap.h" 

/*********************************************************************************************************/
#endif //CL_CFG_H
/**********************************************************************************************************
*  End Of File 																				   	          *
**********************************************************************************************************/
