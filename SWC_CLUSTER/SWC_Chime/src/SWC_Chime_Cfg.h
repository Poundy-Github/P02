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
**  Name:               SWC_Chime_Cfg.c
**
**  Description:        The main switching logic of the chime module
**
**  Organization:       
**
**********************************************************************************************************/
#ifndef SWC_CHIME_CFG_H
#define SWC_CHIME_CFG_H

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/


/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
#define SOUND_BREAK_STOPIMM					(0x0001)
#define SOUND_BREAK_BREAK					(0x0002)
#define SOUND_BREAK_BREAKIMM				(0x0004)
#define SOUND_BREAK_SEED_STOP_IMM			(0x0008)
#define SOUND_BREAK_RECOVER					(0x0010)
#define SOUND_BREAK_STOP_TIME_CANCEL		(0x0020)
#define SOUND_BREAK_BREAKSELF				(0x0040)
#define SOUND_BREAK_RECOVER_PENDING			(0x0080)
#define SOUND_BREAK_REQUEST_WITH_SOUND		(0x0100)
#define SOUND_PLAY_EDGE						(0x0200)
#define SOUND_BREAK_BREAKSELF_IMM			(0x0400)
#define SOUND_BREAK_REVOVER_WITH_TTFlASH	(0x0800)


#define SOUND_CHECK_ATTRIBUTE(id,bit)		((bit) == (ChimeAudioMap_s[(id)].AttributeBit_u16 & (bit)))

#define CHIME_REQUEST_TIMEOURTTIME			(5000u)

#define CHIME_TIMER_TASK_CYCLE				(10)

#define CHIME_TIMER_OUT_OF_CHIME			(1)

#define CHIME_AUDIO_SEED_MAP_TABLE			{0,625,1000,5000,333,333,500,20,20,20,20,50,50,250,150,830,1174,936,1205,896,1515,768,603,621,900,2427,1000,1998,100,1202,0}

