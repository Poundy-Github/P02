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
*File Name   : WN_Config.h                                                                                *
*                                                                                                         *
*Description : Warning module config file.                                                                *
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
#ifndef WN_CFG_H
#define WN_CFG_H
/**********************************************************************************************************
* External Function Include                                                                               *
**********************************************************************************************************/
#include "Compiler.h"
#include "Platform_Types.h"	
#include "logger.h"

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   System Configuration                                                                                  *
*                                                                                                         *
*                                                                                                         *
***********************************************************************************************************/

#define WN_CFG_WARNING_FUNCTION         (TRUE)
	
/* WN Log */

#define SWC_WN_LOGOUT_ENBLE (TRUE)

#define SWC_WN_PRINT_WARN   fuel_warn

/*********************************************************************************************************/

#define WN_CFG_DEBUG                    (FALSE)

/*********************************************************************************************************/

#define WN_CFG_TIME_TASK_CYCLE          (20u)//ms

#define RTE_E_ComEx_COMEX_NEVER_RECEIVED_WN          (6u)
#define RTE_E_ComEx_COMEX_UPDATE_RECEIVED_WN          (8u)
/**********************************************************************************************************
*   Timer Interface Configuration                                                                         *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  WN_CFG_TIMER_USE_TASK_CYCLE     0x01                                          /***/
/***/          #define  WN_CFG_TIMER_USE_SYSTEM_TIMER   0x02                                          /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define WN_CFG_TIMER_MODE_CONFIG         (WN_CFG_TIMER_USE_TASK_CYCLE)

/*********************************************************************************************************/
#if (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_TASK_CYCLE)

#elif (WN_CFG_TIMER_MODE_CONFIG == WN_CFG_TIMER_USE_SYSTEM_TIMER)

#define WN_CFG_INIT_TIMER()               ()  // modify by fchao in 20200518  (MST_API_boStartTimerWithClear(MST_CFG_enWN_DELAY_TICK,0));

#define WN_CFG_GET_DELAY_TIMER_RUNNING_TIME()   0  // modify by fchao in 20200518   (UINT16)(MST_API_u32GetTimerRunningTimeThenRefresh(MST_CFG_enWN_DELAY_TICK,0))

#else

#error "WN_CFG_TIMER_MODE_CONFIG must be WN_CFG_TIMER_USE_TASK_CYCLE(0x01) or WN_CFG_TIMER_USE_SYSTEM_TIMER(0x02)"

#endif


/**********************************************************************************************************
*   Output Mode Configuration                                                                             *
**********************************************************************************************************/
/***/                                                                                                 /***/
/***/          #define  WN_CFG_OUTPUT_ON_CAN        0x01                                              /***/
/***/          #define  WN_CFG_OUTPUT_ON_SBUS       0x02                                              /***/
/***/                                                                                                 /***/
/*********************************************************************************************************/

#define WN_CFG_OUTPUT_MODE  (WN_CFG_OUTPUT_ON_SBUS)

/*********************************************************************************************************/

