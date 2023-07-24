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
**  Name:               SWC_Chime_Process.h
**
**  Description:        SWC chime queue message set and get interface
**
**  Organization:       
**
**********************************************************************************************************/

/**********************************************************************************************************
* Start Of File                                                                                           *
**********************************************************************************************************/
#ifndef SWC_CHIME_PROCESS_H
#define SWC_CHIME_PROCESS_H

/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"
#include "SWC_WN_Config.h"

/**********************************************************************************************************
* Internel Function Include                                                                               *
**********************************************************************************************************/
#include "SWC_Chime_Adapt.h"
#include "SWC_Chime_App.h"

/**********************************************************************************************************
* Start of code                                                                                           *
**********************************************************************************************************/
/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
#define CHIME_SIGNAL_CAN				(0x01)
#define CHIME_SIGNAL_CANFD				(0x00)
#define CHIME_BUFFER_BIT_TYPE			(8)

#define CHIME_WARNING_MAX_ID			WN_enFuelPrepare_Sound
#define CHIME_WARNING_ADAS_BEGIN		(999)
#define CHIME_WARNING_DMS_NUMBER		(5)


#define CHIME_PROCESS_FUN_NULL			((void *)0u)

#define CHIME_FUN_RUN_POWER_ON			0x0001
#define CHIME_FUN_RUN_POWER_OFF			0x0002
#define CHIME_FUN_RUN_POWER_SLEEP		0x0008
#define CHIME_FUN_RUN_POWER_PRESLEEP	0x0010
#define CHIME_FUN_RUN_POWER_WAITTING	0x0020
#define CHIME_FUN_RUN_POWER_ABNORMAL	0x0004

#define CHIME_80KM_OVERSPEED_TIMER		(120000)

#define CHIME_RSDS_POSITION_NULL		(0x0000)
#define CHIME_RSDS_POSITION_ALL			(0xFFFF)
#define CHIME_RSDS_POSITION_VFL			(0x0001)
#define CHIME_RSDS_POSITION_VFR			(0x0002)
#define CHIME_RSDS_POSITION_VRL			(0x0004)
#define CHIME_RSDS_POSITION_VRR			(0x0008)
#define CHIME_RSDS_POSITION_SWL			(0x0010)
#define CHIME_RSDS_POSITION_SWR			(0x0020)
#define CHIME_RSDS_POSITION_CENTER		(0x0040u)
#define CHIME_RSDS_POSITION_DRR			(0x0080)
#define CHIME_RSDS_POSITION_DRL			(0x0100)
//reserved
#define CHIME_RSDS_POSITION_DRF			(0x0200)
#define CHIME_RSDS_POSITION_DRB			(0x0400)

#define CHIME_SOUND_REQUEST_BIT00		(0x0001)
#define CHIME_SOUND_REQUEST_BIT01		(0x0002)
#define CHIME_SOUND_REQUEST_BIT02		(0x0004)
#define CHIME_SOUND_REQUEST_BIT03		(0x0008)
#define CHIME_SOUND_REQUEST_BIT04		(0x0010)
#define CHIME_SOUND_REQUEST_BIT05		(0x0020)
#define CHIME_SOUND_REQUEST_BIT06		(0x0040)
#define CHIME_SOUND_REQUEST_BIT07		(0x0080)
#define CHIME_SOUND_REQUEST_BIT08		(0x0100)
#define CHIME_SOUND_REQUEST_BIT09		(0x0200)
#define CHIME_SOUND_REQUEST_BIT10		(0x0400)
#define CHIME_SOUND_REQUEST_BIT11		(0x0800)
#define CHIME_SOUND_REQUEST_BIT12		(0x1000)
#define CHIME_SOUND_REQUEST_BIT13		(0x2000)
#define CHIME_SOUND_REQUEST_BIT14		(0x4000)
#define CHIME_SOUND_REQUEST_FORKEEP		(0x8000)

#define CHIME_WARNING_SOUND_REQ			(0x01u)
#define CHIME_WARNING_SOUND_CEL			(0x02u)

#define CHIME_RTE_E_ComEx_E_OK				(0x08U)

//#define CHIME_CAN_STATUS(sts)			(((sts & RTE_E_NEVER_RECEIVED) != RTE_E_NEVER_RECEIVED) && ((sts & RTE_E_MAX_AGE_EXCEEDED) != RTE_E_MAX_AGE_EXCEEDED)&& ((sts & RTE_E_TIMEOUT) != RTE_E_TIMEOUT) && ((sts & RTE_E_UNCONNECTED) != RTE_E_UNCONNECTED))
#define CHIME_CAN_STATUS(sts)			((RTE_E_OK == sts) || (CHIME_RTE_E_ComEx_E_OK == sts))

