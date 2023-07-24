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
**  Name:               SWC_IPC_data.c
**
**  Description:        The main switching logic of the chime module
**
**  Organization:       
**
**********************************************************************************************************/
#ifndef SWC_CHIME_APP_H
#define SWC_CHIME_APP_H

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
#include "SWC_Chime_Adapt.h"


/**********************************************************************************************************
* Parament                                                                                                *
**********************************************************************************************************/
/*Sound tab parament types**************************************************************/
typedef enum
{
/*0,*/		e_SoundSeed_None = 0,
		
/*625*/		CHIME_SOUND_Radarfailure,
/*100*/		CHIME_SOUND_RearRadar_L,
/*100*/		CHIME_SOUND_FrontRadar_L,
/*333*/		CHIME_SOUND_RearRadar_sigaltone,
/*333*/		CHIME_SOUND_FrontRadar_sigletone,
/*500*/		CHIME_SOUND_LCDgong,
/*100*/		CHIME_SOUND_Cornering_R_clark,
/*101*/		CHIME_SOUND_Cornering_R_click,
/*100*/		CHIME_SOUND_Cornering_L_clark,
/*101*/		CHIME_SOUND_Cornering_L_click,
/*50*/		CHIME_SOUND_Hazard_Tock,
/*50*/		CHIME_SOUND_Hazard_Tick,
/*250*/		CHIME_SOUND_Chime05,
/*150*/		CHIME_SOUND_Chime01_sigletone,
/*750*/		CHIME_SOUND_Chime04,
/*1174*/	CHIME_SOUND_Gear,
/*936*/		CHIME_SOUND_DriveMode01,
/*1205*/	CHIME_SOUND_DriveMode02,
/*896*/		CHIME_SOUND_DriveMode03,
/*1515*/	CHIME_SOUND_DriveMode04,
/*768*/		CHIME_SOUND_NoticeStart_face,
/*603*/		CHIME_SOUND_NoticeFailure_face,
/*621*/		CHIME_SOUND_NoticeSuccess_face,
/*900*/		CHIME_SOUND_Cruise_Ready,
/*2427*/	CHIME_SOUND_Cruise_Active,
/*1000*/	CHIME_SOUND_Cruise_Fail,
/*1998*/	CHIME_SOUND_Cruise_Quit,
/*100*/		CHIME_SOUND_Cruise_TakeOveraigaltone,
/*1202*/	CHIME_SOUND_Charge_mono,

/*0,*/		CHIME_SOUND_Reserved,									/*Reserved*/
			e_SoundSeed_All,
}e_SoundSeedList_t;