/**********************************************************************************************************
*   Warning Configuration                                                                                 *
**********************************************************************************************************/
typedef enum
{
    //Special alarm
    WN_enDrvAwayCar,                    //1.147 危险！请立即远离车辆！
    WN_enDrvAwayCarStop,                //1.147 危险！请安全停车并立即远离车辆！
    WN_enIFCESSTrig,                    //1.213 ESS紧急转向避让辅助功能激活
    WN_enIFCAESTrig,                    //1.212 AES自动紧急转向避让辅助功能激活
    WN_enAEBTrigP,                      //1.187 针对行人的自动紧急制动启动
    WN_enAEBTrigV,                      //1.186 针对车辆的自动紧急制动启动
    WN_enIASTrigV,                      //1.188 交叉路口辅助制动启动(针对车辆)
    WN_enFCTABrakeActive,               //1.190 前横穿侧向制动启动
    WN_enRSDSRLBStart,                  //1.196 倒车侧向制动启动
    WN_enACCTakeOverBrake,              //1.198 触发ACC接管请求---请制动
    WN_enAEBFCWWarning,                 //1.184 前碰撞预警---请制动
    WN_enFCTABrakePlease,               //1.189 前横穿侧向警告功能-请制动
    WN_enIFCHoldWheel_1Hz,              //1.210 请手握方向盘1hz
    WN_enIFCHoldWheel_2Hz,              //1.210 请手握方向盘2hz
    WN_enIFCHoldWheel_3Hz,              //1.210 请手握方向盘3hz
    WN_enIFCHoldWheel_4Hz,              //1.210 请手握方向盘4hz
    WN_enAEBSafeDistance,               //1.185 请保持安全距离
    WN_enACCHWATakeOver,                //1.205 高速公路辅助系统-请轻转方向盘
    WN_enACCHWATakeOver_2Hz,            //1.205 高速公路辅助系统-请轻转方向盘2Hz提示音
    WN_enACCHWATakeOver_4Hz,            //1.205 高速公路辅助系统-请轻转方向盘4Hz提示音
    WN_enIFCTakeOver,                   //1.210 车道辅助系统退出，请接管车辆
    WN_enACCHWATakeAtte,                //1.197 高速公路辅助系统-请目视前方
    WN_enACCHWATakeAtte_2Hz,            //1.197 高速公路辅助系统-请目视前方2hz
    WN_enACCHWATakeAtte_4Hz,            //1.197 高速公路辅助系统-请目视前方4hz
    WN_enGearPSelect,                   //1.71  请选择P挡(8AT)   No signal

    //Important alarm
    WN_enLFDoorOpen,                    //1.17/1.18  左前门开报警
    WN_enRFDoorOpen,                    //1.17/1.18  右前门开报警
    WN_enLRDoorOpen,                    //1.17/1.18  左后门开报警
    WN_enRRDoorOpen,                    //1.17/1.18  右后门开报警
    WN_enTrunkOpen,                     //1.17/1.18  后备箱开报警
    WN_enHoodOpen,                      //1.17/1.18  发动机盖开报警
    WN_enFirRowLSeatBelt,               //1.44  第一排左安全带报警提示
    WN_enFirRowRSeatBelt,               //1.44  第一排右安全带报警提示
    WN_enSecRowLSeatBelt,               //1.44  第二排左安全带报警提示
    WN_enSecRowMSeatBelt,               //1.44  第二排中安全带报警提示
    WN_enSecRowRSeatBelt,               //1.44  第二排右安全带报警提示
    WN_enBrakeSysFault,                 //1.12/1.13/1.14  制动系统故障
    WN_enDynSysFault,                   //1.160 动力系统严重故障   No signal
    WN_enCCOTargetSpeed0,               //1.145 CCO目标车速一段
    WN_enCCOTargetSpeed1,               //1.145 CCO目标车速二段
    WN_enCCOTargetSpeed2,               //1.145 CCO目标车速三段
    WN_enCCOTargetSpeed3,               //1.145 CCO目标车速四段
    WN_enCCOTargetSpeed4,               //1.145 CCO目标车速五段
    WN_enCCOTargetSpeed5,               //1.145 CCO目标车速六段
    WN_enCCOTargetSpeed6,               //1.145 CCO目标车速七段
    WN_enCCOTargetSpeed7,               //1.145 CCO目标车速八段
    WN_enCCOTargetSpeed8,               //1.145 CCO目标车速九段
    WN_enSlowTargetSpeed0,              //1.216 蠕行目标车速一段
    WN_enSlowTargetSpeed1,              //1.216 蠕行目标车速二段
    WN_enSlowTargetSpeed2,              //1.216 蠕行目标车速三段
    WN_enSlowTargetSpeed3,              //1.216 蠕行目标车速四段
    WN_enSlowTargetSpeed4,              //1.216 蠕行目标车速五段
    WN_enSlowTargetSpeed5,              //1.216 蠕行目标车速六段
    WN_enSlowTargetSpeed6,              //1.216 蠕行目标车速七段
    WN_enSlowTargetSpeed7,              //1.216 蠕行目标车速八段
    WN_enSlowTargetSpeed8,              //1.216 蠕行目标车速九段
    WN_enIFCESSFault,                   //1.213 紧急转向避让辅助功能故障
    WN_enFLTirePressWarning,            //1.33  左前胎压过低报警
    WN_enFRTirePressWarning,            //1.33  右前胎压过低报警
    WN_enRLTirePressWarning,            //1.33  左后胎压过低报警
    WN_enRRTirePressWarning,            //1.33  右后胎压过低报警
    WN_enFLTireTempWarning,             //1.34  左前胎温过高报警
    WN_enFRTireTempWarning,             //1.34  右前胎温过高报警
    WN_enRLTireTempWarning,             //1.34  左后胎温过高报警
    WN_enRRTireTempWarning,             //1.34  右后胎温过高报警
    WN_en4WDSystemFault,                //1.72  四驱系统故障
    WN_en4WDSystemHeat,                 //1.73  四驱系统过热
    WN_enHybSysFault_Stop,              //1.100 混合动力系统故障，请安全停车
    WN_enHybSysUnavailable,             //1.101 车辆发生碰撞，混合动力系统不可用
    WN_enCharging,                      //1.186 正在充电 TBD
    WN_enChargeWait,                    //1.186 预约充电 TBD
    WN_enChargeComplete,                //1.186 充电已完成 TBD
    WN_enChargeStop,                    //1.186 充电已停止 TBD
    WN_enDynBattSysFault_Stop,          //1.102 动力电池系统故障，请安全停车
    WN_enDynBattSysFault_Repair,        //1.102 动力电池系统故障，请及时到4S店维修
    WN_enIFCAESFault,                   //1.212 自动紧急转向避让功能不可用
    WN_enTransWarnStopCar,              //1.45  变速器过热,请安全停车
    WN_enPowerSysFault,                 //1.68  动力系统故障  (8AT)   No signal
    WN_enTransFault,                    //1.48/1.49/1.50/1.51  变速器故障
    WN_enTransPutInPFailed,             //1.52/1.53  变速器未能成功挂入P挡
    WN_enLowOilPressure,                //1.7   机油压力不足
    WN_enEngWaterTempHigh,              //1.2   发动机水温过高
    WN_enTransWarning,                  //1.45/1.46/1.47  变速器过热
    WN_enDrvSysFault_Repair,            //1.99  驱动系统故障 请及时到4S店维修
    WN_enHybSysFault_Repair,            //1.96  混合动力系统故障，请及时到4S店维修
    WN_enStartingSysFault,              //1.93  起动系统故障，请及时到4S店维修
    WN_enHybSysLimited,                 //1.97  混合动力系统功率暂时受限，请小心驾驶
    WN_enRecoverySysFault,              //1.98  能量回收系统故障，请及时到4S店维修
    WN_enChargerFault,                  //1.91  充电机故障，请及时到4S店维修
    WN_enChargeSysFault,                //1.92  充电系统故障，充电停止
    WN_enChargerTempHigh,               //1.86  充电机温度过高，充电停止
    WN_enDynBattTempHigh,               //1.87  动力电池温度过高，充电停止
    WN_enChargerPWReduced,              //1.89  充电机输出功率降低
    WN_enFCTAUnavai,                    //1.194 前向横穿辅助功能不可用
    WN_enLockFailureN,                  //1.63  变速器在N档，车辆无法锁止
    WN_enNoticeGearN,                   //1.66  请注意变速器在N挡(8AT)
    WN_enPositionLampOn,                //1.21/1.22  灯光未关提示
    WN_enRSDSTrailer,                   //1.195 拖车模式 侧后辅助系统停用
    WN_enAEBFCWTrailer,                 //1.192 拖车模式 前向辅助系统停用
    WN_enACCHWACrossTunnel,             //1.204 前方隧道，请小心
    WN_enACCHWABranchRoad,              //1.204 前方岔路口，请手扶方向盘
    WN_enChargeDevConnectErr,           //1.90  充电装置连接不正确，充电停止
    WN_enDynBattTempLow,                //1.88  动力电池温度过低，充电停止
    WN_enChargePortWarning,             //1.85  充电口输入功率不足，充电停止
    WN_enIFCSCalibrating,               //1.209 智能前视系统传感器标定中
    WN_enTransAuthenFailed,             //1.48/1.108 防盗认证失败
    WN_enTransLimited,                  //1.48/1.49/1.50  变速器功能受限
    WN_enTransReleasePFailed,           //1.52  变速器无法解除P挡
    WN_enElecSteerUnlockFail,           //1.43  电子转向锁解锁失败，请转动方向盘
    WN_enEngPumpFault,                  //1.148 发动机主水泵故障，请尽快维修
    WN_enAGSFault,                      //1.165 主动格栅故障
    WN_enChargeDevDisconnect,           //1.81  请断开充电装置
    WN_enChargeDevConnect,              //1.90  请连接充电装置
    WN_enDynBattLow,                    //1.79  动力电池电量低，请及时充电
    WN_enGearChngP,                     //1.82  请将挡位置于P挡
    WN_enGearPNeedStop,                 //1.69  P挡时车辆需静止 (8AT)
    WN_enHighBeamSysFault,              //1.131/1.132/1.133 前照灯故障
    WN_enGearPNotSuitable,              //1.70  车速较高不适合挂入P挡(8AT)
    WN_enLimpModeGearD,                 //1.64  变速器D挡跛行模式(8AT)   No signal
    WN_enLimpModeGearP,                 //1.65  变速器P挡跛行模式(8AT)   No signal
    WN_enReadyNoRefuel,                 //1.149 车辆已上上电，禁止加油   No signal
    WN_enFuelPrepare,                   //1.178 加油准备中
    WN_enRaceLaunchActive,              //1.111 弹射起步激活
    WN_enRaceModeActive,                //1.112 弹射模式激活
    WN_enRaceLaunchTimeout,             //1.111 超时保护
    WN_enChargingNoRefuel,              //1.149 充电装置已连接，禁止加油   No signal
    WN_enFuelTankSysFault,              //1.110 油箱系统故障，请维修
    WN_enFuelTankCapOn,                 //1.141 油箱盖未关闭
    WN_enGPFRegenerating,               //1.118 颗粒捕集器正在再生
    WN_enGPFRegenerate,                 //1.118 颗粒捕集器需要再生
    WN_enRearAxleSysFault,              //1.99  后桥系统故障，请及时到4S店维修
    WN_enFrontAxleSysFault,             //1.94  前桥系统故障，请及时到4S店维修
    WN_enDoNotStepAcAndBr,              //1.107 请勿同时踩下加速与刹车踏板
    WN_enElecShifterFault,              //1.67  电子换挡器故障 (8AT)   No signal
    WN_enStatBattLowTranMode,           //1.8   运输模式
    WN_enStatBattLowComfortOff,         //1.8   12V电源系统故障，舒适功能关闭 
    WN_en12VFaultStop,                  //1.151 12V电源系统故障，请安全停车
    WN_en12VFaultRepair,                //1.151 12V电源系统故障，请及时到4S店维修
    WN_enStatBattLowSavingMode,         //1.8   电量消耗过多，进入省电模式
    WN_enStatBattLowStartUp,            //1.8   12V蓄电池电量低，请启动车辆
    WN_enModeSwitchFailed,              //1.139 模式切换失败，请熄火重试
    WN_enRefuelingNoCharge,             //1.150 正在加油，禁止充电
    WN_enShiftGearBrakeAndKey,          //1.56  换挡请踩刹车并按下解锁键
    WN_enShiftGearStepBrake,            //1.59  换挡请踩刹车
    WN_enShiftGearPressKey,             //1.56  换挡请按下解锁键   No signal
    WN_enShiftNotAllowed,               //1.60/1.61 车速过高无法切换挡位
    WN_enShiftPStop,                    //1.60  请在车辆静止时挂入P档
    WN_enDMSTakeRest_1,                 //TBD   请注意休息，取自DMS模块
    WN_enDMSTakeRest_2,                 //TBD   请注意休息，取自DMS模块
    WN_enDMSTakeRest_3,                 //TBD   请注意休息，取自DMS模块
    WN_enDMSTakeAttention,              //TBD   请专心驾驶
    WN_enPPMIFault,                     //1.166 主动式安全带故障   No signal
    WN_enSidePPMIErr,                   //1.238 副驾主动式安全带故障
    WN_enBSGSysFault,                   //1.95  BSG系统故障，请及时到4S店维修
    WN_enPlsStartSelfClean,             //1.234 请原地开启排气自洁
    WN_enPlsStartCarSlowly,             //1.234 请启动车辆并怠速
    WN_enDPFCleaning,                   //1.234 颗粒捕集器正在自洁
    WN_enSelfCleanComplete,             //1.234 自洁完成感谢等待
    WN_enGearChngPN,                    //1.83  请将挡位置于P挡或N挡   
    WN_enRainDoorOpen,                  //1.241 防雨棚未关闭
    WN_enHeatingPlugIn,                 //1.152 动力电池温度低，请插枪加热
    WN_enUreaLow,                       //1.233 尿素液位低，请加注
    WN_enUreaVeryLow,                   //1.233 尿素液位极低，请加注
    WN_enUreaTankEmpty,                 //1.233 尿素罐空，禁止下次启动
    WN_enUreaUnqualifyPlsCheck,         //1.233 尿素不合格，请检查
    WN_enUreaUnqualifyOver50km,         //1.233 尿素不合格 行驶超过50km
    WN_enUreaFillStopPlsReFill,         //1.233 尿素喷射中断 请检查
    WN_enUreaFillStopOver50km,          //1.233 尿素喷射中断 行驶超过50km
    WN_enUreaSysDisableEng,             //1.233 尿素系统禁止发动机启动
    WN_enUreaSysErrPlsCheck,            //1.233 尿素系统故障，请入站检查
    WN_enUreaSysErrOver50km,            //1.233 尿素系统故障，行驶超过50km
    WN_enUreaSysErrRestartErr,          //1.233 尿素系统故障，禁止下次启动
    WN_enDM_ENS_EV,                     //1.109 发动机需要启动, EV模式不可用
    WN_enFrontTireAlignFinish,          //1.235 前轮回正完成
    WN_enFrontTireTurnRight,            //1.235 前轮未回正 请右打方向盘
    WN_enFrontTireTurnLeft,             //1.235 前轮未回正 请左打方向盘
    WN_enRayAntiVirusWarn,              //1.243 请在车内无人状态下开启紫外线消毒杀菌功能
    WN_enDrvConcentrate,                //1.169 危险 请专心驾驶
    WN_enDrvDrowsy,                     //1.170 危险 请勿疲劳驾驶
    WN_enCantDriveBatt,                 //1.152 电池温度低，车辆无法行驶
    WN_enDischargingV2L,                //1.167 连接成功，正在放电中+V2L   No signal
    WN_enDischargingV2V,                //1.167 连接成功，正在放电中+V2V   No signal
    WN_enEngVinMismatch,                //1.182 发动机与仪表VIN未匹配
    WN_enORExperMode,                   //1.140 越野专家模式
	WN_enChargeHeating,                 //1.214 动力电池预热中
    WN_enHSMLimitPlsSwiEV,              //1.228 储氢系统受限，请切换为电动模式
    WN_enHSMErrPlsSwiEVAndStop,         //1.228 储氢系统故障，请切换为电动模式并安全停车
    WN_enHSMErrStop,                    //1.228 储氢系统故障，请安全停车
    WN_enBattSysErrPlsFix,              //1.229 燃料电池系统故障，请到4S店维修
    WN_enBattSysErrPlsFix_1,            //1.229 燃料电池系统故障，请到4S店维修
    WN_enHSErrPlsFix,                   //1.230 氢气系统故障，请到4S店维修
    WN_enHSLeakPlsFix,                  //1.230 氢气泄漏，请到4S店维修
    WN_enHSLeakPlsSwiEV,                //1.231 氢气泄漏，请切换为电动模式
    WN_enHSLeakPlsSwiEVStop,            //1.231 氢气泄漏，请切换为电动模式并安全停车
    WN_enHSLeakStop,                    //1.231 氢气泄漏，请安全停车，并远离车辆
    WN_enDeionizerErrPlsFix,            //1.232 冷却液离子浓度过高，请到4S店维修
    WN_enWPCTakePhone,                  //1.144 请带好手机
    WN_enARHUDFault,                    //1.217 抬头显示故障
    WN_enARHUDOverheat,                 //1.217 抬头显示过温保护无法显示
    WN_enSRaceLaunchActive,             //1.111 超级弹射起步激活
    WN_enBattLowSRaceLaunUnAvail,       //1.111 动力电池可用功率低，超级弹射不可用； 普通弹射激活
    WN_enTransHeatSLaunchUnAvail,       //1.111 变速器温度高，超级弹射不可用；普通弹射激活
    WN_enSRaceLaunchOverLimit,          //1.111 超级弹射使用次数达到上限，普通弹射激活
    WN_enBattTempLowCantStart,          //1.152 动力电池温度过低，车辆无法启动
    WN_enBattTempLowPowerDown,          //1.221 动力电池温度低，动力降低
    WN_enBattTempHighPowerDown,         //1.221 动力电池温度高，动力降低
    WN_enPlsPrsBrktoWait,               //1.52 请踩下制动踏板或拉起EPB，待P挡自学习完成后释放
    WN_enSelfLearnNotComplete,          //1.52 P挡自学习未完成，待自学习完成后换挡
    WN_enLearnSuccessPlsRelBrk,         //1.52 P挡自学习完成，请松开制动踏板
    WN_enPowerLowEVUnvil,               //1.109 动力电池可用功率低，EV模式不可用
    WN_enPlsCtrlWheel,                  //1.210 车辆偏离，请控制方向盘
    WN_enRearAxSysErr4WDUnvil,          //1.109 后桥系统故障，四驱相关模式不可用

    //Secondary alarm
    WN_enPEPSPowerFault,                //1.41  PEPS电源继电器故障
    WN_enOverSpeedLevel_1,              //1.16  车速一级警报
    WN_enOverSpeedLevel_2,              //1.16  车速二级警报
    WN_enOverSpeedSetting,              //1.62  车速警报手动可调
    WN_enLicPlateLampFault,             //1.25/1.26  牌照灯故障
    WN_enRvsLampFault,                  //1.27/1.28  倒车灯故障
    WN_enRearPosnLampFault,             //1.29  后位灯故障
    WN_enLasHdLightFault,               //1.120 激光辅助远光光源故障
    WN_enIFCSDectectLimited,            //1.208 智能前视系统传感器探测受限
    WN_enACCSensorDetectLimited,        //1.191 前向辅助系统传感器探测受限
    WN_enFCTSDectectLimit,              //1.193 前角雷达传感器探测受限
    WN_enIFCLKAFunLimited,              //1.207 紧急车道保持功能受限
    WN_enCommunicationFault,            //1.104 通信故障，请小心驾驶  已删除
    WN_enACCHWAFuncFault,               //1.206 变道辅助功能故障
    WN_enRSDSRCWWarning,                //1.197 后方车辆车速过高
    WN_enBeepSysFault,                  //1.103 声音提示系统错误
    WN_enBrakeLampFault,                //1.23/1.24  制动灯故障
    WN_enRearFogLampFault,              //1.19/1.20  后雾灯故障
    WN_enRainLightFault,                //1.31  雨量光线传感器故障
    WN_enAFSSystemFault,                //1.129 AFS系统故障
    WN_enACCUnavailable,                //1.201 智慧巡航功能不可用
    WN_enACCCruiseFunFault,             //1.199 自适应巡航功能不可用
    WN_enAEBESPOff,                     //1.183 ESP关闭 前向辅助系统已停用
    WN_enTrafficSignFault,              //1.211 交通标志信息功能故障
    WN_enStatBattLowPwrReduce,          //1.8   12V蓄电池电量低，舒适功能降功率
    WN_enALSSysFault,                   //1.127 ALS系统故障
    WN_enORCruiseLimited,               //TBD   越野巡航功能受限
    WN_enTurnAssistLimited,             //TBD   转向辅助功能受限
    WN_enHDCLimited,                    //1.9  陡坡缓降功能受限
    WN_enAutoholdLimited,               //1.10  自动驻车功能受限
    WN_enWPCChargeZone,                 //1.143 请确认手机充电区域是否有异物或者偏离
    WN_enPHLFault,                      //1.124 像素大灯故障   No signal
    WN_enPHLCameraFault,                //1.125 像素大灯摄像头故障   No signal
    WN_en4LModeSlow,                    //1.136 4L模式请减速慢行  No signal
    WN_en4WDSystemDemotion,             //1.146 四驱系统功能降级  No signal
    WN_en4HModeSlow,                    //1.136 4L模式请减速慢行  No signal
    WN_enVSGFault,                      //1.154 VSG故障  No signal
    WN_enDynBattCutOff,                 //1.155 动力蓄电池已切断  No signal
    WN_enElecMachiFault,                //1.156 电机故障  No signal
    WN_enDCDCFault,                     //1.157 12V蓄电池充电系统故障  No signal
    WN_enEParkFault,                    //1.159 E-PARK故障  No signal
    WN_enRemoveChargeGun,               //1.160 请移除充电枪
    WN_enRemoveDischrgGun,              //1.160 请移除充放电枪
    WN_enShifterFault,                  //1.160 换挡器故障
    WN_enShiftNotAllowEV,               //1.62  车速过高无法切换挡位（EV）
    WN_enShiftPFault,                   //1.160 P挡故障
    WN_enShiftPStopEV,                  //1.160 请在车辆静止时挂入P挡（EV）  No signal
    WN_enChargingShift,                 //1.160 车辆充电中无法换挡  No signal
    WN_enStepBrakeOutP,                 //1.160 请踩制动切出P挡  No signal
    WN_enStepBrakeOutN,                 //1.160 请踩制动切出N挡  No signal
    WN_enLVBattFault,                   //1.160 小蓄电池故障  No signal
    WN_enHVBattSport,                   //1.160 动力电池电量低，运动模式不可用  No signal
    WN_enHVBattAir,                     //1.160 动力电池电量低，空调功能受限  No signal
    WN_enECOValue,                      //1.160 已到ECO模式极限值  No signal
    WN_enPedalLimit,                    //1.160 电量高，单踏板功能受限  No signal
    WN_enUnidentifyBatt,                //1.160 无法识别电池包，请检查  No signal
    WN_enHeatManagerFault,              //1.161 热管理伺服部件故障，请尽快检修  useless
    WN_enFarBeamFault,                  //1.122 超远辅助远光故障  No signal
    WN_enDynBattFault,                  //1.158 动力电池故障  No signal
    WN_enTboxErr,                       //1.179 请更换紧急呼叫系统备用电池
    WN_enDynBattLowEV,                  //1.78  动力电池电量低
    WN_enSuspensionLimit,               //1.237 悬架阻尼功能受限

    //Tips
    WN_enPowerOnGearDrive,              //1.105/1.106 已上电可挂挡行驶  No signal
    WN_enFuelStart,                     //1.178 可以开始加油
    WN_enKeyInCarOrNot,                 //1.36  请确认钥匙是否在车内
    WN_enACCISLCruiseSpeed,             //1.203 向里拨动开关，确认调整车速
    WN_enStepBrakeStartGearPN,          //1.37 踩下刹车+一键启动 请挂P挡或N挡
    WN_enStepClutchStartGearNull,       //1.38 踩下离合+ 一键启动 请挂空档
    WN_enStepBrakeStartGearNull,        //1.40 踩下刹车+一键启动 请挂N挡 
    WN_enACCISLSlowDown,                //1.203 速度过高请主动减速
    WN_enTargetCruiseSpeed,             //1.3/1.4/1.5   定速巡航
    WN_enLasHdLightOn,                  //1.121 激光辅助远光开启
    WN_enLasHdLightOff,                 //1.121 激光辅助远光关闭
    WN_enParkLampOn,                    //1.30  驻车灯已开启
    WN_enDrowsyDrvWarning,              //1.32  疲劳驾驶预警
    WN_enDrowsyDrvWarning_1Hz,          //1.32  疲劳驾驶预警1hz
    WN_enTakeTheKeyTip,                 //1.35  请带好钥匙提示
    WN_enFuelLowWarn,                   //1.74  请添加燃油
    WN_enAFSDrivingMode,                //1.130 AFS临时行驶模式  No signal
    WN_enALSDrivingSide,                //1.128 ALS临时行驶模式  No signal
    WN_enMaintainPlease,                //TBD   请保养汽车 已删除
    WN_enMaintainNext,                  //TBD   距下次保养XXkm 已删除
    WN_enReleaseElecParkCCO,            //1.77  请释放电子驻车
    WN_enPleaseSlowDown,                //1.77  请减速
    WN_en4LModeStop,                    //1.173 为完成4L模式切换，请停车  No signal
    WN_enPleaseGearN,                   //1.174 为完成4L模式切换，请挂N挡  No signal
    WN_en4LModeEx,                      //1.175 请退出4L模式  No signal
    WN_en4LModeSelect,                  //1.177 请选择4L  No signal
    WN_en4HModeSelect,                  //1.177 请选择4H  No signal
    WN_en4LModeEn,                      //1.176 请进入4L模式
    WN_enORCruiseActive,                //1.75 请激活越野巡航功能  No signal
    WN_enDM_B30_Standard,               //1.113 标准模式
    WN_enDM_B30_Sport,                  //1.113 运动模式
    WN_enDM_B30_Snow,                   //1.113 雪地模式
    WN_enDM_B30_Muddy,                  //1.113 泥地模式
    WN_enDM_B30_Sand,                   //1.113 沙地模式
    WN_enDM_B30_4L,                     //1.113 4L模式
    WN_enDM_B30_ECO,                    //1.113 经济模式
    WN_enDM_B30_IMC,                    //1.113 智能模式
    WN_enDM_B30_SportPlus,              //1.113 超级运动模式
    WN_enDM_B30_OffRoad,                //1.113 越野模式
    WN_enDM_B30_Expert,                 //1.113 专家模式
    WN_enDM_B30_Rock,                   //1.113 岩石模式
    WN_enDM_B30_Pothole,                //1.113 凹凸路模式
    WN_enDM_B30_MuddySand,              //1.113 泥砂模式
    WN_enDM_B30_Mountain,               //1.113 山地模式
    WN_enDM_StandardSelect,             //1.113 标准模式已选择
    WN_enDM_SportSelect,                //1.113 运动模式已选择
    WN_enDM_SportPlusSelect,            //1.113 超级运动模式已选择
    WN_enDM_SnowSelect,                 //1.113 雪地模式已选择
    WN_enDM_MuddySelect,                //1.113 泥地模式已选择
    WN_enDM_SandSelect,                 //1.113 沙地模式已选择
    WN_enDM_EcoSelect,                  //1.113 经济模式已选择
    WN_enDM_RockSelect,                 //1.113 岩石模式已选择
    WN_enDM_PotholeSelect,              //1.113 凹凸路模式已选择
    WN_enDM_MuddySandSelect,            //1.113 泥沙模式已选择
    WN_enDM_MountainSelect,             //1.113 山地模式已选择
    WN_enDM_ExpertSelect,               //1.113 专家模式已选择
    WN_enDM_OffRoadSelect,              //1.113 越野模式已选择
    WN_enDM_4LSelect,                   //1.113 4L模式已选择
    WN_enDM_IMCSelect,                  //1.113 智能模式已选择
    WN_enDM_StandardDPR,                //1.113 标准模式切换中，无法进入D/P/R档
    WN_enDM_SportDPR,                   //1.113 运动模式切换中，无法进入D/P/R档
    WN_enDM_EcoDPR,                     //1.113 经济模式切换中，无法进入D/P/R档
    WN_enDM_SnowDPR,                    //1.113 雪地模式切换中，无法进入D/P/R档
    WN_enDM_MuddyDPR,                   //1.113 泥地模式切换中，无法进入D/P/R档
    WN_enDM_SandDPR,                    //1.113 沙地模式切换中，无法进入D/P/R档
    WN_enDM_PotholeDPR,                 //1.113 凹凸路模式切换中，无法进入D/P/R档
    WN_enDM_MountainDPR,                //1.113 山地模式切换中，无法进入D/P/R档
    WN_enDM_RockDPR,                    //1.113 岩石模式切换中，无法进入D/P/R档
    WN_enDM_OffRoadDPR,                 //1.113 越野模式切换中，无法进入D/P/R档
    WN_enDM_SportPlusDPR,               //1.113 超级运动模式切换中，无法进入D/P/R档
    WN_enDM_ExpertDPR,                  //1.113 专家模式切换中，无法进入D/P/R档
    WN_enDM_MuddySandDPR,               //1.113 泥沙模式切换中，无法进入D/P/R档
    WN_enDM_IMCDPR,                     //1.113 智能模式切换中，无法进入D/P/R档
    WN_enDM_4LDPR,                      //1.113 4L模式切换中，无法进入D/P/R档
    WN_en4LEnGearN,                     //1.134/1.135 ESOF 驱动模式 要进入4L模式，请停车挂N 挡  No signal
    WN_en4LEnGearDRP,                   //1.134/1.135 ESOF 驱动模式 进入4L模式中，无法挂入D/R/P 挡  No signal
    WN_en4LExGearN,                     //1.134/1.135 ESOF 驱动模式 要退出4L模式，请停车挂N 挡  No signal
    WN_en4LExGearDRP,                   //1.134/1.135 ESOF 驱动模式 退出4L模式中，无法挂入D/R/P 挡  No signal
    WN_en4LEnClutchStep,                //1.134/1.135 ESOF 驱动模式 要进入4L模式，请停车并踩下离合  No signal
    WN_en4LEnClutchRele,                //1.134/1.135 ESOF 驱动模式 进入4L模式中，请勿松开离合踏板  No signal
    WN_en4LExClutchStep,                //1.134/1.135 ESOF 驱动模式 要退出4L模式，请停车并踩下离合  No signal
    WN_en4LExClutchRele,                //1.134/1.135 ESOF 驱动模式 退出4L模式中，请勿松开离合踏板  No signal
    WN_enDM_StandardSecond,             //1.113 标准模式
    WN_enDM_SportSecond,                //1.113 运动模式
    WN_enDM_SportPlusSecond,            //1.113 超级运动模式
    WN_enDM_SnowSecond,                 //1.113 雪地模式
    WN_enDM_MuddySecond,                //1.113 泥地模式
    WN_enDM_SandSecond,                 //1.113 沙地模式
    WN_enDM_ECOSecond,                  //1.113 经济模式
    WN_enDM_4LSecond,                   //1.113 4L模式
    WN_enDM_PotholeSecond,              //1.113 凹凸路模式
    WN_enDM_MountainSecond,             //1.113 山地模式
    WN_enDM_RockSecond,                 //1.113 岩石模式
    WN_enDM_OffRoadSecond,              //1.113 越野模式
    WN_enDM_ExpertSecond,               //1.113 专家模式
    WN_enDM_IMCSecond,                  //1.113 智能模式
    WN_enDM_MuddySandSecond,            //1.113 泥砂模式
    WN_enDM_EV_StandardStart,           //1.115 标准模式已启动
    WN_enDM_EV_SportStart,              //1.115 运动模式已启动
    WN_enDM_EV_EcoStart,                //1.115 经济模式已启动
    WN_enDM_EV_SnowStart,               //1.115 雪地模式已启动 
    WN_enDM_EV_AutoStart,               //1.115 AUTO模式已启动
    WN_enDM_V51EV_SinPedalStart,        //1.117 单踏板功能已启动
    WN_enDM_V51EV_SinPedalQuit,         //1.117 单踏板功能退出
    WN_enStopBrakeGearN,                //1.162 长时间停车，请踩下刹车/挂入P挡
    WN_enPowerNotInOff,                 //1.42  请关闭电源
    WN_enAutoStartStop,                 //1.6   智能启停
    WN_enChargeDevRemoved,              //1.80 充电装置已移除  No signal
    WN_enDM_DBL_EV_Err,                 //1.109 动力电池电量低，EV模式不可用
    WN_enDM_HSL_AWD,                    //1.109 混合动力系统暂时受限，AWD模式不可用
    WN_enDM_HSL_EV,                     //1.109 混合动力系统暂时受限，EV模式不可用
    WN_enDM_HSL_SAVE,                   //1.109 混合动力系统暂时受限，SAVE模式不可用
    WN_enDM_HSL_SPORT,                  //1.109 混合动力系统暂时受限，SPORT模式不可用
    WN_enDM_HSL_SAND,                   //1.109 混合动力系统暂时受限，沙地模式不可用
    WN_enDM_HSL_MUDDY,                  //1.109 混合动力系统暂时受限，泥地模式不可用
    WN_enDM_HSL_SNOW,                   //1.109 混合动力系统暂时受限，雪地模式不可用
    WN_enDM_PHEV_AutoStart,             //1.114 标准模式已启动
    WN_enDM_PHEV_EvStart,               //1.114 纯电模式已启动
    WN_enDM_PHEV_SaveStart,             //1.114 能量储备模式已启动
    WN_enDM_PHEV_SportStart,            //1.114 运动模式已启动
    WN_enDM_PHEV_AWDStart,              //1.114 四驱模式已启动
    WN_enDM_PHEV_SnowStart,             //1.114 雪地模式已启动
    WN_enDM_PHEV_MuddyStart,            //1.114 泥地模式已启动
    WN_enDM_PHEV_SandStart,             //1.114 沙地模式已启动
    WN_enDM_PHEV_EcoStart,              //1.114 经济模式已启动
    WN_enDM_PHEV_SportPlusStart,        //1.114 超级运动模式已启动
    WN_enDM_MS_SPORT,                   //1.109 已使用手动换挡，车辆切换至SPORT模式
    WN_enDM_MS_SPORT_Only,              //1.109 已使用手动换挡，仅SPORT模式可用
    WN_enDM_HSR_EV,                     //1.109 混合动力系统限制解除，EV模式可用
    WN_enRLUnavaiESPAVH,                //1.111 ESP/AVH功能未关闭，弹射起步不可用
    WN_enRLUnavaiHYB,                   //1.111 混合动力系统暂时受限，弹射起步不可用
    WN_enDM_HSL_SPORT_P,                //1.109 混合动力系统暂时受限，超级动力模式模式不可用
    WN_enDM_HSL_ECO,                    //1.109 混合动力系统暂时受限, ECO模式不可用
    WN_enTurnAssistOn,                  //TBD   转向辅助功能已开启
    WN_enTurnAssistWork,                //TBD   转向辅助功能工作中
    WN_enTurnAssistClose,               //TBD   转向辅助功能已关闭
    WN_enORCruiseClose,                 //TBD   越野巡航功能已关闭
    WN_enORCruiseWait,                  //TBD   越野巡航功能已进入待机状态
    WN_enORCruiseOn,                    //TBD   越野巡航功能已开启
    WN_enFastenSeatbelt,                //1.11  EPB报警1 请系安全带
    WN_enGradientHighWarning,           //1.11  EPB报警1 坡度过大
    WN_enParkSysWarning,                //1.11  EPB报警1 驻车制动过热
    WN_enClampForceWarning,             //1.11  EPB报警1 夹紧力不足
    WN_enStepBrakePedal,                //1.15  请踩制动踏板
    WN_enSettingVehilce,                //TBD   请停车进行设置 已删除
    WN_enOutTempLow,                    //1.119 室外温度低，请减速慢行
    WN_enAFSOff,                        //1.129 AFS关闭  No signal
    WN_enAFSOn,                         //1.129 AFS开启  No signal
    WN_enSwitchMudSand,                 //1.142 请先切换至泥地或沙地模式
    WN_enRaceModeExit,                  //1.112 弹射模式退出
    WN_enRaceModeFault,                 //1.112 无法进入弹射模式
    WN_enPHLWideFunOff,                 //1.123 像素大灯示宽功能未开启，请在中控中设置开启  No signal
    WN_enPHLWideOn,                     //1.123 像素大灯示宽功能开启  No signal
    WN_enPHLWideOff,                    //1.123 像素大灯示宽功能关闭  No signal
    WN_enPHLFunOff,                     //1.136 像素大灯功能关闭  No signal
    WN_enPHLFunOn,                      //1.136 像素大灯功能开启  No signal
    WN_enQuitCompactMode,               //TBD   请退出简洁模式
    WN_enWashModeActive,                //1.163 洗车/拖车模式已激活
    WN_enWashModeSpeed,                 //1.163 车速过高，洗车/拖车模式不可用
    WN_enWashModeBatt,                  //1.163 蓄电池电量低，洗车/拖车模式不可用
    WN_enChargeDisGunConnect,           //1.164 充/放电枪已连接
    WN_enChargeGunConnect,              //1.164 充电枪已连接
    WN_enReleaseElecPark,               //1.76  请释放电子驻车
    WN_enReleaseRearELD,                //1.76  请释放后桥差速锁
    WN_enRLUnavaiESP,                   //1.111 ESP功能未关闭，弹射起步不可用
    WN_enHeatingComplete,               //1.152 动力电池预热完成
    WN_enFaceCancelled,                 //1.172 人脸识别已取消
    WN_enFaceNoMatch,                   //1.172 未找到匹配的人脸
    WN_enFaceSuccess,                   //1.172 人脸识别成功
    WN_enPedalDynBatt,                  //1.168 混合动力系统暂时受限，单踏板不可用  No signal
    WN_enPedalDynSnow,                  //1.168 雪地模式开启，单踏板不可用  No signal
    WN_enFarBeamOn,                     //1.122 超远辅助远光开启  No signal
    WN_enFarBeamOff,                    //1.122 超远辅助远光关闭  No signal
    WN_enTmsTrailerOn,                  //1.180 拖车防摆功能已开启
    WN_enTmsTrailerOff,                 //1.180 拖车防摆功能已关闭
    WN_en4WDGearDelayPlsSlow,           //1.138 四驱换挡直行 请尝试低速直行 TBD
    WN_enARHUDLightLimit,               //1.217 抬头显示亮度限制中
    WN_enBattLowLaunchUnavil,           //1.111 动力电池电量/温度低，弹射起步不可用
    WN_enIFCExitPlsControl,             //1.218 横向控制已退出 请控制方向

    //Update for Warning table v0.60
    //Special alarm

    //Important alarm
    WN_enERCSysErr,                     //1.242 ERC系统故障 请立即维修
    WN_enIFCLKAFuncOn,                  //1.269 紧急车道保持启动

    //Secondary alarm
    WN_enTurnAssistFuncLimit,           //1.248 转向助力功能受限 请小心驾驶
    WN_enERCSysLimit,                   //1.242 ERC系统受限

    //Tips
    WN_enMainTankLow,                   //1.239 主油箱油量低，请添加燃油
    WN_enMainTankLowPlsSwitch,          //1.239 主油箱油量低，请及时熄火并切换到副油箱
    WN_enAuxTankLow,                    //1.239 副油箱油量低，请添加燃油
    WN_enAuxTankLowPlsSwitch,           //1.239 副油箱油量低，请及时熄火并切换到主油箱
    WN_enDM_B30_Turbo,                  //1.113 SUPER SPORT
    WN_enDM_B30_Race,                   //1.113 赛道模式
    WN_enDM_B30_GrassGravel,            //1.113 草地/碎石模式
    WN_enDM_B30_Uneven,                 //1.113 凹凸路模式
    WN_enDM_B30_Wade4H,                 //1.113 涉水模式
    WN_enDM_B30_Wade4L,                 //1.113 低速涉水模式
    WN_enDM_B30_2H,                     //1.113 2H模式
    WN_enDM_B30_4H,                     //1.113 4H模式
    WN_enDM_TurboSelect,                //1.113 狂暴模式已选择
    WN_enDM_RaceSelect,                 //1.113 赛道模式已选择
    WN_enDM_GrassGravelSelect,          //1.113 草地/碎石模式已选择
    WN_enDM_UnevenSelect,               //1.113 凹凸路模式已选择
    WN_enDM_Wade4HSelect,               //1.113 涉水模式已选择
    WN_enDM_Wade4LSelect,               //1.113 低速涉水模式已选择
    WN_enDM_2HSelect,                   //1.113 2H模式已选择
    WN_enDM_4HSelect,                   //1.113 4H模式已选择
    WN_enDM_TurboDPR,                   //1.113 狂暴模式切换中，无法进入D/P/R档
    WN_enDM_RaceDPR,                    //1.113 赛道模式切换中，无法进入D/P/R档
    WN_enDM_GrassGravelDPR,             //1.113 草地/碎石模式切换中，无法进入D/P/R档
    WN_enDM_UnevenDPR,                  //1.113 凹凸路模式切换中，无法进入D/P/R档
    WN_enDM_Wade4HDPR,                  //1.113 涉水模式切换中，无法进入D/P/R档
    WN_enDM_Wade4LDPR,                  //1.113 低速涉水模式切换中，无法进入D/P/R档
    WN_enDM_2HDPR,                      //1.113 2H模式切换中，无法进入D/P/R档
    WN_enDM_4HDPR,                      //1.113 4H模式切换中，无法进入D/P/R档
    WN_enDM_TurboSecond,                //1.113 SUPER SPORT
    WN_enDM_RaceSecond,                 //1.113 赛道模式
    WN_enDM_GrassGravelSecond,          //1.113 草地/碎石模式
    WN_enDM_UnevenSecond,               //1.113 凹凸路模式
    WN_enDM_Wade4HSecond,               //1.113 涉水模式
    WN_enDM_Wade4LSecond,               //1.113 低速涉水模式
    WN_enDM_2HSecond,                   //1.113 2H模式
    WN_enDM_4HSecond,                   //1.113 4H模式
    WN_enDM_PHEV_P2HEVStart,            //1.114 混动模式已启动 useless
    WN_enDM_PHEV_P2EVStart,             //1.114 纯电模式已启动 useless
    WN_enDM_PHEV_P2SaveStart,           //1.114 能量储备模式已启动 useless
    WN_enAutoNaviStart,                 //1.247 已进入支持NOH路段，欢迎使用
    WN_enAutoNaviExitPlsTake,           //1.247 前方 XX 米，即将退出自动导航辅助 useless
    WN_enAutoNaviEnd,                   //1.247 NOH已退出
    WN_enOverSpeedERCSysOn,             //1.242 车速过高 ERC系统自动连接 useless
    WN_enERCSysDisable,                 //1.242 当前驾驶模式 ERC系统断开禁用
    WN_enOffroadThmSts,                 //1.265 越野散热模式已开启
    WN_enAntennaLostErr,                //1.245 低频天线异常
    WN_enAutoLmpStsOn,                  //1.268 自动大灯开启
    WN_enAutoLmpStsOff,                 //1.268 自动大灯关闭
    WN_enPlsExitWadeMode,               //1.267 请退出涉水模式
    WN_enWadeModePlsSlow,               //1.267 请减速
    WN_enWadeModePlsCare,               //1.267 请确认周边工况 如已涉水，谨慎点火

    //Update for Warning table v0.62
    //Special alarm
    
    //Important alarm
    WN_enCarPowerShutDown,              //1.249 长按紧急下电开关，整车下电！
    WN_enLifeDetectFault,               //1.296 生命探测功能故障
    WN_enClutchOverheat,                //1.270 离合器过热
    WN_enQuickStartOvertime,            //TBD 弹射起步超时

    //Secondary alarm

    //Tips
    WN_enLifeDetectClose,               //1.295 生命探测功能关闭
    WN_enStopGearNSeatbelt,             //1.40 踩下刹车+请挂N挡+驾驶侧有人或安全带系上
    WN_enStopGearPNSeatbelt,            //1.40 踩下刹车+请挂P挡或N挡+驾驶侧有人或安全带系上
    WN_enSwitchSnowSand,                //1.142 请先切换至雪地、泥地、沙地或凹凸路模式
    WN_enIndividual,                    //1.116 个性化模式已启动
    WN_enPowerSysLimitLaunchFail,       //TBD 动力系统暂时受限，弹射起步不可用 
    WN_enForwardChargeMode,             //1.274 当前为预约充电模式
    WN_en4WDEVSaveDisable,              //1.109 四驱模式，纯电和能量储备模式不可用
    
    //Popup

    //Update for Warning table v0.64
    //Special alarm
    WN_enV2XCarDistance,                  //1.250 请注意前车距离+图片
    WN_enV2XPeopleRight,                  //1.259 注意避让行人+前后图片
    WN_enV2XPeopleMid,                    //1.259 注意避让行人+后图片
    WN_enV2XPeopleLeft,                   //1.259 注意避让行人+前图片
    WN_enV2XFaceCar,                      //1.255 注意对向来车+图片
    WN_enV2XSideCarTwoSide,               //1.254 注意横向来车+两侧图片
    WN_enV2XSideCarRight,                 //1.254 注意横向来车+右侧图片
    WN_enV2XSideCarLeft,                  //1.254 注意横向来车+左侧图片
    WN_enV2XFrontCarAEB,                  //1.253 前方车辆紧急制动+图片
    WN_enV2XFrontCarUnContron,            //1.258 注意前方失控车辆+图片
    WN_enV2XBackCarUnContron,             //1.258 注意后方失控车辆+图片
    WN_enV2XAroundCarUnContron,           //1.258 注意周围失控车辆+图片
    //Important alarm
    WN_enHookFaultPlsCheck,               //1.278 拖车钩故障 请检查
    WN_enSuspensionFuncLimit,             //1.285 空气悬架功能受限！请尽快维修
    WN_enSuspensionFuncFault,             //1.285 空气悬架故障！请立即维修
    WN_enCatalystSuHigh,                  //1.289 催化器硫含量较高
    WN_enSuClearing,                      //1.289 正在除硫
    WN_enOilLeverLow,                     //1.288 机油液位过低
    WN_enOilLeverHigh,                    //1.288 机油液位过高
    WN_enOilLeverFault,                   //1.288 机油液位检测故障
    WN_enV2XLeftLine,                     //1.252 请勿左侧变道+图片
    WN_enV2XRightLine,                    //1.252 请勿右侧变道+图片
    WN_enV2XReverseLine,                  //1.261 请勿逆向超车+图片
    WN_enV2XFrontRoad,                    //1.262 请注意前方路况+图片
    WN_enV2XFrontCarAttention,            //1.256 请注意前方异常车辆+正前方图片
    WN_enV2XLeaveCar,                     //1.257 注意避让紧急车辆
    WN_enV2XLeaveFireCar,                 //1.257 注意避让消防车
    WN_enV2XLeaveAmbulance,               //1.257 注意避让救护车
    WN_enV2XLeavePolice,                  //1.257 注意避让警车
    WN_enV2XLeaveEngCar,                  //1.257 注意避让工程救援车
    WN_enV2XBackCarLeft,                  //1.251 注意后方盲区车辆+左后盲区图片
    WN_enV2XBackCarRight,                 //1.251 注意后方盲区车辆+右后盲区图片
    WN_enV2XBackCarTwoSide,               //1.251 注意后方盲区车辆+左右后方盲区图片
    //Secondary alarm
    WN_enSavePlusPowerLimit,              //1.160 超级省电模式下动力性和舒适性受限
    WN_enOverSpeedSavePlusFail,           //1.160 车速过高,无法切换超级省电模式
    WN_enWormFuncActive,                  //1.160 蠕行功能已激活
    WN_enWormFuncOff,                     //1.160 蠕行功能已关闭
    WN_enBattLowStartEng,                 //1.284 蓄电池电量低\n启动发动机更改车辆高度
    WN_enSuspensionCoolDown,              //1.284 空气悬架系统正在冷却，请等待
    WN_enHeightModeDisable,               //1.284 所选高度模式不允许
    WN_enPlsCloseDoorRise,                //1.284 请关闭车门\n以完成高度升降
    WN_enRiseModeSusLimit,                //1.284 进入举升模式\n空气悬架临时禁用
    WN_enSuspensionTimeLimit,             //1.284 空气悬架临时禁用
    WN_enOverSpeedHeightDisable,          //1.284 车速高\n无法完成高度切换
    //Tips
    WN_enOverDefaultPower,                //1.287 当前电量高于预设SOC值，无法充电
    WN_enHookLock,                        //1.276 拖车钩已上锁
    WN_enHookUnlock,                      //1.276 拖车钩已解锁
    WN_enHookPowerOn,                     //1.277 拖车钩电气连接完成
    WN_enSwitchParkSts,                   //1.279 请先切换为驻车状态
    WN_enPlsCloseHook,                    //1.280 请先关闭拖车钩
    WN_enPlsCheckHookSts,                 //1.281 请检查拖车钩连接状态
    WN_enNormalHeightSelect,              //1.283 已选择标准高度
    WN_enSuitHeightSelect,                //1.283 已选择便捷进出高度
    WN_enORHeight1Select,                 //1.283 已选择越野高度1
    WN_enORHeight2Select,                 //1.283 已选择越野高度2
    WN_enSuspensionExtend,                //1.283 悬架进入扩展模式
    WN_enSuspensionLockHeight,            //1.283 悬架锁定在便捷进出高度
    WN_enBackShaftHeightSelect,           //1.283 已选择后轴装载高度
    WN_enSuitHeightModeSelect,            //1.283 已选择自动便捷进出模式
    WN_enSuspensionTrailer,               //1.283 空气悬架启用拖车模式
    WN_enSuspensionLimitRise,             //1.283 空气悬架临时禁用\n以进行换胎、举升
    WN_enKickBackShaft,                   //1.283 已选择脚踢开启后轴装载模式
    WN_enSuspensionLimitTrans,            //1.283 空气悬架临时禁用\n用于车辆运输
    WN_enSuspensionRise,                  //1.283 悬架即将升高\n退出当前低水平高度
    WN_enCarHighPlsSlow,                  //1.283 当前车辆处于高位\n请减速慢行
    WN_enSuClearDown,                     //1.289 除硫结束
    WN_enSysFailACCDisable,               //1.282 系统故障，自适应能量回收不可用
    WN_enACCPowerDisable,                 //1.282 传感器故障，自适应能量回收不可用
    WN_enHWAACCPowerDisable,              //1.282 智能驾驶功能激活，自适应能量回收 不可用
    WN_enESPACCPowerDisable,              //1.282 ESP功能激活，自适应能量 回收不可用
    WN_enACCPowerExit,                    //1.282 自适应能量回收退出 
    WN_enBattPowerLowEVDisable,           //TBD 动力电池功率低，纯电模式不可用 已删除
    WN_enBattTempLowEVDisable,            //TBD 动力电池温度低，纯电模式不可用 已删除
    WN_en4LModeEVSaveDisable,             //TBD 当前为4L模式，纯电和能量储备模式不可用
    WN_enCalibreHeatTabLimit,             //1.76 卡钳过热，转向辅助功能受限
    WN_enSavePlusModeStart,               //TBD 超级省电模式已启动
    WN_enV2XRoadBlockLever1,              //1.264 道路轻度拥堵+图片
    WN_enV2XRoadBlockLever2,              //1.264 道路中度拥堵+图片
    WN_enV2XRoadBlockLever3,              //1.264 道路严重拥堵+图片
    WN_enV2XRoadBlock,                    //1.264 道路拥堵+图片
    WN_enStepBrakeStartGearBlank,         //TBD 踩下刹车+一键启动 请挂空挡 
    WN_enStopGearBlankSeatbelt,           //1.38 踩下刹车+请挂空挡+驾驶侧有人或安全带系上

    //Update for Warning table v0.66
    //Special alarm
    WN_enPlsTakeOver,                     //1.205 请立即接管
    WN_enPlsTakeOver_2Hz,                 //1.205 请立即接管2Hz提示音
    WN_enPlsTakeOver_4Hz,                 //1.205 请立即接管4Hz提示音
    WN_enCarAutoBrakePlsTake,             //1.272 车辆正在自动刹停，请立即接管
    WN_enCarParkingPlsTake,               //1.272 车辆正在靠边停车，请立即接管
    WN_enCarUrgeBrakePlsTake,             //1.272 车辆正在紧急刹停，请立即接管
    WN_enMoveRampFailPlsTake,             //1.297 驶入匝道失败，请立即接管
    WN_enMoveMainFailPlsTake,             //1.297 汇入主路失败，请立即接管
    WN_enMoveMainFailPlsTake_2Hz,         //1.297 汇入主路失败，请立即接管2Hz提示音
    WN_enMoveMainFailPlsTake_4Hz,         //1.297 汇入主路失败，请立即接管4Hz提示音
    WN_enTurnFailPlsTake,                 //1.297 转弯失败，请立即接管
    WN_enTurnFailPlsTake_2Hz,             //1.297 转弯失败，请立即接管2Hz提示音
    WN_enTurnFailPlsTake_4Hz,             //1.297 转弯失败，请立即接管4Hz提示音
    WN_enTollGateFailPlsTake,             //1.297 无法成功通过收费站，请立即接管
    WN_enTollGateFailPlsTake_2Hz,         //1.297 无法成功通过收费站，请立即接管2Hz提示音
    WN_enTollGateFailPlsTake_4Hz,         //1.297 无法成功通过收费站，请立即接管4Hz提示音
    WN_enRoundaboutFailPlsTake,           //1.297 无法成功通过环岛，请立即接管
    WN_enRoundaboutFailPlsTake_2Hz,       //1.297 无法成功通过环岛，请立即接管2Hz提示音
    WN_enRoundaboutFailPlsTake_4Hz,       //1.297 无法成功通过环岛，请立即接管4Hz提示音

    //Important alarm
    WN_enV2XFrontCarAttentionLeft,        //1.256 请注意前方异常车辆+左前方图片
    WN_enV2XFrontCarAttentionRight,       //1.256 请注意前方异常车辆+右前方图片
    WN_enUrgeTurnPlsHoldWheel,            //1.204 前方急转弯，请手扶方向盘
    WN_enFastChrgFault,                   //1.294 快充桩故障，充电停止 useless
    WN_enNOHFailPlsFix,                   //1.273 无法开启NOH，请前往4S店修理
    WN_enNOHFailPlsGearP,                 //1.273 无法开启NOH，请挂P挡重新尝试
    WN_enMoveRampFailPlsHand,             //1.273 请手动进入匝道
    WN_enMoveMainFailPlsHand,             //1.273 这次有点难，需要你的帮助
    WN_enTurnFailPlsHand,                 //1.273 转弯失败，请手动尝试
    WN_enTollGateFailPlsHand,             //1.273 无法成功通过收费站，请手动尝试
    WN_enRoundaboutFailPlsHand,           //1.273 无法成功通过环岛，请手动尝试
    WN_enRePlanLanes,                     //1.273 已重新规划路径
    WN_enPlsHandChangeLanes,              //1.273 路况复杂，请手动变道汇出
    WN_enMoveRampFailHandWheel,           //1.297 驶入匝道失败，请控制方向盘
    WN_enMoveRampFailHandWheel_2Hz,       //1.297 驶入匝道失败，请控制方向盘2Hz提示音
    WN_enMoveMainFailHandWheel,           //1.297 汇入主路失败，请控制方向盘
    WN_enTurnFailPlsHandWheel,            //1.297 转弯失败，请控制方向盘
    WN_enTollGateFailPlsHandWheel,        //1.297 无法成功通过收费站，请控制方向盘
    WN_enRoundaboutFailPlsHandWheel,      //1.297 无法成功通过环岛，请控制方向盘

    //Secondary alarm
    WN_enTJAICADisable,                   //1.201 智慧巡航不可用  Useless
    WN_enLowSpeedLaneAssistDisable,       //1.204 车速低于40km/h，变道辅助不可用
    WN_enOverSpeedLaneAssistDisable,      //1.204 车速高于120km/h，变道辅助不可用
    WN_enTJAICAFaultPlsFixCamera,         //1.297 当前无法开启智慧巡航 系统，请擦拭摄像头
    WN_enTJAICAFaultPlsFix,               //1.297 当前无法开启智慧巡航系统，请前往4S 店修理
    WN_enWPCChargeZoneFront,              //1.143 请确认前排手机充电区域是否有异物或者偏离
    WN_enWPCChargeZoneRear,               //1.143 请确认后排手机充电区域是否有异物或者偏离
    WN_enWPCChargeZoneRR,                 //1.143 请确认后排右侧手机充电区域是否有异物或者偏离
    WN_enWPCChargeZoneRL,                 //1.143 请确认后排左侧手机充电区域是否有异物或者偏离

    //Tips
    WN_enAutoNaviExit,                    //1.247 xx公里/xx米后，将退出自动跟随导航驾驶
    WN_enAcceleratorPowen,                //1.282 建议松开油门，便于经济驾驶
    WN_enTurnSafeSlow,                    //1.203 过弯安全降速
    WN_enNOHExit,                         //1.247 XX公里/米后将退出NOH
    WN_enNOHExitPlsTake,                  //1.247 请准备接管，XX米后NOH将退出
    WN_enNOHFinishExit,                   //1.247 请立即接管，NOH已退出
    WN_enOverSpeedNOHExit,                //1.247 若车速高于125km/h，NOH将退出
    WN_enDriveIntoHighSpeed,              //1.247 即将进入快速车道
    WN_enDriveIntoRamp,                   //1.247 进入匝道，请注意安全
    WN_enNOHSetAccSpeed,                  //1.247 巡航车速设为XXkm/h
    WN_enLockNGearDisable,                //1.290 N挡已锁止\n无法换挡
    WN_enPlsPressBrakeTest,               //1.267 请轻踩制动，测试制动性能
    WN_en4Aor4HModeSelect,                //1.177 请选择4A/4H

    //Update for Warning table v0.66
    //Special alarm

    //Important alarm
    WN_enBrakeSwitchFault,                //1.12/1.13/1.14 制动液位开关故障

    //Secondary alarm

    //Tips
    WN_enSafeBackStart,                   //TBD 安全备用系统已启动
    WN_enSafeBackStopCar,                 //TBD 安全备用系统即将靠边停车
    WN_enSwitchGearReleaseBrake,          //1.11 请切换到非P挡释放驻车
    WN_enDM_EV_MuddyStart,                //1.116 泥地模式已启动
    WN_enDM_EV_SandStart,                 //1.116 沙地模式已启动
    WN_enDM_EV_SportPlusStart,            //1.116 超级运动模式已启动

    //Popup
    //Important alarm
	WN_enOneTrunkBoardOpen, 			//1.17/1.18  一体式车箱后板开报警
	WN_enSplitTrunkBoardOpen,           //1.17/1.18  分体式车箱后板开报警

    //Update for Warning table v0.71
    //Special alarm

    //Important alarm
	WN_enQuickChargeFlapOpenPicture,        //1.303  快充电口盖打开的效果示意图片
    WN_enSlowFillingFlapOpenPicture,        //1.303  慢充电口盖打开的效果示意图片
	WN_enSlowFillingFlapNotClosed, 			//1.303  慢充口盖未关
	WN_enQuickChargeFlapNotClosed,          //1.303  快充口盖未关
    WN_enAttentionWaterRoad,                //1.262   请注意前方过水路面
    WN_enAttentionLowlyingRoad,             //1.262   请注意前方低洼路面
    WN_enAttentionWetRoad,                  //1.262   请注意前方湿滑路面
    WN_enAttentionSharpTurn,                //1.262   请注意前方急转弯
    WN_enNoteRoadFailure,                   //1.262   请注意前方道路障碍
    WN_enNoteUnevenRoad,                    //1.262   请注意前方不平路面
    WN_enAttentionDangerousRoad,            //1.262   请注意前方傍山险路
    WN_enAwareDebrisFlow,                   //1.262   请注意前方泥石流
    WN_enNoteBridge,                        //1.262   请注意前方桥梁
    WN_enAttentionTunnel,                   //1.262   请注意前方隧道
    WN_enAwareFire,                         //1.262   请注意前方火灾
    WN_enNoteFallingRock,                   //1.262   请注意前方落石
    WN_enNoteIcyRoad,                       //1.262   请注意前方结冰路面
    WN_enNoteCrosswindRoad,                 //1.262   请注意前方横风路段
    WN_enEmbankmentRoad,                    //1.262   请注意前方堤坝路段
    WN_enNoteContinuousSharpTurn,           //1.262   请注意前方连续急转弯
    WN_enNoteRoadNarrows,                   //1.262   请注意前方道路变窄
    WN_enNoteIncomingTraffic,               //1.262   请注意前方车辆汇入
    WN_enNotedamgeRoadFacities,             //1.262   请注意前方道路设施损坏
    WN_enAwareScatteredObject,              //1.262   请注意前方散落物体
    WN_enNOHIsResumed,                      //1.273   NOH已恢复
    WN_enMargeWatchOutFOrCarsComing,        //1.273   前方汇入，小心侧方来车
    WN_enSlowingDownForDischarge,           //1.273   正在减速，准备汇出
    WN_enNOExitedTakeSteeringWheel,         //1.273   NOH已退出，请接管方向盘
    WN_enLaneLineNotClearDriveCarefully,    //1.273   车道线不清晰，请小心驾驶
	WN_enFourWheelDriveSystem,              //1.301   四驱系统暂时锁定
	WN_enCatcherSeriouslyBlocked,           //1.234   颗粒捕集器严重堵塞，请入站检查
	WN_enChargingStatusDisplay,             //        充电状态显示（延时充电）
//Secondary alarm
	WN_enExcessiveSpeedFourWheelDrive,      //1.301   车速过高四驱系统暂时解除锁定
	
  
//info
    WN_enNavigationSlowDownActive,          //1.302   导航降速已激活，请注意车速
    WN_enPlsPayAttentionToSlowDown,         //1.302   请注意减速
    WN_enSpeedLimitForward60kmPerHour,      //1.302   前方导航限速60km/h，请注意减速
    WN_enSpeedLimitForward70kmPerHour,      //1.302   前方导航限速70km/h，请注意减速
    WN_enSPeedLimitForward80kmPerHour,      //1.302   前方导航限速80km/h，请注意减80
    WN_enSpeedLimitForward90kmPerHour,      //1.302   前方导航限速90km/h，请注意减速
    WN_enSpeedLimitForward100kmPerHour,     //1.302   前方导航限速100km/h，请注意减速
    WN_enSpeedLimitForward110kmPerHour,     //1.302   前方导航限速110km/h，请注意减速
    WN_enSpeedLimitForward120kmPerHour,     //1.302   前方导航限速120km/h，请注意减速
    WN_enCurrentlyExceedNavigationLimit,    //1.302   请注意当前设置车速超过导航限速
    WN_enTurnGearDownConfirmSpeedAdjustment,   //1.203    向下拨动怀挡，确认调整车速
    WN_enPressCruiseConfirmAdjustment,      //1.203    按cruise键，确认调整车速
    WN_enComingOutMainRoad,                 //1.247     即将从主路汇出
    WN_enGoddessModeActivated,              //1.116   女神模式已启动

	
    //Update for Warning table v0.71 official version
    //Special alarm

    //Important alarm
	WN_enWshngLiquidNotEnough,				//1.306 洗涤液不足 请及时加注
	WN_enUreaInsCantStartAfter,				//1.233 尿素不足，XXXkm后无法启动，请加注
	WN_enUreaInsSeriouslyCantStartAfter,	//1.233 尿素严重不足，xxxkm后无法启动，请加注
	WN_enUreaEmptyCantStartNext,			//1.233 尿素罐空，下次无法启动，请加注
	WN_enUreaEmptyCantStart,				//1.233 尿素罐空，无法启动，请加注
	WN_enUreaUnqualifyCantStartAfter,		//1.233 尿素不合格，xxxkm后无法启动，请维修
	WN_enUreaUnqualifyCantStartNext,		//1.233 尿素不合格，下次无法启动，请维修
	WN_enUreaUnqualifyCantStart,			//1.233 尿素不合格，无法启动，请维修
	WN_enUreaFillStopCantStartAfter,		//1.233 尿素喷射中断，xxxkm后无法启动，请维修
	WN_enUreaFillStopCantStartNext,			//1.233 尿素喷射中断，下次无法启动，请维修*/
	WN_enUreaFillStopCantStart,				//1.233 尿素喷射中断，无法启动，请维修
	WN_enConsumDeviatCantStartAfter,		//1.233 尿素消耗偏差，xxxkm后无法启动，请维修
	WN_enConsumDeviatCantStartNext,			//1.233 尿素消耗偏差，下次无法启动，请维修
	WN_enConsumDeviatCantStart,				//1.233 尿素消耗偏差，无法启动，请维修
	WN_enHoodClosedRestart,					//1.309 请关闭机舱盖后，重新启动车辆
	WN_enOilTankClosedRestart,				//1.310 请关闭油箱盖后，重新启动车辆

	//Secondary alarm

	//info
	WN_enFaceFail,							//TBD 人脸识别失败
	WN_enFaceInforNotEntered,				//TBD 人脸信息未录入，请尝试其它方式登录
	WN_enCSTActive,							//1.307 舒适制动功能已开启
	WN_enCSTClosed,							//1.307 舒适制动功能已关闭
	WN_enEVModeBattPowerLow,				//1.109 车辆处于强制纯电模式，动力电池可用功率低
	WN_enConnectedDischarging,				//1.308 连接成功，正在放电
	WN_enConnectedNoDischarge,				//1.308 连接成功，未放电

    //Update for Warning table v0.72 official version
    
	//Important alarm
	WN_enFrontTireAutoBack,					//TBD 前轮自动回正中…
	WN_enSteeringAutomaFuncsExits,			//TBD 方向盘自动回正功能退出
	WN_enEmergencyCallLimited,				//1.179 紧急呼叫功能受限 
	WN_enPowerLowStartEngine,				//1.314 动力电池电量低，请启动发动机用于放电
	WN_enFailedActivateDischarge,			//1.314 放电功能激活失败
	WN_enPowerSystemLimited,				//1.102 动力电池系统受限

	//Secondary alarm
	WN_enRearWheelSteeringFailure,			//1.312 后轮转向故障,请小心驾驶
	WN_enRearWheelSteeringLimited,			//1.312 后轮转向功能受限
	WN_enETCSystemFault, 					//TBD ETC系统故障

	//info
	WN_enDischargeDeviceRemoved,			//1.80 放电装置已移除
	WN_enETCNormal,							//TBD ETC通行正常
	WN_enETCAbnormal,						//TBD ETC通行异常
	WN_enExpresswayNormal,					//TBD 您本次高速通行正常，预计消费 XX.XX元

	 //Update for Warning table v0.73 official version

    //Tips
    WN_enCurrentTerrainCannotUnlocked,        //1.380 当前地形模式下不可解锁
    WN_enPowerBattWarmup,                     //1.382 动力电池预热中

    //Important alarm
    WN_enChargerFailure,                      //1.382 充电机故障
    WN_enDisconnectChargingDischarging,       //1.81 请断开充/放电装置
    WN_enPowerOffAfterThreeMinute,            //1.8 蓄电池电量过低，系统3分钟后关闭电源，请启动车辆

    //Tips
    WN_enACCCCActive,                         //TBD ACC/CC激活：上下左右按键描述
    WN_enACCCCCancel,                         //TBD ACC/CC取消：上下左右按键描述
    WN_enPleaseReadUserManual,                //1.315 车门锁：行车过程中只能通过紧急开关开启，请参见用户手册
    WN_enNoviceModel,                         //1.113 新手模式
    WN_enNoviceModelSelect,                   //1.113 新手模式已选择
    WN_enNoviceModelSwitch,                   //1.113 新手模式切换中，无法进入D/R/P挡

    //Update for Warning table v0.74
    //Special alarm

    //Important alarm
    WN_enCrabModeFailure,                     //TBD 螃蟹模式故障
    WN_enFrontTireAlignFinishGEEP40,          //1.235 前轮回正完成(应用项目：GEEP4.0)
    WN_enFactoryPatternGEEP40,                //TBD 工厂模式
    WN_enGalleryMode,                         //TBD 展厅模式
    WN_enStatBattLowTranModeGEEP40,           //1.8 运输模式(应用项目：GEEP4.0)
    WN_enStatBattLowComfortOffGEEP40,         //1.8 12V电源系统故障，舒适功能关闭，请联系4S店维修(应用项目：GEEP4.0)
    WN_enStatBattLowSavingModeGEEP40,         //1.8 电量消耗过多，进入省电模式(应用项目：GEEP4.0)
    WN_enPowerOffAfterThreeMinuteGEEP40,      //1.8 蓄电池电量过低，系统3分钟后关闭电源，请启动车辆(应用项目：GEEP4.0)  
    WN_enChargingCoverOpen,                   //TBD 充电口盖已开启

    //Secondary alarm
    WN_enStatBattLowPwrReduceGEEP40,          //1.8 12V蓄电池电量低，舒适功能降功率(应用项目：GEEP4.0)

    //info
    WN_enInboundFailedContinueCruise,         //1.273 汇入失败，继续巡航
    WN_enApproachingRamp,                     //1.247 xx公里/xx米后即将进入匝道
    WN_enCrabModeExitedGEEP40,                //TBD 螃蟹模式已退出(应用项目：GEEP4.0)
    WN_enCrabModeEnabledGEEP40,               //TBD 螃蟹模式已开启(应用项目：GEEP4.0)
    WN_enCrabModeStandbyGEEP40,               //TBD 螃蟹模式已待机(应用项目：GEEP4.0)
    WN_enLowBatteryStartVehicle,              //1.311 动力电池电量较低，请及时启动车辆
    WN_enLowBatteryPlugGunCharge,             //1.311 动力电池电量较低，请及时启动车辆或插枪充电
    WN_enAuxiliaryOpenSingPedalUnable,        //1.168 驾驶辅助功能开启，单踏板不可用

    //Update for Warning table v0.75 official version
    //Special alarm
    WN_enSmartCruiseouteEmergencyBrake,       //1.210 智慧巡航已退出，紧急刹车辅助启动

    //Important alarm

    //Secondary alarm
    WN_enSteerFailDrivelowSpeed,              //1.411 转向功能故障，请低速行驶(应用项目：GEEP4.0)
    WN_enSteerFailDriveCarefully,             //1.411 转向功能受限，请小心驾驶(应用项目：GEEP4.0)

    //info
    WN_enSteeringAutoNotTouchWheel,             //1.412 方向盘正在自动对齐，请勿触摸方向盘(应用项目：GEEP4.0)
    WN_ensteeringWheelAutoaLigned,              //1.412 方向盘自动对齐完成(应用项目：GEEP4.0)
    WN_enDM_B30_Novice,                        //1.113 新手模式
    
	//Update for D01-2683 
    //Important alarm
	WN_enFuelPrepare_Sound,                   //1.178 加油准备中加油准备中(有声音)

    /*Add new warning here*/
    WN_enWARNING_TOTAL_NUMBER
}WN_CFG_enWarningID;