typedef enum
{
	e_SoundBuffer_IdleMode = 0,
//	e_SoundType_RadarRFail3Times,                                                   后倒车雷达故障-3次
	e_SoundType_RadarRFail3Times_PasCase1_1,
	e_SoundType_RadarRFail3Times_PasCase1_2,
	e_SoundType_RadarRFail3Times_PasCase3_1,
	e_SoundType_RadarRFail3Times_PasCase3_2,
	e_SoundType_RadarRFail3Times_FDPasCase1_1,
	e_SoundType_RadarRFail3Times_FDPasCase1_2,
	e_SoundType_RadarRFail3Times_FDPasCase3_1,
	e_SoundType_RadarRFail3Times_FDPasCase3_2,

//	e_SoundType_RadarFFail3Times,                                                   前车雷达故障-3次
	e_SoundType_RadarFFail3Times_PasCase2_1,
	e_SoundType_RadarFFail3Times_PasCase2_2,
	e_SoundType_RadarFFail3Times_PasCase3_1,
	e_SoundType_RadarFFail3Times_PasCase3_2,
	e_SoundType_RadarFFail3Times_FDPasCase2_1,
	e_SoundType_RadarFFail3Times_FDPasCase2_2,
	e_SoundType_RadarFFail3Times_FDPasCase3_1,
	e_SoundType_RadarFFail3Times_FDPasCase3_2,

//	e_SoundType_RadarSDWFail3Times,                                                 SDW雷达故障-3次
	e_SoundType_RadarSDWFail3Times_PasCase4_1,
	e_SoundType_RadarSDWFail3Times_PasCase4_2,
	e_SoundType_RadarSDWFail3Times_PasCase4_3,
	e_SoundType_RadarSDWFail3Times_PasCase4_4,
	e_SoundType_RadarSDWFail3Times_PasCase4_5,

//	e_SoundType_APAOnce,                                                            APA声音提示-单次
	e_SoundType_APAOnce_PasCase5_1,
	e_SoundType_APAOnce_PasCase5_2,
	e_SoundType_APAOnce_PasCase5_3,
	e_SoundType_APAOnce_PasCase5_4,
//	e_SoundType_RadarRLongRe,                                                       后倒车雷达Long-重复
	e_SoundType_RadarRLongRe_PasCase1_1,
	e_SoundType_RadarRLongRe_PasCase3_1,
	e_SoundType_RadarRLongRe_FDPasCase1_1,
	e_SoundType_RadarRLongRe_FDPasCase3_1,
//	e_SoundType_RadarFLongRe,                                                       前车雷达Long-重复
	e_SoundType_RadarFLongRe_PasCase2_1,
	e_SoundType_RadarFLongRe_PasCase3_1,
	e_SoundType_RadarFLongRe_FDPasCase2_1,
	e_SoundType_RadarFLongRe_FDPasCase3_1,
//	e_SoundType_RadarSDWLongRe,                                                     SDW雷达Long-重复
	e_SoundType_RadarSDWLongRe_PasCase4_1,
//	e_SoundType_RadarDWDLongRe,                                                     涉水深度DWD Long-重复
	e_SoundType_RadarDWDLongRe_1,
//	e_SoundType_RadarRSDS4Hz,                                                       RSDS侧后辅助系统声音-4HZ_重复
	e_SoundType_RadarRSDS4Hz_RSDS_1,
	e_SoundType_RadarRSDS4Hz_RSDS_2,
	e_SoundType_RadarRSDS4Hz_RSDS_3,
	e_SoundType_RadarRSDS4Hz_RSDS_4,
	e_SoundType_RadarRSDS4Hz_RSDS_5,
	e_SoundType_RadarRSDS4Hz_RSDS_6,
	e_SoundType_RadarRSDS4Hz_RSDS_7,
	e_SoundType_RadarRSDS4Hz_RSDS_8,
//	e_SoundType_RadarRSDS3Hz,                                                       RSDS侧后辅助系统声音-3HZ_重复
	e_SoundType_RadarRSDS3Hz_RSDS_1,
	e_SoundType_RadarRSDS3Hz_RSDS_2,
	e_SoundType_RadarRSDS3Hz_RSDS_3,
	e_SoundType_RadarRSDS3Hz_RSDS_4,
	e_SoundType_RadarRSDS3Hz_RSDS_5,
	e_SoundType_RadarRSDS3Hz_RSDS_6,
//	e_SoundType_RadarF4HZ,                                                          前雷达4Hz-4HZ_重复
//	e_SoundType_RadarR3HZ,                                                          后倒车雷达3Hz-3HZ_重复
	e_SoundType_RadarR3HZ_PasCase1_1,
	e_SoundType_RadarR3HZ_PasCase3_1,
	e_SoundType_RadarR3HZ_FDPasCase1_1,
	e_SoundType_RadarR3HZ_FDPasCase3_1,
//	e_SoundType_RadarF3Hz,                                                          前车雷达3Hz-重复
	e_SoundType_RadarF3Hz_PasCase2_1,
	e_SoundType_RadarF3Hz_PasCase3_1,
	e_SoundType_RadarF3Hz_FDPasCase2_1,
	e_SoundType_RadarF3Hz_FDPasCase3_1,
//	e_SoundType_RadarSDW3Hz,                                                        SDW3Hz-重复
	e_SoundType_RadarSDW3Hz_PasCase4_1,
//	e_SoundType_RadarDWD3Hz,                                                        涉水深度DWD3Hz-重复
	e_SoundType_RadarDWD3Hz_1,
//	e_SoundType_RadarR2Hz,                                                          后雷达2Hz-重复
//	e_SoundType_LDW_LKAOnce,                                                        LDW&LKA声音提示-重复
	e_SoundType_LDW_LKAOnce_LDWLKA_1,
	e_SoundType_LDW_LKAOnce_LDWLKA_2,
	e_SoundType_LDW_LKAOnce_LDWLKA_3,
	e_SoundType_LDW_LKAOnce_LDWLKA_4,
	e_SoundType_LDW_LKAOnce_LDWLKA_5,
	e_SoundType_LDW_LKAOnce_LDWLKA_6,
	e_SoundType_LDW_LKAOnce_LDWLKA_7,
	e_SoundType_LDW_LKAOnce_LDWLKA_8,
	e_SoundType_LDW_LKAOnce_LDWLKA_9,
	e_SoundType_LDW_LKAOnce_LDWLKA_10,
	e_SoundType_LDW_LKAOnce_LDWLKA_11,
	e_SoundType_LDW_LKAOnce_LDWLKA_12,
	e_SoundType_LDW_LKAOnce_LDWLKA_13,
	e_SoundType_LDW_LKAOnce_LDWLKA_14,
	e_SoundType_LDW_LKAOnce_LDWLKA_15,
//	e_SoundType_RadarR1_5Hz,                                                        后倒车雷达1.5Hz-重复
	e_SoundType_RadarR1_5Hz_PasCase1_1,
	e_SoundType_RadarR1_5Hz_PasCase3_1,
	e_SoundType_RadarR1_5Hz_FDPasCase1_1,
	e_SoundType_RadarR1_5Hz_FDPasCase3_1,
//	e_SoundType_RadarF1_5Hz,                                                        前车雷达1.5Hz-重复
	e_SoundType_RadarF1_5Hz_PasCase2_1,
	e_SoundType_RadarF1_5Hz_PasCase3_1,
	e_SoundType_RadarF1_5Hz_FDPasCase2_1,
	e_SoundType_RadarF1_5Hz_FDPasCase3_1,
//	e_SoundType_RadarSDW1_5Hz,                                                      SDW1.5Hz-重复
	e_SoundType_RadarSDW1_5Hz_PasCase4_1,
//	e_SoundType_RadarDWD1_5Hz,                                                      涉水深度DWD 1.5Hz-重复
	e_SoundType_RadarDWD1_5Hz_1,
//	e_SoundType_RadarR1Hz,                                                          后雷达-1Hz-3次
//	e_SoundType_RadarF1Hz,                                                          前雷达-1Hz-3次
//	e_SoundType_LeaveCar4Hz,                                                        危险！请立即远离车辆！-4HZ_重复
	e_SoundType_LeaveCar4Hz_Wrn_1,
//	e_SoundType_StopCar4Hz,                                                         危险！请安全停车并立即远离车辆-4HZ_重复
	e_SoundType_StopCar4Hz_Wrn_1,
//	e_SoundType_SteeringActRe,                                                      紧急转向避让辅助激活-重复
	e_SoundType_SteeringActRe_Wrn_1,
//	e_SoundType_AutoSteeringActRe,                                                  自动紧急转向避让辅助激活-重复
	e_SoundType_AutoSteeringActRe_Wrn_1,
//	e_SoundType_AutoBrakePersonRe,                                                  自动紧急制动启动+行人图片-重复
	e_SoundType_AutoBrakePersonRe_Wrn_1,
//	e_SoundType_AutoBrakeCarRe,                                                     自动紧急制动启动+车辆图片-重复
	e_SoundType_AutoBrakeCarRe_Wrn_1,
//	e_SoundType_AuxiliaryBrakeRe,                                                   交叉路口辅助制动启动+车辆图片-重复
	e_SoundType_AuxiliaryBrakeRe_Wrn_1,
//	e_SoundType_CrossSideBrakeRe,                                                   前横穿侧向制动启动+车辆图片-重复
	e_SoundType_CrossSideBrakeRe_Wrn_1,
//	e_SoundType_RSideBrakeRe,                                                       倒车侧向制动启动+车辆图片-重复
	e_SoundType_RSideBrakeRe_Wrn_1,
//	e_SoundType_TakeBrakeAcc4Hz,                                                    请踩刹车（自适应巡航）-4HZ_重复
	e_SoundType_TakeBrakeAcc4Hz_Wrn_1,
//	e_SoundType_TakeBrakeFCWRe,                                                     请踩刹车（FCW）-重复
	e_SoundType_TakeBrakeFCWRe_Wrn_1,
//	e_SoundType_TakeBrakeFCrossRe,                                                  请踩刹车（前横穿侧向警告）-重复
	e_SoundType_TakeBrakeFCrossRe_Wrn_1,
//	e_SoundType_TakeSteering4Hz,                                                    请手握方向盘-4HZ_重复
	e_SoundType_TakeSteering4Hz_Wrn_1,
	e_SoundType_TakeSteering4Hz_Wrn_2,
//	e_SoundType_TakeSteering2Hz,                                                    请手握方向盘-2HZ_重复
	e_SoundType_TakeSteering2Hz_Wrn_1,
//	e_SoundType_TakeSteering1Hz,                                                    请手握方向盘-1HZ_3次
	e_SoundType_TakeSteering1Hz_Wrn_1,
//	e_SoundType_KeepDistance,                                                       请保持安全距离-单次
	e_SoundType_KeepDistance_Wrn_1,
//	e_SoundType_TakeCar4Hz,                                                         请接管车辆-4HZ_重复
	e_SoundType_TakeCar4Hz_Wrn_1,
//	e_SoundType_TakeCar2Hz,                                                         请接管车辆-2HZ_重复
	e_SoundType_TakeCar2Hz_Wrn_1,
//	e_SoundType_TakeCar1Hz,                                                         请接管车辆-1HZ_3次
	e_SoundType_TakeCar1Hz_Wrn_1,
//	e_SoundType_AssistExit4Hz,                                                      车道辅助系统退出请接管车辆-4HZ_重复
	e_SoundType_AssistExit4Hz_Wrn_1,
//e_SoundType_SmartCruiseExit														智慧巡航已退出，紧急刹车辅助启动-重复
	e_SoundType_SmartCruiseExit_Wrn_1,
//	e_SoundType_KeepPoint4Hz,                                                       请保持注意力-4HZ_重复
	e_SoundType_KeepPoint4Hz_Wrn_1,
//	e_SoundType_KeepPoint2Hz,                                                       请保持注意力-2HZ_重复
	e_SoundType_KeepPoint2Hz_Wrn_1,
//	e_SoundType_KeepPointOnce,                                                      请保持注意力-单次
	e_SoundType_KeepPoint1Hz_Wrn_1,
//	e_SoundType_CheckP0_5Hz,                                                        请选择P挡-0.5HZ_60S
	e_SoundType_CheckP0_5Hz_Wrn_1,
//  e_SoundType_CarDistancce,                                                       请注意行车距离-重复
	e_SoundType_CarDistancce_Wrn_1,
//  e_SoundType_Pedestrian                                                          请注意避让行人-重复
	e_SoundType_Pedestrian_Wrn_1,
	e_SoundType_Pedestrian_Wrn_2,
	e_SoundType_Pedestrian_Wrn_3,
//  e_SoundType_FaceCar,                                                            注意对向来车-重复
	e_SoundType_FaceCar_Wrn_1,
//  e_SoundType_CrosswiseCar,                                                       注意横向来车-重复
	e_SoundType_CrosswiseCar_Wrn_1,
	e_SoundType_CrosswiseCar_Wrn_2,
	e_SoundType_CrosswiseCar_Wrn_3,
//  e_SoundType_FrontCarAEB,                                                        前方车辆紧急制动-重复
	e_SoundType_FrontCarAEB_Wrn_1,
//  e_SoundType_FrontCarUnContron,                                                  注意前方失控车辆-重复
	e_SoundType_FrontCarUnContron_Wrn_1,
//  e_SoundType_BackCarUnContron,                                                   注意后方失控车辆-重复
	e_SoundType_BackCarUnContron_Wrn_1,
//  e_SoundType_AroundCarUnContron,                                                 注意周围失控车辆-重复
	e_SoundType_AroundCarUnContron_Wrn_1,
//  e_SoundType_PlsTakeOver4Hz,                                                     请立即接管-4HZ_重复
	e_SoundType_PlsTakeOver4Hz_Wrn_1,
//  e_SoundType_PlsTakeOver2Hz                                                      请立即接管-2HZ_重复
	e_SoundType_PlsTakeOver2Hz_Wrn_1,	
//  e_SoundType_PlsTakeOver1Hz                                                      请立即接管-1hz_3次
	e_SoundType_PlsTakeOver1Hz_Wrn_1,
//  e_SoundType_CarAutoBrakePlsTake                                                 车辆正在自动刹停，请立即接管-重复
	e_SoundType_CarAutoBrakePlsTake_Wrn_1,	
//  e_SoundType_CarParkingPlsTake                                                   车辆正在靠边停车，请立即接管-重复
	e_SoundType_CarParkingPlsTake_Wrn_1,
//  e_SoundType_CarUrgeBrakePlsTake                                                 车辆正在紧急刹停，请立即接管-重复
	e_SoundType_CarUrgeBrakePlsTake_Wrn_1,	
//  e_SoundType_MoveRampFailPlsTake                                                  驶入匝道失败，请立即接管-重复
	e_SoundType_MoveRampFailPlsTake_Wrn_1,
//  e_SoundType_MoveMainFailPlsTake4Hz                                               汇入主路失败，请立即接管-4HZ_重复
	e_SoundType_MoveMainFailPlsTake4Hz_Wrn_1,
//  e_SoundType_MoveMainFailPlsTake2Hz                                               汇入主路失败，请立即接管-2HZ_重复
	e_SoundType_MoveMainFailPlsTake2Hz_Wrn_1,	
//  e_SoundType_MoveMainFailPlsTake1Hz                                               汇入主路失败，请立即接管-1HZ_3次
	e_SoundType_MoveMainFailPlsTake1Hz_Wrn_1,
//  e_SoundType_TurnFailPlsTake4Hz                                                   转弯失败，请立即接管-4HZ_重复
	e_SoundType_TurnFailPlsTake4Hz_Wrn_1,
//  e_SoundType_TurnFailPlsTake2Hz                                                   转弯失败，请立即接管-2HZ_重复
	e_SoundType_TurnFailPlsTake2Hz_Wrn_1,
//  e_SoundType_TurnFailPlsTake1Hz                                                   转弯失败，请立即接管-1HZ_3次
	e_SoundType_TurnFailPlsTake1Hz_Wrn_1,
//  e_SoundType_TollGateFailPlsTake4Hz                                               无法成功通过收费站，请立即接管-4HZ_重复
	e_SoundType_TollGateFailPlsTake4Hz_Wrn_1,
//  e_SoundType_TollGateFailPlsTake2Hz                                               无法成功通过收费站，请立即接管-2HZ_重复
	e_SoundType_TollGateFailPlsTake2Hz_Wrn_1,
//  e_SoundType_TollGateFailPlsTake1Hz                                               无法成功通过收费站，请立即接管-1HZ_3次
	e_SoundType_TollGateFailPlsTake1Hz_Wrn_1,	
//  e_SoundType_RoundaboutFailPlsTake4Hz                                             无法成功通过环岛，请立即接管-4HZ_重复
	e_SoundType_RoundaboutFailPlsTake4Hz_Wrn_1,
//  e_SoundType_RoundaboutFailPlsTake2Hz                                             无法成功通过环岛，请立即接管-2HZ_重复
	e_SoundType_RoundaboutFailPlsTake2Hz_Wrn_1,
//  e_SoundType_RoundaboutFailPlsTake1Hz                                             无法成功通过环岛，请立即接管-1HZ_3次
	e_SoundType_RoundaboutFailPlsTake1Hz_Wrn_1,		
//  e_SoundType_MoveRampFailHandWheel_2Hz                                          	驶入匝道失败，请控制方向盘-2Hz_重复
	e_SoundType_MoveRampFailHandWheel_2Hz_Wrn_1,
//  e_SoundType_MoveRampFailHandWheel,												驶入匝道失败，请控制方向盘-1Hz_3次
	e_SoundType_MoveRampFailHandWheel_Wrn_1,
//	e_SoundType_MoveMainFailHandWheel,												汇入主路失败，请控制方向盘-1Hz_3次
	e_SoundType_MoveMainFailHandWheel_Wrn_1,
//  e_SoundType_TurnFailPlsHandWheel,												转弯失败，请控制方向盘-1Hz_3次
	e_SoundType_TurnFailPlsHandWheel_Wrn_1,
//  e_SoundType_TollGateFailPlsHandWheel,											无法成功通过收费站，请控制方向盘-1Hz_3次
	e_SoundType_TollGateFailPlsHandWheel_Wrn_1,
//  e_SoundType_RoundaboutFailPlsHandWheel											无法成功通过环岛，请控制方向盘-1Hz_3次
	e_SoundType_RoundaboutFailPlsHandWheel_Wrn_1,
//	e_SoundType_Tpms1Hz,                                                            胎压报警声音提示-1HZ_3次
	e_SoundType_Tpms1Hz_TPMS_1,
//	e_SoundType_HybridFail1Hz,                                                      混合动力系统故障报警音-1HZ_3次
	e_SoundType_HybridFail1Hz_HCU_1,
	e_SoundType_HybridFail1Hz_HCU_2,
//	e_SoundType_Seatbelt0_5Hz,                                                      安全带未系-0.5HZ_重复
	e_SoundType_Seatbelt0_5Hz_SEATBELT_1,
//  e_SoundType_battery_low0_5Hz,													蓄电池电量过低，系统3分钟后关闭电源，请启动车辆-0.5HZ_重复
	e_SoundType_battery_low0_5Hz_1_Wrn_1,
//	e_SoundType_DoorOpen1_5Hz,                                                      车门打开声音提示-1.5HZ_60S
	e_SoundType_DoorOpen1_5Hz_DOOR_1,
	e_SoundType_DoorOpen1_5Hz_DOOR_2,
	e_SoundType_DoorOpen1_5Hz_DOOR_3,
	e_SoundType_DoorOpen1_5Hz_DOOR_4,
	e_SoundType_DoorOpen1_5Hz_DOOR_5,
	e_SoundType_DoorOpen1_5Hz_DOOR_6,
//	e_SoundType_DoorOpen1_Once,														后车门打开声音提示-单次
	e_SoundType_DoorOpen1_Once_DOOR_1,	
//	e_SoundType_DynamicBrake0_5Hz,                                                  动态制动报警提示-0.5HZ_重复
	e_SoundType_DynamicBrake0_5Hz_1,
	e_SoundType_DynamicBrake0_5Hz_2,
//	e_SoundType_HandBrake0_5Hz,                                                     手刹未松报警提示-0.5HZ_重复
//	e_SoundType_PositionTickOnce,                                                   双闪提示音Click-单次
	e_SoundType_PositionTickOnce_1,
//	e_SoundType_PositionTockOnce,                                                   双闪提示音Clack-单次
	e_SoundType_PositionTockOnce_1,
//	e_SoundType_TurnLeftTickOnce,                                                   左转向声音提示Click-单次
	e_SoundType_TurnLeftTickOnce_1,
//	e_SoundType_TurnLeftTockOnce,                                                   左转向声音提示Clalk-单次
	e_SoundType_TurnLeftTockOnce_1,
//	e_SoundType_TurnRightTickOnce,                                                  右转向声音提示Click-单次
	e_SoundType_TurnRightTickOnce_1,
//	e_SoundType_TurnRightTockOnce,                                                  右转向声音提示Clalk-单次
	e_SoundType_TurnRightTockOnce_1,
//	e_SoundType_OverSpeed1Hz,                                                       120km/h超速报警声音提示-1HZ_10S
	e_SoundType_OverSpeed1Hz_SPEED_1,
//	e_SoundType_India120Speed1Hz,                                                   印度超速报警（二级：120km/h）-1HZ_重复
	e_SoundType_India120Speed1Hz_SPEED_1,
//	e_SoundType_India80Speed1Hz,                                                    印度超速报警（一级：80km/h）-1HZ_10S
	e_SoundType_India80Speed1Hz_SPEED_1,
//	e_SoundType_OverSpeedAlarm1Hz,                                                  超速提醒报警声音提示-1HZ_3S
	e_SoundType_OverSpeedAlarm1Hz_Wrn_1,
//	e_SoundType_TsrOnce,                                                            限速报警标志提示声音-单次
	e_SoundType_TsrOnce_TSR_1,
//	e_SoundType_FLockOnce,                                                          前桥差速锁声音报警-单次
	e_SoundType_FLockOnce_FLOCK_1,
	e_SoundType_FLockOnce_FLOCK_2,
//	e_SoundType_RLockOnce,                                                          后桥差速锁声音报警-单次
	e_SoundType_RLockOnce_RLOCK_1,
	e_SoundType_RLockOnce_RLOCK_2,
//	e_SoundType_CLockOnce,															中央差速锁声音报警-单次
	e_SoundType_CLockOnce_CLOCK_1,
	e_SoundType_CLockOnce_CLOCK_2,
//	e_SoundType_LightOn0_5Hz,                                                       灯光未关-0.5HZ_60S
	e_SoundType_LightOn0_5Hz_Wrn_1,
//	e_SoundType_TunnelTakeCarOnce,                                                  前方即将穿过隧道,请及时接管车辆-单次
	e_SoundType_TunnelTakeCarOnce_Wrn_1,
//	e_SoundType_RoadTakeCarOnce,                                                    前方存在分叉路口，请及时接管车辆-单次
	e_SoundType_RoadTakeCarOnce_Wrn_1,
//	e_SoundType_ModeFailOnce,                                                       模式切换失败，请熄火重试-单次
	e_SoundType_ModeFailOnce_Wrn_1,
//	e_SoundType_HcExitTakeDirOnce,                                                  横向控制已退出，请控制方向-单次
	e_SoundType_HcExitTakeDirOnce_Wrn_1,
//	e_SoundType_NOHExitPlsTake,                                                  	前方XX米，即将退出自动导航辅助，请准备接管
	e_SoundType_NOHExitPlsTake_Wrn_1,
//	e_SoundType_RCarSpeedHigh1Hz,                                                   后方车辆车速过高-1HZ_3S
	e_SoundType_RCarSpeedHigh1Hz_Wrn_1,
//	e_SoundType_4LModeOnce,                                                         4L模式请减速慢行-单次
	e_SoundType_4LModeOnce_Wrn_1,
//	e_SoundType_PowerOnOnce,                                                        已上电可挂挡行驶-单次
	e_SoundType_PowerOnOnce_Wrn_1,
//	e_SoundType_PleaseRestOnce,                                                     请注意休息-单次
	e_SoundType_PleaseRestOnce_Wrn_1,
//	e_SoundType_PleaseRest1Hz,                                                      请注意休息-1HZ_3S
	e_SoundType_PleaseRest1Hz_Wrn_1,
//	e_SoundType_CruiseActOnce,                                                      巡航类功能激活-单次
	e_SoundType_CruiseActOnce_ACC_1,
	e_SoundType_CruiseActOnce_ACC_2,
	e_SoundType_CruiseActOnce_ACC_3,
//	e_SoundType_LckActOnce,                                                         LCK功能激活-单次
	e_SoundType_LckActOnce_Wrn_1,
//	e_SoundType_CruiseDownOnce,                                                     巡航类功能降级-单次
	e_SoundType_CruiseDownOnce_ACC_1,
	e_SoundType_CruiseDownOnce_ACC_2,
//	e_SoundType_CruiseStartOnce,                                                    巡航类功能启动-单次
	e_SoundType_CruiseStartOnce_ACC_1,
	e_SoundType_CruiseStartOnce_ACC_2,
	e_SoundType_CruiseStartOnce_ACC_3,
//	e_SoundType_LeftSmartdodgeOnce,                                                 左侧智慧躲闪-单次
	e_SoundType_LeftSmartdodgeOnce_C1,
//	e_SoundType_RightSmartdodgeOnce,                                                右侧智慧躲闪-单次
	e_SoundType_RightSmartdodgeOnce_C1,
//	e_SoundType_VehicleDevRepeate,													车辆偏离请控制方向盘-持续
	e_SoundType_VehicleDevRepeate_Wrn_1,
//  e_SoundType_UrgeTurnPlsHoldWheel,												前方急转弯，请手扶方向盘
	e_SoundType_UrgeTurnPlsHoldWheel_Wrn_1,	
//	e_SoundType_SafeDrivRepeat, 													车道辅助系统持续控制中请安全驾驶-持续
	e_SoundType_SafeDrivRepeat_Wrn_1,
	e_SoundType_SafeDrivRepeat_Wrn_2,
//	e_SoundType_LcdAlarmTen,                                                      	通用报警-10次
	e_SoundType_LcdAlarmTen_Wrn_1,
//	e_SoundType_12VPowerSysFail,													12V电源系统故障，舒适功能关闭，请联系4S店维修！通用报警-10次													
	e_SoundType_12VPowerSysFailWrn_1,
//	e_SoundType_LcdAlarmThree,                                                      通用报警-3次
	e_SoundType_LcdAlarmThree_Wrn_1,
//	e_SoundType_LcdAlarmOnce,                                                       通用报警-单次
	e_SoundType_LcdAlarmOnce_Wrn_1,
	e_SoundType_LcdAlarmOnce_Wrn_2,
	e_SoundType_AdasAlarmOnce_Wrn_1,
//	e_SoundType_PowerBatWarmOnce,                                                   动力电池预热中-单次
	e_SoundType_PowerBatWarmOnce_Wrn_1,
//	e_SoundType_ChargeFaultOnce,													充电故障声音提示(PHEV)
	e_SoundType_ChargeFaultOnce_1,
//	e_SoundType_AccCruiseFailOnce,                                                  自适应巡航无法激活-单次
	e_SoundType_AccCruiseFailOnce_Wrn_1,
//	e_SoundType_AccCruiseQuitOnce,                                                  自适应巡航功能取消-单次
	e_SoundType_AccCruiseQuitOnce_Wrn_1,
//	e_SoundType_SmartCruiseFailOnce,                                                智能巡航辅助无法激活-单次
	e_SoundType_SmartCruiseFailOnce_Wrn_1,
//	e_SoundType_SmartCruisQuitOnce,                                                 智能巡航辅助功能取消-单次
	e_SoundType_SmartCruisQuitOnce_Wrn_1,
//	e_SoundType_FCOKOnce,                                                           前车已起步-单次
	e_SoundType_FCOKOnce_Wrn_1,
//	e_SoundType_FCOKAttRoadEnvOnce,                                                 前车已起步，请注意前方道路环境-单次
	e_SoundType_FCOKAttRoadEnvOnce_Wrn_1,
//	e_SoundType_FCOKKeepAtOnce,                                                     前车已起步，请保持注意力-单次
	e_SoundType_FCOKKeepAtOnce_Wrn_1,
//	e_SoundType_FCOKTakeCarOnce,                                                    前车已起步，请接管车辆-单次
	e_SoundType_FCOKTakeCarOnce_Wrn_1,
//	e_SoundType_AccCruiseOkkeepAtOnce,                                              自适应巡航已激活，请保持注意力-单次
	e_SoundType_AccCruiseOkkeepAtOnce_Wrn_1,
//	e_SoundType_SmartCruiseOkhwOnce,                                                智慧巡航已激活，请保持注意力并手握方向盘-单次
	e_SoundType_SmartCruiseOkhwOnce_Wrn_1,
// 	e_SoundType_NOHIsActivated														自动导航辅助已启动
	e_SoundType_NOHIsActivated_Wrn_1,	
//	e_SoundType_ConditionNotMet														环境条件不满足，请稍后尝试
	e_SoundType_ConditionNotMet_Wrn_1,
//	e_SoundType_StayFocusedTryAgain,												请保持专注驾驶，再次开启尝试
	e_SoundType_StayFocusedTryAgain_Wrn_1,
//	e_SoundType_HandsOnthewheelTryAgain,											请保持手握方向盘，再次尝试开启
	e_SoundType_HandsOnthewheelTryAgain_Wrn_1,
//	e_SoundType_FastenSeatBelt,														请系紧安全带
	e_SoundType_FastenSeatBelt_Wrn_1,
//	e_SoundType_CloseTheDoor,														请关闭车门
	e_SoundType_CloseTheDoor_Wrn_1,
//	e_SoundType_FastenPassengerSeat,												请副驾驶系紧安全带
	e_SoundType_FastenPassengerSeat_Wrn_1,
//	e_SoundType_CCOOnce,                                                            CCO(越野巡航)故障指示-单次
	e_SoundType_CCOOnce_COO_1,
//	e_SoundType_TABFailOnce,                                                        TAB（转向辅助）失效指示-单次
	e_SoundType_TABFailOnce_TAB_1,
//	e_SoundType_HighVol0_5Hz,                                                       上高压后司机离开车门-0.5HZ_12S
	e_SoundType_HighVol0_5Hz_EV_1,
	e_SoundType_HighVol0_5Hz_PHEV_2,
	e_SoundType_HighVol0_5Hz_RE300_3,
/*	Number of chime */
	e_SoundBuffer_NumberOfChimes,
}e_SoundBufferList_t;