typedef enum
{
    e_SoundType_IdleMode = 0,
    e_SoundType_RadarRFail3Times,                                                   /*Chime id = 1    后倒车雷达故障-3次*/
    e_SoundType_RadarFFail3Times,                                                   /*Chime id = 2    前车雷达故障-3次*/
    e_SoundType_RadarSDWFail3Times,                                                 /*Chime id = 3    SDW雷达故障-3次*/
    e_SoundType_APAOnce,                                                            /*Chime id = 4    APA声音提示-单次*/
    e_SoundType_RadarRLongRe,                                                       /*Chime id = 5    后倒车雷达Long-重复*/
    e_SoundType_RadarFLongRe,                                                       /*Chime id = 6    前车雷达Long-重复*/
    e_SoundType_RadarSDWLongRe,                                                     /*Chime id = 7    SDW雷达Long-重复*/
    e_SoundType_RadarDWDLongRe,                                                     /*Chime id = 8    涉水深度DWD Long-重复*/
    e_SoundType_RadarRSDS4Hz,                                                       /*Chime id = 9    RSDS侧后辅助系统声音-4HZ_重复*/
    e_SoundType_RadarRSDS3Hz,                                                       /*Chime id = 10    RSDS侧后辅助系统声音-3HZ_重复*/
    e_SoundType_RadarF4HZ,                                                          /*Chime id = 11    前雷达4Hz-4HZ_重复*/
    e_SoundType_RadarR3HZ,                                                          /*Chime id = 12    后倒车雷达3Hz-3HZ_重复*/
    e_SoundType_RadarF3Hz,                                                          /*Chime id = 13    前车雷达3Hz-重复*/
    e_SoundType_RadarSDW3Hz,                                                        /*Chime id = 14    SDW3Hz-重复*/
    e_SoundType_RadarDWD3Hz,                                                        /*Chime id = 15    涉水深度DWD 3Hz-重复*/
    e_SoundType_RadarR2Hz,                                                          /*Chime id = 16    后雷达2Hz-重复*/
    e_SoundType_LDW_LKAOnce,                                                        /*Chime id = 17    LDW&LKA声音提示-重复*/
    e_SoundType_RadarR1_5Hz,                                                        /*Chime id = 18    后倒车雷达1.5Hz-重复*/
    e_SoundType_RadarF1_5Hz,                                                        /*Chime id = 19    前车雷达1.5Hz-重复*/
    e_SoundType_RadarSDW1_5Hz,                                                      /*Chime id = 20    SDW1.5Hz-重复*/
    e_SoundType_RadarDWD1_5Hz,                                                      /*Chime id = 21    涉水深度DWD 1.5Hz-重复*/
    e_SoundType_RadarR1Hz,                                                          /*Chime id = 22    后雷达-1Hz-3次*/
    e_SoundType_RadarF1Hz,                                                          /*Chime id = 23    前雷达-1Hz-3次*/
    e_SoundType_LeaveCar4Hz,                                                        /*Chime id = 24    危险！请立即远离车辆！-4HZ_重复*/
    e_SoundType_StopCar4Hz,                                                         /*Chime id = 25    危险！请安全停车并立即远离车辆-4HZ_重复*/
    e_SoundType_SteeringActRe,                                                      /*Chime id = 26    紧急转向避让辅助激活-重复*/
    e_SoundType_AutoSteeringActRe,                                                  /*Chime id = 27    自动紧急转向避让辅助激活-重复*/
    e_SoundType_AutoBrakePersonRe,                                                  /*Chime id = 28    自动紧急制动启动+行人图片-重复*/
    e_SoundType_AutoBrakeCarRe,                                                     /*Chime id = 29    自动紧急制动启动+车辆图片-重复*/
    e_SoundType_AuxiliaryBrakeRe,                                                   /*Chime id = 30    交叉路口辅助制动启动+车辆图片-重复*/
    e_SoundType_CrossSideBrakeRe,                                                   /*Chime id = 31    前横穿侧向制动启动+车辆图片-重复*/
    e_SoundType_RSideBrakeRe,                                                       /*Chime id = 32    倒车侧向制动启动+车辆图片-重复*/
    e_SoundType_TakeBrakeAcc4Hz,                                                    /*Chime id = 33    请踩刹车（自适应巡航）-4HZ_重复*/
    e_SoundType_TakeBrakeFCWRe,                                                     /*Chime id = 34    请踩刹车（FCW）-重复*/
    e_SoundType_TakeBrakeFCrossRe,                                                  /*Chime id = 35    请踩刹车（前横穿侧向警告）-重复*/
    e_SoundType_TakeSteering4Hz,                                                    /*Chime id = 36    请手握方向盘-4HZ_重复*/
    e_SoundType_TakeSteering2Hz,                                                    /*Chime id = 37    请手握方向盘-2HZ_重复*/
    e_SoundType_TakeSteering1Hz,                                                    /*Chime id = 38    请手握方向盘-1HZ_3次*/
    e_SoundType_KeepDistance,                                                       /*Chime id = 39    请保持安全距离-单次*/
    e_SoundType_TakeCar4Hz,                                                         /*Chime id = 40    请轻转方向盘-4HZ_重复*/
    e_SoundType_TakeCar2Hz,                                                         /*Chime id = 41    请轻转方向盘-2HZ_重复*/
    e_SoundType_TakeCar1Hz,                                                         /*Chime id = 42    请轻转方向盘-1HZ_3次*/
    e_SoundType_AssistExit4Hz,                                                      /*Chime id = 43    车道辅助系统退出请接管车辆-4HZ_重复*/
    e_SoundType_SmartCruiseExit,                                                    /*Chime id = 44    智慧巡航已退出，紧急刹车辅助启动-重复*/
    e_SoundType_KeepPoint4Hz,                                                       /*Chime id = 45    请目视前方-4HZ_重复*/
    e_SoundType_KeepPoint2Hz,                                                       /*Chime id = 46    请目视前方-2HZ_重复*/
    e_SoundType_KeepPointOnce,                                                      /*Chime id = 47    请目视前方-单次*/
    e_SoundType_CheckP0_5Hz,                                                        /*Chime id = 48    请选择P挡-0.5HZ_60S*/
    e_SoundType_CarDistancce,                                                       /*Chime id = 49    请注意前车距离-重复*/
    e_SoundType_Pedestrian,                                                         /*Chime id = 50    注意避让行人-重复*/
    e_SoundType_FaceCar,                                                            /*Chime id = 51    注意对向来车-重复*/
    e_SoundType_CrosswiseCar,                                                       /*Chime id = 52    注意横向来车-重复*/
    e_SoundType_FrontCarAEB,                                                        /*Chime id = 53    前方车辆紧急制动-重复*/
    e_SoundType_FrontCarUnContron,                                                  /*Chime id = 54    注意前方失控车辆-重复*/
    e_SoundType_BackCarUnContron,                                                   /*Chime id = 55    注意后方失控车辆-重复*/
    e_SoundType_AroundCarUnContron,                                                 /*Chime id = 56    注意周围失控车辆-重复*/
    e_SoundType_PlsTakeOver4Hz,                                                     /*Chime id = 57    请立即接管-4hz_重复*/
    e_SoundType_PlsTakeOver2Hz,                                                     /*Chime id = 58    请立即接管-2hz_重复*/
    e_SoundType_PlsTakeOver1Hz,                                                     /*Chime id = 59    请立即接管-1hz_3次*/
    e_SoundType_CarAutoBrakePlsTake,                                                /*Chime id = 60    车辆正在自动刹停，请立即接管-重复*/
    e_SoundType_CarParkingPlsTake,                                                  /*Chime id = 61    车辆正在靠边停车，请立即接管-重复*/
    e_SoundType_CarUrgeBrakePlsTake,                                                /*Chime id = 62    车辆正在紧急刹停，请立即接管-重复*/
    e_SoundType_MoveRampFailPlsTake,                                                /*Chime id = 63    驶入匝道失败，请立即接管-重复*/
    e_SoundType_MoveMainFailPlsTake4Hz,                                             /*Chime id = 64    汇入主路失败，请立即接管-4HZ_重复*/
    e_SoundType_MoveMainFailPlsTake2Hz,                                             /*Chime id = 65    汇入主路失败，请立即接管-2HZ_重复*/
    e_SoundType_MoveMainFailPlsTake1Hz,                                             /*Chime id = 66    汇入主路失败，请立即接管-1HZ_3次*/
    e_SoundType_TurnFailPlsTake4Hz,                                                 /*Chime id = 67    转弯失败，请立即接管-4HZ_重复*/
    e_SoundType_TurnFailPlsTake2Hz,                                                 /*Chime id = 68    转弯失败，请立即接管-2HZ_重复*/
    e_SoundType_TurnFailPlsTake1Hz,                                                 /*Chime id = 69    转弯失败，请立即接管-1HZ_3次*/
    e_SoundType_TollGateFailPlsTake4Hz,                                             /*Chime id = 70    无法成功通过收费站，请立即接管-4HZ_重复*/
    e_SoundType_TollGateFailPlsTake2Hz,                                             /*Chime id = 71    无法成功通过收费站，请立即接管-2HZ_重复*/
    e_SoundType_TollGateFailPlsTake1Hz,                                             /*Chime id = 72    无法成功通过收费站，请立即接管-1HZ_3次*/
    e_SoundType_RoundaboutFailPlsTake4Hz,                                           /*Chime id = 73    无法成功通过环岛，请立即接管-4HZ_重复*/
    e_SoundType_RoundaboutFailPlsTake2Hz,                                           /*Chime id = 74    无法成功通过环岛，请立即接管-2HZ_重复*/
    e_SoundType_RoundaboutFailPlsTake1Hz,                                           /*Chime id = 75    无法成功通过环岛，请立即接管-1HZ_3次*/
    e_SoundType_MoveRampFailHandWheel_2Hz,                                          /*Chime id = 76    驶入匝道失败，请控制方向盘-2Hz_重复*/
    e_SoundType_MoveRampFailHandWheel,                                              /*Chime id = 77    驶入匝道失败，请控制方向盘-1Hz_3次*/
    e_SoundType_MoveMainFailHandWheel,                                              /*Chime id = 78    汇入主路失败，请控制方向盘-1Hz_3次*/
    e_SoundType_TurnFailPlsHandWheel,                                               /*Chime id = 79    转弯失败，请控制方向盘-1Hz_3次*/
    e_SoundType_TollGateFailPlsHandWheel,                                           /*Chime id = 80    无法成功通过收费站，请控制方向盘-1Hz_3次*/
    e_SoundType_RoundaboutFailPlsHandWheel,                                         /*Chime id = 81    无法成功通过环岛，请控制方向盘-1Hz_3次*/
    e_SoundType_Tpms1Hz,                                                            /*Chime id = 82    胎压报警声音提示-1HZ_3次*/
    e_SoundType_HybridFail1Hz,                                                      /*Chime id = 83    混合动力系统故障报警音-1HZ_3次*/
    e_SoundType_Seatbelt0_5Hz,                                                      /*Chime id = 84    安全带未系-0.5HZ_重复*/
    e_SoundType_battery_low0_5Hz,                                                   /*Chime id = 85    蓄电池电量过低，系统3分钟后关闭电源，请启动车辆-0.5HZ_重复 */
    e_SoundType_DoorOpen1_5Hz,                                                      /*Chime id = 86    车门打开声音提示-1.5HZ_60S*/
    e_SoundType_DoorOpen1_Once,                                                     /*Chime id = 87    车门打开声音提示-单次*/
    e_SoundType_DynamicBrake0_5Hz,                                                  /*Chime id = 88    动态制动报警提示-0.5HZ_重复*/
    e_SoundType_HandBrake0_5Hz,                                                     /*Chime id = 89    手刹未松报警提示-0.5HZ_重复*/
    e_SoundType_PositionTickOnce,                                                   /*Chime id = 90    双闪提示音Click-单次*/
    e_SoundType_PositionTockOnce,                                                   /*Chime id = 91    双闪提示音Clack-单次*/
    e_SoundType_TurnLeftTickOnce,                                                   /*Chime id = 92    左转向声音提示Click-单次*/
    e_SoundType_TurnLeftTockOnce,                                                   /*Chime id = 93    左转向声音提示Clalk-单次*/
    e_SoundType_TurnRightTickOnce,                                                  /*Chime id = 94    右转向声音提示Click-单次*/
    e_SoundType_TurnRightTockOnce,                                                  /*Chime id = 95    右转向声音提示Clalk-单次*/
    e_SoundType_OverSpeed1Hz,                                                       /*Chime id = 96    120km/h超速报警声音提示-1HZ_10S*/
    e_SoundType_India120Speed1Hz,                                                   /*Chime id = 97    印度超速报警（二级：120km/h）-1HZ_重复*/
    e_SoundType_India80Speed1Hz,                                                    /*Chime id = 98    印度超速报警（一级：80km/h）-1HZ_10S*/
    e_SoundType_OverSpeedAlarm1Hz,                                                  /*Chime id = 99    超速提醒报警声音提示-1HZ_3S*/
    e_SoundType_TsrOnce,                                                            /*Chime id = 100    限速报警标志提示声音-单次*/
    e_SoundType_FLockOnce,                                                          /*Chime id = 101    前桥差速锁声音报警-单次*/
    e_SoundType_RLockOnce,                                                          /*Chime id = 102    后桥差速锁声音报警-单次*/
    e_SoundType_CLockOnce,                                                          /*Chime id = 103    中央差速锁声音报警-单次*/
    e_SoundType_LightOn0_5Hz,                                                       /*Chime id = 104    灯光未关-0.5HZ_60S*/
    e_SoundType_TunnelTakeCarOnce,                                                  /*Chime id = 105    前方即将穿过隧道,请及时接管车辆-单次*/
    e_SoundType_RoadTakeCarOnce,                                                    /*Chime id = 106    前方存在分叉路口，请及时接管车辆-单次*/
    e_SoundType_ModeFailOnce,                                                       /*Chime id = 107    模式切换失败，请熄火重试-单次*/
    e_SoundType_HcExitTakeDirOnce,                                                  /*Chime id = 108    横向控制已退出，请控制方向-单次*/
    e_SoundType_NOHExitPlsTake,                                                     /*Chime id = 109    前方XX米，即将退出自动导航辅助，请准备接管*/
    e_SoundType_RCarSpeedHigh1Hz,                                                   /*Chime id = 110    后方车辆车速过高-1HZ_3S*/
    e_SoundType_4LModeOnce,                                                         /*Chime id = 111    4L模式请减速慢行-单次*/
    e_SoundType_PowerOnOnce,                                                        /*Chime id = 112    已上电可挂挡行驶-单次*/
    e_SoundType_PleaseRestOnce,                                                     /*Chime id = 113    请注意休息-单次*/
    e_SoundType_PleaseRest1Hz,                                                      /*Chime id = 114    请注意休息-1HZ_3S*/
    e_SoundType_CruiseActOnce,                                                      /*Chime id = 115    巡航类功能激活-单次*/
    e_SoundType_LckActOnce,                                                         /*Chime id = 116    LCK功能激活-单次*/
    e_SoundType_CruiseDownOnce,                                                     /*Chime id = 117    巡航类功能降级-单次*/
    e_SoundType_CruiseStartOnce,                                                    /*Chime id = 118    巡航类功能启动-单次*/
    e_SoundType_LeftSmartdodgeOnce,                                                 /*Chime id = 119    左侧智慧躲闪-单次*/
    e_SoundType_RightSmartdodgeOnce,                                                /*Chime id = 120    右侧智慧躲闪-单次*/
    e_SoundType_VehicleDevRepeate,                                                  /*Chime id = 121    车辆偏离请控制方向盘-持续*/
    e_SoundType_UrgeTurnPlsHoldWheel,                                               /*Chime id = 122    前方急转弯，请手扶方向盘*/
    e_SoundType_SafeDrivRepeat,                                                     /*Chime id = 123    车道辅助系统持续控制中请安全驾驶-持续*/
    e_SoundType_LcdAlarmTen,                                                        /*Chime id = 124    通用报警-10次*/
    e_SoundType_12VPowerSysFail,                                                    /*Chime id = 125    12V电源系统故障，舒适功能关闭，请联系4S店维修！通用报警-10次*/
    e_SoundType_LcdAlarmThree,                                                      /*Chime id = 126    通用报警-3次*/
    e_SoundType_LcdAlarmOnce,                                                       /*Chime id = 127    通用报警-单次*/
    e_SoundType_PowerBatWarmOnce,                                                   /*Chime id = 128    动力电池预热中-单次*/
    e_SoundType_ChargeFaultOnce,                                                    /*Chime id = 129    充电故障声音提示(EV)*/
    e_SoundType_AccCruiseFailOnce,                                                  /*Chime id = 130    自适应巡航无法激活-单次*/
    e_SoundType_AccCruiseQuitOnce,                                                  /*Chime id = 131    自适应巡航功能取消-单次*/
    e_SoundType_SmartCruiseFailOnce,                                                /*Chime id = 132    智能巡航辅助无法激活-单次*/
    e_SoundType_SmartCruisQuitOnce,                                                 /*Chime id = 133    智能巡航辅助功能取消-单次*/
    e_SoundType_FCOKOnce,                                                           /*Chime id = 134    前车已起步-单次*/
    e_SoundType_FCOKAttRoadEnvOnce,                                                 /*Chime id = 135    前车已起步，请注意前方道路环境-单次*/
    e_SoundType_FCOKKeepAtOnce,                                                     /*Chime id = 136    前车已起步，请保持注意力-单次*/
    e_SoundType_FCOKTakeCarOnce,                                                    /*Chime id = 137    前车已起步，请接管车辆-单次*/
    e_SoundType_AccCruiseOkkeepAtOnce,                                              /*Chime id = 138    自适应巡航已激活，请保持注意力-单次*/
    e_SoundType_SmartCruiseOkhwOnce,                                                /*Chime id = 139    智慧巡航已激活，请保持注意力并手握方向盘-单次*/
    e_SoundType_NOHIsActivated,                                                     /*Chime id = 140    自动导航辅助已启动*/
    e_SoundType_ConditionNotMet,                                                    /*Chime id = 141    环境条件不满足，请稍后尝试*/
    e_SoundType_StayFocusedTryAgain,                                                /*Chime id = 142    请保持专注驾驶，再次开启尝试*/
    e_SoundType_HandsOnthewheelTryAgain,                                            /*Chime id = 143    请保持手握方向盘，再次尝试开启*/
    e_SoundType_FastenSeatBelt,                                                     /*Chime id = 144    请系紧安全带*/
    e_SoundType_CloseTheDoor,                                                       /*Chime id = 145    请关闭车门*/
    e_SoundType_FastenPassengerSeat,                                                /*Chime id = 146    请副驾驶系紧安全带*/
    e_SoundType_CCOOnce,                                                            /*Chime id = 147    CCO(越野巡航)故障指示-单次*/
    e_SoundType_TABFailOnce,                                                        /*Chime id = 148    TAB（转向辅助）失效指示-单次*/
    e_SoundType_HighVol0_5Hz,                                                       /*Chime id = 149    上高压后司机离开车门-0.5HZ_12S*/
    e_SoundType_Reserved,                                                           /*Chime id = 150    预留*/
    e_SoundType_NumberOfChimes,
    e_SoundType_NoChime = e_SoundType_NumberOfChimes,
}e_SoundTypeList_t;