#if defined (GWM_V35_PROJECT_TYPE_D03) || defined (GWM_V35_PROJECT_TYPE_P02)
	#define CHIME_AUDIO_MAP_TABLE \
	{\
		/*soundId								PlayTyp_e								freq									Priority  Rept		ReptTime  Shield	AttributeBit*/																								  \
	\
		{e_SoundType_IdleMode,					e_SoundSeed_None,						e_SoundFreq_None,						255,	  0,		0,		  0,		(0) 																										  },\
		/*Chime id = 1	  后倒车雷达故障-3次*/\
		{e_SoundType_RadarRFail3Times,			CHIME_SOUND_Radarfailure,				e_SoundFreq_0_889HZ,					1,		  3,		1124,	  0,		(SOUND_BREAK_STOP_TIME_CANCEL)																				  },\
		/*Chime id = 2	  前车雷达故障-3次*/\
		{e_SoundType_RadarFFail3Times,			CHIME_SOUND_Radarfailure,				e_SoundFreq_0_889HZ,					2,		  3,		1124,	  0,		(SOUND_BREAK_STOP_TIME_CANCEL)																				  },\
		/*Chime id = 3	  SDW雷达故障-3次*/\
		{e_SoundType_RadarSDWFail3Times,		CHIME_SOUND_Radarfailure,				e_SoundFreq_0_889HZ,					3,		  3,		1124,	  0,		(SOUND_BREAK_STOP_TIME_CANCEL)																				  },\
		/*Chime id = 4	  APA声音提示-单次*/\
		{e_SoundType_APAOnce,					CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						4,		  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_REQUEST_WITH_SOUND) 								  },\
		/*Chime id = 5	  后倒车雷达Long-重复*/\
		{e_SoundType_RadarRLongRe,				CHIME_SOUND_RearRadar_L,				e_SoundFreq_0HZ,						5,		  255,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 6	  前车雷达Long-重复*/\
		{e_SoundType_RadarFLongRe,				CHIME_SOUND_FrontRadar_L,				e_SoundFreq_0HZ,						6,		  255,		5000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 7	  SDW雷达Long-重复*/\
		{e_SoundType_RadarSDWLongRe,			CHIME_SOUND_RearRadar_L,				e_SoundFreq_0HZ,						7,		  255,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 8	  涉水深度DWD Long-重复*/\
		{e_SoundType_RadarDWDLongRe,			CHIME_SOUND_RearRadar_L,				e_SoundFreq_0HZ,						8,		  255,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 9	  RSDS侧后辅助系统声音-4HZ_重复*/\
		{e_SoundType_RadarRSDS4Hz,				CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_4HZ,						9,		  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_BREAKSELF | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 10    RSDS侧后辅助系统声音-3HZ_重复*/\
		{e_SoundType_RadarRSDS3Hz,				CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_3HZ,						10, 	  255,		333,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_BREAKSELF | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 11    前雷达4Hz-4HZ_重复*/\
		{e_SoundType_RadarF4HZ, 				CHIME_SOUND_FrontRadar_sigletone,		e_SoundFreq_1HZ,						11, 	  255,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 12    后倒车雷达3Hz-3HZ_重复*/\
		{e_SoundType_RadarR3HZ, 				CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_3HZ,						12, 	  255,		333,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 13    前车雷达3Hz-重复*/\
		{e_SoundType_RadarF3Hz, 				CHIME_SOUND_FrontRadar_sigletone,		e_SoundFreq_3HZ,						13, 	  255,		333,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 14    SDW3Hz-重复*/\
		{e_SoundType_RadarSDW3Hz,				CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_3HZ,						14, 	  255,		333,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 15    涉水深度DWD 3Hz-重复*/\
		{e_SoundType_RadarDWD3Hz,				CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_3HZ,						15, 	  255,		333,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 16    后雷达2Hz-重复*/\
		{e_SoundType_RadarR2Hz, 				CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_2HZ,						16, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 17    LDW&LKA声音提示-重复*/\
		{e_SoundType_LDW_LKAOnce,				CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						17, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 18    后倒车雷达1.5Hz-重复*/\
		{e_SoundType_RadarR1_5Hz,				CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_1_5HZ,						18, 	  255,		666,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 19    前车雷达1.5Hz-重复*/\
		{e_SoundType_RadarF1_5Hz,				CHIME_SOUND_FrontRadar_sigletone,		e_SoundFreq_1_5HZ,						19, 	  255,		666,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 20    SDW1.5Hz-重复*/\
		{e_SoundType_RadarSDW1_5Hz, 			CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_1_5HZ,						20, 	  255,		666,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 21    涉水深度DWD 1.5Hz-重复*/\
		{e_SoundType_RadarDWD1_5Hz, 			CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_1_5HZ,						21, 	  255,		666,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 22    后雷达-1Hz-3次*/\
		{e_SoundType_RadarR1Hz, 				CHIME_SOUND_RearRadar_sigaltone,		e_SoundFreq_1HZ,						22, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 23    前雷达-1Hz-3次*/\
		{e_SoundType_RadarF1Hz, 				CHIME_SOUND_FrontRadar_sigletone,		e_SoundFreq_1HZ,						23, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 24    危险！请立即远离车辆！-4HZ_重复*/\
		{e_SoundType_LeaveCar4Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_4HZ,						24, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 25    危险！请安全停车并立即远离车辆-4HZ_重复*/\
		{e_SoundType_StopCar4Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_4HZ,						25, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 26    紧急转向避让辅助激活-重复*/\
		{e_SoundType_SteeringActRe, 			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						26, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 27    自动紧急转向避让辅助激活-重复*/\
		{e_SoundType_AutoSteeringActRe, 		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						27, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 28    自动紧急制动启动+行人图片-重复*/\
		{e_SoundType_AutoBrakePersonRe, 		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						28, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 29    自动紧急制动启动+车辆图片-重复*/\
		{e_SoundType_AutoBrakeCarRe,			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						29, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 30    交叉路口辅助制动启动+车辆图片-重复*/\
		{e_SoundType_AuxiliaryBrakeRe,			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						30, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 31    前横穿侧向制动启动+车辆图片-重复*/\
		{e_SoundType_CrossSideBrakeRe,			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						31, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 32    倒车侧向制动启动+车辆图片-重复*/\
		{e_SoundType_RSideBrakeRe,				CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						32, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 33    请踩刹车（自适应巡航）-4HZ_重复*/\
		{e_SoundType_TakeBrakeAcc4Hz,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						33, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 34    请踩刹车（FCW）-重复*/\
		{e_SoundType_TakeBrakeFCWRe,			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						34, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 35    请踩刹车（前横穿侧向警告）-重复*/\
		{e_SoundType_TakeBrakeFCrossRe, 		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						35, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 36    请手握方向盘-4HZ_重复*/\
		{e_SoundType_TakeSteering4Hz,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						36, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 37    请手握方向盘-2HZ_重复*/\
		{e_SoundType_TakeSteering2Hz,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						37, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 38    请手握方向盘-1HZ_3次*/\
		{e_SoundType_TakeSteering1Hz,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						38, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 39    请保持安全距离-单次*/\
		{e_SoundType_KeepDistance,				CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						39, 	  1,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 40    请轻转方向盘-4HZ_重复*/\
		{e_SoundType_TakeCar4Hz,				CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						40, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 41    请轻转方向盘-2HZ_重复*/\
		{e_SoundType_TakeCar2Hz,				CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						41, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 42    请轻转方向盘-1HZ_3次*/\
		{e_SoundType_TakeCar1Hz,				CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						42, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 43    车道辅助系统退出请接管车辆-4HZ_重复*/\
		{e_SoundType_AssistExit4Hz, 			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						43, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 44    智慧巡航已退出，紧急刹车辅助启动-重复*/\
		{e_SoundType_SmartCruiseExit,		    CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						44, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 45    请目视前方-4HZ_重复*/\
		{e_SoundType_KeepPoint4Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_4HZ,						45, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 46    请目视前方-2HZ_重复*/\
		{e_SoundType_KeepPoint2Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_2HZ,						46, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 47    请目视前方-单次*/\
		{e_SoundType_KeepPointOnce, 			CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						47, 	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 48    请选择P挡-0.5HZ_60S*/\
		{e_SoundType_CheckP0_5Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_0_5HZ,						48, 	  30,		2000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 49    请注意前车距离-重复*/\
		{e_SoundType_CarDistancce,				CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						49, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 50    注意避让行人-重复*/\
		{e_SoundType_Pedestrian,				CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						50, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 51    注意对向来车-重复*/\
		{e_SoundType_FaceCar,					CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						51, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 52    注意横向来车-重复*/\
		{e_SoundType_CrosswiseCar,				CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						52, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 53    前方车辆紧急制动-重复*/\
		{e_SoundType_FrontCarAEB,				CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						53, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 54    注意前方失控车辆-重复*/\
		{e_SoundType_FrontCarUnContron, 		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						54, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 55    注意后方失控车辆-重复*/\
		{e_SoundType_BackCarUnContron,			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						55, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 56    注意周围失控车辆-重复*/\
		{e_SoundType_AroundCarUnContron,		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						56, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 57    请立即接管-4hz_重复*/\
		{e_SoundType_PlsTakeOver4Hz,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						57, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 58    请立即接管-2hz_重复*/\
		{e_SoundType_PlsTakeOver2Hz,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						58, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 59    请立即接管-1hz_3次*/\
		{e_SoundType_PlsTakeOver1Hz,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						59, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 60    车辆正在自动刹停，请立即接管-重复*/\
		{e_SoundType_CarAutoBrakePlsTake,		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						60, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 61    车辆正在靠边停车，请立即接管-重复*/\
		{e_SoundType_CarParkingPlsTake, 		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						61, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 62    车辆正在紧急刹停，请立即接管-重复*/\
		{e_SoundType_CarUrgeBrakePlsTake,		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						62, 	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 63    驶入匝道失败，请立即接管-重复*/\
		{e_SoundType_MoveRampFailPlsTake,		CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						63, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 64    汇入主路失败，请立即接管-4HZ_重复*/\
		{e_SoundType_MoveMainFailPlsTake4Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						64, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 65    汇入主路失败，请立即接管-2HZ_重复*/\
		{e_SoundType_MoveMainFailPlsTake2Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						65, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 66    汇入主路失败，请立即接管-1HZ_3次*/\
		{e_SoundType_MoveMainFailPlsTake1Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						66, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 67    转弯失败，请立即接管-4HZ_重复*/\
		{e_SoundType_TurnFailPlsTake4Hz,		CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						67, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 68    转弯失败，请立即接管-2HZ_重复*/\
		{e_SoundType_TurnFailPlsTake2Hz,		CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						68, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 69    转弯失败，请立即接管-1HZ_3次*/\
		{e_SoundType_TurnFailPlsTake1Hz,		CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						69, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 70    无法成功通过收费站，请立即接管-4HZ_重复*/\
		{e_SoundType_TollGateFailPlsTake4Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						70, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 71    无法成功通过收费站，请立即接管-2HZ_重复*/\
		{e_SoundType_TollGateFailPlsTake2Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						71, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 72    无法成功通过收费站，请立即接管-1HZ_3次*/\
		{e_SoundType_TollGateFailPlsTake1Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						72, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 73    无法成功通过环岛，请立即接管-4HZ_重复*/\
		{e_SoundType_RoundaboutFailPlsTake4Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_4HZ,						73, 	  255,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 74    无法成功通过环岛，请立即接管-2HZ_重复*/\
		{e_SoundType_RoundaboutFailPlsTake2Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						74, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 75    无法成功通过环岛，请立即接管-1HZ_3次*/\
		{e_SoundType_RoundaboutFailPlsTake1Hz,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						75, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 76    驶入匝道失败，请控制方向盘-2Hz_重复*/\
		{e_SoundType_MoveRampFailHandWheel_2Hz, CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_2HZ,						76, 	  255,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 77    驶入匝道失败，请控制方向盘-1Hz_3次*/\
		{e_SoundType_MoveRampFailHandWheel, 	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						77, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 78    汇入主路失败，请控制方向盘-1Hz_3次*/\
		{e_SoundType_MoveMainFailHandWheel, 	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						78, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 79    转弯失败，请控制方向盘-1Hz_3次*/\
		{e_SoundType_TurnFailPlsHandWheel,		CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						79, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 80    无法成功通过收费站，请控制方向盘-1Hz_3次*/\
		{e_SoundType_TollGateFailPlsHandWheel,	CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						80, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 81    无法成功通过环岛，请控制方向盘-1Hz_3次*/\
		{e_SoundType_RoundaboutFailPlsHandWheel,CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_1HZ,						81, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 82    胎压报警声音提示-1HZ_3次*/\
		{e_SoundType_Tpms1Hz,					CHIME_SOUND_Chime05,					e_SoundFreq_1HZ,						82, 	  3,		1000,	  0,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE | SOUND_BREAK_REVOVER_WITH_TTFlASH)},\
		/*Chime id = 83    混合动力系统故障报警音-1HZ_3次*/\
		{e_SoundType_HybridFail1Hz, 			CHIME_SOUND_Chime05,					e_SoundFreq_1HZ,						89, 	  3,		1000,	  0,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 84    安全带未系-0.5HZ_重复*/\
		{e_SoundType_Seatbelt0_5Hz, 			CHIME_SOUND_Chime05,					e_SoundFreq_0_5HZ,						84, 	  255,		2000,	  0,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING | SOUND_PLAY_EDGE | SOUND_BREAK_REVOVER_WITH_TTFlASH)},\
		/*Chime id = 85    蓄电池电量过低，系统3分钟后关闭电源，请启动车辆-0.5HZ_重复 */\
		{e_SoundType_battery_low0_5Hz,			CHIME_SOUND_Chime05,					e_SoundFreq_0_5HZ,						84, 	  255,		2000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 86    车门打开声音提示-1.5HZ_60S*/\
		{e_SoundType_DoorOpen1_5Hz, 			CHIME_SOUND_Chime05,					e_SoundFreq_1_5HZ,						85, 	  90,		666,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_BREAKSELF)					  },\
		/*Chime id = 87    车门打开声音提示-单次*/\
		{e_SoundType_DoorOpen1_Once,			CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						86, 	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 88    动态制动报警提示-0.5HZ_重复*/\
		{e_SoundType_DynamicBrake0_5Hz, 		CHIME_SOUND_Chime05,					e_SoundFreq_0_5HZ,						87, 	  255,		2000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 89    手刹未松报警提示-0.5HZ_重复*/\
		{e_SoundType_HandBrake0_5Hz,			CHIME_SOUND_Chime05,					e_SoundFreq_0_5HZ,						88, 	  255,		2000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 90    双闪提示音Click-单次*/\
		{e_SoundType_PositionTickOnce,			CHIME_SOUND_Hazard_Tick,				e_SoundFreq_0HZ,						89, 	  1,		20, 	  550,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 91    双闪提示音Clack-单次*/\
		{e_SoundType_PositionTockOnce,			CHIME_SOUND_Hazard_Tock,				e_SoundFreq_0HZ,						89, 	  1,		20, 	  550,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 92    左转向声音提示Click-单次*/\
		{e_SoundType_TurnLeftTickOnce,			CHIME_SOUND_Cornering_L_click,			e_SoundFreq_0HZ,						89, 	  1,		20, 	  600,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 93    左转向声音提示Clalk-单次*/\
		{e_SoundType_TurnLeftTockOnce,			CHIME_SOUND_Cornering_L_clark , 		e_SoundFreq_0HZ,						89, 	  1,		20, 	  600,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 94    右转向声音提示Click-单次*/\
		{e_SoundType_TurnRightTickOnce, 		CHIME_SOUND_Cornering_R_click,			e_SoundFreq_0HZ,						89, 	  1,		20, 	  600,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 95    右转向声音提示Clalk-单次*/\
		{e_SoundType_TurnRightTockOnce, 		CHIME_SOUND_Cornering_R_clark,			e_SoundFreq_0HZ,						89, 	  1,		20, 	  600,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 96    120km/h超速报警声音提示-1HZ_10S*/\
		{e_SoundType_OverSpeed1Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_1HZ,						90, 	  10,		1000,	  0,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_PLAY_EDGE | SOUND_BREAK_REVOVER_WITH_TTFlASH)},\
		/*Chime id = 97    印度超速报警（二级：120km/h）-1HZ_重复*/\
		{e_SoundType_India120Speed1Hz,			CHIME_SOUND_Chime05,					e_SoundFreq_1HZ,						91, 	  255,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER)											  },\
		/*Chime id = 98    印度超速报警（一级：80km/h）-1HZ_10S*/\
		{e_SoundType_India80Speed1Hz,			CHIME_SOUND_Chime05,					e_SoundFreq_1HZ,						92, 	  10,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER)											  },\
		/*Chime id = 99    超速提醒报警声音提示-1HZ_3S*/\
		{e_SoundType_OverSpeedAlarm1Hz, 		CHIME_SOUND_Chime05,					e_SoundFreq_1HZ,						93, 	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 100	限速报警标志提示声音-单次*/\
		{e_SoundType_TsrOnce,					CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						94, 	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 101	前桥差速锁声音报警-单次*/\
		{e_SoundType_FLockOnce, 				CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						95, 	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 102	后桥差速锁声音报警-单次*/\
		{e_SoundType_RLockOnce, 				CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						96, 	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 103	中央差速锁声音报警-单次*/\
		{e_SoundType_CLockOnce, 				CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						97, 	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 104	灯光未关-0.5HZ_60S*/\
		{e_SoundType_LightOn0_5Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_0_5HZ,						98, 	  30,		2000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 105	前方即将穿过隧道,请及时接管车辆-单次*/\
		{e_SoundType_TunnelTakeCarOnce, 		CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_0HZ,						99, 	  1,		100,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 106	前方存在分叉路口，请及时接管车辆-单次*/\
		{e_SoundType_RoadTakeCarOnce,			CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_0HZ,						100,	  1,		100,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 107	模式切换失败，请熄火重试-单次*/\
		{e_SoundType_ModeFailOnce,				CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						101,	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 108	横向控制已退出，请控制方向-单次*/\
		{e_SoundType_HcExitTakeDirOnce, 		CHIME_SOUND_Cruise_Quit,				e_SoundFreq_0HZ,						102,	  1,		1997,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 109	前方XX米，即将退出自动导航辅助，请准备接管*/\
		{e_SoundType_NOHExitPlsTake,			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						103,	  1,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 110	后方车辆车速过高-1HZ_3S*/\
		{e_SoundType_RCarSpeedHigh1Hz,			CHIME_SOUND_Chime04,					e_SoundFreq_1HZ,						104,	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 111	4L模式请减速慢行-单次*/\
		{e_SoundType_4LModeOnce,				CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						105,	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 112	已上电可挂挡行驶-单次*/\
		{e_SoundType_PowerOnOnce,				CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						106,	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 113	请注意休息-单次*/\
		{e_SoundType_PleaseRestOnce,			CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						107,	  1,		250,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 114	请注意休息-1HZ_3S*/\
		{e_SoundType_PleaseRest1Hz, 			CHIME_SOUND_Chime05,					e_SoundFreq_1HZ,						108,	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 115	巡航类功能激活-单次*/\
		{e_SoundType_CruiseActOnce, 			CHIME_SOUND_Cruise_Active,				e_SoundFreq_0HZ,						109,	  1,		2426,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 116	LCK功能激活-单次*/\
		{e_SoundType_LckActOnce,				CHIME_SOUND_Cruise_Active,				e_SoundFreq_0HZ,						110,	  1,		2426,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 117	巡航类功能降级-单次*/\
		{e_SoundType_CruiseDownOnce,			CHIME_SOUND_Cruise_Quit,				e_SoundFreq_0HZ,						111,	  1,		1997,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 118	巡航类功能启动-单次*/\
		{e_SoundType_CruiseStartOnce,			CHIME_SOUND_Cruise_Ready,				e_SoundFreq_0HZ,						112,	  1,		900,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 119	左侧智慧躲闪-单次*/\
		{e_SoundType_LeftSmartdodgeOnce,		CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						113,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 120	右侧智慧躲闪-单次*/\
		{e_SoundType_RightSmartdodgeOnce,		CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						114,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 121	车辆偏离请控制方向盘-持续*/\
		{e_SoundType_VehicleDevRepeate, 		CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						115,	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 122	前方急转弯，请手扶方向盘*/\
		{e_SoundType_UrgeTurnPlsHoldWheel,		CHIME_SOUND_Cruise_TakeOveraigaltone,	e_SoundFreq_0HZ,						116,	  1,		100,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 123	车道辅助系统持续控制中请安全驾驶-持续*/\
		{e_SoundType_SafeDrivRepeat,			CHIME_SOUND_Chime04,					e_SoundFreq_0HZ,						117,	  255,		830,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 124	通用报警-10次*/\
		{e_SoundType_LcdAlarmTen,				CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						118,	  10,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 125	12V电源系统故障，舒适功能关闭，请联系4S店维修！通用报警-10次*/\
		{e_SoundType_12VPowerSysFail,			CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						119,	  10,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 126	通用报警-3次*/\
		{e_SoundType_LcdAlarmThree, 			CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						120,	  3,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 127	通用报警-单次*/\
		{e_SoundType_LcdAlarmOnce,				CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						121,	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 128	动力电池预热中-单次*/\
		{e_SoundType_PowerBatWarmOnce,			CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						122,	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 129	充电故障声音提示(EV)*/\
		{e_SoundType_ChargeFaultOnce,			CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						123,	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 130	自适应巡航无法激活-单次*/\
		{e_SoundType_AccCruiseFailOnce, 		CHIME_SOUND_Cruise_Fail,				e_SoundFreq_0HZ,						124,	  1,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 131	自适应巡航功能取消-单次*/\
		{e_SoundType_AccCruiseQuitOnce, 		CHIME_SOUND_Cruise_Quit,				e_SoundFreq_0HZ,						125,	  1,		1997,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 132	智能巡航辅助无法激活-单次*/\
		{e_SoundType_SmartCruiseFailOnce,		CHIME_SOUND_Cruise_Fail,				e_SoundFreq_0HZ,						126,	  1,		1000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 133	智能巡航辅助功能取消-单次*/\
		{e_SoundType_SmartCruisQuitOnce,		CHIME_SOUND_Cruise_Quit,				e_SoundFreq_0HZ,						127,	  1,		1997,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 134	前车已起步-单次*/\
		{e_SoundType_FCOKOnce,					CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						128,	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 135	前车已起步，请注意前方道路环境-单次*/\
		{e_SoundType_FCOKAttRoadEnvOnce,		CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						129,	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 136	前车已起步，请保持注意力-单次*/\
		{e_SoundType_FCOKKeepAtOnce,			CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						130,	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 137	前车已起步，请接管车辆-单次*/\
		{e_SoundType_FCOKTakeCarOnce,			CHIME_SOUND_LCDgong,					e_SoundFreq_0HZ,						131,	  1,		500,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 138	自适应巡航已激活，请保持注意力-单次*/\
		{e_SoundType_AccCruiseOkkeepAtOnce, 	CHIME_SOUND_Cruise_Active,				e_SoundFreq_0HZ,						132,	  1,		2426,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 139	智慧巡航已激活，请保持注意力并手握方向盘-单次*/\
		{e_SoundType_SmartCruiseOkhwOnce,		CHIME_SOUND_Cruise_Active,				e_SoundFreq_0HZ,						133,	  1,		2426,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 140	自动导航辅助已启动*/\
		{e_SoundType_NOHIsActivated,			CHIME_SOUND_Cruise_Active,				e_SoundFreq_0HZ,						134,	  1,		2426,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 141	环境条件不满足，请稍后尝试*/\
		{e_SoundType_ConditionNotMet,			CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						135,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 142	请保持专注驾驶，再次开启尝试*/\
		{e_SoundType_StayFocusedTryAgain,		CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						136,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 143	请保持手握方向盘，再次尝试开启*/\
		{e_SoundType_HandsOnthewheelTryAgain,	CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						137,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 144	请系紧安全带*/\
		{e_SoundType_FastenSeatBelt,			CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						138,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 145	请关闭车门*/\
		{e_SoundType_CloseTheDoor,				CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						139,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 146	请副驾驶系紧安全带*/\
		{e_SoundType_FastenPassengerSeat,		CHIME_SOUND_Chime01_sigletone,			e_SoundFreq_0HZ,						140,	  1,		150,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
		/*Chime id = 147	CCO(越野巡航)故障指示-单次*/\
		{e_SoundType_CCOOnce,					CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						141,	  1,		250,	  0,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 148	TAB（转向辅助）失效指示-单次*/\
		{e_SoundType_TABFailOnce,				CHIME_SOUND_Chime05,					e_SoundFreq_0HZ,						142,	  1,		250,	  0,		(SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)							  },\
		/*Chime id = 149	上高压后司机离开车门-0.5HZ_12S*/\
		{e_SoundType_HighVol0_5Hz,				CHIME_SOUND_Chime05,					e_SoundFreq_0_5HZ,						143,	  6,		2000,	  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)				  },\
		/*Chime id = 150	预留*/\
		{e_SoundType_Reserved,					CHIME_SOUND_Reserved,					e_SoundFreq_0HZ,						255,	  0,		0,		  0,		(SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)																	  },\
	};

;
#else
	#define CHIME_AUDIO_MAP_TABLE \
	{\
   	 /*soundId                               PlayTyp_e                               freq                                    Priority  Rept      ReptTime  Shield    AttributeBit*/                                                                                                \
	\
		{e_SoundType_IdleMode,                  e_SoundSeed_None,                       e_SoundFreq_None,                       255,      0,        0,        0,        (0)                                                                                                           },\
		/*Chime id = 1    后倒车雷达故障-3次*/\
		{e_SoundType_RadarRFail3Times,          CHIME_SOUND_Radarfailure,               e_SoundFreq_0_889HZ,                    1,        3,        1124,     0,        (SOUND_BREAK_STOP_TIME_CANCEL)                                                                                },\
		/*Chime id = 2    前车雷达故障-3次*/\
		{e_SoundType_RadarFFail3Times,          CHIME_SOUND_Radarfailure,               e_SoundFreq_0_889HZ,                    2,        3,        1124,     0,        (SOUND_BREAK_STOP_TIME_CANCEL)                                                                                },\
		/*Chime id = 3    SDW雷达故障-3次*/\
		{e_SoundType_RadarSDWFail3Times,        CHIME_SOUND_Radarfailure,               e_SoundFreq_0_889HZ,                    3,        3,        1124,     0,        (SOUND_BREAK_STOP_TIME_CANCEL)                                                                                },\
		/*Chime id = 4    APA声音提示-单次*/\
		{e_SoundType_APAOnce,                   CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        4,        1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_REQUEST_WITH_SOUND)                                   },\
		/*Chime id = 5    后倒车雷达Long-重复*/\
		{e_SoundType_RadarRLongRe,              CHIME_SOUND_RearRadar_L,                e_SoundFreq_0HZ,                        5,        255,      1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 6    前车雷达Long-重复*/\
		{e_SoundType_RadarFLongRe,              CHIME_SOUND_FrontRadar_L,               e_SoundFreq_0HZ,                        6,        255,      5000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 7    SDW雷达Long-重复*/\
		{e_SoundType_RadarSDWLongRe,            CHIME_SOUND_RearRadar_L,                e_SoundFreq_0HZ,                        7,        255,      1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 8    涉水深度DWD Long-重复*/\
		{e_SoundType_RadarDWDLongRe,            CHIME_SOUND_RearRadar_L,                e_SoundFreq_0HZ,                        8,        255,      1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_SEED_STOP_IMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 9    RSDS侧后辅助系统声音-4HZ_重复*/\
		{e_SoundType_RadarRSDS4Hz,              CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_4HZ,                        9,        255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_BREAKSELF | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 10    RSDS侧后辅助系统声音-3HZ_重复*/\
		{e_SoundType_RadarRSDS3Hz,              CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_3HZ,                        10,       255,      333,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_BREAKSELF | SOUND_BREAK_RECOVER_PENDING)},\
		/*Chime id = 11    前雷达4Hz-4HZ_重复*/\
		{e_SoundType_RadarF4HZ,                 CHIME_SOUND_FrontRadar_sigletone,       e_SoundFreq_1HZ,                        11,       255,      1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 12    后倒车雷达3Hz-3HZ_重复*/\
		{e_SoundType_RadarR3HZ,                 CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_3HZ,                        12,       255,      333,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 13    前车雷达3Hz-重复*/\
		{e_SoundType_RadarF3Hz,                 CHIME_SOUND_FrontRadar_sigletone,       e_SoundFreq_3HZ,                        13,       255,      333,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 14    SDW3Hz-重复*/\
		{e_SoundType_RadarSDW3Hz,               CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_3HZ,                        14,       255,      333,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 15    涉水深度DWD 3Hz-重复*/\
		{e_SoundType_RadarDWD3Hz,               CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_3HZ,                        15,       255,      333,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 16    后雷达2Hz-重复*/\
		{e_SoundType_RadarR2Hz,                 CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_2HZ,                        16,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 17    LDW&LKA声音提示-重复*/\
		{e_SoundType_LDW_LKAOnce,               CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        17,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 18    后倒车雷达1.5Hz-重复*/\
		{e_SoundType_RadarR1_5Hz,               CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_1_5HZ,                      18,       255,      666,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 19    前车雷达1.5Hz-重复*/\
		{e_SoundType_RadarF1_5Hz,               CHIME_SOUND_FrontRadar_sigletone,       e_SoundFreq_1_5HZ,                      19,       255,      666,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 20    SDW1.5Hz-重复*/\
		{e_SoundType_RadarSDW1_5Hz,             CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_1_5HZ,                      20,       255,      666,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 21    涉水深度DWD 1.5Hz-重复*/\
		{e_SoundType_RadarDWD1_5Hz,             CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_1_5HZ,                      21,       255,      666,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 22    后雷达-1Hz-3次*/\
		{e_SoundType_RadarR1Hz,                 CHIME_SOUND_RearRadar_sigaltone,        e_SoundFreq_1HZ,                        22,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 23    前雷达-1Hz-3次*/\
		{e_SoundType_RadarF1Hz,                 CHIME_SOUND_FrontRadar_sigletone,       e_SoundFreq_1HZ,                        23,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 24    危险！请立即远离车辆！-4HZ_重复*/\
		{e_SoundType_LeaveCar4Hz,               CHIME_SOUND_Chime05,                    e_SoundFreq_4HZ,                        24,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 25    危险！请安全停车并立即远离车辆-4HZ_重复*/\
		{e_SoundType_StopCar4Hz,                CHIME_SOUND_Chime05,                    e_SoundFreq_4HZ,                        25,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 26    紧急转向避让辅助激活-重复*/\
		{e_SoundType_SteeringActRe,             CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        26,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 27    自动紧急转向避让辅助激活-重复*/\
		{e_SoundType_AutoSteeringActRe,         CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        27,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 28    自动紧急制动启动+行人图片-重复*/\
		{e_SoundType_AutoBrakePersonRe,         CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        28,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 29    自动紧急制动启动+车辆图片-重复*/\
		{e_SoundType_AutoBrakeCarRe,            CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        29,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 30    交叉路口辅助制动启动+车辆图片-重复*/\
		{e_SoundType_AuxiliaryBrakeRe,          CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        30,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 31    前横穿侧向制动启动+车辆图片-重复*/\
		{e_SoundType_CrossSideBrakeRe,          CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        31,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 32    倒车侧向制动启动+车辆图片-重复*/\
		{e_SoundType_RSideBrakeRe,              CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        32,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 33    请踩刹车（自适应巡航）-4HZ_重复*/\
		{e_SoundType_TakeBrakeAcc4Hz,           CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        33,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 34    请踩刹车（FCW）-重复*/\
		{e_SoundType_TakeBrakeFCWRe,            CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        34,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 35    请踩刹车（前横穿侧向警告）-重复*/\
		{e_SoundType_TakeBrakeFCrossRe,         CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        35,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 36    请手握方向盘-4HZ_重复*/\
		{e_SoundType_TakeSteering4Hz,           CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        36,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 37    请手握方向盘-2HZ_重复*/\
		{e_SoundType_TakeSteering2Hz,           CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        37,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 38    请手握方向盘-1HZ_3次*/\
		{e_SoundType_TakeSteering1Hz,           CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        38,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 39    请保持安全距离-单次*/\
		{e_SoundType_KeepDistance,              CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        39,       1,        830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 40    请轻转方向盘-4HZ_重复*/\
		{e_SoundType_TakeCar4Hz,                CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        40,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 41    请轻转方向盘-2HZ_重复*/\
		{e_SoundType_TakeCar2Hz,                CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        41,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 42    请轻转方向盘-1HZ_3次*/\
		{e_SoundType_TakeCar1Hz,                CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        42,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 43    车道辅助系统退出请接管车辆-4HZ_重复*/\
		{e_SoundType_AssistExit4Hz,             CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        43,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 44    智慧巡航已退出，紧急刹车辅助启动-重复*/\
		{e_SoundType_SmartCruiseExit,           CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        44,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 45    请目视前方-4HZ_重复*/\
		{e_SoundType_KeepPoint4Hz,              CHIME_SOUND_Chime05,                    e_SoundFreq_4HZ,                        45,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 46    请目视前方-2HZ_重复*/\
		{e_SoundType_KeepPoint2Hz,              CHIME_SOUND_Chime05,                    e_SoundFreq_2HZ,                        46,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 47    请目视前方-单次*/\
		{e_SoundType_KeepPointOnce,             CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        47,       1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 48    请选择P挡-0.5HZ_60S*/\
		{e_SoundType_CheckP0_5Hz,               CHIME_SOUND_Chime05,                    e_SoundFreq_0_5HZ,                      48,       30,       2000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 49    请注意前车距离-重复*/\
		{e_SoundType_CarDistancce,              CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        49,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 50    注意避让行人-重复*/\
		{e_SoundType_Pedestrian,                CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        50,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 51    注意对向来车-重复*/\
		{e_SoundType_FaceCar,                   CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        51,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 52    注意横向来车-重复*/\
		{e_SoundType_CrosswiseCar,              CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        52,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 53    前方车辆紧急制动-重复*/\
		{e_SoundType_FrontCarAEB,               CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        53,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 54    注意前方失控车辆-重复*/\
		{e_SoundType_FrontCarUnContron,         CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        54,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 55    注意后方失控车辆-重复*/\
		{e_SoundType_BackCarUnContron,          CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        55,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 56    注意周围失控车辆-重复*/\
		{e_SoundType_AroundCarUnContron,        CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        56,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 57    请立即接管-4hz_重复*/\
		{e_SoundType_PlsTakeOver4Hz,            CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        57,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 58    请立即接管-2hz_重复*/\
		{e_SoundType_PlsTakeOver2Hz,            CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        58,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 59    请立即接管-1hz_3次*/\
		{e_SoundType_PlsTakeOver1Hz,            CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        59,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 60    车辆正在自动刹停，请立即接管-重复*/\
		{e_SoundType_CarAutoBrakePlsTake,       CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        60,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 61    车辆正在靠边停车，请立即接管-重复*/\
		{e_SoundType_CarParkingPlsTake,         CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        61,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 62    车辆正在紧急刹停，请立即接管-重复*/\
		{e_SoundType_CarUrgeBrakePlsTake,       CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        62,       255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 63    驶入匝道失败，请立即接管-重复*/\
		{e_SoundType_MoveRampFailPlsTake,       CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        63,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 64    汇入主路失败，请立即接管-4HZ_重复*/\
		{e_SoundType_MoveMainFailPlsTake4Hz,    CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        64,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 65    汇入主路失败，请立即接管-2HZ_重复*/\
		{e_SoundType_MoveMainFailPlsTake2Hz,    CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        65,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 66    汇入主路失败，请立即接管-1HZ_3次*/\
		{e_SoundType_MoveMainFailPlsTake1Hz,    CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        66,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 67    转弯失败，请立即接管-4HZ_重复*/\
		{e_SoundType_TurnFailPlsTake4Hz,        CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        67,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 68    转弯失败，请立即接管-2HZ_重复*/\
		{e_SoundType_TurnFailPlsTake2Hz,        CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        68,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 69    转弯失败，请立即接管-1HZ_3次*/\
		{e_SoundType_TurnFailPlsTake1Hz,        CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        69,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 70    无法成功通过收费站，请立即接管-4HZ_重复*/\
		{e_SoundType_TollGateFailPlsTake4Hz,    CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        70,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 71    无法成功通过收费站，请立即接管-2HZ_重复*/\
		{e_SoundType_TollGateFailPlsTake2Hz,    CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        71,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 72    无法成功通过收费站，请立即接管-1HZ_3次*/\
		{e_SoundType_TollGateFailPlsTake1Hz,    CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        72,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 73    无法成功通过环岛，请立即接管-4HZ_重复*/\
		{e_SoundType_RoundaboutFailPlsTake4Hz,  CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_4HZ,                        73,       255,      250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 74    无法成功通过环岛，请立即接管-2HZ_重复*/\
		{e_SoundType_RoundaboutFailPlsTake2Hz,  CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        74,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 75    无法成功通过环岛，请立即接管-1HZ_3次*/\
		{e_SoundType_RoundaboutFailPlsTake1Hz,  CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        75,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 76    驶入匝道失败，请控制方向盘-2Hz_重复*/\
		{e_SoundType_MoveRampFailHandWheel_2Hz, CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_2HZ,                        76,       255,      500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 77    驶入匝道失败，请控制方向盘-1Hz_3次*/\
		{e_SoundType_MoveRampFailHandWheel,     CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        77,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 78    汇入主路失败，请控制方向盘-1Hz_3次*/\
		{e_SoundType_MoveMainFailHandWheel,     CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        78,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 79    转弯失败，请控制方向盘-1Hz_3次*/\
		{e_SoundType_TurnFailPlsHandWheel,      CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        79,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 80    无法成功通过收费站，请控制方向盘-1Hz_3次*/\
		{e_SoundType_TollGateFailPlsHandWheel,  CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        80,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 81    无法成功通过环岛，请控制方向盘-1Hz_3次*/\
		{e_SoundType_RoundaboutFailPlsHandWheel,CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_1HZ,                        81,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 82    胎压报警声音提示-1HZ_3次*/\
		{e_SoundType_Tpms1Hz,                   CHIME_SOUND_Chime05,                    e_SoundFreq_1HZ,                        82,       3,        1000,     0,        (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE | SOUND_BREAK_REVOVER_WITH_TTFlASH)},\
		/*Chime id = 83    混合动力系统故障报警音-1HZ_3次*/\
		{e_SoundType_HybridFail1Hz,             CHIME_SOUND_Chime05,                    e_SoundFreq_1HZ,                        89,       3,        1000,     0,        (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 84    安全带未系-0.5HZ_重复*/\
		{e_SoundType_Seatbelt0_5Hz,             CHIME_SOUND_Chime05,                    e_SoundFreq_0_5HZ,                      84,       255,      2000,     0,        (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING | SOUND_PLAY_EDGE | SOUND_BREAK_REVOVER_WITH_TTFlASH)},\
		/*Chime id = 85    蓄电池电量过低，系统3分钟后关闭电源，请启动车辆-0.5HZ_重复 */\
		{e_SoundType_battery_low0_5Hz,          CHIME_SOUND_Chime05,                    e_SoundFreq_0_5HZ,                      84,       255,      2000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 86    车门打开声音提示-1.5HZ_60S*/\
		{e_SoundType_DoorOpen1_5Hz,             CHIME_SOUND_Chime05,                    e_SoundFreq_1_5HZ,                      85,       90,       666,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_BREAKSELF)                      },\
		/*Chime id = 87    车门打开声音提示-单次*/\
		{e_SoundType_DoorOpen1_Once,            CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        86,       1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 88    动态制动报警提示-0.5HZ_重复*/\
		{e_SoundType_DynamicBrake0_5Hz,         CHIME_SOUND_Chime05,                    e_SoundFreq_0_5HZ,                      87,       255,      2000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 89    手刹未松报警提示-0.5HZ_重复*/\
		{e_SoundType_HandBrake0_5Hz,            CHIME_SOUND_Chime05,                    e_SoundFreq_0_5HZ,                      88,       255,      2000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 90    双闪提示音Click-单次*/\
		{e_SoundType_PositionTickOnce,          CHIME_SOUND_Hazard_Tick,                e_SoundFreq_0HZ,                        89,       1,        20,       550,      (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 91    双闪提示音Clack-单次*/\
		{e_SoundType_PositionTockOnce,          CHIME_SOUND_Hazard_Tock,                e_SoundFreq_0HZ,                        89,       1,        20,       550,      (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 92    左转向声音提示Click-单次*/\
		{e_SoundType_TurnLeftTickOnce,          CHIME_SOUND_Cornering_L_click,          e_SoundFreq_0HZ,                        89,       1,        20,       600,      (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 93    左转向声音提示Clalk-单次*/\
		{e_SoundType_TurnLeftTockOnce,          CHIME_SOUND_Cornering_L_clark ,         e_SoundFreq_0HZ,                        89,       1,        20,       600,      (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 94    右转向声音提示Click-单次*/\
		{e_SoundType_TurnRightTickOnce,         CHIME_SOUND_Cornering_R_click,          e_SoundFreq_0HZ,                        89,       1,        20,       600,      (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 95    右转向声音提示Clalk-单次*/\
		{e_SoundType_TurnRightTockOnce,         CHIME_SOUND_Cornering_R_clark,          e_SoundFreq_0HZ,                        89,       1,        20,       600,      (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 96    120km/h超速报警声音提示-1HZ_10S*/\
		{e_SoundType_OverSpeed1Hz,              CHIME_SOUND_Chime05,                    e_SoundFreq_1HZ,                        90,       10,       1000,     0,        (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_PLAY_EDGE | SOUND_BREAK_REVOVER_WITH_TTFlASH)},\
		/*Chime id = 97    印度超速报警（二级：120km/h）-1HZ_重复*/\
		{e_SoundType_India120Speed1Hz,          CHIME_SOUND_Chime05,                    e_SoundFreq_1HZ,                        91,       255,      1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER)                                              },\
		/*Chime id = 98    印度超速报警（一级：80km/h）-1HZ_10S*/\
		{e_SoundType_India80Speed1Hz,           CHIME_SOUND_Chime05,                    e_SoundFreq_1HZ,                        92,       10,       1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER)                                              },\
		/*Chime id = 99    超速提醒报警声音提示-1HZ_3S*/\
		{e_SoundType_OverSpeedAlarm1Hz,         CHIME_SOUND_Chime05,                    e_SoundFreq_1HZ,                        93,       3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 100    限速报警标志提示声音-单次*/\
		{e_SoundType_TsrOnce,                   CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        94,       1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 101    前桥差速锁声音报警-单次*/\
		{e_SoundType_FLockOnce,                 CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        95,       1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 102    后桥差速锁声音报警-单次*/\
		{e_SoundType_RLockOnce,                 CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        96,       1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 103    中央差速锁声音报警-单次*/\
		{e_SoundType_CLockOnce,                 CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        97,       1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 104    灯光未关-0.5HZ_60S*/\
		{e_SoundType_LightOn0_5Hz,              CHIME_SOUND_Chime05,                    e_SoundFreq_0_5HZ,                      98,       30,       2000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 105    前方即将穿过隧道,请及时接管车辆-单次*/\
		{e_SoundType_TunnelTakeCarOnce,         CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_0HZ,                        99,       1,        100,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 106    前方存在分叉路口，请及时接管车辆-单次*/\
		{e_SoundType_RoadTakeCarOnce,           CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_0HZ,                        100,      1,        100,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 107    模式切换失败，请熄火重试-单次*/\
		{e_SoundType_ModeFailOnce,              CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        101,      1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 108    横向控制已退出，请控制方向-单次*/\
		{e_SoundType_HcExitTakeDirOnce,         CHIME_SOUND_Cruise_Quit,                e_SoundFreq_0HZ,                        102,      1,        1997,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 109    前方XX米，即将退出自动导航辅助，请准备接管*/\
		{e_SoundType_NOHExitPlsTake,            CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        103,      1,        830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 110    后方车辆车速过高-1HZ_3S*/\
		{e_SoundType_RCarSpeedHigh1Hz,          CHIME_SOUND_Chime04,                    e_SoundFreq_1HZ,                        104,      3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 111    4L模式请减速慢行-单次*/\
		{e_SoundType_4LModeOnce,                CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        105,      1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 112    已上电可挂挡行驶-单次*/\
		{e_SoundType_PowerOnOnce,               CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        106,      1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 113    请注意休息-单次*/\
		{e_SoundType_PleaseRestOnce,            CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        107,      1,        250,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 114    请注意休息-1HZ_3S*/\
		{e_SoundType_PleaseRest1Hz,             CHIME_SOUND_Chime05,                    e_SoundFreq_1HZ,                        108,      3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 115    巡航类功能激活-单次*/\
		{e_SoundType_CruiseActOnce,             CHIME_SOUND_Cruise_Active,              e_SoundFreq_0HZ,                        109,      1,        2426,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 116    LCK功能激活-单次*/\
		{e_SoundType_LckActOnce,                CHIME_SOUND_Cruise_Active,              e_SoundFreq_0HZ,                        110,      1,        2426,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 117    巡航类功能降级-单次*/\
		{e_SoundType_CruiseDownOnce,            CHIME_SOUND_Cruise_Quit,                e_SoundFreq_0HZ,                        111,      1,        1997,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 118    巡航类功能启动-单次*/\
		{e_SoundType_CruiseStartOnce,           CHIME_SOUND_Cruise_Ready,               e_SoundFreq_0HZ,                        112,      1,        900,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 119    左侧智慧躲闪-单次*/\
		{e_SoundType_LeftSmartdodgeOnce,        CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        113,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 120    右侧智慧躲闪-单次*/\
		{e_SoundType_RightSmartdodgeOnce,       CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        114,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 121    车辆偏离请控制方向盘-持续*/\
		{e_SoundType_VehicleDevRepeate,         CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        115,      255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 122    前方急转弯，请手扶方向盘*/\
		{e_SoundType_UrgeTurnPlsHoldWheel,      CHIME_SOUND_Cruise_TakeOveraigaltone,   e_SoundFreq_0HZ,                        116,      1,        100,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 123    车道辅助系统持续控制中请安全驾驶-持续*/\
		{e_SoundType_SafeDrivRepeat,            CHIME_SOUND_Chime04,                    e_SoundFreq_0HZ,                        117,      255,      830,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 124    通用报警-10次*/\
		{e_SoundType_LcdAlarmTen,               CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        118,      10,       1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 125    12V电源系统故障，舒适功能关闭，请联系4S店维修！通用报警-10次*/\
		{e_SoundType_12VPowerSysFail,           CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        119,      10,       1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 126    通用报警-3次*/\
		{e_SoundType_LcdAlarmThree,             CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        120,      3,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 127    通用报警-单次*/\
		{e_SoundType_LcdAlarmOnce,              CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        121,      1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 128    动力电池预热中-单次*/\
		{e_SoundType_PowerBatWarmOnce,          CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        122,      1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 129    充电故障声音提示(EV)*/\
		{e_SoundType_ChargeFaultOnce,           CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        123,      1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 130    自适应巡航无法激活-单次*/\
		{e_SoundType_AccCruiseFailOnce,         CHIME_SOUND_Cruise_Fail,                e_SoundFreq_0HZ,                        124,      1,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 131    自适应巡航功能取消-单次*/\
		{e_SoundType_AccCruiseQuitOnce,         CHIME_SOUND_Cruise_Quit,                e_SoundFreq_0HZ,                        125,      1,        1997,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 132    智能巡航辅助无法激活-单次*/\
		{e_SoundType_SmartCruiseFailOnce,       CHIME_SOUND_Cruise_Fail,                e_SoundFreq_0HZ,                        126,      1,        1000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 133    智能巡航辅助功能取消-单次*/\
		{e_SoundType_SmartCruisQuitOnce,        CHIME_SOUND_Cruise_Quit,                e_SoundFreq_0HZ,                        127,      1,        1997,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 134    前车已起步-单次*/\
		{e_SoundType_FCOKOnce,                  CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        128,      1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 135    前车已起步，请注意前方道路环境-单次*/\
		{e_SoundType_FCOKAttRoadEnvOnce,        CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        129,      1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 136    前车已起步，请保持注意力-单次*/\
		{e_SoundType_FCOKKeepAtOnce,            CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        130,      1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 137    前车已起步，请接管车辆-单次*/\
		{e_SoundType_FCOKTakeCarOnce,           CHIME_SOUND_LCDgong,                    e_SoundFreq_0HZ,                        131,      1,        500,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 138    自适应巡航已激活，请保持注意力-单次*/\
		{e_SoundType_AccCruiseOkkeepAtOnce,     CHIME_SOUND_Cruise_Active,              e_SoundFreq_0HZ,                        132,      1,        2426,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 139    智慧巡航已激活，请保持注意力并手握方向盘-单次*/\
		{e_SoundType_SmartCruiseOkhwOnce,       CHIME_SOUND_Cruise_Active,              e_SoundFreq_0HZ,                        133,      1,        2426,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 140    自动导航辅助已启动*/\
		{e_SoundType_NOHIsActivated,            CHIME_SOUND_Cruise_Active,              e_SoundFreq_0HZ,                        134,      1,        2426,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 141    环境条件不满足，请稍后尝试*/\
		{e_SoundType_ConditionNotMet,           CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        135,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 142    请保持专注驾驶，再次开启尝试*/\
		{e_SoundType_StayFocusedTryAgain,       CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        136,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 143    请保持手握方向盘，再次尝试开启*/\
		{e_SoundType_HandsOnthewheelTryAgain,   CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        137,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 144    请系紧安全带*/\
		{e_SoundType_FastenSeatBelt,            CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        138,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 145    请关闭车门*/\
		{e_SoundType_CloseTheDoor,              CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        139,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 146    请副驾驶系紧安全带*/\
		{e_SoundType_FastenPassengerSeat,       CHIME_SOUND_Chime01_sigletone,          e_SoundFreq_0HZ,                        140,      1,        150,      0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
		/*Chime id = 147    CCO(越野巡航)故障指示-单次*/\
		{e_SoundType_CCOOnce,                   CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        141,      1,        250,      0,        (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 148    TAB（转向辅助）失效指示-单次*/\
		{e_SoundType_TABFailOnce,               CHIME_SOUND_Chime05,                    e_SoundFreq_0HZ,                        142,      1,        250,      0,        (SOUND_BREAK_STOPIMM | SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_PLAY_EDGE)                            },\
		/*Chime id = 149    上高压后司机离开车门-0.5HZ_12S*/\
		{e_SoundType_HighVol0_5Hz,              CHIME_SOUND_Chime05,                    e_SoundFreq_0_5HZ,                      143,      6,        2000,     0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM | SOUND_BREAK_RECOVER | SOUND_BREAK_RECOVER_PENDING)                },\
		/*Chime id = 150    预留*/\
		{e_SoundType_Reserved,                  CHIME_SOUND_Reserved,                   e_SoundFreq_0HZ,                        255,      0,        0,        0,        (SOUND_BREAK_BREAK | SOUND_BREAK_BREAKIMM)                                                                    },\
	};
;
#endif







/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/08/10     Original Version
**
**********************************************************************************************************/
#endif
/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/