typedef enum
{
	e_WarnReq_LeaveCar4Hz = 0,
	e_WarnReq_StopCar4Hz,
	e_WarnReq_SteeringActRe,
	e_WarnReq_AutoSteeringActRe,
	e_WarnReq_AutoBrakePersonRe,
	e_WarnReq_AutoBrakeCarRe,
	e_WarnReq_AuxiliaryBrakeRe,
	e_WarnReq_CrossSideBrakeRe,
	e_WarnReq_RSideBrakeRe,
	e_WarnReq_TakeBrakeAcc4Hz,
	e_WarnReq_TakeBrakeFCWRe,
	e_WarnReq_TakeBrakeFCrossRe,
	e_WarnReq_TakeSteering2Hz,
	e_WarnReq_TakeSteering3Hz,
	e_WarnReq_TakeSteering4Hz,
	e_WarnReq_TakeCar2Hz,
	e_WarnReq_TakeCar4Hz,
	e_WarnReq_AssistExit4Hz,
	e_WarnReq_KeepPoint2Hz,
	e_WarnReq_KeepPoint4Hz,
	e_WarnReq_CheckP0_5Hz,

	e_WarnReq_ChimeDoorOpenCheck,
	e_WarnReq_LightOn0_5Hz,
	e_WarnReq_ChimeOverspeedIndia80Check,
	e_WarnReq_ChimeOverspeedIndia120Check,
	e_WarnReq_VehicleDevRepeate,
	e_WarnReq_UrgeTurnPlsHoldWheel,
	e_WarnReq_MoveRampFailHandWheel_2Hz,
	e_WarnReq_MoveRampFailHandWheel,
	e_WarnReq_MoveMainFailHandWheel,
	e_WarnReq_TurnFailPlsHandWheel,
	e_WarnReq_TollGateFailPlsHandWheel,
	e_WarnReq_RoundaboutFailPlsHandWheel,
	e_WarnReq_LcdAlarmTenTimes,
	e_WarnReq_ChimeRainDoorOverspeedCheck,
	e_WarnReq_ChimeCarDistance,
	e_WarnReq_ChimePeopleRight,
	e_WarnReq_ChimePeopleMid,
	e_WarnReq_ChimePeopleLeft,
	e_WarnReq_ChimeFaceCar,
	e_WarnReq_ChimeSideCarTwoSide,
	e_WarnReq_ChimeSideCarRight,
	e_WarnReq_ChimeSideCarLeft,
	e_WarnReq_ChimeFrontCarAEB,
	e_WarnReq_ChimeFrontCarUnContron,
	e_WarnReq_ChimeBackCarUnContron,
	e_WarnReq_ChimeAroundCarUnContron,
	e_WarnReq_ChimePlsTakeOver4Hz,
	e_WarnReq_ChimePlsTakeOver2Hz,
	e_WarnReq_ChimePlsTakeOver1Hz,
	e_WarnReq_ChimeCarAutoBrakePlsTake,
	e_WarnReq_ChimeCarParkingPlsTake,
	e_WarnReq_ChimeCarUrgeBrakePlsTake,
	e_WarnReq_ChimeMoveRampFailPlsTake,
	e_WarnReq_ChimeMoveMainFailPlsTake4Hz,
	e_WarnReq_ChimeMoveMainFailPlsTake2Hz,
	e_WarnReq_ChimeMoveMainFailPlsTake1Hz,
	e_WarnReq_ChimeTurnFailPlsTake4Hz,
	e_WarnReq_ChimeTurnFailPlsTake2Hz,
	e_WarnReq_ChimeTurnFailPlsTake1Hz,
	e_WarnReq_ChimeTollGateFailPlsTake4Hz,
	e_WarnReq_ChimeTollGateFailPlsTake2Hz,
	e_WarnReq_ChimeTollGateFailPlsTake1Hz,
	e_WarnReq_ChimeRoundaboutFailPlsTake4Hz,
	e_WarnReq_ChimeRoundaboutFailPlsTake2Hz,
	e_WarnReq_ChimeRoundaboutFailPlsTake1Hz,
	e_WarnReq_ChimePowerOffAfterThreeMinute,
	e_WarnReq_ChimeStatBattLowComfortOff,
	e_WarnReq_ChimeSmartCruiseExit,

	e_WarnReq_ChimeOverspeedCheck,
	e_WarnReq_RCarSpeedHigh1Hz,
	e_WarnReq_PleaseRest1Hz,
	e_WarnReq_TakeSteering1Hz,
	e_WarnReq_TakeCar1Hz,
	e_WarnReq_KeepPoint1Hz,
	e_WarnReq_KeepDistance,
	e_WarnReq_LcdAlarmThree,
	e_WarnReq_LcdAlarmOnce,
	e_WarnReq_TunnelTakeCarOnce,
	e_WarnReq_RoadTakeCarOnce,
	e_WarnReq_ModeFailOnce,
	e_WarnReq_HcExitTakeDirOnce,
	e_WarnReq_ChimeNOHExitPlsTake,
	e_WarnReq_PowerOnOnce,
	e_WarnReq_4LModeOnce,
	e_WarnReq_PleaseRestOnce,
	e_WarnReq_AdasStart,
	e_WarnReq_AccCruiseFailOnce = e_WarnReq_AdasStart,
	e_WarnReq_AccCruiseQuitOnce,
	e_WarnReq_SmartCruiseFailOnce,
	e_WarnReq_SmartCruisQuitOnce,
	e_WarnReq_AccCruiseOkkeepAtOnce,
	e_WarnReq_SmartCruiseOkhwOnce,
	e_WarnReq_FCOKOnce,
	e_WarnReq_FCOKAttRoadEnvOnce,
	e_WarnReq_FCOKKeepAtOnce,
	e_WarnReq_FCOKTakeCarOnce,
	e_WarnReq_NOHIsActivated,
	e_WarnReq_EnvNotSup,
	e_WarnReq_KeepFocusTryAgain,
	e_WarnReq_PlsHandsWheelTryAgain,
	e_WarnReq_Plsfastenseatbelt,
	e_WarnReq_PlsShutTheDoor,
	e_WarnReq_PlsfastenPassSeatbelt,
	e_WarnReq_MaxNumber,

}e_WarningRequestList_t;