typedef enum
{
	e_SoundFreq_None = 0,
		
	e_SoundFreq_0HZ = 0,
	e_SoundFreq_0_5HZ = 5,
	e_SoundFreq_0_889HZ = 9,
	e_SoundFreq_1HZ = 10,
	e_SoundFreq_1_5HZ = 15,
	e_SoundFreq_2HZ = 20,
	e_SoundFreq_3HZ = 30,
	e_SoundFreq_4HZ = 40,

	e_SoundFreq_All,
}e_SoundFrequmentList_t;

typedef struct
{
	e_SoundTypeList_t			soundId_e;
	e_SoundSeedList_t			PlayTyp_e;
	e_SoundFrequmentList_t		Freq_e;
	uint8						Priority_u8;
	uint16					Repeats_u16;
	uint16					ReptTime_u16;
	uint16					Shield_u16;
	uint16 					AttributeBit_u16;
}s_ChimeAudioMap_t;

/********************************************************************************************/
typedef enum
{
	e_ChimeOperationNull = 0,
	e_ChimeOperationStart,
	e_ChimeOperationStartImm,
	e_ChimeOperationStop,
	e_ChimeOperationStopImm,
	e_ChimeOperationRead,
	e_ChimeOperationSetVol,
	e_ChimeOperationMAX
}e_ChimeOperationStatus_t;