/**********************************************************************************************************
*   Output Status Type Configuration                                                                      *
**********************************************************************************************************/
typedef enum
{
    WN_enDISPLAY_OFF = 0,
    WN_enDISPLAY_ON  = 1,
}WN_CFG_enSTATUS_Common;

/*Add new warning status type here*/
/*********************************************************************************************************/

/*********************************************************************************************************/
/*Power Mode Status*/
typedef enum
{
    WN_enNULL_POWER_MODE = 0x0000,
    WN_enOFF = 0x0001,
    WN_enRUN = 0x0002,
    WN_enSLEEP = 0x0004,
    WN_enABNORMAL_VOLTAGE = 0x0008,
}WN_CFG_u32WorkPowerMode;

#define WN_D1   (uint32)WN_enRUN
#define WN_D2   (uint32)WN_enOFF
#define WN_D3   (uint32)WN_enABNORMAL_VOLTAGE
/*********************************************************************************************************/
typedef void (*ptrStatusChangesOperation)(void);
typedef struct
{
    uint32                    u32WorkPowerMode;
    uint16                    u16IgnOnResponseDelayTime;
    uint16                    u16ExitAbnormalResponseDelayTime;
    uint8                     u8ConfigurationSwitch;
    ptrStatusChangesOperation vptrStatusChangesOperation;
}WN_CFG_tstWarningAttribute;
/**********************************************************************************************************/
#define WN_DEFAULT_STATUS     (0)
#define WN_NULL               (0)
#define WN_DO_NOTHING         (void *)0
#define WN_NOT_CONCERNED      (TRUE)
/*********************************************************************************************************/
/* WarningName                  WorkPower       IgnOnResponse  ExitAbnormal         Configuration   StatusChanges
                                Mode            DelayTime      ResponseDelayTime    Switch          Hock  */