typedef enum
{
	e_ChimeTable_ReqSound = 0,
	e_ChimeTable_ActSound,
	e_ChimeTable_All,
}e_ChimeReqActTable_t;

typedef struct
{
	void (*Process)(void);
	void (*Cancel)(void);
	uint16 BitSts_u16;
	uint16 OnDelayTime;
}s_ChimeProcessFunParameter_t;


typedef struct
{
	uint8 TimerSts_u8;
	uint8 WrnSts_u8;
	uint32 TimerCnt_u32;
}s_ChimeProcessTimer_t;

typedef struct
{
	e_WarningRequestList_t ReqListNum;
	WN_CFG_enWarningID WarningId_u16;
	void (*Process)(uint8 flag,uint8 enable,uint16 bit);
}s_ChimeWarningReqTbl_t;

typedef struct
{
	uint16 AdasWrnId_u16;
	void (*Process)(uint8 flag,uint8 enable,uint16 bit);
}s_ChimeAdasWrnReqTbl_t;

typedef struct
{
	e_WarningRequestList_t WarnReqNum;
}s_ChimeWrnProcess_t;
typedef struct
{
	uint8 PasLastConfig;

	uint8 TpmsLastSts_u8;
	uint8 HybridPowerLastSts_u8;
	uint8 SeatbeltLastSts_u8;
	uint8 TickLastSts_u8;
	uint8 TockLastSts_u8;
	uint8 OverspeedLastSts_u8;
	uint8 CCOLEDLastSts_u8;
	uint8 TabLEDLastSts_u8;
	uint8 READYLEDLastSts_u8;
	uint8 PowerFlg_u8;
	uint8 FELDLastSts_u8;
	uint8 RELDLastSts_u8;

	uint8 OverspeedLEDSts_u8;
	uint8 TSRSpdLimLValue_u8;
	uint8 LEDTSR120KMHData_u8;
	
	uint8 DoorOpenShiedFlag_u8;
	uint8 SpeedZeroFlag_u8;
	uint16 DoorOpenIndex_u16;
	uint16 DoorReqIndex_u16;
	uint16 DoorShiedIndex_u16;
	uint16 DoorOpenTimerIndex_u16;

	uint8 GearFirstFlag_u8;
	uint8 Gear7DCTFirstSigFlag_u8;
	uint8 Gear9DCTFirstSigFlag_u8;
	uint8 Gear8ATFirstSigFlag_u8;
	uint8 GearPHEVFirstSigFlag_u8;
	uint8 GearEVFirstSigFlag_u8;

	uint8 ACC_CruiseStart_TJAFlag_u8;
	uint8 ACC_CruiseStart_ACCFlag_u8;
	uint8 ACC_CruiseStart_HWAFlag_u8;
	uint8 ACC_CruiseAct_TJAFlag_u8;
	uint8 ACC_CruiseAct_ACCFlag_u8;
	uint8 ACC_CruiseAct_HWAFlag_u8;

	uint8 ACC_CruiseLast_HWA_u8;
	uint8 ACC_CruiseLast_TJA_u8;
	
	uint8 ACC_CruiseDown_HWA_u8;
	uint8 ACC_CruiseDown_TJA_u8;
	uint8 TT_SelfCheck_u8;
	uint8 TT_CheckTimerOutCounter_u8;

	uint16 LastRSDS3HZField_u16;
	uint16 LastRSDS4HZField_u16;
	uint16 LastLDW_LKAField_u16;
	s_ChimeProcessTimer_t Overspeed80kmT_s;
	s_ChimeOstmData_t CruiseStartT_s;
	s_ChimeOstmData_t CruiseActiveT_s;
	s_ChimeOstmData_t CruiseDownT_s;
	s_ChimeOstmData_t DoorOpenTab_s[6];
	
	uint8 CELDLastSts_u8;
	
}s_ChimeGlobalData_t;