typedef enum
{
	e_ChimeNenOk = 0u,
	e_ChimeLowerPriority,
	e_ChimeCurrentlyQueued,
	e_ChimeFullQueue,
	e_ChimeNotQueued,
	e_ChimeCurrentlyPlaying,
	e_ChimeNenOkWithLowerPriority,
	e_ChimeNotActive,
	e_ChimeInvalidRequest
}e_ChimeReturnStatus_t;

typedef enum
{
	e_ChimeCallback_NoChime = 0,
	e_ChimeCallback_Request,
	e_ChimeCallback_Ng,
	e_ChimeCallback_Playing,
	e_ChimeCallback_Idle
}e_ChimeCallbackStatus_t;

typedef enum
{
	e_OstmStatus_Clear = 0,
	e_OstmStatus_Runing,
	e_OstmStatus_Suspend,
	e_OstmStatus_Delay,
	e_OstmStatus_TimeOver,
	e_OstmStatus_Error,
	e_OstmStatus_Max
}e_ChimeOstmStatus_t;

typedef struct
{
	uint8 Id_u8;
	uint8 repeat_u8;
}s_ChimeBackSound_t;

typedef struct
{
	uint8 Id_u8;
	uint8 RsId_u8;
}s_ChimeBackWrn_t;

typedef struct
{
	uint8 Id_u8;
	uint8 RsId_u8;
}s_ChimeBackTT_t;