#define WN_CFG_WARNING_CONTROL_ATTRIBUTE  {\
/*WN_enDrvAwayCar*/                 { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDrvAwayCarStop*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCESSTrig*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCAESTrig*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAEBTrigP*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAEBTrigV*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIASTrigV*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFCTABrakeActive*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRSDSRLBStart*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCTakeOverBrake*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAEBFCWWarning*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFCTABrakePlease*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCHoldWheel_1Hz*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCHoldWheel_2Hz*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCHoldWheel_3Hz*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCHoldWheel_4Hz*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAEBSafeDistance*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWATakeOver*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWATakeOver_2Hz*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWATakeOver_4Hz*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCTakeOver*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWATakeAtte*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWATakeAtte_2Hz*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWATakeAtte_4Hz*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGearPSelect*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLFDoorOpen*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRFDoorOpen*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLRDoorOpen*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRRDoorOpen*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTrunkOpen*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHoodOpen*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFirRowLSeatBelt*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFirRowRSeatBelt*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSecRowLSeatBelt*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSecRowMSeatBelt*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSecRowRSeatBelt*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBrakeSysFault*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynSysFault*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed0*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed1*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed2*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed3*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed4*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed5*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed6*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed7*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCCOTargetSpeed8*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed0*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed1*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed2*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed3*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed4*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed5*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed6*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed7*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowTargetSpeed8*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCESSFault*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFLTirePressWarning*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFRTirePressWarning*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRLTirePressWarning*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRRTirePressWarning*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFLTireTempWarning*/          { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFRTireTempWarning*/          { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRLTireTempWarning*/          { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRRTireTempWarning*/          { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4WDSystemFault*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4WDSystemHeat*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHybSysFault_Stop*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHybSysUnavailable*/          { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCharging*/                   { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeWait*/                 { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeComplete*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeStop*/                 { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattSysFault_Stop*/       { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattSysFault_Repair*/     { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCAESFault*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransWarnStopCar*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPowerSysFault*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransFault*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransPutInPFailed*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLowOilPressure*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enEngWaterTempHigh*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransWarning*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDrvSysFault_Repair*/         { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHybSysFault_Repair*/         { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStartingSysFault*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHybSysLimited*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRecoverySysFault*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargerFault*/               { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeSysFault*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargerTempHigh*/            { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattTempHigh*/            { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargerPWReduced*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFCTAUnavai*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLockFailureN*/               { WN_D2 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enNoticeGearN*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPositionLampOn*/             { WN_D2 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRSDSTrailer*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAEBFCWTrailer*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWACrossTunnel*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWABranchRoad*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeDevConnectErr*/        { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattTempLow*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargePortWarning*/          { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCSCalibrating*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransAuthenFailed*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransLimited*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransReleasePFailed*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enElecSteerUnlockFail*/        { WN_D2 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enEngPumpFault*/               { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAGSFault*/                   { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeDevDisconnect*/        { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeDevConnect*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattLow*/                 { WN_D2 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGearChngP*/                  { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGearPNeedStop*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHighBeamSysFault*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGearPNotSuitable*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLimpModeGearD*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLimpModeGearP*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enReadyNoRefuel*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFuelPrepare*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRaceLaunchActive*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRaceModeActive*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRaceLaunchTimeout*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargingNoRefuel*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFuelTankSysFault*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFuelTankCapOn*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGPFRegenerating*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGPFRegenerate*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRearAxleSysFault*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFrontAxleSysFault*/          { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDoNotStepAcAndBr*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enElecShifterFault*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStatBattLowTranMode*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStatBattLowComfortOff*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en12VFaultStop*/               { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en12VFaultRepair*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStatBattLowSavingMode*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStatBattLowStartUp*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enModeSwitchFailed*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRefuelingNoCharge*/          { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftGearBrakeAndKey*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftGearStepBrake*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftGearPressKey*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftNotAllowed*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftPStop*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDMSTakeRest_1*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDMSTakeRest_2*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDMSTakeRest_3*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDMSTakeAttention*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPPMIFault*/                  { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSidePPMIErr*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBSGSysFault*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsStartSelfClean*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsStartCarSlowly*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDPFCleaning*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSelfCleanComplete*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGearChngPN*/                 { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRainDoorOpen*/               { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHeatingPlugIn*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaLow*/                    { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaVeryLow*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaTankEmpty*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaUnqualifyPlsCheck*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaUnqualifyOver50km*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaFillStopPlsReFill*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaFillStopOver50km*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaSysDisableEng*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaSysErrPlsCheck*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaSysErrOver50km*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUreaSysErrRestartErr*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_ENS_EV*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFrontTireAlignFinish*/       { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFrontTireTurnRight*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFrontTireTurnLeft*/          { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRayAntiVirusWarn*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDrvConcentrate*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDrvDrowsy*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCantDriveBatt*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDischargingV2L*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDischargingV2V*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enEngVinMismatch*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORExperMode*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeHeating*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSMLimitPlsSwiEV*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSMErrPlsSwiEVAndStop*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSMErrStop*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattSysErrPlsFix*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattSysErrPlsFix_1*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSErrPlsFix*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSLeakPlsFix*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSLeakPlsSwiEV*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSLeakPlsSwiEVStop*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHSLeakStop*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDeionizerErrPlsFix*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWPCTakePhone*/               { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enARHUDFault*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enARHUDOverheat*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSRaceLaunchActive*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattLowSRaceLaunUnAvail*/    { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTransHeatSLaunchUnAvail*/    { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSRaceLaunchOverLimit*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattTempLowCantStart*/       { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattTempLowPowerDown*/       { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattTempHighPowerDown*/      { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsPrsBrktoWait*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSelfLearnNotComplete*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLearnSuccessPlsRelBrk*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPowerLowEVUnvil*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsCtrlWheel*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRearAxSysErr4WDUnvil*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPEPSPowerFault*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOverSpeedLevel_1*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOverSpeedLevel_2*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOverSpeedSetting*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLicPlateLampFault*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRvsLampFault*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRearPosnLampFault*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLasHdLightFault*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCSDectectLimited*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCSensorDetectLimited*/     { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFCTSDectectLimit*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCLKAFunLimited*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCommunicationFault*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCHWAFuncFault*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRSDSRCWWarning*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBeepSysFault*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBrakeLampFault*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRearFogLampFault*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRainLightFault*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAFSSystemFault*/             { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCUnavailable*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCCruiseFunFault*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAEBESPOff*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTrafficSignFault*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStatBattLowPwrReduce*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enALSSysFault*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORCruiseLimited*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTurnAssistLimited*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHDCLimited*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAutoholdLimited*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWPCChargeZone*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPHLFault*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPHLCameraFault*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LModeSlow*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4WDSystemDemotion*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4HModeSlow*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enVSGFault*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattCutOff*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enElecMachiFault*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDCDCFault*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enEParkFault*/                 { WN_D1       , (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRemoveChargeGun*/            { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRemoveDischrgGun*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShifterFault*/               { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftNotAllowEV*/            { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftPFault*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enShiftPStopEV*/               { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargingShift*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStepBrakeOutP*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStepBrakeOutN*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLVBattFault*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHVBattSport*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHVBattAir*/                  { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enECOValue*/                   { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPedalLimit*/                 { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enUnidentifyBatt*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHeatManagerFault*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFarBeamFault*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattFault*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTboxErr*/                    { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDynBattLowEV*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionLimit*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPowerOnGearDrive*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFuelStart*/                  { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enKeyInCarOrNot*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCISLCruiseSpeed*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStepBrakeStartGearPN*/       { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStepClutchStartGearNull*/    { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStepBrakeStartGearNull*/     { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCISLSlowDown*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTargetCruiseSpeed*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLasHdLightOn*/               { WN_D1 ,       (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLasHdLightOff*/              { WN_D1 ,       (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enParkLampOn*/                 { WN_D2 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDrowsyDrvWarning*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDrowsyDrvWarning_1Hz*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTakeTheKeyTip*/              { WN_D2 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFuelLowWarn*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAFSDrivingMode*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enALSDrivingSide*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enMaintainPlease*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enMaintainNext*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enReleaseElecParkCCO*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPleaseSlowDown*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LModeStop*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPleaseGearN*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LModeEx*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LModeSelect*/               { WN_D1       , (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4HModeSelect*/               { WN_D1       , (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LModeEn*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORCruiseActive*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Standard*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Sport*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Snow*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Muddy*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Sand*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_4L*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_ECO*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_IMC*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_SportPlus*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_OffRoad*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Expert*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Rock*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Pothole*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_MuddySand*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Mountain*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_StandardSelect*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
 /*WN_enDM_SportSelect*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SportPlusSelect*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SnowSelect*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MuddySelect*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SandSelect*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_EcoSelect*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_RockSelect*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PotholeSelect*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MuddySandSelect*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MountainSelect*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_ExpertSelect*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_OffRoadSelect*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_4LSelect*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_IMCSelect*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_StandardDPR*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SportDPR*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_EcoDPR*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SnowDPR*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MuddyDPR*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SandDPR*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PotholeDPR*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MountainDPR*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_RockDPR*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_OffRoadDPR*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SportPlusDPR*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_ExpertDPR*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MuddySandDPR*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_IMCDPR*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_4LDPR*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LEnGearN*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LEnGearDRP*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LExGearN*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LExGearDRP*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LEnClutchStep*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LEnClutchRele*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LExClutchStep*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LExClutchRele*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_StandardSecond*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SportSecond*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SportPlusSecond*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SnowSecond*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MuddySecond*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_SandSecond*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_ECOSecond*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_4LSecond*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PotholeSecond*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MountainSecond*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_RockSecond*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_OffRoadSecond*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_ExpertSecond*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_IMCSecond*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MuddySandSecond*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_EV_StandardStart*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_EV_SportStart*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_EV_EcoStart*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_EV_SnowStart*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_EV_AutoStart*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_V51EV_SinPedalStart*/     { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_V51EV_SinPedalQuit*/      { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStopBrakeGearN*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPowerNotInOff*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAutoStartStop*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeDevRemoved*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_DBL_EV_Err*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_AWD*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_EV*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_SAVE*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_SPORT*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_SAND*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_MUDDY*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_SNOW*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_AutoStart*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_EvStart*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_SaveStart*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_SportStart*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_AWDStart*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_SnowStart*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_MuddyStart*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_SandStart*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_EcoStart*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_SportPlusStart*/     { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MS_SPORT*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_MS_SPORT_Only*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSR_EV*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRLUnAvaiESPAVH*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRLUnAvaiHYB*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_SPORT_P*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_HSL_ECO*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTurnAssistOn*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTurnAssistWork*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTurnAssistClose*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORCruiseClose*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORCruiseWait*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORCruiseOn*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFastenSeatbelt*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enGradientHighWarning*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enParkSysWarning*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enClampForceWarning*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStepBrakePedal*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSettingVehilce*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOutTempLow*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAFSOff*/                     { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAFSOn*/                      { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSwitchMudSand*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRaceModeExit*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRaceModeFault*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPHLWideFunOff*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPHLWideOn*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPHLWideOff*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPHLFunOff*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPHLFunOn*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enQuitCompactMode*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWashModeActive*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWashModeSpeed*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWashModeBatt*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeDisGunConnect*/        { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enChargeGunConnect*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enReleaseElecPark*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enReleaseRearELD*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRLUnAvaiESP*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHeatingComplete*/            { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFaceCancelled*/              { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFaceNoMatch*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFaceSuccess*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPedalDynBatt*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPedalDynSnow*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFarBeamOn*/                  { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enFarBeamOff*/                 { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTmsTrailerOn*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTmsTrailerOff*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4WDGearDelayPlsSlow*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enARHUDLightLimit*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattLowLaunchUnavil*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCExitPlsControl*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enERCSysErr*/                  { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIFCLKAFuncOn*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enTurnAssistFuncLimit*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enERCSysLimit*/                { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enMainTankLow*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enMainTankLowPlsSwitch*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAuxTankLow*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAuxTankLowPlsSwitch*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Turbo*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Race*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_GrassGravel*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Uneven*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Wade4H*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_Wade4L*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_2H*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_B30_4H*/                  { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_TurboSelect*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_RaceSelect*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_GrassGravelSelect*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_UnevenSelect*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_Wade4HSelect*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_Wade4LSelect*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_2HSelect*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_4HSelect*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_TurboDPR*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_RaceDPR*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_GrassGravelDPR*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_UnevenDPR*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_Wade4HDPR*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_Wade4LDPR*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_2HDPR*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_4HDPR*/                   { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_TurboSecond*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_RaceSecond*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_GrassGravelSecond*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_UnevenSecond*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_Wade4HSecond*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_Wade4LSecond*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_2HSecond*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_4HSecond*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_P2HEVStart*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_P2EVStart*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enDM_PHEV_P2SaveStart*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAutoNaviStart*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAutoNaviExitPlsTake*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAutoNaviEnd*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOverSpeedERCSysOn*/          { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enERCSysDisable*/              { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOffroadThmSts*/              { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAntennaLostErr*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAutoLmpStsOn*/               { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enAutoLmpStsOff*/              { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsExitWadeMode*/            { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWadeModePlsSlow*/            { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWadeModePlsCare*/            { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCarPowerShutDown*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLifeDetectFault*/            { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enClutchOverheat*/             { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enQuickStartOvertime*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enLifeDetectClose*/            { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStopGearNSeatbelt*/          { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStopGearPNSeatbelt*/         { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSwitchSnowSand*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enIndividual*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPowerSysLimitLaunchFail*/    { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enForwardChargeMode*/          { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4WDEVSaveDisable*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XCarDistance*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XPeopleRight*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XPeopleMid*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XPeopleLeft*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XFaceCar*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XSideCarTwoSide*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XSideCarRight*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XSideCarLeft*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XFrontCarAEB*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XFrontCarUnContron*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XBackCarUnContron*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XAroundCarUnContron*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHookFaultPlsCheck*/          { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionFuncLimit*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionFuncFault*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCatalystSuHigh*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuClearing*/                 { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOilLeverLow*/                { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOilLeverHigh*/               { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOilLeverFault*/              { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XLeftLine*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XRightLine*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XReverseLine*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XFrontRoad*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XFrontCarAttention*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XLeaveCar*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XLeaveFireCar*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XLeaveAmbulance*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XLeavePolice*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XLeaveEngCar*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XBackCarLeft*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XBackCarRight*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XBackCarTwoSide*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSavePlusPowerLimit*/         { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOverSpeedSavePlusFail*/      { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWormFuncActive*/             { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enWormFuncOff*/                { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattLowStartEng*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionCoolDown*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHeightModeDisable*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsCloseDoorRise*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enRiseModeSusLimit*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionTimeLimit*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOverSpeedHeightDisable*/     { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enOverDefaultPower*/           { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHookLock*/                   { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHookUnlock*/                 { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHookPowerOn*/                { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSwitchParkSts*/              { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsCloseHook*/               { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsCheckHookSts*/            { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enNormalHeightSelect*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuitHeightSelect*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORHeight1Select*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enORHeight2Select*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionExtend*/           { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionLockHeight*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBackShaftHeightSelect*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuitHeightModeSelect*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionTrailer*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionLimitRise*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enKickBackShaft*/              { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionLimitTrans*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuspensionRise*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCarHighPlsSlow*/             { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSuClearDown*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSysFailACCDisable*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCPowerDisable*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enHWAACCPowerDisable*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enESPACCPowerDisable*/         { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enACCPowerExit*/               { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattPowerLowEVDisable*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enBattTempLowEVDisable*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_en4LModeEVSaveDisable*/        { WN_D1|WN_D2 , (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enCalibreHeatTabLimit*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enSavePlusModeStart*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XRoadBlockLever1*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XRoadBlockLever2*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XRoadBlockLever3*/         { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enV2XRoadBlock*/               { WN_D1 ,       (uint16)0   , (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStepBrakeStartGearBlank*/    { WN_D1 ,       (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enStopGearBlankSeatbelt*/      { WN_D1|WN_D2 , (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING },\
/*WN_enPlsTakeOver*/                { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enPlsTakeOver_2Hz*/	        { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enPlsTakeOver_4Hz*/            { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enCarAutoBrakePlsTake*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enCarParkingPlsTake*/          { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enCarUrgeBrakePlsTake*/        { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveRampFailPlsTake*/        { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveMainFailPlsTake*/        { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveMainFailPlsTake_2Hz*/    { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveMainFailPlsTake_4Hz*/    { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTurnFailPlsTake*/	        { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTurnFailPlsTake_2Hz*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTurnFailPlsTake_4Hz*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTollGateFailPlsTake*/        { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTollGateFailPlsTake_2Hz*/    { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTollGateFailPlsTake_4Hz*/    { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enRoundaboutFailPlsTake*/      { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enRoundaboutFailPlsTake_2Hz*/  { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enRoundaboutFailPlsTake_4Hz*/  { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enV2XFrontCarAttentionLeft*/   { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enV2XFrontCarAttentionRight*/  { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enUrgeTurnPlsHoldWheel*/       { WN_D1 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enFastChrgFault*/              { WN_D1|WN_D2 , (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enNOHFailPlsFix*/              { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enNOHFailPlsGearP*/            { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveRampFailPlsHand*/        { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveMainFailPlsHand*/        { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTurnFailPlsHand*/            { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTollGateFailPlsHand*/        { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enRoundaboutFailPlsHand*/      { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enRePlanLanes*/                { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enPlsHandChangeLanes*/         { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveRampFailHandWheel*/      { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveRampFailHandWheel_2Hz*/  { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enMoveMainFailHandWheel*/      { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTurnFailPlsHandWheel*/       { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTollGateFailPlsHandWheel*/   { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enRoundaboutFailPlsHandWheel*/ { WN_D1 ,       (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTJAICADisable*/			    { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enLowSpeedLaneAssistDisable*/  { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enOverSpeedLaneAssistDisable*/ { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTJAICAFaultPlsFixCamera*/    { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTJAICAFaultPlsFix*/          { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enWPCChargeZoneFront*/         { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enWPCChargeZoneRear*/          { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enWPCChargeZoneRR*/            { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enWPCChargeZoneRL*/            { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enAutoNaviExit*/               { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enAcceleratorPowen*/           { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enTurnSafeSlow*/               { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enNOHExit*/                    { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enNOHExitPlsTake*/             { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enNOHFinishExit*/              { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enOverSpeedNOHExit*/           { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enDriveIntoHighSpeed*/         { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enDriveIntoRamp*/              { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enNOHSetAccSpeed*/             { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enLockNGearDisable*/           { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enPlsPressBrakeTest*/          { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_en4Aor4HModeSelect*/           { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enBrakeSwitchFault*/           { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enSafeBackStart*/              { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enSafeBackStopCar*/            { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enSwitchGearReleaseBrake*/     { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enDM_EV_MuddyStart*/           { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enDM_EV_SandStart*/            { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enDM_EV_SportPlusStart*/       { WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enOneTrunkBoardOpen*/		    { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING },\
/*WN_enSplitTrunkBoardOpen*/	        { WN_D1 ,	 (uint16)3000, (uint16)1000 ,	 TRUE ,  WN_DO_NOTHING },\
/*WN_enQuickChargeFlapOpenPicture*/  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowFillingFlapOpenPicture*/  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING },\
/*WN_enSlowFillingFlapNotClosed*/    { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enQuickChargeFlapNotClosed*/    { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAttentionWaterRoad*/                { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAttentionLowlyingRoad*/            { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAttentionWetRoad*/                 { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAttentionSharpTurn*/               { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteRoadFailure*/                  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteUnevenRoad*/                   { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAttentionDangerousRoad*/           { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAwareDebrisFlow*/                  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteBridge*/                       { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAttentionTunnel*/                  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAwareFire*/                        { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteFallingRock*/                  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteIcyRoad*/                      { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteCrosswindRoad*/                { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enEmbankmentRoad*/                   { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteContinuousSharpTurn*/          { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteRoadNarrows*/                  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNoteIncomingTraffic*/              { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNotedamgeRoadFacities*/            { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enAwareScatteredObject*/             { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNOHIsResumed*/                     { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enMargeWatchOutFOrCarsComing*/       { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enSlowingDownForDischarge*/        { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNOExitedTakeSteeringWheel*/        { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enLaneLineNotClearDriveCarefully*/   { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enFourWheelDriveSystem*/           { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enCatcherSeriouslyBlocked*/        { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enChargingStatusDisplay*/          { WN_D1|WN_D2 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enExcessiveSpeedFourWheelDrive*/   { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enNavigationSlowDownActive*/    { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enPlsPayAttentionToSlowDown*/      { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enSpeedLimitForward60kmPerHour*/      {WN_D1 ,     (uint16)3000, (uint16)1000,   TRUE ,  WN_DO_NOTHING},\
/*WN_enSpeedLimitForward70kmPerHour*/      { WN_D1 ,    (uint16)3000, (uint16)1000 ,   TRUE ,  WN_DO_NOTHING},\
/*WN_enSPeedLimitForward80kmPerHour*/      { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enSpeedLimitForward90kmPerHour*/      { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enSpeedLimitForward100kmPerHour*/     { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enSpeedLimitForward110kmPerHour*/     { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enSpeedLimitForward120kmPerHour*/     { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enCurrentlyExceedNavigationLimit*/    { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enTurnGearDownConfirmSpeedAdjustment*/  { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enPressCruiseConfirmAdjustment*/     { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enComingOutMainRoad*/                { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enGoddessModeActivated*/           { WN_D1 ,    (uint16)3000, (uint16)1000 ,    TRUE ,  WN_DO_NOTHING},\
/*WN_enWshngLiquidNotEnough*/			{ WN_D1 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
/*WN_enUreaInsCantStartAfter*/			{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaInsSeriouslyCantStartAfter*/	{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaEmptyCantStartNext*/			{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaEmptyCantStart*/				{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaUnqualifyCantStartAfter*/	{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaUnqualifyCantStartNext*/		{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaUnqualifyCantStart*/			{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaFillStopCantStartAfter*/		{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaFillStopCantStartNext*/		{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enUreaFillStopCantStart*/			{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enConsumDeviatCantStartAfter*/		{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enConsumDeviatCantStartNext*/		{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enConsumDeviatCantStart*/			{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enHoodClosedRestart*/				{ WN_D1|WN_D2 , (uint16)0,    (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enOilTankClosedRestart*/			{ WN_D1|WN_D2 , (uint16)0,    (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enFaceFail*/						{ WN_D1 ,    	(uint16)0	, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enFaceInforNotEntered*/			{ WN_D1 ,    	(uint16)0	, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enCSTActive*/						{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enCSTClosed*/						{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enEVModeBattPowerLow*/				{ WN_D1 ,    	(uint16)3000, (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enConnectedDischarging*/			{ WN_D1|WN_D2 , (uint16)0,    (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enConnectedNoDischarge*/			{ WN_D1|WN_D2 , (uint16)0,    (uint16)1000 ,   		TRUE ,  WN_DO_NOTHING},\
/*WN_enFrontTireAutoBack*/			{ WN_D1 ,			(uint16)0, 	  (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enSteeringAutomaFuncsExits*/ 	{ WN_D1 ,			(uint16)0,	  (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enEmergencyCallLimited*/		{ WN_D1 ,			(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enPowerLowStartEngine*/		{ WN_D1|WN_D2 ,		(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enFailedActivateDischarge*/	{ WN_D1|WN_D2 , 	(uint16)0,	  (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enPowerSystemLimited*/			{ WN_D1 , 	        (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enRearWheelSteeringFailure*/	{ WN_D1 ,			(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enRearWheelSteeringLimited*/	{ WN_D1 ,			(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enETCSystemFault*/				{ WN_D1 ,			(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enDischargeDeviceRemoved*/		{ WN_D1|WN_D2,		(uint16)0,    (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enETCNormal*/ 					{ WN_D1 ,			(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enETCAbnormal*/				{ WN_D1 ,			(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enExpresswayNormal*/			{ WN_D1 ,			(uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enDisconnectChargingDischarging*/{ WN_D1|WN_D2 ,	    (uint16)0,    (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enPowerOffAfterThreeMinute*/     { WN_D1 ,	        (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enChargerFailure*/               { WN_D1|WN_D2 ,	    (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enCurrentTerrainCannotUnlocked*/ { WN_D1 ,	        (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enPowerBattWarmup*/              { WN_D1|WN_D2 ,	    (uint16)0,    (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enACCCCActive*/                  { WN_D1 ,	        (uint16)0,    (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enACCCCCancel*/                  { WN_D1 ,	        (uint16)0,    (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enPleaseReadUserManual*/         { WN_D1|WN_D2 ,	    (uint16)0,    (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enNoviceModel*/                  { WN_D1 ,	        (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enNoviceModelSelect*/            { WN_D1 ,	        (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enNoviceModelSwitch*/            { WN_D1 ,	        (uint16)3000, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING},\
/*WN_enCrabModeFailure*/              { WN_D1 ,         (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enFrontTireAlignFinishGEEP40*/ { WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enFactoryPatternGEEP40*/       { WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enGalleryMode*/                { WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enStatBattLowTranModeGEEP40*/  { WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enStatBattLowComfortOffGEEP40*/{ WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enStatBattLowSavingModeGEEP40*/{ WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enPowerOffAfterThreeMinuteGEEP40*/ { WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enChargingCoverOpen*/          { WN_D1 ,           (uint16)4000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enStatBattLowPwrReduceGEEP40*/ { WN_D1|WN_D2 ,     (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enInboundFailedContinueCruise*/{ WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enApproachingRamp*/            { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enCrabModeExitedGEEP40*/       { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enCrabModeEnabledGEEP40*/      { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enCrabModeStandbyGEEP40*/      { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enLowBatteryStartVehicle*/     { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enLowBatteryPlugGunCharge*/    { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enAuxiliaryOpenSingPedalUnable*/   { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enSmartCruiseouteEmergencyBrake*/  { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enSteerFailDrivelowSpeed*/         { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enSteerFailDriveCarefully*/        { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enSteeringAutoNotTouchWheel*/      { WN_D1 ,           (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_ensteeringWheelAutoaLigned*/       { WN_D1 ,           (uint16)0,    (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enDM_B30_Novice*/                  { WN_D1 ,           (uint16)3000, (uint16)1000 ,        TRUE ,  WN_DO_NOTHING},\
/*WN_enFuelPrepare_Sound*/				{ WN_D1|WN_D2 , 	(uint16)0	, (uint16)1000 ,		TRUE ,	WN_DO_NOTHING },\
}



/*Add new warning here*/
/*********************************************************************************************************/

/**********************************************************************************************************
*   Warning Power Mode Configuration                                                                      *
**********************************************************************************************************/
/*The power state from power module*/
#define WN_CFG_POWER_STATE                         0x08  // modify by fchao in 20200518 (FSM_u8Get_SuperState())

/*********************************************************************************************************/

#define WN_CFG_POWER_STATE_IS_OFF                  (0x10 == WN_CFG_POWER_STATE)
#define WN_CFG_POWER_STATE_IS_RUN                  (0x08 == WN_CFG_POWER_STATE)
#define WN_CFG_POWER_STATE_IS_ABNORMAL_VOLTAGE     (0x20 == WN_CFG_POWER_STATE)

/*********************************************************************************************************/

/**********************************************************************************************************
*   Warning Work Mode Configuration                                                                       *
**********************************************************************************************************/
/*The module working mode configuration*/

#define WN_CFG_DIAGNOSIS_MODE_ENABLE             (FALSE)

#define WN_CFG_EOL_MODE_ENABLE                   (FALSE)

/*********************************************************************************************************/


/**********************************************************************************************************
*   CAN Message Configuration                                                                             *
**********************************************************************************************************/
/*Test Signal*/
#define WN_CFG_TEST_MSG_HAS_RECEIVED    ((uint8)FALSE)

#define WN_CFG_TEST_MSG_NOT_MISSING     ((uint8)FALSE)

#define WN_CFG_TEST_MSG_VALUE           ((uint16)0)


/**********************************************************************************************************
*   Customer Configuration                                                                                *
**********************************************************************************************************/
#define WN_CFG_NET_CONDITION_OF_PS      TRUE
#define WN_CFG_NET_CONDITION_OF_LCDA    TRUE
#define WN_CFG_NET_CONDITION_OF_IFC     TRUE
#define WN_CFG_NET_CONDITION_OF_TCU     TRUE
#define WN_CFG_NET_CONDITION_OF_EPB     TRUE
#define WN_CFG_NET_CONDITION_OF_AEB     TRUE

/**********************************************************************************************************
*   HardWire Input Configuration                                                                                *
**********************************************************************************************************/
/*Brake fluid level*/
#define WN_CFG_GPIO_CONDITION_OF_BRAKE_FLUID_LEVEL  \
        FALSE//(LOW == GPIO_GetPinLevel(P17_6))


//1D0,1F4,1F6,12C,8C,186

/**********************************************************************************************************
*   Other Input Configuration                                                                             *
**********************************************************************************************************/
#define WN_CFG_CONDITION_OF_FUEL_LOW  \
    (FALSE)

#define WN_CFG_CONDITION_OF_RANGE_BELOW_40KM  \
    (FALSE)




/**********************************************************************************************************
*   CAN Ouptput Configuration                                                                             *
**********************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)

#define WN_CFG_SEND_WARNING_STATUS_CAN_MSG(Message)    ()

#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
/**********************************************************************************************************
*   SBUS Ouptput Configuration                                                                            *
**********************************************************************************************************/
    /**********************************************************************************************************
    *   SBUS Ouptput Configuration                                                                            *
    **********************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)

#define WN_CFG_SEND_WARNING_STATUS_SBUS_MSG(Message)    ()
        /*modify by fchao in 20200518
        { \
            NW_SIL_TX_WarningInfo_1_DATA(Message[0]);\
            NW_SIL_TX_WarningInfo_2_DATA(Message[1]);\
            NW_SIL_TX_WarningInfo_3_DATA(Message[2]);\
            NW_SIL_TX_WarningInfo_4_DATA(Message[3]);\
        } \
        */

#endif //((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)

/**********************************************************************************************************
*   Warning Control Status Configuration                                                                  *
**********************************************************************************************************/
typedef struct
{
#if (WN_CFG_DEBUG == TRUE)
    WN_CFG_enWarningID enWarningName;
#endif
    union
    {
        uint8 u8Status[4];
        struct
        {
            uint8 LogicType                     :8 ;
            uint8 ResultLogicType               :8 ;
            uint8 LastLogicType                 :8 ;
            uint8 ExternalControlStatus         :1 ; /*0x1:TRUE or 0x0:FALSE*/
            uint8 IgnitionOnResponseDelayStatus :1 ; /*0x1:TRUE or 0x0:FALSE*/
            uint8 ExitAbnormalDelayStatus       :1 ; /*0x1:TRUE or 0x0:FALSE*/
            uint8 Reserved                      :5 ;
        }stStatus;
    }unStatus;
}WN_CFG_tstWarningControlStatus;
/*********************************************************************************************************/


/**********************************************************************************************************
*   Other function Configuration                                                                          *
**********************************************************************************************************/



/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Main Object structure                                                                                 *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/
/**********************************************************************************************************
*   System Status                                                                                         *
**********************************************************************************************************/
typedef enum
{
/*Normal Status*/
      WN_SYSTEM_DEFAULT = 0x0000u,
      WN_SYSTEM_RUNNING = 0x0001u,

/*Abnormal Status*/
    WN_SYSTEM_FAILD = 0x0010u,
    WN_EEPROM_CONFIG_ERROR = 0x0020u,
    WN_POWER_MODE_ERROR = 0x0040u,
    WN_LOGIC_PROCESS_RETURN_VALUE_ERROR = 0x0080u,

    WN_KEEP_PREVIOUS = 0xFFFF
}WN_CFG_enSYSTEM_STATUS;
/**********************************************************************************************************
*   Main Object Structure Definition                                                                      *
**********************************************************************************************************/
typedef struct
{
    /*****************************************************************************************************/
    /*System Status*/
    /*****************************************************************************************************/
    union
    {
        uint32 u32SystemErrorStatus; /*The error status of Warning function*/
        struct
        {
            uint32 NormalStatusReserved    :4 ;

            uint32 SystemFaild             :1 ;
            uint32 EEPROMConfigError       :1 ;
            uint32 PowerModeError          :1 ;
            uint32 LogicProcessReturnError :1 ;

            uint32 Reserved                :24;
        }stSystemErrorStatus;
    }unSystemErrorStatus;
    /*****************************************************************************************************/
    /*Basic Function*/
    /******************************************************************************************************/
    union
    {
        uint32 u32PowerModeStatus; /*The status of power mode*/
        struct
        {
            uint32 WN_Off               :1 ;
            uint32 WN_Run               :1 ;
            uint32 WN_AbnormalVoltage   :1 ;
            uint32 Reserved             :29;
        }stPowerModeStatus;
    }unPowerModeStatus;
    /*The control status of warning*/
    WN_CFG_tstWarningControlStatus stWarningControlStatus[WN_enWARNING_TOTAL_NUMBER];
    /******************************************************************************************************/
    /*Output On CAN*/
    /******************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_CAN) != FALSE)
    uint32 u32CANMessage;                 /*The CAN message*/
#endif
    /******************************************************************************************************/
    /*Output On SBUS*/
    /******************************************************************************************************/
#if ((WN_CFG_OUTPUT_MODE & WN_CFG_OUTPUT_ON_SBUS) != FALSE)
    uint32 u32SBUSMessage;                 /*The SBUS message*/
#endif
    /******************************************************************************************************/
    /*Other Function*/
    /******************************************************************************************************/


    /******************************************************************************************************/
    /*Count Function*/
    /******************************************************************************************************/
    struct
    {
        uint16 u16IgnitionOnResponseDelayMaxTickCount;
        uint16 u16ExitAbnormalResponseDelayMaxTickCount;
        uint32 u32TimeTaskLoopRateTickCount;
    }stCount;
    /******************************************************************************************************/
    /*Timer Function*/
    /******************************************************************************************************/
    struct
    {
        uint16 u16IgnitionOnResponseDelayTick;
        uint16 u16ExitAbnormalResponseDelayDelayTick;
    }stTimer;
    /******************************************************************************************************/
    union
    {
        uint32 u32FuncFlag;                 /*the flag of Warning function*/
        struct
        {
            uint32 CANUpdateFlag            :1;   /*CAN update flag ,1 means need to update ,0 means do nothing */
            uint32 SBUSUpdateFlag           :1;   /*SBUS update flag ,1 means need to update ,0 means do nothing */

            uint32 Reserved                 :30;  /*Reserved bitfileds*/
        }stFuncFlag;
    }unFunctionFlag;
}WN_CFG_tstMAIN_OBJECT;  /*The Warning object type*/
/**********************************************************************************************************
*   Flag Operation                                                                                        *
**********************************************************************************************************/
typedef struct
{
    uint8  u8FlagBitIndex;
    uint8  u8FlagBitLength;
    uint8  u8ColdInitSetValue;
    uint8  u8WarmInitSetValue;
    uint8  u8WakeUpSetValue;
    uint8  u8SleepSetValue;
    uint8  u8EnterAbnormalSetValue;
    uint8  u8ExitAbnormalSetValue;
}WN_CFG_tstFLAG_ATTRIBUTE;

typedef enum
{
    WN_FLAG_DEFAULT  = 0x00,
    WN_FLAG_CLEAR    = 0x00,
    WN_FLAG_PREVIOUS = 0xFF
}WN_CFG_enFLAG_OPERATION;

typedef enum
{
    WN_COLD_INIT ,
    WN_WARM_INIT ,
    WN_WAKE_UP ,
    WN_SLEEP ,
    WN_ENTER_ABNORMAL,
    WN_EXIT_ABNORMAL
}WN_CFG_enFLAG_PROCESS_STAGE;




/*FlagName                          FlagBit  FlagBit  SetValueWhen       SetValueWhen       SetValueWhen       SetValueWhen       SetValueWhen       SetValueWhen
                                    Index    Length   ColdInit           WarmInit           WakeUp             Sleep              EnterAbnormal      ExitAbnormal  */
#define WN_CFG_FLAG_ATTRIBUTE   {\
/*CAN update flag*/             {     0 ,      1,     (uint8)WN_FLAG_DEFAULT ,   (uint8)WN_FLAG_DEFAULT , (uint8)WN_FLAG_PREVIOUS , (uint8)WN_FLAG_PREVIOUS , (uint8)WN_FLAG_PREVIOUS , (uint8)WN_FLAG_PREVIOUS},\
/*SBUS update flag*/            {     1 ,      1,     (uint8)WN_FLAG_DEFAULT ,   (uint8)WN_FLAG_DEFAULT , (uint8)WN_FLAG_PREVIOUS , (uint8)WN_FLAG_PREVIOUS , (uint8)WN_FLAG_PREVIOUS , (uint8)WN_FLAG_PREVIOUS},\
                                {    32 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },\
                                }
/*********************************************************************************************************/

/**********************************************************************************************************
*                                                                                                         *
*                                                                                                         *
*   Function Configuration                                                                                *
*                                                                                                         *
*                                                                                                         *
**********************************************************************************************************/
#define SWC_WN_START_SEC_CODE
#include "SWC_WN_MemMap.h"

void WN_CFG_vSetWarningStatus(WN_CFG_enWarningID enWarningID,uint8 u8LogicStatus,WN_CFG_tstMAIN_OBJECT* stMainObject);
uint32 WN_CFG_vGetPowerModeSts(void);
uint8 WN_CFG_vGetCruiseSpeed(void);
uint8 WN_CFG_vGetCruiseSpeedVld(void);
uint8 WN_CFG_vGetDrvModeCase(void);
uint16 WN_CFG_vGetNOH_DistToExit(void);
uint8 WN_CFG_vGetACC_SpdSetValue(void);//R11
uint8 WN_CFG_vGetV2XFrontRoadData(void);//R11
uint16 WN_CFG_vGetUreaRemainDistData(void);//R15
uint8 WN_CFG_vGetWN_PressReliProgsData(void);

#if (WN_CFG_DEBUG == TRUE)
void WN_TEST_vTestProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
#endif
/**********************************************************************************************************
*   Process Configuration                                                                                 *
**********************************************************************************************************/
void WN_ReadVehCfgProcess(void);
void WN_EngineTempHighProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TargetCruiseSpeedProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AutoStartStopProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_LowOilPressureProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_StatBattLowProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ESPFD2Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_EPBWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_BrakeSysFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_StepBrakePedalProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_OverSpeedWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_OverSpeedAlarmProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DoorOpenProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_RearFogLampFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PositionLampOnProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_BrakeLampFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_LicPlateLampFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_RvsLampFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_RearPositonLampFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ParkLampOnProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_RainLightFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DrowsyDriveWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TpmsWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TakeTheKeyTipProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_KeyInCarOrNotProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PEPSStartTipProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PEPSPowerFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PowerNotInOffProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ElecSteerUnlockFailProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_SeatBeltProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TransWarnProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TransFailProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ShiftGearTipProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TransTipProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_LimpModeGearProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_NoticeGearNProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ElecShifterFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PowerSysFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_GearPWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_4WDSystemWarnProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FuelLowWarnProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ORCruiseActiveProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ESP8Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DynBattLowEVProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AdaptiveCruiseControlProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ChargeDevRemovedProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_HCUPT4Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_HCUPT7Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_HCUPT8Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DynBattSysFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_BeepSysFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_CommunicationFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PowerOnGearDriveProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DoNotStepAcAndBrProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_EngAuthenFailedProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DrivingModeWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FuelTankSysFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_RaceLanuchWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_RaceModeWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DriveModeWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_SinPedalFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_GPFRegenerateProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_OutTemperatureProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_LasHdLightWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FarLasHdLightWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PixelHeadlightProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ALSSysFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ALSDrivingSideProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AFSStsProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AFSDrivingModeProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_HighBeamSysFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ESOFDrivingModeProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_4LModeSlowProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ModeSwitchFailedProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FuelTankCapWarnProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_SwitchMudSandProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_WPCPhoneProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_4WDSystemDemotionProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DriveSafetyTip1Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_EngPumpFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_HeatingGunProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_VSGFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ElecMachiFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DCDCFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DynBattFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_EParkFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_VCUFD3Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_HeatManagerFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AGSFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PPMIFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DischargingProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DriveSafetyTip2Process(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FaceTipProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_4LModeStopProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_4LModeEnterProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_4LModeSelectProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FuelTipProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_PlsUpdateCallBattProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TSMFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_EngVinMismatchProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AutoEmergencyBrakeProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_InterAssistSystemProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FCTAWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_RearSideAssistSystemProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TrafficSignFaultProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_IntelligentForwardSystemProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ARHUDStsProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_SuspensionFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_FrontTireProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_DPFWarningProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_UreaFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AntiVirusFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AntennaLostProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_OilBoxStatusProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ERCFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_TurnAssistFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_OffroadThmProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_WadeModeFuncProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_AutoLampStsProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_NOHProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_V2VProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_ClutOvrHeatdProcess(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_Oillevel_alarm(WN_CFG_tstMAIN_OBJECT* stMainObject);
void WN_Active_sulphur_removal( WN_CFG_tstMAIN_OBJECT *stMainObject );
void HWA_Process( WN_CFG_tstMAIN_OBJECT *stMainObject );
void Energy_recovery_Process( WN_CFG_tstMAIN_OBJECT *stMainObject );
void Air_Suspension_Process( WN_CFG_tstMAIN_OBJECT *stMainObject );//R12
void VMDR_Function_Process( WN_CFG_tstMAIN_OBJECT *stMainObject );//R12
void TrailerHook_Function_Process( WN_CFG_tstMAIN_OBJECT *stMainObject );//R13
void WN_FourWheel_Drive_Locked(WN_CFG_tstMAIN_OBJECT *stMainObject);//R14
void WN_Navigation_Speed_Down(WN_CFG_tstMAIN_OBJECT *stMainObject);//R14
void WN_Electric_Charging_Prompt(WN_CFG_tstMAIN_OBJECT *stMainObject);//R14
void WshngLiquid_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject);//R15
void CST_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject);//R15
void OBD_Charge_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject);//R15
void Electricity_Unlock_Function_Process(WN_CFG_tstMAIN_OBJECT *stMainObject);//R17
void Charger_Status_Prormpt(WN_CFG_tstMAIN_OBJECT *stMainObject);//R18

#define SWC_WN_STOP_SEC_CODE
#include "SWC_WN_MemMap.h"

/*Add Logic Process here*/
/*********************************************************************************************************/
/*Logic Process Status*/
typedef enum
{
    WN_enINTERFACE = 0x01,/*Run in interrupt always set this attribute*/
    WN_enTIME_TASK = 0x02,
    WN_enROBIN_TASK = 0x04,
}WN_CFG_enLogicProcessMode;
#define WN_I   (uint32)WN_enINTERFACE
#define WN_TT  (uint32)WN_enTIME_TASK
#define WN_RT  (uint32)WN_enROBIN_TASK
/*********************************************************************************************************/
/*     WarningLogicProcess                LogicProcess         TimeTaskMode       TimeTaskMode
             Function                         Mode               RunFactor          RunOffset  */
#define WN_CFG_LOGIC_PROCESS_ATTRIBUTE  \
{ WN_ReadVehCfgProcess ,                    WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_EngineTempHighProcess ,                WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_TargetCruiseSpeedProcess ,             WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_AutoStartStopProcess ,                 WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_LowOilPressureProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_StatBattLowProcess ,                   WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_ESPFD2Process ,                        WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_EPBWarningProcess ,                    WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_BrakeSysFaultProcess ,                 WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_StepBrakePedalProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_OverSpeedWarningProcess ,              WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_OverSpeedAlarmProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_RearFogLampFaultProcess ,              WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_PositionLampOnProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_BrakeLampFaultProcess ,                WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_LicPlateLampFaultProcess ,             WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_RvsLampFaultProcess ,                  WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_RearPositonLampFaultProcess ,          WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_ParkLampOnProcess ,                    WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_RainLightFaultProcess ,                WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_DrowsyDriveWarningProcess ,            WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_TpmsWarningProcess ,                   WN_TT ,            (uint16)5,          (uint16)0  },\
{ WN_TakeTheKeyTipProcess ,                 WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_KeyInCarOrNotProcess ,                 WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_PEPSStartTipProcess ,                  WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_PEPSPowerFaultProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_PowerNotInOffProcess ,                 WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_ElecSteerUnlockFailProcess ,           WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_SeatBeltProcess ,                      WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DoorOpenProcess ,                      WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_TransWarnProcess ,                     WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_TransFailProcess ,                     WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_ShiftGearTipProcess ,                  WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_TransTipProcess ,                      WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_LimpModeGearProcess ,                  WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_NoticeGearNProcess ,                   WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_ElecShifterFaultProcess ,              WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_PowerSysFaultProcess ,                 WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_GearPWarningProcess ,                  WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_4WDSystemWarnProcess ,                 WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_FuelLowWarnProcess ,                   WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_ORCruiseActiveProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_ESP8Process ,                          WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DynBattLowEVProcess ,                  WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_AdaptiveCruiseControlProcess ,         WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_ChargeDevRemovedProcess ,              WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_HCUPT4Process ,                        WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_HCUPT7Process ,                        WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_HCUPT8Process ,                        WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_DynBattSysFaultProcess ,               WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_BeepSysFaultProcess ,                  WN_TT ,            (uint16)5 ,         (uint16)2  },\
{ WN_CommunicationFaultProcess ,            WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_PowerOnGearDriveProcess ,              WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_DoNotStepAcAndBrProcess ,              WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_EngAuthenFailedProcess ,               WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DrivingModeWarningProcess ,            WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_FuelTankSysFaultProcess ,              WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_RaceLanuchWarningProcess ,             WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_RaceModeWarningProcess ,               WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DriveModeWarningProcess ,              WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_SinPedalFuncProcess ,                  WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_GPFRegenerateProcess ,                 WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_OutTemperatureProcess ,                WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_LasHdLightWarningProcess ,             WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_FarLasHdLightWarningProcess ,          WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_PixelHeadlightProcess ,                WN_TT ,            (uint16)5 ,         (uint16)2  },\
{ WN_ALSSysFaultProcess ,                   WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_ALSDrivingSideProcess ,                WN_TT ,            (uint16)5 ,         (uint16)4  },\
{ WN_AFSStsProcess ,                        WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_AFSDrivingModeProcess ,                WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_HighBeamSysFaultProcess ,              WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_ESOFDrivingModeProcess ,               WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_4LModeSlowProcess ,                    WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_ModeSwitchFailedProcess ,              WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_FuelTankCapWarnProcess ,               WN_TT ,            (uint16)5 ,         (uint16)2  },\
{ WN_SwitchMudSandProcess ,                 WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_WPCPhoneProcess ,                      WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_4WDSystemDemotionProcess ,             WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DriveSafetyTip1Process ,               WN_TT ,            (uint16)5 ,         (uint16)4  },\
{ WN_EngPumpFaultProcess ,                  WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_HeatingGunProcess ,                    WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_VSGFaultProcess ,                      WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_ElecMachiFaultProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DCDCFaultProcess ,                     WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DynBattFaultProcess ,                  WN_TT ,            (uint16)5 ,         (uint16)2  },\
{ WN_EParkFaultProcess ,                    WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_VCUFD3Process ,                        WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_HeatManagerFaultProcess ,              WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_AGSFaultProcess ,                      WN_TT ,            (uint16)5 ,         (uint16)4  },\
{ WN_PPMIFaultProcess ,                     WN_TT ,            (uint16)5,          (uint16)0  },\
{ WN_DischargingProcess ,                   WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_DriveSafetyTip2Process ,               WN_TT ,            (uint16)5,          (uint16)0  },\
{ WN_FaceTipProcess ,                       WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_4LModeStopProcess ,                    WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_4LModeEnterProcess ,                   WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_4LModeSelectProcess ,                  WN_TT ,            (uint16)5 ,         (uint16)2  },\
{ WN_FuelTipProcess ,                       WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_PlsUpdateCallBattProcess ,             WN_TT ,            (uint16)5,          (uint16)0  },\
{ WN_TSMFuncProcess ,                       WN_TT ,            (uint16)1,          (uint16)0  },\
{ WN_EngVinMismatchProcess ,                WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_AutoEmergencyBrakeProcess ,            WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_InterAssistSystemProcess ,             WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_FCTAWarningProcess ,                   WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_RearSideAssistSystemProcess ,          WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_TrafficSignFaultProcess ,              WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_IntelligentForwardSystemProcess ,      WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_ARHUDStsProcess ,                      WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_SuspensionFuncProcess ,                WN_TT ,            (uint16)5 ,         (uint16)2  },\
{ WN_FrontTireProcess ,                     WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_DPFWarningProcess ,                    WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_UreaFuncProcess ,                      WN_TT ,            (uint16)5 ,         (uint16)4  },\
{ WN_AntiVirusFuncProcess ,                 WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_AntennaLostProcess ,                   WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_OilBoxStatusProcess ,                  WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_ERCFuncProcess ,                       WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_TurnAssistFuncProcess ,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_OffroadThmProcess ,                    WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_WadeModeFuncProcess ,                  WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ WN_AutoLampStsProcess ,                   WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_NOHProcess,                            WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_V2VProcess,                            WN_TT ,            (uint16)5 ,         (uint16)2  },\
{ WN_ClutOvrHeatdProcess,                   WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ WN_Oillevel_alarm,                        WN_TT ,            (uint16)5 ,         (uint16)3  },\
{ WN_Active_sulphur_removal,                WN_TT ,            (uint16)5 ,         (uint16)4  },\
{ HWA_Process,                              WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ Energy_recovery_Process,                  WN_TT ,            (uint16)2 ,         (uint16)1  },\
{ Air_Suspension_Process,                   WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ VMDR_Function_Process,                    WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ TrailerHook_Function_Process,             WN_TT ,            (uint16)2 ,         (uint16)0  },\
{ WN_FourWheel_Drive_Locked,                WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ WN_Navigation_Speed_Down,                 WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ WN_Electric_Charging_Prompt,              WN_TT ,            (uint16)5,          (uint16)1  },\
{ WshngLiquid_Function_Process,             WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ CST_Function_Process,                  	WN_TT ,            (uint16)1 ,         (uint16)0  },\
{ OBD_Charge_Function_Process,              WN_TT ,            (uint16)5 ,         (uint16)0  },\
{ Electricity_Unlock_Function_Process,      WN_TT ,            (uint16)5 ,         (uint16)1  },\
{ (void*)0 ,                                WN_TT ,            (uint16)1 ,         (uint16)0  },\
/* Update Process order by Zhangbin 2020/8/6 by warning SRS V1.2 20200729 */



/*Add Logic Process here*/
/*********************************************************************************************************/
typedef void (*ptrWarningLogicOperation)(WN_CFG_tstMAIN_OBJECT* stMainObject);
typedef struct
{
    ptrWarningLogicOperation  vptrWarningLogicOperation;
    uint32                    u32LogicProcessMode;
	uint16                    u16TimeTaskModeLoopFactor;
	uint16                    u16TimeTaskModeLoopOffset;
}WN_CFG_tstLogicProcessAttribute;
/*********************************************************************************************************/
#endif //WN_CFG_H
/**********************************************************************************************************
*  End Of File                                                                                            *
**********************************************************************************************************/