typedef struct
{
	uint8 ReqWarning[e_WarnReq_MaxNumber];
	uint16 CurDisplayWrn_u16;
	uint16 CurDisplayAdas_u16;
}s_ChimeGlobalIPCWarnData_t;

typedef struct
{
	uint16 Field;
	e_SoundTypeList_t SoundId;
	uint16 SoundBit;
}s_CHimeReqBit2Chime_t;

typedef IPC_S2M_ClusterAppClusterSocTtToChime_t ChimeTTFlashCallback_t;



/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h" 
/**********************************************************************************************************
*Function   : Chime_KSWarmInit                                                                            *
*                                                                                                         *
*Description: Chime warm init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_ProcessColdInit(void);

/**********************************************************************************************************
*Function   : Chime_KSWarmInit                                                                            *
*                                                                                                         *
*Description: Chime warm init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_ProcessWarmInit(void);

/**********************************************************************************************************
*Function   : Chime_KSWarmInit                                                                            *
*                                                                                                         *
*Description: Chime warm init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void SWC_ChimeMainProcess(void);

/**********************************************************************************************************
*Function   : Chime_KSWarmInit                                                                            *
*                                                                                                         *
*Description: Chime warm init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void CHIME_vCancelAllSound(void);

/**********************************************************************************************************
*Function   : SWC_ChimeDoorOpenTimerStart                                                                 *
*                                                                                                         *
*Description: Chime door open sound request timer start                                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-21                                                                                  *
**********************************************************************************************************/
void SWC_ChimeDoorOpenTimerStart(uint8 flag,uint16 bit,uint32 time);