typedef struct
{
	uint8 CurId_u8;
	uint8 LstId_u8;
	uint8 Sts_u8;
	uint8 Vol_u8;
	uint8 DelayId_u8;
	uint8 IntevalId_u8;
	uint16 CurChimeField;
	s_ChimeOstmData_t delay;
	s_ChimeOstmData_t Inteval;
}s_ChimeLocalSound_t;

typedef struct
{
	uint8 WrnSts[4];
}s_ChimeLocalWrn_t;

typedef struct
{
	uint8 TtSts[64];
}s_ChimeLocalTT_t;


typedef struct
{
	s_ChimeBackSound_t Chime;
	s_ChimeBackWrn_t Wrn;
	s_ChimeBackTT_t Tt;
}s_ChimeBackData_t;

typedef struct
{
	s_ChimeLocalSound_t Chime;
	s_ChimeLocalWrn_t Wrn;
	s_ChimeLocalTT_t Tt;
	s_ChimeOstmData_t Timeout;
	uint8 Pwr_u8;
	uint8 OstmErr_u8;
	uint8 OstmCntStart_u8;
	uint32 OstmCnt_u32;
	uint32 OstmCntOld_u32;
}s_ChimeLocalData_t;

typedef struct 
{
	s_ChimeOstmData_t timer;
	uint16 repeat_u16;
	uint16 feild_u16;
}s_ChimeAppParameterData_t;
/**********************************************************************************************************
* S  E  C  T  I  O  N       S  T  A  R  T                                                                 *
* #ifdef SECTION_TEST                                                                                     *
**********************************************************************************************************/
#define SWC_CHIME_START_SEC_CODE
#include "SWC_Chime_MemMap.h" 

/**********************************************************************************************************
*Function   : Chime_KSColdInit                                                                            *
*                                                                                                         *
*Description: Chime cold init interface ,need to call by runable                                          *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_KSColdInit(void);

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
void Chime_KSWarmInit(void);

/**********************************************************************************************************
*Function   : Chime_SpeakSound                                                                            *
*                                                                                                         *
*Description: Chime requirement interface call by app                                                     *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_SpeakSound(uint8 soundId_u8,uint16 field);

/**********************************************************************************************************
*Function   : Chime_StopChime                                                                             *
*                                                                                                         *
*Description: Chime stop interface call by app                                                            *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*           : immFlg_bool: stop immediately flag                                                          *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_StopChime(uint8 soundId_u8,boolean immFlg_bool);

/**********************************************************************************************************
*Function   : Chime_StopAll                                                                               *
*                                                                                                         *
*Description: Chime stop interface call by app                                                            *
*                                                                                                         *
*Parameter  : soundId_u8 : sound id emum                                                                  *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_StopAll(void);

/**********************************************************************************************************
*Function   : Chime_ReadState                                                                             *
*                                                                                                         *
*Description: Read current SOC status                                                                     *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_ReadState(void);

/**********************************************************************************************************
*Function   : Chime_Api_SetVolume_Set                                                                     *
*                                                                                                         *
*Description: Set sound volume                                                                            *
*                                                                                                         *
*Parameter  : volume_u8 : volume 0~100%                                                                   *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_SetVolume_Set(uint8 volume_u8);

/**********************************************************************************************************
*Function   : Chime_Api_FeadbackCheck                                                                     *
*                                                                                                         *
*Description: Check current soc status,if is no chime or current playing ,app can send requirement        *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : boolean   : TRUE feedback ok, FALSE: nedd to feedback                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
boolean Chime_Api_FeadbackCheck(void);

/**********************************************************************************************************
*Function   : Chime_Api_RequestProcess_Set                                                                *
*                                                                                                         *
*Description: Chime process requirement interface, requirement once will play once                        *
*                                                                                                         *
*Parameter  : sound_e     :Request id                                                                     *
*                                                                                                         *
*Return     : e_ChimeReturnStatus_t   : Request back status                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
e_ChimeReturnStatus_t Chime_Api_RequestProcess_Set(uint8 sound_u8,uint16 bit);

/**********************************************************************************************************
*Function   : Chime_Api_Cancel_Set                                                                        *
*                                                                                                         *
*Description: Chime process cancel interface,                                                             *
*                                                                                                         *
*Parameter  : sound_e     :Request id                                                                     *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_Cancel_Set(uint8 sound_u8);
/**********************************************************************************************************
*Function   : Chime_Api_RequestField_Set                                                                  *
*                                                                                                         *
*Description: Chime field requirement interface                                                           *
*                                                                                                         *
*Parameter  : field     :Request id                                                                       *
*                                                                                                         *
*Return     : e_ChimeReturnStatus_t   : Request back status                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-10-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_RequestField_Set(uint16 Idx_u16,uint16 field);

/**********************************************************************************************************
*Function   : Chime_Api_CancelField_Set                                                                   *
*                                                                                                         *
*Description: Chime field cancel interface                                                                *
*                                                                                                         *
*Parameter  : field     :Request id                                                                       *
*                                                                                                         *
*Return     : e_ChimeReturnStatus_t   : Request back status                                               *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-10-10                                                                                  *
**********************************************************************************************************/
void Chime_Api_CancelField_Set(uint16 Idx_u16,uint16 field);