/**********************************************************************************************************
*Function   : SWC_ChimeOverspeedIndia80TimerStart                                                         *
*                                                                                                         *
*Description: Chime overspeed sound timer start,base on sound play over                                   *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void SWC_ChimeOverspeedIndia80Timer(uint8 sts);
/**********************************************************************************************************
*Function   : SWC_ChimeOverspeedIndia80TimerCheck                                                         *
*                                                                                                         *
*Description: Chime overspeed timer process                                                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void SWC_ChimeProcessTimerCheck(uint32 passtime);

/**********************************************************************************************************
*Function   : SWC_ChimeACC_TJA_ICA_StartTimer                                                             *
*                                                                                                         *
*Description: Chime Cruise start sound timer start,base on sound play over                                *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void SWC_ChimeACC_TJA_ICA_StartTimer(uint8 sts);

/**********************************************************************************************************
*Function   : SWC_ChimeACC_TJA_ICA_ActiveTimer                                                            *
*                                                                                                         *
*Description: Chime Cruise Active sound timer start,base on sound play over                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void SWC_ChimeACC_TJA_ICA_ActiveTimer(uint8 sts);
/**********************************************************************************************************
*Function   : SWC_ChimeACC_TJA_ICA_DownTimer                                                              *
*                                                                                                         *
*Description: Chime Cruise Down sound timer start,base on sound play over                                 *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-09-10                                                                                  *
**********************************************************************************************************/
void SWC_ChimeACC_TJA_ICA_DownTimer(uint8 sts);

/**********************************************************************************************************
*Function   : Chime_Api_TTFlashCallback                                                                   *
*                                                                                                         *
*Description: Chime callback get TT flash data                                                            *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Xu                                                                                 *
*                                                                                                         *
*Date       : 2021-10-11                                                                                  *
**********************************************************************************************************/
void Chime_Api_TTFlashCallback(uint8 *data);
uint8 chime_api_TTFuc(void);

#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

#endif

/**********************************************************************************************************
**
**  Revision:      1.0  
**  
**  Author  :      Cao wenping
**
**  Date    :      2020/07/10     Original Version
**
**********************************************************************************************************/

/**********************************************************************************************************
* End Of File                                                                                             *
**********************************************************************************************************/