/**********************************************************************************************************
*Function   : Chime_SlowRateTask                                                                          *
*                                                                                                         *
*Description: Chime app slow task,call by ruable,The faster call the better                               *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_SlowRateTask(void);
/**********************************************************************************************************
*Function   : Chime_IdleTimeOverCheck                                                                     *
*                                                                                                         *
*Description: check next chime if need to play while idle time                                            *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：Chime id                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint8 Chime_IdleTimeOverCheck(uint8 NexId);

/**********************************************************************************************************
*Function   : Chime_HandleRepeats                                                                         *
*                                                                                                         *
*Description: Chime timer tick subtraction process                                                        *
*                                                                                                         *
*Parameter  : passtime  ：time passing counter,base on OSTM counter or task cycle                          *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_HandleRepeats(uint32 passtime);

/**********************************************************************************************************
*Function   : Chime_OStmStart                                                                             *
*                                                                                                         *
*Description: Chime timer start function,call by sound start playing                                      *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：sound id                                                                       *
*                                                                                                         *
*Return     : uint16 : Repeat times                                                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint32 Chime_OStmStart(uint8 ChimeId_u8);

/**********************************************************************************************************
*Function   : Chime_OStmCheck                                                                             *
*                                                                                                         *
*Description: Chime timer check function,call by task function                                            *
*                                                                                                         *
*Parameter  : void                                                                                        *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_OStmCheck(void);

/**********************************************************************************************************
*Function   : Chime_OStmPause                                                                             *
*                                                                                                         *
*Description: Chime timer pause function,call by sound break by higher priority sound                     *
*                                                                                                         *
*Parameter  : ChimeId_u8 :current playing chime id                                                        *
*             immFlg_bool:break immediately flag                                                          *
*Return     : e_ChimeOperationStatus_t : break status                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
boolean Chime_OStmPause(uint8 ChimeId_u8,uint8 Repeat_u8);

/**********************************************************************************************************
*Function   : Chime_ReleaseDelayCheck                                                                     *
*                                                                                                         *
*Description: Timer status control function                                                               *
*                                                                                                         *
*Parameter  : ChimeId_u8 :chime id                                                                        *
*             Status_u8  :Timer control status                                                            *
*Return     : e_ChimeOperationStatus_t : break status                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
//void Chime_ReleaseDelayCheck(uint8 ChimeId_u8);
/**********************************************************************************************************
*Function   : Chime_ClearLowOnce                                                                          *
*                                                                                                         *
*Description: when high priority eage sound is playing,clear low eage sound                               *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：Chime id                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
uint16 Chime_GetCurrentSoundField(uint8 ChimeId_u8);

/**********************************************************************************************************
*Function   : Chime_ClearLowOnce                                                                          *
*                                                                                                         *
*Description: when high priority eage sound is playing,clear low eage sound                               *
*                                                                                                         *
*Parameter  : ChimeId_u8  ：Chime id                                                                       *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_ClearLowOnce(uint8 ChimeId_u8);

/**********************************************************************************************************
*Function   : Chime_GetCurrentSound                                                                       *
*                                                                                                         *
*Description: Current playing sound get                                                                   *
*                                                                                                         *
*Parameter  : ChimeId_u8 :chime id                                                                        *
*                                                                                                         *
*Return     : e_SoundTypeList_t : sound id                                                                *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
s_ChimeLocalSound_t Chime_GetCurrentSoundSts(void);
/**********************************************************************************************************
*Function   : Chime_IntervalTimeProcess                                                                   *
*                                                                                                         *
*Description: Interval time process                                                                       *
*                                                                                                         *
*Parameter  : id_u8 :chime id                                                                             *
*                                                                                                         *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
void Chime_IntervalTimeProcess(uint8 id_u8);

/**********************************************************************************************************
*Function   : Chime_GetBreakStatus                                                                        *
*                                                                                                         *
*Description: Get sound attributes of soundid                                                             *
*                                                                                                         *
*Parameter  : id_u8  ：sound id                                                                            *
*           bit_u16  ：bit                                                                                 *
*Return     : void                                                                                        *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
boolean Chime_GetBreakStatus(uint8 id_u8,uint16 bit_u16);
/**********************************************************************************************************
*Function   : Chime_OStmGetTimer                                                                          *
*                                                                                                         *
*Description: get timer ptr                                                                               *
*                                                                                                         *
*Parameter  : Id_u8 :current playing chime id                                                             *
*             immFlg_bool:break immediately flag                                                          *
*Return     : e_ChimeOperationStatus_t : break status                                                     *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-08-10                                                                                  *
**********************************************************************************************************/
s_ChimeOstmData_t *Chime_OStmGetTimer(uint8 Id_u8);

/**********************************************************************************************************
*Function   : Chime_AudioConfigGet                                                                        *
*                                                                                                         *
*Description: Chime config get function                                                                   *
*                                                                                                         *
*Parameter  : Id_u8 :chime id                                                                             *
*                                                                                                         *
*Return     : s_ChimeAudioMap_t : configuration ptr                                                       *
*                                                                                                         *
*Author     : Cao wen ping                                                                                *
*                                                                                                         *
*Date       : 2020-12-21                                                                                  *
**********************************************************************************************************/
s_ChimeAudioMap_t Chime_AudioConfigGet(uint8 Id_u8);

//#define CHIME_SOUND_REQUEST_TEST

#ifdef CHIME_SOUND_REQUEST_TEST
void Chime_RequestTestFun(void);
#endif
#define SWC_CHIME_STOP_SEC_CODE
#include "SWC_Chime_MemMap.h"
/**********************************************************************************************************
*#endif Section End                                                                                     *
**********************************************************************************************************/

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

